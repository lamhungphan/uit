# Buổi 5 – Đại số tuyến tính

> Chương 3: KHÔNG GIAN VÉC TƠ

---

## 1. Không gian véc tơ ℝⁿ và không gian véc tơ tổng quát

### Không gian ℝⁿ
Định nghĩa:
```
ℝⁿ = ℝ × ℝ × ... × ℝ = { (x₁; x₂; ...; xₙ) | x₁, x₂, ..., xₙ ∈ ℝ }
       (n lần)
```

Ví dụ:
```
ℝ¹ = { (a; b) | a, b ∈ ℝ }   ←  ℝ² thực chất là các cặp số thực
ℝ³ = { (a; b; c) | a, b, c ∈ ℝ }
```

Trên ℝⁿ định nghĩa 2 phép toán:

**a. Phép cộng véc tơ:**
```
∀ α = (x₁; x₂; ...; xₙ) ∈ ℝⁿ, ∀ β = (y₁; y₂; ...; yₙ) ∈ ℝⁿ
α + β = (x₁ + y₁; x₂ + y₂; ...; xₙ + yₙ) ∈ ℝⁿ
```

**b. Phép nhân một số thực với véc tơ:**
```
∀ α = (x₁; x₂; ...; xₙ) ∈ ℝⁿ, ∀ c ∈ ℝ
c·α = (cx₁; cx₂; ...; cxₙ) ∈ ℝⁿ
```

### Tính chất của c·α
- c·α cùng **phương** (cùng giá đỡ – support) với α
- c·α **cùng chiều** với α nếu c > 0, **ngược chiều** với α nếu c < 0
- Khi c = 0 thì c·α là **véc tơ zero**
- c·α có **độ dài gấp |c| lần** độ dài của α

Cấu trúc đại số (ℝⁿ, +, ·) là **không gian tuyến tính** (không gian véc tơ) n chiều trên trường số thực.

### Không gian véc tơ tổng quát
Tổng quát, ký hiệu (V, +, ·) là không gian tuyến tính (không gian véc tơ) trên trường F, với phép cộng và phép nhân định nghĩa tương tự như trên ℝⁿ (V = Vector space).

### Ví dụ
Trên ℝ⁶ cho:
```
α = (2; 3; 5; −8; −4; 9)
β = (7; −1; −2; 4; 6; 3)
```
Tìm:
```
235α − 1479β = ?
3572β − 5383α = ?
```

---

## 2. Không gian véc tơ con (Sub-vector space)

### Định nghĩa
Cho (V, +, ·) là không gian véc tơ tổng quát trên trường F, và cho tập hợp W ≠ ∅ trên V.

Do W ⊂ V nên các véc tơ trên W thừa hưởng phép cộng (+) và nhân (·) có sẵn trên V.

W là **không gian véc tơ con** của V, ký hiệu W ≤ V, nếu chứng minh được **2 tính chất**:
```
1. ∀ α ∈ W, ∀ β ∈ W → (α + β) ∈ W
2. ∀ α ∈ W, ∀ c ∈ F → (c·α) ∈ W
```

Ngược lại, nếu 1 trong 2 tính chất bị vi phạm thì W **không phải** là không gian véc tơ con của V.

### Ví dụ mẫu 1: W = { (x; y; z) ∈ ℝ³ | 2x − y + 3z = 0 }
Kiểm chứng W ≤ V:
- γ = (1; −1; −1) ∈ W vì 2·1 − (−1) + 3·(−1) = 0 → W ≠ ∅ (*)
- ∀ α = (x₁; y₁; z₁), β = (x₂; y₂; z₂) ∈ W:
  - 2x₁ − y₁ + 3z₁ = 0 (1)
  - 2x₂ − y₂ + 3z₂ = 0 (2)
  - Cộng (1), (2): 2(x₁+x₂) − (y₁+y₂) + 3(z₁+z₂) = 0 → α + β = (x₁+x₂; y₁+y₂; z₁+z₂) ∈ W (**)
