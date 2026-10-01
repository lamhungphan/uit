# BÀI TẬP BUỔI 5 – ĐẠI SỐ TUYẾN TÍNH

> Chương 3: Không gian véc tơ, không gian con, tổ hợp tuyến tính và ĐLTT/PTTT.

---

## 1. Tính phép toán véc tơ trên $\mathbb{R}^6$

### Bài tập ví dụ trang 2
> Cho $\alpha = (-2; 3; 5; -8; -4; 9)$ và $\beta = (7; -1; 2; 4; -6; 3)$ trên $\mathbb{R}^6$.  
> Tìm các véc tơ $u = 235\alpha - 1479\beta$ và $v = 3572\beta - 5383\alpha$.

**Lời giải:**

1. **Tính $u = 235\alpha - 1479\beta$:**
   * $235\alpha = 235 \times (2; 3; 5; -8; -4; 9) = (470; 705; 1175; -1880; -940; 2115)$
   * $1479\beta = 1479 \times (7; -1; 2; 4; -6; 3) = (10353; -1479; 2958; 5916; -8874; 4437)$
   $$\implies u = (470 - 10353;\; 705 + 1479;\; 1175 - 2958;\; -1880 - 5916;\; -940 + 8874;\; 2115 - 4437)$$
   $$\implies u = (-9883;\; 2184;\; -1783;\; -7796;\; 7934;\; -2322)$$

2. **Tính $v = 3572\beta - 5383\alpha$:**
   * $3572\beta = (25004;\; -3572;\; 7144;\; 14288;\; -21432;\; 10716)$
   * $5383\alpha = (10766;\; 16149;\; 26915;\; -43064;\; -21532;\; 48447)$
   $$\implies v = (25004 - 10766;\; -3572 - 16149;\; 7144 - 26915;\; 14288 + 43064;\; -21432 + 21532;\; 10716 - 48447)$$
   $$\implies v = (14238;\; -19721;\; -19771;\; 57352;\; 100;\; -37731)$$

---

## PHẦN 2: KIỂM TRA KHÔNG GIAN VÉC TƠ CON ($W \le V$)

### BÀI TẬP TỰ LUYỆN (Trang 5)

#### a/ $V = \mathbb{R}^3, W = \{(x; y; z) \mid 3x + 5z = 0\}$
* **Giải:**
  * Chọn $\mathbf{0} = (0;0;0) \in W$ vì $3(0) + 5(0) = 0 \implies W \neq \emptyset$.
  * Với mọi $\alpha = (x_1; y_1; z_1) \in W \implies 3x_1 + 5z_1 = 0$
  * Với mọi $\beta = (x_2; y_2; z_2) \in W \implies 3x_2 + 5z_2 = 0$
  * Cộng 2 vế: $3(x_1 + x_2) + 5(z_1 + z_2) = 0 \implies \alpha + \beta \in W$.
  * Nhân số thực $c \in \mathbb{R}$: $c(3x_1 + 5z_1) = 0 \implies 3(cx_1) + 5(cz_1) = 0 \implies c\alpha \in W$.
  * **Kết luận:** $W \le V$.

#### b/ $V = \mathbb{R}^3, W = \{(x; y; z) \mid y = 0\}$
* **Giải:** 
  * Dễ thấy $\mathbf{0} \in W$.
  * Với mọi $\alpha = (x_1; 0; z_1), \beta = (x_2; 0; z_2) \in W \implies \alpha + \beta = (x_1 + x_2; 0; z_1 + z_2) \in W$.
  * Với mọi $c \in \mathbb{R} \implies c\alpha = (cx_1; 0; cz_1) \in W$.
  * **Kết luận:** $W \le V$.

#### c/ $V = \mathbb{R}^3, W = \{(x; y; z) \mid 4x = 2y - z\}$
* **Giải:**

Biến đổi điều kiện về dạng phương trình tuyến tính thuần nhất:


$$4x - 2y + z = 0$$

Suy ra $z = 2y - 4x$. Chọn $x = a, y = b$ làm 2 ẩn tự do ($a, b \in \mathbb{R}$):

* $z = 2b - 4a$

Thay vào véc tơ tổng quát $X$:


$$X = (a;\; b;\; 2b - 4a) = a(1;\; 0;\; -4) + b(0;\; 1;\; 2)$$

Đặt $\alpha_1 = (1; 0; -4)$ và $\alpha_2 = (0; 1; 2)$, gọi $S = \{\alpha_1, \alpha_2\}$.

