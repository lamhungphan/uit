Dưới đây là bảng tra ký hiệu phổ biến trong 8 chương.

## Biến cố và xác suất

| Ký hiệu | Tiếng Việt | English | Ý nghĩa / công thức |
|---|---|---|---|
| $\Omega$ | Không gian mẫu | Sample space | Tập hợp tất cả kết quả có thể xảy ra |
| $\omega$ | Kết quả sơ cấp | Elementary outcome | Một kết quả cụ thể trong $\Omega$ |
| $A,B,C$ | Biến cố | Event | Tập con của không gian mẫu |
| $\varnothing$ | Biến cố rỗng | Empty/null event | Biến cố không bao giờ xảy ra |
| $P(A)$ | Xác suất của $A$ | Probability of $A$ | $0\le P(A)\le1$ |
| $P(A)=k/n$ | Xác suất cổ điển | Classical probability | $k$: số trường hợp thuận lợi; $n$: tổng số trường hợp đồng khả năng |
| $P(A)\approx k/n$ | Xác suất thống kê | Statistical probability | $k$: số lần $A$ xảy ra trong $n$ phép thử |
| $P(A\cup B)$ | Xác suất $A$ hoặc $B$ | Probability of union | $P(A)+P(B)-P(A\cap B)$ |
| $P(A\cap B)$ | Xác suất $A$ và $B$ | Probability of intersection | Cả hai biến cố cùng xảy ra |
| $AB$ | Tích hai biến cố | Intersection event | Cách viết khác của $A\cap B$ |
| $A+B$ | Tổng hai biến cố | Union event | Cách viết khác của $A\cup B$ |
| $\overline A$ | Biến cố đối lập của $A$ | Complement of $A$ | $P(\overline A)=1-P(A)$ |
| $A\setminus B$ | Hiệu của $A$ và $B$ | Set difference | $A$ xảy ra nhưng $B$ không xảy ra |
| $A\subset B$ | $A$ kéo theo $B$ | $A$ implies $B$ | $A$ xảy ra thì $B$ chắc xảy ra |
| $A\perp B$ | $A,B$ độc lập | Independent events | $P(A\cap B)=P(A)P(B)$ |
| $P(A\mid B)$ | Xác suất có điều kiện | Conditional probability | $P(A\mid B)=P(A\cap B)/P(B)$ |
| $P(A\cap B)$ | Xác suất đồng thời | Joint probability | $P(A)P(B\mid A)$ |
| $P(B)=\sum P(A_i)P(B\mid A_i)$ | Công thức xác suất đầy đủ | Law of total probability | Cộng xác suất qua mọi trường hợp đầy đủ |
| $P(A_k\mid B)$ | Công thức Bayes | Bayes' theorem | $\dfrac{P(A_k)P(B\mid A_k)}{\sum P(A_i)P(B\mid A_i)}$ |

## Biến ngẫu nhiên