- Nhân (1) với c: 2(cx₁) − (cy₁) + 3(cz₁) = 0 → c·α = (cx₁; cy₁; cz₁) ∈ W (***)
- Từ (*), (**), (***) → **W ≤ V**

### Ví dụ mẫu 2: W = { (x; y; z) ∈ ℝ³ | x² − 5y + 8z = 1 }
**Cách 1** (vi phạm phép cộng):
- α = (4; 3; 0) ∈ W vì 4² − 5·3 + 8·0 = 1
- β = (−4; 3; 0) ∈ W vì (−4)² − 5·3 + 8·0 = 1
- Nhưng α + β = (0; 6; 0) có 0² − 5·6 + 8·0 = −30 ≠ 1 → (α + β) ∉ W
- → **W ≰ V**

**Cách 2** (vi phạm phép nhân):
- α = (3; 0; −1) ∈ W vì 3² − 5·0 + 8·(−1) = 1
- Chọn c = 2 → c·α = (6; 0; −2) có 6² − 5·0 + 8·(−2) = 36 − 16 = 20 ≠ 1 → (c·α) ∉ W
- → **W ≰ V**

### Ví dụ mẫu 3: W = { A = [[a, −b],[2b, 4a]] | a, b ∈ ℝ } ⊂ M₂(ℝ)
Kiểm chứng W ≤ V:
- C₁ = [[1, −3],[6, 4]] ∈ W ứng với a = 1, b = 3 → W ≠ ∅ (*)
- ∀ A₁ = [[a₁, −b₁],[2b₁, 4a₁]], A₂ = [[a₂, −b₂],[2b₂, 4a₂]] ∈ W:
  - A₁ + A₂ = [[a₁+a₂, −(b₁+b₂)],[2(b₁+b₂), 4(a₁+a₂)]] ∈ W ứng với a = a₁+a₂, b = b₁+b₂ (**)
- ∀ c ∈ ℝ: c·A₁ = [[ca₁, −cb₁],[2cb₁, 4ca₁]] ∈ W ứng với a = ca₁, b = cb₁ (***)
- Từ (*), (**), (***) → **W ≤ V**

### Ví dụ mẫu 4: W = { A = [[a², b],[2b, −2a]] | a, b ∈ ℝ } ⊂ M₂(ℝ)
- Chọn a = 2, b = 1: A₁ = [[4, 1],[2, −4]] ∈ W
- Chọn a = −2, b = 1: A₂ = [[4, 1],[2, 4]] ∈ W
- Nhưng A₁ + A₂ = [[8, 2],[0, 0]] ∉ W vì không thỏa điều kiện của W (hệ [[a² = 8],[−2a = 0]] vô lý)
- → **W ≰ V**

### Bài tập: Kiểm chứng W có phải là không gian con của V không?
```
a/ V = ℝ³, W = { (x; y; z) | 3x + 5z = 0 }
b/ V = ℝ³, W = { (x; y; z) | y = 0 }
c/ V = ℝ³, W = { (x; y; z) | x = 4y − 2z }
d/ V = ℝ³, W = { (x; y; z) | 6x − 5yz = 0 }
e/ V = ℝ³, W = { (x; y; z) | xyz = 0 }
f/ V = ℝ³, W = { (x; y; z) | x = 7z − 2 }
g/ V = ℝ³, W = { (x; y; z) | 2x² − 5z = 0 }
h/ V = ℝ³, W = { (x; y; z) | 3x + 5z = 0; 4x − y + z = 0 }
i/ V = ℝ⁴, W = { (x; y; z; t) | 2x − 4y + 6z − t = 0 }
j/ V = ℝ⁴, W = { (x; y; z; t) | x + 2y − z + t = 0; 4x = z − t }
k/ V = M₂(ℝ), W = { A = [[a, b],[b, −a + 3b]] | a, b ∈ ℝ }
l/ V = M₂(ℝ), W = { A = [[ab, b²],[2b, a]] | a, b ∈ ℝ }
```

---

## 3. Tổ hợp tuyến tính (Linear combination)

