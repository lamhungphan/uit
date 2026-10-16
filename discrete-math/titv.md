## Mệnh đề

Một mệnh đề là một khẳng định có giá trị chân lý xác định, chỉ có thể là đúng hoặc sai, không thể vừa đúng vừa sai.

- Ký hiệu mệnh đề: $P, Q, R, \dots$
- Giá trị chân lý: đúng = 1 (True), sai = 0 (False)

## 1. Bit (hệ nhị phân)
Bit là đơn vị cơ bản trong hệ nhị phân, chỉ nhận hai giá trị:

- 0: sai
- 1: đúng

Ví dụ:
- "2 là số chẵn" $\Rightarrow$ mệnh đề đúng, giá trị $1$
- "1 là số chẵn" $\Rightarrow$ mệnh đề sai, giá trị $0$
- "$x + 2 > 5$" $\Rightarrow$ không phải là mệnh đề nếu chưa biết giá trị của $x$

## 2. Các phép toán trên mệnh đề

### 2.1. Phủ định
Phủ định của mệnh đề $P$ là mệnh đề phủ định của $P$, ký hiệu:

$$
\neg P
$$

- Nếu $P$ đúng thì $\neg P$ sai.
- Nếu $P$ sai thì $\neg P$ đúng.

### 2.2. Hội (phép AND)
Hội của hai mệnh đề $P$ và $Q$, ký hiệu:

$$
P \land Q
$$

Mệnh đề $P \land Q$ đúng khi cả hai mệnh đề đều đúng; ngược lại thì sai.

### 2.3. Tuyển (phép OR)
Tuyển của hai mệnh đề $P$ và $Q$, ký hiệu:

$$
P \lor Q
$$

Mệnh đề $P \lor Q$ đúng khi có ít nhất một mệnh đề đúng.

### 2.4. Mệnh đề kéo theo
Mệnh đề $P$ kéo theo $Q$, ký hiệu:

$$
P \rightarrow Q
$$

hoặc viết là $P \Rightarrow Q$.

- Chỉ sai khi $P$ đúng và $Q$ sai.
- Trong các trường hợp còn lại, mệnh đề kéo theo là đúng.

Ví dụ:

1. $11$ là số nguyên tố $\Rightarrow$ $11$ không chia hết cho $2$
   - $P = 1$, $Q = 1$
   - $P \rightarrow Q = 1$
   - Mệnh đề đúng.

2. $(6 + 5 = 11) \Rightarrow (6 \cdot 5 = 11)$
   - $P = 1$, $Q = 0$
   - $P \rightarrow Q = 0$
   - Mệnh đề sai.

3. "Trái Đất không quay" $\Rightarrow$ "Việt Nam ở châu Âu"
   - $P = 0$, $Q = 0$
   - $P \rightarrow Q = 1$
   - Mệnh đề đúng vì trường hợp $P=0$ thì kéo theo luôn đúng.

4. Nếu $a\neq 0$ và $\dfrac{a}{b}=c$, thì $a = b\cdot c$
   - Đây là một ví dụ dạng mệnh đề có điều kiện trong toán học.
   - Nếu giả thiết đúng thì kết luận đúng, ta có thể coi đây là một định lý.

5. "Khỏe mạnh" là điều kiện cần nhưng không đủ để "giỏi các môn thể thao".
   - Điều kiện cần: nếu giỏi thể thao thì phải khỏe mạnh.
   - Nhưng khỏe mạnh không đảm bảo giỏi thể thao.

6. "Thi giữa kỳ" là điều kiện cần để "qua môn".
   - Nghĩa là nếu qua môn thì chắc chắn đã thi giữa kỳ.
   - Nhưng thi giữa kỳ chưa chắc đã qua môn.
    

### 2.5. Tương đương logic
Hai mệnh đề $P$ và $Q$ tương đương logic nếu chúng có cùng giá trị chân lý, ký hiệu:

$$
P \leftrightarrow Q
$$

Mệnh đề $P \leftrightarrow Q$ đúng khi $P$ và $Q$ cùng đúng hoặc cùng sai.

