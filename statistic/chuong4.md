# Chương 4. ĐỊNH LÝ GIỚI HẠN TRONG XÁC SUẤT

# §1. MỘT SỐ LOẠI HỘI TỤ TRONG XÁC SUẤT VÀ CÁC ĐỊNH LÝ (tham khảo)

## 1.1. Hội tụ theo xác suất – Luật số lớn

### a) Định nghĩa

- Dãy các biến ngẫu nhiên $\{X_i\}$ ($i = 1, \dots, n, \dots$) được gọi là ***hội tụ theo xác suất*** đến biến ngẫu nhiên $X$ nếu:

$$\forall \omega \in \Omega,\ \forall \varepsilon > 0:\ \lim_{n \to \infty} P\big(|X_n(\omega) - X(\omega)| \ge \varepsilon\big) = 0.$$

Ký hiệu: $X_n \xrightarrow{\ P\ } X\ (n \to \infty)$.

- Dãy các biến ngẫu nhiên $\{X_i\}$ ($i = 1, \dots, n, \dots$) được gọi là tuân theo ***luật số lớn*** (dạng Tchébyshev) nếu:

$$\forall \varepsilon > 0:\ \lim_{n \to \infty} P\left(\left|\frac{1}{n}\sum_{i=1}^{n} X_i - \frac{1}{n}\sum_{i=1}^{n} EX_i\right| < \varepsilon\right) = 1.$$

### b) Định lý (*Bất đẳng thức Tchébyshev*)

Nếu biến ngẫu nhiên $X$ có $EX = \mu$ và $VarX = \sigma^2$ thì:

$$\forall \varepsilon > 0:\ P\big(|X - \mu| \ge \varepsilon\big) \le \frac{\sigma^2}{\varepsilon^2} \iff P\big(|X - \mu| < \varepsilon\big) \ge 1 - \frac{\sigma^2}{\varepsilon^2}.$$

***Chứng minh***

- Nếu $X$ là biến ngẫu nhiên rời rạc, ta có:

$$\begin{aligned}
\sigma^2 &= \sum_x (x - \mu)^2 f(x) \\
&= \sum_{|x - \mu| < \varepsilon} (x - \mu)^2 f(x) + \sum_{|x - \mu| \ge \varepsilon} (x - \mu)^2 f(x) \\
&\ge \sum_{|x - \mu| \ge \varepsilon} (x - \mu)^2 f(x) \\
&\ge \varepsilon^2 \sum_{|x - \mu| \ge \varepsilon} f(x) = \varepsilon^2 P\big(|X - \mu| \ge \varepsilon\big).
\end{aligned}$$

- Nếu $X$ là biến ngẫu nhiên liên tục, ta có:

$$\begin{aligned}
\sigma^2 &= \int_{-\infty}^{+\infty} (x - \mu)^2 f(x)\,dx \\
&= \int_{|x - \mu| < \varepsilon} (x - \mu)^2 f(x)\,dx + \int_{|x - \mu| \ge \varepsilon} (x - \mu)^2 f(x)\,dx \\
&\ge \int_{|x - \mu| \ge \varepsilon} (x - \mu)^2 f(x)\,dx \\
&\ge \varepsilon^2 \int_{|x - \mu| \ge \varepsilon} f(x)\,dx = \varepsilon^2 P\big(|X - \mu| \ge \varepsilon\big).
\end{aligned}$$

Vậy $\sigma^2 \ge \varepsilon^2 P\big(|X - \mu| \ge \varepsilon\big) \iff P\big(|X - \mu| \ge \varepsilon\big) \le \dfrac{\sigma^2}{\varepsilon^2}$ ∎

***Ý nghĩa của định lý***

Với mọi số $\varepsilon > 0$ cho trước, xác suất để $X$ nhận giá trị trong khoảng $(\mu - \varepsilon;\ \mu + \varepsilon)$ ít nhất phải bằng $1 - \dfrac{\sigma^2}{\varepsilon^2}$.

### c) Định lý luật số lớn Tchébyshev

**Định lý**

Nếu dãy các BNN $\{X_i\}$ ($i = 1, \dots, n, \dots$) độc lập từng đôi có $EX_i$ hữu hạn và $VarX_i \le C$ (hằng số) thì:

$$\forall \varepsilon > 0:\ \lim_{n \to \infty} P\left(\left|\frac{1}{n}\sum_{i=1}^{n} X_i - \frac{1}{n}\sum_{i=1}^{n} EX_i\right| \ge \varepsilon\right) = 0.$$

**Hệ quả**

Nếu dãy các BNN $\{X_i\}$ ($i = 1, \dots, n, \dots$) độc lập từng đôi có $EX_i = \mu$ và $VarX_i = \sigma^2$ thì

$$\frac{1}{n}\sum_{i=1}^{n} X_i \xrightarrow{\ P\ } \mu.$$

**Ý nghĩa của định lý**

- Thể hiện tính ổn định của trung bình các BNN độc lập cùng phân phối và có phương sai hữu hạn.
- Để đo một đại lượng vật lý nào đó, ta đo $n$ lần và lấy trung bình các kết quả làm giá trị thực của đại lượng cần đo.
- Áp dụng trong thống kê là: dựa vào một mẫu khá nhỏ để kết luận tổng thể.

## 1.2. Hội tụ yếu – Định lý giới hạn trung tâm

### a) Định nghĩa

Dãy các biến ngẫu nhiên $\{X_i\}$ ($i = 1, \dots, n, \dots$) được gọi là ***hội tụ yếu*** hay ***hội tụ theo phân phối*** đến biến ngẫu nhiên $X$ nếu $\displaystyle\lim_{n \to \infty} F_n(x) = F(x),\ \forall x \in C(F)$.

Trong đó, $C(F)$ là tập các điểm liên tục của $F(x)$.

Ký hiệu: $X_n \xrightarrow{\ d\ } X$ hay $F_n \xrightarrow{\ d\ } F$.

***Chú ý***

Nếu $X_n \xrightarrow{\ P\ } X$ thì $X_n \xrightarrow{\ d\ } X$.

### b) Định lý giới hạn trung tâm (*định lý Liapounop*)

Cho dãy BNN $\{X_i\}$ ($i = 1, \dots, n, \dots$) độc lập từng đôi.

Đặt $Y = \displaystyle\sum_{i=1}^{n} X_i,\ \mu = \sum_{i=1}^{n} EX_i,\ \sigma^2 = \sum_{i=1}^{n} VarX_i$.

Nếu $EX_i$, $VarX_i$ hữu hạn, $\displaystyle\lim_{n \to \infty} \sum_{i=1}^{n} \frac{E|X_i - EX_i|^3}{\sigma^3} = 0$ thì $Y \in N(\mu,\ \sigma^2)$.

**Ý nghĩa của định lý**

- Sử dụng định lý giới hạn trung tâm Liapounop để tính xấp xỉ (gần đúng) xác suất.
- Xác định các phân phối xấp xỉ để giải quyết các vấn đề của lý thuyết ước lượng, kiểm định,…

---

# §2. CÁC LOẠI XẤP XỈ PHÂN PHỐI XÁC SUẤT

## 2.1. Xấp xỉ phân phối Siêu bội bởi Nhị thức

Xét BNN $X$ có phân phối Siêu bội $H(N;\ N_A;\ n)$.

- Nếu $n$ cố định, $N \to \infty$ và $\dfrac{N_A}{N} \to p$ ($0 \ne p \ne 1$) thì:

$$\frac{C_{N_A}^{k}\, C_{N - N_A}^{n-k}}{C_N^{n}} \xrightarrow{\ d\ } C_n^k\, p^k q^{n-k}.$$

**Ứng dụng xấp xỉ phân phối Siêu bội bằng Nhị thức**

- Cho $X \in H(N;\ N_A;\ n)$. Nếu $N$ khá lớn và $n$ rất nhỏ so với $N$ ($n < 5\% \cdot N$) thì:

$$X \sim B(n;\ p),\quad p = \frac{N_A}{N}.$$

***Chú ý***

Khi cỡ mẫu $n$ khá nhỏ so với kích thước $N$ (khoảng $5\%N$) của tổng thể thì việc lấy mẫu có hoàn lại hay không hoàn lại là như nhau.

