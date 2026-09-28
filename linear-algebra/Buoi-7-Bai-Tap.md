# 1. MA TRẬN CHUYỂN CƠ SỞ VÀ ĐỔI TỌA ĐỘ

## Bài 3.28. Trong $U = \mathbb{R}^3$, cho $T_{a \to b} = \begin{pmatrix} 1 & 2 & -4 \\ 2 & 5 & 3 \\ 3 & 2 & 1 \end{pmatrix}$ và $[x]_a = \begin{pmatrix} 1 \\ 4 \\ -2 \end{pmatrix}$. Tìm $[x]_b$.

Áp dụng công thức đổi tọa độ: $[x]_a = T_{a \to b} \cdot [x]_b \implies [x]_b = (T_{a \to b})^{-1} \cdot [x]_a$

1. Tính $\det(T) = 1(5-6) - 2(2-9) - 4(4-15) = -1 + 14 + 44 = 57 \neq 0$
2. Ma trận nghịch đảo $T^{-1}$:
$$T^{-1} = \frac{1}{57} \begin{pmatrix} -1 & -10 & 26 \\ 7 & 13 & -11 \\ -11 & 4 & 1 \end{pmatrix}$$
3. Tìm $[x]_b$:
$$[x]_b = \frac{1}{57} \begin{pmatrix} -1 & -10 & 26 \\ 7 & 13 & -11 \\ -11 & 4 & 1 \end{pmatrix} \begin{pmatrix} 1 \\ 4 \\ -2 \end{pmatrix} = \frac{1}{57} \begin{pmatrix} -93 \\ 81 \\ 3 \end{pmatrix} = \begin{pmatrix} -\frac{31}{19} \\ \frac{27}{19} \\ \frac{1}{19} \end{pmatrix}$$

## Bài 3.30. Cho $(a) = \{a_1, a_2, a_3\}$ và $b_1 = 2a_1 + 3a_2 - a_3, b_2 = a_1 + 4a_2 + 2a_3, b_3 = 3a_1 - a_2 + a_3$. Tìm $T_{b \to a}$

1. Ma trận chuyển cơ sở từ $(a)$ sang $(b)$:
$$T_{a \to b} = \begin{pmatrix} [b_1]_a & [b_2]_a & [b_3]_a \end{pmatrix} = \begin{pmatrix} 2 & 1 & 3 \\ 3 & 4 & -1 \\ -1 & 2 & 1 \end{pmatrix}$$
2. Ma trận chuyển cơ sở từ $(b)$ sang $(a)$ là $T_{b \to a} = (T_{a \to b})^{-1}$:
$$\det(T_{a \to b}) = 2(6) - 1(2) + 3(10) = 40$$
$$T_{b \to a} = \frac{1}{40} \begin{pmatrix} 6 & 5 & -13 \\ -2 & 5 & 11 \\ 10 & -5 & 5 \end{pmatrix}$$

## Bài 3.32. Cho $T_{c \to a} = \begin{pmatrix} 2 & -1 & 1 \\ 2 & 1 & 2 \\ 3 & 1 & 4 \end{pmatrix}$ và $T_{c \to b} = \begin{pmatrix} 1 & 1 & 1 \\ -2 & 3 & 1 \\ 2 & 1 & -2 \end{pmatrix}$. Tìm $T_{a \to b}$

1. Áp dụng tính chất: $T_{c \to b} = T_{c \to a} \cdot T_{a \to b} \implies T_{a \to b} = (T_{c \to a})^{-1} \cdot T_{c \to b}$
2. Tính $(T_{c \to a})^{-1}$:
$$\det(T_{c \to a}) = 2(2) - (-1)(2) + 1(-1) = 5$$
$$(T_{c \to a})^{-1} = \frac{1}{5} \begin{pmatrix} 2 & 5 & -3 \\ -2 & 5 & -2 \\ -1 & -5 & 4 \end{pmatrix}$$
3. Tính $T_{a \to b}$:
$$T_{a \to b} = \frac{1}{5} \begin{pmatrix} 2 & 5 & -3 \\ -2 & 5 & -2 \\ -1 & -5 & 4 \end{pmatrix} \begin{pmatrix} 1 & 1 & 1 \\ -2 & 3 & 1 \\ 2 & 1 & -2 \end{pmatrix} = \frac{1}{5} \begin{pmatrix} -14 & 14 & 13 \\ -16 & 11 & 7 \\ 17 & -12 & -14 \end{pmatrix}$$

