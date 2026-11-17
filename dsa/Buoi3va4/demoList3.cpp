#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

struct SinhVien
{
    string maSV;
    string hoTen;
    float diemTB;
};

void inDanhSachSV(const forward_list<SinhVien>& ds)
{
    for (const auto& sv : ds)
    {
        cout << sv.maSV << " - " << sv.hoTen << " - Diem: " << sv.diemTB << endl;
    }
}

int main()
{
    // --- PHẦN 1: Thao tác với kiểu dữ liệu nguyên thủy (int) ---
    forward_list<int> ds = {20, 30}; // Khởi tạo sẵn phần tử

    ds.push_front(10); // Thêm vào đầu danh sách -> {10, 20, 30}
    
    // Chèn số 15 vào sau phần tử đầu tiên (sau số 10)
    auto it = ds.begin();
    ds.insert_after(it, 15); // -> {10, 15, 20, 30}

    ds.pop_front(); // Xóa phần tử đầu tiên (số 10) -> {15, 20, 30}

    cout << "Danh sach so nguyen: ";
    for (int x : ds) {
        cout << x << " ";
    }
    cout << "\n-------------------\n";

    // --- PHẦN 2: Thao tác với struct SinhVien ---
    forward_list<SinhVien> dssv;

    // Thêm sinh viên vào đầu danh sách
    dssv.push_front({"SV01", "Nguyen Van A", 8.5});
    dssv.push_front({"SV02", "Tran Thi B", 9.0});
    dssv.push_front({"SV03", "Le Van C", 7.2});

    cout << "Danh sach sinh vien (thu tu nguoc lai do push_front):\n";
    inDanhSachSV(dssv);

    // Xóa sinh viên ở đầu danh sách (SV03)
    dssv.pop_front();

    cout << "\nSau khi xoa sinh vien dau tien:\n";
    inDanhSachSV(dssv);

    return 0;
}