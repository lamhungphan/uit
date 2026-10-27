#include <iostream>
using namespace std;

/* 1. Hàm khởi tạo giá trị
Input:
    + int* a
    + int& n

Output:
    + int* a
    + int& n
*/
void initDataArr(int *a, int &n)
{
    *a = 12;
    *(a + 1) = 23;
    *(a + 2) = 78;
    *(a + 3) = 56;
    n = 4;
}

/* 2. Hàm in giá trị mảng
Input:
    + int* a
    + int n

Output:
    + cout
*/
void printArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << endl;
    }
}

/* 3. Viết hàm tính tổng các giá trị trong mảng
Input:
    + int* a
    + int n

Output:
    + return int
*/
int tinhTong(int *a, int n)
{
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        t = t + *(a + i);
    }
    return t;
}

/*
Input:
    +
    +

Output:
    +
    +
*/
int main()
{

    int* a = new int[10000];
    int n = 0;
    
    cout << "Test: 1. Ham tao gia tri cho mang:" << endl;
    initDataArr(a, n);
    cout << "\t+ Ket qua: " << n << " phan tu." << endl;

    cout << "Test: 2. Ham in mang:" << endl;
    printArr(a, n);
    cout << "\t+ Ket qua: " << n << " phan tu." << endl;

    cout << "Test: 3. Tinh tong cac gia tri trong mang" << endl;
    int kq = tinhTong(a, n);
    cout << "\t+ Ket qua: " << kq << endl;

    // delete[] a;
    // a = nullptr;

    cout << "\nTest: " << endl;
    cout << "\t+ Ket qua:" << endl;

    return 0;
}
