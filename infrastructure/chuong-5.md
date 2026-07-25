# Chương 5: Tài nguyên mạng và dịch vụ mạng cơ bản

**Biên soạn: ThS. Nguyễn Thị Anh Thư**  
**Email: thunta@uit.edu.vn**

---

## Nội dung
I. Khái niệm  
II. Thiết bị mạng cơ bản  
III. Dịch vụ nền  
IV. Tổng kết

---

## I. Khái niệm

### 1. Mạng nội bộ

Mạng nội bộ là mạng kết nối các thiết bị trong phạm vi nhỏ:
- Phòng làm việc
- Lớp học
- Văn phòng
- Tòa nhà

Cho phép các thiết bị:
- Trao đổi dữ liệu
- Dùng chung máy in, máy chủ, internet
- Quản lý tập trung

Tốc độ thường cao, chi phí triển khai hợp lý.

### 2. Internet

Internet là hệ thống kết nối hàng tỷ thiết bị trên toàn thế giới. Cho phép truy cập các dịch vụ:
- Web
- Email
- Học trực tuyến
- Gọi video
- Lưu trữ đám mây

Internet không phải là một mạng duy nhất, mà là nhiều mạng liên kết với nhau. Muốn vào internet, thiết bị thường cần:
- Kết nối mạng
- Địa chỉ IP
- Thiết bị trung gian như router/modem

### 3. Địa chỉ IP

IP là viết tắt của Internet Protocol. Địa chỉ IP dùng để nhận diện thiết bị khi tham gia mạng.

**IP nội bộ (Private IP)**:
- Dùng trong mạng LAN
- Không truy cập trực tiếp từ internet
- Ví dụ: 192.168.x.x, 10.x.x.x

**IP công cộng (Public IP)**:
- Dùng để giao tiếp ra internet
- Do nhà cung cấp dịch vụ mạng cấp

**IP tĩnh (Static IP)**:
- Ít thay đổi
- Phù hợp máy chủ, camera, thiết bị quản trị

**IP động (Dynamic IP)**:
- Có thể thay đổi theo thời gian
- Thường cấp tự động cho máy người dùng

### 4. Mô hình kết nối

**Thiết bị đầu cuối**: máy tính, điện thoại, máy in, camera.  
**Thiết bị mạng trung gian**: switch, router, firewall.  
**Đường truyền**: cáp mạng, Wi-Fi, Internet.  
**Máy chủ/dịch vụ**: web server, file server, DNS, DHCP.

**1. Peer-to-Peer (ngang hàng)**:
- Các máy có thể chia sẻ trực tiếp với nhau
- Phù hợp mạng nhỏ, đơn giản
- Dễ triển khai nhưng khó quản lý khi số lượng lớn

**2. Client–Server (khách – chủ)**:
- Máy khách gửi yêu cầu đến máy chủ
- Máy chủ cung cấp dữ liệu/dịch vụ
- Phù hợp tổ chức, doanh nghiệp, trường học

---

## II. Thiết bị mạng cơ bản

### 1. Switch

Switch dùng để kết nối nhiều thiết bị trong cùng mạng LAN. Nhận dữ liệu từ một cổng và chuyển đến đúng thiết bị đích.

Giúp:
- Mở rộng số lượng thiết bị kết nối
- Tăng hiệu quả truyền dữ liệu trong nội bộ

Vai trò dễ nhớ: Switch giống như "bộ chia thông minh" trong mạng nội bộ.

### 2. Router

Router dùng để kết nối:
- Mạng nội bộ với internet
- Hoặc giữa nhiều mạng khác nhau

Chức năng chính:
- Định tuyến dữ liệu
- Chọn đường đi phù hợp cho gói tin

Vai trò dễ nhớ: Router là "cổng ra vào" giữa mạng nội bộ và bên ngoài.

### 3. Firewall

Firewall là thiết bị hoặc phần mềm dùng để: kiểm soát lưu lượng ra/vào, chặn truy cập trái phép, tăng an toàn mạng.

Hoạt động dựa trên các quy tắc: cho phép, từ chối, giới hạn truy cập.

Vai trò dễ nhớ: Firewall giống như "chốt bảo vệ" của mạng.

### 4. So sánh

| Thiết bị | Vai trò chính | Phạm vi hoạt động | Kết luận ngắn |
|----------|---------------|-------------------|---------------|
| Switch | Kết nối các thiết bị trong cùng LAN | Nội bộ | Switch để kết nối |
| Router | Kết nối giữa các mạng, đưa LAN ra Internet | Liên mạng | Router để định tuyến |
| Firewall | Kiểm soát và bảo vệ lưu lượng mạng | Bảo mật | Firewall để bảo vệ |

---

## III. Dịch vụ nền

### 1. DNS

DNS là viết tắt của Domain Name System. Chức năng: chuyển tên miền thành địa chỉ IP.

Vai trò dễ nhớ: DNS giống như "danh bạ" của Internet.

### 2. DHCP

DHCP là viết tắt của Dynamic Host Configuration Protocol. Chức năng: cấp IP tự động cho thiết bị khi kết nối mạng, giảm cấu hình thủ công, tránh trùng địa chỉ IP.

Ngoài IP, DHCP có thể cung cấp thêm:
- subnet mask
- gateway
- DNS server

Vai trò dễ nhớ: DHCP giống như "bộ cấp số tự động" trong mạng.

### 3. VPN

VPN là viết tắt của Virtual Private Network: Tạo kết nối an toàn giữa người dùng và mạng đích qua Internet.

**Lợi ích**:
- Mã hóa lưu lượng
- Hỗ trợ làm việc từ xa
- Hạn chế rủi ro khi dùng wi-fi công cộng

**Lưu ý**:
- VPN không thay thế hoàn toàn mọi biện pháp bảo mật
- Cần tài khoản, cấu hình và chính sách sử dụng phù hợp

### 4. Giám sát kết nối

Giám sát kết nối là việc theo dõi: mạng có đang hoạt động không, tốc độ có ổn định không, có mất gói, nghẽn mạng hay không.

**Mục đích**: phát hiện sự cố sớm, nâng cao độ ổn định, hỗ trợ quản trị mạng.

**Các nội dung thường theo dõi**:
- Trạng thái thiết bị
- Băng thông
- Độ trễ
- Tỷ lệ mất kết nối

**Một số cách giám sát cơ bản**:
- Ping: kiểm tra thiết bị còn phản hồi hay không
- Traceroute/Tracert: xem đường đi của dữ liệu
- Đèn trạng thái thiết bị mạng: kiểm tra kết nối vật lý
- Giao diện quản trị router/switch: xem trạng thái cổng, thiết bị đang kết nối
- Phần mềm giám sát mạng: hỗ trợ cảnh báo, thống kê, báo cáo

---

## IV. Tổng kết

- Mạng nội bộ và Internet là nền tảng của kết nối số
- Địa chỉ IP giúp thiết bị nhận diện và giao tiếp trên mạng
- Switch, router, firewall có vai trò khác nhau nhưng bổ trợ cho nhau
- DNS, DHCP, VPN là các dịch vụ nền quan trọng
- Giám sát kết nối giúp đảm bảo mạng hoạt động ổn định và an toàn

---

*Q & A*
