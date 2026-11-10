# Bài tập buổi 1

### Bài tập 1

Gọi $E$ là biến cố khách hàng mua được đúng 2 máy của A và 1 máy của B.

Số cách chọn 3 máy bất kỳ trong 30 máy là

$$
C_{30}^3
= \frac{30!}{3!(30-3)!}
= \frac{30 \cdot 29 \cdot 28}{3 \cdot 2 \cdot 1}
= 4060.
$$

Số cách chọn 2 máy của A trong 20 máy và 1 máy của B trong 10 máy là

$$
C_{20}^2 C_{10}^1
= \frac{20!}{2!(20-2)!} \cdot \frac{10!}{1!(10-1)!}
= \frac{20 \cdot 19}{2 \cdot 1} \cdot \frac{10}{1}
= 190 \cdot 10
= 1900.
$$

Do các máy được chọn ngẫu nhiên như nhau, xác suất cần tìm là

$$
\begin{aligned}
P(E)
&= \frac{C_{20}^2 C_{10}^1}{C_{30}^3} \\
&= \frac{1900}{4060} \\
&= \frac{95}{203} \\
&\approx 0{,}468.
\end{aligned}
$$

Vậy xác suất khách hàng mua được 2 máy của A và 1 máy của B là

$$
\boxed{\frac{95}{203} \approx 46{,}8\%}
$$

---

### Bài 2

Gọi $A$ là biến cố người được chọn thích loại A, $B$ là biến cố người được chọn thích loại B.
Theo bài ra: $P(A) = \frac{120}{200} = 0,6$; $P(B) = \frac{100}{200} = 0,5$; $P(AB) = \frac{60}{200} = 0,3$.

1. **Thích ít nhất một loại:**

$$P(A \cup B) = P(A) + P(B) - P(AB) = 0,6 + 0,5 - 0,3 = 0,8$$

2. **Không thích loại nào:**

$$P(\overline{A \cup B}) = 1 - P(A \cup B) = 1 - 0,8 = 0,2$$

---

### Bài 3

1. **Xác suất viên 1 trắng:** $T_1$ là biến cố viên 1 màu trắng.

$$P(T_1) = \frac{10}{16} = \frac{5}{8} = 0,625$$

2. **Xác suất viên 2 đỏ biết viên 1 trắng:** Khi viên 1 là trắng, trong hộp còn 9 trắng, 6 đỏ (tổng 15 viên).

$$P(Đ_2 \mid T_1) = \frac{6}{15} = \frac{2}{5} = 0,4$$

---

### Bài 4

Gọi $T$ là biến cố sinh viên giỏi Toán, $A$ là biến cố sinh viên giỏi Anh.
Theo bài ra: $P(T) = \frac{17}{20}$; $P(TA) = \frac{5}{20}$.
Xác suất sinh viên giỏi Anh biết sinh viên đó giỏi Toán:

$$P(A \mid T) = \frac{P(TA)}{P(T)} = \frac{5/20}{17/20} = \frac{5}{17} \approx 0,294$$

---

### Bài 5

Ký hiệu: $N$ là mặt ngửa, $S$ là mặt sấp.

* Không gian mẫu: $\Omega = \{NN, NS, SN, SS\} \implies \vert{}\Omega\vert{} = 4$.
* Biểu diễn tập hợp:
* $A = \{NN, NS\} \implies P(A) = \frac{2}{4} = \frac{1}{2}$
* $B = \{NN, SN\} \implies P(B) = \frac{2}{4} = \frac{1}{2}$
* $C = \{NN, SS\} \implies P(C) = \frac{2}{4} = \frac{1}{2}$

* Chứng minh $A, B, C$ đôi một độc lập:
* $AB = \{NN\} \implies P(AB) = \frac{1}{4} = P(A) \cdot P(B)$
* $AC = \{NN\} \implies P(AC) = \frac{1}{4} = P(A) \cdot P(C)$
* $BC = \{NN\} \implies P(BC) = \frac{1}{4} = P(B) \cdot P(C)$

$\implies A, B, C$ đôi một độc lập.

---

### Bài 6

Xác suất chọn sản phẩm từ mỗi lô:

* Lô 1 (15 sp): $P(A_1) = \frac{10}{15} = \frac{2}{3}$; $P(B_1) = \frac{5}{15} = \frac{1}{3}$.
* Lô 2 (20 sp): $P(A_2) = \frac{12}{20} = \frac{3}{5}$; $P(B_2) = \frac{8}{20} = \frac{2}{5}$.

