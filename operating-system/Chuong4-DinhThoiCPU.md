## 1. Khái niệm cơ bản về định thời

- **Định thời**: chiến lược chọn tiến trình phù hợp để được thực thi nhằm đạt hiệu quả cao nhất
- Trong hệ thống đa nhiệm, tại mỗi thời điểm chỉ có một tiến trình được thực thi
- **Service time** (burst time): thời gian một tiến trình cần CPU trong một chu kỳ CPU-I/O

### Phân loại tiến trình
| Loại | Đặc điểm | Ví dụ |
|---|---|---|
| **CPU-bound** | Service time lớn, thiên về tính toán | Vòng lặp tính tổng |
| **I/O-bound** | Thiên về nhập/xuất, chờ I/O nhiều | Đọc file |

## 2. Các loại định thời

### 2.1. Định thời dài (Long-term scheduling)
- Xác định chương trình nào được nạp vào hệ thống để thực thi
- Điều khiển **mức độ đa chương** của hệ thống
- Duy trì xen lẫn CPU-bound và I/O-bound processes

### 2.2. Định thời vừa (Medium-term scheduling)
- Quyết định tiến trình nào được **swap in/out** khỏi bộ nhớ chính
- Được thực hiện bởi thành phần quản lý bộ nhớ

### 2.3. Định thời ngắn (Short-term scheduling) = CPU scheduling
- Xác định tiến trình nào trong ready queue sẽ được chiếm CPU
- Được gọi khi có: clock interrupt, I/O interrupt, system call, tín hiệu đồng bộ
- **Dispatch latency**: thời gian bộ định thời dừng một tiến trình và khởi động tiến trình khác

## 3. Các tiêu chuẩn định thời CPU

### Hướng người dùng
| Tiêu chuẩn | Định nghĩa | Mục tiêu |
|---|---|---|
| **Response time** (R) | Thời gian từ lúc gửi yêu cầu đến khi được đáp ứng lần đầu | Cực tiểu |
| **Turnaround time** (T) | Thời gian từ lúc nạp vào hệ thống đến khi kết thúc | Cực tiểu |
| **Waiting time** (W) | Tổng thời gian đợi trong ready queue | Cực tiểu |

Công thức: `R = t0 - r`, `T = f - r`, `W = f - r - E` (E = tổng CPU burst)

### Hướng hệ thống
| Tiêu chuẩn | Mục tiêu |
|---|---|
| **Processor utilization** | Cực đại (CPU càng bận càng tốt) |
| **Throughput** | Cực đại (số tiến trình hoàn tất/đơn vị thời gian) |
| **Fairness** | Tất cả tiến trình được đối xử như nhau |

## 4. Các giải thuật định thời

### Cấu trúc giải thuật định thời
- **Hàm chọn lựa** (selection function): căn cứ để chọn tiến trình
- **Chế độ quyết định** (decision mode):
  - **Non-preemptive**: tiến trình chạy đến khi kết thúc hoặc bị blocked
  - **Preemptive**: tiến trình có thể bị ngắt giữa chừng, chi phí cao hơn nhưng đáp ứng tốt hơn

### 4.1. First-Come, First-Served (FCFS)
- **Chọn**: tiến trình yêu cầu CPU trước được phục vụ trước
- **Chế độ**: non-preemptive
- **Hiện thực**: hàng đợi FIFO
- **Nhược điểm**: thời gian chờ trung bình lớn (hiệu ứng đoàn tàu - convoy effect)

### 4.2. Shortest-Job-First (SJF)
- **Chọn**: tiến trình có CPU burst ngắn nhất
- **Chế độ**: có thể non-preemptive hoặc preemptive (SRTF)
- **Tối ưu**: thời gian chờ trung bình ngắn nhất
- **Vấn đề**: cần ước lượng thời gian CPU burst tiếp theo (dùng exponential averaging)
  - `τn+1 = αtn + (1-α)τn`, với 0 ≤ α ≤ 1
- **Starvation**: tiến trình CPU burst lớn có thể không được thực thi

#### SRTF (Shortest Remaining Time First)
- SJF ở chế độ preemptive
- Khi có tiến trình mới với remaining time nhỏ hơn tiến trình đang chạy → trưng dụng CPU

### 4.3. Priority Scheduling
- Mỗi tiến trình gán một độ ưu tiên, CPU cấp cho tiến trình có độ ưu tiên cao nhất
- Có thể preemptive hoặc non-preemptive
- **Vấn đề**: starvation (trì hoãn vô hạn định) → giải pháp: **aging** (tăng độ ưu tiên theo thời gian)

