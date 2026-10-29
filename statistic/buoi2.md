# Chương 2. Biến ngẫu nhiên

**Mục lục**

- §1. Biến ngẫu nhiên và hàm mật độ
- §2. Hàm phân phối xác suất
- §3. Tham số đặc trưng của biến ngẫu nhiên

---

# §1. BIẾN NGẪU NHIÊN VÀ HÀM MẬT ĐỘ

## 1.1. Khái niệm biến ngẫu nhiên

Xét một phép thử với không gian mẫu $\Omega$.

Giả sử, ứng với mỗi biến cố sơ cấp $\omega \in \Omega$, ta liên kết với một số thực $X(\omega) \in \mathbb{R}$, thì $X$ được gọi là một **biến ngẫu nhiên** (*đại lượng ngẫu nhiên*).

Tổng quát, biến ngẫu nhiên (BNN) $X$ của một phép thử với không gian mẫu $\Omega$ là một ánh xạ

$$X : \Omega \to \mathbb{R}, \qquad \omega \mapsto X(\omega) = x.$$

Giá trị $x$ được gọi là một giá trị của biến ngẫu nhiên $X$.

### VD 1

Người $A$ mua một loại bảo hiểm tai nạn trong 1 năm với phí là 70 ngàn đồng. Nếu bị tai nạn thì công ty sẽ chi trả 3 triệu đồng. Gọi $X$ là số tiền người $A$ có được sau 1 năm mua bảo hiểm này. Khi đó, ta có:

- Phép thử là: "mua bảo hiểm tai nạn".
- Biến cố là $T$: "người $A$ bị tai nạn".
- Không gian mẫu là $\Omega = \{T, \bar{T}\}$.
- Vậy $X(T) = 2{,}93$ (triệu), $X(\bar{T}) = -0{,}07$ (triệu).

### Ký hiệu biến cố theo BNN

Ký hiệu $\{X = x\}$ là **một biến cố** bao gồm *các biến cố sơ cấp* $\omega$ sao cho $X(\omega) = x$, nghĩa là

$$\{X = x\} = \{\omega \in \Omega : X(\omega) = x\}$$

Tương tự, ta có

$$\{X \le x\} = \{\omega \in \Omega : X(\omega) \le x\}, \qquad \{X < x\} = \{\omega \in \Omega : X(\omega) < x\}, \ \dots$$

**Ví dụ.** Tung một đồng xu 2 lần, ta có không gian mẫu: $\Omega = \{NN, NS, SN, SS\}$.

- Nếu gọi $X$ là ĐLNN thể hiện *số lần mặt ngửa xuất hiện*, thì:
  $X(NN) = 2,\ X(NS) = X(SN) = 1,\ X(SS) = 0$
- **Miền giá trị** của ĐLNN $X$: $X(\Omega) = \{0, 1, 2\}$
- Xác suất:
  - $\{X = 0\} = \{SS\} \Rightarrow P(X = 0) = 1/4$,
  - $\{X = 1\} = \{NS, SN\} \Rightarrow P(X = 1) = 1/2$,
  - $\{X \le 1\} = \{NS, SN, SS\} \Rightarrow P(X \le 1) = 3/4$.

### Phân loại biến ngẫu nhiên

- Nếu $X(\Omega)$ là 1 tập hữu hạn $\{x_1, x_2, \dots, x_n\}$ hay vô hạn đếm được thì $X$ được gọi là **biến ngẫu nhiên rời rạc**. Để cho gọn, ta viết là $X = \{x_1, x_2, \dots, x_n, \dots\}$.
- Nếu $X(\Omega)$ là 1 khoảng của $\mathbb{R}$ (hay cả $\mathbb{R}$) thì $X$ được gọi là **biến ngẫu nhiên liên tục**.

*Ví dụ:* Chọn ngẫu nhiên một số thực trong đoạn $[0,1]$, gọi $X$ là giá trị được chọn. Khi đó $X$ là ĐLNN liên tục.

ĐLNN liên tục: thời gian cài đặt phần mềm, thời gian download file, …

ĐLNN liên tục: cân nặng, chiều cao, nhiệt độ, …

- Cho biến ngẫu nhiên $X$ và hàm số $y = \varphi(x)$. Khi đó, biến ngẫu nhiên $Y = \varphi(X)$ được gọi là **hàm của biến ngẫu nhiên $X$**.

---

## 1.2. Hàm mật độ

### a) Biến ngẫu nhiên rời rạc

Cho BNN rời rạc $X : \Omega \to \mathbb{R}$, $X = \{x_1, x_2, \dots, x_n, \dots\}$.

Giả sử $x_1 < x_2 < \dots < x_n < \dots$ với xác suất tương ứng:

$$P(X = x_i) = p_i, \quad i = 1, 2, \dots$$

Ta định nghĩa:

- **Bảng phân phối xác suất của $X$** là

| $X$ | $x_1$ | $x_2$ | … | $x_n$ | … |
|-----|-------|-------|---|-------|---|
| $P$ | $p_1$ | $p_2$ | … | $p_n$ | … |

- **Hàm mật độ của $X$** là

$$f(x) = \begin{cases} p_i & \text{khi } x = x_i, \\ 0 & \text{khi } x \ne x_i,\ \forall i. \end{cases}$$

**Chú ý**

- $p_i \ge 0$; $\sum p_i = 1$, $i = 1, 2, \dots$

- Nếu $x \notin \{x_1, x_2, \dots, x_n, \dots\}$ thì $P(X = x) = 0$

- $P(a < X \le b) = \displaystyle\sum_{a < x_i \le b} p_i$

