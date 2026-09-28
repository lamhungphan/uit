# Buổi 6 – Đại số tuyến tính

> Nguồn: `DSTT Buoi 6.pdf` (lớp MA003.F32.LT.CNTT, ngày 23-08-2026)  
> Kết hợp: Đề kiểm tra giữa kỳ III + Chương 3: KHÔNG GIAN VÉC TƠ (tiếp theo)

---

## Phần 1: Đề kiểm tra giữa kỳ III (Năm học 2025-2026)

### Câu 1: (3,0 điểm) – Ma trận

Cho các ma trận thực:
```
A = [ 1  1  2 ]   m∈ℝ
    [ 1  0  m ]
    [ 3  5  7 ]

B = [ 1  4  2 ]
    [−5  9  1 ]
    [ 3  6  0 ]

C = [ 3  2  1 ]
    [ 1  2  4 ]
    [ λ  1  2 ]   λ∈ℝ
```

a) Tìm ma trận: `2C⁵ Bᵀ A⁻¹`
b) Tìm λ để ma trận C có hạng nhỏ nhất.
c) Với m = 2, tìm ma trận X thỏa `X³ A = D + B`, với
```
D = [ 4  1  0 ]
    [−1  1  5 ]
    [ 8  3  1 ]
```

---

### Câu 2: (3,0 điểm) – Hệ phương trình tuyến tính

Giải và biện luận hệ phương trình tuyến tính sau trên trường số thực:
```
−2x + 2y + 3z = 1
mx − my + mz = 1
mx + y − mz = 1
```
với m là tham số thực.

---

### Câu 3: (2,0 điểm) – Không gian véc tơ con

Trên không gian ℝ⁵, cho tập hợp:
```
W = { (x₁; x₂; x₃; x₄; x₅) | x₁ − 5x₂ + 3x₄ = 0; x₅ + 2x₁ + 7x₂ + 4x₃ = 0 }
```
Hỏi W có phải là không gian véc tơ con của ℝ⁵ không? Vì sao?

---

### Câu 4: (2,0 điểm) – Độc lập/Phụ thuộc tuyến tính & Tọa độ

Trên không gian ℝ⁴, cho tập hợp `S = {u₁, u₂, u₃, u₄}` với:
```
u₁ = (0; 1; 3; −4)
u₂ = (1; 0; −2; 3)
u₃ = (−3; 2; 0; −5)
u₄ = (4; 3; −5; 0)
```

a) Hỏi tập hợp S là độc lập tuyến tính hay phụ thuộc tuyến tính? Vì sao?

b) Tìm một biểu diễn tuyến tính của véc tơ `α = λu₄ − 3u₃` theo các véc tơ `u₁, u₂, u₃, u₄`, trong đó:
```
α = (−10; 2; 15; −5)
β = (−2; 4; 10; −2)
```

---

## Phần 2: Chương 3 – KHÔNG GIAN VÉC TƠ (TIẾP THEO)

---

### 5. Không gian con sinh bởi một tập hợp (Span)

Cho (V, +, ·) là không gian tuyến tính tổng quát trên trường F, và tập hợp `S = {α₁, α₂, ..., αₘ}` trên V.

Ký hiệu:
```
⟨S⟩ = tập hợp tất cả các THTT có từ S
    = { c₁α₁ + c₂α₂ + ... + cₘαₘ | c₁, c₂, ..., cₘ ∈ F }
```

Ta có **⟨S⟩ ≤ V**, nghĩa là ⟨S⟩ là không gian véc tơ con (không gian tuyến tính con) của V, **sinh bởi tập hợp S** (thường viết **S spans ⟨S⟩**).

**Ý nghĩa:** Trên V có thể có nhiều không gian con khác nhau chứa được S, nhưng **⟨S⟩ là không gian con nhỏ nhất** chứa được S.

---

### 6. Cơ sở (Basis) của không gian véc tơ

**Định nghĩa:** Cơ sở của một không gian véc tơ là một hệ sinh (tập sinh), **độc lập tuyến tính**, của không gian tuyến tính đó.

- Cơ sở của không gian tuyến tính **không duy nhất** (có vô số cơ sở khác nhau).
- Cơ sở là tập hợp chứa những véc tơ **cơ bản nhất, cốt lõi nhất** để tạo ra không gian véc tơ.
- Nếu S = {α₁, ..., αₘ} là cơ sở của V, thì mọi véc tơ α ∈ V đều biểu diễn được duy nhất theo cơ sở S:
  `α = c₁α₁ + c₂α₂ + ... + cₘαₘ`