* Vì $W = \langle S \rangle$ nên **$W \le V$** (ĐPCM).
* Do $\alpha_1, \alpha_2$ không cùng phương nên hệ $S$ độc lập tuyến tính.

**Kết luận:**

* **Hệ sinh:** $S = \{(1; 0; -4),\ (0; 1; 2)\}$
* **Cơ sở:** $S = \{(1; 0; -4),\ (0; 1; 2)\}$
* **Số chiều:** $\dim_{\mathbb{R}} W = 2$

#### d/ $V = \mathbb{R}^3, W = \{(x; y; z) \mid 6x - 5yz = 0\}$
* **Giải:**
  * Chọn $\alpha = (5; 6; 1) \in W$ do $6(5) - 5(6)(1) = 0$.
  * Chọn $\beta = (5; 1; 6) \in W$ do $6(5) - 5(1)(6) = 0$.
  * Xét $\alpha + \beta = (10; 7; 7)$, ta có: $6(10) - 5(7)(7) = 60 - 245 = -185 \neq 0 \implies \alpha + \beta \notin W$.
  * **Kết luận:** $W \not\le V$.

#### e/ $V = \mathbb{R}^3, W = \{(x; y; z) \mid xyz = 0\}$
* **Giải:**
  * Chọn $\alpha = (1; 0; 0) \in W$ và $\beta = (0; 1; 1) \in W$.
  * Xét $\alpha + \beta = (1; 1; 1)$, có $(1)(1)(1) = 1 \neq 0 \implies \alpha + \beta \notin W$.
  * **Kết luận:** $W \not\le V$.

#### f/ $V = \mathbb{R}^3, W = \{(x; y; z) \mid 7x - z = 2\}$
* **Giải:**

* Xét véc tơ zero $\mathbf{0} = (0; 0; 0)$: ta có $7(0) - 0 = 0 \neq 2 \implies \mathbf{0} \notin W$.
* Vì $\mathbf{0} \notin W$ nên $W$ không thỏa điều kiện cần để là không gian con.

Kiểm tra thêm phép cộng:

* Chọn $\alpha = (1; 0; 5) \in W$ do $7(1) - 5 = 2$.
* Chọn $\beta = (0; 0; -2) \in W$ do $7(0) - (-2) = 2$.
* Xét $\alpha + \beta = (1; 0; 3)$, ta có $7(1) - 3 = 4 \neq 2 \implies \alpha + \beta \notin W$.

* **Kết luận:** $W \not\le V$.

#### g/ $V = \mathbb{R}^3, W = \{(x; y; z) \mid 2x - 5z^2 = 0\}$
* **Giải:**

* Điều kiện có chứa $z^2$ (bậc hai) nên dự đoán $W$ không là không gian con. Kiểm chứng:
* $\mathbf{0} = (0; 0; 0) \in W$ vì $2(0) - 5(0)^2 = 0$ (nên phải kiểm tra 2 phép toán).
* Chọn $\alpha = (10; 0; 2) \in W$ do $2(10) - 5(2)^2 = 20 - 20 = 0$.
* Chọn $\beta = (10; 0; -2) \in W$ do $2(10) - 5(-2)^2 = 20 - 20 = 0$.
* Xét $\alpha + \beta = (20; 0; 0)$, ta có $2(20) - 5(0)^2 = 40 \neq 0 \implies \alpha + \beta \notin W$.
* **Kết luận:** $W \not\le V$ (không đóng kín với phép cộng véc tơ).

#### h/ $V = \mathbb{R}^3, W = \{(x; y; z) \mid x + 5z = 0 \text{ và } 4y - z = 0\}$
* **Giải:** Đây là hệ phương trình tuyến tính thuần nhất nên dự đoán $W \le V$; kiểm chứng cụ thể.

Hệ phương trình điều kiện:


$$\begin{cases} x + 5z = 0 \\ 4y - z = 0 \end{cases}$$

Hệ có 3 ẩn, 2 phương trình $\implies$ còn 1 ẩn tự do. Chọn $z = 4a$ ($a \in \mathbb{R}$) để tránh phân số:

* Từ phương trình (2): $4y - 4a = 0 \implies y = a$
* Từ phương trình (1): $x + 5(4a) = 0 \implies x = -20a$

Thay vào véc tơ tổng quát $X$:


$$X = (-20a;\; a;\; 4a) = a(-20;\; 1;\; 4)$$

