# Chương 2

# 1. Tập hợp và các phép toán

## Toán tử tập hợp: Phép giao và Phép hợp

**Phép giao (Intersection):** Giao của hai tập hợp $A$ và $B$ ($A \cap B$) chứa các phần tử thuộc cả $A$ và $B$.

$$A \cap B = \{x \mid x \in A \land x \in B\}$$

**Phép hợp (Union):** Hợp của hai tập hợp $A$ và $B$ ($A \cup B$) chứa các phần tử thuộc $A$, hoặc $B$, hoặc cả hai.

$$A \cup B = \{x \mid x \in A \lor x \in B\}$$

(Hình Venn minh họa $A \cap B$ và $A \cup B$.)

**Lưu ý:** Hai tập rời nhau nếu $A \cap B = \varnothing$.

**Nhận xét:** phép giao ứng với phép hội $\land$, phép hợp ứng với phép tuyển $\lor$.

## Hiệu tập hợp và Phần bù

- **Hiệu tập hợp** ($A - B$): chứa các phần tử thuộc $A$ nhưng không thuộc $B$.
$$A - B = \{x \mid x \in A \land x \notin B\}$$
- **Phần bù** ($\overline{A}$): nếu $U$ là tập vũ trụ, $\overline{A} = U - A$.
$$\overline{A} = \{x \in U \mid x \notin A\}$$

**Câu hỏi:** $A - B$ có bằng $B - A$ không?
→ Không. Ví dụ: $A = \{1, 2\}$, $B = \{2, 3\}$: $A - B = \{1\}$, $B - A = \{3\}$.

## Các luật của tập hợp

Các luật này tương ứng với các luật logic: thay $\cap \leftrightarrow \land$, $\cup \leftrightarrow \lor$, phần bù $\leftrightarrow \lnot$.

| Luật | Đẳng thức |
|---|---|
| Đồng nhất | $A \cap U = A$; $A \cup \varnothing = A$ |
| Phủ định kép | $\overline{\overline{A}} = A$ |
| Giao hoán | $A \cup B = B \cup A$; $A \cap B = B \cap A$ |
| De Morgan | $\overline{A \cap B} = \overline{A} \cup \overline{B}$; $\overline{A \cup B} = \overline{A} \cap \overline{B}$ |
| Phân phối | $A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$ |
| | $A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$ |

Làm sao chứng minh các luật này? → Dùng **bảng thuộc tính**.

## Bảng thuộc tính

Dùng để chứng minh các hằng đẳng thức tập hợp (1: Thuộc, 0: Không thuộc).

Ví dụ: Chứng minh luật phân phối $A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$.

| $A$ | $B$ | $C$ | $B \cup C$ | $A \cap (B \cup C)$ | $A \cap B$ | $A \cap C$ | $(A \cap B) \cup (A \cap C)$ |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 0 | 1 | 1 | 1 | 0 | 1 |
| 1 | 0 | 1 | 1 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 1 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

Hai cột kết quả giống hệt nhau ⇒ đẳng thức được chứng minh.

## Biểu diễn tập hợp bằng Chuỗi Bit

Giả sử $U = \{1, 2, 3, 4, 5, 6, 7, 8, 9, 10\}$. Bit thứ $i$ bằng 1 nếu $i$ thuộc tập hợp, bằng 0 nếu không thuộc.

- Tập $A = \{1, 2, 3, 4, 5\}$ → chuỗi bit: `11 1110 0000`
- Tập $B = \{1, 3, 5, 7, 9\}$ → chuỗi bit: `10 1010 1010`

**Phép toán bitwise:**

- Hợp ($A \cup B$): `11 1110 0000` OR `10 1010 1010` = `11 1110 1010` = $\{1, 2, 3, 4, 5, 7, 9\}$
- Giao ($A \cap B$): `11 1110 0000` AND `10 1010 1010` = `10 1010 0000` = $\{1, 3, 5\}$
- Phần bù ($\overline{A}$): đảo từng bit của `11 1110 0000` = `00 0001 1111` = $\{6, \dots, 10\}$
- Hiệu ($A - B = A \cap \overline{B}$): `11 1110 0000` AND `01 0101 0101` = `01 0100 0000` = $\{2, 4\}$

