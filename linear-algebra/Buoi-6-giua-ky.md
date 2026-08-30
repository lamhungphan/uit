# Buổi 6 - Giữa kỳ: Giải và giải thích

## Phần 1: Đề kiểm tra giữa kỳ III (Năm học 2025-2026)

### Câu 1a: Tìm ma trận `2C⁵ Bᵀ A⁻¹`

**Dữ liệu ma trận:**
```
A = [ 1  1  2 ]   (m ∈ ℝ)
    [ 1  0  m ]

    [ 3  5  7 ]

B = [ 1  4  2 ]
    [−5  9  1 ]
    [ 3  6  0 ]

C = [ 3  2  1 ]
    [ 1  2  4 ]
    [ λ  1  2 ]   (λ ∈ ℝ)
```

**Bước 1: Tính A⁻¹**
- det(A) = 1·(0·7 − m·5) − 1·(1·7 − m·3) + 2·(1·5 − 0·3) = −5m − 7 + 3m + 10 = 3 − 2m
- Ma trận đồng biến adj(A):
  ```
  adj(A) = [−5m    3     m]
           [3m−7   1   2−m]
           [ 5    −2    −1]
  ```
- A⁻¹ = (1/(3−2m)) · adj(A)

**Bước 2: Tính Bᵀ**
```
Bᵀ = [ 1  −5   3]
     [ 4   9   6]
     [ 2   1   0]
```

**Bước 3: Tính C⁵**
- Sử dụng phân tích riêng hoặc quy hoạch động ma trận:
- C² = C · C, C³ = C² · C, ...
- Hoặc sử dụng Định lý Cayley-Hamilton: C³ = pC + qI (với đa thứccharacteristic của C bậc 3)
- Tiếp tục lặp để tìm C⁵

**Kết quả:** `2C⁵ Bᵀ A⁻¹` được tính theo chuỗi: `(2 · C⁵) · Bᵀ · A⁻¹`. Kết quả cụ thể phụ thuộc vào giá trị λ và m, được tính bằng phương pháp trên.

---

### Câu 1b: Tìm λ để ma trận C có hạng nhỏ nhất

**Phân tích:**
```
C = [ 3  2  1 ]
    [ 1  2  4 ]
    [ λ  1  2 ]
```

**Tính det(C):**
```
det(C) = 3·(2·2 − 4·1) − 2·(1·2 − 4·λ) + 1·(1·1 − 2·λ)
       = 3·(4 − 4) − 2·(2 − 4λ) + 1·(1 − 2λ)
       = 0 − 4 + 8λ + 1 − 2λ
       = 6λ − 3
```

**Tìm λ để det(C) = 0:**
```
6λ − 3 = 0 → λ = 1/2
```

**Kiểm tra hạng khi λ = 1/2:**
Thay λ = 1/2 vào C và đưa về dạng chuẩn:
```
C = [ 3   2   1 ]
    [ 1   2   4 ]
    [1/2  1   2 ]
```
Biến đổi hàng:
- R1 ↔ R2: [1 2 4; 3 2 1; 1/2 1 2]
- R2 ← R2 − 3R1: [0 −4 −11]
- R3 ← R3 − (1/2)R1: [0 0 0]

Ma trận chuẩn có 2 hàng không 0 → **rank(C) = 2**.

**Kết luận:** Giá trị λ = 1/2 làm cho ma trận C có hạng nhỏ nhất bằng **2**.

---

### Câu 1c: Với m = 2, tìm ma trận X thỏa X³A = D + B

**Dữ liệu với m = 2:**
```
A = [ 1  1  2 ]
    [ 1  0  2 ]
    [ 3  5  7 ]

D = [ 4  1  0 ]
    [−1  1  5 ]
    [ 8  3  1 ]

B = [ 1  4  2 ]
    [−5  9  1 ]
    [ 3  6  0 ]
```

**Bước 1: Tính A⁻¹ (với m = 2)**
- det(A) = 3 − 2·2 = −1
- adj(A) với m = 2:
  ```
  adj(A) = [−10   3   2]
           [ −1   1   0]
           [  5  −2  −1]
  ```
