#include "c_time.h"

/*
 * Nhận vào: Không có tham số truyền vào.
 * Cho ra: Không có (phương thức nội bộ).
 * Giải thuật: Quy đổi toàn bộ giờ, phút, giây hiện tại ra tổng số giây. Nếu tổng giây âm (lùi quá 00:00:00), bù thêm giây của một ngày (86400 giây) để vòng lại mặt đồng hồ. Sau đó tính ngược lại số giờ (chia 3600), số phút (chia dư 3600 rồi chia 60) và số giây (chia dư 60). Luôn giới hạn giờ trong khoảng 0-23.
 */
void c_time::chuan_hoa() {
    long long tong_giay = gio * 3600 + phut * 60 + giay;
    tong_giay = tong_giay % 86400;
    if (tong_giay < 0) {
        tong_giay += 86400;
    }
    gio = tong_giay / 3600;
    phut = (tong_giay % 3600) / 60;
    giay = tong_giay % 60;
}

/*
 * Nhận vào: Ba số nguyên g, p, gy tương ứng với giờ, phút, giây (mặc định bằng 0).
 * Cho ra: Không có (phương thức thiết lập).
 * Giải thuật: Gán các giá trị truyền vào cho các thuộc tính giờ, phút, giây tương ứng. Sau đó gọi hàm chuan_hoa() để đảm bảo thời gian hợp lệ (ví dụ: truyền vào 65 phút sẽ tự đổi thành 1 giờ 5 phút).
 */
c_time::c_time(int g, int p, int gy) {
    gio = g;
    phut = p;
    giay = gy;
    chuan_hoa();
}

/*
 * Nhận vào: Một số nguyên giay_them đại diện cho số giây cần cộng thêm.
 * Cho ra: Một đối tượng c_time mới là kết quả của phép cộng.
 * Giải thuật: Tạo một đối tượng mới với cấu hình giờ, phút giữ nguyên, nhưng số giây được cộng thêm lượng tương ứng. Nhờ constructor tự động gọi chuan_hoa(), kết quả trả về sẽ luôn là một thời gian hợp lệ.
 */
c_time c_time::operator+(int giay_them) const {
    return c_time(gio, phut, giay + giay_them);
}

/*
 * Nhận vào: Một số nguyên giay_bot đại diện cho số giây cần trừ đi.
 * Cho ra: Một đối tượng c_time mới là kết quả của phép trừ.
 * Giải thuật: Tạo một đối tượng mới bằng cách lấy số giây hiện tại trừ đi giay_bot. Kết quả được tự động chuẩn hóa bởi constructor.
 */
c_time c_time::operator-(int giay_bot) const {
    return c_time(gio, phut, giay - giay_bot);
}

/*
 * Nhận vào: Không có tham số (toán tử tiền tố ++).
 * Cho ra: Tham chiếu đến chính đối tượng c_time hiện tại sau khi đã tăng.
 * Giải thuật: Tăng giá trị thuộc tính giay lên 1, sau đó chuẩn hóa đối tượng hiện tại và trả về tham chiếu (*this).
 */
c_time& c_time::operator++() {
    giay++;
    chuan_hoa();
    return *this;
}

/*
 * Nhận vào: Một số nguyên giả (dummy) để phân biệt với tiền tố (toán tử hậu tố ++).
 * Cho ra: Một đối tượng c_time mang giá trị cũ trước khi tăng.
 * Giải thuật: Lưu lại trạng thái hiện tại vào biến tam. Tăng giây của đối tượng hiện tại lên 1 và chuẩn hóa. Cuối cùng trả về biến tam (giá trị cũ).
 */
c_time c_time::operator++(int) {
    c_time tam = *this;
    giay++;
    chuan_hoa();
    return tam;
}

/*
 * Nhận vào: Không có tham số (toán tử tiền tố --).
 * Cho ra: Tham chiếu đến chính đối tượng c_time hiện tại sau khi đã giảm.
 * Giải thuật: Giảm giá trị thuộc tính giay đi 1, sau đó chuẩn hóa đối tượng hiện tại và trả về tham chiếu (*this).
 */
c_time& c_time::operator--() {
    giay--;
    chuan_hoa();
    return *this;
}

/*
 * Nhận vào: Một số nguyên giả (dummy) để phân biệt với tiền tố (toán tử hậu tố --).
 * Cho ra: Một đối tượng c_time mang giá trị cũ trước khi giảm.
 * Giải thuật: Lưu lại trạng thái hiện tại. Giảm giây của đối tượng hiện tại đi 1 và chuẩn hóa. Cuối cùng trả về trạng thái cũ đã lưu.
 */
c_time c_time::operator--(int) {
    c_time tam = *this;
    giay--;
    chuan_hoa();
    return tam;
}

/*
 * Nhận vào: Luồng nhập (istream) và một đối tượng c_time (tham chiếu).
 * Cho ra: Luồng nhập (istream) sau khi đã xử lý.
 * Giải thuật: Nhập lần lượt giờ, phút, giây từ bàn phím. Sau khi nhập, gọi hàm chuẩn hóa để đảm bảo số liệu nằm trong giới hạn cho phép của đồng hồ thực tế.
 */
std::istream& operator>>(std::istream& is, c_time& t) {
    std::cout << "nhap gio: ";
    is >> t.gio;
    std::cout << "nhap phut: ";
    is >> t.phut;
    std::cout << "nhap giay: ";
    is >> t.giay;
    t.chuan_hoa();
    return is;
}

/*
 * Nhận vào: Luồng xuất (ostream) và một đối tượng c_time (tham chiếu hằng).
 * Cho ra: Luồng xuất (ostream) sau khi đã xử lý.
 * Giải thuật: Sử dụng thư viện iomanip (setfill, setw) để xuất thời gian theo định dạng HH:MM:SS chuẩn (thêm số 0 ở trước nếu chỉ có 1 chữ số).
 */
std::ostream& operator<<(std::ostream& os, const c_time& t) {
    os << std::setfill('0') << std::setw(2) << t.gio << ":"
       << std::setfill('0') << std::setw(2) << t.phut << ":"
       << std::setfill('0') << std::setw(2) << t.giay;
    return os;
}
