#include "c_matrix.h"

int main() {
    c_matrix m_1;
    c_matrix m_2;

    std::cout << "--- NHAP MA TRAN 1 ---\n";
    std::cin >> m_1;

    std::cout << "\n--- NHAP MA TRAN 2 ---\n";
    std::cin >> m_2;

    std::cout << "\nMa tran 1:\n" << m_1;
    std::cout << "Ma tran 2:\n" << m_2;

    std::cout << "\n--- PHEP CONG ---\n";
    c_matrix tong = m_1 + m_2;
    std::cout << "Tong hai ma tran (M1 + M2):\n" << tong;

    std::cout << "\n--- PHEP NHAN MA TRAN VOI MA TRAN ---\n";
    c_matrix tich_mm = m_1 * m_2;
    std::cout << "Tich hai ma tran (M1 * M2):\n" << tich_mm;

    std::cout << "\n--- PHEP NHAN MA TRAN VOI VECTOR ---\n";
    c_vector v_1;
    std::cout << "Nhap vector de nhan voi Ma tran 1:\n";
    std::cin >> v_1;

    std::cout << "Vector vua nhap: " << v_1 << "\n";
    c_vector tich_mv = m_1 * v_1;
    std::cout << "Tich (Ma tran 1 * Vector): " << tich_mv << "\n";

    return 0;
}
