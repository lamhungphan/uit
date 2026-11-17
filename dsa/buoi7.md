# Cây nhị phân tìm kiếm (Binary Search Tree – BST)

## Ý tưởng – Giải pháp
- Vấn đề: muốn lưu trữ nhiều số (50, 73, 26, 66, 15, 88, ...). Làm thế nào?
- Các cấu trúc đã xét: mảng 1 chiều/2 chiều, danh sách liên kết đơn/đôi/vòng, bảng băm, ...
- => Giới thiệu thêm **cây nhị phân tìm kiếm**

## Kiến trúc
Quy tắc của cây nhị phân tìm kiếm, với mỗi node:
- Giá trị cây con bên **trái** của một node **nhỏ hơn** giá trị của node đó
- Giá trị cây con bên **phải** của một node **lớn hơn** giá trị của node đó

Ví dụ nhập lần lượt `50, 73, 26, 66, 15, 88`: 50 là gốc (`pRoot`); 26 và 15 nằm bên trái; 73, 66, 88 nằm bên phải.

- Mỗi node có 3 phần: `pLeft` (con trái), `data`, `pRight` (con phải)
- Cây được quản lý bằng con trỏ `pRoot` (node gốc)

## Các bước xây dựng
```cpp
// Bước 1: Node
struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
};

// Bước 2: tạo Node từ giá trị
Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

// Bước 3: cấu trúc Tree
struct Tree {
    Node* pRoot;
};

// Bước 4: khởi tạo Tree
void initTree(Tree& t)
{
    t.pRoot = NULL;
}
```

Khai báo:
```cpp
Tree tree;
initTree(tree);          // pRoot => NULL

Node* p1 = initNode(50);
Node* p2 = initNode(26);
Node* p3 = initNode(73);
```

## Các thao tác

### Thêm node vào cây
Thuật toán `addNode(tree, p)`:
1. **Kiểm tra cây rỗng**: nếu rỗng thì `p` thành node gốc
2. **Tìm vị trí thích hợp để chèn**
   - Bắt đầu từ node gốc
   - So sánh giá trị của `p` với node hiện tại: nhỏ hơn thì đi sang con **trái**, lớn hơn thì đi sang con **phải**
   - Lặp lại cho đến khi tìm được vị trí trống (con trái hoặc con phải không tồn tại)
3. **Chèn node mới**: `p < node hiện tại` thì chèn vào bên trái, `p > node hiện tại` thì chèn vào bên phải

```cpp
void addNode(Tree& tree, Node* p)
{
    if (tree.pRoot == NULL)
    {
        tree.pRoot = p;
        return;
    }

    Node* pGoto = tree.pRoot;   // node đang xét
    Node* pLoca = NULL;         // node cha của vị trí chèn

    while (pGoto != NULL)
    {
        pLoca = pGoto;
        if (p->data < pGoto->data)
            pGoto = pGoto->pLeft;
        else if (p->data > pGoto->data)
            pGoto = pGoto->pRight;
    }

    if (p->data < pLoca->data)
        pLoca->pLeft = p;
    else if (p->data > pLoca->data)
        pLoca->pRight = p;
}
```

### Duyệt cây
Có 3 cách duyệt:

| Cách duyệt | Thứ tự | Ghi chú |
|---|---|---|
| **InOrder** (LNR) | Left – **Node** – Right | các giá trị được duyệt theo thứ tự **tăng dần** |
| **PreOrder** (NLR) | **Node** – Left – Right | |
| **PostOrder** (LRN) | Left – Right – **Node** | |

**Duyệt InOrder không dùng đệ quy (dùng stack)**
Các bước theo slide:
1. Tạo stack rỗng, bắt đầu từ node gốc
2. Duyệt trái: đưa các node đi qua vào stack, đi hết con trái
3. Xử lý node: lấy node trong stack ra để xử lý (in giá trị, ...)
4. Di chuyển qua node con bên phải
5. Lặp lại cho đến khi stack rỗng và không còn node để đi

```cpp
#include <stack>

void inOrder(Tree tree)
{
    stack<Node*> s;
    Node* p = tree.pRoot;

    while (p != NULL || !s.empty())
    {
        while (p != NULL)
        {
            s.push(p);
            p = p->pLeft;
        }

        p = s.top();
        s.pop();
        cout << p->data << "  ";

        p = p->pRight;
    }
}
```
> Slide viết điều kiện vòng ngoài là `s.empty() == NULL`, tương đương `!s.empty()`. Mình viết lại cho rõ nghĩa hơn.

Kết quả với cây ví dụ (50, 26, 73, 18, 39, 66, 88): `18  26  39  50  66  73  88`

**Duyệt dùng đệ quy**
Slide đưa mẫu LNR:
```cpp
void LNR(Node* p)
{
    if (p != NULL)
    {
        LNR(p->pLeft);
        cout << p->data << "  ";
        LNR(p->pRight);
    }
}
```
Mẫu chung của duyệt đệ quy: chỉ khác vị trí của dòng "xử lý node"
```cpp
void traversal(Node* p)
{
    if (p != NULL)
    {
        // xử lý node  (đặt ở đây => NLR)
        traversal(p->pLeft);
        // xử lý node  (đặt ở giữa => LNR)
        traversal(p->pRight);
        // xử lý node  (đặt ở cuối => LRN)
    }
}
```
> Slide chỉ nêu mẫu `traversal` với dòng "xử lý node" ở đầu (NLR). Ba chú thích vị trí ở trên là mình thêm để thể hiện đúng định nghĩa NLR / LNR / LRN.

