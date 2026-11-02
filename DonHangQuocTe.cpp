#include <bits/stdc++.h>
#include "DonHang (2).h"
#include "DonHangQuocTe.h"
using namespace std;

DonHangQuocTe::DonHangQuocTe(string _MaDonHang, string _NgayDatHang, string _GoiVanChuyen,double _PhiHaiQuan,double _PhiPhatSinh):DonHang(_MaDonHang,_NgayDatHang,_GoiVanChuyen)
{
    PhiHaiQuan=_PhiHaiQuan;
    PhiPhatSinh=_PhiPhatSinh;
}
DonHangQuocTe::DonHangQuocTe(const DonHangQuocTe &h):DonHang(h)
{
    PhiHaiQuan=h.PhiHaiQuan;
    PhiPhatSinh=h.PhiPhatSinh;
}
DonHangQuocTe::~DonHangQuocTe(){}
//get-set
void DonHangQuocTe::setPhiHaiQuan(double t)
{
    PhiHaiQuan=t;
}
double DonHangQuocTe::getPhiHaiQuan()
{
    return PhiHaiQuan;
}
void DonHangQuocTe::setPhiPhatSinh(double t)
{
    PhiPhatSinh=t;
}
double DonHangQuocTe::getPhiPhatSinh()
{
    return PhiPhatSinh;
}
//extend
double DonHangQuocTe::TinhTongTien() const
{
    return PhiPhatSinh+PhiHaiQuan;
}
void DonHangQuocTe::Nhap(istream &is)
{
    DonHang::Nhap(is);
    is>>PhiHaiQuan>>PhiPhatSinh;
}
void DonHangQuocTe::InThongTin(ostream& out) const
{
    XuatThongTinChung(out);
    out<<"Phi Hai Quan: "<<PhiHaiQuan<<endl;
    out<<"Phi Phat Sinh: "<<PhiPhatSinh<<endl;
    out<<"Tinh Tong Tien: "<<TinhTongTien()<<endl;
}

