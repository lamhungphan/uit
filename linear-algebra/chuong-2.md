# Chương 2: Hệ phương trình tuyến tính

## 1. Hạng của ma trận & Ma trận bậc thang

### Ma trận bậc thang (echelon form)
Là ma trận có dạng "bậc thang":
- Các hàng zero nằm dưới cùng
- Số khác 0 đầu tiên của hàng dưới nằm **bên phải** so với hàng trên

Ví dụ (dạng bậc thang):
```
[ 1  2  3  4 ]
[ 0  5  6  7 ]
[ 0  0  0  8 ]    ← OK
```

**Không** phải bậc thang:
```
[ 5  1  2 ]
[ 1  3  4 ]       ← số đầu hàng 2 (số 1) nằm bên trái số đầu hàng 1 (số 5)
```

### Hạng của ma trận (rank) — ký hiệu r(A)
- **Hạng = số hàng khác 0** của ma trận bậc thang
- Cách tìm: biến đổi sơ cấp đưa ma trận về dạng bậc thang, rồi **đếm số hàng khác 0**

Ví dụ:
```
      [ 1  2  3 ]
A →   [ 0  5  6 ]    ← 2 hàng khác 0
      [ 0  0  0 ]
```
→ r(A) = 2

### Định lý Kronecker-Capelli (quan trọng)
Xét hệ AX = B với A là ma trận hệ số, $\bar{A}$ là ma trận bổ sung (A|B):

| Điều kiện | Kết luận |
|---|---|
| r(A) < r($\bar{A}$) | **Vô nghiệm** |
| r(A) = r($\bar{A}$) = n | **Nghiệm duy nhất** |
| r(A) = r($\bar{A}$) = k < n | **Vô số nghiệm** (phụ thuộc n−k tham số) |

---

## 2. Ma trận khả nghịch (invertible matrix)

### Định nghĩa
Ma trận vuông A gọi là **khả nghịch** nếu tồn tại ma trận A⁻¹ sao cho:
```
A × A⁻¹ = A⁻¹ × A = I (ma trận đơn vị)
```

### Cách 1: Tìm A⁻¹ bằng biến đổi sơ cấp trên dòng
Ghép (A | I) rồi biến đổi đến khi bên trái thành I:
```
(A | I) → ... → (I | A⁻¹)
```
- Nếu bên trái **không** thành I → A không khả nghịch

Ví dụ:
```
Cho A = [ -3  4  6 ]     Ghép A|I rồi biến đổi...
        [  0 -1 -1 ]
        [  2 -3 -4 ]

Kết quả: A⁻¹ = [ 1  -2   2 ]
               [ -2  0  -3 ]
               [  2  -1   3 ]
```

### Cách 2: Tìm A⁻¹ bằng định thức
1. Tính det(A). Nếu det(A) = 0 → không khả nghịch
2. Nếu det(A) ≠ 0:
   - Tìm phần bù đại số cᵢⱼ = (-1)ⁱ⁺ʲ × det(bỏ hàng i, cột j)
   - Lập ma trận C = (cᵢⱼ)
   - Chuyển vị C → Cᵀ
   - **A⁻¹ = (1/det(A)) × Cᵀ**

Ví dụ:
```
A = [ -3  2  10 ]
    [  8 -1   7 ]
    [  6  4  -2 ]

det(A) = 574 ≠ 0 → khả nghịch

C = [ -26   58   38 ]     Cᵀ = [ -26   44   24 ]
    [  44  -54   24 ]          [  58  -54  101 ]
    [  24  101  -13 ]          [  38   24  -13 ]

A⁻¹ = (1/574) × Cᵀ
```

---

## 3. Giải hệ bằng phương pháp khử Gauss

**Các bước:**
1. Viết ma trận bổ sung (A | B)
2. Biến đổi sơ cấp trên dòng → đưa về dạng **bậc thang thu gọn** (phần tử cơ sở = 1)
3. Viết lại hệ phương trình tương ứng
4. **Thay thế lùi**: tìm ẩn cuối trước, thay lên trên
5. Nếu vô số nghiệm: đặt tham số cho các ẩn **không phải phần tử cơ sở**

Ví dụ (nghiệm duy nhất):
```
x₁ + x₂ - x₃ = 2
2x₁ + 3x₂ + x₃ = -1    → biến đổi → x₁ = -9
5x₁ + 8x₂ + 2x₃ = 3                x₂ = 7
                                    x₃ = -4
```

Ví dụ (vô số nghiệm):
```
Đưa về bậc thang → r(A) = r(Ā) = 2 < 4 (số ẩn)
→ Đặt x₃ = a, x₄ = b → tính x₁, x₂ theo a, b
```

---

## 4. Giải hệ bằng phương pháp Cramer

### Chỉ áp dụng cho hệ Cramer (vuông, det ≠ 0)

**Công thức:**
```
xᵢ = det(Aᵢ) / det(A)
```
Trong đó Aᵢ là ma trận A đã thay cột i bằng cột B.

Ví dụ:
```
Hệ:  2x₁ + 2x₂ + 5x₃ = 21
     2x₁ + 3x₂ + 6x₃ = 26
      x₁ - 6x₂ - 9x₃ = -37

det(A) = -9 ≠ 0

x₁ = det(A₁)/det(A) = -12/-9 = 4/3
x₂ = det(A₂)/det(A) = -20/-9 = 20/9
x₃ = det(A₃)/det(A) = -25/-9 = 25/9
```

> ⚠ **Lưu ý**: Nếu mọi det = 0 thì Cramer không kết luận được → phải dùng Gauss.

---

## 5. Hệ phương trình tuyến tính thuần nhất

**Dạng:** AX = 0 (vế phải toàn 0)

- Luôn có **nghiệm tầm thường**: x₁ = x₂ = ... = xₙ = 0
- Nếu r(A) = n → nghiệm duy nhất (chính là nghiệm tầm thường)
- Nếu r(A) = k < n → **vô số nghiệm**

### Bộ nghiệm cơ bản
Khi hệ có vô số nghiệm với n−k tham số, lần lượt cho:
- 1 tham số = 1, các tham số còn lại = 0
- Mỗi lần được 1 nghiệm → gọi là **bộ nghiệm cơ bản**

Ví dụ:
```
Hệ 3 pt, 4 ẩn, r(A) = 2 → vô số nghiệm, 2 tham số
Đặt x₃ = t₁, x₄ = t₂
- Cho t₁=1, t₂=0 → được nghiệm x¹
- Cho t₁=0, t₂=1 → được nghiệm x²
→ {x¹, x²} là bộ nghiệm cơ bản
```

---

### Tóm tắt nhanh

| Khái niệm | Ý chính |
|---|---|
| **Hạng ma trận** | Số hàng khác 0 sau khi đưa về bậc thang |
| **Ma trận khả nghịch** | A⁻¹ tồn tại ⇔ det(A) ≠ 0 |
| **Gauss** | Biến đổi dòng → bậc thang → thay thế lùi |
| **Cramer** | xᵢ = det(Aᵢ)/det(A), chỉ dùng cho hệ vuông det≠0 |
| **Thuần nhất** | AX = 0, luôn có nghiệm 0, nếu r(A) < n thì vô số nghiệm |
