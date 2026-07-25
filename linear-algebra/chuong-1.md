# 1. Khái niệm

## Định nghĩa

**Ma trận** là một bảng số hình chữ nhật, gồm **hàng** (dòng) và **cột**.

Ví dụ:
```
    [ 1  2  3 ]    ← hàng 1
A = [ 4  5  6 ]    ← hàng 2
```
Ma trận trên có **2 hàng, 3 cột** → ký hiệu `2×3`.

- Mỗi vị trí trong bảng gọi là **phần tử**, ký hiệu `aᵢⱼ` (hàng `i`, cột `j`).

### Các loại số cơ bản

| Ký hiệu | Tên | Ví dụ | Giải thích dễ hiểu |
|---|---|---|---|
| **N** | Số tự nhiên | `0, 1, 2, 3, ...` | Số đếm thông thường, không âm |
| **Z** | Số nguyên | `..., -2, -1, 0, 1, 2, ...` | N + thêm số âm |
| **Q** | Số hữu tỉ | `-3, 0, 1/2, 0.75, -2/7, 5` | Viết được dưới dạng **phân số** `a/b` |
| **R** | Số thực | `-1, 0, √2, π, 0.333..., e` | Q + số vô tỉ (thập phân **không tuần hoàn**) |
| **C** | Số phức | `2+3i, -i, 5` | R + số ảo `i` (với `i² = -1`) |

**Số vô tỉ** là số thập phân vô hạn **không tuần hoàn**, không viết được thành phân số `a/b`.

Ví dụ: `√2 = 1.4142135623...`, `π = 3.1415926535...`, `e = 2.7182818284...`

**Thứ tự bao hàm**: `N ⊂ Z ⊂ Q ⊂ R ⊂ C` (C rộng nhất)

### Ma trận zero (ma trận không)
Tất cả phần tử đều bằng 0. Giống tờ giấy trắng.

Ví dụ:
```
0 = [ 0  0  0 ]    0 = [ 0  0  0 ]
    [ 0  0  0 ]        [ 0  0  0 ]
                       [ 0  0  0 ]
```

### Ma trận đường chéo (diagonal matrix)
Ma trận vuông, **chỉ có số trên đường chéo chính**, còn lại = 0.

Ví dụ:
```
    [ 3   0   0   0 ]
A = [ 0  -2   0   0 ]
    [ 0   0   5   0 ]
    [ 0   0   0  -8 ]
```

### Ma trận đơn vị (Identity matrix)
Ma trận đường chéo đặc biệt: **đường chéo toàn 1**, ký hiệu `I` (giống "số 1" trong thế giới ma trận).

Ví dụ:
```
    [ 1  0  0 ]
I = [ 0  1  0 ]
    [ 0  0  1 ]
```

### Ma trận tam giác trên (upper triangular matrix)
Ma trận vuông: **dưới đường chéo chính toàn 0**, phần còn lại tùy ý.

Ví dụ:
```
    [ 1   0   8  -3 ]
A = [ 0   3  -2   9 ]
    [ 0   0   7   0 ]
    [ 0   0   0  -6 ]
```

### Ma trận tam giác dưới (lower triangular matrix)
Ma trận vuông: **trên đường chéo chính toàn 0**, phần còn lại tùy ý.

Ví dụ:
```
    [ 9   0   0   0 ]
A = [ 0  -4   0   0 ]
    [ 5   2   6   0 ]
    [ 1   0  -3   5 ]
```

# 2. Các phép biến đổi sơ cấp trên dòng đối với ma trận (Row Elementary Operations)

Có **3 loại** phép biến đổi

### Loại 1 - Nhân một dòng với một số
Lấy cả dòng `i` nhân với một số `c` (khác 0).

### Loại 2 - Đổi chỗ 2 dòng
Hoán vị dòng `i` và dòng `j`.

### Loại 3 - Cộng bội của dòng này vào dòng kia
Thay dòng `i` bằng **dòng i + c × dòng j**.

