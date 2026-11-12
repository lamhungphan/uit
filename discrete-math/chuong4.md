# Chương 4 – Đại số Bool

> Quy ước: $\bar x$ là phần bù (phủ định) của $x$; $xy$ nghĩa là $x\land y$; $x\lor y$ là tổng Bool.

# I. Đại số Bool

## Mở đầu: bài toán mạch điện
Cầu dao $A$ mắc song song với cụm $B,C$ mắc nối tiếp. Cầu dao đóng $=1$, mở $=0$; có dòng điện qua $MN$ $=1$.
Mỗi biến xem như một cầu dao, ta có công thức:

$$MN = A\lor(B\land C)$$

| $A$ | $B$ | $C$ | $MN$ |
|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 1 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 1 |

## Định nghĩa
Đại số Bool $(A,\land,\lor,\bar{\ },0,1)$ là tập $A\ne\varnothing$ cùng hai phép toán hai ngôi $\land,\lor$, một phép toán một ngôi $\bar{\ }$ và hai phần tử đặc biệt $0,1\in A$, thỏa 5 tính chất (với mọi $x,y,z\in A$):

| # | Tính chất | Công thức |
|:-:|---|---|
| 1 | Giao hoán | $x\land y=y\land x$; $\;x\lor y=y\lor x$ |
| 2 | Kết hợp | $(x\land y)\land z=x\land(y\land z)$; $\;(x\lor y)\lor z=x\lor(y\lor z)$ |
| 3 | Phân phối | $x\land(y\lor z)=(x\land y)\lor(x\land z)$; $\;x\lor(y\land z)=(x\lor y)\land(x\lor z)$ |
| 4 | Trung hòa | $x\land1=x$; $\;x\lor0=x$ |
| 5 | Phần tử bù | $x\land\bar x=0$; $\;x\lor\bar x=1$ |

Nhận xét: giống hệt các luật logic ở Chương 1 và các luật tập hợp ở Chương 2.

## Ví dụ về đại số Bool

| | Ví dụ 1 | Ví dụ 2 | Ví dụ 3 |
|---|---|---|---|
| Tập $A$ | $\{0,1\}$ | $\mathcal P(S)$ (các tập con của $S$) | Các mệnh đề |
| Phép $\land$ | $x\land y=\min\{x,y\}$ | $X\cap Y$ | Phép hội (và) |
| Phép $\lor$ | $x\lor y=\max\{x,y\}$ | $X\cup Y$ | Phép tuyển (hoặc) |
| Phép bù | $\bar x=1-x$ | $\bar X=S\setminus X$ | Phép phủ định |
| Phần tử $0$ | $0$ | $\varnothing$ | Mệnh đề luôn sai |
| Phần tử $1$ | $1$ | $S$ | Mệnh đề luôn đúng |

Ví dụ 1 là đại số Bool quan trọng nhất: nó mô tả bit, cầu dao, mạch điện.

## Một số tính chất suy ra từ định nghĩa
Với mọi $x,y$:
- **Lũy đẳng:** $x\lor x=x$; $\;x\land x=x$
- **Thống trị:** $x\lor1=1$; $\;x\land0=0$
- **Hấp thụ:** $x\lor(x\land y)=x$
- **De Morgan:** $\overline{x\lor y}=\bar x\land\bar y$; $\;\overline{x\land y}=\bar x\lor\bar y$

**Ví dụ 1:** Chứng minh $x\lor(x\land y)=x$.

$$
\begin{aligned}
x\lor(x\land y)&=(x\land1)\lor(x\land y) &&\text{(trung hòa)}\\
&=x\land(1\lor y) &&\text{(phân phối)}\\
&=x\land1=x &&\text{(thống trị, trung hòa)}
\end{aligned}
$$

**Ví dụ 2:** Rút gọn $x\lor(\bar x\land y)$.

$$
\begin{aligned}
x\lor(\bar x\land y)&=(x\lor\bar x)\land(x\lor y) &&\text{(phân phối)}\\
&=1\land(x\lor y)=x\lor y &&\text{(bù, trung hòa)}
\end{aligned}
$$

---

# II. Hàm Bool

## Định nghĩa
Hàm Bool $n$ biến là ánh xạ $f:B^n\to B$ với $B=\{0,1\}$.
- Có $2^n$ bộ giá trị của biến ⇒ bảng chân trị có $2^n$ dòng.
- Ký hiệu $F_n$ là tập các hàm Bool $n$ biến: $|F_n|=2^{2^n}$ (mỗi dòng nhận 0 hoặc 1).

**Ví dụ 1 (bầu cử 3 phiếu):** $f=1$ nếu đa số tán thành.

| $x$ | $y$ | $z$ | $f$ |
|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 1 |

**Ví dụ 2:** $f(x,y)=\bar x\lor y$ là hàm 2 biến, bảng có $2^2=4$ dòng: $f(1,0)=0$, các dòng còn lại bằng $1$.

