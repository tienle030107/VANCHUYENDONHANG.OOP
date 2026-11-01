#include <bits/stdc++.h>
#include "DonHang.h"
#include "DonHangTrongNuoc.h"
using namespace std;

DonHangTrongNuoc::DonHangTrongNuoc(string _MaDonHang, string _NgayDatHang, string _GoiVanChuyen,double _PhiVanChuyen,double _PhiPhatSinh):DonHang(_MaDonHang,_NgayDatHang,_GoiVanChuyen)
{
    PhiVanChuyen=_PhiVanChuyen;
    PhiPhatSinh=_PhiPhatSinh;
}
DonHangTrongNuoc::DonHangTrongNuoc(const DonHangTrongNuoc &h):DonHang(h)
{
    PhiVanChuyen=h.PhiVanChuyen;
    PhiPhatSinh=h.PhiPhatSinh;
}
DonHangTrongNuoc::~DonHangTrongNuoc(){}
//get-set
void DonHangTrongNuoc::setPhiVanChuyen(double t)
{
    PhiVanChuyen=t;
}
double DonHangTrongNuoc::getPhiVanChuyen()
{
    return PhiVanChuyen;
}
void DonHangTrongNuoc::setPhiPhatSinh(double t)
{
    PhiPhatSinh=t;
}
double DonHangTrongNuoc::getPhatSinh()
{
    return PhiPhatSinh;
}
//extend
double DonHangTrongNuoc::TinhTongTien() const
{
    return PhiPhatSinh+PhiVanChuyen;
}
void DonHangTrongNuoc::Nhap(istream &is)
{
    DonHang::Nhap(is);
    is>>PhiVanChuyen>>PhiPhatSinh;
}
void DonHangTrongNuoc::InThongTin(ostream& out) const
{
    XuatThongTinChung(out);
    out<<"Phi Van Chuyen: "<<PhiVanChuyen<<endl;
    out<<"Phi Phat Sinh: "<<PhiPhatSinh<<endl;
    out<<"Tinh Tong Tien: "<<TinhTongTien()<<endl;
}

