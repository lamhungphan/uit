## 1. Khái niệm cơ sở

- **Quản lý bộ nhớ**: công việc của HĐH với sự hỗ trợ của phần cứng nhằm phân phối, sắp xếp tiến trình trong bộ nhớ hiệu quả
- **Mục tiêu**: nạp càng nhiều tiến trình vào bộ nhớ càng tốt (tăng mức độ đa chương)
- Kernel chiếm phần cố định, còn lại phân phối cho tiến trình

### Các yêu cầu với quản lý bộ nhớ
1. Cấp phát bộ nhớ cho tiến trình
2. Tái định vị (relocation): khi swapping,...
3. Bảo vệ: kiểm tra truy xuất bộ nhớ hợp lệ
4. Chia sẻ: cho phép tiến trình chia sẻ vùng nhớ chung
5. Kết gán địa chỉ luận lý vào địa chỉ thực

## 2. Các kiểu địa chỉ nhớ

| Kiểu | Mô tả |
|---|---|
| **Physical address** | Vị trí thực trong bộ nhớ chính |
| **Logical address** | Vị trí nhớ trong chương trình (còn gọi là virtual address) |
| **Absolute address** | Địa chỉ tương đương với địa chỉ thực |
| **Relative address** | Địa chỉ khả tái định vị, biểu diễn tương đối so với vị trí xác định |

## 3. Chuyển đổi địa chỉ

### Ba thời điểm chuyển đổi

| Thời điểm | Cơ chế | Ví dụ |
|---|---|---|
| **Compile time** | Biết trước địa chỉ bộ nhớ → địa chỉ tuyệt đối | MS-DOS .COM |
| **Load time** | Loader chuyển địa chỉ khả tái định vị thành địa chỉ thực dựa trên địa chỉ nền | Phải reload nếu địa chỉ nền thay đổi |
| **Execution time** | Trì hoãn đến thời điểm thực thi, cần phần cứng hỗ trợ (base/limit register) | Swapping, paging, segmentation |

### Dynamic Linking
- Link module ngoài (DLL - Windows, .so - Unix) sau khi tạo load module
- **Stub** tham chiếu đến routine, khi gọi lần đầu stub nạp routine vào bộ nhớ
- **Ưu điểm**: chia sẻ mã, tiết kiệm bộ nhớ và đĩa

### Dynamic Loading
- Thủ tục chỉ được nạp vào bộ nhớ khi được gọi đến
- Hiệu quả với mã có tần suất sử dụng thấp (vd: xử lý lỗi)

## 4. Mô hình quản lý bộ nhớ

### 4.1. Fixed Partitioning
- Bộ nhớ chia thành các partition cố định (bằng nhau hoặc khác nhau)
- **Phân mảnh nội (internal fragmentation)**: tiến trình nhỏ vẫn chiếm trọn partition
- Giải pháp: partition không bằng nhau, gán tiến trình vào partition nhỏ nhất phù hợp

### 4.2. Dynamic Partitioning
- Số lượng partition không cố định, kích thước tùy theo tiến trình
- Gây **phân mảnh ngoại (external fragmentation)**: không gian trống không liên tục
- Giải pháp: **compaction** (kết khối)
- **Chiến lược placement**:
  - **Best-fit**: chọn khối trống nhỏ nhất
  - **First-fit**: chọn khối trống phù hợp đầu tiên
  - **Next-fit**: chọn khối phù hợp từ vị trí cấp phát cuối
  - **Worst-fit**: chọn khối trống lớn nhất

## 5. Cơ chế phân trang (Paging)

- Chia bộ nhớ vật lý thành **frames** (cố định, 512B - 16MB)
- Chia bộ nhớ luận lý thành **pages** (bằng kích thước frame)
- Dùng **Page Table** để ánh xạ địa chỉ luận lý → địa chỉ thực

### Địa chỉ luận lý
```
| page number (p) | page offset (d) |
```
- p: m-n bits, d: n bits
- Nếu không gian ảo = 2^m, page size = 2^n → bảng trang có 2^(m-n) mục

--- 

### Cài đặt bảng trang
- **PTBR** (Page-Table Base Register): trỏ đến bảng trang
- **PTLR** (Page-Table Length Register): kích thước bảng trang
- Mỗi truy cập cần 2 lần access bộ nhớ → dùng **TLB** (Translation Look-aside Buffer)

### EAT (Effective Access Time)
```
EAT = (ε + x)α + (ε + 2x)(1 - α) = (2 - α)x + ε
```
- ε: thời gian tìm TLB, x: chu kỳ truy xuất bộ nhớ, α: hit ratio

### Tổ chức bảng trang
- **Phân trang 2 cấp** (hoặc đa cấp) cho không gian ảo lớn
- **Bảng trang nghịch đảo**: dùng cho tất cả tiến trình, lưu <IDP, p, d>

### Bảo vệ bộ nhớ
- **Protection bits**: read-only, read-write, execute-only
- **Valid/Invalid bit**: valid = trang hợp lệ, invalid = trang bất hợp lệ

## 6. Cơ chế Swapping

- Tiến trình tạm thời bị swap ra khỏi bộ nhớ chính, lưu trên bộ nhớ phụ
- **Round-robin**: swap out P1 hết quantum, swap in P2
- **Roll out/roll in**: dùng trong priority-based scheduling