Đặt $\alpha_1 = (-20; 1; 4)$, gọi $S = \{\alpha_1\}$.

* Vì $W = \langle S \rangle$ nên **$W \le V$** (ĐPCM).
* Do $\alpha_1 \neq \mathbf{0}$ nên hệ $S$ độc lập tuyến tính.

**Kết luận:**

* **Hệ sinh:** $S = \{(-20; 1; 4)\}$
* **Cơ sở:** $S = \{(-20; 1; 4)\}$
* **Số chiều:** $\dim_{\mathbb{R}} W = 1$

#### i/ $V = \mathbb{R}^4, W = \{(x; y; z; t) \mid 2x - 4y + z - 6t = 0\}$
* **Giải:** Phương trình tuyến tính thuần nhất nên dự đoán $W \le V$; kiểm chứng cụ thể.


$$2x - 4y + z - 6t = 0$$

Hệ có 4 ẩn, 1 phương trình $\implies$ còn 3 ẩn tự do. Chọn $x = a, y = b, t = c$ ($a, b, c \in \mathbb{R}$):

* $z = -2a + 4b + 6c$

Thay vào véc tơ tổng quát $X$:


$$X = (a;\; b;\; -2a + 4b + 6c;\; c) = a(1;\; 0;\; -2;\; 0) + b(0;\; 1;\; 4;\; 0) + c(0;\; 0;\; 6;\; 1)$$

Đặt $S = \{\alpha_1 = (1; 0; -2; 0),\ \alpha_2 = (0; 1; 4; 0),\ \alpha_3 = (0; 0; 6; 1)\}$.

* Vì $W = \langle S \rangle$ nên **$W \le V$** (ĐPCM).
* Ba véc tơ trong $S$ có vị trí dẫn đầu khác nhau nên hệ $S$ độc lập tuyến tính.

**Kết luận:**

* **Hệ sinh:** $S = \{(1; 0; -2; 0),\ (0; 1; 4; 0),\ (0; 0; 6; 1)\}$
* **Cơ sở:** $S = \{(1; 0; -2; 0),\ (0; 1; 4; 0),\ (0; 0; 6; 1)\}$
* **Số chiều:** $\dim_{\mathbb{R}} W = 3$

#### j/ $V = \mathbb{R}^4, W = \left\{ (x; y; z; t) \in \mathbb{R}^4 \;\middle\vert{}\; \begin{cases} x + y - 2z + 3t = 0 \\ x = 4z - t \end{cases} \right\}$


Biến đổi hệ phương trình điều kiện về dạng hệ tuyến tính thuần nhất:


$$\begin{cases} x + y - 2z + 3t = 0 \\ x - 4z + t = 0 \end{cases}$$

Ma trận hệ số $A$:


$$A = \begin{pmatrix} 1 & 1 & -2 & 3 \\ 1 & 0 & -4 & 1 \end{pmatrix} \xrightarrow{(2) \to (2) - (1)} \begin{pmatrix} 1 & 1 & -2 & 3 \\ 0 & -1 & -2 & -2 \end{pmatrix}$$

Hệ phương trình tương đương:


$$\begin{cases} x + y - 2z + 3t = 0 \\ -y - 2z - 2t = 0 \end{cases}$$

Chọn $z = a, t = b$ làm 2 ẩn tự do ($a, b \in \mathbb{R}$):

* Từ phương trình (2): $-y - 2a - 2b = 0 \implies y = -2a - 2b$
* Từ phương trình (1): $x + (-2a - 2b) - 2a + 3b = 0 \implies x = 4a - b$

Thay $x, y, z, t$ vào véc tơ tổng quát $X$:


$$X = (4a - b;\; -2a - 2b;\; a;\; b) = a(4;\; -2;\; 1;\; 0) + b(-1;\; -2;\; 0;\; 1)$$

Đặt $\alpha_1 = (4; -2; 1; 0)$ và $\alpha_2 = (-1; -2; 0; 1)$, gọi $S = \{\alpha_1, \alpha_2\}$.

* Vì $W = \langle S \rangle$ nên **$W \le V$** (ĐPCM).
* Do $\alpha_1, \alpha_2$ không cùng phương nên hệ $S$ độc lập tuyến tính.

**Kết luận:**

* **Hệ sinh:** $S = \{(4; -2; 1; 0), (-1; -2; 0; 1)\}$
* **Cơ sở:** $S = \{(4; -2; 1; 0), (-1; -2; 0; 1)\}$
* **Số chiều:** $\dim_{\mathbb{R}} W = 2$

