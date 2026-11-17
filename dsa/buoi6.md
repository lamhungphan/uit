# Bảng băm (Hash Table)

## Giới thiệu
- Cấu trúc dữ liệu dùng để **lưu trữ và truy xuất** dữ liệu rất hiệu quả
- Hiệu quả: truy xuất nhanh, lưu trữ lớn
- Nguyên tắc hoạt động: ánh xạ một **khóa (key)** tới một **giá trị (value)** bằng **hàm băm (hash function)** để tính vị trí lưu trữ trong bảng băm

### Phân loại
- Chained Hash Table – Băm liên kết
- Linear Probing – Dò tuyến tính
- Quadratic Probing – Dò tuyến tính bậc 2
- Double hashing – Băm kép

=> Slide chọn **Chained Hash Table** (băm liên kết) để minh họa và cài đặt.

## Cơ chế hoạt động (Chained Hash Table)
- Dùng hàm băm: `value % 5 => key` (5 là kích thước bảng)
- Giá trị nào có cùng kết quả (cùng key) thì nằm chung một **bucket**, nối với nhau thành danh sách liên kết

Ví dụ với dãy: 50, 73, 35, 36, 64, 28, 90, 21, 53, 13

| Giá trị | `% 5` | Bucket |
|---|---|---|
| 50 | 0 | 0 |
| 73 | 3 | 3 |
| 35 | 0 | 0 |
| 36 | 1 | 1 |
| 64 | 4 | 4 |
| 28 | 3 | 3 |
| 90 | 0 | 0 |
| 21 | 1 | 1 |
| 53 | 3 | 3 |
| 13 | 3 | 3 |

Kết quả:
```
bucket 0: 50 -> 35 -> 90
bucket 1: 36 -> 21
bucket 2: (rỗng)
bucket 3: 73 -> 28 -> 53 -> 13
bucket 4: 64
```

## Thiết kế
- Mỗi bucket là **1 List** (danh sách liên kết đơn)
- Dùng **mảng** có kích thước bằng kích thước bảng băm để quản lý các bucket

## Cài đặt cách 1 (6 bước)
```cpp
#define Size 5   // kích thước bảng băm (slide dùng Size = 5)

// Bước 1: Node
struct Node {
    int data;
    Node* pNext;
};

// Bước 2: tạo Node từ giá trị
Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}

// Bước 3: cấu trúc Bucket
struct Bucket {
    Node* pHead;
    Node* pTail;
};

// Bước 4: khởi tạo Bucket
void initBucket(Bucket& bk)
{
    bk.pHead = bk.pTail = NULL;
}

// Bước 5: cấu trúc HashTable
struct HashTable {
    Bucket bucket[Size];
};

// Bước 6: khởi tạo HashTable (gọi hàm khởi tạo từng bucket)
void initHashTable(HashTable& h)
{
    for (int i = 0; i < Size; i++)
    {
        initBucket(h.bucket[i]);
    }
}
```

## Cài đặt cách 2 (4 bước)
Gộp `Bucket` vào bên trong `HashTable`, nên bớt được bước khởi tạo riêng cho bucket:
```cpp
// Bước 1, 2: Node và initNode giống cách 1

// Bước 3: cấu trúc HashTable (Bucket lồng bên trong)
struct HashTable {
    struct Bucket {
        Node* pHead;
        Node* pTail;
    };
    Bucket bucket[Size];
};

// Bước 4: khởi tạo HashTable (tức là khởi tạo từng Bucket trong HashTable)
void initHashTable(HashTable& h)
{
    for (int i = 0; i < Size; i++)
    {
        h.bucket[i].pHead = NULL;
        h.bucket[i].pTail = NULL;
    }
}
```

## Các thao tác

### Hàm băm (phương pháp chia lấy dư)
```cpp
int hashFunc(int value)
{
    return value % Size;
}
```

### Thêm node vào bảng băm
Cách 1: dùng hàm thêm cuối của danh sách cho từng bucket.
```cpp
void addTail(Bucket& bk, Node* p)
{
    if (bk.pHead == NULL)
    {
        bk.pHead = bk.pTail = p;
    }
    else
    {
        bk.pTail->pNext = p;
        bk.pTail = p;
    }
}

void add(HashTable& h, Node* p)
{
    int i = hashFunc(p->data);   // tính bucket cho p
    addTail(h.bucket[i], p);
}
```
Cách 2: viết thẳng trong hàm `add`.
```cpp
void add(HashTable& h, Node* p)
{
    int i = hashFunc(p->data);

    if (h.bucket[i].pHead == NULL)
    {
        h.bucket[i].pHead = p;
        h.bucket[i].pTail = p;
    }
    else
    {
        h.bucket[i].pTail->pNext = p;
        h.bucket[i].pTail = p;
    }
}
```
Slide cũng có biến thể dùng `addHead(Bucket&, Node*)` thay cho `addTail` (thêm vào đầu bucket).

### In bảng băm
```cpp
void print(HashTable h)
{
    for (int i = 0; i < Size; i++)
    {
        Bucket bk = h.bucket[i];
        printf("Bucket[%d] = ", i);
        for (Node* p = bk.pHead; p != NULL; p = p->pNext)
        {
            cout << p->data << "  ";
        }
        cout << endl;
    }
}
```

### Hàm main mẫu
```cpp
int main()
{
    HashTable h;
    initHashTable(h);

    add(h, initNode(50));
    add(h, initNode(73));
    add(h, initNode(35));
    add(h, initNode(36));
    add(h, initNode(64));
    add(h, initNode(28));
    add(h, initNode(90));
    add(h, initNode(21));
    add(h, initNode(53));
    add(h, initNode(13));

    print(h);
    return 0;
}
```
Kết quả:
```
Bucket[0] = 50   35   90
Bucket[1] = 36   21
Bucket[2] =
Bucket[3] = 73   28   53   13
Bucket[4] = 64
```
> Slide in bằng `printf("Bucket[%d] = ", i)` nên cần thêm `#include <cstdio>` (hoặc `<stdio.h>`) nếu trình biên dịch của bạn không tự bao gồm.

## Ghi nhớ nhanh
- Hàm băm cho biết giá trị thuộc bucket nào; cùng bucket thì nối vào danh sách (đây là cách xử lý **đụng độ**)
- Bảng băm = mảng các bucket, mỗi bucket là một danh sách liên kết đơn
- Cách 1 tách `Bucket` thành struct riêng; cách 2 lồng `Bucket` vào `HashTable` nên ít hàm hơn

## Bài tập
Viết chương trình cài đặt bảng băm liên kết để lưu các số thực:
1. Viết hàm tạo dữ liệu dạng tự động cho bảng băm. Các giá trị được chọn ngẫu nhiên trong đoạn [856; 988]. Số lượng giá trị cần nhập [45; 95].
2. Viết hàm tạo dữ liệu cho bảng băm từ mảng 1 chiều.
3. Viết hàm tạo dữ liệu dạng thủ công nhập từ bàn phím.
4. Viết hàm in bảng băm.
5. Viết hàm tìm một giá trị trong bảng băm.
6. Viết hàm xóa giá trị trong bảng băm.
7. Viết hàm tính tổng các giá trị lẻ trong bảng băm.
8. Viết hàm kiểm tra bảng băm có rỗng không.
9. Viết hàm xử lý bảng băm theo một điều kiện nào đó (ví dụ: chẵn/lẻ, số âm/dương, nguyên tố...) theo yêu cầu người dùng (GV hướng dẫn trên lớp).
10. Trong hàm main thể hiện các menu lựa chọn các hàm câu 1-9.
