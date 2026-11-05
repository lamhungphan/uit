# ĐỀ THI MẪU 3

### **Câu 1 (2.5 điểm) (G3.1)**

Tuổi thọ của pin một loại điện thoại thông minh là biến ngẫu nhiên có phân phối chuẩn với trung bình là $8000$ giờ và độ lệch chuẩn là $500$ giờ. Những viên pin có tuổi thọ dưới $7000$ giờ bị coi là lỗi và phải thay mới miễn phí.

* **a)** Tìm tỷ lệ pin thay mới.

* **b)** Phải quy định thời gian bảo hành là bao nhiêu giờ để tỷ lệ pin lỗi chỉ chiếm $1\%$?

### **Câu 2 (2.5 điểm) (G3.1)**

Cho $X$ là biến ngẫu nhiên liên tục, có hàm mật độ xác suất:

$$
f(x) = \begin{cases} K(2x^2 + x), & x \in [0; 2] \\ 0, & x \notin [0; 2] \end{cases}
$$

* **a)** Hãy tìm hằng số $K$.

* **b)** Tìm $E(X)$ và $Var(X)$.

* **c)** Tính xác suất $P(1 < X < 1.5)$.

### **Câu 3 (3.0 điểm) (G3.1)**

Để khảo sát trọng lượng của sinh viên tại trường Đại học B, người ta chọn ngẫu nhiên 400 sinh viên và thu được bảng số liệu sau:

| Cân nặng (kg) | $45-50$ | $50-55$ | $55-60$ | $60-65$ | $65-70$ | $70-75$ | $75-80$ | 
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | 
| **Số sinh viên** | $35$ | $62$ | $88$ | $115$ | $70$ | $20$ | $10$ | 

* **a)** Tìm các giá trị: $\bar{x}$ và $s$.

* **b)** Hãy ước lượng khoảng tin cậy cho trọng lượng trung bình của sinh viên trường Đại học B với độ tin cậy $95\%$.

* **c)** Những sinh viên có trọng lượng từ $70 \text{ kg}$ trở lên được xếp vào nhóm "thể trọng cao". Có ý kiến cho rằng tỷ lệ sinh viên có thể trọng cao của trường này nhiều hơn $9\%$. Với mức ý nghĩa $\alpha = 0.05$, hãy cho biết ý kiến đó có đúng hay không?

### **Câu 4 (2.0 điểm) (G3.1)**

Doanh thu của một cửa hàng bán lẻ qua 8 năm hoạt động được ghi nhận như sau:

| Năm ($X$) | $2018$ | $2019$ | $2020$ | $2021$ | $2022$ | $2023$ | $2024$ | $2025$ | 
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | 
| **Doanh thu (**$Y$**) (tỷ)** | $12.5$ | $13.5$ | $14$ | $14.8$ | $15.5$ | $16.2$ | $17$ | $17.8$ | 

* **a)** Tìm hệ số tương quan giữa năm và doanh thu. Nêu nhận xét về mối tương quan này.

* **b)** Tìm phương trình hồi quy giữa doanh thu theo thời gian.

* **c)** Dựa vào câu b, hãy dự báo doanh thu của cửa hàng vào năm $2027$.

---

# BÀI GIẢI

### Câu 2

#### **a) Tìm hằng số $K$**

Do $f(x)$ là hàm mật độ xác suất nên phải thỏa mãn điều kiện:

$$\int_{-\infty}^{+\infty} f(x) \, dx = 1$$

Thay hàm $f(x)$ vào tích phân:

$$\int_{0}^{2} K(2x^2 + x) \, dx = 1$$

$$K \cdot \left[ \frac{2x^3}{3} + \frac{x^2}{2} \right]_0^2 = 1$$

$$K \cdot \left( \left( \frac{2 \cdot 2^3}{3} + \frac{2^2}{2} \right) - 0 \right) = 1$$

