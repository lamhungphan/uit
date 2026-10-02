# BỘ TÀI LIỆU ÔN THI MÔN HỆ ĐIỀU HÀNH (IT007)

## PHẦN 1: BÀI TẬP TRẮC NGHIỆM (20 CÂU)

---

### 🔹 CÂU 1
**Đề bài:** Phát biểu nào sau đây là ĐÚNG khi nói về binary semaphore?
- **A.** Binary semaphore chỉ nhận các giá trị nguyên lớn hơn hoặc bằng 0
- **B.** Binary semaphore thường được sử dụng để đảm bảo điều kiện Progress khi đồng bộ
- **C.** Binary semaphore chỉ nhận giá trị 0 hoặc 1 và thường được dùng cho mục đích đồng bộ hóa
- **D.** Binary semaphore thường được sử dụng để quản lý số lượng tài nguyên giới hạn

**💡 Kiến thức cần biết:**
- Binary semaphore chỉ có giá trị **0** hoặc **1**.
- Dùng để đồng bộ hóa và bảo vệ critical section.

**✏️ Lời giải chi tiết:**
- Chỉ có `0` và `1` là hợp lệ cho binary semaphore.
- Do đó đáp án đúng là **C**.

👉 **Đáp án đúng: C. Binary semaphore chỉ nhận giá trị 0 hoặc 1 và thường được dùng cho mục đích đồng bộ hóa**

---

### 🔹 CÂU 2
**Đề bài:** Để cài đặt bộ nhớ ảo, hệ thống cần phải đảm bảo điều kiện nào sau đây?
- **A.** Hệ điều hành phải quản lý sự di chuyển của trang giữa bộ nhớ chính và bộ nhớ thứ cấp
- **B.** Phần cứng quản lý bộ nhớ phải hỗ trợ cơ chế phân trang
- **C.** Tất cả đều đúng

**💡 Kiến thức cần biết:**
- Bộ nhớ ảo cần có **hệ điều hành và phần cứng** cùng hỗ trợ.

**✏️ Lời giải chi tiết:**
- Hệ điều hành phải xử lý swap/page fault.
- Phần cứng phải có cơ chế phân trang và địa chỉ ảo/ vật lý.
- Vậy cả A và B đều cần thiết.

👉 **Đáp án đúng: C. Tất cả đều đúng**

---

### 🔹 CÂU 3
**Đề bài:** Cho bảng trang (trang $\rightarrow$ khung): 

0 $\rightarrow$ 1

1 $\rightarrow$ 6

2 $\rightarrow$ 3

3 $\rightarrow$ 4

Biết kích thước khung trang là 1KB, hỏi địa chỉ vật lý 4567 là ánh xạ của địa chỉ luận lý nào sau đây?
- **A.** 3543
- **B.** 471
- **C.** 2519
- **D.** 1496

**💡 Kiến thức cần biết:**
- Địa chỉ vật lý: $(\text{frame} \times 1024) + \text{offset}$
- Địa chỉ luận lý: $(\text{page} \times 1024) + \text{offset}$

**✏️ Lời giải chi tiết:**
- Với địa chỉ vật lý 4567, ta tìm khung: $4567 \div 1024 = 4$ dư $471$.
- Khung 4 tương ứng với page 3 theo bảng trang: $3 \rightarrow 4$.
- Vậy địa chỉ luận lý là: $(3 \times 1024) + 471 = 3072 + 471 = 3543$.

👉 **Đáp án đúng: A. 3543**

---

### 🔹 CÂU 4
**Đề bài:** Critical section trong hệ điều hành là gì?
- **A.** Vùng nhớ chứa dữ liệu được chia sẻ bởi hai hay nhiều tiến trình
- **B.** Vùng code tác động hoặc truy cập dữ liệu được chia sẻ giữa hai hay nhiều tiến trình
- **C.** Vùng code được dùng chung bởi hai hay nhiều tiến trình
- **D.** Data section được cấp phát chung cho hai hay nhiều tiến trình

**💡 Kiến thức cần biết:**
- Critical section là phần code truy cập dữ liệu chia sẻ.

**✏️ Lời giải chi tiết:**
- Không phải mọi vùng code dùng chung, mà là phần code **truy cập dữ liệu chia sẻ**.

