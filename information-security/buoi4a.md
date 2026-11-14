# Bài 3A – Dò tìm lỗ hổng bảo mật thông tin: Thăm dò (Footprinting)

> Môn: Nhập môn Bảo đảm và An ninh thông tin – ThS. Tô Nguyễn Nhật Quang – Trường ĐH Công nghệ Thông tin

## Nội dung bài học

- Thăm dò (Footprinting / Reconnaissance)
  - Khái niệm chung
  - Đối tượng thăm dò
  - Các mối đe doạ
  - Một số kỹ thuật thăm dò: WHOIS, DNS, Network, Website, E-mail Footprinting, Google Hacking
  - Biện pháp phòng chống
  - Bài tập

---

## 1. Khái niệm chung

- Báo chí, phim ảnh thường xuyên đưa những câu chuyện về xâm nhập hệ thống máy tính. Tin tặc là những thiên tài?
- Thực tế phức tạp hơn: tấn công vào một hệ thống đòi hỏi nhiều thời gian nghiên cứu mục tiêu.
- Tin tặc có thể dùng công cụ do người khác viết và tải từ Internet để tấn công mục tiêu.

**Footprinting and reconnaissance** (thực hiện **trước** khi tấn công):

- Thu thập thông tin cơ bản về mục tiêu và mạng của nó.
- Xác định hệ điều hành, nền tảng đang chạy, phiên bản web server…
- Thực hiện bằng các kỹ thuật như Whois, DNS, truy vấn mạng và truy vấn tổ chức.
- Tìm lỗ hổng và exploit để phát động tấn công.

## 2. Đối tượng thăm dò

| Nhóm thông tin | Nội dung thu thập |
|---|---|
| **Network information** | Domain name, internal domain names, network blocks, IP của các hệ thống truy cập được, rogue/private websites, dịch vụ TCP/UDP đang chạy, networking protocols, VPN points, ACLs, IDS đang chạy, số điện thoại analog/digital, cơ chế xác thực |
| **System information** | Tên user và group, system banners, routing tables, thông tin SNMP, kiến trúc hệ thống, loại remote system, tên hệ thống, mật khẩu |
| **Organization information** | Chi tiết nhân viên, website tổ chức, danh bạ công ty, địa chỉ và số điện thoại, thông tin nền về tổ chức, bài báo/thông cáo báo chí |

## 3. Các mối đe doạ

- Business loss (thiệt hại kinh doanh)
- Corporate espionage (gián điệp công ty)
- Privacy loss (mất riêng tư)
- Social engineering (tấn công phi kỹ thuật)
- System and network attacks (tấn công hệ thống và mạng)
- Information leakage (rò rỉ thông tin)

## 4. Một số kỹ thuật thăm dò

### 4.1. Phương pháp luận Footprinting

Quy trình gồm các nhánh: **Internet Footprinting** → **Competitive Intelligence** → **WHOIS Footprinting** → **DNS Footprinting** → **Network Footprinting** → **Website Footprinting** → **E-mail Footprinting** → **Google Hacking**.

### 4.2. Thu thập thông tin qua Internet / công cụ tìm kiếm

**Tìm URL của công ty:** tìm tên công ty bằng Google hoặc Bing.

