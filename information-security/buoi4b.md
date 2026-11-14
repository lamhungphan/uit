# Bài 3B – Dò tìm lỗ hổng bảo mật thông tin: Quét mạng

> Môn: Nhập môn Bảo đảm và An ninh thông tin – ThS. Tô Nguyễn Nhật Quang – Trường ĐH Công nghệ Thông tin

## Nội dung bài học

- Quét hệ thống mạng
  - Khái niệm chung
  - Quét hệ thống
  - Một số khái niệm cơ bản
  - Các kỹ thuật quét mạng: quét port, biện pháp đối phó quét port, quét điểm yếu, vẽ lược đồ mạng, sử dụng Proxy, ẩn danh, địa chỉ IP giả
  - Biện pháp phòng chống
  - Bài tập

---

## 1. Khái niệm chung

- **Scanning** là tập hợp các thủ tục để xác định **host, port và dịch vụ** trong một mạng.
- Scanning là một thành phần của việc thu thập thông tin tình báo (intelligence gathering) để kẻ tấn công dựng hồ sơ về tổ chức mục tiêu.
- Kẻ tấn công gửi các TCP/IP probe vào mạng và nhận lại thông tin mạng.
- Thông tin thu được: địa chỉ IP và open port của các live host; hệ điều hành và kiến trúc hệ thống; dịch vụ đang chạy trên host.

### Các loại quét

| Loại | Mô tả |
|---|---|
| **Port scanning** | Chuỗi thông điệp gửi bởi người cố xâm nhập máy tính để tìm hiểu các dịch vụ mạng của máy đó. Mỗi thông điệp gắn với một số port "well-known" |
| **Vulnerability scanning** | Quá trình tự động chủ động xác định các lỗ hổng của hệ thống máy tính trong mạng |
| **Network scanning** | Thủ tục xác định các host đang hoạt động trên mạng, để tấn công chúng hoặc để đánh giá an ninh mạng |

### Phương pháp luận quét (Scanning Methodology)

1. Check for live systems (kiểm tra hệ thống đang hoạt động)
2. Check for open ports (kiểm tra port mở)
3. Banner grabbing / OS fingerprinting
4. Scan for vulnerability (quét điểm yếu)
5. Draw network diagrams (vẽ lược đồ mạng)
6. Prepare proxies (chuẩn bị proxy)

---

## 2. Quét hệ thống

### Kiểm tra hệ thống đang hoạt động – ICMP Scanning

- **Ping scan**: gửi ICMP ECHO request tới một host; nếu host đang hoạt động sẽ trả về ICMP ECHO reply.
- Hữu ích để xác định thiết bị đang hoạt động hoặc kiểm tra ICMP có đi qua được firewall hay không.
- Ví dụ Nmap: `nmap -sP -v 192.168.168.5` → "Host appears to be up", kèm MAC address.

### Ping sweep

- Dùng để xác định **các live host trong một dải IP** bằng cách gửi ICMP ECHO request tới nhiều host; host nào hoạt động sẽ trả ICMP ECHO reply.
- Kẻ tấn công dùng ping sweep để lập **bảng kê các hệ thống đang hoạt động** trong mạng.
- Ví dụ Nmap: `nmap -sP -PE -PA21,23,80,3389 192.168.168.1-50`

**Công cụ ping sweep:** Colasoft Ping Tool, SolarWinds Standard Edition, Utility Ping, Visual Ping Tester, Ping Scanner Pro, Ultra Ping Pro, PingInfoView, PacketTrap pt360.

---

## 3. Một số khái niệm cơ bản

### TCP three-way handshake

TCP dùng bắt tay 3 bước để thiết lập kết nối giữa client và server:

1. Máy A khởi tạo kết nối tới server bằng gói chỉ có cờ **SYN**.
2. Server trả lời bằng gói có cả cờ **SYN** và **ACK**.
3. Client đáp lại bằng một gói **ACK**.
4. Hoàn tất 3 bước không lỗi → kết nối TCP được thiết lập.

### Cấu trúc gói IP/TCP

