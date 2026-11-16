# BÀI 5: MÃ ĐỘC VÀ KỸ THUẬT PHÂN TÍCH MÃ ĐỘC

## Phần 1: Giới thiệu về mã độc

### 1. Định nghĩa
**Malware** (Malicious Software) là bất kỳ chương trình, đoạn mã hoặc phần mềm nào được lập trình với ý đồ độc hại, nhằm:
* Xâm nhập hệ thống trái phép.
* Gây hư hại dữ liệu hoặc thiết bị.
* Đánh cắp hoặc làm rò rỉ thông tin nhạy cảm.
* Theo dõi hoạt động người dùng.
* Chiếm quyền điều khiển từ xa.
* Trục lợi kinh tế hoặc phá hoại.

> **Tính chất của Virus máy tính:** Lây lan, Phá hoại, Nhỏ gọn, Tương thích cao, Phát triển kế thừa. *(Một số công cụ tạo virus/trojan tự động phổ biến trước đây như: Terabit Virus Maker, Darkhorse Trojan Maker, JPS Virus Maker, Internet Worm Maker).*

### 2. Phân loại mã độc
* **Virus:** Lây nhiễm bằng cách gắn mã độc vào các tệp tin hợp lệ.
  * *Theo cách thức lây nhiễm:* Overwriting/Cavity, Companion/Camouflage, Shell, File Extension, Multipartite, Macro, Add-on, Intrusive, Direct Action (Transient), Terminate and Stay Resident (TSR).
  * *Theo đối tượng lây nhiễm:* System/Boot Sector, File Viruses, Cluster Viruses, Sparse Infector, Stealth/Tunneling, Encryption, Polymorphic (Đa hình), Metamorphic (Biến hình).
* **Worm (Sâu máy tính):** Có khả năng tự nhân bản và lây lan độc lập qua mạng mà không cần tệp chủ hay tương tác người dùng.
* **Trojan Horse:** Ngụy trang dưới dạng phần mềm hợp pháp/hữu ích để lừa người dùng cài đặt.
  * *Mục đích:* Đánh cắp thông tin (keylogger), xóa/thay thế file hệ thống, tạo traffic ảo (DoS/DDoS), tải thêm spyware/adware, vô hiệu hóa firewall/AV, quay lén/chụp màn hình, biến máy nạn nhân thành proxy hoặc botnet.
  * *Các biến thể phổ biến:* RAT (Remote Access Trojan), E-banking Trojan, Proxy Server Trojan, Botnet Trojan, Command Shell Trojan, Defacement Trojan, Covert Channel Trojan...
* **Backdoor:** Tạo cửa hậu vượt qua cơ chế xác thực thông thường để truy cập từ xa.
* **Rootkit:** Che giấu sự hiện diện của mã độc và duy trì quyền truy cập mức hệ thống (kernel/user mode).
* **Spyware & Adware:** Gián điệp thu thập thông tin người dùng và hiển thị quảng cáo trái phép.
* **Ransomware:** Mã hóa dữ liệu trên hệ thống và đòi tiền chuộc để giải mã.
* **Botnet:** Mạng lưới các máy tính bị nhiễm mã độc (zombie/bot) chịu sự điều khiển từ xa của kẻ tấn công (Botmaster).
* **Crypter:** Công cụ dùng để mã hóa, làm rối mã độc nhằm qua mặt các phần mềm diệt virus.

### 3. Nguồn lây nhiễm
* **Email Phishing:** File đính kèm độc hại (`.docm`, `.xlsm`, `.pdf`, `.zip`) hoặc liên kết dẫn tới trang tải mã độc.
* **Web Compromised / Drive-by Download:** Truy cập website bị chèn mã độc, trình duyệt/plugin tự động bị khai thác lỗ hổng thông qua các **Exploit Kit** (bộ công cụ tự động dò tìm lỗ hổng trên máy nạn nhân và thả payload).
* **Ứng dụng nhắn tin (Messenger) & Chia sẻ file:** Gửi trực tiếp qua chat hoặc mạng chia sẻ ngang hàng.
* **Phần mềm miễn phí / Crack:** Cài đặt các ứng dụng không rõ nguồn gốc, game lậu, screensaver...
* **Thiết bị ngoại vi:** USB, ổ cứng di động cắm vào hệ thống.
* **Supply Chain Attack:** Mã độc được cài cắm trực tiếp vào phần mềm hợp pháp hoặc bản cập nhật từ nhà cung cấp (ví dụ: vụ tấn công SolarWinds).

