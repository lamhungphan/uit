#include <iostream>
using namespace std;

int main(){

    int* p = new int(6789);

    cout << "\nTruoc thu hoi" << endl;
    cout << p << endl;
    cout << *p << endl;

    delete p;

    cout << "\nSau thu hoi" << endl;
    cout << p << endl;
    cout << *p << endl;

    return 0;
}