- **IP header**: Version, IHL, Type of Service, Total Length, Identification, Flags, Fragment Offset, Time to Live, Protocol (= 6 cho TCP), Header Checksum, Source Address, Destination Address, Options, Padding.
- **TCP header**: Source Port, Destination Port, Sequence Number, Acknowledgment Number, Data Offset, các cờ (URG, ACK, PSH, RST, SYN, FIN), Window, Checksum, Urgent Pointer, TCP Options, Padding, rồi TCP Data.

### Các cờ TCP (TCP Communication Flags)

| Cờ | Ý nghĩa |
|---|---|
| **SYN** (Synchronize) | Khởi tạo kết nối giữa các host |
| **ACK** (Acknowledgement) | Xác nhận đã nhận gói tin |
| **PSH** (Push) | Yêu cầu hệ thống gửi đẩy ngay toàn bộ dữ liệu trong buffer |
| **URG** (Urgent) | Dữ liệu trong gói cần được xử lý ngay |
| **FIN** (Finish) | Báo cho hệ thống từ xa rằng sẽ không còn truyền dữ liệu nữa |
| **RST** (Reset) | Reset kết nối |

Có thể tạo **gói tin tuỳ chỉnh** với các cờ TCP bằng các công cụ packet crafter (ví dụ Komodia's packet crafter).

### Hping2 / Hping3

- Packet crafter dòng lệnh cho giao thức TCP/IP.
- Công cụ kiểm tra và audit firewall, mạng.
- Chạy trên cả Windows và Linux.
- hping3 là công cụ dòng lệnh dùng ngôn ngữ TCL, tương thích hping2.

**Các lệnh Hping:**

| Mục đích | Lệnh |
|---|---|
| ICMP ping | `hping3 -1 10.0.0.25` |
| ACK scan trên port 80 | `hping3 -A 10.0.0.25 -p 80` |
| UDP scan trên port 80 | `hping3 -2 10.0.0.25 -p 80` |
| Thu thập Initial Sequence Number | `hping3 192.168.1.103 -Q -p 139 -s` |
| SYN scan trên port 50–60 | `hping3 -8 50-56 -S 10.0.0.25 -V` |
| FIN, PUSH và URG scan trên port 80 | `hping3 -F -P -U 10.0.0.25 -p 80` |
| Quét cả subnet tìm live host | `hping3 -1 10.0.1.x --rand-dest -I eth0` |
| Chặn mọi traffic có chữ ký HTTP | `hping3 -9 HTTP -I eth0` |

---

## 4. Các kỹ thuật quét mạng

### 4.1. Kỹ thuật quét port

Các kỹ thuật: **TCP Connect Scan**, **Stealth Scan**, **XMAS Scan**, **FIN Scan** (SYN/ACK/FIN), **NULL Scan**, **IDLE Scan**, **Inverse Mapping Scan** (Inverse TCP Flag Scan), ACK Flag Scan, UDP Scan.

#### TCP Connect / Full Open Scan

- Phát hiện port mở bằng cách **hoàn tất three-way handshake**.
- Thiết lập kết nối đầy đủ rồi ngắt bằng gói **RST**.
- Luồng: Attacker gửi `SYN (port n)` → Target trả `SYN/ACK` → Attacker gửi `ACK + RST`.

#### Stealth Scan (Half-open Scan)

- Kẻ tấn công dùng stealth scanning để **vượt qua luật firewall, cơ chế ghi log**, và nguỵ trang thành traffic mạng bình thường.
- Client gửi một gói **SYN** tới port cần kiểm tra.
- Port **mở**: server trả **SYN/ACK**; client gửi **RST** để đóng ngay trước khi kết nối được thiết lập hoàn chỉnh.
- Port **đóng**: server trả **RST**.

#### Xmas Scan

- Gửi khung TCP tới thiết bị từ xa với các cờ **URG, ACK, RST, SYN và FIN** được đặt (theo slide; nhãn trong hình là FIN, URG, PUSH).
- Port **mở**: không có phản hồi. Port **đóng**: trả **RST**.
- Chỉ hoạt động với OS có TCP/IP phát triển theo **RFC 793**; **không hoạt động** với các phiên bản **Microsoft Windows** hiện hành.
- Ví dụ: `nmap -sX -v 10.0.0.8`

#### FIN Scan

- Gửi khung TCP với **chỉ cờ FIN** tới thiết bị từ xa.
- Port mở: không phản hồi. Port đóng: trả **RST/ACK**.
- Chỉ hoạt động với OS theo RFC 793; không hoạt động với Windows hiện hành.
- Ví dụ: `nmap -sF 192.168.168.13`

#### NULL Scan

- Gửi khung TCP **không đặt cờ nào**.
- Port mở: không phản hồi. Port đóng: trả **RST/ACK**.
- Chỉ hoạt động với OS theo RFC 793; không hoạt động với Windows hiện hành.
- Ví dụ: `nmap -sN 192.168.168.13`

#### SYN/FIN Scanning dùng IP Fragments

- Không phải phương pháp mới mà là **biến thể** của các phương pháp trước.
- TCP header được **chia nhỏ thành nhiều gói** để packet filter không phát hiện được ý đồ của gói tin.
- Ví dụ: `nmap -sS -T4 -A -f -v 192.168.168.26` (tuỳ chọn `-f` để phân mảnh).

#### UDP Scanning

- Không có three-way handshake cho UDP.
- Port **mở**: hệ thống **không phản hồi**.
- Port **đóng**: hệ thống trả thông điệp **ICMP port unreachable**.
- Spyware, trojan và các ứng dụng độc hại khác dùng port UDP.

#### Inverse TCP Flag Scanning

- Gửi các gói thăm dò TCP với nhiều cờ khác nhau (FIN, URG, PSH) hoặc không có cờ.
- **Không phản hồi** → port **mở**; **RST/ACK** → port **đóng**.

#### ACK Flag Scanning

- Gửi gói thăm dò **ACK** với sequence number ngẫu nhiên.
- **Không phản hồi** → port bị **filtered** (có stateful firewall); phản hồi **RST** → port **không bị lọc** (không có firewall).
- Ví dụ: `nmap -sA -P0 10.10.0.25` → "All 529 scanned ports are filtered".

#### Công cụ quét port

- **Nmap**: công cụ mã nguồn mở miễn phí để khám phá mạng. Quản trị viên dùng để kiểm kê mạng, quản lý lịch dịch vụ, giám sát uptime của host/dịch vụ. Kẻ tấn công dùng để trích xuất: live host trên mạng, dịch vụ (tên và phiên bản ứng dụng), hệ điều hành (và phiên bản), loại packet filter/firewall. Có giao diện đồ hoạ Zenmap. (http://nmap.org)
- **NetScanTools Pro** (netscantools.com).
- Công cụ khác: Global Network Inventory Scanner, AWSPS UDP Scanner, Net Tools Suite Pack, AWPTA, Advanced Port Scanner, MegaPing, Netifera, Network Inventory Explorer.

### 4.2. Biện pháp đối phó quét port (Scanning Countermeasures)

- Cấu hình firewall và luật IDS để phát hiện và chặn các probe.
- Chặn các port không cần thiết tại firewall.
- Dùng bộ luật tuỳ chỉnh (custom rule set) để khoá chặt mạng.
- Ẩn thông tin nhạy cảm khỏi tầm nhìn công khai.

### 4.3. Quét điểm yếu (Vulnerability scanning)

Slide chỉ nêu mục này trong phần nội dung và trong quy trình pen testing (xem mục 6): dùng các công cụ **Nessus, SAINT, GFI LANGuard, Core Impact, Nsauditor, MBSA**…

### 4.4. Vẽ lược đồ mạng

**LANsurveyor** (SolarWinds):

- Tự động khám phá và vẽ sơ đồ network topology.
- Tạo network map trong Microsoft Office Visio.
- Phát hiện thiết bị mới và các thay đổi trong topology.
- Quản lý kiểm kê tài sản phần cứng và phần mềm.
- Đáp ứng trực tiếp PCI compliance và các yêu cầu quy định khác.

**Network mappers:** LANState, CartoReso, Insightix Visibility, Lan-Secure Switch Center, FriendlyPinger, HP OpenView Network Node Manager, Ipsonar, NetMapper.

### 4.5. Sử dụng Proxy

**Proxy server** là một máy tính trong mạng đóng vai trò **trung gian** để kết nối với các máy tính khác. Vai trò:

- Như firewall: bảo vệ mạng nội bộ khỏi truy cập từ bên ngoài.
- Như bộ ghép kênh địa chỉ IP: cho phép nhiều máy truy cập Internet khi chỉ có một địa chỉ IP.
- Có thể bảo vệ ở mức nào đó trước các tấn công hacking.
- Proxy chuyên dụng có thể lọc nội dung không mong muốn (quảng cáo, nội dung không phù hợp).
- Có thể dùng (ở mức độ nào đó) để **ẩn danh khi duyệt web**.

**Tại sao kẻ tấn công dùng proxy server:**

1. Ẩn **địa chỉ IP nguồn** để có thể tấn công mà không gặp hệ quả pháp lý.
2. Trong log của máy nạn nhân, kẻ tấn công xuất hiện với địa chỉ giả của proxy thay vì địa chỉ thật.
3. Truy cập từ xa vào intranet và tài nguyên website thường bị cấm.
4. Chuyển mọi yêu cầu của kẻ tấn công tới đích thứ ba, nên nạn nhân chỉ xác định được địa chỉ của proxy.
5. Dùng **nhiều proxy server** để quét và tấn công, khiến quản trị viên khó lần ra nguồn thật.

**Use of proxies for attack:** tấn công trực tiếp (không proxy) → qua một logged proxy → qua chuỗi nhiều proxy ở nhiều quốc gia (Mexico, Toronto, Dubai, London, Paris, Tokyo, Israel, Philippines…).

**MultiProxy:** chạy tại `127.0.0.1:8088`; lấy từ một danh sách proxy server (host:port) và chuyển tiếp traffic của kẻ tấn công qua các proxy đó tới mục tiêu.

**Free proxy servers:** tìm trên Google ra hàng nghìn proxy server miễn phí.

**Proxifier:** chương trình cho phép các ứng dụng không hỗ trợ proxy hoạt động qua proxy server HTTPS hoặc SOCKS, hoặc qua **chuỗi proxy**.

**HTTP Tunneling:**

- Công nghệ cho phép người dùng thực hiện nhiều tác vụ Internet bất chấp hạn chế của firewall, bằng cách gửi dữ liệu qua **HTTP (port 80)**.
- Tình huống: tổ chức chặn mọi port trên firewall (23, 21, 79, 25, 110, 500, 69…), chỉ cho phép port 80/443 → có thể đóng gói dữ liệu (ví dụ FTP) vào gói HTTP để đi qua; phía ngoài có HTTP tunnel server nhận và chuyển tiếp dữ liệu.

**Công cụ proxy:** Proxy Commander, GProxy, Protoport Proxy Chain, Proxy+, FastProxySwitch, ProxyFinder, ProxyFinder Enterprise, Proxy-Pro Professional GateKeeper.

### 4.6. Ẩn danh (Anonymizers)

- Anonymizer **loại bỏ mọi thông tin nhận dạng** khỏi máy tính người dùng khi lướt Internet.
- Làm hoạt động trên Internet **không thể truy vết**.
- Cho phép **vượt qua** các website bị kiểm duyệt.
- Lý do dùng: privacy và anonymity, vượt qua luật IDS và firewall, bảo vệ khỏi tấn công trực tuyến, truy cập nội dung bị chính phủ hạn chế.

**Công cụ:** Mowser, Anonymous Web Surfing Tool, Hide Your IP Address, JAP Anonymity and Privacy, Anonymizer, The Cloak, IDsecure, Guardster.

### 4.7. Địa chỉ IP giả (IP Spoofing)

- Là việc kẻ tấn công **thay đổi địa chỉ IP** để trông như là người khác.
- Khi nạn nhân phản hồi, gói phản hồi đi về **địa chỉ bị giả mạo** chứ không về địa chỉ thật của kẻ tấn công.
- Ví dụ với Hping2: `hping2 www.juggyboy.com -a 7.7.7.7` (gói gửi đi mang địa chỉ giả 7.7.7.7).
- Hạn chế: **không thể hoàn tất three-way handshake** và mở kết nối TCP thành công khi giả địa chỉ IP.

**Kỹ thuật phát hiện IP spoofing:**

| Kỹ thuật | Cách hoạt động |
|---|---|
| **Direct TTL Probes** | Gửi gói tới host bị mạo danh; nếu **TTL trong phản hồi khác** với TTL của gói đang kiểm tra → gói giả mạo. Thành công khi kẻ tấn công ở **subnet khác** |
| **IP Identification Number** | Gửi gói thăm dò; nếu **IP ID trong phản hồi không gần** giá trị của gói đang kiểm tra → gói giả mạo. Thành công cả khi kẻ tấn công ở **cùng subnet** |
| **TCP Flow Control Method** | Kẻ tấn công gửi gói giả sẽ không nhận được ACK của mục tiêu nên không đáp lại SYN+ACK. Nếu vẫn tiếp tục gửi sau khi hết cửa sổ (window) ban đầu → nhiều khả năng là gói giả |

**Biện pháp đối phó IP spoofing:**

- **Encryption**: mã hoá toàn bộ traffic mạng.
- **Limit Access**: hạn chế truy cập thông tin cấu hình trên máy.
- **Egress Filtering**: dùng bộ lọc ngăn gói tin rời khỏi mạng.
- **Ingress Filtering**: dùng bộ lọc trên router ngăn gói tin đi vào mạng.
- **Sequence Number**: dùng initial sequence number ngẫu nhiên.

---

## 5. Biện pháp phòng chống

### Scanning Pen Testing

- Mục tiêu: xác định **tình trạng an ninh mạng** bằng cách tìm live system, port mở, dịch vụ liên quan và lấy banner hệ thống, mô phỏng từ xa một nỗ lực tấn công mạng.
- Báo cáo pen test giúp quản trị viên hệ thống:
  - **Đóng các port không dùng** (close unused ports).
  - **Tắt các dịch vụ không cần thiết** (disable unnecessary services).
  - **Ẩn hoặc tuỳ chỉnh banner** (hide or customize banners).
  - **Khắc phục lỗi cấu hình dịch vụ** (troubleshoot service configuration errors).
  - **Hiệu chỉnh luật firewall** (calibrate firewall rules).

## 6. Quy trình Scanning Pen Testing

| Bước | Công cụ gợi ý |
|---|---|
| 1. Perform host discovery | Angry IP Scanner, Nmap, Netscan; kiểm tra live host bằng Angry IP Scanner, SolarWinds Engineer's toolset, Colasoft Ping, Utility Ping, Nmap, Netscan |
| 2. Perform port scanning | Nmap, NetScanTools Pro, Net Tools Suite Pack, UDP Scanner |
| 3. Perform banner grabbing / OS fingerprinting | Telnet, Netcraft, Xprobe, Satori |
| 4. Scan for vulnerability | Nessus, SAINT, GFI LANGuard, Core Impact, Nsauditor, MBSA |
| 5. Draw network diagrams | LANsurveyor, Ipsonar, CartoReso, NetMapper |
| 6. Prepare proxies | Proxifier, SocksChain, SSL Proxy, Proxy+, GProxy, ProxyFinder |
| 7. Document all the findings | Lập tài liệu cho mọi phát hiện |

---

## 7. Bài tập

1. Lập bảng tổng hợp các kỹ thuật quét mạng cơ bản (tên, đặc điểm, cách sử dụng, kết quả thu được…).
2. Proxy server là gì? Tại sao hacker sử dụng proxy server?
3. Trình bày các biện pháp phòng chống quét mạng.

**Tên file:** `Bài tập 3B_họtên_mssv.doc`
