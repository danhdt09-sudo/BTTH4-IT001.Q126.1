#include "so_phuc.h"

/*
 * Nhận vào: Hai số thực mang tên thuc và ao (có giá trị mặc định là 0.0).
 * Cho ra: Không có (phương thức thiết lập).
 * Giải thuật: Gán giá trị được truyền vào cho thuộc tính phan_thuc và phan_ao. Nếu người dùng chỉ truyền vào một số thực, tham số ao sẽ mặc định bằng 0, giúp coi số thực như một số phức đặc biệt.
 */
so_phuc::so_phuc(double thuc, double ao) {
    phan_thuc = thuc;
    phan_ao = ao;
}

/*
 * Nhận vào: Một đối tượng so_phuc khác (tham chiếu hằng).
 * Cho ra: Một đối tượng so_phuc mới là kết quả của phép cộng.
 * Giải thuật: Lấy phần thực cộng phần thực, phần ảo cộng phần ảo để tạo ra số phức mới.
 */
so_phuc so_phuc::operator+(const so_phuc& khac) const {
    return so_phuc(phan_thuc + khac.phan_thuc, phan_ao + khac.phan_ao);
}

/*
 * Nhận vào: Một đối tượng so_phuc khác (tham chiếu hằng).
 * Cho ra: Một đối tượng so_phuc mới là kết quả của phép trừ.
 * Giải thuật: Lấy phần thực trừ phần thực, phần ảo trừ phần ảo để tạo ra số phức mới.
 */
so_phuc so_phuc::operator-(const so_phuc& khac) const {
    return so_phuc(phan_thuc - khac.phan_thuc, phan_ao - khac.phan_ao);
}

/*
 * Nhận vào: Một đối tượng so_phuc khác (tham chiếu hằng).
 * Cho ra: Một đối tượng so_phuc mới là kết quả của phép nhân.
 * Giải thuật: Áp dụng công thức nhân số phức: (a+bi)*(c+di) = (a*c - b*d) + (a*d + b*c)i.
 */
so_phuc so_phuc::operator*(const so_phuc& khac) const {
    double thuc_moi = (phan_thuc * khac.phan_thuc) - (phan_ao * khac.phan_ao);
    double ao_moi = (phan_thuc * khac.phan_ao) + (phan_ao * khac.phan_thuc);
    return so_phuc(thuc_moi, ao_moi);
}

/*
 * Nhận vào: Một đối tượng so_phuc khác (tham chiếu hằng).
 * Cho ra: Một đối tượng so_phuc mới là kết quả của phép chia.
 * Giải thuật: Nhân cả tử và mẫu cho số phức liên hợp của mẫu. Công thức: (a+bi)/(c+di) = (a*c + b*d)/(c^2 + d^2) + (b*c - a*d)/(c^2 + d^2)i. Nếu mẫu số bằng 0, in ra thông báo lỗi và trả về số phức (0,0).
 */
so_phuc so_phuc::operator/(const so_phuc& khac) const {
    double mau_so = (khac.phan_thuc * khac.phan_thuc) + (khac.phan_ao * khac.phan_ao);
    if (mau_so == 0) {
        std::cerr << "loi: chia cho 0\n";
        return so_phuc(0, 0);
    }
    double thuc_moi = ((phan_thuc * khac.phan_thuc) + (phan_ao * khac.phan_ao)) / mau_so;
    double ao_moi = ((phan_ao * khac.phan_thuc) - (phan_thuc * khac.phan_ao)) / mau_so;
    return so_phuc(thuc_moi, ao_moi);
}

/*
 * Nhận vào: Một đối tượng so_phuc khác (tham chiếu hằng).
 * Cho ra: Giá trị boolean (true nếu bằng nhau, false nếu ngược lại).
 * Giải thuật: So sánh đồng thời phần thực với phần thực, và phần ảo với phần ảo. Nếu cả hai cặp đều bằng nhau thì trả về true.
 */
bool so_phuc::operator==(const so_phuc& khac) const {
    return (phan_thuc == khac.phan_thuc) && (phan_ao == khac.phan_ao);
}

/*
 * Nhận vào: Một đối tượng so_phuc khác (tham chiếu hằng).
 * Cho ra: Giá trị boolean (true nếu khác nhau, false nếu bằng nhau).
 * Giải thuật: Phủ định lại kết quả của toán tử == vừa được định nghĩa.
 */
bool so_phuc::operator!=(const so_phuc& khac) const {
    return !(*this == khac);
}

/*
 * Nhận vào: Luồng nhập (istream) và một đối tượng so_phuc (tham chiếu).
 * Cho ra: Luồng nhập (istream) sau khi đã xử lý.
 * Giải thuật: Yêu cầu người dùng nhập lần lượt phần thực và phần ảo từ bàn phím, sau đó gán vào các thuộc tính tương ứng của đối tượng.
 */
std::istream& operator>>(std::istream& is, so_phuc& sp) {
    std::cout << "nhap phan thuc: ";
    is >> sp.phan_thuc;
    std::cout << "nhap phan ao: ";
    is >> sp.phan_ao;
    return is;
}

/*
 * Nhận vào: Luồng xuất (ostream) và một đối tượng so_phuc (tham chiếu hằng).
 * Cho ra: Luồng xuất (ostream) sau khi đã xử lý.
 * Giải thuật: Kiểm tra dấu của phần ảo để in ra định dạng a + bi hoặc a - bi cho đẹp mắt. Nếu phần ảo bằng 0 thì chỉ in phần thực.
 */
std::ostream& operator<<(std::ostream& os, const so_phuc& sp) {
    if (sp.phan_ao == 0) {
        os << sp.phan_thuc;
    } else if (sp.phan_ao < 0) {
        os << sp.phan_thuc << " - " << -sp.phan_ao << "i";
    } else {
        os << sp.phan_thuc << " + " << sp.phan_ao << "i";
    }
    return os;
}
