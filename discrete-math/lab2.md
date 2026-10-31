## Bài tập quy tắc phản ví dụ

### Bài 1: $p \rightarrow q, \quad r \rightarrow q \quad \therefore p \rightarrow r$

Để kiểm tra tính hợp lệ của suy luận, ta gán tất cả các tiền đề bằng **1** (Đúng) và kết luận bằng **0** (Sai). Nếu tìm được bộ giá trị thỏa mãn thì suy luận **không hợp lệ**

| Mệnh đề | Cần | Gán | B1 | B2 | B3 |
| --- | --- | --- | --- | --- | --- |
| $p \rightarrow q$ | $1$ | $1$ |  | $p = 1 \Rightarrow 1 \rightarrow q = 1 \Rightarrow q = 1$ |  |
| $r \rightarrow q$ | $1$ | $1$ |  |  | Với $q = 1 \Rightarrow r \rightarrow 1 = 1$ (thỏa mãn với mọi $r$, chọn $r = 0$) |
| $\therefore p \rightarrow r$ | $1?$ | **$0$** | $p \rightarrow r = 0 \Rightarrow p = 1, r = 0$ |  |  |

> $\Rightarrow$ **Kết luận:** Tìm được bộ giá trị phản ví dụ $(p = 1, q = 1, r = 0)$ làm cho tiền đề đúng nhưng kết luận sai. Vậy suy luận trên **KHÔNG HỢP LỆ (SAI)**

---

### Bài 2: $p \rightarrow q, \quad q \vee r \quad \therefore p \vee r$

| Mệnh đề | Cần | Gán | B1 | B2 | B3 |
| --- | --- | --- | --- | --- | --- |
| $p \rightarrow q$ | $1$ | $1$ |  | $p = 0 \Rightarrow 0 \rightarrow q = 1$ (thỏa mãn với mọi $q$) |  |
| $q \vee r$ | $1$ | $1$ |  |  | Chọn $q = 1 \Rightarrow 1 \vee 0 = 1$ (thỏa mãn) |
| $\therefore p \vee r$ | $1?$ | **$0$** | $p \vee r = 0 \Rightarrow p = 0, r = 0$ |  |  |

> $\Rightarrow$ **Kết luận:** Tìm được bộ giá trị phản ví dụ $(p = 0, q = 1, r = 0)$ làm cho các tiền đề đều đúng ($0 \rightarrow 1 \equiv 1$ và $1 \vee 0 \equiv 1$) nhưng kết luận sai ($0 \vee 0 \equiv 0$). Vậy suy luận trên **KHÔNG HỢP LỆ (SAI)**.
