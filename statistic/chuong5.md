# PHẦN II. THỐNG KÊ (Statistic)

# Chương 5. LÝ THUYẾT MẪU

## Nội dung

1. Giới thiệu về mẫu và các tham số đặc trưng mẫu
2. Các dạng biểu diễn mẫu thường gặp
3. Luật phân phối của các tham số đặc trưng mẫu

---

# 1. Giới thiệu về mẫu và các tham số đặc trưng mẫu

## Khái niệm và ký hiệu

- **Tổng thể** (*population*): tập hợp tất cả những phần tử mà ta quan tâm.
  - Kích thước tổng thể: $N$ (thường rất lớn).
  - *Ví dụ*:
    - Tập hợp tất cả những người đi bầu trong cuộc bầu cử sắp tới
    - Tập hợp tất cả những bóng đèn do nhà máy sản xuất trong tháng.
- **Mẫu** (*sample*): **1 tập con** bất kỳ của tổng thể.
  - Kích thước mẫu: $n$ ($n \ll N$).
  - *Ví dụ*:
    - Phỏng vấn *ngẫu nhiên* 1000 người **trước khi** cuộc bầu cử diễn ra (mục đích: tham dò dư luận về khả năng của các ứng viên)
    - Chọn *ngẫu nhiên* 100 bóng đèn để kiểm tra chất lượng.

> **Ghi chú:** Vì $N$ rất lớn, nên ta không thể khảo sát tất cả phần tử trong tổng thể, do đó không thể biết được thông tin chính xác về tổng thể.

## How & what for?

(Hình: sơ đồ *Population* → *Sampling / Lấy mẫu* → *Sample*, và mũi tên ngược lại *Inference / Suy luận* từ mẫu về tổng thể.)

**Mục đích:** từ thông tin của mẫu suy ra thông tin về tổng thể. Quá trình này được gọi là **suy luận thống kê** (*inference*).

## Ví dụ về việc lấy mẫu

Muốn tìm chiều cao trung bình của 12000 thanh niên của một khu vực.

- Không thể khảo sát chiều cao của **tất cả** 12000 thanh niên trong khu vực.
- Chọn ngẫu nhiên một mẫu gồm 100 thanh niên trong khu vực để khảo sát
  - Ký hiệu: $\{x_1, \dots, x_{100}\}$, trong đó $x_i$ là chiều cao của thanh niên thứ $i$
  - Tính chiều cao trung bình $\bar{x}$ của 100 thanh niên này.
- Từ **trung bình mẫu** $\bar{x}$, ta suy ra thông tin về **trung bình tổng thể** $\mu$ (chiều cao của 12000 thanh niên trong khu vực).

## Tại sao phải lấy mẫu?

- **Không thể** khảo sát tất cả từng phần tử của tổng thể. *Ví dụ: kiểm tra các hộp sữa của một lô hàng.*
- Bị giới hạn về thời gian và chi phí. *Ví dụ: khảo sát **trước** mỗi kỳ bầu cử tổng thống Mỹ.*
- Ta có thể suy ra được các kết quả thống kê khá chính xác nếu **lấy mẫu hợp lí**.

## Lấy mẫu như thế nào là hợp lý?

- **Lấy mẫu ngẫu nhiên**: mỗi phần tử trong tổng thể có **cơ hội** được chọn **như nhau**.

  (Hình: tranh biếm họa người bị bịt mắt chỉ vào đám đông, "You, You, You" – "I can't hear you! Is it still random?")

- **Kích thước mẫu đủ lớn**: **n càng lớn**, thông tin suy luận về tổng thể **càng đáng tin cậy và có ý nghĩa**
- Vấn đề: {value of infomation} vs {time & cost} → balance

> **Ghi chú:** Nếu không lấy ngẫu nhiên, mẫu sẽ bị lệch, và không đại diện cho tổng thể.

## Ví dụ: Khảo sát chiều cao

