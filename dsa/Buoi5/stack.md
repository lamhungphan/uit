# Stack

### 1. Ý tưởng
- Bài toán: chuyển số hệ 10 sang hệ 2. Chia liên tiếp cho 2, các số dư được tạo ra theo thứ tự từ thấp lên cao nhưng kết quả phải đọc **ngược lại** (13 → 1101)
- Cần một cấu trúc mà phần tử vào sau được lấy ra trước

### 2. Giới thiệu
- Cấu trúc dữ liệu quản lý phần tử theo cơ chế **LIFO** (Last-In-First-Out): vào sau, ra trước
- Phần tử được đưa vào sau cùng là phần tử được lấy ra đầu tiên
- Phần tử nằm trên cùng gọi là **TOP**
- Hai thao tác chính: `push` (đẩy vào) và `pop` (lấy ra), cùng thực hiện ở đầu TOP
- Cài đặt bằng **mảng** hoặc **danh sách liên kết**

### 3. Kiến trúc
- Stack là danh sách liên kết đơn chỉ thao tác ở **đầu danh sách**
- Chỉ cần 1 con trỏ `pTop` (tương ứng `pHead` của danh sách)

### 4. Các bước xây dựng
```cpp
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

// Bước 3: cấu trúc Stack
struct Stack {
    Node* pTop;
};

// Bước 4: khởi tạo Stack
void initStack(Stack& s)
{
    s.pTop = NULL;
}
```

### 5. Các thao tác
Slide liệt kê: Push, Pop, kiểm tra stack rỗng, kiểm tra stack đầy, lấy giá trị phần tử trên cùng.

**Push – thêm phần tử vào stack**
- Stack rỗng: `pTop` trỏ vào `p`
- Ngược lại: `p` trỏ tới node TOP cũ, rồi `pTop` dời về `p`
```cpp
void push(Stack& s, Node* p)
{
    if (s.pTop == NULL)
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
}
```

**Print - in stack**
```cpp
void printStack(Stack s)
{
    cout << "Stack = Top < ";
    for (Node* p = s.pTop; p != NULL; p = p->pNext)
    {
        cout << p->data << "  ";
    }
    cout << ">" << endl;
}
```

**Pop – lấy phần tử ra khỏi stack**
- (1) `p` giữ node TOP
- (2) `pTop` dời sang node kế
- (3) lấy `data` ra
- (4) `delete p`

```cpp
void pop(Stack& s, int& value)
{
    if (s.pTop == NULL)
        return;

    Node* p = s.pTop;
    s.pTop = s.pTop->pNext;
    value = p->data;
    delete p;
}
```

**Hàm main mẫu**
```cpp
int main()
{
    Stack s;
    initStack(s);

    Node* p1 = initNode(10);
    push(s, p1);
    push(s, initNode(79));
    push(s, initNode(39));

    printStack(s);          // Stack = Top < 39  79  10 >

    int value;
    pop(s, value);
    cout << "Pop => " << value << endl;   // Pop => 39

    printStack(s);          // Stack = Top < 79  10 >
    return 0;
}
```

### Bài tập
1. Viết chương trình cài đặt stack (cấp phát động) để lưu trữ tạm các số nguyên, gồm:
   - Khai báo cấu trúc Node và Stack.
   - Viết hàm khởi tạo Node và Stack.
   - Viết hàm kiểm tra stack rỗng.
   - Viết hàm kiểm tra stack có full hay không (nếu có).
   - Viết hàm đẩy một phần tử vào stack.
   - Viết hàm lấy một phần tử ra khỏi stack.
   - Lấy giá trị phần tử TOP của stack.
   - Trong hàm main, viết menu thể hiện các lựa chọn câu trên.
2. Viết chương trình áp dụng stack để minh họa quá trình chuyển đổi số thập phân sang số nhị phân. Ví dụ: nhập 13, kết quả 1101.
3. Viết chương trình áp dụng stack để minh họa cách đảo một chuỗi nhập vào. Ví dụ: nhập `Dai Hoc`, kết quả `Hoc Dai`.
