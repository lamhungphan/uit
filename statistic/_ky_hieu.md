## Biến cố và xác suất

| Ký hiệu | Cách đọc | Tiếng Việt | English | Ý nghĩa / công thức |
|---|---|---|---|---|
| $\Omega$ | Omega lớn | Không gian mẫu | Sample space | Tập hợp tất cả kết quả có thể xảy ra |
| $\omega$ | Omega thường | Kết quả sơ cấp | Elementary outcome | Một kết quả cụ thể trong $\Omega$ |
| $A,B,C$ |  | Biến cố | Event | Tập con của không gian mẫu |
| $\varnothing$ | Tập rỗng | Biến cố rỗng | Empty/null event | Biến cố không bao giờ xảy ra |
| $P(A)$ | P của A | Xác suất của $A$ | Probability of $A$ | $0\le P(A)\le1$ |
| $P(A)=k/n$ | P của A bằng k trên n | Xác suất cổ điển | Classical probability | $k$: số trường hợp thuận lợi; $n$: tổng số trường hợp đồng khả năng |
| $P(A)\approx k/n$ | P của A xấp xỉ k trên n | Xác suất thống kê | Statistical probability | $k$: số lần $A$ xảy ra trong $n$ phép thử |
| $P(A\cup B)$ | P của A hợp B | Xác suất $A$ hoặc $B$ | Probability of union | $P(A)+P(B)-P(A\cap B)$ |
| $P(A\cap B)$ | P của A giao B | Xác suất $A$ và $B$ | Probability of intersection | Cả hai biến cố cùng xảy ra |
| $AB$ | A nhân B | Tích hai biến cố | Intersection event | Cách viết khác của $A\cap B$ |
| $A+B$ | A cộng B | Tổng hai biến cố | Union event | Cách viết khác của $A\cup B$ |
| $\overline A$ | A gạch ngang trên | Biến cố đối lập của $A$ | Complement of $A$ | $P(\overline A)=1-P(A)$ |
| $A\setminus B$ | A trừ B | Hiệu của $A$ và $B$ | Set difference | $A$ xảy ra nhưng $B$ không xảy ra |
| $A\subset B$ | A là tập con của B | $A$ kéo theo $B$ | $A$ implies $B$ | $A$ xảy ra thì $B$ chắc xảy ra |
| $A\perp B$ | A độc lập với B | $A,B$ độc lập | Independent events | $P(A\cap B)=P(A)P(B)$ |
| $P(A\mid B)$ | Xác suất của A với điều kiện B | Xác suất có điều kiện | Conditional probability | $P(A\mid B)=P(A\cap B)/P(B)$ |
| $P(A\cap B)$ | Xác suất của A giao B | Xác suất đồng thời | Joint probability | $P(A)P(B\mid A)$ |
| $P(B)=\sum P(A_i)P(B\mid A_i)$ | P của B bằng tổng P của A-i nhân P của B với điều kiện A-i | Công thức xác suất đầy đủ | Law of total probability | Cộng xác suất qua mọi trường hợp đầy đủ |
| $P(A_k\mid B)$ | Xác suất của A-k với điều kiện B | Công thức Bayes | Bayes' theorem | $\dfrac{P(A_k)P(B\mid A_k)}{\sum P(A_i)P(B\mid A_i)}$ |

## Biến ngẫu nhiên

