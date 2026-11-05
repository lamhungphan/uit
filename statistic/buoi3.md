# Chương 3. PHÂN PHỐI XÁC SUẤT THÔNG DỤNG

# §1. PHÂN PHỐI SIÊU BỘI

1.1. Định nghĩa phân phối Siêu bội
1.2. Các số đặc trưng của $X \sim H(N, N_A, n)$

## 1.1. Định nghĩa

- Xét tập có $N$ phần tử gồm $N_A$ phần tử có tính chất $A$ và $N - N_A$ phần tử có tính chất $\overline{A}$. Từ tập đó, ta chọn ra $n$ phần tử.
- Gọi $X$ là số phần tử có tính chất $A$ lẫn trong $n$ phần tử đã chọn thì $X$ có phân phối **Siêu bội** (*Hypergeometric distribution*) với 3 tham số $N$, $N_A$, $n$.

Ký hiệu là: $X \in H(N, N_A, n)$ hay $X \sim H(N, N_A, n)$.

(Hình minh họa: tập $N$ phần tử, trong đó vùng $N_A$ phần tử có tính chất $A$ và vùng $N - N_A$ còn lại; chọn $n$ phần tử trong đó có $k$ phần tử có tính chất $A$.)

$$\max\{0;\ n - (N - N_A)\} \le k \le \min\{n;\ N_A\}$$

Xác suất trong $n$ phần tử chọn ra có $k$ phần tử $A$ là:

$$p_k = P(X = k) = \frac{C_{N_A}^{k}\, C_{N - N_A}^{n-k}}{C_N^{n}}.$$

Trong đó: $0 \le k \le n$ và $n - (N - N_A) \le k \le N_A$.

**Chứng minh:**

- Số cách chọn $n$ phần tử (chọn ngẫu nhiên không hoàn lại) từ $N$ phần tử: $C_N^n$
- Số cách chọn $k$ phần tử có tính chất $A$ (từ $N_A$ phần tử): $C_{N_A}^k$
- Số cách chọn $(n - k)$ phần tử không có tính chất $A$ (từ $N - N_A$ phần tử): $C_{N - N_A}^{n-k}$

Theo định nghĩa xác suất cổ điển, ta có:

$$p_k = P(X = k) = \frac{C_{N_A}^{k}\, C_{N - N_A}^{n-k}}{C_N^{n}}$$

**VD 1.** Một hộp phấn gồm 10 viên, trong đó có 6 viên màu trắng. Lấy ngẫu nhiên 3 viên phấn từ hộp này. Gọi $X$ là số viên phấn trắng lấy được. Lập bảng phân phối xác suất của $X$?

*Giải.* Ta có: $X = \{0; 1; 2; 3\}$ và $N = 10,\ N_A = 6,\ n = 3 \Rightarrow X \in H(10, 6, 3)$.

Vậy ta có bảng phân phối xác suất của $X$:

| $X$ | 0 | 1 | 2 | 3 |
|:-:|:-:|:-:|:-:|:-:|
| $P$ | $\dfrac{C_6^0 C_4^3}{C_{10}^3}$ | $\dfrac{C_6^1 C_4^2}{C_{10}^3}$ | $\dfrac{C_6^2 C_4^1}{C_{10}^3}$ | $\dfrac{C_6^3 C_4^0}{C_{10}^3}$ |

**VD 2.** Một cửa hàng bán 10 bóng đèn, trong đó có 3 bóng hỏng. Một người chọn mua ngẫu nhiên 5 bóng đèn từ cửa hàng này. Gọi $X$ là số bóng đèn tốt người đó mua được. Tính xác suất người đó mua được 3 hoặc 4 bóng đèn tốt?

*Giải.* Ta có: $X = \{2; 3; 4; 5\}$ và $N = 10,\ N_A = 7,\ n = 5 \Rightarrow X \in H(10, 7, 5)$.

$$P[(X = 3) \cup (X = 4)] = p_3 + p_4 = \frac{C_7^3 C_3^2}{C_{10}^5} + \frac{C_7^4 C_3^1}{C_{10}^5} = \frac{5}{6}.$$

## 1.2. Các số đặc trưng của $X \sim H(N, N_A, n)$

$$EX = np; \qquad VarX = npq\,\frac{N - n}{N - 1}.$$

Trong đó $p = \dfrac{N_A}{N},\ q = 1 - p$.

**VD 3.** Tại một công trình có 100 người đang làm việc, trong đó có 70 kỹ sư. Chọn ngẫu nhiên 40 người từ công trình này. Gọi $X$ là số kỹ sư chọn được.

1. Tính xác suất chọn được từ 27 đến 29 kỹ sư?
2. Tính trung bình số kỹ sư chọn được và $VarX$?

