#include <iostream>
#include <vector>
using namespace std;

// 1. Xây dựng cấu trúc node và cấu trúc danh sách liên kết đơn
struct Node
{
    int data;
    Node* pNext;
};

struct List
{
    Node* pHead;
    Node* pTail;
};

// 2.
/* Khởi tạo địa chỉ Node từ một số nguyên
Input:
    + int value

Output:
    + return Node*
*/
Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
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

// 3.
/* Chèn node vào đầu danh sách
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

// 4.
/* Chèn node vào cuối danh sách
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

// 5.
/* Khởi tạo giá trị cho danh sách từ mảng một chiều
Input:
    + List& l
    + int arr[]
    + int n

Output:
    + return void
*/
void initListFromArray(List& l, int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        Node* p = initNode(arr[i]);
        addTail(l, p);
    }
}

// 6.
/* In giá trị danh sách đã nhập
Input:
    + List l

Output:
    + return void
*/
void printList(List l)
{
    for (Node* p = l.pHead; p != nullptr; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

// 7.
/* In giá trị kèm địa chỉ của từng node trong danh sách
Input:
    + List l

Output:
    + return void
*/
void printListWithAddress(List l)
{
    if (l.pHead == nullptr)
    {
        cout << "Danh sach rong!" << endl;
        return;
    }

    for (Node* p = l.pHead; p != nullptr; p = p->pNext)
    {
        cout << "Gia tri: " << p->data << "\t| Dia chi: " << p << endl;
    }
}

// 8.
/* Kiểm tra danh sách có rỗng hay không
Input:
    + List l

Output:
    + return bool (true nếu rỗng, false nếu không rỗng)
*/
bool isEmpty(List l)
{
    return l.pHead == nullptr;
}

// 9.
/* Trả về node thứ n trong danh sách
Input:
    + List l
    + int n

Output:
    + return Node* (trả về nullptr nếu n không hợp lệ)
*/
Node* getNodeAt(List l, int n)
{
    if (n < 0) return nullptr;

    Node* p = l.pHead;
    int count = 0;
    while (p != nullptr)
    {
        if (count == n)
            return p;
        count++;
        p = p->pNext;
    }
    return nullptr;
}

// 10.
/* Tìm kiếm một node đầu tiên có giá trị X trong danh sách
Input:
    + List l
    + int x

Output:
    + return Node* (trả về địa chỉ node tìm thấy, hoặc nullptr nếu không có)
*/
Node* searchNodeWithValue(List l, int x)
{
    for (Node* p = l.pHead; p != nullptr; p = p->pNext)
    {
        if (p->data == x)
            return p;
    }
    return nullptr;
}

// 11.
/* Tìm kiếm tất cả các địa chỉ node có giá trị X trong danh sách
Input:
    + List l
    + int x

Output:
    + return vector<Node*> (danh sách chứa các địa chỉ node tìm thấy)
*/
vector<Node*> searchNodesWithValue(List l, int x)
{
    vector<Node*> result;
    for (Node* p = l.pHead; p != nullptr; p = p->pNext)
    {
        if (p->data == x)
        {
            result.push_back(p);
        }
    }
    return result;
}

// 12.
/* Đếm số lượng các node có giá trị âm, dương trong danh sách
Input:
    + List l
    + int& negativeCount
    + int& positiveCount

Output:
    + return void (kết quả lưu qua tham chiếu)
*/
void countNegativePositiveNodes(List l, int& negativeCount, int& positiveCount)
{
    negativeCount = 0;
    positiveCount = 0;

    for (Node* p = l.pHead; p != nullptr; p = p->pNext)
    {
        if (p->data < 0)
            negativeCount++;
        else if (p->data > 0)
            positiveCount++;
    }
}

/* Hàm nạp dữ liệu mẫu
Input:
    + List& l

Output:
    + return int
*/
int loadData(List& l)
{
    Node* p1 = initNode(10);
    Node* p2 = initNode(79);

    addHead(l, p1);
    addHead(l, p2);
    addTail(l, initNode(39));
    addTail(l, initNode(-15));
    addTail(l, initNode(10));
    addTail(l, initNode(0));

    return 1;
}

int main()
{
    List l;
    initList(l);

    cout << "1. Kiem tra rong ban dau: " << (isEmpty(l) ? "Rong" : "Khong rong") << endl;

    loadData(l);

    cout << "\n2. Danh sach sau khi nap du lieu: ";
    printList(l);

    cout << "\n3. Chi tiet gia tri va dia chi tung node:" << endl;
    printListWithAddress(l);

    int index = 2;
    Node* nodeAt = getNodeAt(l, index);
    cout << "\n4. Node tai vi tri " << index << ": ";
    if (nodeAt != nullptr)
        cout << nodeAt->data << " (Dia chi: " << nodeAt << ")" << endl;
    else
        cout << "Khong ton tai" << endl;

    int x = 10;
    Node* foundOne = searchNodeWithValue(l, x);
    cout << "\n5. Tim 1 node co gia tri " << x << ": ";
    if (foundOne != nullptr)
        cout << "Tim thay tai dia chi " << foundOne << endl;
    else
        cout << "Khong tim thay" << endl;

    vector<Node*> foundAll = searchNodesWithValue(l, x);
    cout << "\n6. Tim tat ca dia chi node co gia tri " << x << ": ";
    if (!foundAll.empty())
    {
        for (Node* p : foundAll)
            cout << p << " ";
        cout << endl;
    }
    else
        cout << "Khong tim thay" << endl;

    int neg = 0, pos = 0;
    countNegativePositiveNodes(l, neg, pos);
    cout << "\n7. So luong node am: " << neg << ", So luong node duong: " << pos << endl;

    return 0;
}