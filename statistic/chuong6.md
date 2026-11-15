# Chương 6. ƯỚC LƯỢNG THAM SỐ

# 1. Khái niệm chung về ước lượng

- Ước lượng là phỏng đoán một giá trị chưa biết của tổng thể dựa vào quan sát trên mẫu lấy ra từ tổng thể đó. Thông thường, ta cần ước lượng về trung bình, tỉ lệ, phương sai, hệ số tương quan của tổng thể.
- Có hai hình thức ước lượng:
  - ***Ước lượng điểm***: kết quả cần ước lượng được cho bởi một trị số.
  - ***Ước lượng khoảng***: kết quả cần ước lượng được cho bởi một khoảng.
- Ước lượng điểm có ưu điểm là cho ta một giá trị cụ thể, có thể dùng để tính các kết quả khác, nhưng nhược điểm là không cho biết sai số của ước lượng. Ước lượng khoảng thì ngược lại.

## Ví dụ

- Công ty A có hàng ngàn công nhân.
  - Thăm dò 100 công nhân của công ty nhận thấy thu nhập trung bình là 1,5 triệu đồng/tháng.
  - Sử dụng trung bình mẫu để ước lượng thu nhập trung bình của công nhân công ty A.
  - Ta nói thu nhập trung bình của công nhân công ty được ước lượng là 1,5 triệu đồng/tháng,

--- 

- Nếu nói một độ dài nào đó là 5,28 m thì ta nói về ước lượng điểm.
- Nếu nói độ dài đó là $5{,}28 \pm 0{,}03$ m thì độ dài đó nằm trong khoảng 5,25 và 5,31 m thì ta đã đưa ra một ước lượng khoảng.
- Giá trị 0,03 được gọi là **sai số** của phép ước lượng.
- Sai số của phép ước lượng, ký hiệu $\varepsilon$, ***thể hiện độ chính xác*** của phép ước lượng đó.
- Sai số càng nhỏ, độ chính xác càng cao.

## Các khái niệm và kí hiệu chung cho bài toán ước lượng

Xét ĐLNN $X$ trong tổng thể. Xét một mẫu ngẫu nhiên gồm $n$ phần tử.

- $\mu$: giá trị trung bình của ĐLNN $X$ trong tổng thể.
- $\bar{x} = \dfrac{x_1 + x_2 + \dots + x_n}{n}$: trung bình mẫu cụ thể
- $\sigma$: độ lệch chuẩn của $X$ trong **tổng thể**.
- $s$: độ lệch chuẩn **có hiệu chỉnh** của **mẫu cụ thể**
$$s = \sqrt{\frac{(x_1 - \bar{x})^2 + (x_2 - \bar{x})^2 + \dots + (x_n - \bar{x})^2}{n - 1}}$$

---

# 2. Ước lượng khoảng cho trung bình tổng thể $\mu$

## Ước lượng khoảng cho trung bình tổng thể $\mu$

- **Mục tiêu:** ước lượng $\mu$ với độ tin cậy $1 - \alpha$
  - Độ tin cậy $1 - \alpha$ là khả năng $\mu$ thuộc vào khoảng tin cậy mà ta đưa ra.
  - Dùng giá trị trung bình của mẫu $(\bar{x})$ để ước lượng trung bình của tổng thể $\mu$
- Ta cần tìm **khoảng tin cậy** $[\bar{x} - \varepsilon;\ \bar{x} + \varepsilon]$ sao cho:
$$P(\bar{x} - \varepsilon \le \mu \le \bar{x} + \varepsilon) = 1 - \alpha$$
- Ví dụ: Khoảng tin cậy là [156; 173] với độ tin cậy là 95% nghĩa là có 95% khả năng $\mu$ thuộc khoảng [156; 173] và có 5% khả năng $\mu$ không thuộc khoảng [156; 173].

## Ước lượng $\mu$ với độ tin cậy $1-\alpha$

**1) TH: $X$ có phân phối chuẩn, $\sigma$ đã biết**

$$Z = \frac{\overline{X} - \mu}{\sigma / \sqrt{n}} \sim N(0, 1)$$

Tìm $z_{\alpha/2}$ sao cho $P(-z_{\alpha/2} \le Z \le z_{\alpha/2}) = 1 - \alpha$, nghĩa là tìm $z_{\alpha/2}$ (tra bảng A4) thỏa

