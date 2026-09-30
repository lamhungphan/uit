# BỘ TÀI LIỆU ÔN THI MÔN HỆ ĐIỀU HÀNH (IT007)

---

## 📚 TỔNG QUAN VỀ KIẾN THỨC CẦN NẮM

Để làm tốt đề thi môn Hệ điều hành (đặc biệt là đề thi CITD/UIT), bạn cần nắm vững **4 trụ cột chính** tương ứng với các chương trọng tâm:

1. **Quản lý Bộ nhớ & Bộ nhớ ảo (Memory Management & Virtual Memory):**
   - Phân trang (Paging), Địa chỉ luận lý vs Địa chỉ vật lý, Bảng trang (Page Table), PTBR/PTLR.
   - Bộ nhớ đệm chuyển đổi trang (TLB) & Công thức tính EAT (Effective Access Time).
   - Kỹ thuật Demand Paging & Lỗi trang (Page Fault).
   - Các giải thuật thay thế trang: FIFO, OPT, LRU. Hiện tượng Belady's Anomaly.
2. **Đồng bộ Tiến trình (Process Synchronization):**
   - Miền gán/Vùng tranh chấp (Critical Section), Điều kiện race condition.
   - Lời giải bài toán đồng bộ: Peterson, Mutex, Semaphore (`wait`/`P` và `signal`/`V`).
   - Tình trạng Busy Waiting vs Block/Wakeup.
3. **Tắc nghẽn (Deadlock):**
   - 4 điều kiện cần của Deadlock: Mutual Exclusion, Hold & Wait, No Preemption, Circular Wait.
   - Đồ thị cấp phát tài nguyên (Resource Allocation Graph - RAG).
   - Giải thuật Banker (Bảng Allocation, Max, Need, Available) để tìm Chuỗi an toàn (Safe Sequence) và xử lý Yêu cầu cấp phát (Resource-Request Algorithm).
   - Các chiến lược xử lý Deadlock: Deadlock Prevention, Deadlock Avoidance, Detection & Recovery.

---

## PHẦN 1: BÀI TẬP TRẮC NGHIỆM (28 CÂU)

---

### 🔹 CÂU 1
**Đề bài:** Giả sử một tiến trình được cấp 4 khung trang (frame) trong bộ nhớ vật lý và 7 trang trong bộ nhớ ảo (đang trống). Chuỗi truy xuất trang:
`4 2 4 4 5 7 3 1 4 2 1 7 5 6 5 2 4 3 5 1`
Tại thời điểm tiến trình truy xuất trang nhớ số `7` lần đầu tiên, trang nhớ nào sẽ bị thay thế nếu sử dụng giải thuật **FIFO**?
- **A.** Không trang nhớ nào bị thay thế
- **B.** 2
- **C.** 5
- **D.** 4

**💡 Kiến thức cần biết:**
- **FIFO (First-In, First-Out):** Trang nào được nạp vào bộ nhớ trước tiên thì sẽ bị thay thế trước tiên khi bộ nhớ bị đầy (không còn frame trống).
- **Trạng thái frame:** Tiến trình có 4 frame trống.

**✏️ Lời giải chi tiết:**
1. Truy xuất `4` $\rightarrow$ Nạp 4 (Frames: [4])
2. Truy xuất `2` $\rightarrow$ Nạp 2 (Frames: [4, 2])
3. Truy xuất `4` $\rightarrow$ Đã có 4 (Frames: [4, 2])
4. Truy xuất `4` $\rightarrow$ Đã có 4 (Frames: [4, 2])
5. Truy xuất `5` $\rightarrow$ Nạp 5 (Frames: [4, 2, 5])
6. Truy xuất `7` $\rightarrow$ Nạp 7 (Frames: [4, 2, 5, 7])

Tại thời điểm nạp trang `7` lần đầu tiên, bộ nhớ vật lý lúc đó đang chứa [4, 2, 5] (mới dùng 3 frame), nên trang `7` được nạp vào frame trống thứ 4 mà **chưa phải thay thế trang nào**.

👉 **Đáp án đúng: A. Không trang nhớ nào bị thay thế**

---

### 🔹 CÂU 2
**Đề bài:** Tại thời điểm tiến trình truy xuất trang nhớ số `6` lần đầu tiên, có tổng cộng bao nhiêu lỗi trang (Page Fault) đã xảy ra nếu sử dụng giải thuật thay thế trang **OPT** (không tính lỗi trang khi truy xuất trang 6)?
- **A.** 7
- **B.** 8
- **C.** 9
- **D.** 6

**💡 Kiến thức cần biết:**
- **OPT (Optimal Page Replacement):** Thay thế trang sẽ **không được sử dụng trong thời gian dài nhất ở tương lai**.
- **Page Fault (Lỗi trang):** Xảy ra khi trang được truy xuất chưa có sẵn trong bộ nhớ vật lý (frame).

**✏️ Lời giải chi tiết:**
Chuỗi truy xuất: `4, 2, 4, 4, 5, 7, 3, 1, 4, 2, 1, 7, 5, 6...`
Số frame = 4.

- `4`: PF (1) $\rightarrow$ [4]
- `2`: PF (2) $\rightarrow$ [4, 2]
- `4`: hit
- `4`: hit
- `5`: PF (3) $\rightarrow$ [4, 2, 5]
- `7`: PF (4) $\rightarrow$ [4, 2, 5, 7] (Bộ nhớ đầy)
- `3`: PF (5) $\rightarrow$ Nhìn về tương lai: `1, 4, 2, 1, 7, 5, 6...`. Trong [4, 2, 5, 7], trang `5` xuất hiện trễ nhất/không dùng sớm. Do đó thay `5` bằng `3` $\rightarrow$ [4, 2, 3, 7]
- `1`: PF (6) $\rightarrow$ Nhìn về tương lai từ 1: `4, 2, 1, 7, 5, 6...`. Trong [4, 2, 3, 7], trang `3` không còn dùng lại nữa! Thay `3` bằng `1` $\rightarrow$ [4, 2, 1, 7]
- `4`: hit
- `2`: hit
- `1`: hit
- `7`: hit
- `5`: PF (7) $\rightarrow$ Nhìn tương lai từ 5: `6, 5, 2, 4, 3, 5, 1`. Trong [4, 2, 1, 7], trang `7` không còn dùng lại nữa! Thay `7` bằng `5` $\rightarrow$ [4, 2, 1, 5]
- `6`: Thời điểm dừng tính!

