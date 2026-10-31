# Buổi 2 – Vị từ, lượng từ và suy luận

# 4. Suy luận và chứng minh (tiếp)

## Quy tắc phản ví dụ & phản chứng
Cách thứ hai để kiểm tra lập luận $p_1, p_2, \dots, p_n \;\therefore\; q$ có hợp lệ không, **không cần chứng minh trực tiếp bằng các quy tắc suy luận**.

**Cách làm (truy ngược):**
1. Lập bảng: mỗi tiền đề cần bằng $1$, kết luận cần bằng $1$ (dấu "?").
2. Cột **Gán**: gán kết luận $= 0$, mọi tiền đề $= 1$.
3. Truy ngược từ dòng kết luận đi lên: mỗi bước (B1, B2, …) suy ra giá trị bắt buộc của một biến, ghi vào dòng của mệnh đề đã dùng.
4. Tiếp tục cho đến khi kiểm tra hết các tiền đề.

| Kết quả | Ý nghĩa |
|---|---|
| **Không gặp mâu thuẫn** | Bộ giá trị tìm được là **phản ví dụ** ⇒ lập luận **không hợp lệ**. |
| **Gặp mâu thuẫn** | Kết luận không thể bằng $0$ (**phản chứng**) ⇒ lập luận **hợp lệ**. |

### Bài (d)
Kiểm tra: $p \to r,\;\; \lnot p \to q,\;\; q \to s \;\;\therefore\;\; \lnot r \to s$

| Mệnh đề | Cần | Gán | B1 | B2 | B3 | B4 |
|---|:-:|:-:|:-:|:-:|:-:|:-:|
| $p \to r$ | 1 | 1 | | | | $1 \to 0 = 0$ |
| $\lnot p \to q$ | 1 | 1 | | | $\lnot p: 0 \Rightarrow p: 1$ | |
| $q \to s$ | 1 | 1 | | $q: 0$ | | |
| $\therefore \lnot r \to s$ | 1? | 0 | $s: 0,\; r: 0$ | | | |

- B1: $\lnot r \to s = 0$ khi và chỉ khi $\lnot r = 1$ và $s = 0$, tức $r = 0$, $s = 0$.
- B2: $q \to s = 1$ mà $s = 0$ ⇒ $q = 0$.
- B3: $\lnot p \to q = 1$ mà $q = 0$ ⇒ $\lnot p = 0$ ⇒ $p = 1$.
- B4: $p \to r = 1 \to 0 = 0$, mâu thuẫn với yêu cầu $p \to r = 1$.

**Mâu thuẫn ⇒ lập luận hợp lệ.**

### Bài (e)
Kiểm tra: $p \leftrightarrow q,\;\; q \to r,\;\; r \lor \lnot s,\;\; \lnot s \to \lnot q \;\;\therefore\;\; s$

| Mệnh đề | Cần | Gán | B1 | B2 | B3 | B4 | B5 |
|---|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| $p \leftrightarrow q$ | 1 | 1 | | | $p: 0$ | | |
| $q \to r$ | 1 | 1 | | | | $r$ tùy ý | |
| $r \lor \lnot s$ | 1 | 1 | | | | | $r$ tùy ý |
| $\lnot s \to \lnot q$ | 1 | 1 | | $\lnot q: 1 \Rightarrow q: 0$ | | | |
| $\therefore s$ | 1? | 0 | $s: 0$ | | | | |

- B1: gán $s = 0$.
- B2: $\lnot s = 1$ và $\lnot s \to \lnot q = 1$ ⇒ $\lnot q = 1$ ⇒ $q = 0$.
- B3: $p \leftrightarrow q = 1$ mà $q = 0$ ⇒ $p = 0$.
- B4, B5: $q \to r$ đúng vì $q = 0$; $r \lor \lnot s$ đúng vì $\lnot s = 1$ ⇒ $r$ tùy ý.

**Không mâu thuẫn** ⇒ phản ví dụ: $p = 0,\; q = 0,\; r = 0,\; s = 0$ ⇒ lập luận **không hợp lệ**. ($r$ có thể bằng $0$ hoặc $1$, chọn giá trị nào cũng là phản ví dụ.)

