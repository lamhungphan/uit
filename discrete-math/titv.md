# Mệnh đề

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
$$

$$
\overline{P \lor Q} = \overline{P} \land \overline{Q}
$$

### 6.3. Luật giao hoán

$$
P \land Q = Q \land P
$$

$$
P \lor Q = Q \lor P
$$

### 6.4. Luật kết hợp

$$
P \land (Q \land R) = (P \land Q) \land R
$$

$$
P \lor (Q \lor R) = (P \lor Q) \lor R
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
$$

$$
P \lor P = P
$$

### 6.7. Luật về phần tử bù

$$
P \land \overline{P} = 0
$$

$$
P \lor \overline{P} = 1
$$

### 6.8. Luật thống trị

$$
P \land 0 = 0
$$

$$
P \lor 1 = 1
$$

### 6.9. Luật hấp thụ

$$
P \land (P \lor Q) = P
$$

$$
P \lor (P \land Q) = P
$$

### 6.10. Luật chứng minh phản chứng

$$
(P \implies Q) \equiv (\overline{Q} \implies \overline{P})
$$

$$
\overline{P \implies Q} \equiv P \land \overline{Q}
$$
