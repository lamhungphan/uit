# Buổi 4 – Đại số tuyến tính

## 1. Phần bù đại số (định thức cấp n ≥ 3)

### Khái niệm
A vuông cấp n (n ≥ 3), ký hiệu:
```
A(i|j) = ma trận A sau khi xóa dòng i và cột j
cᵢⱼ = (−1)^(i+j) · det[A(i|j)] ,  ∀ 1 ≤ i, j ≤ n
```
cᵢⱼ được gọi là **phần bù đại số**.

### Ví dụ mẫu
Cho A = [[5, −1, 4],[7, 2, −6],[−9, 10, 3]]. Tìm A(2|3), A(3|1), A(1|2) và c₂₃, c₃₁, c₁₂.

### Các ví dụ
- **Ví dụ 1:** A = [[4, 3, 10],[6, −1, 7],[−9, 5, 3]] → tìm c₂₁, c₃₁, c₁₁
- **Ví dụ 2:** B = [[8, −3, −7],[6, 10, 5],[9, 2, −1]] → tìm c₂₃, c₃₃, c₁₃
- **Ví dụ 3:** C = [[4, −2, 9],[10, −8, 3],[1, 6, −5]] → tìm c₂₁, c₂₂, c₃₂
- **Ví dụ 4:** D = [[3, −1, 8, 6],[9, 0, 2, 5],[3, 7, −1, −8],[10, 6, 4, −2]] → tìm c₁₄, c₂₃
- **Ví dụ 5:** E = [[2, 5, 10, 0],[6, −7, −1, 3],[4, 9, 8, 2],[5, −1, 3, 7]] → tìm c₃₄, c₃₂

---

## 2. Tính det(A) = |A| bằng khai triển dòng/cột

Xét A = (aᵢⱼ) cấp n, ta có thể tính định thức dựa theo **bất kỳ dòng hoặc cột nào**:

```
Khai triển dòng 1: det(A) = a₁₁c₁₁ + a₁₂c₁₂ + ... + a₁ₙc₁ₙ
Khai triển dòng 2: det(A) = a₂₁c₂₁ + a₂₂c₂₂ + ... + a₂ₙc₂ₙ
...
Khai triển cột 1: det(A) = a₁₁c₁₁ + a₂₁c₂₁ + ... + aₙ₁cₙ₁
Khai triển cột 3: det(A) = a₁₃c₁₃ + a₂₃c₂₃ + ... + aₙ₃cₙ₃
```

### Lưu ý
- **Chọn dòng/cột có nhiều hệ số = 0 nhất** để tính cho gọn
- Nếu A có **2 dòng tỉ lệ** (hoặc 2 cột tỉ lệ) → det(A) = 0

---

## 3. Mối quan hệ giữa phép biến đổi sơ cấp (dòng & cột) và định thức

Cho A vuông cấp n trên F. Có 3 loại phép biến đổi sơ cấp trên dòng, tương tự cũng có trên cột:

