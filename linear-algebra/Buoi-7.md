# Buổi 7 – Đại số tuyến tính

> Nguồn: `DSTT Buoi 7.pdf` (lớp MA003.F32.LT.CNTT, ngày 06-09-2026)

---

## Phần 1: Ma trận chuyển cơ sở (Chương 3 tiếp)

### 8. Ma trận chuyển cơ sở

Cho (V, +, ·) là không gian tuyến tính tổng quát trên F = ℝ.  
Cho 2 cơ sở của V:
```
a = {α₁, α₂, ..., αₙ}
b = {β₁, β₂, ..., βₙ}
```

Lấy tọa độ của các véc tơ trong b biểu diễn theo cơ sở a:
```
[β₁]_a, [β₂]_a, ..., [βₙ]_a
```
(Mỗi [βᵢ]_a tìm bằng cách giải hệ n phương trình, n ẩn)

Lập ma trận:
```
P_{a→b} = [ [β₁]_a  [β₂]_a  ...  [βₙ]_a ]  (ma trận vuông cấp n)
```
Được gọi là **ma trận chuyển cơ sở từ a sang b**.

### Tính chất

Cho a, b, c là 3 cơ sở của V:
| Tính chất | Công thức |
|---|---|
| i/ | T_{a→a} = T_{b→b} = T_{c→c} = I |
| ii/ | (T_{a→b})⁻¹ = T_{b→a} |
| iii/ | T_{a→c} = T_{a→b} · T_{b→c} |

**Mẹo:** Thường chọn **c = 0 = {e₁, e₂, ..., eₙ}** (cơ sở chính tắc) để dễ tính. Khi đó:
```
T_{0→a} = [ [α₁]_0  [α₂]_0  ...  [αₙ]_0 ]  (với [α]_0 = α vì cơ sở chính tắc)
```

### Công thức đổi tọa độ
```
[α]_a = T_{a→b} · [α]_b
```

### Ví dụ mẫu 6 (bài 3.31)
**Cách 1 (theo định nghĩa):** Tìm [β₁]_a, [β₂]_a, [β₃]_a bằng cách giải 3 hệ pt → lập ma trận P.

**Cách 2 (qua cơ sở chính tắc):**
```
T_{a→b} = (T_{0→b})⁻¹ · T_{0→a} = T_{b→0} · T_{0→a}
```
Với T_{0→a} = [α₁ α₂ α₃] (các véc tơ làm cột), T_{0→b} = [β₁ β₂ β₃].
→ T_{a→b} = ([β₁ β₂ β₃])⁻¹ · [α₁ α₂ α₃]

### Ví dụ mẫu 7 (bài 3.29)
Cho T_{a→b} = ... tìm T_{b→a} = (T_{a→b})⁻¹.

**Bài tập tương tự:** bài 3.28; 3.30; 3.32; 3.33

---

## Phần 2: Chương 4 – TRỊ RIÊNG, VÉC TƠ RIÊNG, KHÔNG GIAN RIÊNG, ĐA THỨC ĐẶC TRƯNG

### 1. Các khái niệm

Cho A là ma trận vuông cấp n trên ℝ. Cho số thực c ∈ ℝ.

Đặt:
```
E_c = { X ∈ ℝⁿ | (A − cI)X = 0 }
```
= không gian nghiệm của hệ tuyến tính thuần nhất (A − cI)X = 0.

**Giải hệ (A − cI)X = 0:**
- Nếu chỉ có nghiệm tầm thường (0;...;0) → c **không phải** trị riêng.
- Nếu có vô số nghiệm (bên cạnh nghiệm tầm thường) → c **là trị riêng** (eigenvalue) của A.

Gọi:
- **E_c** = không gian riêng (eigenvector-space) ứng với trị riêng c.
- Mỗi α ∈ E_c là **véc tơ riêng** (eigenvector) ứng với trị riêng c.

### Ví dụ mẫu 1
Cho ma trận thực A. Kiểm tra 3, −2, 4 có phải trị riêng không.

a) c = 3: Giải (A − 3I)X = 0 → chỉ nghiệm tầm thường → **3 không phải trị riêng**.
b) c = −2: Giải (A + 2I)X = 0 → cột 2 không bán chuẩn hóa → vô số nghiệm → **−2 là trị riêng**.
c) c = 4: Tự làm tương tự.