| Ký hiệu | Tiếng Việt | English | Ý nghĩa / công thức |
|---|---|---|---|
| $X,Y,Z$ | Biến ngẫu nhiên | Random variable | Đại lượng nhận giá trị theo xác suất |
| $X=x$ | $X$ nhận giá trị $x$ | $X$ equals $x$ | Một biến cố |
| $X\le x$ | $X$ nhỏ hơn hoặc bằng $x$ | $X$ is at most $x$ | Biến cố của hàm phân phối |
| $x_i$ | Giá trị quan sát | Observed value | Một giá trị cụ thể của $X$ |
| $p_i$ | Xác suất tại $x_i$ | Probability mass | $p_i=P(X=x_i)$ |
| $\sum p_i=1$ | Tổng xác suất bằng 1 | Sum of probabilities | Điều kiện của phân phối rời rạc |
| $f(x)$ | Hàm mật độ | Probability density function | $P(a\le X\le b)=\int_a^bf(x)\,dx$ |
| $F(x)$ | Hàm phân phối tích lũy | Cumulative distribution function | $F(x)=P(X\le x)$ |
| $P(a<X\le b)$ | Xác suất trong khoảng | Probability interval | $F(b)-F(a)$ |
| $Y=\varphi(X)$ | Hàm của biến ngẫu nhiên | Function of random variable | Biến đổi giá trị của $X$ |
| $Mode(X)$ | Mốt / giá trị tin chắc nhất | Mode | Giá trị có xác suất hoặc mật độ lớn nhất |
| $Med(X)$ | Trung vị | Median | Chia phân phối thành hai nửa 50% |
| $EX$ | Kỳ vọng của $X$ | Expected value / mean | Giá trị trung bình theo xác suất |
| $EX=\sum x_ip_i$ | Kỳ vọng rời rạc | Discrete expectation | Cộng giá trị nhân xác suất |
| $EX=\int xf(x)\,dx$ | Kỳ vọng liên tục | Continuous expectation | Tích phân giá trị nhân mật độ |
| $E(C)=C$ | Kỳ vọng hằng số | Expectation of constant | Hằng số không đổi |
| $E(CX)=CEX$ | Kỳ vọng nhân hằng số | Scaling property | Cố định mọi giá trị |
| $E(X+Y)=EX+EY$ | Kỳ vọng tổng | Linearity of expectation | Luôn đúng |
| $Var(X)$ | Phương sai | Variance | $Var(X)=E[(X-EX)^2]$ |
| $Var(X)$ | Phương sai | Variance | $Var(X)=E(X^2)-(EX)^2$ |
| $\sigma$ | Độ lệch chuẩn | Standard deviation | $\sigma=\sqrt{Var(X)}$ |
| $\sigma^2$ | Phương sai | Variance | Bình phương độ lệch chuẩn |
| $\sigma/\mu$ | Hệ số biến thiên tương đối | Coefficient of variation | Độ phân tán tương đối |

## Phân phối xác suất

| Ký hiệu | Tiếng Việt | English | Công thức |
|---|---|---|---|
| $B(p)$ | Phân phối Bernoulli | Bernoulli distribution | $P(X=1)=p$, $P(X=0)=1-p$ |
| $B(n,p)$ | Phân phối Nhị thức | Binomial distribution | $P(X=k)=C_n^kp^kq^{n-k}$ |
| $q$ | Xác suất thất bại | Failure probability | $q=1-p$ |
| $C_n^k$ | Tổ hợp chập $k$ của $n$ | Binomial coefficient | $C_n^k=n!/[k!(n-k)!]$ |
| $H(N,N_A,n)$ | Phân phối Siêu bội | Hypergeometric distribution | $P(X=k)=C_{N_A}^{k}C_{N-N_A}^{n-k}/C_N^n$ |
| $P(\lambda)$ | Phân phối Poisson | Poisson distribution | $P(X=k)=e^{-\lambda}\lambda^k/k!$ |
| $\lambda$ | Tham số Poisson | Poisson rate | Trung bình số sự kiện trong khoảng quan sát |
| $N(\mu,\sigma^2)$ | Phân phối Chuẩn | Normal distribution | $f(x)=\dfrac1{\sigma\sqrt{2\pi}}e^{-(x-\mu)^2/(2\sigma^2)}$ |
| $N(0,1)$ | Chuẩn đơn giản / Chuẩn tắc | Standard normal | Phân phối chuẩn có $\mu=0,\sigma=1$ |
| $Z$ | Biến chuẩn hóa | Standard score | $Z=(X-\mu)/\sigma\sim N(0,1)$ |
| $\varphi(z)$ | Hàm Laplace | Standard normal CDF | $\varphi(z)=P(Z\le z)$ |
| $\chi^2(n)$ | Phân phối Chi bình phương | Chi-square distribution | Có $n$ bậc tự do |
| $n$ | Bậc tự do | Degrees of freedom | Số tham số độc lập được phép thay đổi |
| $St(n)$ | Phân phối Student | Student's t-distribution | Dùng cho mẫu nhỏ khi $\sigma$ chưa biết |
| $t_{\alpha}$ | Phân vị Student | Critical t-value | Điểm cắt thỏa $P(T>t_\alpha)=\alpha$ |

## Đặc trưng phân phối thông dụng

