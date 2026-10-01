# Câu 1. Không gian Véc-tơ con & Cơ sở
> ## Dạng 1: Cho trước hệ sinh $S$
## $V = \mathbb{R}^3$, tập hợp $S = \{a_1 = (1; -3; 2), a_2 = (0; 1; -4), a_3 = (-2; 3; 1)\}$ và $W = \langle S \rangle$

$$A_S = \begin{pmatrix} a_1 \\ a_2 \\ a_3 \end{pmatrix} = \begin{pmatrix} 1 & -3 & 2 \\ 0 & 1 & -4 \\ -2 & 3 & 1 \end{pmatrix}$$

$$\xrightarrow{(3) \to (3) + 2(1)} \begin{pmatrix} 1 & -3 & 2 \\ 0 & 1 & -4 \\ 0 & -3 & 5 \end{pmatrix}$$

$$\xrightarrow{(3) \to (3) + 3(2)} \begin{pmatrix} 1 & -3 & 2 \\ 0 & 1 & -4 \\ 0 & 0 & -7 \end{pmatrix} = \begin{pmatrix} \gamma_1 \\ \gamma_2 \\ \gamma_3 \end{pmatrix}$$

Cơ sở của $W$ = $$\mathcal{B} = \{ \gamma_1 = (1; -3; 2), \gamma_2 = (0; 1; -4), \gamma_3 = (0; 0; -7) \}$$

Số chiều của không gian con $W$ = $$\dim_{\mathbb{R}} W = 3$$

> ## Dạng 2: Tham số
## $V = \mathbb{R}^4$, $W = \{\alpha = (-a+2b+c; 4c+5a; 2c-b+a; 2a-3b-c) \mid a,b,c \in \mathbb{R}\}$

Tách tham số:

$$\alpha = a(-1; 5; 1; 2) + b(2; 0; -1; -3) + c(1; 4; 2; -1)$$

Đặt $\alpha_1 = (-1; 5; 1; 2)$, $\alpha_2 = (2; 0; -1; -3)$, $\alpha_3 = (1; 4; 2; -1)$ và gọi $S = \{\alpha_1, \alpha_2, \alpha_3\}$.
$\Rightarrow W = \langle S \rangle$, suy ra $S$ là một hệ sinh của $W$.

Lập ma trận $A_S$:


$$A_S = \begin{pmatrix} -1 & 5 & 1 & 2 \\ 2 & 0 & -1 & -3 \\ 1 & 4 & 2 & -1 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (2) \to (2) + 2(1) \\ (3) \to (3) + (1) \end{matrix}} \begin{pmatrix} -1 & 5 & 1 & 2 \\ 0 & 10 & 1 & 1 \\ 0 & 9 & 3 & 1 \end{pmatrix}$$

$$\xrightarrow{(3) \to 10(3) - 9(2)} \begin{pmatrix} -1 & 5 & 1 & 2 \\ 0 & 10 & 1 & 1 \\ 0 & 0 & 21 & 1 \end{pmatrix} = \begin{pmatrix} \gamma_1 \\ \gamma_2 \\ \gamma_3 \end{pmatrix}$$

Cơ sở của $W$: $a = \{\gamma_1 = (-1; 5; 1; 2), \gamma_2 = (0; 10; 1; 1), \gamma_3 = (0; 0; 21; 1)\}$
Số chiều: $\dim_{\mathbb{R}} W = 3$


>## Dạng 3: Hệ phương trình

## $V = \mathbb{R}^4, W = \left\{ X = (x_1; x_2; x_3; x_4) \in \mathbb{R}^4 \;\middle\vert{}\; \begin{cases} 2x_2 - x_1 + x_3 = 0 \\ x_1 - 3x_2 + 2x_4 = 0 \\ 2x_1 - 3x_2 - x_4 = 0 \end{cases} \right\}$

Sắp xếp lại hệ phương trình theo thứ tự ẩn $(x_1, x_2, x_3, x_4)$:

$$\begin{cases} -x_1 + 2x_2 + x_3 = 0 \\ x_1 - 3x_2 + 2x_4 = 0 \\ 2x_1 - 3x_2 - x_4 = 0 \end{cases}$$

Lập ma trận hệ số $A$:

$$A = \begin{pmatrix} -1 & 2 & 1 & 0 \\ 1 & -3 & 0 & 2 \\ 2 & -3 & 0 & -1 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (2) \to (2) + (1) \\ (3) \to (3) + 2(1) \end{matrix}} \begin{pmatrix} -1 & 2 & 1 & 0 \\ 0 & -1 & 1 & 2 \\ 0 & 1 & 2 & -1 \end{pmatrix}$$

$$\xrightarrow{(3) \to (3) + (2)} \begin{pmatrix} -1 & 2 & 1 & 0 \\ 0 & -1 & 1 & 2 \\ 0 & 0 & 3 & 1 \end{pmatrix}$$

Hệ phương trình bậc thang tương đương:

$$\begin{cases} -x_1 + 2x_2 + x_3 = 0 \\ -x_2 + x_3 + 2x_4 = 0 \\ 3x_3 + x_4 = 0 \end{cases}$$

Hệ có 4 ẩn, 3 phương trình bậc thang $\implies$ có $4 - 3 = 1$ ẩn tự do.

Chọn **$x_4 = 3a$** làm ẩn tự do $(a \in \mathbb{R})$:

* Từ (3): $3x_3 + 3a = 0 \implies x_3 = -a$
* Từ (2): $-x_2 + (-a) + 2(3a) = 0 \implies x_2 = 5a$
* Từ (1): $-x_1 + 2(5a) + (-a) = 0 \implies x_1 = 9a$

Thay vào $X$:

$$X = (9a;\; 5a;\; -a;\; 3a) = a(9;\; 5;\; -1;\; 3)$$

* **Cơ sở của $W$**: $S = \{(9;\; 5;\; -1;\; 3)\}$
* **Số chiều**: $\dim_{\mathbb{R}} W = 1$

>## Dạng 4: Phương trình

## $V = \mathbb{R}^4, W = \{X = (x_1; x_2; x_3; x_4) \in \mathbb{R}^4 \mid x_1 + 2x_2 - x_3 + 3x_4 = 0\}$

Ta có phương trình tuyến tính thuần nhất nên $W$ là một không gian con của $\mathbb{R}^4$.

Chọn $x_2 = a, x_3 = b, x_4 = c$ làm các ẩn tự do ($a,b,c \in \mathbb{R}$). Từ phương trình:

* $x_1 + 2a - b + 3c = 0 \implies x_1 = -2a + b - 3c$

Thay vào $X$:

$$X = (-2a+b-3c;\; a;\; b;\; c) = a(-2;\;1;\;0;\;0) + b(1;\;0;\;1;\;0) + c(-3;\;0;\;0;\;1)$$

Đặt $S = \{(-2; 1; 0; 0), (1; 0; 1; 0), (-3; 0; 0; 1)\}$. Ba véc-tơ này độc lập tuyến tính vì các tọa độ thứ hai, thứ ba, thứ tư lần lượt cho ngay các hệ số $a,b,c$ trong một tổ hợp tuyến tính bằng véc-tơ không.

* **Cơ sở của $W$**: $S$
* **Số chiều**: $\dim_{\mathbb{R}} W = 3$

>## Dạng 5: Ma trận

## $V = M_2(\mathbb{R}), W = \left\{ A = \begin{pmatrix} 3a &  5b \\ -b  & a+b \end{pmatrix} \;\middle|\; a, b \in \mathbb{R} \right\}$

**1) Kiểm tra $W \le V$:**

* Chọn $A = \begin{pmatrix} 3 & 0 \\ 0 & 1 \end{pmatrix} \in W$ ứng với $a = 1, b = 0 \implies W \neq \emptyset$ (*).
* Lấy $A_1 = \begin{pmatrix} 3a_1 & 5b_1 \\ -b_1 & a_1+b_1 \end{pmatrix}$ và $A_2 = \begin{pmatrix} 3a_2 & 5b_2 \\ -b_2 & a_2+b_2 \end{pmatrix}$ thuộc $W$. Khi đó:

$$A_1 + A_2 = \begin{pmatrix} 3(a_1+a_2) & 5(b_1+b_2) \\ -(b_1+b_2) & (a_1+a_2)+(b_1+b_2) \end{pmatrix} \in W$$

ứng với $a = a_1 + a_2$ và $b = b_1 + b_2$ (**).

* Với mọi $c \in \mathbb{R}$:

$$cA_1 = \begin{pmatrix} 3(ca_1) & 5(cb_1) \\ -(cb_1) & (ca_1)+(cb_1) \end{pmatrix} \in W$$

ứng với $a = ca_1$ và $b = cb_1$ (***).

\* Từ (\*), (\*\*), (\*\*\*) $\implies$ **$W \le V$** (ĐPCM).

**2) Tìm hệ sinh, cơ sở, số chiều:**

Tách ma trận tổng quát theo $a, b$:


$$A = a\begin{pmatrix} 3 & 0 \\ 0 & 1 \end{pmatrix} + b\begin{pmatrix} 0 & 5 \\ -1 & 1 \end{pmatrix}$$

Đặt $S = \left\{ \begin{pmatrix} 3 & 0 \\ 0 & 1 \end{pmatrix},\ \begin{pmatrix} 0 & 5 \\ -1 & 1 \end{pmatrix} \right\}$.

* Vì $W = \langle S \rangle$ nên **$W \le V$**.
* Hai ma trận trong $S$ không tỉ lệ với nhau nên hệ $S$ độc lập tuyến tính.

**Kết luận:**

* **Hệ sinh:** $S = \left\{ \begin{pmatrix} 3 & 0 \\ 0 & 1 \end{pmatrix},\ \begin{pmatrix} 0 & 5 \\ -1 & 1 \end{pmatrix} \right\}$
* **Cơ sở:** $S$
* **Số chiều:** $\dim_{\mathbb{R}} W = 2$

---
---

# **Câu 2**

Trên $V = \mathbb{R}^3$ (tích vô hướng chính tắc), cho tập hợp:
$$a = \{u_1 = (1, 1, 0); u_2 = (1, 0, 1); u_3 = (0, 1, 1)\}$$

a) Chứng minh rằng $a$ là một cơ sở của $\mathbb{R}^3$.  
b) Trực chuẩn hóa cơ sở $a$ thành cơ sở trực chuẩn $b$.  
c) Tìm tọa độ của vector $v = (4, 3, 5) \in \mathbb{R}^3$ theo cơ sở $a$. (Tìm $[v]_a$)  
d) Tìm tọa độ của vector $v = (4, 3, 5) \in \mathbb{R}^3$ theo cơ sở $b$.  

## **a) Chứng minh $a$ là 1 cơ sở của $\mathbb{R}^3$**

Ta có $\dim \mathbb{R}^3 = 3$. Tập $a$ có đúng $3$ vector, nên để $a$ là cơ sở của $\mathbb{R}^3$ ta chỉ cần chứng minh $a$ độc lập tuyến tính.

Ta lập ma trận:
$$A_S = \begin{pmatrix} u_1 \\ u_2 \\ u_3 \end{pmatrix} = \begin{pmatrix} 1 & 1 & 0 \\ 1 & 0 & 1 \\ 0 & 1 & 1 \end{pmatrix}$$

Ta có:
$$\det(A_S) = 1 \cdot 0 \cdot 1 + 1 \cdot 1 \cdot 0 + 0 \cdot 1 \cdot 1 - [0 \cdot 0 \cdot 0 + 1 \cdot 1 \cdot 1 + 1 \cdot 1 \cdot 1] = -2 \neq 0$$

Suy ra $a$ độc lập tuyến tính, và do đó $a$ là một cơ sở của $\mathbb{R}^3$.


## **b) Trực chuẩn hóa cơ sở $a$ thành cơ sở trực chuẩn $b$**

Dùng phương pháp Gram-Schmidt, ta làm như sau:

Đặt:
$$v_1 = u_1 = (1, 1, 0)$$

$$v_2 = u_2 - \frac{\langle u_2, v_1 \rangle}{\langle v_1, v_1 \rangle} v_1 = (1, 0, 1) - \frac{1 \cdot 1 + 0 \cdot 1 + 1 \cdot 0}{1^2 + 1^2 + 0^2} (1, 1, 0) = (1, 0, 1) - \frac{1}{2}(1, 1, 0) = \left(\frac{1}{2}, -\frac{1}{2}, 1\right)$$