### VD 2

Cho BNN rời rạc $X$ có bảng phân phối xác suất:

| $X$ | −1 | 0 | 1 | 3 | 5 |
|-----|----|---|-----|----|-----|
| $P$ | $3a$ | $a$ | 0,1 | $2a$ | 0,3 |

1. Tìm $a$ và tính $P(-1 < X \le 3)$.
2. Lập bảng phân phối xác suất của hàm $Y = X^2$.

**Giải**

1. Ta có: $\sum p_i = 1 \Rightarrow 3a + a + 0{,}1 + 2a + 0{,}3 = 1 \Rightarrow a = 0{,}1$.

   Vậy
   $$P(-1 < X \le 3) = P(X = 0) + P(X = 1) + P(X = 3) = 0{,}1 + 0{,}1 + 0{,}2 = 0{,}4.$$

2. Bảng phân phối xác suất của hàm $Y = X^2$:

   | $Y$ | 1 | 0 | 1 | 9 | 25 |
   |-----|-----|-----|-----|-----|-----|
   | $P$ | 0,3 | 0,1 | 0,1 | 0,2 | 0,3 |

   Gộp hai giá trị $Y = 1$ (xác suất 0,3 và 0,1):

   | $Y$ | 0 | 1 | 9 | 25 |
   |-----|-----|-----|-----|-----|
   | $P$ | 0,1 | 0,4 | 0,2 | 0,3 |

### VD 4

Một hộp có 3 viên phấn trắng và 2 viên phấn đỏ. Một người lấy ngẫu nhiên mỗi lần 1 viên (không trả lại) từ hộp đó ra cho đến khi lấy được 2 viên phấn đỏ. Gọi $X$ là số lần người đó lấy phấn. Hãy lập bảng phân phối xác suất và hàm mật độ của $X$?

**Giải.** Ta có: $X = \{2; 3; 4; 5\}$.

Gọi $A_i$: "viên phấn được lấy lần thứ $i$ là đỏ", $i = \overline{1;5}$. Ta có:

- $P(X = 2) = P(A_1 A_2) = P(A_1)\,P(A_2 \mid A_1) = \dfrac{2}{5} \cdot \dfrac{1}{4} = 0{,}1$

- $P(X = 3) = P(A_1 \bar{A}_2 A_3) + P(\bar{A}_1 A_2 A_3) = \dfrac{2}{5} \cdot \dfrac{3}{4} \cdot \dfrac{1}{3} + \dfrac{3}{5} \cdot \dfrac{2}{4} \cdot \dfrac{1}{3} = 0{,}2$

- $P(X = 4) = P(A_1 \bar{A}_2 \bar{A}_3 A_4) + P(\bar{A}_1 A_2 \bar{A}_3 A_4) + P(\bar{A}_1 \bar{A}_2 A_3 A_4) = 0{,}3$

- $P(X = 5) = 1 - \dfrac{1}{10} - \dfrac{2}{10} - \dfrac{3}{10} = 0{,}4$

Vậy bảng phân phối xác suất của $X$ là:

| $X$ | 2 | 3 | 4 | 5 |
|-----|-----|-----|-----|-----|
| $P$ | 0,1 | 0,2 | 0,3 | 0,4 |

Hàm mật độ của $X$ là:

$$f(x) = \begin{cases} 0{,}1 & \text{khi } x = 2, \\ 0{,}2 & \text{khi } x = 3, \\ 0{,}3 & \text{khi } x = 4, \\ 0{,}4 & \text{khi } x = 5, \\ 0 & \text{khi } x \ne 2, 3, 4, 5 \end{cases}$$

### b) Biến ngẫu nhiên liên tục

Hàm số $f : \mathbb{R} \to \mathbb{R}$ được gọi là **hàm mật độ** của biến ngẫu nhiên liên tục $X$ nếu:

$$P(a \le X \le b) = \int_a^b f(x)\,dx, \quad \forall a, b \in \mathbb{R}$$

**Chú ý.** $f(x)$ là hàm mật độ của biến ngẫu nhiên liên tục $X$ khi và chỉ khi

$$f(x) \ge 0,\ \forall x \in \mathbb{R} \quad \text{và} \quad \int_{-\infty}^{+\infty} f(x)\,dx = 1$$

**Nhận xét**

- Khi $f(x)$ liên tục trên lân cận của điểm $a$, ta có:

  $$P(a - \varepsilon \le X \le a + \varepsilon) = \int_{a-\varepsilon}^{a+\varepsilon} f(x)\,dx \ \Rightarrow\ P(X = a) = \lim_{\varepsilon \to 0} \int_{a-\varepsilon}^{a+\varepsilon} f(x)\,dx = 0$$

  Vậy
  $$P(a \le X < b) = P(a < X \le b) = P(a < X < b) = \int_a^b f(x)\,dx$$

- **Ý nghĩa hình học:** xác suất của biến ngẫu nhiên $X$ nhận giá trị trong $[a; b]$ bằng diện tích hình thang cong giới hạn bởi $x = a$, $x = b$, $y = f(x)$ và $Ox$

### VD 5

Chứng tỏ
$$f(x) = \begin{cases} 4x^3, & x \in [0; 1] \\ 0, & x \notin [0; 1] \end{cases}$$
là hàm mật độ của biến ngẫu nhiên $X$ và tính $P(0{,}5 \le X < 3)$?

**Giải**

