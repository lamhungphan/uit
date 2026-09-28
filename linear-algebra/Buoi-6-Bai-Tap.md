# 1. Tìm cơ sở và số chiều cho W (Cho truước hệ sinh S)

## a) $V = \mathbb{R}^3$, tập hợp $S = \{a_1 = (1; -3; 2), a_2 = (0; 1; -4), a_3 = (-2; 3; 1)\}$ và $W = \langle S \rangle$

$$A_S = \begin{pmatrix} a_1 \\ a_2 \\ a_3 \end{pmatrix} = \begin{pmatrix} 1 & -3 & 2 \\ 0 & 1 & -4 \\ -2 & 3 & 1 \end{pmatrix}$$

$$\xrightarrow{(3) \to (3) + 2(1)} \begin{pmatrix} 1 & -3 & 2 \\ 0 & 1 & -4 \\ 0 & -3 & 5 \end{pmatrix}$$

$$\xrightarrow{(3) \to (3) + 3(2)} \begin{pmatrix} 1 & -3 & 2 \\ 0 & 1 & -4 \\ 0 & 0 & -7 \end{pmatrix} = \begin{pmatrix} \gamma_1 \\ \gamma_2 \\ \gamma_3 \end{pmatrix}$$

Cơ sở của $W$ = $$\mathcal{B} = \{ \gamma_1 = (1; -3; 2), \gamma_2 = (0; 1; -4), \gamma_3 = (0; 0; -7) \}$$

Số chiều của không gian con $W$ = $$\dim_{\mathbb{R}} W = 3$$

## b) $V = \mathbb{R}^4$, $S = \{a_1 = (1; 0; -1; 2), a_2 = (2; 0; 3; -1), a_3 = (-1; -2; 0; 2)\}$ và $W = \langle S \rangle$

$$A_S = \begin{pmatrix} a_1 \\ a_2 \\ a_3 \end{pmatrix} = \begin{pmatrix} 1 & 0 & -1 & 2 \\ 2 & 0 & 3 & -1 \\ -1 & -2 & 0 & 2 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (2) \to (2) - 2(1) \\ (3) \to (3) + (1) \end{matrix}} \begin{pmatrix} 1 & 0 & -1 & 2 \\ 0 & 0 & 5 & -5 \\ 0 & -2 & -1 & 4 \end{pmatrix}$$

$$\xrightarrow{(2) \leftrightarrow (3)} \begin{pmatrix} 1 & 0 & -1 & 2 \\ 0 & -2 & -1 & 4 \\ 0 & 0 & 5 & -5 \end{pmatrix} = \begin{pmatrix} \gamma_1 \\ \gamma_2 \\ \gamma_3 \end{pmatrix}$$

Ma trận có 3 dòng khác zero $\Rightarrow r(A_S) = 3 = \text{số vectơ trong } S$.
$\Rightarrow S$ là một hệ sinh nên $S$ cũng là một cơ sở của $W$.

$$\dim_{\mathbb{R}} W = 3$$

## c) $V = \mathbb{R}^4$, $S = \{a_1 = (-1; 3; 2; -4), a_2 = (0; 0; 1; -1), a_3 = (1; 0; 1; 0), a_4 = (2; 3; -1; 4)\}$ và $W = \langle S \rangle$

$$A_S = \begin{pmatrix} a_1 \\ a_2 \\ a_3 \\ a_4 \end{pmatrix} = \begin{pmatrix} -1 & 3 & 2 & -4 \\ 0 & 0 & 1 & -1 \\ 1 & 0 & 1 & 0 \\ 2 & 3 & -1 & 4 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (3) \to (3) + (1) \\ (4) \to (4) + 2(1) \end{matrix}} \begin{pmatrix} -1 & 3 & 2 & -4 \\ 0 & 0 & 1 & -1 \\ 0 & 3 & 3 & -4 \\ 0 & 9 & 3 & -4 \end{pmatrix}$$

$$\xrightarrow{(2) \leftrightarrow (3)} \begin{pmatrix} -1 & 3 & 2 & -4 \\ 0 & 3 & 3 & -4 \\ 0 & 0 & 1 & -1 \\ 0 & 9 & 3 & -4 \end{pmatrix}$$