👉 **Đáp án đúng: B. Vùng code tác động hoặc truy cập dữ liệu được chia sẻ giữa hai hay nhiều tiến trình**

---

### 🔹 CÂU 5
**Đề bài:** Cho các tính chất sau:
1. Khi một tiến trình P đang thực thi trong vùng tranh chấp của nó thì không có tiến trình Q nào khác đang thực thi trong vùng tranh chấp của Q.
2. Tất cả các tiến trình phải được đối xử như nhau.
3. Một tiến trình tạm dừng bên ngoài critical section không được ngăn cản các tiến trình khác vào critical section.
4. Mỗi tiến trình chỉ phải chờ để được vào vùng tranh chấp trong một khoảng thời gian có hạn định nào đó.

Lời giải dành cho vấn đề vùng tranh chấp cần phải thỏa mãn các tính chất nào trong các tính chất trên?
- **A.** (1), (2), (4)
- **B.** (2), (3), (4)
- **C.** (1), (3), (4)
- **D.** (1), (2), (3), (4)

**💡 Kiến thức cần biết:**
- Các tính chất cần thiết của critical section: Mutual exclusion, Progress, Bounded waiting.

**✏️ Lời giải chi tiết:**
- Tính chất 2 là **Fairness** nhưng không phải là điều kiện bắt buộc ngay trong định nghĩa gốc.
- Các điều kiện bắt buộc thường là: (1), (3), (4).

👉 **Đáp án đúng: C. (1), (3), (4)**

---

### 🔹 CÂU 6
**Đề bài:** Trong hệ điều hành, mục tiêu của quản lý bộ nhớ cần đạt được là gì?
- **A.** Đảm bảo việc truyền dữ liệu giữa các thiết bị ngoại vi và bộ nhớ chính được ổn định
- **B.** Duy trì tốc độ đọc - ghi dữ liệu liên tục
- **C.** Gia tăng mức độ đa chương của hệ thống
- **D.** Tăng tốc độ xử lý của CPU bằng cách giảm thời gian chờ đợi

**💡 Kiến thức cần biết:**
- Quản lý bộ nhớ nhằm tăng hiệu quả sử dụng bộ nhớ và giảm thời gian chờ CPU.

**✏️ Lời giải chi tiết:**
- Giảm thời gian chờ CPU bằng cách cho phép nhiều tiến trình cùng lưu trú hợp lý trong RAM là mục tiêu cốt lõi.

👉 **Đáp án đúng: D. Tăng tốc độ xử lý của CPU bằng cách giảm thời gian chờ đợi**

---

### 🔹 CÂU 7
**Đề bài:** Bước nào sau đây KHÔNG có trong quy trình xử lý lỗi trang?
- **A.** Kiểm tra xem địa chỉ truy cập có hợp lệ hay không
- **B.** Nạp trang cần thiết từ bộ nhớ phụ (ví dụ: đĩa cứng) vào bộ nhớ chính
- **C.** Chuyển tiến trình về trạng thái Ready để tránh xảy ra lỗi
- **D.** Cập nhật bảng trang sau khi nạp trang thành công

**💡 Kiến thức cần biết:**
- Khi xảy ra page fault, tiến trình thường được **block** chờ nạp trang, không được chuyển ngay sang Ready.

**✏️ Lời giải chi tiết:**
- Hệ điều hành **không** chuyển tiến trình thẳng sang Ready ngay lập tức.
- Từng bước chuẩn là: kiểm tra hợp lệ → tìm/trích trang → nạp → cập nhật bảng trang → cho tiến trình tiếp tục.

👉 **Đáp án đúng: C. Chuyển tiến trình về trạng thái Ready để tránh xảy ra lỗi**

---

### 🔹 CÂU 8
**Đề bài:** Bộ nhớ ảo (virtual memory) là gì?
- **A.** Là bộ nhớ được tạo ra bằng cách ghép nhiều thanh RAM vật lý lại với nhau
- **B.** Là vùng bộ nhớ cache nằm giữa CPU và RAM để tăng tốc độ truy xuất
- **C.** Là kỹ thuật cho phép tiến trình sử dụng không gian địa chỉ lớn hơn bộ nhớ vật lý thực có
- **D.** Là vùng nhớ nằm trên ổ cứng dùng để lưu trữ vĩnh viễn các tập tin của hệ điều hành

