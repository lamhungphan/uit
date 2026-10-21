#include <iostream>
using namespace std;

void printArr(int*a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << endl;
    }
}

void initDataArr(int* a, int& n)
{
    *a = 12;
    *(a + 1) = 23;
    *(a + 2) = 78;
    *(a + 3) = 56;
    n = 4;
}

int main()
{
    // int a[100] = {12, 23, 78, 56, 98, 42};
    // int n = 6;
    
    // cout << "a: " << a << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << &a[i] << " - " << a[i] << endl;
    // }

    int* a = new int[10000];
    int n = 0;

    initDataArr(a, n);
    printArr(a, n);

    delete[] a;
    a = nullptr;

    return 0;
}