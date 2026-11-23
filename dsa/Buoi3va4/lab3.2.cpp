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

// 8.
/*  Cập nhật xếp loại học lực
Input:
    + List l

Output:
    + return void
*/
void classifyPerfomance(List& l)
{
  if(l.pHead == nullptr) return;

  for (Node* p = l.pHead; p != nullptr; p= p->pNext){
    float diem = p->data.diemTB;

    if (diem >= 8.0f && diem <= 10.0f)
    {
        p->data.xepLoai = "Gioi";
    }
    else if (diem >= 6.5f)
    {
        p->data.xepLoai = "Kha";
    }
    else if (diem >= 5.0f)
    {
        p->data.xepLoai = "Trung binh";
    } else 
    {
        p->data.xepLoai = "Yeu";
    }
  }
}

// 9.
/* Tìm điểm trung bình cao nhất
Input:
    + List l

Output:
    + return float
*/
float findMaxScore(List& l)
{   
    if (l.pHead == nullptr)
        return 0.0f;

    float max = l.pHead->data.diemTB;

    for(Node* p = l.pHead; p != nullptr; p = p->pNext){
        if (p->data.diemTB > max)
        max = p->data.diemTB;
    }
    return max;
}

// 10.
/*  Tìm kiếm sinh viên theo mã sinh viên
Input:
    + int

Output:
    + return SinhVien
*/
SinhVien findSinhVienById(List& l, int maSV)
{
    for(Node* p = l.pHead; p != nullptr; p = p->pNext)
    {
        if(p->data.maSV == maSV){
            return p->data;
        }
    }
    return {0, "", 0.0f, ""};
}

// 11.
/*   Tìm SV có điểm trung bình cao nhất
Input:
    + List l

Output:
    + return SinhVien
*/
SinhVien findMaxScoreSinhVien(List& l)
{
    if (l.pHead == nullptr){
        return {0, "", 0.0f, ""};
    }

    Node* max = l.pHead;
    for (Node* p = l.pHead->pNext; p != nullptr; p = p->pNext)
    {
        if (p->data.diemTB > max->data.diemTB)
            max = p;
    }

    return max->data;
}

// 12.
/*   Tìm SV có trung bình thấp nhất
Input:
    + List l

Output:
    + return SinhVien
*/
SinhVien findMinScoreSinhVien(List& l)
{
    if (l.pHead == nullptr)
        return {0, "", 0.0f, ""};

    Node* min = l.pHead;

    for (Node* p = l.pHead->pNext; p != nullptr; p = p->pNext)
    {
        if (p->data.diemTB < min->data.diemTB)
            min = p;
    }

    return min->data;
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

    cout << "\n=== BAI 8: XEP LOAI HOC LUC ===" << endl;
    classifyPerfomance(l);
    printList(l);

    cout << "\n=== BAI 9: DIEM TRUNG BINH CAO NHAT ===" << endl;
    cout << findMaxScore(l) << endl;

    cout << "\n=== BAI 10: TIM SINH VIEN THEO MA ===" << endl;
    int maSVCanTim = 125;
    SinhVien svTimDuoc = findSinhVienById(l, maSVCanTim);
    if (svTimDuoc.maSV != 0)
        printSinhVien(svTimDuoc);
    else
        cout << "Khong tim thay sinh vien co ma " << maSVCanTim << endl;

    cout << "\n=== BAI 11: SINH VIEN CO DIEM CAO NHAT ===" << endl;
    printSinhVien(findMaxScoreSinhVien(l));

    cout << "\n=== BAI 12: SINH VIEN CO DIEM THAP NHAT ===" << endl;
    printSinhVien(findMinScoreSinhVien(l));

    return 0;
}