#include <iostream>
#include <vector>
#include <limits>
#include <memory>
#include "DonHang (2).h"
#include "DonHangTrongNuoc.h"
#include "DonHangQuocTe.h"
using namespace std;
void hienThiMenu() {
    cout << "\n========== QUAN LY VAN CHUYEN ==========\n";
    cout << "1. Them don hang\n";
    cout << "2. Hien thi danh sach don hang\n";
    cout << "3. Thoat chuong trinh\n";
    cout << "========================================\n";
    cout << "Nhap lua chon: ";
}
void themDonHang(vector<unique_ptr<DonHang>>& danhSach) {
    int loaiChon;
    cout << "\n1. Don hang trong nuoc\n";
    cout << "2. Don hang quoc te\n";
    cout << "Chon loai don hang: ";
    if (!(cin >> loaiChon) ||
        (loaiChon != 1 && loaiChon != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Loai don hang khong hop le!\n";
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    unique_ptr<DonHang> dh;
    if (loaiChon == 1) {
        dh = make_unique<DonHangTrongNuoc>();
    } else {
        dh = make_unique<DonHangQuocTe>();
    }
    if (!(cin >> *dh)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Du lieu don hang khong hop le!\n";
        return;
    }
    if (dh->GetMaDonHang().empty()) {
        cout << "Ma don hang khong duoc de trong!\n";
        return;
    }
    danhSach.push_back(move(dh));
    cout << "Them don hang thanh cong!\n";
}
void hienThiDanhSach(
    const vector<unique_ptr<DonHang>>& danhSach
) {
    if (danhSach.empty()) {
        cout << "\nDanh sach don hang dang rong!\n";
        return;
    }
    cout << "\n========== DANH SACH DON HANG ==========\n";
    for (size_t i = 0; i < danhSach.size(); i++) {
        cout << "\nDon hang thu " << i + 1 << '\n';
        cout << *danhSach[i];
    }
}
int main() {
    vector<unique_ptr<DonHang>> danhSach;
    int luaChon;
    do {
        hienThiMenu();
        if (!(cin >> luaChon)) {
            cout << "Vui long nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (luaChon) {
            case 1:
                themDonHang(danhSach);
                break;
            case 2:
                hienThiDanhSach(danhSach);
                break;
            case 3:
                cout << "Ket thuc chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (luaChon != 3);
    return 0;
}
