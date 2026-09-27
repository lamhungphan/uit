# Bảng chuyển đổi Thập phân sang Nhị phân ($2^0$ đến $2^{20}$)

| **Luỹ thừa** | **Hệ Thập phân (Bytes)** | **Hệ Nhị phân (Binary)** | **Dung lượng (KB)** |
| :---: | :---: | :---: | :---: |
| $2^{0}$ | 1 | `1` | 0.0009765625 KB |
| $2^{1}$ | 2 | `10` | 0.001953125 KB |
| $2^{2}$ | 4 | `100` | 0.00390625 KB |
| $2^{3}$ | 8 | `1000` | 0.0078125 KB |
| $2^{4}$ | 16 | `10000` | 0.015625 KB |
| $2^{5}$ | 32 | `100000` | 0.03125 KB |
| $2^{6}$ | 64 | `1000000` | 0.0625 KB |
| $2^{7}$ | 128 | `10000000` | 0.125 KB |
| $2^{8}$ | 256 | `100000000` | 0.25 KB |
| $2^{9}$ | 512 | `1000000000` | 0.5 KB |
| $2^{10}$ | 1,024 | `10000000000` | **1 KB** |
| $2^{11}$ | 2,048 | `100000000000` | **2 KB** |
| $2^{12}$ | 4,096 | `1000000000000` | **4 KB** |
| $2^{13}$ | 8,192 | `10000000000000` | **8 KB** |
| $2^{14}$ | 16,384 | `100000000000000` | **16 KB** |
| $2^{15}$ | 32,768 | `1000000000000000` | **32 KB** |
| $2^{16}$ | 65,536 | `10000000000000000` | **64 KB** |
| $2^{17}$ | 131,072 | `100000000000000000` | **128 KB** |
| $2^{18}$ | 262,144 | `1000000000000000000` | **256 KB** |
| $2^{19}$ | 524,288 | `10000000000000000000` | **512 KB** |
| $2^{20}$ | 1,048,576 | `100000000000000000000` | **1,024 KB (1 MB)** |

> **Quy tắc:** Trong hệ nhị phân, $2^n$ luôn có dạng chữ số `1` đứng đầu, theo sau bởi đúng $n$ chữ số `0`.
> 
> **Cách tính nhanh trên máy tính Casio:**
> - Chuyển sang chế độ hệ cơ số: bấm **`MODE` $\to$ `BASE-N`** (hoặc **`MENU` $\to$ `3`** trên FX-580VN X).
> - Để chuyển đổi giá trị lũy thừa $2^n$ hoặc tính toán nhanh:
>   - Nhập giá trị cơ số 10 (DEC) $\to$ ấn `=` $\to$ ấn nút **`BIN`** (thường ở phím `log` hoặc `x²` tùy dòng máy) để đổi sang nhị phân.
>   - Đơn vị tính cơ bản trong máy tính: $1 \text{ KB} = 1024 \text{ Bytes} = 2^{10} \text{ Bytes}$.

# Tính thời gian truy xuất bộ nhớ hiệu dụng (EAT)
## 1.
Xét một hệ thống sử dụng kỹ thuật phân trang, với bảng trang được lưu trữ trong bộ nhớ chính. Thời gian cho một lần truy xuất bộ nhớ bình thường là $250\text{ ns}$. Nếu sử dụng TLBs với hit-ratio (tỷ lệ tìm thấy) là $85\%$, thời gian để tìm trong TLBs xem như bằng $0$, thì thời gian truy xuất bộ nhớ trong hệ thống là khoảng bao nhiêu?

* **TLB hit ($85\%$):** 
  * Chỉ cần $1$ lần truy xuất bộ nhớ chính (để lấy dữ liệu).
  * $\text{Thời gian} = 250\text{ ns}$

