# NỘI DUNG ÔN TẬP CUỐI KỲ - MÔN ĐẠI SỐ TUYẾN TÍNH

## CÂU 1: KHÔNG GIAN VÉC TƠ CON & CƠ SỞ (2.5 - 3.0 điểm)

### 1. Dạng đề bài
Cho không gian $V = \mathbb{R}^5$ (hoặc $V = \mathbb{R}^6$) và tập hợp $W = \{X \in V \mid \text{điều kiện}\}$.
* **Yêu cầu:**
  1. Chứng minh $W$ là không gian véc tơ con của $V$.
  2. Tìm hệ sinh, cơ sở và xác định số chiều $\dim(W)$.

### 2. Phương pháp làm bài

#### Bước 1: Chứng minh $W$ là không gian véc tơ con của $V$ ($W \le V$)
* **Cách 1 (Thường dùng cho hệ phương trình thuần nhất hoặc tập phụ thuộc tham số):**
  * Đặt véc tơ tổng quát $X \in W$, tách $X$ theo các tham số tự do $a, b, c, \dots$:
    $$X = a \cdot u_1 + b \cdot u_2 + c \cdot u_3$$
  * Gọi $S = \{u_1, u_2, u_3\} \subset V$.
  * Suy ra $W = \langle S \rangle$ (không gian con sinh bởi $S$).
  * Vì $\langle S \rangle \le V \implies W \le V$ (ĐPCM).

* **Cách 2 (Dùng định nghĩa):**
  * **Tính chất 1 (Khác rỗng):** Chỉ ra $\mathbf{0}_V \in W$.
  * **Tính chất 2 (Đóng kín với phép cộng):** Lấy $X, Y \in W \implies X + Y \in W$.
  * **Tính chất 3 (Đóng kín với phép nhân):** Lấy $X \in W, k \in \mathbb{R} \implies kX \in W$.

#### Bước 2: Tìm hệ sinh
* Sau khi biểu diễn $X = a \cdot u_1 + b \cdot u_2 + c \cdot u_3$, suy ra $S = \{u_1, u_2, u_3\}$ là một **hệ sinh** của $W$.

#### Bước 3: Tìm cơ sở và số chiều của $W$
* Xếp các véc tơ của hệ sinh $S$ thành các dòng của ma trận $A_S$.
* Biến đổi sơ cấp theo dòng để đưa $A_S$ về dạng **ma trận bậc thang** $H$.
* **Cơ sở của $W$:** Tập hợp các véc tơ dòng khác $\mathbf{0}$ trong ma trận bậc thang $H$.
* **Số chiều:** $\dim(W) = r(A_S) =$ số véc tơ trong cơ sở vừa tìm được.

---

## CÂU 2: CƠ SỞ, TRỰC CHUẨN HÓA VÀ TỌA ĐỘ TRONG $\mathbb{R}^3$ (2.5 điểm)

### 1. Dạng đề bài
Trên $V = \mathbb{R}^3$, cho tập hợp $a = \{u_1, u_2, u_3\}$ và véc tơ $v \in \mathbb{R}^3$.
* **Yêu cầu:**
  a) Chứng minh $a$ là một cơ sở của $\mathbb{R}^3$.
  b) Trực chuẩn hóa cơ sở $a$ thành cơ sở trực chuẩn $b$.
  c) Tìm tọa độ $[v]_a$.
  d) Tìm tọa độ $[v]_b$.

### 2. Phương pháp làm bài

#### Câu a: Chứng minh $a$ là một cơ sở của $\mathbb{R}^3$
* Vì $\dim(\mathbb{R}^3) = 3$ và tập $a$ có đúng 3 véc tơ, nên chỉ cần chứng minh $a$ ĐLTT:
  * Lập ma trận $A_a$ có các dòng (hoặc cột) là tọa độ của $u_1, u_2, u_3$.
  * Tính $\det(A_a)$. Nếu $\det(A_a) \neq 0 \implies a$ độc lập tuyến tính.
  * Kết luận: $a$ là một cơ sở của $\mathbb{R}^3$.

#### Câu b: Trực chuẩn hóa cơ sở $a = \{u_1, u_2, u_3\}$ thành cơ sở trực chuẩn $b = \{e_1, e_2, e_3\}$
Sử dụng thuật toán **Gram-Schmidt**:
1. **Trực giao hóa (Tìm hệ trực giao $\{v_1, v_2, v_3\}$):**
   * $v_1 = u_1$
   * $v_2 = u_2 - \dfrac{\langle u_2, v_1 \rangle}{\|v_1\|^2} \cdot v_1$
   * $v_3 = u_3 - \dfrac{\langle u_3, v_1 \rangle}{\|v_1\|^2} \cdot v_1 - \dfrac{\langle u_3, v_2 \rangle}{\|v_2\|^2} \cdot v_2$
   *(Lưu ý: Tích vô hướng chuẩn trên $\mathbb{R}^3$ là $\langle X, Y \rangle = x_1 y_1 + x_2 y_2 + x_3 y_3$ và $\|v\|^2 = \langle v, v \rangle$).*

2. **Chuẩn hóa (Tìm hệ trực chuẩn $b = \{e_1, e_2, e_3\}$):**
   * $e_1 = \dfrac{v_1}{\|v_1\|}, \quad e_2 = \dfrac{v_2}{\|v_2\|}, \quad e_3 = \dfrac{v_3}{\|v_3\|}$