(Hình: so sánh hai biểu đồ cột. Đỏ: $X \in H(10.000;\ 4.000;\ 10)$, Xanh: $X \in B(10;\ 0{,}4)$; hai biểu đồ gần như trùng nhau.)

**VD 1.** Một vườn lan có 10.000 cây sắp nở hoa, trong đó có 1.000 cây hoa màu đỏ.

1. Tính xác suất để khi chọn ngẫu nhiên 20 cây lan thì được 5 cây có hoa màu đỏ.
2. Tính xác suất để khi chọn ngẫu nhiên 50 cây lan thì được 10 cây có hoa màu đỏ.
3. Có thể tính xác suất để khi chọn ngẫu nhiên 200 cây lan thì có 50 cây hoa màu đỏ được không?

*Giải.*

1. Gọi $X$ là số cây lan màu đỏ chọn được, ta có: $X \in H(10.000;\ 1.000;\ 20)$.

   Vì $n = 20$ rất nhỏ so với $N = 10.000$ nên: với $p = \dfrac{1.000}{10.000} = 0{,}1$ thì $X \sim B(20;\ 0{,}1)$.

   $$\text{Vậy } P(X = 5) \approx C_{20}^5 (0{,}1)^5 (0{,}9)^{15} = 0{,}0319.$$

   ***Nhận xét.*** Nếu dùng công thức của phân phối Siêu bội thì:
   $$P(X = 5) = \frac{C_{1.000}^5\, C_{9.000}^{15}}{C_{10.000}^{20}} = 0{,}0318.$$

2. Tương tự, ta có: $X \sim B(50;\ 0{,}1)$.
   $$\text{Vậy } P(X = 10) \approx C_{50}^{10} (0{,}1)^{10} (0{,}9)^{40} = 0{,}0152.$$

## 2.2. Xấp xỉ phân phối Nhị thức bởi Poisson

Xét biến ngẫu nhiên $X$ có phân phối Nhị thức $B(n;\ p)$.

- Khi $n \to \infty$, nếu $p \to 0$ và $np \to \lambda$ thì:

$$C_n^k\, p^k q^{n-k} \xrightarrow{\ d\ } \frac{e^{-\lambda} \cdot \lambda^k}{k!}.$$

***Ứng dụng.*** Cho $X$ có phân phối nhị thức $B(n, p)$, $\lambda = np$.

- Nếu $n$ lớn và $p$ khá bé ($p \approx 0$) thì: $X \sim P(\lambda)$.

  Cụ thể: $p \le 5\%$, $n \ge 30$ và $np < 5$.

- Nếu $n$ lớn và $p$ cũng khá lớn ($p \approx 1$) thì: $X \sim P(\lambda)$.

(Hình: so sánh hai biểu đồ cột. Xanh: $X \in B(1.000;\ 0{,}005)$, Đỏ: $X \in P(5)$; hai biểu đồ gần như trùng nhau.)

**VD 2.** Một lô hàng thịt đông lạnh đóng gói nhập khẩu có chứa 0,4% bị nhiễm khuẩn. Tìm xác suất để khi chọn ngẫu nhiên 1.000 gói thịt từ lô hàng này có:

1. không quá 2 gói bị nhiễm khuẩn;
2. đúng 34 gói bị nhiễm khuẩn.

*Giải.* Gọi $X$ là số gói thịt bị nhiễm khuẩn, ta có: $X \in B(1.000;\ 0{,}004)$.

Vì $\lambda = np = 4 < 5$ nên $X \sim P(4)$.

1. $$P(X \le 2) \approx p_0 + p_1 + p_2 = e^{-4}\left(\frac{4^0}{0!} + \frac{4^1}{1!} + \frac{4^2}{2!}\right) = 0{,}2381.$$

   ***Nhận xét.*** Nếu dùng công thức của phân phối Nhị thức thì:
   $$P(X \le 2) = 0{,}996^{1000} + 1000 \cdot 0{,}004 \cdot (0{,}996)^{999} + C_{1000}^2 (0{,}004)^2 (0{,}996)^{998} = 0{,}2375.$$