- Chọn mẫu ngẫu nhiên: $n = 100$ sinh viên → trung bình mẫu $\bar{x} = 165\text{cm}$ (chiều cao trung bình của 100 sv)
- Gọi $\mu$ là trung bình tổng thể (chiều cao của **tất cả** sinh viên)
- Bằng tính toán, ta tìm được 1 con số $\varepsilon$ sao cho
$$P(\bar{x} - \varepsilon < \mu < \bar{x} + \varepsilon) = 95\%$$
  - *Ví dụ*, nếu $\varepsilon = 10\text{cm}$, thì có đến **95% khả năng** trung bình tổng thể $\mu$ nằm trong khoảng $\bar{x} \pm \varepsilon$, tức $(155\text{cm},\ 175\text{cm})$.
- 95% được gọi là **độ tin cậy**, được ký hiệu là $1 - \alpha$
- $(\bar{x} - \varepsilon,\ \bar{x} + \varepsilon)$ được gọi là **khoảng ước lượng**.
- Tăng $n$: hoặc ta có độ tin cậy **lớn hơn**, hoặc ta có khoảng ước lượng **nhỏ hơn** (*thông tin có giá trị hơn*).

> **Ghi chú:** Nhấn mạnh: biết mẫu, không thể biết tổng thể (mà chỉ có thể dự đoán, ước lượng…)

## Trung bình mẫu

- $\overline{X}$: trung bình mẫu **ngẫu nhiên** $\{X_1, \dots, X_n\}$
$$\overline{X} = \frac{X_1 + \dots + X_n}{n} = \frac{\sum_{i=1}^{n} X_i}{n}$$
  (chú thích trên slide: *n = Sample Size*)
- $\bar{x}$: trung bình mẫu **cụ thể**, là một *giá trị cụ thể* của $\overline{X}$.
$$\bar{x} = \frac{x_1 + \dots + x_n}{n} = \frac{\sum_{i=1}^{n} x_i}{n} = \frac{\sum x_i}{n}$$
  - Từ tổng thể, có vô số cách chọn ra **các mẫu** có $n$ phần tử.
  - Mỗi mẫu cụ thể có một giá trị trung bình $\bar{x}$.
  - Các giá trị $\bar{x}$ tạo thành **phân phối của trung bình mẫu** $\overline{X}$.

## Phương sai mẫu

| Các giá trị đặc trưng | Mẫu ngẫu nhiên | Mẫu cụ thể |
|---|---|---|
| Giá trị trung bình | $\overline{X} = \dfrac{X_1 + \dots + X_n}{n}$ | $\bar{x} = \dfrac{x_1 + \dots + x_n}{n}$ |
| Phương sai không hiệu chỉnh | $\hat{S}_X^2 = \dfrac{(X_1 - \overline{X})^2 + \dots + (X_n - \overline{X})^2}{n}$ | $\hat{s}_x^2 = \dfrac{(x_1 - \bar{x})^2 + \dots + (x_n - \bar{x})^2}{n}$ |
| Phương sai hiệu chỉnh | $S_X^2 = \dfrac{(X_1 - \overline{X})^2 + \dots + (X_n - \overline{X})^2}{n - 1}$ | $s_x^2 = \dfrac{(x_1 - \bar{x})^2 + \dots + (x_n - \bar{x})^2}{n - 1}$ |

Độ lệch chuẩn có hiệu chỉnh $s$ được dùng trong các bài toán ước lượng và kiểm định.

> **Ghi chú:** Viết hoa: ĐLNN, viết thường: giá trị cụ thể của ĐLNN.

## Tỷ lệ mẫu

Xét mẫu gồm $n$ phần tử trong đó có $m$ phần tử có tính chất $A$.

Tỷ lệ mẫu có tính chất $A$:

$$f = \frac{m}{n}$$

Ta thường kí hiệu tỷ lệ (xác suất) cá thể có tính chất $A$ trong tổng thể là: $p$

Từ $f$, suy ra thông tin về tỷ lệ của tổng thể $p$.

---

# 2. Các dạng biểu diễn mẫu thường gặp

## Các dạng mẫu thường gặp

- **Mẫu dạng điểm**: còn gọi là bảng dữ liệu thô
- **Mẫu dạng tần số**: dữ liệu thô được tổ chức lại theo tần số xuất hiện.
- **Mẫu dạng khoảng**: dữ liệu thô được chia thành các khoảng lớp và tần số tương ứng