| Phân phối | Kỳ vọng | Phương sai |
|---|---:|---:|
| Bernoulli $B(p)$ | $p$ | $pq$ |
| Nhị thức $B(n,p)$ | $np$ | $npq$ |
| Siêu bội $H(N,N_A,n)$ | $np$ | $npq\dfrac{N-n}{N-1}$ |
| Poisson $P(\lambda)$ | $\lambda$ | $\lambda$ |
| Chuẩn $N(\mu,\sigma^2)$ | $\mu$ | $\sigma^2$ |

## Định lý giới hạn và xấp xỉ

| Ký hiệu / Công thức | Tiếng Việt | English |
|---|---|---|
| $X_n\xrightarrow{P}X$ | Hội tụ theo xác suất | Convergence in probability |
| $X_n\xrightarrow{d}X$ | Hội tụ theo phân phối | Convergence in distribution |
| $P(|X-\mu|\ge\varepsilon)\le\sigma^2/\varepsilon^2$ | Bất đẳng thức Tchébyshev | Chebyshev's inequality |
| $\bar X_n=\sum X_i/n$ | Trung bình $n$ quan sát | Sample mean |
| $\bar X_n\xrightarrow{P}\mu$ | Luật số lớn | Law of large numbers |
| $\sum X_i\approx N(\mu,\sigma^2)$ | Định lý giới hạn trung tâm | Central limit theorem |
| $H\to B(n,p)$ | Siêu bội xấp xỉ Nhị thức | Hypergeometric approximated by binomial |
| $n<5\%N$ | Điều kiện lấy mẫu nhỏ so với tổng thể | Sample is less than 5% of population |
| $B(n,p)\to P(np)$ | Nhị thức xấp xỉ Poisson | Binomial approximated by Poisson |
| $B(n,p)\to N(np,npq)$ | Nhị thức xấp xỉ Chuẩn | Binomial approximated by normal |
| $a-0,5,\ b+0,5$ | Điều chỉnh 0,5 | Continuity correction |

Điều kiện xấp xỉ Nhị thức bằng Chuẩn:

$$np\ge5,\qquad nq\ge5,\qquad n>30$$

## Tổng thể và mẫu

| Ký hiệu | Tiếng Việt | English | Ý nghĩa |
|---|---|---|---|
| $N$ | Kích thước tổng thể | Population size | Tổng số phần tử của tổng thể |
| $n$ | Kích thước mẫu | Sample size | Số phần tử được quan sát |
| $X$ | Dữ liệu trong tổng thể | Population variable | Đại lượng cần khảo sát |
| $x_i$ | Quan sát thứ $i$ | $i$-th observation | Giá trị cụ thể trong mẫu |
| $\mu$ | Trung bình tổng thể | Population mean | Trung bình thực của toàn bộ tổng thể |
| $\sigma$ | Độ lệch chuẩn tổng thể | Population standard deviation | Độ phân tán của tổng thể |
| $\bar x$ | Trung bình mẫu cụ thể | Sample mean | $\bar x=\sum x_i/n$ |
| $\bar X$ | Trung bình mẫu ngẫu nhiên | Random sample mean | Biến ngẫu nhiên của trung bình mẫu |
| $s^2$ | Phương sai mẫu hiệu chỉnh | Sample variance | $s^2=\sum(x_i-\bar x)^2/(n-1)$ |
| $s$ | Độ lệch chuẩn mẫu hiệu chỉnh | Sample standard deviation | $s=\sqrt{s^2}$ |
| $\hat s^2$ | Phương sai mẫu chưa hiệu chỉnh | Uncorrected sample variance | $\hat s^2=\sum(x_i-\bar x)^2/n$ |
| $p$ | Tỷ lệ tổng thể | Population proportion | Tỷ lệ phần tử có tính chất cần khảo sát |
| $f$ | Tỷ lệ mẫu | Sample proportion | $f=m/n$ |
| $m$ | Số phần tử thoả tính chất | Number of successes | Số quan sát có tính chất $A$ |

Phân phối trung bình mẫu:

$$\bar X\sim N\left(\mu,\frac{\sigma^2}{n}\right)$$

