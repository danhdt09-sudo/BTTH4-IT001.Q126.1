#include "so_phuc.h"

int main() {
    so_phuc sp_1;
    so_phuc sp_2;

    std::cout << "--- nhap so phuc 1 ---\n";
    std::cin >> sp_1;

    std::cout << "--- nhap so phuc 2 ---\n";
    std::cin >> sp_2;

    std::cout << "\nso phuc 1: " << sp_1 << "\n";
    std::cout << "so phuc 2: " << sp_2 << "\n";

    so_phuc tong = sp_1 + sp_2;
    std::cout << "tong: " << tong << "\n";

    so_phuc hieu = sp_1 - sp_2;
    std::cout << "hieu: " << hieu << "\n";

    so_phuc tich = sp_1 * sp_2;
    std::cout << "tich: " << tich << "\n";

    so_phuc thuong = sp_1 / sp_2;
    std::cout << "thuong: " << thuong << "\n";

    if (sp_1 == sp_2) {
        std::cout << "hai so phuc bang nhau.\n";
    }

    if (sp_1 != sp_2) {
        std::cout << "hai so phuc khac nhau.\n";
    }

    return 0;
}
