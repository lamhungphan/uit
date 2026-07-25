# CƠ SỞ HẠ TẦNG CÔNG NGHỆ THÔNG TIN

**Biên soạn: ThS. Nguyễn Thị Anh Thư**  
**Email: thunta@uit.edu.vn**

---

# Chương 1: Tổng quan CNTT trong tổ chức và bối cảnh ứng dụng

## Nội dung
I. Vai trò của CNTT trong tổ chức: Hạ tầng vận hành và chuyển đổi số  
II. CNTT trong hệ sinh thái quản trị – vận hành – kinh doanh – dịch vụ số  
III. Bối cảnh ứng dụng CNTT: Từ khu vực công đến các ngành kinh tế – xã hội

---

## I. Vai trò của CNTT trong tổ chức

### 1. Vai trò CNTT trong cơ quan/doanh nghiệp

#### 1.1. CNTT như "xương sống" cho vận hành (Operational Backbone)
CNTT bảo đảm tổ chức chạy ổn định mỗi ngày thông qua:
- Hệ thống nghiệp vụ lõi: ERP, kế toán, nhân sự, CRM, DMS, e-Office, một cửa điện tử...
- Hạ tầng kỹ thuật: mạng, máy chủ/Cloud, lưu trữ, endpoint, email/collab, thoại–họp, thiết bị...
- Bảo mật & tuân thủ: IAM/SSO, phân quyền, log/audit, DLP, backup/DR, quản lý rủi ro.
- Duy trì SLA: đảm bảo tính sẵn sàng, hiệu năng, tính liên tục kinh doanh.

Điểm then chốt: CNTT vận hành tốt = "giảm ma sát" trong quy trình, giảm lỗi, giảm gián đoạn, giảm chi phí ẩn.

#### 1.2. CNTT như "đòn bẩy chiến lược" (Strategic Enabler)
Khi CNTT không chỉ "hỗ trợ" mà tham gia tạo giá trị, nó trở thành năng lực cạnh tranh:
- Tăng tốc ra quyết định dựa trên dữ liệu (BI/Analytics/AI).
- Tối ưu mô hình vận hành (tự động hóa, workflow, RPA, process mining).
- Nâng trải nghiệm khách hàng/người dân (omni-channel, self-service, personalization).
- Mở rộng hệ sinh thái (API, tích hợp đối tác, nền tảng số).

#### 1.3. CNTT như "cơ chế quản trị rủi ro"
Trong bối cảnh rủi ro số tăng (ransomware, lộ lọt dữ liệu, gian lận), CNTT còn là:
- "Hệ miễn dịch" của tổ chức: Zero Trust, giám sát an ninh, ứng cứu sự cố.
- Công cụ đảm bảo tuân thủ (ISO 27001, NIST, quy định dữ liệu cá nhân, lưu trữ hồ sơ...).

### 2. CNTT như "hạ tầng" cho vận hành và chuyển đổi số

#### 2.1. "Hạ tầng" CNTT gồm những lớp nào?
Có thể nhìn CNTT như hạ tầng kiểu "điện–nước–đường" nhưng cho thế giới số, gồm các lớp năng lực:

1. **Hạ tầng tính toán & kết nối**: Data center / Cloud / Hybrid, compute, storage, network, SD-WAN, VPN.
2. **Nền tảng vận hành (Ops Platform)**: Monitoring/Observability, ITSM, CMDB, patching, backup, DR, capacity, FinOps.
3. **Danh tính & bảo mật (Security + Identity)**: IAM/SSO/MFA, PAM, EDR/XDR, SIEM/SOC, WAF, DLP, mã hóa, phân loại dữ liệu.
4. **Nền tảng ứng dụng & tích hợp**: Middleware/ESB, API Gateway, microservices, container/K8s, message queue/event bus.
5. **Nền tảng dữ liệu**: Data warehouse/lakehouse, ETL/ELT, MDM, data governance, data quality, catalog.

#### 2.2. CNTT là "hạ tầng" của chuyển đổi số?
Chuyển đổi số không chỉ là "mua phần mềm", mà là tái thiết năng lực:
- Số hóa quy trình (digitization) → cần workflow, tích hợp, dữ liệu chuẩn.
- Số hóa vận hành (digitalization) → cần tự động hóa + đo lường + giám sát.
- Tái cấu trúc mô hình kinh doanh (transformation) → cần nền tảng API, data, cloud, bảo mật, DevSecOps.

#### 2.3. Mâu thuẫn kinh điển cần quản trị
- Vận hành cần ổn định, kiểm soát thay đổi, chuẩn hóa.
- Chuyển đổi số cần nhanh, thử nghiệm, linh hoạt.

