# Tổng hợp Keyword – Cơ sở hạ tầng Công nghệ Thông tin

---

## Chương 1: Tổng quan CNTT trong tổ chức và bối cảnh ứng dụng

### 1) Ứng dụng nghiệp vụ (Business Applications)
- **ERP** (Enterprise Resource Planning): Hệ thống quản trị nguồn lực tổng thể—tích hợp tài chính, kế toán, mua hàng, kho, sản xuất, nhân sự... trong một nền tảng.
- **CRM** (Customer Relationship Management): Hệ thống quản trị quan hệ khách hàng—lưu hồ sơ khách hàng, bán hàng, chăm sóc, marketing, lịch sử tương tác.
- **DMS** (Document Management System): Hệ thống quản lý tài liệu/hồ sơ—lưu trữ, phân loại, tìm kiếm, phiên bản, phân quyền, luồng phê duyệt.

### 2) Quản trị doanh nghiệp & tuân thủ (Enterprise Governance)
- **EA** (Enterprise Architecture): Kiến trúc doanh nghiệp—khung định hướng chuẩn hóa hệ thống, dữ liệu, tích hợp và lộ trình công nghệ.
- **Portfolio**: Danh mục đầu tư/dự án—quản trị ưu tiên, ngân sách, tiến độ và giá trị của các chương trình CNTT/chuyển đổi số.
- **Compliance**: Tuân thủ—đáp ứng quy định/chuẩn (pháp lý, tiêu chuẩn, audit) về dữ liệu, quy trình, bảo mật.
- **Security governance**: Quản trị an ninh—chính sách, vai trò, kiểm soát rủi ro và giám sát thực thi bảo mật.

### 3) Nhận dạng & quản lý truy cập (Identity & Access)
- **IAM/SSO**:
  - IAM: quản lý định danh và quyền truy cập (ai được làm gì, trên hệ thống nào).
  - SSO: đăng nhập một lần dùng nhiều hệ thống (kết hợp MFA nếu cần).
- **MFA** (Multi-Factor Authentication): Xác thực đa yếu tố (mật khẩu + OTP/token/biometrics) để tăng bảo mật đăng nhập.
- **PAM** (Privileged Access Management): Quản lý tài khoản đặc quyền (admin/root): cấp quyền tạm thời, ghi lại phiên thao tác, vault mật khẩu.

### 4) An ninh mạng & phòng thủ (Security)
- **Ransomware**: Loại malware mã hóa hoặc khóa dữ liệu/hệ thống để làm gián đoạn hoạt động, rồi đòi tiền chuộc.
- **Zero Trust**: Cách tiếp cận bảo mật coi mọi truy cập đều không đáng tin cho đến khi được xác minh liên tục.
- **DLP** (Data Loss Prevention): Giải pháp ngăn thất thoát/rò rỉ dữ liệu—phát hiện và chặn gửi nhầm/chia sẻ trái phép dữ liệu nhạy cảm.
- **WAF** (Web Application Firewall): Tường lửa ứng dụng web, chặn tấn công như SQLi, XSS, bot...
- **EDR/XDR**:
  - EDR: phát hiện–phản ứng sự cố trên máy trạm/endpoint.
  - XDR: mở rộng tương quan nhiều nguồn (endpoint, email, network, cloud) để điều tra–ứng cứu tốt hơn.
- **SIEM/SOC**:
  - SIEM: thu thập–phân tích log bảo mật, tương quan cảnh báo.
  - SOC: đội/đơn vị vận hành an ninh 24/7 (giám sát, ứng cứu).

### 5) Mạng & kết nối (Network & Connectivity)
- **SD-WAN** (Software-Defined WAN): Mạng WAN "điều khiển bằng phần mềm", tối ưu kết nối nhiều chi nhánh.
- **VPN** (Virtual Private Network): "Đường hầm" mã hóa để truy cập mạng nội bộ từ xa an toàn.

### 6) Vận hành CNTT & quản lý dịch vụ (IT Operations & Service Management)
- **ITSM** (IT Service Management): Quản lý dịch vụ CNTT theo quy trình (incident, request, change, problem, SLA...).
- **CMDB** (Configuration Management Database): CSDL quản lý cấu hình & tài sản CNTT và quan hệ phụ thuộc.
- **SRE** (Site Reliability Engineering): Thực hành/kỹ thuật đảm bảo độ tin cậy hệ thống bằng tự động hóa, SLO, quan sát/giám sát.
- **Log/Audit**:
  - Log: nhật ký kỹ thuật về sự kiện hệ thống/ứng dụng.
  - Audit: dấu vết kiểm tra phục vụ tuân thủ/điều tra.
- **Backup/DR**:
  - Backup: sao lưu dữ liệu để khôi phục khi mất/xóa/virus.
  - DR: kế hoạch & hạ tầng khôi phục sau thảm họa.