*Giải.* Ta có: $X = \{10; 11; \dots; 39; 40\}$ và $N = 100,\ N_A = 70,\ n = 40 \Rightarrow X \in H(100, 70, 40)$.

1. $$P(27 \le X \le 29) = p_{27} + p_{28} + p_{29} = \frac{C_{70}^{27} C_{30}^{13}}{C_{100}^{40}} + \frac{C_{70}^{28} C_{30}^{12}}{C_{100}^{40}} + \frac{C_{70}^{29} C_{30}^{11}}{C_{100}^{40}} = 0{,}4955.$$
2. Ta có: $p = \dfrac{70}{100} = 0{,}7 \Rightarrow q = 0{,}3$.

   Trung bình số kỹ sư chọn được là: $EX = np = 40 \cdot 0{,}7 = 28$ (kỹ sư).

   $$VarX = npq \cdot \frac{N - n}{N - 1} = 40 \cdot 0{,}7 \cdot 0{,}3 \cdot \frac{60}{99} = \frac{56}{11}.$$

---

# §2. PHÂN PHỐI NHỊ THỨC

## 2.1. Phân phối Bernoulli

### 2.1.1. Định nghĩa

- Phép thử Bernoulli là một phép thử mà ta chỉ quan tâm đến 2 biến cố $A$ và $\overline{A}$, với $P(A) = p$.
- Xét biến ngẫu nhiên:

$$X = \begin{cases} 1 & \text{khi } A \text{ xuất hiện,} \\ 0 & \text{khi } \overline{A} \text{ xuất hiện,} \end{cases} \qquad P(\overline{A}) = 1 - p = q.$$

Khi đó, ta nói $X$ có phân phối Bernoulli với tham số $p$. Ký hiệu là $X \in B(p)$ hay $X \sim B(p)$.

Bảng phân phối xác suất của $X$ là:

| $X$ | 0 | 1 |
|:-:|:-:|:-:|
| $P$ | $q$ | $p$ |

### 2.1.2. Các số đặc trưng của $X \sim B(p)$

$$EX = p; \qquad VarX = pq.$$

**VD 1.** Một câu hỏi trắc nghiệm có 4 phương án trả lời, trong đó chỉ có 1 phương án đúng. Một sinh viên chọn ngẫu nhiên 1 phương án để trả lời câu hỏi đó.

Gọi $A$: "sinh viên này trả lời đúng". Khi đó, việc trả lời câu hỏi của sinh viên này là một phép thử Bernoulli và $p = P(A) = \dfrac{1}{4},\ q = \dfrac{3}{4}$.

Gọi BNN $X = \begin{cases} 1 & \text{khi sinh viên này trả lời đúng,} \\ 0 & \text{khi sinh viên này trả lời sai.} \end{cases}$

thì $X \in B\!\left(\dfrac{1}{4}\right)$ và $EX = \dfrac{1}{4},\ VarX = \dfrac{1}{4} \cdot \dfrac{3}{4} = \dfrac{3}{16}$.

## 2.2. Phân phối Nhị thức

### 2.2.1. Định nghĩa

- Xét dãy $n$ phép thử Bernoulli độc lập. Với phép thử thứ $i$, ta xét biến ngẫu nhiên $X_i \in B(p)$ ($i = 1, \dots, n$). Nghĩa là:

$$X_i = \begin{cases} 1 & \text{khi là biến cố } A \text{ xuất hiện,} \\ 0 & \text{khi là biến cố } \overline{A} \text{ xuất hiện.} \end{cases}$$

- Gọi $X$ là số lần biến cố $A$ xuất hiện trong $n$ phép thử. Khi đó, $X = X_1 + \dots + X_n$ và ta nói $X$ có phân phối **Nhị thức** (*Binomial distribution*) với tham số $n$, $p$.

Ký hiệu là $X \in B(n, p)$ hay $X \sim B(n, p)$.

- Xác suất trong $n$ lần thử có $k$ lần $A$ xuất hiện là:

$$p_k = P(X = k) = C_n^k\, p^k q^{n-k} \quad (k = 0, 1, \dots, n).$$

**VD 2.** Một đề thi XSTK gồm 20 câu hỏi trắc nghiệm như trong VD 1. Sinh viên $B$ làm bài một cách ngẫu nhiên. Biết rằng, nếu trả lời đúng 1 câu thì sinh viên $B$ được 0,5 điểm và nếu trả lời sai 1 câu thì bị trừ 0,125 điểm. Tính xác suất để sinh viên $B$ đạt điểm 5?

*Giải.* Gọi $x$ là số câu đúng để sinh viên $B$ đạt điểm 5.

Ta có: $0{,}5x - 0{,}125(20 - x) = 5 \Rightarrow x = 12$ (câu).

Vậy xác suất để sinh viên $B$ đạt điểm 5 là:

$$p_5 = C_{20}^{12} (0{,}25)^{12} (0{,}75)^8 \approx 0{,}0008.$$

### 2.2.2. Các số đặc trưng của $X \sim B(n, p)$

$$EX = np; \qquad VarX = npq;$$
$$ModX = x_0:\ np - q \le x_0 \le np - q + 1.$$

**VD 3.** Ông $B$ trồng 100 cây bạch đàn với xác suất cây chết là 0,02. Gọi $X$ là số cây bạch đàn chết.

1. Tính xác suất có từ 3 đến 5 cây bạch đàn chết?
2. Tính trung bình số cây bạch đàn chết và $VarX$?
3. Hỏi ông $B$ cần phải trồng tối thiểu mấy cây bạch đàn để xác suất có ít nhất 1 cây chết lớn hơn 10%?

*Giải.*

1. Ta có: $X = \{0, 1, 2, \dots, 100\}$ và $n = 100,\ p = 0{,}02 \Rightarrow X \in B(100; 0{,}02)$.

$$P(3 \le X \le 5) = p_3 + p_4 + p_5 = C_{100}^3 (0{,}02)^3 (0{,}98)^{97} + C_{100}^4 (0{,}02)^4 (0{,}98)^{96} + C_{100}^5 (0{,}02)^5 (0{,}98)^{95} = 0{,}3078.$$

2. Trung bình số cây bạch đàn chết là: $EX = np = 100 \cdot 0{,}02 = 2$ (cây).
   Phương sai là: $VarX = npq = 1{,}96$.

3. Gọi $N$ là số cây bạch đàn ông $B$ cần phải trồng. Ta có:

$$P(X \ge 1) = 1 - P(X = 0) = 1 - p_0 = 1 - C_N^0 (0{,}02)^0 (0{,}98)^N = 1 - (0{,}98)^N.$$

$$P(X \ge 1) > 0{,}1 \Leftrightarrow 1 - (0{,}98)^N > 0{,}1 \Leftrightarrow (0{,}98)^N < 0{,}9 \Leftrightarrow N \ln 0{,}98 < \ln 0{,}9 \Leftrightarrow N > 5{,}2152.$$

Vậy ông $B$ cần phải trồng ít nhất 6 cây bạch đàn.

**VD 4.** Một nhà vườn trồng 126 cây lan quý, xác suất nở hoa của mỗi cây trong 1 năm là 0,67.

1. Giá bán 1 cây lan quý nở hoa là 2 triệu đồng. Giả sử nhà vườn bán hết những cây lan nở hoa thì mỗi năm nhà vườn thu được chắc chắn nhất là bao nhiêu tiền?
2. Nếu muốn trung bình mỗi năm có nhiều hơn 100 cây lan quý nở hoa thì nhà vườn phải trồng tối thiểu mấy cây lan quý?

*Giải.* Gọi $X$ là số cây lan quý nở hoa trong 1 năm. $X = \{0, 1, 2, \dots, 126\},\ p = 0{,}67 \Rightarrow X \in B(126; 0{,}67)$.

1. Ta có $ModX = x_0$:
$$np - q \le x_0 \le np - q + 1 \Rightarrow 84{,}09 \le x_0 \le 85{,}09 \Rightarrow x_0 = 85$$
là số cây lan chắc chắn nhất sẽ nở hoa. Vậy nhà vườn thu được $85 \cdot 2 = 170$ triệu đồng.

2. Gọi $N$ là số cây lan quý nhà vườn phải trồng, ta có:
$$EX > 100 \Rightarrow N \cdot 0{,}67 > 100 \Rightarrow N > 149{,}25.$$
Vậy nhà vườn phải trồng tối thiểu 150 cây.

**VD 5.** Một nhà tuyển dụng kiểm tra kiến thức lần lượt các ứng viên, xác suất được chọn của mỗi ứng viên đều bằng 0,56. Biết xác suất để nhà tuyển dụng chọn đúng 8 ứng viên là 0,0843. Số người cần phải kiểm tra là:

A. 9 người; B. 10 người; C. 12 người; D. 13 người.

*Giải.* Gọi $n$, $n \ge 8$ là số người cần phải kiểm tra và $X$ là số người được chọn, ta có:

$$X = \{0; 1; 2; \dots; n\},\ p = 0{,}56 \Rightarrow X \in B(n; 0{,}56) \Rightarrow P(X = 8) = C_n^8 (0{,}56)^8 (0{,}44)^{n-8}.$$

Thử trực tiếp từ đáp án, ta được đáp án đúng là **B**.

**VD 6.** Một lô hàng chứa 20 sản phẩm trong đó có 4 phế phẩm. Chọn liên tiếp 3 lần (có hoàn lại) từ lô hàng, mỗi lần chọn ra 4 sản phẩm. Tính xác suất để trong 3 lần chọn có đúng 1 lần chọn phải 2 phế phẩm.

