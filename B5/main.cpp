#include "da_thuc.h"

int main() {
    da_thuc dt;

    std::cout << "--- nhap thong tin da thuc ---\n";
    std::cin >> dt;

    std::cout << "\nda thuc vua nhap la: P(x) = " << dt << "\n";

    double x;
    std::cout << "\nnhap gia tri x de tinh P(x): ";
    std::cin >> x;

    double ket_qua = dt.tinh_gia_tri(x);
    std::cout << "P(" << x << ") = " << ket_qua << "\n";

    return 0;
}