- Ta có: $f(x) \ge 0,\ \forall x \in \mathbb{R}$ và
  $$\int_{-\infty}^{+\infty} f(x)\,dx = \int_{-\infty}^{0} f(x)\,dx + \int_{0}^{1} f(x)\,dx + \int_{1}^{+\infty} f(x)\,dx = \int_0^1 4x^3\,dx = x^4 \Big|_0^1 = 1.$$

  Vậy $f(x)$ là hàm mật độ của BNN $X$.

- $$P(0{,}5 \le X < 3) = \int_{0{,}5}^{3} f(x)\,dx = \int_{0{,}5}^{1} f(x)\,dx + \int_{1}^{3} f(x)\,dx = \int_{0{,}5}^{1} 4x^3\,dx = x^4 \Big|_{0{,}5}^{1} = \frac{15}{16}.$$

### VD 6

Cho biến ngẫu nhiên $X$ có hàm mật độ:
$$f(x) = \begin{cases} 0, & x < 2 \\ \dfrac{k}{x^2}, & x \ge 2. \end{cases}$$
Tính $P(-3 < X < 5)$?

**Giải.** Do $f(x)$ là hàm mật độ của $X$, nên:

$$\int_{-\infty}^{+\infty} f(x)\,dx = 1 \Rightarrow k \int_2^{+\infty} \frac{dx}{x^2} = 1 \Rightarrow -\frac{k}{x}\Big|_2^{+\infty} = 1 \Rightarrow k = 2.$$

Vậy
$$P(-3 < X < 5) = \int_{-3}^{5} f(x)\,dx = 2\int_2^5 \frac{dx}{x^2} = -\frac{2}{x}\Big|_2^5 = 0{,}6.$$

---

# §2. HÀM PHÂN PHỐI XÁC SUẤT

## 2.1. Định nghĩa

**Hàm phân phối xác suất** (hay hàm phân phối tích lũy) của biến ngẫu nhiên $X$, ký hiệu $F(x)$, là xác suất để $X$ nhận giá trị nhỏ hơn hay bằng $x$ với mọi $x \in \mathbb{R}$.

Nghĩa là:

$$F(x) = P(X \le x), \quad \forall x \in \mathbb{R}.$$

### Nhận xét 1

- Nếu biến ngẫu nhiên $X$ là **rời rạc** với phân phối xác suất $P(X = x_i) = p_i$ thì:
  $$F(x) = \sum_{x_i \le x} p_i.$$
- Nếu biến ngẫu nhiên $X$ là **liên tục** với hàm mật độ $f(x)$ thì:
  $$F(x) = \int_{-\infty}^{x} f(t)\,dt.$$

(Ý nghĩa hình học: $F(x_1)$ là diện tích phần nằm dưới đường cong $f(x)$ và bên trái $x = x_1$; tương tự cho $F(x_2)$.)

### Nhận xét 2

Giả sử BNN rời rạc $X$ nhận các giá trị trong $[x_1; x_n]$ và $x_1 < x_2 < \dots < x_n$, $P(X = x_i) = p_i$ $(i = 1, 2, \dots, n)$.

Ta có hàm phân phối của $X$ là:

$$F(x) = \begin{cases}
0 & \text{khi } x < x_1 \\
p_1 & \text{khi } x_1 \le x < x_2 \\
p_1 + p_2 & \text{khi } x_2 \le x < x_3 \\
\dots & \dots \\
p_1 + p_2 + \dots + p_{n-1} & \text{khi } x_{n-1} \le x < x_n \\
1 & \text{khi } x_n \le x.
\end{cases}$$

**Chứng minh:**

- $x < x_1$: $F(x) = P(X \le x) = P(X < x_1) = P(\emptyset) = 0$.
- $x_1 \le x < x_2$: $F(x) = P(X < x_2) = P(X = x_1) = p_1$.
- $x_2 \le x < x_3$: $F(x) = P(X < x_3) = P(X = x_1) + P(X = x_2) = p_1 + p_2$.
- …
- $x_n \le x$: $F(x) = P(X \le x_n) = P(X = x_1) + \dots + P(X = x_n) = p_1 + \dots + p_n = 1$.

**Quy ước.** Nếu BNN $X$ liên tục thì miền xác định của $F(x)$ được lấy theo hàm mật độ $f(x)$.

- Giả sử BNN liên tục $X$ có hàm mật độ
  $$f(x) = \begin{cases} \varphi(x), & x \in [a; b] \\ 0, & x \notin [a; b]. \end{cases}$$
  Ta có hàm phân phối của $X$ là:
  $$F(x) = \begin{cases} 0 & \text{khi } x < a \\ \displaystyle\int_a^x \varphi(t)\,dt & \text{khi } a \le x \le b \\ 1 & \text{khi } b < x. \end{cases}$$

- Giả sử BNN liên tục $X$ có hàm mật độ
  $$f(x) = \begin{cases} 0, & x < a \\ \varphi(x), & x \ge a. \end{cases}$$
  Ta có hàm phân phối của $X$ là:
  $$F(x) = \begin{cases} 0 & \text{khi } x < a \\ \displaystyle\int_a^x \varphi(t)\,dt & \text{khi } x \ge a. \end{cases}$$

- Giả sử BNN liên tục $X$ có hàm mật độ
  $$f(x) = \begin{cases} \varphi(x), & x \le a \\ 0, & x > a. \end{cases}$$
  Ta có hàm phân phối của $X$ là:
  $$F(x) = \begin{cases} \displaystyle\int_{-\infty}^x \varphi(t)\,dt & \text{khi } x \le a \\ 1 & \text{khi } x > a. \end{cases}$$

### VD 1

Cho BNN $X$ có bảng phân phối xác suất là:

| $X$ | −2 | 1 | 3 | 4 |
|-----|-----|-----|-----|-----|
| $P$ | 0,1 | 0,2 | 0,2 | 0,5 |

Hãy lập hàm phân phối của $X$ và vẽ đồ thị của $F(x)$?

**Giải.** Hàm phân phối của $X$ là:

$$F(x) = \begin{cases}
0 & \text{khi } x < -2 \\
0{,}1 & \text{khi } -2 \le x < 1 \\
0{,}3 & \text{khi } 1 \le x < 3 \\
0{,}5 & \text{khi } 3 \le x < 4 \\
1 & \text{khi } 4 \le x.
\end{cases}$$

Đồ thị của $F(x)$ là hàm bậc thang, nhảy lên các mức 0,1; 0,3; 0,5; 1 tại các điểm $x = -2, 1, 3, 4$ (liên tục phải tại mỗi điểm nhảy).

### VD 2

Cho BNN $X$ có hàm mật độ là:
$$f(x) = \begin{cases} 0, & x \notin [0; 1] \\ 3x^2, & x \in [0; 1]. \end{cases}$$
Tìm hàm phân phối của $X$ và vẽ đồ thị của $F(x)$?

**Giải.** Hàm phân phối của $X$ là:

$$F(x) = \begin{cases} 0, & x < 0 \\ \displaystyle\int_0^x 3t^2\,dt, & 0 \le x \le 1 \\ 1, & 1 < x \end{cases} = \begin{cases} 0, & x < 0 \\ x^3, & 0 \le x \le 1 \\ 1, & 1 < x. \end{cases}$$

Đồ thị của $F(x)$: bằng 0 khi $x < 0$, là đường cong $y = x^3$ trên $[0; 1]$, rồi bằng 1 khi $x > 1$.

### VD 3

Cho BNN $X$ có hàm mật độ là:
$$f(x) = \begin{cases} 0, & x < 100 \\ \dfrac{100}{x^2}, & x \ge 100. \end{cases}$$
Tìm hàm phân phối $F(x)$ của $X$?

**Giải.** Hàm phân phối $F(x)$ của $X$ là:

$$F(x) = \begin{cases} 0, & x < 100 \\ 100 \displaystyle\int_{100}^x \frac{dt}{t^2}, & x \ge 100 \end{cases} = \begin{cases} 0, & x < 100 \\ \dfrac{x - 100}{x}, & x \ge 100. \end{cases}$$

---

## 2.2. Tính chất của hàm phân phối xác suất

1. Hàm $F(x)$ xác định với mọi $x \in \mathbb{R}$.
2. $0 \le F(x) \le 1,\ \forall x \in \mathbb{R}$; $F(-\infty) = 0$; $F(+\infty) = 1$.
3. $F(x)$ không giảm và liên tục phải tại mọi $x \in \mathbb{R}$. Đặc biệt, với $X$ liên tục thì $F(x)$ liên tục $\forall x \in \mathbb{R}$.
4. $P(a \le X \le b) = F(b) - F(a)$.

**Đặc biệt**

- Nếu $X$ là BNN **rời rạc** thì:
  $$p_i = F(x_{i+1}) - F(x_i),\ \forall i.$$
- Nếu $X$ là BNN **liên tục** thì:
  $$P(a \le X \le b) = P(a \le X < b) = P(a < X \le b) = P(a < X < b) = F(b) - F(a).$$
- Nếu $X$ là BNN liên tục có hàm mật độ $f(x)$ thì:
  $$F'(x) = f(x).$$

### VD 4

Tính xác suất $P(X \ge 400)$ trong VD 3?

**Giải**

$$P(X \ge 400) = P(400 \le X < +\infty) = F(+\infty) - F(400) = 1 - \frac{3}{4} = \frac{1}{4}.$$

### VD 6

Cho BNN $X$ có hàm phân phối xác suất:
$$F(x) = \begin{cases} 0, & x \le -2 \\ ax^3 + 2b, & x \in (-2; 3] \\ 1, & x > 3. \end{cases}$$

1. Tìm các hằng số $a$ và $b$?
2. Tính $P\left(\sqrt{2} < Y \le \sqrt{5}\right)$ với $Y = \sqrt{X^2 + 1}$.

**Giải**

1. Do $F(x)$ liên tục tại mọi $x \in \mathbb{R}$, nên:
   - $\displaystyle\lim_{x \to -2^+} F(x) = F(-2) \Rightarrow -8a + 2b = 0$ (1),
   - $\displaystyle\lim_{x \to 3^+} F(x) = F(3) \Rightarrow 27a + 2b = 1$ (2).

   Từ (1) và (2) ta có: $a = \dfrac{1}{35}$ và $b = \dfrac{4}{35}$.

2. $$P\left(\sqrt{2} < Y \le \sqrt{5}\right) = P\left(\sqrt{2} < \sqrt{X^2 + 1} \le \sqrt{5}\right) = P(-2 \le X < -1) + P(1 < X \le 2)$$
   $$= F(-1) - F(-2) + F(2) - F(1) = \frac{14}{35}.$$

---

# §3. THAM SỐ ĐẶC TRƯNG CỦA BIẾN NGẪU NHIÊN

Những thông tin cô đọng phản ánh từng phần về biến ngẫu nhiên giúp ta so sánh giữa các đại lượng với nhau được gọi là **các đặc trưng số**. Có 3 loại đặc trưng số là:

- Các đặc trưng số cho xu hướng trung tâm của BNN: ***Trung vị***, ***Mode***, ***Kỳ vọng***, …
- Các đặc trưng số cho độ phân tán của BNN: ***Phương sai***, ***Độ lệch chuẩn***, …
- Các đặc trưng số cho dạng phân phối xác suất.

