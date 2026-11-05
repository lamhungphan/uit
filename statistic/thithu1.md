# ĐỀ THI MẪU 1

### Câu 1

Một máy tính để bàn có 3 ổ đĩa cứng là $C, D, E$. Biết rằng khả năng bị nhiễm virus máy tính của các tệp tin ở các ổ đĩa $C, D, E$ lần lượt là $2\%$, $6\%$ và $8\%$. Chọn ngẫu nhiên một tệp tin trong các ổ đĩa của máy tính này.

a) Tính xác suất để tệp tin này không bị nhiễm virus máy tính.  
b) Giả sử rằng tệp tin chọn ra kiểm tra đã bị nhiễm virus máy tính. Tính khả năng tệp tin này thuộc ổ đĩa $E$ của máy tính.

---

# BÀI GIẢI

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

### a) Tính xác suất để tệp tin chọn ra **không** bị nhiễm virus

Áp dụng **công thức xác suất đầy đủ**, xác suất để tệp tin bị nhiễm virus $P(A)$ là:

$$P(A) = P(C) \cdot P(A|C) + P(D) \cdot P(A|D) + P(E) \cdot P(A|E)$$

$$P(A) = \frac{1}{3} \cdot 0{,}02 + \frac{1}{3} \cdot 0{,}06 + \frac{1}{3} \cdot 0{,}08 = \frac{1}{3} \cdot (0{,}02 + 0{,}06 + 0{,}08)$$

$$P(A) = \frac{1}{3} \cdot 0{,}16 = \frac{0{,}16}{3} = \frac{4}{75} \approx 0{,}0533 \quad (5{,}33\%)$$

Gọi $\overline{A}$ là biến cố: "Tệp tin được chọn **không** bị nhiễm virus".  
Xác suất tệp tin không bị nhiễm virus là:

$$P(\overline{A}) = 1 - P(A) = 1 - \frac{4}{75} = \frac{71}{75} \approx 0{,}9467 \quad (94{,}67\%)$$

### b) Tính khả năng tệp tin bị nhiễm virus thuộc ổ đĩa $E$

Biết tệp tin đã bị nhiễm virus (biến cố $A$ đã xảy ra), ta cần tính xác suất điều kiện $P(E|A)$.

Áp dụng **công thức Bayes**:

$$P(E|A) = \frac{P(E) \cdot P(A|E)}{P(A)}$$

Thay các giá trị đã tính vào:

$$P(E|A) = \frac{\frac{1}{3} \cdot 0{,}08}{\frac{0{,}16}{3}} = \frac{0{,}08}{0{,}16} = \frac{1}{2} = 0{,}5 \quad (50\%)$$

**Kết luận**

a) Xác suất để tệp tin chọn ra không bị nhiễm virus là **$\frac{71}{75}$** (hoặc khoảng **$94{,}67\%$**)

b) Khả năng tệp tin bị nhiễm virus thuộc ổ đĩa $E$ là **$\frac{1}{2}$** (hoặc **$50\%$**).