Sai số chuẩn:

$$SE_{\bar X}=\frac{\sigma}{\sqrt n}$$

Phân phối tỷ lệ mẫu:

$$F\approx N\left(p,\frac{p(1-p)}n\right)$$

## Ước lượng tham số

| Ký hiệu | Tiếng Việt | English | Ý nghĩa |
|---|---|---|---|
| $\theta$ | Tham số cần ước lượng | Population parameter | Có thể là $\mu,p,\sigma^2$ |
| $\hat\theta$ | Ước lượng của $\theta$ | Estimator | Thống kê dùng để ước lượng tham số |
| $\varepsilon$ | Sai số ước lượng | Margin of error | Độ lệch hai cận của khoảng tin cậy |
| $1-\alpha$ | Độ tin cậy | Confidence level | Tỉ lệ khoảng chứa tham số đúng |
| $\alpha$ | Mức sai lệch | Significance level | Xác suất sai lầm loại I |
| $\alpha/2$ | Mức sai lề hai phía | Two-tail probability | Dùng cho khoảng hai đuôi |
| $[\bar x-\varepsilon,\bar x+\varepsilon]$ | Khoảng tin cậy cho $\mu$ | Confidence interval for mean | Ước lượng khoảng |
| $z_{\alpha/2}$ | Phân vị Chuẩn | Critical z-value | Điểm cắt chuẩn hai đuôi |
| $t_{\alpha/2,n-1}$ | Phân vị Student | Critical t-value | Điểm cắt Student với $n-1$ bậc tự do |
| $[f-\varepsilon,f+\varepsilon]$ | Khoảng tin cậy cho $p$ | Confidence interval for proportion | Khoảng ước lượng tỷ lệ |

Sai số trung bình:

$$\varepsilon=z_{\alpha/2}\frac{\sigma}{\sqrt n}$$

Khi $\sigma$ chưa biết và $n\ge30$:

$$\varepsilon=z_{\alpha/2}\frac{s}{\sqrt n}$$

Khi $\sigma$ chưa biết và $n<30$, tổng thể chuẩn:

$$\varepsilon=t_{\alpha/2,n-1}\frac{s}{\sqrt n}$$

Sai số tỷ lệ:

$$\varepsilon=z_{\alpha/2}\sqrt{\frac{f(1-f)}n}$$

## Kiểm định giả thiết thống kê

| Ký hiệu | Tiếng Việt | English | Ý nghĩa |
|---|---|---|---|
| $H_0$ | Giả thiết gốc / giả thiết không | Null hypothesis | Tuyên bố ban đầu, thường có đẳng thức |
| $H_1$ | Đối thiết / giả thiết thay thế | Alternative hypothesis | Tuyên bố cần chứng minh |
| $\mu_0,p_0$ | Giá trị giả thiết | Hypothesized value | Giá trị dùng để kiểm định |
| $\alpha$ | Mức ý nghĩa | Significance level | Thường bằng 0,05 hoặc 0,01 |
| $T$ | Thống kê kiểm định | Test statistic | Đại lượng tính từ dữ liệu mẫu |
| $R$ | Miền bác bỏ | Rejection region | Miền giá trị dẫn tới bác bỏ $H_0$ |
| Sai lầm loại I | Bác bỏ $H_0$ khi $H_0$ đúng | Type I error | Xác suất bằng $\alpha$ |
| Sai lầm loại II | Chấp nhận $H_0$ khi $H_0$ sai | Type II error | Thường ký hiệu $\beta$ |

Kiểm định trung bình có $\sigma$ đã biết:

$$z=\frac{\bar x-\mu_0}{\sigma/\sqrt n}$$

Kiểm định trung bình có $\sigma$ chưa biết:

$$z=\frac{\bar x-\mu_0}{s/\sqrt n}$$

với mẫu lớn, hoặc:

$$t=\frac{\bar x-\mu_0}{s/\sqrt n}$$

với mẫu nhỏ và tổng thể chuẩn.

Kiểm định tỷ lệ:

$$z=\frac{(f-p_0)\sqrt n}{\sqrt{p_0(1-p_0)}}$$