### 4.4. Round Robin (RR)
- Mỗi tiến trình nhận **quantum time** (10-100ms) để thực thi
- Hết quantum → tiến trình bị đoạt quyền và về cuối ready queue
- Không tiến trình nào chờ quá `(n-1) × q` đơn vị thời gian
- **q lớn** → RR thành FCFS; **q nhỏ** → tốn chi phí chuyển ngữ cảnh
- **Ưu điểm**: thời gian đáp ứng nhỏ
- **Hạn chế**: thời gian chờ và turnaround trung bình lớn

### 4.5. Highest Response Ratio Next (HRRN)
- Chọn tiến trình có `Response Ratio = (wait time + service time) / service time` lớn nhất
- Công thức: `R = (w + s) / s`

### 4.6. Multilevel Queue
- Ready queue chia thành nhiều hàng đợi theo loại tiến trình
- Mỗi hàng đợi dùng giải thuật riêng (vd: foreground = RR, background = FCFS)
- Định thời giữa các hàng đợi:
  - **Fixed priority**: phục vụ từ cao đến thấp → có thể starvation
  - **Time slice**: mỗi hàng đợi nhận % CPU nhất định

### 4.7. Multilevel Feedback Queue
- Cho phép tiến trình di chuyển giữa các hàng đợi
- I/O-bound và interactive → hàng đợi ưu tiên cao; CPU-bound → hàng đợi ưu tiên thấp
- Có cơ chế **aging** để chống starvation
- Cần xác định: số hàng đợi, giải thuật mỗi hàng, thời điểm chuyển, hàng đợi khởi tạo

## 5. Định thời tiểu trình (Thread scheduling)

- Trên HĐH hiện đại, **tiểu trình được định thời**, không phải tiến trình
- **User thread (PCS)**: định thời trong phạm vi tiến trình, qua thư viện quản lý
- **Kernel thread (SCS)**: định thời trên tất cả CPU khả dụng, toàn hệ thống

## 6. Định thời đa bộ xử lý

### 6.1. Đa xử lý bất đối xứng (Asymmetric)
- Một **master server** xử lý mọi scheduling, I/O; các CPU khác chạy user code
- **Ưu**: đơn giản; **Nhược**: master có thể nghẽn cổ chai

### 6.2. Đa xử lý đối xứng (SMP)
- Mỗi CPU tự định thời cho chính nó
- Hai cách tổ chức:
  - **(a)** Tất cả thread trong một ready queue → vùng tranh chấp
  - **(b)** Mỗi CPU có hàng đợi riêng → phổ biến hơn

### Cân bằng tải (Load balancing)
- **Push migration**: tác vụ đặc biệt đẩy tác vụ từ CPU quá tải sang CPU khác
- **Pull migration**: CPU rỗi kéo tác vụ từ CPU bận

### Processor affinity
- Tác vụ có tính liên kết với CPU (do cache lưu dữ liệu)
- **Soft affinity**: hệ thống cố giữ tác vụ trên CPU đó
- **Hard affinity**: tiến trình chọn tập CPU có thể chạy

## 7. Định thời theo thời gian thực

- **Soft real-time**: tác vụ quan trọng có độ ưu tiên cao nhất
- **Hard real-time**: tác vụ phải hoàn thành trong deadline
- Tiến trình có chu kỳ: thời gian xử lý C, deadline d, chu kỳ T (0 ≤ C ≤ d ≤ T)
- Giải thuật: **Rate Monotonic** (RM), **Earliest Deadline First** (EDF), **Total Bandwidth Server** (TBS)

## 8. Định thời trên một số HĐH

### 8.1. Linux
- **Linux 2.5**: bộ định thời O(1) - thời gian hằng số, hoạt động tốt trên SMP
- **Linux 2.6.23+**: **CFS (Completely Fair Scheduler)**
  - Định thời theo lớp, chọn tác vụ ưu tiên cao nhất trong lớp ưu tiên cao nhất
  - Thời gian CPU dựa trên tỷ lệ, không dùng quantum cố định
  - Dùng **virtual run time**: chọn tiến trình có virtual run time nhỏ nhất
  - Giá trị **nice** từ -20 đến 19 (thấp hơn = ưu tiên cao hơn)
  - Real-time: 0-99; Normal: 100-139

### 8.2. Windows
- 32 độ ưu tiên: variable (1-15), real-time (16-31), 0 dành cho quản lý bộ nhớ
- Preemptive priority-based
- Lớp ưu tiên: REALTIME, HIGH, ABOVE_NORMAL, NORMAL, BELOW_NORMAL, IDLE
- Windows 7+: **UMS (User-Mode Scheduling)** - ứng dụng tự quản lý thread

### 8.3. Solaris
- 6 lớp: TS (time sharing), IA (interactive), RT (real time), SYS (system), FSS (fair share), FP (fixed priority)
- Lớp TS dùng MFQ, độ ưu tiên càng lớn thì time slice càng nhỏ
