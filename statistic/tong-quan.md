# Tổng quan môn Xác suất và Thống kê

## 1. Xác suất và thống kê là gì?

- Xác suất học nghiên cứu khả năng xảy ra của các biến cố ngẫu nhiên.
- Thống kê học nghiên cứu cách thu thập, mô tả, phân tích và suy luận từ dữ liệu.

Nói ngắn gọn:
- Xác suất: "dự đoán khả năng xảy ra"
- Thống kê: "rút ra kết luận từ dữ liệu thực tế"

Ví dụ:
- Xác suất: Khi tung một đồng xu, xác suất ra mặt ngửa là $\frac{1}{2}$.
- Thống kê: Trong 1000 người khảo sát, 620 người thích sản phẩm A, nên tỉ lệ thích sản phẩm A là
  $$
  \frac{620}{1000} = 0.62 = 62\%
  $$

---

## 2. Không gian mẫu và biến cố

### 2.1. Không gian mẫu
Một thí nghiệm ngẫu nhiên có tập hợp tất cả các kết quả có thể xảy ra gọi là không gian mẫu, ký hiệu là $\Omega$.

Ví dụ 1: Tung một đồng xu
$$
\Omega = \{S, N\}
$$
trong đó $S$ là mặt sấp, $N$ là mặt ngửa.

Ví dụ 2: Tung một con xúc xắc
$$
\Omega = \{1, 2, 3, 4, 5, 6\}
$$

### 2.2. Biến cố
Một biến cố là tập con của không gian mẫu.

Ví dụ: Tung xúc xắc, biến cố "ra số chẵn" là
$$
A = \{2, 4, 6\}
$$

Các loại biến cố:
- Biến cố đơn giản: chỉ gồm một kết quả
- Biến cố phức hợp: gồm nhiều kết quả
- Biến cố chắc chắn: xảy ra với xác suất $1$
- Biến cố không thể: xảy ra với xác suất $0$

---

## 3. Xác suất của biến cố

Xác suất của biến cố $A$, ký hiệu $P(A)$, là xác suất mà biến cố đó xảy ra.

### 3.1. Tính chất cơ bản

1. $0 \le P(A) \le 1$
2. $P(\Omega) = 1$
3. $P(\varnothing) = 0$
4. Nếu $A$ và $B$ xung khắc (không thể xảy ra cùng lúc), thì:
   $$
   P(A \cup B) = P(A) + P(B)
   $$

### 3.2. Xác suất bằng tỉ lệ

Khi số lần thử lớn, xác suất gần bằng tần suất tương đối:

$$
P(A) \approx \frac{\text{số lần } A \text{ xảy ra}}{\text{tổng số lần thử}}
$$

---

## 4. Quy tắc cộng và quy tắc nhân

### 4.1. Quy tắc cộng
Nếu $A$ và $B$ là hai biến cố bất kỳ, thì:

$$
P(A \cup B) = P(A) + P(B) - P(A \cap B)
$$

Đây là công thức tránh trùng lặp khi hai biến cố có thể xảy ra đồng thời.

### 4.2. Quy tắc nhân
Nếu $A$ và $B$ là độc lập, thì:

$$
P(A \cap B) = P(A) \cdot P(B)
$$

Hai biến cố độc lập nghĩa là xảy ra của biến cố này không ảnh hưởng đến xác suất của biến cố kia.

Ví dụ: Tung hai đồng xu độc lập. Xác suất để cả hai đồng xu ra mặt ngửa là
$$
P(\text{2 mặt ngửa}) = P(N) \cdot P(N) = \frac{1}{2} \cdot \frac{1}{2} = \frac{1}{4}
$$

Ví dụ mở rộng: Nếu $A$ là "mặt ngửa ở đồng xu thứ nhất" và $B$ là "mặt ngửa ở đồng xu thứ hai", thì:
$$
P(A \cap B) = P(A)P(B) = \frac{1}{2}\cdot\frac{1}{2}=\frac{1}{4}
$$

---

## 5. Biến ngẫu nhiên

Biến ngẫu nhiên là biến nhận giá trị theo xác suất.

Có hai loại chính:

### 5.1. Biến ngẫu nhiên rời rạc
Lấy các giá trị đếm được, ví dụ:
- số lượng khách đến cửa hàng trong 1 giờ
- số mặt ngửa khi tung 3 đồng xu

Ví dụ: Số mặt ngửa khi tung 3 đồng xu có thể là
$$
X \in \{0,1,2,3\}
$$

### 5.2. Biến ngẫu nhiên liên tục
Lấy giá trị trong một khoảng, ví dụ:
- chiều cao của sinh viên
- thời gian chờ của khách hàng