---

# 2. Các nguyên lý đếm cơ bản

## 1. Quy tắc cộng và Quy tắc nhân

**Quy tắc cộng (Rule of Sum):** Nếu một công việc có thể thực hiện theo $n_1$ cách hoặc $n_2$ cách (hai phương án rời nhau), thì có tổng cộng $n_1 + n_2$ cách thực hiện.

VD: Chọn 1 lớp trưởng từ 5 nữ hoặc 10 nam → $5 + 10 = 15$ cách.

**Quy tắc nhân (Rule of Product):** Nếu một công việc được thực hiện qua hai giai đoạn liên tiếp, giai đoạn 1 có $n_1$ cách và giai đoạn 2 có $n_2$ cách, thì có tổng cộng $n_1 \times n_2$ cách thực hiện.

VD: Mật khẩu gồm 2 chữ cái rồi đến 1 chữ số → $26 \times 26 \times 10 = 6760$ cách.

## 2. Nguyên lý Bao hàm và Loại trừ

Dùng để đếm số phần tử của hợp hai hoặc nhiều tập hợp không rời nhau.

- Với 2 tập hợp: $|A \cup B| = |A| + |B| - |A \cap B|$
- Với 3 tập hợp:

$$|A \cup B \cup C| = |A| + |B| + |C| - (|A \cap B| + |A \cap C| + |B \cap C|) + |A \cap B \cap C|$$

(Hình Venn: phần giao bị đếm 2 lần ⇒ phải trừ đi 1 lần.)

**Quy luật:** cộng các tập đơn, trừ các giao đôi, cộng các giao ba, … (dấu xen kẽ).

### Bài tập: Số lẻ hoặc số chính phương

**Đề:** Trong đoạn từ 1 đến 1000 có bao nhiêu số là số lẻ hoặc là số chính phương?

**Gợi mở:** Từ "hoặc" gợi ý ta dùng phép hợp. Hai tập này có rời nhau không?

- $A$: tập các số lẻ, $A = \{1, 3, 5, \dots, 999\}$. Suy ra $|A| = 500$.
- $B$: tập các số chính phương, $B = \{n^2 \mid n^2 \le 1000\}$. Vì $31^2 = 961 \le 1000 < 32^2$, nên $|B| = 31$.
- $A \cap B$: các số vừa lẻ vừa chính phương. $n^2$ lẻ $\Leftrightarrow$ $n$ lẻ, với $n \in \{1, 3, \dots, 31\}$: $|A \cap B| = 16$ (số).

Theo nguyên lý bao hàm - loại trừ:

$$|A \cup B| = |A| + |B| - |A \cap B| = 500 + 31 - 16 = 515$$

### Bài tập: Xâu nhị phân bắt đầu bởi 00 hoặc 11

**Đề bài:** Đếm số xâu nhị phân độ dài 8 có hai bit đầu là 00 hoặc 11.

Xâu nhị phân độ dài 8 có dạng $b_1 b_2 b_3 b_4 b_5 b_6 b_7 b_8$ với $b_i \in \{0, 1\}$.

- Trường hợp 1: Dạng $00 b_3 b_4 b_5 b_6 b_7 b_8$. Còn 6 vị trí tự do, mỗi vị trí có 2 cách. Số xâu: $2^6 = 64$.
- Trường hợp 2: Dạng $11 b_3 b_4 b_5 b_6 b_7 b_8$. Số xâu: $2^6 = 64$.

**Câu hỏi:** Hai trường hợp có rời nhau không? → Có: một xâu không thể vừa bắt đầu bằng 00 vừa bắt đầu bằng 11.

Theo quy tắc cộng: Tổng số xâu $= 64 + 64 = 128$ (xâu).

### Bài tập: Xâu không chứa 6 số 0 liền nhau

**Đề bài:** Có bao nhiêu xâu nhị phân độ dài 8 không chứa 6 số 0 liền nhau?

Tổng số xâu nhị phân độ dài 8 là $2^8 = 256$. Ta dùng phương pháp phần bù: đếm số xâu có chứa ít nhất 6 số 0 liền nhau.

Các cụm 6 số 0 có thể ở vị trí:

1. `000000xx`: có $2^2 = 4$ xâu (00000000, 00000001, 00000010, 00000011)
2. `x000000x`: có $2^2 = 4$ xâu (00000000, 00000001, 10000000, 10000001)
3. `xx000000`: có $2^2 = 4$ xâu (00000000, 10000000, 01000000, 11000000)

**Chú ý:** $4 + 4 + 4 = 12$ là sai, vì có các xâu bị đếm lặp (tô đỏ).

Liệt kê các xâu phân biệt: 00000000, 00000001, 00000010, 00000011, 10000000, 10000001, 01000000, 11000000. Tổng cộng có 8 xâu vi phạm.

$$\text{Số xâu thỏa mãn} = 256 - 8 = 248 \text{ (xâu)}$$

### Bài tập: Bắt đầu bởi 111 hoặc kết thúc bởi 0000

**Đề bài:** Có bao nhiêu xâu nhị phân độ dài 10 bắt đầu bởi 3 số 1 hoặc kết thúc bởi 4 số 0?

**Gợi mở:** Hai điều kiện có thể xảy ra cùng lúc không? → Dùng bao hàm - loại trừ.

- Gọi $A$ là tập xâu bắt đầu bởi 111: dạng $111 b_4 b_5 b_6 b_7 b_8 b_9 b_{10}$ ⟹ $|A| = 2^7 = 128$.
- Gọi $B$ là tập xâu kết thúc bởi 0000: dạng $b_1 b_2 b_3 b_4 b_5 b_6 0000$ ⟹ $|B| = 2^6 = 64$.
- $A \cap B$ là tập xâu thỏa mãn cả hai: dạng $111 b_4 b_5 b_6 0000$ ⟹ $|A \cap B| = 2^3 = 8$.

Theo nguyên lý bao hàm - loại trừ:

$$|A \cup B| = |A| + |B| - |A \cap B| = 128 + 64 - 8 = 184 \text{ (xâu)}$$

### Bài tập: Chọn 1 nam và 1 nữ

**Đề bài:** Một lớp có 5 nữ, 10 nam. Có bao nhiêu cách chọn ra 2 sinh viên gồm 1 nam và 1 nữ?

**Câu hỏi:** Dùng quy tắc cộng hay quy tắc nhân? → Nhân, vì phải chọn nam rồi chọn nữ.

Việc chọn có thể chia làm 2 công đoạn liên tiếp:

- Công đoạn 1: Chọn 1 sinh viên nam từ 10 sinh viên nam: $C_{10}^1 = 10$ cách.
- Công đoạn 2: Chọn 1 sinh viên nữ từ 5 sinh viên nữ: $C_5^1 = 5$ cách.

Theo quy tắc nhân, tổng số cách chọn là: $10 \times 5 = 50$ (cách).

---

# 3. Nguyên lý Chuồng bồ câu

## Nguyên lý Chuồng bồ câu (Dirichlet)

**Phát biểu:** Nếu xếp $n$ con chim vào $k$ cái chuồng ($n > k$), thì ít nhất một chuồng chứa từ 2 con chim trở lên.

**Nguyên lý tổng quát:** Nếu xếp $N$ đồ vật vào $k$ cái hộp, thì có ít nhất một hộp chứa ít nhất $\lceil N/k \rceil$ đồ vật.

($\lceil x \rceil$: số nguyên nhỏ nhất $\ge x$. Ví dụ: $\lceil 2.1 \rceil = 3$, $\lceil 3 \rceil = 3$.)

**Ví dụ:**

- Trong một nhóm 367 người, chắc chắn có ít nhất 2 người cùng ngày sinh nhật. (Có tối đa 366 ngày sinh khác nhau, mà $367 > 366$.)
- Trong 100 người, có ít nhất $\lceil 100/12 \rceil = 9$ người sinh cùng tháng.

**Mấu chốt khi làm bài:** xác định đâu là "chim" và đâu là "chuồng".

### Bài tập: Tên bắt đầu bằng cùng một chữ cái

**Đề bài:** Chứng tỏ rằng trong một lớp có 30 sinh viên thì ít nhất có 2 sinh viên có tên bắt đầu bằng cùng một chữ cái.

**Câu hỏi:** Đâu là "chim", đâu là "chuồng"?