$$v_3 = u_3 - \frac{\langle u_3, v_2 \rangle}{\langle v_2, v_2 \rangle} v_2 - \frac{\langle u_3, v_1 \rangle}{\langle v_1, v_1 \rangle} v_1$$
$$= (0, 1, 1) - \frac{0 \cdot \frac{1}{2} + 1 \cdot \left(-\frac{1}{2}\right) + 1 \cdot 1}{\left(\frac{1}{2}\right)^2 + \left(-\frac{1}{2}\right)^2 + 1^2} \left(\frac{1}{2}, -\frac{1}{2}, 1\right) - \frac{0 \cdot 1 + 1 \cdot 1 + 1 \cdot 0}{1^2 + 1^2 + 0^2} (1, 1, 0)$$
$$= (0, 1, 1) - \frac{1}{3}\left(\frac{1}{2}, -\frac{1}{2}, 1\right) - \frac{1}{2}(1, 1, 0)$$
$$= (0, 1, 1) - \left(\frac{1}{6}, -\frac{1}{6}, \frac{1}{3}\right) - \left(\frac{1}{2}, \frac{1}{2}, 0\right) = \left(-\frac{2}{3}, \frac{2}{3}, \frac{2}{3}\right)$$

Ta có $a' = \{v_1, v_2, v_3\}$ là một tập hợp trực giao trên $\mathbb{R}^3$.

Chuẩn hóa các vector:
$$q_1 = \frac{v_1}{\|v_1\|} = \frac{(1, 1, 0)}{\sqrt{1^2 + 1^2 + 0^2}} = \frac{1}{\sqrt{2}}(1, 1, 0) = \left(\frac{\sqrt{2}}{2}, \frac{\sqrt{2}}{2}, 0\right)$$

$$q_2 = \frac{v_2}{\|v_2\|} = \frac{\left(\frac{1}{2}, -\frac{1}{2}, 1\right)}{\sqrt{\left(\frac{1}{2}\right)^2 + \left(-\frac{1}{2}\right)^2 + 1^2}} = \frac{1}{\frac{\sqrt{6}}{2}}\left(\frac{1}{2}, -\frac{1}{2}, 1\right) = \left(\frac{\sqrt{6}}{6}, -\frac{\sqrt{6}}{6}, \frac{\sqrt{6}}{3}\right)$$

$$q_3 = \frac{v_3}{\|v_3\|} = \frac{\left(-\frac{2}{3}, \frac{2}{3}, \frac{2}{3}\right)}{\sqrt{\left(-\frac{2}{3}\right)^2 + \left(\frac{2}{3}\right)^2 + \left(\frac{2}{3}\right)^2}} = \frac{1}{\frac{2\sqrt{3}}{3}}\left(-\frac{2}{3}, \frac{2}{3}, \frac{2}{3}\right) = \left(-\frac{\sqrt{3}}{3}, \frac{\sqrt{3}}{3}, \frac{\sqrt{3}}{3}\right)$$

Suy ra $b = \{q_1, q_2, q_3\}$ là một tập hợp trực chuẩn của $\mathbb{R}^3$, và là cơ sở trực chuẩn cần tìm.


## **c) Tìm tọa độ của vector $v = (4, 3, 5) \in \mathbb{R}^3$ theo cơ sở $a$ (Cách 1: Giải hệ pt)**

Ta cần tìm $c_1, c_2, c_3 \in \mathbb{R}$ sao cho:
$$v = c_1 u_1 + c_2 u_2 + c_3 u_3$$
$$\Leftrightarrow (4, 3, 5) = c_1 (1, 1, 0) + c_2 (1, 0, 1) + c_3 (0, 1, 1)$$
$$\Leftrightarrow \begin{cases} c_1 + c_2 = 4 \\ c_1 + c_3 = 3 \\ c_2 + c_3 = 5 \end{cases} \Leftrightarrow \begin{cases} c_1 = 1 \\ c_2 = 3 \\ c_3 = 2 \end{cases}$$

Như vậy, ta có:
$$[v]_a = \begin{pmatrix} c_1 \\ c_2 \\ c_3 \end{pmatrix} = \begin{pmatrix} 1 \\ 3 \\ 2 \end{pmatrix}$$


## **d) Tìm tọa độ của vector $v = (4, 3, 5) \in \mathbb{R}^3$ theo cơ sở $b$ (Cách 2: Dùng tích vô hướng)**

*(Áp dụng khi cơ sở $b$ là trực chuẩn)*

