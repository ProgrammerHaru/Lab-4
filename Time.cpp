#include "Time.h"
#include <iomanip>
// Đổi giờ phút giây ra tổng số giây tính từ 00:00:00
int CTime::ToToTalGiay() const {
    return gio * 3600 + phut * 60 + giay;
}
// Từ tổng số giây chuyển ngược lại thành giờ, phút, giây hợp lệ
void CTime::TuTotalGiay(int totalGiay) {
    const int GIAY_MOT_NGAY = 86400;
    // Xử lý tràn ngày
    totalGiay = totalGiay % GIAY_MOT_NGAY;
    if (totalGiay < 0) {
        totalGiay += GIAY_MOT_NGAY;
    }
    gio = totalGiay / 3600;
    phut = (totalGiay % 3600) / 60;
    giay = totalGiay % 60;
}
// Constructor
CTime::CTime(int h, int m, int s) {
    int total = h * 3600 + m * 60 + s;
    TuTotalGiay(total);
}
// Cộng một số nguyên giây
CTime CTime::operator+(int s) const {
    CTime res;
    res.TuTotalGiay(this->ToToTalGiay() + s);
    return res;
}
// Trừ một số nguyên giây
CTime CTime::operator-(int s) const {
    CTime res;
    res.TuTotalGiay(this->ToToTalGiay() - s);
    return res;
}
// Tiền tố tăng ++t
CTime& CTime::operator++() {
    TuTotalGiay(ToToTalGiay() + 1);
    return *this;
}
// Hậu tố tăng t++
CTime CTime::operator++(int) {
    CTime temp = *this;
    TuTotalGiay(ToToTalGiay() + 1);
    return temp;
}
// Tiền tố giảm --t
CTime& CTime::operator--() {
    TuTotalGiay(ToToTalGiay() - 1);
    return *this;
}
// Hậu tố giảm t--
CTime CTime::operator--(int) {
    CTime temp = *this;
    TuTotalGiay(ToToTalGiay() - 1);
    return temp;
}
// Hiển thị đồng hồ ở góc trên bên phải màn hình console
void CTime::HienThiGocManHinh() const {
    // Sử dụng ANSI escape codes để điều khiển con trỏ:
    // \033[s  : Lưu vị trí con trỏ hiện tại của người dùng
    // \033[u  : Khôi phục lại vị trí con trỏ cũ để người dùng tiếp tục thao tác bên dưới mẫu
    std::cout << "\033[s"
        << "\033[1;65H"
        << "[ " << std::setfill('0')
        << std::setw(2) << gio << ":"
        << std::setw(2) << phut << ":"
        << std::setw(2) << giay << " ]"
        << "\033[u" << std::flush;
}
// Toán tử xuất <<
std::ostream& operator<<(std::ostream& os, const CTime& t) {
    os << std::setfill('0') << std::setw(2) << t.gio << ":"
        << std::setfill('0') << std::setw(2) << t.phut << ":"
        << std::setfill('0') << std::setw(2) << t.giay;
    return os;
}
// Toán tử nhập >>
std::istream& operator>>(std::istream& is, CTime& t) {
    int h, m, s;
    std::cout << "Nhap gio: "; is >> h;
    std::cout << "Nhap phut: "; is >> m;
    std::cout << "Nhap giay: "; is >> s;
    int total = h * 3600 + m * 60 + s;
    t.TuTotalGiay(total);
    return is;
}