**💡 Kiến thức cần biết:**
- Virtual memory cho phép tiến trình truy cập không gian địa chỉ lớn hơn RAM thật nhờ swap/page file.

👉 **Đáp án đúng: C. Là kỹ thuật cho phép tiến trình sử dụng không gian địa chỉ lớn hơn bộ nhớ vật lý thực có**

---

### 🔹 CÂU 9
**Đề bài:** Đặc điểm phân biệt địa chỉ tuyệt đối và địa chỉ tương đối trong quản lý bộ nhớ?
- **A.** Địa chỉ tuyệt đối được sử dụng bởi lập trình viên, còn địa chỉ tương đối chỉ dùng trong phần cứng
- **B.** Địa chỉ tuyệt đối được sử dụng trong thời gian biên dịch, còn địa chỉ tương đối được sử dụng trong thời gian chạy
- **C.** Địa chỉ tuyệt đối là địa chỉ thật trong bộ nhớ chính, còn địa chỉ tương đối là địa chỉ so với một điểm gốc (base)
- **D.** Không có sự khác biệt rõ ràng giữa địa chỉ tuyệt đối và địa chỉ tương đối

**💡 Kiến thức cần biết:**
- Địa chỉ tương đối = địa chỉ tính từ một điểm gốc, ví dụ base register.

👉 **Đáp án đúng: C. Địa chỉ tuyệt đối là địa chỉ thật trong bộ nhớ chính, còn địa chỉ tương đối là địa chỉ so với một điểm gốc (base)**

---

### 🔹 CÂU 10
**Đề bài:** Xét một không gian địa chỉ luận lý có 124 trang, mỗi trang có kích thước là 2MB. Như vậy ta cần bao nhiêu bit để biểu diễn cho một địa chỉ luận lý trong không gian này?
- **A.** 28 bit
- **B.** 25 bit
- **C.** 27 bit
- **D.** 26 bit

**✏️ Lời giải chi tiết:**
$$\lceil \log_2(124) \rceil = 7$$
$$\log_2(2\text{MB}) = \log_2(2^{21}) = 21$$
$$\text{Tổng} = 7 + 21 = 28\text{ bit}$$

👉 **Đáp án đúng: A. 28 bit**

---

### 🔹 CÂU 11
**Đề bài:** Khi tiến trình bị lỗi trang, hệ điều hành sẽ chuyển tiến trình về trạng thái nào?
- **A.** Trạng thái Ready
- **B.** Trạng thái Waiting
- **C.** Trạng thái Terminated
- **D.** Trạng thái New

**💡 Kiến thức cần biết:**
- Page fault làm tiến trình **chờ** để nạp trang vào RAM.

**✏️ Lời giải chi tiết:**
- Tiến trình được chuyển sang trạng thái chờ (Waiting/Blocked) cho đến khi page fault được xử lý.

👉 **Đáp án đúng: B. Trạng thái Waiting**

---

### 🔹 CÂU 12
**Đề bài:** Giải thuật thay thế trang OPT hoạt động như thế nào khi xảy ra lỗi trang?
- **A.** Thay thế trang có địa chỉ nhỏ nhất trong bộ nhớ
- **B.** Thay thế trang sẽ được sử dụng muộn nhất trong tương lai
- **C.** Thay thế trang được sử dụng nhiều nhất trong quá khứ
- **D.** Thay thế trang vừa mới được sử dụng gần nhất

**💡 Kiến thức cần biết:**
- OPT là thuật toán lý thuyết, thay trang **không được dùng lâu nhất** trong tương lai.

**✏️ Lời giải chi tiết:**
- Đây là bản chất của OPT.

👉 **Đáp án đúng: B. Thay thế trang sẽ được sử dụng muộn nhất trong tương lai**

---

### 🔹 CÂU 13
**Đề bài:** Xét một hệ thống sử dụng kỹ thuật phân trang, với bảng trang được lưu trữ trong bộ nhớ chính. Thời gian cho một lần truy xuất bộ nhớ bình thường là 300ns, nếu sử dụng TLBs với hit-ratio (tỉ lệ tìm thấy) là 85%, thời gian để tìm trong TLBs bằng 25ns, tính thời gian cho một thao tác truy xuất lệnh/dữ liệu trong hệ thống (effective access time - EAT)?
- **A.** 715 ns
- **B.** 370 ns
- **C.** 730 ns
- **D.** 197.5 ns

