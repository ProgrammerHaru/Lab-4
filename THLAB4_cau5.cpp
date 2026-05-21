#include <iostream>
#include "DaThuc.h"

int main() {
    DaThuc P, Q;

    std::cout << "Nhap da thuc P\n";
    std::cin >> P;
    std::cout << "Da thuc P vua nhap: " << P << "\n\n";

    std::cout << "Nhap da thuc Q\n";
    std::cin >> Q;
    std::cout << "Da thuc Q vua nhap: " << Q << "\n\n";

    // 1. Kiểm tra các phép toán đại số
    std::cout << "Ket qua phep toan\n";
    std::cout << " P + Q = " << (P + Q) << "\n";
    std::cout << " P - Q = " << (P - Q) << "\n";
    std::cout << " P * Q = " << (P * Q) << "\n\n";

    // 2. Tính giá trị đa thức tại một điểm x cụ thể
    double x;
    std::cout << "Enter gia tri x de tinh toan: ";
    std::cin >> x;
    std::cout << " -> Gia tri P(" << x << ") = " << P.TinhGiaTri(x) << "\n";
    std::cout << " -> Gia tri Q(" << x << ") = " << Q.TinhGiaTri(x) << "\n";

    return 0;
}