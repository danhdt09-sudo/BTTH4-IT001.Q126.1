#include "phan_so.h"

int main() {
    phan_so ps_1;
    phan_so ps_2;

    std::cout << "--- nhap phan so 1 ---\n";
    std::cin >> ps_1;

    std::cout << "--- nhap phan so 2 ---\n";
    std::cin >> ps_2;

    std::cout << "\nphan so 1: " << ps_1 << "\n";
    std::cout << "phan so 2: " << ps_2 << "\n";

    phan_so tong = ps_1 + ps_2;
    std::cout << "tong: " << tong << "\n";

    phan_so hieu = ps_1 - ps_2;
    std::cout << "hieu: " << hieu << "\n";

    phan_so tich = ps_1 * ps_2;
    std::cout << "tich: " << tich << "\n";

    phan_so thuong = ps_1 / ps_2;
    std::cout << "thuong: " << thuong << "\n";

    if (ps_1 == ps_2) {
        std::cout << "hai phan so bang nhau.\n";
    } else if (ps_1 > ps_2) {
        std::cout << "phan so 1 lon hon phan so 2.\n";
    } else if (ps_1 < ps_2) {
        std::cout << "phan so 1 nho hon phan so 2.\n";
    }

    return 0;
}
