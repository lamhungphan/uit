# TRƯỜNG ĐẠI HỌC CÔNG NGHỆ THÔNG TIN - TRUNG TÂM PHÁT TRIỂN CNTT
**ĐỀ THI CUỐI HỌC KỲ: II (2024-2025)**  
**MÔN: HỆ ĐIỀU HÀNH (MÃ ĐỀ: 001 / IT007)**  
*Thời gian làm bài: 75 phút*

---

## 📋 BẢNG ĐÁP ÁN TỔNG HỢP

### PHẦN 1: TRẮC NGHIỆM (6.0 điểm)

| CÂU | ĐÁP ÁN | CÂU | ĐÁP ÁN | CÂU | ĐÁP ÁN | CÂU | ĐÁP ÁN |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Câu 1** | **C** | **Câu 6** | **C** | **Câu 11** | **B** | **Câu 16** | **B** |
| **Câu 2** | **C** | **Câu 7** | **C** | **Câu 12** | **B** | **Câu 17** | **C** |
| **Câu 3** | **A** | **Câu 8** | **C** | **Câu 13** | **B** | **Câu 18** | **B** |
| **Câu 4** | **B** | **Câu 9** | **C** | **Câu 14** | **B** | **Câu 19** | **A** |
| **Câu 5** | **C** | **Câu 10** | **A** | **Câu 15** | **B** | **Câu 20** | **A** |

---

### PHẦN 2: TỰ LUẬN (4.0 điểm)

| CÂU | VỊ TRÍ | ĐÁP ÁN ĐIỀN |
| :---: | :---: | :--- |
| **Câu 21** | **(a)** | **8** *(lỗi trang đã phát sinh trước khi truy xuất trang 3)* |
| | **(b)** | **1** *(hoặc **6**, **0**)* |
| **Câu 22** | **(a)** | `wait(S);` |
| | **(b)** | `BLANK` |
| | **(c)** | `BLANK` |
| | **(d)** | `signal(S);` |
| **Câu 23** | **(a)** | **Vùng 6** *(280 KB)* |
| | **(b)** | **Vùng 1** *(340 KB)* |

---

## 🔍 GIẢI THÍCH CHI TIẾT CÁC CÂU HỎI

### PHẦN 1: TRẮC NGHIỆM

#### **Câu 1: C**
* **Lý do:** Binary semaphore chỉ nhận hai giá trị duy nhất là `0` và `1`, thường được sử dụng cho mục đích đồng bộ hóa và loại trừ tương hỗ (mutual exclusion).

#### **Câu 2: C**
* **Lý do:** Để triển khai bộ nhớ ảo (Virtual Memory), hệ thống bắt buộc phải có sự hỗ trợ từ phần cứng (cơ chế phân trang / MMU) và sự quản lý của HĐH trong việc luân chuyển các trang giữa RAM và đĩa cứng (Paging/Swapping).

#### **Câu 3: A**
* **Lý do:**
  * Kích thước khung trang: $1	ext{ KB} = 1024	ext{ bytes}$.
  * Địa chỉ vật lý $PA = 4567$.
  * Số hiệu khung trang (Frame number) $= \lfloor 4567 / 1024 
floor = 4$.
  * Độ lệch (Offset) $= 4567 \pmod{1024} = 467$.
  * Tra bảng trang: Khung trang $4$ ứng với trang luận lý $3$.
  * Địa chỉ luận lý $LA = (3 	imes 1024) + 467 = 3072 + 467 = \mathbf{3543}$.

#### **Câu 4: B**
* **Lý do:** Critical Section (miền găng) là đoạn mã (code segment) trong chương trình có thực hiện truy cập hoặc thao tác trên tài nguyên/dữ liệu dùng chung.

#### **Câu 5: C**
* **Lý do:** Lời giải bài toán miền găng bắt buộc thỏa mãn 3 điều kiện:
  1. **Mutual Exclusion** (Loại trừ tương hỗ) — điều kiện (1).
  2. **Progress** (Tiến triển) — điều kiện (3).
  3. **Bounded Waiting** (Chờ có giới hạn) — điều kiện (4).

#### **Câu 6: C**
* **Lý do:** Mục tiêu quan trọng nhất của quản lý bộ nhớ là duy trì và gia tăng mức độ đa chương (degree of multiprogramming), cho phép nhiều tiến trình cùng tồn tại trong bộ nhớ để nâng cao hiệu suất CPU.