$$\xrightarrow{(4) \to (4) - 3(2)} \begin{pmatrix} -1 & 3 & 2 & -4 \\ 0 & 3 & 3 & -4 \\ 0 & 0 & 1 & -1 \\ 0 & 0 & -6 & 8 \end{pmatrix}$$

$$\xrightarrow{(4) \to (4) + 6(3)} \begin{pmatrix} -1 & 3 & 2 & -4 \\ 0 & 3 & 3 & -4 \\ 0 & 0 & 1 & -1 \\ 0 & 0 & 0 & 2 \end{pmatrix} = \begin{pmatrix} \gamma_1 \\ \gamma_2 \\ \gamma_3 \\ \gamma_4 \end{pmatrix}$$

Ta có $a = \{\gamma_1 = (-1; 3; 2; -4), \gamma_2 = (0; 3; 3; -4), \gamma_3 = (0; 0; 1; -1), \gamma_4 = (0; 0; 0; 2)\}$ là một cơ sở của $W$, và số chiều là:

$$\dim_{\mathbb{R}} W = 4$$

## d) $V = \mathbb{R}^5$, $S = \{a_1 = (-1; 1; 0; -1; 1), a_2 = (1; 0; 0; 2; -1), a_3 = (-2; 1; 3; 0; -1)\}$ và $W = \langle S \rangle$

$$A_S = \begin{pmatrix} a_1 \\ a_2 \\ a_3 \end{pmatrix} = \begin{pmatrix} -1 & 1 & 0 & -1 & 1 \\ 1 & 0 & 0 & 2 & -1 \\ -2 & 1 & 3 & 0 & -1 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (2) \to (2) + (1) \\ (3) \to (3) - 2(1) \end{matrix}} \begin{pmatrix} -1 & 1 & 0 & -1 & 1 \\ 0 & 1 & 0 & 1 & 0 \\ 0 & -1 & 3 & 2 & -3 \end{pmatrix}$$

$$\xrightarrow{(3) \to (3) + (2)} \begin{pmatrix} -1 & 1 & 0 & -1 & 1 \\ 0 & 1 & 0 & 1 & 0 \\ 0 & 0 & 3 & 3 & -3 \end{pmatrix} = \begin{pmatrix} \gamma_1 \\ \gamma_2 \\ \gamma_3 \end{pmatrix}$$

Do ma trận kết quả có 3 dòng khác zero $r(A_S) = 3 = \text{số vectơ trong } S$, nên $S$ độc lập tuyến tính.

Suy ra $S$ vừa là hệ sinh, vừa là cơ sở của $W$, hoặc chọn cơ sở bậc thang:

$$a = \{\gamma_1 = (-1; 1; 0; -1; 1), \gamma_2 = (0; 1; 0; 1; 0), \gamma_3 = (0; 0; 3; 3; -3)\}$$

Số chiều của $W$:

$$\dim_{\mathbb{R}} W = 3$$


## e) $V = \mathbb{R}^5$, $S = \{a_1 = (-2; -3; 0; 0; 1), a_2 = (-1; 1; 1; 0; 0), a_3 = (2; -1; 4; 1; 0), a_4 = (-2; 1; -3; 0; 1)\}$ và $W = \langle S \rangle$

Lập ma trận $A_S$:

$$A_S = \begin{pmatrix} a_1 \\ a_2 \\ a_3 \\ a_4 \end{pmatrix} = \begin{pmatrix} -2 & -3 & 0 & 0 & 1 \\ -1 & 1 & 1 & 0 & 0 \\ 2 & -1 & 4 & 1 & 0 \\ -2 & 1 & -3 & 0 & 1 \end{pmatrix}$$

$$\xrightarrow{(1) \leftrightarrow (2)} \begin{pmatrix} -1 & 1 & 1 & 0 & 0 \\ -2 & -3 & 0 & 0 & 1 \\ 2 & -1 & 4 & 1 & 0 \\ -2 & 1 & -3 & 0 & 1 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (2) \to (2) - 2(1) \\ (3) \to (3) + 2(1) \\ (4) \to (4) - 2(1) \end{matrix}} \begin{pmatrix} -1 & 1 & 1 & 0 & 0 \\ 0 & -5 & -2 & 0 & 1 \\ 0 & 1 & 6 & 1 & 0 \\ 0 & -1 & -5 & 0 & 1 \end{pmatrix}$$

