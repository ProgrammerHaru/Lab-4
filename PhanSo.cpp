#include "PhanSo.h"
#include <cmath>
// Hàm tìm ước chung lớn nhất
int PhanSo::UCLN(int a, int b) const {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
// Hàm rút gọn phân số và chuẩn hóa dấu của mẫu số
void PhanSo::RutGon() {
    if (mau == 0) return; // Tránh lỗi chia cho 0

    // Đẩy dấu trừ lên tử nếu mẫu âm
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
    int ucln = UCLN(tu, mau);
    tu /= ucln;
    mau /= ucln;
}
// Constructor duy nhất
PhanSo::PhanSo(int t, int m) : tu(t), mau(m) {
    if (mau == 0) {
        std::cerr << "Canh bao: Mau so bang 0! Tu dong chuyen mau ve 1\n";
        mau = 1;
    }
    RutGon(); // Luôn rút gọn ngay khi khởi tạo
}
// Phép cộng: a/b + c/d = (ad + bc) / bd
PhanSo PhanSo::operator+(const PhanSo& other) const {
    return PhanSo(tu * other.mau + other.tu * mau, mau * other.mau);
}
// Phép trừ: a/b - c/d = (ad - bc) / bd
PhanSo PhanSo::operator-(const PhanSo& other) const {
    return PhanSo(tu * other.mau - other.tu * mau, mau * other.mau);
}
// Phép nhân: a/b * c/d = (ac) / (bd)
PhanSo PhanSo::operator*(const PhanSo& other) const {
    return PhanSo(tu * other.tu, mau * other.mau);
}
// Phép chia: a/b / c/d = (ad) / (bc)
PhanSo PhanSo::operator/(const PhanSo& other) const {
    if (other.tu == 0) {
        std::cerr << "Loi: Khong the chia cho phan so co tu bang 0!\n";
        return PhanSo(0, 1);
    }
    return PhanSo(tu * other.mau, mau * other.tu);
}
// Phép so sánh bằng (Do đã rút gọn ở mọi bước nên chỉ cần so sánh tử với tử, mẫu với mẫu)
bool PhanSo::operator==(const PhanSo& other) const {
    return (tu == other.tu && mau == other.mau);
}
// Phép so sánh nhỏ hơn: a/b < c/d <=> ad < bc (vì mẫu luôn dương)
bool PhanSo::operator<(const PhanSo& other) const {
    return (tu * other.mau < other.tu * mau);
}
// Phép so sánh lớn hơn
bool PhanSo::operator>(const PhanSo& other) const {
    return (tu * other.mau > other.tu * mau);
}
// Toán tử xuất dữ liệu <<
std::ostream& operator<<(std::ostream& os, const PhanSo& ps) {
    if (ps.mau == 1) {
        os << ps.tu; // Nếu mẫu bằng 1 thì chỉ in ra số nguyên
    }
    else {
        os << ps.tu << "/" << ps.mau;
    }
    return os;
}
// Toán tử nhập dữ liệu >>
std::istream& operator>>(std::istream& is, PhanSo& ps) {
    std::cout << "Nhap tu so: ";
    is >> ps.tu;
    do {
        std::cout << "Nhap mau so (khac 0): ";
        is >> ps.mau;
        if (ps.mau == 0) {
            std::cout << "Mau so khong the bang 0. Vui long nhap lai!\n";
        }
    } while (ps.mau == 0);

    ps.RutGon(); // Rút gọn ngay sau khi người dùng nhập xong
    return is;
}