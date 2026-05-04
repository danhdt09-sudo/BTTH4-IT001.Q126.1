#include "c_time.h"
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <windows.h>

void in_goc_tren_phai() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {80, 0};
    SetConsoleCursorPosition(hConsole, pos);
}
#else

void in_goc_tren_phai() {
    std::cout << "\033[s\033[1;80H";
}
#endif

void tra_lai_con_tro() {
#ifndef _WIN32
    std::cout << "\033[u";
#endif
}

int main() {
    c_time thoi_gian;
    std::cout << "--- nhap thoi gian ban dau ---\n";
    std::cin >> thoi_gian;

    std::cout << "\nthoi gian ban dau: " << thoi_gian << "\n";

    c_time thoi_gian_cong = thoi_gian + 150;
    std::cout << "sau khi cong 150 giay: " << thoi_gian_cong << "\n";

    c_time thoi_gian_tru = thoi_gian - 4000;
    std::cout << "sau khi tru 4000 giay: " << thoi_gian_tru << "\n";

    for (int i = 0; i < 1000; ++i) {
        in_goc_tren_phai();
        std::cout << " [ Dong ho: " << thoi_gian << " ] ";
        tra_lai_con_tro();

        std::this_thread::sleep_for(std::chrono::seconds(1)); // Dừng 1 giây
        thoi_gian++; // Tăng thêm 1 giây
    }

    return 0;
}