#### Câu c: Tìm tọa độ $[v]_a$
* Giải hệ phương trình tuyến tính: $v = c_1 u_1 + c_2 u_2 + c_3 u_3$ tìm bộ số $(c_1, c_2, c_3)$.
* Kết luận: $[v]_a = \begin{pmatrix} c_1 \\ c_2 \\ c_3 \end{pmatrix}$.

#### Câu d: Tìm tọa độ $[v]_b$ (Do $b$ là cơ sở trực chuẩn)
* Tính trực tiếp các tọa độ $k_i$ bằng tích vô hướng:
  $$k_1 = \langle v, e_1 \rangle, \quad k_2 = \langle v, e_2 \rangle, \quad k_3 = \langle v, e_3 \rangle$$
* Kết luận: $[v]_b = \begin{pmatrix} k_1 \\ k_2 \\ k_3 \end{pmatrix}$.

---

## CÂU 3: TRỰC CHUẨN HÓA GRAM-SCHMIDT TRONG $\mathbb{R}^4$ (2.0 - 2.5 điểm)

### 1. Dạng đề bài
Trên $V = \mathbb{R}^4$ với tích vô hướng $\langle \cdot \mid \cdot \rangle$, cho hệ độc lập tuyến tính $S = \{u_1, u_2, u_3\}$. Cho véc tơ $\lambda \in \mathbb{R}^4$.
* **Yêu cầu:**
  1. Dùng phương pháp Gram-Schmidt để trực chuẩn hóa hệ $S$.
  2. Tìm tọa độ của véc tơ $\lambda$ theo cơ sở vừa trực chuẩn hóa được.

### 2. Phương pháp làm bài

#### Bước 1: Trực giao hóa hệ $S = \{u_1, u_2, u_3\}$ thành hệ trực giao $S' = \{v_1, v_2, v_3\}$
* $v_1 = u_1$
* $v_2 = u_2 - \dfrac{\langle u_2, v_1 \rangle}{\|v_1\|^2} \cdot v_1$
* $v_3 = u_3 - \dfrac{\langle u_3, v_1 \rangle}{\|v_1\|^2} \cdot v_1 - \dfrac{\langle u_3, v_2 \rangle}{\|v_2\|^2} \cdot v_2$

#### Bước 2: Chuẩn hóa tìm hệ trực chuẩn $E = \{e_1, e_2, e_3\}$
* $e_1 = \dfrac{v_1}{\|v_1\|}, \quad e_2 = \dfrac{v_2}{\|v_2\|}, \quad e_3 = \dfrac{v_3}{\|v_3\|}$

#### Bước 3: Tìm tọa độ của $\lambda$ theo cơ sở $E$
* Vì $E$ là hệ trực chuẩn, tọa độ của $\lambda$ được tính nhanh bằng tích vô hướng:
  $$c_1 = \langle \lambda, e_1 \rangle, \quad c_2 = \langle \lambda, e_2 \rangle, \quad c_3 = \langle \lambda, e_3 \rangle$$
* Kết luận: $[\lambda]_E = \begin{pmatrix} c_1 \\ c_2 \\ c_3 \end{pmatrix}$.

---

## CÂU 4: CHÉO HÓA MA TRẬN VUÔNG CẤP 2 VÀ TÍNH LŨY THỪA $A^{2026}$ (2.0 - 2.5 điểm)

### 1. Dạng đề bài
Cho ma trận vuông thực cấp 2: $A = \begin{pmatrix} a & b \\ c & d \end{pmatrix}$.
* **Yêu cầu:** 
  1. Chéo hóa ma trận $A$.
  2. Tìm $A^m, \forall m \in \mathbb{N}$.
  3. Suy ra $A^{2026}$.

### 2. Phương pháp làm bài

#### Bước 1: Tìm trị riêng của $A$
* Lập đa thức đặc trưng:
  $$p_A(\lambda) = \det(A - \lambda I_2) = \det \begin{pmatrix} a - \lambda & b \\ c & d - \lambda \end{pmatrix} = \lambda^2 - (a+d)\lambda + (ad - bc)$$
* Giải $p_A(\lambda) = 0 \implies$ Tìm các trị riêng $\lambda_1, \lambda_2$.

#### Bước 2: Tìm các véc tơ riêng ứng với từng trị riêng
* **Với $\lambda_1$:** Giải hệ $(A - \lambda_1 I_2)X = O \implies$ Chọn 1 véc tơ riêng $u_1 \neq \mathbf{0}$.
* **Với $\lambda_2$:** Giải hệ $(A - \lambda_2 I_2)X = O \implies$ Chọn 1 véc tơ riêng $u_2 \neq \mathbf{0}$.

#### Bước 3: Lập ma trận làm chéo hóa $T$ và dạng chéo $D$
* Đặt $T = (u_1 \quad u_2) \implies \det(T) \neq 0$.
* Tính ma trận nghịch đảo $T^{-1} = \dfrac{1}{\det(T)} \begin{pmatrix} d_T & -b_T \\ -c_T & a_T \end{pmatrix}$.
* Dạng chéo: $D = T^{-1} A T = \begin{pmatrix} \lambda_1 & 0 \\ 0 & \lambda_2 \end{pmatrix}$.

#### Bước 4: Tính $A^m$ và suy ra $A^{2026}$
* Ta có $A = T D T^{-1} \implies A^m = T D^m T^{-1}$:
  $$A^m = T \begin{pmatrix} \lambda_1^m & 0 \\ 0 & \lambda_2^m \end{pmatrix} T^{-1}$$
* Thực hiện phép nhân ma trận để ra kết quả tổng quát của $A^m$.
* Thế $m = 2026$ vào biểu thức $A^m$ vừa tìm được để ra đáp số $A^{2026}$.