- **Số lượng véc tơ trong cơ sở = số chiều của không gian.**

---

### Để chứng minh một tập hợp S là cơ sở của V:

1. S là một **hệ sinh** ra V (S spans V).
2. S là tập hợp **ĐLTT** (độc lập tuyến tính).

---

### Ví dụ mẫu 8: bài 3.12
Cho biết hệ `S = {a₁, a₂, a₃}` có là một cơ sở của ℝ³ hay không? Tại sao?

**Giải:** ℝ³ là không gian 3 chiều → cơ sở của ℝ³ là hệ sinh chứa 3 véc tơ, ĐLTT. Mà S đã có 3 véc tơ → S là hệ sinh của ℝ³. Chỉ cần kiểm tra S có ĐLTT hay không.

Lập ma trận `A_S` từ S, bán chuẩn hóa cột → H có 3 dòng khác 0 → `r(A_S) = 3 = số véc tơ trong S` → S là ĐLTT. **S là cơ sở của ℝ³.**

---

### TÌM CƠ SỞ CHO KHÔNG GIAN KHI BIẾT TRƯỚC HỆ SINH (TẬP SINH)

Cho (V, +, ·) là không gian véc tơ tổng quát trên F, tập hợp `S = {α₁, ..., αₘ}` trên V.
Gọi `W = ⟨S⟩` (S là hệ sinh của W).

Tìm cơ sở và xác định số chiều cho W:

**TH1: m = 1** → `S = {α₁}`
- α₁ ≠ 0 → S vừa là hệ sinh, vừa là cơ sở của W. `dim_F W = 1`.

**TH2: m = 2** → `S = {α₁, α₂}`
- α₁ không tỷ lệ với α₂ theo tọa độ → S vừa là hệ sinh, vừa là cơ sở của W. `dim_F W = 2`.

**TH3: m ≥ 3** → `S = {α₁, ..., αₘ}`
- Lập ma trận `A_S` (mỗi dòng là một véc tơ trong S):
```
    [ α₁ ]
    [ α₂ ]
A_S = [ .. ]
    [ αₘ ]
```

**TH3.1:** `A_S` là ma trận vuông
- `det(A_S) ≠ 0` → S là hệ sinh, ĐLTT → S là cơ sở của W, `dim_F W = m`.
- `det(A_S) = 0` → chuyển qua TH3.2.

**TH3.2:** `A_S` là ma trận tùy ý (vuông hoặc không vuông)
- Từ `A_S`, bán chuẩn hóa (chuẩn hóa) tối đa các cột → H
- Số dòng khác 0 của H = k → tập hợp `{αᵧ₁, αᵧ₂, ..., αᵧₖ}` (k cột bán chuẩn) là một **cơ sở của W**, và **số chiều = k**.

**Ví dụ:** `A_S` bán chuẩn hóa cho ma trận H:
```
[ 1  0  2  3  4  0  1 ]
[ 0  2  5  1  1  3  2 ]
[ 0  0  0  2  1  0  8 ]
[ 0  0  0  0  0  0  0 ]  ← 3 dòng khác 0
[ 0  0  0  0  0  0  0 ]
```
→ Cơ sở: `{γ₁ = (1; 0; 2; 3; 4; 0; 1), γ₂ = (0; 2; 5; 1; 1; 3; 2), γ₃ = (0; 0; 0; 2; 1; 0; 8)}`, `dim W = 3`.

---

### TÌM HỆ SINH, CƠ SỞ VÀ SỐ CHIỀU CHO KHÔNG GIAN PHỤ THUỘC THAM SỐ

**Ví dụ mẫu:** Trên V = ℝ⁴, cho:
```
W = { (2b−2a+c; 2b−a−c; 3c−2a; 3a−b−c) | a, b, c ∈ ℝ }
```

a) Chứng minh W ≤ V.

b) Tìm hệ sinh, cơ sở và số chiều cho W.

**Giải:**

Viết lại dạng tổ hợp tuyến tính:
```
W = { a(−1; −1; −2; 1) + b(1; 2; 0; −1) + c(2; −1; 3; −1) | a, b, c ∈ ℝ }
```

