# Buổi 1 – Logic mệnh đề

# 1. Mệnh đề

## Khái niệm
**Mệnh đề** là một câu khẳng định một sự kiện, có giá trị **Đúng** hoặc **Sai**, nhưng không thể vừa đúng vừa sai.

## Ký hiệu
- Dùng các chữ cái $p, q, r, \dots$ để ký hiệu mệnh đề.
- Giá trị chân lý: $1$ (Đúng) hoặc $0$ (Sai).

## Ví dụ

**Là mệnh đề**
- "Hà Nội là thủ đô của Việt Nam." → Đúng.
- "$0 > e$" hoặc "$0 > 2$." → Sai.
- "3 là một số nguyên tố." → Đúng.

**Không phải mệnh đề**
- "Một ngày đẹp trời làm sao!" (câu cảm thán).
- "Thầy Hợi rất đẹp trai!" (chủ quan / cảm thán).
- "$3 + x = 2$." (chưa xác định được Đúng/Sai).

## Phân loại
1. **Mệnh đề sơ cấp**: chỉ chứa một sự kiện duy nhất, không thể chia nhỏ hơn.
   - "3 là một số nguyên tố."
2. **Mệnh đề phức hợp**: tạo ra từ các mệnh đề sơ cấp bằng các liên từ/toán tử logic (không, và, hoặc, nếu…thì, nếu và chỉ nếu).
   - "2 là số nguyên tố và là một số chẵn."
   - "Thầy Hợi đang dạy học hoặc đang xem phim."

---

# 2. Các toán tử logic

## Phủ định NOT
$\lnot p$ (hay $\bar p$): "Không phải trường hợp $p$". Giá trị ngược với $p$.

| $p$ | $\lnot p$ |
|:-:|:-:|
| 0 | 1 |
| 1 | 0 |

Ví dụ: $p$: "Paris là thủ đô của Pháp." → $\lnot p$: "Paris không phải là thủ đô của Pháp."

## Hoặc OR
$p \lor q$: "$p$ hoặc $q$". **Đúng nếu có ít nhất một mệnh đề đúng.**

## Giao AND
$p \land q$: "$p$ và $q$". **Đúng chỉ khi cả hai đều đúng.**

## Tuyển loại XOR
$p \oplus q$: đúng khi **chỉ duy nhất một** trong hai mệnh đề đúng. Khác OR ở dòng cuối ($1,1$).

Ví dụ: "Sinh viên chọn súp miễn phí hoặc salad miễn phí" → đúng nếu chỉ lấy một thứ; sai nếu lấy cả hai hoặc không lấy thứ nào.

## Kéo theo
$p \to q$: "Nếu $p$ thì $q$".

**Ghi nhớ:** $p \to q$ chỉ **sai** khi $p$ đúng mà $q$ sai. Giả thiết sai thì kéo theo luôn đúng.

Ví dụ (lời hứa): "Nếu em học chăm chỉ ($p$) thì em sẽ qua môn ($q$)."

| $p$ | $q$ | Tình huống | $p \to q$ |
|:-:|:-:|---|:-:|
| 1 | 1 | Học chăm, qua môn ⇒ thầy giữ lời | 1 |
| 1 | 0 | Học chăm, vẫn trượt ⇒ thầy thất hứa | 0 |
| 0 | 1 | Không học, vẫn qua ⇒ thầy không nói sai | 1 |
| 0 | 0 | Không học, trượt ⇒ thầy không nói sai | 1 |

## Tương đương
$p \leftrightarrow q$: "$p$ nếu và chỉ nếu $q$". Đúng khi $p$ và $q$ có cùng giá trị.

Ví dụ: "Bạn có thể đi chuyến bay nếu và chỉ nếu bạn mua vé."

## Bảng chân trị tổng hợp