- Bảng chữ cái tiếng Việt có 29 chữ cái. Ta coi mỗi chữ cái là một "cái lồng" ($k = 29$).
- Ta coi mỗi sinh viên là một "con bồ câu" ($N = 30$).

Theo nguyên lý chuồng bồ câu, có ít nhất một chữ cái là chữ đầu tên của $\left\lceil \dfrac{30}{29} \right\rceil = 2$ (sinh viên).

### Bài tập: 6 học sinh có điểm bằng nhau

**Đề bài:** Trong 45 học sinh làm bài kiểm tra: không ai dưới 2 điểm, chỉ có 2 học sinh điểm 10. CMR: Ít nhất tìm được 6 học sinh có điểm bằng nhau.

**Gợi mở:** 2 học sinh điểm 10 không giúp ích gì. Hãy tách riêng họ ra.

- Tổng số học sinh: 45.
- Số học sinh đạt điểm 10: 2 học sinh.
- Số học sinh còn lại ("chim"): $45 - 2 = 43$ học sinh.
- Các mức điểm còn lại ("chuồng"): $\{2, 3, 4, 5, 6, 7, 8, 9\}$, tức là 8 mức.

Số học sinh ít nhất cùng điểm là: $\left\lceil \dfrac{43}{8} \right\rceil = \lceil 5.375 \rceil = 6$.

### Bài tập: Bài toán ngược của nguyên lý Dirichlet

**Đề bài:** Có 5 loại học bổng. Phải có ít nhất bao nhiêu sinh viên để chắc chắn rằng có ít ra là 6 sinh viên cùng nhận một loại học bổng?

Đây là bài toán ngược của nguyên lý Dirichlet: biết số chuồng và kết quả, tìm số chim.

- 5 là số loại học bổng (số chuồng, $k = 5$).
- Gọi $N$ là tổng số sinh viên cần tìm (số chim).
- Cần: $\lceil N/5 \rceil \ge 6$.

$$\lceil N/5 \rceil \ge 6 \iff \frac{N}{5} > 5 \iff N > 25 \implies N_{\min} = 26.$$

Kiểm tra trực quan: 25 sinh viên có thể chia đều 5 người mỗi loại (chưa đủ 6). Thêm 1 người nữa thì chắc chắn có một loại có 6 người.

---

# 4. Hoán vị, Tổ hợp và Nhị thức Newton

## 4. Hoán vị và Tổ hợp

- **Hoán vị** ($P_n$): sắp xếp $n$ phần tử theo thứ tự.
$$P_n = n! = n(n-1)\dots 1$$
- **Chỉnh hợp** ($A_n^k$): chọn $k$ phần tử từ $n$ phần tử và có sắp xếp thứ tự.
$$A_n^k = \frac{n!}{(n-k)!}$$
- **Tổ hợp** ($C_n^k$): chọn $k$ phần tử từ $n$ phần tử và không quan tâm thứ tự.
$$C_n^k = \binom{n}{k} = \frac{n!}{k!(n-k)!}$$

**Câu hỏi:** Chọn 3 bạn làm lớp trưởng, lớp phó, thủ quỹ từ 10 bạn: $A_{10}^3 = 720$ (có thứ tự). Chọn 3 bạn đi trực nhật: $C_{10}^3 = 120$ (không thứ tự).

## 5. Nhị thức Newton

Khai triển biểu thức lũy thừa của một tổng:

$$(x + y)^n = \sum_{k=0}^{n} \binom{n}{k} x^{n-k} y^k$$

Ví dụ khai triển $(x + y)^3$:

- $(x + y)^3 = \binom{3}{0} x^3 y^0 + \binom{3}{1} x^2 y^1 + \binom{3}{2} x^1 y^2 + \binom{3}{3} x^0 y^3$
- $\phantom{(x + y)^3} = x^3 + 3x^2 y + 3xy^2 + y^3$

**Hệ quả:** Cho $x = y = 1$, ta được tổng các hệ số $\displaystyle\sum_{k=0}^{n} \binom{n}{k} = 2^n$.

Kiểm tra với $n = 3$: $1 + 3 + 3 + 1 = 8 = 2^3$.