$$\xrightarrow{(2) \leftrightarrow (3)} \begin{pmatrix} -1 & 1 & 1 & 0 & 0 \\ 0 & 1 & 6 & 1 & 0 \\ 0 & -5 & -2 & 0 & 1 \\ 0 & -1 & -5 & 0 & 1 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (3) \to (3) + 5(2) \\ (4) \to (4) + (2) \end{matrix}} \begin{pmatrix} -1 & 1 & 1 & 0 & 0 \\ 0 & 1 & 6 & 1 & 0 \\ 0 & 0 & 28 & 5 & 1 \\ 0 & 0 & 1 & 1 & 0 \end{pmatrix}$$

$$\xrightarrow{(3) \leftrightarrow (4)} \begin{pmatrix} -1 & 1 & 1 & 0 & 0 \\ 0 & 1 & 6 & 1 & 0 \\ 0 & 0 & 1 & 1 & 0 \\ 0 & 0 & 28 & 5 & 1 \end{pmatrix}$$

$$\xrightarrow{(4) \to (4) - 28(3)} \begin{pmatrix} -1 & 1 & 1 & 0 & 0 \\ 0 & 1 & 6 & 1 & 0 \\ 0 & 0 & 1 & 1 & 0 \\ 0 & 0 & 0 & -23 & 1 \end{pmatrix} = \begin{pmatrix} \gamma_1 \\ \gamma_2 \\ \gamma_3 \\ \gamma_4 \end{pmatrix}$$

Ta có $a = \{\gamma_1 = (-1; 1; 1; 0; 0), \gamma_2 = (0; 1; 6; 1; 0), \gamma_3 = (0; 0; 1; 1; 0), \gamma_4 = (0; 0; 0; -23; 1)\}$ là một cơ sở của $W$, và số chiều là:

$$\dim_{\mathbb{R}} W = 4$$

---

# 2. Tìm hệ sinh, cơ sở, số chiều cho **không gian phụ thuộc tham số**

## a) $V = \mathbb{R}^4$, $W = \{\alpha = (-a+2b+c; 4c+5a; 2c-b+a; 2a-3b-c) \mid a,b,c \in \mathbb{R}\}$

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

---

### b) $V = \mathbb{R}^4$, $W = \{\alpha = (3d+a-2b-c; 2d-c+a; 3d-c+b+2a; d-a+b) \mid a,b,c,d \in \mathbb{R}\}$

Tách tham số:

$$\alpha = a(1; 1; 2; -1) + b(-2; 0; 1; 1) + c(-1; -1; -1; 0) + d(3; 2; 3; 1)$$

Gọi $S = \{\alpha_1 = (1; 1; 2; -1), \alpha_2 = (-2; 0; 1; 1), \alpha_3 = (-1; -1; -1; 0), \alpha_4 = (3; 2; 3; 1)\}$.
$\Rightarrow W = \langle S \rangle$, suy ra $S$ là một hệ sinh của $W$.

Lập ma trận $A_S$:

$$A_S = \begin{pmatrix} 1 & 1 & 2 & -1 \\ -2 & 0 & 1 & 1 \\ -1 & -1 & -1 & 0 \\ 3 & 2 & 3 & 1 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (2) \to (2) + 2(1) \\ (3) \to (3) + (1) \\ (4) \to (4) - 3(1) \end{matrix}} \begin{pmatrix} 1 & 1 & 2 & -1 \\ 0 & 2 & 5 & -1 \\ 0 & 0 & 1 & -1 \\ 0 & -1 & -3 & 4 \end{pmatrix}$$

$$\xrightarrow{(4) \to 2(4) + (2)} \begin{pmatrix} 1 & 1 & 2 & -1 \\ 0 & 2 & 5 & -1 \\ 0 & 0 & 1 & -1 \\ 0 & 0 & -1 & 7 \end{pmatrix}$$

$$\xrightarrow{(4) \to (4) + (3)} \begin{pmatrix} 1 & 1 & 2 & -1 \\ 0 & 2 & 5 & -1 \\ 0 & 0 & 1 & -1 \\ 0 & 0 & 0 & 6 \end{pmatrix} = \begin{pmatrix} \gamma_1 \\ \gamma_2 \\ \gamma_3 \\ \gamma_4 \end{pmatrix}$$

