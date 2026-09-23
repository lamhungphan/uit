# Bảng chuyển đổi Thập phân sang Nhị phân ($2^0$ đến $2^{20}$)

| **Luỹ thừa** | **Hệ Thập phân (Bytes)** | **Hệ Nhị phân (Binary)** | **Dung lượng (KB)** |
| :---: | :---: | :---: | :---: |
| $2^{0}$ | 1 | `1` | 0.0009765625 KB |
| $2^{1}$ | 2 | `10` | 0.001953125 KB |
| $2^{2}$ | 4 | `100` | 0.00390625 KB |
| $2^{3}$ | 8 | `1000` | 0.0078125 KB |
| $2^{4}$ | 16 | `10000` | 0.015625 KB |
| $2^{5}$ | 32 | `100000` | 0.03125 KB |
| $2^{6}$ | 64 | `1000000` | 0.0625 KB |
| $2^{7}$ | 128 | `10000000` | 0.125 KB |
| $2^{8}$ | 256 | `100000000` | 0.25 KB |
| $2^{9}$ | 512 | `1000000000` | 0.5 KB |
| $2^{10}$ | 1,024 | `10000000000` | **1 KB** |
| $2^{11}$ | 2,048 | `100000000000` | **2 KB** |
| $2^{12}$ | 4,096 | `1000000000000` | **4 KB** |
| $2^{13}$ | 8,192 | `10000000000000` | **8 KB** |
| $2^{14}$ | 16,384 | `100000000000000` | **16 KB** |
| $2^{15}$ | 32,768 | `1000000000000000` | **32 KB** |
| $2^{16}$ | 65,536 | `10000000000000000` | **64 KB** |
| $2^{17}$ | 131,072 | `100000000000000000` | **128 KB** |
| $2^{18}$ | 262,144 | `1000000000000000000` | **256 KB** |
| $2^{19}$ | 524,288 | `10000000000000000000` | **512 KB** |
| $2^{20}$ | 1,048,576 | `100000000000000000000` | **1,024 KB (1 MB)** |

> **Quy tắc:** Trong hệ nhị phân, $2^n$ luôn có dạng chữ số `1` đứng đầu, theo sau bởi đúng $n$ chữ số `0`.
> 
> **Cách tính nhanh trên máy tính Casio:**
> - Chuyển sang chế độ hệ cơ số: bấm **`MODE` $\to$ `BASE-N`** (hoặc **`MENU` $\to$ `3`** trên FX-580VN X).
> - Để chuyển đổi giá trị lũy thừa $2^n$ hoặc tính toán nhanh:
>   - Nhập giá trị cơ số 10 (DEC) $\to$ ấn `=` $\to$ ấn nút **`BIN`** (thường ở phím `log` hoặc `x²` tùy dòng máy) để đổi sang nhị phân.
>   - Đơn vị tính cơ bản trong máy tính: $1 \text{ KB} = 1024 \text{ Bytes} = 2^{10} \text{ Bytes}$.

# Tính thời gian truy xuất bộ nhớ hiệu dụng (EAT)
## 1.
Xét một hệ thống sử dụng kỹ thuật phân trang, với bảng trang được lưu trữ trong bộ nhớ chính. Thời gian cho một lần truy xuất bộ nhớ bình thường là $250\text{ ns}$. Nếu sử dụng TLBs với hit-ratio (tỷ lệ tìm thấy) là $85\%$, thời gian để tìm trong TLBs xem như bằng $0$, thì thời gian truy xuất bộ nhớ trong hệ thống là khoảng bao nhiêu?

* **TLB hit ($85\%$):** 
  * Chỉ cần $1$ lần truy xuất bộ nhớ chính (để lấy dữ liệu).
  * $\text{Thời gian} = 250\text{ ns}$

* **TLB miss ($15\%$):** 
  * Cần $2$ lần truy xuất bộ nhớ chính ($1$ lần truy xuất bảng trang + $1$ lần truy xuất dữ liệu).
  * $\text{Thời gian} = 250\text{ ns} + 250\text{ ns} = 500\text{ ns}$

$$\text{EAT} = 0.85 \times 250 + 0.15 \times 500 = 212.5 + 75 = 287.5\text{ ns} $$
