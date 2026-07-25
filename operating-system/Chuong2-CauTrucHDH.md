## 1. Các thành phần của hệ điều hành

### 1.1. Quản lý tiến trình
- Tiến trình cần: CPU, bộ nhớ, file, thiết bị I/O
- Nhiệm vụ: tạo/hủy tiến trình, tạm dừng/thực thi tiếp, đồng bộ, giao tiếp (IPC), khống chế tắc nghẽn

### 1.2. Quản lý bộ nhớ chính
- Theo dõi vùng nhớ trống/đã cấp phát
- Quyết định nạp chương trình nào khi có vùng nhớ trống
- Cấp phát và thu hồi vùng nhớ

### 1.3. Quản lý file
- File, thư mục, hệ thống file
- Tạo/xóa file/thư mục, copy, paste
- Ánh xạ file vào thiết bị thứ cấp, sao lưu/phục hồi

### 1.4. Quản lý hệ thống I/O
- Che dấu sự khác biệt thiết bị I/O
- Cơ chế: **buffering, caching, spooling**
- Cung cấp giao diện chung đến device driver

### 1.5. Quản lý hệ thống lưu trữ thứ cấp
- Quản lý không gian trống (free space management)
- Cấp phát không gian lưu trữ (storage allocation)
- Định thời hoạt động đĩa (disk scheduling)

### 1.6. Hệ thống bảo vệ
- Kiểm soát đăng nhập/xuất
- Phân định truy cập hợp pháp/bất hợp pháp
- Thi hành chính sách bảo vệ dữ liệu

### 1.7. Hệ thống thông dịch lệnh
- Giao diện chính giữa người dùng và OS
- Ví dụ: shell (CLI), mouse-based window-and-menu (GUI)

## 2. Các dịch vụ HĐH cung cấp

| Dịch vụ | Mô tả |
|---|---|
| **Thực thi chương trình** | Load và chạy chương trình |
| **Thao tác I/O** | Theo yêu cầu của chương trình |
| **Thao tác hệ thống file** | Đọc, ghi, tạo, xóa file |
| **Trao đổi thông tin** | Shared memory hoặc Message passing |
| **Phát hiện lỗi** | CPU, bộ nhớ, I/O, chương trình (chia 0, truy cập bất hợp pháp) |
| **Cấp phát tài nguyên** | CPU, bộ nhớ, ổ đĩa |
| **Kế toán (Accounting)** | Lưu vết user để tính phí/thống kê |
| **Bảo vệ và an ninh** | Protection + Security |

### Giao diện người dùng
- **CLI** (Command-Line Interface)
- **GUI** (Graphics User Interface)
- **Touch-screen**

## 3. Lời gọi hệ thống (System Call)

- Giao diện giữa tiến trình và HĐH
- Ví dụ: `open`, `read`, `write` file
- Thường viết bằng C/C++, truy cập qua **API**
- 3 API phổ biến: **Win32 API** (Windows), **POSIX API** (UNIX/Linux/macOS), **Java API** (JVM)
- 3 phương pháp truyền tham số:
  1. Qua thanh ghi
  2. Qua vùng nhớ (địa chỉ gửi qua thanh ghi)
  3. Qua stack

## 4. Chương trình hệ thống (System Programs)

Phân biệt với application program, gồm:
- **Quản lý file**: create, delete, rename, list
- **Thông tin trạng thái**: date, time, dung lượng bộ nhớ trống
- **Soạn thảo file**: file editor
- **Hỗ trợ ngôn ngữ lập trình**: compiler, assembler, interpreter
- **Nạp/thực thi/tìm lỗi**: loader, debugger
- **Giao tiếp**: email, talk, web browser

## 5. Cấu trúc hệ thống

### 5.1. Monolithic (Nguyên khối)
- HĐH là một khối thống nhất, kernel và system programs tách rời
- Ví dụ: **Original UNIX**

### 5.2. Layered Approach (Phân lớp)
- Chia thành nhiều lớp, lớp dưới = hardware, lớp trên = user
- Lớp trên chỉ gọi hàm lớp dưới
- Ví dụ: HĐH **THE**

### 5.3. Microkernel
- Chuyển chức năng từ kernel space → user space
- Microkernel chỉ gồm: quản lý tiến trình, bộ nhớ, IPC
- Giao tiếp qua message passing
- Ví dụ: **CMU Mach OS**

### 5.4. Modules
- Dùng **loadable kernel modules (LKMs)**, hướng đối tượng
- Mỗi module tách biệt, trao đổi qua interface
- Ví dụ: **Linux, Solaris**

### 5.5. Hybrid Systems
- Kết hợp nhiều cấu trúc
- **Linux/Solaris**: monolithic + modules
- **Windows**: monolithic + microkernel
- **macOS/iOS**: Darwin kernel (XNU)
- **Android**: dựa trên nhân Linux + ART VM + frameworks
