#ifndef CDATE_H
#define CDATE_H

#include <iostream>

class CDate {
private:
    int ngay;
    int thang;
    int nam;

public:
    // Constructor mặc định và tham số
    CDate(int d = 1, int m = 1, int y = 2026);

    static bool LaNamNhuan(int y);
    static int SoNgayTrongThang(int m, int y);
    bool LaNgayHopLe() const;

    // Phép toán cộng, trừ thêm một số nguyên ngày
    CDate operator+(int days) const;
    CDate operator-(int days) const;

    // Toán tử tăng / giảm 1 ngày
    CDate& operator++();    // ++date
    CDate operator++(int);  // date++
    CDate& operator--();    // --date
    CDate operator--(int);  // date--

    // Toán tử trừ giữa hai mốc CDate để tính khoảng cách
    int operator-(const CDate& other) const;

    // Toán tử so sánh bổ trợ cho việc tính khoảng cách
    bool operator<(const CDate& other) const;
    bool operator==(const CDate& other) const;

    // Phép toán nhập xuất dữ liệu
    friend std::ostream& operator<<(std::ostream& os, const CDate& date);
    friend std::istream& operator>>(std::istream& is, CDate& date);
};

#endif