#### k/ $V = M_2(\mathbb{R}), W = \left\{ A = \begin{pmatrix} 3a &  5b \\ -b  & a+b \end{pmatrix} \;\middle|\; a, b \in \mathbb{R} \right\}$
* **Giải:**

**1) Kiểm tra $W \le V$:**

* Chọn $A = \begin{pmatrix} 3 & 0 \\ 0 & 1 \end{pmatrix} \in W$ ứng với $a = 1, b = 0 \implies W \neq \emptyset$ (*).
* Lấy $A_1 = \begin{pmatrix} 3a_1 & 5b_1 \\ -b_1 & a_1+b_1 \end{pmatrix}$ và $A_2 = \begin{pmatrix} 3a_2 & 5b_2 \\ -b_2 & a_2+b_2 \end{pmatrix}$ thuộc $W$. Khi đó:

$$A_1 + A_2 = \begin{pmatrix} 3(a_1+a_2) & 5(b_1+b_2) \\ -(b_1+b_2) & (a_1+a_2)+(b_1+b_2) \end{pmatrix} \in W$$

ứng với $a = a_1 + a_2$ và $b = b_1 + b_2$ (**).

* Với mọi $c \in \mathbb{R}$:

$$cA_1 = \begin{pmatrix} 3(ca_1) & 5(cb_1) \\ -(cb_1) & (ca_1)+(cb_1) \end{pmatrix} \in W$$

ứng với $a = ca_1$ và $b = cb_1$ (***).

\* Từ (\*), (\*\*), (\*\*\*) $\implies$ **$W \le V$** (ĐPCM).

**2) Tìm hệ sinh, cơ sở, số chiều:**

Tách ma trận tổng quát theo $a, b$:


$$A = a\begin{pmatrix} 3 & 0 \\ 0 & 1 \end{pmatrix} + b\begin{pmatrix} 0 & 5 \\ -1 & 1 \end{pmatrix}$$

Đặt $S = \left\{ \begin{pmatrix} 3 & 0 \\ 0 & 1 \end{pmatrix},\ \begin{pmatrix} 0 & 5 \\ -1 & 1 \end{pmatrix} \right\}$.

* Vì $W = \langle S \rangle$ nên **$W \le V$**.
* Hai ma trận trong $S$ không tỉ lệ với nhau nên hệ $S$ độc lập tuyến tính.

**Kết luận:**

* **Hệ sinh:** $S = \left\{ \begin{pmatrix} 3 & 0 \\ 0 & 1 \end{pmatrix},\ \begin{pmatrix} 0 & 5 \\ -1 & 1 \end{pmatrix} \right\}$
* **Cơ sở:** $S$
* **Số chiều:** $\dim_{\mathbb{R}} W = 2$

#### l/ $V = M_2(\mathbb{R}), W = \left\{ A = \begin{pmatrix} ab & 2b \\ b^3 & a \end{pmatrix} \;\middle|\; a, b \in \mathbb{R} \right\}$
* **Giải:**

* Điều kiện có chứa $ab$ và $b^3$ (bậc hai, bậc ba) nên dự đoán $W$ không là không gian con. Tìm phản ví dụ:
* Chọn $(a; b) = (1; 1)$: $A_1 = \begin{pmatrix} 1 & 2 \\ 1 & 1 \end{pmatrix} \in W$.
* Chọn $(a; b) = (-1; 1)$: $A_2 = \begin{pmatrix} -1 & 2 \\ 1 & -1 \end{pmatrix} \in W$.
* Xét $A_1 + A_2 = \begin{pmatrix} 0 & 4 \\ 2 & 0 \end{pmatrix}$.

Giả sử $A_1 + A_2 \in W$, tức tồn tại $a, b \in \mathbb{R}$ thỏa hệ:


$$\begin{cases} ab = 0 \\ 2b = 4 \\ b^3 = 2 \\ a = 0 \end{cases}$$

Từ $2b = 4 \implies b = 2$, khi đó $b^3 = 8 \neq 2$: mâu thuẫn $\implies A_1 + A_2 \notin W$.

* **Kết luận:** $W \not\le V$ (không đóng kín với phép cộng véc tơ).

---

## PHẦN 3: TỔ HỢP TUYẾN TÍNH

## PHẦN 4: ĐỘC LẬP TUYẾN TÍNH VÀ PHỤ THUỘC TUYẾN TÍNH
