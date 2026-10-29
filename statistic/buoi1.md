# PHẦN I. LÝ THUYẾT XÁC SUẤT (Probability theory)

## Chương 1. XÁC SUẤT CỦA BIẾN CỐ

- §1. Biến cố ngẫu nhiên
- §2. Xác suất của biến cố
- §3. Công thức tính xác suất

---

# §1. BIẾN CỐ NGẪU NHIÊN

- 1.1. Hiện tượng ngẫu nhiên
- 1.2. Phép thử và Biến cố
- 1.3. Quan hệ giữa các biến cố
- 1.4. Hệ đầy đủ các biến cố

## 1.1. Hiện tượng ngẫu nhiên

Hiện tượng chia thành:

- Hiện tượng tất nhiên
- Hiện tượng ngẫu nhiên

Hiện tượng ngẫu nhiên chính là đối tượng khảo sát của lý thuyết xác suất.

## 1.2. Phép thử và Biến cố

**a) Phép thử (test):** Quan sát, thí nghiệm,… Không thể dự đoán được chắc chắn kết quả xảy ra.

**b) Biến cố (events):** Khi thực hiện một phép thử, ta có thể liệt kê tất cả các kết quả có thể xảy ra.

**VD 1.** Xét một sinh viên thi hết môn XSTK, thì hành động của sinh viên này là một phép thử.

Tập hợp tất cả các điểm số $\Omega = \{0; 0{,}5; 1; 1{,}5; \dots; 9{,}5; 10\}$ mà sinh viên này có thể đạt là **không gian mẫu**.

Các phần tử $\omega_1 = 0,\ \omega_2 = 0{,}5,\ \dots,\ \omega_{21} = 10$ là các **biến cố sơ cấp**.

Các tập con của $\Omega$: $A = \{4; 4{,}5; \dots; 10\}$, $B = \{0; 0{,}5; \dots; 3{,}5\}$, … là các **biến cố**.

Các biến cố $A, B$ có thể được phát biểu lại là:

- $A$: "sinh viên này thi đạt môn XSTK";
- $B$: "sinh viên này thi hỏng môn XSTK".

---

- Trong một phép thử, biến cố mà chắc chắn sẽ xảy ra được gọi là **biến cố chắc chắn**, ký hiệu là $\Omega$.
- Biến cố không thể xảy ra được gọi là **biến cố rỗng**, ký hiệu là $\varnothing$.

**VD 2.** Từ nhóm có 6 nam và 4 nữ, ta chọn ngẫu nhiên ra 5 người. Khi đó:

- biến cố "chọn được ít nhất 1 nam" là chắc chắn;
- biến cố "chọn được 5 người nữ" là rỗng.

## 1.3. Quan hệ giữa các biến cố

### a) Quan hệ tương đương

Nếu $A$ xảy ra thì $B$ xảy ra, ta nói $A$ kéo theo $B$, ký hiệu là $A \subset B$.

Nếu $A$ kéo theo $B$ và $B$ kéo theo $A$, ta nói $A$ và $B$ tương đương, ký hiệu là $A = B$.

**VD 3.** Quan sát 4 con gà mái đẻ trứng trong 1 ngày. Gọi

- $A_i$: "có $i$ con gà mái đẻ trứng trong 1 ngày", $i = \overline{0,4}$;
- $A$: "có 3 hoặc 4 con gà mái đẻ trứng trong 1 ngày";
- $B$: "có nhiều hơn 2 con gà mái đẻ trứng trong 1 ngày".

Khi đó, ta có: $A_3 \subset B$, $A_2 \not\subset B$, $B \subset A$ và $A \subset B$ (tức $A = B$).

### b) Tổng và tích của hai biến cố

- **Tổng** của hai biến cố $A$ và $B$ là một biến cố, biến cố này xảy ra khi $A$ xảy ra hay $B$ xảy ra trong một phép thử (ít nhất một trong hai biến cố xảy ra), ký hiệu là $A \cup B$ hay $A + B$.
- **Tích** của hai biến cố $A$ và $B$ là một biến cố, biến cố này xảy ra khi cả $A$ và $B$ cùng xảy ra trong một phép thử, ký hiệu là $A \cap B$ hay $AB$.

**VD 4.** Một người thợ săn bắn hai viên đạn vào một con thú và con thú sẽ chết nếu nó bị trúng cả hai viên đạn.

Gọi $A_i$: "viên đạn thứ $i$ trúng con thú" ($i = 1, 2$); $A$: "con thú bị trúng đạn"; $B$: "con thú bị chết".

Khi đó, ta có: $A = A_1 \cup A_2$ và $B = A_1 \cap A_2$.

**VD 5.** Xét phép thử gieo hai hạt lúa. Gọi $N_i$: "hạt lúa thứ $i$ nảy mầm"; $K_i$: "hạt lúa thứ $i$ không nảy mầm" ($i = 1, 2$); $A$: "có 1 hạt lúa nảy mầm".

Khi đó, không gian mẫu của phép thử là:

$$\Omega = \{K_1K_2;\ N_1K_2;\ K_1N_2;\ N_1N_2\}.$$

Các biến cố tích sau đây là các biến cố sơ cấp: $\omega_1 = K_1K_2,\ \omega_2 = N_1K_2,\ \omega_3 = K_1N_2,\ \omega_4 = N_1N_2$.

Biến cố $A$ không phải là sơ cấp vì $A = N_1K_2 \cup K_1N_2$.

### c) Biến cố đối lập

- **Hiệu** của hai biến cố $A$ và $B$ là một biến cố được ký hiệu $A \setminus B$, biến cố hiệu xảy ra khi và chỉ khi biến cố $A$ xảy ra nhưng biến cố $B$ không xảy ra.
- **Đối lập** của biến cố $A$ là một biến cố được ký hiệu $\overline{A}$:

$$\overline{A} = \Omega \setminus A$$

($A$ xảy ra thì $\overline{A}$ không xảy ra, và ngược lại.)

**VD 6.** Từ 1 lô hàng chứa 12 chính phẩm và 6 phế phẩm, người ta chọn ngẫu nhiên ra 15 sản phẩm. Gọi $A_i$: "chọn được $i$ chính phẩm", $i \in \{9; 10; 11; 12\}$.

