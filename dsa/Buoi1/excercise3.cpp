#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct Employee
{
    string id;
    string name;
    long long baseSalary;
    int workDays;
    long long monthlySalary;
};

Employee *createEmployees(int &count)
{
    count = 10;
    return new Employee[count]{
        {"NV001", "Nguyen Van An", 4500000, 22, 0},
        {"NV002", "Tran Thi Binh", 6000000, 24, 0},
        {"NV003", "Le Van Cuong", 3800000, 20, 0},
        {"NV004", "Pham Thi Dung", 8000000, 26, 0},
        {"NV005", "Hoang Van Giang", 4900000, 21, 0},
        {"NV006", "Vo Thi Hoa", 5500000, 23, 0},
        {"NV007", "Dang Van Khoa", 7000000, 22, 0},
        {"NV008", "Bui Thi Lan", 3000000, 25, 0},
        {"NV009", "Do Van Minh", 9000000, 20, 0},
        {"NV010", "Ngo Thi Nga", 4200000, 24, 0}};
}

void calculateMonthlySalaries(Employee employees[], int count)
{
    for (int i = 0; i < count; ++i)
    {
        long long salary = employees[i].baseSalary + employees[i].workDays * 180000LL;
        if (salary > 8000000)
        {
            salary += salary * 5 / 100;
        }
        if (employees[i].baseSalary < 5000000)
        {
            salary += employees[i].baseSalary * 10 / 100;
        }
        employees[i].monthlySalary = salary;
    }
}

void printEmployee(const Employee &employee)
{
    cout << left << setw(8) << employee.id
         << setw(22) << employee.name
         << right << setw(14) << employee.baseSalary
         << setw(11) << employee.workDays
         << setw(16) << employee.monthlySalary << " VND\n";
}

void printEmployees(const Employee employees[], int count)
{
    cout << left << setw(8) << "Ma NV"
         << setw(22) << "Ho ten"
         << right << setw(14) << "Luong co ban"
         << setw(11) << "Ngay lam"
         << setw(16) << "Luong thang" << '\n';
    for (int i = 0; i < count; ++i)
    {
        printEmployee(employees[i]);
    }
    cout << left;
}

long long totalMonthlySalary(const Employee employees[], int count)
{
    long long total = 0;
    for (int i = 0; i < count; ++i)
    {
        total += employees[i].monthlySalary;
    }
    return total;
}

long long totalLowBaseSalaryEmployees(const Employee employees[], int count)
{
    long long total = 0;
    for (int i = 0; i < count; ++i)
    {
        if (employees[i].baseSalary < 5000000)
        {
            total += employees[i].monthlySalary;
        }
    }
    return total;
}

const Employee *findEmployeeById(const Employee employees[], int count, const string &id)
{
    for (int i = 0; i < count; ++i)
    {
        if (employees[i].id == id)
        {
            return &employees[i];
        }
    }
    return nullptr;
}

void printLowestPaidEmployees(const Employee employees[], int count)
{
    if (count == 0)
    {
        cout << "Danh sach nhan vien rong";
        return;
    }

    long long lowestSalary = employees[0].monthlySalary;
    for (int i = 1; i < count; ++i)
    {
        if (employees[i].monthlySalary < lowestSalary)
        {
            lowestSalary = employees[i].monthlySalary;
        }
    }

    cout << "Nhan vien co luong thang thap nhat (" << lowestSalary << " VND):\n";
    for (int i = 0; i < count; ++i)
    {
        if (employees[i].monthlySalary == lowestSalary)
        {
            printEmployee(employees[i]);
        }
    }
}

void printHighestBaseSalaryEmployees(const Employee employees[], int count)
{
    if (count == 0)
    {
        cout << "Danh sach nhan vien rong";
        return;
    }

    long long highestBaseSalary = employees[0].baseSalary;
    for (int i = 1; i < count; ++i)
    {
        if (employees[i].baseSalary > highestBaseSalary)
        {
            highestBaseSalary = employees[i].baseSalary;
        }
    }

    cout << "Nhan vien co luong co ban cao nhat (" << highestBaseSalary << " VND):\n";
    for (int i = 0; i < count; ++i)
    {
        if (employees[i].baseSalary == highestBaseSalary)
        {
            printEmployee(employees[i]);
        }
    }
}

int main()
{
    int count = 0;
    Employee *employees = createEmployees(count);

    calculateMonthlySalaries(employees, count);

    cout << "Danh sach nhan vien:\n";
    printEmployees(employees, count);

    cout << "\nTong luong cong ty phai tra: "
         << totalMonthlySalary(employees, count) << " VND\n";
    cout << "Tong luong nhan vien co luong co ban duoi 5tr: "
         << totalLowBaseSalaryEmployees(employees, count) << " VND\n";

    cout << "\nNhap ma nhan vien can tim: ";
    string id;
    if (cin >> id)
    {
        const Employee *employee = findEmployeeById(employees, count, id);
        if (employee != nullptr)
        {
            printEmployee(*employee);
        }
        else
        {
            cout << "Khong tim thay nhan vien co ma " << id << "\n";
        }
    }
    else
    {
        cout << "Khong doc duoc ma nhan vien";
    }

    cout << '\n';
    printLowestPaidEmployees(employees, count);
    cout << '\n';
    printHighestBaseSalaryEmployees(employees, count);

    delete[] employees;
    return 0;
}
