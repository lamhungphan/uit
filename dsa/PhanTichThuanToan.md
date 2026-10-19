## Thuật Toán (Algorithm)
- Một chuỗi các bước tính toán được định nghĩa rõ ràng để giải quyết một vấn đề
- Nhận vào một tập các giá trị đầu vào
- Trả về một tập các giá trị đầu ra
- Biểu diễn bằng: mã nguồn, mã giả
- Tính đúng đắn (cần thiết): kết quả trả về phản ánh đúng mong muốn của thông tin nhận vào
- Tính hiệu quả (quan trọng): độ tin cậy, tốc độ xử lý, tài nguyên sử dụng

## Đánh Giá Thuật Toán (Algorithm Evaluation)
- Một vấn đề giải quyết bởi thuật toán khác nhau
- Với mỗi thuật toán
    - Thời gian: thời gian chạy của thuật toán
    - Không gian: dung lượng bộ nhớ sử dụng
- Thời gian chạy
    - Dữ liệu đầu vào
    - Kĩ năng lập trình
    - Chương trình dịch, hệ điều hành
    - Tốc độ phép toán trên máy tính

## Thời Gian Chạy (Running Time)

- **Phụ thuộc vào độ lớn dữ liệu đầu vào:**
    - Tìm một phần tử trong danh sách n phần tử
    - Sắp xếp danh sách n phần tử
    - Bài toán người giao hàng cần thăm n điểm
- **Với dữ liệu cùng độ lớn, thời gian thay đổi:**
    - Tìm một phần tử trong danh sách n phần tử:
        - Phần tử nằm ở đầu danh sách
        - Phần tử nằm ở cuối danh sách
        - Phần tử nằm ở giữa danh sách

- **Phân tích thực nghiệm**
    - Đo thời gian chạy thực, vẽ đồ thị, …
    - Có kịch bản tiến hành thực nghiệm
    - Cần cài đặt thuật toán (khó, lâu)
    - Đôi khi không thể chạy hết các bộ dữ liệu
    - Để so sánh các thuật toán, phải sử dụng cùng môi trường (phần cứng & phần mềm)
    - Phù hợp cho dự đoán

- **Phân tích toán học**
    - Ước lượng số phép toán là hàm của độ lớn dữ liệu đầu vào
    - Thông thường thông qua sử dụng mã giả
    - Xét tất cả các bộ dữ liệu đầu vào
    - Không phụ thuộc môi trường tính toán
    - Phù hợp cho cả dự đoán và giải thích
    - Thường được sử dụng để đánh giá

- **Trường hợp xấu nhất (thông thường)**
    - Thời gian chạy lớn nhất của thuật toán trên tất cả các dữ liệu có cùng độ lớn
- **Trường hợp trung bình (đôi khi)**
    - Thời gian chạy trung bình của thuật toán trên tất cả các dữ liệu có cùng độ lớn
        - Khó: do phải biết phân phối xác suất của dữ liệu
- **Trường hợp tốt nhất (hiếm)**
    - Thời gian chạy ít nhất của thuật toán trên tất cả các dữ liệu có cùng độ lớn

## Mã Giả (Pseudocode)

- Mô tả bậc cao của một thuật toán
- Cấu trúc rõ ràng hơn văn xuôi
- Không chi tiết như mã nguồn
- Được ưa thích trong biểu diễn giải thuật
- Ẩn đi các khía cạnh thiết kế chương trình

```cpp
Algorithm arraySum(A,n):
Input: mảng A (n số nguyên)
Output: tổng các phần tử của A
sum ← 0;
for i ← 0 to n−1 do
sum ← sum + A[i];
return currentMax;
```

## Phân Tích Độ Phức Tạp Thời Gian (Time Complexity Analysis)
- Đánh giá thời gian chạy thuật toán
- $T(n)$ = số lượng phép toán sơ cấp cần thực hiện (số học, lô-gic, so sánh)
- Mỗi phép toán sơ cấp thực hiện trong khoảng thời gian cố định
- Chỉ quan tâm tới tốc độ tăng của hàm $T(n)$
- Ví dụ: $T(n) = 2n^2 + 3n + 10$

