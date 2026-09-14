# Toán cơ sở – Kiến thức nền cho Đại số tuyến tính

> Tài liệu tham khảo nhanh các quy tắc, phép toán, kỹ thuật cơ bản dùng xuyên suốt môn học.

---

## 1. Quy tắc cơ bản của đại số

### Chuyển vế, đổi dấu
```
a + b = c     ⇔     a = c − b
a − b = c     ⇔     a = c + b
a = b + c     ⇔     a − b = c
a = b − c     ⇔     a + c = b
```

### Nhân, chia hai vế
```
a = b        ⇔        a·c = b·c     (c ≠ 0)
a = b        ⇔        a/c = b/c     (c ≠ 0)
a·b = 0      ⇔      a = 0  HOẶC  b = 0
```

### Dấu ngoặc
```
−(a + b) = −a − b
−(a − b) = −a + b
(a + b) + c = a + (b + c)
(a − b) − c = a − b − c
a − (b − c) = a − b + c
```

---

## 2. Phân số và biểu thức hữu tỷ

### Quy tắc cộng, trừ
```
a/b ± c/d = (ad ± bc) / bd
```

### Quy tắc nhân, chia
```
(a/b) · (c/d) = ac / bd
(a/b) / (c/d) = (a/b) · (d/c) = ad / bc   (c ≠ 0)
```

### Rút gọn
```
ab / ac = b / c          (a ≠ 0)
(a + b) / c = a/c + b/c
(a − b) / c = a/c − b/c
```

### Biến đổi hữu ích
```
1 / (a/b) = b/a
a / (b/c) = ac / b
(a/b) / c = a / (bc)
```

---

## 3. Lũy thừa và căn thức

### Lũy thừa
```
a^m · a^n = a^(m+n)
a^m / a^n = a^(m−n)
(a^m)^n = a^(mn)
(ab)^n = a^n · b^n
(a/b)^n = a^n / b^n
a^0 = 1              (a ≠ 0)
a^(−n) = 1 / a^n
a^(1/n) = ⁿ√a
a^(m/n) = ⁿ√(a^m) = (ⁿ√a)^m
```

### Căn thức
```
ⁿ√a · ⁿ√b = ⁿ√(ab)
ⁿ√a / ⁿ√b = ⁿ√(a/b)
ⁿ√(a^m) = a^(m/n)
√a · √b = √(ab)        (a,b ≥ 0)
```

### Khử mẫu (rationalize denominator)
```
1 / √a = √a / a
1 / (√a + √b) = (√a − √b) / (a − b)
1 / (√a − √b) = (√a + √b) / (a − b)
```

---

## 4. Giải phương trình bậc nhất, bậc hai

### Phương trình bậc nhất: ax + b = 0
```
Nếu a ≠ 0:  x = −b/a
Nếu a = 0, b = 0:  vô số nghiệm
Nếu a = 0, b ≠ 0:  vô nghiệm
```

### Phương trình bậc hai: ax² + bx + c = 0 (a ≠ 0)
```
Δ = b² − 4ac
Δ > 0:  2 nghiệm phân biệt  x₁,₂ = (−b ± √Δ) / (2a)
Δ = 0:  nghiệm kép  x = −b / (2a)
Δ < 0:  vô nghiệm thực (có nghiệm phức)
```

### Vieta (khi Δ ≥ 0)
```
x₁ + x₂ = −b/a
x₁ · x₂ = c/a
```

---

## 5. Hệ phương trình tuyến tính

### Hệ 2 phương trình, 2 ẩn
```
a₁x + b₁y = c₁
a₂x + b₂y = c₂
```

**Cramer:**
```
Δ = a₁b₂ − a₂b₁
Δₓ = c₁b₂ − c₂b₁
Δy = a₁c₂ − a₂c₁

Δ ≠ 0:  x = Δₓ/Δ,  y = Δy/Δ
Δ = 0, (Δₓ ≠ 0 hoặc Δy ≠ 0):  vô nghiệm
Δ = Δₓ = Δy = 0:  vô số nghiệm
```

### Hệ 3 phương trình, 3 ẩn
Tương tự dùng Cramer hoặc **phương pháp khử (Gauss)**:
1. Viết ma trận mở rộng
2. Biến đổi sơ cấp hàng → dạng bậc thang
3. Thay thế ngược (back substitution)

---

## 6. Ma trận – Các phép toán cơ bản

### Cộng, trừ (cùng cỡ)
```
(A ± B)ᵢⱼ = Aᵢⱼ ± Bᵢⱼ
```