| Ký hiệu | Cách đọc | Tiếng Việt | English | Ý nghĩa / công thức |
|---|---|---|---|---|
| $X,Y,Z$ |  | Biến ngẫu nhiên | Random variable | Đại lượng nhận giá trị theo xác suất |
| $X=x$ | X bằng x | $X$ nhận giá trị $x$ | $X$ equals $x$ | Một biến cố |
| $X\le x$ | X nhỏ hơn hoặc bằng x | $X$ nhỏ hơn hoặc bằng $x$ | $X$ is at most $x$ | Biến cố của hàm phân phối |
| $x_i$ | X-i | Giá trị quan sát | Observed value | Một giá trị cụ thể của $X$ |
| $p_i$ | P-i | Xác suất tại $x_i$ | Probability mass | $p_i=P(X=x_i)$ |
| $\sum p_i=1$ | Tổng P-i bằng 1 | Tổng xác suất bằng 1 | Sum of probabilities | Điều kiện của phân phối rời rạc |
| $f(x)$ | F của x | Hàm mật độ | Probability density function | $P(a\le X\le b)=\int_a^bf(x)\,dx$ |
| $F(x)$ | F hoa của x | Hàm phân phối tích lũy | Cumulative distribution function | $F(x)=P(X\le x)$ |
| $P(a<X\le b)$ | P của a nhỏ hơn X nhỏ hơn hoặc bằng b | Xác suất trong khoảng | Probability interval | $F(b)-F(a)$ |
| $Y=\varphi(X)$ | Y bằng Phi của X | Hàm của biến ngẫu nhiên | Function of random variable | Biến đổi giá trị của $X$ |
| $Mode(X)$ | Mốt của X | Mốt / giá trị tin chắc nhất | Mode | Giá trị có xác suất hoặc mật độ lớn nhất |
| $Med(X)$ | Trung vị của X | Trung vị | Median | Chia phân phối thành hai nửa 50% |
| $EX$ | E của X / kỳ vọng của X | Kỳ vọng của $X$ | Expected value / mean | Giá trị trung bình theo xác suất |
| $EX=\sum x_ip_i$ | E của X bằng tổng x-i nhân P-i | Kỳ vọng rời rạc | Discrete expectation | Cộng giá trị nhân xác suất |
| $EX=\int xf(x)\,dx$ | E của X bằng tích phân x nhân F của x | Kỳ vọng liên tục | Continuous expectation | Tích phân giá trị nhân mật độ |
| $E(C)=C$ | E của hằng số C bằng C | Kỳ vọng hằng số | Expectation of constant | Hằng số không đổi |
| $E(CX)=CEX$ | E của C nhân X bằng C nhân E của X | Kỳ vọng nhân hằng số | Scaling property | Cố định mọi giá trị |
| $E(X+Y)=EX+EY$ | E của X cộng Y bằng E của X cộng E của Y | Kỳ vọng tổng | Linearity of expectation | Luôn đúng |
| $Var(X)$ | Phương sai của X | Phương sai | Variance | $Var(X)=E[(X-EX)^2]$ |
| $Var(X)=E(X^2)-(EX)^2$ | Phương sai của X bằng E của X bình phương trừ kỳ vọng của X bình phương | Phương sai | Variance | Công thức tính phương sai |
| $\sigma$ | Sigma thường | Độ lệch chuẩn | Standard deviation | $\sigma=\sqrt{Var(X)}$ |
| $\sigma^2$ | Sigma bình phương | Phương sai | Variance | Bình phương độ lệch chuẩn |
| $\sigma/\mu$ | Sigma chia Mu | Hệ số biến thiên tương đối | Coefficient of variation | Độ phân tán tương đối |

## Phân phối xác suất

| Ký hiệu | Cách đọc | Tiếng Việt | English | Công thức |
|---|---|---|---|---|
| $B(p)$ | B của p | Phân phối Bernoulli | Bernoulli distribution | $P(X=1)=p$, $P(X=0)=1-p$ |
| $B(n,p)$ | B của n và p | Phân phối Nhị thức | Binomial distribution | $P(X=k)=C_n^kp^kq^{n-k}$ |
| $q$ |  | Xác suất thất bại | Failure probability | $q=1-p$ |
| $C_n^k$ | Tổ hợp chập k của n | Tổ hợp chập $k$ của $n$ | Binomial coefficient | $C_n^k=n!/[k!(n-k)!]$ |
| $H(N,N_A,n)$ | H của N, N-A và n | Phân phối Siêu bội | Hypergeometric distribution | $P(X=k)=C_{N_A}^{k}C_{N-N_A}^{n-k}/C_N^n$ |
| $P(\lambda)$ | P của Lamda | Phân phối Poisson | Poisson distribution | $P(X=k)=e^{-\lambda}\lambda^k/k!$ |
| $\lambda$ | Lamda | Tham số Poisson | Poisson rate | Trung bình số sự kiện trong khoảng quan sát |
| $N(\mu,\sigma^2)$ | N của Mu và Sigma bình phương | Phân phối Chuẩn | Normal distribution | $f(x)=\dfrac1{\sigma\sqrt{2\pi}}e^{-(x-\mu)^2/(2\sigma^2)}$ |
| $N(0,1)$ | N của 0 và 1 | Chuẩn đơn giản / Chuẩn tắc | Standard normal | Phân phối chuẩn có $\mu=0,\sigma=1$ |
| $Z$ |  | Biến chuẩn hóa | Standard score | $Z=(X-\mu)/\sigma\sim N(0,1)$ |
| $\varphi(z)$ | Phi của z | Hàm Laplace | Standard normal CDF | $\varphi(z)=P(Z\le z)$ |
| $\chi^2(n)$ | Cái bình phương của n | Phân phối Chi bình phương | Chi-square distribution | Có $n$ bậc tự do |
| $n$ |  | Bậc tự do | Degrees of freedom | Số tham số độc lập được phép thay đổi |
| $St(n)$ | Student của n | Phân phối Student | Student's t-distribution | Dùng cho mẫu nhỏ khi $\sigma$ chưa biết |
| $t_{\alpha}$ | T Alpha | Phân vị Student | Critical t-value | Điểm cắt thỏa $P(T>t_\alpha)=\alpha$ |