### Bài (f)
Kiểm tra: $p \land q,\;\; p \to (r \land q),\;\; r \to (s \lor t),\;\; \lnot s \;\;\therefore\;\; t$

| Mệnh đề | Cần | Gán | B1 | B2 | B3 | B4 | B5 |
|---|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| $p \land q$ | 1 | 1 | | | | | $0 \land q = 0$ |
| $p \to (r \land q)$ | 1 | 1 | | | | $r \land q: 0 \Rightarrow p: 0$ | |
| $r \to (s \lor t)$ | 1 | 1 | | | $s \lor t: 0 \Rightarrow r: 0$ | | |
| $\lnot s$ | 1 | 1 | | $s: 0$ | | | |
| $\therefore t$ | 1? | 0 | $t: 0$ | | | | |

- B1: gán $t = 0$.
- B2: $\lnot s = 1$ ⇒ $s = 0$.
- B3: $s \lor t = 0$ nên $r \to (s \lor t) = 1$ buộc $r = 0$.
- B4: $r = 0$ ⇒ $r \land q = 0$; $p \to (r \land q) = 1$ buộc $p = 0$.
- B5: $p \land q = 0 \land q = 0$, mâu thuẫn với yêu cầu $p \land q = 1$.

**Mâu thuẫn ⇒ lập luận hợp lệ.**

### Bài tập: Quy tắc phản ví dụ
Dùng quy tắc phản ví dụ / phản chứng để kiểm tra các lập luận:

- g) $p,\;\; p \to q,\;\; \lnot s \to r,\;\; r \to \lnot q \;\;\therefore\;\; s \lor t$
- h) $p \to q,\;\; r \to s,\;\; (s \land q) \to (p \land t),\;\; t \to \lnot p \;\;\therefore\;\; \lnot(p \land r)$
- i) $t \to u,\;\; r \to (s \lor t),\;\; (\lnot p \lor q) \to r,\;\; \lnot(s \lor u) \;\;\therefore\;\; p$

Thêm:

1. $p \to q,\;\; r \to q \;\;\therefore\;\; p \to r$
2. $p \to q,\;\; q \lor r \;\;\therefore\;\; p \lor r$
3. $p \to q,\;\; \lnot p \;\;\therefore\;\; \lnot q$
4. $(p \land q) \to r,\;\; \lnot r,\;\; p \;\;\therefore\;\; \lnot q$

---

# 5. Vị từ và lượng từ

## Vì sao cần vị từ?
- Câu "$x > 3$" **không** phải mệnh đề: chưa biết $x$ là bao nhiêu nên chưa xác định được đúng hay sai.
- Xét lập luận:
  - "Mọi sinh viên UIT đều học Cấu trúc rời rạc."
  - "An là sinh viên UIT."
  - $\therefore$ "An học Cấu trúc rời rạc."

Lập luận này rõ ràng hợp lệ, nhưng **logic mệnh đề không diễn tả được**: ba câu là ba mệnh đề $p, q, r$ khác nhau, không liên quan gì tới nhau. Cần thêm công cụ: **vị từ** và **lượng từ**.

## Vị từ (Predicates)
**Vị từ** (hay **hàm mệnh đề**) là một câu khẳng định có chứa biến. Nó chỉ trở thành mệnh đề khi các biến được gán giá trị cụ thể.

- **Ví dụ 1:** $P(n): 2n + 1 > 5$ → chưa phải mệnh đề.
  - $P(2)$: $2 \cdot 2 + 1 > 5$, tức $5 > 5$ → mệnh đề **Sai**.
  - $P(3)$: $7 > 5$ → mệnh đề **Đúng**.
- **Ví dụ 2:** $Q(x)$: "$x$ là số nguyên tố". $Q(7)$ Đúng, $Q(9)$ Sai.
- **Ví dụ 3:** $P(x, y): 2x + 3y = 1$ (vị từ 2 biến). $P(2, -1)$: $4 - 3 = 1$ Đúng; $P(0, 0)$ Sai.

