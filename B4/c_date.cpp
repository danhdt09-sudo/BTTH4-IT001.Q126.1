#include "c_date.h"

/*
 * Nhận vào: Một số nguyên n đại diện cho năm.
 * Cho ra: Giá trị boolean (true nếu là năm nhuận, false nếu ngược lại).
 * Giải thuật: Một năm là năm nhuận nếu nó chia hết cho 400, hoặc chia hết cho 4 nhưng không chia hết cho 100.
 */
bool c_date::kiem_tra_nam_nhuan(int n) const {
    return (n % 400 == 0) || (n % 4 == 0 && n % 100 != 0);
}

/*
 * Nhận vào: Hai số nguyên t (tháng) và n (năm).
 * Cho ra: Số nguyên là tổng số ngày của tháng đó trong năm đó.
 * Giải thuật: Các tháng 4, 6, 9, 11 có 30 ngày. Tháng 2 có 29 ngày nếu là năm nhuận, ngược lại có 28 ngày. Các tháng còn lại có 31 ngày.
 */
int c_date::lay_so_ngay_trong_thang(int t, int n) const {
    if (t == 4 || t == 6 || t == 9 || t == 11) return 30;
    if (t == 2) return kiem_tra_nam_nhuan(n) ? 29 : 28;
    return 31;
}

/*
 * Nhận vào: Không có.
 * Cho ra: Không có (phương thức nội bộ cập nhật trực tiếp đối tượng).
 * Giải thuật: Sử dụng vòng lặp để xử lý việc tràn ngày. Nếu số ngày lớn hơn số ngày tối đa của tháng hiện tại, trừ đi số ngày đó và tăng tháng lên 1 (nếu tháng > 12 thì tăng năm). Ngược lại, nếu số ngày <= 0, lùi tháng lại và cộng thêm số ngày của tháng trước đó.
 */
void c_date::chuan_hoa() {
    while (ngay > lay_so_ngay_trong_thang(thang, nam)) {
        ngay -= lay_so_ngay_trong_thang(thang, nam);
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }
    while (ngay <= 0) {
        thang--;
        if (thang < 1) {
            thang = 12;
            nam--;
        }
        ngay += lay_so_ngay_trong_thang(thang, nam);
    }
}

/*
 * Nhận vào: Không có.
 * Cho ra: Số nguyên dài (long long) đại diện cho tổng số ngày tính từ mốc 01/01/0001.
 * Giải thuật: Cộng dồn số ngày của đối tượng hiện tại với tổng số ngày của các tháng trước đó trong năm, và tổng số ngày của các năm trước đó (bao gồm cả việc tính bù các ngày của năm nhuận).
 */
long long c_date::tinh_khoang_cach_tu_moc() const {
    long long tong_ngay = ngay;
    for (int t = 1; t < thang; ++t) {
        tong_ngay += lay_so_ngay_trong_thang(t, nam);
    }
    int nam_truoc = nam - 1;
    tong_ngay += nam_truoc * 365LL + (nam_truoc / 4) - (nam_truoc / 100) + (nam_truoc / 400);
    return tong_ngay;
}

/*
 * Nhận vào: Ba số nguyên ng (ngày), th (tháng), n (năm), mặc định là 01/01/0001.
 * Cho ra: Không có (phương thức thiết lập).
 * Giải thuật: Gán các giá trị truyền vào cho ngày, tháng, năm. Sau đó gọi hàm chuan_hoa() để đảm bảo ngày tháng năm hợp lệ.
 */
c_date::c_date(int ng, int th, int n) {
    ngay = ng;
    thang = th;
    nam = n;
    chuan_hoa();
}

/*
 * Nhận vào: Một số nguyên so_ngay (số ngày cần cộng thêm).
 * Cho ra: Một đối tượng c_date mới là kết quả của phép cộng.
 * Giải thuật: Tạo một bản sao của đối tượng hiện tại, cộng thêm so_ngay vào thuộc tính ngay. Sau đó gọi chuan_hoa() để định dạng lại và trả về đối tượng mới.
 */
c_date c_date::operator+(int so_ngay) const {
    c_date ket_qua = *this;
    ket_qua.ngay += so_ngay;
    ket_qua.chuan_hoa();
    return ket_qua;
}

/*
 * Nhận vào: Một số nguyên so_ngay (số ngày cần trừ đi).
 * Cho ra: Một đối tượng c_date mới là kết quả của phép trừ.
 * Giải thuật: Tạo một bản sao của đối tượng hiện tại, trừ đi so_ngay từ thuộc tính ngay. Sau đó gọi chuan_hoa() để định dạng lại và trả về đối tượng mới.
 */