Ví dụ:

1. "Một số chia hết cho 3" $\leftrightarrow$ "Tổng các chữ số của số đó chia hết cho 3"
   - Với $123$, ta có $123 \equiv 0 \pmod{3}$ và $1+2+3=6 \equiv 0 \pmod{3}$.
   - Vậy $1 \leftrightarrow 1$
   - Mệnh đề đúng.

2. $(\sqrt{9} = 3) \leftrightarrow (3^2 = 9)$
   - $\sqrt{9}=3$ là đúng.
   - $3^2=9$ cũng đúng.
   - Vậy cả hai cùng đúng, nên mệnh đề tương đương là đúng.

3. "18 là số chẵn" $\leftrightarrow$ "18 là số chính phương"
   - "18 là số chẵn" là đúng.
   - "18 là số chính phương" là sai.
   - Vậy $1 \leftrightarrow 0 = 0$
   - Mệnh đề sai.

Note: Số chính phương là số có căn bậc hai là một số nguyên.


## 3. Bảng chân trị

| $P$ | $Q$ | $P \land Q$ | $P \lor Q$ | $P \rightarrow Q$ | $P \leftrightarrow Q$ |
| --- | --- | --- | --- | --- | --- |
| 0 | 0 | 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 1 | 1 | 0 |
| 1 | 0 | 0 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 | 1 | 1 |

## 4. Mệnh đề phức hợp và tương đương logic

### 4.1. Khái niệm mệnh đề phức hợp

Mệnh đề phức hợp là mệnh đề được xây dựng từ các mệnh đề đơn giản bằng cách nối chúng với các phép toán logic như: phủ định, hội, tuyển, kéo theo, tương đương.

Ví dụ:

$$
(3 + 5 = 8) \Rightarrow (8 - 5 = 3)
$$

là một mệnh đề phức hợp.

### 4.2. Hằng đúng và hằng sai

- Một mệnh đề phức hợp luôn có giá trị đúng được gọi là **hằng đúng**.
- Một mệnh đề phức hợp luôn có giá trị sai được gọi là **hằng sai**.

### 4.3. Tương đương logic và hệ quả logic

- Hai mệnh đề $E$ và $F$ gọi là tương đương logic nếu chúng có cùng giá trị chân lý (chân trị).
- Mệnh đề $F$ gọi là hệ quả logic của mệnh đề $E$ nếu $E \Rightarrow F$ là hằng đúng.

### 4.4. Xây dựng bảng chân trị

Để xác định một mệnh đề phức hợp là hằng đúng hay không, ta lập bảng chân trị theo tất cả các khả năng của các biến mệnh đề.

#### Ví dụ 1: $X = (P \land Q) \Rightarrow (P \lor Q)$

Số lượng biến: $2^2 = 4$ dòng

| $P$ | $Q$ | $P \land Q$ | $P \lor Q$ | $X$ |
| --- | --- | --- | --- | --- |
| 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 |

Kết luận: $X$ là một hằng đúng.

#### Ví dụ 2: $(P \land Q) \leftrightarrow r$

Số lượng biến: $2^3 = 8$ dòng

| $P$ | $Q$ | $r$ | $P \land Q$ | $(P \land Q) \leftrightarrow r$ |
| --- | --- | --- | --- | --- |
| 0 | 0 | 0 | 0 | 1 |
| 0 | 0 | 1 | 0 | 0 |
| 0 | 1 | 0 | 0 | 1 |
| 0 | 1 | 1 | 0 | 0 |
| 1 | 0 | 0 | 0 | 1 |
| 1 | 0 | 1 | 0 | 0 |
| 1 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 1 |

Kết luận: Đây không phải là hằng đúng.

---

## 5. Độ ưu tiên của các phép toán mệnh đề

Thứ tự ưu tiên của các phép toán logic là:

1. Các phép toán trong ngoặc
2. Phép phủ định
3. Phép hội ($\land$)
4. Phép tuyển ($\lor$)
5. Phép kéo theo ($\Rightarrow$) và tương đương ($\Leftrightarrow$)