## Các phép toán trên hàm Bool
Với $f,g\in F_n$:
- Cộng Bool: $f\lor g=f+g-fg=\max\{f,g\}$
- Nhân Bool: $f\land g=fg=\min\{f,g\}$
- Hàm bù: $\bar f=1-f$

Ví dụ: $f=\bar x\lor y$ thì $\bar f=\overline{\bar x\lor y}=x\bar y$ (De Morgan), chỉ bằng $1$ khi $x=1,\ y=0$.

## Dạng nối rời chính tắc (CDNF)
Xét hàm Bool theo $n$ biến $x_1,\dots,x_n$:
- **Từ đơn:** $x_i$ hoặc $\bar x_i$.
- **Đơn thức:** tích các từ đơn.
- **Từ tối tiểu:** đơn thức chứa đúng $n$ từ đơn (mỗi biến xuất hiện đúng một lần).
- **Công thức đa thức:** tổng ($\lor$) của các đơn thức.
- **Dạng nối rời chính tắc:** tổng của các từ tối tiểu.

Mỗi từ tối tiểu chỉ bằng $1$ tại đúng một dòng của bảng chân trị, ví dụ $x\bar yz=1\iff(x,y,z)=(1,0,1)$.

**Ví dụ (3 biến $x,y,z$):**
- Từ đơn: $x,y,z,\bar x,\bar y,\bar z$.
- Đơn thức: $xy,\ yz,\ x\bar z,\ xyz,\ \bar x\bar y\bar z$.
- Từ tối tiểu: $xy\bar z,\ \bar xyz,\ \bar x\bar y\bar z$ (phải đủ 3 biến).
- $E=xy\lor yz$ là công thức đa thức (chưa phải CDNF); $F=xyz\lor\bar x\bar y\bar z$ là CDNF.

## Tìm CDNF từ bảng chân trị
**Quy tắc:** mỗi dòng có $f=1$ cho một từ tối tiểu; biến bằng $1$ viết $x_i$, biến bằng $0$ viết $\bar x_i$.

- Hàm bầu cử 3 phiếu: $f=\bar xyz\lor x\bar yz\lor xy\bar z\lor xyz$.
- $f(x,y)=\bar x\lor y$ (các dòng $f=1$: $00,01,11$): $f=\bar x\bar y\lor\bar xy\lor xy$.

CDNF thường dài; mục tiêu tiếp theo là tìm công thức ngắn nhất.

## Công thức đa thức tối tiểu
Cho hai công thức đa thức của một hàm Bool: $F:\ f=m_1\lor\cdots\lor m_k$ và $G:\ f=M_1\lor\cdots\lor M_l$.
$F$ **đơn giản hơn** $G$ nếu tồn tại đơn ánh $h:\{1,\dots,k\}\to\{1,\dots,l\}$ sao cho với mọi $i$, số từ đơn của $m_i$ không nhiều hơn số từ đơn của $M_{h(i)}$.

Hiểu đơn giản: $F$ có ít đơn thức hơn (hoặc bằng) và mỗi đơn thức của $F$ không dài hơn đơn thức tương ứng của $G$. **Công thức đa thức tối tiểu** là công thức không có công thức nào đơn giản hơn nó. Nếu $F$ đơn giản hơn $G$ và $G$ đơn giản hơn $F$ thì hai công thức "đơn giản như nhau".

**Ví dụ 1:** $f\in F_4$ có 3 dạng:
1. $f=x\bar y\bar t\lor\bar xyz\lor x\bar z\bar t\lor xyz$
2. $f=x\bar y\bar t\lor\bar xyz\lor xy\bar z\lor yzt$
3. $f=x\bar y\bar t\lor\bar xyzt\lor\bar xyz\bar t\lor xy\bar z\lor yzt$

(1) và (2) đơn giản như nhau (đều 4 đơn thức, các bậc tương ứng bằng nhau); (2) đơn giản hơn (3) vì (3) có 5 đơn thức.

**Ví dụ 2:** $g\in F_4$ có 2 dạng:
1. $g=x\bar yz\lor z\bar t\lor\bar xyz\lor\bar xy\bar zt$ (bậc: 3, 2, 3, 4)
2. $g=z\bar t\lor x\bar yzt\lor\bar xyzt\lor\bar xy\bar zt$ (bậc: 2, 4, 4, 4)

So theo thứ tự thì chưa kết luận được, nên hoán vị các đơn thức của (2) thành $\bar xy\bar zt\lor z\bar t\lor\bar xyzt\lor x\bar yzt$ (bậc 4, 2, 4, 4). Khi đó (1) đơn giản hơn (2).

---

# III. Biểu đồ Karnaugh
Phương pháp xác định công thức đa thức tối tiểu bằng hình ảnh.