$$K \cdot \left( \frac{16}{3} + 2 \right) = 1$$

$$K \cdot \frac{22}{3} = 1 \implies \mathbf{K = \frac{3}{22}}$$

Hàm mật độ xác suất đầy đủ là:

$$f(x) = \begin{cases} \frac{3}{22}(2x^2 + x), & x \in [0, 2] \\ 0, & x \notin [0, 2] \end{cases}$$

#### **b) Tìm $E(X)$ và $Var(X)$**

* **Kỳ vọng $E(X)$:**

$$E(X) = \int_{-\infty}^{+\infty} x \cdot f(x) \, dx = \int_{0}^{2} x \cdot \frac{3}{22}(2x^2 + x) \, dx$$


$$E(X) = \frac{3}{22} \int_{0}^{2} (2x^3 + x^2) \, dx$$

$$E(X) = \frac{3}{22} \left[ \frac{2x^4}{4} + \frac{x^3}{3} \right]_0^2 = \frac{3}{22} \left[ \frac{x^4}{2} + \frac{x^3}{3} \right]_0^2$$

$$E(X) = \frac{3}{22} \cdot \left( \frac{16}{2} + \frac{8}{3} \right) = \frac{3}{22} \cdot \left( 8 + \frac{8}{3} \right) = \frac{3}{22} \cdot \frac{32}{3} = \mathbf{\frac{16}{11}} \approx 1,4545$$

* **Phương sai $Var(X)$:**
Trước tiên, tính $E(X^2)$:

$$E(X^2) = \int_{-\infty}^{+\infty} x^2 \cdot f(x) \, dx = \int_{0}^{2} x^2 \cdot \frac{3}{22}(2x^2 + x) \, dx$$


$$E(X^2) = \frac{3}{22} \int_{0}^{2} (2x^4 + x^3) \, dx$$

$$E(X^2) = \frac{3}{22} \left[ \frac{2x^5}{5} + \frac{x^4}{4} \right]_0^2 = \frac{3}{22} \cdot \left( \frac{64}{5} + \frac{16}{4} \right)$$

$$E(X^2) = \frac{3}{22} \cdot \left( \frac{64}{5} + 4 \right) = \frac{3}{22} \cdot \frac{84}{5} = \frac{126}{55}$$

Áp dụng công thức phương sai $Var(X) = E(X^2) - [E(X)]^2$:


$$Var(X) = \frac{126}{55} - \left(\frac{16}{11}\right)^2 = \frac{126}{55} - \frac{256}{121}$$

Quy đồng mẫu số ($55 \times 11 = 605$):


$$Var(X) = \frac{1386 - 1280}{605} = \mathbf{\frac{106}{605}} \approx 0,1752$$

#### **c) Tính xác suất $P(1 < X < 1,5)$**

$$P(1 < X < 1,5) = \int_{1}^{1,5} f(x) \, dx = \int_{1}^{1,5} \frac{3}{22}(2x^2 + x) \, dx$$

$$P(1 < X < 1,5) = \frac{3}{22} \left[ \frac{2x^3}{3} + \frac{x^2}{2} \right]_1^{1,5}$$

* Tại $x = 1,5 = \frac{3}{2}$:

$$\frac{2 \cdot (1,5)^3}{3} + \frac{(1,5)^2}{2} = \frac{2 \cdot 3,375}{3} + \frac{2,25}{2} = 2,25 + 1,125 = 3,375 = \frac{27}{8}$$

* Tại $x = 1$:

$$\frac{2 \cdot 1^3}{3} + \frac{1^2}{2} = \frac{2}{3} + \frac{1}{2} = \frac{7}{6}$$

Thế vào tích phân:
$$P(1 < X < 1,5) = \frac{3}{22} \cdot \left( \frac{27}{8} - \frac{7}{6} \right) = \frac{3}{22} \cdot \frac{53}{24} = \mathbf{\frac{53}{176}} \approx 0,3011$$