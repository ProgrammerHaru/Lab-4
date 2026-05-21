#include "CMatrix.h"
#include <iomanip>
CVector::CVector(int dimensions) {
    n = (dimensions < 0) ? 0 : dimensions;
    v = (n > 0) ? new double[n] {0.0} : nullptr;
}
CVector::CVector(const CVector& other) {
    n = other.n;
    v = (n > 0) ? new double[n] : nullptr;
    for (int i = 0; i < n; ++i) v[i] = other.v[i];
}
CVector& CVector::operator=(const CVector& other) {
    if (this != &other) {
        delete[] v;
        n = other.n;
        v = (n > 0) ? new double[n] : nullptr;
        for (int i = 0; i < n; ++i) v[i] = other.v[i];
    }
    return *this;
}
CVector::~CVector() { delete[] v; }
std::ostream& operator<<(std::ostream& os, const CVector& vec) {
    os << "(";
    for (int i = 0; i < vec.n; ++i) {
        os << vec.v[i];
        if (i < vec.n - 1) os << ", ";
    }
    os << ")";
    return os;
}
std::istream& operator>>(std::istream& is, CVector& vec) {
    std::cout << "Nhap so chieu cua Vector: ";
    is >> vec.n;
    delete[] vec.v;
    vec.v = (vec.n > 0) ? new double[vec.n] : nullptr;
    for (int i = 0; i < vec.n; ++i) {
        std::cout << "  Thanh phan [" << i + 1 << "]: ";
        is >> vec.v[i];
    }
    return is;
}
CMatrix::CMatrix(int r, int c) {
    soDong = (r < 0) ? 0 : r;
    soCot = (c < 0) ? 0 : c;
    if (soDong > 0 && soCot > 0) {
        data = new double* [soDong];
        for (int i = 0; i < soDong; ++i) {
            data[i] = new double[soCot] {0.0};
        }
    }
    else data = nullptr;
}
CMatrix::CMatrix(const CMatrix& other) {
    soDong = other.soDong;
    soCot = other.soCot;
    if (soDong > 0 && soCot > 0) {
        data = new double* [soDong];
        for (int i = 0; i < soDong; ++i) {
            data[i] = new double[soCot];
            for (int j = 0; j < soCot; ++j) data[i][j] = other.data[i][j];
        }
    }
    else data = nullptr;
}
CMatrix& CMatrix::operator=(const CMatrix& other) {
    if (this != &other) {
        if (data != nullptr) {
            for (int i = 0; i < soDong; ++i) delete[] data[i];
            delete[] data;
        }
        soDong = other.soDong; soCot = other.soCot;
        if (soDong > 0 && soCot > 0) {
            data = new double* [soDong];
            for (int i = 0; i < soDong; ++i) {
                data[i] = new double[soCot];
                for (int j = 0; j < soCot; ++j) data[i][j] = other.data[i][j];
            }
        }
        else data = nullptr;
    }
    return *this;
}

CMatrix::~CMatrix() {
    if (data != nullptr) {
        for (int i = 0; i < soDong; ++i) delete[] data[i];
        delete[] data;
    }
}
CMatrix CMatrix::operator+(const CMatrix& other) const {
    if (soDong != other.soDong || soCot != other.soCot) {
        std::cerr << "Loi: Khong cung kich thuoc!\n"; return CMatrix(0, 0);
    }
    CMatrix res(soDong, soCot);
    for (int i = 0; i < soDong; ++i)
        for (int j = 0; j < soCot; ++j) res.data[i][j] = data[i][j] + other.data[i][j];
    return res;
}
CMatrix CMatrix::operator-(const CMatrix& other) const {
    if (soDong != other.soDong || soCot != other.soCot) {
        std::cerr << "Loi: Khong cung kich thuoc!\n"; return CMatrix(0, 0);
    }
    CMatrix res(soDong, soCot);
    for (int i = 0; i < soDong; ++i)
        for (int j = 0; j < soCot; ++j) res.data[i][j] = data[i][j] - other.data[i][j];
    return res;
}
// Tích 2 ma trận (m x n) * (n x p) = (m x p)
CMatrix CMatrix::operator*(const CMatrix& other) const {
    if (soCot != other.soDong) {
        std::cerr << "Loi: So cot ma tran truoc phai bang so dong ma tran sau!\n";
        return CMatrix(0, 0);
    }
    CMatrix res(soDong, other.soCot);
    for (int i = 0; i < soDong; ++i) {
        for (int j = 0; j < other.soCot; ++j) {
            for (int k = 0; k < soCot; ++k) res.data[i][j] += data[i][k] * other.data[k][j];
        }
    }
    return res;
}
// Tích Ma trận (m x n) * Vector (n chieu) = Vector (m chieu)
CVector CMatrix::operator*(const CVector& vec) const {
    if (soCot != vec.getSoChieu()) {
        std::cerr << "Loi: Kich thuoc ma tran va vector khong tuong thich!\n";
        return CVector(0);
    }
    CVector res(soDong);
    for (int i = 0; i < soDong; ++i) {
        double tong = 0;
        for (int j = 0; j < soCot; ++j) tong += data[i][j] * vec.getGiaTri(j);
        res.setGiaTri(i, tong);
    }
    return res;
}
std::ostream& operator<<(std::ostream& os, const CMatrix& mat) {
    if (mat.data == nullptr) return os << "[]";
    for (int i = 0; i < mat.soDong; ++i) {
        for (int j = 0; j < mat.soCot; ++j) os << std::setw(8) << mat.data[i][j] << " ";
        os << "\n";
    }
    return os;
}
std::istream& operator>>(std::istream& is, CMatrix& mat) {
    std::cout << "Nhap so dong: "; is >> mat.soDong;
    std::cout << "Nhap so cot: "; is >> mat.soCot;

    if (mat.data != nullptr) {
        for (int i = 0; i < mat.soDong; ++i) delete[] mat.data[i];
        delete[] mat.data;
    }
    if (mat.soDong > 0 && mat.soCot > 0) {
        mat.data = new double* [mat.soDong];
        for (int i = 0; i < mat.soDong; ++i) {
            mat.data[i] = new double[mat.soCot];
            for (int j = 0; j < mat.soCot; ++j) {
                std::cout << "  Phan tu [" << i + 1 << "][" << j + 1 << "]: ";
                is >> mat.data[i][j];
            }
        }
    }
    else mat.data = nullptr;
    return is;
}