**Nội dung:**

- 3.1. Mode
- 3.2. Kỳ vọng (định nghĩa; tính chất; ý nghĩa; kỳ vọng của hàm của biến ngẫu nhiên)
- 3.3. Phương sai (định nghĩa; tính chất; ý nghĩa)

---

## 3.1. MODE

**Mode** của biến ngẫu nhiên $X$, ký hiệu $\mathrm{Mod}X$, là giá trị $x_0 \in X$ thỏa:

- $P(X = x_0)$ max nếu $X$ là rời rạc, và
- $f(x_0)$ max nếu $X$ liên tục có hàm mật độ $f(x)$.

**Chú ý**

- $\mathrm{Mod}X$ còn được gọi là **giá trị tin chắc nhất** của $X$.
- Biến ngẫu nhiên $X$ có thể có nhiều $\mathrm{Mod}X$.

### VD 1

Cho BNN $X$ có bảng phân phối xác suất:

| $X$ | 0 | 1 | 2 | 4 | 5 | 8 |
|-----|------|------|------|------|------|------|
| $P$ | 0,10 | 0,20 | **0,30** | 0,05 | 0,25 | 0,10 |

$\Rightarrow \mathrm{Mod}X = 2$.

### VD 2

Tìm $\mathrm{Mod}X$, biết $X$ có bảng phân phối xác suất:

| $X$ | 1 | 2 | 4 | 5 | 8 |
|-----|--------|------|------|------|-----|
| $P$ | $1 - 3p$ | 0,18 | 0,07 | 0,25 | $p$ |

**Giải.** Ta có: $1 - 3p + 0{,}18 + 0{,}07 + 0{,}25 + p = 1 \Rightarrow p = 0{,}25$.

Vậy $\mathrm{Mod}X = 1;\ 5;\ 8$.

### VD 3

Tìm $\mathrm{Mod}X$, biết $X$ có hàm mật độ xác suất:
$$f(x) = \begin{cases} \dfrac{3}{64} x^2 (4 - x), & x \in [0; 4] \\ 0, & x \notin [0; 4]. \end{cases}$$

**Giải.** Với $x \in [0; 4]$, ta có:

$$f'(x) = 0 \Leftrightarrow x = 0,\ x = \frac{8}{3}.$$

$$f(0) = f(4) = 0,\quad f\left(\frac{8}{3}\right) = \frac{4}{9}$$

$$\Rightarrow \max_{\mathbb{R}} f(x) = f\left(\frac{8}{3}\right) = \frac{4}{9}. \quad \text{Vậy } \mathrm{Mod}X = \frac{8}{3}.$$

---

## 3.2. KỲ VỌNG

### 3.2.1. Định nghĩa

**Kỳ vọng** (*Expectation*) của biến ngẫu nhiên $X$, ký hiệu $EX$ hay $M(X)$, là một số thực được xác định như sau:

- Nếu $X$ là **rời rạc** với xác suất $P(X = x_i) = p_i$ thì:
  $$EX = \sum_i x_i p_i.$$
- Nếu $X$ là **liên tục** có hàm mật độ $f(x)$ thì:
  $$EX = \int_{-\infty}^{+\infty} x \cdot f(x)\,dx.$$

**Đặc biệt.** Nếu biến ngẫu nhiên rời rạc $X = \{x_1; x_2; \dots; x_n\}$ với xác suất tương ứng là $p_1, p_2, \dots, p_n$ thì:

$$EX = x_1 p_1 + x_2 p_2 + \dots + x_n p_n.$$

### VD 4

Cho BNN $X$ có bảng phân phối xác suất:

| $X$ | −1 | 0 | 2 | 3 |
|-----|-----|-----|-----|-----|
| $P$ | 0,1 | 0,2 | 0,4 | 0,3 |

Tính kỳ vọng của $X$?

**Giải.** Ta có: $EX = -1 \times 0{,}1 + 0 \times 0{,}2 + 2 \times 0{,}4 + 3 \times 0{,}3$. Vậy $EX = 1{,}6$.

### VD 6

Tìm kỳ vọng của BNN $X$ có hàm mật độ:
$$f(x) = \begin{cases} \dfrac{3}{4}(x^2 + 2x), & x \in [0; 1] \\ 0, & x \notin [0; 1]. \end{cases}$$

**Giải.**
$$EX = \int_{-\infty}^{+\infty} x f(x)\,dx = \frac{3}{4}\int_0^1 (x^3 + 2x^2)\,dx = \frac{3}{4}\left(\frac{x^4}{4} + \frac{2x^3}{3}\right)\Big|_0^1 = \frac{11}{16}.$$

**Chú ý**

- Nếu $X$ là BNN liên tục trên $[a; b]$ thì $EX \in [a; b]$.
- Nếu $X = \{x_1, \dots, x_n\}$ thì: $EX \in [\min\{x_1, \dots, x_n\};\ \max\{x_1, \dots, x_n\}]$.

### 3.2.2. Tính chất của Kỳ vọng

1. $EC = C$, $C \in \mathbb{R}$.
2. $E(CX) = C \cdot EX$, $C \in \mathbb{R}$.
3. $E(X \pm Y) = EX \pm EY$.
4. $E(X \cdot Y) = EX \cdot EY$ nếu $X, Y$ độc lập.

**Bài tập về nhà.** Cho hai biến ngẫu nhiên $X, Y$ độc lập có bảng ppxs:

| $X$ | −1 | 1 | 3 |
|-----|-----|-----|-----|
| $P$ | 0,3 | 0,1 | 0,6 |

| $Y$ | −1 | 2 |
|-----|-----|-----|
| $P$ | 0,6 | 0,4 |

Tính $E(X^2 \cdot Y - 3XY + 5Y + 7)$.

### 3.2.3. Ý nghĩa của Kỳ vọng

- Kỳ vọng của biến ngẫu nhiên $X$ là **giá trị trung bình** (tính theo xác suất) mà $X$ nhận được, nó phản ánh giá trị trung tâm phân phối xác suất của $X$.
- Trong thực tế sản xuất hay kinh doanh, khi cần chọn phương án cho **năng suất** hay **lợi nhuận** cao, người ta thường chọn phương án sao cho **kỳ vọng năng suất** hay **kỳ vọng lợi nhuận** cao.

### VD 9

Một thống kê cho biết tỉ lệ tai nạn xe máy ở thành phố $H$ là 0,001. Công ty bảo hiểm $A$ đề nghị bán loại bảo hiểm tai nạn xe máy cho ông $B$ ở thành phố $H$ trong 1 năm với số tiền chi trả là 10 (triệu đồng), phí bảo hiểm là 0,1 (triệu đồng). Hỏi trung bình công ty $A$ lãi bao nhiêu khi bán bảo hiểm cho ông $B$?

**Giải.** Gọi $X$ (triệu đồng) là tiền lãi của công ty $A$ sau khi bán bảo hiểm cho ông $B$.

- Khi ông $B$ không bị tai nạn thì: $X = 0{,}1$ và xác suất $p = 0{,}999$.
- Khi ông $B$ bị tai nạn thì: $X = 0{,}1 - 10 = -9{,}9$; $p = 0{,}001$.

Vậy trung bình tiền lãi của công ty $A$ là:
$$EX = 0{,}1 \times 0{,}999 - 9{,}9 \times 0{,}001 = 0{,}09 \text{ (triệu đồng)}.$$

### 3.2.4. Kỳ vọng của hàm của biến ngẫu nhiên

Giả sử $Y = \varphi(X)$ là hàm của biến ngẫu nhiên $X$.

- Nếu $X$ là biến ngẫu nhiên **rời rạc** thì:
  $$EY = \sum_i y_i \cdot p_i = \sum_i \varphi(x_i) \cdot p_i$$
- Nếu $X$ là biến ngẫu nhiên **liên tục** thì:
  $$EY = \int_{-\infty}^{+\infty} y \cdot f(x)\,dx = \int_{-\infty}^{+\infty} \varphi(x) \cdot f(x)\,dx$$

**Chú ý.** Khi biến ngẫu nhiên $X$ là rời rạc thì ta nên lập bảng phân phối xác suất của $Y$, rồi tính $EY$.

### VD 13

Cho BNN $X$ có bảng phân phối xác suất:

| $X$ | −1 | 0 | 1 | 2 |
|-----|-----|-----|------|------|
| $P$ | 0,1 | 0,3 | 0,35 | 0,25 |

Tính $EY$ với $Y = X^2 - 3$?

**Giải.** Ta có bảng phân phối xác suất của $Y$ là:

| $Y$ | −3 | −2 | 1 |
|-----|-----|------|------|
| $P$ | 0,3 | 0,45 | 0,25 |

Vậy $EY = -3 \cdot 0{,}3 - 2 \cdot 0{,}45 + 1 \cdot 0{,}25 = -1{,}55$.

### VD 14

Cho BNN $X$ có hàm mật độ xác suất:
$$f(x) = \begin{cases} \dfrac{2}{x^2}, & x \in [1; 2] \\ 0, & x \notin [1; 2]. \end{cases}$$
Tính $EY$ với $Y = X^5 - \dfrac{2}{X}$?

**Giải.** Áp dụng công thức, ta có:

$$EY = \int_{-\infty}^{+\infty} y \cdot f(x)\,dx = \int_1^2 \left(x^5 - \frac{2}{x}\right) \cdot \frac{2}{x^2}\,dx = \left(\frac{x^4}{2} + \frac{2}{x^2}\right)\Big|_1^2 = 6.$$

---

## 3.3. PHƯƠNG SAI

### 3.3.1. Định nghĩa

**Phương sai** (*Variance* hay *Dispersion*) của biến ngẫu nhiên $X$, ký hiệu $VarX$ hay $D(X)$, là một số thực không âm được xác định bởi:

$$VarX = E(X - EX)^2 = E(X^2) - (EX)^2.$$

*Chứng minh:*
$$VarX = E(X - EX)^2 = E\left[X^2 - 2X \cdot EX + (EX)^2\right] = E(X^2) - 2 \cdot EX \cdot EX + (EX)^2 = E(X^2) - (EX)^2.$$

- Nếu BNN $X$ là **rời rạc** và $P(X = x_i) = p_i$ thì:
  $$VarX = \sum_i x_i^2 \cdot p_i - \left(\sum_i x_i \cdot p_i\right)^2.$$
- Nếu BNN $X$ là **liên tục** và có hàm mật độ $f(x)$ thì:
  $$VarX = \int_{-\infty}^{+\infty} x^2 \cdot f(x)\,dx - \left(\int_{-\infty}^{+\infty} x \cdot f(x)\,dx\right)^2.$$

### VD 15

Cho BNN $X$ có bảng phân phối xác suất:

| $X$ | 1 | 2 | 3 |
|-----|-----|-----|-----|
| $P$ | 0,2 | 0,7 | 0,1 |