| $p$ | $q$ | $p \lor q$ | $p \land q$ | $p \oplus q$ | $p \to q$ | $p \leftrightarrow q$ |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 0 | 0 | 1 | 1 |
| 0 | 1 | 1 | 0 | 1 | 1 | 0 |
| 1 | 0 | 1 | 0 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 | 0 | 1 | 1 |

### Kiểm tra nhanh
Cho $p = 1$, $q = 0$. Tính:

| # | Biểu thức | Giá trị |
|:-:|---|:-:|
| 1 | $\lnot p$ | 0 |
| 2 | $p \lor q$ | 1 |
| 3 | $p \land q$ | 0 |
| 4 | $p \oplus q$ | 1 |
| 5 | $p \to q$ | 0 |
| 6 | $q \to p$ | 1 |
| 7 | $p \leftrightarrow q$ | 0 |

Nhận xét: $p \to q$ và $q \to p$ **không** tương đương.

---

# 3. Biểu thức phức hợp

## Bảng chân trị của các mệnh đề phức hợp
Biểu thức $E(p, q, r, \dots)$ chứa bất kỳ số biến nào. Cách làm: tính lần lượt từng cột, từ biểu thức con trong cùng ra ngoài.

**Ví dụ 1:** $E(p,q) = \lnot(\lnot p \lor q)$

| $p$ | $q$ | $\lnot p$ | $\lnot p \lor q$ | $E = \lnot(\lnot p \lor q)$ |
|:-:|:-:|:-:|:-:|:-:|
| 0 | 0 | 1 | 1 | 0 |
| 0 | 1 | 1 | 1 | 0 |
| 1 | 0 | 0 | 0 | 1 |
| 1 | 1 | 0 | 1 | 0 |

## Kiểm tra tương đương logic
Hai biểu thức **tương đương logic** ($\equiv$) nếu cột kết quả của bảng chân trị giống hệt nhau.

**Ví dụ 2:** Chứng minh $p \to q \equiv \lnot p \lor q$.

| $p$ | $q$ | $p \to q$ | $\lnot p$ | $\lnot p \lor q$ |
|:-:|:-:|:-:|:-:|:-:|
| 0 | 0 | 1 | 1 | 1 |
| 0 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 | 0 |
| 1 | 1 | 1 | 0 | 1 |

Hai cột kết quả giống nhau ⇒ $p \to q \equiv \lnot p \lor q$ (luật kéo theo).

## Biểu thức có 3 biến
**Ví dụ 3:** $E(p,q,r) = (p \to q) \land (q \to r)$. Có 3 biến nên bảng có $2^3 = 8$ dòng.

| $p$ | $q$ | $r$ | $p \to q$ | $q \to r$ | $E$ |
|:-:|:-:|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 1 | 1 | **1** |
| 0 | 0 | 1 | 1 | 1 | **1** |
| 0 | 1 | 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 1 | 1 | **1** |
| 1 | 0 | 0 | 0 | 1 | 0 |
| 1 | 0 | 1 | 0 | 1 | 0 |
| 1 | 1 | 0 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 | 1 | **1** |

$E$ đúng trong 4 trường hợp (in đậm).

### Bài tập
Chứng minh tương đương logic bằng bảng chân trị:

> Câu (a) không hiển thị trong slide gốc.

- b) $p \to (q \lor r) \Leftrightarrow \lnot r \to (\lnot q \to \lnot p)$
- c) $\lnot\big((p \land q) \lor r\big) \Leftrightarrow (p \to \lnot q) \land \lnot r$
- d) $p \land \lnot(q \land r) \Leftrightarrow \lnot(p \to q) \lor (p \land \lnot r)$
- e) $(p \to q) \land \lnot q \land (q \to r) \Leftrightarrow \lnot q \land \lnot p$
- f) $(p \to q) \land (p \to r) \Leftrightarrow p \to (q \land r)$
- g) $\big((p \to r) \lor (q \to r)\big) \to (p \to r) \Leftrightarrow p \to (q \lor r)$