Ta cần tìm $c_1, c_2, c_3 \in \mathbb{R}$ sao cho $v = c_1 q_1 + c_2 q_2 + c_3 q_3$.  
Vì $b = \{q_1, q_2, q_3\}$ là cơ sở trực chuẩn nên $c_i = \langle v, q_i \rangle$ (với $i = 1, 2, 3$).

Ta có:
$$c_1 = \langle v, q_1 \rangle = 4 \cdot \frac{\sqrt{2}}{2} + 3 \cdot \frac{\sqrt{2}}{2} + 5 \cdot 0 = \frac{7\sqrt{2}}{2}$$

$$c_2 = \langle v, q_2 \rangle = 4 \cdot \frac{\sqrt{6}}{6} + 3 \cdot \left(-\frac{\sqrt{6}}{6}\right) + 5 \cdot \frac{\sqrt{6}}{3} = \frac{11\sqrt{6}}{6}$$

$$c_3 = \langle v, q_3 \rangle = 4 \cdot \left(-\frac{\sqrt{3}}{3}\right) + 3 \cdot \frac{\sqrt{3}}{3} + 5 \cdot \frac{\sqrt{3}}{3} = \frac{4\sqrt{3}}{3}$$

Như vậy, ta có:
$$[v]_b = \begin{pmatrix} c_1 \\ c_2 \\ c_3 \end{pmatrix} = \begin{pmatrix} \dfrac{7\sqrt{2}}{2} \\[1em] \dfrac{11\sqrt{6}}{6} \\[1em] \dfrac{4\sqrt{3}}{3} \end{pmatrix}$$

---
---

# **Câu 3**

Trên $V = \mathbb{R}^4$ với tích vô hướng:
$$\langle x \mid y \rangle = x_1 y_1 + 2x_2 y_2 + x_3 y_3 + 3x_4 y_4$$

Cho hệ $S = \{u_1 = (1, 1, 0, 0); u_2 = (0, 1, 1, 0); u_3 = (0, 0, 1, 1)\}$.  
Dùng phương pháp Gram-Schmidt để trực chuẩn hoá $S$.  
Cho vector $\lambda = (1, 3, 3, 1)$. Tìm tọa độ của $\lambda$ theo cơ sở vừa trực chuẩn hoá được.

---

Dùng phương pháp Gram-Schmidt, ta làm như sau:

Đặt:
$$v_1 = u_1 = (1, 1, 0, 0)$$

$$v_2 = u_2 - \frac{\langle u_2, v_1 \rangle}{\langle v_1, v_1 \rangle} v_1 = (0, 1, 1, 0) - \frac{0 \cdot 1 + 2 \cdot (1 \cdot 1) + 1 \cdot 0 + 3 \cdot (0 \cdot 0)}{1^2 + 2 \cdot (1)^2 + 0^2 + 3 \cdot (0)^2} (1, 1, 0, 0)$$
$$= (0, 1, 1, 0) - \frac{2}{3}(1, 1, 0, 0) = \left(-\frac{2}{3}, \frac{1}{3}, 1, 0\right)$$

$$v_3 = u_3 - \frac{\langle u_3, v_2 \rangle}{\langle v_2, v_2 \rangle} v_2 - \frac{\langle u_3, v_1 \rangle}{\langle v_1, v_1 \rangle} v_1$$
$$= (0, 0, 1, 1) - \frac{0 \cdot \left(-\frac{2}{3}\right) + 2 \cdot 0 \cdot \left(\frac{1}{3}\right) + 1 \cdot 1 + 3 \cdot 1 \cdot 0}{\left(-\frac{2}{3}\right)^2 + 2 \cdot \left(\frac{1}{3}\right)^2 + 1^2 + 3 \cdot (0)^2} \left(-\frac{2}{3}, \frac{1}{3}, 1, 0\right) - \frac{0 \cdot 1 + 2 \cdot 0 \cdot 1 + 1 \cdot 0 + 3 \cdot 1 \cdot 0}{1^2 + 2 \cdot (1)^2 + 0^2 + 3 \cdot (0)^2} (1, 1, 0, 0)$$
$$= (0, 0, 1, 1) - \frac{3}{5}\left(-\frac{2}{3}, \frac{1}{3}, 1, 0\right) - 0(1, 1, 0, 0)$$
$$= (0, 0, 1, 1) - \left(-\frac{2}{5}, \frac{1}{5}, \frac{3}{5}, 0\right) = \left(\frac{2}{5}, -\frac{1}{5}, \frac{2}{5}, 1\right)$$