*Giải.*

- Gọi $X$ là số phế phẩm chọn phải, ta có: $X = \{0; 1; \dots; 4\},\ X \in H(20; 4; 4)$.

  Xác suất chọn phải 2 phế phẩm là:
  $$P(X = 2) = \frac{C_4^2 C_{16}^2}{C_{20}^4} = 0{,}1486.$$

- Gọi $Y$ là số lần chọn phải 2 phế phẩm trong 3 lần.

  Do chọn có hoàn lại nên mỗi lần chọn là độc lập với xác suất $p = 0{,}1486 \Rightarrow Y \in B(3; 0{,}1486)$.

  Vậy xác suất trong 3 lần chọn có 1 lần đạt yêu cầu là:
  $$p_1 = C_3^1 \cdot 0{,}1486 \cdot (1 - 0{,}1486)^2 = 0{,}3232.$$

---

# §3. PHÂN PHỐI POISSON

## 3.1. Bài toán dẫn đến phân phối Poisson

- Giả sử các vụ tai nạn giao thông ở vùng $A$ xảy ra một cách ngẫu nhiên, độc lập với nhau và trung bình 1 ngày có $\lambda$ vụ tai nạn. Gọi $X$ là số vụ tai nạn giao thông xảy ra trong 1 ngày ở vùng $A$.
- Chia 24 giờ trong ngày thành $n$ khoảng thời gian sao cho ta có thể coi rằng trong mỗi khoảng thời gian đó có nhiều nhất 1 vụ tai nạn xảy ra, và khả năng xảy ra tai nạn giao thông trong mỗi khoảng thời gian bằng $\dfrac{\lambda}{n}$.

Khi đó, $X \in B\!\left(n, \dfrac{\lambda}{n}\right)$.

- Ta có:

$$\begin{aligned}
P(X = k) &= C_n^k \left(\frac{\lambda}{n}\right)^k \left(1 - \frac{\lambda}{n}\right)^{n-k} \\
&= \frac{n!}{k!(n-k)!} \cdot \frac{\lambda^k}{n^k} \cdot \frac{1}{(n - \lambda)^k \cdot n^{-k}} \cdot \left(1 - \frac{\lambda}{n}\right)^n \\
&= \frac{\lambda^k}{k!} \cdot \frac{n(n-1)\dots(n-k+1)}{(n - \lambda)^k} \cdot \left(1 - \frac{\lambda}{n}\right)^n.
\end{aligned}$$

Suy ra:

$$P(X = k) \xrightarrow{\ n \to \infty\ } \frac{\lambda^k}{k!} \cdot e^{-\lambda}.$$

## 3.2. Định nghĩa phân phối Poisson

Biến ngẫu nhiên $X$ được gọi là có phân phối Poisson tham số $\lambda > 0$, ký hiệu là $X \in P(\lambda)$ hay $X \sim P(\lambda)$, nếu $X$ nhận các giá trị $0, 1, 2, \dots, n, \dots$ với xác suất

$$p_k = P(X = k) = \frac{e^{-\lambda} \cdot \lambda^k}{k!} \quad (k = 0, 1, \dots, n, \dots)$$

trong đó $\lambda$ là trung bình số lần xuất hiện biến cố nào đó mà ta quan tâm.

**Nhận xét**

- Phân phối Poisson không phải là phân phối xác suất chính xác. Tuy vậy, phân phối Poisson rất thuận tiện cho việc mô tả và tính toán.
- Phân phối Poisson thường gắn với yếu tố thời gian.

> Siméon Denis Poisson (1781 – 1840).

## 3.3. Các số đặc trưng của $X \sim P(\lambda)$

$$EX = VarX = \lambda; \qquad ModX = x_0:\ \lambda - 1 \le x_0 \le \lambda.$$

**VD 1.** Quan sát tại siêu thị $A$ thấy trung bình 5 phút có 18 khách đến mua hàng.

1. Tính xác suất để trong 7 phút có 25 khách đến siêu thị $A$?
2. Tính xác suất để trong 2 phút có từ 3 đến 5 khách đến siêu thị $A$?
3. Tính số khách chắc chắn nhất sẽ đến siêu thị $A$ trong 1 giờ?

*Giải.* Gọi $X$ là số khách đến siêu thị $A$ mua hàng. Ta có: $X = \{0; 1; 2; \dots\},\ X \in P(\lambda)$.

1. Cứ 5 phút có 18 khách đến mua hàng, 7 phút có $\lambda$ khách đến mua hàng $\Rightarrow \lambda = 25{,}2$.
$$\text{Vậy } P(X = 25) = e^{-25{,}2} \cdot \frac{(25{,}2)^{25}}{25!} = 0{,}0795.$$

