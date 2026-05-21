#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>

class PhanSo {
private:
    int tu;  // Tử số
    int mau; // Mẫu số

    // Hàm bổ trợ tìm ước chung lớn nhất và rút gọn phân số
    int UCLN(int a, int b) const;
    void RutGon();

public:
    // Phương thức thiết lập sử dụng tham số mặc định
    // Nếu chỉ truyền 1 số nguyên tử số, mẫu số sẽ tự động bằng 1
    PhanSo(int t = 0, int m = 1);

    // Các phép toán số học
    PhanSo operator+(const PhanSo& other) const;
    PhanSo operator-(const PhanSo& other) const;
    PhanSo operator*(const PhanSo& other) const;
    PhanSo operator/(const PhanSo& other) const;

    // Các phép toán so sánh
    bool operator==(const PhanSo& other) const;
    bool operator<(const PhanSo& other) const;
    bool operator>(const PhanSo& other) const;

    // Phép toán nhập xuất dữ liệu
    friend std::ostream& operator<<(std::ostream& os, const PhanSo& ps);
    friend std::istream& operator>>(std::istream& is, PhanSo& ps);
};

#endif