### Định nghĩa
Cho (V, +, ·) là không gian tuyến tính tổng quát và các véc tơ α₁, α₂, ..., αₘ trên V.

Chọn bộ số c₁, c₂, ..., cₘ trên F và lập véc tơ:
```
α = c₁α₁ + c₂α₂ + ... + cₘαₘ
```
Thì α được gọi là một **tổ hợp tuyến tính** (THTT) của α₁, α₂, ..., αₘ.

Vì c₁, c₂, ..., cₘ được chọn tùy ý nên có thể lập được **vô số** tổ hợp tuyến tính của α₁, α₂, ..., αₘ.

Gọi S = {α₁, α₂, ..., αₘ} là tập hợp trên V. Véc tơ α = c₁α₁ + c₂α₂ + ... + cₘαₘ được gọi là một tổ hợp tuyến tính có từ S.

### Ví dụ
Trên V = ℝ⁵, cho S = { α₁ = (−5; −2; 4; 2; 6), α₂ = (7; −1; 8; 6; 3), α₃ = (2; −1; −2; 4; 9) }.

- Chọn c₁ = −2, c₂ = 3, c₃ = 1 → một THTT có từ S
- Chọn c₁ = 4, c₂ = −2, c₃ = −5 → một THTT có từ S

### Ví dụ mẫu 1: bài 3.1
Chứng minh x = (7; −7; 3) là một THTT của {a₁, a₂, a₃}.

**Cách làm:** cần tìm c₁, c₂, c₃ ∈ ℝ sao cho x = c₁a₁ + c₂a₂ + c₃a₃ → viết hệ pt, đưa về ma trận hóa → nếu hệ có nghiệm thì x là THTT.

Kết quả: hệ có nghiệm duy nhất c₁ = 2, c₂ = 2, c₃ = 1 nên x = (7; −7; 3) là một THTT của {a₁, a₂, a₃}.

### Ví dụ mẫu 2: bài 3.4
Tìm tất cả các biểu diễn tuyến tính có thể có của a₄ trên hệ {a₁, a₂, a₃, a₄}.

**Cách làm:** tìm c₁, c₂, c₃, c₄ sao cho a₄ = c₁a₁ + c₂a₂ + c₃a₃ + c₄a₄ → ma trận hóa.

Do cột 4 không bán chuẩn hóa được → hệ có **vô số nghiệm**. Đặt c₄ = a, ∀a ∈ ℝ → tìm các c₁, c₂, c₃ theo a → tập hợp tất cả các biểu diễn tuyến tính của a₄.

### Ví dụ mẫu 3
Tìm λ để x = (2; 3; −2; λ) biểu diễn được theo các véc tơ:
```
a₁ = (1; 1; −2; 2), a₂ = (2; 3; 1; 4), a₃ = (3; −4; 2; 3)
```
- Cần tìm c₁, c₂, c₃ sao cho x = c₁a₁ + c₂a₂ + c₃a₃ có nghiệm
- Viết ma trận hóa: để hệ có nghiệm, pt (4) phải có dạng (0 0 0 | 0), nghĩa là −7 + λ = 0 → **λ = 7**

---

## 4. Sự độc lập tuyến tính (ĐLTT) và phụ thuộc tuyến tính (PTTT)

### Định nghĩa
Cho (V, +, ·) là không gian tuyến tính tổng quát trên trường F, và tập hợp S = {α₁, α₂, ..., αₘ} trên V.

Xét hệ phương trình:
```
c₁α₁ + c₂α₂ + ... + cₘαₘ = 0
(với c₁, c₂, ..., cₘ là các ẩn số cần tìm)
```

- **S là độc lập tuyến tính (ĐLTT):** nếu hệ pt chỉ có bộ nghiệm tầm thường duy nhất c₁ = c₂ = ... = cₘ = 0. Các véc tơ trong S không thể biểu diễn lẫn nhau.
- **S là phụ thuộc tuyến tính (PTTT):** nếu hệ pt có vô số nghiệm (bên cạnh nghiệm tầm thường). Các véc tơ trong S biểu diễn được lẫn nhau, ví dụ α₃ = 5α₂ − 4α₁ + 3α₄.