$$P(Z \le z_{\alpha/2}) = 1 - (\alpha/2)$$

Tính độ sai số của ước lượng:

$$\varepsilon = z_{\alpha/2}\,\frac{\sigma}{\sqrt{n}}$$

Khoảng tin cậy cho $\mu$ với độ tin cậy $1-\alpha$: $[\bar{x} - \varepsilon,\ \bar{x} + \varepsilon]$

**2) TH: $\sigma$ chưa biết**

**a) $n \ge 30$**: thay $\sigma$ bởi $s$ ($X$ có phân phối bất kì)

$$Z = \frac{\overline{X} - \mu}{s / \sqrt{n}} \sim N(0, 1)$$

Tìm $z_{\alpha/2}$ (tra bảng A4) thỏa $P(Z \le z_{\alpha/2}) = 1 - (\alpha/2)$

Tính độ sai số của ước lượng: $\varepsilon = z_{\alpha/2}\,\dfrac{s}{\sqrt{n}}$

Khoảng tin cậy cho $\mu$ với độ tin cậy $1-\alpha$: $[\bar{x} - \varepsilon,\ \bar{x} + \varepsilon]$

**b) $n < 30$, $X$ có phân phối chuẩn**: thay $\sigma$ bởi độ lệch chuẩn mẫu có điều chỉnh $s$

$$T = \frac{\overline{X} - \mu}{s / \sqrt{n}} \sim \text{Phân phối Student bậc tự do } n-1$$

Tìm $t_{\alpha/2}$ (tra bảng A5, dòng $n-1$) thỏa $P(T > t_{\alpha/2}) = \dfrac{\alpha}{2}$

Tính độ sai số của ước lượng: $\varepsilon = t_{\alpha/2}\,\dfrac{s}{\sqrt{n}}$

Khoảng tin cậy cho $\mu$ với độ tin cậy $1-\alpha$: $[\bar{x} - \varepsilon,\ \bar{x} + \varepsilon]$

***Chú ý***

Mối liên hệ giữa độ lệch chuẩn mẫu đã hiệu chỉnh $s$ và chưa hiệu chỉnh $\hat{s}$ là *(ảnh công thức bị lỗi; khôi phục theo VD 4 bên dưới)*:

$$s^2 = \frac{n}{n-1}\,\hat{s}^2 \qquad \Rightarrow \qquad s = \hat{s}\sqrt{\frac{n}{n-1}}$$

## Các bài toán về ước lượng khoảng

- **Bài 1.** Ước lượng khoảng (sử dụng công thức).
- **Bài 2.** Tìm độ tin cậy (ta không xét 2b)
$$\varepsilon = z_{\alpha/2}\frac{s}{\sqrt{n}} \Rightarrow z_{\alpha/2} = \frac{\varepsilon\sqrt{n}}{s} \xrightarrow{\ A4\ } \varphi(z_{\alpha/2})$$
$$\varphi(z_{\alpha/2}) = 1 - \frac{\alpha}{2} \Rightarrow \alpha = 2\big(1 - \varphi(z_{\alpha/2})\big) \Rightarrow 1 - \alpha = 2\varphi(z_{\alpha/2}) - 1$$
- **Bài 3.** Tìm cỡ mẫu (ta không xét 2b)
  - a) Nếu $\varepsilon > \varepsilon'$ thì ta giải bất đẳng thức:
  $$z_{\alpha/2}\frac{s}{\sqrt{N}} > \varepsilon' \Rightarrow N < \left(z_{\alpha/2}\frac{s}{\varepsilon'}\right)^2 \Rightarrow N_{\max}$$
  - b) Nếu $\varepsilon < \varepsilon'$ thì ta giải bất đẳng thức:
  $$z_{\alpha/2}\frac{s}{\sqrt{N}} < \varepsilon' \Rightarrow N > \left(z_{\alpha/2}\frac{s}{\varepsilon'}\right)^2 \Rightarrow N_{\min}$$

## Ví dụ

**VD 1.** Lượng Vitamin có trong một trái cây $A$ là biến ngẫu nhiên $X$ (mg) có độ lệch chuẩn 3,98 mg. Phân tích 250 trái cây $A$ thì thu được lượng Vitamin trung bình là 20 mg. Với độ tin cậy 95%, hãy ước lượng lượng Vitamin trung bình có trong một trái cây $A$?