Ta có $S' = \{v_1, v_2, v_3\}$ là một tập hợp trực giao trên $\mathbb{R}^4$.

Chuẩn hóa các vector:
$$q_1 = \frac{v_1}{\|v_1\|} = \frac{(1, 1, 0, 0)}{\sqrt{1^2 + 2(1)^2 + 0^2 + 3(0)^2}} = \frac{1}{\sqrt{3}}(1, 1, 0, 0) = \left(\frac{\sqrt{3}}{3}, \frac{\sqrt{3}}{3}, 0, 0\right)$$

$$q_2 = \frac{v_2}{\|v_2\|} = \frac{\left(-\frac{2}{3}, \frac{1}{3}, 1, 0\right)}{\sqrt{\left(-\frac{2}{3}\right)^2 + 2\left(\frac{1}{3}\right)^2 + 1^2 + 3(0)^2}} = \frac{1}{\frac{\sqrt{15}}{3}}\left(-\frac{2}{3}, \frac{1}{3}, 1, 0\right) = \left(-\frac{2\sqrt{15}}{15}, \frac{\sqrt{15}}{15}, \frac{\sqrt{15}}{5}, 0\right)$$

$$q_3 = \frac{v_3}{\|v_3\|} = \frac{\left(\frac{2}{5}, -\frac{1}{5}, \frac{2}{5}, 1\right)}{\sqrt{\left(\frac{2}{5}\right)^2 + 2\left(-\frac{1}{5}\right)^2 + \left(\frac{2}{5}\right)^2 + 3(1)^2}} = \frac{1}{\frac{\sqrt{85}}{5}}\left(\frac{2}{5}, -\frac{1}{5}, \frac{2}{5}, 1\right) = \left(\frac{2\sqrt{85}}{85}, -\frac{\sqrt{85}}{85}, \frac{2\sqrt{85}}{85}, \frac{\sqrt{85}}{17}\right)$$

Suy ra $S'' = \{q_1, q_2, q_3\}$ là một tập hợp trực chuẩn của $\mathbb{R}^4$.


## **Tìm $[\lambda]_{S''}$**

Tìm tọa độ của $\lambda = (1, 3, 3, 1)$:

Ta cần tìm $c_1, c_2, c_3 \in \mathbb{R}$ sao cho $\lambda = c_1 q_1 + c_2 q_2 + c_3 q_3$.  
Vì $S'' = \{q_1, q_2, q_3\}$ là cơ sở trực chuẩn nên $c_i = \langle \lambda, q_i \rangle$ (với $i = 1, 2, 3$).

Ta có:
$$c_1 = \langle \lambda, q_1 \rangle = 1 \cdot \frac{\sqrt{3}}{3} + 2 \cdot 3 \cdot \frac{\sqrt{3}}{3} + 3 \cdot 0 + 3 \cdot 1 \cdot 0 = \frac{7\sqrt{3}}{3}$$

$$c_2 = \langle \lambda, q_2 \rangle = 1 \cdot \left(-\frac{2\sqrt{15}}{15}\right) + 2 \cdot 3 \cdot \frac{\sqrt{15}}{15} + 3 \cdot \frac{\sqrt{15}}{5} + 3 \cdot 1 \cdot 0 = \frac{13\sqrt{15}}{15}$$

$$c_3 = \langle \lambda, q_3 \rangle = 1 \cdot \frac{2\sqrt{85}}{85} + 2 \cdot 3 \cdot \left(-\frac{\sqrt{85}}{85}\right) + 3 \cdot \frac{2\sqrt{85}}{85} + 3 \cdot 1 \cdot \frac{\sqrt{85}}{17} = \frac{\sqrt{85}}{5}$$

Như vậy, ta có:
$$[\lambda]_{S''} = \begin{pmatrix} c_1 \\ c_2 \\ c_3 \end{pmatrix} = \begin{pmatrix} \dfrac{7\sqrt{3}}{3} \\[1em] \dfrac{13\sqrt{15}}{15} \\[1em] \dfrac{\sqrt{85}}{5} \end{pmatrix}$$