### Ví dụ mẫu 4: Trên V = ℝ³, S = { α₁ = (1; −2; 1), α₂ = (−1; 3; −2), α₃ = (2; 0; 1), α₄ = (−2; 1; 2) }
Giải hệ c₁α₁ + c₂α₂ + c₃α₃ + c₄α₄ = 0 → ma trận hóa.

Do cột 4 không bán chuẩn hóa được → hệ có **vô số nghiệm**. Đặt c₄ = t → có nghiệm khác nghiệm tầm thường → **S là PTTT**.

### Ví dụ mẫu 5: Trên V = ℝ⁴, S = { a₁ = (1; 0; 1; 0), a₂ = (−1; 1; 0; 1), a₃ = (0; −2; 1; −3) }
Giải hệ c₁a₁ + c₂a₂ + c₃a₃ = 0 → ma trận hóa.

Do ma trận kết quả có 3 cột bán chuẩn liên tiếp → hệ có **nghiệm duy nhất** (nghiệm tầm thường) → **S là ĐLTT**.

---

## 5. Cách nhận diện nhanh S là ĐLTT hay PTTT

Lập ma trận Aₛ (mỗi dòng là một véc tơ trong S):
```
        [ α₁ ]
        [ α₂ ]
Aₛ =    [ .. ]
        [ αₘ ]
```

**Trường hợp 1:** Aₛ là ma trận vuông cấp m
- det(Aₛ) ≠ 0 → S là tập **ĐLTT**
- det(Aₛ) = 0 → S là tập **PTTT**

**Trường hợp 2:** Aₛ là ma trận tùy ý (vuông hoặc không vuông)
- Từ Aₛ, bán chuẩn hóa (chuẩn hóa) tối đa các cột → H
- Xác định r(Aₛ) = rank(Aₛ) = số dòng khác 0 của H
- r(Aₛ) = m (số véc tơ trong S) → S là tập **ĐLTT**
- r(Aₛ) < m → S là tập **PTTT**

### Ví dụ mẫu 6: bài 3.9a
Chứng minh hệ S = {a₁, a₂, a₃} là hệ ĐLTT.

**Cách 1:** Lập ma trận Aₛ (vuông cấp 3), tính det(Aₛ) ≠ 0 → hệ ĐLTT.

**Cách 2:** Bán chuẩn hóa cột Aₛ → H có 3 dòng khác 0 → r(Aₛ) = 3 = số véc tơ trong S → hệ ĐLTT.

### Ví dụ mẫu 7: bài 3.11a
Tìm các giá trị của λ để hệ {a₁, a₂, a₃} là hệ ĐLTT.

Lập ma trận Aₛ (vuông cấp 3). Để hệ ĐLTT thì:
```
det(Aₛ) ≠ 0 ⇔ 3λ − 6 ≠ 0 ⇔ λ ≠ 2
```
**Đáp số:** λ ≠ 2 thì hệ {a₁, a₂, a₃} là hệ ĐLTT.

---

## Tóm tắt nhanh

| Khái niệm | Ý chính |
|---|---|
| **ℝⁿ** | Tập các bộ số thực (x₁;...;xₙ), với phép cộng & nhân vô hướng |
| **Không gian con W ≤ V** | 1. đóng kín với phép cộng, 2. đóng kín với phép nhân vô hướng |
| **Tổ hợp tuyến tính** | α = c₁α₁ + ... + cₘαₘ; kiểm tra hệ pt có nghiệm |
| **ĐLTT** | c₁α₁ + ... + cₘαₘ = 0 chỉ có nghiệm tầm thường |
| **PTTT** | Hệ có vô số nghiệm; các véc tơ biểu diễn được lẫn nhau |
| **Nhận diện nhanh** | Vuông: det ≠ 0 → ĐLTT; tổng quát: r(Aₛ) = m → ĐLTT |
