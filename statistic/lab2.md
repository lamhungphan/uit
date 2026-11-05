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

### Bài tập 3.2.2

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

Vậy $E\left(X^2Y - 3XY + 5Y + 7\right) = 8{,}2$.