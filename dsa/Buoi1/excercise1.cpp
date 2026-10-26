#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <string>
#include <utility>

using namespace std;

double randomValue(mt19937 &gen, uniform_int_distribution<int> &dist)
{
    return dist(gen) / 100.0;
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

pair<double, double> sumAndProduct(const vector<double> &arr)
{
    double sum = 0;
    double product = 1;
    for (double val : arr)
    {
        sum += val;
        product *= val;
    }
    return {sum, product};
}

void countShowUp(const vector<double> &arr, double num)
{
    int count = 0;
    for (double value : arr)
    {
        if (abs(num - value) < 1e-9)
        {
            ++count;
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

vector<double> reverseArr(const vector<double> &arr)
{
    return vector<double>(arr.rbegin(), arr.rend());
}

vector<double> getNegative(const vector<double> &arr)
{
    vector<double> negatives;
    for (double val : arr)
    {
        if (val < 0)
        {
            negatives.push_back(val);
        }
    }
    return negatives;
}

int countElementInRange(const vector<double> &arr, double from, double to)
{
    if (from > to)
    {
        swap(from, to);
    }

    int count = 0;
    for (double value : arr)
    {
        if (value >= from && value <= to)
        {
            ++count;
        }
    }
    return count;
}

vector<double> getElementInRange(const vector<double> &arr, double from, double to)
{
    if (from > to)
    {
        swap(from, to);
    }

    vector<double> values;
    for (double value : arr)
    {
        if (value >= from && value <= to)
        {
            values.push_back(value);
        }
    }
    return values;
}

void printValues(const vector<double> &values)
{
    if (values.empty())
    {
        cout << "khong co";
        return;
    }

    for (size_t i = 0; i < values.size(); ++i)
    {
        if (i > 0)
        {
            cout << ", ";
        }
        cout << values[i];
    }
}

void printValues(const string &label, const vector<double> &values)
{
    cout << label;
    printValues(values);
    cout << endl;
}

int main()
{
    // 1.
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> dist(-26799, 33899);
    uniform_int_distribution<int> sizeDist(10, 20);
    int n = sizeDist(gen);

    vector<double> oneDimArr(n);

    for (int i = 0; i < n; ++i)
    {
        oneDimArr[i] = randomValue(gen, dist);
    }

    printArr(oneDimArr);

    pair<double, double> sumProduct = sumAndProduct(oneDimArr);
    cout << "3. Tong cac phan tu trong mang: " << sumProduct.first << endl;
    cout << "4. Tich cac phan tu trong mang: " << sumProduct.second << endl;

    double num;
    cout << "Nhap gia tri can dem so lan xuat hien: ";
    if (!(cin >> num))
    {
        cerr << "Gia tri khong hop le." << endl;
        return 1;
    }
    countShowUp(oneDimArr, num);

    vector<double> evenElements = getEvenInteger(oneDimArr);

    cout << "6. Cac phan tu co phan nguyen chan: ";
    printValues(evenElements);
    cout << endl;

    cout << "7. Vi tri phan tu nho nhat mang: " << indexOfMinValue(oneDimArr) << endl;

    vector<double> reversed = reverseArr(oneDimArr);
    printValues("8. Mang dao nguoc: ", reversed);
    printValues("9. Cac so am trong mang: ", getNegative(oneDimArr));

    double from;
    double to;
    cout << "Nhap hai gia tri x, y de loc khoang [x, y]: ";
    if (!(cin >> from >> to))
    {
        cerr << "Khoang gia tri khong hop le." << endl;
        return 1;
    }
    cout << "10. So gia tri trong khoang [" << min(from, to) << ", " << max(from, to)
         << "]: " << countElementInRange(oneDimArr, from, to) << endl;
    cout << "11. Cac gia tri trong khoang [" << min(from, to) << ", " << max(from, to) << "]: ";
    printValues(getElementInRange(oneDimArr, from, to));
    cout << endl;

    return 0;
}