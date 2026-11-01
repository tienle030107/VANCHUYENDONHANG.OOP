#include <bits/stdc++.h>

using namespace std;

class DonHangTrongNuoc: public DonHang{
    double PhiVanChuyen;
    double PhiPhatSinh;
public:
    //constructor
    DonHangTrongNuoc(string _MaDonHang="", string _NgayDatHang="", string _GoiVanChuyen="co ban",double _PhiVanChuyen=0,double _PhiPhatSinh=0);
    DonHangTrongNuoc(const DonHangTrongNuoc &h);
    ~DonHangTrongNuoc();
    //get-set
    void setPhiVanChuyen(double t);
    double getPhiVanChuyen();
    void setPhiPhatSinh(double t);
    double getPhatSinh();
    //extend
    double TinhTongTien() const override;
    void Nhap(istream &is) override;
    void InThongTin(ostream &out) const override;
};

