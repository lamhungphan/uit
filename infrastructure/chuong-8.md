# Chương 8: Tổng hợp – Đề xuất dự án hạ tầng

**Biên soạn: ThS. Nguyễn Thị Anh Thư**  
**Email: thunta@uit.edu.vn**

---

## Nội dung
1. Quy trình đề xuất dự án hạ tầng  
2. Bước 1 – Xác định nhu cầu  
3. Bước 2 – Phân tích ràng buộc  
4. Bước 3 – Xây dựng tiêu chí đánh giá  
5. Bước 4 – Đề xuất phương án  
6. So sánh và lựa chọn phương án  
7. Bước 5 – Lập kế hoạch triển khai  
8. Tổng kết

---

## 1. Quy trình đề xuất dự án hạ tầng

Quy trình đề xuất dự án hạ tầng có thể triển khai theo 5 bước:

**Xác định nhu cầu → Phân tích ràng buộc → Xây dựng tiêu chí đánh giá → Đề xuất phương án → Lập kế hoạch triển khai**

**Ý nghĩa**:
- Giúp đề xuất có cơ sở thực tiễn
- Tránh lựa chọn giải pháp theo cảm tính
- Đảm bảo phương án phù hợp với mục tiêu, ngân sách, nhân lực và thời gian
- Hỗ trợ nhóm bảo vệ quyết định kỹ thuật một cách thuyết phục

---

## 2. Bước 1 – Xác định nhu cầu

Xác định nhu cầu là bước làm rõ vấn đề cần giải quyết hoặc mục tiêu cần đạt được thông qua dự án hạ tầng.

**Nội dung cần phân tích**:
- Đơn vị/tổ chức đang gặp vấn đề gì?
- Hạ tầng hiện tại có hạn chế nào?
- Người dùng hoặc hệ thống cần thêm năng lực gì?
- Dự án hướng đến cải thiện hiệu năng, bảo mật, khả năng mở rộng hay độ ổn định?
- Kết quả mong đợi sau khi triển khai là gì?

Khi trình bày nhu cầu, cần tránh mô tả chung chung. Nên mô tả theo cấu trúc:

| Thành phần | Nội dung minh họa |
|------------|------------------|
| **Hiện trạng** | Doanh nghiệp đang dùng một server vật lý cho web và database |
| **Vấn đề** | Server thường quá tải vào giờ cao điểm |
| **Ảnh hưởng** | Website phản hồi chậm, ảnh hưởng trải nghiệm khách hàng |
| **Nhu cầu** | Cần nâng cấp hạ tầng theo hướng tách web server và database server |

---

## 3. Bước 2 – Phân tích ràng buộc

Ràng buộc là các giới hạn mà nhóm phải xem xét khi đề xuất và triển khai dự án.

**Các nhóm ràng buộc phổ biến**:
- **Ngân sách**: tổng chi phí đầu tư, chi phí vận hành, chi phí bảo trì
- **Thời gian**: thời hạn triển khai, thời điểm nghiệm thu
- **Nhân lực**: số lượng thành viên, năng lực kỹ thuật, khả năng vận hành sau triển khai
- **Kỹ thuật**: hệ thống hiện có, yêu cầu tương thích, hiệu năng, bảo mật
- **Pháp lý/quy định**: bảo vệ dữ liệu cá nhân, bản quyền phần mềm, quy định nội bộ
- **Vận hành**: thời gian downtime cho phép, khả năng bảo trì, quy trình hỗ trợ người dùng

---

## 4. Bước 3 – Xây dựng tiêu chí đánh giá

Tiêu chí đánh giá giúp so sánh các phương án một cách khách quan và có cơ sở.

Có thể dùng thang điểm: 1: Rất thấp – 2: Thấp – 3: Trung bình – 4: Tốt – 5: Rất tốt.