## Trường hợp $n=3$ (8 ô)
Mỗi ô ứng với một bộ giá trị $xyz$. Thứ tự cột sắp sao cho hai cột cạnh nhau chỉ khác một biến: $x\bar y\to xy\to\bar xy\to\bar x\bar y\to x\bar y$.

| | $x\bar y$ | $xy$ | $\bar xy$ | $\bar x\bar y$ |
|:-:|:-:|:-:|:-:|:-:|
| $z$ | 101 | 111 | 011 | 001 |
| $\bar z$ | 100 | 110 | 010 | 000 |

**Quy tắc kề nhau:** hai ô kề nhau nếu chỉ lệch nhau một biến duy nhất, kể cả ô đầu và ô cuối của cùng một hàng/cột (ví dụ $101$ và $001$ chỉ khác $x$).

**Ví dụ:** Kar của $f(x,y,z)=xy\lor\bar x\bar yz$: đơn thức $xy$ chiếm cột $xy$ (2 ô), đơn thức $\bar x\bar yz$ chiếm 1 ô.

| | $x\bar y$ | $xy$ | $\bar xy$ | $\bar x\bar y$ |
|:-:|:-:|:-:|:-:|:-:|
| $z$ | 0 | 1 | 0 | 1 |
| $\bar z$ | 0 | 1 | 0 | 0 |

- Đơn thức 3 biến chiếm 1 ô; đơn thức 2 biến chiếm 2 ô kề nhau; đơn thức càng ngắn càng chiếm nhiều ô.

## Trường hợp $n=4$ (16 ô)
Hàng: $z\bar t,\ zt,\ \bar zt,\ \bar z\bar t$; cột: $x\bar y,\ xy,\ \bar xy,\ \bar x\bar y$.

| | $x\bar y$ | $xy$ | $\bar xy$ | $\bar x\bar y$ |
|:-:|:-:|:-:|:-:|:-:|
| $z\bar t$ | 1010 | 1110 | 0110 | 0010 |
| $zt$ | 1011 | 1111 | 0111 | 0011 |
| $\bar zt$ | 1001 | 1101 | 0101 | 0001 |
| $\bar z\bar t$ | 1000 | 1100 | 0100 | 0000 |

Mỗi ô có đúng 4 ô kề (bằng số biến), kể cả kề "vòng quanh" (cột đầu – cột cuối, hàng đầu – hàng cuối). Có thể hình dung bìa được cuộn thành hình xuyến. Ví dụ ô $1010$ kề với $1110,\ 0010,\ 1011,\ 1000$.

## Biểu đồ Karnaugh của một đơn thức
$\operatorname{Kar}(f)$ là tập các ô mà $f$ nhận giá trị $1$. $\operatorname{Kar}$ của một đơn thức luôn là một hình chữ nhật.

| Đơn thức | Số từ đơn | Số ô |
|---|:-:|:-:|
| $x$ | 1 | 8 |
| $yz$ | 2 | 4 |
| $\bar xyzt$ | 4 | 1 |

**Quy luật:** đơn thức có $k$ từ đơn chiếm $2^{4-k}$ ô. Gom $2^m$ ô loại được $m$ biến.

## Tế bào lớn (Prime Implicant)
Tế bào là hình chữ nhật (theo nghĩa rộng) gồm $2^{n-k}$ ô ($0\le k\le n$). Nếu $T$ là tế bào thì $T$ là Kar của một đơn thức duy nhất $m$.

$T$ là **tế bào lớn** của $\operatorname{Kar}(f)$ nếu:
- a) $T$ là tế bào và $T\subseteq\operatorname{Kar}(f)$;
- b) không tồn tại tế bào $T'\ne T$ nào thỏa $T\subseteq T'\subseteq\operatorname{Kar}(f)$.

Hiểu đơn giản: tế bào lớn là vòng gom không thể mở rộng thêm.

**Quy tắc gom nhóm:**
- Vòng gom là hình chữ nhật chứa $2^n$ ô kề nhau (1, 2, 4, 8 ô).
- Số ô trong vòng phải lớn nhất có thể.
- Được gom cả những ô đã gom vào vòng khác để tạo vòng lớn hơn.
- Gom $2^n$ ô loại được $n$ biến; biến bị loại là biến có giá trị thay đổi khi đi qua các ô trong vòng.

**Ví dụ:** $\operatorname{Kar}(f)$ sau có 6 tế bào lớn:

| | $x\bar y$ | $xy$ | $\bar xy$ | $\bar x\bar y$ |
|:-:|:-:|:-:|:-:|:-:|
| $z\bar t$ | 1 | 1 | 0 | 1 |
| $zt$ | 1 | 1 | 0 | 1 |
| $\bar zt$ | 0 | 1 | 1 | 0 |
| $\bar z\bar t$ | 1 | 1 | 0 | 1 |

