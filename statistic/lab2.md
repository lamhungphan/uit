# Bài tập buổi 2

### Bài 1

Vì xạ thủ dừng khi bắn trúng lần đầu tiên hoặc bắn hết 4 viên, nên $X$ chỉ nhận các giá trị:

$$X \in \{1,2,3,4\}$$

Gọi $T$ là biến cố “trúng”, $M$ là biến cố “trượt”. Ta có:

- $P(X=1) = P(T) = 0{,}8$.
- $P(X=2) = P(MT) = 0{,}2 \cdot 0{,}8 = 0{,}16$.
- $P(X=3) = P(MMT) = 0{,}2^2 \cdot 0{,}8 = 0{,}032$.
- $P(X=4) = P(MMMT) + P(MMMM) = 0{,}2^3 \cdot 0{,}8 + 0{,}2^4 = 0{,}0064 + 0{,}0016 = 0{,}008$

Ta kiểm tra tổng xác suất:

$$0{,}8 + 0{,}16 + 0{,}032 + 0{,}008 = 1.$$

Vậy bảng phân phối xác suất của $X$ là:

| $X$ | 1 | 2 | 3 | 4 |
|-----|-----|-----|-----|-----|
| $P$ | 0,8 | 0,16 | 0,032 | 0,008 |

Hoặc viết dưới dạng hàm xác suất:

$$
P(X=x)=
\begin{cases}
0{,}8, & x=1, \\
0{,}16, & x=2, \\
0{,}032, & x=3, \\
0{,}008, & x=4, \\
0, & \text{các giá trị khác.}
\end{cases}
$$

---

### Bài 2

Hàm mật độ: $f(x) = \frac{3}{28}x^2$ khi $x \in [-1; 3]$ và $f(x) = 0$ khi $x \notin [-1; 3]$.
Hàm phân phối $F(x) = \int_{-\infty}^{x} f(t) dt$:

* Với $x < -1$: $F(x) = 0$
* Với $-1 \le x \le 3$:

$$
F(x) = \int_{-1}^{x} \frac{3}{28}t^2 dt = \left[ \frac{t^3}{28} \right]_{-1}^{x} = \frac{x^3 + 1}{28}
$$

* Với $x > 3$: $F(x) = 1$

Vậy:

$$
F(x) = \begin{cases} 0 & \text{khi } x < -1 \\ \dfrac{x^3 + 1}{28} & \text{khi } -1 \le x \le 3 \\ 1 & \text{khi } x > 3 \end{cases}
$$

---

### Bài 3

Cho biến ngẫu nhiên liên tục $X$ có hàm mật độ

$$
f(x)=
\begin{cases}
kx, & x \in [0,1], \\
0, & x \notin [0,1].
\end{cases}
$$

#### 1. Xác định giá trị $k$

Vì $f(x)$ là hàm mật độ xác suất nên

$$
\int_{-\infty}^{+\infty} f(x)\,dx
= \int_0^1 kx\,dx
= \frac{k}{2}
= 1
$$

Suy ra ${k=2}$

#### 3. Tính $P\left(\dfrac{1}{2}<X<\dfrac{3}{4}\right)$

Thay $k=2$ vào hàm mật độ. Do $X$ là biến ngẫu nhiên liên tục,

$$
\begin{aligned}

P\left(\frac{1}{2}<X<\frac{3}{4}\right)

&= \int_{1/2}^{3/4} 2x\,dx \\

&= \left[x^2\right]_{1/2}^{3/4} \\

&= \frac{9}{16}-\frac{1}{4} \\

&= {\frac{5}{16}=0{,}3125}

\end{aligned}

$$

---

### Bài 3.2.2

Cho hai biến ngẫu nhiên $X$ và $Y$ độc lập có bảng phân phối xác suất:

* **Biến ngẫu nhiên $X$:**
  | $X$ | $-1$ | $1$ | $3$ |
  | :---: | :---: | :---: | :---: |
  | $P$ | $0{,}3$ | $0{,}1$ | $0{,}6$ |

* **Biến ngẫu nhiên $Y$:**
  | $Y$ | $-1$ | $2$ |
  | :---: | :---: | :---: |
  | $P$ | $0{,}6$ | $0{,}4$ |

**Yêu cầu:** Tính $E\left(X^2Y - 3XY + 5Y + 7\right)$.