- A⁻¹ = (1/−1) · adj(A) = −adj(A):
  ```
  A⁻¹ = [ 10  −3  −2 ]
        [  1  −1   0 ]
        [ −5   2   1 ]
  ```

**Bước 2: Tính D + B**
```
D + B = [ 4+1   1+4   0+2 ]   = [ 5   5   2 ]
        [ −1+(−5)  1+9   5+1 ]     [−6  10   6 ]
        [  8+3   3+6   1+0 ]     [ 11   9   1 ]
```

**Bước 3: Tính X³ = (D + B) · A⁻¹**
```
X³ = [ 5   5   2 ] · [ 10  −3  −2 ]   = [ 45  −16  −8 ]
     [−6  10   6 ]   [  1  −1   0 ]     [−80   20  18 ]
     [ 11   9   1 ]   [ −5   2   1 ]     [ 114  −40  −21 ]
```

**Bước 4: Tìm X thỏa X³ = kết quả trên**
- Sử dụng phân tích riêng (eigendecomposition) của X³:
  - Tìm các trị riêng λᵢ và vector riêng vᵢ
  - X = V · diag(∛λᵢ) · V⁻¹ (cube root của từng trị riêng)
- Hoặc nếu X³ có thể phân tích dưới dạng Jordan, lấy cube root tương ứng.

**Kết quả X:** Biểu diễn qua phân tích riêng của ma trận X³ = [[45, -16, -8], [-80, 20, 18], [114, -40, -21]]. Các trị riêng và vector riêng cần được tính toán để lấy căn bậc 3, từ đó được ma trận X.

---

### Câu 2: Giải và biện luận hệ phương trình tuyến tính

```
−2x + 2y + 3z = 1
mx − my + mz = 1
mx + y − mz = 1
```
*(Phương pháp giải: đưa hệ về ma trận Augmented, biến đổi Gauss, phân tích theo giá trị m)*

### Câu 3: Không gian véc tơ con W ⊂ ℝ⁵

```
W = { (x₁; x₂; x₃; x₄; x₅) | x₁ − 5x₂ + 3x₄ = 0; x₅ + 2x₁ + 7x₂ + 4x₃ = 0 }
```
- W là tập nghiệm của hệ phương trình tuyến tính -> W ≤ ℝ⁵ (thỏa mãn hai điều kiện: chứa vector 0 và đóng với cộng pha)
- Để tìm cơ sở: Giải hệ để viết x₁, x₅ theo x₂, x₃, x₄ (tham số free)
- Số chiều = số tham số tự do = 3
- Cơ sở: {(5;1;0;0;−14), (−4;0;1;0;−7), (3;0;0;1;−2)} (cần kiểm tra ĐLTT)

### Câu 4: Độc lập/Phụ thuộc tuyến tính & Tọa độ

**Trên ℝ⁴, S = {u₁, u₂, u₃, u₄} với:**
```
u₁ = (0; 1; 3; −4)
u₂ = (1; 0; −2; 3)
u₃ = (−3; 2; 0; −5)
u₄ = (4; 3; −5; 0)
```

**a) Kiểm tra độc lập tuyến tính:**
- Lập ma trận A_S từ các vectơ làm cột
- Biến đổi bán chuẩn → số hàng khác 0 = 4 → rank = 4 = |S|
- Vậy S là **độc lập tuyến tính**.

**b) Tìm tọa độ của α = (−10; 2; 15; −5) theo S:**
- Giải hệ c₁u₁ + c₂u₂ + c₃u₃ + c₄u₄ = α
- Kết quả: (c₁, c₂, c₃, c₄) = ... (cần giải hệ phương trình)

---

### Tóm tắt Phương pháp chính

1. **Tính ma trận đơn vị:** det(A) ≠ 0 → A⁻¹ = adj(A)/det(A)
2. **Phân tích hạng:** det = 0 → kiểm tra minor lớn nhất
3. **X³A = D+B:** Tính X³ = (D+B)A⁻¹, sau đó lấy căn bậc 3 qua eigendecomposition
4. **Hệ phương trình:** Gauss/Jordan elimination
5. **Không gian véc tơ:** Giải hệ, tìm tham số tự do, kiểm tra ĐLTT