### Bài 3.33. Trong $\mathbb{R}^3$, cho $a_1=(3,1,1), a_2=(5,-4,2), a_3=(2,1,1)$ và $b_1=(3,-2,3), b_2=(4,1,-2), b_3=(3,4,2)$. Tìm $T_{b \to a}$.

1. Lập các ma trận chuyển từ cơ sở chính tắc $\beta_0$:
$$T_{\beta_0 \to a} = \begin{pmatrix} 3 & 5 & 2 \\ 1 & -4 & 1 \\ 1 & 2 & 1 \end{pmatrix}, \quad T_{\beta_0 \to b} = \begin{pmatrix} 3 & 4 & 3 \\ -2 & 1 & 4 \\ 3 & -2 & 2 \end{pmatrix}$$
2. Ma trận chuyển cơ sở $T_{b \to a} = (T_{\beta_0 \to b})^{-1} \cdot T_{\beta_0 \to a}$:
$$\det(T_{\beta_0 \to b}) = 3(10) - 4(-16) + 3(1) = 97$$
$$(T_{\beta_0 \to b})^{-1} = \frac{1}{97} \begin{pmatrix} 10 & -14 & 13 \\ 16 & -3 & -18 \\ 1 & 18 & 11 \end{pmatrix}$$
$$T_{b \to a} = \frac{1}{97} \begin{pmatrix} 10 & -14 & 13 \\ 16 & -3 & -18 \\ 1 & 18 & 11 \end{pmatrix} \begin{pmatrix} 3 & 5 & 2 \\ 1 & -4 & 1 \\ 1 & 2 & 1 \end{pmatrix} = \frac{1}{97} \begin{pmatrix} 29 & 132 & 19 \\ 27 & 56 & 11 \\ 32 & -45 & 31 \end{pmatrix}$$

---

# 2. TRỊ RIÊNG VÀ ĐA THỨC ĐẶC TRƯNG

## Bài 1: $A = \begin{pmatrix} 4 & 2 \\ -11 & -5 \end{pmatrix}$
* **a/ $c = -5$ có là trị riêng?**
  $$\det(A - (-5)I_2) = \det\begin{pmatrix} 9 & 2 \\ -11 & 0 \end{pmatrix} = 22 \neq 0 \implies c = -5 \text{ không là trị riêng.}$$
* **b/ $c = -7$ có là trị riêng?**
  $$\det(A - (-7)I_2) = \det\begin{pmatrix} 11 & 2 \\ -11 & 2 \end{pmatrix} = 44 \neq 0 \implies c = -7 \text{ không là trị riêng.}$$
* **c/ Đa thức đặc trưng & trị riêng:**
  $$p_A(\lambda) = \det(A - \lambda I_2) = (4-\lambda)(-5-\lambda) + 22 = \lambda^2 + \lambda + 2$$
  Phương trình $\lambda^2 + \lambda + 2 = 0$ vô nghiệm trên $\mathbb{R} \implies A$ không có trị riêng thực.

## Bài 2: $A = \begin{pmatrix} 8 & 2 \\ 4 & 2 \end{pmatrix}$
* **a/ $c = 0$ có là trị riêng?**
  $$\det(A - 0I_2) = \det(A) = 16 - 8 = 8 \neq 0 \implies c = 0 \text{ không là trị riêng.}$$
* **b/ $c = 6$ có là trị riêng?**
  $$\det(A - 6I_2) = \det\begin{pmatrix} 2 & 2 \\ 4 & -4 \end{pmatrix} = -16 \neq 0 \implies c = 6 \text{ không là trị riêng.}$$
* **c/ Đa thức đặc trưng & trị riêng:**
  $$p_A(\lambda) = \det\begin{pmatrix} 8-\lambda & 2 \\ 4 & 2-\lambda \end{pmatrix} = \lambda^2 - 10\lambda + 8 = 0 \implies \lambda = 5 \pm \sqrt{17}$$