### 4. Vòng đời của mã độc (Malware / APT Lifecycle)
1. **Preparation (Chuẩn bị):** Xác định và nghiên cứu mục tiêu, tổ chức nhóm, xây dựng công cụ và thử nghiệm né tránh phát hiện.
2. **Delivery / Initial Intrusion (Xâm nhập):** Đưa mã độc vào hệ thống thông qua Dropper (chương trình cài đặt mã độc) hoặc Wrapper (công cụ đóng gói mã độc chung với phần mềm sạch).
3. **Execution (Thực thi):** Kích hoạt mã độc chạy trên hệ thống (qua thao tác bật Macro của người dùng, khai thác lỗ hổng trình duyệt/dịch vụ, hoặc chạy các script như PowerShell, VBScript, JS, Batch).
4. **Persistence (Duy trì hiện diện):** Đảm bảo mã độc vẫn hoạt động sau khi khởi động lại máy (qua Registry Run keys, Scheduled Tasks, Windows Services, thư mục Startup).
5. **Expansion / Lateral Movement (Mở rộng & Lan truyền):** Thu thập thông tin xác thực (Pass-the-Hash, Pass-the-Ticket) và lây lan sang các máy khác trong mạng qua SMB, RDP, WMI, PSExec...
6. **Command & Control (C2) & Exfiltration:** Kết nối về máy chủ điều khiển, đánh cắp dữ liệu (qua HTTP/S, DNS tunneling, Cloud) hoặc thực hiện mục tiêu phá hoại (Ransomware, DDoS, Crypto-mining).
7. **Cleanup (Xóa dấu vết):** Xóa log hệ thống, tự hủy file thực thi ban đầu hoặc dùng rootkit ẩn tiến trình.

---

## Phần 2: Cấu trúc và hành vi của mã độc

### 1. Cấu trúc file thực thi (PE File - Windows `.exe`, `.dll`)
* **Header:** Chứa metadata mô tả file (hệ điều hành mục tiêu, kiến trúc 32/64-bit, điểm bắt đầu thực thi **Entry Point**, số lượng section). Dấu hiệu bất thường ở Header thường là chỉ báo của mã độc.
* **Sections (Các phân đoạn chính):**
  * `.text`: Chứa mã lệnh thực thi (code) của chương trình.
  * `.data`: Chứa dữ liệu, biến toàn cục đã khởi tạo.
  * `.rdata`: Chứa chuỗi ký tự (strings), hằng số, thông tin import/export.
  * `.rsrc`: Chứa tài nguyên (icon, hình ảnh, thông điệp, hoặc nơi mã độc giấu cấu hình/payload).
* **Import Table:** Bảng liệt kê các hàm API của hệ điều hành mà chương trình gọi tới. Giúp nhà phân tích dự đoán hành vi (ví dụ: gọi hàm ghi file, sửa registry, kết nối mạng, tạo tiến trình).
* **Resources:** Chứa giao diện, biểu tượng; thường bị lợi dụng để nhúng file thực thi phụ, URL C2 hoặc khóa giải mã.

### 2. Kỹ thuật che giấu và né tránh (Obfuscation & Evasion)

| Kỹ thuật | Cơ chế hoạt động | Mục đích chính |
| :--- | :--- | :--- |
| **Packing (Đóng gói)** | Nén hoặc mã hóa toàn bộ file thực thi gốc; chỉ tự giải nén vào bộ nhớ (RAM) khi chạy. | Ẩn hành vi thật, thay đổi chữ ký file để qua mặt Antivirus. |
| **Obfuscation (Làm rối)** | Mã hóa/đảo chuỗi, đổi tên biến vô nghĩa, chèn lệnh rác, làm phức tạp luồng điều khiển. | Gây khó khăn cho việc đọc hiểu mã nguồn và phân tích tĩnh. |
| **Anti-VM** | Kiểm tra đặc trưng phần cứng/driver (VMware, VirtualBox), tên máy, số lượng CPU/RAM thấp. | Ngừng hoạt động hoặc chạy hành vi giả khi phát hiện đang nằm trong máy ảo. |
| **Anti-Debugging** | Gọi API `IsDebuggerPresent`, tạo vòng lặp vô hạn, bẻ lái luồng thực thi hoặc tự thoát. | Ngăn chặn nhà phân tích sử dụng trình gỡ lỗi (OllyDbg, x64dbg). |
| **AV Evasion** | Chia nhỏ payload, tải mã độc từ Internet sau khi chạy, sử dụng kỹ thuật **Fileless** (chạy hoàn toàn trên RAM). | Tránh để lại dấu vết trên ổ cứng, vô hiệu hóa cơ chế quét truyền thống. |