2. Ta có: $\lambda = 7{,}2$.
$$\text{Vậy } P(3 \le X \le 5) = p_3 + p_4 + p_5 = e^{-7{,}2}\left[\frac{(7{,}2)^3}{3!} + \frac{(7{,}2)^4}{4!} + \frac{(7{,}2)^5}{5!}\right] = 0{,}2504.$$

3. Ta có: $\lambda = \dfrac{60 \times 18}{5} = 216 \Rightarrow \lambda - 1 \le ModX \le \lambda \Rightarrow ModX = 215 \lor 216$.

   Vậy có 215 hay 216 khách chắc chắn nhất sẽ đến siêu thị $A$ mua hàng trong 1 giờ.

**VD 2.** Quan sát thấy trung bình 1 phút có 3 ôtô đi qua trạm thu phí. Biết xác suất có ít nhất 1 ôtô đi qua trạm thu phí trong $t$ phút bằng 0,9. Giá trị của $t$ là:

A. 0,9082 phút; B. 0,8591 phút; C. 0,8514 phút; D. 0,7675 phút.

*Giải.* Gọi $X$ là số ôtô đi qua trạm thu phí trong $t$ phút. Ta có: $X \in P(3t)$.

$$P(X \ge 1) = 1 - p_0 \Rightarrow 0{,}9 = 1 - e^{-3t} \Rightarrow e^{-3t} = 0{,}1 \Rightarrow -3t = \ln(0{,}1) \Rightarrow t = 0{,}7675 \Rightarrow \textbf{D}.$$

**VD 3.** Quan sát thấy trung bình 1 ngày (24 giờ) có 12 chuyến tàu vào cảng $A$. Chọn ngẫu nhiên liên tiếp 6 giờ trong 1 ngày. Tính xác suất để 2 trong 6 giờ ấy, mỗi giờ có đúng 1 tàu vào cảng $A$.

*Giải.* Gọi $X$ là số tàu vào cảng $A$ trong 1 giờ, ta có:

$$X \in P(0{,}5) \Rightarrow P(X = 1) = \frac{e^{-0{,}5} \cdot (0{,}5)^1}{1!} = 0{,}3033.$$

Gọi $Y$ là số lần có đúng 1 tàu vào cảng $A$ mỗi giờ trong 6 giờ đã chọn.

Số tàu vào cảng $A$ trong mỗi giờ là độc lập với xác suất $p = P(X = 1) = 0{,}3033 \Rightarrow Y \in B(6; 0{,}3033)$.

$$\text{Vậy } p_2 = C_6^2 \cdot (0{,}3033)^2 \cdot (1 - 0{,}3033)^4 = 0{,}3251.$$

---

# §4. PHÂN PHỐI CHUẨN

4.1. Phân phối Chuẩn đơn giản
&nbsp;&nbsp;&nbsp;&nbsp;4.1.1. Định nghĩa
&nbsp;&nbsp;&nbsp;&nbsp;4.1.2. Các số đặc trưng của $T \sim N(0; 1)$
&nbsp;&nbsp;&nbsp;&nbsp;4.1.3. Xác suất của $T \sim N(0; 1)$
4.2. Phân phối Chuẩn
&nbsp;&nbsp;&nbsp;&nbsp;4.2.1. Định nghĩa
&nbsp;&nbsp;&nbsp;&nbsp;4.2.2. Các số đặc trưng của $X \sim N(\mu; \sigma^2)$
&nbsp;&nbsp;&nbsp;&nbsp;4.2.3. Xác suất của $X \sim N(\mu; \sigma^2)$

## 4.1. Phân phối Chuẩn đơn giản

### a) Định nghĩa

Biến ngẫu nhiên liên tục $T$ được gọi là có phân phối Chuẩn đơn giản (hay *phân phối **Gauss***), ký hiệu là $T \in N(0; 1)$ hay $T \sim N(0; 1)$, nếu hàm mật độ xác suất của $T$ có dạng:

$$f(t) = \frac{1}{\sqrt{2\pi}}\, e^{-\frac{t^2}{2}}, \quad t \in \mathbb{R}.$$

### b) Các số đặc trưng của $T \sim N(0; 1)$

$$ModT = ET = 0; \qquad VarT = 1.$$

### c) Xác suất của $T \sim N(0; 1)$

**Hàm Laplace**

Hàm $\varphi(x) = \displaystyle\int_{-\infty}^{x} f(t)\,dt$ được gọi là hàm Laplace.

**Tính chất của hàm Laplace**

- Hàm $\varphi(x)$ đồng biến trên $\mathbb{R}$;
- $\varphi(-\infty) = 0;\ \varphi(0) = 0{,}5;\ \varphi(+\infty) = 1$
- $\varphi(x) + \varphi(-x) = 1$