Ta có:
$$VarX = (1^2 \cdot 0{,}2 + 2^2 \cdot 0{,}7 + 3^2 \cdot 0{,}1) - (1 \cdot 0{,}2 + 2 \cdot 0{,}7 + 3 \cdot 0{,}1)^2 = 0{,}29.$$

### VD 16

Tính phương sai của $X$, biết hàm mật độ:
$$f(x) = \begin{cases} \dfrac{3}{4}(x^2 + 2x), & x \in [0; 1] \\ 0, & x \notin [0; 1]. \end{cases}$$

**Giải.** Áp dụng công thức, ta có:

$$VarX = \int_0^1 x^2 \cdot \frac{3}{4}(x^2 + 2x)\,dx - \left[\int_0^1 x \cdot \frac{3}{4}(x^2 + 2x)\,dx\right]^2$$
$$= \frac{3}{4}\left(\frac{x^5}{5} + \frac{x^4}{2}\right)\Big|_0^1 - \left[\frac{3}{4}\left(\frac{x^4}{4} + \frac{2x^3}{3}\right)\Big|_0^1\right]^2 = \frac{67}{1280}.$$

### VD 17

Cho BNN $X$ có hàm mật độ xác suất:
$$f(x) = \begin{cases} \dfrac{3}{4}(1 - x^2), & |x| \le 1 \\ 0, & |x| > 1. \end{cases}$$
Tính phương sai của $Y$, cho biết $Y = 2X^2$.

**Giải.**
$$VarY = \int_{-1}^{1} y^2 \cdot f(x)\,dx - \left(\int_{-1}^{1} y \cdot f(x)\,dx\right)^2$$
$$= \int_{-1}^{1} (2x^2)^2 \cdot \frac{3}{4}(1 - x^2)\,dx - \left[\int_{-1}^{1} 2x^2 \cdot \frac{3}{4}(1 - x^2)\,dx\right]^2$$
$$= 3\left(\frac{x^5}{5} - \frac{x^7}{7}\right)\Big|_{-1}^{1} - \left[\frac{3}{2}\left(\frac{x^3}{3} - \frac{x^5}{5}\right)\Big|_{-1}^{1}\right]^2 = \frac{32}{175}.$$

### 3.3.2. Tính chất của Phương sai

1. $VarC = 0$, $C \in \mathbb{R}$;
2. $Var(CX) = C^2 \cdot VarX$;
3. $Var(X \pm Y) = VarX + VarY$ nếu $X$ và $Y$ độc lập.

### 3.3.3. Ý nghĩa của Phương sai

- $(X - EX)^2$ là bình phương sai biệt giữa giá trị của $X$ so với trung bình của nó. Và phương sai là trung bình của sai biệt này, nên phương sai cho ta hình ảnh về **sự phân tán** của các số liệu: phương sai càng nhỏ thì số liệu càng tập trung xung quanh trung bình của chúng.
- Trong kỹ thuật, phương sai đặc trưng cho độ sai số của thiết bị. Trong kinh doanh, phương sai đặc trưng cho độ rủi ro đầu tư.
- Do đơn vị đo của $VarX$ bằng bình phương đơn vị đo của $X$ nên để so sánh được với các đặc trưng khác, người ta đưa vào khái niệm **độ lệch tiêu chuẩn** (*standard deviation*) là
  $$\sigma = \sqrt{VarX}.$$

### VD 18

Năng suất (sản phẩm/phút) của hai máy tương ứng là các BNN $X$ và $Y$, có bảng phân phối xác suất:

| $X$ | 1 | 2 | 3 | 4 |
|-----|-----|-----|-----|-----|
| $P$ | 0,3 | 0,1 | 0,5 | 0,1 |

| $Y$ | 2 | 3 | 4 | 5 |
|-----|-----|-----|-----|-----|
| $P$ | 0,1 | 0,4 | 0,4 | 0,1 |

Từ bảng phân phối xác suất, ta tính được:
$EX = 2{,}4;\ VarX = 1{,}04;\ EY = 3{,}5;\ VarY = 0{,}65.$

Vì $EX < EY$, $VarX > VarY$ nên nếu phải chọn mua một trong hai loại máy này thì ta chọn mua máy $Y$.

**Chú ý.** Trong trường hợp $\begin{cases} EX < EY \\ VarX < VarY \end{cases}$ hay $\begin{cases} EX > EY \\ VarX > VarY \end{cases}$ thì ta không thể so sánh được. Để giải quyết vấn đề này, trong thực tế người ta dùng **tỉ số tương đối** $\dfrac{\sigma}{\mu} \cdot 100\%$ ($\mu$ là trung bình) để so sánh sự ổn định của các BNN $X$ và $Y$. Tỉ số tương đối **càng nhỏ** thì **độ ổn định càng cao**.

### VD 19

Điểm thi hết môn XSTK của lớp $A$ và $B$ tương ứng là các BNN $X$ và $Y$. Người ta tính được:
$EX = 6{,}25;\ VarX = 1{,}25;\ EY = 5{,}75;\ VarY = 0{,}75.$

Ta có:
$$\frac{\sigma_x}{EX} \cdot 100\% = 17{,}89\%; \qquad \frac{\sigma_y}{EY} \cdot 100\% = 15{,}06\%.$$

Vậy lớp $B$ học đều (ổn định) hơn lớp $A$.

---

## Trung vị (tham khảo)

**Trung vị** (*median*) của BNN $X$, ký hiệu $MedX$, là số thực $m$ thỏa:

$$P(X \le m) = P(X \ge m).$$

### VD 1

