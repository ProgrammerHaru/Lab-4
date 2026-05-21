#include <iostream>
#include "CMatrix.h"

int main() {
    CMatrix M1, M2;

    std::cout << "Nhap ma tran M1:\n";
    std::cin >> M1;
    std::cout << "\nMa tran M1:\n" << M1;

    std::cout << "\nNhap ma tran M2:\n";
    std::cin >> M2;
    std::cout << "\nMa tran M2:\n" << M2;

    std::cout << "Ket qua phep toan\n";

    std::cout << "M1 + M2 =\n" << (M1 + M2) << "\n";
    std::cout << "M1 * M2 =\n" << (M1 * M2) << "\n";

    std::cout << "Nhap vector V de tinh tich\n";
    CVector V;
    std::cin >> V;
    std::cout << "Vector V: " << V << "\n";

    CVector ketQua = M1 * V;
    std::cout << " -> Tich M1 * V = " << ketQua << "\n";

    return 0;
}