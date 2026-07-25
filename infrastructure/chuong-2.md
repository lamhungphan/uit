# Chương 2: Kiến trúc hạ tầng CNTT doanh nghiệp và tư duy hệ thống

## Nội dung
I. Khái niệm cơ sở hạ tầng CNTT  
II. Mô hình hạ tầng tham chiếu  
III. Nguyên tắc cơ bản

---

## I. Khái niệm cơ sở hạ tầng CNTT

### 1. Khái niệm "cơ sở hạ tầng CNTT" (IT Infrastructure) là gì?
Cơ sở hạ tầng CNTT là tập hợp các tài nguyên công nghệ nền tảng (kỹ thuật + vận hành + quản trị) dùng để triển khai, vận hành, bảo vệ và mở rộng các hệ thống số của một tổ chức.

Nó không chỉ là "máy chủ – mạng – máy tính", mà còn gồm nền tảng phần mềm vận hành, quy trình quản trị, cơ chế an toàn thông tin, và dịch vụ hỗ trợ để đảm bảo hệ thống chạy ổn định – an toàn – đúng hiệu năng – đúng chi phí – đúng tuân thủ.

### 2. Mối quan hệ phần cứng – phần mềm – mạng – quản trị – bảo mật

#### (A) Phần cứng (Hardware) — "nền vật lý"
- Máy chủ/PC, storage (SAN/NAS), thiết bị mạng (switch/router/firewall), thiết bị bảo mật, thiết bị người dùng.
- Cung cấp compute + lưu trữ + khả năng kết nối (tài nguyên thô).
- Nếu phần cứng yếu → hệ thống thiếu năng lực xử lý, dễ nghẽn, dễ lỗi phần cứng.

#### (B) Phần mềm (Software) — "nền điều khiển & dịch vụ"
Gồm nhiều lớp:
- Hệ điều hành & ảo hóa/container (Linux/Windows, VMware, K8s).
- Middleware & runtime (web server, app server, message queue).
- Ứng dụng nghiệp vụ (ERP, LMS, HIS, CRM...).
- Hệ quản trị dữ liệu (DBMS, data lake/warehouse).

#### (C) Mạng (Network) — "hệ tuần hoàn"
- LAN/WAN/Internet, SD-WAN, VPN, DNS, load balancer.
- Cho phép các thành phần nói chuyện với nhau: người dùng ↔ ứng dụng ↔ dữ liệu ↔ dịch vụ bên ngoài.
- Mạng quyết định: độ trễ (latency), băng thông, tính sẵn sàng, và là bề mặt tấn công lớn.

#### (D) Quản trị (Governance/Operations) — "luật chơi & kỷ luật vận hành"
- Quy trình: thay đổi (change), sự cố (incident), vấn đề (problem), cấu hình (CMDB), sao lưu/khôi phục (backup/DR).
- Chuẩn & chính sách: kiến trúc, tiêu chuẩn cấu hình, phân quyền, tuân thủ.
- Giám sát & tối ưu: monitoring/observability, capacity planning, FinOps/cost control.

#### (E) Bảo mật (Security) — "lớp bao trùm và xuyên suốt"
- Hardware security: secure boot, TPM/HSM, kiểm soát vật lý.
- OS/App security: hardening, patching, vuln management.
- Network security: segmentation, firewall, IDS/IPS, WAF.
- Identity: IAM/SSO/MFA/PAM (ai được làm gì).
- Data security: mã hóa, DLP, phân loại dữ liệu, audit log.

### 3. Sơ đồ quan hệ (logic phụ thuộc)
- Phần mềm chạy trên phần cứng → cần CPU/RAM/Storage.
- Phần mềm giao tiếp qua mạng → cần DNS, routing, firewall rules, load balancing.
- Mạng + phần mềm + phần cứng phải được quản trị → cấu hình chuẩn, giám sát, sao lưu, khắc phục sự cố, kiểm soát thay đổi.
- Bảo mật xuyên suốt tất cả → danh tính, phân quyền, mã hóa, giám sát bất thường, vá lỗi.