1. $xz$ (4 ô ở góc trên trái)
2. $\bar yz$ (cột đầu và cột cuối, 2 hàng $z$)
3. $x\bar t$ (hàng đầu và hàng cuối, 2 cột $x$)
4. $xy$ (cả cột $xy$)
5. $\bar y\bar t$ (4 góc)
6. $y\bar zt$ (2 ô ở hàng $\bar zt$)

Chú ý: 4 góc của bìa kề nhau từng đôi một nên gom được thành một tế bào.

## Thuật toán tìm đa thức tối tiểu
1. Vẽ biểu đồ Karnaugh của $f$.
2. Xác định tất cả các tế bào lớn của $\operatorname{Kar}(f)$.
3. Xác định các tế bào lớn **nhất thiết phải chọn** (tế bào lớn chứa một ô mà không tế bào lớn nào khác chứa).
4. Xác định các phủ tối tiểu gồm các tế bào lớn (thêm ít tế bào lớn nhất để phủ hết các ô còn lại).
5. Viết công thức đa thức tối tiểu tương ứng.

> **Mẹo:** ghi số thứ tự các tế bào lớn vào từng ô; ô nào chỉ có một số thì tế bào đó nhất thiết phải chọn.

### Ví dụ 1
Tìm công thức đa thức tối tiểu của $f=xyzt\lor x\bar y\lor x\bar z\lor yz\lor xy\bar z\lor xy\bar t$.

**B1.** Kar$(f)$ gồm 10 ô:

| | $x\bar y$ | $xy$ | $\bar xy$ | $\bar x\bar y$ |
|:-:|:-:|:-:|:-:|:-:|
| $z\bar t$ | 1 | 1 | 1 | 0 |
| $zt$ | 1 | 1 | 1 | 0 |
| $\bar zt$ | 1 | 1 | 0 | 0 |
| $\bar z\bar t$ | 1 | 1 | 0 | 0 |

**B2.** Tế bào lớn: (1) $x$ (2 cột $x$, 8 ô); (2) $yz$ (4 ô).
**B3.** Ô $x\bar yzt$ chỉ thuộc (1), ô $\bar xyzt$ chỉ thuộc (2) ⇒ chọn cả hai.
**B4.** Hai tế bào này đã phủ hết Kar$(f)$.
**B5.** $f=x\lor yz$.

### Ví dụ 2
Tìm các công thức đa thức tối tiểu của $f=\bar yzt\lor\bar y\bar z\bar t\lor y\bar z\bar t\lor xyzt\lor\bar xz\bar t$.

**B1.** Kar$(f)$ gồm 9 ô:

| | $x\bar y$ | $xy$ | $\bar xy$ | $\bar x\bar y$ |
|:-:|:-:|:-:|:-:|:-:|
| $z\bar t$ | 0 | 0 | 1 | 1 |
| $zt$ | 1 | 1 | 0 | 1 |
| $\bar zt$ | 0 | 0 | 0 | 0 |
| $\bar z\bar t$ | 1 | 1 | 1 | 1 |

**B2.** Tế bào lớn: (1) $\bar z\bar t$; (2) $\bar x\bar t$; (3) $\bar yzt$; (4) $xzt$; (5) $\bar x\bar yz$.
**B3.** Nhất thiết phải chọn (1), (2), (4): $\bar z\bar t\lor\bar x\bar t\lor xzt$.
**B4.** Còn ô $\bar x\bar yzt$ chưa phủ, thuộc (3) hoặc (5) ⇒ 2 cách chọn.
**B5.** Hai công thức đơn giản như nhau, nên $f$ có 2 công thức đa thức tối tiểu:

$$f=\bar z\bar t\lor\bar x\bar t\lor xzt\lor\bar x\bar yz\qquad f=\bar z\bar t\lor\bar x\bar t\lor xzt\lor\bar yzt$$

### Bài mẫu
Cho $f(x,y,z,t)=\bar xy\bar zt\lor yzt\lor\bar x\bar y\bar z\bar t\lor\bar yzt\lor xyz\bar t\lor x\bar z\bar t$.
a) Tìm dạng nối rời chính tắc. b) Tìm các công thức đa thức tối tiểu.

Kar$(f)$:

| | $x\bar y$ | $xy$ | $\bar xy$ | $\bar x\bar y$ |
|:-:|:-:|:-:|:-:|:-:|
| $z\bar t$ | 0 | 1 | 0 | 0 |
| $zt$ | 1 | 1 | 1 | 1 |
| $\bar zt$ | 0 | 0 | 1 | 0 |
| $\bar z\bar t$ | 1 | 1 | 0 | 1 |

**a)** Mỗi ô bằng 1 là một từ tối tiểu:

$$
\begin{aligned}
f={}&xyz\bar t\lor x\bar yzt\lor xyzt\lor\bar xyzt\lor\bar x\bar yzt\\
&\lor\bar xy\bar zt\lor x\bar y\bar z\bar t\lor xy\bar z\bar t\lor\bar x\bar y\bar z\bar t
\end{aligned}
$$