Đặt:
```
α₁ = (1; 1; 2; 1)  ← (−1)·(−1; −1; −2; 1)
α₂ = (−1; 2; 0; 3)
α₃ = (2; 1; 3; 1)
S = {α₁, α₂, α₃}
```
→ W = ⟨S⟩, và ⟨S⟩ ≤ V ⇒ **W ≤ V**.

S là hệ sinh của W. Tìm cơ sở:

Lập ma trận `A_S` từ S (mỗi dòng một véc tơ), bán chuẩn hóa cột → H có 3 dòng khác 0 → `r(A_S) = 3 = |S|` → **S là ĐLTT** → S là cơ sở của W, `dim W = 3`.

**Cách 2:** Từ H có thể lấy cơ sở khác:
`γ₁ = (1; 1; 2; 1), γ₂ = (0; 1; −2; −2), γ₃ = (0; 0; −3; −1)` cũng là cơ sở của W, `dim W = 3`.

---


### TÌM HỆ SINH, CƠ SỞ VÀ SỐ CHIỀU CHO KHÔNG GIAN NGHIỆM CỦA HỆ THUẦN NHẤT AX = O

Cho (V, +, ·) là không gian tuyến tính tổng quát trên F = ℝ, gọi:
```
W = { X ∈ ℝⁿ | AX = O }
```

Các bước:
1. Từ hệ thuần nhất AX = O, giải hệ (nên dùng pp Gauss hoặc Gauss‑Jordan).
2. Thay nghiệm vào W → viết W dưới dạng không gian phụ thuộc tham số.
3. Chứng minh W ≤ V và tìm hệ sinh, cơ sở, số chiều cho W (theo phương pháp trên).

---

### Ví dụ mẫu 1: Trên V = ℝ⁵

Cho W là tập nghiệm của hệ:
```
3x₁ + 5x₂ + 4x₃ + 1x₄ + 2x₅ = 0
2x₁ + 4x₂ + 5x₃ + 1x₄ + 3x₅ = 0
x₁ + 2x₂ + 3x₃ + 4x₄ + 5x₅ = 0
3x₁ + 4x₂ + 1x₃ + 2x₄ + 5x₅ = 0
4x₁ + 5x₂ + 1x₃ + 2x₄ + 3x₅ = 0
2x₁ + 7x₂ + 3x₃ + 0x₄ + 0x₅ = 0
3x₁ + 2x₂ + 0x₃ + 0x₄ + 0x₅ = 0
```

**Giải:**
- Đưa ma trận hệ về dạng bán chuẩn hóa → cột 3, 4, 5 không bán chuẩn hóa được.
- Đặt `x₃ = a, x₄ = b, x₅ = c` (vô số nghiệm) → tìm `x₁, x₂` theo a, b, c.
- Thay vào W:
```
W = { (2a−2b−c; 3a−b; a; b; c) | a, b, c ∈ ℝ }
  = { a(1; 1; 1; 0; 0) + b(−2; 1; 0; 1; 0) + c(2; 3; 0; 0; 1) | a, b, c ∈ ℝ }
```
- Đặt `α₁ = (1; 1; 1; 0; 0), α₂ = (−2; 1; 0; 1; 0), α₃ = (2; 3; 0; 0; 1)`.
- S = {α₁, α₂, α₃} là hệ sinh của W.
- Lập ma trận từ S, bán chuẩn hóa → H có 3 dòng khác 0 → `r(A_S) = 3` → **S là cơ sở của W**, `dim W = 3`.
- Cơ sở khác từ H: `γ₁ = (1; 1; 1; 0; 0), γ₂ = (0; −2; 0; 1; 1), γ₃ = (0; 0; −4; 1; 1)`, `dim W = 3`.

---

### 7. TỌA ĐỘ VÉC TƠ THEO CƠ SỞ (Coordinates relative to a basis)

Cho (V, +, ·) là không gian tuyến tính tổng quát trên F. Gọi `S = {α₁, α₂, ..., αₘ}` là một **cơ sở** của V.

Với mọi véc tơ α ∈ V, luôn tồn tại **duy nhất** bộ số `c₁, c₂, ..., cₘ ∈ F` sao cho:
```
α = c₁α₁ + c₂α₂ + ... + cₘαₘ
```

Khi đó, tọa độ của véc tơ α theo cơ sở S là:
```
        [ c₁ ]
        [ c₂ ]
[α]_S = [ .. ]   (viết thành 1 cột ma trận)
        [ cₘ ]
```

---

