#include "c_vector.h"

/*
 * Nhận vào: Không có.
 * Cho ra: Không có (phương thức thiết lập mặc định).
 * Giải thuật: Khởi tạo một vector rỗng với số chiều bằng 0 và con trỏ tọa độ trỏ vào null để đảm bảo an toàn bộ nhớ.
 */
c_vector::c_vector() {
    so_chieu = 0;
    toa_do = nullptr;
}

/*
 * Nhận vào: Một số nguyên n đại diện cho số chiều của vector.
 * Cho ra: Không có (phương thức thiết lập có tham số).
 * Giải thuật: Cấp phát mảng động có kích thước n để chứa các tọa độ. Khởi tạo toàn bộ các tọa độ ban đầu có giá trị bằng 0. Nếu n <= 0 thì coi như vector rỗng.
 */
c_vector::c_vector(int n) {
    if (n <= 0) {
        so_chieu = 0;
        toa_do = nullptr;
    } else {
        so_chieu = n;
        toa_do = new double[so_chieu];
        for (int i = 0; i < so_chieu; ++i) {
            toa_do[i] = 0.0;
        }
    }
}

/*
 * Nhận vào: Không có.
 * Cho ra: Không có (phương thức hủy).
 * Giải thuật: Kiểm tra nếu con trỏ tọa độ khác null thì thu hồi bộ nhớ mảng đã cấp phát để tránh rò rỉ bộ nhớ.
 */
c_vector::~c_vector() {
    if (toa_do != nullptr) {
        delete[] toa_do;
    }
}

/*
 * Nhận vào: Một đối tượng c_vector khác (tham chiếu hằng).
 * Cho ra: Không có (phương thức thiết lập sao chép).
 * Giải thuật: Gán số chiều bằng số chiều của vector nguồn. Cấp phát một mảng tọa độ mới và chép từng giá trị từ vector nguồn sang để hai đối tượng hoàn toàn độc lập.
 */
c_vector::c_vector(const c_vector& khac) {
    so_chieu = khac.so_chieu;
    if (so_chieu > 0) {
        toa_do = new double[so_chieu];
        for (int i = 0; i < so_chieu; ++i) {
            toa_do[i] = khac.toa_do[i];
        }
    } else {
        toa_do = nullptr;
    }
}

/*
 * Nhận vào: Một đối tượng c_vector khác (tham chiếu hằng).
 * Cho ra: Tham chiếu đến chính đối tượng c_vector hiện tại.
 * Giải thuật: Kiểm tra địa chỉ để tránh tự gán. Xóa mảng bộ nhớ cũ của đối tượng hiện tại, sau đó cấp phát mảng mới và sao chép dữ liệu từ đối tượng truyền vào y hệt như hàm sao chép.
 */
c_vector& c_vector::operator=(const c_vector& khac) {
    if (this != &khac) {
        if (toa_do != nullptr) {
            delete[] toa_do;
        }
        so_chieu = khac.so_chieu;
        if (so_chieu > 0) {
            toa_do = new double[so_chieu];
            for (int i = 0; i < so_chieu; ++i) {
                toa_do[i] = khac.toa_do[i];
            }
        } else {
            toa_do = nullptr;
        }
    }
    return *this;
}

/*
 * Nhận vào: Một đối tượng c_vector khác (tham chiếu hằng).
 * Cho ra: Một đối tượng c_vector mới là tổng của hai vector.
 * Giải thuật: Kiểm tra xem hai vector có cùng số chiều hay không, nếu không thì báo lỗi và trả về vector rỗng. Nếu cùng, tạo một vector mới, lấy từng tọa độ tương ứng cộng lại với nhau.
 */
c_vector c_vector::operator+(const c_vector& khac) const {
    if (so_chieu != khac.so_chieu) {
        std::cerr << "loi: hai vector khong cung so chieu, khong the cong.\n";
        return c_vector();
    }
    c_vector ket_qua(so_chieu);
    for (int i = 0; i < so_chieu; ++i) {
        ket_qua.toa_do[i] = toa_do[i] + khac.toa_do[i];
    }
    return ket_qua;
}

/*
 * Nhận vào: Một số thực he_so_nhan.
 * Cho ra: Một đối tượng c_vector mới là kết quả của phép nhân vô hướng.
 * Giải thuật: Tạo một vector mới có cùng số chiều. Lấy từng tọa độ của vector hiện tại nhân với he_so_nhan rồi lưu vào vector mới.
 */
c_vector c_vector::operator*(double he_so_nhan) const {
    c_vector ket_qua(so_chieu);
    for (int i = 0; i < so_chieu; ++i) {
        ket_qua.toa_do[i] = toa_do[i] * he_so_nhan;
    }
    return ket_qua;
}

/*
 * Nhận vào: Luồng nhập (istream) và một đối tượng c_vector (tham chiếu).
 * Cho ra: Luồng nhập (istream) sau khi xử lý.
 * Giải thuật: Yêu cầu người dùng nhập số chiều. Thu hồi bộ nhớ mảng cũ (nếu có), cấp phát mảng mới theo số chiều vừa nhập, sau đó dùng vòng lặp để nhập từng giá trị tọa độ.
 */
std::istream& operator>>(std::istream& is, c_vector& v) {
    std::cout << "nhap so chieu cua vector: ";
    is >> v.so_chieu;

    if (v.toa_do != nullptr) {
        delete[] v.toa_do;
    }

    if (v.so_chieu > 0) {
        v.toa_do = new double[v.so_chieu];
        for (int i = 0; i < v.so_chieu; ++i) {
            std::cout << "nhap toa do thu " << i + 1 << ": ";
            is >> v.toa_do[i];
        }
    } else {
        v.toa_do = nullptr;
    }
    return is;
}

/*
 * Nhận vào: Luồng xuất (ostream) và một đối tượng c_vector (tham chiếu hằng).
 * Cho ra: Luồng xuất (ostream) sau khi xử lý.
 * Giải thuật: In vector ra màn hình theo định dạng chuẩn ngoặc đơn, ví dụ (x, y, z). Các tọa độ cách nhau bởi dấu phẩy.
 */
std::ostream& operator<<(std::ostream& os, const c_vector& v) {
    if (v.so_chieu == 0 || v.toa_do == nullptr) {
        os << "()";
        return os;
    }
    os << "(";
    for (int i = 0; i < v.so_chieu; ++i) {
        os << v.toa_do[i];
        if (i < v.so_chieu - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}