> ⚠ **Lưu ý**: Trong loại 3, bắt buộc phải dùng chính dòng `i` để tính. Ví dụ: `dòng(2) = 4×dòng(1) + 5×dòng(3)` không làm được, phải có `dòng(2)` trong biểu thức.

### Phép cộng ma trận
Cộng 2 ma trận **cùng cỡ**: cộng từng số ở vị trí tương ứng với nhau.

```
[ 1 -2  5 ]   [ -5  9 -6 ]   [ -4  7 -1 ]
[ -4 5 -8 ] + [ -3  7 -2 ] = [ -7 12 -10 ]
```

### Phép nhân một số với ma trận
Nhân số đó với **từng phần tử** trong ma trận.

Ví dụ: `5A` = lấy từng số trong A nhân với 5.

### Phép nhân ma trận
- Chỉ nhân được khi **số cột của A = số hàng của B**.
- Cách tính: lấy hàng `i` của A × cột `j` của B (nhân từng cặp rồi cộng).
- ⚠ **Không có tính giao hoán**: A×B ≠ B×A (nói chung).

# 3. Hệ phương trình tuyến tính (Linear Equations)

Hệ = chứa nhiều phương trình `a₁₁x₁ + a₁₂x₂ + ... + a₁ₙxₙ = b₁` (n ẩn, m phương trình).

**Viết gọn dưới 2 dạng:**

1. **Dạng tích ma trận**: `A·X = B`
2. **Dạng ma trận hóa** (augmented matrix): `(A | B)` — dán A và B cạnh nhau

Ví dụ:
```
Hệ:
  4x₁ + 0x₂ + 2x₃ +  x₄ + 2x₅ + 0x₆ =  2
   x₁ + 0x₂ + 9x₃ + 0x₄ + 0x₅ + 3x₆ = -5
   x₁ + 7x₂ + 0x₃ + 2x₄ + 6x₅ - 3x₆ =  8

  → A·X = B      và      (A | B) dạng bảng số
```

# 4. Cách giải hệ phương trình tuyến tính (Phương pháp Gauss-Jordan)

Dùng 3 phép biến đổi dòng để đưa ma trận hóa về dạng **cột chuẩn** (dạng đẹp).

**Mục tiêu**: tạo các cột chuẩn từ trái → phải:
```
       [ 1 ]   [ 0 ]   [ 0 ]
E₁ =   [ 0 ] , [ 1 ] , [ 0 ] , ...
       [ 0 ]   [ 0 ]   [ 1 ]
```
**2 nguyên tắc** khi xây dựng cột chuẩn:
1. Đang xây cột `Eₖ` thì phải giữ nguyên các cột `E₁, E₂, ..., Eₖ₋₁` đã có.
2. Nếu cột này không xây được → skip sang cột bên phải.

**Cách kiểm tra cột có chuẩn hóa được không?**
- Nhìn vào **phần từ vị trí đang xét trở xuống** của cột.
- Nếu **có ≥ 1 số ≠ 0** → được.
- Nếu **toàn 0** → không được.

### 3 trường hợp kết luận:

| Trường hợp | Dấu hiệu | Kết luận |
|---|---|---|
| TH1 | Có dòng `(0 0 0 ... 0 \| a≠0)` | **Vô nghiệm** |
| TH2 | n cột chuẩn liên tiếp, đẹp như I | **Nghiệm duy nhất** (đọc thẳng kết quả) |
| TH3 | Chỉ có r cột chuẩn (r < n), xen kẽ cột không chuẩn | **Vô số nghiệm** (gán ẩn tự do = tham số) |

### Ví dụ vô số nghiệm:
```
(A|B) → [ 1  0  0  2  0  3 |  5 ]
         [ 0  1  0  1  0 -1 | -3 ]
         [ 0  0  1  1  0  0 |  7 ]
         [ 0  0  0  0  1  2 |  4 ]
```
Cột 4 và cột 6 không chuẩn hóa được → đặt `x₄ = a, x₆ = b` (a, b tùy ý), tính các ẩn còn lại theo a, b.