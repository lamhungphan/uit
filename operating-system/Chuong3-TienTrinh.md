## 1. Khái niệm cơ bản

- **Tiến trình (process)**: một chương trình đang thực thi.
- **Chương trình**: thực thể bị động lưu trên đĩa (tập tin thực thi).
- **Tiến trình**: thực thể chủ động, được tạo khi tập tin thực thi được nạp vào bộ nhớ.

### Thành phần của một tiến trình
- **Text section**: mã chương trình (program code)
- **Data section**: chứa biến toàn cục (global variables)
- **Program counter** và **processor registers**
- **Heap section**: chứa bộ nhớ cấp phát động
- **Stack section**: chứa dữ liệu tạm thời (tham số hàm, địa chỉ trả về, biến địa phương)

### Các bước khởi tạo tiến trình
1. Cấp phát định danh duy nhất (PID)
2. Cấp phát không gian nhớ để nạp tiến trình
3. Khởi tạo khối dữ liệu PCB (Process Control Block)
4. Thiết lập các mối liên hệ (ví dụ: sắp PCB vào hàng đợi định thời)

---

## 2. Trạng thái tiến trình

| Trạng thái | Ý nghĩa |
|---|---|
| **New** | Tiến trình vừa được tạo |
| **Ready** | Tiến trình đã có đủ tài nguyên, chỉ còn cần CPU |
| **Running** | Các lệnh của tiến trình đang được thực thi |
| **Waiting (Blocked)** | Tiến trình đợi I/O hoàn tất hoặc đợi tín hiệu |
| **Terminated** | Tiến trình đã kết thúc |

### Sơ đồ chuyển đổi trạng thái
```
new → ready → running → waiting → ready → running → terminated
         ↑         ↓
         └─────────┘ (interrupt)
```

---

## 3. Khối điều khiển tiến trình (PCB - Process Control Block)

PCB là cấu trúc dữ liệu quan trọng nhất của HĐH, gồm:
- **Trạng thái tiến trình**: new, ready, running,...
- **Bộ đếm chương trình** (Program Counter)
- **Các thanh ghi** (Registers)
- **Thông tin lập thời biểu CPU**: độ ưu tiên,...
- **Thông tin quản lý bộ nhớ**
- **Thông tin kế toán**: lượng CPU, thời gian sử dụng,...
- **Thông tin trạng thái I/O**

---

## 4. Định thời tiến trình (Scheduling)

### Yêu cầu của HĐH về quản lý tiến trình
- Hỗ trợ thực thi luân phiên giữa nhiều tiến trình
- Hiệu suất sử dụng CPU
- Thời gian đáp ứng
- Phân phối tài nguyên hợp lý
- Tránh deadlock, trì hoãn vô hạn định
- Cung cấp cơ chế giao tiếp và đồng bộ tiến trình
- Cơ chế hỗ trợ user tạo/kết thúc tiến trình

### Tại sao phải định thời?
- **Đa chương**: tận dụng tối đa CPU
- **Chia thời**: tối thiểu thời gian đáp ứng cho user

### 4.1. Các hàng đợi định thời
- **Job queue**: hàng đợi công việc
- **Ready queue**: hàng đợi sẵn sàng
- **Device queue**: hàng đợi thiết bị

### 4.2. Bộ định thời (Scheduler)

| Loại | Tên gọi | Chức năng |
|---|---|---|
| **Dài hạn** | Long-term / Job scheduler | Chọn tiến trình từ đĩa nạp vào bộ nhớ |
| **Ngắn hạn** | Short-term / CPU scheduler | Chọn tiến trình từ ready queue để cấp CPU |
| **Trung hạn** | Medium-term scheduler | Swap in/out tiến trình giữa bộ nhớ và đĩa |

### Chuyển ngữ cảnh (Context Switch)
Quá trình CPU chuyển từ tiến trình này sang tiến trình khác.

---

## 5. Các tác vụ đối với tiến trình

### 5.1. Tạo tiến trình
- Dùng lời gọi hệ thống **create-process** (vd: `fork()` trong Unix)
- Tiến trình tạo = **tiến trình cha**, tiến trình được tạo = **tiến trình con**
- Quan hệ cha-con tạo thành **cây tiến trình**

