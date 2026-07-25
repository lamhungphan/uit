## 1. Tổng quan về bộ nhớ ảo

- Không phải tất cả phần của tiến trình cần được nạp vào bộ nhớ chính cùng lúc
- **Bộ nhớ ảo**: kỹ thuật cho phép xử lý tiến trình không được nạp toàn bộ vào bộ nhớ vật lý
- **Ưu điểm**:
  - Số lượng tiến trình trong bộ nhớ nhiều hơn
  - Tiến trình lớn hơn bộ nhớ thực vẫn chạy được
  - Giảm nhẹ công việc lập trình viên
- **Swap space**: không gian tráo đổi (swap partition trong Linux, pagefile.sys trong Windows)

## 2. Cài đặt bộ nhớ ảo: Demand Paging

- **Demand paging**: trang chỉ được nạp vào bộ nhớ chính khi được yêu cầu
- Khi tham chiếu trang không có trong bộ nhớ → **page-fault trap** → gọi PFSR

### Các bước xử lý page fault
1. Chuyển tiến trình về blocked
2. Yêu cầu đọc đĩa nạp trang vào frame trống; CPU chạy tiến trình khác
3. I/O hoàn tất → ngắt HĐH → PFSR cập nhật page table, chuyển tiến trình về ready

### Thay thế trang nhớ (khi không có frame trống)
1. Xác định vị trí trên đĩa của trang cần
2. Tìm frame trống; nếu không có → dùng giải thuật thay trang chọn **victim page**
3. Ghi victim page ra đĩa, cập nhật page/frame table
4. Đọc trang cần vào frame, cập nhật page/frame table

## 3. Các giải thuật thay trang

### 3.1. FIFO (First-In, First-Out)
- Thay thế trang được nạp vào bộ nhớ sớm nhất
- Có thể gặp **nghịch lý Belady**: số page fault tăng dù được cấp thêm frame

### 3.2. OPT (Optimal)
- Thay thế trang sẽ được tham chiếu trễ nhất trong tương lai
- Cần biết trước các trang sẽ được tham chiếu → không khả thi trong thực tế

### 3.3. LRU (Least Recently Used)
- Thay thế trang có thời điểm tham chiếu nhỏ nhất (xa nhất trong quá khứ)
- Cần sự hỗ trợ của phần cứng
- Hiệu suất gần với OPT hơn FIFO

## 4. Vấn đề cấp phát Frames

### 4.1. Số lượng frame cấp cho tiến trình
- **Cấp ít frame** → nhiều page fault
- **Cấp nhiều frame** → giảm mức độ multiprogramming

### 4.2. Chiến lược cấp phát tĩnh
- **Bằng nhau**: 100 frame / 5 tiến trình = 20 frame mỗi tiến trình
- **Theo tỉ lệ**: dựa vào kích thước tiến trình
- **Theo độ ưu tiên**

### 4.3. Chiến lược cấp phát động
- Số frame có thể thay đổi khi chạy
- Page fault cao → cấp thêm frame; Page fault thấp → giảm bớt

## 5. Vấn đề Thrashing

- **Thrashing**: hiện tượng các trang nhớ bị hoán chuyển vào/ra liên tục
- Xảy ra khi tiến trình không có đủ số frame cần thiết → tỉ lệ page fault rất cao
- **Nguyên lý locality**: tiến trình gồm nhiều locality (tập trang được tham chiếu gần nhau)
- Thrashing xuất hiện khi **Σ size of locality > memory size**

### Giải pháp: Working Set Model
- **WSi** (Working Set): tập Δ trang được sử dụng gần đây nhất
- **WSSi**: kích thước working set của Pi
- **D = Σ WSSi**: tổng working-set size
- Nếu **D > m** (số frame hệ thống) → thrashing
- Giải pháp: tạm dừng một tiến trình, chuyển trang ra đĩa
- Δ quá nhỏ → không đủ bao phủ locality; Δ quá lớn → bao phủ nhiều locality khác nhau