### Ví dụ mẫu 2: Trên V = ℝ³

Cho `S = { α₁ = (−2; 4; 3), α₂ = (−4; 5; 1), α₃ = (1; 1; −2) }`.

a) Chứng minh S là một cơ sở của ℝ³.
→ ℝ³ là không gian 3 chiều, S có 3 véc tơ (hệ sinh). Kiểm tra ĐLTT: lập ma trận A_S, bán chuẩn hóa → H có 3 dòng khác 0 → `r(A_S) = 3` → **S là cơ sở**.

b) Cho α = (7; −8; −1) ∈ ℝ³. Tìm [α]_S.
→ Giải hệ `c₁α₁ + c₂α₂ + c₃α₃ = α` → tìm c₁, c₂, c₃.

c) Cho β ∈ ℝ³ thỏa `[β]_S = [ 4; 1; −3 ]`. Tìm β.
→ β = 4α₁ + 1α₂ + (−3)α₃ = (7; 8; 5).

d) Cho γ ∈ ℝ³ thỏa `[γ]_S = [ 2; −5; 7 ]`. Tìm γ.
→ γ = 2α₁ − 5α₂ + 7α₃ = (23; −10; 15).

---

### Lưu ý: Cơ sở chính tắc (Standard basis)

Trên V = ℝⁿ, luôn có cơ sở chính tắc:
```
E = { e₁ = (1; 0; ...; 0), e₂ = (0; 1; ...; 0), ..., eₙ = (0; 0; ...; 1) }
```

Với mọi véc tơ `α = (x₁; x₂; ...; xₙ) ∈ ℝⁿ`, tọa độ theo cơ sở chính tắc chính là véc tơ đó:
```
[α]_E = [ x₁ ]
        [ x₂ ]
        [ .. ]
        [ xₙ ]
```
(Không cần giải hệ pt để tìm tọa độ).

---

### Ví dụ mẫu 3: bài 3.18
Tìm tọa độ của véc tơ theo cơ sở cho trước. (Cần tìm 4 số c₁, c₂, c₃, c₄).

---

### Ví dụ mẫu 4: bài 3.20
Cho `u₁ = (2; 1; −1; 1), u₂ = (1; −2; 3; −1)` là cơ sở của không gian `M = ⟨S⟩`.

Tìm số thực λ sao cho `v = (λ; ...)` ∈ M (yêu cầu `λu₁ − v ∈ M` có nghiệm).
→ Đưa về ma trận hóa, để hệ có nghiệm thì dòng 3, 4 phải thỏa dạng (0 0 0 | 0).
→ **Đáp số: λ = −4**.

---

### Ví dụ mẫu 5: bài 3.24
Cho M = { (x₁; x₂; x₃; x₄) | ... hệ thuần nhất ... }.

1. Giải hệ thuần nhất → tìm nghiệm tổng quát (đặt tham số).
2. Viết M dưới dạng ⟨S⟩ → tìm hệ sinh S.
3. Tìm cơ sở của M: lập ma trận từ S, bán chuẩn hóa → H có 3 dòng khác 0.
   → Cơ sở: `γ₁ = (1; 2; 0; 0), γ₂ = (0; −2; 2; 0), γ₃ = (0; 0; 4; 1)`, `dim M = 3`.
4. Tìm tọa độ của w = (1; 5; 1; 1) theo cơ sở a vừa tìm:
   → Giải `w = c₁γ₁ + c₂γ₂ + c₃γ₃` → `[w]_a = [ 1; 3/2; 1 ]`.

---

## Tóm tắt nhanh

| Khái niệm | Ý chính |
|---|---|
| **⟨S⟩ (Span)** | Tập hợp mọi THTT từ S; là không gian con nhỏ nhất chứa S |
| **Cơ sở (Basis)** | Hệ sinh + ĐLTT; không duy nhất; số véc tơ = số chiều |
| **Tìm cơ sở từ hệ sinh** | m=1: α₁≠0; m=2: không tỷ lệ; m≥3: bán chuẩn hóa cột A_S → các cột bán chuẩn = cơ sở |
| **Không gian nghiệm AX=O** | Giải hệ thuần nhất → viết dạng tham số → tìm cơ sở theo phương pháp trên |
| **Tọa độ [α]_S** | Hệ số c₁..cₘ khi α = Σ cᵢαᵢ; giải hệ pt. Cơ sở chính tắc E: [α]_E = α |