Không gian mẫu là: $\Omega = A_9 \cup A_{10} \cup A_{11} \cup A_{12}$.

Biến cố đối lập của $A_{10}$ là: $\overline{A_{10}} = \Omega \setminus A_{10} = A_9 \cup A_{11} \cup A_{12}$.

## 1.4. Hệ đầy đủ các biến cố

### a) Hai biến cố xung khắc

Trong một phép thử, nếu $A$ và $B$ không cùng xảy ra thì ta nói $A$ và $B$ **xung khắc** với nhau.

**VD 7.** Hai sinh viên $A$ và $B$ cùng thi môn XSTK. Gọi

- $A$: "sinh viên $A$ thi đỗ";
- $B$: "chỉ có sinh viên $B$ thi đỗ";
- $C$: "chỉ có 1 sinh viên thi đỗ".

Khi đó, $A$ và $B$ là xung khắc; $B$ và $C$ không xung khắc.

**Chú ý.** $A$ và $B$ xung khắc nhưng không đối lập.

### b) Hệ đầy đủ các biến cố

Trong một phép thử, họ gồm $n$ biến cố $\{A_i\}$, $i = \overline{1,n}$ được gọi là **hệ đầy đủ** khi và chỉ khi có **duy nhất** biến cố $A_{i_0}$, $i_0 \in \{1; 2; \dots; n\}$ của họ xảy ra. Nghĩa là:

1. $A_i \cap A_j = \varnothing,\ \forall i \neq j$ và
2. $A_1 \cup A_2 \cup \dots \cup A_n = \Omega$.

**VD 8.** Trộn lẫn 4 bao lúa vào nhau rồi bốc ra 1 hạt. Gọi $A_i$: "hạt lúa bốc được là của bao thứ $i$", $i = \overline{1,4}$. Khi đó, hệ $\{A_1; A_2; A_3; A_4\}$ là đầy đủ.

**Chú ý.** Trong 1 phép thử, hệ $\{A; \overline{A}\}$ là đầy đủ với $A$ tùy ý.

---

# §2. XÁC SUẤT CỦA BIẾN CỐ

2.1. Khái niệm xác suất
2.2. Định nghĩa xác suất dạng cổ điển
2.3. Định nghĩa xác suất dạng thống kê
2.4. Định nghĩa xác suất theo tiên đề
2.5. Định nghĩa xác suất dạng hình học
2.6. Tính chất cơ bản của xác suất

## 2.1. Khái niệm xác suất

Quan sát các biến cố đối với một phép thử, mặc dù không thể khẳng định một biến cố có xảy ra hay không nhưng người ta có thể phỏng đoán khả năng xảy ra của các biến cố này là ít hay nhiều.

Khả năng xảy ra khách quan của một biến cố được gọi là **xác suất** (probability) của biến cố đó.

## 2.2. Định nghĩa xác suất dạng cổ điển (Trọng tâm môn học)

Xét một phép thử với không gian mẫu $\Omega = \{\omega_1; \dots; \omega_n\}$ và biến cố $A \subset \Omega$ có $k$ phần tử.

Nếu $n$ biến cố sơ cấp có **cùng khả năng xảy ra** (đồng khả năng) thì xác suất của biến cố $A$ được định nghĩa:

$$P(A) = \frac{\text{Số trường hợp } A \text{ xảy ra}}{\text{Số trường hợp có thể xảy ra}} = \frac{k}{n}$$

**VD 1.** Một công ty cần tuyển hai nhân viên. Có 4 người nữ và 2 người nam nộp đơn ngẫu nhiên (khả năng trúng tuyển của 6 người là như nhau). Tính xác suất để:

1. cả hai người trúng tuyển đều là nữ;
2. có ít nhất một người nữ trúng tuyển.

*Giải.* Gọi $A$: "cả hai người trúng tuyển đều là nữ"; $B$: "có ít nhất một người nữ trúng tuyển".

Số trường hợp có thể xảy ra là $n = C_6^2 = 15$.

1. Số trường hợp $A$ xảy ra là $k = C_4^2 = 6$. Vậy $P(A) = \dfrac{k}{n} = \dfrac{6}{15} = \dfrac{2}{5}$.
2. Trong 15 trường hợp, chỉ có 1 trường hợp cả hai người là nam. Suy ra số trường hợp $B$ xảy ra là 14. Vậy $P(B) = \dfrac{14}{15} \approx 0{,}9333$.

**VD 2.** Từ một hộp chứa 6 sản phẩm tốt và 4 phế phẩm người ta chọn ngẫu nhiên ra 5 sản phẩm. Tính xác suất để có:

1. cả 5 sản phẩm đều tốt;
2. đúng 2 phế phẩm.

*Giải.* Chọn từ hộp ra 5 sản phẩm tùy ý có $n = C_{10}^5$ cách.

1. Gọi $A$: "chọn được 5 sản phẩm tốt". Chọn từ hộp ra 5 sản phẩm tốt có $k = C_6^5$ cách. Vậy $P(A) = \dfrac{k}{n} = \dfrac{C_6^5}{C_{10}^5} = \dfrac{1}{42}$.
2. Gọi $B$: "chọn đúng 2 phế phẩm". Chọn từ hộp ra 5 sản phẩm và trong đó có đúng 2 phế phẩm (3 sản phẩm còn lại là tốt) có $C_4^2 C_6^3$ cách. Vậy $P(B) = \dfrac{C_4^2 C_6^3}{C_{10}^5} \approx 0{,}4762 = 47{,}62\%$.

**VD 3.** Tại một bệnh viện có 50 người đang chờ kết quả khám bệnh. Trong đó có 12 người chờ kết quả nội soi, 15 người chờ kết quả siêu âm, 7 người chờ kết quả cả nội soi và siêu âm. Gọi tên ngẫu nhiên một người trong 50 người này, hãy tính xác suất gọi được người đang chờ kết quả nội soi hoặc siêu âm?

*Giải.* Gọi $A$ là biến cố: "gọi được người đang chờ kết quả nội soi hoặc siêu âm".

Biểu đồ Ven: chỉ nội soi: **5**; cả hai: **7**; chỉ siêu âm: **8**.