Cơ sở của $W$: $a = \{\gamma_1 = (1; 1; 2; -1), \gamma_2 = (0; 2; 5; -1), \gamma_3 = (0; 0; 1; -1), \gamma_4 = (0; 0; 0; 6)\}$
Số chiều: $\dim_{\mathbb{R}} W = 4$

---

### c) $V = \mathbb{R}^4$, $W = \{\alpha = (d-e+2a+b-3c; 4e+d-2c+a; e-3d+c+2b-a; 3e+2d-a-b) \mid a,b,c,d,e \in \mathbb{R}\}$

Tách tham số theo $(a,b,c,d,e)$:


$$\alpha_1 = (2; 1; -1; -1), \quad \alpha_2 = (1; 0; 2; -1), \quad \alpha_3 = (-3; -2; 1; 0)$$

$$\alpha_4 = (1; 1; -3; 2), \quad \alpha_5 = (-1; 4; 1; 3)$$

Gọi $S = \{\alpha_1, \alpha_2, \alpha_3, \alpha_4, \alpha_5\} \Rightarrow W = \langle S \rangle$ là hệ sinh của $W$.

Lập ma trận $A_S$:


$$A_S = \begin{pmatrix} 2 & 1 & -1 & -1 \\ 1 & 0 & 2 & -1 \\ -3 & -2 & 1 & 0 \\ 1 & 1 & -3 & 2 \\ -1 & 4 & 1 & 3 \end{pmatrix} \xrightarrow{(1) \leftrightarrow (2)} \begin{pmatrix} 1 & 0 & 2 & -1 \\ 2 & 1 & -1 & -1 \\ -3 & -2 & 1 & 0 \\ 1 & 1 & -3 & 2 \\ -1 & 4 & 1 & 3 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (2) \to (2) - 2(1) \\ (3) \to (3) + 3(1) \\ (4) \to (4) - (1) \\ (5) \to (5) + (1) \end{matrix}} \begin{pmatrix} 1 & 0 & 2 & -1 \\ 0 & 1 & -5 & 1 \\ 0 & -2 & 7 & -3 \\ 0 & 1 & -5 & 3 \\ 0 & 4 & 3 & 2 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (3) \to (3) + 2(2) \\ (4) \to (4) - (2) \\ (5) \to (5) - 4(2) \end{matrix}} \begin{pmatrix} 1 & 0 & 2 & -1 \\ 0 & 1 & -5 & 1 \\ 0 & 0 & -3 & -1 \\ 0 & 0 & 0 & 2 \\ 0 & 0 & 23 & -2 \end{pmatrix}$$

$$\xrightarrow{(5) \to 3(5) + 23(3)} \begin{pmatrix} 1 & 0 & 2 & -1 \\ 0 & 1 & -5 & 1 \\ 0 & 0 & -3 & -1 \\ 0 & 0 & 0 & 2 \\ 0 & 0 & 0 & -29 \end{pmatrix}$$

$$\xrightarrow{(5) \to 2(5) + 29(4)} \begin{pmatrix} 1 & 0 & 2 & -1 \\ 0 & 1 & -5 & 1 \\ 0 & 0 & -3 & -1 \\ 0 & 0 & 0 & 2 \\ 0 & 0 & 0 & 0 \end{pmatrix} = \begin{pmatrix} \gamma_1 \\ \gamma_2 \\ \gamma_3 \\ \gamma_4 \\ O \end{pmatrix}$$

Cơ sở của $W$: $a = \{\gamma_1 = (1; 0; 2; -1), \gamma_2 = (0; 1; -5; 1), \gamma_3 = (0; 0; -3; -1), \gamma_4 = (0; 0; 0; 2)\}$
Số chiều: $\dim_{\mathbb{R}} W = 4$

---

### d) $V = \mathbb{R}^5$, $W = \{\alpha = (a-2b+c; 2c-3a+b; 4c+b-2a; a-b+3c; c-2a-b) \mid a,b,c \in \mathbb{R}\}$

Tách tham số:


$$\alpha = a(1; -3; -2; 1; -2) + b(-2; 1; 1; -1; -1) + c(1; 2; 4; 3; 1)$$

Gọi $S = \{\alpha_1 = (1; -3; -2; 1; -2), \alpha_2 = (-2; 1; 1; -1; -1), \alpha_3 = (1; 2; 4; 3; 1)\} \Rightarrow W = \langle S \rangle$ là hệ sinh của $W$.

Lập ma trận $A_S$:


$$A_S = \begin{pmatrix} 1 & -3 & -2 & 1 & -2 \\ -2 & 1 & 1 & -1 & -1 \\ 1 & 2 & 4 & 3 & 1 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (2) \to (2) + 2(1) \\ (3) \to (3) - (1) \end{matrix}} \begin{pmatrix} 1 & -3 & -2 & 1 & -2 \\ 0 & -5 & -3 & 1 & -5 \\ 0 & 5 & 6 & 2 & 3 \end{pmatrix}$$

$$\xrightarrow{(3) \to (3) + (2)} \begin{pmatrix} 1 & -3 & -2 & 1 & -2 \\ 0 & -5 & -3 & 1 & -5 \\ 0 & 0 & 3 & 3 & -2 \end{pmatrix} = \begin{pmatrix} \gamma_1 \\ \gamma_2 \\ \gamma_3 \end{pmatrix}$$

Cơ sở của $W$: $a = \{\gamma_1 = (1; -3; -2; 1; -2), \gamma_2 = (0; -5; -3; 1; -5), \gamma_3 = (0; 0; 3; 3; -2)\}$
Số chiều: $\dim_{\mathbb{R}} W = 3$

---

### e) $V = \mathbb{R}^5$, $W = \{\alpha = (a-b+2c-d; c+a-2b+3d; 2c+d-a; a-2b+c-3d; c+d-a+b) \mid a,b,c,d \in \mathbb{R}\}$

Tách tham số theo $(a,b,c,d)$:


$$\alpha_1 = (1; 1; -1; 1; -1), \quad \alpha_2 = (-1; -2; 0; -2; 1)$$

$$\alpha_3 = (2; 1; 2; 1; 1), \quad \alpha_4 = (-1; 3; 1; -3; 1)$$

Gọi $S = \{\alpha_1, \alpha_2, \alpha_3, \alpha_4\} \Rightarrow W = \langle S \rangle$ là hệ sinh của $W$.

Lập ma trận $A_S$:


$$A_S = \begin{pmatrix} 1 & 1 & -1 & 1 & -1 \\ -1 & -2 & 0 & -2 & 1 \\ 2 & 1 & 2 & 1 & 1 \\ -1 & 3 & 1 & -3 & 1 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (2) \to (2) + (1) \\ (3) \to (3) - 2(1) \\ (4) \to (4) + (1) \end{matrix}} \begin{pmatrix} 1 & 1 & -1 & 1 & -1 \\ 0 & -1 & -1 & -1 & 0 \\ 0 & -1 & 4 & -1 & 3 \\ 0 & 4 & 0 & -2 & 0 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (3) \to (3) - (2) \\ (4) \to (4) + 4(2) \end{matrix}} \begin{pmatrix} 1 & 1 & -1 & 1 & -1 \\ 0 & -1 & -1 & -1 & 0 \\ 0 & 0 & 5 & 0 & 3 \\ 0 & 0 & -4 & -6 & 0 \end{pmatrix}$$

$$\xrightarrow{(4) \to 5(4) + 4(3)} \begin{pmatrix} 1 & 1 & -1 & 1 & -1 \\ 0 & -1 & -1 & -1 & 0 \\ 0 & 0 & 5 & 0 & 3 \\ 0 & 0 & 0 & -30 & 12 \end{pmatrix} = \begin{pmatrix} \gamma_1 \\ \gamma_2 \\ \gamma_3 \\ \gamma_4 \end{pmatrix}$$

Cơ sở của $W$: $a = \{\gamma_1 = (1; 1; -1; 1; -1), \gamma_2 = (0; -1; -1; -1; 0), \gamma_3 = (0; 0; 5; 0; 3), \gamma_4 = (0; 0; 0; -30; 12)\}$
Số chiều: $\dim_{\mathbb{R}} W = 4$