**Công thức tính xác suất**

$$P(a \le T \le b) = \int_a^b f(t)\,dt = \varphi(b) - \varphi(a).$$

**Chú ý**

- $P(T < b) = P(T \le b) = \varphi(b)$
- $P(T > a) = P(T \ge a) = 1 - P(T < a) = 1 - \varphi(a)$
- $x \ge 3{,}9 \Rightarrow \varphi(x) = 1;\ x \le -3{,}9 \Rightarrow \varphi(x) = 0$

Tìm giá trị của hàm $\varphi(x)$ bằng cách tra bảng A4. (Table A4. Standard Normal distribution)

## 4.2. Phân phối Chuẩn

### a) Định nghĩa

Biến ngẫu nhiên liên tục $X$ được gọi là có phân phối Chuẩn (*Normal distribution*) tham số $\mu$ và $\sigma^2$ ($\sigma > 0$), ký hiệu là $X \in N(\mu; \sigma^2)$ hay $X \sim N(\mu; \sigma^2)$, nếu hàm mật độ xác suất của $X$ có dạng:

$$f(x) = \frac{1}{\sigma\sqrt{2\pi}}\, e^{-\frac{(x - \mu)^2}{2\sigma^2}}, \quad x \in \mathbb{R}.$$

### b) Các số đặc trưng của $X \sim N(\mu, \sigma^2)$

$$ModX = EX = \mu; \qquad VarX = \sigma^2.$$

### c) Xác suất của $X \sim N(\mu, \sigma^2)$

Nếu $X \in N(\mu; \sigma^2)$ thì $T = \dfrac{X - \mu}{\sigma} \in N(0; 1)$.

Vậy, ta có công thức tính xác suất:

$$P(a \le X \le b) = \varphi\!\left(\frac{b - \mu}{\sigma}\right) - \varphi\!\left(\frac{a - \mu}{\sigma}\right).$$

(Hình: đồ thị mật độ $f(x) = \dfrac{1}{\sigma\sqrt{2\pi}} e^{-\frac{(x-\mu)^2}{2\sigma^2}}$ đối xứng quanh $\mu$, độ rộng $\sigma$; qua phép đổi biến $T = \dfrac{X - \mu}{\sigma}$ trở thành đồ thị $f(t) = \dfrac{1}{\sqrt{2\pi}} e^{-\frac{t^2}{2}}$ với $\mu = 0$.)

**Phân bố xác suất** (quy tắc theo $\sigma$):

| Khoảng | Xác suất |
|---|---|
| $[\mu - \sigma;\ \mu]$ và $[\mu;\ \mu + \sigma]$ | 34,1% mỗi bên |
| $[\mu - 2\sigma;\ \mu - \sigma]$ và $[\mu + \sigma;\ \mu + 2\sigma]$ | 13,6% mỗi bên |
| $[\mu - 3\sigma;\ \mu - 2\sigma]$ và $[\mu + 2\sigma;\ \mu + 3\sigma]$ | 2,1% mỗi bên |
| Ngoài $[\mu - 3\sigma;\ \mu + 3\sigma]$ | 0,1% mỗi bên |

> Phân phối chuẩn do **Carl F. Gauss** đưa ra năm 1795. Carl Friedrich Gauss (1777 – 1855).

**VD 1.** Tốc độ chuyển dữ liệu từ máy chủ của ký túc xá đến máy tính của sinh viên vào buổi sáng chủ nhật có phân phối chuẩn với trung bình 60Kbits/s và độ lệch chuẩn 4Kbits/s. Xác suất để tốc độ chuyển dữ liệu lớn hơn 63Kbits/s là:

A. 0,2266; B. 0,2144; C. 0,1313; D. 0,1060.

*Giải.* Gọi $X$ (Kbits/s) là tốc độ chuyển dữ liệu. Ta có: $\mu = 60,\ \sigma = 4 \Rightarrow X \in N(60; 4^2)$.

$$P(X > 63) = P(63 < X < +\infty) = \varphi(+\infty) - \varphi\!\left(\frac{63 - 60}{4}\right) = 1 - \varphi(0{,}75) = 1 - 0{,}7734 = 0{,}2266 \Rightarrow \textbf{A}.$$

**VD 2.** Một kỳ thi đầu vào ở trường chuyên $A$ quy định điểm đỗ là tổng số điểm các môn thi không được thấp hơn 15 điểm. Giả sử tổng điểm các môn thi của học sinh là biến ngẫu nhiên có phân phối chuẩn với trung bình 12 điểm. Biết rằng tỉ lệ học sinh thi đỗ là 25,14%. Độ lệch chuẩn là:

A. 4 điểm; B. 4,5 điểm; C. 5 điểm; D. 5,5 điểm.

*Giải.* Gọi $X$ là tổng điểm thi của HS $\Rightarrow X \in N(12; \sigma^2)$. Ta có:

$$0{,}2514 = P(X \ge 15) = 1 - \varphi\!\left(\frac{15 - 12}{\sigma}\right) \Rightarrow \varphi\!\left(\frac{3}{\sigma}\right) = 0{,}7486 = \varphi(0{,}67) \Rightarrow \sigma = \frac{3}{0{,}67} = 4{,}5 \Rightarrow \textbf{B}.$$

**VD 3.** Tuổi thọ của 1 loại máy lạnh $A$ là BNN $X$ (năm) có phân phối $N(10; 6{,}25)$. Khi bán 1 máy lạnh $A$ thì lãi được 1,4 triệu đồng nhưng nếu máy lạnh phải bảo hành thì lỗ 1,8 triệu đồng. Vậy để có tiền lãi trung bình khi bán mỗi máy lạnh loại này là 0,9 triệu đồng thì cần phải quy định thời gian bảo hành là bao nhiêu?

*Giải.* Gọi $Y$ (triệu đồng) là tiền lãi có được khi bán 1 máy lạnh $A$ và $t$ (năm) là thời gian bảo hành.

- Xác suất (tỉ lệ) máy lạnh phải bảo hành là:
$$p = P(X \le t) = \varphi\!\left(\frac{t - 10}{2{,}5}\right).$$

- Bảng phân phối xác suất của $Y$:

| $Y$ | $-1{,}8$ | $1{,}4$ |
|:-:|:-:|:-:|
| $P$ | $p$ | $1 - p$ |

$$\Rightarrow EY = -1{,}8 \cdot p + 1{,}4 \cdot (1 - p) = 1{,}4 - 3{,}2p.$$

- $EY = 0{,}9 \Rightarrow p = 0{,}1563 \Rightarrow P(X \le t) = 0{,}1563$

$$\Rightarrow \varphi\!\left(\frac{t - 10}{2{,}5}\right) = 0{,}1563 \approx \varphi(-1{,}01) \Rightarrow \frac{t - 10}{2{,}5} = -1{,}01 \Rightarrow t = 7{,}475 \text{ (năm)}.$$

## Phân phối Chi bình phương $\chi^2(n)$ (tham khảo)

Nếu $X_i \in N(0; 1)$ ($i = 1, \dots, n$) và các $X_i$ độc lập thì

$$X = \sum_{i=1}^{n} X_i^2 \in \chi^2(n)$$

với hàm mật độ xác suất:

$$f(x) = \begin{cases} 0, & x \le 0 \\[4pt] \dfrac{1}{2^{n/2} \cdot \Gamma\!\left(\dfrac{n}{2}\right)} \cdot e^{-\frac{x}{2}}\, x^{\frac{n}{2} - 1}, & x > 0. \end{cases}$$

Trong đó: $\Gamma(n) = \displaystyle\int_0^{+\infty} e^{-x} x^{n-1}\,dx$, $\Gamma(n+1) = n\Gamma(n)$, $\Gamma\!\left(\dfrac{1}{2}\right) = \sqrt{\pi}$, $\Gamma(1) = 1$.

> Phân phối $\chi^2(n)$ do Karl Pearson đưa ra năm 1900. Karl Pearson (1857 – 1936).

## Phân phối Student $St(n)$ (tham khảo)

Nếu $T \in N(0; 1)$ và $Y \in \chi^2(n)$ độc lập thì

$$X = T\sqrt{\frac{n}{Y}} \in St(n)$$

với hàm mật độ xác suất:

$$f(x) = \frac{\Gamma\!\left(\dfrac{n+1}{2}\right)}{\sqrt{n\pi}\cdot\Gamma\!\left(\dfrac{n}{2}\right)} \left(1 + \frac{x^2}{n}\right)^{-\frac{n+1}{2}}, \quad x \in \mathbb{R}.$$

Trong đó, $n$ được gọi là bậc tự do.

> Phân phối $St(n)$ do Willam S. Gosset đưa ra năm 1908. Willam Sealy Gosset (1876 – 1937).

---

# BÀI TẬP

**Câu 1:** Một máy tính có 20 thư mục trong đó có 5 thư mục bị nhiễm virus. Chọn ngẫu nhiên 6 thư mục để kiểm tra xem có bị nhiễm virus hay không.

a) Tính xác suất có ít nhất 3 thư mục bị nhiễm virus.
b) Trung bình có bao nhiêu thư mục bị nhiễm trong 6 thư mục được chọn?