### Nhân vô hướng
```
(cA)ᵢⱼ = c · Aᵢⱼ
```

### Nhân ma trận
```
(A·B)ᵢₖ = Σⱼ Aᵢⱼ · Bⱼₖ
```
- Số cột A = số hàng B
- Kết quả: hàng của A × cột của B
- **Không giao hoán**: AB ≠ BA (tổng quát)

### Chuyển vị (Transpose)
```
(Aᵀ)ᵢⱼ = Aⱼᵢ
(A + B)ᵀ = Aᵀ + Bᵀ
(cA)ᵀ = cAᵀ
(AB)ᵀ = BᵀAᵀ        (lưu ý thứ tự ngược!)
```

### Ma trận đơn vị
```
Iₙ = diag(1, 1, ..., 1)
AI = IA = A
```

### Ma trận nghịch đảo
```
A·A⁻¹ = A⁻¹·A = I
(AB)⁻¹ = B⁻¹A⁻¹
(Aᵀ)⁻¹ = (A⁻¹)ᵀ
(A⁻¹)⁻¹ = A
(cA)⁻¹ = (1/c)A⁻¹    (c ≠ 0)
```

---

## 7. Định thức (Determinant)

### Cấp 2
```
det([[a, b], [c, d]]) = ad − bc
```

### Cấp 3 – Quy tắc Sarrus
```
| a b c |
| d e f |  = aei + bfg + cdh − ceg − bdi − afh
| g h i |
```

### Tính chất quan trọng
```
det(A) = det(Aᵀ)
det(AB) = det(A)·det(B)
det(cA) = cⁿ·det(A)        (A cấp n)
det(A⁻¹) = 1/det(A)
det(Aᵏ) = (det(A))ᵏ
det(A) = 0  ⇔  A không khả nghịch
```

### Biến đổi sơ cấp hàng & định thức
| Phép biến đổi | Ảnh hưởng det |
|---|---|
| Hoán vị 2 hàng | đổi dấu |
| Nhân 1 hàng với c | nhân det với c |
| Cộng bội hàng này vào hàng kia | **không đổi** |

---

## 8. Hạng của ma trận (Rank)

```
rank(A) = số hàng (hoặc cột) độc lập tối đa
      = số hàng khác 0 của dạng bậc thang
      = số cột cơ sở (pivot columns)
```

### Định lý Kronecker-Capelli
Hệ AX = B, ma trận mở rộng Ā = (A|B):
```
rank(A) < rank(Ā)        →  VÔ NGHIỆM
rank(A) = rank(Ā) = n    →  NGHIỆM DUY NHẤT
rank(A) = rank(Ā) = k < n  →  VÔ SỐ NGHIỆM (n−k tham số)
```

---

## 9. Không gian véc tơ

### Ký hiệu
```
ℝⁿ = { (x₁, ..., xₙ) | xᵢ ∈ ℝ }
α = (x₁, ..., xₙ)    (véc tơ hàng hoặc cột tùy ngữ cảnh)
```

### Phép toán trên ℝⁿ
```
α + β = (α₁+β₁, ..., αₙ+βₙ)
c·α = (cα₁, ..., cαₙ)
```

### Tích vô hướng (tiêu chuẩn)
```
⟨α, β⟩ = α₁β₁ + ... + αₙβₙ = αᵀβ
```

### Độ dài, khoảng cách
```
‖α‖ = √⟨α, α⟩ = √(α₁² + ... + αₙ²)
d(α, β) = ‖α − β‖
```

### Trực giao, trực chuẩn
```
α ⊥ β  ⇔  ⟨α, β⟩ = 0
{γ₁, ..., γₙ} trực chuẩn  ⇔  ⟨γᵢ, γⱼ⟩ = δᵢⱼ
```

### Gram-Schmidt
```
β₁ = α₁
β₂ = α₂ − (⟨α₂, β₁⟩/‖β₁‖²) β₁
β₃ = α₃ − (⟨α₃, β₁⟩/‖β₁‖²) β₁ − (⟨α₃, β₂⟩/‖β₂‖²) β₂
...
γᵢ = βᵢ / ‖βᵢ‖
```

---

## 9. Trị riêng, véc tơ riêng, chéo hóa

### Trị riêng (eigenvalue)
```
c là trị riêng của A  ⇔  det(A − cI) = 0
⇔  Hệ (A − cI)X = 0 có nghiệm khác 0
```