Hardware cung cấp năng lực, Software cung cấp chức năng, Network cung cấp kết nối, Governance cung cấp kiểm soát, và Security cung cấp bảo vệ/niềm tin.

---

## II. Mô hình hạ tầng tham chiếu

### 1. Khái niệm
Mô hình hạ tầng tham chiếu là một khung mô tả chuẩn (blueprint ở mức khái niệm) dùng để:
- Chuẩn hoá cách nhìn về các thành phần hạ tầng (tính toán, lưu trữ, mạng, bảo mật, vận hành, dữ liệu...)
- Làm "bản đồ" để thiết kế/đánh giá/so sánh các phương án triển khai (on-premise, cloud, hybrid)
- Giao tiếp giữa các bên (IT–Security–Data–Business) bằng cùng một ngôn ngữ kiến trúc
- Làm nền cho governance: tiêu chuẩn, chính sách, kiểm soát rủi ro, SLA, tuân thủ.

### 2. Mô hình On-premise
**Định nghĩa**: Hạ tầng (máy chủ, storage, mạng, ảo hoá, bảo mật, vận hành) đặt tại data center của tổ chức (hoặc thuê chỗ colocation nhưng tổ chức vẫn sở hữu/kiểm soát phần lớn).

**Đặc trưng**:
- Tổ chức tự chịu trách nhiệm end-to-end: mua sắm → vận hành → vá lỗi → backup/DR → mở rộng.
- Mở rộng thường theo kiểu capacity planning (mua trước, dùng dần).
- Phù hợp khi yêu cầu kiểm soát vật lý, hệ thống legacy, độ trễ nội bộ thấp, hoặc ràng buộc tuân thủ đặc thù.

### 3. Mô hình Cloud
**Định nghĩa**: Tài nguyên hạ tầng được cung cấp dưới dạng dịch vụ qua nhà cung cấp cloud; tổ chức thuê dùng theo nhu cầu (elastic, pay-as-you-go).

**Đặc trưng**:
- Phân tách theo mô hình dịch vụ:
  - **IaaS**: thuê máy ảo/mạng/storage (doanh nghiệp vẫn quản OS, patch, app).
  - **PaaS**: thuê nền tảng chạy ứng dụng/DB managed (nhà cung cấp gánh nhiều phần vận hành).
  - **SaaS**: dùng ứng dụng hoàn chỉnh (doanh nghiệp chủ yếu quản cấu hình, người dùng, dữ liệu).
- Điểm then chốt là shared responsibility (trách nhiệm chia sẻ).
- Mở rộng nhanh, tự động hoá tốt, nhưng phải quản trị chi phí, cấu hình bảo mật, phụ thuộc nhà cung cấp.

### 4. Mô hình Hybrid
**Định nghĩa**: Kết hợp on-prem + cloud thành một kiến trúc thống nhất, trong đó workload và dữ liệu có thể phân bổ/hợp tác giữa hai môi trường.

**Đặc trưng**:
- Kết nối (VPN/Direct Connect/ExpressRoute/SD-WAN)
- Đồng bộ danh tính & phân quyền (IAM/SSO/MFA)
- Quản trị & quan sát chung (logging/monitoring, policy, CMDB)
- Luồng dữ liệu/ứng dụng liên thông (API, replication, event bus)

### 5. Khung tham chiếu phổ biến

