# Chương 3: Phần cứng và lưu trữ trong hạ tầng CNTT

## Nội dung
I. Thành phần phần cứng  
II. Khái niệm lưu trữ  
III. Nguyên tắc lựa chọn

---

## I. Thành phần phần cứng

### 1. Vai trò của phần cứng
**Khái niệm**: Phần cứng là tập hợp các thiết bị vật lý tạo nên nền tảng vận hành của hệ thống CNTT. Đây là lớp hạ tầng trực tiếp hỗ trợ:
- Xử lý dữ liệu
- Lưu trữ thông tin
- Kết nối người dùng
- Cung cấp dịch vụ
- Duy trì hoạt động liên tục của tổ chức

**Vai trò**:
- Là nơi triển khai hệ điều hành, phần mềm ứng dụng, cơ sở dữ liệu.
- Là nền tảng cho mạng nội bộ, Internet, dịch vụ số và hệ thống thông tin doanh nghiệp.
- Ảnh hưởng trực tiếp đến: hiệu năng, độ tin cậy, khả năng mở rộng, chi phí đầu tư và vận hành.

### 2. Máy chủ (Server)
**Khái niệm**: Máy chủ (server) là hệ thống máy tính có cấu hình và độ ổn định cao, được thiết kế để cung cấp dịch vụ, tài nguyên hoặc dữ liệu cho các máy khác trong mạng.

**Đặc điểm cơ bản**:
- Hoạt động liên tục trong thời gian dài.
- Hỗ trợ nhiều người dùng hoặc nhiều tiến trình đồng thời.
- Có khả năng mở rộng CPU, RAM, ổ đĩa, card mạng.
- Chú trọng độ tin cậy, khả năng dự phòng và quản trị từ xa.

**Chức năng chính**:
- Lưu trữ và chia sẻ dữ liệu.
- Chạy ứng dụng dùng chung cho tổ chức.
- Quản lý tài khoản, phân quyền và xác thực.
- Lưu trữ và xử lý cơ sở dữ liệu.
- Hỗ trợ sao lưu, khôi phục, giám sát hệ thống.

#### Phân loại máy chủ

**Theo hình thức vật lý**:
- **Tower Server**: dạng tháp, phù hợp doanh nghiệp nhỏ.
- **Rack Server**: gắn tủ rack, phổ biến trong doanh nghiệp và data center.
- **Blade Server**: tối ưu mật độ triển khai, dùng trong môi trường lớn.

**Theo chức năng**:
- File Server, Database Server, Application Server, Web Server, Backup Server, Virtualization Server.

**Theo mô hình triển khai**:
- On-premises server, Hosted/Colocation, Cloud server.

#### Tiêu chí lựa chọn
- Số lượng người dùng
- Loại ứng dụng chạy trên server
- Nhu cầu hiệu năng
- Dung lượng dữ liệu
- Mức độ sẵn sàng cao
- Khả năng mở rộng
- Ngân sách đầu tư và vận hành

### 3. Máy trạm (Workstation)
**Khái niệm**: Máy trạm (workstation) là máy tính phục vụ trực tiếp cho người dùng trong quá trình làm việc, học tập, thiết kế, vận hành hay xử lý nghiệp vụ.

**Phân biệt với PC thông thường**:
- Máy trạm thường có cấu hình mạnh hơn, độ ổn định cao hơn, hỗ trợ xử lý chuyên môn như đồ họa, kỹ thuật, phân tích dữ liệu.
- PC thông thường chủ yếu phục vụ tác vụ văn phòng, học tập, duyệt web.

**Đặc điểm**:
- Có CPU, RAM, GPU phù hợp nhu cầu người dùng.
- Cài đặt hệ điều hành và phần mềm ứng dụng.
- Kết nối với mạng nội bộ, Internet và máy chủ.
- Có thể là desktop, laptop, thin client hoặc mobile workstation.

#### Tiêu chí lựa chọn máy trạm
- Nhu cầu công việc thực tế
- Phần mềm chuyên dụng cần chạy
- Tuổi thọ sử dụng
- Khả năng nâng cấp
- Chi phí đầu tư
- Tính cơ động
- Tiêu thụ điện năng và bảo trì

### 4. Thiết bị lưu trữ (Storage Devices)
**Khái niệm**: Thiết bị lưu trữ là phần cứng dùng để ghi, lưu giữ, truy xuất và bảo vệ dữ liệu.

**Vai trò**:
- Lưu hệ điều hành, phần mềm và dữ liệu vận hành.
- Lưu tài liệu, hồ sơ, cơ sở dữ liệu, nội dung số.
- Phục vụ sao lưu, khôi phục và lưu trữ lâu dài.

#### Các loại thiết bị lưu trữ phổ biến

**Theo công nghệ**:
- **HDD (Hard Disk Drive)**: dung lượng lớn, giá thấp hơn; tốc độ chậm hơn SSD.
- **SSD (Solid State Drive)**: tốc độ cao, độ trễ thấp; phù hợp hệ điều hành, ứng dụng, cơ sở dữ liệu cần truy xuất nhanh.
- **USB/Thẻ nhớ/Ổ cứng di động**: tiện di chuyển; phù hợp sao chép hoặc lưu trữ tạm thời.