## Mẫu dạng điểm, ví dụ

Dữ liệu về số chai champagne bán ra ở Pháp từ năm 1962 đến 1969 (*Table 6-7: Champagne Sales in France*):

| Month | 1962 | 1963 | 1964 | 1965 | 1966 | 1967 | 1968 | 1969 |
|---|---|---|---|---|---|---|---|---|
| Jan. | 2.851 | 2.541 | 3.113 | 5.375 | 3.633 | 4.016 | 2.639 | 3.934 |
| Feb. | 2.672 | 2.475 | 3.006 | 3.088 | 4.292 | 3.957 | 2.899 | 3.162 |
| Mar. | 2.755 | 3.031 | 4.047 | 3.718 | 4.154 | 4.510 | 3.370 | 4.286 |
| Apr. | 2.721 | 3.266 | 3.523 | 4.514 | 4.121 | 4.276 | 3.740 | 4.676 |
| May | 2.946 | 3.776 | 3.937 | 4.520 | 4.647 | 4.968 | 2.927 | 5.010 |
| June | 3.036 | 3.230 | 3.986 | 4.539 | 4.753 | 4.677 | 3.986 | 4.874 |
| July | 2.282 | 3.028 | 3.260 | 3.663 | 3.965 | 3.523 | 4.217 | 4.633 |
| Aug. | 2.212 | 1.759 | 1.573 | 1.643 | 1.723 | 1.821 | 1.738 | 1.659 |
| Sept. | 2.922 | 3.595 | 3.528 | 4.739 | 5.048 | 5.222 | 5.221 | 5.591 |
| Oct. | 4.301 | 4.474 | 5.211 | 5.428 | 6.922 | 6.873 | 6.424 | 6.981 |
| Nov. | 5.764 | 6.838 | 7.614 | 8.314 | 9.858 | 10.803 | 9.842 | 9.851 |
| Dec. | 7.132 | 8.357 | 9.254 | 10.651 | 11.331 | 13.916 | 13.076 | 12.670 |

## Mẫu dạng tần số

Khi có các giá trị $x_i$ trùng nhau, ta gom dữ liệu thô (dạng điểm) về **dữ liệu dạng tần số**.

| $x_i$ | $m_i$ |
|:-:|:-:|
| $x_1$ | $m_1$ |
| $x_2$ | $m_2$ |
| … | … |
| $x_k$ | $m_k$ |

- $x_i$: các giá trị cụ thể mẫu
- Tần số $m_i$: số lần xuất hiện của phần tử $x_i$ tương ứng.

**Ví dụ**: Kiểm tra ngẫu nhiên 50 SV. Ta sắp xếp điểm số thu được theo thứ tự tăng dần và số SV có điểm tương ứng như sau:

| Điểm ($x_i$) | 2 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| Số SV ($m_i$) | 4 | 6 | 20 | 10 | 5 | 2 | 2 | 1 |

## Mẫu dạng khoảng

| Tâm lớp $x_i$ | Chiều cao (cm) (khoảng lớp) | Số SV (tần số $m_i$) |
|:-:|:-:|:-:|
| 154,5 | 151–158 | 5 |
| 162,5 | 159–166 | 18 |
| 170,5 | 167–174 | 41 |
| 178,5 | 175–182 | 27 |
| 186,5 | 183–190 | 8 |

- Khoảng lớp: $x_{\min} \le x \le x_{\max}$
- Tâm lớp $x_i$ = trung bình khoảng lớp = $(x_{\min} + x_{\max})/2$
  - Dùng để đại diện cho mỗi khoảng lớp
  - Sự đại diện này không chính xác → dẫn đến sai số khi tính toán.

## Ví dụ

**VD 1.** Theo dõi mức nguyên liệu hao phí để sản xuất ra một đơn vị sản phẩm ở một nhà máy, ta thu được các số liệu sau (đơn vị: gam):

```
20; 22; 21; 20; 22; 22; 20; 19; 20; 22; 21;
19; 19; 20; 18; 19; 20; 20; 18; 19; 20; 20;
21; 20; 18; 19; 19; 21; 22; 21; 21; 20; 19.
```