### 3. Hành vi điển hình của mã độc
1. **Thao tác File:** Tạo file mới trong thư mục hệ thống, tự nhân bản, mã hóa dữ liệu (Ransomware đổi đuôi thành `.locked`).
2. **Thay đổi Registry & Cấu hình:** Thêm khóa tự khởi động (`HKCU\Software\Microsoft\Windows\CurrentVersion\Run`), vô hiệu hóa Task Manager, CMD, Regedit, Windows Defender.
3. **Process Injection:** Tiêm mã độc vào các tiến trình hợp pháp của Windows (`explorer.exe`, `svchost.exe`) để hoạt động ngầm.
4. **Giao tiếp mạng (C2):** Gửi/nhận dữ liệu tới IP/Domain độc hại qua HTTP/HTTPS, DNS hoặc giao thức tùy chỉnh.
5. **Duy trì tồn tại (Persistence):** Lợi dụng Registry Run, Scheduled Task, Windows Service, Startup folder.
6. **Đánh cắp thông tin:** Keylogger, chụp màn hình (Screen capture), đánh cắp mật khẩu trình duyệt/Wi-Fi, theo dõi Clipboard.
7. **Phá hoại & Chiếm tài nguyên:** Xóa file/log, ghi đè MBR (Master Boot Record), đào tiền ảo (Crypto-mining) gây quá tải CPU/GPU.

### 4. Các chỉ dấu lây nhiễm (Indicators of Compromise - IoCs)
IoC là các bằng chứng kỹ thuật cho thấy hệ thống đã bị xâm nhập, được thu thập từ log AV/EDR, Sysmon, SIEM, PCAP và các nguồn Threat Intelligence (VirusTotal, MISP, Abuse.ch):

* **Host-based IoCs (Mức hệ thống):**
  * File lạ xuất hiện ở `System32`, `Temp`, `Startup`, `/tmp`; file giả mạo tên tiến trình hệ thống.
  * Biến đổi khóa Registry khởi động hoặc thay đổi liên kết mở file (`.exe`, `.bat`).
  * Tiến trình chạy nền chiếm dụng tài nguyên cao, không có chữ ký số.
  * Scheduled Tasks / Cron jobs lạ; Firewall hoặc Antivirus bị tắt.
* **Network-based IoCs (Mức mạng):**
  * Kết nối tới Domain mới đăng ký, IP nằm trong blacklist C2/Botnet.
  * Lưu lượng tải lên (outbound) tăng đột biến bất thường hoặc kết nối ngoài giờ làm việc.
  * Gói tin chứa User-Agent giả mạo hoặc chuỗi mã hóa Base64/RC4 đặc trưng.
* **File-based IoCs (Mức tập tin):**
  * Mã băm (Hash): `MD5`, `SHA-1`, `SHA-256`.
  * Chữ ký số không hợp lệ, chứng chỉ bị thu hồi (revoked) hoặc giả mạo nhà phát hành.
* **Behavioral IoCs (Mức hành vi):**
  * Hành vi tự giải nén, tiêm tiến trình (Process Injection), hook API, kiểm tra môi trường ảo.

---

## Phần 3: Phân tích tĩnh (Static Analysis)

### 1. Mục tiêu
Phân tích cấu trúc, chuỗi ký tự và mã lệnh của mẫu mã độc **mà không cần thực thi nó** nhằm hiểu sơ bộ chức năng, nhận diện cơ chế lây nhiễm/persistence, đánh giá độ phức tạp và trích xuất IoC/chữ ký phát hiện.