**Tập chân lý** của một vị từ là tập các giá trị làm vị từ đúng. Ví dụ 1 trên $\mathbb{N}$: tập chân lý của $P(n)$ là $\{3, 4, 5, \dots\}$.

## Lượng từ (Quantifiers)
Cách thứ hai biến vị từ thành mệnh đề: dùng lượng từ.

- **Lượng từ phổ quát** $\forall$: $\forall x \in A,\; P(x)$
  - Đọc: "Với mọi $x$ thuộc $A$, $P(x)$".
  - Đúng nếu $P(x)$ đúng với **mọi** $x \in A$. Sai nếu có **một** $x$ làm $P(x)$ sai.
- **Lượng từ tồn tại** $\exists$: $\exists x \in A,\; P(x)$
  - Đọc: "Tồn tại ít nhất một $x$ thuộc $A$ sao cho $P(x)$".
  - Đúng nếu có **ít nhất một** $x \in A$ làm $P(x)$ đúng. Sai nếu $P(x)$ sai với mọi $x$.

Trên tập hữu hạn $A = \{a_1, \dots, a_n\}$:

$$
\forall x\, P(x) \equiv P(a_1) \land \dots \land P(a_n), \qquad
\exists x\, P(x) \equiv P(a_1) \lor \dots \lor P(a_n)
$$

### Ví dụ
**Xác định giá trị chân lý (trên $\mathbb{R}$):**

| Mệnh đề | Giá trị | Giải thích |
|---|:-:|---|
| $\forall x,\; x^2 \ge 0$ | Đúng | |
| $\forall x,\; x^2 > 0$ | Sai | phản ví dụ $x = 0$ |
| $\exists x,\; x^2 = 2$ | Đúng | $x = \sqrt{2}$ |
| $\exists x,\; x^2 < 0$ | Sai | mọi $x$ đều có $x^2 \ge 0$ |

Cùng vị từ, **đổi tập xét có thể đổi kết quả**: $\exists x \in \mathbb{Q},\; x^2 = 2$ là **Sai**.

**Dịch câu sang ký hiệu:**
- "Mọi sinh viên đều có máy tính." → $\forall x\, \big(S(x) \to M(x)\big)$
- "Có sinh viên đạt điểm 10." → $\exists x\, \big(S(x) \land D(x)\big)$

> **Ghi nhớ:** $\forall$ thường đi với $\to$. $\;\exists$ thường đi với $\land$.

## Lượng từ lồng nhau (Nested Quantifiers)

| Mệnh đề | Đúng khi | Cách chứng minh |
|---|---|---|
| $\forall x\, \forall y\, P(x, y)$ | mọi cặp $(x, y)$ đều thỏa | lấy $x, y$ tùy ý |
| $\forall x\, \exists y\, P(x, y)$ | với mỗi $x$ có một $y$ (phụ thuộc $x$) | lấy $x$ tùy ý, tìm $y$ theo $x$ |
| $\exists x\, \forall y\, P(x, y)$ | có một $x$ dùng được cho mọi $y$ | tìm $x$, rồi lấy $y$ tùy ý |
| $\exists x\, \exists y\, P(x, y)$ | có ít nhất một cặp thỏa | tìm một cặp cụ thể |

**Thứ tự lượng từ rất quan trọng!** Xét $P(x, y): x + y = 0$ trên $\mathbb{R}$:
- $\forall x\, \exists y\, (x + y = 0)$: **Đúng** (với mỗi $x$, chọn $y = -x$).
- $\exists y\, \forall x\, (x + y = 0)$: **Sai** (không có số $y$ nào làm $x + y = 0$ với mọi $x$).

### Ví dụ: Xác định giá trị chân lý trên $\mathbb{R}$

