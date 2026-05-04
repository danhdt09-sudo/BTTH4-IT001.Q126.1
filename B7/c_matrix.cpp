#include "c_matrix.h"
#include <iomanip>

/*
 * Nhận vào: Số dòng và số cột cần khởi tạo.
 * Cho ra: Không có (phương thức nội bộ).
 * Giải thuật: Cấp phát mảng con trỏ 1 chiều chứa các dòng. Sau đó duyệt qua từng dòng để cấp phát mảng 1 chiều chứa các cột. Khởi tạo toàn bộ giá trị bằng 0 để tránh rác bộ nhớ.
 */
void c_matrix::cap_phat(int dong, int cot) {
    so_dong = dong;
    so_cot = cot;
    if (so_dong > 0 && so_cot > 0) {
        du_lieu = new double*[so_dong];
        for (int i = 0; i < so_dong; ++i) {
            du_lieu[i] = new double[so_cot](); // Dấu () giúp tự động gán 0
        }
    } else {
        du_lieu = nullptr;
        so_dong = 0;
        so_cot = 0;
    }
}

/*
 * Nhận vào: Không có.
 * Cho ra: Không có (phương thức nội bộ).
 * Giải thuật: Nếu con trỏ dữ liệu khác null, duyệt qua từng dòng để xóa bộ nhớ của cột, sau đó xóa mảng dòng và gán null để tránh lỗi con trỏ lơ lửng.
 */
void c_matrix::thu_hoi() {
    if (du_lieu != nullptr) {
        for (int i = 0; i < so_dong; ++i) {
            delete[] du_lieu[i];
        }
        delete[] du_lieu;
        du_lieu = nullptr;
    }
}

/*
 * Nhận vào: Không có.
 * Cho ra: Không có (phương thức thiết lập mặc định).
 * Giải thuật: Gọi hàm thu_hoi để đảm bảo sạch sẽ, sau đó gọi cap_phat(0, 0) để tạo ma trận rỗng.
 */
c_matrix::c_matrix() {
    cap_phat(0, 0);
}

/*
 * Nhận vào: Số nguyên dong và cot.
 * Cho ra: Không có (phương thức thiết lập có tham số).
 * Giải thuật: Trực tiếp gọi phương thức cap_phat(dong, cot) để cấp phát bộ nhớ.
 */
c_matrix::c_matrix(int dong, int cot) {
    cap_phat(dong, cot);
}

/*
 * Nhận vào: Không có.
 * Cho ra: Không có (phương thức hủy).
 * Giải thuật: Gọi phương thức thu_hoi() để dọn dẹp toàn bộ bộ nhớ khi đối tượng bị hủy.
 */
c_matrix::~c_matrix() {
    thu_hoi();
}

/*
 * Nhận vào: Một đối tượng c_matrix khác (tham chiếu hằng).
 * Cho ra: Không có (phương thức thiết lập sao chép).
 * Giải thuật: Cấp phát bộ nhớ với kích thước bằng ma trận nguồn. Sử dụng vòng lặp lồng nhau để chép từng phần tử sang ma trận hiện tại.
 */
c_matrix::c_matrix(const c_matrix& khac) {
    cap_phat(khac.so_dong, khac.so_cot);
    for (int i = 0; i < so_dong; ++i) {
        for (int j = 0; j < so_cot; ++j) {
            du_lieu[i][j] = khac.du_lieu[i][j];
        }
    }
}

/*
 * Nhận vào: Một đối tượng c_matrix khác (tham chiếu hằng).
 * Cho ra: Tham chiếu đến chính đối tượng c_matrix hiện tại.
 * Giải thuật: Kiểm tra tự gán. Nếu khác nhau, thu hồi bộ nhớ cũ, cấp phát bộ nhớ mới theo kích thước của ma trận truyền vào và chép toàn bộ dữ liệu.
 */
c_matrix& c_matrix::operator=(const c_matrix& khac) {
    if (this != &khac) {
        thu_hoi();
        cap_phat(khac.so_dong, khac.so_cot);
        for (int i = 0; i < so_dong; ++i) {
            for (int j = 0; j < so_cot; ++j) {
                du_lieu[i][j] = khac.du_lieu[i][j];
            }
        }
    }
    return *this;
}

/*
 * Nhận vào: Một đối tượng c_matrix khác (tham chiếu hằng).
 * Cho ra: Một đối tượng c_matrix mới là tổng hai ma trận.
 * Giải thuật: Kiểm tra điều kiện (hai ma trận phải cùng dòng, cùng cột). Nếu hợp lệ, cấp phát ma trận kết quả và cộng tương ứng từng phần tử $C_{ij} = A_{ij} + B_{ij}$.
 */