### Đa thức đặc trưng
```
p_A(x) = det(xI − A) = det(A − xI)
Bậc = n (cấp ma trận)
```

### Không gian riêng
```
E_λ = { X | (A − λI)X = 0 } = Ker(A − λI)
dim E_λ = n − rank(A − λI)
```

### Chéo hóa (Diagonalization)
A chéo hóa được trên ℝ ⇔
1. p_A(x) tách được nhân tử bậc 1 trên ℝ
2. ∀λ: dim E_λ = số mũ của λ trong p_A(x)

**Quy trình:**
1. Tìm p_A(x) = det(xI − A)
2. Giải p_A(x) = 0 → λ₁(r₁), ..., λₖ(rₖ)
3. Với mỗi λ: tìm E_λ = Ker(A − λI), lấy cơ sở
4. Nếu dim E_λ = r_λ ∀λ → chéo hóa được
5. P = [véc tơ riêng làm cột], D = P⁻¹AP = diag(λ₁, ..., λₙ)
6. Aᵐ = P Dᵐ P⁻¹

### Chéo hóa trực giao (ma trận đối xứng)
- Aᵀ = A ⇒ luôn chéo hóa trực giao được trên ℝ
- Trực chuẩn hóa từng cơ sở E_λ → P trực giao: P⁻¹ = Pᵀ
- PᵀAP = D

---

## 10. Kỹ thuật giải bài tập thường gặp

### 1. Tìm A⁻¹
- **Cách 1 (adj/det):** A⁻¹ = adj(A)/det(A) – tốt cho ma trận 2×2, 3×3
- **Cách 2 (Gauss-Jordan):** (A | I) → (I | A⁻¹) – tốt cho mọi cỡ, ít sai sót

### 2. Tìm hạng ma trận
- Biến đổi sơ cấp hàng → dạng bậc thang → đếm hàng ≠ 0
- Hoặc: bán chuẩn hóa cột (phương pháp cột chuẩn)

### 3. Giải hệ AX = B
- **Gauss:** (A|B) → bậc thang → thay thế ngược
- **Gauss-Jordan:** (A|B) → bậc thang thu gọn → đọc nghiệm trực tiếp
- **Cramer:** Chỉ khi A vuông, det(A) ≠ 0

### 4. Tìm cơ sở không gian con
- **Từ hệ sinh S:** Lập ma trận hàng từ S → bán chuẩn hóa cột → các cột pivot = cơ sở
- **Từ hệ thuần nhất AX=0:** Giải hệ → viết nghiệm dạng tham số → hệ sinh = cơ sở

### 5. Kiểm tra ĐLTT/PTTT
- Lập ma trận A_S (hàng là các véc tơ) → bán chuẩn hóa cột
- rank = số véc tơ → ĐLTT
- rank < số véc tơ → PTTT

### 6. Tìm tọa độ [α]_S
- S = {α₁, ..., αₙ} cơ sở
- Giải hệ c₁α₁ + ... + cₙαₙ = α
- **Nếu S trực chuẩn:** cᵢ = ⟨α, αᵢ⟩ (không cần giải hệ!)

### 7. Tìm lũy thừa Aᵐ
- Chéo hóa A = PDP⁻¹
- Aᵐ = PDᵐP⁻¹, với Dᵐ = diag(λ₁ᵐ, ..., λₙᵐ)

---

## 11. Các công thức đặc biệt hay dùng

### Nhân ma trận khối (Block matrix)
```
[ A  B ] [ E  F ] = [ AE+BG  AF+BH ]
[ C  D ] [ G  H ]   [ CE+DG  CF+DH ]
```

### Phép Kronecker (tích tensor)
Không thường dùng nhưng biết đến.

### Sherman-Morrison (nghịch đảo rank-1 update)
```
(A + uvᵀ)⁻¹ = A⁻¹ − (A⁻¹uvᵀA⁻¹) / (1 + vᵀA⁻¹u)
```

### Woodbury (nghịch đảo rank-k update)
```
(A + UCV)⁻¹ = A⁻¹ − A⁻¹U(C⁻¹ + VA⁻¹U)⁻¹VA⁻¹
```

---

## 12. Ký hiệu thông dụng