| | Mệnh đề | Giá trị | Giải thích |
|:-:|---|:-:|---|
| E | $\forall x \ne 0,\; \exists y,\; xy = 1$ | Đúng | chọn $y = 1/x$ (nghịch đảo) |
| G | $\forall x,\; \exists y,\; x + y = 1$ | Đúng | chọn $y = 1 - x$ |
| H | $\exists x,\; \exists y,\; (x + y = 2 \land 2x - y = 1)$ | Đúng | cặp $(x, y) = (1, 1)$ thỏa cả hai phương trình |
| I | $\forall x,\; \exists y,\; (x + y = 2 \land 2x - y = 1)$ | Sai | với $x = 0$ cần $y = 2$ và $y = -1$ cùng lúc, vô lý |
| K | $\exists x,\; \forall y,\; xy = y$ | Đúng | chọn $x = 1$, khi đó $1 \cdot y = y$ với mọi $y$ |

**So sánh H và I:** cùng vị từ, đổi $\exists x$ thành $\forall x$ thì kết quả đổi từ Đúng sang Sai.

---

# 6. Phủ định lượng từ

## Quy tắc De Morgan cho lượng từ

$$
\lnot\big(\forall x\, P(x)\big) \equiv \exists x\, \lnot P(x)
\qquad\qquad
\lnot\big(\exists x\, P(x)\big) \equiv \forall x\, \lnot P(x)
$$

- Đổi $\forall \leftrightarrow \exists$, rồi phủ định vị từ.
- Với nhiều lượng từ: đổi từng lượng từ, đưa $\lnot$ vào trong cùng.

Ví dụ: "Không phải mọi sinh viên đều đi học" $\equiv$ "Có sinh viên không đi học".

## Ví dụ A
$A: \forall x \in \mathbb{R},\; x^2 + 6x + 5 \le 0$.

Phủ định: $\lnot A: \exists x \in \mathbb{R},\; x^2 + 6x + 5 > 0$.

**Câu hỏi:** $A$ hay $\lnot A$ đúng?

**Lời giải:** Chọn $x = 0$: $0 + 0 + 5 = 5 > 0$ ⇒ $\lnot A$ **Đúng**, do đó $A$ **Sai**.

*Minh họa:* $y = x^2 + 6x + 5 \le 0$ chỉ khi $-5 \le x \le -1$.

> **Nhận xét:** chứng minh $A$ sai = tìm một phản ví dụ, chính là chứng minh $\lnot A$ đúng.

## Phủ định lượng từ lồng nhau

| | Ví dụ B: $\forall x\, \forall y,\; 2x + y < 1$ | Ví dụ C: $\forall x\, \exists y,\; 2x + y < 1$ |
|---|---|---|
| Phủ định | $\lnot B: \exists x\, \exists y,\; 2x + y \ge 1$ | $\lnot C: \exists x\, \forall y,\; 2x + y \ge 1$ |
| Chứng minh | $\lnot B$: chọn $x = 1,\, y = 1$ thì $2 \cdot 1 + 1 = 3 \ge 1$ | $C$: với $x$ tùy ý, cần tìm $y$ (theo $x$) sao cho $2x + y < 1$. Chọn $y = -2x$: $2x + (-2x) = 0 < 1$ ✓ |
| Kết luận | $\lnot B$ Đúng, $B$ **Sai** | $C$ **Đúng**, $\lnot C$ Sai |

> **Chiến lược:** xét cả mệnh đề và phủ định của nó. Mệnh đề nào bắt đầu bằng $\exists$ thường dễ chứng minh hơn: chỉ cần tìm giá trị.

## Phủ định phép kéo theo
Nhắc lại: $(p \to q) \equiv \lnot p \lor q$ ⇒ $\lnot(p \to q) \equiv p \land \lnot q$.

**Ví dụ D:** $\forall x \in \mathbb{R}\;\exists y \in \mathbb{R},\; (x^2 = y^2) \to (x = y)$

$\lnot D: \exists x \in \mathbb{R}\;\forall y \in \mathbb{R},\; (x^2 = y^2) \land (x \ne y)$.

**Chứng minh $D$:** với $x$ tùy ý, tìm $y$ sao cho phép kéo theo đúng. Chọn $y = x$: $(x^2 = x^2) \to (x = x)$ là $1 \to 1$, Đúng. Vậy $D$ **Đúng**.