| Tiêu chí | Ý nghĩa |
|----------|---------|
| Chi phí | Tổng chi phí đầu tư và vận hành |
| Hiệu năng | Khả năng xử lý tải, tốc độ phản hồi |
| Bảo mật | Khả năng kiểm soát truy cập, chống tấn công, bảo vệ dữ liệu |
| Khả năng mở rộng | Dễ nâng cấp khi số lượng người dùng tăng |
| Độ tin cậy | Khả năng hoạt động ổn định, ít gián đoạn |
| Khả năng bảo trì | Dễ quản lý, giám sát, sửa lỗi |
| Tính khả thi | Phù hợp với nhân lực, thời gian, kỹ thuật hiện có |

---

## 5. Bước 4 – Đề xuất phương án

Cấu trúc trình bày mỗi phương án:
- Tên phương án
- Mô tả tổng quan kiến trúc
- Thành phần chính: server, network, storage, firewall, cloud, backup, monitoring
- Ưu điểm
- Hạn chế
- Chi phí dự kiến
- Điều kiện triển khai

| Phương án | Mô tả ngắn |
|-----------|-----------|
| On-premise | Triển khai server và thiết bị mạng tại doanh nghiệp |
| Cloud-based | Sử dụng máy chủ ảo, storage và dịch vụ bảo mật trên cloud |
| Hybrid | Kết hợp hạ tầng nội bộ với dịch vụ cloud |

---

## 6. So sánh và lựa chọn phương án

Cách trình bày lựa chọn:
- Phương án được chọn là gì?
- Vì sao phương án đó phù hợp nhất?
- Phương án có đáp ứng nhu cầu và ràng buộc không?
- Những rủi ro còn lại là gì?
- Cần điều kiện gì để triển khai thành công?

| Tiêu chí | PA1: On-premise | PA2: Cloud | PA3: Hybrid |
|----------|:---------------:|:-----------:|:-----------:|
| Chi phí ban đầu | 2 | 4 | 3 |
| Hiệu năng | 4 | 4 | 4 |
| Bảo mật | 4 | 4 | 5 |
| Mở rộng | 2 | 5 | 4 |
| Bảo trì | 3 | 4 | 3 |
| Tổng điểm | 15 | 21 | 19 |

---

## 7. Bước 5 – Lập kế hoạch triển khai

Kế hoạch triển khai giúp biến phương án thành các hoạt động cụ thể.

**Nội dung cần có**:
- Các giai đoạn triển khai
- Công việc chính trong từng giai đoạn
- Người phụ trách
- Thời gian thực hiện
- Sản phẩm bàn giao
- Mốc kiểm tra/nghiệm thu
- Kế hoạch dự phòng khi có sự cố

| Giai đoạn | Công việc chính | Kết quả |
|-----------|----------------|---------|
| Khảo sát | Thu thập yêu cầu, kiểm tra hiện trạng | Báo cáo hiện trạng |
| Thiết kế | Vẽ mô hình kiến trúc, chọn thiết bị/dịch vụ | Bản thiết kế hạ tầng |
| Triển khai | Cài đặt server, network, firewall, backup | Hệ thống thử nghiệm |
| Kiểm thử | Kiểm tra hiệu năng, bảo mật, khôi phục | Biên bản kiểm thử |
| Nghiệm thu | Bàn giao tài liệu và hướng dẫn vận hành | Hệ thống hoàn chỉnh |

---

## 8. Tổng kết

- Đề xuất dự án hạ tầng cần bắt đầu từ nhu cầu thực tế, không bắt đầu ngay từ công nghệ
- Mỗi phương án cần được đánh giá theo ràng buộc và tiêu chí rõ ràng
- Báo cáo dự án cần có đủ: mục tiêu, phạm vi, yêu cầu, giải pháp, chi phí, rủi ro và lộ trình
- Làm việc nhóm hiệu quả cần phân vai, phối hợp, phản hồi và kiểm tra chéo
- Thuyết trình tốt là trình bày được logic lựa chọn, không chỉ mô tả giải pháp
- Bảo vệ lựa chọn là năng lực quan trọng trong quản lý và triển khai dự án CNTT

---

*Q & A*
