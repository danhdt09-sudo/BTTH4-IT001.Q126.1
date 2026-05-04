#include "da_thuc.h"
#include <cmath>

/*
 * Nhận vào: Không có.
 * Cho ra: Không có (phương thức thiết lập mặc định).
 * Giải thuật: Khởi tạo đa thức bậc 0, cấp phát mảng động 1 phần tử (hệ số bậc 0) và gán bằng 0.
 */
da_thuc::da_thuc() {
    bac = 0;
    he_so = new double[1];
    he_so[0] = 0.0;
}

/*
 * Nhận vào: Số nguyên b đại diện cho bậc của đa thức.
 * Cho ra: Không có (phương thức thiết lập có tham số).
 * Giải thuật: Cấp phát mảng động có kích thước b + 1 (để chứa các hệ số từ bậc 0 đến bậc b). Gán toàn bộ hệ số ban đầu bằng 0. Nếu b < 0, tự động đưa về bậc 0.
 */
da_thuc::da_thuc(int b) {
    if (b < 0) b = 0;
    bac = b;
    he_so = new double[bac + 1];
    for (int i = 0; i <= bac; ++i) {
        he_so[i] = 0.0;
    }
}

/*
 * Nhận vào: Không có.
 * Cho ra: Không có (phương thức hủy).
 * Giải thuật: Thu hồi bộ nhớ đã cấp phát cho mảng he_so để tránh rò rỉ bộ nhớ (memory leak).
 */
da_thuc::~da_thuc() {
    delete[] he_so;
}

/*
 * Nhận vào: Đối tượng da_thuc khác (tham chiếu hằng).
 * Cho ra: Không có (phương thức thiết lập sao chép).
 * Giải thuật: Cấp phát một mảng mới có cùng kích thước với đa thức cần sao chép, sau đó chép từng hệ số sang để hai đối tượng độc lập về bộ nhớ.
 */
da_thuc::da_thuc(const da_thuc& khac) {
    bac = khac.bac;
    he_so = new double[bac + 1];
    for (int i = 0; i <= bac; ++i) {
        he_so[i] = khac.he_so[i];
    }
}

/*
 * Nhận vào: Đối tượng da_thuc khác (tham chiếu hằng).
 * Cho ra: Tham chiếu đến đối tượng hiện tại.
 * Giải thuật: Kiểm tra tự gán (tránh việc a = a). Xóa mảng cũ của đối tượng hiện tại, cấp phát mảng mới và sao chép dữ liệu từ đối tượng truyền vào.
 */
da_thuc& da_thuc::operator=(const da_thuc& khac) {
    if (this != &khac) {
        delete[] he_so;
        bac = khac.bac;
        he_so = new double[bac + 1];
        for (int i = 0; i <= bac; ++i) {
            he_so[i] = khac.he_so[i];
        }
    }
    return *this;
}

/*
 * Nhận vào: Một số thực x.
 * Cho ra: Giá trị số thực là kết quả của đa thức tại điểm x.
 * Giải thuật: Sử dụng lược đồ Horner để tối ưu hóa việc tính toán. Thay vì dùng hàm pow(), thuật toán tính dồn: P(x) = (...(a_n*x + a_{n-1})*x + ...)*x + a_0.
 */
double da_thuc::tinh_gia_tri(double x) const {
    double ket_qua = he_so[bac];
    for (int i = bac - 1; i >= 0; --i) {
        ket_qua = ket_qua * x + he_so[i];
    }
    return ket_qua;
}

/*
 * Nhận vào: Luồng nhập (istream) và đối tượng da_thuc (tham chiếu).
 * Cho ra: Luồng nhập (istream) sau khi đã xử lý.
 * Giải thuật: Yêu cầu người dùng nhập bậc. Sau đó thu hồi mảng cũ, cấp phát mảng mới theo bậc vừa nhập và dùng vòng lặp để nhập lần lượt các hệ số từ bậc cao nhất xuống bậc 0.
 */
std::istream& operator>>(std::istream& is, da_thuc& dt) {
    std::cout << "nhap bac cua da thuc: ";
    int b;
    is >> b;
    if (b < 0) b = 0;

    // Cấp phát lại bộ nhớ cho đa thức hiện tại
    delete[] dt.he_so;
    dt.bac = b;
    dt.he_so = new double[dt.bac + 1];

    for (int i = dt.bac; i >= 0; --i) {
        std::cout << "nhap he so cua x^" << i << ": ";
        is >> dt.he_so[i];
    }
    return is;
}

/*
 * Nhận vào: Luồng xuất (ostream) và đối tượng da_thuc (tham chiếu hằng).
 * Cho ra: Luồng xuất (ostream) sau khi đã xử lý.
 * Giải thuật: Duyệt mảng hệ số từ bậc cao nhất về 0. Kiểm tra hệ số khác 0 mới in ra. Xử lý logic in dấu + / - và ẩn đi phần biến x nếu là bậc 0.
 */
std::ostream& operator<<(std::ostream& os, const da_thuc& dt) {
    bool la_da_thuc_khong = true;
    for (int i = dt.bac; i >= 0; --i) {
        if (dt.he_so[i] != 0) {
            la_da_thuc_khong = false;
            // In dấu
            if (dt.he_so[i] > 0 && i != dt.bac) {
                os << " + ";
            } else if (dt.he_so[i] < 0) {
                if (i != dt.bac) os << " - ";
                else os << "-";
            }

            // In giá trị tuyệt đối của hệ số
            double gia_tri_tuyet_doi = std::abs(dt.he_so[i]);
            if (gia_tri_tuyet_doi != 1 || i == 0) {
                os << gia_tri_tuyet_doi;
            }

            // In phần biến x
            if (i > 0) {
                os << "x";
                if (i > 1) os << "^" << i;
            }
        }
    }
    if (la_da_thuc_khong) {
        os << "0";
    }
    return os;
}