2. $$P(X = 34) \approx p_{34} = e^{-4} \cdot \frac{4^{34}}{34!} = 1{,}831 \cdot 10^{-20}.$$

**VD 3.** Giải câu 3) trong VD 1.

*Giải.* Ta có: $X \in H(10.000;\ 1.000;\ 200)$.

Ta xấp xỉ $X \sim B(200;\ 0{,}1)$, với $p = 0{,}1$.

Tiếp tục xấp xỉ $X \sim P(20)$, với $\lambda = np = 20$.

$$\text{Vậy } P(X = 50) \approx p_{50} = e^{-20} \cdot \frac{20^{50}}{50!} = 7{,}6 \cdot 10^{-9}.$$

### Tóm tắt các loại xấp xỉ rời rạc

- $X \in H(N, N_A, n)$ → $X \in B(n, p)$ với $p = \dfrac{N_A}{N}$, khi $n < 5\%N$.
- $X \in B(n, p)$ → $X \in P(\lambda)$ với $\lambda = np$, khi $np < 5$ hoặc $nq < 5$.
- $X \in H(N, N_A, n)$ → $X \in P(\lambda)$ với $\lambda = n \cdot \dfrac{N_A}{N}$ (đi thẳng): **sai số rất lớn**.

## 2.3. Xấp xỉ phân phối Nhị thức bởi phân phối Chuẩn

### a) Định lý giới hạn địa phương Moivre – Laplace

Xét biến ngẫu nhiên $X$ có phân phối Nhị thức $B(n;\ p)$ ($p$ không quá gần 0 và không quá gần 1).

Với $k = 0, 1, \dots, n$ bất kỳ và $x = \dfrac{k - np}{\sqrt{npq}}$, ta có:

$$\lim_{n \to \infty} \frac{\sqrt{npq} \cdot P_n(X = k)}{\dfrac{1}{\sqrt{2\pi}}\, e^{-\frac{x^2}{2}}} = 1.$$

### b) Định lý giới hạn tích phân Moivre – Laplace

Xét biến ngẫu nhiên $X$ có phân phối Nhị thức $B(n;\ p)$.

Với mọi $a, b \in \mathbb{R}$ và $a < b$, ta có:

$$\lim_{n \to \infty} P(a \le X \le b) = \frac{1}{\sqrt{2\pi}} \int_{\frac{a - np}{\sqrt{npq}}}^{\frac{b - np}{\sqrt{npq}}} e^{-\frac{x^2}{2}}\,dx.$$

### c) Ứng dụng xấp xỉ Nhị thức bằng phân phối Chuẩn

- Cho $X \in B(n,\ p)$. Nếu $n$ khá lớn, $p$ không quá gần 0 và 1 thì $X \sim N(\mu;\ \sigma^2)$ với $\mu = np,\ \sigma^2 = npq$.

Trong thực tế, người ta hay chọn điều kiện xấp xỉ:

$$n > 30,\quad np \ge 5,\quad nq \ge 5,\quad 0{,}05 \le p \le 0{,}95$$

### Điều chỉnh 0.5

**Chú ý.** Khi xấp xỉ phân phối nhị thức (giá trị nguyên rời rạc) bởi phân phối chuẩn (giá trị thực liên tục) ta cần điều chỉnh 0.5:

- $P(a \le X \le b) \approx P(a - 0{,}5 < X < b + 0{,}5)$
- $P(X \le b) \approx P(X < b + 0{,}5)$
- $P(X < b) \approx P(X < b - 0{,}5)$
- $P(a \le X) \approx P(a - 0{,}5 < X)$; $P(a < X) \approx P(a + 0{,}5 < X)$
- $P(X = a) \approx P(a - 0{,}5 < X < a + 0{,}5)$

(Hình: biểu đồ cột của phân phối nhị thức với đường cong chuẩn đứt nét phủ lên trên; mỗi cột có độ rộng 1, ví dụ cột $k = 5$ trải từ 4,5 đến 5,5.)

**Ví dụ.** Cho $X \sim B(100,\ 0{,}4)$, tính các xác suất

1. $P(20 \le X \le 40)$
2. $P(X < 32)$
3. $P(X \ge 25)$

Hãy xấp xỉ $X$ về phân phối chuẩn và tính lại các xác suất trên.

