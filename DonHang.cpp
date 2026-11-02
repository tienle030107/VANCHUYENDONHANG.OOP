// cài đặt constructor, destructor, getter/setter, nhập/xuất và các phương thức chung.
#include "DonHang (2).h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;
namespace {
string CatKhoangTrang(std::string text) {
    size_t dau = text.find_first_not_of(" \t\r\n");
    if (dau == string::npos) {
        return "";
    }
    size_t cuoi = text.find_last_not_of(" \t\r\n");
    return text.substr(dau, cuoi - dau + 1);
}
    string ChuanHoaGoi(string goi) {
    goi = CatKhoangTrang(goi);
    if (goi == "1" || goi == "co ban") {
        return "co ban";
    }
    if (goi == "2" || goi == "nhanh") {
        return "nhanh";
    }
    if (goi == "3" || goi == "hoa toc") {
        return "hoa toc";
    }

    throw invalid_argument("Goi van chuyen phai la 1/co ban, 2/nhanh hoac 3/hoa toc.");
}
} 
DonHang::DonHang()
    : MaDonHang(""), NgayDatHang(""), GoiVanChuyen("co ban") {
}
DonHang::DonHang(string MaDonHang, string NgayDatHang, string GoiVanChuyen)
    : DonHang() {
    SetMaDonHang(MaDonHang);
    SetNgayDatHang(NgayDatHang);
    SetGoiVanChuyen(GoiVanChuyen);
}
DonHang::DonHang(const DonHang& other)
    : MaDonHang(other.MaDonHang),
      NgayDatHang(other.NgayDatHang),
      GoiVanChuyen(other.GoiVanChuyen) {
}
DonHang::~DonHang() {
}
string DonHang::GetMaDonHang() const {
    return MaDonHang;
}
string DonHang::GetNgayDatHang() const {
    return NgayDatHang;
}
string DonHang::GetGoiVanChuyen() const {
    return GoiVanChuyen;
}
void DonHang::SetMaDonHang(string ma) {
    ma = CatKhoangTrang(ma);
    if (ma.empty()) {
        throw invalid_argument("Ma don hang khong duoc rong.");
    }
    MaDonHang = ma;
}
void DonHang::SetNgayDatHang(string ngay) {
    ngay = CatKhoangTrang(ngay);
    if (ngay.empty()) {
        throw invalid_argument("Ngay dat hang khong duoc rong.");
    }
    NgayDatHang = ngay;
}
void DonHang::SetGoiVanChuyen(string goi) {
    GoiVanChuyen = ChuanHoaGoi(goi);
}
void DonHang::Nhap(std::istream& in) {
    string MaMoi;
    string NgayMoi;
    string GoiMoi;
    if (!getline(in >> ws, MaMoi) ||
        !getline(in, NgayMoi) ||
        !getline(in, GoiMoi)) {
        return;
    }
    MaMoi = CatKhoangTrang(MaMoi);
    NgayMoi = CatKhoangTrang(NgayMoi);
    if (MaMoi.empty() || NgayMoi.empty()) {
        in.setstate(ios::failbit);
        return;
    }
    try {
        GoiMoi = ChuanHoaGoi(GoiMoi);
    } catch (invalid_argument&) {
        in.setstate(ios::failbit);
        return;
    }
    MaDonHang = MaMoi;
    NgayDatHang = NgayMoi;
    GoiVanChuyen = GoiMoi;
}
void DonHang::XuatThongTinChung(ostream& out) const {
    out << "Ma don hang: " << MaDonHang << '\n';
    out << "Ngay dat hang: " << NgayDatHang << '\n';
    out << "Goi van chuyen: " << GoiVanChuyen << '\n';
}
void DonHang::InThongTin(ostream& out) const {
    XuatThongTinChung(out);
    ios::fmtflags CoCu = out.flags();
    streamsize DoChinhXacCu = out.precision();
    out << std::fixed << std::setprecision(2);
    out << "Tong tien: " << TinhTongTien() << endl;
    out.flags(CoCu);
    out.precision(DoChinhXacCu);
}
istream& operator>>(istream& in, DonHang& donHang) {
    donHang.Nhap(in);
    return in;
}
ostream& operator<<(ostream& out, const DonHang& donHang) {
    donHang.InThongTin(out);
    return out;
}