## Bài 3: $A = \begin{pmatrix} 5 & 6 & -3 \\ -1 & 0 & 1 \\ 1 & 2 & 1 \end{pmatrix}$
* **a/ $c = -3$ có là trị riêng?**
  $$\det(A - (-3)I_3) = \det\begin{pmatrix} 8 & 6 & -3 \\ -1 & 3 & 1 \\ 1 & 2 & 4 \end{pmatrix} = 8(10) - 6(-5) - 3(-5) = 125 \neq 0 \implies \text{Không.}$$
* **b/ $c = 2$ có là trị riêng?**
  $$\det(A - 2I_3) = \det\begin{pmatrix} 3 & 6 & -3 \\ -1 & -2 & 1 \\ 1 & 2 & -1 \end{pmatrix} = 0 \implies c = 2 \text{ là trị riêng.}$$
* **c/ Đa thức đặc trưng & trị riêng:**
  $$p_A(\lambda) = \det(A - \lambda I_3) = -(\lambda - 1)(\lambda - 2) + \dots = -\lambda^3 + 6\lambda^2 - 12\lambda + 8 = -(\lambda - 2)^3$$
  $$p_A(\lambda) = 0 \implies \lambda = 2 \text{ (bội 3)}$$

## Bài 4: $A = \begin{pmatrix} 7 & -6 & -10 \\ -12 & 17 & 24 \\ 12 & -15 & -22 \end{pmatrix}$
* **a/ $c = 0$ có là trị riêng?**
  $$\det(A) = 2 \neq 0 \implies c = 0 \text{ không là trị riêng.}$$
* **b/ $c = -1$ có là trị riêng?**
  $$\det(A - (-1)I_3) = \det\begin{pmatrix} 8 & -6 & -10 \\ -12 & 18 & 24 \\ 12 & -15 & -21 \end{pmatrix} = 0 \implies c = -1 \text{ là trị riêng.}$$
* **c/ Đa thức đặc trưng & trị riêng:**
  $$p_A(\lambda) = -\lambda^3 + 2\lambda^2 + \lambda - 2 = 0 \implies \lambda_1 = 1, \lambda_2 = -1, \lambda_3 = 2$$

# 3. CHÉO HÓA MA TRẬN VÀ TÍNH $A^m$

## Bài a: $A = \begin{pmatrix} 4 & 2 \\ -4 & -3 \end{pmatrix}$

**Bước 1: Tìm đa thức đặc trưng và trị riêng của $A$**

Đa thức đặc trưng của $A$:


$$p_A(\lambda) = \det(A - \lambda I_2) = \det \begin{pmatrix} -4 - \lambda & -2 \\ -4 & 3 - \lambda \end{pmatrix}$$

$$= (-4 - \lambda)(3 - \lambda) - (-2)(-4) = \lambda^2 + \lambda - 12 - 8 = \lambda^2 + \lambda - 20$$

Giải phương trình đặc trưng:


$$p_A(\lambda) = 0 \iff \lambda^2 + \lambda - 20 = 0 \iff (\lambda - 4)(\lambda + 5) = 0 \iff \begin{cases} \lambda_1 = 4 \\ \lambda_2 = -5 \end{cases}$$

Ma trận $A$ có 2 trị riêng phân biệt $\lambda_1 = 4, \lambda_2 = -5$ ($r_1 = 1, r_2 = 1$), nên $A$ chéo hóa được trên $\mathbb{R}$.

---

**Bước 2: Tìm cơ sở cho các không gian riêng**

* **Với $\lambda_1 = 4$:** Giải hệ phương trình thuần nhất $(A - 4I_2)X = O$

$$\begin{pmatrix} -8 & -2 \\ -4 & -1 \end{pmatrix} \begin{pmatrix} x_1 \\ x_2 \end{pmatrix} = \begin{pmatrix} 0 \\ 0 \end{pmatrix} \iff 4x_1 + x_2 = 0 \iff x_2 = -4x_1$$



