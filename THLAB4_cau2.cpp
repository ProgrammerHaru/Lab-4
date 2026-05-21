#include <iostream>
#include "PhanSo.h"

int main() {
    // Kiểm tra phương thức thiết lập mặc định và thiết lập với số nguyên
    PhanSo psMacDinh;       // Khởi tạo mặc định: 0/1 (tức là 0)
    PhanSo psTuSoNguyen(7); // Số nguyên 7 coi như phân số đặc biệt: 7/1
    PhanSo psDayDu(6, 8);   // Phân số đầy đủ: 6/8 -> tự động rút gọn thành 3/4

    std::cout << "Test Constructor" << std::endl;
    std::cout << "Phan so mac dinh: " << psMacDinh << std::endl;
    std::cout << "Phan so tu so nguyen 7: " << psTuSoNguyen << std::endl;
    std::cout << "Phan so 6/8 sau khi khoi tao: " << psDayDu << std::endl << std::endl;

    // Thử nghiệm nhập/xuất dữ liệu
    PhanSo A, B;
    std::cout << "Nhap phan so A" << std::endl;
    std::cin >> A;
    std::cout << "Nhap phan so B" << std::endl;
    std::cin >> B;

    // Kiểm tra các phép toán số học
    std::cout << "\nKet qua cac phep toan" << std::endl;
    std::cout << "A + B = " << (A + B) << std::endl;
    std::cout << "A - B = " << (A - B) << std::endl;
    std::cout << "A * B = " << (A * B) << std::endl;
    std::cout << "A / B = " << (A / B) << std::endl;

    // Kiểm tra các phép toán so sánh
    std::cout << "\nKet qua so sanh" << std::endl;
    if (A == B) std::cout << "A bang B" << std::endl;
    if (A < B)  std::cout << "A nho hen B" << std::endl;
    if (A > B)  std::cout << "A lon hon B" << std::endl;

    // Kiểm tra tính tương thích/ép kiểu tự động với số nguyên
    std::cout << "\nTest tinh tuong thich voi so nguyen" << std::endl;
    PhanSo C = A + 5; // Tự hiểu là phân số A cộng với phân số 5/1
    std::cout << "A + 5 = " << C << std::endl;

    return 0;
}