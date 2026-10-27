#include <iostream>
using namespace std;

typedef struct ToaDo
{
    float x;
    float y;
} Diem;

typedef ToaDo Diem;

void inToaDo(ToaDo t)
{
    cout << "(" << t.x << "; " << t.y << ")" << endl;
}

void inToaDoV2(ToaDo* p)
{
    cout << "(" << p->x << "; " << p->y << ")" << endl;
}

void inMangTD(ToaDo* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        inToaDoV2(a + i);
    }
}

void taoMang(ToaDo* a, int& n)
{
    *a = {2, 3};
    *(a + 1) = {3, 1};
    *(a + 2) = {8, 6};
    *(a + 3) = {5, 2};
    *(a + 4) = {1, 3};

    n = 5;
}

int main()
{
    new int[100]{2, 5, 9, 6, 2};

    // ToaDo *a = new ToaDo[100]{{2, 3}, {3, 1}, {8, 6}};
    // int n = 3;

    ToaDo *a = new ToaDo[100];
    int n = 0;

    taoMang(a, n);
    inMangTD(a, n);

    return 0;
}