#### Đặc điểm tạo tiến trình
- Tiến trình con nhận tài nguyên từ OS hoặc từ tiến trình cha
- Chia sẻ tài nguyên: có thể chia sẻ toàn bộ, một phần, hoặc không
- Trình tự thực thi: cha và con thực thi đồng thời, hoặc cha đợi con kết thúc

#### `fork()`
- Tạo tiến trình con bằng cách **sao chép** không gian địa chỉ của tiến trình cha
- Trả về:
  - `> 0`: tiến trình cha
  - `= 0`: tiến trình con
  - `< 0`: thất bại

#### Họ `exec()`
- Nạp tác vụ mới vào không gian địa chỉ của tiến trình gọi
- Tác vụ mới ghi đè lên không gian địa chỉ cũ

### 5.2. Kết thúc tiến trình
- Tiến trình tự kết thúc: thực thi lệnh cuối và gọi `exit`
- Tiến trình kết thúc do tiến trình khác: gọi `abort` với PID
- HĐH thu hồi tất cả tài nguyên (vùng nhớ, I/O buffer,...)

---

## 6. Cộng tác giữa các tiến trình

### Mục đích cộng tác
- Chia sẻ dữ liệu (information sharing)
- Tăng tốc tính toán (computational speedup) - chia công việc chạy song song
- Thực hiện công việc chung: xây dựng phần mềm phức tạp từ các module hợp tác

### 6.1. IPC (Inter Process Communication)
Cơ chế do HĐH cung cấp để các tiến trình giao tiếp và đồng bộ.

**Hai mô hình IPC:**
1. **Shared memory** (bộ nhớ dùng chung)
2. **Message passing** (truyền thông điệp)

### 6.2. Shared Memory
- Vùng nhớ dùng chung giữa các tiến trình
- Giao tiếp do tiến trình điều khiển, không qua HĐH
- Cần cơ chế đồng bộ khi truy xuất bộ nhớ dùng chung

### 6.3. Message Passing
- **Đặt tên (Naming)**:
  - Trực tiếp: `send(P, msg)`, `receive(Q, msg)`
  - Gián tiếp (qua mailbox): `send(A, msg)`, `receive(B, msg)`
- **Đồng bộ hóa**: blocking/nonblocking send, blocking/nonblocking receive
- **Buffering** (vùng đệm):
  - Zero capacity: không có buffer
  - Bounded capacity: queue có giới hạn
  - Unbounded capacity: queue không giới hạn

---

## 7. Tiểu trình (Thread)

### 7.1. Tổng quan
- **Tiểu trình**: đơn vị cơ bản sử dụng CPU, gồm Thread ID, PC, Registers, Stack
- Các thread trong cùng process **chia sẻ** code, data, resources (files)

### So sánh Single-thread vs Multithread
| Single-threaded process | Multithreaded process |
|---|---|
| 1 PC, 1 stack, 1 tập registers | Mỗi thread có PC, stack, registers riêng |
| | Chung code, data, files |

### PCB và TCB
- **PCB** (Process Control Block): PID, danh sách thread, context,...
- **TCB** (Thread Control Block): TID, trạng thái, context (IP, local stack)

### Lợi ích của đa luồng
- **Tính đáp ứng**: chương trình tiếp tục thực thi khi một phần bị khóa
- **Chia sẻ tài nguyên**: dễ dàng, tiết kiệm không gian nhớ
- **Kinh tế**: tạo và chuyển ngữ cảnh nhanh hơn tiến trình (Solaris 2: tạo process chậm hơn 30 lần)
- **Khả năng mở rộng**: thực thi song song trên nhiều lõi xử lý

### Phân loại tiểu trình
- **User thread**: thực thi mã người dùng, quản lý không cần kernel
- **Kernel thread**: thực thi thao tác hệ thống, được HĐH quản lý

### 7.2. Các mô hình đa tiểu trình

#### Many-to-One (Nhiều - Một)
- Nhiều user thread → 1 kernel thread
- Một thread bị block → tất cả bị block
- Không chạy song song trên đa lõi
- Ít được sử dụng

#### One-to-One (Một - Một)
- Mỗi user thread → 1 kernel thread
- Concurrency tốt hơn (thread khác vẫn chạy khi một thread bị block)
- Số lượng thread có thể bị hạn chế
- Windows, Linux sử dụng

#### Many-to-Many (Nhiều - Nhiều)
- Nhiều user thread → nhiều kernel thread
- Giải quyết hạn chế của 2 mô hình trên
- Khó cài đặt, ít phổ biến
