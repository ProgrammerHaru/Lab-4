#include "DaThuc.h"
#include <cmath>

// Hàm thu gọn đa thức nếu hệ số ở bậc cao nhất bằng 0
void DaThuc::ChuanHoa() {
    while (bac > 0 && heSo[bac] == 0) {
        bac--;
    }
}
// Constructor mặc định khởi tạo đa thức bậc b
DaThuc::DaThuc(int b) {
    bac = (b < 0) ? 0 : b;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; ++i) {
        heSo[i] = 0.0;
    }
}
// Copy Constructor
DaThuc::DaThuc(const DaThuc& other) {
    bac = other.bac;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; ++i) {
        heSo[i] = other.heSo[i];
    }
}
//  tử gán bằng
DaThuc& DaThuc::operator=(const DaThuc& other) {
    if (this != &other) {
        delete[] heSo;
        bac = other.bac;
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; ++i) {
            heSo[i] = other.heSo[i];
        }
    }
    return *this;
}
DaThuc::~DaThuc() {
    delete[] heSo;
}
// Tính giá trị đa thức P(x) bằng thuật toán Horner nhằm tối ưu số phép nhân
double DaThuc::TinhGiaTri(double x) const {
    double ketQua = heSo[bac];
    for (int i = bac - 1; i >= 0; --i) {
        ketQua = ketQua * x + heSo[i];
    }
    return ketQua;
}
// Phép toán cộng hai đa thức
DaThuc DaThuc::operator+(const DaThuc& other) const {
    int bacMax = std::max(bac, other.bac);
    DaThuc ketQua(bacMax);

    for (int i = 0; i <= bacMax; ++i) {
        double h1 = (i <= bac) ? heSo[i] : 0.0;
        double h2 = (i <= other.bac) ? other.heSo[i] : 0.0;
        ketQua.heSo[i] = h1 + h2;
    }
    ketQua.ChuanHoa();
    return ketQua;
}
// Phép toán trừ hai đa thức
DaThuc DaThuc::operator-(const DaThuc& other) const {
    int bacMax = std::max(bac, other.bac);
    DaThuc ketQua(bacMax);

    for (int i = 0; i <= bacMax; ++i) {
        double h1 = (i <= bac) ? heSo[i] : 0.0;
        double h2 = (i <= other.bac) ? other.heSo[i] : 0.0;
        ketQua.heSo[i] = h1 - h2;
    }
    ketQua.ChuanHoa();
    return ketQua;
}
// Phép toán nhân hai đa thức: Bậc kết quả = bậc P1 + bậc P2
DaThuc DaThuc::operator*(const DaThuc& other) const {
    int bacMoi = bac + other.bac;
    DaThuc ketQua(bacMoi);
    for (int i = 0; i <= bac; ++i) {
        for (int j = 0; j <= other.bac; ++j) {
            ketQua.heSo[i + j] += heSo[i] * other.heSo[j];
        }
    }
    ketQua.ChuanHoa();
    return ketQua;
}
// Toán tử xuất dữ liệu << dạng chuẩn đẹp
std::ostream& operator<<(std::ostream& os, const DaThuc& dt) {
    bool laDaThucKhong = true;
    for (int i = dt.bac; i >= 0; --i) {
        if (dt.heSo[i] == 0) continue;
        laDaThucKhong = false;
        // In dấu nối giữa các số hạng
        if (i < dt.bac && dt.heSo[i] > 0) os << " + ";
        if (dt.heSo[i] < 0) os << " - ";
        // In giá trị hệ số
        double triTuyetDoi = std::abs(dt.heSo[i]);
        if (triTuyetDoi != 1 || i == 0) {
            os << triTuyetDoi;
        }
        // In phần biến x
        if (i > 0) {
            os << "x";
            if (i > 1) os << "^" << i;
        }
    }
    if (laDaThucKhong) os << "0";
    return os;
}
// Toán tử nhập dữ liệu >>
std::istream& operator>>(std::istream& is, DaThuc& dt) {
    std::cout << "Nhap bac cua da thuc: ";
    int b;
    is >> b;
    if (b < 0) b = 0;
    // Làm sạch bộ nhớ cũ và cấp phát lại theo bậc mới
    delete[] dt.heSo;
    dt.bac = b;
    dt.heSo = new double[dt.bac + 1];
    std::cout << "Nhap cac he so tu bac 0 den bac " << dt.bac << ":\n";
    for (int i = 0; i <= dt.bac; ++i) {
        std::cout << "  He so bac " << i << ": ";
        is >> dt.heSo[i];
    }
    dt.ChuanHoa();
    return is;
}