**Câu 2:** Một kĩ thuật viên theo dõi 12 máy tự động. Xác suất để mỗi máy cần đến sự điều chỉnh của kĩ thuật viên trong mỗi ngày là 0.1. Các máy này hoạt động độc lập nhau.

a) Gọi $X$ là số máy cần sự điều chỉnh mỗi ngày. Tìm phân phối xác suất của $X$.
b) Tìm xác suất mỗi ngày có ít nhất 1 máy cần điều chỉnh.

**Câu 3:** Xác suất trúng mỗi tờ vé số là 0.001.

a) Hỏi nếu mua 20 tờ vé số thì xác suất trúng 2 tờ là bao nhiêu?
b) Hỏi trung bình mua 20 tờ vé số thì trúng bao nhiêu tờ?

**Câu 4:** Có một trò chơi điện tử được phát hành. 60% người chơi hoàn thành được hết các level và có 30% trong số đó sau đó mua phiên bản tiếp theo. Hỏi trung bình trong 15 người chơi, có bao nhiêu người mua phiên bản tiếp theo? Xác suất có ít nhất 2 người chơi sẽ mua phiên bản mới trong 15 người chơi?

**Câu 5:** Trung bình 5 phút có 15 người vào một đại lý bưu điện. Tính xác suất trong 1 phút có 4 người vào đại lý bưu điện đó. Biết rằng số người vào đại lý là một ĐLNN rời rạc có phân phối Poisson.

**Câu 6:** Một công ty cung cấp dịch vụ internet có trung bình 20 khách hàng đăng kí tài khoản mới mỗi ngày. Biết rằng số tài khoản mới đăng kí mỗi ngày có phân phối Poisson.

a) Tính xác suất có ít nhất 3 tài khoản mới đăng kí ra trong ngày mai.
b) Tính xác suất có ít nhất 6 tài khoản mới đăng kí trong 2 ngày tới.

**Câu 7:** Nếu chiều cao $X$ của sinh viên nam có phân phối chuẩn với trung bình 166cm, độ lệch chuẩn 4cm, thì có bao nhiêu % sinh viên nam có chiều cao

1. từ 162cm đến 170cm;
2. từ 154cm đến 178cm;
3. trên 180cm;
4. dưới 160cm.

**Câu 8:** Giả sử đường kính trong của các vòng đệm cao su do một máy sản xuất có phân phối chuẩn, với đường kính trong trung bình là 1.27cm và độ lệch chuẩn là 0.01cm. Đường kính trong của các vòng đệm này được phép có dung sai từ 1,25 đến 1,29 cm, ngược lại thì các vòng đệm được xem bị hỏng. Hãy xác định tỷ lệ phần trăm các vòng đệm do máy này sản xuất bị hỏng.

**Câu 9:** Cho BNN $X$ có phân phối chuẩn với $EX = 10$ và $P(10 < X < 20) = 0{,}3$. Tính $P(0 < X \le 15)$?

**Câu 10:** Giả sử thời gian khách phải chờ để được phục vụ tại một cửa hàng là BNN $X$ (phút), $X \in N(4{,}5;\ 1{,}21)$.

1. Tính xác suất khách phải chờ từ 3,5 phút đến 5 phút.
2. Tính thời gian tối thiểu $t$ nếu xác suất khách phải chờ vượt quá $t$ là không quá 5%.

**Câu 11:** Tuổi thọ $X$ (năm) của một loại bóng đèn $A$ là BNN tuân theo luật phân phối chuẩn $N(4;\ 2.25)$.

a. Tính tỉ lệ bóng đèn $A$ có tuổi thọ từ 4.5 năm trở lên.
b. Quan sát ngẫu nhiên 1 bóng đèn loại $A$ thấy nó có tuổi thọ trên tuổi thọ trung bình. Hãy tính xác suất bóng đèn đó có tuổi thọ không quá 5 năm.
c. Cần mua bao nhiêu bóng đèn loại $A$ để xác suất mua được ít nhất 1 bóng có tuổi thọ từ 6 năm trở lên không nhỏ hơn 90%.

**Câu 12:** Đường kính của một loại trục máy do máy tiện làm ra là một đại lượng ngẫu nhiên có phân phối chuẩn, với giá trị trung bình là 25 mm, và phương sai là 44,1 mm². Trục máy được xem là đạt tiêu chuẩn kỹ thuật nếu đường kính nằm trong khoảng từ 23,44 mm đến 26,56 mm.

1. Tìm tỉ lệ trục máy đạt tiêu chuẩn kỹ thuật.
2. Phải sản xuất ít nhất bao nhiêu trục để khả năng có ít nhất 1 trục đạt tiêu chuẩn kỹ thuật không dưới 99,73 %.
3. Tính tỉ lệ trục máy đạt tiêu chuẩn kỹ thuật trong số các trục máy có đường kính trên 25 mm.