Từ biểu đồ Ven ta có: tổng số người chờ kết quả nội soi hoặc siêu âm là 20. Vậy $P(A) = \dfrac{20}{50} = 40\%$.

**Ưu điểm và hạn chế của định nghĩa dạng cổ điển**

- Ưu điểm: Tính được chính xác giá trị của xác suất mà không cần thực hiện phép thử.
- Hạn chế: Trong thực tế có nhiều phép thử vô hạn các biến cố và biến cố không đồng khả năng.

## 2.3. Định nghĩa xác suất dạng thống kê

- Nếu khi thực hiện một phép thử nào đó $n$ lần, thấy có $k$ lần biến cố $A$ xuất hiện thì tỉ số $\dfrac{k}{n}$ được gọi là **tần suất** của biến cố $A$.
- Khi $n$ thay đổi, tần suất cũng thay đổi theo nhưng luôn dao động quanh một số cố định $p = \displaystyle\lim_{n \to \infty} \frac{k}{n}$.
- Số $p$ cố định này được gọi là **xác suất** của biến cố $A$ theo nghĩa thống kê.

Trong thực tế, khi $n$ đủ lớn thì $P(A) \approx \dfrac{k}{n}$.

**Nhận xét.** Định nghĩa xác suất theo dạng thống kê chỉ cho giá trị xấp xỉ và mức độ chính xác tùy thuộc vào số lần thực hiện phép thử.

**VD 4.**

- Pearson đã gieo một đồng tiền cân đối, đồng chất 12.000 lần thấy có 6.019 lần xuất hiện mặt sấp (tần suất là 0,5016); gieo 24.000 lần thấy có 12.012 lần xuất hiện mặt sấp (tần suất là 0,5005).
- Laplace đã nghiên cứu tỉ lệ sinh trai – gái ở London, Petecbua và Berlin trong 10 năm và đưa ra tần suất sinh bé gái là 21/43.
- Cramer đã nghiên cứu tỉ lệ sinh trai – gái ở Thụy Điển trong năm 1935 và kết quả có 42.591 bé gái được sinh ra trong tổng số 88.273 trẻ sơ sinh, tần suất là 0,4825.

## 2.4. Định nghĩa xác suất theo tiên đề

**Định nghĩa:** Xét phép thử có không gian mẫu là $\Omega$. Xác suất là một hàm số

$$P: \Omega \to [0, 1]$$

thỏa các điều kiện sau:

1. $P(\Omega) = 1$
2. Với bất kì họ đếm được các biến cố xung khắc đôi một $A_1, A_2, \dots$, ta có:
$$P(A_1 \cup A_2 \cup \dots) = P(A_1) + P(A_2) + \cdots$$

Từ định nghĩa trên, ta có: $0 \le P(A) \le 1$; $P(\varnothing) = 0$; $P(\Omega) = 1$.

## 2.5. Định nghĩa xác suất dạng hình học

Cho miền $\Omega$. Gọi **độ đo** của $\Omega$ là độ dài, diện tích, thể tích (ứng với $\Omega$ là đường cong, miền phẳng, khối). Xét điểm $M$ rơi ngẫu nhiên vào miền $\Omega$.

Gọi $A$: "điểm $M$ rơi vào miền $S \subset \Omega$", ta có:

$$P(A) = \frac{\text{độ đo } S}{\text{độ đo } \Omega}.$$

**VD 5.** Tìm xác suất của điểm $M$ rơi vào hình tròn nội tiếp tam giác đều có cạnh 2 cm.

*Giải.* Gọi $A$: "điểm $M$ rơi vào hình tròn nội tiếp".

Diện tích của tam giác là: $dt(\Omega) = \dfrac{2^2 \cdot \sqrt{3}}{4} = \sqrt{3}\ \text{cm}^2$.

Bán kính của hình tròn là: $r = \dfrac{1}{3} \cdot \dfrac{2\sqrt{3}}{2} = \dfrac{\sqrt{3}}{3}\ \text{cm}$.

$$\Rightarrow dt(S) = \pi \left(\frac{\sqrt{3}}{3}\right)^2 = \frac{\pi}{3} \Rightarrow P(A) = \frac{\pi}{3\sqrt{3}} = 0{,}6046.$$

**VD 6.** Hai người bạn hẹn gặp nhau tại 1 địa điểm xác định trong khoảng từ 7h đến 8h. Mỗi người đến (và chắc chắn đến) điểm hẹn một cách độc lập, nếu không gặp người kia thì đợi 30 phút hoặc đến 8 giờ thì không đợi nữa. Tìm xác suất để hai người gặp nhau.

*Giải.* Chọn mốc thời gian 7h là 0. Gọi $x, y$ (giờ) là thời gian tương ứng của mỗi người đi đến điểm hẹn, ta có: $0 \le x \le 1,\ 0 \le y \le 1$.

Suy ra $\Omega$ là hình vuông có cạnh là 1 đơn vị.

Từ điều kiện, ta có:

$$|x - y| \le 0{,}5 \Leftrightarrow \begin{cases} x - y \le 0{,}5 \\ x - y \ge -0{,}5 \end{cases} \Leftrightarrow \begin{cases} x - y - 0{,}5 \le 0 \\ x - y + 0{,}5 \ge 0 \end{cases}$$

Suy ra, miền gặp nhau của hai người là $S$:
$\{0 \le x \le 1,\ 0 \le y \le 1,\ x - y - 0{,}5 \le 0,\ x - y + 0{,}5 \ge 0\}$

(Hình vẽ: hình vuông $[0,1]^2$, miền $S$ nằm giữa hai đường thẳng $x - y + 0{,}5 = 0$ và $x - y - 0{,}5 = 0$.)

Vậy $p = \dfrac{dt(S)}{dt(\Omega)} = \dfrac{3}{4} = 75\%$.

## 2.6. Tính chất cơ bản của xác suất

1. Nếu $A$ là biến cố tùy ý thì $0 \le P(A) \le 1$.
2. $P(\varnothing) = 0$.
3. $P(\Omega) = 1$.
4. Nếu $A \subset B$ thì $P(A) \le P(B)$.

---

# §3. CÔNG THỨC TÍNH XÁC SUẤT

3.1. Công thức cộng xác suất
3.2. Xác suất có điều kiện

