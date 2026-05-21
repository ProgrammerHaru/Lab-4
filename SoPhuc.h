#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>

class SoPhuc {
private:
    double thuc;
    double ao;

public:
    // Giúp ngầm định hiểu một số thực là một số phức có phanAo = 0
    SoPhuc(double t = 0.0, double a = 0.0);

    // Các phép toán số học
    SoPhuc operator+(const SoPhuc& other) const;
    SoPhuc operator-(const SoPhuc& other) const;
    SoPhuc operator*(const SoPhuc& other) const;
    SoPhuc operator/(const SoPhuc& other) const;

    // Các phép toán so sánh
    bool operator==(const SoPhuc& other) const;
    bool operator!=(const SoPhuc& other) const;

    // Phép toán nhập xuất
    friend std::ostream& operator<<(std::ostream& os, const SoPhuc& sp);
    friend std::istream& operator>>(std::istream& is, SoPhuc& sp);
};

#endif