*Giải.* $\sigma = 3{,}98$, $n = 250$, $\bar{x} = 20$

Độ tin cậy $1 - \alpha = 0{,}95 \Rightarrow \varphi(z_{\alpha/2}) = 1 - \dfrac{\alpha}{2} = 0{,}975$

Tra bảng A4, ta tìm được $z_{\alpha/2} = 1{,}96$

Độ chính xác: $\varepsilon = z_{\alpha/2}\dfrac{\sigma}{\sqrt{n}} = 1{,}96 \cdot \dfrac{3{,}98}{\sqrt{250}} = 0{,}4934$ mg

Vậy lượng Vitamin trung bình có trong một trái cây $A$ vào khoảng: $[\bar{x} - \varepsilon;\ \bar{x} + \varepsilon] = [19{,}5066;\ 20{,}4934]$

**VD 2.** Biết chiều cao con người là biến ngẫu nhiên $X$ (cm) có phân phối chuẩn $N(\mu; 10^2)$ *(công thức trong slide bị lỗi; khôi phục theo lời giải "Ta có σ = 10")*. Với độ tin cậy 95%, nếu muốn ước lượng chiều cao trung bình của dân số có sai số không quá 1 cm thì phải cần đo ít nhất mấy người?

*Giải.* Gọi $N$ là số người cần phải đo.

Ta có $\sigma = 10$ và

$$\varepsilon \le \varepsilon' \Rightarrow z_{\alpha/2}\frac{\sigma}{\sqrt{N}} \le 1 \Leftrightarrow 1{,}96\frac{10}{\sqrt{N}} \le 1$$

$$\Leftrightarrow N \ge (1{,}96 \cdot 10)^2 = 384{,}16 \quad \text{(bước này trong slide bị lỗi; khôi phục)}$$

Vậy cần phải đo ít nhất 385 người.

**VD 3.** Kiểm tra tuổi thọ (tính bằng giờ) của 50 bóng đèn do nhà máy $A$ sản xuất ra, người ta được bảng số liệu:

| Tuổi thọ | 3.300 | 3.500 | 3.600 | 4.000 |
|:-:|:-:|:-:|:-:|:-:|
| Số bóng đèn | 10 | 20 | 12 | 8 |

1. Hãy ước lượng tuổi thọ trung bình của loại bóng đèn do nhà máy $A$ sản xuất với độ tin cậy 97%?
2. Dựa vào mẫu trên để ước lượng tuổi thọ trung bình của loại bóng đèn do nhà máy $A$ sản xuất có độ chính xác 59,02 giờ thì đảm bảo độ tin cậy là bao nhiêu?
3. Dựa vào mẫu trên, nếu muốn ước lượng tuổi thọ trung bình của loại bóng đèn do nhà máy $A$ sản xuất có độ chính xác nhỏ hơn 40 giờ với độ tin cậy 98% thì cần phải kiểm tra tối thiểu bao nhiêu bóng đèn nữa?

*Giải.*

1. $n = 50$ và $\sigma$ chưa biết.

   Từ bảng số liệu, ta tính được: $\bar{x} = 3564$ giờ và $s = 217{,}3683$ giờ

   Độ tin cậy $1 - \alpha = 0{,}97 \Rightarrow \varphi(z_{\alpha/2}) = 1 - \dfrac{\alpha}{2} = 0{,}985 \Rightarrow z_{\alpha/2} = 2{,}17$

   Độ chính xác: $\varepsilon = z_{\alpha/2}\dfrac{s}{\sqrt{n}} = 2{,}17 \cdot \dfrac{217{,}3683}{\sqrt{50}} = 66{,}7069$ giờ

   Vậy tuổi thọ trung bình của bóng đèn vào khoảng: $[3497{,}2931;\ 3630{,}7069]$

2. Ta có: $\varepsilon = z_{\alpha/2}\dfrac{s}{\sqrt{n}} \Rightarrow z_{\alpha/2} = \dfrac{\varepsilon\sqrt{n}}{s} = \dfrac{59{,}02 \times \sqrt{50}}{217{,}3683} \approx 1{,}92$

   $\Rightarrow \varphi(z_{\alpha/2}) = \varphi(1{,}92) = 0{,}9726 = 1 - \dfrac{\alpha}{2}$

   $\Rightarrow 1 - \alpha = 2 \cdot 0{,}9726 - 1 = 0{,}9452$

   Vậy độ tin cậy được bảo đảm là 94,52%.