---


# 3. Cho các hệ thuần nhất AX = O, tìm hệ sinh, cơ sở, số chiều cho W
> Dạng bài: Không gian nghiệm của hệ phương trình tuyến tính thuần nhất $AX = O$

## a) $$V = \mathbb{R}^4, W = \left\{ X = (x_1; x_2; x_3; x_4) \in \mathbb{R}^4 \;\middle\vert{}\; \begin{cases} 2x_2 - x_1 + x_3 = 0 \\ x_1 - 3x_2 + 2x_4 = 0 \\ 2x_1 - 3x_2 - x_4 = 0 \end{cases} \right\}$$

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

## b) $$V = \mathbb{R}^4, W = \left\{ X = (x_1; x_2; x_3; x_4) \in \mathbb{R}^4 \;\middle\vert{}\; \begin{cases} 4x_1 + 2x_2 + x_3 = 0 \\ x_1 + 2x_2 + 4x_4 = 0 \\ 2x_1 - x_2 + x_3 + x_4 = 0 \end{cases} \right\}$$

Ma trận hệ số $A$:


$$A = \begin{pmatrix} 4 & 2 & 1 & 0 \\ 1 & 2 & 0 & 4 \\ 2 & -1 & 1 & 1 \end{pmatrix} \xrightarrow{(1) \leftrightarrow (2)} \begin{pmatrix} 1 & 2 & 0 & 4 \\ 4 & 2 & 1 & 0 \\ 2 & -1 & 1 & 1 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (2) \to (2) - 4(1) \\ (3) \to (3) - 2(1) \end{matrix}} \begin{pmatrix} 1 & 2 & 0 & 4 \\ 0 & -6 & 1 & -16 \\ 0 & -5 & 1 & -7 \end{pmatrix}$$

$$\xrightarrow{(3) \to 6(3) - 5(2)} \begin{pmatrix} 1 & 2 & 0 & 4 \\ 0 & -6 & 1 & -16 \\ 0 & 0 & 1 & 38 \end{pmatrix}$$

Hệ có ẩn tự do $x_4 = a$ $(a \in \mathbb{R})$.


$$\implies \begin{cases} x_3 = -38a \\ x_2 = \frac{x_3 - 16a}{6} = \frac{-38a - 16a}{6} = -9a \\ x_1 = -2x_2 - 4a = 18a - 4a = 14a \end{cases}$$

Thay vào $X$:


$$X = (14a; -9a; -38a; a) = a(14; -9; -38; 1)$$

Đặt $\alpha_1 = (14; -9; -38; 1) \neq \mathbf{0} \Rightarrow S = \{\alpha_1\}$ là cơ sở của $W$.
Số chiều: $\dim_{\mathbb{R}} W = 1$

## c) $$V = \mathbb{R}^5, W = \left\{ X = (x_1; x_2; x_3; x_4; x_5) \in \mathbb{R}^5 \;\middle\vert{}\; \begin{cases} 5x_1 - x_2 + 2x_3 + 3x_4 = 0 \\ x_1 - x_2 + 5x_3 = 0 \\ 4x_1 - 2x_2 + 2x_3 + x_4 + 5x_5 = 0 \\ 3x_1 - x_2 + 2x_3 - x_4 + 2x_5 = 0 \end{cases} \right\}$$

Ma trận hệ số $A$:


$$A = \begin{pmatrix} 5 & -1 & 2 & 3 & 0 \\ 1 & -1 & 5 & 0 & 0 \\ 4 & -2 & 2 & 1 & 5 \\ 3 & -1 & 2 & -1 & 2 \end{pmatrix} \xrightarrow{(1) \leftrightarrow (2)} \begin{pmatrix} 1 & -1 & 5 & 0 & 0 \\ 5 & -1 & 2 & 3 & 0 \\ 4 & -2 & 2 & 1 & 5 \\ 3 & -1 & 2 & -1 & 2 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (2) \to (2) - 5(1) \\ (3) \to (3) - 4(1) \\ (4) \to (4) - 3(1) \end{matrix}} \begin{pmatrix} 1 & -1 & 5 & 0 & 0 \\ 0 & 4 & -23 & 3 & 0 \\ 0 & 2 & -18 & 1 & 5 \\ 0 & 2 & -13 & -1 & 2 \end{pmatrix}$$

