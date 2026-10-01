# BÀI TẬP BUỔI 8 – ĐẠI SỐ TUYẾN TÍNH

> Chương 5: không gian Euclide, tích vô hướng và trực chuẩn hóa.

---

## 1. Kiểm tra ánh xạ có phải là tích vô hướng hay không

Kiểm tra xem ánh xạ $\varphi(\alpha, \beta) = \langle \alpha \vert{} \beta \rangle$ có phải là một tích vô hướng trên không gian $V$ hay không? Vì sao?

### **Bài 1a**
* **Đề bài:** $V = \mathbb{R}^2$ và $\varphi(\alpha,\beta) = \langle \begin{pmatrix} x_1 \\ x_2 \end{pmatrix} \Big\vert{} \begin{pmatrix} y_1 \\ y_2 \end{pmatrix} \rangle = 5x_1 y_1 + 8x_2 y_2$
* **Lời giải:**

Ta chứng minh $\langle \alpha \vert{} \beta \rangle$ là một tích vô hướng trên $\mathbb{R}^2$ bằng cách kiểm tra 3 tính chất:

**i/** Với mọi $\alpha = \begin{pmatrix} x_1 \\ x_2 \end{pmatrix} \in \mathbb{R}^2$:
$$\langle \alpha \vert{} \alpha \rangle = 5x_1^2 + 8x_2^2$$
Vì $x_1^2 \ge 0$ và $x_2^2 \ge 0$ nên $5x_1^2 + 8x_2^2 \ge 0, \forall \alpha \in \mathbb{R}^2$.  
Mặt khác: $\langle \alpha \vert{} \alpha \rangle = 0 \Leftrightarrow 5x_1^2 + 8x_2^2 = 0 \Leftrightarrow x_1 = 0 \text{ và } x_2 = 0 \Leftrightarrow \alpha = 0$.

**ii/** Với mọi $\alpha = \begin{pmatrix} x_1 \\ x_2 \end{pmatrix}, \beta = \begin{pmatrix} y_1 \\ y_2 \end{pmatrix} \in \mathbb{R}^2$:
$$\langle \alpha \vert{} \beta \rangle = 5x_1 y_1 + 8x_2 y_2 = 5y_1 x_1 + 8y_2 x_2 = \langle \beta \vert{} \alpha \rangle$$

**iii/** Với mọi $c \in \mathbb{R}, \alpha_1 = \begin{pmatrix} x_1 \\ x_2 \end{pmatrix}, \alpha_2 = \begin{pmatrix} y_1 \\ y_2 \end{pmatrix}, \beta = \begin{pmatrix} z_1 \\ z_2 \end{pmatrix} \in \mathbb{R}^2$:
$$c\alpha_1 + \alpha_2 = \begin{pmatrix} cx_1 + y_1 \\ cx_2 + y_2 \end{pmatrix}$$
$$\begin{aligned} \langle c\alpha_1 + \alpha_2 \vert{} \beta \rangle &= 5(cx_1 + y_1)z_1 + 8(cx_2 + y_2)z_2 \\ &= 5cx_1 z_1 + 5y_1 z_1 + 8cx_2 z_2 + 8y_2 z_2 \\ &= c(5x_1 z_1 + 8x_2 z_2) + (5y_1 z_1 + 8y_2 z_2) \\ &= c\langle \alpha_1 \vert{} \beta \rangle + \langle \alpha_2 \vert{} \beta \rangle \end{aligned}$$

**Kết luận:** $\langle \alpha \vert{} \beta \rangle$ **là một tích vô hướng** trên $\mathbb{R}^2$.

---

### **Bài 1b**
* **Đề bài:** $V = \mathbb{R}^2$ và $\varphi(\alpha,\beta) = \langle \begin{pmatrix} x_1 \\ x_2 \end{pmatrix} \Big\vert{} \begin{pmatrix} y_1 \\ y_2 \end{pmatrix} \rangle = 6x_1 y_2 - 9x_2 y_1 + 2x_1^2$
* **Lời giải:**

Ta chứng tỏ $\langle \alpha \vert{} \beta \rangle$ **không phải** là tích vô hướng bằng cách chỉ ra tính chất đối xứng (ii/) bị vi phạm.

Chọn $\alpha = \begin{pmatrix} 1 \\ 0 \end{pmatrix}, \beta = \begin{pmatrix} 0 \\ 1 \end{pmatrix}$.  
* $\langle \alpha \vert{} \beta \rangle = \langle \begin{pmatrix} 1 \\ 0 \end{pmatrix} \Big\vert{} \begin{pmatrix} 0 \\ 1 \end{pmatrix} \rangle = 6(1)(1) - 9(0)(0) + 2(1)^2 = 6 + 2 = 8$
* $\langle \beta \vert{} \alpha \rangle = \langle \begin{pmatrix} 0 \\ 1 \end{pmatrix} \Big\vert{} \begin{pmatrix} 1 \\ 0 \end{pmatrix} \rangle = 6(0)(0) - 9(1)(1) + 2(0)^2 = -9$

Vì $\langle \alpha \vert{} \beta \rangle \neq \langle \beta \vert{} \alpha \rangle$ ($8 \neq -9$) nên tính chất đối xứng bị vi phạm.

**Kết luận:** $\langle \alpha \vert{} \beta \rangle$ **không phải là tích vô hướng** trên $\mathbb{R}^2$.

---

### **Bài 1c**
* **Đề bài:** $V = \mathbb{R}^3$, $\langle \alpha \vert{} \beta \rangle = \langle \begin{pmatrix} x_1 \\ x_2 \\ x_3 \end{pmatrix} \Big\vert{} \begin{pmatrix} y_1 \\ y_2 \\ y_3 \end{pmatrix} \rangle = x_1 y_1 + 2x_1 y_2 + 3x_3 y_3 + 2x_2 y_1 + 12x_2 y_2$
* **Lời giải:**

Ta chứng minh $\langle \alpha \vert{} \beta \rangle$ là một tích vô hướng trên $\mathbb{R}^3$ bằng cách kiểm tra 3 tính chất:

**i/** Với mọi $\alpha = \begin{pmatrix} x_1 \\ x_2 \\ x_3 \end{pmatrix} \in \mathbb{R}^3$:
$$\langle \alpha \vert{} \alpha \rangle = x_1^2 + 2x_1 x_2 + 2x_2 x_1 + 12x_2^2 + 3x_3^2 = (x_1 + 2x_2)^2 + 8x_2^2 + 3x_3^2$$
Vì $(x_1 + 2x_2)^2 \ge 0$, $8x_2^2 \ge 0$, $3x_3^2 \ge 0$ nên $\langle \alpha \vert{} \alpha \rangle \ge 0, \forall \alpha \in \mathbb{R}^3$.  
Mặt khác: $\langle \alpha \vert{} \alpha \rangle = 0 \Leftrightarrow (x_1 + 2x_2)^2 + 8x_2^2 + 3x_3^2 = 0 \Leftrightarrow x_2 = 0,\ x_3 = 0,\ x_1 + 2x_2 = 0 \Leftrightarrow x_1 = x_2 = x_3 = 0 \Leftrightarrow \alpha = 0$.

**ii/** Với mọi $\alpha = \begin{pmatrix} x_1 \\ x_2 \\ x_3 \end{pmatrix}, \beta = \begin{pmatrix} y_1 \\ y_2 \\ y_3 \end{pmatrix} \in \mathbb{R}^3$:
$$\langle \alpha \vert{} \beta \rangle = x_1 y_1 + 2x_1 y_2 + 2x_2 y_1 + 12x_2 y_2 + 3x_3 y_3$$
$$\langle \beta \vert{} \alpha \rangle = y_1 x_1 + 2y_1 x_2 + 2y_2 x_1 + 12y_2 x_2 + 3y_3 x_3 = \langle \alpha \vert{} \beta \rangle$$

**iii/** Với mọi $c \in \mathbb{R}, \alpha_1 = \begin{pmatrix} x_1 \\ x_2 \\ x_3 \end{pmatrix}, \alpha_2 = \begin{pmatrix} z_1 \\ z_2 \\ z_3 \end{pmatrix}, \beta = \begin{pmatrix} y_1 \\ y_2 \\ y_3 \end{pmatrix} \in \mathbb{R}^3$:
$$c\alpha_1 + \alpha_2 = \begin{pmatrix} cx_1 + z_1 \\ cx_2 + z_2 \\ cx_3 + z_3 \end{pmatrix}$$
$$\begin{aligned} \langle c\alpha_1 + \alpha_2 \vert{} \beta \rangle &= (cx_1 + z_1)y_1 + 2(cx_1 + z_1)y_2 + 3(cx_3 + z_3)y_3 + 2(cx_2 + z_2)y_1 + 12(cx_2 + z_2)y_2 \\ &= c(x_1 y_1 + 2x_1 y_2 + 2x_2 y_1 + 12x_2 y_2 + 3x_3 y_3) + (z_1 y_1 + 2z_1 y_2 + 2z_2 y_1 + 12z_2 y_2 + 3z_3 y_3) \\ &= c\langle \alpha_1 \vert{} \beta \rangle + \langle \alpha_2 \vert{} \beta \rangle \end{aligned}$$

**Kết luận:** $\langle \alpha \vert{} \beta \rangle$ **là một tích vô hướng** trên $\mathbb{R}^3$.

---

### **Bài 1d**
* **Đề bài:** $V = \mathbb{R}^3$, $\langle \alpha \vert{} \beta \rangle = \langle \begin{pmatrix} x_1 \\ x_2 \\ x_3 \end{pmatrix} \Big\vert{} \begin{pmatrix} y_1 \\ y_2 \\ y_3 \end{pmatrix} \rangle = 6x_1 y_1 - 5x_2 y_3 + 2x_3 y_1 - 8x_2 y_2$
* **Lời giải:**

Chọn $\alpha = \begin{pmatrix} 0 \\ 1 \\ 0 \end{pmatrix}$.  
$$\langle \alpha \vert{} \alpha \rangle = \langle \begin{pmatrix} 0 \\ 1 \\ 0 \end{pmatrix} \Big\vert{} \begin{pmatrix} 0 \\ 1 \\ 0 \end{pmatrix} \rangle = 6(0)^2 - 5(1)(0) + 2(0)(0) - 8(1)^2 = -8 < 0$$

Do $\langle \alpha \vert{} \alpha \rangle < 0$ nên tính chất i/ bị vi phạm.

**Kết luận:** $\langle \alpha \vert{} \beta \rangle$ **không phải là tích vô hướng** trên $\mathbb{R}^3$.

---

### **Bài 1e**
* **Đề bài:** $V = \mathbb{R}^3$, $\langle \alpha \vert{} \beta \rangle = \langle \begin{pmatrix} x_1 \\ x_2 \\ x_3 \end{pmatrix} \Big\vert{} \begin{pmatrix} y_1 \\ y_2 \\ y_3 \end{pmatrix} \rangle = 4x_1 y_1 - 2x_2 y_3 + 3x_3 y_2 - 7x_1 y_3$
* **Lời giải:**

Ta chứng tỏ $\langle \alpha \vert{} \beta \rangle$ **không phải** là tích vô hướng bằng cách chỉ ra tính chất đối xứng (ii/) bị vi phạm.

Chọn $\alpha = \begin{pmatrix} 0 \\ 1 \\ 0 \end{pmatrix}, \beta = \begin{pmatrix} 0 \\ 0 \\ 1 \end{pmatrix}$.
* $\langle \alpha \vert{} \beta \rangle = \langle \begin{pmatrix} 0 \\ 1 \\ 0 \end{pmatrix} \Big\vert{} \begin{pmatrix} 0 \\ 0 \\ 1 \end{pmatrix} \rangle = 4(0)(0) - 2(1)(1) + 3(0)(0) - 7(0)(1) = -2$
* $\langle \beta \vert{} \alpha \rangle = \langle \begin{pmatrix} 0 \\ 0 \\ 1 \end{pmatrix} \Big\vert{} \begin{pmatrix} 0 \\ 1 \\ 0 \end{pmatrix} \rangle = 4(0)(0) - 2(0)(0) + 3(1)(1) - 7(0)(0) = 3$

Vì $\langle \alpha \vert{} \beta \rangle \neq \langle \beta \vert{} \alpha \rangle$ ($-2 \neq 3$) nên tính chất đối xứng bị vi phạm.

**Kết luận:** $\langle \alpha \vert{} \beta \rangle$ **không phải là tích vô hướng** trên $\mathbb{R}^3$.
## BÀI TẬP 2: ĐỘ DÀI VÉC-TƠ VÀ KHOẢNG CÁCH GIỮA HAI VÉC-TƠ

### **Ví dụ 2**
* **Đề bài:** Trên không gian Euclide $Eu = (V = \mathbb{R}^5, \langle , \rangle)$ với $\langle , \rangle$ là tích vô hướng tiêu chuẩn trên $\mathbb{R}^5$, cho các véc-tơ:
  $$\alpha_1 = (4, 1, -6, 7, 5); \quad \alpha_2 = (2, -3, -1, 4, -5); \quad \alpha_3 = (-7, 2, -2, 9, 3)$$
  Tìm độ dài các véc-tơ $\Vert{}\alpha_1\Vert{}, \Vert{}\alpha_2\Vert{}, \Vert{}\alpha_3\Vert{}$ và khoảng cách $d(\alpha_1, \alpha_2), d(\alpha_2, \alpha_3), d(\alpha_1, \alpha_3)$.

* **Lời giải:**

**1. Tính độ dài các véc-tơ:**
* $\Vert{}\alpha_1\Vert{} = \sqrt{4^2 + 1^2 + (-6)^2 + 7^2 + 5^2} = \sqrt{16 + 1 + 36 + 49 + 25} = \sqrt{127}$
* $\Vert{}\alpha_2\Vert{} = \sqrt{2^2 + (-3)^2 + (-1)^2 + 4^2 + (-5)^2} = \sqrt{4 + 9 + 1 + 16 + 25} = \sqrt{55}$
* $\Vert{}\alpha_3\Vert{} = \sqrt{(-7)^2 + 2^2 + (-2)^2 + 9^2 + 3^2} = \sqrt{49 + 4 + 4 + 81 + 9} = \sqrt{147} = 7\sqrt{3}$

**2. Tính khoảng cách giữa các véc-tơ:**
* $\alpha_1 - \alpha_2 = (4-2, 1-(-3), -6-(-1), 7-4, 5-(-5)) = (2, 4, -5, 3, 10)$  
  $\Rightarrow d(\alpha_1, \alpha_2) = \Vert{}\alpha_1 - \alpha_2\Vert{} = \sqrt{2^2 + 4^2 + (-5)^2 + 3^2 + 10^2} = \sqrt{4 + 16 + 25 + 9 + 100} = \sqrt{154}$

* $\alpha_2 - \alpha_3 = (2-(-7), -3-2, -1-(-2), 4-9, -5-3) = (9, -5, 1, -5, -8)$  
  $\Rightarrow d(\alpha_2, \alpha_3) = \Vert{}\alpha_2 - \alpha_3\Vert{} = \sqrt{9^2 + (-5)^2 + 1^2 + (-5)^2 + (-8)^2} = \sqrt{81 + 25 + 1 + 25 + 64} = \sqrt{196} = 14$

* $\alpha_1 - \alpha_3 = (4-(-7), 1-2, -6-(-2), 7-9, 5-3) = (11, -1, -4, -2, 2)$  
  $\Rightarrow d(\alpha_1, \alpha_3) = \Vert{}\alpha_1 - \alpha_3\Vert{} = \sqrt{11^2 + (-1)^2 + (-4)^2 + (-2)^2 + 2^2} = \sqrt{121 + 1 + 16 + 4 + 4} = \sqrt{146}$

---

## BÀI TẬP 3: TRỰC CHUẨN HÓA BẰNG PHƯƠNG PHÁP GRAM-SCHMIDT

### **Bài tập tương tự 1**
* **Đề bài:** Trên $Eu = (\mathbb{R}^3, \langle , \rangle)$ với tích vô hướng tiêu chuẩn, cho tập hợp $S = \{u_1 = (2, 3, 6); u_2 = (5, -3, 8); u_3 = (8, 5, 3)\}$. Hãy trực chuẩn hóa $S$.
* **Lời giải:**

**Dùng phương pháp Gram-Schmidt để trực giao hóa $S$ thành $S' = \{v_1, v_2, v_3\}$:**
* $v_1 = u_1 = (2, 3, 6)$  
  $\Vert{}v_1\Vert{}^2 = 2^2 + 3^2 + 6^2 = 49$

* $v_2 = u_2 - \frac{\langle u_2, v_1 \rangle}{\Vert{}v_1\Vert{}^2} v_1$  
  $\langle u_2, v_1 \rangle = 5(2) + (-3)(3) + 8(6) = 10 - 9 + 48 = 49$  
  $v_2 = (5, -3, 8) - \frac{49}{49}(2, 3, 6) = (5-2, -3-3, 8-6) = (3, -6, 2)$  
  $\Vert{}v_2\Vert{}^2 = 3^2 + (-6)^2 + 2^2 = 49$

* $v_3 = u_3 - \frac{\langle u_3, v_2 \rangle}{\Vert{}v_2\Vert{}^2} v_2 - \frac{\langle u_3, v_1 \rangle}{\Vert{}v_1\Vert{}^2} v_1$  
  $\langle u_3, v_2 \rangle = 8(3) + 5(-6) + 3(2) = 24 - 30 + 6 = 0$  
  $\langle u_3, v_1 \rangle = 8(2) + 5(3) + 3(6) = 16 + 15 + 18 = 49$  
  $v_3 = (8, 5, 3) - \frac{0}{49}(3, -6, 2) - \frac{49}{49}(2, 3, 6) = (8-2, 5-3, 3-6) = (6, 2, -3)$  
  $\Vert{}v_3\Vert{}^2 = 6^2 + 2^2 + (-3)^2 = 49$

Tập trực giao thu được: $S' = \{v_1 = (2, 3, 6), v_2 = (3, -6, 2), v_3 = (6, 2, -3)\}$.

**Trực chuẩn hóa $S'$ thành $S'' = \{q_1, q_2, q_3\}$:**
* $q_1 = \frac{v_1}{\Vert{}v_1\Vert{}} = \frac{1}{7}(2, 3, 6) = \left(\frac{2}{7}, \frac{3}{7}, \frac{6}{7}\right)$
* $q_2 = \frac{v_2}{\Vert{}v_2\Vert{}} = \frac{1}{7}(3, -6, 2) = \left(\frac{3}{7}, -\frac{6}{7}, \frac{2}{7}\right)$
* $q_3 = \frac{v_3}{\Vert{}v_3\Vert{}} = \frac{1}{7}(6, 2, -3) = \left(\frac{6}{7}, \frac{2}{7}, -\frac{3}{7}\right)$

**Kết luận:** $S'' = \left\{ \left(\frac{2}{7}, \frac{3}{7}, \frac{6}{7}\right), \left(\frac{3}{7}, -\frac{6}{7}, \frac{2}{7}\right), \left(\frac{6}{7}, \frac{2}{7}, -\frac{3}{7}\right) \right\}$ là tập hợp trực chuẩn của $\mathbb{R}^3$.

---

### **Bài tập tương tự 2 (Tích vô hướng trọng số)**
* **Đề bài:** Trên $Eu = (\mathbb{R}^3, \langle \vert{} \rangle)$ với $\langle \alpha \vert{} \beta \rangle = x_1 y_1 + 3x_2 y_2 + 2x_3 y_3$. Hãy trực chuẩn hóa $S = \{u_1 = (1, 0, 1); u_2 = (-4, 0, 2); u_3 = (-3, -1, -3)\}$.
* **Lời giải:**

**Lưu ý:** Độ dài véctơ được tính theo tích vô hướng đã cho: $\Vert{}\alpha\Vert{}^2 = \langle \alpha \vert{} \alpha \rangle = x_1^2 + 3x_2^2 + 2x_3^2$.

**1. Trực giao hóa Gram-Schmidt:**
* $v_1 = u_1 = (1, 0, 1)$  
  $\Vert{}v_1\Vert{}^2 = 1^2 + 3(0)^2 + 2(1)^2 = 3$

* $v_2 = u_2 - \frac{\langle u_2 \vert{} v_1 \rangle}{\Vert{}v_1\Vert{}^2} v_1$  
  $\langle u_2 \vert{} v_1 \rangle = (-4)(1) + 3(0)(0) + 2(2)(1) = -4 + 0 + 4 = 0$  
  $v_2 = (-4, 0, 2) - 0 = (-4, 0, 2)$  
  $\Vert{}v_2\Vert{}^2 = (-4)^2 + 3(0)^2 + 2(2)^2 = 16 + 8 = 24$

* $v_3 = u_3 - \frac{\langle u_3 \vert{} v_2 \rangle}{\Vert{}v_2\Vert{}^2} v_2 - \frac{\langle u_3 \vert{} v_1 \rangle}{\Vert{}v_1\Vert{}^2} v_1$  
  $\langle u_3 \vert{} v_2 \rangle = (-3)(-4) + 3(-1)(0) + 2(-3)(2) = 12 + 0 - 12 = 0$  
  $\langle u_3 \vert{} v_1 \rangle = (-3)(1) + 3(-1)(0) + 2(-3)(1) = -3 + 0 - 6 = -9$  
  $v_3 = (-3, -1, -3) - 0 - \frac{-9}{3}(1, 0, 1) = (-3, -1, -3) + 3(1, 0, 1) = (0, -1, 0)$  
  $\Vert{}v_3\Vert{}^2 = 0^2 + 3(-1)^2 + 2(0)^2 = 3$

Tập trực giao: $S' = \{v_1 = (1, 0, 1), v_2 = (-4, 0, 2), v_3 = (0, -1, 0)\}$.

**2. Trực chuẩn hóa:**
* $q_1 = \frac{v_1}{\Vert{}v_1\Vert{}} = \frac{1}{\sqrt{3}}(1, 0, 1) = \left(\frac{1}{\sqrt{3}}, 0, \frac{1}{\sqrt{3}}\right)$
* $q_2 = \frac{v_2}{\Vert{}v_2\Vert{}} = \frac{1}{\sqrt{24}}(-4, 0, 2) = \frac{1}{2\sqrt{6}}(-4, 0, 2) = \left(-\frac{2}{\sqrt{6}}, 0, \frac{1}{\sqrt{6}}\right)$
* $q_3 = \frac{v_3}{\Vert{}v_3\Vert{}} = \frac{1}{\sqrt{3}}(0, -1, 0) = \left(0, -\frac{1}{\sqrt{3}}, 0\right)$

**Kết luận:** $S'' = \left\{ \left(\frac{1}{\sqrt{3}}, 0, \frac{1}{\sqrt{3}}\right), \left(-\frac{2}{\sqrt{6}}, 0, \frac{1}{\sqrt{6}}\right), \left(0, -\frac{1}{\sqrt{3}}, 0\right) \right\}$ là tập hợp trực chuẩn cần tìm.

---

### **Bài tập tương tự khác (3 câu)**

#### **Câu 1:** $Eu = (\mathbb{R}^3, \langle \vert{} \rangle)$ tiêu chuẩn, $S = \{\alpha_1 = (2, 3, 6); \alpha_2 = (-3, 6, -2); \alpha_3 = (6, 2, -3)\}$
* **Giải:**
  * $v_1 = (2, 3, 6) \Rightarrow \Vert{}v_1\Vert{}^2 = 49$
  * $\langle \alpha_2 \vert{} v_1 \rangle = (-3)(2) + 6(3) + (-2)(6) = -6 + 18 - 12 = 0 \Rightarrow v_2 = \alpha_2 = (-3, 6, -2) \Rightarrow \Vert{}v_2\Vert{}^2 = 49$
  * $\langle \alpha_3 \vert{} v_1 \rangle = 6(2) + 2(3) + (-3)(6) = 0$ và $\langle \alpha_3 \vert{} v_2 \rangle = 6(-3) + 2(6) + (-3)(-2) = 0 \Rightarrow v_3 = \alpha_3 = (6, 2, -3) \Rightarrow \Vert{}v_3\Vert{}^2 = 49$
  * Do $S$ đã sẵn là tập trực giao nên ta chỉ việc chia độ dài:
    $$S'' = \left\{ \left(\frac{2}{7}, \frac{3}{7}, \frac{6}{7}\right), \left(-\frac{3}{7}, \frac{6}{7}, -\frac{2}{7}\right), \left(\frac{6}{7}, \frac{2}{7}, -\frac{3}{7}\right) \right\}$$

#### **Câu 2:** $Eu = (\mathbb{R}^3, \langle \vert{} \rangle)$ tiêu chuẩn, $S = \{\alpha_1 = (1, 2, 2); \alpha_2 = (-2, 2, -1); \alpha_3 = (2, 1, -2)\}$
* **Giải:**
  * $v_1 = (1, 2, 2) \Rightarrow \Vert{}v_1\Vert{}^2 = 1+4+4 = 9$
  * $\langle \alpha_2 \vert{} v_1 \rangle = -2(1) + 2(2) + (-1)(2) = 0 \Rightarrow v_2 = (-2, 2, -1) \Rightarrow \Vert{}v_2\Vert{}^2 = 9$
  * $\langle \alpha_3 \vert{} v_1 \rangle = 2(1) + 1(2) + (-2)(2) = 0$ và $\langle \alpha_3 \vert{} v_2 \rangle = 2(-2) + 1(2) + (-2)(-1) = 0 \Rightarrow v_3 = (2, 1, -2) \Rightarrow \Vert{}v_3\Vert{}^2 = 9$
  * Kết quả trực chuẩn hóa:
    $$S'' = \left\{ \left(\frac{1}{3}, \frac{2}{3}, \frac{2}{3}\right), \left(-\frac{2}{3}, \frac{2}{3}, -\frac{1}{3}\right), \left(\frac{2}{3}, \frac{1}{3}, -\frac{2}{3}\right) \right\}$$

#### **Câu 3:** $Eu = (\mathbb{R}^3, \langle \vert{} \rangle)$ tiêu chuẩn, $S = \{\alpha_1 = (8, 1, -4); \alpha_2 = (1, 0, 2); \alpha_3 = (-2, 8, -2)\}$
* **Giải:**
  * $v_1 = (8, 1, -4) \Rightarrow \Vert{}v_1\Vert{}^2 = 64 + 1 + 16 = 81$
  * $v_2 = (1, 0, 2) - \frac{8(1) + 0 - 8}{81}(8, 1, -4) = (1, 0, 2) - 0 = (1, 0, 2) \Rightarrow \Vert{}v_2\Vert{}^2 = 1 + 0 + 4 = 5$
  * $v_3 = (-2, 8, -2) - \frac{-2(1) + 0 - 4}{5}(1, 0, 2) - \frac{-2(8) + 8(1) + 8}{81}(8, 1, -4)$  
    $= (-2, 8, -2) - \left(-\frac{6}{5}\right)(1, 0, 2) - 0 = \left(-\frac{4}{5}, 8, \frac{2}{5}\right)$  
    Quy đồng bỏ mẫu tìm $v_3$ tương đương: $v_3 = (-4, 40, 2) \Rightarrow \Vert{}v_3\Vert{}^2 = 16 + 1600 + 4 = 1620 = 18\sqrt{5}$  
  * Kết quả trực chuẩn hóa $S''$:
    $$q_1 = \left(\frac{8}{9}, \frac{1}{9}, -\frac{4}{9}\right)$$
    $$q_2 = \left(\frac{1}{\sqrt{5}}, 0, \frac{2}{\sqrt{5}}\right)$$
    $$q_3 = \left(-\frac{2}{9\sqrt{5}}, \frac{20}{9\sqrt{5}}, \frac{1}{9\sqrt{5}}\right)$$

## BÀI TẬP 6: CHÉO HÓA TRỰC GIAO MA TRẬN VUÔNG (phần thêm)

### **Bài tập tương tự**
* **Đề bài:** Chéo hóa trực giao ma trận vuông thực $A = \begin{pmatrix} 1 & 0 & 1 \\ 0 & 1 & 0 \\ 1 & 0 & 1 \end{pmatrix}$

* **Lời giải:**

**Bước 1: Tìm đa thức đặc trưng và các trị riêng**
$$p_A(\lambda) = \det(\lambda I_3 - A) = \begin{vmatrix} \lambda - 1 & 0 & -1 \\ 0 & \lambda - 1 & 0 \\ -1 & 0 & \lambda - 1 \end{vmatrix}$$
Khai triển theo dòng 2:
$$p_A(\lambda) = (\lambda - 1)\begin{vmatrix} \lambda - 1 & -1 \\ -1 & \lambda - 1 \end{vmatrix} = (\lambda - 1)[(\lambda - 1)^2 - 1] = (\lambda - 1)(\lambda^2 - 2\lambda) = \lambda(\lambda - 1)(\lambda - 2)$$

Phương trình $p_A(\lambda) = 0$ có 3 nghiệm phân biệt:
$$\begin{cases} c_1 = \lambda_1 = 0; & r_1 = 1 \\ c_2 = \lambda_2 = 1; & r_2 = 1 \\ c_3 = \lambda_3 = 2; & r_3 = 1 \end{cases}$$

**Bước 2: Tìm cơ sở cho các không gian riêng**

* **Với $c_1 = \lambda_1 = 0$:**
  Giải hệ $(A - 0\cdot I_3)X = O \Leftrightarrow \begin{pmatrix} 1 & 0 & 1 \\ 0 & 1 & 0 \\ 1 & 0 & 1 \end{pmatrix} \begin{pmatrix} x_1 \\ x_2 \\ x_3 \end{pmatrix} = \begin{pmatrix} 0 \\ 0 \\ 0 \end{pmatrix}$  
  $\Rightarrow \begin{cases} x_1 + x_3 = 0 \\ x_2 = 0 \end{cases} \Rightarrow \begin{cases} x_1 = -t \\ x_2 = 0 \\ x_3 = t \end{cases} (t \in \mathbb{R})$  
  Cơ sở $a_1 = \{\alpha_1 = (-1, 0, 1)\}$, $\dim E_0 = 1$.

* **Với $c_2 = \lambda_2 = 1$:**
  Giải hệ $(A - 1\cdot I_3)X = O \Leftrightarrow \begin{pmatrix} 0 & 0 & 1 \\ 0 & 0 & 0 \\ 1 & 0 & 0 \end{pmatrix} \begin{pmatrix} x_1 \\ x_2 \\ x_3 \end{pmatrix} = \begin{pmatrix} 0 \\ 0 \\ 0 \end{pmatrix}$  
  $\Rightarrow \begin{cases} x_1 = 0 \\ x_3 = 0 \\ x_2 = t \end{cases} (t \in \mathbb{R})$  
  Cơ sở $a_2 = \{\alpha_2 = (0, 1, 0)\}$, $\dim E_1 = 1$.

* **Với $c_3 = \lambda_3 = 2$:**
  Giải hệ $(A - 2\cdot I_3)X = O \Leftrightarrow \begin{pmatrix} -1 & 0 & 1 \\ 0 & -1 & 0 \\ 1 & 0 & -1 \end{pmatrix} \begin{pmatrix} x_1 \\ x_2 \\ x_3 \end{pmatrix} = \begin{pmatrix} 0 \\ 0 \\ 0 \end{pmatrix}$  
  $\Rightarrow \begin{cases} -x_1 + x_3 = 0 \\ x_2 = 0 \end{cases} \Rightarrow \begin{cases} x_1 = t \\ x_2 = 0 \\ x_3 = t \end{cases} (t \in \mathbb{R})$  
  Cơ sở $a_3 = \{\alpha_3 = (1, 0, 1)\}$, $\dim E_2 = 1$.

**Bước 3: Trực chuẩn hóa các cơ sở không gian riêng**
Vì các trị riêng đôi một khác nhau nên các véctơ thuộc các không gian riêng tương ứng đã đôi một vuông góc. Ta chỉ cần chia cho độ dài từng véctơ:

* $\gamma_1 = \frac{\alpha_1}{\Vert{}\alpha_1\Vert{}} = \frac{(-1, 0, 1)}{\sqrt{(-1)^2 + 0^2 + 1^2}} = \left(-\frac{1}{\sqrt{2}}, 0, \frac{1}{\sqrt{2}}\right)$
* $\gamma_2 = \frac{\alpha_2}{\Vert{}\alpha_2\Vert{}} = (0, 1, 0)$
* $\gamma_3 = \frac{\alpha_3}{\Vert{}\alpha_3\Vert{}} = \frac{(1, 0, 1)}{\sqrt{1^2 + 0^2 + 1^2}} = \left(\frac{1}{\sqrt{2}}, 0, \frac{1}{\sqrt{2}}\right)$

Tập $\zeta = \{\gamma_1, \gamma_2, \gamma_3\}$ là một cơ sở trực chuẩn của $\mathbb{R}^3$.

**Bước 4: Ma trận trực giao $P$ và dạng chéo $D$**
Đặt ma trận $P$:
$$P = \begin{pmatrix} -1/\sqrt{2} & 0 & 1/\sqrt{2} \\ 0 & 1 & 0 \\ 1/\sqrt{2} & 0 & 1/\sqrt{2} \end{pmatrix}$$

$P$ là ma trận trực giao thỏa mãn $P^{-1} = P^T$ và dạng chéo hóa trực giao của $A$ là:
$$D = P^T A P = \begin{pmatrix} 0 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 2 \end{pmatrix}$$