- **SLA/SLO**:
  - SLA: cam kết mức dịch vụ (hợp đồng/thoả thuận).
  - SLO: mục tiêu nội bộ để vận hành đạt SLA.

### 7) Chỉ số độ tin cậy & quản trị sự cố (Reliability & Incident Metrics)
- **Availability / Uptime**: Mức độ sẵn sàng của hệ thống (tỷ lệ thời gian hoạt động bình thường).
- **MTTR** (Mean Time To Restore/Recover): Thời gian trung bình để khôi phục dịch vụ sau sự cố.
- **Incident rate**: Tần suất sự cố trong một khoảng thời gian.
- **P1 / P2**: Mức độ nghiêm trọng của sự cố (P1: nghiêm trọng nhất, P2: nghiêm trọng cao).
- **RPO / RTO**:
  - RPO: mất dữ liệu cho phép tối đa.
  - RTO: thời gian khôi phục tối đa để dịch vụ chạy lại.

### 8) Tích hợp & kiến trúc ứng dụng (Integration & Application Architecture)
- **Middleware/ESB**:
  - Middleware: lớp trung gian giúp hệ thống giao tiếp/trao đổi dữ liệu.
  - ESB: "bus" tích hợp doanh nghiệp (routing, transform, orchestration).
- **API Gateway**: Cổng quản lý API (xác thực, giới hạn tốc độ, routing, logging, versioning).
- **Microservices**: Kiến trúc chia ứng dụng thành các dịch vụ nhỏ, độc lập triển khai/mở rộng.
- **Container/K8s**:
  - Container: đóng gói ứng dụng + phụ thuộc để chạy nhất quán.
  - K8s (Kubernetes): nền tảng điều phối container.
- **Message queue / Event bus**:
  - Message queue: hàng đợi thông điệp để xử lý bất đồng bộ.
  - Event bus: luồng sự kiện publish/subscribe cho kiến trúc hướng sự kiện.

### 9) Quản trị dữ liệu & nền tảng dữ liệu khách hàng (Data Management)
- **MDM** (Master Data Management): Quản trị dữ liệu chủ (khách hàng, sản phẩm, nhà cung cấp...).
- **MarTech/CRM/CDP**:
  - MarTech: bộ công cụ công nghệ marketing.
  - CRM: quản trị quan hệ khách hàng.
  - CDP: nền tảng hợp nhất dữ liệu khách hàng đa nguồn.
- **Analytics**: Phân tích dữ liệu để đo lường, hiểu hành vi, tối ưu quyết định.

### 10) Trải nghiệm số & tăng trưởng (Digital Experience & Growth)
- **Omni-channel**: Đa kênh hợp nhất—trải nghiệm và dữ liệu liền mạch giữa các kênh.
- **Self-service**: Khách hàng/người dùng tự thực hiện các nhu cầu phổ biến.
- **Personalization**: Tùy biến nội dung/đề xuất/ưu đãi/giao diện theo từng người dùng.
- **Adoption**: Mức độ người dùng chấp nhận/sử dụng.
- **NPS/CSAT**:
  - NPS: mức độ sẵn sàng giới thiệu (điểm trung thành).
  - CSAT: mức hài lòng sau tương tác/dịch vụ.
- **Engagement**: Mức độ tương tác.
- **Churn**: Tỷ lệ rời bỏ/ngừng sử dụng.
- **Conversion**: Tỷ lệ chuyển đổi.
- **Cost-to-serve**: Chi phí để phục vụ một khách hàng/đơn hàng/yêu cầu.
- **Cycle time**: Thời gian hoàn tất một quy trình end-to-end.

### 11) Tự động hóa quy trình (Process Automation)
- **RPA** (Robotic Process Automation): Tự động hóa các tác vụ lặp lại theo quy tắc bằng "bot".

### 12) Phân phối phần mềm & DevOps/DevSecOps (Software Delivery)
- **DevSecOps**: Mô hình phát triển–vận hành phần mềm tích hợp bảo mật ngay từ đầu.
- **CI/CD**:
  - CI: tự động build/test khi tích hợp mã.
  - CD: tự động đóng gói, kiểm thử, triển khai.
- **DORA metrics**: Bộ chỉ số đo hiệu quả triển khai phần mềm.
- **Tốc độ release**: Tần suất/nhịp phát hành phiên bản/tính năng.
- **Change failure rate**: Tỷ lệ thay đổi/triển khai gây lỗi.

### 13) Quản trị chi phí Cloud (Cloud Cost Management)
- **FinOps**: Quản trị chi phí cloud theo mô hình phối hợp IT–Finance–Business.

### 14) Bối cảnh OT/IT (Industrial Context)
- **IT**: CNTT "văn phòng/doanh nghiệp": hệ thống quản trị và dữ liệu nghiệp vụ.
- **OT**: Công nghệ vận hành "hiện trường/công nghiệp": điều khiển, giám sát máy móc và quy trình vật lý.