- Định nghĩa xác suất có điều kiện
- Công thức nhân xác suất
- Công thức xác suất đầy đủ và Bayes

## 3.1. Công thức cộng xác suất

Xét một phép thử, ta có các công thức cộng xác suất sau:

- Nếu $A$ và $B$ là hai biến cố tùy ý:
$$P(A \cup B) = P(A) + P(B) - P(A \cap B).$$
- Nếu $A$ và $B$ là hai biến cố xung khắc thì:
$$P(A \cup B) = P(A) + P(B).$$
- Nếu họ $\{A_i\}$ ($i = 1, \dots, n$) xung khắc từng đôi thì:
$$P(A_1 \cup A_2 \cup \dots \cup A_n) = P(A_1) + P(A_2) + \dots + P(A_n).$$

**VD 1.** Một nhóm có 30 nhà đầu tư các loại, trong đó có: 13 nhà đầu tư vàng; 17 nhà đầu tư chứng khoán và 10 nhà đầu tư cả vàng lẫn chứng khoán. Một đối tác gặp ngẫu nhiên một nhà đầu tư trong nhóm. Tìm xác suất để người đó gặp được nhà đầu tư vàng hoặc chứng khoán?

*Giải.* Gọi $A$: "đối tác gặp nhà đầu tư vàng hoặc chứng khoán"; $V$: "đối tác gặp nhà đầu tư vàng"; $C$: "đối tác gặp nhà đầu tư chứng khoán". Ta có:

$$P(A) = P(V) + P(C) - P(V \cap C) = \frac{13}{30} + \frac{17}{30} - \frac{10}{30} = \frac{2}{3}.$$

**Đặc biệt:**

$$P(\overline{A}) = 1 - P(A); \qquad P(A) = P(A \cdot B) + P(A \cdot \overline{B}).$$

**VD 2.** Một hộp phấn có 10 viên trong đó có 3 viên màu đỏ. Lấy ngẫu nhiên từ hộp ra 3 viên phấn. Tính xác suất để lấy được ít nhất 1 viên phấn màu đỏ.

*Giải.* Gọi $A$: "lấy được ít nhất 1 viên phấn màu đỏ"; $A_i$: "lấy được $i$ viên phấn màu đỏ", ($i = 0, 1, 2, 3$). Ta có $\{A_1, A_2, A_3\}$ xung khắc từng đôi.

$$P(A) = P(A_1) + P(A_2) + P(A_3) = \frac{C_3^1 C_7^2}{C_{10}^3} + \frac{C_3^2 C_7^1}{C_{10}^3} + \frac{C_3^3 C_7^0}{C_{10}^3} = \frac{17}{24}.$$

*Cách khác:*

$$P(A) = 1 - P(A_0) = 1 - \frac{C_3^0 C_7^3}{C_{10}^3} = \frac{17}{24}.$$

**Chú ý.** $\overline{A \cup B} = \overline{A} \cap \overline{B}$; $\overline{A \cap B} = \overline{A} \cup \overline{B}$.

**VD 3.** Trong một vùng dân cư, tỉ lệ người mắc bệnh tim là 9%; mắc bệnh huyết áp là 12%; mắc cả bệnh tim và huyết áp là 7%. Chọn ngẫu nhiên 1 người trong vùng đó. Tính xác suất để người này không mắc bệnh tim và không mắc bệnh huyết áp?

*Giải.* Gọi $A$: "người được chọn mắc bệnh tim"; $B$: "người được chọn mắc bệnh huyết áp"; $H$: "người được chọn không mắc cả hai bệnh trên".

Ta có: $H = \overline{A} \cap \overline{B} \Rightarrow \overline{H} = A \cup B$.

Vậy

$$P(H) = 1 - P(\overline{H}) = 1 - P(A \cup B) = 1 - \left[P(A) + P(B) - P(AB)\right] = 1 - (0{,}09 + 0{,}12 - 0{,}07) = 0{,}86.$$

Sơ đồ Ven: ngoài hai tập: **86%**; chỉ tim: **2%**; cả hai: **7%**; chỉ huyết áp: **5%**.

## 3.2. Xác suất có điều kiện

Xét phép thử: có 3 người $A$, $B$ và $C$ thi tuyển vào một công ty. Gọi $A$: "người $A$ thi đỗ"; $B$: "người $B$ thi đỗ"; $C$: "người $C$ thi đỗ"; $H$: "có 2 người thi đỗ".

Khi đó, không gian mẫu $\Omega$ là:

$$\Omega = \{ABC,\ AB\overline{C},\ A\overline{B}C,\ A\overline{B}\,\overline{C},\ \overline{A}BC,\ \overline{A}B\overline{C},\ \overline{A}\,\overline{B}C,\ \overline{A}\,\overline{B}\,\overline{C}\}.$$

Ta có:

- $A = \{ABC,\ AB\overline{C},\ A\overline{B}C,\ A\overline{B}\,\overline{C}\} \Rightarrow P(A) = \dfrac{4}{8}$;
- $H = \{AB\overline{C},\ A\overline{B}C,\ \overline{A}BC\} \Rightarrow P(H) = \dfrac{3}{8}$.

Lúc này, biến cố "2 người thi đỗ trong đó có $A$" là $AH = \{AB\overline{C},\ A\overline{B}C\}$ và $P(AH) = \dfrac{2}{8}$.

Bây giờ, ta xét phép thử là: $A$, $B$, $C$ thi tuyển vào một công ty và biết thêm thông tin có 2 người thi đỗ. Không gian mẫu trở thành $H$ và $A$ trở thành $AH$.

Gọi $A|H$: "$A$ thi đỗ biết rằng có 2 người thi đỗ" thì ta được

$$P(A|H) = \frac{2}{3} = \frac{P(AH)}{P(H)}.$$

Đọc là: biến cố $A$ với điều kiện $H$ (đã xảy ra).

### 3.2.1. Định nghĩa xác suất có điều kiện

Trong một phép thử, xét hai biến cố bất kỳ $A$ và $B$ với $P(B) > 0$. Xác suất có điều kiện của $A$ với điều kiện $B$ đã xảy ra được ký hiệu và định nghĩa là

$$P(A|B) = \frac{P(A \cap B)}{P(B)}$$