Ví dụ:

$$
\neg (3 + 5 = 8) \Rightarrow (6 : 2 = 3) \land (15 : 3 = 4)
$$

Ta tính như sau:

- $\neg(1) \Rightarrow (1) \land (0)$
- $0 \Rightarrow (1 \land 0)$
- $0 \Rightarrow 0$
- $1$

Vậy mệnh đề này là đúng.

---

## 6. Các quy luật logic

Với $P$, $Q$, $R$ là các mệnh đề bất kỳ, ta có các quy luật sau:

### 6.1. Luật phủ định của phủ định

$$
\overline{\overline{P}} = P
$$

### 6.2. Các luật De Morgan

$$
\overline{P \land Q} = \overline{P} \lor \overline{Q}
\mathbin ;
\overline{P \lor Q} = \overline{P} \land \overline{Q}
$$

### 6.3. Luật giao hoán

$$
P \land Q = Q \land P
\mathbin ;
P \lor Q = Q \lor P
$$

### 6.4. Luật kết hợp

$$
P \land (Q \land R) = (P \land Q) \land R
$$

### 6.5. Luật phân phối

$$
P \land (Q \lor R) = (P \land Q) \lor (P \land R)
$$

$$
P \lor (Q \land R) = (P \lor Q) \land (P \lor R)
$$

### 6.6. Luật lũy đẳng

$$
P \land P = P
\mathbin ;
P \lor P = P
$$

### 6.7. Luật về phần tử bù

$$
P \land \overline{P} = 0
\mathbin ;
P \lor \overline{P} = 1
$$

### 6.8. Luật thống trị

$$
P \land 0 = 0
\mathbin ;
P \lor 1 = 1
$$

### 6.9. Luật hấp thụ

$$
P \land (P \lor Q) = P
\mathbin ;
P \lor (P \land Q) = P
$$

### 6.10. Luật chứng minh phản chứng thứ nhất

$$
(P \implies Q) \equiv (\overline{Q} \implies \overline{P})
$$

### 6.11. Luật chứng minh phản chứng thứ hai

$$
\overline{P \implies Q} \equiv P \land \overline{Q}
$$

## 7. Vị từ và lượng từ

### 7.1. Hàm mệnh đề

Hàm mệnh đề là một khẳng định $P(x, y, \dots)$ có chứa một hay nhiều biến thuộc các tập hợp $A, B, \dots$, sao cho:

- Bản thân $P(x, y, \dots)$ chưa phải là mệnh đề.
- Khi thay các biến $x, y, \dots$ bằng các giá trị cụ thể, ta thu được một mệnh đề.

Nói cách khác, bản thân hàm mệnh đề chưa phải là mệnh đề; sau khi thay biến bằng giá trị cụ thể, ta thu được một mệnh đề.

**Ví dụ 1:** “$x$ là số nguyên tố”, với $x \in \mathbb{N}$:

- $x = 2$: mệnh đề đúng, giá trị $1$.
- $x = 3$: mệnh đề đúng, giá trị $1$.
- $x = 4$: mệnh đề sai, giá trị $0$.

**Ví dụ 2:** “$x + y = 3$”, với $x, y \in \mathbb{N}$:

- $x = 5,\ y = 2$: mệnh đề sai, giá trị $0$.
- $x = 0,\ y = 4$: mệnh đề sai, giá trị $0$.
- $x = 1,\ y = 2$: mệnh đề đúng, giá trị $1$.

### 7.2. Vị từ và lượng từ

- $\forall$ là ký hiệu **với mọi** (Universal Quantifier, chữ A viết ngược từ chữ *All*).
- $\exists$ là ký hiệu **tồn tại** (Existential Quantifier, chữ E viết ngược từ chữ *Exist*).
- Hai ký hiệu trên được gọi là các **lượng từ**.
- **Vị từ** là một hàm mệnh đề có chứa các lượng từ.

**Ví dụ:**

