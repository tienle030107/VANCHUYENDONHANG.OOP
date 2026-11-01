#include <bits/stdc++.h>

using namespace std;

class DonHangQuocTe: public DonHang{
    double PhiHaiQuan;
    double PhiPhatSinh;
public:
    //constructor
    DonHangQuocTe(string _MaDonHang="", string _NgayDatHang="", string _GoiVanChuyen="co ban",double _PhiHaiQuan=0,double _PhiPhatSinh=0);
    DonHangQuocTe(const DonHangQuocTe &h);
    ~DonHangQuocTe();
    //get-set
    void setPhiHaiQuan(double t);
    double getPhiHaiQuan();
    void setPhiPhatSinh(double t);
    double getPhiPhatSinh();
    //extend
    double TinhTongTien() const override;
    void Nhap(istream &is) override;
    void InThongTin(ostream &out) const override;
};