### Bài tập: Xếp chỗ quanh bàn tròn (a)

**Đề bài:** 4 nữ (Huệ, Hồng, Lan, Hương) và 4 nam (An, Bình, Hạnh, Phúc) ngồi vào bàn tròn 8 chỗ.

a) Có bao nhiêu cách xếp để nam nữ ngồi xen kẽ?

**Lưu ý:** Với bàn tròn, các cách xếp chỉ khác nhau bởi phép xoay được coi là như nhau.

1. Cố định 1 bạn nữ (ví dụ Huệ) để loại bỏ các cách xoay: có 1 cách.
2. Xếp 3 nữ còn lại vào 3 vị trí nữ: $3! = 6$ cách.
3. Xếp 4 nam vào 4 vị trí xen kẽ giữa các bạn nữ: $4! = 24$ cách.

⟹ Theo quy tắc nhân, số cách: $6 \times 24 = 144$ cách.

### Bài tập: Xếp chỗ quanh bàn tròn (b)

b) Nam nữ xen kẽ nhưng Hồng và An không ngồi cạnh nhau?

**Gợi mở:** Đếm trực tiếp "không cạnh nhau" rất khó. Hãy đếm phần bù!

1. Phần bù: $N = (\text{Tổng xen kẽ}) - (\text{Hồng, An cạnh nhau})$.
2. Đếm số cách Hồng và An cạnh nhau. Cố định chỗ của Hồng:
    - An ngồi ở 1 trong 2 ghế hai bên Hồng: 2.
    - Xếp 3 nữ còn lại vào các vị trí nữ: $3! = 6$.
    - Xếp 3 nam còn lại vào các vị trí nam: $3! = 6$.

⟹ Số cách cạnh nhau: $2 \times 6 \times 6 = 72$ cách.

⟹ Kết quả: $144 - 72 = 72$ cách.

### Bài tập: Xếp chỗ trên hàng ghế dài (c)

c) Nếu 8 bạn ngồi trên một hàng ghế dài (8 ghế thẳng hàng), có bao nhiêu cách xếp nam nữ xen kẽ?

**Câu hỏi:** Khác gì bàn tròn? → Hàng ghế có đầu và cuối: xoay không còn cho cùng một cách xếp, nên không cố định ai cả.

- Kiểu 1: Nữ – Nam – Nữ – Nam – Nữ – Nam – Nữ – Nam
- Kiểu 2: Nam – Nữ – Nam – Nữ – Nam – Nữ – Nam – Nữ

1. Chọn kiểu xen kẽ (Nữ đứng đầu hoặc Nam đứng đầu): 2 cách.
2. Xếp 4 nữ vào 4 vị trí nữ: $4! = 24$ cách. Xếp 4 nam vào 4 vị trí nam: $4! = 24$ cách.

⟹ Số cách: $2 \times 24 \times 24 = 1152$ cách.

**Nhận xét:** $1152 = 8 \times 144$. Vì sao? (mỗi cách xếp bàn tròn ứng với 8 cách xoay)

### Bài tập: Xếp chỗ trên hàng ghế dài (d)

d) Hàng ghế dài, nam nữ xen kẽ, nhưng Hồng và An không ngồi cạnh nhau?

**Gợi mở:** Vẫn dùng phần bù. Nhưng khác bàn tròn: Hồng ngồi ở đầu hàng thì chỉ có 1 ghế bên cạnh!

(Hình: 8 ghế đánh số 1–8; có 7 cặp ghế cạnh nhau, mỗi cặp gồm 1 ghế nữ và 1 ghế nam.)

Đếm số cách Hồng và An ngồi cạnh nhau (với mỗi kiểu xen kẽ):

- Chọn 1 trong 7 cặp ghế cạnh nhau cho Hồng (ghế nữ) và An (ghế nam): 7 cách.
- Xếp 3 nữ và 3 nam còn lại: $3! \times 3! = 36$ cách.

⟹ Cạnh nhau: $2 \times 7 \times 36 = 504$ cách.

⟹ Kết quả: $1152 - 504 = 648$ cách.

### Bài tập: Hoán vị lặp

**Đề bài:** Có bao nhiêu chuỗi ký tự khác nhau lập được từ tất cả các ký tự trong từ MISSISSIPPI?