## Đặc trưng phân phối thông dụng

| Phân phối | Cách đọc | Kỳ vọng | Phương sai |
|---|---|---:|---:|
| Bernoulli $B(p)$ | B của p | $p$ | $pq$ |
| Nhị thức $B(n,p)$ | B của n và p | $np$ | $npq$ |
| Siêu bội $H(N,N_A,n)$ | H của N, N-A và n | $np$ | $npq\dfrac{N-n}{N-1}$ |
| Poisson $P(\lambda)$ | P của Lamda | $\lambda$ | $\lambda$ |
| Chuẩn $N(\mu,\sigma^2)$ | N của Mu và Sigma bình phương | $\mu$ | $\sigma^2$ |

## Định lý giới hạn và xấp xỉ

| Ký hiệu / Công thức | Cách đọc | Tiếng Việt | English |
|---|---|---|---|
| $X_n\xrightarrow{P}X$ | X-n hội tụ theo xác suất tới X | Hội tụ theo xác suất | Convergence in probability |
| $X_n\xrightarrow{d}X$ | X-n hội tụ theo phân phối tới X | Hội tụ theo phân phối | Convergence in distribution |
| $P\left(\lvert X-\mu\rvert\ge\varepsilon\right)\le\dfrac{\sigma^2}{\varepsilon^2}$ | P của trị tuyệt đối X trừ Mu lớn hơn hoặc bằng Epsilon không lớn hơn Sigma bình phương chia Epsilon bình phương | Bất đẳng thức Tchébyshev | Chebyshev's inequality |
| $\bar X_n=\sum X_i/n$ | X-n gạch ngang bằng tổng X-i chia n | Trung bình $n$ quan sát | Sample mean |
| $\bar X_n\xrightarrow{P}\mu$ | X-n gạch ngang hội tụ theo xác suất tới Mu | Luật số lớn | Law of large numbers |
| $\sum X_i\approx N(\mu,\sigma^2)$ | Tổng X-i xấp xỉ N của Mu và Sigma bình phương | Định lý giới hạn trung tâm | Central limit theorem |
| $H\to B(n,p)$ | H tiến tới B của n và p | Siêu bội xấp xỉ Nhị thức | Hypergeometric approximated by binomial |
| $n<5\%N$ | n nhỏ hơn năm phần trăm N | Điều kiện lấy mẫu nhỏ so với tổng thể | Sample is less than 5% of population |
| $B(n,p)\to P(np)$ | B của n và p tiến tới P của n nhân p | Nhị thức xấp xỉ Poisson | Binomial approximated by Poisson |
| $B(n,p)\to N(np,npq)$ | B của n và p tiến tới N của n nhân p và n nhân p nhân q | Nhị thức xấp xỉ Chuẩn | Binomial approximated by normal |
| $a-0,5,\ b+0,5$ | A trừ 0,5 và B cộng 0,5 | Điều chỉnh 0,5 | Continuity correction |

Điều kiện xấp xỉ Nhị thức bằng Chuẩn:

$$np\ge5,\qquad nq\ge5,\qquad n>30$$

## Tổng thể và mẫu