**Lời giải câu (b):** $p \to (q \lor r) \Leftrightarrow \lnot r \to (\lnot q \to \lnot p)$

| $p$ | $q$ | $r$ | $q \lor r$ | $p \to (q \lor r)$ | $\lnot q \to \lnot p$ | $\lnot r \to (\lnot q \to \lnot p)$ |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 0 | 1 | 1 | 1 |
| 0 | 0 | 1 | 1 | 1 | 1 | 1 |
| 0 | 1 | 0 | 1 | 1 | 1 | 1 |
| 0 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 | 1 | 0 | 1 |
| 1 | 1 | 0 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 |

Hai cột kết quả giống nhau (cùng chỉ sai khi $p=1, q=0, r=0$) ⇒ tương đương logic.

**Lời giải câu (c):** $\lnot\big((p \land q) \lor r\big) \Leftrightarrow (p \to \lnot q) \land \lnot r$

| $p$ | $q$ | $r$ | $p \land q$ | $(p \land q) \lor r$ | $\lnot\big((p \land q) \lor r\big)$ | $p \to \lnot q$ | $\lnot r$ | $(p \to \lnot q) \land \lnot r$ |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |
| 0 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |
| 0 | 1 | 1 | 0 | 1 | 0 | 1 | 0 | 0 |
| 1 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |
| 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 0 |
| 1 | 1 | 0 | 1 | 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 |

Hai cột kết quả giống nhau ⇒ tương đương logic.

## Các luật tương đương logic

| Luật | Tương đương |
|---|---|
| Đồng nhất | $p \land 1 \equiv p$; $\; p \lor 0 \equiv p$ |
| Thống trị | $p \lor 1 \equiv 1$; $\; p \land 0 \equiv 0$ |
| Lũy đẳng | $p \lor p \equiv p$; $\; p \land p \equiv p$ |
| Phủ định kép | $\lnot(\lnot p) \equiv p$ |
| Phủ định | $p \lor \lnot p \equiv 1$ (hằng đúng); $\; p \land \lnot p \equiv 0$ (hằng sai) |
| Giao hoán | $p \lor q \equiv q \lor p$; $\; p \land q \equiv q \land p$ |
| Kết hợp | $(p \lor q) \lor r \equiv p \lor (q \lor r)$; $\; (p \land q) \land r \equiv p \land (q \land r)$ |
| Phân phối | $p \lor (q \land r) \equiv (p \lor q) \land (p \lor r)$; $\; p \land (q \lor r) \equiv (p \land q) \lor (p \land r)$ |
| De Morgan | $\lnot(p \land q) \equiv \lnot p \lor \lnot q$; $\; \lnot(p \lor q) \equiv \lnot p \land \lnot q$ |
| Hấp thụ | $p \lor (p \land q) \equiv p$; $\; p \land (p \lor q) \equiv p$ |
| Kéo theo | $p \to q \equiv \lnot p \lor q$; $\; p \to q \equiv \lnot q \to \lnot p$ (phản đảo) |
| Tương đương | $p \leftrightarrow q \equiv (p \to q) \land (q \to p)$; $\; p \leftrightarrow q \equiv \lnot p \leftrightarrow \lnot q$ |

### Chứng minh tương đương logic
**Ví dụ:** Chứng minh $\lnot(p \lor (\lnot p \land q)) \equiv \lnot p \land \lnot q$.

$$
\begin{aligned}
\lnot(p \lor (\lnot p \land q)) &\equiv \lnot p \land \lnot(\lnot p \land q) && \text{De Morgan} \\
&\equiv \lnot p \land [\lnot(\lnot p) \lor \lnot q] && \text{De Morgan} \\
&\equiv \lnot p \land (p \lor \lnot q) && \text{phủ định kép} \\
&\equiv (\lnot p \land p) \lor (\lnot p \land \lnot q) && \text{phân phối} \\
&\equiv 0 \lor (\lnot p \land \lnot q) && \lnot p \land p \equiv 0 \\
&\equiv (\lnot p \land \lnot q) \lor 0 && \text{giao hoán} \\
&\equiv \lnot p \land \lnot q && \text{đồng nhất}
\end{aligned}
$$