* **TLB miss ($15\%$):** 
  * Cần $2$ lần truy xuất bộ nhớ chính ($1$ lần truy xuất bảng trang + $1$ lần truy xuất dữ liệu).
  * $\text{Thời gian} = 250\text{ ns} + 250\text{ ns} = 500\text{ ns}$

$$\text{EAT} = 0.85 \times 250 + 0.15 \times 500 = 212.5 + 75 = 287.5\text{ ns} $$

--- 

# Tiểu kết

## Câu 1. Hiện tượng phân mảnh ngoại có thể được giải quyết bằng phương pháp kết khối (compaction). Chọn phát biểu khi nói về phương pháp này?
- Việc kết khối được thực hiện trong giai đoạn thực thi
- Phương pháp kết khối chỉ khả thi khi hệ thống có thể linh hoạt tái định vị địa chỉ
- Các vùng nhớ được trộn để gom tất cả vùng nhớ trống lại với nhau để hình thành 1 vùng nhớ trống lớn hơn

## Câu 2. Xét một không gian địa chỉ luận lý cần 20 bit để biểu diễn địa chỉ. Biết rằng 12 trang trong không gian này được ánh xạ vào bộ nhớ vật lý có 36 khung trang. Vậy ta cần bao nhiêu bit để biểu diễn một địa chỉ vật lý?
- Số trang trong không gian địa chỉ luận lý = 12 trang.
  - Để định danh $12$ trang, ta dùng $p = \lceil \log_2(12) \rceil = 4$ bit dành cho số trang (page number).

- Tổng độ dài địa chỉ luận lý = $20$ bit. 
  - Kích thước độ lệch (offset/page offset) $d = 20 - 4 = 16$ bit.
  - Do đó, kích thước một trang/khung trang là $2^{16}$ bytes.

- Bộ nhớ vật lý có $36$ khung trang (frame).   
  - Số bit cần để biểu diễn số khung trang (frame number $f$) là $f_{bits} = \lceil \log_2(36) \rceil = 6$ bit (vì $2^5 = 32 < 36 \le 64 = 2^6$).

- Kích thước địa chỉ vật lý = (Số bit biểu diễn khung trang) + (Kích thước offset $d$)
  - Địa chỉ vật lý $= 6 + 16 = 22$ bit

## Câu 3. Trong kỹ thuật phân trang, mục đích của việc thiết lập bảng trang là gì?
- a. **Chuyển địa chỉ luận lý thành địa chỉ vật lý** Bảng trang (page table) chứa thông tin ánh xạ từ số trang (page number) của địa chỉ luận lý sang số khung trang (frame number) của địa chỉ vật lý.

- b, c: Kỹ thuật phân trang loại bỏ phân mảnh ngoại nhưng vẫn phát sinh phân mảnh nội ở trang cuối cùng.

- d. Phân bổ bộ nhớ vật lý mỗi khi có sẵn: Đây là chức năng cấp phát bộ nhớ của hệ điều hành, không phải mục đích tồn tại của bảng trang.

## Câu 4. Không gian địa chỉ luận lý là gì?
- Tập hợp tất cả các địa chỉ luận lý được tạo ra bởi một chương trình

## Câu 5. Trong kỹ thuật paging, bộ nhớ vật lý được chia thành các khối, ý nào sau đây mô tả đúng về các khối này?
- Kích thước mỗi khối là bằng nhau và cố định trong khoảng 512 bytes đến 16Mbytes

## Câu 6. Nếu không sử dụng TLBs, hệ điều hành cần truy cập bộ nhớ chính bao nhiêu lần cho một thao tác truy cập lệnh/dữ liệu?
- Khi không dùng TLB (Translation Lookaside Buffer), mỗi thao tác truy cập dữ liệu/lệnh yêu cầu 2 lần truy cập bộ nhớ chính (RAM)
  - Lần 1: Truy cập vào bảng trang (Page Table) trong RAM để lấy địa chỉ khung trang vật lý.
  - Lần 2: Truy cập vào vị trí dữ liệu/lệnh thực sự trong RAM.