**VD 4.** Một nhóm 10 sinh viên gồm 3 nam và 7 nữ trong đó có 2 nam 18 tuổi và 3 nữ 18 tuổi. Chọn ngẫu nhiên 1 sinh viên từ nhóm đó. Gọi $A$: "sinh viên được chọn là nữ", $B$: "sinh viên được chọn là 18 tuổi". Hãy tính $P(A|B)$, $P(B|A)$?

*Giải.* Ta có: $P(A) = 0{,}7;\ P(B) = 0{,}5;\ P(A \cap B) = 0{,}3$.

Suy ra:

$$P(A|B) = \frac{P(A \cap B)}{P(B)} = \frac{0{,}3}{0{,}5} = 0{,}6; \qquad P(B|A) = \frac{P(B \cap A)}{P(A)} = \frac{0{,}3}{0{,}7} = \frac{3}{7}.$$

*Cách khác:*

$$P(A|B) = \frac{\text{Số sinh viên nữ 18 tuổi}}{\text{Số sinh viên 18 tuổi}} = \frac{3}{5}$$

$$P(B|A) = \frac{\text{Số sinh viên 18 tuổi là nữ}}{\text{Số sinh viên nữ}} = \frac{3}{7}$$

**Nhận xét.** Khi tính $P(A|B)$ với điều kiện $B$ đã xảy ra, nghĩa là ta đã hạn chế không gian mẫu $\Omega$ xuống còn $B$ và hạn chế $A$ xuống còn $A \cap B$.

**Tính chất**

1. $0 \le P(A|B) \le 1,\ \forall A \subset \Omega$;
2. nếu $A \subset C$ thì $P(A|B) \le P(C|B)$;
3. $P(\overline{A}|B) = 1 - P(A|B)$.

### 3.2.2. Công thức nhân xác suất

**a) Sự độc lập của hai biến cố**

Trong một phép thử, hai biến cố $A$ và $B$ được gọi là **độc lập** nếu $B$ có xảy ra hay không cũng không ảnh hưởng đến khả năng xảy ra $A$ và ngược lại.

**Chú ý.** Nếu $A$ và $B$ độc lập với nhau thì các cặp biến cố: $A$ và $\overline{B}$, $\overline{A}$ và $B$, $\overline{A}$ và $\overline{B}$ cũng độc lập với nhau.

**b) Công thức nhân**

- Nếu $A$ và $B$ là hai biến cố không độc lập thì:
$$P(A \cap B) = P(B)\,P(A|B) = P(A)\,P(B|A).$$
- Nếu $A$ và $B$ là hai biến cố độc lập thì:
$$P(A \cap B) = P(A) \cdot P(B).$$
- Nếu $n$ biến cố $A_i$, $i = 1, \dots, n$ không độc lập thì:
$$P(A_1A_2\dots A_n) = P(A_1)\,P(A_2|A_1)\dots P(A_n|A_1 \dots A_{n-1}).$$

**VD 5.** Một người có 5 bóng đèn trong đó có 2 bóng bị hỏng. Người đó thử ngẫu nhiên lần lượt từng bóng đèn (không hoàn lại) cho đến khi chọn được 1 bóng tốt. Tính xác suất để người đó thử đến lần thứ 2.

*Giải.* Gọi $A$: "người đó thử đến lần thứ 2"; $A_i$: "bóng đèn được thử lần thứ $i$ tốt", $i = \overline{1,5}$.

Ta có
$$P(A) = P(\overline{A_1} \cap A_2) = P(\overline{A_1})\,P(A_2|\overline{A_1}) = \frac{2}{5} \cdot \frac{3}{4} = 30\%.$$

**VD 6.** Một sinh viên học hệ niên chế được thi lại 1 lần nếu lần thi thứ nhất bị rớt (2 lần thi độc lập). Biết rằng xác suất để sinh viên này thi đỗ lần 1 và lần 2 tương ứng là 60% và 80%. Tính xác suất sinh viên này thi đỗ?

*Giải.* Gọi $A$: "sinh viên này thi đỗ"; $A_i$: "sinh viên này thi đỗ lần thứ $i$", $i = \overline{1,2}$. Ta có:

$$P(A) = P(A_1 \cup \overline{A_1}A_2) = P(A_1) + P(\overline{A_1}A_2) = P(A_1) + P(\overline{A_1})\,P(A_2) = 0{,}6 + (1 - 0{,}6) \cdot 0{,}8 = 92\%.$$

*Cách khác:*

$$P(A) = 1 - P(\overline{A_1}\,\overline{A_2}) = 1 - P(\overline{A_1})\,P(\overline{A_2}) = 1 - 0{,}4 \cdot 0{,}2 = 0{,}92.$$

**VD 7.** Có hai người $A$ và $B$ cùng đặt lệnh (độc lập) để mua cổ phiếu của một công ty với xác suất mua được tương ứng là 0,8 và 0,7. Biết rằng có người mua được, xác suất để người $A$ mua được cổ phiếu này là:

A. $\dfrac{19}{47}$; B. $\dfrac{12}{19}$; C. $\dfrac{40}{47}$; D. $\dfrac{10}{19}$.

*Giải.* Gọi $C$: "có người mua được cổ phiếu"; $A$: "người $A$ mua được cổ phiếu"; $B$: "người $B$ mua được cổ phiếu". Ta có:

$$P(A|C) = \frac{P(AC)}{P(C)} = \frac{P(A\overline{B} \cup AB)}{P(A\overline{B} \cup \overline{A}B \cup AB)} = \frac{0{,}8 \cdot 0{,}3 + 0{,}8 \cdot 0{,}7}{0{,}8 \cdot 0{,}3 + 0{,}2 \cdot 0{,}7 + 0{,}8 \cdot 0{,}7} = \frac{40}{47} \Rightarrow \textbf{C}.$$

*Cách khác:*

$$P(A|C) = \frac{P(AC)}{1 - P(\overline{A}\,\overline{B})} = \frac{P(A)}{1 - P(\overline{A})P(\overline{B})} = \frac{0{,}8}{1 - 0{,}2 \cdot 0{,}3} = \frac{40}{47}.$$

