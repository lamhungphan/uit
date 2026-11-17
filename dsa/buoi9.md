# Sắp xếp (Sorting)

## 1. Selection Sort (sắp xếp chọn trực tiếp)

### Giới thiệu
- Áp dụng cho dãy: mảng, danh sách, ...
- Lặp qua dãy, chọn phần tử:
  - **nhỏ nhất** (sắp xếp tăng)
  - hoặc **lớn nhất** (sắp xếp giảm)

  từ dãy chưa được sắp xếp, sau đó **hoán đổi** phần tử đó với phần tử đầu tiên của dãy chưa được sắp xếp
- Quá trình lặp lại cho đến khi toàn bộ dãy được sắp xếp

### Phương pháp
Ví dụ dãy `79 39 26 66 55 20` (sắp xếp tăng):

| Lần | Dãy sau khi hoán đổi | Ghi chú |
|---|---|---|
| ban đầu | 79 39 26 66 55 20 | |
| #1 | **20** 39 26 66 55 79 | nhỏ nhất là 20, đổi chỗ với 79 |
| #2 | 20 **26** 39 66 55 79 | nhỏ nhất của phần còn lại là 26, đổi chỗ với 39 |
| #3 | 20 26 **39** 66 55 79 | 39 đã đúng vị trí |
| #4 | 20 26 39 **55** 66 79 | đổi chỗ 66 và 55 |
| #5 | 20 26 39 55 **66** 79 | 66 đã đúng vị trí |

### Thuật toán
1. Bắt đầu: đánh dấu toàn bộ là **dãy chưa sắp xếp**
2. Tìm phần tử nhỏ nhất trong dãy chưa sắp xếp
3. Hoán vị phần tử nhỏ nhất đó với phần tử đầu tiên của dãy chưa sắp xếp
4. Sau khi hoán vị xong thì đánh dấu phần tử đó thuộc **dãy đã sắp xếp**
5. Lặp lại từ bước 2 cho dãy chưa sắp xếp

Mã giả theo slide:
```
hàm selectionSort(mảng A, n)
  min: vị trí có giá trị nhỏ nhất
  for i = 0 ---> n - 1
    min = i
    for j = i + 1 ---> n
      if A[j] < A[min]
        min = j
    if min khác i
      hoán vị A[i] và A[min]
```

### Cài đặt
```cpp
void selectionSort(int a[], int n)
{
    int m;
    for (int i = 0; i < n - 1; i++)
    {
        m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[m])
                m = j;
        }
        if (m != i)
            swap(a[i], a[m]);
    }
}
```
- `m` là vị trí của phần tử nhỏ nhất trong đoạn chưa sắp xếp
- Muốn sắp xếp **giảm dần**: đổi điều kiện thành `a[j] > a[m]` (chọn phần tử lớn nhất)

## 2. Insertion Sort (sắp xếp chèn trực tiếp)

### Giới thiệu
- Áp dụng cho dãy: mảng, danh sách, ...
- Thực hiện bằng cách:
  - Bắt đầu từ **phần tử thứ hai**
  - Sau đó **chèn** phần tử vào vị trí thích hợp (trong phần đã sắp xếp)
  - Lặp lại cho phần tử tiếp theo đến hết dãy

### Phương pháp
Ví dụ dãy `79 39 26 66 55 20` (sắp xếp tăng):

| Lần | Dãy | Ghi chú |
|---|---|---|
| ban đầu | 79 39 26 66 55 20 | phần tử đầu (79) coi như đã sắp xếp |
| #1 | **39 79** 26 66 55 20 | chèn 39 vào trước 79 |
| #2 | **26 39 79** 66 55 20 | chèn 26 vào đầu |
| #3 | **26 39 66 79** 55 20 | chèn 66 vào giữa 39 và 79 |
| #4 | **26 39 55 66 79** 20 | chèn 55 vào giữa 39 và 66 |
| #5 | **20 26 39 55 66 79** | chèn 20 vào đầu |

### Thuật toán
1. Quy định phần tử đầu tiên của dãy thuộc **dãy đã sắp xếp**
2. Chọn phần tử tiếp theo: phần tử này sẽ thuộc dãy chưa sắp xếp
3. So sánh phần tử được chọn với các phần tử trong dãy đã sắp xếp để tìm vị trí thích hợp chèn vào
   - Dịch chuyển tất cả các phần tử lớn hơn phần tử hiện tại trong dãy đã sắp xếp sang phải 1 vị trí
4. Chèn phần tử vào vị trí thích hợp
5. Lặp lại bước 2 cho mỗi phần tử tiếp theo cho đến khi toàn bộ dãy được sắp xếp

### Cài đặt
```cpp
void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int item = a[i];          // phần tử cần chèn
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] < item)
                break;            // đã tìm được vị trí
            a[j + 1] = a[j];      // dịch sang phải 1 vị trí
        }
        a[j + 1] = item;          // chèn vào vị trí thích hợp
    }
}
```
- Muốn sắp xếp **giảm dần**: đổi điều kiện `a[j] < item` thành `a[j] > item`

## 3. Tính thời gian sắp xếp

### Phương pháp
- Lấy thời gian CPU của một tiến trình dùng hàm `clock()`
- Khai báo thư viện `#include <time.h>` để dùng
- Hằng số `CLOCKS_PER_SEC`: số lần tích tắc mỗi giây

```cpp
clock_t start, end;
double cpu_time_used;

start = clock();

/* Do the work. */

end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
```

### Áp dụng
Bọc lời gọi hàm sắp xếp bằng hai mốc thời gian:
```cpp
double sort_time(int a[], int n)
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    selectionSort(a, n);      // đổi thành insertionSort(a, n) để đo thuật toán kia

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    return cpu_time_used;
}
```

## So sánh nhanh
| | Selection Sort | Insertion Sort |
|---|---|---|
| Ý tưởng | Chọn phần tử nhỏ nhất (hoặc lớn nhất) của dãy chưa sắp xếp, đổi chỗ với phần tử đầu dãy đó | Lấy từng phần tử, chèn vào đúng vị trí trong dãy đã sắp xếp |
| Bắt đầu | Từ phần tử đầu tiên (`i = 0`) | Từ phần tử thứ hai (`i = 1`) |
| Thao tác chính | Hoán vị | Dịch chuyển sang phải rồi chèn |

## Bài tập
Khởi tạo mảng `arrayA` với kích thước 1e6 phần tử kiểu số thực. Viết hàm thực hiện các yêu cầu sau:
- Viết hàm khởi tạo tự động 100000 phần tử kiểu số thực (lấy 3 số sau dấu thập phân) cho mảng.
- Viết hàm xuất các giá trị trong mảng.
- Viết hàm sắp xếp mảng tăng/giảm dần bằng thuật toán chọn trực tiếp.
- Viết hàm tính thời gian thực hiện sắp xếp mảng tăng/giảm dần bằng thuật toán chọn trực tiếp.
- Viết hàm sắp xếp mảng tăng/giảm dần bằng thuật toán chèn trực tiếp.
- Viết hàm tính thời gian thực hiện sắp xếp mảng tăng/giảm dần bằng thuật toán chèn trực tiếp.

> Đề bài ghi mảng 1e6 phần tử nhưng chỉ khởi tạo 100000 phần tử. Đây là nguyên văn slide, bạn nên hỏi lại giảng viên dùng số nào. Ngoài ra các hàm trong slide dùng `int a[]`, còn đề yêu cầu số thực nên khi làm bài cần đổi kiểu sang `double`.