**Bài tập tương tự (4 bài):**
1. A = [[−4, 2], [11, −5]]: kiểm tra −5, −7; tìm đa thức đặc trưng & mọi trị riêng.
2. A = [[8, 2], [4, −2]]: kiểm tra 0, 6; tìm đa thức đặc trưng & mọi trị riêng.
3. A = [[5, 6, 3], [1, 0, 1], [1, −2, 1]]: kiểm tra −3, 2; tìm đa thức đặc trưng & mọi trị riêng.
4. A = [[7, 6, 10], [−12, 17, 24], [−12, 15, 22]]: kiểm tra 0, −1; tìm đa thức đặc trưng & mọi trị riêng.

---

### 2. Đa thức đặc trưng của ma trận vuông

Cho A vuông cấp n trên ℝ.

**Định nghĩa:**
```
p_A(x) = det(xI − A)   hoặc   p_A(λ) = det(A − λI)
```
= **đa thức đặc trưng** (characteristic polynomial) của A.

**Khi c là trị riêng của A ⇔ p_A(c) = 0.**
→ Tìm tất cả trị riêng = giải phương trình p_A(x) = 0.

### Ví dụ mẫu 2
A = [[3, 1], [7, 5]]:
```
p_A(x) = det(xI − A) = det([[x−3, −1], [−7, x−5]])
       = (x−3)(x−5) − 7 = x² − 8x + 15 − 7 = x² − 8x + 8
```
Giải x² − 8x + 8 = 0 → x = 4 ± 2√2 (2 trị riêng thực phân biệt).

---

### 3. Chéo hóa ma trận vuông (Diagonalization)

Cho A vuông cấp n trên ℝ. Xét xem A có chéo hóa được trên ℝ không.

#### Các bước chéo hóa:

**Bước 1:** Tìm đa thức đặc trưng p_A(x) = det(xI − A).

**Bước 2:** Giải p_A(x) = 0 trên ℝ.
- Vô nghiệm trên ℝ → A **không chéo hóa được** → dừng.
- Có nghiệm: λ₁ (r₁ lần), λ₂ (r₂ lần), ..., λₖ (rₖ lần).
  Ta viết: p_A(x) = (x − λ₁)ʳ¹ · (x − λ₂)ʳ² · ... · (x − λₖ)ʳᵏ.

**Bước 3:** Tìm cơ sở cho các không gian riêng:
```
E_{λⱼ} = { X ∈ ℝⁿ | (A − λⱼI)X = 0 }
```
với 1 ≤ j ≤ k. Tìm dim E_{λⱼ}.

**Mẹo:** Nên xét không gian riêng có số mũ rⱼ > 1 trước.

**Bước 4:** Kiểm tra điều kiện chéo hóa:
- Nếu tồn tại j sao cho **dim E_{λⱼ} < rⱼ** → A **không chéo hóa được** → dừng.
- Nếu **dim E_{λⱼ} = rⱼ** ∀ j = 1..k → A **chéo hóa được**.

**Bước 5:** Lấy a = a₁ ∪ a₂ ∪ ... ∪ aₖ (hợp các cơ sở). Khi đó a là một cơ sở của ℝⁿ.

**Bước 6:** Gọi 0 = {e₁, e₂, ..., eₙ} là cơ sở chính tắc.  
Đặt **P = T_{0→a}** = ma trận chuyển cơ sở từ 0 sang a.  
(Tức P = [a₁ a₂ ... aₙ] – các véc tơ riêng làm cột). P luôn khả nghịch.

**Bước 7:** Dạng chéo hóa của A:
```
D = P⁻¹ A P = diag(λ₁, λ₁, ..., λ₂, λ₂, ..., λₖ, ..., λₖ)
```
(trị riêng λ₁ lặp r₁ lần, λ₂ lặp r₂ lần, ...)

### Ứng dụng: Tìm Aᵐ (m ≥ 0 nguyên)

```
A = P D P⁻¹
Aᵐ = P Dᵐ P⁻¹ = P · diag(λ₁ᵐ, ..., λₖᵐ) · P⁻¹
```

---

### Ví dụ mẫu: Chéo hóa A và tìm Aᵐ

**A = [[−3, 1, 0], [1, −2, −1], [0, −1, 3]]**

