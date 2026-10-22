# Buổi 2 – Danh sách liên kết đơn (Singly Linked List)

## 1. Ý tưởng
- Mảng cần biết trước kích thước, thêm/xóa phần tử phải dịch chuyển nhiều.
- Danh sách liên kết: các phần tử (node) nằm rải rác trong bộ nhớ, mỗi node **lưu địa chỉ của node kế tiếp**.
- Nhờ con trỏ nên danh sách có thể tăng/giảm số lượng linh hoạt khi chạy chương trình.

## 2. Kiến trúc
- Mỗi **node** gồm 2 phần: `data` (dữ liệu) và `pNext` (địa chỉ node kế).
- Node cuối có `pNext = NULL`.
- Quản lý danh sách bằng 2 con trỏ: `pHead` (node đầu) và `pTail` (node cuối).
- Danh sách rỗng khi `pHead == NULL` và `pTail == NULL`.

## 3. Các bước xây dựng
```cpp
// Bước 1: cấu trúc Node
struct Node {
    int data;
    Node* pNext;
};

// Bước 2: hàm tạo Node từ giá trị
Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}

// Bước 3: cấu trúc List
struct List {
    Node* pHead;
    Node* pTail;
};

// Bước 4: khởi tạo List
void initList(List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
```

## 4. Các thao tác

### Thêm node vào đầu
```cpp
void addHead(List& l, Node* p)
{
    if (l.pTail == NULL)      // danh sách rỗng
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;   // p trỏ vào node đầu cũ
        l.pHead = p;          // p thành node đầu mới
    }
}
```

### Thêm node vào cuối
```cpp
void addTail(List& l, Node* p)
{
    if (l.pHead == NULL)      // danh sách rỗng
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;   // node cuối cũ trỏ vào p
        l.pTail = p;          // p thành node cuối mới
    }
}
```

### In danh sách
```cpp
void printList(List l)
{
    for (Node* p = l.pHead; p != NULL; p = p->pNext)
        cout << p->data << "\t";
}
```
Cũng có thể viết bằng `while`: `Node* p = l.pHead; while (p != NULL) { ...; p = p->pNext; }`

### Hàm main mẫu
```cpp
int main()
{
    List l;
    initList(l);

    Node* p = initNode(10);
    addHead(l, p);
    addHead(l, initNode(79));
    addTail(l, initNode(39));

    printList(l);   // 79  10  39
    return 0;
}
```

### Tìm kiếm một giá trị
```cpp
bool timGiaTri(List l, int value)
{
    for (Node* p = l.pHead; p != NULL; p = p->pNext)
        if (p->data == value)
            return true;
    return false;
}
```
Mở rộng: trả về địa chỉ node (`Node*`) thay vì `bool`.

### Kỹ thuật duyệt để đếm, tính tổng, tìm max/min
Tất cả cùng một khung duyệt `for (Node* p = l.pHead; p != NULL; p = p->pNext)`:
- **Đếm**: có điều kiện thì tăng biến đếm (vd đếm số chẵn).
- **Tổng**: `t = t + p->data;`
- **Max/min**: khởi tạo `m = l.pHead->data`, rồi so sánh từng node và cập nhật.

```cpp
int timGiaTriMax(List l)
{
    int m = l.pHead->data;
    for (Node* p = l.pHead; p != NULL; p = p->pNext)
        if (p->data > m)
            m = p->data;
    return m;
}
```

### Xóa node đầu
Slide trình bày các bước: (1) `p` trỏ vào node đầu, (2) `pHead` dời sang node kế, (3) giải phóng `p`, rồi trả về giá trị đã xóa.
```cpp
int removeHead(List& l)
{
    Node* p = l.pHead;
    int value = p->data;
    l.pHead = l.pHead->pNext;
    if (l.pHead == NULL)       // xóa xong thì rỗng
        l.pTail = NULL;
    delete p;
    return value;
}
```

