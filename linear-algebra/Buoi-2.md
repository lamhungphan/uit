# Buổi 2 – Đại số tuyến tính

## 1. Các cột bán chuẩn (semi‑standard columns)

### Định nghĩa
Các cột bán chuẩn cấp m là các cột có m thành phần, ký hiệu:

```
E'₁, E'₂, ..., E'ₘ
```

Dạng tổng quát:

```
E'₁ = [a  , 0, 0, ..., 0]ᵀ       (a ≠ 0)
E'₂ = [b₁, u, 0, ..., 0]ᵀ
E'₃ = [c₁, c₂, v, ..., 0]ᵀ
...
E'ₘ = [u₁, u₂, u₃, ..., uₘ₋₁, w]ᵀ   (w ≠ 0)
```

Trong đó **a, u, v, ..., w** là các số tùy ý khác 0;  
còn **b₁, c₁, c₂, ..., u₁,..., uₘ₋₁** là các số tùy ý.

Khác với **cột chuẩn** (chỉ có 1 số khác 0 ở đúng vị trí dòng tương ứng), cột bán chuẩn cho phép các số tùy ý ở **phía trên** phần tử cơ sở.

### Ví dụ – Các cột bán chuẩn cấp 5
```
E'₁ = [−3, 0, 0, 0, 0]ᵀ
E'₂ = [−1, 7, 0, 0, 0]ᵀ
E'₃ = [8, 0, −5, 0, 0]ᵀ
E'₄ = [6, 3, 0, 9, 0]ᵀ
E'₅ = [3, 1, 8, 5, −11]ᵀ
```

---

## 2. Tìm hạng bằng bán chuẩn hóa cột

### Phương pháp
Cho ma trận A = (aᵢⱼ)ₘₓₙ trên trường F:

1. Từ A, **bán chuẩn hóa (chuẩn hóa) tối đa các cột** → thu được ma trận H
2. H được gọi là **ma trận dạng bậc thang (echelon form)** của A
3. rank(A) = r(A) = **số dòng khác 0** của H

**Khác biệt với giáo trình chung:**
- Giáo trình chung dùng biến đổi sơ cấp trên **dòng** để đưa về dạng bậc thang
- Bài học dùng **bán chuẩn hóa cột** (thao tác trên cột)

### Ví dụ mẫu
Cho:
```
A = [ 2 -1  0  3 ]
    [ 4 -5  1 -2 ]
    [ 8 10 -2 -4 ]
```
Sau bán chuẩn hóa cột → H có **2 dòng khác 0** → r(A) = 2

### Bài tập tương tự (5 bài)
- Bài 1–2: Tính hạng ma trận số cụ thể (4×5, 5×4)
- Bài 3–5: Biện luận hạng theo tham số thực m

---

## 3. Giải hệ bằng phương pháp bán chuẩn (pp GAUSS)

### So với pp GAUSS‑JORDAN
- **GAUSS‑JORDAN**: chuẩn hóa các cột → có nghiệm trực tiếp
- **GAUSS (bán chuẩn)**: bán chuẩn hóa các cột → tìm ẩn chỉ số lớn trước, thay thế lùi dần

### Các bước
1. Đưa hệ về dạng ma trận bổ sung (A|B)
2. Bán chuẩn hóa các cột
3. Giải từ ẩn cuối (chỉ số lớn) → thay ngược lên trên

### Ví dụ
Hệ (A|B) sau khi bán chuẩn hóa:
```
[ 1 -2  0 -3 -4  -5 ]
[ 0  2 -3 -2 -6 -12 ]
[ 0  0  0  3  9  18 ]
[ 0  0  0  0  2   4 ]
```

- x₅ = −2
- x₄ = −12
- x₃ = a (ẩn tự do, cột 3 không bán chuẩn hóa được)
- x₂ = −16 − 3a

### Phân biệt
- Nếu ma trận kết quả có **3 cột bán chuẩn liên tiếp** → nghiệm duy nhất
- Nếu có cột **không bán chuẩn hóa được** → đặt ẩn tự do → vô số nghiệm

---

## 4. Các phép tính trên ma trận

> **Không có trong giáo trình chương 2** (giáo trình giả định đã học từ chương 1 hoặc các bài trước)

### a. Cộng / trừ hai ma trận
A ± B = (aᵢⱼ ± bᵢⱼ), với A, B cùng kích thước m×n

### b. Nhân vô hướng
c·A = (c·aᵢⱼ), với c ∈ F

### c. Nhân dòng với cột
U·V = u₁v₁ + u₂v₂ + ... + uₙvₙ

Với U = (u₁ u₂ ... uₙ) là dòng, V = (v₁ v₂ ... vₙ)ᵀ là cột

### d. Nhân hai ma trận
C = Aₘₓₙ · Bₙₓₚ → Cₘₓₚ  
Phần tử cᵢₖ = dòng i của A × cột k của B

**Tính chất:**
1. Kết hợp: (AB)C = A(BC) = ABC
2. A·O = O·A = O
3. I·A = A, A·I = A
4. Phân phối: (A±B)C = AB±AC, B(C±D) = BC±BD
5. c(AB) = (cA)B = A(cB)

**Lưu ý:** Nhân ma trận **không giao hoán**: AB ≠ BA (tổng quát)

---

## 5. Lũy thừa của ma trận vuông

Với A là ma trận vuông cấp n trên F:

- A⁰ = Iₙ
- A¹ = A
- Aᵏ = A·A·...·A (k lần), ∀k ≥ 0 nguyên

### Ví dụ chứng minh quy nạp
Cho A = [[1,0],[1,1]], chứng minh Aᵏ = [[1,0],[k,1]] ∀k ≥ 0

### Bài tập (7 bài)
- Bài 1–7: Tìm Aᵏ cho các ma trận vuông đặc biệt cấp 2, 3

### Lưu ý quan trọng
Nếu AB = O **không** được suy ra A = O hay B = O  
Ví dụ:
```
A = [[1,2],[0,0]], B = [[-4,0],[2,0]] → AB = O nhưng A,B ≠ O
```