### 2. Công cụ phân tích tĩnh
* **Xem cấu trúc PE:** `PEview`, `CFF Explorer`, `PEStudio`, `ExeInfoPE`, `Detect It Easy (DIE)`.
* **Phân tích chuỗi (Strings):** `Strings` (Sysinternals), `FLOSS` (giải mã chuỗi bị làm rối), `BinText`.
* **Kiểm tra Hash & Chữ ký số:** `HashMyFiles`, `Sigcheck`, `md5sum`/`sha256sum`.
* **Disassembler & Decompiler:** `IDA Free/Pro` (Hex-Rays), `Ghidra`, `Radare2/Cutter`, `Binary Ninja`.
* **Nhận diện & Unpack:** `UPX`, `PEiD`, `DIE`, `UnpacMe`.
* **Phân tích tài nguyên (Resource):** `Resource Hacker`, `ResEdit`.
* **Sandbox tĩnh & Signature:** `VirusTotal`, `Hybrid-Analysis`, `Intezer`, `YARA`, `ClamAV`.

### 3. Quy trình 10 bước phân tích tĩnh
1. **Chuẩn bị môi trường:** Sử dụng máy ảo cách ly (Host-Only/ngắt mạng), chụp Snapshot sạch.
2. **Thu thập thông tin ban đầu:** Ghi nhận tên file, kích thước, tính mã Hash (MD5/SHA256) tra cứu trên VirusTotal, kiểm tra chữ ký số (`Sigcheck`).
3. **Kiểm tra cấu trúc & Metadata:** Dùng `DIE`, `PEStudio` kiểm tra Header, Entry Point, Timestamp và các Section bất thường (`.upx`, `.textbss`...).
4. **Phát hiện Packing/Obfuscation:** Kiểm tra độ hỗn loạn dữ liệu (Entropy) và công cụ đóng gói để quyết định unpack hay chuyển sang phân tích động.
5. **Phân tích chuỗi (Strings):** Trích xuất URL, IP, domain C2, đường dẫn file, khóa registry, thông báo lỗi hoặc lệnh thực thi.
6. **Kiểm tra Import Table & API:** Dự đoán hành vi dựa trên nhóm hàm API được gọi:
   * *Mạng:* `WinHttpOpen`, `InternetConnect`
   * *File:* `CreateFile`, `WriteFile`
   * *Tiến trình:* `CreateProcess`, `OpenProcess`
   * *Registry:* `RegSetValue`
   * *Mã hóa:* `CryptEncrypt`, `CryptGenKey`
7. **Phân tích Resource:** Dùng `Resource Hacker` tìm các file nhúng (DLL, script, cấu hình) hoặc icon giả mạo.
8. **Dịch ngược mã máy (Disassembly/Decompile):** Dùng `Ghidra` hoặc `IDA` đọc biểu đồ luồng điều khiển (CFG) và mã giả (pseudo-code) để tìm hàm giải mã, kết nối C2.
9. **Trích xuất IoCs:** Tổng hợp Hash, chuỗi, API, đường dẫn để viết luật **YARA** hoặc **Snort/Suricata**.
10. **Tổng hợp & Điều hướng:** Đánh giá mức độ nguy hiểm và quyết định bước tiếp theo (chuyển sang phân tích động hoặc báo cáo SOC/CSIRT).

---

## Phần 4: Phân tích động (Dynamic Analysis)

### 1. Môi trường phân tích an toàn (Sandbox)
Chạy thử nghiệm mã độc trong môi trường được cô lập hoàn toàn để quan sát hành vi thực tế:
* **Sandbox tự động:** `Cuckoo Sandbox`, `CAPE Sandbox`, `Any.Run`, `Hybrid Analysis`, `Joe Sandbox` (nhanh, tự xuất báo cáo nhưng dễ bị mã độc tinh vi phát hiện).
* **Sandbox thủ công:** Tự dựng trên `VMware` hoặc `VirtualBox` (kiểm soát sâu, dễ tùy biến để qua mặt kỹ thuật Anti-VM).
* **Cô lập mạng:** Sử dụng chế độ *Host-Only*, *Internal Network* kết hợp công cụ giả lập dịch vụ mạng như `FakeNet-NG` hoặc `INetSim` để đánh lừa mã độc rằng nó đang kết nối Internet thật.
* **Kỹ thuật ẩn máy ảo (Anti-Anti-VM):** Đổi tên máy giống máy người dùng thật, tăng dung lượng RAM/CPU, cài sẵn các ứng dụng văn phòng/trình duyệt phổ biến, ẩn tiến trình/registry của VMware Tools.

