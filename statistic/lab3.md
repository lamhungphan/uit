# Bài tập chương 3

### Bài 1

Gọi $X$ là số thư mục nhiễm virus trong 6 thư mục được chọn Vì chọn không hoàn lại,

$$X \in H(20, 5, 6), \qquad X \in \{0,1,2,3,4,5\}$$

Xác suất có ít nhất 3 thư mục nhiễm virus:

$$
\begin{aligned}
P(X \ge 3)
&= \sum_{k=3}^{5} \frac{C_5^k C_{15}^{6-k}}{C_{20}^6} \\
&= \frac{C_5^3 C_{15}^3 + C_5^4 C_{15}^2 + C_5^5 C_{15}^1}{C_{20}^6} \\
&= \frac{4550 + 525 + 15}{38760}
= \frac{509}{3876}
\approx 0{,}1313
\end{aligned}
$$

Với $p = \dfrac{5}{20}$, số thư mục nhiễm virus trung bình là

$$EX = np = 6 \cdot \frac{5}{20} = 1{,}5 \text{ thư mục}$$

---

### Bài 2

Mỗi máy cần điều chỉnh với xác suất $p=0{,}1$, các máy hoạt động độc lập nên

$$X \sim B(12; 0{,}1), \qquad P(X=k)=C_{12}^k(0{,}1)^k(0{,}9)^{12-k},\quad k=0,1,\ldots,12$$

Đây là phân phối xác suất của $X$ Xác suất mỗi ngày có ít nhất 1 máy cần điều chỉnh:

$$
\begin{aligned}
P(X \ge 1)
&= 1-P(X=0) \\
&= 1-(0{,}9)^{12} \\
&\approx 0{,}7176
\end{aligned}
$$

---

### Bài 3

Gọi $X$ là số vé trúng trong 20 vé Ta có $X \sim B(20; 0{,}001)$

$$
\begin{aligned}
P(X=2)
&= C_{20}^2(0{,}001)^2(0{,}999)^{18} \\
&\approx 0{,}0001866
\end{aligned}
$$

Trung bình số vé trúng là

$$EX=np=20\cdot 0{,}001=0{,}02 \text{ vé}$$

---

### Bài 4

Xác suất một người hoàn thành các level và mua phiên bản tiếp theo là

$$p=0{,}6\cdot 0{,}3=0{,}18$$

Gọi $X$ là số người mua phiên bản tiếp theo trong 15 người Khi đó $X\sim B(15;0{,}18)$

Số người mua trung bình:

$$EX=np=15\cdot 0{,}18=2{,}7 \text{ người}$$

Xác suất có ít nhất 2 người mua:

$$
\begin{aligned}
P(X\ge 2)
&=1-P(X=0)-P(X=1)\\
&=1-(0{,}82)^{15}-C_{15}^1(0{,}18)(0{,}82)^{14}\\
&\approx 0{,}7813
\end{aligned}
$$

---

### Bài 5

Gọi $X$ là số người vào đại lý trong 1 phút Trung bình 1 phút có

$$\lambda=\frac{15}{5}=3 \text{ người}, \qquad X\sim P(3)$$

Do đó

$$
P(X=4)=\frac{e^{-3}3^4}{4!}\approx 0{,}1680
$$

---

### Bài 6

Gọi số tài khoản đăng ký trong một ngày có phân phối Poisson với tham số $\lambda=20$

**a)** Ngày mai:

$$
\begin{aligned}
P(X\ge 3)
&=1-[P(X=0)+P(X=1)+P(X=2)]\\
&=1-e^{-20}\left(1+20+\frac{20^2}{2!}\right)\\
&\approx 0{,}99999954
\end{aligned}
$$

**b)** Trong 2 ngày, tham số Poisson là $\lambda=2\cdot20=40$ Gọi $Y$ là số tài khoản đăng ký trong thời gian này:

$$
\begin{aligned}
P(Y\ge 6)
&=1-\sum_{k=0}^{5}\frac{e^{-40}40^k}{k!}\\
&\approx 0{,}999999999996
\end{aligned}
$$

---

### Bài 7

Ta có $X\sim N(166;4^2)$ và chuẩn hóa $T=\dfrac{X-166}{4}\sim N(0;1)$

1. $$P(162\le X\le170)=\varphi(1)-\varphi(-1)=2\varphi(1)-1\approx 0{,}6827$$
2. $$P(154\le X\le178)=\varphi(3)-\varphi(-3)=2\varphi(3)-1\approx 0{,}9973$$
3. $$P(X>180)=1-\varphi\left(\frac{180-166}{4}\right)=1-\varphi(3{,}5)\approx 0{,}00023$$
4. $$P(X<160)=\varphi\left(\frac{160-166}{4}\right)=\varphi(-1{,}5)\approx 0{,}0668$$

Vậy các tỷ lệ tương ứng xấp xỉ là $68{,}27\%$, $99{,}73\%$, $0{,}023\%$ và $6{,}68\%$

---

### Bài 8

Gọi $X$ là đường kính trong của vòng đệm. Ta có $X\sim N(1{,}27;0{,}01^2)$ Vòng đệm bị hỏng khi $X<1{,}25$ hoặc $X>1{,}29$

Chuẩn hóa hai giới hạn:

$$\frac{1{,}25-1{,}27}{0{,}01}=-2,\qquad \frac{1{,}29-1{,}27}{0{,}01}=2$$

Vậy tỷ lệ vòng đệm bị hỏng là