Ví dụ: Chiều cao của một sinh viên có thể nằm trong khoảng
$$
X \in [150, 190]
$$
(đơn vị cm)

---

## 6. Kỳ vọng và phương sai

### 6.1. Kỳ vọng (Expected value)
Kỳ vọng của biến ngẫu nhiên $X$, ký hiệu $E(X)$, là giá trị trung bình mong đợi nếu thử nghiệm được lặp lại nhiều lần.

$$
E(X) = \sum x_i P(X = x_i)
$$

với biến ngẫu nhiên rời rạc.

Ví dụ: Tung một con xúc xắc, giá trị của $X$ có thể là $1,2,3,4,5,6$. Khi đó:
$$
E(X) = \frac{1+2+3+4+5+6}{6} = \frac{21}{6} = 3.5
$$

Nghĩa là, nếu tung xúc xắc nhiều lần, giá trị trung bình mong đợi sẽ xấp xỉ $3.5$.

### 6.2. Phương sai (Variance)
Phương sai đo mức độ phân tán quanh giá trị trung bình.

$$
Var(X) = E[(X - E(X))^2]
$$

Một cách tương đương:

$$
Var(X) = E(X^2) - [E(X)]^2
$$

- Phương sai lớn $\Rightarrow$ dữ liệu phân tán mạnh
- Phương sai nhỏ $\Rightarrow$ dữ liệu tập trung quanh trung bình

---

## 7. Độ lệch chuẩn

Độ lệch chuẩn là căn bậc hai của phương sai:

$$
\sigma = \sqrt{Var(X)}
$$

Nó cho biết mức độ dao động của dữ liệu so với giá trị trung bình.

---

## 8. Dữ liệu thống kê và các khái niệm quan trọng

### 8.1. Dân số (Population)
Tập hợp toàn bộ các đơn vị cần nghiên cứu.

Ví dụ:
- toàn bộ sinh viên của trường
- toàn bộ sản phẩm trong lô hàng

### 8.2. Mẫu (Sample)
Một tập con lấy từ dân số để nghiên cứu.

Ví dụ: Một lớp có 500 sinh viên, ta chọn ngẫu nhiên 200 sinh viên để khảo sát thái độ về môn học. Tập 200 sinh viên đó là một mẫu.

### 8.3. Thống kê mô tả
Mô tả dữ liệu bằng các số như:
- trung bình
- trung vị
- tần suất
- phương sai
- độ lệch chuẩn

### 8.4. Thống kê suy luận
Dùng dữ liệu mẫu để suy luận về dân số.

Ví dụ: Từ mẫu 100 người, có 60 người thích món A. Ta suy ra tỉ lệ thích món A trong mẫu là $60\%$. Từ đó, có thể suy luận về tỷ lệ tương tự trong dân số lớn hơn.

---

## 9. Một số đại lượng thống kê cơ bản

### 9.1. Trung bình cộng
$$
\bar{x} = \frac{1}{n} \sum_{i=1}^{n} x_i
$$

### 9.2. Trung vị
Là giá trị ở giữa khi sắp xếp dữ liệu theo thứ tự tăng dần.

### 9.3. Mốt
Giá trị xuất hiện nhiều nhất trong dữ liệu.

### 9.4. Tần suất
Số lần một giá trị xuất hiện.

### 9.5. Tần suất tương đối
$$
\frac{\text{số lần xuất hiện}}{\text{tổng số quan sát}}
$$

---

## 10. Mối quan hệ giữa xác suất và thống kê

- Xác suất bắt đầu từ mô hình lý thuyết để suy ra khả năng xảy ra.
- Thống kê bắt đầu từ dữ liệu thực tế để ước lượng và kiểm định mô hình.

Nói cách khác:
- Xác suất giúp xây dựng lý thuyết.
- Thống kê giúp kiểm chứng và ứng dụng vào thực tế.

---

## 11. Cách học hiệu quả cho buổi 1

Bạn không cần nhớ ngay hết các công thức khó. Hãy ưu tiên nắm chắc 5 ý chính sau:

1. Không gian mẫu là tập hợp tất cả kết quả có thể xảy ra.
2. Biến cố là tập con của không gian mẫu.
3. Xác suất luôn nằm trong khoảng $[0,1]$.
4. Kỳ vọng là giá trị trung bình mong đợi.
5. Phương sai và độ lệch chuẩn đo mức độ phân tán của dữ liệu.

---

## 12. Tóm tắt ngắn gọn

- $\Omega$: không gian mẫu
- $A$: biến cố
- $P(A)$: xác suất của biến cố $A$
- $E(X)$: kỳ vọng của biến ngẫu nhiên $X$
- $Var(X)$: phương sai
- $\sigma$: độ lệch chuẩn
