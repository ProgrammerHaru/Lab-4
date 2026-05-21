#ifndef CTIME_H
#define CTIME_H

#include <iostream>

class CTime {
private:
    int gio;
    int phut;
    int giay;

    // Hàm bổ trợ quy đổi toàn bộ thời gian ra giây và ngược lại để tính toán chính xác
    int ToToTalGiay() const;
    void TuTotalGiay(int totalGiay);

public:
    // Constructor mặc định và tham số
    CTime(int h = 0, int m = 0, int s = 0);

    // Phép toán cộng, trừ thêm một số nguyên giây
    CTime operator+(int s) const;
    CTime operator-(int s) const;

    // Toán tử tăng (Prefix và Postfix)
    CTime& operator++();    // ++t
    CTime operator++(int);  // t++

    // Toán tử giảm (Prefix và Postfix)
    CTime& operator--();    // --t
    CTime operator--(int);  // t--

    // Hàm hiển thị đồng hồ tại một góc cố định (sử dụng ANSI Escape Codes)
    void HienThiGocManHinh() const;

    // Phép toán nhập xuất dữ liệu
    friend std::ostream& operator<<(std::ostream& os, const CTime& t);
    friend std::istream& operator>>(std::istream& is, CTime& t);
};

#endif // CTIME_H