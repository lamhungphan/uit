#include <iostream>
using namespace std;

struct ToaDo
{
    float x;
    float y;
};

typedef ToaDo Diem;

void inToaDo(ToaDo t)
{
    cout << "(" << t.x << "; " << t.y << ")" << endl;
}

int main()
{
    int n = 10, m;
    m = 20;
    cout << n << endl;
    cout << m << endl;

    ToaDo a = {2, 3}, b;
    b = {1.2, 5.3};
    // cout << a << endl;
    inToaDo(a);
    inToaDo(b);

    Diem c = {2, 3};
    inToaDo(c);
    
    return 0;
}