**VD 8.** Trong dịp tết, ông $A$ đem bán 1 cây mai lớn và 1 cây mai nhỏ. Xác suất bán được cây mai lớn là 0,9. Nếu bán được cây mai lớn thì xác suất bán được cây mai nhỏ là 0,7. Nếu cây mai lớn không bán được thì xác suất bán được cây mai nhỏ là 0,2. Biết rằng ông $A$ bán được ít nhất 1 cây mai, xác suất để ông $A$ bán được cả hai cây mai là:

A. 0,6342; B. 0,6848; C. 0,4796; D. 0,8791.

*Giải.* Gọi $A_1$: "ông $A$ bán được cây mai lớn"; $A_2$: "ông $A$ bán được cây mai nhỏ"; $B$: "ông $A$ bán được ít nhất 1 cây mai". Ta có:

$$P(A_1A_2|B) = \frac{P(A_1A_2B)}{P(B)} = \frac{P(A_1A_2)}{1 - P(\overline{A_1}\,\overline{A_2})} = \frac{P(A_1)\,P(A_2|A_1)}{1 - P(\overline{A_1})\,P(\overline{A_2}|\overline{A_1})} = \frac{0{,}9 \cdot 0{,}7}{1 - 0{,}1 \cdot 0{,}8} = 0{,}6848 \Rightarrow \textbf{B}.$$

**VD 9.** Hai người $A$ và $B$ cùng chơi trò chơi như sau: Cả hai luân phiên lấy mỗi lần 1 viên bi từ một hộp đựng 2 bi trắng và 4 bi đen (bi được lấy ra không trả lại hộp). Người nào lấy được bi trắng trước thì thắng cuộc. Giả sử $A$ lấy trước, tính xác suất $A$ thắng cuộc?

*Giải.* Gọi $A$: "người $A$ thắng cuộc"; $A_i$: "người $A$ lấy được bi trắng ở lần thứ $i$"; $B_i$: "người $B$ lấy được bi trắng ở lần thứ $i$".

Ta có
$$A = A_1 \cup \overline{A_1}\,\overline{B_1}A_2 \cup \overline{A_1}\,\overline{B_1}\,\overline{A_2}\,\overline{B_2}A_3$$

$$P(A) = \frac{2}{6} + \frac{4}{6} \cdot \frac{3}{5} \cdot \frac{2}{4} + \frac{4}{6} \cdot \frac{3}{5} \cdot \frac{2}{4} \cdot \frac{1}{3} \cdot 1 = \frac{3}{5}.$$

### 3.2.3. Công thức xác suất đầy đủ và Bayes

**a) Công thức xác suất đầy đủ**

Xét họ $n$ biến cố $\{A_i\}$ ($i = 1, 2, \dots, n$) đầy đủ và $B$ là một biến cố bất kỳ trong phép thử, ta có:

$$P(B) = \sum_{i=1}^{n} P(A_i)\,P(B|A_i) = P(A_1)\,P(B|A_1) + \dots + P(A_n)\,P(B|A_n).$$

*Chứng minh.*

$$\begin{aligned}
P(B) &= P(B \cap \Omega) \\
&= P\big(B \cap (A_1 \cup A_2 \cup \dots \cup A_n)\big) \\
&= P(BA_1 \cup BA_2 \cup \dots \cup BA_n) \\
&= P(A_1B) + P(A_2B) + \dots + P(A_nB) \\
&= P(A_1)\,P(B|A_1) + \dots + P(A_n)\,P(B|A_n).
\end{aligned}$$

**VD 10.** Một cửa hàng bán hai loại bóng đèn cùng kích cỡ gồm: 70 bóng màu trắng với tỉ lệ bóng hỏng là 1% và 30 bóng màu vàng với tỉ lệ hỏng 2%. Một khách hàng chọn mua ngẫu nhiên 1 bóng đèn từ cửa hàng này. Tính xác suất để người này mua được bóng đèn tốt?

*Giải.* Gọi $B$: "khách chọn được bóng đèn tốt"; $A_1$: "khách chọn được bóng đèn màu trắng"; $A_2$: "khách chọn được bóng đèn màu vàng". Suy ra hệ $\{A_1, A_2\}$ là đầy đủ.

Ta có:

$$P(B) = P(A_1)\,P(B|A_1) + P(A_2)\,P(B|A_2) = \frac{70}{70+30} \cdot 0{,}99 + \frac{30}{70+30} \cdot 0{,}98 = 0{,}987.$$

**Chú ý.** Trong trắc nghiệm ta dùng sơ đồ giải nhanh như sau:

- Nhánh 1: $P(\text{đèn tốt màu trắng}) = 0{,}7 \cdot 0{,}99$.
- Nhánh 2: $P(\text{đèn tốt màu vàng}) = 0{,}3 \cdot 0{,}98$.

Suy ra: $P(\text{đèn tốt})$ = tổng xác suất của 2 nhánh $= 0{,}987$.

**VD 11.** Chuồng thỏ I có 3 con thỏ trắng và 4 con thỏ đen; chuồng II có 5 thỏ trắng và 3 thỏ đen. Quan sát thấy có 1 con thỏ chạy từ chuồng I sang chuồng II, sau đó có 1 con thỏ chạy ra từ chuồng II. Tính xác suất để con thỏ chạy ra từ chuồng II là thỏ trắng?

*Giải.* Gọi $T$: "con thỏ chạy ra từ chuồng II là thỏ trắng"; $T_1$: "con thỏ chạy từ chuồng I là thỏ trắng"; $\overline{T_1}$: "con thỏ chạy từ chuồng I là thỏ đen". Suy ra hệ $\{T_1, \overline{T_1}\}$ là đầy đủ.

Ta có:

$$P(T) = P(T_1)\,P(T|T_1) + P(\overline{T_1})\,P(T|\overline{T_1}) = \frac{3}{7} \cdot \frac{6}{9} + \frac{4}{7} \cdot \frac{5}{9} = \frac{38}{63}.$$

Sơ đồ:

- $P(\text{thỏ 1 trắng và thỏ 2 trắng}) = \dfrac{3}{7} \cdot \dfrac{6}{9}$
- $P(\text{thỏ 1 đen và thỏ 2 trắng}) = \dfrac{4}{7} \cdot \dfrac{5}{9}$