**b)** Các tế bào lớn: $T_1=zt$, $T_2=xyz$, $T_3=x\bar z\bar t$, $T_4=\bar xyt$, $T_5=\bar y\bar z\bar t$, $T_6=xy\bar t$.
Nhất thiết phải chọn $T_1,T_4,T_5$. Còn 2 ô $xyz\bar t$ và $xy\bar z\bar t$ chưa phủ. Các họ phủ: $\{T_3,T_2\}$ (5 hạng tử) hoặc $\{T_6\}$ (4 hạng tử).

Kết quả tối tiểu:

$$f=zt\lor\bar xyt\lor\bar y\bar z\bar t\lor xy\bar t$$

---

# IV. Mạch logic

## Các cổng cơ bản
| Cổng | Phép toán | Đầu ra |
|---|---|---|
| OR | Phép cộng | $x\lor y$ |
| AND | Phép nhân | $xy$ |
| NOT | Phủ định | $\bar x$ |

| $x$ | $y$ | $x\lor y$ | $xy$ |
|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 0 |
| 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 |

Cổng AND, OR có thể có nhiều hơn 2 đầu vào (ví dụ AND 3 đầu vào tính $xyz$).

## Ví dụ: mạch logic của một biểu thức
- **Ví dụ 1:** vẽ mạch cho $f=xy\lor\bar z$: cổng AND tính $xy$, cổng NOT tính $\bar z$, cổng OR gộp lại.
- **Ví dụ 2:** đọc mạch từ trái sang phải, ghi biểu thức ở đầu ra mỗi cổng. Mạch trong slide có cổng OR tính $x\lor y$, cổng NOT tính $\bar z$, rồi cổng AND cho đầu ra $(x\lor y)\bar z$.

## Cổng NAND và NOR
- NAND là cổng bù của AND: $X\ \text{nand}\ Y=\overline{XY}$.
- NOR là cổng bù của OR: $X\ \text{nor}\ Y=\overline{X+Y}$.

Mọi mạch logic đều có thể chuyển về chỉ dùng toàn cổng NAND hoặc toàn cổng NOR.
- $X\ \text{nand}\ X=\overline{XX}=\bar X$ ⇒ cổng NOT làm từ 1 cổng NAND.
- $(X\ \text{nand}\ Y)\ \text{nand}\ (X\ \text{nand}\ Y)=\overline{\overline{XY}}=XY$ ⇒ cổng AND làm từ 2 cổng NAND.

## Thiết kế mạch logic tổng hợp
Quy trình 5 bước:
1. Đặt biến đầu vào và hàm đầu ra.
2. Thiết lập bảng chân trị.
3. Viết biểu thức logic (dạng nối rời chính tắc).
4. Tìm công thức tối tiểu (dùng Karnaugh).
5. Vẽ sơ đồ mạch logic tương ứng.

Công thức càng tối tiểu thì mạch càng ít cổng ⇒ rẻ hơn, nhanh hơn, ít hỏng hơn.

### Ví dụ: đèn 3 công tắc
Một ngôi nhà có 3 công tắc; đèn sáng khi cả 3 công tắc đều hở, hoặc khi công tắc 1 và 2 đóng còn công tắc 3 hở. Thiết kế mạch dùng ít cổng cơ bản nhất.

**Bước 1.** Ba công tắc $A,B,C$; đèn $Y$. Công tắc đóng $=1$, hở $=0$; đèn sáng $=1$.

**Bước 2.** Bảng chân trị:

| $A$ | $B$ | $C$ | $Y$ | |
|:-:|:-:|:-:|:-:|---|
| 0 | 0 | 0 | 1 | sáng ⇒ $\bar A\bar B\bar C$ |
| 0 | 0 | 1 | 0 | |
| 0 | 1 | 0 | 0 | |
| 0 | 1 | 1 | 0 | |
| 1 | 0 | 0 | 0 | |
| 1 | 0 | 1 | 0 | |
| 1 | 1 | 0 | 1 | sáng ⇒ $AB\bar C$ |
| 1 | 1 | 1 | 0 | |

**Bước 3.** $Y=\bar A\bar B\bar C+AB\bar C$.

**Bước 4.** Hai ô $000$ và $110$ không kề nhau trên bìa Karnaugh nên không gom được: công thức tối tiểu vẫn là $Y=\bar A\bar B\bar C+AB\bar C$.

**Bước 5.** Mạch dùng 3 cổng NOT, 2 cổng AND và 1 cổng OR.

---

# Bài tập

## Nhóm 1: Câu 1–8

**Câu 1.** Cho hàm Bool 4 biến $f(x,y,z,t)=xz\bar t\lor x\bar yt\lor yt\lor\bar x\bar y\bar z\lor\bar x\bar zt\lor\bar xy\bar z\bar t$.
- a) Tìm dạng nối rời chính tắc.
- b) Tìm công thức đa thức tối tiểu.
- c) Vẽ sơ đồ mạch logic.