### 2. Nguyên tắc an toàn khi chạy Malware trong Lab
1. **Cô lập tuyệt đối:** Không bao giờ chạy mã độc trên máy thật.
2. **Kiểm soát mạng:** Ngắt Internet thật, chỉ dùng mạng giả lập.
3. **Tắt tính năng chia sẻ:** Vô hiệu hóa Shared Folder, Shared Clipboard và Drag-and-Drop giữa máy thật và máy ảo.
4. **Phân quyền hợp lý:** Chạy mẫu dưới quyền User thường trước; chỉ dùng quyền Administrator khi mã độc yêu cầu để kích hoạt hành vi.
5. **Tắt bảo vệ trong VM:** Tắt Windows Defender/AV bên trong máy ảo lab (nhưng luôn bật trên máy thật).
6. **Snapshot & Rollback:** Luôn chụp Snapshot trước khi chạy và khôi phục lại trạng thái sạch ngay sau khi phân tích xong.
7. **Lưu trữ Log đầy đủ:** Ghi lại toàn bộ nhật ký tiến trình, mạng và hệ thống.
8. **Đóng gói an toàn khi chia sẻ:** Nếu cần gửi mẫu mã độc, phải nén file và đặt mật khẩu chuẩn (thường là `infected`).
9. **Không dùng tài khoản thật:** Tuyệt đối không đăng nhập email, mạng xã hội hay ngân hàng trong máy ảo phân tích.

### 3. Công cụ phân tích động
* **Giám sát tiến trình:** `Process Monitor (Procmon)` (theo dõi File, Registry, Process theo thời gian thực), `Process Explorer` (xem cây tiến trình và DLL được nạp).
* **Giám sát mạng:** `Wireshark` (bắt và phân tích gói tin), `TCPView` / `CurrPorts` (xem các cổng kết nối đang mở), `Capsa Network Analyzer`, `FakeNet-NG`, `INetSim`.
* **Giám sát thay đổi hệ thống:** `Regshot` (chụp và so sánh sự thay đổi của Registry trước/sau khi chạy mẫu), `Sysmon` (ghi log sự kiện chi tiết).
* **Giám sát File & Startup:** `FileActivityWatch`, `FolderChangesView`, `Autoruns`.
* **Giám sát API & Debug:** `API Monitor` (theo dõi trực tiếp các lời gọi hàm Windows API), `x64dbg` / `OllyDbg`.

### 4. Quy trình 8 bước phân tích động
1. **Chuẩn bị môi trường:** Bật máy ảo cô lập, khởi chạy sẵn các công cụ giám sát (`Procmon`, `Wireshark`, `FakeNet-NG`).
2. **Ghi nhận trạng thái gốc (Baseline):** Chụp ảnh Registry bằng `Regshot`, lưu danh sách tiến trình và kết nối mạng ban đầu.
3. **Thực thi mẫu mã độc:** Chạy file dưới quyền User thường; quan sát phản ứng tức thì.
4. **Theo dõi hoạt động hệ thống:** Quan sát cây tiến trình cha-con, file mới tạo/bị mã hóa, khóa Registry autostart và lưu lượng mạng C2.
5. **Giám sát thời gian thực (Live Monitoring):** Kết hợp `Procexp`, `Procmon`, `API Monitor` và `Wireshark` để bắt trọn luồng hành vi.
6. **Ghi nhận thay đổi sau thực thi:** Chụp `Regshot` lần 2 và nhấn *Compare* để tìm các thay đổi; xuất log từ `Procmon` và trích xuất toàn bộ IoCs (IP, Domain, Mutex, File path, Registry key).
7. **Phân tích & Kết luận:** Xác định chủng loại mã độc, mục tiêu tấn công, cơ chế persistence và khả năng lây lan.
8. **Lập báo cáo:** Tổng hợp Process Tree, hành vi chính, danh sách IoCs và đề xuất phương án ngăn chặn.

---

## Phần 5: Kỹ thuật phòng chống và phát hiện mã độc