Chọn $x_1 = 1 \implies x_2 = -4$. Ta được vectơ riêng $u_1 = \begin{pmatrix} 1 \\ -4 \end{pmatrix}$.
* **Với $\lambda_2 = -5$:** Giải hệ phương trình thuần nhất $(A - (-5)I_2)X = O \iff (A + 5I_2)X = O$

$$\begin{pmatrix} 1 & -2 \\ -4 & 8 \end{pmatrix} \begin{pmatrix} x_1 \\ x_2 \end{pmatrix} = \begin{pmatrix} 0 \\ 0 \end{pmatrix} \iff x_1 - 2x_2 = 0 \iff x_1 = 2x_2$$



Chọn $x_2 = 1 \implies x_1 = 2$. Ta được vectơ riêng $u_2 = \begin{pmatrix} 2 \\ 1 \end{pmatrix}$.

---

**Bước 3: Lập ma trận làm chéo hóa $T$ và dạng chéo $D$**

Đặt $T = (u_1 \quad u_2) = \begin{pmatrix} 1 & 2 \\ -4 & 1 \end{pmatrix}$.

Tính $\det(T) = 1\cdot 1 - 2\cdot(-4) = 9 \neq 0 \implies T$ khả nghịch.
Ma trận nghịch đảo:


$$T^{-1} = \frac{1}{9} \begin{pmatrix} 1 & -2 \\ 4 & 1 \end{pmatrix}$$

Dạng chéo của $A$:


$$D = T^{-1} A T = \begin{pmatrix} 4 & 0 \\ 0 & -5 \end{pmatrix}$$

---

**Bước 4: Tính $A^m$ $(\forall m \in \mathbb{N})$**

Ta có $A = T D T^{-1} \implies A^m = T D^m T^{-1}$:

$$A^m = \begin{pmatrix} 1 & 2 \\ -4 & 1 \end{pmatrix} \begin{pmatrix} 4^m & 0 \\ 0 & (-5)^m \end{pmatrix} \left[ \frac{1}{9} \begin{pmatrix} 1 & -2 \\ 4 & 1 \end{pmatrix} \right]$$

$$= \frac{1}{9} \begin{pmatrix} 4^m & 2 \cdot (-5)^m \\ -4 \cdot 4^m & (-5)^m \end{pmatrix} \begin{pmatrix} 1 & -2 \\ 4 & 1 \end{pmatrix}$$

$$= \frac{1}{9} \begin{pmatrix} 4^m + 8 \cdot (-5)^m & -2 \cdot 4^m + 2 \cdot (-5)^m \\ -4 \cdot 4^m + 4 \cdot (-5)^m & 8 \cdot 4^m + (-5)^m \end{pmatrix}$$

## Bài b: $A = \begin{pmatrix} -5 & -3 \\ -3 & 3 \end{pmatrix}$
1. Đa thức đặc trưng: $p_A(\lambda) = \lambda^2 + 2\lambda - 24 = 0 \implies \lambda_1 = 4, \lambda_2 = -6$
2. Vectơ riêng:
   * Với $\lambda_1 = 4$: $(A - 4I)X = O \implies -9x_1 - 3x_2 = 0 \implies u_1 = (1, -3)^T$
   * Với $\lambda_2 = -6$: $(A + 6I)X = O \implies x_1 - 3x_2 = 0 \implies u_2 = (3, 1)^T$
3. Ma trận $T = \begin{pmatrix} 1 & 3 \\ -3 & 1 \end{pmatrix} \implies T^{-1} = \frac{1}{10} \begin{pmatrix} 1 & -3 \\ 3 & 1 \end{pmatrix}$
4. Kết quả lũy thừa:
$$A^m = T \begin{pmatrix} 4^m & 0 \\ 0 & (-6)^m \end{pmatrix} T^{-1} = \frac{1}{10} \begin{pmatrix} 4^m + 9(-6)^m & -3\cdot 4^m + 3(-6)^m \\ -3\cdot 4^m + 3(-6)^m & 9\cdot 4^m + (-6)^m \end{pmatrix}$$

