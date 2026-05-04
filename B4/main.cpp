#include "c_date.h"
#include <iomanip>

int main() {
    c_date ngay_1;
    c_date ngay_2;

    std::cout << "--- Kiem tra cac phep toan cua c_date ---\n";
    std::cout << "Nhap ngay thu nhat:\n";
    std::cin >> ngay_1;

    std::cout << "\nNhap ngay thu hai:\n";
    std::cin >> ngay_2;

    std::cout << "\nNgay 1: " << ngay_1 << "\n";
    std::cout << "Ngay 2: " << ngay_2 << "\n";

    int khoang_cach = ngay_1 - ngay_2;
    std::cout << "Khoang cach tu ngay 1 den ngay 2 la: " << khoang_cach << " ngay.\n";

    c_date ngay_cong = ngay_1 + 45;
    std::cout << "Ngay 1 sau khi cong 45 ngay: " << ngay_cong << "\n";

    c_date ngay_tru = ngay_1 - 20;
    std::cout << "Ngay 1 sau khi tru 20 ngay: " << ngay_tru << "\n";

    std::cout << "\n--- BAI TOAN TINH LAI SUAT NGAN HANG ---\n";

    double tien_gui;
    double lai_suat_nam;
    c_date ngay_gui;
    c_date ngay_rut;

    std::cout << "Nhap so tien gui (VND): ";
    std::cin >> tien_gui;
    std::cout << "Nhap lai suat hang nam (%): ";
    std::cin >> lai_suat_nam;

    std::cout << "Nhap ngay bat dau gui:\n";
    std::cin >> ngay_gui;

    std::cout << "Nhap ngay rut tien:\n";
    std::cin >> ngay_rut;

    // Giải bài toán ngân hàng
    int so_ngay_gui = ngay_rut - ngay_gui;

    if (so_ngay_gui < 0) {
        std::cerr << "\nLoi: Ngay rut tien khong the nho hon ngay gui tien!\n";
    } else {
        // Công thức tính lãi: Tiền gửi * (Lãi suất / 100) * (Số ngày gửi / 365)
        double tien_lai = tien_gui * (lai_suat_nam / 100.0) * (so_ngay_gui / 365.0);
        double tong_tien_nhan = tien_gui + tien_lai;

        std::cout << "\n--- KET QUA TINH TOAN ---\n";
        std::cout << "Thoi gian da gui: " << so_ngay_gui << " ngay.\n";

        std::cout << std::fixed << std::setprecision(0);
        std::cout << "Tien lai nhan duoc: " << tien_lai << " VND\n";
        std::cout << "Tong so tien nhan duoc: " << tong_tien_nhan << " VND\n";
    }

    return 0;
}
