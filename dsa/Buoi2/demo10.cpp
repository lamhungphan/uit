#include <iostream>
using namespace std;

typedef struct NhanVien
{
    int maNV;
    string hoTen;
    float luongCB;
    int soNg;
    float luongHT;
} NV;

void inNV(NhanVien nv)
{
    cout << "[" << nv.maNV << ", "
         << nv.hoTen << ", "
         << nv.luongCB << ", "
         << nv.soNg << ", "
         << nv.luongHT << "]"
         << endl;
}

void printArr(NV* a, int n)
{
    for(int i = 0; i < n; i++){
        inNV(*(a + i));
    }
}

// Tính lương sử dụng con trỏ
void tinhLuongNV(NhanVien* nv)
{
    nv->luongHT = nv->luongCB + nv->soNg * 180000;
}

// Tính lương sử dụng tham chiếu
void tinhLuongNV2(NhanVien& nv)
{
    nv.luongHT = nv.luongCB + nv.soNg * 180000;
}

void tinhLuongHT(NV* a, int n)
{
    for(int i = 0; i < n; i++){
        tinhLuongNV(a + i);
    }
}

int initDataNV(NV* a, int& n)
{
    *a       = {123, "Nguyen Van A", 5e6, 23, 0};
    *(a + 1) = {124, "Nguyen Van B", 4e6, 21, 0};
    *(a + 2) = {125, "Nguyen Van C", 6.5e6, 22, 0};

    return n = 3;
}

int main()
{
    NhanVien* a = new NhanVien[1000];
    int n = 0;

    cout << "Test: 1. Tao va in du lieu ban dau" << endl;
    initDataNV(a, n);
    printArr(a, n);

    cout << "\nTest: 2. Tinh luong thuc te va in lai" << endl;
    tinhLuongHT(a, n);
    printArr(a, n);

    delete[] a;

    return 0;
}