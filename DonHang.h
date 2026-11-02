// khai báo lớp cha với mã đơn hàng, ngày đặt hàng, gói vận chuyển (cơ bản, nhanh, hỏa tốc) 
// khai báo phương thức truy cập và giao diện phương thức ảo.
#include <iostream>
#include <string>
using namespace std;
class DonHang {
private:
    string MaDonHang;
    string NgayDatHang;
    string GoiVanChuyen;
protected:
    void XuatThongTinChung(ostream& out) const;
public:
    DonHang();
    DonHang(string MaDonHang, string NgayDatHang, string GoiVanChuyen);
    DonHang(const DonHang& other);
    virtual ~DonHang();
    string GetMaDonHang() const;
    string GetNgayDatHang() const;
    string GetGoiVanChuyen() const;

    void SetMaDonHang(string ma);
    void SetNgayDatHang(string ngay);
    void SetGoiVanChuyen(string goi);
    virtual void Nhap(istream& in);

    virtual void InThongTin(ostream& out) const;

    virtual double TinhTongTien() const = 0;
};
istream& operator>>(istream& in, DonHang& donHang);
ostream& operator<<(ostream& out, const DonHang& donHang);