Hãy sắp xếp số liệu trên dưới dạng bảng?

**VD 2.** Cho mẫu có cỡ mẫu là $n = 9$ như sau:

| $X$ | 12 | 11 | 15 |
|:-:|:-:|:-:|:-:|
| $n$ | 3 | 2 | 4 |

Tính trung bình, độ lệch chuẩn và độ lệch chuẩn có hiệu chỉnh của mẫu.

*Đáp số:* trên slide gồm 3 công thức $\bar{x}$, $\hat{s}$, $s$ nhưng ảnh công thức bị lỗi khi đọc, nên các giá trị dưới đây là **mình tự tính lại** từ bảng: $\bar{x} = \dfrac{118}{9} \approx 13{,}11$; $\hat{s} \approx 1{,}7285$; $s \approx 1{,}8333$.

**VD 3.** Điều tra năng suất của 100 ha lúa trong vùng $A$, ta có bảng số liệu sau:

| Năng suất (tấn/ha) | 3 - 3,5 | 3,5 - 4 | 4 - 4,5 | 4,5 - 5 | 5 - 5,5 | 5,5 - 6 | 6 - 6,5 | 6,5 - 7 |
|---|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| Diện tích (ha) | 7 | 12 | 18 | 27 | 20 | 8 | 5 | 3 |

Những thửa ruộng có năng suất ít hơn 4,4 tấn/ha là có năng suất thấp.

Dùng máy tính bỏ túi để tính:

1. tỉ lệ diện tích lúa có năng suất thấp;
2. năng suất lúa trung bình, phương sai mẫu chưa hiệu chỉnh và độ lệch chuẩn của mẫu có hiệu chỉnh.

*Giải.* Bảng số liệu được viết lại (theo tâm lớp; ba cột đầu 3,25 / 3,75 / 4,25 được tô đỏ là các lớp "năng suất thấp"):

| Năng suất (tấn/ha) | **3,25** | **3,75** | **4,25** | 4,75 | 5,25 | 5,75 | 6,25 | 6,75 |
|---|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| Diện tích (ha) | **7** | **12** | **18** | 27 | 20 | 8 | 5 | 3 |

Slide có 2 công thức đáp án (1) và (2) nhưng ảnh công thức bị lỗi khi đọc; các giá trị dưới đây là **mình tự tính lại** từ bảng:

1. $f = \dfrac{m}{n} = \dfrac{7 + 12 + 18}{100} = 0{,}37$
2. $\bar{x} = 4{,}75$ (tấn/ha); phương sai mẫu chưa hiệu chỉnh $\hat{s}^2 = 0{,}685$; độ lệch chuẩn có hiệu chỉnh $s \approx 0{,}8318$.

---

# 3. Luật phân phối của các tham số đặc trưng mẫu

## Định lý giới hạn trung tâm

- $\{X_1, \dots, X_n\}$ là các đại lượng ngẫu nhiên **độc lập** và **có cùng luật phân phối với tổng thể** $X$ với trung bình $\mu$ và độ lệch chuẩn $\sigma$ hữu hạn.
- Xét tổng $S_n = X_1 + \dots + X_n$
- Khi $n \to \infty$: $S_n \sim N\big(\mu_{S_n}, (\sigma_{S_n})^2\big)$
  - Trong đó: $\mu_{S_n} = n\mu$, $\sigma_{S_n} = \sigma\sqrt{n}$
  - ĐLNN chuẩn tắc của $S_n$: $Z = \dfrac{S_n - n\mu}{\sigma\sqrt{n}} \sim N(0, 1)$
- ***Lưu ý***:
  - Nếu tổng thể $X$ **bất kỳ**: $S_n \underset{\text{xấp xỉ}}{\sim} N\big(n\mu, (\sigma\sqrt{n})^2\big)$ khi $n \ge 30$
  - Nếu tổng thể $X$ có **pp chuẩn**: $S_n \underset{\text{có}}{\sim} N\big(n\mu, (\sigma\sqrt{n})^2\big)$ với mọi $n$.