**Câu 2.** Cho biết tập các giá trị làm hàm bằng 0: $f^{-1}(0)=\{0011,0110,1100,1110,1001\}$ (thứ tự biến $x,y,z,t$). Thực hiện các yêu cầu tương tự Câu 1.

**Câu 3.** Tìm dạng nối rời chính tắc của hàm $f(x,y,z)=x\lor\bar yz$.

**Câu 4.** Dùng biểu đồ Karnaugh, tìm công thức đa thức tối tiểu của hàm bầu cử 3 phiếu: $f(x,y,z)=\bar xyz\lor x\bar yz\lor xy\bar z\lor xyz$.

**Câu 5.** Chứng minh trong mọi đại số Bool:
- a) $x\land(x\lor y)=x$
- b) $\overline{x\lor y}=\bar x\land\bar y$

**Câu 6.** Vẽ mạch logic cho các hàm:
- a) $f=(x\lor\bar y)z$
- b) $g=\bar xy\lor x\bar z\lor yz$

**Câu 7 (Đèn cầu thang).** Một bóng đèn ở cầu thang được điều khiển bởi 2 công tắc $A$ (chân cầu thang) và $B$ (đầu cầu thang). Gạt bất kỳ công tắc nào thì đèn đổi trạng thái (đang sáng thành tắt, đang tắt thành sáng). Biết khi cả hai công tắc cùng hở thì đèn tắt. Hãy thiết kế mạch logic điều khiển đèn.

**Câu 8.** Cho $f(x,y,z,t)=\bar x\bar z\lor xyz\lor\bar y\bar zt\lor\bar xyt$. Vẽ $\operatorname{Kar}(f)$, tìm tất cả các tế bào lớn và công thức đa thức tối tiểu.

### Lời giải Câu 2
$f=0$ tại 5 bộ giá trị: $0011=\bar x\bar yzt$, $0110=\bar xyz\bar t$, $1100=xy\bar z\bar t$, $1110=xyz\bar t$, $1001=x\bar y\bar zt$; $f=1$ tại $16-5=11$ bộ còn lại.

| | $x\bar y$ | $xy$ | $\bar xy$ | $\bar x\bar y$ |
|:-:|:-:|:-:|:-:|:-:|
| $z\bar t$ | 1 | 0 | 0 | 1 |
| $zt$ | 1 | 1 | 1 | 0 |
| $\bar zt$ | 0 | 1 | 1 | 1 |
| $\bar z\bar t$ | 1 | 0 | 1 | 1 |

**a) CDNF:**

$$
\begin{aligned}
f={}&x\bar yz\bar t\lor\bar x\bar yz\bar t\lor x\bar yzt\lor xyzt\lor\bar xyzt\lor xy\bar zt\\
&\lor\bar xy\bar zt\lor\bar x\bar y\bar zt\lor x\bar y\bar z\bar t\lor\bar xy\bar z\bar t\lor\bar x\bar y\bar z\bar t
\end{aligned}
$$

**b) Tế bào lớn:** $T_1=yt$, $T_2=\bar x\bar z$, $T_3=\bar y\bar t$ (4 góc), $T_4=x\bar yz$, $T_5=xzt$.
Nhất thiết phải chọn $T_1,T_2,T_3$. Còn ô $x\bar yzt$ chưa phủ: chọn $T_4$ hoặc $T_5$. Hai công thức tối tiểu:

$$f=yt\lor\bar x\bar z\lor\bar y\bar t\lor x\bar yz\qquad f=yt\lor\bar x\bar z\lor\bar y\bar t\lor xzt$$

**c) Mạch** cho $f=yt\lor\bar x\bar z\lor\bar y\bar t\lor xzt$: AND ($yt$), NOT + NOT + AND ($\bar x\bar z$), NOT + NOT + AND ($\bar y\bar t$), AND 3 đầu vào ($xzt$), rồi OR 4 đầu vào. Tổng cộng: 4 cổng NOT, 4 cổng AND, 1 cổng OR.

### Lời giải Câu 7
**Bước 1–2.** $A,B$: đóng $=1$, hở $=0$; đèn $Y$: sáng $=1$. $A=B=0$ thì đèn tắt (đề cho); gạt một công tắc thì đèn sáng; gạt tiếp công tắc còn lại thì đèn tắt.

| $A$ | $B$ | $Y$ | |
|:-:|:-:|:-:|---|
| 0 | 0 | 0 | |
| 0 | 1 | 1 | $\bar AB$ |
| 1 | 0 | 1 | $A\bar B$ |
| 1 | 1 | 0 | |

**Bước 3.** $Y=\bar AB\lor A\bar B$. Đèn sáng khi và chỉ khi đúng một công tắc đóng (phép XOR).

**Bước 4.** Hai ô $01$ và $10$ khác nhau ở cả hai biến nên không kề nhau, không gom được: công thức tối tiểu là $Y=\bar AB\lor A\bar B$.

