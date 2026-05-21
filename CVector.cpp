#include "CVector.h"
#include <cmath>

// Constructor khởi tạo vector n chiều mang giá trị 0
CVector::CVector(int dimensions) {
    n = (dimensions < 0) ? 0 : dimensions;
    if (n > 0) {
        v = new double[n];
        for (int i = 0; i < n; ++i) {
            v[i] = 0.0;
        }
    }
    else {
        v = nullptr;
    }
}
// Copy Constructor
CVector::CVector(const CVector& other) {
    n = other.n;
    if (n > 0) {
        v = new double[n];
        for (int i = 0; i < n; ++i) {
            v[i] = other.v[i];
        }
    }
    else {
        v = nullptr;
    }
}
// Copy Assignment Operator
CVector& CVector::operator=(const CVector& other) {
    if (this != &other) {
        delete[] v; // Giải phóng mảng hiện tại

        n = other.n;
        if (n > 0) {
            v = new double[n];
            for (int i = 0; i < n; ++i) {
                v[i] = other.v[i];
            }
        }
        else {
            v = nullptr;
        }
    }
    return *this;
}
// Destructor thu hồi bộ nhớ động
CVector::~CVector() {
    delete[] v;
}
// Tính độ dài vector: |v| = sqrt(v1^2 + v2^2 + ... + vn^2)
double CVector::TinhDoDai() const {
    double tongBinhPhuong = 0.0;
    for (int i = 0; i < n; ++i) {
        tongBinhPhuong += v[i] * v[i];
    }
    return std::sqrt(tongBinhPhuong);
}
// Phép toán cộng hai vector (yêu cầu phải cùng số chiều)
CVector CVector::operator+(const CVector& other) const {
    if (n != other.n) {
        std::cerr << "Loi: Khong the cong hai vector khac so chieu!\n";
        return CVector(0);
    }
    CVector ketQua(n);
    for (int i = 0; i < n; ++i) {
        ketQua.v[i] = v[i] + other.v[i];
    }
    return ketQua;
}
// Phép toán trừ hai vector
CVector CVector::operator-(const CVector& other) const {
    if (n != other.n) {
        std::cerr << "Loi: Khong the tru hai vector khac so chieu!\n";
        return CVector(0);
    }
    CVector ketQua(n);
    for (int i = 0; i < n; ++i) {
        ketQua.v[i] = v[i] - other.v[i];
    }
    return ketQua;
}
// Tích vô hướng của hai vector: v . u = v1*u1 + v2*u2 + ... + vn*un
double CVector::operator*(const CVector& other) const {
    if (n != other.n) {
        std::cerr << "Loi: Khong the tinh tich vo huong hai vector khac so chieu!\n";
        return 0.0;
    }
    double tichVoHuong = 0.0;
    for (int i = 0; i < n; ++i) {
        tichVoHuong += v[i] * other.v[i];
    }
    return tichVoHuong;
}
// Nhân một vector với một số thực k: k * v = (k*v1, k*v2, ..., k*vn)
CVector CVector::operator*(double k) const {
    CVector ketQua(n);
    for (int i = 0; i < n; ++i) {
        ketQua.v[i] = v[i] * k;
    }
    return ketQua;
}
// Toán tử xuất dữ liệu << dưới dạng định dạng chuẩn
std::ostream& operator<<(std::ostream& os, const CVector& vec) {
    if (vec.n == 0 || vec.v == nullptr) {
        os << "()";
        return os;
    }
    os << "(";
    for (int i = 0; i < vec.n; ++i) {
        os << vec.v[i];
        if (i < vec.n - 1) os << ", ";
    }
    os << ")";
    return os;
}
// Toán tử nhập dữ liệu >>
std::istream& operator>>(std::istream& is, CVector& vec) {
    std::cout << "Nhap so chieu cua vector: ";
    int dimensions;
    is >> dimensions;
    if (dimensions < 0) dimensions = 0;
    // Giải phóng dữ liệu cũ và chuẩn bị cấp phát mới
    delete[] vec.v;
    vec.n = dimensions;
    if (vec.n > 0) {
        vec.v = new double[vec.n];
        std::cout << "Nhap các thanh phan toa do:\n";
        for (int i = 0; i < vec.n; ++i) {
            std::cout << "  Thanh phan [" << i + 1 << "]: ";
            is >> vec.v[i];
        }
    }
    else {
        vec.v = nullptr;
    }
    return is;
}