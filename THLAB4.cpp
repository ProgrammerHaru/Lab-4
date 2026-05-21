#include <iostream>
#include "SoPhuc.h"

int main() {
    // Kiểm tra phương thức thiết lập duy nhất
    SoPhuc spMacDinh;         // Khởi tạo mặc định
    SoPhuc spTuSoThuc(5.5);   // Coi số thực 5.5 như số phức đặc biệt
    SoPhuc spDayDu(3.0, 4.0); // Số phức đầy đủ

    std::cout << "Test Constructor" << std::endl;
    std::cout << "Sp mac dinh: " << spMacDinh << std::endl;
    std::cout << "Sp tu so thuc: " << spTuSoThuc << std::endl;
    std::cout << "Sp day du: " << spDayDu << std::endl << std::endl;

    // Nhập/xuất dữ liệu
    SoPhuc A, B;
    std::cout << "Nhap so phuc A" << std::endl;
    std::cin >> A;
    std::cout << "Nhap so phuc B" << std::endl;
    std::cin >> B;

    // Kiểm tra các phép toán số học
    std::cout << "\nKet qua cac phep toan" << std::endl;
    std::cout << "A + B = " << (A + B) << std::endl;
    std::cout << "A - B = " << (A - B) << std::endl;
    std::cout << "A * B = " << (A * B) << std::endl;
    std::cout << "A / B = " << (A / B) << std::endl;

    // Kiểm tra các phép toán so sánh
    std::cout << "\nKet qua so sanh" << std::endl;
    if (A == B) {
        std::cout << "A bang B" << std::endl;
    }
    if (A != B) {
        std::cout << "A khac B" << std::endl;
    }

    
    std::cout << "\n Test tinh tuong thich voi so thuc" << std::endl;
    SoPhuc C = A + 10.0; // Tự động biến 10.0 thành SoPhuc(10.0, 0.0) rồi thực hiện phép cộng
    std::cout << "A + 10.0 = " << C << std::endl;

    return 0;
}