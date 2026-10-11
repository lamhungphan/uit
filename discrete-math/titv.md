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