## Câu 7. Chọn phát biểu SAI khi nói về Translation Look-Aside Buffer (TLB)?
- a. TLB giúp cho thao tác truy xuất lệnh/dữ liệu trở nên nhanh hơn

→ ĐÚNG (mục đích chính của TLB là tăng tốc độ chuyển đổi địa chỉ).

- b. Xác suất tìm thấy trang trong TLB là trên 90%

→ ĐÚNG (tỷ lệ TLB hit rate thực tế thường đạt từ 90% đến 99%).

- c. TLB được lưu trên cache do đó có tốc độ truy xuất rất nhanh

→ SAI. TLB không nằm trên bộ nhớ đệm Cache thông thường mà là một vùng bộ nhớ liên kết (associative memory / SRAM) tích hợp trực tiếp bên trong MMU (Memory Management Unit) của CPU.

- d. Kích thước của TLB thường rất nhỏ

→ ĐÚNG (chỉ chứa từ 64 đến 1024 dòng).

## Câu 8. Chọn phát biểu đúng khi nói về việc truy cập bộ nhớ?
- a. Lập trình viên phải xác định tập không gian địa chỉ mà tiến trình được phép truy cập

→ SAI (Việc quản lý và bảo vệ không gian địa chỉ do Hệ điều hành và MMU đảm nhận, lập trình viên không cần can thiệp thủ công).

- b. Một tiến trình chỉ có thể truy cập được những địa chỉ trong không gian địa chỉ của chính nó

→ ĐÚNG. Đây là nguyên tắc bảo vệ bộ nhớ (Memory Protection) cốt lõi của Hệ điều hành nhằm tránh việc một tiến trình xâm phạm bộ nhớ của tiến trình khác hay của Kernel.

## Câu 9. Thời gian truy xuất bộ nhớ bình thường $m = 184\text{ ns}$, tỉ lệ hit TLB $\alpha = 95\% = 0.95$, thời gian truy xuất TLB $\epsilon = 20\text{ ns}$. Tính thời gian truy xuất hiệu dụng (EMAT - Effective Memory Access Time).
- Trường hợp TLB Hit ($\alpha = 95\%$): Thời gian $= 20 + 184 = 204\text{ ns}$
- Trường hợp TLB Miss ($1 - \alpha = 5\%$): Thời gian $= 20 + 184 + 184 = 388\text{ ns}$
- $\text{EMAT} = 0.95 \times 204 + 0.05 \times 388 = 193.8 + 19.4 = 213.2\text{ ns}$

## Câu 10. Cho bảng trang (Page Table):

Page 0 $\rightarrow$ Frame 7

Page 1 $\rightarrow$ Frame 4

Page 2 $\rightarrow$ Frame 9

Page 3 $\rightarrow$ Frame 2

Page 4 $\rightarrow$ Frame 5

Page 5 $\rightarrow$ Frame 6

Kích thước trang (Page Size) $= 2\text{ Kbytes} = 2048\text{ bytes}$. Tìm địa chỉ vật lý tương ứng với địa chỉ ảo 8576.

- Xác định số trang (Page Number - $p$) và Độ lệch (Offset - $d$):
  - Số trang $p = \lfloor \frac{8576}{2048} \rfloor = 4$
  - Độ lệch $d = 8576 \pmod{2048} = 8576 - (4 \times 2048) = 8576 - 8192 = 384$
 
- Tra bảng trang
  - Với $p = 4$, khung trang tương ứng là $f = 5$.

- Tính địa chỉ vật lý (Physical Address)
  - $\text{Địa chỉ vật lý} = (f \times \text{Page Size}) + d$
  - $\text{Địa chỉ vật lý} = (5 \times 2048) + 384 = 10240 + 384 = 10624$

