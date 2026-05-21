#ifndef CMATRIX_H
#define CMATRIX_H
#include <iostream>
// Định nghĩa lớp CVector tối giản để phục vụ riêng cho phép nhân Ma trận x Vector
class CVector {
private:
    int n;
    double* v;
public:
    CVector(int dimensions = 0);
    CVector(const CVector& other);
    CVector& operator=(const CVector& other);
    ~CVector();

    int getSoChieu() const { return n; }
    double getGiaTri(int i) const { return v[i]; }
    void setGiaTri(int i, double val) { if (i >= 0 && i < n) v[i] = val; }

    friend std::ostream& operator<<(std::ostream& os, const CVector& vec);
    friend std::istream& operator>>(std::istream& is, CVector& vec);
};
// Khai báo lớp CMatrix
class CMatrix {
private:
    int soDong;
    int soCot;
    double** data;

public:
    CMatrix(int r = 0, int c = 0);
    CMatrix(const CMatrix& other);
    CMatrix& operator=(const CMatrix& other);
    ~CMatrix();
    // Các phép toán đại số
    CMatrix operator+(const CMatrix& other) const;
    CMatrix operator-(const CMatrix& other) const;
    CMatrix operator*(const CMatrix& other) const; // Tích 2 ma trận
    CVector operator*(const CVector& vec) const;   // Tích Ma trận x Vector

    // Nhập xuất dữ liệu
    friend std::ostream& operator<<(std::ostream& os, const CMatrix& mat);
    friend std::istream& operator>>(std::istream& is, CMatrix& mat);
};

#endif // CMATRIX_H