**Mẹo với phép kéo theo:** (giả thiết) $\to$ (kết luận) đúng khi
- giả thiết **sai** (khi đó luôn đúng), hoặc
- giả thiết và kết luận **cùng đúng**.

Ví dụ: $\forall x\, \exists y,\; (x^2 \ge y^2) \to (x > y)$ **Đúng**: chọn $y = \lvert x \rvert + 1$ thì $x^2 < y^2$, giả thiết sai.

---

# 7. Suy luận với lượng từ

## Các quy tắc suy luận với lượng từ

| Quy tắc | Dạng | Ý nghĩa |
|---|---|---|
| **Cụ thể hóa phổ quát** | $\forall x\, P(x) \;\therefore\; P(c)$ | Đúng với mọi $x$ thì đúng với $c$ bất kỳ. |
| **Tổng quát hóa phổ quát** | $P(c)$ với $c$ tùy ý $\;\therefore\; \forall x\, P(x)$ | $c$ phải là phần tử **tùy ý**. |
| **Cụ thể hóa tồn tại** | $\exists x\, P(x) \;\therefore\; P(c)$ với $c$ nào đó | Đặt **tên mới** $c$ cho phần tử đó. |
| **Tổng quát hóa tồn tại** | $P(c) \;\therefore\; \exists x\, P(x)$ | Có một ví dụ thì "tồn tại". |

Kết hợp với Modus Ponens: $\forall x\, \big(P(x) \to Q(x)\big),\; P(a) \;\therefore\; Q(a)$.

## Ví dụ 1
**Tiền đề:** "Mọi người trong lớp đều đã học Tin học cơ sở" và "An ở trong lớp này."
**Kết luận:** "An đã học Tin học cơ sở."

Đặt $D(x)$: $x$ ở trong lớp; $C(x)$: $x$ đã học Tin học cơ sở.

| Bước | Mệnh đề | Căn cứ |
|:-:|---|---|
| 1 | $\forall x\, \big(D(x) \to C(x)\big)$ | Tiền đề |
| 2 | $D(\text{An}) \to C(\text{An})$ | Cụ thể hóa phổ quát từ (1) |
| 3 | $D(\text{An})$ | Tiền đề |
| 4 | $C(\text{An})$ | Modus Ponens từ (2) và (3) |

$\therefore$ An đã học Tin học cơ sở. (Đây chính là lập luận ở mục "Vì sao cần vị từ?".)

## Ví dụ 2
**Tiền đề:** $\exists x\, \big(C(x) \land \lnot B(x)\big)$ và $\forall x\, \big(C(x) \to P(x)\big)$.
**Kết luận:** $\exists x\, \big(P(x) \land \lnot B(x)\big)$.

($C(x)$: $x$ học lớp này; $B(x)$: $x$ đã đọc sách; $P(x)$: $x$ đậu kỳ thi.)

| Bước | Mệnh đề | Căn cứ |
|:-:|---|---|
| 1 | $\exists x\, \big(C(x) \land \lnot B(x)\big)$ | Tiền đề |
| 2 | $C(a) \land \lnot B(a)$ | Cụ thể hóa tồn tại từ (1) |
| 3 | $C(a)$ | Rút gọn từ (2) |
| 4 | $\forall x\, \big(C(x) \to P(x)\big)$ | Tiền đề |
| 5 | $C(a) \to P(a)$ | Cụ thể hóa phổ quát từ (4) |
| 6 | $P(a)$ | Modus Ponens từ (3) và (5) |
| 7 | $\lnot B(a)$ | Rút gọn từ (2) |
| 8 | $P(a) \land \lnot B(a)$ | Quy tắc hội từ (6) và (7) |
| 9 | $\exists x\, \big(P(x) \land \lnot B(x)\big)$ | Tổng quát hóa tồn tại từ (8) |

