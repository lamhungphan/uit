#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

double *initArr(int &size)
{
    const double values[] = {0.8, 5.6, 9.1, 7.3, 10.0, 5.9, 7.2, 9.3, 8.0, 8.7};
    size = sizeof(values) / sizeof(values[0]);

    double *arr = new double[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = values[i];
    }
    return arr;
}

void printArr(const double arr[], int size)
{
    cout << fixed << setprecision(2);
    for (int i = 0; i < size; ++i)
    {
        if (i > 0)
        {
            cout << ", ";
        }
        cout << arr[i];
    }
    cout << endl;
}

bool isAllPositive(const double arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] <= 0)
        {
            return false;
        }
    }
    return true;
}

bool isSymmetric(const double arr[], int size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        if (arr[i] != arr[size - 1 - i])
        {
            return false;
        }
    }
    return true;
}

bool toInteger(double value, int &integer)
{
    double intPart;
    if (modf(value, &intPart) != 0.0 ||
        intPart < numeric_limits<int>::min() ||
        intPart > numeric_limits<int>::max())
    {
        return false;
    }
    integer = static_cast<int>(intPart);
    return true;
}

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int divisor = 2; divisor <= n / divisor; ++divisor)
    {
        if (n % divisor == 0)
        {
            return false;
        }
    }
    return true;
}

bool isSquare(int n)
{
    if (n < 0)
    {
        return false;
    }
    int root = static_cast<int>(sqrt(n));
    return root * root == n;
}

bool isPrimeValue(double value)
{
    int integer;
    return toInteger(value, integer) && isPrime(integer);
}

bool isSquareValue(double value)
{
    int integer;
    return toInteger(value, integer) && isSquare(integer);
}

bool containsPrime(const double arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (isPrimeValue(arr[i]))
        {
            return true;
        }
    }
    return false;
}

bool containsSquare(const double arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (isSquareValue(arr[i]))
        {
            return true;
        }
    }
    return false;
}

void showCheckResult(const double arr[], int size)
{
    cout << "3. Mang " << (isAllPositive(arr, size) ? "toan so duong" : "khong toan so duong") << endl;
    cout << "4. Mang " << (isSymmetric(arr, size) ? "doi xung" : "khong doi xung") << endl;
    cout << "5. Mang " << (containsPrime(arr, size) ? "co" : "khong co") << " so nguyen to va "
         << (containsSquare(arr, size) ? "co" : "khong co") << " so chinh phuong" << endl;
}

bool findNumInArr(const double arr[], int size, double num)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

double *getValuesMatching(const double arr[], int size, bool (*matches)(double), int &resultSize)
{
    resultSize = 0;
    for (int i = 0; i < size; ++i)
    {
        if (matches(arr[i]))
        {
            ++resultSize;
        }
    }

    if (resultSize == 0)
    {
        return nullptr;
    }

    double *result = new double[resultSize];
    int resultIndex = 0;
    for (int i = 0; i < size; ++i)
    {
        if (matches(arr[i]))
        {
            result[resultIndex++] = arr[i];
        }
    }
    return result;
}

bool isNegative(double value)
{
    return value < 0;
}

double *getPrimeNum(const double arr[], int size, int &resultSize)
{
    return getValuesMatching(arr, size, isPrimeValue, resultSize);
}

double *getSquareNum(const double arr[], int size, int &resultSize)
{
    return getValuesMatching(arr, size, isSquareValue, resultSize);
}

double *getNegative(const double arr[], int size, int &resultSize)
{
    return getValuesMatching(arr, size, isNegative, resultSize);
}

double getSumPositive(const double arr[], int size)
{
    double sum = 0;
    cout << "10. Cac so duong: ";
    bool first = true;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] > 0)
        {
            if (!first)
            {
                cout << ", ";
            }
            cout << arr[i];
            sum += arr[i];
            first = false;
        }
    }
    cout << "\n    Tong cac so duong: " << sum << endl;
    return sum;
}

void printResult(const char *label, const double arr[], int size)
{
    cout << label;
    if (size == 0)
    {
        cout << "khong co";
    }
    else
    {
        printArr(arr, size);
        return;
    }
    cout << endl;
}

void reverseArr(double arr[], int size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        double temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main()
{
    int size = 0;
    double *arr = initArr(size);

    cout << "2. Mang da tao: ";
    printArr(arr, size);
    showCheckResult(arr, size);

    const double searchValue = 5.6;
    cout << "6. Gia tri " << searchValue << (findNumInArr(arr, size, searchValue) ? " co" : " khong co")
         << " trong mang" << endl;

    int primeCount;
    double *primes = getPrimeNum(arr, size, primeCount);
    printResult("7. Cac so nguyen to: ", primes, primeCount);
    delete[] primes;

    int squareCount;
    double *squares = getSquareNum(arr, size, squareCount);
    printResult("8. Cac so chinh phuong: ", squares, squareCount);
    delete[] squares;

    int negativeCount;
    double *negatives = getNegative(arr, size, negativeCount);
    printResult("9. Cac so am: ", negatives, negativeCount);
    delete[] negatives;

    getSumPositive(arr, size);

    reverseArr(arr, size);
    cout << "11. Mang sau khi dao nguoc: ";
    printArr(arr, size);

    delete[] arr;
    return 0;
}
