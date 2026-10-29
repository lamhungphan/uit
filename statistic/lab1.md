### Câu 1 Đề thi thử

Một máy tính để bàn có 3 ổ đĩa cứng là $C, D, E$. Biết rằng khả năng bị nhiễm virus máy tính của các tệp tin ở các ổ đĩa $C, D, E$ lần lượt là $2\%$, $6\%$ và $8\%$. Chọn ngẫu nhiên một tệp tin trong các ổ đĩa của máy tính này.

a) Tính xác suất để tệp tin này không bị nhiễm virus máy tính.  
b) Giả sử rằng tệp tin chọn ra kiểm tra đã bị nhiễm virus máy tính. Tính khả năng tệp tin này thuộc ổ đĩa $E$ của máy tính.

---

### 1. Ký hiệu biến cố và thông tin đã biết

Vì tệp tin được chọn ngẫu nhiên từ các ổ đĩa của máy tính có 3 ổ đĩa $C, D, E$, ta giả định xác suất chọn ngẫu nhiên một tệp tin ở mỗi ổ đĩa là như nhau (đều bằng $\frac{1}{3}$):

Gọi các biến cố:
* $C$: "Tệp tin được chọn thuộc ổ đĩa $C$" $\Rightarrow P(C) = \frac{1}{3}$

* $D$: "Tệp tin được chọn thuộc ổ đĩa $D$" $\Rightarrow P(D) = \frac{1}{3}$

* $E$: "Tệp tin được chọn thuộc ổ đĩa $E$" $\Rightarrow P(E) = \frac{1}{3}$

Hệ $\{C, D, E\}$ tạo thành một **hệ biến cố đầy đủ**.

Gọi $A$ là biến cố: "Tệp tin được chọn bị nhiễm virus máy tính".

Theo đề bài, xác suất có điều kiện tệp tin bị nhiễm virus khi thuộc từng ổ đĩa là:
* $P(A|C) = 2\% = 0{,}02$
* $P(A|D) = 6\% = 0{,}06$
* $P(A|E) = 8\% = 0{,}08$

---

### a) Tính xác suất để tệp tin chọn ra **không** bị nhiễm virus

Áp dụng **công thức xác suất đầy đủ**, xác suất để tệp tin bị nhiễm virus $P(A)$ là:

$$P(A) = P(C) \cdot P(A|C) + P(D) \cdot P(A|D) + P(E) \cdot P(A|E)$$

$$P(A) = \frac{1}{3} \cdot 0{,}02 + \frac{1}{3} \cdot 0{,}06 + \frac{1}{3} \cdot 0{,}08 = \frac{1}{3} \cdot (0{,}02 + 0{,}06 + 0{,}08)$$

$$P(A) = \frac{1}{3} \cdot 0{,}16 = \frac{0{,}16}{3} = \frac{4}{75} \approx 0{,}0533 \quad (5{,}33\%)$$

Gọi $\overline{A}$ là biến cố: "Tệp tin được chọn **không** bị nhiễm virus".  
Xác suất tệp tin không bị nhiễm virus là:

$$P(\overline{A}) = 1 - P(A) = 1 - \frac{4}{75} = \frac{71}{75} \approx 0{,}9467 \quad (94{,}67\%)$$

---

### b) Tính khả năng tệp tin bị nhiễm virus thuộc ổ đĩa $E$

Biết tệp tin đã bị nhiễm virus (biến cố $A$ đã xảy ra), ta cần tính xác suất điều kiện $P(E|A)$.

Áp dụng **công thức Bayes**:

$$P(E|A) = \frac{P(E) \cdot P(A|E)}{P(A)}$$

Thay các giá trị đã tính vào:

$$P(E|A) = \frac{\frac{1}{3} \cdot 0{,}08}{\frac{0{,}16}{3}} = \frac{0{,}08}{0{,}16} = \frac{1}{2} = 0{,}5 \quad (50\%)$$

**Kết luận**

a) Xác suất để tệp tin chọn ra không bị nhiễm virus là **$\frac{71}{75}$** (hoặc khoảng **$94{,}67\%$**)

b) Khả năng tệp tin bị nhiễm virus thuộc ổ đĩa $E$ là **$\frac{1}{2}$** (hoặc **$50\%$**).

---

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
\boxed{\frac{95}{203} \approx 46{,}8\%}.
$$
