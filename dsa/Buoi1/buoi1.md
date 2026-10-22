## Con trỏ và ứng dụng

### Đặt vấn đề
trong 1 chương trình khai báo 3 biến. hỏi 3 biến được quản lý như thế nào

```cpp
#include <iostream>
using namespace std;

int main(){
    char c = 'F';
    int x = 10;
    double y = 1.8;

    return 0;
}
```

### Vùng nhớ RAM
trong ram chứa nhiều cell kích thước 1 byte tương ứng với 1 địa chỉ hệ 16 theo thứ tự

### Kích thước và địa chỉ của biến
- mỗi biến chiếm 1 hoặc nhiều cell liên tiếp tùy kiểu dữ liệu: `char` = 1 byte, `int` = 4 byte, `double` = 8 byte
- địa chỉ của biến là địa chỉ của cell đầu tiên mà biến chiếm

| Biến | Giá trị | Địa chỉ | Số cell |
|---|---|---|---|
| `c` | 'F' | 0xf919a1 | 1 |
| `x` | 10 | 0xf919a2 | 4 (a2 → a5) |
| `y` | 1.8 | 0xf919a6 | 8 (a6 → ad) |

> địa chỉ trên chỉ là ví dụ minh họa, mỗi lần chạy sẽ khác

### Ví dụ dùng & và *
```cpp
int x = 36;
cout << x;        // 36        (giá trị)
cout << &x;       // 0xb369    (địa chỉ của x)
cout << *(&x);    // 36        (giá trị tại địa chỉ đó)
```
- `*(&x)` cho lại chính giá trị của `x`

> lưu ý: dấu `*` có 2 nghĩa
> - `int* p;` => khai báo p là con trỏ
> - `*p` => lấy giá trị mà p đang trỏ tới

### Trả lời
- Hiểu đơn giản: giá trị của biến được đưa vào các cell trong RAM. Việc đưa vào bằng cách nào thuộc môn "Kiến trúc máy tính".
- Mỗi vùng nhớ được chọn làm nơi lưu biến có một **địa chỉ riêng** (duy nhất, không trùng nhau).
- Hễ gọi đến `c` là gọi đến vùng nhớ có địa chỉ tương ứng của `c`.
- Vì vậy, để quản lý biến `x` ta có thể dùng chính **địa chỉ** của nó.

=> **Con trỏ** là cách sử dụng giá trị địa chỉ.

> **Ví dụ so sánh:** địa chỉ giống như tờ giấy ghi kho hàng nằm ở đâu, còn gọi tên biến giống như lấy cả kho hàng ra.

## Toán tử &
- dùng để lấy địa chỉ của biến
- `&tên_biến`

## Toán tử *
- dùng để truy cập vào giá trị mà một con trỏ đang trỏ đến
- `*địa_chỉ`

## Con trỏ
- 1 biến lưu trữ địa chỉ của 1 vùng nhớ
- `kiểu_dữ_liệu* tên_biến`
- con trỏ chưa khởi tạo thì chứa giá trị rác, nên gán `NULL` nếu chưa trỏ vào đâu
- `int* p = NULL;` => con trỏ không trỏ vào biến nào cả
- `int n = 36; int* p = &n;` => p lưu địa chỉ của n
- `sizeof()` dùng để biết kích thước (byte) của kiểu dữ liệu hoặc biến, vd `sizeof(int)` = 4, `sizeof(double)` = 8. Con trỏ có kích thước cố định (4 byte với 32-bit, 8 byte với 64-bit), không phụ thuộc kiểu mà nó trỏ tới

## Cấp phát bộ nhớ tĩnh (Static Memory Allocation)
- khai báo biến hoặc mảng với kích thước cụ thể ngay tại thời điểm biên dịch
- vùng nhớ tồn tại suốt thời gian chạy chương trình và không thay đổi kích thước được

```cpp
int a[100]; // luôn chiếm 100 phần tử dù chỉ dùng 6
```

## Cấp phát bộ nhớ động (Dynamic Memory Allocation)
- cấp phát trong lúc chương trình đang chạy, không dùng nữa thì giải phóng

| Ngôn ngữ | Cấp phát | Thu hồi |
|---|---|---|
| C++ | `new` | `delete` |
| C | `malloc()`, `calloc()`, `realloc()` | `free()` |