#### **Câu 7: C**
* **Lý do:** Khi xảy ra lỗi trang (Page Fault), tiến trình sẽ bị ngắt và chuyển sang trạng thái **Waiting/Blocked** để chờ HĐH đọc trang từ đĩa vào RAM, không bao giờ chuyển trực tiếp về Ready ở bước này.

#### **Câu 8: C**
* **Lý do:** Bộ nhớ ảo là kỹ thuật tách biệt bộ nhớ luận lý của người dùng khỏi bộ nhớ vật lý, cho phép thực thi tiến trình có không gian địa chỉ lớn hơn dung lượng RAM thực tế.

#### **Câu 9: C**
* **Lý do:** Địa chỉ tuyệt đối (Absolute Address) là địa chỉ vật lý thực sự trong RAM. Địa chỉ tương đối (Relative/Logical Address) được tính dựa trên vị trí tương đối so với một địa chỉ gốc (Base Address).

#### **Câu 10: A**
* **Lý do:**
  * Số trang $= 124 \le 2^7 \implies$ Cần **7 bit** để định danh số hiệu trang.
  * Kích thước trang $= 2	ext{ MB} = 2^{21}	ext{ bytes} \implies$ Cần **21 bit** biểu diễn offset.
  * Tổng số bit luận lý $= 7 + 21 = \mathbf{28	ext{ bit}}$.

#### **Câu 11: B**
* **Lý do:** Xử lý lỗi trang yêu cầu thao tác I/O đọc đĩa (tốn nhiều thời gian), do đó HĐH sẽ đưa tiến trình vào trạng thái **Waiting** (Chờ).

#### **Câu 12: B**
* **Lý do:** Thuật toán OPT (Optimal) sẽ thay thế trang nhớ không được sử dụng trong thời gian dài nhất ở **tương lai**.

#### **Câu 13: B**
* **Lý do:**
  * Thời gian truy xuất TLB: $25	ext{ ns}$.
  * Thời gian truy xuất RAM: $300	ext{ ns}$.
  * Hit ratio: $lpha = 0.85$.
  * $EAT = lpha 	imes (t_{TLB} + t_{RAM}) + (1 - lpha) 	imes (t_{TLB} + 2 	imes t_{RAM})$
  * $EAT = 0.85 	imes (25 + 300) + 0.15 	imes (25 + 300 + 300) = 276.25 + 93.75 = \mathbf{370	ext{ ns}}$.

#### **Câu 14: B**
* **Lý do:** Để giải quyết busy waiting (chờ bận), HĐH cung cấp hai thao tác nguyên tử là `block()` (đưa tiến trình vào hàng đợi chờ) và `wakeup()` (đưa tiến trình trở lại Ready).

#### **Câu 15: B**
* **Lý do:** Dynamic Loading (nạp động) giúp tiết kiệm bộ nhớ bằng cách chỉ nạp các thủ tục/module vào RAM khi chúng thực sự được chương trình gọi tới.

#### **Câu 16: B**
* **Lý do:** Các tiến trình cộng tác phải giải quyết đồng thời các vấn đề: đảm bảo tính nhất quán dữ liệu, tránh tình trạng bế tắc (deadlock) và tránh đói tài nguyên (starvation).

#### **Câu 17: C**
* **Lý do:** Điều kiện Bounded Waiting đặt ra giới hạn về số lần các tiến trình khác được vào miền găng sau khi một tiến trình đã yêu cầu, nhằm đảm bảo tiến trình không bị tình trạng starvation (đói tài nguyên).

#### **Câu 18: B**
* **Lý do:** Giá trị semaphore $S < 0$ có độ lớn $|S|$ đúng bằng **số lượng tiến trình đang bị chặn** (blocked) và nằm trong hàng đợi chờ của semaphore đó. Vì $S = -4 \implies$ có 4 tiến trình đang bị chặn.

#### **Câu 19: A**
* **Lý do:** Thứ tự xử lý chuẩn: Trình biên dịch (**Compiler**) tạo mã máy $	o$ Trình liên kết (**Linker**) kết nối thư viện/file object $	o$ Trình nạp (**Loader**) nạp chương trình vào RAM để chạy.

