#include "CDate.h"
#include <cmath>

// Constructor
CDate::CDate(int d, int m, int y) : ngay(d), thang(m), nam(y) {
    if (!LaNgayHopLe()) {
        ngay = 1; thang = 1; nam = 2026; // Trả về ngày mặc định nếu không hợp lệ
    }
}
// Kiểm tra năm nhuận
bool CDate::LaNamNhuan(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}
// Trả về số ngày tối đa trong tháng
int CDate::SoNgayTrongThang(int m, int y) {
    switch (m) {
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return LaNamNhuan(y) ? 29 : 28;
    default:
        return 31;
    }
}
// Kiểm tra ngày hiện tại có hợp lệ không
bool CDate::LaNgayHopLe() const {
    if (nam < 1 || thang < 1 || thang > 12) return false;
    if (ngay < 1 || ngay > SoNgayTrongThang(thang, nam)) return false;
    return true;
}
// Tiền tố tăng ++
CDate& CDate::operator++() {
    ngay++;
    if (ngay > SoNgayTrongThang(thang, nam)) {
        ngay = 1;
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }
    return *this;
}
// Hậu tố tăng ++
CDate CDate::operator++(int) {
    CDate temp = *this;
    ++(*this);
    return temp;
}
// Tiền tố giảm --
CDate& CDate::operator--() {
    ngay--;
    if (ngay < 1) {
        thang--;
        if (thang < 1) {
            thang = 12;
            nam--;
        }
        ngay = SoNgayTrongThang(thang, nam);
    }
    return *this;
}
// Hậu tố giảm --
CDate CDate::operator--(int) {
    CDate temp = *this;
    --(*this);
    return temp;
}
// Cộng thêm một số nguyên ngày
CDate CDate::operator+(int days) const {
    CDate temp = *this;
    if (days > 0) {
        for (int i = 0; i < days; ++i) ++temp;
    }
    else {
        for (int i = 0; i < -days; ++i) --temp;
    }
    return temp;
}
// Trừ đi một số nguyên ngày
CDate CDate::operator-(int days) const {
    return *this + (-days);
}
// So sánh nhỏ hơn
bool CDate::operator<(const CDate& other) const {
    if (nam != other.nam) return nam < other.nam;
    if (thang != other.thang) return thang < other.thang;
    return ngay < other.ngay;
}
// So sánh bằng
bool CDate::operator==(const CDate& other) const {
    return (nam == other.nam && thang == other.thang && ngay == other.ngay);
}
// Tính khoảng cách số ngày giữa hai mốc CDate
int CDate::operator-(const CDate& other) const {
    if (*this == other) return 0;
    int count = 0;
    if (other < *this) {
        CDate temp = other;
        while (!(temp == *this)) {
            ++temp;
            count++;
        }
        return count;
    }
    else {
        CDate temp = *this;
        while (!(temp == other)) {
            ++temp;
            count++;
        }
        return -count; // Trả về số âm nếu ngày hiện tại đứng trước ngày truyền vào
    }
}
// Toán tử xuất <<
std::ostream& operator<<(std::ostream& os, const CDate& date) {
    if (date.ngay < 10) os << "0";
    os << date.ngay << "/";
    if (date.thang < 10) os << "0";
    os << date.thang << "/" << date.nam;
    return os;
}
// Toán tử nhập >>
std::istream& operator>>(std::istream& is, CDate& date) {
    do {
        std::cout << "  Nhap ngay, thang, nam (cach nhau boi dau cach): ";
        is >> date.ngay >> date.thang >> date.nam;
        if (!date.LaNgayHopLe()) {
            std::cout << "  => Ngay khong hop le! Vui long nhap lai.\n";
        }
    } while (!date.LaNgayHopLe());
    return is;
}