Vì $X$ và $Y$ là hai biến ngẫu nhiên độc lập nên ta có các tính chất:
$$
E(XY) = E(X)E(Y)
$$

$$
E(X^2Y) = E(X^2)E(Y)
$$

Ta có

$$
\begin{aligned}
E(X) &= (-1) \cdot 0{,}3 + 1 \cdot 0{,}1 + 3 \cdot 0{,}6 \\
     &= -0{,}3 + 0{,}1 + 1{,}8 = 1{,}6
\end{aligned}
$$

$$
\begin{aligned}
E(X^2) &= (-1)^2 \cdot 0{,}3 + 1^2 \cdot 0{,}1 + 3^2 \cdot 0{,}6 \\
       &= 1 \cdot 0{,}3 + 1 \cdot 0{,}1 + 9 \cdot 0{,}6 \\
       &= 0{,}3 + 0{,}1 + 5{,}4 = 5{,}8
\end{aligned}
$$

$$
\begin{aligned}
E(Y) &= (-1) \cdot 0{,}6 + 2 \cdot 0{,}4 \\
     &= -0{,}6 + 0{,}8 = 0{,}2
\end{aligned}
$$

Áp dụng tính chất kỳ vọng

$$
\begin{aligned}
E\left(X^2Y - 3XY + 5Y + 7\right) &= E(X^2Y) - 3E(XY) + 5E(Y) + 7 \\
&= E(X^2)E(Y) - 3E(X)E(Y) + 5E(Y) + 7
\end{aligned}
$$

Thay các giá trị đã tính vào biểu thức:
$$
\begin{aligned}
&= 5{,}8 \cdot 0{,}2 - 3 \cdot 1{,}6 \cdot 0{,}2 + 5 \cdot 0{,}2 + 7 \\
&= 1{,}16 - 0{,}96 + 1 + 7 \\
&= 8{,}2
\end{aligned}
$$

Vậy $E\left(X^2Y - 3XY + 5Y + 7\right) = 8{,}2$

---

### Bài 4

Chọn 4 sản phẩm từ 12 sản phẩm (10 tốt, 2 phế). Tổng số cách chọn: $C_{12}^4 = 495$.
$X$ là số sản phẩm tốt trong 4 sản phẩm lấy ra $\implies X \in \{2, 3, 4\}$.

* $P(X=2) = \dfrac{C_{10}^2 \cdot C_2^2}{C_{12}^4} = \dfrac{45 \cdot 1}{495} = \dfrac{1}{11} \approx 0{,}0909$
* $P(X=3) = \dfrac{C_{10}^3 \cdot C_2^1}{C_{12}^4} = \dfrac{120 \cdot 2}{495} = \dfrac{16}{33} \approx 0{,}4848$
* $P(X=4) = \dfrac{C_{10}^4 \cdot C_2^0}{C_{12}^4} = \dfrac{210 \cdot 1}{495} = \dfrac{14}{33} \approx 0{,}4242$

Bảng phân phối xác suất:

| $X$ | 2 | 3 | 4 |
| --- | --- | --- | --- |
| $P$ | $\frac{1}{11}$ | $\frac{16}{33}$ | $\frac{14}{33}$ |

**Kỳ vọng:** $E(X) = 2 \cdot \frac{3}{33} + 3 \cdot \frac{16}{33} + 4 \cdot \frac{14}{33} = \frac{110}{33} = \frac{10}{3} \approx 3{,}33$

---

### Bài 5

Ta có hai điều kiện:

1. Tổng xác suất bằng 1: $a + 0{,}2 + b + 0{,}2 + 0{,}1 = 1 \iff a + b = 0{,}5 \implies b = 0{,}5 - a$
2. Kỳ vọng $E(X) = 3{,}5$:

$$1 \cdot a + 2 \cdot 0{,}2 + 4 \cdot b + 5 \cdot 0{,}2 + 7 \cdot 0{,}1 = 3{,}5$$

$$a + 0{,}4 + 4b + 1 + 0{,}7 = 3{,}5 \iff a + 4b = 1{,}4$$

Thay $b = 0{,}5 - a$ vào:

$$a + 4(0{,}5 - a) = 1{,}4 \iff -3a + 2 = 1{,}4 \iff 3a = 0{,}6 \implies a = 0{,}2$$

Suy ra $b = 0{,}5 - 0{,}2 = 0{,}3$

Vậy $a = 0{,}2$ và $b = 0{,}3$

