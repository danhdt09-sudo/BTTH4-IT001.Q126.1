#include "phan_so.h"

/*
 * Nhận vào: Không có tham số truyền vào.
 * Cho ra: Không có (phương thức nội bộ).
 * Giải thuật: Tìm Ước chung lớn nhất (UCLN) của tử số và mẫu số bằng thuật toán Euclid. Sau đó chia cả tử và mẫu cho UCLN này để tối giản phân số. Đảm bảo mẫu số luôn dương bằng cách đổi dấu cả tử và mẫu nếu mẫu bị âm.
 */
void phan_so::rut_gon() {
    if (mau_so == 0) return;
    int a = std::abs(tu_so);
    int b = std::abs(mau_so);
    while (b != 0) {
        int tam = a % b;
        a = b;
        b = tam;
    }
    tu_so /= a;
    mau_so /= a;

    if (mau_so < 0) {
        tu_so = -tu_so;
        mau_so = -mau_so;
    }
}

/*
 * Nhận vào: Hai số nguyên tu và mau (mặc định tu = 0, mau = 1).
 * Cho ra: Không có (phương thức thiết lập).
 * Giải thuật: Gán giá trị đầu vào cho tử số và mẫu số. Nếu truyền vào 1 số nguyên, mẫu số mặc định là 1 (coi số nguyên như phân số đặc biệt). Kiểm tra mẫu số khác 0, sau đó gọi phương thức rut_gon() để chuẩn hóa.
 */
phan_so::phan_so(int tu, int mau) {
    tu_so = tu;
    if (mau == 0) {
        std::cerr << "loi: mau so khong the bang 0. dat mau so = 1.\n";
        mau_so = 1;
    } else {
        mau_so = mau;
    }
    rut_gon();
}

/*
 * Nhận vào: Một đối tượng phan_so khác (tham chiếu hằng).
 * Cho ra: Một đối tượng phan_so mới là tổng của hai phân số.
 * Giải thuật: Quy đồng mẫu số: tử mới = (tử 1 * mẫu 2) + (tử 2 * mẫu 1), mẫu mới = mẫu 1 * mẫu 2. Sau đó trả về đối tượng mới (tự động được rút gọn nhờ constructor).
 */
phan_so phan_so::operator+(const phan_so& khac) const {
    int tu_moi = (tu_so * khac.mau_so) + (khac.tu_so * mau_so);
    int mau_moi = mau_so * khac.mau_so;
    return phan_so(tu_moi, mau_moi);
}

/*
 * Nhận vào: Một đối tượng phan_so khác (tham chiếu hằng).
 * Cho ra: Một đối tượng phan_so mới là hiệu của hai phân số.
 * Giải thuật: Quy đồng mẫu số: tử mới = (tử 1 * mẫu 2) - (tử 2 * mẫu 1), mẫu mới = mẫu 1 * mẫu 2. Trả về đối tượng mới.
 */
phan_so phan_so::operator-(const phan_so& khac) const {
    int tu_moi = (tu_so * khac.mau_so) - (khac.tu_so * mau_so);
    int mau_moi = mau_so * khac.mau_so;
    return phan_so(tu_moi, mau_moi);
}

/*
 * Nhận vào: Một đối tượng phan_so khác (tham chiếu hằng).
 * Cho ra: Một đối tượng phan_so mới là tích của hai phân số.
 * Giải thuật: Lấy tử nhân tử, mẫu nhân mẫu. Trả về đối tượng mới.
 */
phan_so phan_so::operator*(const phan_so& khac) const {
    int tu_moi = tu_so * khac.tu_so;
    int mau_moi = mau_so * khac.mau_so;
    return phan_so(tu_moi, mau_moi);
}

/*
 * Nhận vào: Một đối tượng phan_so khác (tham chiếu hằng).
 * Cho ra: Một đối tượng phan_so mới là thương của hai phân số.
 * Giải thuật: Nhân phân số thứ nhất với phân số đảo ngược của phân số thứ hai (tử 1 * mẫu 2, mẫu 1 * tử 2). Nếu tử của phân số thứ 2 bằng 0 thì báo lỗi.
 */
phan_so phan_so::operator/(const phan_so& khac) const {
    if (khac.tu_so == 0) {
        std::cerr << "loi: chia cho 0.\n";
        return phan_so(0, 1);
    }
    int tu_moi = tu_so * khac.mau_so;
    int mau_moi = mau_so * khac.tu_so;
    return phan_so(tu_moi, mau_moi);
}

/*
 * Nhận vào: Một đối tượng phan_so khác (tham chiếu hằng).
 * Cho ra: Giá trị boolean (true nếu bằng nhau).
 * Giải thuật: So sánh tích chéo. Nếu (tử 1 * mẫu 2) == (tử 2 * mẫu 1) thì trả về true.
 */
bool phan_so::operator==(const phan_so& khac) const {
    return (tu_so * khac.mau_so) == (khac.tu_so * mau_so);
}

/*
 * Nhận vào: Một đối tượng phan_so khác (tham chiếu hằng).
 * Cho ra: Giá trị boolean (true nếu phân số hiện tại lớn hơn).
 * Giải thuật: So sánh tích chéo. Do thuộc tính mẫu số luôn được đảm bảo là dương nhờ hàm rut_gon, ta có thể so sánh trực tiếp: (tử 1 * mẫu 2) > (tử 2 * mẫu 1).
 */
bool phan_so::operator>(const phan_so& khac) const {
    return (tu_so * khac.mau_so) > (khac.tu_so * mau_so);
}

/*
 * Nhận vào: Một đối tượng phan_so khác (tham chiếu hằng).
 * Cho ra: Giá trị boolean (true nếu phân số hiện tại nhỏ hơn).
 * Giải thuật: Tương tự phép lớn hơn, so sánh tích chéo: (tử 1 * mẫu 2) < (tử 2 * mẫu 1).
 */
bool phan_so::operator<(const phan_so& khac) const {
    return (tu_so * khac.mau_so) < (khac.tu_so * mau_so);
}

/*
 * Nhận vào: Luồng nhập (istream) và một đối tượng phan_so (tham chiếu).
 * Cho ra: Luồng nhập (istream) sau khi đã xử lý.
 * Giải thuật: Nhập tử số và mẫu số từ bàn phím. Kiểm tra nếu mẫu số bằng 0 thì buộc chuyển thành 1. Cuối cùng gọi rut_gon() để chuẩn hóa phân số vừa nhập.
 */
std::istream& operator>>(std::istream& is, phan_so& ps) {
    std::cout << "nhap tu so: ";
    is >> ps.tu_so;
    std::cout << "nhap mau so: ";
    is >> ps.mau_so;
    if (ps.mau_so == 0) {
        std::cerr << "loi: mau so bang 0, tu dong chuyen thanh 1.\n";
        ps.mau_so = 1;
    }
    ps.rut_gon();
    return is;
}

/*
 * Nhận vào: Luồng xuất (ostream) và một đối tượng phan_so (tham chiếu hằng).
 * Cho ra: Luồng xuất (ostream) sau khi đã xử lý.
 * Giải thuật: In ra tử số. Nếu mẫu số khác 1 (và khác 0), in thêm dấu "/" và mẫu số. Việc này giúp hiển thị số nguyên một cách tự nhiên.
 */
std::ostream& operator<<(std::ostream& os, const phan_so& ps) {
    if (ps.mau_so == 1) {
        os << ps.tu_so;
    } else if (ps.tu_so == 0) {
        os << "0";
    } else {
        os << ps.tu_so << "/" << ps.mau_so;
    }
    return os;
}