**💡 Kiến thức cần biết:**
$$\text{EAT} = \alpha(\epsilon + m) + (1-\alpha)(\epsilon + 2m)$$

**✏️ Lời giải chi tiết:**
- $\alpha = 0.85$, $\epsilon = 25$, $m = 300$
- Hit: $25 + 300 = 325$
- Miss: $25 + 300 + 300 = 625$
$$\text{EAT} = 0.85 \cdot 325 + 0.15 \cdot 625 = 276.25 + 93.75 = 370\text{ ns}$$

👉 **Đáp án đúng: B. 370 ns**

---

### 🔹 CÂU 14
**Đề bài:** Để tránh busy waiting khi hiện thực mutex, hệ điều hành cần cung cấp cơ chế nào?
- **A.** Wait và Signal
- **B.** Block và Wakeup
- **C.** Lock và Unlock
- **D.** Load và Store

**💡 Kiến thức cần biết:**
- Busy waiting là chờ vòng lặp liên tục; để tránh cần **block/wakeup**.

**✏️ Lời giải chi tiết:**
- Hệ điều hành dùng block/wakeup để cho tiến trình ngủ khi không thể vào critical section.

👉 **Đáp án đúng: B. Block và Wakeup**

---

### 🔹 CÂU 15
**Đề bài:** Phát biểu nào sau đây là đúng khi nói về dynamic loading (nạp động) trong hệ điều hành?
- **A.** Tất cả các đoạn chương trình đều được nạp vào bộ nhớ ngay khi chương trình bắt đầu thực thi
- **B.** Các đoạn chương trình được nạp vào bộ nhớ chính khi chúng được gọi đến trong quá trình thực thi
- **C.** Dynamic loading yêu cầu liên kết tất cả các thư viện tại thời điểm biên dịch
- **D.** Dynamic loading làm tăng kích thước file thực thi vì tất cả mã đều phải lưu sẵn trong file

**💡 Kiến thức cần biết:**
- Dynamic loading nạp code **khi cần**, không tải toàn bộ cùng lúc.

**✏️ Lời giải chi tiết:**
- **B** mô tả chính xác dynamic loading.

👉 **Đáp án đúng: B. Các đoạn chương trình được nạp vào bộ nhớ chính khi chúng được gọi đến trong quá trình thực thi**

---

### 🔹 CÂU 16
**Đề bài:** Khi các tiến trình cộng tác với nhau cần phải đảm bảo điều nào sau đây?
- **A.** Tránh deadlock
- **B.** Tất cả đều đúng
- **C.** Nhất quán dữ liệu
- **D.** Tránh starvation

**💡 Kiến thức cần biết:**
- Cộng tác tiến trình phải đảm bảo các yếu tố về đúng đắn và hiệu quả hoạt động.

**✏️ Lời giải chi tiết:**
- Deadlock, starvation và consistency đều là nhu cầu quan trọng trong cộng tác tiến trình.

👉 **Đáp án đúng: B. Tất cả đều đúng**

---

### 🔹 CÂU 17
**Đề bài:** Tại sao Bounded Waiting là yêu cầu cần thiết cho lời giải bài toán đồng bộ?
- **A.** Để đảm bảo các tiến trình không đồng thời thực thi critical section
- **B.** Để đảm bảo tiến trình sử dụng tài nguyên hiệu quả
- **C.** Để đảm bảo rằng tiến trình không bị tình trạng đói tài nguyên
- **D.** Để tránh mất mát dữ liệu

**💡 Kiến thức cần biết:**
- Bounded waiting nghĩa là tiến trình không bị chờ vô hạn.

**✏️ Lời giải chi tiết:**
- **C** mô tả đúng nghĩa của bounded waiting.

👉 **Đáp án đúng: C. Để đảm bảo rằng tiến trình không bị tình trạng đói tài nguyên**

---

