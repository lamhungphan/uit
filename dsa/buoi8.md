# Tìm kiếm (Searching)

## 1. Tìm kiếm tuyến tính – Linear search

### Giới thiệu
- Tìm kiếm bằng cách kiểm tra **tuần tự từng phần tử** trong dãy (mảng, danh sách, ...) cho đến khi tìm thấy phần tử cần tìm
- Không hiệu quả nếu dãy lớn
- Dãy **không cần sắp xếp**
- Thời gian thực hiện phụ thuộc vào số lượng phần tử và vị trí cần tìm. Trường hợp xấu nhất thì phải tìm toàn bộ dãy

### Phương pháp
Ví dụ dãy `10 35 12 18 16 20 50 32`, tìm `value = 18`: duyệt qua từng phần tử (10, 35, 12, 18), so sánh với giá trị cần tìm, đến 18 thì dừng.

### Cài đặt
1. Bắt đầu từ phần tử đầu tiên
2. So sánh phần tử hiện tại với giá trị cần tìm. Nếu bằng thì tìm thấy => dừng
3. Di chuyển tuần tự: nếu giá trị hiện tại khác giá trị cần tìm thì sang phần tử kế tiếp
4. Lặp lại bước 2

```cpp
bool linearSearch(int a[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == value)
        {
            return true;
        }
    }
    return false;
}
```
Cũng có thể viết bằng `while`:
```cpp
bool linearSearch(int a[], int n, int value)
{
    int i = 0;
    while (i < n)
    {
        if (a[i] == value)
            return true;
        i++;
    }
    return false;
}
```

## 2. Tìm kiếm nhị phân – Binary search

### Giới thiệu
- Áp dụng để tìm một phần tử trong một dãy **đã được sắp xếp** (hay dãy có thứ tự)
- Ý tưởng chính:
  - Tìm vị trí giữa
  - Lấy giá trị tại vị trí giữa so sánh với giá trị cần tìm
- Hoạt động hiệu quả vì mỗi lần so sánh sẽ **loại bỏ một nửa phần tử** khỏi phạm vi tìm kiếm

### Phương pháp
Ví dụ dãy `10 15 18 25 27 35` (n = 6, chỉ số 0 → 5), tìm `value = 27`.

Các bước:
1. Xác định phạm vi tìm kiếm `L` và `R`
2. Tính vị trí giữa `M = (L + R) / 2`
3. So sánh giá trị giữa và giá trị cần tìm
   - Nếu **bằng** thì tìm thấy
   - Nếu **khác** thì cập nhật phạm vi tìm `L` hoặc `R`
4. Cập nhật lại `L` hoặc `R`
   - Nếu giá trị tìm **<** giá trị giữa thì `R = M - 1`
   - Nếu giá trị tìm **>** giá trị giữa thì `L = M + 1`
5. Lặp lại, bắt đầu lại từ bước 2 nếu `L <= R`

Ví dụ không tìm thấy: `value = 26` trên dãy trên.
- `L = 0, R = 5` => `M = 2`, `a[2] = 18 < 26` => `L = 3`
- `L = 3, R = 5` => `M = 4`, `a[4] = 27 > 26` => `R = 3`
- `L = 3, R = 3` => `M = 3`, `a[3] = 25 < 26` => `L = 4`
- `L = 4 > R = 3` => dừng vì không còn thỏa điều kiện `L <= R`: **không tìm thấy** giá trị trong dãy

> Slide chỉ ghi chi tiết phần cuối của ví dụ này (từ `L = 3, R = 3`). Hai bước đầu trên là mình tính lại cho đủ chuỗi.

### Cài đặt
```cpp
bool binarySearch(int a[], int n, int value)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int m = left + (right - left) / 2;

        if (a[m] == value)
            return true;

        if (a[m] < value)
            left = m + 1;
        else if (a[m] > value)
            right = m - 1;
    }
    return false;
}
```
- Trong code, vị trí giữa viết `left + (right - left) / 2` thay vì `(left + right) / 2` (cho cùng kết quả, nhưng tránh tràn số khi `left + right` rất lớn)

## 3. Tìm kiếm nội suy – Interpolation search

### Giới thiệu
- Tương tự tìm kiếm nhị phân, cũng áp dụng cho dãy **có thứ tự**
- Nâng cao từ ý tưởng của tìm kiếm nhị phân
- Tính toán **vị trí giữa** bằng cách kết hợp thêm **giá trị cần tìm**:

```
vị_trí = L + ((R - L) / (a[R] - a[L])) * (value - a[L])
```

### Cài đặt
Giống tìm kiếm nhị phân, chỉ đổi cách tính `m`:
```cpp
bool interpolationSearch(int a[], int n, int value)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int m = left + ((right - left) / (a[right] - a[left])) * (value - a[left]);

        if (a[m] == value)
            return true;

        if (a[m] < value)
            left = m + 1;
        else if (a[m] > value)
            right = m - 1;
    }
    return false;
}
```
> Slide chỉ đưa công thức tính `m` và ghi tên hàm là `...Search`; mình ghép lại thành hàm hoàn chỉnh với tên `interpolationSearch`. Lưu ý khi tự chạy thử: với kiểu `int`, `(right - left) / (a[right] - a[left])` bị cắt phần thập phân nên thường ra `0`; thường người ta viết `left + (right - left) * (value - a[left]) / (a[right] - a[left])`. Cũng cần tránh chia cho 0 khi `a[right] == a[left]` và kiểm tra `value` nằm trong khoảng `[a[left], a[right]]` để `m` không vượt ra ngoài mảng. Đây là phần mình bổ sung, slide không đề cập.

## So sánh nhanh
| | Tuyến tính | Nhị phân | Nội suy |
|---|---|---|---|
| Dãy cần sắp xếp | Không | Có | Có |
| Cách chọn vị trí so sánh | Lần lượt từng phần tử | Vị trí giữa | Vị trí giữa tính theo giá trị cần tìm |
| Hiệu quả | Kém nếu dãy lớn | Loại bỏ một nửa dãy mỗi lần | Cải tiến từ nhị phân |

## Bài tập
- Viết hàm nhập giá trị tự động cho mảng, các giá trị thuộc [100; 999], số lượng phần tử thuộc [30; 50].
- Viết hàm nhập giá trị tự động **tăng dần** cho mảng, phần tử đầu tiên ≤ 130, các phần tử kề nhau không quá 15, các giá trị thuộc [100; 999], số lượng phần tử thuộc [30; 50].
- Viết hàm nhập giá trị tự động **tăng dần** cho mảng, phần tử đầu tiên ≤ 130, các phần tử kề nhau không quá 15, các giá trị thuộc [100; 250], số lượng phần tử thuộc [30; 50].
- Viết hàm xuất mảng.
- Viết hàm tìm kiếm một phần tử trong mảng bằng tìm kiếm tuyến tính.
- Viết hàm tìm kiếm một phần tử trong mảng bằng tìm kiếm nhị phân.
- Viết hàm tìm kiếm một phần tử trong mảng bằng tìm kiếm nội suy.
- Viết hàm so sánh số lần thực hiện tìm kiếm cùng một giá trị cho 3 thuật toán tìm kiếm trên.
