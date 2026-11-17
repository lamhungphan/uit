# Danh sách liên kết đôi (Doubly Linked List)

## 1. Kiến trúc
- Giống danh sách liên kết đơn nhưng mỗi node có **2 liên kết**: trỏ tới node kế (`pNext`) và trỏ về node trước (`pPre`)
- Nhờ vậy có thể duyệt theo **2 chiều**: từ đầu đến cuối và từ cuối về đầu
- Vẫn quản lý danh sách bằng `pHead` (node đầu) và `pTail` (node cuối)
- Node đầu có `pPre = NULL`, node cuối có `pNext = NULL`

| | Danh sách đơn | Danh sách đôi |
|---|---|---|
| Thành phần node | `data`, `pNext` | `pPre`, `data`, `pNext` |
| Chiều duyệt | 1 chiều (đầu → cuối) | 2 chiều |

## 2. Các bước xây dựng

### Bước 1: cấu trúc Node
```cpp
struct Node {
    int data;
    Node* pPre;
    Node* pNext;
};
```

### Bước 2: hàm khởi tạo Node từ giá trị
Viết hàm chuyển một giá trị thành Node. Cả `pPre` và `pNext` đều gán `NULL`.
```cpp
Node* initNode(int value)
{
    Node* p = new Node;

    p->data = value;
    p->pPre = NULL;
    p->pNext = NULL;
    return p;
}
```

### Bước 3: cấu trúc List
```cpp
struct List {
    Node* pHead;
    Node* pTail;
};
```

### Bước 4: khởi tạo List
```cpp
void initList(List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
```

### Khai báo và khởi tạo
```cpp
List l;
initList(l);          // pHead => NULL, pTail => NULL

Node* p1 = initNode(10);
Node* p2 = initNode(79);
Node* p3 = initNode(39);
```

## 3. Các thao tác

### Thêm node vào đầu
- Danh sách rỗng: `pHead` và `pTail` cùng trỏ vào `p`
- Ngược lại, nối `p` vào trước node đầu cũ theo **cả 2 chiều**:
  1. `p->pNext = l.pHead;` (p trỏ tới node đầu cũ)
  2. `l.pHead->pPre = p;` (node đầu cũ trỏ ngược về p)
  3. `l.pHead = p;` (p thành node đầu mới)

```cpp
void addHead(List& l, Node* p)
{
    if (l.pTail == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead->pPre = p;
        l.pHead = p;
    }
}
```

### Thêm node vào cuối
- Danh sách rỗng: `pHead` và `pTail` cùng trỏ vào `p`
- Ngược lại, nối `p` vào sau node cuối cũ theo **cả 2 chiều**:
  1. `l.pTail->pNext = p;` (node cuối cũ trỏ tới p)
  2. `p->pPre = l.pTail;` (p trỏ ngược về node cuối cũ)
  3. `l.pTail = p;` (p thành node cuối mới)

```cpp
void addTail(List& l, Node* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        p->pPre = l.pTail;
        l.pTail = p;
    }
}
```

### In danh sách
- In xuôi: từ `pHead`, đi theo `pNext` đến khi gặp `NULL`
- In ngược: từ `pTail`, đi theo `pPre` đến khi gặp `NULL`

```cpp
void printListFor(List l)
{
    for (Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << "\t";
    }

    cout << endl;
    for (Node* p = l.pTail; p != NULL; p = p->pPre)
    {
        cout << p->data << "\t";
    }
}
```

### Hàm main mẫu
```cpp
int main()
{
    List l;
    initList(l);

    addHead(l, initNode(10));
    addHead(l, initNode(79));
    addTail(l, initNode(39));

    printListFor(l);
    // 79   10   39
    // 39   10   79

    return 0;
}
```

## Ghi nhớ nhanh
- Mỗi lần thêm node phải cập nhật **đủ 2 liên kết** (`pNext` và `pPre`), thiếu một cái là danh sách bị đứt một chiều
- Luôn xét trường hợp danh sách **rỗng** trước
- Khác với danh sách đơn: thêm cuối và duyệt ngược đều làm được trực tiếp nhờ `pTail` và `pPre`
