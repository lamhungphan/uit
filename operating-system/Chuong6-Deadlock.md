## 1. Vấn đề Deadlock

### 1.1. Định nghĩa
- **Deadlock**: tập các tiến trình bị block, mỗi tiến trình giữ tài nguyên và đang chờ tài nguyên mà tiến trình khác trong tập đang giữ
- **Deadlock process**: tiến trình đang đợi một sự kiện sẽ không bao giờ xảy ra
- **Starvation**: tiến trình bị trì hoãn lặp đi lặp lại, không bao giờ nhận được CPU

### 1.2. 4 điều kiện cần để xảy ra deadlock
| Điều kiện | Mô tả |
|---|---|
| **(1) Mutual exclusion** | Ít nhất một tài nguyên ở chế độ nonsharable (vd: printer ≠ read-only files) |
| **(2) Hold and wait** | Tiến trình giữ ít nhất một tài nguyên và đang chờ thêm tài nguyên do tiến trình khác giữ |
| **(3) No preemption** | Tài nguyên không thể bị lấy lại, chỉ được trả lại từ tiến trình đang giữ |
| **(4) Circular wait** | Tồn tại tập {P0,...,Pn} sao cho P0 chờ tài nguyên P1 giữ, P1 chờ tài nguyên P2 giữ, ..., Pn chờ tài nguyên P0 giữ |

## 2. Mô hình hóa hệ thống

### 2.1. Đồ thị cấp phát tài nguyên (RAG)
- Đồ thị có hướng với tập đỉnh V = P (tiến trình) ∪ R (tài nguyên)
- **Cạnh yêu cầu**: Pi → Rj (Pi yêu cầu tài nguyên Rj)
- **Cạnh cấp phát**: Rj → Pi (Pi đang giữ tài nguyên Rj)

### 2.2. RAG và Deadlock
- **Không có chu trình** → không deadlock
- **Có chu trình**:
  - Mỗi loại tài nguyên chỉ có 1 thực thể → **deadlock**
  - Mỗi loại tài nguyên có nhiều thực thể → **có thể deadlock**

## 3. Các phương pháp giải quyết deadlock

### 3.1. Ngăn deadlock (Prevention)
Ngăn ít nhất một trong 4 điều kiện cần:
- **Mutual exclusion**: không thể ngăn với tài nguyên không chia sẻ (printer)
- **Hold and wait**: yêu cầu toàn bộ tài nguyên một lần, hoặc không giữ tài nguyên nào khi yêu cầu
- **No preemption**: lấy lại tài nguyên từ tiến trình đang giữ nếu yêu cầu không được đáp ứng ngay
- **Circular wait**: gán thứ tự cho tất cả tài nguyên, tiến trình chỉ yêu cầu theo thứ tự tăng dần

### 3.2. Tránh deadlock (Avoidance)
- Yêu cầu tiến trình khai báo số lượng tài nguyên tối đa cần
- **Trạng thái an toàn (safe state)**: tồn tại một chuỗi an toàn
- **Chuỗi an toàn**: <P1, P2, ..., Pn> sao cho yêu cầu tối đa của Pi có thể thỏa bởi tài nguyên sẵn sàng + tài nguyên các Pj (j < i) đang giữ
- Hệ thống safe → không deadlock; unsafe → có thể dẫn đến deadlock

#### Giải thuật Banker
- Dùng cho mỗi loại tài nguyên có nhiều thực thể
- Các ma trận: **Available**, **Max**, **Allocation**, **Need** (= Max - Allocation)
- Yêu cầu Requesti:
  1. Nếu Requesti ≤ Needi → bước 2, nếu không → báo lỗi
  2. Nếu Requesti ≤ Available → bước 3, nếu không → Pi phải chờ
  3. Giả định cấp phát: Available -= Requesti; Allocationi += Requesti; Needi -= Requesti
  4. Kiểm tra trạng thái safe → nếu safe thì cấp thật, nếu không thì phục hồi và Pi chờ

### 3.3. Phát hiện deadlock (Detection)

#### Mỗi loại tài nguyên có 1 thực thể
- Dùng **Wait-for graph** (Pi → Pj nếu Pi chờ tài nguyên từ Pj)
- Nếu có chu trình → deadlock
- Độ phức tạp O(n²)

#### Mỗi loại tài nguyên có nhiều thực thể
- Dùng giải thuật phát hiện với ma trận **Request** và **Allocation**
- Độ phức tạp O(m·n²)

### 3.4. Phục hồi (Recovery)
- **Chấm dứt tiến trình**: chấm dứt lần lượt từng tiến trình đến khi hết deadlock
- **Lấy lại tài nguyên**: lấy tài nguyên từ tiến trình, cấp cho tiến trình khác
  - Chọn nạn nhân (victim) để tối thiểu chi phí
  - **Rollback**: đưa tiến trình về trạng thái safe
  - Cần tránh **starvation** (không để tiến trình luôn bị lấy lại tài nguyên)