```cpp
int* p = new int;            // cấp phát 1 ô int, giá trị chưa xác định
if (p == NULL) { cout << "Cap phat khong thanh cong"; }
*p = 6789;                   // gán giá trị vào vùng nhớ

int* q = new int(6789);      // vừa cấp phát vừa khởi tạo giá trị
```

- cú pháp: `kiểu_dữ_liệu* tên_p = new kiểu_dữ_liệu(giá_trị);`

## Thu hồi / Giải phóng
- dùng `delete` để thu hồi vùng nhớ
- sau khi `delete`, con trỏ vẫn trỏ đến địa chỉ cũ => truy cập tiếp cho kết quả không lường trước (rác)
- => hiện tượng **lạc con trỏ** (dangling pointer)
- cách tránh: sau `delete` gán `NULL` cho con trỏ

```cpp
int* p = new int(6789);
cout << *p;     // 6789

delete p;
p = NULL;       // tránh lạc con trỏ
```

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

---

# Bài tập buổi 1

## Bài 1
Xây dựng mảng 1 chiều lưu trữ các số thực. Sau đó, viết hàm thực hiện các chức năng sau:
1. Tạo giá trị ngẫu nhiên (số thực, 2 chữ số sau dấu chấm) thuộc khoảng (-268; 339). Số lượng thuộc đoạn [10; 20].
2. Xuất (in) mảng vừa tạo.
3. Tính tổng các giá trị có trong mảng.
4. Tính tổng, tích các giá trị có trong mảng (viết 1 hàm).
5. Đếm số lần xuất hiện 1 phần tử x bất kỳ.
6. Trả về các phần tử chẵn (chẵn-lẻ dựa vào giá trị nguyên của số thực) có trong mảng.
7. Tìm vị trí phần tử nhỏ nhất trong mảng.
8. Tạo một mảng đảo ngược.
9. Trả về các số âm trong mảng.
10. Trả về số lượng các giá trị trong mảng một chiều thuộc đoạn [x, y].
11. Trả về các giá trị trong mảng một chiều thuộc đoạn [x, y].

## Bài 2
Áp dụng kỹ thuật cấp phát động cho mảng một chiều. Viết HÀM thực hiện các yêu cầu sau:
1. Tạo mảng số thực có các giá trị sau: | 0.8 | 5.6 | 9.1 | 7.3 | 10 | 5.9 | 7.2 | 9.3 | 8.0 | 8.7 |
2. Xuất mảng (in) ra màn hình.
3. Kiểm tra mảng có toàn dương.
4. Kiểm tra mảng có đối xứng.
5. Kiểm tra trong mảng có chứa số nguyên tố, số chính phương.
6. Tìm một giá trị có trong mảng.
7. Tìm các số nguyên tố có trong mảng.
8. Tìm các chính phương có trong mảng.
9. Trả về các số âm có trong mảng.
10. Tìm các số dương trong mảng và tính tổng của chúng.
11. Đảo ngược các phần tử trong mảng.

> Lưu ý: trên slide, số thứ tự của Bài 2 đi 1, 2, 3, 6, 7, 8 rồi 9–13 (nhảy từ 3 sang 6, không có mục 4 và 5). Nội dung chỉ có 11 mục; mình đánh số lại liên tục từ 1 đến 11 cho dễ theo dõi.

## Bài 3
Viết chương trình quản lý và tính tiền lương cho các nhân viên trong một công ty. Nhân viên có các thông tin sau: mã nhân viên, họ tên, lương cơ bản, số ngày làm và lương hàng tháng.

Công thức tính tiền lương hàng tháng cho nhân viên như sau:
- Lương hàng tháng = lương căn bản + số ngày làm việc * 180.000 đ
- Nếu lương hàng tháng hơn 8.000.000 thì thưởng thêm 5%.
- Nếu lương cơ bản dưới 5.000.000 thì phụ cấp thêm 10%.

Áp dụng cấp phát động. Xây dựng chương trình đáp ứng các yêu cầu sau:
1. Tạo dữ liệu các nhân viên dùng để kiểm thử (10 nhân viên).
2. Xuất danh sách nhân viên trong công ty.
3. Tính và cập nhật tiền lương cho các loại nhân viên.
4. Tính tổng lương hàng tháng mà công ty phải trả cho toàn bộ nhân viên.
5. Tính tổng lương hàng tháng các nhân viên có lương cơ bản < 5 triệu.
6. Tìm nhân viên theo mã nhân viên.
7. Tìm các nhân viên có lương hàng tháng thấp nhất.
8. Tìm các nhân viên có lương cơ bản cao nhất.