### 1. Phòng ngừa ở cấp độ người dùng
* **Thói quen an toàn:** Không mở file đính kèm hoặc nhấp vào liên kết lạ trong email/tin nhắn; không sử dụng phần mềm crack, keygen; cập nhật hệ điều hành và ứng dụng thường xuyên.
* **Quản lý xác thực:** Sử dụng mật khẩu mạnh, bật xác thực đa yếu tố (**MFA**), hạn chế lưu mật khẩu trực tiếp trên trình duyệt.
* **Sao lưu định kỳ:** Tuân thủ nguyên tắc **Backup 3-2-1** (3 bản sao dữ liệu, lưu trên 2 loại phương tiện khác nhau, có ít nhất 1 bản lưu trữ ngoại tuyến/offline) để chống lại Ransomware.

### 2. Phòng vệ ở cấp độ hệ thống
* **Quản lý bản vá & Ứng dụng:** Cập nhật bản vá bảo mật định kỳ (Patch Management); vô hiệu hóa tính năng tự động chạy Macro trên Microsoft Office; luôn bật Windows Defender / EDR.
* **Quản lý đặc quyền:** Áp dụng nguyên tắc **Đặc quyền tối thiểu (Least Privilege)**, sử dụng tài khoản User thông thường cho công việc hàng ngày thay vì tài khoản Administrator.
* **Gia cố hệ thống (Hardening):** Tắt các dịch vụ và cổng (port) không cần thiết; giới hạn truy cập từ xa qua RDP, SMB; bật Host-based Firewall.

### 3. Phòng vệ ở cấp độ mạng
* **Tường lửa & Hệ thống phát hiện/ngăn chặn xâm nhập:** Triển khai Firewall và **IDS/IPS** (Snort, Suricata) để phát hiện lưu lượng C2 và chặn các gói tin khai thác lỗ hổng.
* **Lọc DNS (DNS Filtering):** Chặn truy vấn tới các tên miền độc hại hoặc nằm trong danh sách đen (Blacklist).
* **Phân vùng mạng (Network Segmentation):** Chia nhỏ mạng nội bộ thành các vùng độc lập để hạn chế khả năng lây lan ngang (Lateral Movement) khi có một máy bị nhiễm.

### 4. Các phương pháp phát hiện mã độc
* **Phát hiện dựa trên chữ ký (Signature-based):** So khớp mã Hash, chuỗi ký tự hoặc mẫu byte đặc trưng. *Ưu điểm:* Nhanh, độ chính xác cao. *Nhược điểm:* Không phát hiện được mã độc mới (Zero-day) hoặc mã độc đã qua làm rối/đóng gói.
* **Phát hiện dựa trên hành vi (Behavior-based):** Giám sát các hành động bất thường theo thời gian thực (tiêm tiến trình, mã hóa hàng loạt file, sửa khóa Run). *Ưu điểm:* Phát hiện được biến thể mới. *Nhược điểm:* Có thể gây cảnh báo giả (False Positive).
* **Phát hiện bằng Machine Learning / AI:** Huấn luyện mô hình từ các đặc trưng tĩnh và động để nhận diện mã độc chưa từng biết (tích hợp trong các giải pháp EDR/XDR hiện đại).
* **Phát hiện dựa trên Sandbox:** Tự động đưa các file đáng ngờ từ email/web vào môi trường ảo hóa để chạy thử và phân tích hành vi trước khi cho phép đi vào mạng nội bộ.

### 5. Quy trình phản ứng sự cố (Incident Response)
1. **Cô lập (Containment):** Ngắt kết nối mạng ngay lập tức đối với các máy trạm/máy chủ bị nhiễm để ngăn chặn lây lan.
2. **Loại bỏ (Eradication):** Sử dụng công cụ AV/EDR chuyên dụng hoặc tiến hành gỡ bỏ thủ công các file, tiến trình, dịch vụ và khóa registry độc hại.
3. **Khôi phục (Recovery):** Phục hồi dữ liệu từ các bản sao lưu sạch (tuyệt đối không trả tiền chuộc cho tin tặc khi bị Ransomware).
4. **Rút kinh nghiệm (Lessons Learned):** Viết báo cáo phân tích sau sự cố, cập nhật thêm các luật phát hiện (IoC, YARA, IDS rules) và siết chặt chính sách an toàn thông tin.