### Chứng minh một hằng đúng
**Ví dụ:** Chứng minh $(p \land q) \to (p \lor q)$ là hằng đúng. Dùng các tương đương để đưa biểu thức về $1$.

$$
\begin{aligned}
(p \land q) \to (p \lor q) &\equiv \lnot(p \land q) \lor (p \lor q) && \text{kéo theo} \\
&\equiv (\lnot p \lor \lnot q) \lor (p \lor q) && \text{De Morgan} \\
&\equiv (\lnot p \lor p) \lor (\lnot q \lor q) && \text{kết hợp, giao hoán} \\
&\equiv 1 \lor 1 && \text{phủ định} \\
&\equiv 1 && \text{lũy đẳng}
\end{aligned}
$$

### Bài tập: Áp dụng các luật logic
Không dùng bảng chân trị, hãy dùng các luật logic để chứng minh:

1. $\lnot(p \to q) \equiv p \land \lnot q$
2. $(p \to q) \land (p \to r) \equiv p \to (q \land r)$
3. $(p \land q) \to p$ là hằng đúng.
4. $\lnot(p \lor \lnot q) \lor (\lnot p \land \lnot q) \equiv \lnot p$
5. $[(p \to q) \land p] \to q$ là hằng đúng.

> **Gợi ý:** thường bắt đầu bằng luật kéo theo để khử dấu $\to$, rồi dùng De Morgan để đưa dấu phủ định vào trong.

**Lời giải bài 2:**

$$
\begin{aligned}
(p \to q) \land (p \to r) &\equiv (\lnot p \lor q) \land (\lnot p \lor r) && \text{kéo theo} \\
&\equiv \lnot p \lor (q \land r) && \text{phân phối} \\
&\equiv p \to (q \land r) && \text{kéo theo}
\end{aligned}
$$

Ý nghĩa: "Nếu $p$ thì $q$, và nếu $p$ thì $r$" chính là "Nếu $p$ thì cả $q$ và $r$".

**Lời giải bài 5:**

$$
\begin{aligned}
[(p \to q) \land p] \to q &\equiv [(\lnot p \lor q) \land p] \to q && \text{kéo theo} \\
&\equiv [(p \land \lnot p) \lor (p \land q)] \to q && \text{giao hoán, phân phối} \\
&\equiv [0 \lor (p \land q)] \to q && \text{phủ định} \\
&\equiv (p \land q) \to q && \text{đồng nhất} \\
&\equiv \lnot(p \land q) \lor q && \text{kéo theo} \\
&\equiv (\lnot p \lor \lnot q) \lor q && \text{De Morgan} \\
&\equiv \lnot p \lor (\lnot q \lor q) && \text{kết hợp} \\
&\equiv \lnot p \lor 1 && \text{phủ định} \\
&\equiv 1 && \text{đồng nhất}
\end{aligned}
$$

Đây là hằng đúng, cơ sở của quy tắc Modus Ponens.

---

# 4. Suy luận và chứng minh

## Các quy tắc suy luận
Dạng $A_1, A_2, \dots \;\therefore\; B$: từ các tiền đề $A_1, A_2, \dots$ suy ra kết luận $B$.