$$
\begin{aligned}
P(X<1{,}25)+P(X>1{,}29)
&=\varphi(-2)+1-\varphi(2)\\
&=2[1-\varphi(2)]\\
&\approx 0{,}0455=4{,}55\%
\end{aligned}
$$

---

### Bài 9

Vì $EX=10$, phân phối chuẩn của $X$ có $\mu=10$ Đặt $T=\dfrac{X-10}{\sigma}\sim N(0;1)$ Từ giả thiết:

$$
P(10<X<20)
=\varphi\left(\frac{10}{\sigma}\right)-\varphi(0)
=0{,}3
$$

Suy ra $\varphi\left(\dfrac{10}{\sigma}\right)=0{,}8$, nên $\dfrac{10}{\sigma}\approx0{,}8416$ và $\sigma\approx11{,}8818$

Do đó

$$
\begin{aligned}
P(0<X\le15)
&=\varphi\left(\frac{15-10}{\sigma}\right)
-\varphi\left(\frac{0-10}{\sigma}\right)\\
&=\varphi(0{,}4208)-\varphi(-0{,}8416)\\
&\approx 0{,}6631-0{,}2000\\
&\approx 0{,}4631
\end{aligned}
$$

---

### Bài 10

Ta có $X\sim N(4{,}5;1{,}21)$, nên $\mu=4{,}5$ và $\sigma=1{,}1$ Chuẩn hóa $T=\dfrac{X-4{,}5}{1{,}1}\sim N(0;1)$

**1.**

$$
\begin{aligned}
P(3{,}5\le X\le5)
&=\varphi\left(\frac{5-4{,}5}{1{,}1}\right)
-\varphi\left(\frac{3{,}5-4{,}5}{1{,}1}\right)\\
&=\varphi(0{,}4545)-\varphi(-0{,}9091)\\
&\approx0{,}4936
\end{aligned}
$$

**2.** Cần tìm $t$ sao cho $P(X>t)\le0{,}05$:

$$
1-\varphi\left(\frac{t-4{,}5}{1{,}1}\right)\le0{,}05
\iff \frac{t-4{,}5}{1{,}1}\ge1{,}645
$$

Vậy thời gian tối thiểu là

$$t=4{,}5+1{,}645\cdot1{,}1\approx6{,}31 \text{ phút}$$

---

### Bài 11

Ta có $X\sim N(4;2{,}25)$, nên $\mu=4$ và $\sigma=1{,}5$

**a.** Tỉ lệ bóng đèn có tuổi thọ từ 4,5 năm trở lên:

$$
P(X\ge4{,}5)=1-\varphi\left(\frac{4{,}5-4}{1{,}5}\right)
=1-\varphi(0{,}3333)\approx0{,}3694
$$

**b.** Vì đã biết tuổi thọ trên trung bình, xác suất cần tìm là xác suất có điều kiện:

$$
\begin{aligned}
P(X\le5\mid X>4)
&=\frac{P(4<X\le5)}{P(X>4)}\\
&=\frac{\varphi\left(\frac{5-4}{1{,}5}\right)-\varphi(0)}{1-\varphi(0)}\\
&=2\varphi(0{,}6667)-1\\
&\approx0{,}4950
\end{aligned}
$$

**c.** Xác suất một bóng đèn có tuổi thọ từ 6 năm trở lên là

$$p=P(X\ge6)=1-\varphi\left(\frac{6-4}{1{,}5}\right)
=1-\varphi(1{,}3333)\approx0{,}09121$$

Gọi $n$ là số bóng đèn cần mua Điều kiện có ít nhất một bóng tuổi thọ từ 6 năm trở lên với xác suất không nhỏ hơn $0{,}9$:

$$
\begin{aligned}
1-(1-p)^n&\ge0{,}9\\
n&\ge\frac{\ln(0{,}1)}{\ln(1-p)}
\approx24{,}075
\end{aligned}
$$

Vậy cần mua tối thiểu **25 bóng đèn**

---

### Bài 12

Gọi $X$ là đường kính trục máy Ta có $X\sim N(25;44{,}1)$, do đó $\mu=25$ và $\sigma=\sqrt{44{,}1}\approx6{,}6408$ mm Đặt $T=\dfrac{X-25}{\sqrt{44{,}1}}\sim N(0;1)$

**1.** Hai giới hạn đạt tiêu chuẩn có điểm chuẩn hóa đối xứng:

$$z=\frac{26{,}56-25}{\sqrt{44{,}1}}\approx0{,}2349$$

Tỉ lệ trục đạt tiêu chuẩn là

$$
P(23{,}44\le X\le26{,}56)
=\varphi(z)-\varphi(-z)
=2\varphi(0{,}2349)-1
\approx0{,}1857=18{,}57\%
$$

**2.** Gọi $p\approx0{,}1857$ là xác suất một trục đạt tiêu chuẩn Với $n$ trục được sản xuất độc lập:

$$
\begin{aligned}
1-(1-p)^n&\ge0{,}9973\\
n&\ge\frac{\ln(1-0{,}9973)}{\ln(1-p)}
\approx28{,}79
\end{aligned}
$$

Vậy cần sản xuất ít nhất **29 trục**

**3** Tỉ lệ đạt tiêu chuẩn trong số các trục có đường kính trên 25 mm là

$$
\begin{aligned}
P(25<X\le26{,}56\mid X>25)
&=\frac{\varphi(z)-\varphi(0)}{1-\varphi(0)}\\
&=2\varphi(0{,}2349)-1\\
&\approx0{,}1857=18{,}57\%
\end{aligned}
$$
