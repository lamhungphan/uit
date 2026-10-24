#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
// #include <cmath>

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
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << arr[i];
        if (i + 1 < arr.size())
        {
            cout << ", ";
        }
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

vector<double> getEvenInteger(const vector<double> &arr)
{
    vector<double> even;
    for (double value : arr)
    {
        long long intPart = static_cast<long long>(value);
        if (intPart % 2 == 0)
        {
            even.push_back(value);
        }
    }
    return even;
}

int indexOfMinValue(const vector<double> &arr)
{
    if (arr.empty())
    {
        return -1;
    }

    size_t minIndex = 0;
    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    return static_cast<int>(minIndex);
}

void reverseArr(const vector<double> &arr)
{
    cout << "8. Mang sau khi dao nguoc: ";
    for (size_t i = arr.size(); i > 0; --i)
    {
        cout << arr[i - 1] << ", ";
    }
    cout << endl;
}

void getNegative(const vector<double> &arr)
{
    cout << "9. Cac phan tu am trong mang: ";
    for (double val : arr)
    {
        if (val < 0)
        {
            cout << val << ", ";
        }
    }
    cout << endl;
}

void countElementInRange(const vector<double> &arr, int from, int to)
{
    int start = max(0, min(from, to));
    int end = min(static_cast<int>(arr.size()) - 1, max(from, to));

    int count = (start <= end) ? (end - start + 1) : 0;
    cout << "10. Co " << count << " phan tu tu vi tri " << from << " toi " << to << endl;
}

void getElementInRange(const vector<double> &arr, int from, int to)
{
    int start = max(0, min(from, to));
    int end = min(static_cast<int>(arr.size()) - 1, max(from, to));

    cout << "11. Cac phan tu tu vi tri " << from << " toi " << to << ": ";
    for (int i = start; i <= end; ++i)
    {
        cout << arr[i];
        if (i < end)
        {
            cout << ", ";
        }
    }
    cout << endl;
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
    vector<double> evenElements = getEvenInteger(oneDimArr);

    cout << "6. Cac phan tu co phan nguyen chan: ";
    for (double value : evenElements)
    {
        cout << value << ", ";
    }
    cout << endl;

    cout << "7. Vi tri phan tu nho nhat mang: " << indexOfMinValue(oneDimArr) << endl;
    reverseArr(oneDimArr);
    getNegative(oneDimArr);
    countElementInRange(oneDimArr, 2, 4);
    getElementInRange(oneDimArr, 2, 4);

    return 0;
}