## Bài c: $A = \begin{pmatrix} 1 & 0 & 1 \\ 0 & 1 & 0 \\ 1 & 0 & 1 \end{pmatrix}$
1. Trị riêng: $\det(A - \lambda I_3) = (1-\lambda)[(1-\lambda)^2 - 1] = 0 \implies \lambda_1 = 1, \lambda_2 = 0, \lambda_3 = 2$
2. Vectơ riêng: $u_1 = (0, 1, 0)^T, u_2 = (-1, 0, 1)^T, u_3 = (1, 0, 1)^T$
3. Ma trận $T = \begin{pmatrix} 0 & -1 & 1 \\ 1 & 0 & 0 \\ 0 & 1 & 1 \end{pmatrix} \implies T^{-1} = \begin{pmatrix} 0 & 1 & 0 \\ -1/2 & 0 & 1/2 \\ 1/2 & 0 & 1/2 \end{pmatrix}$
4. Lũy thừa $A^m$ (với $m \ge 1$):
$$A^m = T \begin{pmatrix} 1 & 0 & 0 \\ 0 & 0 & 0 \\ 0 & 0 & 2^m \end{pmatrix} T^{-1} = \begin{pmatrix} 2^{m-1} & 0 & 2^{m-1} \\ 0 & 1 & 0 \\ 2^{m-1} & 0 & 2^{m-1} \end{pmatrix}$$

## Bài d: $A = \begin{pmatrix} 7 & -6 & -10 \\ -12 & 17 & 24 \\ 12 & -15 & -22 \end{pmatrix}$
1. Trị riêng: $\lambda_1 = 1, \lambda_2 = -1, \lambda_3 = 2$
2. Vectơ riêng: $u_1 = (1, 1, 0)^T, u_2 = (-1, 3, -2)^T, u_3 = (-2, 5, -4)^T$
3. Ma trận $T = \begin{pmatrix} 1 & -1 & -2 \\ 1 & 3 & 5 \\ 0 & -2 & -4 \end{pmatrix} \implies T^{-1} = \begin{pmatrix} 1 & 0 & -1/2 \\ -2 & 2 & 7/2 \\ 1 & -1 & -2 \end{pmatrix}$
4. Kết quả: $A^m = T \text{diag}(1^m, (-1)^m, 2^m) T^{-1}$

## Bài e: $A = \begin{pmatrix} 8 & -1 & -5 \\ -2 & 3 & 1 \\ 4 & -1 & -1 \end{pmatrix}$
1. Trị riêng: $p_A(\lambda) = -(\lambda - 2)^2 (\lambda - 6) = 0 \implies \lambda_1 = 2 \text{ (bội 2)}, \lambda_2 = 6$
2. Không gian riêng ứng với $\lambda_1 = 2$:
   $$(A - 2I)X = O \implies \begin{pmatrix} 6 & -1 & -5 \\ -2 & 1 & 1 \\ 4 & -1 & -3 \end{pmatrix} X = O \implies \dim E_2 = 1 < 2$$
3. **Kết luận:** Ma trận $A$ **không chéo hóa được** trên $\mathbb{R}$.

## Bài f: $A = \begin{pmatrix} 5 & 6 & -3 \\ -1 & 0 & 1 \\ 1 & 2 & 1 \end{pmatrix}$
1. Trị riêng: $\lambda = 2$ (bội 3)
2. Xét $(A - 2I)X = O \implies \begin{pmatrix} 3 & 6 & -3 \\ -1 & -2 & 1 \\ 1 & 2 & -1 \end{pmatrix} X = O \implies \dim E_2 = 2 < 3$
3. **Kết luận:** Ma trận $A$ **không chéo hóa được** trên $\mathbb{R}$.

## Bài g: $A = \begin{pmatrix} -1 & 3 & -1 \\ -3 & 5 & -1 \\ -3 & 3 & 1 \end{pmatrix}$
1. Trị riêng: $\lambda_1 = 1, \lambda_2 = 2$ (bội 2)
2. Với $\lambda_2 = 2$:
   $$(A - 2I)X = O \implies \begin{pmatrix} -3 & 3 & -1 \\ -3 & 3 & -1 \\ -3 & 3 & -1 \end{pmatrix} X = O \implies \dim E_2 = 2 = r_2$$
