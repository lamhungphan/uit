### Bài tập điểm danh buổi 4

- Họ và tên: Nguyễn Phan Lâm Hùng
- MSSV: **26410212**
- Lớp: MA004.G12.LT.CNTT

---

### Bài 6
Trên tập số nguyên $\mathbb Z$, xét quan hệ $R$ định nghĩa bởi: $aRb\iff 3a+4b$ chia hết cho $7$
- a) Chứng minh $R$ là quan hệ tương đương. *Gợi ý:* thử biểu diễn $3a+4b$ qua hiệu $(a-b)$
- b) Tìm lớp tương đương $[0]_R$
- c) Chứng minh rằng quan hệ này thực chất chính là quan hệ đồng dư modulo $7$

Ta có:

$$
3a+4b=7a-4(a-b)
$$

Do $7a$ chia hết cho $7$, nên

$$
7\mid(3a+4b)\iff 7\mid 4(a-b)
$$

Vì 7 là số nguyên tố, từ $7\mid4(a-b)$ và $7\nmid4$ suy ra $7\mid(a-b)$. Do đó:

$$
aRb\iff a-b\equiv0\pmod7\iff a\equiv b\pmod7
$$

#### a) Chứng minh $R$ là quan hệ tương đương

- **Phản xạ:** $a-a=0$, nên $7\mid(a-a)$, suy ra $aRa$
- **Đối xứng:** Nếu $aRb$ thì $7\mid(a-b)$. Suy ra $7\mid(b-a)$, nên $bRa$
- **Bắc cầu:** Nếu $aRb$ và $bRc$ thì $7\mid(a-b)$ và $7\mid(b-c)$, do đó $a-c=(a-b)+(b-c)$ cũng chia hết cho $7$, nên $aRc$

Vậy $R$ phản xạ, đối xứng và bắc cầu, tức là quan hệ tương đương

#### b) Tìm lớp tương đương $[0]_R$

Theo định nghĩa:

$$
[0]_R=\{b\in\mathbb Z\mid bR0\}
$$

Ta có

$$
bR0\iff 3b+4\cdot0\text{ chia hết cho }7
\iff 7\mid3b
$$

Vì 7 là số nguyên tố, từ $7\mid3b$ và $7\nmid3$ suy ra $7\mid b$. Do đó

$$
[0]_R=\{7k\mid k\in\mathbb Z\}
=\{\ldots,-14,-7,0,7,14,\ldots\}
$$

#### c) Chứng minh $R$ chính là quan hệ đồng dư modulo $7$

Với mọi $a,b\in\mathbb Z$:

$$
\begin{aligned}
aRb
&\iff 7\mid(3a+4b)\\
&\iff 7\mid\bigl(7a-4(a-b)\bigr)\\
&\iff 7\mid4(a-b)\\
&\iff 7\mid(a-b)\\
&\iff a\equiv b\pmod7.
\end{aligned}
$$

Vì 7 là số nguyên tố và $7\nmid4$, nên có thể khử thừa số $4$ ở modulo $7$.

$$
R=\{(a,b)\in\mathbb Z^2\mid a\equiv b\pmod7\}
$$