| Quy tắc | Dạng | Ví dụ |
|---|---|---|
| **Modus Ponens** | $p,\; p \to q \;\therefore\; q$ | Trời mưa. Nếu mưa thì đường ướt. ⇒ Đường ướt. |
| **Modus Tollens** | $p \to q,\; \lnot q \;\therefore\; \lnot p$ | Nếu mưa thì đường ướt. Đường không ướt. ⇒ Không mưa. |
| **Tam đoạn luận giả định** | $p \to q,\; q \to r \;\therefore\; p \to r$ | Học thì hiểu bài; hiểu bài thì qua môn. ⇒ Học thì qua môn. |
| **Tam đoạn luận tuyển** | $p \lor q,\; \lnot p \;\therefore\; q$ | Đi xe buýt hoặc đi bộ. Không đi xe buýt. ⇒ Đi bộ. |
| **Quy tắc cộng** | $p \;\therefore\; p \lor q$ | 3 là số nguyên tố ⇒ 3 là số nguyên tố hoặc 3 là số chẵn. |
| **Quy tắc rút gọn** | $p \land q \;\therefore\; p$ | Trời mưa và lạnh ⇒ Trời mưa. |
| **Quy tắc hội** | $p,\; q \;\therefore\; p \land q$ | Trời mưa. Trời lạnh. ⇒ Trời mưa và lạnh. |
| **Quy tắc phân giải** | $p \lor q,\; \lnot p \lor r \;\therefore\; q \lor r$ | Mưa hoặc nắng. Không mưa hoặc lạnh. ⇒ Nắng hoặc lạnh. |

### Bài tập: Kiểm tra tính hợp lệ của các lập luận

- a) $p,\;\; q \to r,\;\; p \to \lnot r \;\;\therefore\;\; \lnot q$
- b) $p \to q,\;\; \lnot q,\;\; \lnot r \;\;\therefore\;\; \lnot(p \lor r)$
- c) $p \to (q \to r),\;\; \lnot q \to \lnot p,\;\; p \;\;\therefore\;\; r$
- d) $p \to r,\;\; \lnot p \to q,\;\; q \to s \;\;\therefore\;\; \lnot r \to s$
- e) $p \leftrightarrow q,\;\; q \to r,\;\; r \lor \lnot s,\;\; \lnot s \to \lnot q \;\;\therefore\;\; s$
- f) $p \land q,\;\; p \to (r \land q),\;\; r \to (s \lor t),\;\; \lnot s \;\;\therefore\;\; t$
- g) $p,\;\; p \to q,\;\; \lnot s \to r,\;\; r \to \lnot q \;\;\therefore\;\; s \lor t$
- h) $p \to q,\;\; r \to s,\;\; (s \land q) \to (p \land t),\;\; t \to \lnot p \;\;\therefore\;\; \lnot(p \land r)$
- i) $t \to u,\;\; r \to (s \lor t),\;\; (\lnot p \lor q) \to r,\;\; \lnot(s \lor u) \;\;\therefore\;\; p$

**Lời giải câu (a):** gợi ý: từ $p$ và $p \to \lnot r$ suy ra được gì?

| Bước | Mệnh đề | Lý do |
|:-:|---|---|
| 1 | $p$ | Tiền đề |
| 2 | $p \to \lnot r$ | Tiền đề |
| 3 | $\lnot r$ | Modus Ponens từ 1, 2 |
| 4 | $q \to r$ | Tiền đề |
| 5 | $\lnot q$ | Modus Tollens từ 3, 4 |

⇒ Lập luận hợp lệ.

**Lời giải câu (b):** gợi ý: De Morgan $\lnot(p \lor r) \equiv \lnot p \land \lnot r$. Đã có $\lnot r$, cần tìm $\lnot p$.

| Bước | Mệnh đề | Lý do |
|:-:|---|---|
| 1 | $p \to q$ | Tiền đề |
| 2 | $\lnot q$ | Tiền đề |
| 3 | $\lnot p$ | Modus Tollens từ 1, 2 |
| 4 | $\lnot r$ | Tiền đề |
| 5 | $\lnot p \land \lnot r$ | Quy tắc hội từ 3, 4 |
| 6 | $\lnot(p \lor r)$ | De Morgan từ 5 |

⇒ Lập luận hợp lệ.

**Lời giải câu (c):** gợi ý: để có $r$ từ $q \to r$ cần chứng minh được $q$.