### 🔹 CÂU 18
**Đề bài:** Biết rằng tại thời điểm $t_0$ trong hệ thống, giá trị của semaphore $S$ là -4, phát biểu nào sau đây là đúng?
- **A.** Các tiến trình có thể thực thi thao tác wait(S) 4 lần liên tiếp mà không bị chặn
- **B.** Có 4 tiến trình đang bị chặn trên hàng đợi của semaphore S
- **C.** Thao tác wait(S) đã thực hiện tổng cộng 4 lần
- **D.** Cho phép tối đa 4 tiến trình vào vùng tranh chấp

**💡 Kiến thức cần biết:**
- Nếu semaphore có giá trị âm, số tuyệt đối của nó bằng số tiến trình đang bị block.

**✏️ Lời giải chi tiết:**
- $S = -4$ nghĩa là có 4 tiến trình đang bị chặn trên hàng đợi của semaphore đó.

👉 **Đáp án đúng: B. Có 4 tiến trình đang bị chặn trên hàng đợi của semaphore S**

---

### 🔹 CÂU 19
**Đề bài:** Thứ tự thực thi đúng của các thành phần sau trong quá trình biên dịch và thực thi chương trình C là gì?
- **A.** Compiler $\rightarrow$ Linker $\rightarrow$ Loader
- **B.** Compiler $\rightarrow$ Loader $\rightarrow$ Linker
- **C.** Linker $\rightarrow$ Compiler $\rightarrow$ Loader
- **D.** Loader $\rightarrow$ Compiler

**💡 Kiến thức cần biết:**
- Compiler tạo object code, linker gắn nối các module, loader nạp vào bộ nhớ.

**✏️ Lời giải chi tiết:**
- Thực hiện theo thứ tự: **Compiler → Linker → Loader**.

👉 **Đáp án đúng: A. Compiler $\rightarrow$ Linker $\rightarrow$ Loader**

---

### 🔹 CÂU 20
**Đề bài:** Hình mô tả việc ứng dụng semaphore để đảm bảo thao tác S1 trong P1 luôn thực thi trước thao tác S2 trong P2, biết synch là một semaphore, hãy cho biết giá trị của synch cần được khởi tạo là bao nhiêu?

**P1:** `S1; signal(synch);`

**P2:** `wait(synch); S2;`

- **A.** 0
- **B.** -1
- **C.** 2
- **D.** 1

**💡 Kiến thức cần biết:**
- Muốn `P2` phải block ngay khi gọi `wait(synch)`, thì semaphore bắt đầu ở **0**.

**✏️ Lời giải chi tiết:**
- `wait(synch)` ở 0 khiến tiến trình bị block.
- Đến khi `P1` chạy `signal(synch)`, `P2` mới tiếp tục và thực hiện `S2`.

👉 **Đáp án đúng: A. 0**

---

## PHẦN 2. TỰ LUẬN

### 🔹 CÂU 21
**Đề bài:** Xét chuỗi truy xuất bộ nhớ sau: **2, 1, 2, 5, 6, 4, 0, 1, 4, 7, 1, 3, 6, 7, 1, 3, 5, 0**

Giả sử hệ thống có 4 khung trang, khi sử dụng giải thuật LRU, tại thời điểm truy xuất trang nhớ số 3 lần đầu tiên, có **...(a)...** lỗi trang đã phát sinh (không tính lỗi trang khi truy xuất trang số 3). Sau khi kết thúc chuỗi truy xuất trên, theo thống kê, trang nhớ trở thành trang hy sinh nhiều nhất là trang **...(b)...**

**💡 Kiến thức cần biết:**
- LRU thay thế trang **ít được dùng gần đây nhất**.
- Khi xử lý chuỗi truy xuất, ta cần đếm lỗi trang theo từng lần truy xuất.

**✏️ Lời giải chi tiết:**

