# Buổi 3 – Đại số tuyến tính

## 1. Ma trận vuông khả nghịch

### a. Định nghĩa
A vuông cấp n trên F được gọi **khả nghịch** nếu tồn tại ma trận vuông A' (cấp n) sao cho:
```
A·A' = A'·A = Iₙ
```

### b. Tính duy nhất
Ma trận A' nếu tồn tại thì **duy nhất**, ký hiệu:
```
A' = A⁻¹  (ma trận nghịch đảo của A)
```

### c. Lũy thừa nguyên âm
Khi A khả nghịch, ngoài lũy thừa nguyên không âm còn có lũy thừa nguyên âm:
```
A⁻¹  = A'            (nghịch đảo của A)
A⁻²  = A⁻¹·A⁻¹
A⁻³  = A⁻¹·A⁻¹·A⁻¹
A⁻ᵏ  = A⁻¹·A⁻¹·...·A⁻¹ (k lần), ∀k > 0, k ∈ ℤ
```

### d. Cách nhận diện và tìm nghịch đảo
Viết dạng ma trận hóa **(A | Iₙ)**, dùng phép biến đổi sơ cấp trên dòng để xây dựng trong A các **cột chuẩn** theo thứ tự trái → phải (giống pp GAUSS‑JORDAN):
```
(A | Iₙ) → (A₁ | B₁) → (A₂ | B₂) → ... → (Aₖ | Bₖ)
```

- **TH1:** Aₖ ≠ Iₙ → A **không khả nghịch**, không tồn tại A⁻¹
- **TH2:** Aₖ = Iₙ → A khả nghịch và **A⁻¹ = Bₖ**

### Ví dụ mẫu
Cho A = [[−3, 4, 6],[0, −1, −1],[2, −3, −4]]:
- Kết quả A₃ = I₃ → A khả nghịch
- A⁻¹ = [[1, −2, 2],[−2, 0, −3],[2, −1, 3]]
- Từ đó tính được A⁻², A⁻⁴

### Lưu ý – các loại ma trận đặc biệt
- **Ma trận lũy linh (nilpotent):** Aᵐ = O với m là số nguyên dương nào đó
- **Ma trận lũy đẳng (idempotent):** A² = A
- **Ma trận trực giao (orthogonal):** A⁻¹ = Aᵀ (với Aᵀ là ma trận chuyển vị: dòng ↔ cột)

### Cách bấm máy tính CASIO (fx‑570ES PLUS)
1. `MODE → 6: MATRIX → 1: MatA → 1: 3x3`
2. Nhập từng phần tử của A (bấm `=` sau mỗi số)
3. Bấm `AC`, rồi `SHIFT + 4 → 3: MatA`
4. Bấm `x⁻¹` rồi `=` → kết quả A⁻¹
5. Để tìm A⁻²: lấy kết quả A⁻¹ nhân với A⁻¹, hoặc bấm A, x⁻¹, x²

---

## 2. Ứng dụng: giải phương trình ma trận

### a. Phương trình AX = B (*)
- A vuông cấp m, B cấp m×n, X là ẩn cấp m×n
- A không khả nghịch → **vô nghiệm**
- A khả nghịch → nghiệm duy nhất: **X = A⁻¹B**

### b. Phương trình XA = B (**)
- A vuông cấp n, B cấp m×n, X ẩn cấp m×n
- A không khả nghịch → **vô nghiệm**
- A khả nghịch → nghiệm duy nhất: **X = BA⁻¹**

### c. Phương trình AXC = B (***)
- A vuông cấp m, C vuông cấp n, B cấp m×n, X ẩn cấp m×n
- A hoặc C không khả nghịch → **vô nghiệm**
- A và C đều khả nghịch → nghiệm duy nhất: **X = A⁻¹BC⁻¹**