**Bước 5.** Mạch gồm: AND trên ($\bar AB$), AND dưới ($A\bar B$), cổng OR cho $Y$. Tổng cộng 2 NOT, 2 AND, 1 OR. Có thể thay cả mạch bằng một cổng XOR: $Y=A\oplus B$.

---

## Nhóm 2: Cho trước $f^{-1}(0)$ hoặc $f^{-1}(1)$

### Đề 1 (cho $f^{-1}(0)$)
Cho hàm Boole $f$ theo 4 biến $x,y,z,t$, biết $f^{-1}(0)=\{0100,1100,0001,1001,0011\}$.
- a) Tìm dạng nối rời chính tắc của $f$.
- b) Tìm (các) công thức đa thức tối tiểu của $f$.
- c) Vẽ sơ đồ mạch cho một công thức đa thức tối tiểu của $f$ vừa tìm được.

($f^{-1}(0)$ là tập các bộ $(x,y,z,t)$ làm cho $f=0$. Ý tưởng: đánh dấu 5 ô bằng 0 trên bìa Karnaugh, các ô còn lại bằng 1.)

**Lời giải**

5 ô bằng 0: $0100=\bar xy\bar z\bar t$, $1100=xy\bar z\bar t$, $0001=\bar x\bar y\bar zt$, $1001=x\bar y\bar zt$, $0011=\bar x\bar yzt$; $16-5=11$ ô còn lại bằng 1.

| | $x\bar y$ | $xy$ | $\bar xy$ | $\bar x\bar y$ |
|:-:|:-:|:-:|:-:|:-:|
| $z\bar t$ | 1 | 1 | 1 | 1 |
| $zt$ | 1 | 1 | 1 | 0 |
| $\bar zt$ | 0 | 1 | 1 | 0 |
| $\bar z\bar t$ | 1 | 0 | 0 | 1 |

**a) CDNF:**

$$
\begin{aligned}
f={}&x\bar yz\bar t\lor xyz\bar t\lor\bar xyz\bar t\lor\bar x\bar yz\bar t\lor x\bar yzt\lor xyzt\\
&\lor\bar xyzt\lor xy\bar zt\lor\bar xy\bar zt\lor x\bar y\bar z\bar t\lor\bar x\bar y\bar z\bar t
\end{aligned}
$$

**b) Tế bào lớn:** $T_1=z\bar t$, $T_2=yz$, $T_3=yt$, $T_4=xz$, $T_5=\bar y\bar t$ (4 góc).
Nhất thiết phải chọn $T_3,T_4,T_5$. Còn ô $\bar xyz\bar t$ (số 1;2) chưa phủ: chọn $T_1$ hoặc $T_2$. Hai công thức tối tiểu (đơn giản như nhau):

$$f=xz\lor yt\lor\bar y\bar t\lor z\bar t\qquad f=xz\lor yt\lor\bar y\bar t\lor yz$$

**c) Mạch** cho $f=xz\lor yz\lor yt\lor\bar y\bar t$: AND ($xz$), AND ($yz$), AND ($yt$), NOT + NOT + AND ($\bar y\bar t$), rồi OR 4 đầu vào. Tổng cộng: 2 NOT, 4 AND, 1 OR. Chọn công thức có $yz$ thay vì $z\bar t$ để không cần thêm cổng NOT nào.

### Đề 2 (cho $f^{-1}(1)$)
Cho hàm Boole $f$ theo 4 biến $x,y,z,t$, biết $f^{-1}(1)=\{0000,0010,1000,1010,0101,0111,1101,1111,1110\}$. Yêu cầu a), b), c) như Đề 1.

(Khác Đề 1 ở chỗ $f^{-1}(1)$ cho trực tiếp các bộ làm $f=1$: không cần lấy phần bù; mỗi bộ chính là một ô bằng 1 và một từ tối tiểu.)

**Lời giải**

| | $x\bar y$ | $xy$ | $\bar xy$ | $\bar x\bar y$ |
|:-:|:-:|:-:|:-:|:-:|
| $z\bar t$ | 1 | 1 | 0 | 1 |
| $zt$ | 0 | 1 | 1 | 0 |
| $\bar zt$ | 0 | 1 | 1 | 0 |
| $\bar z\bar t$ | 1 | 0 | 0 | 1 |

$0000,0010,1000,1010$ là 4 ô ở 4 góc; $0101,0111,1101,1111$ là 4 ô ở giữa; $1110$ là ô $xyz\bar t$.

**a) CDNF (9 từ tối tiểu):**

$$
\begin{aligned}
f={}&\bar x\bar y\bar z\bar t\lor\bar x\bar yz\bar t\lor x\bar y\bar z\bar t\lor x\bar yz\bar t\lor\bar xy\bar zt\\
&\lor\bar xyzt\lor xy\bar zt\lor xyzt\lor xyz\bar t
\end{aligned}
$$

