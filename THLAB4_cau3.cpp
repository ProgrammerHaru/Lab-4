#include <iostream>
#include <thread>  // Để dùng hàm sleep ngủ 1 giây
#include <chrono>  // Quản lý thời gian thực của vòng lặp
#include "Time.h"

int main() {
    std::cout << "\033[2J\033[1;1H";

    CTime t;
    std::cout << "Khoi tao thoi gian ban dau\n";
    std::cin >> t;

    std::cout << "\nThoi gian ban dau ban vua nhap: " << t << std::endl;
    std::cout << "Thoi gian sau khi + 10 giây: " << (t + 10) << std::endl;
    std::cout << "Thoi gian sau khi - 70 giay: " << (t - 70) << std::endl;

    std::cout << "\nChuan bi kich hoat dong ho o goc phai man hinh...\n";
    std::cout << "Nhan Ctrl + C de thoat chuong trinh.\n\n";

    // In một vài dòng mẫu để chứng minh luồng nhập xuất bên dưới không bị ảnh hưởng bởi đồng hồ
    std::cout << "[Nhat ky he thong] Ung dung dang chay..." << std::endl;
    std::cout << "[Nhat ky he thong] Dong ho dang cap nhat lien tuc moi giay..." << std::endl;

    // Vòng lặp vô hạn mô phỏng đồng hồ chạy real-time
    while (true) {
        t.HienThiGocManHinh(); // In thời gian hiện tại lên góc màn hình

        // Luồng chương trình ngủ 1 giây trước khi tăng giây tiếp theo
        std::this_thread::sleep_for(std::chrono::seconds(1));

        t++; // Tăng thêm 1 giây
    }

    return 0;
}