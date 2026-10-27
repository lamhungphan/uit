## Đề bài: Chứng minh sự tương đương logic:

$$\neg (p \rightarrow q) \vee (p \wedge r) \equiv p \wedge (\neg q \vee r)$$

### Câu 1. Chứng minh bằng bảng chân lý

Ta lập bảng chân lý cho cả vế trái ($\text{VT}$) và vế phải ($\text{VP}$) với 3 biến mệnh đề $p, q, r$ (trong đó $1$ tương ứng với Đúng/True, $0$ tương ứng với Sai/False):

| $p$ | $q$ | $r$ | $p \rightarrow q$ | $\neg(p \rightarrow q)$ | $p \wedge r$ | **$\text{VT} = \neg(p \rightarrow q) \vee (p \wedge r)$** | $\neg q$ | $\neg q \vee r$ | **$\text{VP} = p \wedge (\neg q \vee r)$** |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 1 | 1 | 1 | 0 | 1 | **1** | 0 | 1 | **1** |
| 1 | 1 | 0 | 1 | 0 | 0 | **0** | 0 | 0 | **0** |
| 1 | 0 | 1 | 0 | 1 | 1 | **1** | 1 | 1 | **1** |
| 1 | 0 | 0 | 0 | 1 | 0 | **1** | 1 | 1 | **1** |
| 0 | 1 | 1 | 1 | 0 | 0 | **0** | 0 | 1 | **0** |
| 0 | 1 | 0 | 1 | 0 | 0 | **0** | 0 | 0 | **0** |
| 0 | 0 | 1 | 1 | 0 | 0 | **0** | 1 | 1 | **0** |
| 0 | 0 | 0 | 1 | 0 | 0 | **0** | 1 | 1 | **0** |

**Nhận xét:** Cột của vế trái ($\text{VT}$) và vế phải ($\text{VP}$) hoàn toàn trùng khớp trong mọi trường hợp giá trị chân lý của các biến $p, q, r$.
Vậy đẳng thức logic được chứng minh

---

### Câu 2. Chứng minh bằng các luật logic

Ta tiến hành biến đổi vế trái ($\text{VT}$) thành vế phải ($\text{VP}$) bằng cách áp dụng các luật logic tương đương cơ bản:

$$\begin{aligned} 
\text{VT} &= \neg(p \rightarrow q) \vee (p \wedge r) \\ 

&\equiv \neg(\neg p \vee q) \vee (p \wedge r) && \text{(Luật kéo theo: } p \rightarrow q \equiv \neg p \vee q\text{)} \\ 

&\equiv [\neg(\neg p) \wedge \neg q] \vee (p \wedge r) && \text{(Luật De Morgan: } \neg(A \vee B) \equiv \neg A \wedge \neg B\text{)} \\ 

&\equiv (p \wedge \neg q) \vee (p \wedge r) && \text{(Luật phủ định kép: } \neg(\neg p) \equiv p\text{)} \\ 

&\equiv p \wedge (\neg q \vee r) && \text{(Luật phân phối đối với phép tuyển: } (A \wedge B) \vee (A \wedge C) \equiv A \wedge (B \vee C)\text{)} \\

&= \text{VP} 

\end{aligned}$$

Do đó đẳng thức logic 
$$\neg (p \rightarrow q) \vee (p \wedge r) \equiv p \wedge (\neg q \vee r)$$
được chứng minh
