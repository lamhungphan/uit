## 1. Tổng quan

### Hệ điều hành là gì?
- **Chương trình trung gian** giữa phần cứng máy tính và người sử dụng
- Điều khiển và phối hợp việc sử dụng phần cứng
- Cung cấp dịch vụ cơ bản cho các ứng dụng

### Mục tiêu
- Giúp người dùng dễ dàng sử dụng hệ thống
- Quản lý và cấp phát tài nguyên hệ thống hiệu quả

### Cấu trúc hệ thống máy tính
| Thành phần | Vai trò |
|---|---|
| **Hardware** | CPU, bộ nhớ, thiết bị I/O |
| **Operating System** | Phân phối tài nguyên, điều khiển, phối hợp hoạt động |
| **Application programs** | Compilers, database, games, business programs |
| **Users** | People, machines, other computers |

## 2. Hoạt động bên trong máy tính

### Kernel
- Chương trình duy nhất luôn chạy khi máy tính hoạt động
- Kèm theo: **system programs** (đóng gói cùng HĐH) và **application programs**

### Hoạt động I/O
- CPU và các device controller kết nối qua bus, dùng shared memory
- Mỗi device controller có buffer cục bộ và device driver tương ứng
- Khi I/O hoàn tất → device controller phát sinh **ngắt (interrupt)**

### Ngắt (Interrupt)
- Chuyển điều khiển đến **interrupt service routine** qua **interrupt vector**
- **Trap/Exception**: ngắt do phần mềm (lỗi hoặc yêu cầu người dùng)
- HĐH hoạt động theo cơ chế **interrupt-driven**

### Cấu trúc lưu trữ
- Phân cấp dựa trên: tốc độ, chi phí, khả năng lưu trữ khi mất điện
- **Bộ nhớ chính** (DRAM): CPU truy xuất trực tiếp, mất dữ liệu khi mất điện
- **Bộ nhớ thứ cấp** (secondary storage): lưu trữ không bay hơi, dung lượng lớn

### Kiến trúc Von Neumann
- CPU thực thi lệnh
- **Processor**: chip chứa một hoặc nhiều CPU
- **Core**: đơn vị tính toán cơ bản của CPU
- **Multicore**: nhiều lõi trên cùng CPU
- **Multiprocessor**: nhiều bộ xử lý

## 3. Kiến trúc hệ thống máy tính

| Kiến trúc | Mô tả |
|---|---|
| **Single-Processor** | 1 CPU đa dụng + có thể có special-purpose processors |
| **Multiprocessor** | Nhiều CPU: tăng throughput, kinh tế (dùng chung tài nguyên), tin cậy cao. Gồm asymmetric và symmetric (SMP) |
| **Clustered** | Nhiều hệ thống làm việc qua SAN, high-availability. Gồm asymmetric và symmetric clustering |

## 4. Các thao tác trong hệ điều hành

### Đơn chương (Uniprogramming)
- Một chương trình tại một thời điểm, thực thi tuần tự

### Đa chương (Multiprogramming)
- Nhiều công việc nạp đồng thời vào bộ nhớ
- Khi một job chờ I/O → HĐH chuyển sang job khác
- Tăng **CPU utilization**

### Đa nhiệm (Multitasking)
- Mở rộng của đa chương, CPU chuyển công việc thường xuyên hơn
- Người dùng tương tác được với từng công việc

### Chế độ hoạt động
- **User mode**: ứng dụng người dùng thực thi (bit chế độ = 1)
- **Kernel mode**: mã hạt nhân thực thi (bit chế độ = 0)
- Lệnh đặc quyền (privileged) chỉ thực thi ở kernel mode
- Chuyển từ user → kernel mode qua system call hoặc interrupt

## 5. Lịch sử phát triển HĐH

| Thế hệ | Thời kỳ | Đặc điểm |
|---|---|---|
| 1 | 1945-1955 | Một nhóm làm tất cả, phiếu đục lỗ |
| 2 | 1955-1965 | Phân công công việc, xử lý theo lô, băng từ |
| 3 | 1965-1980 | Ra đời HĐH, đa chương, chia sẻ thời gian (CTSS, MULTICS, UNIX) |
| 4 | 1980-nay | PC (IBM PC), MS-DOS, MacOS, Windows, Linux |
| 5 | 1990-nay | Thiết bị di động: Symbian, BlackBerry, Android, iOS |
