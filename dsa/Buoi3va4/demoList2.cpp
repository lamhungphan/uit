#include <iostream>
using namespace std;

// Bước 1: Định nghĩa Node
struct Node
{
    int data;
    Node *pNext;
};

// Bước 2: Cấp phát vùng nhớ để lưu trữ giá trị
Node *initNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}

// Bước 3: Định nghĩa List
struct List
{
    Node *pHead;
    Node *pTail;
};

// Bước 4: Khởi tạo List
void initList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

void addHead(List &l, Node *p)
{
    if (l.pHead == nullptr && l.pTail == nullptr)
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

void addTail(List &l, Node *p)
{
    if (l.pHead == nullptr && l.pTail == nullptr)
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

void printList(List l)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
        cout << p->data << " ";
}

int loadData(List &l)
{
    Node *p1 = initNode(10);
    Node *p2 = initNode(-79);

    addHead(l, p1);
    addHead(l, p2);
    addTail(l, initNode(-39));
    addTail(l, initNode(23));
    addTail(l, initNode(78));
    addTail(l, initNode(-12));
    addTail(l, initNode(68));

    return 7;
}

/* Tìm kiếm 1 giá trị có trong danh sách hay không
Input:
    + List l
    + int x

Output:
    + return bool
*/
bool searchValue(List l, int x)
{
    for (Node *p = l.pHead; p != nullptr; p = p->pNext)
    {
        if (p->data == x)
            return true;
    }
    return false;
}

/* Đếm số node có giá trị dương
Input:
    + List l

Output:
    + return int
*/
int countPositive(List l)
{
    int count = 0;
    for (Node *p = l.pHead; p != nullptr; p = p->pNext)
    {
        if (p->data > 0)
            count++;
    }
    return count;
};

/* Tìm giá trị lớn nhất
Input:
    + List l

Output:
    + return int
    * nên trả về địa chỉ
*/
int searchMax(List l)
{
    int m = l.pHead->data;
    for (Node *p = l.pHead->pNext; p != nullptr; p = p->pNext)
    {
        if (p->data > m)
            m = p->data;
    }
    return m;
};

/* Xóa Node đầu tiên trong danh sách
Input:
    + List& l

Output:
    + List& l
*/
void popHead(List& l)
{
    if(l.pHead == nullptr && l.pTail == nullptr)
        return;

    // không rỗng, tiến hành xóa
    Node* p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete p;

    // nếu không có sẽ lỗi nếu xóa nhiều hơn giá trị của list
    if (l.pHead == nullptr) 
        l.pTail = nullptr;
}

int main()
{
    List l;
    initList(l);

    cout << "Test: 1. Khoi tao du lieu cho list: " << endl;
    int soLuong = loadData(l);
    cout << "\t + Ket qua:  " << soLuong << " node" << endl;

    cout << "\nTest: 2. In cac gia tri trong list: " << endl;
    cout << "\t + Ket qua: " << endl;
    printList(l);

    cout << "\nTest: 3. Tim gia tri: " << endl;
    cout << "\t+ Ket qua tim 10(1): " << searchValue(l, 10) << endl;
    cout << "\t+ Ket qua tim 20(0): " << searchValue(l, 20) << endl;

    cout << "\nTest: 4. Dem node co gia tri duong " << endl;
    int positive = countPositive(l);
    cout << "\t+ Ket qua: " << positive << endl;

    cout << "\nTest: 5. Tim gia tri lon nhat " << endl;
    int max = searchMax(l);
    cout << "\t+ Ket qua: " << max << endl;

    cout << "\nTest: 6. Xoa node dau" << endl;
    popHead(l);
    popHead(l);
    printList(l);

    return 0;
}