## Ví dụ – TH tổng thể có pp chuẩn

**Ví dụ 1.1** Trọng lượng của các nhân viên trong trụ sở một công ty tuân theo quy luật phân phối chuẩn với $\mu = 71{,}5$ kg và độ lệch chuẩn $\sigma = 7{,}3$ kg. Thang máy trong trụ sở có mức tải trọng an toàn 444 kg. Giả sử có 6 người bất kỳ cùng vào thang máy.

1. Tính xác suất tổng trọng lượng của 6 người vượt mức an toàn cho phép.
2. Nếu muốn xác suất trong câu (a) không vượt quá 5% thì công ty cần một thang máy có tải trọng an toàn là bao nhiêu?

- $X_i$: trọng lượng của người $i$ ($i = \overline{1,6}$).
- Các $X_i$ **độc lập** và có cùng pp chuẩn với tổng thể $X$ (trọng lượng của **tất cả** nhân viên trong cty).
- $S = X_1 + \dots + X_6$: tổng trọng lượng của 6 người.
- Suy ra $S \sim N\big(n\mu, (\sigma\sqrt{n})^2\big)$.

## Phân phối của trung bình mẫu

- Từ tổng thể $X$ chọn ra một mẫu ngẫu nhiên kích thước $n$, ký hiệu $\{X_1, \dots, X_n\}$
- $\overline{X} = \dfrac{X_1 + X_2 + \dots + X_n}{n}$: trung bình của mẫu ngẫu nhiên
- $\bar{x} = \dfrac{x_1 + \dots + x_n}{n}$: trung bình của *một mẫu cụ thể*
- Từ tổng thể, có vô số cách chọn **các mẫu** có kích thước $n$. Mỗi mẫu có một giá trị trung bình $\bar{x}$.
- Các giá trị của trung bình mẫu cụ thể $\bar{x}$ tạo nên phân phối của trung bình mẫu ngẫu nhiên $\overline{X}$.

## Tính chất của trung bình mẫu

- Kỳ vọng của trung bình mẫu = trung bình tổng thể
$$\mu_{\overline{X}} = \mu$$
- Độ lệch chuẩn của trung bình mẫu = phương sai tổng thể chia cho kích thước mẫu (nguyên văn trên slide)
$$\sigma_{\overline{X}} = \sigma / \sqrt{n}$$
- $n$ càng lớn $\sigma_{\overline{X}}$ càng nhỏ (tuy nhiên $\mu_{\overline{X}}$ luôn không đổi) → các giá trị của $\bar{x}$ càng tập trung gần $\mu_{\overline{X}} = \mu$.

## Định lý về phân phối của trung bình mẫu

- Nếu tổng thể có phân phối chuẩn: $X \sim N(\mu, \sigma^2)$ thì trung bình mẫu cũng **có** phân phối chuẩn:
$$\overline{X} \underset{\text{có}}{\sim} N\!\left(\mu, \frac{\sigma^2}{n}\right) \quad \text{với } \mu_{\overline{X}} = \mu \text{ và } \sigma_{\overline{X}} = \sigma/\sqrt{n}$$
- Nếu tổng thể **không** có phân phối chuẩn nhưng kích thước mẫu lớn ($n \ge 30$) thì trung bình mẫu **xấp xỉ** phân phối chuẩn:
$$\overline{X} \underset{\text{xấp xỉ}}{\sim} N\!\left(\mu, \frac{\sigma^2}{n}\right) \quad \text{với } \mu_{\overline{X}} = \mu \text{ và } \sigma_{\overline{X}} = \sigma/\sqrt{n}$$

## Phân phối của trung bình mẫu – ví dụ

Giả sử chiều cao của sinh viên nam ở tpHCM có phân phối chuẩn với trung bình là 172 cm và độ lệch chuẩn là 10 cm. Chọn ngẫu nhiên một mẫu gồm 25 sinh viên.

a) Tìm quy luật phân phối của trung bình mẫu.
b) Tính xác suất để một mẫu ngẫu nhiên có chiều cao trung bình lớn hơn 174cm.