**Theo mô hình kết nối**:
- **DAS (Direct Attached Storage)**: gắn trực tiếp
- **NAS (Network Attached Storage)**: lưu trữ qua mạng, chia sẻ file
- **SAN (Storage Area Network)**: hạ tầng lưu trữ chuyên dụng cho quy mô lớn

#### Tiêu chí đánh giá thiết bị lưu trữ
- Dung lượng
- Tốc độ đọc/ghi
- Độ tin cậy
- Khả năng mở rộng
- Tính sẵn sàng
- Mức độ an toàn dữ liệu
- Chi phí đầu tư

### 5. Thiết bị ngoại vi (Peripheral Devices)
**Khái niệm**: Thiết bị ngoại vi là các thiết bị kết nối với máy tính hoặc hệ thống để hỗ trợ nhập dữ liệu, xuất dữ liệu, tương tác và vận hành.

**Phân nhóm cơ bản**:
- **Thiết bị nhập**: Bàn phím, Chuột, Máy quét (scanner), Webcam, Microphone, Đầu đọc mã vạch, đầu đọc thẻ.
- **Thiết bị xuất**: Màn hình, Máy in, Loa, Máy chiếu.
- **Thiết bị nhập/xuất**: Màn hình cảm ứng, Máy in đa chức năng, Thiết bị hội nghị truyền hình.

### 6. Trung tâm dữ liệu (Data Center)
**Khái niệm**: Trung tâm dữ liệu (Data Center) là nơi tập trung các thiết bị CNTT quan trọng như máy chủ, hệ thống lưu trữ, thiết bị mạng và các hệ thống phụ trợ để vận hành dịch vụ CNTT một cách liên tục, an toàn và có kiểm soát.

**Các thành phần cơ bản**:
- **Thành phần CNTT**: Máy chủ, Storage, Thiết bị mạng, Tủ rack.
- **Thành phần hạ tầng hỗ trợ**: Nguồn điện, UPS, máy phát điện; Hệ thống làm mát; PCCC; Kiểm soát ra vào; Giám sát môi trường và an ninh.

---

## II. Khái niệm lưu trữ

### 1. DAS (Direct Attached Storage)
**Khái niệm**: DAS là thiết bị lưu trữ gắn trực tiếp vào một máy tính hoặc máy chủ.

**Ưu điểm**:
- Dễ triển khai
- Chi phí đầu tư thấp
- Tốc độ tốt do kết nối trực tiếp

**Hạn chế**:
- Khó chia sẻ cho nhiều người dùng
- Khó quản lý tập trung
- Khả năng mở rộng hạn chế

### 2. NAS (Network Attached Storage)
**Khái niệm**: NAS là thiết bị lưu trữ kết nối vào mạng, cho phép nhiều người dùng hoặc nhiều máy cùng truy cập dữ liệu.

**Ưu điểm**:
- Chia sẻ dữ liệu thuận tiện
- Quản lý tập trung
- Dễ mở rộng hơn DAS

**Hạn chế**:
- Tốc độ phụ thuộc vào mạng
- Không tối ưu cho các hệ thống yêu cầu hiệu năng rất cao

### 3. SAN (Storage Area Network)
**Khái niệm**: SAN là một mạng lưu trữ chuyên dụng, kết nối các máy chủ với các thiết bị lưu trữ tốc độ cao.

**Đặc điểm chính**:
- Hiệu năng cao
- Độ trễ thấp
- Phục vụ tốt cho nhiều máy chủ
- Hỗ trợ hệ thống lớn, nghiệp vụ quan trọng
- Thường phức tạp hơn và chi phí cao hơn DAS/NAS

---

## III. Nguyên tắc lựa chọn

**Chuỗi liên kết cơ bản**:
- Máy trạm: nơi người dùng làm việc
- Máy chủ: nơi cung cấp dịch vụ và xử lý tập trung
- Lưu trữ: nơi dữ liệu được duy trì và bảo vệ
- Ngoại vi: công cụ hỗ trợ tương tác và vận hành
- Trung tâm dữ liệu: môi trường tổ chức và bảo vệ toàn bộ hệ thống

**Ý chính**: Một hạ tầng CNTT hiệu quả là sự phối hợp đồng bộ giữa nhiều thành phần phần cứng, chứ không phải tối ưu một thiết bị riêng lẻ. Theo nhu cầu nghiệp vụ và tải hệ thống.

### Tình huống minh họa
Một doanh nghiệp nhỏ có:
- 30 nhân viên
- 1 phần mềm kế toán
- 1 hệ thống quản lý bán hàng
- Nhu cầu lưu trữ tài liệu nội bộ
- Nhu cầu họp trực tuyến và in ấn thường xuyên

Gợi ý thành phần phần cứng cần có:
- Máy trạm cho nhân viên
- 1–2 máy chủ hoặc server cloud
- NAS hoặc storage dùng chung
- Máy in mạng, scanner, webcam, microphone
- Thiết bị mạng cơ bản
- Không nhất thiết cần data center riêng; có thể đặt server tại phòng máy chủ nhỏ hoặc thuê dịch vụ ngoài