### d. Trường hợp đặc biệt – ma trận vuông cấp 2
Với A = [[a, b],[c, d]]:
```
k = ad − bc
```
- **k = 0** → A không khả nghịch
- **k ≠ 0** → A khả nghịch và:
```
A⁻¹ = (1/k) · [ d  −b ]
               [ −c   a ]
```

Ví dụ:
```
A = [−7  4]  → k = (−7)(3) − (−4)(5) = −1 ≠ 0 → khả nghịch
    [−5  3]      A⁻¹ = (−1/1)·[ 3  −4 ] = [ −3   4 ]
                              [  5  −7 ]   [ −5   7 ]

B = [ 2 −5]  → k = (−2)(10) − 5(−3) = −5 ≠ 0 → khả nghịch
    [ 3 10]      B⁻¹ = (−1/5)·[ 10  5 ] = [ −2  −1 ]
                              [ −3 −2 ]   [ 3/5  2/5 ]

C = [−2 −4]  → k = (−2)(2) − 4(−1) = 0 → không khả nghịch
    [−1  2]
```

### Các ví dụ mẫu (Ví dụ 1–10)
- Ví dụ 1–3: giải pt AX=B, XA=B, AXC=B
- Ví dụ 4–6: giải pt ma trận với ma trận 2×2
- Ví dụ 7: giải X² = I₂ (gợi ý: đặt X = [[a,b],[c,d]], đồng nhất thức 2 vế → hệ pt)
- Ví dụ 8–10: giải pt ma trận, xác định kích thước của X rồi đặt ẩn

---

## 3. Định thức ma trận vuông

### Định nghĩa
A vuông cấp n trên F luôn có một con số đặc trưng duy nhất gọi là **định thức** của A, ký hiệu det(A) hay |A|.

### Cách tính

**TH1 – cấp 1:** A = (a) → det(A) = |A| = a

**TH2 – cấp 2:** A = [[a, b],[c, d]] → det(A) = ad − bc

**TH3 – cấp 3 – quy tắc SARRUS (6 đường chéo):**
```
    [ a  b  c ] a  b
A = [ p  q  r ] p  q
    [ u  v  w ] u  v

det(A) = aqv + b ru + cpw − (bv p + c q u + a r w)
```
(tổng tích 3 đường chéo chính trừ tổng tích 3 đường chéo phụ)

**TH4 – cấp n ≥ 3 – khai triển theo dòng/cột:**

Ký hiệu A(i|j) = ma trận A sau khi xóa dòng i và cột j.
Phần bù đại số:
```
cᵢⱼ = (−1)^(i+j) · det[A(i|j)] , ∀ 1 ≤ i, j ≤ n
```

Khai triển theo **dòng i**:
```
det(A) = aᵢ₁cᵢ₁ + aᵢ₂cᵢ₂ + ... + aᵢₙcᵢₙ
```
Khai triển theo **cột j**:
```
det(A) = a₁ⱼc₁ⱼ + a₂ⱼc₂ⱼ + ... + aₙⱼcₙⱼ
```

### Lưu ý
- Nên chọn dòng/cột có **nhiều hệ số 0 nhất** để khai triển cho gọn
- Nếu A có **2 dòng tỉ lệ** (hoặc 2 cột tỉ lệ) → det(A) = 0

### Ví dụ mẫu (quy tắc Sarrus)
Cho A = [[3, −5, −2],[10, 6, −1],[−4, 5, 8]] → det(A) = −401

---

## 4. Bài tập

### Phần A – Kiểm tra khả nghịch & tìm A⁻¹, A⁻², A⁻⁴, A⁻⁸

**Bài 1:**
```
     [ 3   4  9 ]
A =  [ 2  -1 -2 ]
     [ 7  -1  4 ]
```
Tìm A⁻¹, A⁻², A⁻⁴, A⁻⁸ nếu khả nghịch.

**Bài 2:**
```
     [ 2  -7   1 ]
A =  [22 -75  12 ]
     [ 9 -31   5 ]
```

**Bài 3:**
```
     [ 13  -8  12 ]
A =  [ 12  -7  12 ]
     [  6  -4   5 ]
```