## Ví dụ 3 (tìm lỗi sai)
**Khẳng định:** Nếu $\exists x\, P(x) \land \exists x\, Q(x)$ đúng thì $\exists x\, \big(P(x) \land Q(x)\big)$ đúng.

**"Chứng minh" sai:**

| Bước | Mệnh đề | Căn cứ |
|:-:|---|---|
| 1 | $\exists x\, P(x) \land \exists x\, Q(x)$ | Tiền đề |
| 2 | $\exists x\, P(x)$ và $\exists x\, Q(x)$ | Rút gọn |
| 3 | $P(c)$ | Cụ thể hóa tồn tại |
| 4 | $Q(c)$ | Cụ thể hóa tồn tại (**sai!**) |
| 5 | $P(c) \land Q(c)$, do đó $\exists x\, \big(P(x) \land Q(x)\big)$ | |

**Lỗi sai:** mỗi lần cụ thể hóa tồn tại phải dùng **một tên mới**. Có $x$ thỏa $P$, có $x$ thỏa $Q$, nhưng không chắc là cùng một $x$.

**Phản ví dụ:** trên $\mathbb{Z}$, $P(x)$: "$x$ chẵn", $Q(x)$: "$x$ lẻ". Có số chẵn, có số lẻ, nhưng không có số nào vừa chẵn vừa lẻ.

---

# 8. Bài tập: Vị từ và lượng từ

**Bài 1:** Xác định giá trị chân lý của các mệnh đề sau trên $\mathbb{R}$. Nếu sai, đưa ra phản ví dụ:
- a) $\forall x,\; x^2 + 1 \ge 1$
- b) $\exists x,\; x^2 - 2 = 0$
- c) $\forall x,\; \dfrac{1}{x} > 0$
- d) $\exists x,\; x^2 < 0$

**Bài 2:** Xác định giá trị chân lý trên tập số nguyên $\mathbb{Z}$:
- a) $\forall n,\; n^2 \ge n$
- b) $\exists n,\; n^2 = 2$
- c) $\forall n,\; n + 1 > n$
- d) $\exists n,\; n + n = n$

**Bài 3:** Xác định giá trị chân lý trên $\mathbb{R}$:
- a) $\forall x\, \exists y,\; x + y = 10$
- b) $\exists y\, \forall x,\; x + y = 10$
- c) $\forall x\, \forall y,\; (x < y \lor y < x \lor x = y)$
- d) $\forall x \ne 0\;\exists y,\; xy = 1$
- e) $\exists x\, \forall y,\; xy = y$

**Bài 4:** Viết mệnh đề phủ định (không để $\lnot$ đứng trực tiếp trước lượng từ):
- a) $\forall x\, \big(P(x) \land Q(x)\big)$
- b) $\exists x\, \big(P(x) \to Q(x)\big)$
- c) $\forall x\, \exists y\, (x^2 < y)$
- d) $\forall x\, \exists y\, \forall z\, (xy = z)$
- e) $\exists x \in \mathbb{R}\; (x > 0 \land \sqrt{x} < 0)$

**Bài 5:** Dùng vị từ, lượng từ và các phép toán logic để biểu diễn các câu:
- a) "Mọi sinh viên trong lớp này đều có máy tính xách tay."
- b) "Có một số nguyên là số nguyên tố và là số chẵn."
- c) "Mọi số thực dương đều có một căn bậc hai thực."
- d) "Không có ai là hoàn hảo." (dùng $P(x)$: $x$ là hoàn hảo)
- e) "Mọi người đều có ít nhất một người bạn." (dùng $F(x, y)$: $x$ là bạn của $y$)

**Bài 6:** Cho $S: \forall x \in \mathbb{R}\;\exists y \in \mathbb{R},\; (x + y = 0)$.
- a) Phát biểu $S$ bằng lời.
- b) Xác định giá trị chân lý của $S$.
- c) Viết $\lnot S$ dưới dạng ký hiệu.
- d) Xác định giá trị chân lý của $\lnot S$.