1. $\forall x \in \mathbb{Z},\ 2x$ là số lẻ. Giá trị chân lý là $0$, vì $2x$ luôn là số chẵn với mọi số nguyên $x$.
2. $\exists n \in \mathbb{Z},\ 0 \cdot n + 1 = 0$. Giá trị chân lý là $0$, vì $1 = 0$ không thể đúng với bất kỳ $n$ nào.
3. $\exists x \in \mathbb{N},\ \forall y \in \mathbb{N},\ x \cdot y = 0$. Giá trị chân lý là $1$, vì chọn $x = 0$ thì $0 \cdot y = 0$ luôn đúng với mọi $y$.

### 7.3. Phủ định của vị từ

Khi lấy phủ định của một mệnh đề chứa lượng từ, ta áp dụng quy tắc đổi lượng từ và phủ định vị từ bên trong:

- $\forall$ chuyển thành $\exists$.
- $\exists$ chuyển thành $\forall$.
- $P(x)$ chuyển thành $\neg P(x)$.
- $\neg P(x)$ chuyển thành $P(x)$.

**Ví dụ 1:**

Phủ định của mệnh đề

$$
\exists x,\ \forall y \in \mathbb{Z},\ x + y < 5
$$

là

$$
\forall x,\ \exists y \in \mathbb{Z},\ x + y \ge 5.
$$

**Ví dụ 2:**

Cho mệnh đề

$$
\forall x,\ \exists y \in \mathbb{N},\ x \% y = 0.
$$

Phủ định của mệnh đề trên là

$$
\exists x,\ \forall y \in \mathbb{N},\ x \% y \ne 0.
$$

## 8. Suy luận và quy tắc suy diễn

### 8.1. Khái niệm suy luận

Suy luận là quá trình rút ra mệnh đề mới từ một hoặc nhiều mệnh đề đã có. Mệnh đề đã có được gọi là **giả thiết** hoặc **tiền đề**, còn mệnh đề mới được gọi là **kết luận**.

Trong chứng minh toán học, ta có các khẳng định $P_1, P_2, P_3, \dots, P_n$ và sử dụng các quy tắc suy diễn để rút ra kết luận $Q$:

$$
(P_1 \land P_2 \land \dots \land P_n) \Rightarrow Q
$$

Trong đó:

- $P_1, P_2, \dots, P_n$ là các tiền đề (hay giả thiết).
- $\therefore$ là ký hiệu “do đó” hoặc “vì vậy” (Therefore).
- $Q$ là kết luận rút ra từ các tiền đề $P_1, P_2, \dots, P_n$.

Sơ đồ biểu diễn:

$$
\begin{array}{c}
P_1 \\
P_2 \\
\vdots \\
P_n \\
\hline
\therefore Q
\end{array}
$$

Mô hình trên đại diện cho dạng lập luận (Argument form) trong logic học.

### 8.2. Phương pháp khẳng định (quy tắc Modus Ponens)

Quy tắc này được thể hiện bởi hằng đúng:

$$
[(P \Rightarrow Q) \land P] \Rightarrow Q
$$

Dưới dạng sơ đồ:

$$
\begin{array}{c}
P \Rightarrow Q \\
P \\
\hline
\therefore Q
\end{array}
$$

- Tiền đề 1: Nếu $P$ thì $Q$ ($P \Rightarrow Q$).
- Tiền đề 2: Khẳng định $P$ đúng ($P$).
- Kết luận: Do đó, $Q$ đúng ($\therefore Q$).

**Ví dụ 1:**

$$
\begin{array}{l}
\text{Chuồn chuồn bay thấp thì mưa} \\
\text{Chuồn chuồn bay thấp} \\
\hline
\therefore \text{Trời mưa}
\end{array}
$$

**Ví dụ 2:**

$$
\begin{array}{l}
\text{Nếu P lười học thì P đạt môn Toán Rời Rạc} \\
\text{Mà P rất lười học} \\
\hline
\therefore \text{P đạt môn Toán Rời Rạc}
\end{array}
$$

