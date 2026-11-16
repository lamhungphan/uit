# BÀI 6: TẤN CÔNG MẠNG VÀ PHÒNG CHỐNG XÂM NHẬP

## PHẦN 1: QUY TRÌNH TẤN CÔNG MẠNG (CYBER KILL CHAIN)

Một cuộc tấn công mạng có chủ đích thường không diễn ra ngẫu nhiên mà tuân theo chuỗi 7 giai đoạn chuẩn hóa (mô hình Lockheed Martin Cyber Kill Chain):

```
[1. Trinh sát] ──► [2. Vũ khí hóa] ──► [3. Phát tán] ──► [4. Khai thác]
                                                               │
[7. Hành động] ◄── [6. Điều khiển] ◄── [5. Cài đặt] ◄──────────┘
```

1. **Trinh sát (Reconnaissance):** Thu thập thông tin mục tiêu (IP, tên miền, nhân sự, công nghệ sử dụng) qua OSINT, quét cổng (Nmap).
2. **Vũ khí hóa (Weaponization):** Đóng gói mã khai thác (Exploit) cùng với mã độc (Payload) thành một tệp tin hoàn chỉnh (ví dụ: file PDF, Word chứa macro độc hại).
3. **Phát tán (Delivery):** Truyền vũ khí tới mục tiêu thông qua Email lừa đảo (Phishing), USB, hoặc website bị nhiễm mã độc.
4. **Khai thác (Exploitation):** Kích hoạt mã độc để khai thác lỗ hổng phần mềm hoặc sai lầm của người dùng nhằm thực thi mã trên hệ thống.
5. **Cài đặt (Installation):** Cài đặt Backdoor hoặc Trojan lên máy nạn nhân để duy trì quyền truy cập lâu dài (Persistence).
6. **Điều khiển (Command & Control - C&C):** Thiết lập kênh liên lạc từ máy nạn nhân về máy chủ của kẻ tấn công để nhận lệnh điều khiển từ xa.
7. **Hành động theo mục tiêu (Actions on Objectives):** Thực hiện mục đích cuối cùng như đánh cắp dữ liệu, mã hóa tống tiền, hoặc bàn đạp tấn công sang các máy khác (Lateral Movement).

---

## PHẦN 2: CÁC HÌNH THỨC TẤN CÔNG MẠNG PHỔ BIẾN

### 2.1. Tấn công Từ chối dịch vụ (DoS / DDoS)
Làm cạn kiệt tài nguyên hệ thống (băng thông, CPU, RAM) khiến người dùng hợp pháp không thể truy cập dịch vụ.

```
[ Kẻ tấn công ] ──► [ Mạng Botnet (Hàng ngàn máy Zombie) ]
                           │        │        │
                           ▼        ▼        ▼
                    [ Máy chủ Mục tiêu (Quá tải & Sập) ]
```

* **Tấn công băng thông (Volumetric):** UDP Flood, ICMP Flood, DNS Amplification (làm ngập đường truyền).
* **Tấn công giao thức (Protocol):** SYN Flood (lợi dụng quy trình bắt tay 3 bước của TCP để làm đầy bảng kết nối nửa mở).
* **Tấn công tầng ứng dụng (Application Layer - Layer 7):** HTTP Flood, Slowloris (gửi các yêu cầu HTTP hợp pháp với tốc độ cao hoặc giữ kết nối mở thật lâu làm sập Web Server).

### 2.2. Tấn công Xen giữa (Man-in-the-Middle - MitM)
Kẻ tấn công bí mật xen vào giữa đường truyền giao tiếp của hai bên để nghe lén hoặc chỉnh sửa dữ liệu.

```
[ Nạn nhân ] ◄─── (Dữ liệu bị đọc/sửa) ───► [ Kẻ tấn công ] ◄───► [ Gateway / Server ]
```

* **ARP Spoofing (ARP Poisoning):** Gửi các gói tin ARP giả mạo trong mạng LAN để gán địa chỉ MAC của kẻ tấn công với địa chỉ IP của Default Gateway.
* **DNS Spoofing:** Giả mạo phản hồi DNS để điều hướng người dùng truy cập vào trang web giả mạo thay vì trang web thật.
* **SSL Stripping:** Hạ cấp kết nối từ HTTPS xuống HTTP không mã hóa để đọc trộm mật khẩu dạng văn bản rõ (Plaintext).

### 2.3. Tấn công Khai thác Ứng dụng Web (Web Attacks)
* **SQL Injection (SQLi):** Chèn mã truy vấn SQL độc hại thông qua dữ liệu đầu vào của người dùng để đọc trộm, sửa đổi hoặc xóa dữ liệu trong Database.
* **Cross-Site Scripting (XSS):** Chèn mã kịch bản độc hại (thường là JavaScript) vào trang web để đánh cắp Cookie/Session của người dùng khác.
* **Cross-Site Request Forgery (CSRF):** Lừa trình duyệt của người dùng đã đăng nhập thực hiện một hành động trái ý muốn trên ứng dụng web (ví dụ: tự động đổi mật khẩu hoặc chuyển tiền).

---

## PHẦN 3: HỆ THỐNG PHÒNG THỦ VÀ PHÁT HIỆN XÂM NHẬP