> Nhà Toán học người Anh **Thomas Bayes** (1702 – 1761).

**b) Công thức Bayes**

Xét họ $n$ biến cố $\{A_i\}$ ($i = 1, 2, \dots, n$) đầy đủ và $B$ là một biến cố bất kỳ trong phép thử. Khi đó, xác suất để biến cố $A_k$ xảy ra sau khi $B$ đã xảy ra là:

$$P(A_k|B) = \frac{P(A_k \cdot B)}{P(B)} = \frac{P(A_k)\,P(B|A_k)}{P(B)} = \frac{P(A_k)\,P(B|A_k)}{\displaystyle\sum_{i=1}^{n} P(A_i)\,P(B|A_i)}, \qquad P(B) > 0.$$

**VD 12.** Xét tiếp VD 10. Giả sử khách hàng chọn mua được bóng đèn tốt. Tính xác suất để người này mua được bóng đèn màu vàng?

*Giải.* Đặt tên biến cố như VD 10. Ta có:

$$P(A_2|B) = \frac{P(A_2)\,P(B|A_2)}{P(B)} = \frac{0{,}3 \cdot 0{,}98}{0{,}987} = \frac{14}{47}.$$

**Nhận xét.** Nếu ta dùng sơ đồ như VD 10. Khi đó: $P(\text{đèn vàng} \mid \text{tốt})$ = (nhánh 2) **chia** (tổng 2 nhánh).

### Phân biệt các bài toán áp dụng công thức Nhân – Đầy đủ – Bayes

Trong 1 bài toán, ta xét 3 biến cố $A_1, A_2, B$.

1. Nếu bài toán yêu cầu tìm xác suất của $A_1 \cap B$, $A_2 \cap B$ thì đây là bài toán **công thức nhân**. Xác suất là *xác suất tích của từng nhánh*.
2. Nếu bài toán yêu cầu tìm xác suất của $B$ và $\{A_1, A_2\}$ đầy đủ thì đây là bài toán áp dụng **công thức đầy đủ**. Xác suất bằng *tổng 2 nhánh*.
3. Nếu bài toán yêu cầu tìm xác suất của $A_1$, $A_2$ và cho biết $B$ *đã xảy ra*, đồng thời hệ $\{A_1, A_2\}$ đầy đủ thì đây là bài toán áp dụng **công thức Bayes**. Xác suất là *tỉ số* giữa *nhánh cần tìm* với *tổng của hai nhánh*.

**VD 13.** Nhà máy X có 3 phân xưởng $A$, $B$, $C$ tương ứng sản xuất ra 20%, 30% và 50% tổng sản phẩm của nhà máy. Giả sử tỉ lệ sản phẩm hỏng do các phân xưởng $A$, $B$, $C$ tương ứng sản xuất ra là 1%, 2% và 3%. Chọn ngẫu nhiên 1 sản phẩm do nhà máy X sản xuất ra.

1. Tính xác suất (tỉ lệ) sản phẩm này là hỏng?
2. Tính xác suất sản phẩm này hỏng và do phân xưởng $A$ sản xuất ra?
3. Biết rằng sản phẩm được chọn là hỏng, tính xác suất sản phẩm này là do phân xưởng $A$ sản xuất ra?

*Giải.* Gọi $H$: "sản phẩm được chọn là hỏng"; $A$: "sản phẩm được chọn là của phân xưởng $A$"; $B$: "sản phẩm được chọn là của phân xưởng $B$"; $C$: "sản phẩm được chọn là của phân xưởng $C$". Suy ra hệ $\{A, B, C\}$ là đầy đủ.

1. $P(H) = P(A)P(H|A) + P(B)P(H|B) + P(C)P(H|C) = 0{,}2 \cdot 0{,}01 + 0{,}3 \cdot 0{,}02 + 0{,}5 \cdot 0{,}03 = 0{,}023.$

2. $P(AH) = P(A)\,P(H|A) = 0{,}2 \cdot 0{,}01 = 0{,}002.$

3. $P(A|H) = \dfrac{P(A)\,P(H|A)}{P(H)} = \dfrac{0{,}002}{0{,}023} = \dfrac{2}{23}.$

Sơ đồ:

- $P(\text{sản phẩm hỏng của phân xưởng } A) = 0{,}2 \cdot 0{,}01$
- $P(\text{sản phẩm hỏng của phân xưởng } B) = 0{,}3 \cdot 0{,}02$
- $P(\text{sản phẩm hỏng của phân xưởng } C) = 0{,}5 \cdot 0{,}03$

**VD 14.** Tỉ lệ ôtô tải, ôtô con và xe máy đi qua đường X có trạm bơm dầu là 5 : 2 : 13. Xác suất để ôtô tải, ôtô con và xe máy đi qua đường này vào bơm dầu lần lượt là 0,1; 0,2 và 0,15. Biết rằng có 1 xe đi qua đường X vào bơm dầu, tính xác suất để đó là ôtô con?

A. $\dfrac{11}{57}$; B. $\dfrac{10}{57}$; C. $\dfrac{8}{57}$; D. $\dfrac{7}{57}$.

*Giải.* Gọi $T$: "xe đi qua là ôtô tải"; $C$: "xe đi qua là ôtô con"; $M$: "xe đi qua là xe máy"; $B$: "xe đi qua vào bơm dầu". Hệ $\{T, C, M\}$ là đầy đủ.

Từ tỉ lệ $5 : 2 : 13$, ta có:

$$P(T) = \frac{5}{20}, \qquad P(C) = \frac{2}{20}, \qquad P(M) = \frac{13}{20}.$$

Theo công thức Bayes:

$$
\begin{aligned}
P(C|B)

&= \frac{P(C)\,P(B|C)}{P(T)\,P(B|T) + P(C)\,P(B|C) + P(M)\,P(B|M)} \\

&= \frac{\frac{2}{20} \cdot 0{,}2}{\frac{5}{20} \cdot 0{,}1 + \frac{2}{20} \cdot 0{,}2 + \frac{13}{20} \cdot 0{,}15} \\

&= \frac{0{,}02}{0{,}1425} \\

&= \frac{8}{57}.
\end{aligned}
$$

Vậy xác suất để xe vào bơm dầu là ôtô con bằng $\dfrac{8}{57}$, chọn **C**.