## Câu 11. Phần cứng thực hiện việc ánh xạ địa chỉ ảo thành địa chỉ vật lý được gọi là?
- MMU là viết tắt của Memory Management Unit (Đơn vị quản lý bộ nhớ), đây là thiết bị phần cứng đảm nhận vai trò dịch địa chỉ ảo/luận lý sang địa chỉ vật lý

## Câu 12. Xét một không gian địa chỉ luận lý có 18 trang, mỗi trang có kích thước là 4K. Như vậy ta cần bao nhiêu bit để biểu diễn cho một địa chỉ luận lý trong không gian này?
- Số bit cho số trang (Page Number - $p$)
  - Số trang = $18$ trang.
  - Số bit để biểu diễn 18 trang: $p = \lceil \log_2(18) \rceil = 5$ bit (vì $2^4 = 16 < 18 \le 32 = 2^5$).
- Số bit cho độ lệch (Offset - $d$):
  - Kích thước 1 trang = $4\text{ KB} = 4 \times 1024\text{ bytes} = 4096\text{ bytes} = 2^{12}\text{ bytes}$. 
  - Số bit dành cho offset: $d = 12$ bit.
- Tổng số bit địa chỉ luận lý:
  - $\text{Địa chỉ luận lý} = p + d = 5 + 12 = 17$ bit.

## Câu 13. Điền vào chỗ trống:
"Để hiện thực cơ chế phân trang, ta cần lưu bảng trang trong [1]. Để tìm đến vị trí chính xác của bảng trang, ta cần sử dụng thanh ghi [2]. Kích thước của bảng trang được lưu trong thanh ghi [3]."

- [1]: Main memory / Bộ nhớ chính
- [2]: Page-table base register (PTBR)
- [3]: Page-talbe lengh register (PTLR)

## Câu 14. Nếu vị trí bộ nhớ được biết trước thì (mã tuyệt đối) absolute code có thể được tạo" là mô tả nói về việc gán địa chỉ của các lệnh và dữ liệu vào giai đoạn nào?
- Compile time (Thời gian biên dịch): Nếu vị trí bộ nhớ của tiến trình được biết trước tại thời điểm biên dịch, trình biên dịch có thể sinh ra mã tuyệt đối (absolute code).

- Load time (Thời gian nạp): Nếu vị trí bộ nhớ không được biết tại thời điểm biên dịch, trình biên dịch sinh mã tái định vị (relocatable code). Việc gán địa chỉ thực sự diễn ra khi tiến trình được nạp vào bộ nhớ.

- Execution time / Run time (Thời gian thực thi): Địa chỉ được gán và dịch động trong lúc tiến trình đang chạy (cần hỗ trợ từ phần cứng MMU).

## Câu 15. Cho bảng trang (Page Table):

Page 0 $\rightarrow$ Frame 4

Page 1 $\rightarrow$ Frame 8

Page 2 $\rightarrow$ Frame 1

Page 3 $\rightarrow$ Frame 2

Page 4 $\rightarrow$ Frame 9

Page 5 $\rightarrow$ Frame 3

Kích thước mỗi frame (Frame Size) $= 1\text{ Kbytes} = 1024\text{ bytes}$. Tìm địa chỉ luận lý có ánh xạ tương ứng với địa chỉ vật lý 

- Xác định số trang Số khung trang (Frame Number - $f$) và và Độ lệch (Offset - $d$):
  - Số Số khung trang $f = \lfloor \frac{2099}{1024} \rfloor = 2$
  - Độ lệch $d = 2099 \pmod{1024} = 2099 - (2 \times 1024) = 2099 - 2048 = 51$
 
- Tra bảng trang
  - Khung trang $f = 2$ ánh xạ ngược lại tương ứng với trang Page $p = 3$ .

- Tính địa chỉ vật lý (Physical Address)
  - $\text{Địa chỉ luận lý} = (p \times \text{Page Size}) + d$
  - $\text{Địa chỉ luận lý} = (3 \times 1024) + 51 = 3072 + 51 = 3123$