Tổng số lỗi trang trước khi nạp 6 là **7**.

👉 **Đáp án đúng: A. 7**

---

### 🔹 CÂU 3
**Đề bài:** Nếu sử dụng giải thuật **LRU**, có tổng cộng bao nhiêu lỗi trang xảy ra cho toàn bộ chuỗi?
- **A.** 12
- **B.** 10
- **C.** 15
- **D.** 8

**💡 Kiến thức cần biết:**
- **LRU (Least Recently Used):** Thay thế trang **ít được sử dụng nhất trong thời gian gần đây nhất** (nhìn về quá khứ).

**✏️ Lời giải chi tiết:**
Chuỗi: `4 2 4 4 5 7 3 1 4 2 1 7 5 6 5 2 4 3 5 1` (20 lần truy xuất, 4 frame)

1. `4`: PF (1) $\rightarrow$ [4]
2. `2`: PF (2) $\rightarrow$ [4, 2]
3. `4`: Hit $\rightarrow$ [2, 4]
4. `4`: Hit $\rightarrow$ [2, 4]
5. `5`: PF (3) $\rightarrow$ [2, 4, 5]
6. `7`: PF (4) $\rightarrow$ [2, 4, 5, 7]
7. `3`: PF (5) $\rightarrow$ Lâu nhất là 2 $\rightarrow$ Thay 2 $\rightarrow$ [4, 5, 7, 3]
8. `1`: PF (6) $\rightarrow$ Lâu nhất là 4 $\rightarrow$ Thay 4 $\rightarrow$ [5, 7, 3, 1]
9. `4`: PF (7) $\rightarrow$ Lâu nhất là 5 $\rightarrow$ Thay 5 $\rightarrow$ [7, 3, 1, 4]
10. `2`: PF (8) $\rightarrow$ Lâu nhất là 7 $\rightarrow$ Thay 7 $\rightarrow$ [3, 1, 4, 2]
11. `1`: Hit $\rightarrow$ [3, 4, 2, 1]
12. `7`: PF (9) $\rightarrow$ Lâu nhất là 3 $\rightarrow$ Thay 3 $\rightarrow$ [4, 2, 1, 7]
13. `5`: PF (10) $\rightarrow$ Lâu nhất là 4 $\rightarrow$ Thay 4 $\rightarrow$ [2, 1, 7, 5]
14. `6`: PF (11) $\rightarrow$ Lâu nhất là 2 $\rightarrow$ Thay 2 $\rightarrow$ [1, 7, 5, 6]
15. `5`: Hit $\rightarrow$ [1, 7, 6, 5]
16. `2`: PF (12) $\rightarrow$ Lâu nhất là 1 $\rightarrow$ Thay 1 $\rightarrow$ [7, 6, 5, 2]
17. `4`: PF (13) $\rightarrow$ Lâu nhất là 7 $\rightarrow$ Thay 7 $\rightarrow$ [6, 5, 2, 4]
18. `3`: PF (14) $\rightarrow$ Lâu nhất là 6 $\rightarrow$ Thay 6 $\rightarrow$ [5, 2, 4, 3]
19. `5`: Hit $\rightarrow$ [2, 4, 3, 5]
20. `1`: PF (15) $\rightarrow$ Lâu nhất là 2 $\rightarrow$ Thay 2 $\rightarrow$ [4, 3, 5, 1]

Tổng cộng có **15** lỗi trang.

👉 **Đáp án đúng: C. 15**

---

### 🔹 CÂU 4
**Đề bài:** Một bộ vi xử lý có không gian địa chỉ ảo 32 bit. Hỏi bảng trang có bao nhiêu mục (entry) nếu kích thước bảng trang là 512KB và kích thước của mỗi mục là 4 bytes?
- **A.** $2^{19}$
- **B.** $2^{16}$
- **C.** $2^{17}$
- **D.** $2^{18}$

**💡 Kiến thức cần biết:**
- **Số mục trong bảng trang (Number of entries)** = $\frac{\text{Kích thước bảng trang}}{\text{Kích thước 1 mục (entry size)}}$.
- Quy đổi đơn vị: $1 \text{ KB} = 2^{10} \text{ bytes}$, $512 \text{ KB} = 512 \times 2^{10} \text{ bytes} = 2^9 \times 2^{10} = 2^{19} \text{ bytes}$.
- $4 \text{ bytes} = 2^2 \text{ bytes}$.

**✏️ Lời giải chi tiết:**
$$\text{Số mục} = \frac{512 \text{ KB}}{4 \text{ bytes}} = \frac{2^{19}}{2^2} = 2^{17} \text{ mục}$$

👉 **Đáp án đúng: C. $2^{17}$**

---

### 🔹 CÂU 5
**Đề bài:** Trong mô hình quản lý bộ nhớ, tiến trình có thể chuyển đổi địa chỉ (Address Binding) tại các thời điểm nào sau đây?
- **A.** Thời điểm nạp (Load time)
- **B.** Thời điểm thực thi (Execution time)
- **C.** Thời điểm biên dịch (Compile time)
- **D.** Tất cả đáp án đều đúng

**💡 Kiến thức cần biết:**
- **Address Binding (Ràng buộc địa chỉ):** Chuyển đổi từ địa chỉ logic/ký hiệu sang địa chỉ vật lý trong bộ nhớ.
- Có 3 thời điểm ràng buộc: Compile time, Load time, và Execution time.