### 8.3. Phương pháp phủ định (quy tắc Modus Tollens)

Quy tắc này được thể hiện bởi hằng đúng:

$$
[(P \Rightarrow Q) \land \overline{Q}] \Rightarrow \overline{P}
$$

Dưới dạng sơ đồ:

$$
\begin{array}{c}
P \Rightarrow Q \\
\overline{Q} \\
\hline
\therefore \overline{P}
\end{array}
$$

- Tiền đề 1: Nếu $P$ thì $Q$ ($P \Rightarrow Q$).
- Tiền đề 2: Phủ định $Q$ (tức là $Q$ sai, ký hiệu $\overline{Q}$ hoặc $\neg Q$).
- Kết luận: Do đó, phủ định $P$ (tức là $P$ sai, ký hiệu $\overline{P}$ hoặc $\neg P$).

**Ví dụ:**

$$
\begin{array}{l}
\text{Nếu P chăm học thì P đạt môn Toán Rời Rạc} \\
\text{P không đạt môn Toán Rời Rạc} \\
\hline
\therefore \text{P không chăm học}
\end{array}
$$

### 8.4. Tam đoạn luận (quy tắc bắc cầu / Syllogism)

Quy tắc này được thể hiện bởi hằng đúng:

$$
[(P \Rightarrow Q) \land (Q \Rightarrow R)] \Rightarrow (P \Rightarrow R)
$$

Dưới dạng sơ đồ:

$$
\begin{array}{c}
P \Rightarrow Q \\
Q \Rightarrow R \\
\hline
\therefore P \Rightarrow R
\end{array}
$$

- Tiền đề 1: Nếu $P$ thì $Q$ ($P \Rightarrow Q$).
- Tiền đề 2: Nếu $Q$ thì $R$ ($Q \Rightarrow R$).
- Kết luận: Do đó, nếu $P$ thì $R$ ($\therefore P \Rightarrow R$).

**Ví dụ 1:**

$$
\begin{array}{l}
a < b \\
b < c \\
\hline
\therefore a < c
\end{array}
$$

**Ví dụ 2:**

$$
\begin{array}{l}
a \mathbin{\vdots} b \\
b \mathbin{\vdots} c \\
\hline
\therefore a \mathbin{\vdots} c
\end{array}
$$

**Ghi chú:** Cả $a \vdots b$ và $b \mid a$ đều mang nghĩa $a$ chia hết cho $b$.

### 8.5. Quy tắc mâu thuẫn (chứng minh bằng phản chứng)

$$
[P \Rightarrow Q] \iff [(P \land \overline{Q}) \Rightarrow 0]
$$

Xét suy luận sau và xác định suy luận đúng hay sai:

$$
\begin{array}{c}
P \Rightarrow R \\
\overline{P} \Rightarrow Q \\
Q \Rightarrow S \\
\hline
\therefore \overline{R} \Rightarrow S
\end{array}
$$

Phủ định kết luận dựa trên **luật chứng minh phản chứng thứ hai**:

$$
\overline{\overline{R} \Rightarrow S}
= \overline{R} \land \overline{S}
$$

Thêm $\overline{R}$ và $\overline{S}$ vào các tiền đề:

$$
\begin{array}{c}
P \Rightarrow R \\
\overline{P} \Rightarrow Q \\
Q \Rightarrow S \\
\overline{R} \\
\overline{S} \\
\hline
\therefore 0
\end{array}
$$

Các bước suy luận:

1. Từ (2) và (3), áp dụng **tam đoạn luận**:
   $$
   \overline{P} \Rightarrow S.
   $$
2. Từ kết quả trên và (5), áp dụng **quy tắc phủ định**:
   $$
   \overline{(\overline{P})} = P.
   $$
3. Từ kết quả trên và (1), áp dụng **quy tắc khẳng định**:
   $$
   R.
   $$
4. Kết hợp kết quả trên với (4):
   $$
   R \land \overline{R} = 0.
   $$

**Kết luận:** Suy luận đúng (True).
