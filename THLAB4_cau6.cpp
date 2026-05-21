#include <iostream>
#include "CVector.h"

int main() {
    CVector V1, V2;

    std::cout << "Nhap vector V1\n";
    std::cin >> V1;
    std::cout << "Vector V1 = " << V1 << "\n\n";

    std::cout << "Nhap vector V2\n";
    std::cin >> V2;
    std::cout << "Vector V2 = " << V2 << "\n\n";

    std::cout << "Ket qua phep toan\n";

    // Kiểm tra phép cộng và trừ hai vector
    CVector tong = V1 + V2;
    CVector hieu = V1 - V2;
    std::cout << " V1 + V2 = " << tong << "\n";
    std::cout << " V1 - V2 = " << hieu << "\n";

    // Kiểm tra phép nhân vector với một số thực
    double k;
    std::cout << "\nNhap so thuc k de nhân: ";
    std::cin >> k;
    std::cout << " V1 * " << k << " = " << (V1 * k) << "\n";

    // Kiểm tra phép tính tích vô hướng
    double tichVoHuong = V1 * V2;
    std::cout << "\nTich vo huong (V1 . V2) = " << tichVoHuong << "\n";

    // Kiểm tra tính độ dài vector
    std::cout << "\nDo dai (module) cua vector V1 = " << V1.TinhDoDai() << "\n";
    std::cout << "Do dai (module) cua vector V2 = " << V2.TinhDoDai() << "\n";

    return 0;
}