### Xóa node cuối
Slide trình bày: (1) tìm node `q` đứng ngay trước `pTail`, (2) `p` giữ node cuối, (3) `pTail = q`, (4) `q->pNext = NULL`, (5) giải phóng `p`. Vì danh sách đơn không có con trỏ ngược nên phải duyệt từ đầu để tìm `q`.
```cpp
int removeTail(List& l)
{
    Node* p = l.pTail;
    int value = p->data;
    if (l.pHead == l.pTail)    // chỉ có 1 node
    {
        l.pHead = NULL;
        l.pTail = NULL;
    }
    else
    {
        Node* q = l.pHead;
        while (q->pNext != l.pTail)
            q = q->pNext;
        l.pTail = q;
        q->pNext = NULL;
    }
    delete p;
    return value;
}
```

> Hai hàm `removeHead` và `removeTail` ở trên mình viết lại theo các bước trong slide vì slide chỉ để khung trống (`return value;`), chưa có code hoàn chỉnh. Cả hai giả định danh sách không rỗng, bạn nên kiểm tra rỗng trước khi gọi.

## 5. Ghi nhớ nhanh
- Thêm đầu/cuối: luôn xét trường hợp danh sách **rỗng** trước.
- Duyệt: dừng khi `p == NULL`.
- Xóa node phải `delete` để tránh rò rỉ bộ nhớ, và cập nhật lại `pHead`/`pTail`.
- Xóa cuối tốn O(n) vì phải tìm node đứng trước `pTail`.

## 6. Bài tập

### Bài 1 – Danh sách số nguyên
1. Xây dựng cấu trúc node và cấu trúc danh sách liên kết đơn.
2. Viết hàm khởi tạo danh sách liên kết đơn và hàm khởi tạo địa chỉ node từ một số nguyên.
3. Viết hàm chèn node vào đầu danh sách.
4. Viết hàm chèn node vào cuối danh sách.
5. Viết hàm khởi tạo giá trị cho danh sách từ mảng một chiều.
6. Viết hàm in giá trị danh sách đã nhập.
7. Viết hàm in giá trị kèm địa chỉ của từng node trong danh sách.
8. Viết hàm kiểm tra danh sách có rỗng hay không.
9. Viết hàm trả về node thứ n trong danh sách.
10. Viết hàm tìm kiếm một node có giá trị X trong danh sách.
11. Viết hàm tìm kiếm các địa chỉ node có giá trị X trong danh sách.
12. Viết hàm đếm số lượng các node có giá trị âm, dương.
13. Viết hàm tìm node có giá trị âm lớn nhất, tìm node có giá trị lẻ nhỏ nhất trong danh sách.
14. Viết hàm cập nhật giá trị cho một node có giá trị là X bằng giá trị Y mới.
15. Viết hàm copy danh sách.

### Bài 2 – Danh sách sinh viên
1. Xây dựng cấu trúc dữ liệu `SinhVien` lưu các thông tin: maSV, hoTen, diemTB, xepLoai (hoặc thêm thông tin khác nếu muốn).
2. Xây dựng cấu trúc node để lưu sinh viên và cấu trúc danh sách liên kết đơn quản lý sinh viên.
3. Viết hàm khởi tạo danh sách liên kết đơn và hàm khởi tạo địa chỉ node từ kiểu `SinhVien`.
4. Viết hàm thêm sinh viên vào đầu danh sách.
5. Viết hàm thêm sinh viên vào cuối danh sách.
6. Viết hàm khởi tạo dữ liệu cho danh sách sinh viên (dữ liệu kiểm thử bên dưới).
7. Viết hàm in danh sách sinh viên.
8. Viết hàm cập nhật xếp loại học lực.
9. Viết hàm tìm điểm trung bình cao nhất.
10. Viết hàm tìm kiếm sinh viên theo mã sinh viên.
11. Viết hàm tìm SV có trung bình cao nhất.
12. Viết hàm tìm SV có điểm trung bình thấp nhất.

Dữ liệu kiểm thử (maSV, hoTen, diemTB, xepLoai):
```
{123, "Nguyen Van A", 9.1, ""}
{124, "Nguyen Van B", 8.8, ""}
{125, "Nguyen Van C", 9.1, ""}
{126, "Nguyen Van D", 2.1, ""}
{127, "Nguyen Van F", 9.7, ""}
{128, "Nguyen Van G", 4.1, ""}
{129, "Nguyen Van H", 8.3, ""}
{130, "Nguyen Van K", 7.9, ""}
```