* **Diễn biến nạp trang:**
  1. `2` $\rightarrow$ [2] *(Lỗi 1)*
  2. `1` $\rightarrow$ [2, 1] *(Lỗi 2)*
  3. `2` $\rightarrow$ [2, 1] *(Hit)*
  4. `5` $\rightarrow$ [2, 1, 5] *(Lỗi 3)*
  5. `6` $\rightarrow$ [2, 1, 5, 6] *(Lỗi 4)*
  6. `4` $\rightarrow$ Thay `2` $\implies$ [4, 1, 5, 6] *(Lỗi 5)*
  7. `0` $\rightarrow$ Thay `1` $\implies$ [4, 0, 5, 6] *(Lỗi 6)*
  8. `1` $\rightarrow$ Thay `5` $\implies$ [4, 0, 1, 6] *(Lỗi 7)*
  9. `4` $\rightarrow$ [4, 0, 1, 6] *(Hit)*
  10. `7` $\rightarrow$ Thay `6` $\implies$ [4, 0, 1, 7] *(Lỗi 8)*
  11. `1` $\rightarrow$ [4, 0, 1, 7] *(Hit)*
  12. `3` $\rightarrow$ Thay `0` $\implies$ [4, 3, 1, 7] *(Lỗi 9 - lần đầu xuất hiện 3)*

👉 **Kết quả mẫu: (a) 9, (b) 1**

---

### 🔹 CÂU 22
**Đề bài:** Cho 2 tiến trình P1 và P2 có mã giả như bên dưới (`int x, y;` khai báo toàn cục).

- **P1:** `{ ...(a)... y = x / 2; ...(c)... }`
- **P2:** `{ ...(b)... x = 10 * 2; ...(d)... }`

Để đồng bộ P1 và P2, ta dùng 1 semaphore S. Điền các thao tác semaphore vào chỗ trống để x và y được tính bình thường (vị trí để trống thì điền "BLANK").

**💡 Kiến thức cần biết:**
- Dùng semaphore để đảm bảo thứ tự thực thi giữa hai tiến trình.
- Cần tránh đọc x chưa được cập nhật hoặc ghi x trước khi P1 đọc x.

**✏️ Lời giải chi tiết:**

```c
semaphore S = 0; // Khởi tạo semaphore bằng 0

P1 {
    wait(S);     // (a) Chờ P2 tính xong x
    y = x / 2;
    BLANK        // (c) Không cần làm gì thêm
}

P2 {
    BLANK        // (b) Không cần làm gì trước
    x = 10 * 2;
    signal(S);   // (d) Báo hiệu cho P1 biết x đã sẵn sàng
}
```

---

### 🔹 CÂU 23
**Đề bài:** Bộ nhớ chính được chia thành các phân vùng cố định theo thứ tự: **1 (340 KB), 2 (200 KB), 3 (250 KB), 4 (410 KB), 5 (190 KB), 6 (280 KB)**.

Con trỏ đang ở vùng nhớ 4; vùng 4 và 2 đã được cấp phát, các vùng khác còn trống.

- **a.** Nếu dùng **next-fit**, tiến trình P (240 KB) được cấp phát vùng nhớ nào?
- **b.** Nếu dùng **worst-fit**, tiến trình Q (120 KB) được cấp phát vùng nhớ nào?

**💡 Kiến thức cần biết:**
- **Next-fit:** tìm vùng trống bắt đầu từ vị trí con trỏ hiện tại, không quay lại đầu.
- **Worst-fit:** chọn vùng trống có kích thước lớn nhất.

**✏️ Lời giải chi tiết:**
- Trạng thái các phân vùng:
  - Vùng 1: 340 KB (trống)
  - Vùng 2: 200 KB (đã cấp phát)
  - Vùng 3: 250 KB (trống)
  - Vùng 4: 410 KB (đã cấp phát, con trỏ PC đang ở đây)
  - Vùng 5: 190 KB (trống)
  - Vùng 6: 280 KB (trống)

**a. Next-fit cho $P = 240\text{ KB}$**
- Bắt đầu từ vị trí con trỏ ở Vùng 4.
- Vùng 5: $190 < 240$ ⇒ không đủ.
- Vùng 6: $280 \ge 240$ ⇒ đủ điều kiện.
- **Đáp án: Vùng 6**

**b. Worst-fit cho $Q = 120\text{ KB}$**
- Tìm phân vùng trống có kích thước lớn nhất: Vùng 1 (340 KB), Vùng 3 (250 KB), Vùng 5 (190 KB), Vùng 6 (280 KB).
- Vùng lớn nhất là Vùng 1.
- **Đáp án: Vùng 1**

👉 **Đáp án đúng:**
- **a. Vùng 6**
- **b. Vùng 1**