**Xác định hệ điều hành – SHODAN:** công cụ tìm kiếm cho phép tìm các thiết bị cụ thể (router, server…) bằng nhiều bộ lọc; "expose online devices" như webcam, router, nhà máy điện, điện thoại, tuabin gió, tủ lạnh, VoIP phone. (http://www.shodanhq.com)

**Tìm thông tin công ty:**

- Tìm trên các search engine lớn (Google, Bing), dùng từ khoá phức tạp.
- Thông tin: cập nhật trên website, cơ sở dữ liệu nhân viên, thông cáo báo chí, thông tin liên hệ.
- Kỹ thuật: trích xuất archive và mirror website, tìm trên web, people search, competitive intelligence.

**Công cụ trích xuất dữ liệu công ty:**

| Công cụ | Chức năng |
|---|---|
| Web Data Extractor (webextractor.com) | Trích xuất dữ liệu liên hệ (email, phone, fax) của công ty mục tiêu từ Internet |
| SpiderFoot (binarypool.com) | Công cụ domain footprinting, quét các website trên domain, đồng thời tìm trên Google, Netcraft, Whois, DNS để thu thập thông tin công ty |
| Robtex (robtex.com) | Crawl Internet bằng user-agent "robtexbot", chủ yếu lấy title và meta information |

**Footprinting qua search engine:** kẻ tấn công dùng search engine để trích xuất thông tin về mục tiêu như nền tảng công nghệ, chi tiết nhân viên, trang đăng nhập, intranet portal… phục vụ social engineering và các tấn công hệ thống nâng cao. **Cache** của search engine có thể chứa thông tin nhạy cảm đã bị gỡ khỏi web. (Google, Bing, Yahoo, Ask)

**Thu thập thông tin vị trí:**

- Google Earth để xem vị trí vật lý của mục tiêu.
- Công cụ tìm vị trí địa lý: Google Maps, Wikimapia, National Geographic Maps, Yahoo Maps, Bing Maps.

**People search / mạng xã hội:**

- Mạng xã hội và các dịch vụ people search (ví dụ pipl, LinkedIn) là nguồn thông tin cá nhân và tổ chức lớn.
- Thông tin thu được: địa chỉ nhà và email, số liên lạc và ngày sinh, ảnh và hồ sơ mạng xã hội, URL blog, ảnh vệ tinh nhà riêng, dự án sắp tới và môi trường hoạt động.
- Các trang: Orkut, Facebook, LinkedIn, Twitter.

**Thông tin có trên mạng xã hội:**

| Người dùng làm gì | Tổ chức làm gì | Kẻ tấn công thu được |
|---|---|---|
| Duy trì hồ sơ, kết nối bạn bè/chat, chia sẻ ảnh/video, chơi game/tham gia nhóm, tạo sự kiện | Khảo sát người dùng, quảng bá sản phẩm, hỗ trợ người dùng, tuyển dụng, kiểm tra lý lịch ứng viên | Thông tin liên hệ/vị trí, danh sách bạn bè, danh tính người thân, sở thích, hoạt động; chiến lược kinh doanh, hồ sơ sản phẩm, social engineering, thông tin nền tảng/công nghệ, loại hình kinh doanh |

**Dịch vụ tài chính:** cung cấp giá trị thị trường cổ phiếu, hồ sơ công ty, chi tiết đối thủ (Google Finance, Yahoo! Finance).

**Groups, forums, blogs:**

- Cung cấp thông tin nhạy cảm về mục tiêu: thông tin mạng công cộng, thông tin hệ thống, thông tin cá nhân.
- Đăng ký hồ sơ giả trên Google Groups, Yahoo Groups… để tham gia nhóm nhân viên của tổ chức mục tiêu, nơi họ chia sẻ thông tin cá nhân và công ty.
- Tìm theo FQDN, địa chỉ IP, username trong groups, forums, blogs.

### 4.3. WHOIS Footprinting

- Cơ sở dữ liệu WHOIS do các **Regional Internet Registry** (AfriNIC, ARIN, APNIC, LACNIC, RIPE NCC) duy trì, chứa thông tin cá nhân của chủ sở hữu domain.
- **WHOIS query trả về:** chi tiết domain name, chi tiết liên hệ chủ domain, name server của domain, NetRange.
- **Kẻ tấn công tìm:** vị trí vật lý, số điện thoại, email, liên hệ kỹ thuật và quản trị.
- Công cụ: tamos.com, netcraft.com, whois.net, iptools.com.

**SmartWhois:** tiện ích tra cứu thông tin về một IP, hostname hoặc domain; cung cấp cả quốc gia, bang/tỉnh, thành phố, tên nhà cung cấp mạng, quản trị viên và liên hệ hỗ trợ kỹ thuật.

| Loại công cụ | Công cụ |
|---|---|
| WHOIS cho mobile | DNS Tools (dnssniffer.com), UltraTools Mobile (ultratools.com), Whois Lookup Tool (whois.com.au) |
| WHOIS cài đặt | Sam Spade, My IP Suite, CountryWhois, LanWhois, NetRanger Whois, Lapshins Whois, Alchemy Eye, WebFerret |
| WHOIS online | Whois (tools.whois.net), Whois Lookup (iptools.com), Better Whois, Geek Whois, ARIN Whois Database Search, Network Solutions Whois, DomainTools, AutoWhois |

### 4.4. DNS Footprinting

**Các loại DNS record** (cung cấp thông tin về vị trí và loại server):

| Record | Ý nghĩa |
|---|---|
| A | Trỏ tới địa chỉ IP của host |
| MX | Trỏ tới mail server của domain |
| NS | Trỏ tới name server của host |
| CNAME | Canonical name – cho phép đặt alias cho host |
| SOA | Chỉ thẩm quyền (authority) của domain |
| SRV | Service records |
| PTR | Ánh xạ địa chỉ IP sang hostname |
| RP | Người chịu trách nhiệm (Responsible person) |
| HINFO | Thông tin host, gồm loại CPU và OS |

**Công cụ DNS interrogation:**

- Cài đặt: NetInspector, NSLOOKUP, DigDug (DNS Analyzer), MSR Strider URL Tracer, WhereIsIP, Dnsmap, Multiple Addresses, DNS Tool.
- Online: Online DNS Tools, Better Whois, Professional Toolset (dnsstuff.com), Geek Whois, DNS Record (network-tools.com), Mozzle Domain Name Pro, Check DNS (checkdns.net), Domain Information Groper (kloth.net).
- Dịch vụ tra cứu: DNS Dossier, DNS Lookup (centralops.net, network-tools.webwiz.co.uk).

### 4.5. Network Footprinting

**Xác định dải mạng (Network Range):**

1. Tìm dải địa chỉ IP.
2. Dùng công cụ tìm kiếm cơ sở dữ liệu whois của **ARIN**.

Có thể tìm dải IP và subnet mask do tổ chức mục tiêu sử dụng từ RIR. Kết quả Network Whois record gồm: NetRange, CIDR, NetName, NetHandle, Parent, NetType, NameServer, RegDate, OrgName, Address…

**Traceroute:**

- Hoạt động dựa trên **giao thức ICMP** và dùng **trường TTL** trong header của gói tin để khám phá các router trên đường tới host đích.
- Gửi ICMP Echo request với TTL = 1, 2, 3, 4…; mỗi router giảm TTL, khi TTL về 0 sẽ trả ICMP error message (Time Exceeded) → lộ ra từng hop.

**Traceroute analysis:**

1. Kẻ tấn công dùng traceroute để lấy thông tin về network topology, trusted routers và vị trí firewall.
2. Sau nhiều lần traceroute (ví dụ xem "hop áp chót" của từng đích), có thể suy ra cấu trúc.
3. Ghép thông tin lại để **vẽ sơ đồ mạng** (Hacker – Router – Firewall – Bastion Host/Web Server – DMZ – Mail Server).

**Công cụ traceroute:** 3D Traceroute (d3tr.de), LoriotPro, Path Analyzer Pro (pathanalyzer.com), VisualRoute Trace, GEOSpider, vTrace, Magic NetTrace, 3D Visual Trace Route, Visual IP Trace, Trout, Patrice Zwenger Traceroute.

### 4.6. Website Footprinting

- Là việc theo dõi và phân tích website của tổ chức mục tiêu để lấy thông tin.
- Duyệt website có thể cho biết: phần mềm sử dụng và phiên bản, hệ điều hành, thư mục con/thư mục phụ, tên file/đường dẫn/tên trường cơ sở dữ liệu/truy vấn, nền tảng scripting, chi tiết liên hệ và CMS.
- Dùng **Burp Suite, Zaproxy, Paros Proxy, Website Informer, Firebug…** để xem header: trạng thái kết nối và content-type, Accept-Ranges, thông tin Last-Modified, X-Powered-By, web server đang dùng và phiên bản.

**Mirroring website** (sao chép toàn bộ website):

- Công cụ mirroring tải website về thư mục cục bộ, dựng lại đệ quy mọi thư mục, HTML, ảnh, flash, video và file khác từ server về máy.
- Công cụ: HTTrack Web Site Copier, SurfOffline, PageNest, KeepNI, Wget, Website Ripper Copier, Webripper, BlackWidow, WinWSD, Reamweaver, xaldon WebSpider 2, Teleport Pro.

**Web spiders:**

- Thực hiện tìm kiếm tự động trên website mục tiêu và thu thập thông tin chỉ định như tên nhân viên, địa chỉ email…
- Kẻ tấn công dùng dữ liệu này để tiếp tục footprinting và tấn công social engineering.
- Công cụ: GSA Email Spider, Web Data Extractor.

**Archive.org – Wayback Machine:** cho phép xem các phiên bản lưu trữ của website theo năm/ngày (ví dụ lịch sử của www.uit.edu.vn, www.microsoft.com), từ đó tìm được nội dung đã bị gỡ.

**Theo dõi cập nhật web:** **Website Watcher** – đánh dấu thay đổi trên trang web (màu vàng) và từ khoá (màu xanh).

### 4.7. E-mail Footprinting

**Thu thập thông tin từ email header** (ví dụ header của Gmail) cho biết:

- Địa chỉ IP của người gửi và địa chỉ mà thông điệp được gửi từ đó.
- Mail server của người gửi.
- Ngày giờ nhận ở mail server của người khởi tạo.
- Hệ thống xác thực của mail server người gửi (SPF, DKIM…).
- Ngày giờ gửi, số ID duy nhất của thông điệp, tên đầy đủ người gửi.

**Theo dõi email (email tracking):** phương pháp giám sát và theo dõi email đã gửi tới người nhận dự kiến. Cho biết:

1. Khi nào email được nhận và đọc.
2. Gửi email phá hoại (destructive emails).
3. Vị trí GPS và bản đồ của người nhận.
4. Thời gian đọc email.
5. Người nhận có truy cập link trong email hay không.
6. Theo dõi PDF và các loại file đính kèm khác.
7. Đặt thông điệp tự hết hạn sau thời gian chỉ định.

**Công cụ:** eMailTrackerPro, Read Notify, DidTheyReadIt, PoliteMail; cùng nhóm công cụ trace: VisualRoute Trace, GEOSpider, vTrace, Magic NetTrace, 3D Visual Trace Route, Visual IP Trace, Trout, Patrice Zwenger Traceroute.

### 4.8. Google Hacking

Footprinting bằng kỹ thuật Google Hacking gồm ba thành phần:

| Thành phần | Mô tả |
|---|---|
| Query String | "Google hacking" là thuật ngữ chỉ nghệ thuật tạo ra các truy vấn tìm kiếm phức tạp |
| Vulnerable Sites | Phát hiện các website dễ bị khai thác nhiều lỗ hổng |
| Google Operators | Dùng toán tử Google để định vị các chuỗi văn bản cụ thể trong kết quả tìm kiếm |

**Hacker có thể làm gì với Google Hacking:** tìm advisories và lỗ hổng server, thông báo lỗi chứa thông tin nhạy cảm, file chứa mật khẩu, thư mục nhạy cảm, trang chứa dữ liệu mạng/lỗ hổng, trang đăng nhập (logon portals).

**Google advanced search operators:**

| Toán tử | Chức năng |
|---|---|
| `cache:` | Hiển thị phiên bản trang web mà Google lưu trong cache |
| `link:` | Liệt kê các trang có link tới trang chỉ định |
| `related:` | Liệt kê các trang "tương tự" trang chỉ định |
| `info:` | Hiển thị một số thông tin Google có về trang web đó |
| `site:` | Giới hạn kết quả trong các website thuộc domain đã cho |
| `allintitle:` | Giới hạn kết quả ở các trang có tất cả từ khoá trong title |
| `intitle:` | Giới hạn kết quả ở tài liệu có từ khoá đó trong title |
| `allinurl:` | Giới hạn kết quả ở các trang có tất cả từ khoá trong URL |
| `inurl:` | Giới hạn kết quả ở tài liệu có từ khoá đó trong URL |

**Công cụ Google hacking:** MetaGoofil, Goolink Scanner, SiteDigger, Google Hacks, Google Cartography, Google Hack Honeypot, GMapCatcher, BiLE Suite.

**Công cụ footprinting bổ sung:** Prefix WhoIs, DMitry (Deepmagic Information Gathering Tool), Tctrace, Autonomous System Scanner (ASS), NetScanTools Pro, Netmask, Maltego, Host.

---

## 5. Biện pháp phòng chống

1. Hạn chế nhân viên truy cập mạng xã hội từ mạng của tổ chức.
2. Cấu hình web server để tránh rò rỉ thông tin.
3. Giáo dục nhân viên dùng **bút danh (pseudonym)** trên blog, group, forum.
4. Không tiết lộ thông tin quan trọng trong thông cáo báo chí, báo cáo thường niên, catalogue sản phẩm…
5. Hạn chế lượng thông tin công bố trên website/Internet.
6. Dùng chính các kỹ thuật footprinting để tìm và gỡ thông tin nhạy cảm đang công khai.
7. Ngăn search engine cache trang web và dùng dịch vụ đăng ký ẩn danh (anonymous registration).
8. Áp dụng **chính sách bảo mật** điều chỉnh thông tin nhân viên được phép tiết lộ cho bên thứ ba.
9. Tách DNS nội bộ và bên ngoài hoặc dùng **split DNS**; hạn chế **zone transfer** chỉ cho server được phép.
10. Tắt **directory listing** trên web server.
11. Giáo dục nhân viên về các mánh khoé và rủi ro social engineering.
12. Dùng dịch vụ **privacy** trên cơ sở dữ liệu Whois.
13. Tránh cross-linking cấp domain cho các tài sản quan trọng.
14. **Mã hoá** và bảo vệ bằng mật khẩu thông tin nhạy cảm.

### Footprinting Pen Testing

- Dùng để xác định thông tin mà tổ chức đang công khai trên Internet (kiến trúc mạng, hệ điều hành, ứng dụng, người dùng).
- Người kiểm thử cố thu thập càng nhiều thông tin càng tốt về tổ chức từ Internet và các nguồn công khai khác.
- Giúp quản trị viên: ngăn rò rỉ thông tin, ngăn truy xuất DNS record từ server công khai, ngăn các nỗ lực social engineering.

**Quy trình:**

1. Xin uỷ quyền phù hợp (get proper authorization) và xác định phạm vi đánh giá.
2. Internet footprinting – công cụ: Web Data Extractor, Link Extractor.
3. Thu thập competitive intelligence – SEC Info, Business Wire, C-SPAN.
4. WHOIS footprinting – SmartWhois, Alchemy Eye.
5. E-mail footprinting – NetInspector, NsLookup (theo slide).
6. Website footprinting – 3D Traceroute, LoriotPro (theo slide).
7. Network footprinting – HTTrack Web Site Copier, Wget (theo slide).
8. DNS footprinting – eMailTrackerPro, PoliteMail (theo slide).
9. Google hacking – GHDB, MetaGoofil, SiteDigger.
10. Lập tài liệu cho mọi phát hiện (document all the findings).

> Lưu ý: ở slide quy trình, công cụ gắn với các bước 5–8 không khớp với tên bước (ví dụ "network footprinting" lại ghi HTTrack/Wget, "DNS footprinting" lại ghi eMailTrackerPro/PoliteMail). Phần trên giữ nguyên theo slide.

---

## 6. Bài tập

1. Lập bảng trình bày các kỹ thuật thăm dò (phương pháp, công cụ, mục tiêu…).
2. Nêu các biện pháp phòng chống thăm dò (7–8 biện pháp), liệt kê theo thứ tự ưu tiên (quan trọng) từ cao đến thấp.

**Tên file:** `Bài tập 3A_họtên_mssv.doc`