```cpp
Algorithm arraySum(A,n):
Input: mảng A (n số nguyên)
Output: tổng các phần tử của A
sum ← 0;
for i ← 0 to n−1 do
sum ← sum + A[i];
return sum;
```

## Phân Tích Độ Phức Tạp Không Gian (Space Complexity Analysis)
- Đánh giá bộ nhớ sử dụng bởi thuật toán
- $S(n)$ = tổng dung lượng bộ nhớ cần thiết (biến, cấu trúc dữ liệu, ngăn xếp đệ quy)
- Bao gồm:
    - **Không gian cố định (Fixed Space):** mã chương trình, biến cục bộ đơn giản, hằng số — $O(1)$
    - **Không gian biến đổi (Variable Space):** mảng động, cấu trúc dữ liệu, ngăn xếp gọi đệ quy — phụ thuộc $n$
- Chỉ quan tâm tới tốc độ tăng của hàm $S(n)$
- Ví dụ: $S(n) = n^2 + 2n + 10$ (ma trận $n \times n$)

```cpp
Algorithm arraySum(A,n):
Input: mảng A (n số nguyên)
Output: tổng các phần tử của A
sum ← 0;           // O(1)
for i ← 0 to n−1 do
    sum ← sum + A[i];  // A[] là input, không tính thêm
return sum;        // Tổng S(n) = O(1)
```

```cpp
Algorithm matrixMultiply(A,B,n):
Input: ma trận A, B kích thước n×n
Output: ma trận C = A × B
C ← new matrix[n][n];  // O(n²)
for i ← 0 to n−1 do
    for j ← 0 to n−1 do
        C[i][j] ← 0;
        for k ← 0 to n−1 do
            C[i][j] ← C[i][j] + A[i][k] * B[k][j];
return C;              // Tổng S(n) = O(n²)
```

## Độ Tăng Của Hàm (Function Growth Rate)
- Với $n$ là độ lớn dữ liệu đầu vào
- **Tỷ lệ tăng trưởng (chính xác):**
    - $an^2 + bn + c$
    - $an + b$
    - $an \log n + bn + c$
- **Bậc tăng trưởng (xấp xỉ):**
    - $an^2 + bn + c \Rightarrow$ bậc $n^2$
    - $an + b \Rightarrow$ bậc $n$
    - $an \log n + bn + c \Rightarrow$ bậc $n \log n$

## Ký Hiệu Tiệm Cận (Big-O Notation)
- $O$ Big-O (chặn trên / Upper Bound):
    - **Ý nghĩa:** $f(n)$ không tăng nhanh hơn $g(n)$ khi $n$ đủ lớn.
    - **Định nghĩa:** $f(n) \in O(g(n))$ nếu tồn tại $c > 0$, $n_0 > 0$ sao cho:
      $$0 \le f(n) \le c \cdot g(n) \quad \forall n \ge n_0$$
    - **Giải thích:**
        - $g(n)$: hàm chặn trên — đường chạy **bên trên** $f(n)$
        - $c$: hệ số nhân — cho phép co giãn dọc
        - $n_0$: ngưỡng — chỉ xét $n$ đủ lớn (bỏ qua hằng số nhỏ)
    - **Ký hiệu:** $f(n) \in O(g(n))$
    - **Ví dụ:** $2n^2 + 3n + 10 \in O(n^2)$ vì $2n^2 + 3n + 10 \le 3n^2$ khi $n \ge 4$
    - **Ví dụ loose bound:** $2n^2 \in O(n^3)$ — đúng nhưng không chặt
    - **Sai:** $2n^2 \in O(n)$ — vì $n^2$ tăng nhanh hơn $n$
    - *Lưu ý:* $O(g(n))$ là một **tập các hàm**, không phải một giá trị đơn lẻ.

### Giải thích thuật ngữ "Tiệm cận" (Asymptotic) — Tiệm cận cái gì với cái gì?

