#include <iostream>
#include <string>
using namespace std;

// 1. Xây dựng cấu trúc dữ liệu SinhVien
struct SinhVien
{
    int maSV;
    string hoTen;
    float diemTB;
    string xepLoai;
};

// 2. Xây dựng cấu trúc node và cấu trúc danh sách liên kết đơn quản lý sinh viên
struct Node
{
    SinhVien data;
    Node* pNext;
};

struct List
{
    Node* pHead;
    Node* pTail;
};

// 3.
/* Khởi tạo địa chỉ Node từ một biến SinhVien
Input:
    + SinhVien sv

Output:
    + return Node*
*/
Node* initNode(SinhVien sv)
{
    Node* p = new Node;
    p->data = sv;
    p->pNext = nullptr;
    return p;
}

/* Khởi tạo danh sách liên kết đơn
Input:
    + List& l

Output:
    + return void
*/
void initList(List& l)
{
    l.pHead = nullptr;
    l.pTail = nullptr;
}

// 4.
/* Thêm một node sinh viên vào đầu danh sách
Input:
    + List& l
    + Node* p

Output:
    + return void
*/
void addHead(List& l, Node* p)
{
    if (p == nullptr) return;

    if (l.pHead == nullptr)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

// 5.
/* Thêm một node sinh viên vào cuối danh sách
Input:
    + List& l
    + Node* p

Output:
    + return void
*/
void addTail(List& l, Node* p)
{
    if (p == nullptr) return;

    if (l.pHead == nullptr)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

// 6. Khởi tạo dữ liệu cho danh sách sinh viên
/* Nạp dữ liệu kiểm thử vào danh sách sinh viên
Input:
    + List& l

Output:
    + return void
*/
void loadData(List& l)
{
    SinhVien ds[] = {
        {123, "Nguyen Van A", 9.1, ""},
        {124, "Nguyen Van B", 8.8, ""},
        {125, "Nguyen Van C", 9.1, ""},
        {126, "Nguyen Van D", 2.1, ""},
        {127, "Nguyen Van F", 9.7, ""},
        {128, "Nguyen Van G", 4.1, ""},
        {129, "Nguyen Van H", 8.3, ""},
        {130, "Nguyen Van K", 7.9, ""}
    };

    int n = sizeof(ds) / sizeof(ds[0]);
    for (int i = 0; i < n; i++)
    {
        addTail(l, initNode(ds[i]));
    }
}

// Hàm phụ trợ
/* In thông tin chi tiết của một sinh viên
Input:
    + SinhVien sv

Output:
    + return void
*/
void printSinhVien(SinhVien sv)
{
    cout << "Ma SV: " << sv.maSV
         << "\t| Ho ten: " << sv.hoTen
         << "\t| Diem TB: " << sv.diemTB
         << "\t| Xep loai: " << (sv.xepLoai.empty() ? "Chua xep loai" : sv.xepLoai) << endl;
}

// 7.
/* In toàn bộ danh sách sinh viên
Input:
    + List l

Output:
    + return void
*/
void printList(List l)
{
    if (l.pHead == nullptr)
    {
        cout << "Danh sach sinh vien rong!" << endl;
        return;
    }

    for (Node* p = l.pHead; p != nullptr; p = p->pNext)
    {
        printSinhVien(p->data);
    }
}

/* Tìm và in thông tin sinh viên kế cuối trong danh sách
Input:
    + List l

Output:
    + return void
*/
void printSecondLast(List l)
{
    if (l.pHead == nullptr || l.pHead->pNext == nullptr)
    {
        cout << "Danh sach co it hon 2 sinh vien, khong co sinh vien ke cuoi!" << endl;
        return;
    }

    Node* p = l.pHead;
    while (p->pNext != l.pTail)
    {
        p = p->pNext;
    }

    printSinhVien(p->data);
}

int main()
{
    List l;
    initList(l);

    loadData(l);

    cout << "=== DANH SACH SINH VIEN ===" << endl;
    printList(l);

    cout << "\n=== SINH VIEN KE CUOI ===" << endl;
    printSecondLast(l);

    return 0;
}