| Loại | Phép biến đổi | Ảnh hưởng đến định thức |
|---|---|---|
| **Loại 1** | Nhân 1 dòng (hoặc 1 cột) với số c ≠ 0 | det(A') = **c·det(A)** (gấp c lần) |
| **Loại 2** | Đổi chỗ 2 dòng (hoặc 2 cột) | det(A') = **−det(A)** (đổi dấu) |
| **Loại 3** | Cộng bội của 1 dòng vào dòng khác (tương tự cột) | det(A') = **det(A)** (không đổi) |

### Ứng dụng
Dùng tùy ý các phép biến đổi (khuyến khích **loại 3**) để đưa 1 dòng/cột nào đó về **nhiều hệ số 0 nhất**, rồi khai triển định thức theo dòng/cột đó.

### Ví dụ mẫu – giải phương trình định thức
Giải:
```
|x  x  x  x |
|3  3  3  x |  = 0
|3  3  x  3 |
|3  x  3  3 |
```
- Tính định thức theo dòng 4, rồi theo dòng 3 → đưa về phương trình đơn giản
- **Đáp số:** x = 3 hoặc x = −3

**Ví dụ 1:** Tính định thức ma trận (áp dụng biến đổi sơ cấp)

**Ví dụ 2:** Giải phương trình trên ℝ:
```
|1  1  1  1 |
|1  1  1  x |  = 0   (x là ẩn cần tìm)
|1  1  x  1 |
|1  x  1  1 |
```

### Ma trận đặc biệt
Khi A là **ma trận đường chéo**, **ma trận tam giác trên**, hoặc **ma trận tam giác dưới**:
```
det(A) = tích các phần tử trên đường chéo chính
```
Ví dụ: A = [[3, 2, 1, 0],[0, 1, 7, 5],[0, 0, 6, −1],[0, 0, 0, −2]] → det(A) = 3·1·6·(−2) = −36

---

## 4. Mối liên hệ giữa ma trận khả nghịch và định thức

### Các bước tìm A⁻¹ bằng phương pháp định thức

- **Bước 1:** Tìm det(A) = |A|
- **Bước 2:** Nếu det(A) = 0 → A **không khả nghịch**, không tồn tại A⁻¹  
  Nếu det(A) ≠ 0 → A khả nghịch, chuyển sang Bước 3
- **Bước 3:** Tìm n² hệ số cᵢⱼ = (−1)^(i+j)·det[A(i|j)], ∀ 1 ≤ i, j ≤ n
- **Bước 4:** Lập ma trận C = (cᵢⱼ)
- **Bước 5:** Viết Cᵀ = (cⱼᵢ) — ma trận chuyển vị của C, gọi là **ma trận phụ hợp (adjoint matrix)** của A:
```
Cᵀ = adj(A) = A*
```
Suy ra:
```
A⁻¹ = (1/det(A)) · Cᵀ
```

### Ví dụ mẫu 1
Cho A = [[3, 2, 10],[8, −1, 7],[6, 4, −2]].
- det(A) = 574 ≠ 0 → khả nghịch
- Lập ma trận C = [[−26, 58, 38],[44, −54, 24],[24, 101, −13]]
- Cᵀ = adj(A) = [[−26, 44, 24],[58, −54, 101],[38, 24, −13]]
- A⁻¹ = (1/574) · Cᵀ

### Ví dụ mẫu 2 – biện luận
Cho A = [[1, a, a²],[1, b, b²],[1, c, c²]] với a, b, c là tham số thực.
- Khai triển det(A) theo cột 1 → det(A) = (a−b)(b−c)(c−a) (dạng Vandermonde)
- A khả nghịch khi a, b, c **đôi một khác nhau**
- A không khả nghịch khi a = b hoặc b = c hoặc c = a

---

## 5. Giải hệ pt tuyến tính bằng phương pháp định thức (pp CRAMER)

### Đặt vấn đề
Hệ n pt, n ẩn trên F, viết dạng ma trận AX = B:
```
a₁₁x₁ + a₁₂x₂ + ... + a₁ₙxₙ = b₁
a₂₁x₁ + a₂₂x₂ + ... + a₂ₙxₙ = b₂
.............................................
aₙ₁x₁ + aₙ₂x₂ + ... + aₙₙxₙ = bₙ
```

Đặt:
- Δ = det(A) = |A|
- Δⱼ = det(Aⱼ), với Aⱼ là ma trận A **sau khi xóa cột j và thay bằng cột B** (1 ≤ j ≤ n)

### Phân loại nghiệm

| Trường hợp | Kết luận |
|---|---|
| **TH1:** Δ ≠ 0 | Hệ có **nghiệm duy nhất**: xⱼ = Δⱼ / Δ |
| **TH2:** Δ = 0 và có (ít nhất) một Δⱼ ≠ 0 | Hệ **VÔ NGHIỆM** |
| **TH3:** Δ = Δ₁ = ... = Δₙ = 0 | Không kết luận được → phải giải bằng pp GAUSS‑JORDAN hoặc pp GAUSS |

### Ví dụ mẫu 2 – hệ Cramer
```
2x₁ + 2x₂ + 5x₃ = 21
2x₁ + 3x₂ + 6x₃ = 26
 x₁ − 6x₂ − 9x₃ = −37
```
- Δ = |A| = −9 ≠ 0 → nghiệm duy nhất
- x₁ = Δ₁/Δ, x₂ = Δ₂/Δ, x₃ = Δ₃/Δ
- Kết luận: hệ có nghiệm duy nhất

### Ví dụ – giải và biện luận theo tham số m
Cho hệ pt tuyến tính trên ℝ với m là tham số thực:
```
[ 1   2   2 ] [x₁]   [ 0 ]
[ 2   5   m ] [x₂] = [ 2 ]
[−1  −1  m ] [x₃]   [−2 ]
```
Đặt A, B, X như trên, gọi Δ = det(A), Δ₁, Δ₂, Δ₃.

- **TH1:** Δ ≠ 0 → hệ có nghiệm duy nhất
- **TH2:** Δ = 0 (xét m = 0 và m = ...):
  - TH2.1: thay m vào các Δⱼ tìm giá trị
  - TH2.2: thay m vào các Δⱼ tìm giá trị
  - Kết luận (vô nghiệm hoặc vô số nghiệm)

---

## 6. Bài tập

### Phần A – Tính det(A) & giải phương trình định thức
- **Ví dụ mẫu:** giải pt |x x x x; 3 3 3 x; 3 3 x 3; 3 x 3 3| = 0 (đáp số x = ±3)
- **Ví dụ 1:** Tính định thức ma trận (dùng biến đổi sơ cấp)
- **Ví dụ 2:** Giải pt |1 1 1 1; 1 1 1 x; 1 1 x 1; 1 x 1 1| = 0

### Phần B – Tìm A⁻¹ bằng phương pháp định thức

**Bài 1:**
```
     [ 4  -3   2 ]
A =  [10  -6   5 ]
     [ 7  -1   4 ]
```

**Bài 2:**
```
     [ 2  -7  -9 ]
A =  [ 8  -1   3 ]
     [ 4  -9  -6 ]
```

**Bài 3–5:** Biện luận khi nào A khả nghịch, và tìm A⁻¹ bằng phương pháp định thức (ma trận chứa tham số).

### Phần C – Giải hệ bằng pp Cramer

- **Ví dụ mẫu 2:** hệ
```
2x₁ + 2x₂ + 5x₃ = 21
2x₁ + 3x₂ + 6x₃ = 26
 x₁ − 6x₂ − 9x₃ = −37
```
- **Ví dụ biện luận:** hệ theo tham số m (đề ở mục 5)

---

## Tóm tắt nhanh

| Khái niệm | Ý chính |
|---|---|
| **Phần bù đại số** | cᵢⱼ = (−1)^(i+j)·det[A(i\|j)] |
| **Khai triển det** | Theo dòng/cột: det = Σ aᵢⱼcᵢⱼ (chọn dòng/cột nhiều số 0) |
| **BĐSC loại 1/2/3** | det ×c / đổi dấu / không đổi |
| **Ma trận tam giác** | det = tích đường chéo chính |
| **A⁻¹ bằng định thức** | A⁻¹ = (1/det(A))·adj(A) = (1/det(A))·Cᵀ |
| **Cramer** | Δ ≠ 0 → nghiệm duy nhất; Δ = 0 & có Δⱼ ≠ 0 → vô nghiệm; Δ = Δⱼ = 0 → phải dùng Gauss |