---

### Bài 6

Gọi $Y$ là số tiền nhận được ở mỗi lần lấy bi (đơn vị: ngàn đồng)

* Lấy bi đỏ (xác suất $P = \frac{4}{10} = 0{,}4$): $Y = +100$
* Lấy bi đen (xác suất $P = \frac{6}{10} = 0{,}6$): $Y = -70$

Trung bình mỗi lần lấy bi, ông A nhận được:

$$E(Y) = 100 \cdot 0{,}4 + (-70) \cdot 0{,}6 = 40 - 42 = -2 \text{ (ngàn đồng)}$$

Vậy trung bình mỗi lần ông A bị **lỗ 2 ngàn đồng** (nhận -2.000 VNĐ)

---

### Bài 7

Do hai bức tranh độc lập, gọi $X_A, X_B$ lần lượt là số tiền thu được từ tranh A và B (đơn vị: triệu đồng)

* Với tranh A:
* Thành công ($P=0{,}97$): $+1{,}3$
* Hỏng ($P=0{,}03$): $-0{,}8$
* $E(X_A) = 1{,}3 \cdot 0{,}97 + (-0{,}8) \cdot 0{,}03 = 1{,}261 - 0{,}024 = 1{,}237$

* Với tranh B:
* Thành công ($P=0{,}95$): $+0{,}9$
* Hỏng ($P=0{,}05$): $-0{,}6$
* $E(X_B) = 0{,}9 \cdot 0{,}95 + (-0{,}6) \cdot 0{,}05 = 0{,}855 - 0{,}03 = 0{,}825$

Trung bình người thợ nhận được mỗi tuần:

$$E(X) = E(X_A) + E(X_B) = 1{,}237 + 0{,}825 = 2{,}062 \text{ (triệu đồng)}$$

Vậy trung bình kiếm được **2.062.000 VNĐ/tuần**

---

### Bài 8

Lấy có hoàn lại 2 sản phẩm, xác suất lấy được loại 1 mỗi lần là $p = \frac{6}{10} = 0{,}6$
Số sản phẩm loại 1 lấy được $X \sim B(2; 0{,}6)$.

1. **Luật phân phối xác suất:** $X \in \{0, 1, 2\}$
* $P(X=0) = (0{,}4)^2 = 0{,}16$
* $P(X=1) = 2 \cdot 0{,}6 \cdot 0{,}4 = 0{,}48$
* $P(X=2) = (0{,}6)^2 = 0{,}36$

2. **Kỳ vọng $E(X)$:**

$$E(X) = n \cdot p = 2 \cdot 0{,}6 = 1{,}2$$

3. **Phương sai $Var(X)$:**

$$Var(X) = n \cdot p \cdot (1-p) = 2 \cdot 0{,}6 \cdot 0{,}4 = 0{,}48$$

---

### Bài 9

Gọi $Y$ là lợi luận thu được từ dự án (đơn vị: nghìn USD)

* Thành công ($P = 0{,}3$): Thu về 1.000, trừ chi phí 100 $\implies Y = 900$
* Thất bại ($P = 0{,}7$): Không thu về gì, mất chi phí 100 $\implies Y = -100$

Kỳ vọng lợi nhuận:

$$E(Y) = 900 \cdot 0{,}3 + (-100) \cdot 0{,}7 = 270 - 70 = 200 \text{ (nghìn USD)}$$

Vậy kỳ vọng lợi nhuận là **200.000 USD**

---

### Bài 10

Hàm mật độ $f(x) = 2e^{-2x}$ với $x \ge 0$ (Phân phối mũ với $\lambda = 2$)

1. **Kỳ vọng $E(X)$:**

$$E(X) = \int_{0}^{+\infty} x \cdot 2e^{-2x} \, dx = \frac{1}{\lambda} = \frac{1}{2} = 0{,}5$$

2. **Phương sai $Var(X)$ và Độ lệch chuẩn $\sigma$:**

$$Var(X) = \frac{1}{\lambda^2} = \frac{1}{4} = 0{,}25$$


$$\sigma = \sqrt{Var(X)} = \sqrt{0{,}25} = 0{,}5$$


3. **Mod(X):**
Hàm $f(x) = 2e^{-2x}$ đạt giá trị lớn nhất tại $x = 0$ trên $[0, +\infty)$

$$\implies \text{Mod}(X) = 0$$