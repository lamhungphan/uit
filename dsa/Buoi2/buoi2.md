## Con trỏ và hàm
- con trỏ dùng làm tham số hoặc kiểu trả về của hàm
- truyền địa chỉ vào hàm để hàm thay đổi được giá trị gốc

```cpp
void hoan_vi(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// gọi: hoan_vi(&x, &y);
```

## Con trỏ và mảng 1 chiều
- tên mảng chính là địa chỉ phần tử đầu tiên: `a` tương đương `&a[0]`
- địa chỉ các phần tử liên tiếp nhau, cách nhau đúng bằng kích thước kiểu dữ liệu (int cách 4 byte, double cách 8 byte)

### Phép cộng/trừ trên con trỏ
- con trỏ cộng/trừ một số nguyên n thì địa chỉ tăng/giảm `n * sizeof(kiểu)` byte, chứ không phải n byte
- `p + 1` trỏ đến phần tử kế tiếp, `p - 1` trỏ đến phần tử trước đó

```cpp
int a[] = {5, 3, 7, 5, 9, 1};
int* p = &a[1];
cout << *(p - 1);  // 5
cout << *(p + 1);  // 7
```

### Truy xuất phần tử
- `a[i]` tương đương `*(a + i)`
- `a + i` là địa chỉ, `*(a + i)` là giá trị

```cpp
int tinhTong(int* a, int n)
{
    int t = 0;
    for (int i = 0; i < n; i++)
        t = t + *(a + i);
    return t;
}
```

### Cấp phát động mảng 1 chiều
- cú pháp: `Kiểu_Dữ_Liệu* ten_mang = new Kiểu_Dữ_Liệu[kích_thước];`

```cpp
int* a = new int[100];
```

## Con trỏ và cấu trúc
- khai báo: `KieuCauTruc* ten_bien;`
- cấp phát: `ten_bien = new KieuCauTruc();`
- truy xuất thuộc tính qua con trỏ dùng toán tử `->`

```cpp
struct Diem { int x; int y; };

Diem a = {3, 5};
Diem* p = &a;
cout << p->x << " " << p->y;
```