👉 **Đáp án đúng: D. Tất cả đáp án đều đúng**

---

### 🔹 CÂU 6
**Đề bài:** Hình bên dưới mô tả việc ứng dụng semaphore để đảm bảo thao tác `S1` trong `P1` luôn thực thi trước thao tác `S2` trong `P2`. Giá trị của `synch` cần được khởi tạo là bao nhiêu?
- P1: `S1; signal(synch);`
- P2: `wait(synch); S2;`
- **A.** 1
- **B.** -1
- **C.** 2
- **D.** 0

**💡 Kiến thức cần biết:**
- **Semaphore synch:**
  - `wait(synch)`: Giảm `synch` đi 1. Nếu `synch < 0`, tiến trình bị block (chờ).
  - `signal(synch)`: Tăng `synch` lên 1. Nếu có tiến trình đang chờ, đánh thức nó.
- Muốn `S2` phải chờ `S1` làm xong, thì ban đầu khi `P2` gọi `wait(synch)`, `P2` phải bị **chờ**. Khi `P1` làm xong `S1` và gọi `signal(synch)` thì `P2` mới được chạy `S2`.
- Để `wait(synch)` chặn P2 ngay từ đầu, giá trị khởi tạo của `synch` phải bằng **0**.

👉 **Đáp án đúng: D. 0**

---

### 🔹 CÂU 7
**Đề bài:** Xét một hệ thống sử dụng kỹ thuật phân trang với bảng trang được lưu trong bộ nhớ chính. Thời gian tìm kiếm trong TLB là $\epsilon = 25\text{ns}$, thời gian một chu kỳ truy xuất bộ nhớ ($m$) là $200\text{ns}$, và thời gian truy xuất bộ nhớ hiệu dụng ($\text{EAT}$) là $250\text{ns}$. Hỏi tỉ lệ tìm thấy trang nhớ trong TLB ($\alpha$) là bao nhiêu?
- **A.** 90.7%
- **B.** 85.7%
- **C.** 87.5%
- **D.** 95.0%

**💡 Kiến thức cần biết:**
- **Công thức EAT với TLB:**
  $$\text{EAT} = \alpha \times (\epsilon + m) + (1 - \alpha) \times (\epsilon + 2m)$$
  *(Giải thích: Khi TLB Hit ($\alpha$), tốn 1 lần tra TLB + 1 lần truy xuất bộ nhớ. Khi TLB Miss ($1-\alpha$), tốn 1 lần tra TLB + 1 lần tra Bảng trang trong bộ nhớ + 1 lần truy xuất dữ liệu thật).*

**✏️ Lời giải chi tiết:**
- $\epsilon = 25$, $m = 200$, $\text{EAT} = 250$.
- Thay vào công thức:
  $$250 = \alpha \times (25 + 200) + (1 - \alpha) \times (25 + 400)$$
  $$250 = 225\alpha + 425(1 - \alpha)$$
  $$250 = 425 - 200\alpha \implies 200\alpha = 175 \implies \alpha = \frac{175}{200} = 0.875 = 87.5\%$$

👉 **Đáp án đúng: C. 87.5%**

---

### 🔹 CÂU 8
**Đề bài:** Trong các giải thuật thay thế trang, giải thuật nào yêu cầu thêm sự hỗ trợ từ phần cứng để thực hiện?
- **A.** LRU
- **B.** OPT
- **C.** Không có giải thuật nào yêu cầu thêm sự hỗ trợ từ phần cứng
- **D.** FIFO

**💡 Kiến thức cần biết:**
- **LRU (Least Recently Used)** cần lưu vết thời gian truy xuất gần nhất của từng trang (sử dụng Counter/Clock hoặc Stack phần cứng) $\rightarrow$ **Cần hỗ trợ phần cứng**.
- OPT là giải thuật lý thuyết (không thực hiện được trong thực tế).
- FIFO chỉ cần hàng đợi phần mềm (Queue).

👉 **Đáp án đúng: A. LRU**

---

### 🔹 CÂU 9
**Đề bài:** Cho semaphore $S$ và $Q$ được khởi tạo giá trị 1.
- P1: `wait(S); wait(Q); ... signal(S); signal(Q);`
- P2: `wait(Q); wait(S); ... signal(Q); signal(S);`
Hỏi vấn đề gì có thể xảy ra khi P1 và P2 thực thi đồng thời?
- **A.** Không có vấn đề gì xảy ra
- **B.** Tiến trình P2 luôn thực thi trước P1
- **C.** Tiến trình P1 luôn thực thi trước P2
- **D.** P1 và P2 có thể bị deadlock

**💡 Kiến thức cần biết:**
- Nếu P1 thực thi `wait(S)` thành công (giữ S), đúng lúc đó context switch sang P2 thực thi `wait(Q)` thành công (giữ Q).
- Tiếp theo, P1 gọi `wait(Q)` $\rightarrow$ bị chặn vì P2 đang giữ Q.
- P2 gọi `wait(S)` $\rightarrow$ bị chặn vì P1 đang giữ S.
- Cả 2 tiến trình chờ lẫn nhau vô thời hạn $\rightarrow$ **Deadlock** (Tắc nghẽn).

👉 **Đáp án đúng: D. P1 và P2 có thể bị deadlock**

---

### 🔹 CÂU 10
**Đề bài:** Để áp dụng giải thuật Banker, tiến trình cần phải khai báo những thông tin gì?
- **A.** Số lượng thực thể tối thiểu mà tiến trình cần ở mỗi loại tài nguyên
- **B.** Số lượng thực thể tối đa của mỗi loại tài nguyên mà tiến trình cần
- **C.** Số lượng tài nguyên tối đa mà tiến trình cần
- **D.** Dung lượng bộ nhớ tối đa mà tiến trình cần