| Ký hiệu | Cách đọc | Tiếng Việt | English | Ý nghĩa |
|---|---|---|---|---|
| $N$ |  | Kích thước tổng thể | Population size | Tổng số phần tử của tổng thể |
| $n$ |  | Kích thước mẫu | Sample size | Số phần tử được quan sát |
| $X$ |  | Dữ liệu trong tổng thể | Population variable | Đại lượng cần khảo sát |
| $x_i$ | X-i | Quan sát thứ $i$ | $i$-th observation | Giá trị cụ thể trong mẫu |
| $\mu$ | Mu | Trung bình tổng thể | Population mean | Trung bình thực của toàn bộ tổng thể |
| $\sigma$ | Sigma | Độ lệch chuẩn tổng thể | Population standard deviation | Độ phân tán của tổng thể |
| $\bar x$ | X gạch ngang | Trung bình mẫu cụ thể | Sample mean | $\bar x=\sum x_i/n$ |
| $\bar X$ | X hoa gạch ngang | Trung bình mẫu ngẫu nhiên | Random sample mean | Biến ngẫu nhiên của trung bình mẫu |
| $s^2$ | Es bình phương | Phương sai mẫu hiệu chỉnh | Sample variance | $s^2=\sum(x_i-\bar x)^2/(n-1)$ |
| $s$ |  | Độ lệch chuẩn mẫu hiệu chỉnh | Sample standard deviation | $s=\sqrt{s^2}$ |
| $\hat s^2$ | s mũ bình phương | Phương sai mẫu chưa hiệu chỉnh | Uncorrected sample variance | $\hat s^2=\sum(x_i-\bar x)^2/n$ |
| $p$ |  | Tỷ lệ tổng thể | Population proportion | Tỷ lệ phần tử có tính chất cần khảo sát |
| $f$ |  | Tỷ lệ mẫu | Sample proportion | $f=m/n$ |
| $m$ |  | Số phần tử thoả tính chất | Number of successes | Số quan sát có tính chất $A$ |

Phân phối trung bình mẫu:

$$\bar X\sim N\left(\mu,\frac{\sigma^2}{n}\right)$$

Sai số chuẩn:

$$SE_{\bar X}=\frac{\sigma}{\sqrt n}$$

Phân phối tỷ lệ mẫu:

$$F\approx N\left(p,\frac{p(1-p)}n\right)$$

## Ước lượng tham số

| Ký hiệu | Cách đọc | Tiếng Việt | English | Ý nghĩa |
|---|---|---|---|---|
| $\theta$ | Theta | Tham số cần ước lượng | Population parameter | Có thể là $\mu,p,\sigma^2$ |
| $\hat\theta$ | Theta mũ | Ước lượng của $\theta$ | Estimator | Thống kê dùng để ước lượng tham số |
| $\varepsilon$ | Epsilon | Sai số ước lượng | Margin of error | Độ lệch hai cận của khoảng tin cậy |
| $1-\alpha$ | Một trừ Alpha | Độ tin cậy | Confidence level | Tỉ lệ khoảng chứa tham số đúng |
| $\alpha$ | Alpha | Mức sai lệch | Significance level | Xác suất sai lầm loại I |
| $\alpha/2$ | Alpha chia hai | Mức sai lề hai phía | Two-tail probability | Dùng cho khoảng hai đuôi |
| $[\bar x-\varepsilon,\bar x+\varepsilon]$ | Mở ngoặc vuông X gạch ngang trừ Epsilon, X gạch ngang cộng Epsilon đóng ngoặc vuông | Khoảng tin cậy cho $\mu$ | Confidence interval for mean | Ước lượng khoảng |
| $z_{\alpha/2}$ | Zét Alpha trên hai | Phân vị Chuẩn | Critical z-value | Điểm cắt chuẩn hai đuôi |
| $t_{\alpha/2,n-1}$ | T Alpha trên hai, En trừ một | Phân vị Student | Critical t-value | Điểm cắt Student với $n-1$ bậc tự do |
| $[f-\varepsilon,f+\varepsilon]$ | Mở ngoặc vuông Ép trừ Epsilon, Ép cộng Epsilon đóng ngoặc vuông | Khoảng tin cậy cho $p$ | Confidence interval for proportion | Khoảng ước lượng tỷ lệ |

Sai số trung bình:

$$\varepsilon=z_{\alpha/2}\frac{\sigma}{\sqrt n}$$

Khi $\sigma$ chưa biết và $n\ge30$:

$$\varepsilon=z_{\alpha/2}\frac{s}{\sqrt n}$$