Quy tắc hai đuôi:

$$H_1:\mu\ne\mu_0,\qquad \text{bác bỏ }H_0\text{ nếu }|z|>z_{\alpha/2}$$

Quy tắc đuôi phải:

$$H_1:\mu>\mu_0,\qquad \text{bác bỏ }H_0\text{ nếu }z>z_\alpha$$

Quy tắc đuôi trái:

$$H_1:\mu<\mu_0,\qquad \text{bác bỏ }H_0\text{ nếu }z<-z_\alpha$$

## Tương quan và hồi quy

| Ký hiệu | Tiếng Việt | English | Công thức / ý nghĩa |
|---|---|---|---|
| $(x_i,y_i)$ | Cặp dữ liệu quan sát | Data pair | Một quan sát hai chiều |
| $\bar x,\bar y$ | Trung bình từng đại lượng | Sample means | $\bar x=\sum x_i/n$, $\bar y=\sum y_i/n$ |
| $\overline{xy}$ | Trung bình tích $XY$ | Mean of products | $\overline{xy}=\sum x_iy_i/n$ |
| $\overline{x^2}$ | Trung bình bình phương $X$ | Mean of squares | $\overline{x^2}=\sum x_i^2/n$ |
| $r$ | Hệ số tương quan mẫu | Sample correlation coefficient | $-1\le r\le1$ |
| $r$ | Hệ số tương quan tuyến tính | Correlation coefficient | $\dfrac{\overline{xy}-\bar x\bar y}{\sqrt{(\overline{x^2}-\bar x^2)(\overline{y^2}-\bar y^2)}}$ |
| $r>0$ | Tương quan thuận | Positive correlation | $X,Y$ có xu hướng tăng cùng nhau |
| $r<0$ | Tương quan nghịch | Negative correlation | $X$ tăng thì $Y$ giảm |
| $r\approx0$ | Không tương quan tuyến tính | No linear correlation | Có thể vẫn có quan hệ phi tuyến |
| $Y=A+BX$ | Hồi quy $Y$ theo $X$ | Regression of $Y$ on $X$ | $X$ là biến độc lập, $Y$ là biến phụ thuộc |
| $B$ | Hệ số góc hồi quy | Regression slope | $\dfrac{\overline{xy}-\bar x\bar y}{\overline{x^2}-\bar x^2}$ |
| $A$ | Hệ số chặn | Regression intercept | $A=\bar y-B\bar x$ |
| $\hat y_i$ | Giá trị dự đoán | Predicted value | $\hat y_i=A+Bx_i$ |
| $y_i-\hat y_i$ | Phần dư / sai số dự đoán | Residual | Độ sai khác giữa quan sát và dự đoán |
| Bình phương bé nhất | OLS / Least squares | $\sum(y_i-A-Bx_i)^2$ tối thiểu | Đường hồi quy có tổng sai bình phương nhỏ nhất |

## Một số ký hiệu Toán học chung

| Ký hiệu | Tiếng Việt | English |
|---|---|---|
| $\sum$ | Tổng | Summation |
| $\prod$ | Tích | Product |
| $\int$ | Tích phân | Integral |
| $\forall$ | Với mọi | For all |
| $\exists$ | Tồn tại | There exists |
| $\in$ | Thuộc | Belongs to |
| $\notin$ | Không thuộc | Does not belong |
| $\le,\ge$ | Nhỏ hơn hoặc bằng / lớn hơn hoặc bằng | Less/greater than or equal |
| $\approx$ | Xấp xỉ | Approximately |
| $\sim$ | Theo phân phối / phân bố theo | Distributed as |
| $\to$ | Tiến tới | Tends to |
| $\max$ | Giá trị lớn nhất | Maximum |
| $\min$ | Giá trị nhỏ nhất | Minimum |
| $\ln x$ | Logarit tự nhiên | Natural logarithm |
| $e$ | Cơ số logarit tự nhiên | Euler's number |
| $\pi$ | Số Pi | Pi |
| $\Gamma(n)$ | Hàm Gamma | Gamma function |
| $n!$ | Giai thừa | Factorial |