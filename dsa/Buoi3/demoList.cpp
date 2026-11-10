#include <iostream>
using namespace std;

// Bước 1: Định nghĩa Node
struct Node
{
    int data;
    Node* pNext;
};

// Bước 2: Cấp phát vùng nhớ để lưu trữ giá trị
Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}

// Bước 3: Định nghĩa List
struct List
{
    Node* pHead;
    Node* pTail;
};

// Bước 4: Khởi tạo List
void initList(List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

void addHead(List& l, Node* p)
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

void addTail(List& l, Node* p)
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
    for (Node* p = l.pHead; p != NULL; p = p->pNext)
        cout << p->data << " ";
}

void printListWh(List l)
{
    Node* p = l.pHead;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << endl;
}

int loadData(List& l)
{
    Node* p1 = initNode(10);
    Node* p2 = initNode(79);

    addHead(l, p1);
    addHead(l, p2);
    addTail(l, initNode(39));

    return 1;
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
    for (Node* p = l.pHead; p != nullptr; p = p->pNext)
    {
        if (p->data == x)
            return true;
    }
    return false;
}

int main()
{
    List l;
    initList(l); // Danh sách rỗng

    loadData(l);

    printList(l);
    printListWh(l);

    cout << "\nTest: Tim gia tri: " << endl;
    cout << "\t+ Ket qua tim 10: " << searchValue(l, 10) << endl;
    cout << "\t+ Ket qua tim 20: " << searchValue(l, 20) << endl;

    return 0;
}