Để bảo vệ hệ thống trước các cuộc tấn công trên, kiến trúc phòng thủ nhiều lớp (Defense-in-Depth) được áp dụng với các thành phần cốt lõi sau:

```
[ Internet ] ──► [ Firewall ] ──► [ IPS (Ngăn chặn) ] ──► [ Mạng Nội Bộ ]
                                         │
                                         ▼ (Bản sao lưu lượng)
                                  [ IDS (Phát hiện) ] ──► [ SIEM / SOC ]
```

### 3.1. Tường lửa (Firewall)
Kiểm soát lưu lượng mạng ra/vào dựa trên các quy tắc (Rules) được thiết lập sẵn.
* **Packet Filtering Firewall:** Lọc gói tin ở tầng Network/Transport dựa trên IP nguồn/đích, Port, Protocol (Stateless).
* **Stateful Inspection Firewall:** Theo dõi trạng thái của toàn bộ phiên kết nối (Session), chỉ cho phép các gói tin thuộc về một kết nối hợp lệ đã được thiết lập.
* **Next-Generation Firewall (NGFW):** Tích hợp thêm khả năng kiểm tra gói tin sâu (DPI - Deep Packet Inspection), nhận diện ứng dụng, tích hợp IPS và tình báo mối đe dọa (Threat Intelligence).

### 3.2. Hệ thống Phát hiện (IDS) và Ngăn chặn Xâm nhập (IPS)

| Tiêu chí | IDS (Intrusion Detection System) | IPS (Intrusion Prevention System) |
| :--- | :--- | :--- |
| **Chức năng chính** | Giám sát, phát hiện và gửi cảnh báo (Alert). | Giám sát, phát hiện và **chủ động chặn** (Drop/Block). |
| **Vị trí triển khai** | Mắc song song (Out-of-band) qua cổng SPAN/TAP. | Mắc nối tiếp (In-line) trên đường đi của dữ liệu. |
| **Ảnh hưởng hiệu năng** | Không làm trễ lưu lượng mạng. | Có thể gây độ trễ (Latency) hoặc nghẽn cổ chai. |
| **Rủi ro cảnh báo giả** | Chỉ gây nhiễu cho quản trị viên. | **False Positive** có thể chặn nhầm người dùng thật. |

### 3.3. Phương pháp phát hiện của IDS/IPS
* **Dựa trên chữ ký (Signature-based):** So sánh lưu lượng mạng với cơ sở dữ liệu các mẫu tấn công đã biết (tương tự phần mềm diệt virus). *Ưu điểm:* Chính xác cao. *Nhược điểm:* Không phát hiện được tấn công Zero-day.
* **Dựa trên bất thường (Anomaly-based):** Xây dựng hồ sơ lưu lượng bình thường (Baseline) và cảnh báo khi có hành vi sai lệch lớn (ví dụ: lưu lượng tăng đột biến lúc 2h sáng). *Ưu điểm:* Phát hiện được tấn công mới. *Nhược điểm:* Tỷ lệ cảnh báo giả (False Positive) cao.

---

## PHẦN 4: CÁC BIỆN PHÁP GIA CỐ HỆ THỐNG (HARDENING)

1. **Phân đoạn mạng (Network Segmentation / VLAN):** Chia nhỏ mạng nội bộ thành các vùng độc lập (DMZ, vùng người dùng, vùng máy chủ cơ sở dữ liệu) để ngăn chặn kẻ tấn công di chuyển ngang.
2. **Sử dụng VPN & Mã hóa kênh truyền:** Áp dụng IPSec, TLS 1.3, SSH để chống nghe lén (MitM) khi truyền dữ liệu qua môi trường không tin cậy.
3. **Cập nhật bản vá (Patch Management):** Thường xuyên cập nhật hệ điều hành và phần mềm để đóng các lỗ hổng bảo mật đã công bố (CVE).
4. **Giám sát tập trung (SIEM):** Thu thập log từ Firewall, IDS/IPS, Server về hệ thống SIEM (như Splunk, ELK Stack, Wazuh) để phân tích tương quan và phản ứng sự cố kịp thời.

---

## PHẦN 5: CÂU HỎI ÔN TẬP NHANH

1. **Tại sao tấn công SYN Flood có thể làm tê liệt một máy chủ Web mà không cần tiêu tốn quá nhiều băng thông?**
   * *Gợi ý:* Kẻ tấn công gửi hàng loạt gói `SYN` với IP nguồn giả mạo, khiến máy chủ gửi `SYN-ACK` và giữ trạng thái chờ (`SYN_RECEIVED`) cho đến khi tràn bộ nhớ bảng kết nối, từ chối các kết nối hợp pháp mới.
2. **Sự khác biệt lớn nhất về cách lắp đặt vật lý/logic giữa IDS và IPS là gì?**
   * *Gợi ý:* IDS lắp song song (nhận bản sao lưu lượng qua Port Mirroring), còn IPS lắp nối tiếp (Inline - mọi gói tin đều phải đi xuyên qua nó).
3. **Để chống lại tấn công ARP Spoofing trong mạng nội bộ (LAN), quản trị viên có thể cấu hình tính năng gì trên thiết bị Switch?**
   * *Gợi ý:* Dynamic ARP Inspection (DAI) kết hợp với DHCP Snooping.