**💡 Kiến thức cần biết:**
- **Giải thuật Banker (Tránh Deadlock):** Bắt buộc mỗi tiến trình phải khai báo trước **nhu cầu tài nguyên tối đa (Max)** mà nó sẽ sử dụng trong suốt quá trình chạy.

👉 **Đáp án đúng: B. Số lượng thực thể tối đa của mỗi loại tài nguyên mà tiến trình cần**

---

### 🔹 CÂU 11
**Đề bài:** Cho 4 đồ thị cấp phát tài nguyên (a), (b), (c), (d). Hỏi đồ thị nào có deadlock xảy ra?
- **A.** Đồ thị (a), (b)
- **B.** Đồ thị (c), (d)
- **C.** Đồ thị (b), (c), (d)
- **D.** Đồ thị (b), (d)

**💡 Kiến thức cần biết:**
- Quy tắc kiểm tra Deadlock trên Đồ thị cấp phát tài nguyên (RAG):
  1. Nếu đồ thị **không có chu trình (cycle)** $\rightarrow$ **Không Deadlock**.
  2. Nếu đồ thị **có chu trình**:
     - Nếu mỗi loại tài nguyên chỉ có **1 thực thể (1 chấm)** $\rightarrow$ **Chắc chắn Deadlock**.
     - Nếu tài nguyên có **nhiều thực thể (nhiều chấm)** $\rightarrow$ Có thể có Deadlock hoặc không (cần kiểm tra xem có tiến trình nào ngoài chu trình có thể giải phóng tài nguyên để phá vỡ chu trình không).

**✏️ Lời giải chi tiết:**
- **(a):** Không có chu trình $\rightarrow$ No deadlock.
- **(b):** Có chu trình $T_1 \rightarrow R_3 \rightarrow T_2 \rightarrow R_3 / R_1 \rightarrow T_1$, tất cả tài nguyên $R_1, R_2, R_3$ đều chỉ có 1 thực thể (1 dot) $\rightarrow$ **Deadlock**.
- **(c):** $R_1, R_2$ có 2 thực thể. $T_3$ giữ $R_2$ nhưng không chờ ai cả $\rightarrow T_3$ chạy xong trả $R_2 \rightarrow$ giải phóng chu trình $\rightarrow$ No deadlock.
- **(d):** Các tiến trình trong chu trình đều giữ tất cả các thực thể của $R_1$ và $R_2$, không có tiến trình độc lập nào chạy xong để trả tài nguyên $\rightarrow$ **Deadlock**.

👉 **Đáp án đúng: D. Đồ thị (b), (d)**

---