Cho BNN $X$ có bảng phân phối xác suất:

| $X$ | 0 | 1 | 2 | 3 |
|-----|-------|-------|-------|-------|
| $P$ | 0,125 | 0,375 | 0,375 | 0,125 |

Ta có: $MedX = m$ thỏa $1 < m < 2$.

### VD 2

Cho BNN $X$ có hàm mật độ:
$$f(x) = \frac{2}{9}\begin{cases} 3x - x^2, & x \in [0; 3] \\ 0, & x \notin [0; 3]. \end{cases}$$

Ta có: $P(X \le m) = P(X \ge m) \Rightarrow MedX = m \in [0; 3]$

$$\Rightarrow \frac{1}{2} = \frac{2}{9}\int_0^m (3x - x^2)\,dx \Rightarrow m = \frac{3}{2} \in [0; 3].$$

### Minh họa

- **Mode**: giá trị tại đỉnh của đường cong mật độ.
- **Mean** (kỳ vọng): điểm cân bằng của phân phối.
- **Median** (trung vị): chia diện tích dưới đường cong thành hai phần bằng nhau, mỗi phần 50%.
- **Phương sai**: phương sai nhỏ thì đường cong nhọn, tập trung quanh $\mu$; phương sai lớn thì đường cong thấp, dẹt và phân tán rộng hơn.

---

# BÀI TẬP

**1.** Một xạ thủ có 4 viên đạn, bắn lần lượt từng viên vào một mục tiêu một cách độc lập. Xác suất trúng mục tiêu ở mỗi lần bắn là 0,8. Biết rằng, nếu có 1 viên trúng mục tiêu hoặc hết đạn thì dừng. Gọi $X$ là số viên đạn xạ thủ đã bắn, hãy lập bảng phân phối xác suất của $X$?

**2.** Cho BNN $X$ có hàm mật độ
$$f(x) = \begin{cases} \dfrac{3}{28} x^2, & x \in [-1; 3] \\ 0, & x \notin [-1; 3]. \end{cases}$$
Tìm hàm phân phối $F(x)$ của $X$?

**3.** Cho $X$ là ĐLNN liên tục với hàm mật độ
$$f(x) = \begin{cases} kx, & x \in [0, 1] \\ 0, & x \notin [0, 1] \end{cases}$$

1. Xác định giá trị $k$.
2. Tìm hàm phân phối $F(x)$.
3. Tính các xác suất $P\left(X < \dfrac{1}{2}\right)$ và $P\left(\dfrac{1}{2} < X < \dfrac{3}{4}\right)$.

**4.** Một lô hàng gồm 10 sản phẩm tốt và 2 phế phẩm. Lấy ngẫu nhiên 4 sản phẩm từ lô hàng đó, gọi $X$ là số sản phẩm tốt trong 4 sản phẩm lấy ra. Tìm phân phối xác suất và tính kỳ vọng của $X$?

**5.** Cho BNN $X$ có bảng phân phối xác suất:

| $X$ | 1 | 2 | 4 | 5 | 7 |
|-----|-----|-----|-----|-----|-----|
| $P$ | $a$ | 0,2 | $b$ | 0,2 | 0,1 |

Tìm giá trị của tham số $a$ và $b$ để $EX = 3{,}5$?

**6.** Ông $A$ tham gia một trò chơi đỏ, đen như sau: Trong một hộp có 4 bi đỏ và 6 bi đen. Mỗi lần ông $A$ lấy ra 1 bi: nếu là đỏ thì được thưởng 100 (ngàn đồng), nếu là đen thì bị mất 70 (ngàn đồng). Hỏi trung bình mỗi lần lấy bi ông $A$ nhận được bao nhiêu tiền?

**7.** Người thợ chép tranh mỗi tuần chép hai bức tranh độc lập $A$ và $B$ với xác suất hỏng tương ứng là 0,03 và 0,05. Nếu thành công thì người thợ sẽ kiếm lời từ bức tranh $A$ là 1,3 triệu đồng và $B$ là 0,9 triệu đồng, nhưng nếu hỏng thì bị lỗ do bức tranh $A$ là 0,8 triệu đồng và do $B$ là 0,6 triệu đồng. Hỏi trung bình người thợ nhận được bao nhiêu tiền chép tranh mỗi tuần?

**8.** Cho một kiện hàng có 6 sản phẩm loại 1, 4 sản phẩm loại 2. Chọn ngẫu nhiên có hoàn lại 2 sản phẩm từ kiện hàng này. Gọi $X$ là số sản phẩm loại 1 trong 2 sản phẩm được lấy ra.

1. Tìm luật phân phối xác suất của $X$.
2. Tìm kỳ vọng $E(X)$.
3. Tìm phương sai $Var(X)$.

**9.** Một doanh nghiệp đầu tư phát triển một loại sản phẩm mới, xác suất thành công là 30%. Chi phí đầu tư bỏ ra là 100 nghìn USD. Nếu không thành công thì mất chi phí đầu tư mà không thu về được gì, nhưng nếu thành công thì thu về được 1 triệu USD (trước khi trừ đi chi phí đầu tư). Tính **kỳ vọng lợi nhuận** từ dự án đầu tư này.

**10.** Cho ĐLNN $X$ có hàm mật độ xác suất như sau
$$f(x) = \begin{cases} 2e^{-2x}, & x \ge 0 \\ 0, & x < 0 \end{cases}$$
Tìm các giá trị:

1. Kỳ vọng $E(X)$
2. Phương sai $Var(X)$ và độ lệch chuẩn $\sigma$
3. $Mod(X)$