3. Gọi $N$ là số bóng đèn cần phải kiểm tra.

   Ta có $1 - \alpha = 0{,}98 \Rightarrow z_{\alpha/2} = 2{,}33$

   $$\varepsilon < \varepsilon' \Rightarrow z_{\alpha/2}\frac{s}{\sqrt{N}} < 40 \Leftrightarrow 2{,}33 \cdot \frac{217{,}3683}{\sqrt{N}} < 40$$

   $$\Leftrightarrow N > \left(\frac{2{,}33 \cdot 217{,}3683}{40}\right)^2 \approx 160{,}3 \Rightarrow N_{\min} = 161 $$

   Vậy cần phải kiểm tra thêm tối thiểu 111 bóng đèn nữa.

**VD 4.** Chiều cao của loại cây $A$ là biến ngẫu nhiên có phân phối chuẩn. Người ta đo ngẫu nhiên 20 cây $A$ thì thấy chiều cao trung bình 23,12 m và độ lệch chuẩn của mẫu chưa hiệu chỉnh là 1,25 m. Tìm khoảng ước lượng chiều cao trung bình của loại cây $A$ với độ tin cậy 95%?

*Giải.* $n = 20$, $\sigma$ chưa biết; $\bar{x} = 23{,}12$

- $\hat{s} = 1{,}25$ m, $s = \hat{s}\sqrt{\dfrac{20}{19}} = 1{,}2825$ m
- $1 - \alpha = 0{,}95 \Rightarrow \dfrac{\alpha}{2} = 0{,}025 \xrightarrow{\ A5\ } t_{0{,}025}^{19} = 2{,}093$
- $\varepsilon = t_{\alpha/2}^{n-1}\dfrac{s}{\sqrt{n}} = 2{,}093 \cdot \dfrac{1{,}2825}{\sqrt{20}} = 0{,}6002$ m

Vậy chiều cao trung bình của cây vào khoảng: $[22{,}5198;\ 23{,}7202]$

## Bài tập

**Bài tập: mẫu bé, biết $\sigma$.** Trọng lượng của những vỉ thuốc do một công ty dược sản xuất ***có phân phối chuẩn*** với ***độ lệch chuẩn 0.038mg***. Một mẫu ngẫu nhiên gồm 10 vỉ thuốc có ***trọng lượng trung bình là 4.87mg***. Với ***độ tin cậy 95%***, hãy ước lượng trọng lượng trung bình các vỉ thuốc do công ty sản xuất.

**Bài tập: mẫu lớn, không biết $\sigma$.** Độ đo các đường kính của một mẫu ngẫu nhiên gồm 100 vòng bi do một máy sản xuất trong một tuần có đường kính trung bình là 0,824 cm và độ lệch chuẩn mẫu có điều chỉnh là 0,042 cm. Hãy tìm khoảng tin cậy đường kính trung bình của tất cả các vòng bi với độ tin cậy 96%.

**Bài tập: mẫu bé, không biết $\sigma$.** Một mẫu gồm 10 độ đo đường kính của một quả cầu, có đường kính trung bình là 4,38 cm và độ lệch chuẩn mẫu có điều chỉnh là 0,06 cm. Biết rằng đường kính của một quả cầu có *phân phối chuẩn*, hãy tìm khoảng tin cậy của đường kính tất cả các quả cầu với độ tin cậy 95%.

**Bài tập.** Trọng lượng của một loại sản phẩm là một biến ngẫu nhiên phân bố theo quy luật chuẩn với độ lệch tiêu chuẩn 1 gram. Cần thử 25 sản phẩm loại này ta thu được kết quả:

| Trọng lượng (gram) | 18 | 19 | 20 | 21 |
|:-:|:-:|:-:|:-:|:-:|
| Số SP tương ứng | 3 | 5 | 15 | 2 |

Với độ tin cậy 95%

a. Hãy tìm khoảng tin cậy của trọng lượng trung bình của loại sản phẩm trên.
b. Nếu muốn độ chính xác của ước lượng không vượt quá 0,3 thì cần cân thử ít nhất bao nhiêu sản phẩm.

**Bài tập.** Để nghiên cứu nhu cầu về loại hàng $X$ ở phường $A$ người ta tiến hành khảo sát 400 trong toàn bộ 4000 gia đình. Kết quả khảo sát là:

| Nhu cầu (kg/tháng) | 0,5 | 1,5 | 2,5 | 3,5 |
|:-:|:-:|:-:|:-:|:-:|
| Số gia đình | 10 | 35 | 86 | 132 |

| Nhu cầu (kg/tháng) | 4,5 | 5,5 | 6,5 | 7,5 |
|:-:|:-:|:-:|:-:|:-:|
| Số gia đình | 78 | 31 | 18 | 10 |

1) Hãy ước lượng nhu cầu trung bình về loại hàng $X$ của toàn bộ gia đình ở phường $A$ trong 1 năm với độ tin cậy 95%?
2) Với mẫu khảo sát trên, nếu ước lượng nhu cầu trung bình về loại hàng $X$ của phường $A$ với độ chính xác lớn hơn 4,8 tấn/năm và độ tin cậy 99% thì cần khảo sát tối đa bao nhiêu gia đình trong phường $A$?

**Bài tập.** Năng suất của một loại giống mới là một biến ngẫu nhiên có quy luật phân bố chuẩn $N(\mu; \sigma^2)$. Gieo thử giống hạt này trên 16 mảnh vườn thí nghiệm thu được như sau (đơn vị kg/ha):

172, 173, 173, 174, 174, 175, 176, 166, 166, 167, 165, 173, 171, 170, 171, 170.

Hãy tìm khoảng tin cậy cho năng suất trung bình của loại hạt giống này với độ tin cậy $\beta = 95\%$.

---

# 3. Ước lượng tỷ lệ tổng thể $p$

## Ước lượng tỷ lệ tổng thể $p$ với độ tin cậy $1-\alpha$

Kí hiệu:

- $p$: tỷ lệ phần tử có tính chất $\mathcal{P}$ trong tổng thể,
- $f$: tỷ lệ phần tử có tính chất $\mathcal{P}$ trong mẫu.

**Lưu ý:** bài toán ước lượng tỷ lệ chỉ xét trong trường hợp mẫu lớn, do đó ta dùng phân phối chuẩn.

Khoảng tin cậy: $[f - \varepsilon;\ f + \varepsilon]$

Độ chính xác (sai số):

$$\varepsilon = z_{\alpha/2}\sqrt{\frac{f(1-f)}{n}}$$

Trong đó $z_{\alpha/2}$ thỏa $P(Z \le z_{\alpha/2}) = 1 - (\alpha/2)$, $Z \sim N(0,1)$ (tra bảng A4 để xác định $z_{\alpha/2}$)

## Ví dụ

Thăm dò ý kiến của 100 cử tri được chọn ngẫu nhiên tại một địa phương cho thấy có 80% trong số này ủng hộ ứng cử viên A. Với độ tin cậy 98%, hãy ước lượng tỷ lệ của tất cả các cử tri tại địa phương này ủng hộ ứng cử viên A.

## Nhận xét về khoảng tin cậy

- Tung một đồng xu 1000 lần, thấy có 536 lần xuất hiện mặt ngửa.
- Với độ tin cậy 95% ta tìm được khoảng tin cậy $50{,}5\% < p < 56{,}7\%$
- Nhận xét: **có đến 95% khả năng** tỉ lệ tổng thể $p$ nằm trong khoảng từ 50.5% đến 56.7%
- Do đó **nhiều khả năng**, đây là một đồng xu không công bằng.

## Dùng khoảng tin cậy của $p$ để ước lượng $N$

**VD.** Để ước lượng số cá có trong một hồ người ta bắt lên 10.000 con, đánh dấu rồi thả lại xuống hồ. Sau một thời gian, lại bắt lên 8.000 con cá thấy 564 con có đánh dấu. Với độ tin cậy 97%, hãy ước lượng tỉ lệ cá có đánh dấu và số cá có trong hồ?

*Giải.* Tỉ lệ cá có đánh dấu trong mẫu là: $f = \dfrac{564}{8000} = 0{,}0705$

$\varepsilon = z_{\alpha/2}\sqrt{\dfrac{f(1-f)}{n}}$ với $z_{\alpha/2} = 2{,}17$ (97%) $\Rightarrow \varepsilon \approx 0{,}0062$ *(dòng này bị lỗi hiển thị; khôi phục)*.