| Thuật ngữ | Ý nghĩa thực tế |
|-----------|-----------------|
| **Tiệm cận** (Asymptotic) | Xét hành vi khi $n \to \infty$ (dữ liệu đủ lớn) |
| **$T(n)$** | Thời gian chạy **thực tế** của thuật toán (hàm chính xác) |
| **$g(n)$** | Hàm **đơn giản** dùng để so sánh (ví dụ: $n^2$, $n \log n$) |
| **$O(g(n))$** | **Tập hợp** tất cả hàm không tăng nhanh hơn $g(n)$ |

**Mối quan hệ:**
```
Thuật toán → T(n) (thực tế, phức tạp) 
                ↓ "tiệm cận" (khi n → ∞)
           g(n) (đơn giản, dễ hiểu)
                ↓
           O(g(n)) (ký hiệu: T(n) thuộc tập này)
```

**Ví dụ:**
- Thuật toán `arraySum`: $T(n) = 4n + 2$
- Khi $n \to \infty$: hạng tử $4n$ chiếm ưu thế, $+2$ có thể bỏ qua
- Chọn $g(n) = n$ (hàm đơn giản cùng cấp độ)
- Viết: $T(n) \in O(n)$ — đọc: *"T(n) tiệm cận tuyến tính"* hoặc *"thuộc O(n)"*

**Tóm lại:** "Tiệm cận" ở đây nghĩa là **hành vi khi n đủ lớn**. $T(n)$ **tiệm cận** $g(n)$ = tỷ số $T(n)/g(n)$ tiến tới một hằng số khi $n \to \infty$.

## Ký Hiệu O Biểu Diễn Thời Gian Chạy (Big-O for Running Time)
- Lấy cận trên chặt biểu diễn thời gian chạy của thuật toán
- $f(n)$ là cận trên chặt của $T(n)$ nếu:
    - $T(n) \in O(f(n))$, và
    - Nếu $T(n) \in O(g(n))$ thì $f(n) \in O(g(n))$
- Nói cách khác: Không thể tìm được một hàm $g(n)$ là cận trên của $T(n)$ mà tăng chậm hơn hàm $f(n)$.

## Cấp Độ Thời Gian Chạy (Time Complexity Classes)

| Ký hiệu ô lớn | Tên gọi |
| :--- | :--- |
| $O(1)$ | Hằng |
| $O(\log n)$ | Logarit |
| $O(n)$ | Tuyến tính |
| $O(n \log n)$ | nlogn |
| $O(n^2)$ | Bình phương |
| $O(n^3)$ | Lập phương |
| $O(2^n)$ | Mũ |
| $O(n!)$ | Giai thừa |

## Phân Tích Tiệm Cận Thuật Toán (Algorithm Asymptotic Analysis)
- Xác định thời gian chạy sử dụng ký hiệu $O$
- Tìm số lần các phép toán sơ cấp thực hiện nhiều nhất là hàm của độ lớn dữ liệu đầu vào
- Miêu tả hàm này theo ký hiệu $O$
- **Ví dụ:**
    - Thuật toán `arraySum(A,n)` chạy nhiều nhất $(4n+2)$ phép toán sơ cấp.
    - Ta nói thuật toán `arraySum(A,n)` chạy trong thời gian $O(n)$.

## Kỹ Thuật Đánh Giá Thời Gian Chạy (Running Time Evaluation Techniques)
- Thời gian chạy các lệnh:
    - Gán
    - Lựa chọn
    - Lặp
- Không đệ quy so với đệ quy

## Thời Gian Chạy Của Các Lệnh (Running Time of Statements)
- **Lệnh gán:**
    - $X =$ `<biểu thức>`
    - Thời gian chạy của lệnh gán bằng thời gian thực hiện biểu thức.
