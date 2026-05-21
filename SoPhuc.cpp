#include "SoPhuc.h"
SoPhuc::SoPhuc(double t, double a) : thuc(t), ao(a) {} // Triển khai constructor duy nhất
// Phép cộng: (a + bi) + (c + di) = (a + c) + (b + d)i
SoPhuc SoPhuc::operator+(const SoPhuc& other) const {
    return SoPhuc(thuc + other.thuc, ao + other.ao);
}
// Phép trừ: (a + bi) - (c + di) = (a - c) + (b - d)i
SoPhuc SoPhuc::operator-(const SoPhuc& other) const {
    return SoPhuc(thuc - other.thuc, ao - other.ao);
}
// Phép nhân: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
SoPhuc SoPhuc::operator*(const SoPhuc& other) const {
    return SoPhuc(thuc * other.thuc - ao * other.ao, thuc * other.ao + ao * other.thuc);
}
// Phép chia: nhân cả tử và mẫu cho số phức liên hợp của mẫu
SoPhuc SoPhuc::operator/(const SoPhuc& other) const {
    double mau = other.thuc * other.thuc + other.ao * other.ao;
    if (mau == 0) {
        std::cerr << "Loi: Khong the chia cho 0!" << std::endl;
        return SoPhuc(0, 0);
    }
    double tuThuc = thuc * other.thuc + ao * other.ao;
    double tuAo = ao * other.thuc - thuc * other.ao;
    return SoPhuc(tuThuc / mau, tuAo / mau);
}
bool SoPhuc::operator==(const SoPhuc& other) const {
    return (thuc == other.thuc && ao == other.ao);
}// Phép so sánh bằng
bool SoPhuc::operator!=(const SoPhuc& other) const {
    return !(*this == other); // Sử dụng lại toán tử ==
}// Phép so sánh khác
std::ostream& operator<<(std::ostream& os, const SoPhuc& sp) {
    os << sp.thuc;
    if (sp.ao >= 0) {
        os << " + " << sp.ao << "i";
    }
    else {
        os << " - " << -sp.ao << "i"; // Đảo dấu
    }
    return os;
}// Toán tử xuất dữ liệu <<
std::istream& operator>>(std::istream& is, SoPhuc& sp) {
    std::cout << "Nhap phan thuc: ";
    is >> sp.thuc;
    std::cout << "Nhap phan ao: ";
    is >> sp.ao;
    return is;
}// Toán tử nhập dữ liệu >>