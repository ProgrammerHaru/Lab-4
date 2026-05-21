#include <iostream>
#include <iomanip>
#include "CDate.h"

int main() {
    std::cout << "Chuong trinh tinh lai suat tien gui\n";
    double soTienGui = 0;
    double laiSuatNam = 0; // đơn vị %/năm
    CDate ngayGui, ngayRut;
    // Nhập thông tin khoản gửi
    std::cout << "Nhap so tien muon gui (VND): ";
    std::cin >> soTienGui;
    std::cout << "Nhap lai suat hang nam (%/nam): ";
    std::cin >> laiSuatNam;
    std::cout << "Nhap ngay gui:\n";
    std::cin >> ngayGui;
    // Nhập ngày rút (phải lớn hơn hoặc bằng ngày gửi)
    do {
        std::cout << "Nhap ngay rut tien:\n";
        std::cin >> ngayRut;
        if (ngayRut < ngayGui) {
            std::cout << "  => Loi: Ngay rut khong the truoc ngay gui! Nhap lai.\n";
        }
    } while (ngayRut < ngayGui);
    // Áp dụng toán tử trừ của CDate để lấy số ngày gửi thực tế
    int soNgayGui = ngayRut - ngayGui;
    // Tính toán tiền lãi 
    // Công thức tính lãi theo ngày: Tiền gốc * (Lãi suất năm / 100) * (Số ngày gửi / 365)
    double tienLai = soTienGui * (laiSuatNam / 100.0) * (soNgayGui / 365.0);
    double tongNhan = soTienGui + tienLai;
    // In kết quả báo cáo
    std::cout << "Hoa don lai suat\n";
    std::cout << " - Ngay bat dau gui : " << ngayGui << "\n";
    std::cout << " - Ngay ket thuc rut: " << ngayRut << "\n";
    std::cout << " - Tong so ngay gui : " << soNgayGui << " ngay\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << " -> So tien goc     : " << soTienGui << " VND\n";
    std::cout << " -> Tien lai thu ve : " << tienLai << " VND\n";
    std::cout << " -> Tong tien nhan  : " << tongNhan << " VND\n";
    // Thử nghiệm thêm toán tử ++, -- và cộng số ngày để kiểm tra tính đúng đắn
    std::cout << "\n[Kiem tra bo sung] Ngay gui sau khi cong 100 ngay: " << (ngayGui + 100) << "\n";
    return 0;
}