### 🔹 CÂU 12
**Đề bài:** Nghịch lý Belady (Belady's Anomaly) là gì?
- **A.** Hiện tượng số lỗi trang giảm khi tiến trình được cấp nhiều frame hơn
- **B.** Hiện tượng số lỗi trang tăng mặc dù tiến trình được cấp nhiều frame hơn
- **C.** Hiện số lỗi trang tăng mặc dù tiến trình được cấp ít frame lại
- **D.** Hiện tượng số lỗi trang không đổi khi tiến trình được cấp nhiều frame hơn

**💡 Kiến thức cần biết:**
- Thông thường, cấp thêm frame thì số lỗi trang phải giảm.
- **Belady's Anomaly:** Là hiện tượng bất thường ở một số giải thuật (như FIFO), khi **tăng số frame được cấp**, số lượng lỗi trang lại **tăng lên**.

👉 **Đáp án đúng: B. Hiện tượng số lỗi trang tăng mặc dù tiến trình được cấp nhiều frame hơn**

---

### 🔹 CÂU 13
**Đề bài:** Cho trạng thái hệ thống với 5 tiến trình ($P_0 \dots P_4$) và 4 tài nguyên ($A, B, C, D$).
- **Allocation:** $P_0(2001), P_1(3121), P_2(2103), P_3(1312), P_4(1432)$
- **Max:** $P_0(4212), P_1(5252), P_2(2316), P_3(1424), P_4(3665)$
- **Available:** $A=3, B=3, C=2, D=1$

Lựa chọn nào sau đây **KHÔNG PHẢI** là chuỗi an toàn (Safe Sequence)?
- **A.** `<P3, P0, P4, P2, P1>`
- **B.** `<P1, P3, P0, P4, P2>`
- **C.** `<P0, P3, P1, P2, P4>`
- **D.** `<P0, P1, P3, P2, P4>`

**💡 Kiến thức cần biết:**
- Tính ma trận **Need = Max - Allocation**:
  - $Need(P_0) = (4,2,1,2) - (2,0,0,1) = (2, 2, 1, 1)$
  - $Need(P_1) = (5,2,5,2) - (3,1,2,1) = (2, 1, 3, 1)$
  - $Need(P_2) = (2,3,1,6) - (2,1,0,3) = (0, 2, 1, 3)$
  - $Need(P_3) = (1,4,2,4) - (1,3,1,2) = (0, 1, 1, 2)$
  - $Need(P_4) = (3,6,6,5) - (1,4,3,2) = (2, 2, 3, 3)$
- Điều kiện để tiến trình $P_i$ thực thi: $Need(P_i) \le Available$.
- Khi $P_i$ hoàn thành: $Available_{\text{mới}} = Available_{\text{cũ}} + Allocation(P_i)$.

**✏️ Lời giải chi tiết:**
- **Thử câu B:** `<P1, ...>`
  - Ban đầu $Available = (3, 3, 2, 1)$.
  - So sánh với $Need(P_1) = (2, 1, 3, 1)$:
    - $Need_C(P_1) = 3 > Available_C = 2 \rightarrow$ **Không đủ C cho $P_1$ ngay từ đầu!**
  - Do đó $P_1$ không thể chạy đầu tiên $\rightarrow$ **Chuỗi B không hợp lệ.**

👉 **Đáp án đúng: B. `<P1, P3, P0, P4, P2>`**

---

### 🔹 CÂU 14
**Đề bài:** Tại thời điểm $t_1$, yêu cầu cấp phát (Request) nào sau đây sẽ được đáp ứng?
- **A.** Không yêu cầu nào có thể được cấp phát
- **B.** $P_2$ yêu cầu `<0, 0, 1, 1>`
- **C.** $P_0$ yêu cầu `<3, 0, 1, 0>`
- **D.** $P_3$ yêu cầu `<1, 0, 0, 1>`

**💡 Kiến thức cần biết:**
Thuật toán Yêu cầu Tài nguyên (Resource-Request Algorithm):
1. $Request_i \le Need_i$ (nếu sai $\rightarrow$ Báo lỗi vượt quá nhu cầu đã khai báo).
2. $Request_i \le Available$ (nếu sai $\rightarrow P_i$ phải chờ vì hệ thống không đủ tài nguyên rảnh).
3. Thử cấp phát giả định và kiểm tra trạng thái an toàn (Banker).

**✏️ Lời giải chi tiết:**
$Available = (3, 3, 2, 1)$.
- **Xét C ($P_0$ req `<3,0,1,0>`):** $Need(P_0) = (2,2,1,1)$. $Request_A = 3 > Need_A = 2 \rightarrow$ Vi phạm Bước 1.
- **Xét B ($P_2$ req `<0,0,1,1>`):** $Need(P_2) = (0,2,1,3)$. $Request_D = 1 \le Need_D = 3$. $Request \le Available (3,3,2,1)$.
  - Giả định cấp cho $P_2$:
    - $Available_{\text{mới}} = (3,3,2,1) - (0,0,1,1) = (3,3,1,0)$.
    - $Allocation(P_2)_{\text{mới}} = (2,1,1,4)$. $Need(P_2)_{\text{mới}} = (0,2,0,2)$.
  - Thử tìm chuỗi an toàn mới với $Available = (3,3,1,0)$:
    - $P_3$ có $Need = (0,1,1,2)$. $Need_D = 2 > Available_D = 0 \rightarrow P_3$ không chạy được.
    - $P_0$ có $Need = (2,2,1,1)$. $Need_D = 1 > Available_D = 0 \rightarrow P_0$ không chạy được.
    - $P_1$ có $Need_D = 1 > 0 \rightarrow$ Không chạy được.
    - $P_2$ có $Need_D = 2 > 0 \rightarrow$ Không chạy được.
    - $P_4$ có $Need_D = 3 > 0 \rightarrow$ Không chạy được.
    $\rightarrow$ Mọi tiến trình đều bị tắc nghẽn ở tài nguyên $D$ ($Available_D = 0$)! Trạng thái KHÔNG an toàn $\rightarrow$ Từ chối.
- **Xét D ($P_3$ req `<1,0,0,1>`):** $Need(P_3) = (0,1,1,2)$. $Request_A = 1 > Need_A = 0 \rightarrow$ Vi phạm Bước 1.

Do đó, **không yêu cầu nào có thể được đáp ứng**.

👉 **Đáp án đúng: A. Không yêu cầu nào có thể được cấp phát**

---

### 🔹 CÂU 15
**Đề bài:** Phát biểu nào sau đây là **SAI** khi nói về hiện tượng phân mảnh ngoại (External Fragmentation)?
- **A.** Kỹ thuật nén bộ nhớ (Memory Compaction) có thể được sử dụng để giảm thiểu phân mảnh ngoại.
- **B.** Phân mảnh ngoại xảy ra khi không gian bộ nhớ bị phân chia thành các khối nhỏ và không đủ lớn để đáp ứng các yêu cầu cấp phát.
- **C.** Hiện tượng phân mảnh ngoại chủ yếu xảy ra trong các hệ thống quản lý bộ nhớ có phân vùng cố định.
- **D.** Phân mảnh ngoại chỉ xảy ra khi có nhiều tiến trình yêu cầu bộ nhớ đồng thời và bộ nhớ trống không liên tục.

**💡 Kiến thức cần biết:**
- **Phân vùng cố định (Fixed partitioning):** Gây ra **Phân mảnh nội (Internal Fragmentation)**.
- **Phân vùng động / Phân đoạn:** Gây ra **Phân mảnh ngoại (External Fragmentation)**.

👉 **Đáp án đúng: C. Hiện tượng phân mảnh ngoại chủ yếu xảy ra trong các hệ thống quản lý bộ nhớ có phân vùng cố định**

---

### 🔹 CÂU 16
**Đề bài:** Chọn phát biểu đúng khi nói về **vùng tranh chấp (Critical Section)**?
- **A.** Vùng tranh chấp là một vùng code được chia sẻ giữa nhiều tiến trình, tại một thời điểm, chỉ có một tiến trình được phép thực thi vùng code này
- **B.** Vùng tranh chấp là một vùng nhớ mà tại đó các tiến trình giành quyền để cập nhật dữ liệu
- **C.** Vùng tranh chấp là một vùng code mà tại đó các tiến trình thực hiện việc truy cập và/hoặc thay đổi giá trị của dữ liệu được chia sẻ
- **D.** Vùng tranh chấp là một vùng nhớ mà tại một thời điểm, chỉ có một tiến trình được phép truy cập

**💡 Kiến thức cần biết:**
- **Critical Section (Vùng tranh chấp / Miền gán):** Định nghĩa chuẩn là **đoạn mã (vùng code)** trong đó tiến trình truy cập và thao tác trên dữ liệu/biến dùng chung.

👉 **Đáp án đúng: C. Vùng tranh chấp là một vùng code mà tại đó các tiến trình thực hiện việc truy cập và/hoặc thay đổi giá trị của dữ liệu được chia sẻ**

---

### 🔹 CÂU 17
**Đề bài:** Để tránh **busy waiting** khi hiện thực mutex/semaphore, hệ điều hành cần cung cấp cơ chế nào?
- **A.** Block và Wakeup
- **B.** Lock và Unlock
- **C.** Wait và Signal
- **D.** Load và Store

**💡 Kiến thức cần biết:**
- Busy waiting bắt CPU chạy vòng lặp vô tận (`while(true)`).
- Để tránh lãng phí CPU, khi tài nguyên chưa sẵn sàng, OS gọi hàm **`block()`** để chuyển tiến trình vào danh sách chờ (Waiting State). Khi tài nguyên mở, gọi **`wakeup()`** để đưa tiến trình trở lại Ready State.

👉 **Đáp án đúng: A. Block và Wakeup**

---

### 🔹 CÂU 18
**Đề bài:** Nhóm giải pháp nào sau đây thực hiện giải quyết deadlock bằng cách **không để 1 trong 4 điều kiện cần của deadlock xảy ra**?
- **A.** Tránh deadlock (Deadlock Avoidance)
- **B.** Ngăn deadlock (Deadlock Prevention)
- **C.** Phát hiện và phục hồi deadlock
- **D.** Bỏ qua deadlock

**💡 Kiến thức cần biết:**
- **Deadlock Prevention (Ngăn ngừa deadlock):** Đảm bảo rằng ít nhất một trong 4 điều kiện cần (Mutual Exclusion, Hold & Wait, No Preemption, Circular Wait) **không bao giờ có thể xảy ra**.

👉 **Đáp án đúng: B. Ngăn deadlock**

---

### 🔹 CÂU 19
**Đề bài:** “Mỗi tiến trình chỉ có thể yêu cầu thực thể của một loại tài nguyên theo thứ tự tăng dần của loại tài nguyên" là giải pháp để triệt tiêu điều kiện nào của deadlock?
- **A.** Chu trình đợi (Circular Wait)
- **B.** Không được trưng dụng tài nguyên (No Preemption)
- **C.** Loại trừ tương hỗ (Mutual Exclusion)
- **D.** Giữ và chờ tài nguyên (Hold and Wait)

**💡 Kiến thức cần biết:**
- Đánh số thứ tự các tài nguyên $F(R)$ và bắt buộc yêu cầu tài nguyên theo thứ tự tăng dần sẽ triệt tiêu khả năng tạo thành vòng khép kín $\rightarrow$ Triệt tiêu **Circular Wait (Chu trình đợi)**.

👉 **Đáp án đúng: A. Chu trình đợi**

---

### 🔹 CÂU 20
**Đề bài:** Kỹ thuật **phân trang theo yêu cầu (Demand Paging)** trong hệ điều hành hoạt động như thế nào?
- **A.** Bộ nhớ chính được phân chia thành các khối nhỏ, mỗi khối chứa toàn bộ tiến trình
- **B.** Tất cả các trang của tiến trình đều được nạp vào bộ nhớ chính trước khi tiến trình bắt đầu thực thi
- **C.** Tất cả các tiến trình được nạp vào bộ nhớ ảo trước khi chuyển sang bộ nhớ chính
- **D.** Chỉ những trang được tiến trình yêu cầu mới được nạp vào bộ nhớ chính

**💡 Kiến thức cần biết:**
- **Demand Paging (Phân trang theo yêu cầu):** Nạp trang vào RAM theo nguyên tắc **Lazy Swapper** — "Khi nào cần/được yêu cầu thì mới nạp vào bộ nhớ chính".

👉 **Đáp án đúng: D. Chỉ những trang được tiến trình yêu cầu mới được nạp vào bộ nhớ chính**

---

### 🔹 CÂU 21
**Đề bài:** Khi có lỗi trang xảy ra, thao tác nào sau đây **KHÔNG** thuộc quy trình xử lý lỗi trang (Page Fault Service Routine)?
- **A.** Trang còn thiếu được thêm từ bộ nhớ phụ vào bộ nhớ chính
- **B.** Sau khi lỗi trang được xử lý, lệnh gây ra lỗi trang được reset và thực thi lại
- **C.** Khi phát hiện lỗi trang, tiến trình bị chuyển từ trạng thái Running về trạng thái Waiting
- **D.** Sau khi xử lý xong lỗi trang, tiến trình chuyển từ trạng thái Waiting về lại trạng thái Running

**💡 Kiến thức cần biết:**
- Thực tế trong lý thuyết OS (Silberschatz):
  1. Trap/Interrupt đến OS.
  2. Lưu trạng thái, chuyển tiến trình bị ngắt sang **Waiting** (chờ I/O đọc đĩa).
  3. Đọc trang từ đĩa (Bộ nhớ phụ) vào Frame trống trong RAM (Bộ nhớ chính).
  4. Cập nhật Bảng trang (valid bit = 1).
  5. Đưa tiến trình về **Ready** state (chứ không phải chuyển thẳng lại Running!). Tiến trình phải ở Ready để CPU Scheduler chọn lại.

*(Lưu ý: Trong các lựa chọn, câu D phát biểu "chuyển từ Waiting về lại Running" là SAI về mặt luồng chuyển trạng thái chuẩn của OS).*

👉 **Đáp án đúng: D. Sau khi xử lý xong lỗi trang, tiến trình chuyển từ trạng thái Waiting về lại trạng thái Running**

---

### 🔹 CÂU 22
**Đề bài:** Một hệ thống phân trang sử dụng TLB với xác suất tìm thấy trang trong TLB là $\alpha = 0.92$. Thời gian tìm kiếm trong TLB là $\epsilon = 20\text{ns}$, và thời gian truy xuất bộ nhớ hiệu quả ($\text{EAT}$) là $210\text{ns}$. Hãy tính thời gian một thao tác truy xuất bộ nhớ ($m$) khi không dùng TLB?
- **A.** 351.85ns
- **B.** 182.42ns
- **C.** 175.93ns
- **D.** 204.84ns

**💡 Kiến thức cần biết:**
$$\text{EAT} = \alpha(\epsilon + m) + (1-\alpha)(\epsilon + 2m)$$

**✏️ Lời giải chi tiết:**
$$210 = 0.92(20 + m) + 0.08(20 + 2m)$$
$$210 = 18.4 + 0.92m + 1.6 + 0.16m$$
$$210 = 20 + 1.08m \implies 1.08m = 190 \implies m = \frac{190}{1.08} \approx 175.9259 \text{ ns}$$

75.9259 x 2 = 351.85

👉 **Đáp án đúng: A. 351.85ns**

---

### 🔹 CÂU 23
**Đề bài:** Cho một Semaphore $S$ có giá trị khởi tạo là 5. Chọn phát biểu đúng nhất?
- **A.** Khi giá trị của S bằng 0 có nghĩa là đã có ít nhất 5 tiến trình thực thi thao tác wait(&S) mà không bị block
- **B.** Các tiến trình có thể thực thi thao tác wait(&S) liên tục 5 lần mà không bị block
- **C.** S là một binary semaphore
- **D.** Có 5 tiến trình có thể thực thi đồng thời

**💡 Kiến thức cần biết:**
- Semaphore đếm $S = 5$ cho phép thực hiện thành công 5 lần `wait(S)` giảm dần từ 5 xuống 0 mà không bị block tiến trình nào.

👉 **Đáp án đúng: B. Các tiến trình có thể thực thi thao tác wait(&S) liên tục 5 lần mà không bị block**

---

### 🔹 CÂU 24
**Đề bài:** Biết rằng các trang 0, 1, 2, 3, 4 của tiến trình P lần lượt được nạp vào các khung trang (frame) 4, 7, 9, 5, 6 của bộ nhớ vật lý. Tiến trình P truy xuất biến tại địa chỉ luận lý là 2555. Hỏi địa chỉ vật lý tương ứng là bao nhiêu nếu kích thước trang/frame là 1024 bytes?
- **A.** 6567
- **B.** 5627
- **C.** 8190
- **D.** 9723

**💡 Kiến thức cần biết:**
1. **Số trang (Page Number - p):** $p = \lfloor \text{Địa chỉ logic} / \text{Kích thước trang} \rfloor$
2. **Độ lệch (Offset - d):** $d = \text{Địa chỉ logic} \pmod{\text{Kích thước trang}}$
3. **Địa chỉ vật lý (Physical Address):** $\text{Frame number} \times \text{Kích thước trang} + d$

**✏️ Lời giải chi tiết:**
- Địa chỉ logic $= 2555$, Kích thước trang $= 1024$.
- $p = \lfloor 2555 / 1024 \rfloor = 2$ (Trang số 2).
- $d = 2555 \pmod{1024} = 2555 - 2 \times 1024 = 507$.
- Tra bảng trang: Trang 2 được nạp vào **Frame 9**.
- Địa chỉ vật lý $= 9 \times 1024 + 507 = 9216 + 507 = 9723$.

👉 **Đáp án đúng: D. 9723**

---

### 🔹 CÂU 25
**Đề bài:** **Race condition** có thể dẫn đến hậu quả nào sau đây?
- **A.** Deadlock
- **B.** Dữ liệu không nhất quán (Data Inconsistency)
- **C.** Tiến trình bị trì hoãn vô hạn định
- **D.** Tiến trình bị đói (Starvation)

**💡 Kiến thức cần biết:**
- **Race Condition (Tình trạng tranh đua):** Xảy ra khi nhiều tiến trình cùng truy cập và chỉnh sửa dữ liệu dùng chung đồng thời, kết quả cuối cùng phụ thuộc vào thứ tự thực thi $\rightarrow$ Gây ra **dữ liệu sai lệch / không nhất quán**.

👉 **Đáp án đúng: B. Dữ liệu không nhất quán**

---

### 🔹 CÂU 26
**Đề bài:** Trong cơ chế phân trang, khi tiến trình thực thi, bảng trang được truy cập như thế nào?
- **A.** Sử dụng địa chỉ được lưu trong thanh ghi PTBR và kích thước được lưu trong thanh ghi PTLR
- **B.** Bảng trang luôn được lưu tại một vị trí cố định trong bộ nhớ
- **C.** Sử dụng thanh ghi địa chỉ nền
- **D.** Tất cả phương án đều đúng

**💡 Kiến thức cần biết:**
- Hệ điều hành sử dụng:
  - **PTBR (Page-Table Base Register):** Trỏ đến địa chỉ gốc của Bảng trang trong RAM.
  - **PTLR (Page-Table Length Register):** Lưu kích thước của bảng trang.

👉 **Đáp án đúng: A. Sử dụng địa chỉ được lưu trong thanh ghi PTBR và kích thước được lưu trong thanh ghi PTLR**

---

### 🔹 CÂU 27
**Đề bài:** Phát biểu nào sau đây là **SAI** khi nói về deadlock?
- **A.** Deadlock chỉ xảy ra trong hệ thống đa chương
- **B.** Trong đồ thị RAG, nếu có chu trình đợi xuất hiện thì có deadlock xảy ra
- **C.** Việc đồng bộ tiến trình không đúng có thể gây ra deadlock
- **D.** Khi một tiến trình bị deadlock, nó sẽ không thể tự phục hồi về trạng thái trước đó

**💡 Kiến thức cần biết:**
- Trong đồ thị RAG có tài nguyên nhiều thực thể, sự xuất hiện của chu trình (cycle) là **điều kiện cần chứ chưa đủ** để kết luận có deadlock. Do đó khẳng định "có chu trình thì có deadlock" là **SAI**.

👉 **Đáp án đúng: B. Trong đồ thị RAG, nếu có chu trình đợi xuất hiện thì có deadlock xảy ra**

---

### 🔹 CÂU 28
**Đề bài:** Phát biểu nào sau đây là **SAI** khi nhắc về giải pháp **Peterson** trong đồng bộ tiến trình?
- **A.** Giải pháp Peterson thỏa mãn cả 03 điều kiện dành cho lời giải bài toán đồng bộ
- **B.** Giải pháp Peterson có thể được áp dụng trên n tiến trình
- **C.** Giải pháp Peterson sử dụng 2 biến chia sẻ là `turn` và `flag[]`
- **D.** Giải pháp Peterson không cần sự hỗ trợ của hệ điều hành / phần cứng đặc biệt

**💡 Kiến thức cần biết:**
- Giải pháp Peterson thuần túy được thiết kế chuẩn dành riêng cho **2 tiến trình** ($P_0$ và $P_1$). (Mặc dù có mở rộng Filter algorithm cho $N$ tiến trình nhưng bản chất thuật toán Peterson kinh điển chỉ áp dụng cho 2 tiến trình).

👉 **Đáp án đúng: B. Giải pháp Peterson có thể được áp dụng trên n tiến trình**

---

## PHẦN 2: TỰ LUẬN (4 CÂU)

---

### 🔹 CÂU 29
**Đề bài:** Cho 2 tiến trình Produce và Consume:
- Produce: `while(1) { Products++; }`
- Consume: `while(1) { Sells++; }`
Biết `Products` và `Sells` ban đầu là $100$ và $20$. Nếu dùng Semaphore $S$ để đồng bộ sao cho luôn đảm bảo $Sells \le Products - 10$, giá trị khởi tạo tối thiểu của Semaphore $S$ là bao nhiêu?

**💡 Lời giải & Kiến thức:**
- Điều kiện: $Sells \le Products - 10 \iff Products - Sells \ge 10 \iff (Products - Sells) - 10 \ge 0$.
- Đặt khoảng chênh lệch cho phép thực hiện hành động $Sells$:
  Ban đầu $Products = 100$, $Sells = 20$.
  Số dư bán hàng tối đa hiện tại $= 100 - 20 - 10 = 70$.
- Tiến trình `Consume` trước khi tăng `Sells` sẽ gọi `wait(S)`. Mỗi lần bán 1 sản phẩm thì $S$ giảm 1.
- Tiến trình `Produce` mỗi lần tạo 1 sản phẩm sẽ gọi `signal(S)` làm $S$ tăng 1.
- Do đó, số lần `Consume` có thể thực hiện ngay lập tức mà không bị chặn chính là $70$.

👉 **Đáp án điền:** **`70`**

---

### 🔹 CÂU 30
**Đề bài:** Trong hệ điều hành, để biểu diễn trạng thái cấp phát tài nguyên của hệ thống, ta có thể sử dụng đồ thị ______

**💡 Lời giải & Kiến thức:**
- Tên tiếng Anh: Resource Allocation Graph (RAG).
- Tiếng Việt: **đồ thị cấp phát tài nguyên**.

👉 **Đáp án điền:** **`cấp phát tài nguyên`** *(hoặc `Resource Allocation Graph` / `RAG`)*

---

### 🔹 CÂU 31
**Đề bài:** Khi sử dụng mutex để đồng bộ tiến trình, nếu tiến trình thực hiện thao tác `acquire()` mutex trong tình trạng mutex đã khóa thì tiến trình sẽ chuyển sang trạng thái ______

**💡 Lời giải & Kiến thức:**
- Khi mutex đang bị khóa bởi tiến trình khác, tiến trình gọi `acquire()` sẽ không thể lấy khóa và bị hệ điều hành đưa vào danh sách chờ $\rightarrow$ Trạng thái **Waiting** (hoặc **Blocked**).

👉 **Đáp án điền:** **`Waiting`** *(hoặc `Blocked` / `chờ`)*

---

### 🔹 CÂU 32
**Đề bài:** Bộ vi xử lý MIPS R2000 có không gian địa chỉ ảo 32 bit với kích thước trang là 4096 bytes ($4\text{KB}$). Như vậy, bảng trang của hệ thống này sẽ có tổng cộng ______ mục.

**💡 Lời giải & Kiến thức:**
- Không gian địa chỉ $32 \text{ bit} \implies 2^{32} \text{ bytes}$.
- Kích thước trang $= 4096 \text{ bytes} = 2^{12} \text{ bytes}$.
- Số trang (số mục trong bảng trang):
  $$\text{Số mục} = \frac{2^{32}}{2^{12}} = 2^{20} = 1,048,576 \text{ mục}$$

👉 **Đáp án điền:** **`1048576`** *(hoặc `2^20`)*

---

## 🎯 CẨM NANG CHIẾN THUẬT ÔN THI MÔN IT007

1. **Luyện thành thạo bài tập Thay thế trang (Page Replacement):**
   - Lập bảng từng bước cho FIFO, LRU, OPT.
   - Nhớ kỹ định nghĩa Belady Anomaly (xảy ra ở FIFO, không xảy ra ở LRU/OPT vì chúng thuộc lớp Stack Algorithms).
2. **Tính toán Địa chỉ & TLB:**
   - Thuộc lòng: $p = \lfloor \text{address} / \text{pagesize} \rfloor$, $d = \text{address} \pmod{\text{pagesize}}$.
   - Thuộc công thức EAT: $\text{EAT} = \alpha(\epsilon + m) + (1-\alpha)(\epsilon + 2m)$.
3. **Đồng bộ Tiến trình & Semaphore:**
   - Phân biệt Semaphore đếm (Counting Semaphore) vs Mutex (Binary).
   - Nắm quy tắc khởi tạo Semaphore để ép thứ tự thực thi: Muốn $B$ chạy sau $A$, khởi tạo `synch = 0`, $A$ gọi `signal`, $B$ gọi `wait`.
4. **Bảng Banker & Đồ thị RAG:**
   - Luôn tính trước ma trận $Need = Max - Allocation$.
   - Kiểm tra điều kiện $Request \le Need$ và $Request \le Available$ trước khi chạy giải thuật thử nghiệm.