### Tìm kiếm một giá trị
Tìm `x` (ví dụ x = 28):
1. Bắt đầu từ node gốc
2. So sánh giá trị cần tìm với node hiện tại
   - bằng nhau => tìm thấy (dừng)
   - nhỏ hơn => đi sang con **trái**
   - lớn hơn => đi sang con **phải**
3. Lặp lại bước 2, kết thúc khi tìm thấy hoặc không còn node để so sánh

```cpp
bool tim(Tree tree, int value)
{
    Node* p = tree.pRoot;

    while (p != NULL)
    {
        if (p->data == value)
            return true;

        if (value < p->data)
            p = p->pLeft;
        else if (value > p->data)
            p = p->pRight;
    }
    return false;
}
```

### Tính tổng và đếm
Dùng đệ quy, duyệt qua mọi node; kết quả trả qua tham chiếu (`int&`).
```cpp
// Tính tổng các giá trị trong cây
void tinh(Node* p, int& tong)
{
    if (p != NULL)
    {
        tong = tong + p->data;

        tinh(p->pLeft, tong);
        tinh(p->pRight, tong);
    }
}

// Đếm số lượng node trong cây
void dem(Node* p, int& s)
{
    if (p != NULL)
    {
        s = s + 1;

        dem(p->pLeft, s);
        dem(p->pRight, s);
    }
}
```
> Hàm `dem` trên slide đang viết `s = s + p->data;` và gọi `dem(p->pLeft, tong)` (sao chép từ hàm tính tổng, `tong` không tồn tại trong hàm này). Bản ở trên là bản sửa cho đúng ý "đếm số node". Cả hai hàm cần khởi tạo biến kết quả bằng 0 trước khi gọi, ví dụ `int tong = 0; tinh(tree.pRoot, tong);`.

Mở rộng (slide gợi ý): tổng các node âm, tổng các node lẻ, đếm các node dương, đếm các node chẵn, ...

### Node lá
- Điều kiện node lá: `pLeft` và `pRight` đều `NULL`
- Áp dụng: in các node lá, tìm các node lá, tính tổng các node lá, số lượng node lá, số lượng các node không phải là node lá

```cpp
void printLeaf(Node* p)
{
    if (p != NULL)
    {
        printLeaf(p->pLeft);

        if (p->pLeft == NULL && p->pRight == NULL)
            cout << p->data << "  ";

        printLeaf(p->pRight);
    }
}
```

### Node có 1 nhánh con
- Điều kiện: một trong hai địa chỉ `pLeft` hoặc `pRight` bằng `NULL` (và cái còn lại khác `NULL`)
- Áp dụng: in các node có 1 nhánh, tìm các node có 1 nhánh, tính tổng các node có 1 nhánh, số lượng node có 1 nhánh, tính tổng các node có 2 nhánh

> Slide viết "pLeft hoặc pRight bằng NULL". Nếu cả hai cùng NULL thì đó là node lá, nên điều kiện "có 1 nhánh" phải loại trường hợp này.

## Chú ý
- Trong cây nhị phân tìm kiếm, các giá trị có thể **trùng nhau** hoặc **không trùng nhau**, tùy thiết kế của người dùng
- Bài học này **không xử lý** trường hợp giá trị trùng nhau (hàm `addNode` ở trên bỏ qua node có giá trị trùng)
- Slide giao cho sinh viên tự thiết kế cây giải quyết trường hợp cây có giá trị trùng nhau

## Ghi nhớ nhanh
- Thêm và tìm kiếm đều đi từ gốc, mỗi bước rẽ trái hoặc phải tùy so sánh
- Duyệt InOrder (LNR) cho dãy giá trị **tăng dần**
- Các hàm tính tổng / đếm / in lá đều là biến thể của khung duyệt đệ quy `traversal`

## Bài tập
Viết chương trình cài đặt cây tìm kiếm nhị phân lưu trữ các số nguyên (hoặc số thực). Sau đó, viết hàm thực hiện các yêu cầu sau:
1. Tạo cấu trúc node và cây.
2. Viết hàm chuyển một giá trị nguyên sang node.
3. Viết hàm khởi tạo cây.
4. Viết hàm chèn node chứa giá trị (dữ liệu) vào cây (không dùng đệ quy).
5. Viết hàm khởi tạo giá trị tự động cho cây. Các giá trị được chọn ngẫu nhiên trong đoạn [-38; 68]. Số lượng cho một lần tạo tự động [10; 20].
6. Viết hàm khởi tạo giá trị cho cây từ mảng 1 chiều.
7. Viết hàm duyệt cây theo NLR, LNR, LRN.
8. Viết hàm tìm kiếm giá trị trong cây.
9. Viết hàm đếm toàn bộ số node của cây.
10. Viết hàm đếm số node lá của cây.
11. Viết hàm in ra nhánh (NLR) của một node.
12. Viết hàm đếm số node có giá trị nhỏ hơn X.
13. Viết hàm tính tổng các node trong cây.
14. Viết hàm tính tổng các node chẵn trong cây.
15. Viết hàm tìm node có giá trị lớn nhất và nhỏ nhất trong cây (viết 1 hàm).