| Ký hiệu | Nghĩa |
|---|---|
| ℝ | Tập số thực |
| ℂ | Tập số phức |
| ℝⁿ | Không gian véc tơ cỡ n |
| Mₙ(ℝ) | Ma trận vuông cấp n trên ℝ |
| det(A) / \|A\| | Định thức |
| rank(A) / r(A) | Hạng |
| Aᵀ | Chuyển vị |
| A⁻¹ | Nghịch đảo |
| tr(A) | Dấu vết (trace) = Σ Aᵢᵢ |
| Ker(A) | Không gian nhân (nullspace) |
| Im(A) | Không gian giá trị (column space) |
| ⟨α, β⟩ | Tích vô hướng |
| ‖α‖ | Chuẩn (độ dài) |
| α ⊥ β | Vuông góc |
| E_λ | Không gian riêng λ |
| p_A(x) | Đa thức đặc trưng |
| A ∼ B | Tương đồng (similar) |
| A ≅ B | Phù hợp (congruent) |

---

## 13. Mẹo tránh lỗi thường gặp

| Lỗi thường gặp | Cách khắc phục |
|---|---|
| Quên đổi dấu khi chuyển vế | Luôn viết rõ: "Chuyển vế: ... ⇒ ..." |
| Nhân ma trận sai thứ tự | Vẽ mũi tên: hàng × cột; AB ≠ BA |
| Tính det sai dấu (Sarrus) | Viết rõ 6 tích: +aei +bfg +cdh −ceg −bdi −afh |
| Quên kiểm tra det ≠ 0 trước khi tìm A⁻¹ | Luôn tính det trước |
| Nhầm rank(A) với rank(A\|B) | Viết rõ: A = ma trận hệ số, Ā = ma trận mở rộng |
| Không kiểm tra điều kiện chéo hóa | Luôn so sánh dim E_λ với số mũ r_λ |
| Quên chuẩn hóa khi làm Gram-Schmidt | Bước 2: γᵢ = βᵢ/‖βᵢ‖ |
| Sai công thức tọa độ cơ sở trực chuẩn | cᵢ = ⟨α, γᵢ⟩ (chỉ đúng khi cơ sở ĐÃ trực chuẩn) |
| Quên nghiệm tầm thường khi biện luận hệ thuần nhất | Luôn nhắc: "Hệ luôn có nghiệm (0,...,0)" |

---

## 14. Quy trình chuẩn cho các bài toán điển hình

### Bài toán: "Tìm cơ sở và số chiều của W = {X | AX = 0}"
1. Viết ma trận A
2. Biến đổi sơ cấp hàng → dạng bậc thang
3. Xác định cột pivot / cột tự do
4. Đặt tham số cho các ẩn tự do
5. Viết nghiệm dưới dạng tổ hợp tuyến tính
6. Các véc tơ hệ số là hệ sinh → kiểm tra ĐLTT → cơ sở
7. Số chiều = số ẩn tự do = n − rank(A)

### Bài toán: "Chéo hóa ma trận A"
1. Tính p_A(x) = det(xI − A)
2. Giải p_A(x) = 0 → λᵢ, số mũ rᵢ
3. Với mỗi λᵢ: lập A − λᵢI, giải (A − λᵢI)X = 0 → cơ sở E_λᵢ
4. Tính dim E_λᵢ, so sánh với rᵢ
5. Nếu dim = rᵢ ∀i: gom các cơ sở → P, tính P⁻¹, D = P⁻¹AP
6. Nếu cần Aᵐ: Aᵐ = PDᵐP⁻¹

### Bài toán: "Trực chuẩn hóa tập S bằng Gram-Schmidt"
1. β₁ = α₁
2. Với i = 2..m:
   βᵢ = αᵢ − Σ_{j=1}^{i−1} (⟨αᵢ, βⱼ⟩ / ‖βⱼ‖²) βⱼ
3. γᵢ = βᵢ / ‖βᵢ‖  (i = 1..m)
4. Kết quả: {γ₁, ..., γₘ} trực chuẩn

---

## 15. Các giá trị, công thức cần nhớ thuộc

```
det(I) = 1
det(Aᵀ) = det(A)
det(AB) = det(A)det(B)
det(A⁻¹) = 1/det(A)
det(cA) = cⁿ det(A)
rank(A) = rank(Aᵀ)
rank(AB) ≤ min(rank(A), rank(B))
dim Ker(A) + rank(A) = n    (Định lý rank-nullity)
trace(A) = Σ trị riêng
det(A) = Π trị riêng
(A⁻¹)ᵀ = (Aᵀ)⁻¹
(AB)⁻¹ = B⁻¹A⁻¹
(Aᵏ)⁻¹ = (A⁻¹)ᵏ
```

---

*File này được cập nhật liên tục khi học thêm kiến thức mới.*