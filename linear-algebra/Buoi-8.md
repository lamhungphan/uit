# Buổi 8 – Đại số tuyến tính

> Nguồn: `DSTT Buoi 8.pdf` (lớp MA003.F32.LT.CNTT, ngày 13-09-2026)

---

## Phần 1: Liên hệ giữa trị riêng và định thức (Chương 4 bổ sung)

### Lưu ý quan trọng

Cho A là ma trận vuông cấp n trên ℝ. Giả sử A có các trị riêng thực là:
```
λ₁ = λ₂ = ... = λ₁ (r₁ lần)
λ₂ = λ₂ = ... = λ₂ (r₂ lần)
...
λₖ = λₖ = ... = λₖ (rₖ lần)
```

Tức đa thức đặc trưng tách thành nhân tử:
```
p_A(λ) = det(A − λI) = (λ₁ − λ)ʳ¹ · (λ₂ − λ)ʳ² · ... · (λₖ − λ)ʳᵏ
```

**Suy ra:** Hệ số tự do của đa thức đặc trưng chính là **det(A)** = tích các trị riêng (tính theo số mũ):
```
det(A) = λ₁ʳ¹ · λ₂ʳ² · ... · λₖʳᵏ
```

### Ví dụ mẫu
Cho A vuông cấp 2, có 2 trị riêng: λ₁ = 5, λ₂ = −4. Tìm det(A)?
```
p_A(λ) = (5 − λ)(−4 − λ) = λ² − λ − 20
→ Hệ số tự do = −20 = det(A)
```
Kiểm chứng: det(A) = λ₁·λ₂ = 5·(−4) = −20. ✓

---

## Phần 2: Chương 5 – KHÔNG GIAN EUCLIDE

### 1. Tích vô hướng (Inner Product)

Cho (V, +, ·) là không gian véc tơ tổng quát trên ℝ.
Một **tích vô hướng** trên V là ánh xạ:
```
⟨·, ·⟩ : V × V → ℝ
```
thỏa mãn 4 tính chất:

| Tính chất | Công thức |
|---|---|
| **i/** Tính dương | ⟨α, α⟩ ≥ 0, ∀α ∈ V. Có ⟨α, α⟩ = 0 ⇔ α = 0 |
| **ii/** Tính đối xứng | ⟨α, β⟩ = ⟨β, α⟩, ∀α, β ∈ V |
| **iii/** Tuyến tính biến 1 | ⟨c₁α₁ + c₂α₂, β⟩ = c₁⟨α₁, β⟩ + c₂⟨α₂, β⟩, ∀c₁,c₂∈ℝ, α₁,α₂,β∈V |
| **iv/** Tuyến tính biến 2 | ⟨α, c₁β₁ + c₂β₂⟩ = c₁⟨α, β₁⟩ + c₂⟨α, β₂⟩, ∀c₁,c₂∈ℝ, α,β₁,β₂∈V |

**Lưu ý khi kiểm tra:**
- Chỉ cần kiểm tra **i/, ii/, iii/** là đủ (iv/ suy ra từ ii/ + iii/; v/ luôn đúng).
- Để chứng minh **không phải** tích vô hướng → chỉ cần tìm 1 ví dụ vi phạm 1 trong 4 tính chất.

**Không gian Euclide:** Không gian véc tơ V có trang bị thêm một tích vô hướng ⟨·, ·⟩. Ký hiệu: (V, ⟨·, ·⟩) hoặc Eu = (V, ⟨·, ·⟩).

### Ví dụ mẫu 1: V = ℝ³
Ánh xạ:
```
⟨(x₁;x₂;x₃), (y₁;y₂;y₃)⟩ = x₁y₁ + 2x₂y₂ + 3x₃y₃
```
Kiểm tra:
- i/ ⟨α, α⟩ = x₁² + 2x₂² + 3x₃² ≥ 0. =0 ⇔ x₁=x₂=x₃=0. ✓
- ii/ ⟨α, β⟩ = x₁y₁+2x₂y₂+3x₃y₃ = y₁x₁+2y₂x₂+3y₃x₃ = ⟨β, α⟩. ✓
- iii/ Tuyến tính biến 1: chứng minh trực tiếp. ✓
→ **Là tích vô hướng** trên ℝ³.

### Ví dụ mẫu 2: V = ℝ²
Ánh xạ:
```
⟨(x₁;x₂), (y₁;y₂)⟩ = x₁y₁ + x₂y₂ + 1  (cộng thêm 1)
```
Kiểm tra tính chất i/:
```
Chọn α = (0; 4): ⟨α, α⟩ = 0·0 + 4·4 + 1 = 17 ≥ 0  (thỏa)
Nhưng α = (0; 4) ≠ 0 mà ⟨α, α⟩ ≠ 0 (không vi phạm)
```
Chỉ vi phạm khi tìm được α ≠ 0 mà ⟨α, α⟩ = 0 hoặc ⟨α, α⟩ < 0.

Cách 2: Kiểm tra ii/ (đối xứng):
```
Chọn α = (1; 0), β = (0; 1):
⟨α, β⟩ = 1·0 + 0·1 + 1 = 1
⟨β, α⟩ = 0·1 + 1·0 + 1 = 1  (thỏa)
```
Cách 3: Kiểm tra iii/ (tuyến tính biến 1):
```
Chọn α₁ = (1; 0), α₂ = (0; 1), β = (1; 1), c₁ = c₂ = 1:
⟨α₁+α₂, β⟩ = ⟨(1;1), (1;1)⟩ = 1+1+1 = 3
⟨α₁, β⟩ + ⟨α₂, β⟩ = (1+1) + (0+1+1) = 2+2 = 4 ≠ 3
→ **Vi phạm iii/** → **Không phải tích vô hướng**.
```

### Bài tập tương tự (5 bài): Kiểm tra các ánh xạ trên ℝ², ℝ³

a/ ℝ²: ⟨(x₁;x₂), (y₁;y₂)⟩ = x₁y₁ + 5x₂y₂
b/ ℝ²: ⟨(x₁;x₂), (y₁;y₂)⟩ = x₁y₁ + 6x₁y₂ + 9x₂y₁ + 2x₂y₂
c/ ℝ³: ⟨(x₁;x₂;x₃), (y₁;y₂;y₃)⟩ = x₁y₁ + x₂y₂ + x₃y₃ + x₁y₂ + 2x₂y₁ + 3x₂y₂ + x₃y₁ + x₁y₃ + 2x₂y₃
d/ ℝ³: ⟨...⟩ = x₁y₁ + x₂y₂ + x₃y₃ + 6x₁y₂ + 5x₂y₁ + 2x₃y₂ + 8x₂y₃
e/ ℝ³: ⟨...⟩ = x₁y₁ + x₂y₂ + x₃y₃ + 4x₁y₂ + 2x₂y₁ + 3x₃y₂ + 7x₂y₃

### Tích vô hướng tiêu chuẩn (Standard Inner Product)
Trên ℝⁿ luôn có tích vô hướng tiêu chuẩn:
```
⟨α, β⟩ = x₁y₁ + x₂y₂ + ... + xₙyₙ  (tích vô hướng Euclide chuẩn)
```

---

### 2. Độ dài véc tơ và khoảng cách

Cho không gian Euclide (V, ⟨·, ·⟩).

**Độ dài (module) của véc tơ α:**
```
‖α‖ = √⟨α, α⟩
```

**Khoảng cách giữa 2 véc tơ α, β:**
```
d(α, β) = ‖α − β‖ = √⟨α − β, α − β⟩
```

### Ví dụ 1: ℝ⁴ với tích vô hướng tiêu chuẩn
Cho các véc tơ. Tìm độ dài và khoảng cách. (Áp dụng công thức trực tiếp).

### Ví dụ 2: ℝ⁵ với tích vô hướng tiêu chuẩn
Tương tự.

---

### 3. Trực giao (Orthogonal) và Trực chuẩn (Orthonormal)

Cho không gian Euclide (V, ⟨·, ·⟩).

**Hai véc tơ vuông góc:** α₁ ⊥ α₂ ⇔ ⟨α₁, α₂⟩ = 0.

**Tập hợp trực giao:** S = {α₁, ..., αₘ} với ⟨αᵢ, αⱼ⟩ = 0 ∀ i ≠ j.

**Tập hợp trực chuẩn:** S là tập trực giao + ‖αᵢ‖ = 1 ∀ i.

**Véc tơ vuông góc với tập S:** α ⊥ S ⇔ ⟨α, αᵢ⟩ = 0 ∀ αᵢ ∈ S.

**Không gian trực giao với S:** Tập hợp tất cả các véc tơ vuông góc với S.

---

### 4. Trực giao hóa và Trực chuẩn hóa (Gram-Schmidt)

Cho S = {α₁, α₂, ..., αₘ} trên không gian Euclide V.

**Bước 1: Trực giao hóa S thành S' = {β₁, β₂, ..., βₘ}**
```
β₁ = α₁
β₂ = α₂ − ⟨α₂, β₁⟩/‖β₁‖² · β₁
β₃ = α₃ − ⟨α₃, β₁⟩/‖β₁‖² · β₁ − ⟨α₃, β₂⟩/‖β₂‖² · β₂
...
βₘ = αₘ − Σ ⟨αₘ, βᵢ⟩/‖βᵢ‖² · βᵢ  (i = 1..m−1)
```

**Bước 2: Trực chuẩn hóa S' thành S'' = {γ₁, γ₂, ..., γₘ}**
```
γᵢ = βᵢ / ‖βᵢ‖   (i = 1..m)
```

### Ví dụ mẫu 3: ℝ³ với tích vô hướng tiêu chuẩn
Cho S = {α₁, α₂, α₃}. Áp dụng Gram-Schmidt:
```
β₁ = α₁
β₂ = α₂ − (⟨α₂,β₁⟩/‖β₁‖²)β₁
β₃ = α₃ − (⟨α₃,β₁⟩/‖β₁‖²)β₁ − (⟨α₃,β₂⟩/‖β₂‖²)β₂
```
Sau đó chuẩn hóa: γᵢ = βᵢ/‖βᵢ‖.

### Bài tập tương tự (4 bài trực chuẩn hóa trên ℝ³):

1. S = {(2; 3; 6), (−3; 6; −2), (6; −2; 3)}
2. S = {(1; −2; 2), (−2; 2; −1), (2; 1; −2)}
3. S = {(8; 1; −4), (1; 0; −2), (−2; 8; −2)}
4. Trên ℝ³ với tích vô hướng cho trước (không phải tiêu chuẩn), S = {(1; 0; 1), (−4; 0; 2), (−3; 1; 3)}

---

### 5. Tọa độ theo cơ sở trực chuẩn

Cho không gian Euclide V = (ℝⁿ, ⟨·, ·⟩) có cơ sở trực chuẩn:
```
ζ = {γ₁, γ₂, ..., γₙ}  (⟨γᵢ, γⱼ⟩ = δᵢⱼ)
```

Với mọi α ∈ V, biểu diễn: α = c₁γ₁ + c₂γ₂ + ... + cₙγₙ.

**Công thức tọa độ (RẤT QUAN TRỌNG):**
```
cᵢ = ⟨α, γᵢ⟩   (vì ⟨α, γᵢ⟩ = Σ cⱼ⟨γⱼ, γᵢ⟩ = cᵢ)
```

**Tọa độ theo cơ sở trực chuẩn:**
```
[α]_ζ = [ ⟨α, γ₁⟩, ⟨α, γ₂⟩, ..., ⟨α, γₙ⟩ ]ᵀ
```

**Lưu ý:** Không cần giải hệ phương trình! Chỉ cần tính tích vô hướng.

### Ví dụ mẫu: ℝ³ với cơ sở trực chuẩn ζ
Cho α = (6; −7; 1). Tìm [α]_ζ.
```
c₁ = ⟨α, γ₁⟩, c₂ = ⟨α, γ₂⟩, c₃ = ⟨α, γ₃⟩
→ [α]_ζ = [c₁, c₂, c₃]ᵀ
```

---

### 6. Chéo hóa trực giao ma trận vuông (Symmetric Diagonalization)

**Ma trận trực giao:** A khả nghịch và A⁻¹ = Aᵀ (tức AᵀA = I).

**Mọi ma trận đối xứng thực (Aᵀ = A) đều chéo hóa trực giao được** (Định lý Spectral).

#### Các bước chéo hóa trực giao:

1. Tìm đa thức đặc trưng p_A(x) = det(A − xI).
2. Giải p_A(x) = 0 trên ℝ → tìm các trị riêng λⱼ (có số mũ rⱼ).
3. Nếu p_A(x) có nghiệm phức → **không chéo hóa trực giao trên ℝ**.
4. Với mỗi trị riêng λⱼ: tìm không gian riêng E_{λⱼ} = Ker(A − λⱼI) và cơ sở aⱼ.
5. Kiểm tra: dim E_{λⱼ} = rⱼ ∀ j → chéo hóa được.
6. **Trực chuẩn hóa từng cơ sở aⱼ bằng Gram-Schmidt** → được cơ sở trực chuẩn ζⱼ.
7. Gộp ζ = ζ₁ ∪ ζ₂ ∪ ... ∪ ζₖ → ζ là cơ sở trực chuẩn của ℝⁿ.
8. Đặt P = [ζ₁ ζ₂ ... ζₙ] (các véc tơ trực chuẩn làm cột). Khi đó **P là ma trận trực giao**: P⁻¹ = Pᵀ.
9. Dạng chéo hóa trực giao:
   ```
   D = Pᵀ A P = P⁻¹ A P = diag(λ₁, ..., λₖ)
   ```

### Ví dụ mẫu: Chéo hóa trực giao

Cho A = [[...]]. Các bước:
- Tìm đa thức đặc trưng, giải → λ₁ = 0, λ₂ = 3 (r₂ = 2).
- Tìm E_0: Ker(A − 0I) → cơ sở a₁ = {(1; 1; 1)}, dim = 1 = r₁.
- Tìm E_3: Ker(A − 3I) → cơ sở a₂ = {(−1; 1; 0), (−1; 0; 1)}, dim = 2 = r₂.
- **Trực chuẩn hóa a₁, a₂ bằng Gram-Schmidt:**
  - a₁ = {u₁ = (1; 1; 1)} → γ₁ = u₁/√3 = (1/√3; 1/√3; 1/√3).
  - a₂ = {v₁ = (−1; 1; 0), v₂ = (−1; 0; 1)}:
    - β₁ = v₁ → γ₂ = v₁/√2 = (−1/√2; 1/√2; 0).
    - β₂ = v₂ − ⟨v₂, γ₂⟩γ₂ → chuẩn hóa → γ₃.
- P = [γ₁ γ₂ γ₃] là ma trận trực giao (P⁻¹ = Pᵀ).
- D = PᵀAP = diag(0, 3, 3).

### Bài tập tương tự: Chéo hóa trực giao các ma trận vuông thực.

---

## Phần 3: Nội dung ôn tập cuối kỳ (90 phút)

### Câu 1: Không gian véc tơ con
Trên ℝ⁵ (hoặc ℝ⁶), cho W = { ... | ... }.
- Chứng minh W ≤ V.
- Tìm hệ sinh, cơ sở, số chiều cho W.

### Câu 2: Cơ sở & Trực chuẩn hóa
Trên ℝ³, cho S = {u₁, u₂, u₃}.
- a/ Chứng minh S là cơ sở của ℝ³.
- b/ Trực chuẩn hóa S thành cơ sở trực chuẩn S' (Gram-Schmidt).
- c/ Tìm tọa độ véc tơ v ∈ ℝ³ theo cơ sở S.
- d/ Tìm tọa độ véc tơ v ∈ ℝ³ theo cơ sở trực chuẩn S'.

### Câu 3: Gram-Schmidt trên ℝ⁴
Với tích vô hướng cho trước, dùng Gram-Schmidt trực chuẩn hóa S = {u₁, u₂, u₃}.
- Tìm tọa độ véc tơ λ theo cơ sở trực chuẩn vừa tìm.

### Câu 4: Chéo hóa ma trận cấp 2 & lũy thừa
Cho ma trận A = [[...]].
- Chéo hóa A.
- Tìm Aᵐ ∀ m ∈ ℕ.
- Suy ra A²⁰²⁶.

---

## Tóm tắt nhanh Chương 5

| Khái niệm | Công thức / Ý chính |
|---|---|
| **Tích vô hướng** | ⟨α, β⟩ = Σ xᵢyᵢ (tiêu chuẩn); kiểm tra i, ii, iii |
| **Độ dài** | ‖α‖ = √⟨α, α⟩ |
| **Khoảng cách** | d(α, β) = ‖α − β‖ |
| **Trực giao** | α ⊥ β ⇔ ⟨α, β⟩ = 0 |
| **Gram-Schmidt** | β₁ = α₁; βᵢ = αᵢ − Σ⟨αᵢ, βⱼ⟩/‖βⱼ‖² βⱼ; γᵢ = βᵢ/‖βᵢ‖ |
| **Tọa độ cơ sở trực chuẩn** | cᵢ = ⟨α, γᵢ⟩ → [α]_ζ = [⟨α, γ₁⟩ ... ⟨α, γₙ⟩]ᵀ |
| **Ma trận trực giao** | A⁻¹ = Aᵀ ⇔ AᵀA = I |
| **Chéo hóa trực giao** | A đối xứng → P = [γ₁ ... γₙ], P⁻¹ = Pᵀ, PᵀAP = diag(λ) |