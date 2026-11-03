# Queue

### 1. Ý tưởng
- Ví dụ thực tế: hàng đợi in của máy in. Tài liệu gửi in trước thì được in trước

### 2. Giới thiệu
- Cấu trúc dữ liệu lưu trữ và quản lý phần tử theo nguyên tắc **FIFO** (First-In-First-Out): vào trước, ra trước
- Phần tử đưa vào hàng đợi trước sẽ được lấy ra trước
- Thêm vào ở cuối hàng (**Rear**, thao tác `EnQueue`), lấy ra ở đầu hàng (**Front**, thao tác `DeQueue`)
- Cài đặt bằng **mảng** hoặc **danh sách liên kết**

### 3. Kiến trúc
- Queue là danh sách liên kết đơn: `pFront` tương ứng `pHead`, `pRear` tương ứng `pTail`
- Thêm ở `pRear`, lấy ra ở `pFront`

### 4. Các bước xây dựng
```cpp
// Bước 1: Node và Bước 2: initNode giống Stack

// Bước 3: cấu trúc Queue
struct Queue {
    Node* pFront;
    Node* pRear;
};

// Bước 4: khởi tạo Queue
void initQueue(Queue& q)
{
    q.pFront = NULL;
    q.pRear = NULL;
}
```

### 5. Các thao tác
Slide liệt kê: EnQueue (thêm vào), DeQueue (lấy ra), in hàng đợi, kiểm tra rỗng.

**EnQueue – thêm vào cuối hàng**
```cpp
void enQueue(Queue& q, Node* p)
{
    if (q.pFront == NULL)
    {
        q.pFront = p;
        q.pRear = p;
    }
    else
    {
        q.pRear->pNext = p;
        q.pRear = p;
    }
}
```

**DeQueue – lấy ra ở đầu hàng**
```cpp
int deQueue(Queue& q)
{
    if (q.pFront == NULL)
        return 0;

    Node* p = q.pFront;
    q.pFront = q.pFront->pNext;
    int value = p->data;
    delete p;

    return value;
}
```

**In hàng đợi**
```cpp
void printQueue(Queue q)
{
    cout << "Queue Q = Front<\t";
    for (Node* p = q.pFront; p != NULL; p = p->pNext)
    {
        cout << p->data << "\t";
    }
    cout << ">Rear" << endl;
}
```
Cũng có thể viết bằng `while` (`printQueueWhile`).

**Hàm main mẫu**
```cpp
int main()
{
    Queue q;
    initQueue(q);

    enQueue(q, initNode(10));
    enQueue(q, initNode(79));
    enQueue(q, initNode(39));

    printQueue(q);          // Queue Q = Front<  10  79  39  >Rear

    int value = deQueue(q);
    printQueueWhile(q);     // Queue Q = Front<  79  39  >Rear
    return 0;
}
```

### Bài tập
Viết chương trình cài đặt queue bằng danh sách liên kết đơn để lưu trữ tạm các số nguyên (hoặc ký tự):
1. Viết hàm khởi tạo queue.
2. Viết hàm kiểm tra queue rỗng.
3. Viết hàm đưa một phần tử vào queue.
4. Viết hàm lấy một phần tử ra khỏi queue.
5. Viết hàm in ra phần tử REAR và FRONT của queue.
6. Trong hàm main, viết menu thể hiện các lựa chọn câu trên.

---

## Ghi nhớ nhanh
| | Stack | Queue |
|---|---|---|
| Nguyên tắc | LIFO (vào sau, ra trước) | FIFO (vào trước, ra trước) |
| Thêm vào | `push`, ở đầu (TOP) | `enQueue`, ở cuối (Rear) |
| Lấy ra | `pop`, ở đầu (TOP) | `deQueue`, ở đầu (Front) |
| Con trỏ quản lý | `pTop` | `pFront`, `pRear` |
