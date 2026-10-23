#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <cmath>

using namespace std;

double randomValue(mt19937 &gen, uniform_real_distribution<double> &dist)
{
    double value = dist(gen);
    return round(value * 100.0) / 100.0;
}

void printArr(const vector<double> &arr)
{
    cout << "2. Mang da tao (so luong phan tu = " << arr.size() << "):" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

double sumArr(const vector<double> &arr)
{
    double sum = 0;
    for (double val : arr)
    {
        sum += val;
    }
    return sum;
}

double prodArr(const vector<double> &arr)
{
    double product = 1;
    for (double val : arr)
    {
        product *= val;
    }
    return product;
}

void countShowUp(const vector<double> &arr, double num)
{
    int count = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (num == arr[i])
        {
            count++;
        }
    }
    cout << "5. So " << num << " lap lai " << count << " lan" << endl;
}

int main()
{
    // 1.
    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<double> dist(-268.0, 339.0);
    uniform_int_distribution<int> sizeDist(10, 20);
    int n = sizeDist(gen);

    vector<double> oneDimArr(n);

    for (int i = 0; i < n; ++i)
    {
        oneDimArr[i] = randomValue(gen, dist);
    }

    printArr(oneDimArr);

    cout << "3. Tong cac phan tu trong mang: " << sumArr(oneDimArr) << endl;
    cout << "4. Tich cac phan tu trong mang: " << prodArr(oneDimArr) << endl;
    countShowUp(oneDimArr, 99.9);

    return 0;
}