c_date c_date::operator-(int so_ngay) const {
    c_date ket_qua = *this;
    ket_qua.ngay -= so_ngay;
    ket_qua.chuan_hoa();
    return ket_qua;
}

/*
 * Nhận vào: Không có (toán tử tiền tố ++).
 * Cho ra: Tham chiếu đến chính đối tượng c_date hiện tại sau khi đã tăng 1 ngày.
 * Giải thuật: Tăng thuộc tính ngay lên 1, gọi chuan_hoa(), và trả về tham chiếu *this.
 */
c_date& c_date::operator++() {
    ngay++;
    chuan_hoa();
    return *this;
}

/*
 * Nhận vào: Một số nguyên giả (dummy) để phân biệt hậu tố.
 * Cho ra: Một đối tượng c_date mang giá trị cũ trước khi tăng 1 ngày.
 * Giải thuật: Lưu lại trạng thái hiện tại vào biến tam. Tăng ngày của đối tượng hiện tại lên 1, gọi chuan_hoa(). Cuối cùng trả về biến tam.
 */
c_date c_date::operator++(int) {
    c_date tam = *this;
    ngay++;
    chuan_hoa();
    return tam;
}

/*
 * Nhận vào: Không có (toán tử tiền tố --).
 * Cho ra: Tham chiếu đến chính đối tượng c_date hiện tại sau khi lùi 1 ngày.
 * Giải thuật: Giảm thuộc tính ngay đi 1, gọi chuan_hoa(), và trả về tham chiếu *this.
 */
c_date& c_date::operator--() {
    ngay--;
    chuan_hoa();
    return *this;
}

/*
 * Nhận vào: Một số nguyên giả (dummy) để phân biệt hậu tố.
 * Cho ra: Một đối tượng c_date mang giá trị cũ trước khi lùi 1 ngày.
 * Giải thuật: Lưu lại trạng thái hiện tại vào biến tam. Giảm ngày của đối tượng hiện tại đi 1, gọi chuan_hoa(). Cuối cùng trả về biến tam.
 */
c_date c_date::operator--(int) {
    c_date tam = *this;
    ngay--;
    chuan_hoa();
    return tam;
}

/*
 * Nhận vào: Một đối tượng c_date khác (tham chiếu hằng).
 * Cho ra: Số nguyên là khoảng cách số ngày giữa hai mốc thời gian.
 * Giải thuật: Quy đổi cả hai mốc thời gian ra tổng số ngày tính từ 01/01/0001 bằng hàm tinh_khoang_cach_tu_moc(). Lấy giá trị của đối tượng hiện tại trừ đi giá trị của đối tượng truyền vào.
 */
int c_date::operator-(const c_date& khac) const {
    return this->tinh_khoang_cach_tu_moc() - khac.tinh_khoang_cach_tu_moc();
}

/*
 * Nhận vào: Luồng nhập (istream) và một đối tượng c_date (tham chiếu).
 * Cho ra: Luồng nhập (istream) sau khi đã xử lý.
 * Giải thuật: Lấy dữ liệu ngày, tháng, năm từ bàn phím và gọi hàm chuan_hoa() để đảm bảo ngày tháng năm nhập vào là hợp lệ (ví dụ nhập 32/1 thì tự biến thành 1/2).
 */
std::istream& operator>>(std::istream& is, c_date& d) {
    std::cout << "nhap ngay: "; is >> d.ngay;
    std::cout << "nhap thang: "; is >> d.thang;
    std::cout << "nhap nam: "; is >> d.nam;
    d.chuan_hoa();
    return is;
}

/*
 * Nhận vào: Luồng xuất (ostream) và một đối tượng c_date (tham chiếu hằng).
 * Cho ra: Luồng xuất (ostream) sau khi đã xử lý.
 * Giải thuật: In ra thông tin ngày, tháng, năm theo định dạng dd/mm/yyyy. Thêm số 0 ở trước nếu ngày hoặc tháng chỉ có 1 chữ số để hiển thị đẹp hơn.
 */
std::ostream& operator<<(std::ostream& os, const c_date& d) {
    if (d.ngay < 10) os << "0";
    os << d.ngay << "/";
    if (d.thang < 10) os << "0";
    os << d.thang << "/" << d.nam;
    return os;
}