**Bước 1:** p_A(x) = det(xI − A) = ... (tính được)
**Bước 2:** Giải p_A(x) = 0 → 3 trị riêng: λ₁ = 3, λ₂ = 1, λ₃ = 4. Số mũ r₁ = r₂ = r₃ = 1.

**Bước 3:** Tìm cơ sở không gian riêng:

**Với λ₁ = 3:**
```
E_3 = { X | (A − 3I)X = 0 }
A − 3I = [[−6, 1, 0], [1, −5, −1], [0, −1, 0]]
```
Bán chuẩn hóa cột → cột 3 không bán chuẩn hóa được.
Đặt x₃ = a → x₁ = x₂ = a → X = a(1; 1; 1).
→ Cơ sở: a₁ = {u₁ = (−1; 0; 1)}. dim E_3 = 1 = r₁. ✓

**Với λ₂ = 1:**
```
E_1 = { X | (A − I)X = 0 }
A − I = [[−4, 1, 0], [1, −3, −1], [0, −1, 2]]
```
Cột 3 không bán chuẩn hóa → đặt x₃ = b → X = b(1; 2; 1).
→ Cơ sở: a₂ = {u₂ = (1; 2; 1)}. dim E_1 = 1 = r₂. ✓

**Với λ₃ = 4:**
```
E_4 = { X | (A − 4I)X = 0 }
A − 4I = [[−7, 1, 0], [1, −6, −1], [0, −1, −1]]
```
Cột 3 không bán chuẩn hóa → đặt x₃ = c → X = c(1; 1; −1).
→ Cơ sở: a₃ = {u₃ = (−1; −1; 1)}. dim E_4 = 1 = r₃. ✓

**Kết luận:** A chéo hóa được trên ℝ.

**Bước 5-6:**
a = {u₁, u₂, u₃} là cơ sở ℝ³.
P = T_{0→a} = [u₁ u₂ u₃] = [[−1, 1, −1], [0, 2, −1], [1, 1, 1]]
Tính P⁻¹ (bằng adj/det hoặc Gauss-Jordan):
```
P⁻¹ = (1/6) · [[−3, 2, 1], [1, 0, 1], [−2, 2, 2]]  (chỉ làm ví dụ, giá trị thực cần tính)
```

**Bước 7: Dạng chéo hóa**
```
D = P⁻¹ A P = diag(3, 1, 4)
```

**Tìm Aᵐ (m ≥ 0 nguyên):**
```
Aᵐ = P · diag(3ᵐ, 1ᵐ, 4ᵐ) · P⁻¹ = P · diag(3ᵐ, 1, 4ᵐ) · P⁻¹
```

---

### Bài tập tương tự (10 bài chéo hóa và tìm Aᵐ):

| Bài | Ma trận A |
|---|---|
| a/ | [[4, 2], [−4, −3]] |
| b/ | [[5, 3], [−3, −3]] |
| c/ | [[1, 0, 1], [0, 1, 0], [1, 0, 1]] |
| d/ | [[7, 6, 10], [−12, 17, 24], [−12, 15, 22]] |
| e/ | [[8, 1, 5], [−2, 3, −1], [4, −1, −1]] |
| f/ | [[5, 6, 3], [1, 0, 1], [1, −2, 1]] |
| g/ | [[1, 3, 1], [−3, 5, 1], [−3, 3, 1]] |
| h/ | [[7, 12, 2], [−3, 4, 0], [2, 0, 2]] |
| i/ | [[2, 1, 1], [−1, 2, 1], [−1, 1, 2]] |
| j/ | [[3, 2, 0], [2, 4, 2], [0, 2, 5]] |

---

## Tóm tắt nhanh Chương 4

| Bước | Nội dung |
|---|---|
| 1 | p_A(x) = det(xI − A) |
| 2 | Giải p_A(x) = 0 → λ₁(r₁), λ₂(r₂), ..., λₖ(rₖ) |
| 3 | Tìm E_{λⱼ} = Ker(A − λⱼI), dim E_{λⱼ} |
| 4 | Nếu dim E_{λⱼ} = rⱼ ∀j → chéo hóa được |
| 5 | P = [véc tơ riêng làm cột], P khả nghịch |
| 6 | D = P⁻¹AP = diag(λ₁, ..., λₖ) |
| 7 | Aᵐ = P Dᵐ P⁻¹ |