**Câu hỏi:** Tại sao không phải là $11!$? → Vì đổi chỗ hai chữ S cho nhau không tạo ra chuỗi mới.

Từ MISSISSIPPI có tổng cộng 11 ký tự. Ta đếm tần suất xuất hiện của mỗi chữ cái:

- M: 1 lần
- I: 4 lần
- S: 4 lần
- P: 2 lần

Đây là bài toán hoán vị lặp của 11 phần tử:

$$P = \frac{n!}{n_1!\, n_2!\, n_3!\, n_4!} = \frac{11!}{1! \times 4! \times 4! \times 2!} = \frac{39\,916\,800}{1152} = 34\,650 \text{ (chuỗi)}$$

### Bài tập: Nghiệm nguyên không âm

**Đề bài:** Phương trình $x_1 + x_2 + x_3 + x_4 = 20$ có bao nhiêu bộ nghiệm nguyên không âm?

Bài toán tìm số nghiệm nguyên không âm của phương trình $x_1 + x_2 + \dots + x_n = k$ tương ứng với bài toán "Chia $k$ cái kẹo cho $n$ đứa trẻ".

- Số biến (số đứa trẻ): $n = 4$
- Tổng (số kẹo): $k = 20$
- $x_i$ là số kẹo bạn thứ $i$ nhận được. Nghiệm không âm: có bạn được 0 kẹo cũng được.

**Câu hỏi:** Làm sao đếm số cách chia mà không phải liệt kê?

### Ý tưởng: Chia kẹo bằng vách ngăn

Xếp 20 cái kẹo và 3 vách ngăn thành một hàng $20 + 3 = 23$ vị trí. Các vách chia kẹo thành 4 phần cho 4 bạn.

- VD 1: $x_1 = 5,\ x_2 = 7,\ x_3 = 3,\ x_4 = 5$
- VD 2: $x_1 = 0,\ x_2 = 8,\ x_3 = 12,\ x_4 = 0$

Vách đứng ở đầu hàng, cuối hàng, hoặc hai vách sát nhau ⇒ có bạn nhận 0 kẹo.

Mỗi nghiệm ↔ một cách chọn 3 vị trí (trong 23 vị trí) để đặt vách.

### Bài tập: Nghiệm nguyên không âm (tt)

Từ ý tưởng vách ngăn: số nghiệm = số cách chọn 3 vị trí đặt vách trong 23 vị trí.

**Tổng quát:** chia $k$ kẹo cho $n$ bạn cần $n - 1$ vách, tổng cộng $n + k - 1$ vị trí. Công thức tính số nghiệm là tổ hợp lặp:

$$C_{n+k-1}^{n-1} = C_{n+k-1}^{k}$$

Áp dụng với $n = 4$, $k = 20$:

$$C_{23}^{20} = C_{23}^{3} = \frac{23 \times 22 \times 21}{3!} = 1771 \text{ (nghiệm)}$$

### Bài tập: Nghiệm nguyên có điều kiện

**Đề bài:** Tìm số nghiệm nguyên không âm của $x + y + z + t = 20$ thỏa mãn: $x \ge 1,\ y > 2,\ z > 3,\ t > 4$.

**Gợi mở:** Đưa về bài toán "nghiệm $\ge 0$" như bài trước bằng cách đổi biến.

Đầu tiên, ta viết lại các điều kiện dưới dạng $\ge$: $x \ge 1,\ y \ge 3,\ z \ge 4,\ t \ge 5$.

- $x' = x - 1 \ge 0 \Longrightarrow x = x' + 1$
- $y' = y - 3 \ge 0 \Longrightarrow y = y' + 3$
- $z' = z - 4 \ge 0 \Longrightarrow z = z' + 4$
- $t' = t - 5 \ge 0 \Longrightarrow t = t' + 5$

Thay vào phương trình:

$$x' + y' + z' + t' = 20 - (1 + 3 + 4 + 5) = 7$$

Số nghiệm là $C_{n+k'-1}^{k'}$ với $n = 4$, $k' = 7$:

$$C_{10}^{7} = \frac{10 \times 9 \times 8}{3!} = 120 \text{ (nghiệm)}$$