#### **Câu 20: A**
* **Lý do:** Để ép $S_1$ chạy trước $S_2$:
  * $P_2$ muốn chạy $S_2$ phải qua `wait(synch)`.
  * Ban đầu khởi tạo $synch = 0$, nếu $P_2$ chạy trước nó sẽ gọi `wait(synch)` làm $synch$ thành $-1$ và $P_2$ bị block.
  * Sau khi $P_1$ thực thi $S_1$ xong, nó gọi `signal(synch)` tăng $synch$ lên $0$ và đánh thức $P_2$ thực thi $S_2$.

---

### PHẦN 2: TỰ LUẬN

#### **Câu 21: Thuật toán thay thế trang LRU (4 Khung trang)**
* **Chuỗi truy xuất:** `2, 1, 2, 5, 6, 4, 0, 1, 4, 7, 1, 3, 6, 7, 1, 3, 5, 0`
* **Diễn biến nạp trang:**
  1. `2` $	o$ [2] *(Lỗi 1)*
  2. `1` $	o$ [2, 1] *(Lỗi 2)*
  3. `2` $	o$ [2, 1] *(Hit)*
  4. `5` $	o$ [2, 1, 5] *(Lỗi 3)*
  5. `6` $	o$ [2, 1, 5, 6] *(Lỗi 4)*
  6. `4` $	o$ Thay `2` $\implies$ [4, 1, 5, 6] *(Lỗi 5)*
  7. `0` $	o$ Thay `1` $\implies$ [4, 0, 5, 6] *(Lỗi 6)*
  8. `1` $	o$ Thay `5` $\implies$ [4, 0, 1, 6] *(Lỗi 7)*
  9. `4` $	o$ [4, 0, 1, 6] *(Hit)*
  10. `7` $	o$ Thay `6` $\implies$ [4, 0, 1, 7] *(Lỗi 8)*
  11. `1` $	o$ [4, 0, 1, 7] *(Hit)*
  12. `3` $	o$ Thay `0` $\implies$ [4, 3, 1, 7] *(Lỗi 9 - lần đầu xuất hiện 3)*

* **Kết quả:**
  * **(a):** Trước khi nạp trang `3` ở bước 12, đã có **8 lỗi trang** phát sinh.
  * **(b):** Thống kê các trang hy sinh toàn bộ chuỗi: Trang `1`, `6`, `0` đều bị thay thế 2 lần (Trang `1` hy sinh ở bước 7 & 18; Trang `6` ở bước 10 & 17; Trang `0` ở bước 12 & 16). Điền **1** (hoặc **6**, **0**).

---

#### **Câu 22: Đồng bộ tiến trình P1 và P2**
* **Yêu cầu:** Tính $y = x / 2$ thì $x$ phải có giá trị trước ($x = 10 	imes 2 = 20$). Do đó $P_2$ phải gán $x$ xong mới cho phép $P_1$ tính $y$.
* **Cấu trúc đoạn mã:**
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

#### **Câu 23: Cấp phát bộ nhớ (Fixed Partitioning)**
* **Trạng thái các phân vùng:**
  * Vùng 1: 340 KB (Trống)
  * Vùng 2: 200 KB (Đã cấp phát)
  * Vùng 3: 250 KB (Trống)
  * Vùng 4: 410 KB (Đã cấp phát, **Con trỏ PC đang ở đây**)
  * Vùng 5: 190 KB (Trống)
  * Vùng 6: 280 KB (Trống)

* **Trả lời:**
  * **a. Next-Fit cho $P = 240	ext{ KB}$:**
    * Duyệt tiếp từ vị trí PC (Vùng 4): Vùng 5 (190 KB < 240 KB $	o$ Bỏ qua) $	o$ Vùng 6 (280 KB $\ge 240	ext{ KB} \implies$ Đủ điều kiện).
    * **Đáp án:** **Vùng 6**
  * **b. Worst-Fit cho $Q = 120	ext{ KB}$:**
    * Tìm phân vùng trống có kích thước LỚN NHẤT trong toàn bộ bộ nhớ.
    * Danh sách vùng trống: Vùng 1 (340 KB), Vùng 3 (250 KB), Vùng 5 (190 KB), Vùng 6 (280 KB).
    * Vùng trống lớn nhất là Vùng 1 (340 KB).
    * **Đáp án:** **Vùng 1**
