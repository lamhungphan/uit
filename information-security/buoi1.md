## 1 MỘT SỐ KHÁI NIỆM
### Dữ liệu là gì?
- Là tất cả những gì được tạo ra và lưu trên máy tính
- Gồm 2 trạng thái 
    - Lưu trữ / Storage
    - Truyền / Transmission
### Yêu cầu đối với dữ liệu
- Tính bảo mật / Confidentiality: Chỉ người được phép mới có thể truy cập
- Tính toàn vẹn / Integrity: Không bị thay đổi trong quá trình truyền tải hoặc lưu trữ
- Tính không thể từ chối / Non-repudiation: Không thể chối bỏ hành động của mình
- Tính sẵn sàng / Availability: Khi cần là phải có

## 2 CÁC KỸ THUẬT TẤN CÔNG VÀ CƠ CHẾ PHÒNG THỦ
### 2.1 Eavesdropping: Nghe lén
### 2.2 Cryptanalysis: Phân tích mật mã
### 2.3 Password Pilfering: Đánh cắp mật khẩu
### 2.4 Identify Spoofing: Mạo danh
#### 2.4.1 Message replay: Tái sử dụng tin nhắn
#### 2.4.2 Network Spoofing: Mạo danh mạng
- TCP hijacking: Tấn công chiếm quyền điều khiển TCP
- ARP Spoofing: Tấn công ARP

### 2.5 Buffer-Overflow Explorations: Tràn bộ đệm
### 2.6 Repudiation: Chối bỏ
### 2.7 Intrusion: Xâm nhập
### 2.8 Denial of Service (DoS): Tấn công từ chối dịch vụ
#### 2.8.1 Smurf Attack
#### 2.8.2 SYNonic Attack
#### 2.8.3 Teardrop Attack
#### 2.8.4 Ping of Death
### 2.9 Malicious code
- **Virus**
    - Phần mềm có thể nhân bản chính nó và được gắn vào một tập tin hoặc chương trình khác
    - Khi chương trình bị nhiễm virus được thực thi, virus sẽ được kích hoạt
    - Khi thực hiện, virus có thể làm hại máy tính và sao chép chính nó để lây nhiễm sang máy khác
- **Worms**: Giống virus nhưng có thể tự lây nhiễm mà không cần được thực thi
- **Trojans hourses**: Phần mềm được ngụy trang thành phần mềm hợp pháp
- **Logic bomb**: Phần mềm được kích hoạt khi một điều kiện nhất định xảy ra
- **Backdoors**: Phần mềm độc hại có thể truy cập hệ thống từ xa
- **Spywares**: Phần mềm thu thập thông tin người dùng mà không được phép
- **Ransomware**: Phần mềm mã hóa dữ liệu và yêu cầu tiền chuộc để giải mã
- **Rootkits**: Bộ công cụ phần mềm độc hại được thiết kế để che giấu sự tồn tại của tin tặc trong hệ thống
- **Fileless Malware**: Phần mềm độc hại không cần cài đặt
- **Botnet**: Một mạng máy tính bị chiếm quyền điều khiển và sử dụng để tấn công
- **Keyloggers**: Phần mềm ghi lại thao tác bàn phím

## 3. LÝ LỊCH CỦA NHỮNG KẺ TẤN CÔNG
- Black hat
- Script kiddies
- Cyber spies
- Vicious employees
- Cyber terrorists

### Hacking Phases
1. Reconnaissance
2. Scanning
3. Gaining Access
4. Maintaining Access
5. Covering Tracks

## 4. MÔ HÌNH BẢO MẬT CƠ BẢN
- Mô hình bảo mật cơ bản gồm 4 thành phần
    - Hệ thống mã hóa (Cryptosystem)
    - Tường lửa (Firewall)
    - Hệ thống phần mềm chống độc hại (Anti-Malicious System software - AMS software)
    - Hệ thống tìm kiếm xâm nhập (Intrusion Detection System - IDS)

- Mô hình phòng thủ theo chiều sâu (Defense in Depth)
    1. Data
    2. Application
    3. Host
    4. Internal Network
    5. Perimeter
    6. Physical Security
    7. Policy, Procedures & Awareness
    8. User

## Mô hình bảo mật kiểm tra hệ thống

`Information Gathering` → `Vulnerability Analysis` → `External PT` → `Internal PT` → `Router and Switches PT` → `Firewall PT` → `IDS PT` → `Wireless Network  PT` → `Denial of Service PT` → `Password Cracking PT` → `Social Engineering PT` → `Stolen Laptop, PDAs, Phones PT` → `Application PT`

`Physical Security PT` → `Database PT` → `VoIP PT` → `VPN PT` → `War Dialing` → `Virus & Trojan Detection` → `Log Management PT` → `File Intergrity Checking` → `Bluetooth & Handheld Device PT` → `Communication System PT` → `Email Security PT` → `Security Patches PT` → `Data Leakage PT`

**Note**: PT = Penetration Testing