3. Vectơ riêng: $u_1 = (1, 1, 1)^T, u_2 = (1, 1, 0)^T, u_3 = (-1, 0, 3)^T$
4. Ma trận $T = \begin{pmatrix} 1 & 1 & -1 \\ 1 & 1 & 0 \\ 1 & 0 & 3 \end{pmatrix}$, $D = \begin{pmatrix} 1 & 0 & 0 \\ 0 & 2 & 0 \\ 0 & 0 & 2 \end{pmatrix} \implies A^m = T D^m T^{-1}$

## Bài h: $A = \begin{pmatrix} 7 & -12 & -2 \\ 3 & -4 & 0 \\ -2 & 0 & -2 \end{pmatrix}$
1. Trị riêng: $\lambda_1 = -2, \lambda_2 = 1, \lambda_3 = 2$
2. Vectơ riêng tương ứng: $u_1 = (2, 1, 3)^T, u_2 = (2, 1, 0)^T, u_3 = (4, 1, -2)^T$
3. Đặt $T = \begin{pmatrix} 2 & 2 & 4 \\ 1 & 1 & 1 \\ 3 & 0 & -2 \end{pmatrix}$, $D = \begin{pmatrix} -2 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 2 \end{pmatrix} \implies A^m = T D^m T^{-1}$

### Bài i: $A = \begin{pmatrix} 2 & -1 & -1 \\ -1 & 2 & -1 \\ -1 & -1 & 2 \end{pmatrix}$
1. Trị riêng: $\lambda_1 = 0, \lambda_2 = 3$ (bội 2)
2. Vì $A$ là ma trận thực đối xứng nên $A$ luôn chéo hóa được:
   * $\lambda_1 = 0 \implies u_1 = (1, 1, 1)^T$
   * $\lambda_2 = 3 \implies u_2 = (-1, 1, 0)^T, u_3 = (-1, 0, 1)^T$
3. Ma trận $T = \begin{pmatrix} 1 & -1 & -1 \\ 1 & 1 & 0 \\ 1 & 0 & 1 \end{pmatrix} \implies T^{-1} = \frac{1}{3} \begin{pmatrix} 1 & 1 & 1 \\ -1 & 2 & -1 \\ -1 & -1 & 2 \end{pmatrix}$
4. Lũy thừa $A^m$:
$$A^m = T \begin{pmatrix} 0 & 0 & 0 \\ 0 & 3^m & 0 \\ 0 & 0 & 3^m \end{pmatrix} T^{-1} = \frac{3^m}{3} \begin{pmatrix} 2 & -1 & -1 \\ -1 & 2 & -1 \\ -1 & -1 & 2 \end{pmatrix} = 3^{m-1} A$$

## Bài j: $A = \begin{pmatrix} 3 & 2 & 0 \\ 2 & 4 & -2 \\ 0 & -2 & 5 \end{pmatrix}$
1. Trị riêng: $p_A(\lambda) = -\lambda^3 + 12\lambda^2 - 39\lambda + 28 = 0 \implies \lambda_1 = 1, \lambda_2 = 4, \lambda_3 = 7$
2. Vectơ riêng:
   * $\lambda_1 = 1 \implies u_1 = (-2, 2, 1)^T$
   * $\lambda_2 = 4 \implies u_2 = (-2, -1, 2)^T$
   * $\lambda_3 = 7 \implies u_3 = (1, 2, -2)^T$
3. Ma trận $T = \begin{pmatrix} -2 & -2 & 1 \\ 2 & -1 & 2 \\ 1 & 2 & -2 \end{pmatrix} \implies T^{-1} = \frac{1}{9} \begin{pmatrix} -2 & 2 & 1 \\ -2 & -1 & 2 \\ 1 & 2 & -2 \end{pmatrix}$
4. Lũy thừa $A^m$:
$$A^m = T \begin{pmatrix} 1^m & 0 & 0 \\ 0 & 4^m & 0 \\ 0 & 0 & 7^m \end{pmatrix} T^{-1}$$