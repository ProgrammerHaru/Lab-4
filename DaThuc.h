#ifndef DATHUC_H
#define DATHUC_H

#include <iostream>

class DaThuc {
private:
    int bac;
    double* heSo;     // Mảng động lưu các hệ số

    void ChuanHoa();  // Hàm bổ trợ thu gọn bậc nếu hệ số bậc cao nhất bằng 0

public:
    // Các phương thức thiết lập và hủy
    DaThuc(int b = 0);
    DaThuc(const DaThuc& other);
    DaThuc& operator=(const DaThuc& other);
    ~DaThuc();

    // Tính giá trị của đa thức tại x bằng thuật toán Horner
    double TinhGiaTri(double x) const;

    // Các phép toán đại số
    DaThuc operator+(const DaThuc& other) const;
    DaThuc operator-(const DaThuc& other) const;
    DaThuc operator*(const DaThuc& other) const;

    // Toán tử nhập xuất dữ liệu
    friend std::ostream& operator<<(std::ostream& os, const DaThuc& dt);
    friend std::istream& operator>>(std::istream& is, DaThuc& dt);
};

#endif // DATHUC_H