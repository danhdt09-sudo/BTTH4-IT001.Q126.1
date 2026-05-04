#include "c_vector.h"

int main() {
    c_vector v_1;
    c_vector v_2;

    std::cout << "--- nhap vector thu nhat ---\n";
    std::cin >> v_1;

    std::cout << "\n--- nhap vector thu hai ---\n";
    std::cin >> v_2;

    std::cout << "\nvector 1: " << v_1 << "\n";
    std::cout << "vector 2: " << v_2 << "\n";

    c_vector tong = v_1 + v_2;
    // Nếu in ra rỗng "()" nghĩa là hai vector khác số chiều, lỗi đã được báo ở hàm cộng.
    std::cout << "tong hai vector (v1 + v2) = " << tong << "\n";

    double he_so;
    std::cout << "\nnhap he so de nhan voi vector 1: ";
    std::cin >> he_so;

    c_vector tich_vo_huong = v_1 * he_so;
    std::cout << "ket qua v1 * " << he_so << " = " << tich_vo_huong << "\n";

    return 0;
}
