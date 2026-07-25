## 1. Hệ điều hành Linux

### 1.1. Lịch sử phát triển
- **1991**: Linus Torvalds bắt đầu phát triển nhân Linux, tương thích UNIX, mã nguồn mở
- **Phiên bản 0.01 (5/1991)**: chạy trên PC Intel 80386, chưa có mạng
- **Phiên bản 1.0 (3/1994)**: TCP/IP, socket BSD, cải thiện hệ thống tập tin
- **Phiên bản 2.0 (6/1996)**: hỗ trợ nhiều kiến trúc (64-bit Alpha), đa bộ xử lý
- **2.4, 2.6**: tăng cường SMP, hỗ trợ bộ nhớ 64-bit
- **3.0 (7/2011)**: cải thiện ảo hóa, quản lý bộ nhớ, định thời
- **4.0 (4/2015)**: hỗ trợ thêm kiến trúc mới, cải thiện di động
- Đánh số: **số lẻ** = bản phát triển, **số chẵn** = bản chính (production)

### 1.2. Nguyên tắc thiết kế
- Hệ thống nhiều người dùng, đa tác vụ, tương thích UNIX
- Hệ thống tập tin tuân thủ UNIX, mô hình mạng chuẩn UNIX
- Giao diện lập trình tuân thủ SVR4 UNIX
- Mục tiêu: **tốc độ, hiệu quả, tiêu chuẩn hóa**
- Hỗ trợ POSIX, Pthreads, real-time POSIX

### 1.3. Các thành phần chính
| Thành phần | Vai trò |
|---|---|
| **Kernel** | Duy trì hoạt động mức trừu tượng (bộ nhớ ảo, tiến trình), chạy ở kernel mode |
| **System libraries** | Tập chuẩn các hàm để ứng dụng tương tác với nhân |
| **System utilities** | Chương trình quản lý cụ thể |

### 1.4. Kernel Modules
- Các phần mã nhân có thể biên dịch, nạp, gỡ độc lập
- Cài đặt: trình điều khiển thiết bị, hệ thống tập tin, giao thức mạng
- 4 loại: module-management system, loader/unloader, driver-registration system, conflict-resolution mechanism

### 1.5. Quản lý tiến trình
- `fork()` tạo tiến trình mới; `exec()` chạy chương trình mới
- Thuộc tính tiến trình chia 3 nhóm: **định danh, môi trường, ngữ cảnh**
- **Giao tiếp IPC**:
  - **Signal**: thông báo sự kiện, giới hạn, không chứa thông tin
  - **Pipe**: kênh giao tiếp cha-con
  - **Network**: gửi dữ liệu cục bộ/từ xa
  - **Shared memory**: nhanh, cần kết hợp đồng bộ

### 1.6. Định thời
- **O(1) scheduler** (2.5): priority-based preemptive, tốt trên SMP
- **CFS** (2.6.23+): completely fair, virtual run time, nice value (-20 đến 19)

### 1.7. Quản lý bộ nhớ
- **Vật lý**: chia 6 vùng (DMA, DMA32, NORMAL, HIGHMEM, MOVABLE, DEVICE), dùng **buddy heap algorithm**
- **Ảo**: không gian địa chỉ mỗi tiến trình gồm **logical view** (vùng nhớ không chồng lấn) và **physical view** (bảng trang)
- `fork()` sao chép thông tin cấu trúc bộ nhớ ảo, bảng trang → cha con chia sẻ cùng trang vật lý
- **Phân trang**: pageout-policy + paging mechanism, giải thuật next-fit
- **Liên kết động**: thông qua thư viện liên kết đặc biệt

## 2. Hệ điều hành Windows

### 2.1. Lịch sử phát triển
- **1988**: Microsoft phát triển NT (New Technology), hỗ trợ OS/2 và POSIX API
- Chuyển từ OS/2 → Win32 API
- Các phiên bản: 95, 98, Me, 2000, XP, Vista, 7, 8, 8.1, 10, 11

### 2.2. Nguyên tắc thiết kế
| Nguyên tắc | Mô tả |
|---|---|
| **Bảo mật** | ACLs, DEP, mã hóa tập tin, chữ ký số |
| **Đáng tin cậy** | Bảo vệ phần cứng bộ nhớ ảo + bảo vệ phần mềm |
| **Dễ mở rộng** | Kiến trúc phân tầng, RPCs, ALPCs |
| **Hiệu năng cao** | Truyền thông điệp hiệu năng cao, SMP, preemptive |
| **Tương thích** | IEEE 1003.1 (POSIX) |
| **Di động** | Chạy trên nhiều kiến trúc |
| **Quốc tế hóa** | NLS API |
| **Tiết kiệm năng lượng** | Dynamic tick, connected standby,... |

### 2.3. Kiến trúc Windows 10
- **Kernel mode**: HAL, nhân, secure kernel, executive, Hyper-V
- **User mode**: environmental subsystems + protection subsystems
- **Nhân**: định thời thread, chuyển ngữ cảnh, đồng bộ, xử lý ngắt/ngoại lệ, system call
- **HAL**: che dấu khác biệt phần cứng
- **Executive**: quản lý bộ nhớ ảo, tiến trình, I/O, năng lượng, PnP, registry, LPC

### 2.4. Quản lý tiến trình/tiểu trình
- Mỗi tiến trình có không gian địa chỉ ảo riêng, processor affinity
- **8 trạng thái thread**: initializing, ready, deferred-ready, standby, running, waiting, transition, terminated
- **2 chế độ**: user-mode thread (UT) và kernel-mode thread (KT), mỗi chế độ stack riêng

### 2.5. Định thời
- 32 độ ưu tiên: **real-time** (16-31) và **variable** (0-15)
- Preemptive priority-based
- Ưu tiên thread interactive (chuột, cửa sổ) và I/O-bound
- **Soft real-time**: không đảm bảo thời gian cố định

### 2.6. Quản lý bộ nhớ ảo
- Quy trình 2 bước: **dự trữ** (reserve) không gian địa chỉ → **cấp phát** (commit)
- 6 trạng thái trang: valid, zeroed, free, standby, modified, bad
- Chuyển đổi địa chỉ: page directory (1024 PDE) → page table (1024 PTE) → frame 4KB

### 2.7. Các tác vụ điều hành
- **Plug-and-Play**: ghi nhận thay đổi phần cứng, nạp driver
- **LPC** (Local Procedure Call): giao tiếp tiến trình cùng máy, 3 loại (thông điệp ngắn, shared memory, quick LPC)
- **Registry**: lưu cấu hình trong hives, có system restore point