$$\xrightarrow{(2) \leftrightarrow (3)} \begin{pmatrix} 1 & -1 & 5 & 0 & 0 \\ 0 & 2 & -18 & 1 & 5 \\ 0 & 4 & -23 & 3 & 0 \\ 0 & 2 & -13 & -1 & 2 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (3) \to (3) - 2(2) \\ (4) \to (4) - (2) \end{matrix}} \begin{pmatrix} 1 & -1 & 5 & 0 & 0 \\ 0 & 2 & -18 & 1 & 5 \\ 0 & 0 & 13 & 1 & -10 \\ 0 & 0 & 5 & -2 & -3 \end{pmatrix}$$

$$\xrightarrow{(4) \to 13(4) - 5(3)} \begin{pmatrix} 1 & -1 & 5 & 0 & 0 \\ 0 & 2 & -18 & 1 & 5 \\ 0 & 0 & 13 & 1 & -10 \\ 0 & 0 & 0 & -31 & 11 \end{pmatrix}$$

Hệ có ẩn tự do $x_5 = a$ $(a \in \mathbb{R})$.


$$\implies \begin{cases} x_4 = \frac{11}{31}a \\ x_3 = \frac{10a - x_4}{13} = \frac{10a - \frac{11}{31}a}{13} = \frac{23}{31}a \\ x_2 = \frac{18x_3 - x_4 - 5a}{2} = \frac{18(\frac{23}{31}a) - \frac{11}{31}a - 5a}{2} = \frac{124}{31}a = 4a \\ x_1 = x_2 - 5x_3 = 4a - 5(\frac{23}{31}a) = \frac{9}{31}a \end{cases}$$

Chọn $a = 31 \Rightarrow X = (9; 124; 23; 11; 31)$.
Cơ sở của $W$: $S = \{(9; 124; 23; 11; 31)\}$
Số chiều: $\dim_{\mathbb{R}} W = 1$

## d) $$V = \mathbb{R}^5, W = \left\{ X = (x_1; x_2; x_3; x_4; x_5) \in \mathbb{R}^5 \;\middle\vert{}\; \begin{cases} 3x_3 - 4x_4 + x_1 + 2x_2 = 0 \\ 5x_5 - x_1 + 2x_2 + 3x_4 = 0 \\ x_1 - x_2 + 2x_5 = 0 \end{cases} \right\}$$

Sắp xếp lại hệ theo thứ tự $(x_1, x_2, x_3, x_4, x_5)$:

$$\begin{cases} x_1 + 2x_2 + 3x_3 - 4x_4 = 0 \\ -x_1 + 2x_2 + 3x_4 + 5x_5 = 0 \\ x_1 - x_2 + 2x_5 = 0 \end{cases}$$

Ma trận hệ số $A$:


$$A = \begin{pmatrix} 1 & 2 & 3 & -4 & 0 \\ -1 & 2 & 0 & 3 & 5 \\ 1 & -1 & 0 & 0 & 2 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (2) \to (2) + (1) \\ (3) \to (3) - (1) \end{matrix}} \begin{pmatrix} 1 & 2 & 3 & -4 & 0 \\ 0 & 4 & 3 & -1 & 5 \\ 0 & -3 & -3 & 4 & 2 \end{pmatrix}$$

$$\xrightarrow{(3) \to 4(3) + 3(2)} \begin{pmatrix} 1 & 2 & 3 & -4 & 0 \\ 0 & 4 & 3 & -1 & 5 \\ 0 & 0 & -3 & 13 & 23 \end{pmatrix}$$

Hệ có ẩn tự do $x_4 = a, x_5 = b$ $(a, b \in \mathbb{R})$.


$$\implies \begin{cases} x_3 = \frac{13a + 23b}{3} \\ x_2 = \frac{a - 5b - 3x_3}{4} = \frac{a - 5b - (13a + 23b)}{4} = -3a - 7b \\ x_1 = -2x_2 - 3x_3 + 4a = -2(-3a - 7b) - 3\left(\frac{13a + 23b}{3}\right) + 4a = -3a - 9b \end{cases}$$

Thay vào $X$:


$$X = \left(-3a - 9b; -3a - 7b; \frac{13}{3}a + \frac{23}{3}b; a; b\right)$$

$$= a\left(-3; -3; \frac{13}{3}; 1; 0\right) + b\left(-9; -7; \frac{23}{3}; 0; 1\right)$$

Cơ sở của $W$: $S = \{(-9; -9; 13; 3; 0), (-27; -21; 23; 0; 3)\}$
Số chiều: $\dim_{\mathbb{R}} W = 2$

## e) $$V = \mathbb{R}^5, W = \left\{ X = (x_1; x_2; x_3; x_4; x_5) \in \mathbb{R}^5 \;\middle\vert{}\; \begin{cases} 2x_2 - 5x_5 + x_1 - 3x_3 = 0 \\ 5x_5 + 4x_4 - x_1 + 3x_3 = 0 \\ x_1 - x_2 + 2x_5 - 4x_3 = 0 \\ 3x_1 - 2x_2 + 6x_5 - 6x_4 = 0 \end{cases} \right\}$$

Sắp xếp lại hệ theo thứ tự $(x_1, x_2, x_3, x_4, x_5)$:


$$\begin{cases} x_1 + 2x_2 - 3x_3 - 5x_5 = 0 \\ -x_1 - 3x_3 + 4x_4 + 5x_5 = 0 \\ x_1 - x_2 - 4x_3 + 2x_5 = 0 \\ 3x_1 - 2x_2 - 6x_4 + 6x_5 = 0 \end{cases}$$

Ma trận hệ số $A$:


$$A = \begin{pmatrix} 1 & 2 & -3 & 0 & -5 \\ -1 & 0 & -3 & 4 & 5 \\ 1 & -1 & -4 & 0 & 2 \\ 3 & -2 & 0 & -6 & 6 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (2) \to (2) + (1) \\ (3) \to (3) - (1) \\ (4) \to (4) - 3(1) \end{matrix}} \begin{pmatrix} 1 & 2 & -3 & 0 & -5 \\ 0 & 2 & -6 & 4 & 0 \\ 0 & -3 & -1 & 0 & 7 \\ 0 & -8 & 9 & -6 & 21 \end{pmatrix}$$

$$\xrightarrow{(2) \to \frac{1}{2}(2)} \begin{pmatrix} 1 & 2 & -3 & 0 & -5 \\ 0 & 1 & -3 & 2 & 0 \\ 0 & -3 & -1 & 0 & 7 \\ 0 & -8 & 9 & -6 & 21 \end{pmatrix}$$

$$\xrightarrow{\begin{matrix} (3) \to (3) + 3(2) \\ (4) \to (4) + 8(2) \end{matrix}} \begin{pmatrix} 1 & 2 & -3 & 0 & -5 \\ 0 & 1 & -3 & 2 & 0 \\ 0 & 0 & -10 & 6 & 7 \\ 0 & 0 & -15 & 10 & 21 \end{pmatrix}$$

$$\xrightarrow{(4) \to 2(4) - 3(3)} \begin{pmatrix} 1 & 2 & -3 & 0 & -5 \\ 0 & 1 & -3 & 2 & 0 \\ 0 & 0 & -10 & 6 & 7 \\ 0 & 0 & 0 & 2 & 21 \end{pmatrix}$$

Hệ có ẩn tự do $x_5 = a$ $(a \in \mathbb{R})$.


$$\implies \begin{cases} x_4 = -\frac{21}{2}a \\ x_3 = \frac{6x_4 + 7a}{10} = \frac{6(-\frac{21}{2}a) + 7a}{10} = -\frac{28}{5}a \\ x_2 = 3x_3 - 2x_4 = 3\left(-\frac{28}{5}a\right) - 2\left(-\frac{21}{2}a\right) = \frac{21}{5}a \\ x_1 = -2x_2 + 3x_3 + 5a = -2\left(\frac{21}{5}a\right) + 3\left(-\frac{28}{5}a\right) + 5a = -\frac{101}{5}a \end{cases}$$

Chọn $a = 10 \implies X = (-202; 42; -112; -210; 10)$.
Cơ sở của $W$: $S = \{(-202; 42; -112; -210; 10)\}$
Số chiều: $\dim_{\mathbb{R}} W = 1$