---

## Chương 2: Kiến trúc hạ tầng CNTT doanh nghiệp và tư duy hệ thống

| Keyword | Ý nghĩa |
|---------|---------|
| **PC** | Personal Computer – máy tính cá nhân cho người dùng cuối |
| **SAN** | Storage Area Network – mạng lưu trữ chuyên dụng kết nối máy chủ với hệ thống lưu trữ tốc độ cao |
| **NAS** | Network Attached Storage – thiết bị lưu trữ gắn mạng, cung cấp chia sẻ file qua mạng |
| **CPU** | Central Processing Unit – bộ xử lý trung tâm thực thi lệnh và điều phối tính toán |
| **RAM** | Random Access Memory – bộ nhớ truy cập ngẫu nhiên, lưu dữ liệu tạm thời khi hệ thống chạy |
| **IO (I/O)** | Input/Output – các hoạt động vào/ra dữ liệu giữa CPU–bộ nhớ–đĩa–mạng |
| **LAN** | Local Area Network – mạng cục bộ trong phạm vi nhỏ (phòng, tầng, toà nhà) |
| **WAN** | Wide Area Network – mạng diện rộng kết nối các điểm ở xa (liên tỉnh/quốc gia) |
| **SD-WAN** | Software-Defined Wide Area Network – WAN điều khiển bằng phần mềm để tối ưu định tuyến/hiệu năng/kết nối chi nhánh |
| **VPN** | Virtual Private Network – mạng riêng ảo tạo kênh kết nối an toàn qua Internet |
| **DNS** | Domain Name System – hệ thống phân giải tên miền sang địa chỉ IP |
| **ERP** | Enterprise Resource Planning – hệ thống hoạch định nguồn lực doanh nghiệp |
| **LMS** | Learning Management System – hệ thống quản lý học tập |
| **HIS** | Hospital Information System – hệ thống thông tin bệnh viện |
| **CRM** | Customer Relationship Management – hệ thống quản lý quan hệ khách hàng |
| **DBMS** | Database Management System – hệ quản trị cơ sở dữ liệu |
| **DB** | Database – cơ sở dữ liệu |
| **OS** | Operating System – hệ điều hành |
| **app** | application – ứng dụng |
| **K8s** | Kubernetes – nền tảng điều phối container |
| **VMware** | Nền tảng ảo hoá để chạy nhiều máy ảo trên một hạ tầng vật lý |
| **CMDB** | Configuration Management Database – cơ sở dữ liệu quản lý cấu hình/tài sản CNTT |
| **DR** | Disaster Recovery – khôi phục sau thảm hoạ |
| **FinOps** | Financial Operations – thực hành quản trị chi phí (thường cho cloud) |
| **TPM** | Trusted Platform Module – chip/bộ phần cứng bảo mật hỗ trợ lưu khóa và xác thực |
| **HSM** | Hardware Security Module – thiết bị phần cứng chuyên dụng để sinh/lưu/tiết lộ khóa mật mã |
| **IDS** | Intrusion Detection System – hệ thống phát hiện xâm nhập |
| **IPS** | Intrusion Prevention System – hệ thống ngăn chặn xâm nhập |
| **WAF** | Web Application Firewall – tường lửa ứng dụng web |
| **IAM** | Identity and Access Management – quản lý danh tính và quyền truy cập |
| **SSO** | Single Sign-On – đăng nhập một lần để truy cập nhiều hệ thống |
| **MFA** | Multi-Factor Authentication – xác thực đa yếu tố |
| **PAM** | Privileged Access Management – quản lý truy cập đặc quyền |
| **DLP** | Data Loss Prevention – ngăn ngừa rò rỉ dữ liệu |
| **SLA** | Service Level Agreement – cam kết mức dịch vụ |
| **SLO** | Service Level Objective – mục tiêu mức dịch vụ |
| **SPOF** | Single Point of Failure – điểm lỗi đơn |
| **IOPS** | Input/Output Operations Per Second – số thao tác I/O mỗi giây |
| **TCO** | Total Cost of Ownership – tổng chi phí sở hữu/vận hành |
| **CapEx** | Capital Expenditure – chi phí đầu tư |
| **OpEx** | Operating Expenditure – chi phí vận hành |
| **IR** | Incident Response – ứng phó sự cố |
| **BCP** | Business Continuity Plan – kế hoạch duy trì hoạt động liên tục |
| **IaaS** | Infrastructure as a Service – dịch vụ hạ tầng |
| **PaaS** | Platform as a Service – dịch vụ nền tảng |
| **SaaS** | Software as a Service – dịch vụ phần mềm hoàn chỉnh |
| **API** | Application Programming Interface – giao diện lập trình ứng dụng |
| **vuln** | vulnerability – lỗ hổng bảo mật |