| Bước | Mệnh đề | Lý do |
|:-:|---|---|
| 1 | $p$ | Tiền đề |
| 2 | $p \to (q \to r)$ | Tiền đề |
| 3 | $q \to r$ | Modus Ponens từ 1, 2 |
| 4 | $\lnot q \to \lnot p$ | Tiền đề |
| 5 | $p \to q$ | Phản đảo của 4 |
| 6 | $q$ | Modus Ponens từ 1, 5 |
| 7 | $r$ | Modus Ponens từ 3, 6 |

⇒ Lập luận hợp lệ.

### Bài toán thực tế 1: Ông Minh

**Đề:** Ông Minh nói rằng nếu ông không được tăng lương, ông sẽ nghỉ việc. Mặt khác, nếu ông nghỉ việc và vợ ông mất việc, ông sẽ phải bán xe. Biết rằng nếu vợ ông đi làm muộn, bà ấy sớm muộn cũng sẽ mất việc và ông Minh đã được tăng lương. Nếu ông không bán xe, thì vợ ông đã không đi làm muộn!

**Các mệnh đề sơ cấp:**
- $p$: "Ông Minh được tăng lương" (câu gốc là $\lnot p$)
- $q$: "Ông nghỉ việc"
- $r$: "Vợ ông mất việc"
- $s$: "Ông bán xe"
- $t$: "Vợ ông đi làm muộn"

**Tiền đề:**
1. $\lnot p \to q$ (không tăng lương → nghỉ việc)
2. $(q \land r) \to s$ (nghỉ việc và vợ mất việc → bán xe)
3. $t \to r$ (vợ đi muộn → mất việc)
4. $p$ (ông Minh được tăng lương)

**Yêu cầu:** Chứng minh "Nếu không bán xe ($\lnot s$), thì vợ không đi muộn ($\lnot t$)", tức $\lnot s \to \lnot t$.

### Bài toán thực tế 2: Đi bơi hay đi canô?

**Yêu cầu:** Chứng minh các tiền đề sau dẫn đến kết luận "Chúng ta sẽ về nhà trước khi mặt trời lặn."

1. "Chiều nay trời không nắng và trời lạnh hơn hôm qua."
2. "Chúng ta sẽ đi bơi chỉ khi trời nắng."
3. "Nếu chúng ta không đi bơi, chúng ta sẽ đi tham quan bằng canô."
4. "Nếu đi tham quan bằng canô, chúng ta sẽ về nhà trước khi mặt trời lặn."

Câu hỏi: Có bao nhiêu mệnh đề sơ cấp trong bài toán này? (Đáp án: 5)

**Đặt mệnh đề:**
- $p$: "Chiều nay trời nắng."
- $q$: "Trời lạnh hơn hôm qua."
- $r$: "Chúng ta sẽ đi bơi."
- $s$: "Chúng ta sẽ đi tham quan bằng canô."
- $t$: "Chúng ta sẽ về nhà trước khi mặt trời lặn."

**Hình thức hóa:**
1. $\lnot p \land q$
2. $r \to p$ ("$r$ chỉ khi $p$")
3. $\lnot r \to s$
4. $s \to t$

Kết luận: $t$.

**Lời giải:**

| Bước | Mệnh đề | Lý do |
|:-:|---|---|
| 1 | $\lnot p \land q$ | Tiền đề |
| 2 | $\lnot p$ | Quy tắc rút gọn từ (1) |
| 3 | $r \to p$ | Tiền đề |
| 4 | $\lnot r$ | Modus Tollens từ (2) và (3) |
| 5 | $\lnot r \to s$ | Tiền đề |
| 6 | $s$ | Modus Ponens từ (4) và (5) |
| 7 | $s \to t$ | Tiền đề |
| 8 | $t$ | Modus Ponens từ (6) và (7) |

$\therefore$ Kết luận "Chúng ta sẽ về nhà trước khi mặt trời lặn" là hợp lệ.