Giải pháp quản trị hay dùng:
- Mô hình Run – Grow – Transform (vừa chạy hệ lõi, vừa cải tiến, vừa đổi mới).
- Kiến trúc doanh nghiệp (EA) + nguyên tắc chuẩn hóa (standards) để "nhanh mà không loạn".
- DevSecOps: tự động hóa kiểm thử–triển khai–bảo mật để tăng tốc nhưng vẫn kiểm soát.

### 3. CNTT tác động trực tiếp đến hiệu quả tổ chức

#### 3.1. Tác động đến chi phí (Cost)
- Giảm chi phí vận hành thủ công, giảm lỗi, giảm thời gian xử lý.
- Tối ưu tài nguyên hạ tầng (ảo hóa/cloud/FinOps).
- Tránh "chi phí sự cố" (downtime, mất dữ liệu, phạt tuân thủ).

#### 3.2. Tác động đến năng suất và chất lượng dịch vụ (Productivity & Service Quality)
- Quy trình end-to-end, ít nhập liệu lặp, ít "đi xin dữ liệu".
- SLA rõ: uptime, MTTR, thời gian xử lý hồ sơ/đơn hàng.

#### 3.3. Tác động đến tốc độ đổi mới (Time-to-Market)
- Có API + data platform + CI/CD → ra tính năng nhanh, tích hợp nhanh.
- Tránh "nợ kỹ thuật" làm chậm mọi dự án.

### 4. Một bộ chỉ số nên theo dõi

**Vận hành (IT Reliability)**
- Availability/Uptime theo hệ thống trọng yếu
- MTTR (Mean Time To Recover), số sự cố P1/P2
- Backup success rate, RPO/RTO đạt hay không

**Chuyển đổi (Delivery & Agility)**
- Deployment frequency, lead time for change, change failure rate (DORA metrics)
- Tỷ lệ quy trình được số hóa end-to-end
- Thời gian tích hợp hệ thống/đối tác (API time)

**Dữ liệu & an ninh**
- Data quality (đầy đủ/đúng/nhất quán/kịp thời)
- Số sự kiện an ninh nghiêm trọng, thời gian phát hiện–ứng cứu
- Tỷ lệ hệ thống đạt chuẩn baseline bảo mật (MFA, EDR, patching...)

### 5. Kết luận phân tích
- CNTT trong tổ chức có 2 vai trò đồng thời: (i) đảm bảo vận hành tin cậy (operational backbone), (ii) tạo nền tảng năng lực để chuyển đổi số (digital platform).
- Muốn "CNTT là hạ tầng cho chuyển đổi số", trọng tâm không chỉ là phần cứng/phần mềm, mà là nền tảng vận hành + an ninh + tích hợp + dữ liệu + quản trị.
- Chuyển đổi số bền vững thường thành công khi tổ chức xây được: hạ tầng tin cậy → nền tảng dùng chung → dữ liệu chuẩn → tích hợp mở → giao hàng nhanh (DevSecOps) → quản trị rủi ro tốt.

---

## II. CNTT trong hệ sinh thái quản trị – vận hành – kinh doanh – dịch vụ số

| Miền | Kỳ vọng từ CNTT | CNTT cung cấp | KPI chung (đo cùng nhau) |
|------|----------------|---------------|--------------------------|
| Quản trị | Minh bạch chi phí, rủi ro, lộ trình | EA, portfolio, compliance, security governance | % dự án đúng hạn/đúng ngân sách; mức tuân thủ; rủi ro giảm |
| Vận hành | Hệ thống ổn định | ITSM, SRE, DR, SOC | Uptime, MTTR, incident rate, RPO/RTO đạt |
| Kinh doanh | Năng lực đạt mục tiêu | Ứng dụng, data/AI, tích hợp | Doanh thu số, conversion, cost-to-serve, cycle time |
| Truyền thông | Kênh & đo lường | MarTech/CRM/CDP, analytics, omni-channel | Adoption, NPS/CSAT, engagement, churn |
| Dịch vụ số | Sản phẩm số tin cậy | DevSecOps, platform, service catalog | SLA/SLO, tốc độ release, change failure rate |

---

## III. Bối cảnh ứng dụng CNTT

- **Nhà nước**: liên thông – tuân thủ – minh bạch – dịch vụ công
- **Doanh nghiệp**: tăng trưởng – tối ưu – đổi mới nhanh – cạnh tranh
- **Giáo dục**: cá nhân hóa – quản trị học tập – đo lường tiến bộ
- **Y tế**: an toàn – chính xác – bảo mật – tiêu chuẩn liên thông
- **Dịch vụ**: omnichannel – real-time – trải nghiệm – chống gian lận
- **Sản xuất**: OT/IT – thời gian thực – độ tin cậy – chất lượng & downtime