Khi $\sigma$ chưa biết và $n<30$, tổng thể chuẩn:

$$\varepsilon=t_{\alpha/2,n-1}\frac{s}{\sqrt n}$$

Sai số tỷ lệ:

$$\varepsilon=z_{\alpha/2}\sqrt{\frac{f(1-f)}n}$$

## Kiểm định giả thiết thống kê

| Ký hiệu | Cách đọc | Tiếng Việt | English | Ý nghĩa |
|---|---|---|---|---|
| $H_0$ | H không | Giả thiết gốc / giả thiết không | Null hypothesis | Tuyên bố ban đầu, thường có đẳng thức |
| $H_1$ | H một | Đối thiết / giả thiết thay thế | Alternative hypothesis | Tuyên bố cần chứng minh |
| $\mu_0,p_0$ | Mu không, P không | Giá trị giả thiết | Hypothesized value | Giá trị dùng để kiểm định |
| $\alpha$ | Alpha | Mức ý nghĩa | Significance level | Thường bằng 0,05 hoặc 0,01 |
| $T$ |  | Thống kê kiểm định | Test statistic | Đại lượng tính từ dữ liệu mẫu |
| $R$ |  | Miền bác bỏ | Rejection region | Miền giá trị dẫn tới bác bỏ $H_0$ |
| Sai lầm loại I |  | Bác bỏ $H_0$ khi $H_0$ đúng | Type I error | Xác suất bằng $\alpha$ |
| Sai lầm loại II |  | Chấp nhận $H_0$ khi $H_0$ sai | Type II error | Thường ký hiệu $\beta$ |

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

| Ký hiệu | Cách đọc | Tiếng Việt | English | Công thức / ý nghĩa |
|---|---|---|---|---|
| $(x_i,y_i)$ | Mở ngoặc X-i, Y-i đóng ngoặc | Cặp dữ liệu quan sát | Data pair | Một quan sát hai chiều |
| $\bar x,\bar y$ | X gạch ngang, Y gạch ngang | Trung bình từng đại lượng | Sample means | $\bar x=\sum x_i/n$, $\bar y=\sum y_i/n$ |
| $\overline{xy}$ | X-Y gạch ngang trên | Trung bình tích $XY$ | Mean of products | $\overline{xy}=\sum x_iy_i/n$ |
| $\overline{x^2}$ | X bình phương gạch ngang | Trung bình bình phương $X$ | Mean of squares | $\overline{x^2}=\sum x_i^2/n$ |
| $r$ |  | Hệ số tương quan mẫu | Sample correlation coefficient | $-1\le r\le1$ |
| $r$ |  | Hệ số tương quan tuyến tính | Correlation coefficient | $\dfrac{\overline{xy}-\bar x\bar y}{\sqrt{(\overline{x^2}-\bar x^2)(\overline{y^2}-\bar y^2)}}$ |
| $r>0$ | R lớn hơn 0 | Tương quan thuận | Positive correlation | $X,Y$ có xu hướng tăng cùng nhau |
| $r<0$ | R nhỏ hơn 0 | Tương quan nghịch | Negative correlation | $X$ tăng thì $Y$ giảm |
| $r\approx0$ | R xấp xỉ 0 | Không tương quan tuyến tính | No linear correlation | Có thể vẫn có quan hệ phi tuyến |
| $Y=A+BX$ | Y bằng A cộng B nhân X | Hồi quy $Y$ theo $X$ | Regression of $Y$ on $X$ | $X$ là biến độc lập, $Y$ là biến phụ thuộc |
| $B$ |  | Hệ số góc hồi quy | Regression slope | $\dfrac{\overline{xy}-\bar x\bar y}{\overline{x^2}-\bar x^2}$ |
| $A$ |  | Hệ số chặn | Regression intercept | $A=\bar y-B\bar x$ |
| $\hat y_i$ | Y-i mũ | Giá trị dự đoán | Predicted value | $\hat y_i=A+Bx_i$ |
| $y_i-\hat y_i$ | Y-i trừ Y-i mũ | Phần dư / sai số dự đoán | Residual | Độ sai khác giữa quan sát và dự đoán |
| Bình phương bé nhất |  | OLS / Least squares | $\sum(y_i-A-Bx_i)^2$ tối thiểu | Đường hồi quy có tổng sai bình phương nhỏ nhất |