| Lớp năng lực | Phần cứng (HW) | Phần mềm (SW) | Mạng (Network) | Quản trị (Governance/Ops) | Bảo mật (Security) |
|---|---|---|---|---|---|
| **(1) Compute & Connectivity** | Server/PC, storage, switch/router/firewall, endpoint | OS nền, hypervisor, SDN/storage software | LAN/WAN, VPC/VNET, SD-WAN, VPN, DNS, LB cơ bản | Chuẩn cấu hình, inventory/asset, capacity baseline | Hardening, segmentation nền, firewall baseline, TLS/VPN, firmware/patch nền |
| **(2) Ops Platform** | Máy chạy tool/agent (nhẹ) | Monitoring/observability, ITSM, CMDB, patching/orchestration, backup/DR tooling, IaC/automation, FinOps tooling | Telemetry/log/metric pipeline; management plane | Incident/Change/Problem, SLO/SLA, DR drills, capacity planning, cost control, chuẩn vận hành | Audit/log integrity, kiểm soát quyền admin, quy trình vá lỗi, cảnh báo an ninh vận hành |
| **(3) Security + Identity** | Appliance/sensor, HSM/TPM, firewall/WAF (on-prem) | IAM/SSO/MFA, PAM, EDR/XDR, SIEM/SOAR, DLP, KMS, vuln mgmt | ZTNA/VPN, IDS/IPS, WAF path, segmentation/Zero Trust | Policy, risk/compliance, access review, IR playbook | Lớp "bao trùm": identity + policy + detection/response cho (1)-(5) |
| **(4) App & Integration Platform** | Compute nền (1) | Middleware/ESB, API Gateway, microservices, container/K8s, service mesh, message queue/event bus | Ingress/egress, routing nội bộ, service discovery, LB, API traffic control | CI/CD, release/change, versioning API, SRE practice, app observability | AuthN/Z (OIDC/SAML), secrets mgmt, runtime security, API security/WAF, image scanning |
| **(5) Data Platform** | Storage/compute mạnh IO | DBMS, DW/Lake/Lakehouse, ETL/ELT, streaming, catalog/lineage, MDM, DQ tooling | Ingest/replication, batch/stream movement, kết nối nguồn | Data governance, stewardship, retention, data quality rules, metadata standards | Encryption at-rest/in-transit, KMS, masking, row/column security, DLP, audit truy cập dữ liệu |

---

## III. Nguyên tắc cơ bản

### 1) Tính sẵn sàng (Availability)
Tính sẵn sàng là mức độ hệ thống có thể truy cập và hoạt động liên tục khi người dùng cần, thường gắn với SLA/SLO và thời gian downtime cho phép. Nó đạt được nhờ dự phòng (redundancy), loại bỏ điểm lỗi đơn (SPOF), failover, và quy trình vận hành/khôi phục (incident, DR).

### 2) Hiệu năng (Performance)
Hiệu năng phản ánh hệ thống phản hồi nhanh và xử lý đủ tải theo yêu cầu (latency, throughput, IOPS, concurrency). Hiệu năng phụ thuộc đồng thời vào compute–storage–network, tối ưu ứng dụng/dữ liệu, và quan sát để phát hiện nghẽn (bottleneck) nhằm tinh chỉnh liên tục.

### 3) Khả năng mở rộng (Scalability)
Khả năng mở rộng là năng lực tăng/giảm tài nguyên để đáp ứng tăng trưởng người dùng, dữ liệu, hoặc lưu lượng mà vẫn giữ mức dịch vụ chấp nhận được. Bao gồm scale-up (tăng sức mạnh máy) và scale-out (thêm nút), thường cần kiến trúc phù hợp (stateless, phân mảnh dữ liệu, queue/cache) và tự động hoá.

### 4) Chi phí (Cost)
Chi phí là tổng chi phí sở hữu/vận hành (TCO) gồm đầu tư ban đầu (CapEx), chi phí vận hành (OpEx), nhân sự, bản quyền, điện/khấu hao, và chi phí gián tiếp do downtime. Quản trị chi phí tốt đòi hỏi đo lường theo đơn vị tiêu thụ (unit cost), tối ưu sizing, tự động tắt/mở, và cân bằng giữa hiệu năng–sẵn sàng–mức độ quản trị.

### 5) Rủi ro (Risk)
Rủi ro là xác suất và mức độ tác động của các sự cố như mất an toàn thông tin, gián đoạn dịch vụ, mất dữ liệu, vi phạm tuân thủ, hoặc phụ thuộc nhà cung cấp. Giảm rủi ro dựa trên phòng ngừa + phát hiện + ứng phó: kiểm soát truy cập, phân đoạn mạng, mã hoá, sao lưu/khôi phục, giám sát, kiểm thử định kỳ và kế hoạch IR/BCP/DR.

---
