#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>

class CVector {
private:
    int n;          // Số chiều của vector
    double* v;      // Mảng động lưu các thành phần tọa độ của vector

public:
    // Các phương thức thiết lập và hủy
    CVector(int dimensions = 0);
    CVector(const CVector& other);
    CVector& operator=(const CVector& other);
    ~CVector();                                   // Destructor
    // Hàm lấy độ dài của vector
    double TinhDoDai() const;

    // Các phép toán đại số cơ bản trên Vector
    CVector operator+(const CVector& other) const;
    CVector operator-(const CVector& other) const;

    // Nạp chồng toán tử nhân '*' cho 2 trường hợp:
    double operator*(const CVector& other) const; // 1. Tích vô hướng của 2 vector
    CVector operator*(double k) const;            // 2. Nhân một vector với một số thực k

    // Toán tử nhập xuất dữ liệu
    friend std::ostream& operator<<(std::ostream& os, const CVector& vec);
    friend std::istream& operator>>(std::istream& is, CVector& vec);
};

#endif // CVECTOR_H