**Bài 7:** Xác định giá trị chân lý, viết phủ định (trên $\mathbb{R}$):
- a) $\forall x\, \exists y,\; (xy \ge 0) \to (x - 3y \ne 2)$
- b) $\exists x\, \forall y,\; (xy < 0) \to (x - 4y = 5)$

**Bài 8:** Xác định giá trị chân lý và viết phủ định (trên $\mathbb{N}$):
- a) $\forall x\, \exists y,\; (2x + y) \,\vdots\, 2$ (tức $2x + y$ chia hết cho $2$)
- b) $\exists x\, \forall y,\; (y \ne 0 \to xy = 1)$
- c) $\forall x\, \exists y,\; (x + y = 2 \land 2x - y = 1)$
- d) $\forall x,\; \big(x \ne 0 \to \exists y,\; xy = 1\big)$
- e) $\forall x\, \forall y\, \exists z,\; z = (x + y)/2$

**Bài 9:** Chứng minh lập luận sau hợp lệ, chỉ rõ quy tắc suy luận ở mỗi bước:
"Mọi số chia hết cho 6 đều chia hết cho 3. Mọi số chia hết cho 3 có tổng các chữ số chia hết cho 3. 42 chia hết cho 6. Vậy tổng các chữ số của 42 chia hết cho 3."

**Bài 10:** Chỉ ra rằng các tiền đề $(p \land t) \to (r \lor s)$, $\; q \to (u \land t)$, $\; u \to p$, $\; \lnot s$ dẫn đến kết luận $q \to r$.

## Lời giải mẫu: Bài 3

| Câu | Mệnh đề | Giá trị | Giải thích |
|:-:|---|:-:|---|
| a | $\forall x\, \exists y,\; x + y = 10$ | Đúng | với $x$ tùy ý, chọn $y = 10 - x$ |
| b | $\exists y\, \forall x,\; x + y = 10$ | Sai | phủ định $\forall y\, \exists x,\; x + y \ne 10$ đúng: với $y$ tùy ý, chọn $x = 11 - y$ thì $x + y = 11 \ne 10$ |
| c | $\forall x\, \forall y,\; (x < y \lor y < x \lor x = y)$ | Đúng | hai số thực bất kỳ luôn so sánh được |
| d | $\forall x \ne 0\;\exists y,\; xy = 1$ | Đúng | chọn $y = 1/x$ |
| e | $\exists x\, \forall y,\; xy = y$ | Đúng | chọn $x = 1$: $1 \cdot y = y$ với mọi $y$ |

> **Nhận xét (so sánh a và b):** trong a), $y$ được chọn **sau** $x$ nên có thể phụ thuộc $x$. Trong b), $y$ phải chọn **trước** và dùng chung cho mọi $x$, điều đó không thể.

## Lời giải mẫu: Bài 7

**a)** $A: \forall x\, \exists y,\; (xy \ge 0) \to (x - 3y \ne 2)$
- Với $x \ne 0$: chọn $y = -x$ ⇒ $xy = -x^2 < 0$, giả thiết sai ⇒ phép kéo theo đúng.
- Với $x = 0$: chọn $y = 0$ ⇒ $0 \ge 0$ và $0 - 0 = 0 \ne 2$ ⇒ $1 \to 1$ đúng.
- ⇒ $A$ **Đúng**.
- Phủ định: $\lnot A: \exists x\, \forall y,\; (xy \ge 0) \land (x - 3y = 2)$.

**b)** $C: \exists x\, \forall y,\; (xy < 0) \to (x - 4y = 5)$
- Chọn $x = 0$: với mọi $y$, $xy = 0$, nên giả thiết $xy < 0$ luôn sai.
- ⇒ phép kéo theo đúng với mọi $y$ ⇒ $C$ **Đúng**.
- Phủ định: $\lnot C: \forall x\, \exists y,\; (xy < 0) \land (x - 4y \ne 5)$. **Sai** (với $x = 0$ không có $y$ nào làm $xy < 0$).

> **Bẫy thường gặp:** phép kéo theo có giả thiết luôn sai thì luôn đúng. Hãy thử các giá trị đặc biệt như $x = 0$!