---

# Phép thử Bernoulli

- Dãy các phép thử lặp lại, độc lập, trong mỗi phép thử chỉ có 2 kết quả: $A$ và $\overline{A}$, xác suất xảy ra biến cố $A$ không đổi $P(A) = p$ được gọi là **dãy phép thử Bernoulli**.
- Xác suất biến cố $A$ xảy ra $k$ lần trong $n$ phép thử là:

$$P_n(k, p) = C_n^k \, p^k (1-p)^{n-k}$$

**Ví dụ.** Tín hiệu thông tin được phát đi 3 lần độc lập nhau. Xác suất thu được mỗi lần là 0.4.

a) Tìm xác suất để nguồn thu nhận được thông tin đúng 2 lần.
b) Tìm xác suất để nguồn thu nhận được thông tin đó.
c) Nếu muốn xác suất thu được tin ít nhất là 90% thì phải phát đi ít nhất bao nhiêu lần.

*Giải.*

a) Xác suất để nguồn thu nhận được thông tin đúng 2 lần là
$$P_3(2; 0{,}4) = C_3^2 (0{,}4)^2 (0{,}6) = 0{,}288.$$

b) Xác suất để nguồn thu nhận được thông tin là
$$P = 1 - P_3(0; 0{,}4) = 1 - (0{,}6)^3 = 0{,}784.$$

c) Xác suất để nguồn thu nhận được thông tin khi phát $n$ lần là $P = 1 - (0{,}6)^n$. Vậy nếu muốn xác suất thu được tin $\ge 0{,}9$ thì phải phát đi ít nhất $n$ lần sao cho:

$$1 - (0{,}6)^n \ge 0{,}9 \Leftrightarrow (0{,}6)^n \le 0{,}1 \Leftrightarrow n \ge \log_{0{,}6}(0{,}1) = 4{,}504 \Rightarrow n = 5.$$

---

# BÀI TẬP

**Câu 1:** Một cửa hàng có 30 máy tính, trong đó có 20 máy tính do cty A sản xuất và 10 máy tính do cty B sản xuất. Một khách hàng đến cửa hàng mua 3 máy tính. Giả sử khả năng được mua của mỗi máy là như nhau. Tính xác suất để khách hàng này mua được 2 máy của A và 1 máy của B.

**Câu 2:** Một hãng nước ngọt thăm dò thị hiếu người tiêu dùng về 2 loại nước giải khát A và B. Trong số 200 người được hỏi có 120 người thích loại A, 100 người thích loại B, 60 người thích cả 2 loại A và B. Chọn ngẫu nhiên 1 người trong số được thăm dò. Tính xác suất người này:

1. Thích ít nhất một loại nước giải khát trên
2. Không thích loại nước nào cả.

**Câu 3:** Một hộp phấn có 10 viên trắng, 6 viên đỏ. Chọn ngẫu nhiên không hoàn lại 2 viên (mỗi lần 1 viên).

1. Tính xác suất viên thứ nhất màu trắng.
2. Tính xác suất viên thứ hai màu đỏ, biết rằng viên thứ nhất màu trắng.

**Câu 4:** Lớp có 20 sv trong đó có 17 sv giỏi toán; 8 sv giỏi anh; trong đó có 5 sv giỏi cả hai môn. Với giả thiết chọn được một sinh viên giỏi toán, tính xác suất để sinh viên đó cũng giỏi anh.

**Câu 5:** Tung 2 đồng xu. Gọi

- $A$: biến cố đồng xu thứ nhất xuất hiện mặt ngửa
- $B$: biến cố đồng xu thứ hai xuất hiện mặt ngửa
- $C$: biến cố 2 đồng xu xuất hiện mặt giống nhau.

Xác định không gian mẫu và biểu diễn $A, B, C$ dưới dạng tập hợp. Từ đó tính $P(A)$, $P(B)$, $P(C)$. Chứng minh $A, B, C$ *đôi một độc lập*.

**Câu 6:** Có 2 lô hàng:

- Lô 1 có 10 sản phẩm loại A, 5 sản phẩm loại B
- Lô 2 có 12 sản phẩm loại A, 8 sản phẩm loại B.

Chọn ngẫu nhiên *mỗi lô một sản phẩm*. Tính xác suất được:

1. Hai sản phẩm loại A
2. Hai sản phẩm cùng loại
3. Hai sản phẩm khác loại

**Câu 7:** Một lô hàng gồm 20 sản phẩm trong đó có 2 phế phẩm. Người ta **lần lượt lấy** mỗi lần một sản phẩm để kiểm tra (không hoàn lại) cho đến khi phát hiện đủ 2 phế phẩm thì dừng.

a) Tính xác suất để việc kiểm tra dừng ở lần thứ hai
b) Tính xác suất để việc kiểm tra dừng ở lần thứ ba

**Câu 8:** Bắn 3 viên đạn độc lập vào một bia. Xác suất trúng bia của mỗi viên đạn lần lượt là 0,6 ; 0,9 ; 0,7. Tính xác suất:

a) Cả ba viên đều trúng bia.
b) Không viên nào trúng bia.
c) Có một viên trúng bia.
d) Có ít nhất 1 viên trúng bia.

**Câu 9:** Hộp thứ nhất chứa 3 bi đỏ và 2 bi xanh; hộp thứ hai chứa 2 bi đỏ và 8 bi xanh. Chọn ngẫu nhiên *một hộp* và từ hộp đó chọn ngẫu nhiên *một bi*.

1. Tìm xác suất chọn được bi đỏ.
2. Giả sử *đã chọn được* bi đỏ. Tính xác suất để bi đỏ này là của hộp thứ nhất.

**Câu 10:** Một bác sĩ chữa khỏi bệnh D cho một người với xác suất là 95%. Giả sử có 10 người bị bệnh D đến bác sĩ này chữa bệnh, tính xác suất:

a) Có 8 người khỏi bệnh.
b) Có nhiều nhất 9 người khỏi bệnh.

**Câu 11:** Xét việc gieo một con súc sắc. Hãy tính xem cần gieo bao nhiêu lần thì xác suất được ít nhất 1 lần xuất hiện mặt sáu chấm không nhỏ hơn 0.9.