**Bài 4:**
```
     [ 1  -4  -3 ]
A =  [ 1  -3  -2 ]
     [ 1  -1  -1 ]
```

**Bài 5:**
```
     [ 1  0   2 ]
A =  [ 2  1   6 ]
     [ 3 -2  -11 ]
```

**Bài 6:**
```
     [ 2  7   8 ]
A =  [ 1 -4   5 ]
     [ 3 -9  -8 ]
```

**Bài 7:**
```
     [ 13  16   3 ]
A =  [ -7  -8   2 ]
     [  3  -3  -1 ]
```

### Phần B – Giải phương trình ma trận

**Ví dụ 4–6:** giải pt ma trận 2×2 (dạng AX=B hoặc tương đương, dùng công thức cấp 2)

**Ví dụ 7:** Giải X² = I₂ trên ℝ, với X là ma trận ẩn.
*Gợi ý:* đặt X = [[a,b],[c,d]], tính X² rồi đồng nhất thức 2 vế → hệ pt

**Ví dụ 8–10:** giải pt ma trận, xác định kích thước X rồi đặt ẩn và đồng nhất

### Phần C – Tính định thức

**Bài 1:**
```
     [ 3  -5   1 ]
A =  [10  -6   7 ]
     [ 4  -9   8 ]
```

**Bài 2:**
```
     [ 3  -1   5 ]
A =  [ 4  -7  -2 ]
     [ 5  -4   3 ]
```

**Bài 3:**
```
     [  1  a  bc ]
A =  [  1  b  ac ]
     [  1  c  ab ]
```

**Bài 4:**
```
     [  1   1   1 ]
A =  [  a   b   c ]
     [ a²  b²  c² ]
```

**Bài 5:**
```
     [ a  a²  1 ]
A =  [ b  b²  1 ]
     [ c  c²  1 ]
```

### Phần D – Phần bù đại số (Tính cᵢⱼ)

**Ví dụ mẫu:** A = [[5, −1, 4],[7, 2, −6],[−9, 10, 3]] → tìm A(2|3), A(3|1), A(1|2) và c₂₃, c₃₁, c₁₂

**Ví dụ 1:** A = [[4, 3, 10],[6, −1, 7],[−9, 5, 3]] → tìm c₂₁, c₃₁, c₁₁

**Ví dụ 2:** B = [[8, −3, −7],[6, 10, 5],[9, 2, −1]] → tìm c₂₃, c₃₃, c₁₃

**Ví dụ 3:** C = [[4, −2, 9],[10, −8, 3],[1, 6, −5]] → tìm c₂₁, c₂₂, c₃₂

**Ví dụ 4:** D = [[3, −1, 8, 6],[9, 0, 2, 5],[3, 7, −1, −8],[10, 6, 4, −2]] → tìm c₁₄, c₂₃

**Ví dụ 5:** E = [[2, 5, 10, 0],[6, −7, −1, 3],[4, 9, 8, 2],[5, −1, 3, 7]] → tìm c₃₄, c₃₂

---

## Tóm tắt nhanh

| Khái niệm | Ý chính |
|---|---|
| **Khả nghịch** | (A\|I) → (I\|A⁻¹); 2×2: k = ad−bc ≠ 0 |
| **Lũy thừa âm** | A⁻ᵏ = (A⁻¹)ᵏ |
| **AX = B** | X = A⁻¹B |
| **XA = B** | X = BA⁻¹ |
| **AXC = B** | X = A⁻¹BC⁻¹ |
| **Lũy linh / lũy đẳng / trực giao** | Aᵐ=O / A²=A / A⁻¹=Aᵀ |
| **Định thức cấp 2** | ad − bc |
| **Định thức cấp 3** | Quy tắc Sarrus (6 đường chéo) |
| **Định thức cấp n** | Khai triển dòng/cột theo cᵢⱼ = (−1)^(i+j)·det[A(i\|j)] |