**b) Tế bào lớn:** $T_1=\bar y\bar t$ (4 góc), $T_2=yt$ (4 ô giữa), $T_3=xz\bar t$, $T_4=xyz$.
Nhất thiết phải chọn $T_1,T_2$. Còn ô $xyz\bar t$ (số 3;4) chưa phủ: chọn $T_3$ hoặc $T_4$. Hai công thức tối tiểu:

$$f=\bar y\bar t\lor yt\lor xz\bar t\qquad f=\bar y\bar t\lor yt\lor xyz$$

**c) Mạch** cho $f=\bar y\bar t\lor yt\lor xyz$: NOT + NOT + AND ($\bar y\bar t$), AND ($yt$), AND 3 đầu vào ($xyz$), rồi OR 3 đầu vào. Tổng cộng: 2 NOT, 3 AND, 1 OR. Nhận xét: $\bar y\bar t\lor yt$ bằng 1 khi $y=t$.

### Bài 8 (phân tích mạch logic)
Cho mạch logic (hình trong slide gốc) có 4 đầu vào $A,B,C,D$ và đầu ra $Y$.
- a) Viết biểu thức hàm $Y$ theo các biến $A,B,C,D$.
- b) Rút gọn hàm logic này. Vẽ lại mạch với hàm rút gọn.

(Cách đọc mạch: $\bar A,\bar B,\bar C$ là đầu ra của các cổng NOT. Chấm tròn là dây nối vào thanh dọc; dây chỉ cắt qua mà không có chấm thì không nối.)

**Lời giải**

**a)** Đọc đầu vào của từng cổng AND:
- AND 1 (trên): $\bar A,\bar B,\bar C\Rightarrow\bar A\bar B\bar C$
- AND 2 (giữa): $A,\bar B,\bar C\Rightarrow A\bar B\bar C$
- AND 3 (dưới): $\bar A,\bar B,D\Rightarrow\bar A\bar BD$

Cổng OR cộng 3 đầu ra: $Y=\bar A\bar B\bar C+A\bar B\bar C+\bar A\bar BD$. Mạch gốc dùng 3 NOT, 3 AND (3 đầu vào) và 1 OR (3 đầu vào).

**b) Rút gọn** bằng tính chất đại số Bool:

$$
\begin{aligned}
Y&=\bar A\bar B\bar C+A\bar B\bar C+\bar A\bar BD\\
&=(\bar A+A)\bar B\bar C+\bar A\bar BD &&\text{(phân phối)}\\
&=1\cdot\bar B\bar C+\bar A\bar BD &&\text{(phần tử bù)}\\
&=\bar B\bar C+\bar A\bar BD &&\text{(trung hòa)}
\end{aligned}
$$

Mẹo: hai số hạng chỉ khác nhau ở $A$ và $\bar A$ thì gộp được và loại biến $A$. Kiểm tra bằng Karnaugh: $\bar B\bar C$ chiếm 4 ô (2 cột $\bar B$, 2 hàng $\bar C$), $\bar A\bar BD$ chiếm 2 ô, cho cùng kết quả.

$$Y=\bar B\bar C+\bar A\bar BD$$

Mạch mới: AND 2 đầu vào ($\bar B\bar C$), AND 3 đầu vào ($\bar A\bar BD$), OR 2 đầu vào. So với mạch gốc (3 AND, OR 3 đầu vào) thì ít cổng hơn; chỉ cần một cổng NOT cho $B$ và nối $\bar B$ vào cả hai cổng AND.

---

## Bài tập luyện thêm

**Câu 9.** (4,0 điểm) Cho hàm Boole $f(x,y,z,t)$, biết $f^{-1}(0)=\{0010,1011,1111,0001,0000\}$.
- a) Tìm dạng nối rời chính tắc của $f$.
- b) Tìm các công thức đa thức tối tiểu của $f$.
- c) Vẽ sơ đồ mạch cho một công thức đa thức tối tiểu của $f$ vừa tìm được.

*Gợi ý:* đánh dấu 5 ô bằng 0 trên bìa Karnaugh trước, $16-5=11$ ô còn lại bằng 1.

**Câu 10.** (4,0 điểm) Cho hàm Bool theo 4 biến: $f(x,y,z,t)=xz\bar t\lor x\bar yt\lor yt\lor\bar x\bar y\bar z\lor\bar x\bar zt\lor\bar xy\bar z\bar t$.
- a) Tìm dạng nối rời chính tắc của $f$.
- b) Tìm các công thức đa thức tối tiểu của $f$.
- c) Vẽ sơ đồ mạch cho một công thức đa thức tối tiểu của $f$ vừa tìm được.

*Gợi ý:* tô lần lượt các ô của từng đơn thức lên bìa Karnaugh; ô nào đã tô rồi thì giữ nguyên.

(Câu 10 chính là hàm của Câu 1.)