1. **Hai sản phẩm loại A:**

$$P(A_1 A_2) = \frac{2}{3} \cdot \frac{3}{5} = \frac{2}{5} = 0,4$$

2. **Hai sản phẩm cùng loại:**

$$
P(A_1 A_2) + P(B_1 B_2) = \frac{2}{5} + \left(\frac{1}{3} \cdot \frac{2}{5}\right) = \frac{2}{5} + \frac{2}{15} = \frac{8}{15} \approx 0,533
$$

3. **Hai sản phẩm khác loại:**

$$1 - P(\text{cùng loại}) = 1 - \frac{8}{15} = \frac{7}{15} \approx 0,467$$

---

### Bài 7

Lô hàng có 18 chính phẩm, 2 phế phẩm (tổng 20 sp).

a) **Dừng ở lần thứ 2:** Lần 1 rút phế phẩm, lần 2 rút phế phẩm.

$$P = \frac{2}{20} \cdot \frac{1}{19} = \frac{1}{190} \approx 0,0053$$

b) **Dừng ở lần thứ 3:** Trong 2 lần đầu có đúng 1 phế phẩm, lần 3 là phế phẩm.

$$P = \left(C_2^1 \cdot \frac{2}{20} \cdot \frac{18}{19}\right) \cdot \frac{1}{18} = \frac{2}{190} = \frac{1}{95} \approx 0,0105$$

---

### Bài 8

Gọi $p_1 = 0,6; p_2 = 0,9; p_3 = 0,7$ và $q_1 = 0,4; q_2 = 0,1; q_3 = 0,3$.

a) **Cả 3 trúng:**

$$P = 0,6 \cdot 0,9 \cdot 0,7 = 0,378$$

b) **Không viên nào trúng:**

$$P = 0,4 \cdot 0,1 \cdot 0,3 = 0,012$$

c) **Có đúng 1 viên trúng:**

$$P = (0,6 \cdot 0,1 \cdot 0,3) + (0,4 \cdot 0,9 \cdot 0,3) + (0,4 \cdot 0,1 \cdot 0,7) = 0,018 + 0,108 + 0,028 = 0,154$$

d) **Có ít nhất 1 viên trúng:**


$$P = 1 - P(\text{không viên nào trúng}) = 1 - 0,012 = 0,988$$

---

### Bài 9

Gọi $H_1, H_2$ là biến cố chọn hộp 1, hộp 2. $P(H_1) = P(H_2) = 0,5$.
Gọi $D$ là biến cố chọn được bi đỏ:

* $P(D \mid H_1) = \frac{3}{5} = 0,6$
* $P(D \mid H_2) = \frac{2}{10} = 0,2$

1. **Xác suất chọn được bi đỏ:**

$$P(D) = P(H_1)P(D \mid H_1) + P(H_2)P(D \mid H_2) = 0,5 \cdot 0,6 + 0,5 \cdot 0,2 = 0,4$$

2. **Xác suất bi đỏ thuộc hộp 1:**

$$P(H_1 \mid D) = \frac{P(H_1)P(D \mid H_1)}{P(D)} = \frac{0,5 \cdot 0,6}{0,4} = 0,75$$

---

### Bài 10

Gọi $X$ là số người khỏi bệnh $\implies X \sim B(10; 0,95)$.

a) **Có 8 người khỏi bệnh:**


$$P(X = 8) = C_{10}^8 \cdot (0,95)^8 \cdot (0,05)^2 = 45 \cdot 0,6634 \cdot 0,0025 \approx 0,0746$$


b) **Có nhiều nhất 9 người khỏi bệnh:**


$$P(X \le 9) = 1 - P(X = 10) = 1 - (0,95)^{10} \approx 1 - 0,5987 = 0,4013$$

---

### Bài 11

Gieo 1 con súc sắc $n$ lần độc lập. Xác suất không xuất hiện mặt 6 chấm trong 1 lần gieo là $\frac{5}{6}$.
Xác suất có ít nhất 1 lần xuất hiện mặt 6 chấm là:


$$P = 1 - \left(\frac{5}{6}\right)^n$$

Yêu cầu bài toán:


$$1 - \left(\frac{5}{6}\right)^n \ge 0,9 \iff \left(\frac{5}{6}\right)^n \le 0,1 \iff n \ge \log_{5/6}(0,1) \approx 12,63$$

Vậy cần gieo **ít nhất 13 lần**