Vì $np = 40,\ nq = 60 > 5$, nên ta có thể xấp xỉ $B(n = 100,\ p = 0{,}4)$ về phân phối chuẩn $N(\mu, \sigma^2)$, với $\mu = np = 40$ và $\sigma = \sqrt{npq} = 2\sqrt{6}$.

1. $$P(20 \le X \le 40) \approx P(19{,}5 \le X \le 40{,}5) = \varphi\!\left(\frac{40{,}5 - 40}{2\sqrt{6}}\right) - \varphi\!\left(\frac{19{,}5 - 40}{2\sqrt{6}}\right) \approx \varphi(0{,}1) - \varphi(-4{,}18) = 0{,}5398 - 0 = 0{,}5398$$

2. $$P(X < 32) \approx P(X < 31{,}5) = \varphi\!\left(\frac{31{,}5 - 40}{2\sqrt{6}}\right) \approx \varphi(-1{,}74) = 0{,}0409$$

3. $$P(X \ge 25) \approx P(X > 24{,}5) = 1 - P(X \le 24{,}5) \approx 1 - \varphi(-3{,}16) = 1 - 0{,}0008 = 0{,}9992$$

**VD 4.** Trong một đợt thi tuyển công chức ở một thành phố có 1.000 người dự thi với tỉ lệ thi đạt là 80%. Tính xác suất để:

1. có 172 người không đạt;
2. có khoảng 170 đến 180 người không đạt.

*Giải.* Gọi $X$ là số người không đạt, $X \in B(1.000;\ 0{,}2)$.

$\mu = np = 200,\ \sigma^2 = npq = 160 \Rightarrow X \sim N(200;\ 160)$.

1. $$P(X = 172) \approx P(171{,}5 \le X \le 172{,}5) = \varphi\!\left(\frac{172{,}5 - 200}{\sqrt{160}}\right) - \varphi\!\left(\frac{171{,}5 - 200}{\sqrt{160}}\right) \approx \varphi(-2{,}17) - \varphi(-2{,}25) = 0{,}015 - 0{,}0122 = 0{,}0028$$

2. $$P(170 \le X \le 180) \approx P(169{,}5 \le X \le 180{,}5) = \varphi\!\left(\frac{180{,}5 - 200}{\sqrt{160}}\right) - \varphi\!\left(\frac{169{,}5 - 200}{\sqrt{160}}\right) \approx \varphi(-1{,}54) - \varphi(-2{,}41) = 0{,}0618 - 0{,}008 = 0{,}0538$$

### Tóm tắt xấp xỉ Chuẩn cho Nhị thức

| $X \in B(n, p)$ | điều kiện | $X \in N(\mu, \sigma^2)$ |
|---|---|---|
| $EX = np$ | $np \ge 5$ và $nq \ge 5$ | $EX = \mu$ |
| $VarX = npq$ | $\mu = np,\ \sigma^2 = npq$ | $VarX = \sigma^2$ |

---

# BÀI TẬP

**VD 5.** Trong 10.000 sản phẩm trên một dây chuyền sản xuất có 2.000 sản phẩm không được kiểm tra chất lượng. Tìm xác suất để trong 400 sản phẩm sản xuất ra:

1. có 80 sản phẩm không được kiểm tra;
2. có từ 70 đến 100 sản phẩm không được kiểm tra.

**VD 6.** Một khách sạn nhận đặt chỗ của 325 khách hàng cho 300 phòng vào ngày 1/1 vì theo kinh nghiệm của những năm trước cho thấy có 10% khách đặt chỗ nhưng không đến. Biết mỗi khách đặt 1 phòng, tính xác suất:

1. có 300 khách đến vào ngày 1/1 và nhận phòng;
2. tất cả khách đến vào ngày 1/1 đều nhận được phòng.

**VD 7.** Một cửa hàng bán cá giống có 20.000 con cá loại da trơn trong đó để lẫn 4.000 con cá tra. Một khách hàng chọn ngẫu nhiên (1 lần) 1.000 con từ 20.000 con cá da trơn đó. Tính xác suất khách chọn được từ 182 đến 230 con cá tra?