Tỉ lệ cá có đánh dấu trong hồ vào khoảng: $[f - \varepsilon;\ f + \varepsilon] = [0{,}0643;\ 0{,}0764]$ *(nguyên văn slide; bước tiếp theo dùng cận trên 0,0767, tức là slide có sai lệch một chữ số)*

Vậy số cá có trong hồ vào khoảng:

$$\left[\frac{10.000}{0{,}0767};\ \frac{10.000}{0{,}0643}\right] = [130.379;\ 155.520]$$

## Bài toán xác định cỡ mẫu

**Bài toán:** Xác định cỡ mẫu cần khảo sát để đạt được ước lượng cho tỷ lệ tổng thể với **độ tin cậy và độ sai số cho trước**.

$$\varepsilon = z_{\alpha/2}\sqrt{\frac{f(1-f)}{n}}$$

| Đã có mẫu thăm dò | Chưa có mẫu thăm dò |
|---|---|
| $\varepsilon \le \varepsilon_0$ | **Chú ý:** $f(1-f) = \dfrac{1}{4} - \left(f - \dfrac{1}{2}\right)^2 \le \dfrac{1}{4},\ \forall f \in [0,1]$ |
| $\Leftrightarrow z_{\alpha/2}\sqrt{\dfrac{f(1-f)}{n}} \le \varepsilon_0$ | $\varepsilon = z_{\alpha/2}\sqrt{\dfrac{f(1-f)}{n}} \le z_{\alpha/2}\dfrac{1}{2\sqrt{n}},\ \forall f \in [0,1]$ |
| $\Leftrightarrow n \ge \left(\dfrac{z_{\alpha/2}}{\varepsilon_0}\right)^2 f(1-f)$ | $\varepsilon \le \varepsilon_0 \to z_{\alpha/2}\dfrac{1}{2\sqrt{n}} \le \varepsilon_0 \Rightarrow n \ge \left(\dfrac{z_{\alpha/2}}{2\varepsilon_0}\right)^2$ |

## Ví dụ

Người ta chọn ngẫu nhiên 500 chiếc tivi trong một kho chứa TV thì thấy có 27 TV Sony.

1) Dựa vào mẫu trên, để ước lượng tỉ lệ TV Sony trong kho có độ chính xác là $\varepsilon = 0{,}0177$ thì đảm bảo độ tin cậy của ước lượng là bao nhiêu?
2) Dựa vào mẫu trên, nếu muốn có độ chính xác của ước lượng tỉ lệ TV Sony nhỏ hơn 0,01 với độ tin cậy 95% thì cần chọn thêm ít nhất bao nhiêu TV nữa?

*Giải.* Tỉ lệ TV Sony có trong mẫu là: $f = \dfrac{27}{500} = 0{,}054$

1) Ta có:
$$\varepsilon = z_{\alpha/2}\sqrt{\frac{f(1-f)}{n}} \Rightarrow z_{\alpha/2} = \varepsilon\sqrt{\frac{n}{f(1-f)}}$$
$$\Rightarrow z_{\alpha/2} = 0{,}0177\sqrt{\frac{500}{0{,}054 \times 0{,}946}} \approx 1{,}75$$
$$\Rightarrow 1 - \frac{\alpha}{2} = \varphi(z_{\alpha/2}) = 0{,}9599 \Rightarrow 1 - \alpha = 0{,}9198$$

Vậy độ tin cậy của ước lượng là 91,98%.

2) Gọi $N$ là số TV cần chọn, ta có:
$$\varepsilon < 0{,}01 \Rightarrow z_{\alpha/2}\sqrt{\frac{f(1-f)}{N}} < 0{,}01$$
$$\Rightarrow N > \left(\frac{1{,}96}{0{,}01}\right)^2 \cdot 0{,}054 \cdot 0{,}946 \approx 1962{,}5 \Rightarrow N_{\min} = 1963 \quad \text{(bước này bị lỗi hiển thị; khôi phục)}$$

Vậy cần chọn thêm ít nhất 1463 chiếc TV nữa.

## Ví dụ

Một nhà nghiên cứu muốn ước lượng tỷ lệ những con muỗi mang virus sốt huyết với ***sai số tối đa*** là 3% và độ tin cậy 95%. Hỏi cần khảo sát mẫu có kích thước **nhỏ nhất** là bao nhiêu?

## Đánh giá sai số của bài toán ước lượng tỉ lệ