> **Ghi chú:** Tổng thể có phân phối chuẩn

## Giải ví dụ

- Gọi $X$ là chiều cao của sinh viên tpHCM (tổng thể).
- $\overline{X}$ là chiều cao **trung bình** của một **mẫu ngẫu nhiên** gồm 25 sinh viên.
- Vì tổng thể có phân phối chuẩn $X \sim N(\mu, \sigma^2)$ nên trung bình mẫu có pp chuẩn: $\overline{X} \sim N\big(\mu_{\overline{X}}, (\sigma_{\overline{X}})^2\big)$.
- Trong đó $\mu_{\overline{X}} = \mu = 172\text{cm}$, $\sigma_{\overline{X}} = \dfrac{\sigma}{\sqrt{n}} = \dfrac{10}{\sqrt{25}} = 2\text{cm}$.
- $P(\overline{X} > 174) = 1 - F(174) \approx 15{,}87\%$

## Ví dụ

*The contents of soft drink cans is distributed with mean 378mL and standard deviation 7.2mL. Find the likelihood that a box of 36 cans has average contents less than 375mL.*

(Hình: đường cong "Distribution of sample means" tâm 378, diện tích phần đuôi trái tại 375 là 0.00621.)

**Giải**

- Tổng thể $X$: dung tích (mL) của các chai do công ty sản xuất, với $\mu = 378\text{mL}$, $\sigma = 7{,}2\text{mL}$
- $\overline{X}$: dung tích trung bình của 36 chai trong thùng.
- Vì $n = 36 > 30$ nên $\overline{X} \sim N\big(\mu_{\overline{X}}, (\sigma_{\overline{X}})^2\big)$, với
  - $\mu_{\overline{X}} = \mu = 378\text{mL}$ và $\sigma_{\overline{X}} = \dfrac{\sigma}{\sqrt{n}} = 1{,}2\text{mL}$
- $P(\overline{X} < 375) = F(375) \approx 0{,}62\%$

## Phân phối tỷ lệ mẫu

- Tỷ lệ của tổng thể $p$ (tỷ lệ các phần tử có tính chất $A$ trong tổng thể)
- $F$ là tỷ lệ của mẫu ngẫu nhiên (tỷ lệ các phần tử có tính chất $A$ trong mẫu)
- Tính chất: $\mu_F = p$ và $\sigma_F = \sqrt{\dfrac{p(1-p)}{n}}$ với mọi $n$.
- Khi $n$ lớn ($n \ge 30$): $F$ xấp xỉ với phân phối chuẩn
$$F \sim N\!\left(p, \frac{p(1-p)}{n}\right) \quad \text{với } \mu_F = p \text{ và } \sigma_F = \sqrt{\frac{p(1-p)}{n}}$$

## Ví dụ

Người ta phát hiện một máy sản xuất có 2% sản phẩm do máy này sản xuất ra bị hỏng. Tính xác suất trong 400 sản phẩm do máy này sản xuất ra có: không dưới 3% sản phẩm bị hỏng?

- Tỷ lệ của tổng thể $p = 2\%$
- Kích thước mẫu $n = 400$
- Vì kích thước mẫu lớn ($n > 30$) nên $F$ xấp xỉ với phân phối chuẩn $F \sim N\!\left(p, \dfrac{p(1-p)}{n}\right)$
- Trong đó $\mu_F = p = 2\%$ và $\sigma_F = \sqrt{\dfrac{p(1-p)}{n}} = 0{,}7\%$
- $P(F \ge 3\%) = 1 - F(3\%) = 7{,}66\%$

## Bài tập tương tự

Một công bố về kết quả bầu cử cho thấy một ứng cử viên đạt được 46% số phiếu bầu.

1. Tìm xác suất trong 200 số phiếu bầu được chọn ngẫu nhiên từ tổng số phiếu bầu có đa số phiếu bầu dành cho ứng viên này. (tức là có số phiếu lớn hơn 50%)
2. Tìm xác suất trong 1000 số phiếu bầu được chọn ngẫu nhiên từ tổng số phiếu bầu có đa số phiếu bầu dành cho ứng viên này.