c_matrix c_matrix::operator+(const c_matrix& khac) const {
    if (so_dong != khac.so_dong || so_cot != khac.so_cot) {
        std::cerr << "loi: hai ma tran khong cung kich thuoc de cong.\n";
        return c_matrix();
    }
    c_matrix ket_qua(so_dong, so_cot);
    for (int i = 0; i < so_dong; ++i) {
        for (int j = 0; j < so_cot; ++j) {
            ket_qua.du_lieu[i][j] = du_lieu[i][j] + khac.du_lieu[i][j];
        }
    }
    return ket_qua;
}

/*
 * Nhận vào: Một đối tượng c_matrix khác (tham chiếu hằng).
 * Cho ra: Một đối tượng c_matrix mới là tích hai ma trận.
 * Giải thuật: Số cột của ma trận A phải bằng số dòng của B. Kích thước ma trận kết quả là (dòng A $\times$ cột B). Công thức tính phần tử: $C_{ij} = \sum (A_{ik} \times B_{kj})$.
 */
c_matrix c_matrix::operator*(const c_matrix& khac) const {
    if (so_cot != khac.so_dong) {
        std::cerr << "loi: so cot ma tran 1 phai bang so dong ma tran 2.\n";
        return c_matrix();
    }
    c_matrix ket_qua(so_dong, khac.so_cot);
    for (int i = 0; i < so_dong; ++i) {
        for (int j = 0; j < khac.so_cot; ++j) {
            for (int k = 0; k < so_cot; ++k) {
                ket_qua.du_lieu[i][j] += du_lieu[i][k] * khac.du_lieu[k][j];
            }
        }
    }
    return ket_qua;
}

/*
 * Nhận vào: Một đối tượng c_vector (tham chiếu hằng).
 * Cho ra: Một đối tượng c_vector mới là kết quả của phép nhân.
 * Giải thuật: Số cột của ma trận phải bằng số chiều của vector. Kết quả sinh ra một vector mới có số chiều bằng số dòng của ma trận. Áp dụng công thức: $V_{moi}[i] = \sum (A_{ij} \times V_{cu}[j])$.
 */
c_vector c_matrix::operator*(const c_vector& v) const {
    if (so_cot != v.lay_so_chieu()) {
        std::cerr << "loi: so cot ma tran phai bang so chieu vector de nhan.\n";
        return c_vector();
    }
    c_vector ket_qua(so_dong);
    for (int i = 0; i < so_dong; ++i) {
        double tong = 0;
        for (int j = 0; j < so_cot; ++j) {
            tong += du_lieu[i][j] * v[j];
        }
        ket_qua[i] = tong;
    }
    return ket_qua;
}

/*
 * Nhận vào: Luồng nhập (istream) và một đối tượng c_matrix (tham chiếu).
 * Cho ra: Luồng nhập (istream) sau khi xử lý.
 * Giải thuật: Yêu cầu người dùng nhập số dòng và cột. Thu hồi bộ nhớ cũ (nếu có), cấp phát mảng mới theo kích thước vừa nhập và dùng 2 vòng lặp để nhập lần lượt các phần tử.
 */
std::istream& operator>>(std::istream& is, c_matrix& m) {
    int d, c;
    std::cout << "nhap so dong: ";
    is >> d;
    std::cout << "nhap so cot: ";
    is >> c;

    m.thu_hoi();
    m.cap_phat(d, c);

    for (int i = 0; i < m.so_dong; ++i) {
        for (int j = 0; j < m.so_cot; ++j) {
            std::cout << "nhap phan tu [" << i << "][" << j << "]: ";
            is >> m.du_lieu[i][j];
        }
    }
    return is;
}

/*
 * Nhận vào: Luồng xuất (ostream) và một đối tượng c_matrix (tham chiếu hằng).
 * Cho ra: Luồng xuất (ostream) sau khi xử lý.
 * Giải thuật: In ma trận ra theo dạng bảng. Sử dụng setw(8) để căn lề phải cho các cột, giúp ma trận hiển thị vuông vức và dễ nhìn.
 */
std::ostream& operator<<(std::ostream& os, const c_matrix& m) {
    if (m.so_dong == 0 || m.so_cot == 0) {
        os << "[ma tran rong]\n";
        return os;
    }
    for (int i = 0; i < m.so_dong; ++i) {
        for (int j = 0; j < m.so_cot; ++j) {
            os << std::setw(8) << m.du_lieu[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}