$$\varepsilon = z_{\alpha/2}\sqrt{\frac{f(1-f)}{n}} \le \frac{z_{\alpha/2}}{2\sqrt{n}} = \varepsilon_{\max}$$

Vì lí do tài chính, một tờ báo quyết định chỉ khảo sát 2000 cử tri về dự định của họ trong cuộc bầu cử sắp tới. Với độ tin cậy 95%, sai số tối đa khi ước lượng tỷ lệ cử tri bầu cho ứng viên X là bao nhiêu?

## Bài tập

**Bài tập.** Tỉnh $X$ có 1.000.000 thanh niên. Người ta khảo sát ngẫu nhiên 20.000 thanh niên của tỉnh $X$ về trình độ học vấn thì thấy có 12.575 thanh niên đã tốt nghiệp PTTH. Hãy ước lượng tỉ lệ thanh niên đã tốt nghiệp PTTH của tỉnh $X$ với độ tin cậy 95%? Số thanh niên đã tốt nghiệp PTTH của tỉnh $X$ trong khoảng nào?

**Bài tập.** Lấy ngẫu nhiên 200 sản phẩm trong kho hàng $A$ thấy có 21 phế phẩm.

1) Dựa vào mẫu trên, để ước lượng tỉ lệ phế phẩm trong kho $A$ có độ chính xác là $\varepsilon = 0{,}035$ thì đảm bảo độ tin cậy của ước lượng là bao nhiêu?
2) Dựa vào mẫu trên, nếu muốn có độ chính xác của ước lượng tỉ lệ phế phẩm nhỏ hơn 0,01 với độ tin cậy 93% thì cần kiểm tra thêm ít nhất bao nhiêu sản phẩm nữa?

**Bài tập.** Khảo sát năng suất $X$ (tấn/ha) của 100 ha lúa ở huyện $A$, ta có bảng số liệu:

| $X$ | 3,25 | 3,75 | 4,25 | 4,75 | 5,25 | 5,75 | 6,25 | 6,75 |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| $S$ (ha) | 7 | 12 | 18 | 27 | 20 | 8 | 5 | 3 |

Những thửa ruộng có năng suất lúa trên 5,5 tấn/ha là những thửa ruộng có năng suất cao. Sử dụng bảng khảo sát trên, để ước lượng tỉ lệ diện tích lúa có năng suất cao ở huyện $A$ có độ chính xác là $\varepsilon = 8{,}54\%$ thì đảm bảo độ tin cậy là bao nhiêu?

A. 92%; B. 94%; C. 96%; D. 98%.

**Bài tập.** Khảo sát doanh số bán của một siêu thị trong một số ngày được chọn ngẫu nhiên, ta thu được số liệu như bảng kế bên:

| Doanh số (triệu đồng) | Số ngày |
|:-:|:-:|
| 50 - 70 | 6 |
| 70 - 90 | 30 |
| 90 - 110 | 40 |
| 110 - 130 | 25 |
| 130 - 150 | 15 |
| 150 – 200 | 5 |

1. Hãy ước lượng doanh số bán trung bình của siêu thị trong một ngày với độ tin cậy 95%.
2. Nếu muốn sai số ước lượng doanh số bình trung ngày có sai số không quá 2 triệu đồng/ngày ở độ tin cậy 99% thì có cần thêm ngày quan sát không? Nếu có thì cần quan sát thêm ít nhất bao nhiêu ngày?
3. Những ngày có doanh số bán trên 130 triệu đồng được gọi là ngày đắt hàng. Hãy ước lượng tỷ lệ những ngày đắt hàng của siêu thị với độ tin cậy 90%.
4. Hãy ước lượng doanh số trung bình của một ngày đắt hàng với độ tin cậy 96%. Cho biết doanh số bán hàng có phân phối chuẩn.

**Bài tập.** Giả sử tại tp HCM, thăm dò 500 người dân về việc đập bỏ Dinh Thượng Thư, có 380 người không đồng ý.

1. Với độ tin cậy 95%, hãy ước lượng tỷ lệ người dân tp HCM không đồng ý việc đập bỏ Dinh Thượng Thư
2. Nếu muốn độ chính xác của phép ước lượng là 3% thì độ tin cậy là bao nhiêu?
3. Nếu muốn phép ước lượng có độ tin cậy là 99% và độ chính xác là 3% thì cần thăm dò thêm bao nhiêu người nữa?