- **Lệnh lựa chọn:**
    - `if (điều kiện)` $\rightarrow T_0(n)$
    - `lệnh 1` $\rightarrow T_1(n)$
    - `else`
    - `lệnh 2` $\rightarrow T_2(n)$
    - Thời gian: $T_0(n) + \max(T_1(n), T_2(n))$ *(hoặc ước lượng với trường hợp tương ứng)*
- **Lệnh lặp (for, while, do-while):**
    - $\sum_{i=1}^{X(n)} (T_0(n) + T_i(n))$
    - $X(n)$: số vòng lặp
    - $T_0(n)$: kiểm tra điều kiện lặp
    - $T_i(n)$: thời gian thực hiện vòng lặp thứ $i$

## Phân Tích Hàm Đệ Quy (Recursive Function Analysis)
- Định nghĩa đệ quy có 2 phần:
    - **Phần cơ sở:** định nghĩa một số phần tử đầu tiên trong chuỗi
    - **Phần đệ quy**
- **Ví dụ:** Thời gian tính hàm giai thừa:
    - $T(1) \in O(1)$
    - $T(n) = T(n-1) + O(1)$ với $n > 1$

## Bài Tập (Exercises)

**Bài tập 1:**
```cpp
1 for (i = 0; i < n; i++)
2     for (j = 0; j < n; j++)
3         a[i][j] = 0;
4 for (i = 0; i < n; i++)
5     a[i][j] = 1;
```
Phân tích độ phức tạp
- $T_3 = O(1)$
- $T_2 = O(n) \Rightarrow T_{23} = O(n) \times O(1) = O(n)$
- $T_1 = O(n) \Rightarrow T_{123} = O(n) \times O(n) = O(n^2)$
- $T_5 = O(1)$
- $T_4 = O(n) \Rightarrow T_{45} = O(n) \times O(1) = O(n)$
- $T_{12345} = T_{123} + T_{45} = O(n^2) + O(n) = O(n^2 + n) = O(n^2)$   

**Bài tập 2:**
```cpp
1 for (i = 0; i < n; i++)
2     for (j = 0; j < n; j++)
3         if (i == j)
4             a[i][j] = 1;
5         else
6             a[i][j] = 0;
```
Phân tích độ phức tạp
- $T_3 = O(1)$ 
- $T_4 = O(1)$
- $T_6 = O(1) \Rightarrow T_{3456} = O(1)$
- $T_2 = O(n) \Rightarrow T_{23456} = O(n) \times O(1) = O(n)$
- $T_1 = O(n)$
- $T_{123456} = O(n) \times O(n) = O(n^2)$

**Bài tập 3:**
```cpp
1 for (i = 0; i < n; i++)
2     for (j = 0; j < n; j++)
3         a[i][j] = 0;
4 for (i = 0; i < n; i++)
5     a[i][j] = 1;
```
Phân tích độ phức tạp: 
- $T_3 = O(1)$ 
- $T_2 = O(n)$
- $T_{23} = O(n) \times O(1) = O(n)$
- $T_1 = O(n)$
- $T_{123} = O(n) \times O(n) = O(n^2)$
- $T_5 = O(1)$
- $T_4 = O(n)$
- $T_{45} = O(n) \times O(1) = O(n)$
- $T_{12345} = T_{123} + T_{45} = O(n^2) + O(n) = O(n^2 + n) = O(n^2)$

**Bài tập 4:**
```cpp
1 sum = 0
2 for (i = 0; i < n; i++)
3     for (j = i + 1; j <= n; j++)
4         for (k = 1; k < 10; k++)
5             sum = sum + i * j * k;
```

**Bài tập 5:**
```cpp
1 sum = 0
2 for (i = 0; i < n; i++)
3     for (j = i + 1; j <= n; j++)
4         for (k = 1; k < m; k++) {
5             x = 2 * y
6             sum = sum + i * j * k;
7         }
```

**Bài tập 6:**
```cpp
1 sum = 0
2 thisSum = 0
3 for (i = 0; i < n; i++) {
4     thisSum += a[i];
5     if (thisSum > sum)
6         sum = thisSum;
7     else
8         thisSum = sum;
9 }
```