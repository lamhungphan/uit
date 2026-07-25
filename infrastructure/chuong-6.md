# Chương 6: Quản trị hệ thống và vận hành hạ tầng

**Biên soạn: ThS. Nguyễn Thị Anh Thư**  
**Email: thunta@uit.edu.vn**

---

## Nội dung
I. Nguyên tắc quản trị  
II. Khái niệm  
III. Quản trị  
IV. Tổng kết

---

## I. Nguyên tắc quản trị

### 1. Quản lý người dùng

Quản lý người dùng là quá trình tạo, cập nhật, tạm ngưng và thu hồi tài khoản theo vòng đời sử dụng.

**Mục tiêu**:
- Đúng người dùng
- Đúng thời điểm
- Đúng phạm vi sử dụng
- Dễ kiểm soát và truy vết

**Nguyên tắc cơ bản**:
- Mỗi người dùng có tài khoản riêng
- Không dùng chung tài khoản quản trị
- Tài khoản nghỉ việc/chuyển vị trí phải được xử lý ngay
- Tài khoản không dùng đến phải bị vô hiệu hóa định kỳ

### 2. Phân quyền

Phân quyền là việc xác định ai được làm gì trên hệ thống.

**Các mức quyền phổ biến**: Xem; Tạo mới; Chỉnh sửa; Xóa; Quản trị.

**Nguyên tắc phân quyền**:
- **Least privilege**: chỉ cấp quyền tối thiểu cần thiết
- **Need-to-know**: chỉ truy cập phần thông tin cần cho công việc
- **Separation of duties**: tránh một người nắm toàn bộ quy trình quan trọng

**Cách triển khai phổ biến**:
- Phân quyền theo cá nhân
- Phân quyền theo nhóm
- Phân quyền theo vai trò (RBAC)

### 3. Cấu hình

Cấu hình là tập hợp các tham số, thiết lập và tiêu chuẩn vận hành của hệ thống.

**Ví dụ**: Cấu hình máy chủ; Cấu hình mạng; Cấu hình ứng dụng; Cấu hình bảo mật.

**Nguyên tắc thực hiện**:
- Có chuẩn cấu hình ban đầu (baseline)
- Mọi thay đổi phải được phê duyệt và ghi nhận
- Ưu tiên mẫu cấu hình chuẩn
- Lưu lịch sử phiên bản cấu hình

### 4. Nhật ký (Log)

Nhật ký (log) là bản ghi lại các sự kiện xảy ra trên hệ thống.

**Các loại nhật ký thường gặp**: Nhật ký đăng nhập/đăng xuất; Nhật ký thay đổi cấu hình; Nhật ký truy cập ứng dụng; Nhật ký lỗi và cảnh báo; Nhật ký bảo mật.

**Yêu cầu cơ bản**:
- Ghi log đầy đủ, đúng thời gian
- Đồng bộ thời gian hệ thống
- Lưu trữ an toàn, tránh bị sửa/xóa tùy tiện
- Có cơ chế tìm kiếm và cảnh báo

### 5. Sao lưu – Khôi phục

Sao lưu (backup): tạo bản sao dữ liệu để phòng mất mát.  
Khôi phục (restore/recovery): phục hồi dữ liệu hoặc dịch vụ khi có sự cố.

**Nguyên tắc cơ bản**:
- Sao lưu định kỳ
- Lưu nhiều phiên bản
- Có bản sao ngoài hệ thống chính
- Kiểm tra khả năng khôi phục định kỳ

**Khái niệm cần biết**:
- **RPO**: mất dữ liệu tối đa chấp nhận được
- **RTO**: thời gian khôi phục tối đa chấp nhận được

**Thực hành tốt**:
- Áp dụng nguyên tắc 3-2-1
- Có kịch bản khôi phục cho từng mức sự cố
- Thử nghiệm restore, không chỉ backup

---

## II. Khái niệm

### 1. SLA/Uptime

**SLA** (Service Level Agreement): cam kết mức độ dịch vụ giữa đơn vị cung cấp và đơn vị sử dụng.  
**Uptime**: tỷ lệ thời gian hệ thống hoạt động bình thường.

**Ví dụ mức uptime thường gặp**:
- 99%: phù hợp dịch vụ cơ bản (~7 giờ 18 phút/tháng)
- 99.9%: phổ biến với dịch vụ quan trọng (~44 phút/tháng)
- 99.99%: yêu cầu cao hơn (~4 phút 23 giây/tháng)

### 2. Giám sát

Giám sát là quá trình theo dõi liên tục tình trạng của hạ tầng và dịch vụ.

**Các nhóm giám sát cơ bản**:
- Hạ tầng: CPU, RAM, disk, network
- Dịch vụ: web, database, mail, API
- Ứng dụng: lỗi, thời gian phản hồi, tỷ lệ thành công
- Bảo mật: đăng nhập bất thường, thay đổi trái phép

### 3. Quy trình xử lý sự cố

Incident là sự cố làm giảm chất lượng hoặc gián đoạn dịch vụ CNTT.

**Quy trình cơ bản gồm 6 bước**:
1. Phát hiện / tiếp nhận
2. Phân loại mức độ ảnh hưởng
3. Phân công người xử lý
4. Khoanh vùng và khắc phục tạm thời
5. Khôi phục dịch vụ
6. Tổng kết nguyên nhân và phòng ngừa tái diễn

**Phân mức sự cố**:
- **P1**: nghiêm trọng, gián đoạn diện rộng
- **P2**: ảnh hưởng lớn nhưng có giải pháp tạm
- **P3**: ảnh hưởng cục bộ
- **P4**: lỗi nhỏ/yêu cầu hỗ trợ

---

## III. Quản trị

### 1. Quản trị tài sản CNTT

**Phạm vi**: Tài sản CNTT bao gồm phần cứng, phần mềm, dịch vụ (cloud, bảo trì, hỗ trợ kỹ thuật), dữ liệu và tài liệu liên quan.

**Quản trị tài sản CNTT là quản lý toàn bộ vòng đời**:
- Lập nhu cầu → Mua sắm / cấp phát → Vận hành → Bảo trì / nâng cấp → Thu hồi / thanh lý

**Chi phí**:
- **CAPEX**: chi phí đầu tư ban đầu (máy chủ, thiết bị mạng, giấy phép mua đứt)
- **OPEX**: chi phí vận hành định kỳ (điện, Internet, cloud subscription, bảo trì, nhân sự)
- **TCO 3–5 năm**: tổng chi phí sở hữu = CAPEX + OPEX + bảo trì + nâng cấp + đào tạo + chi phí gián đoạn

**Roadmap triển khai**:
- **Foundation**: kiểm kê tài sản, chuẩn hóa danh mục, xác lập chủ sở hữu
- **Core**: áp dụng quy trình mua sắm, cấp phát, theo dõi vòng đời
- **Security uplift**: bổ sung kiểm soát bảo mật, quản lý bản vá, bản quyền
- **Migration**: thay thế/chuyển đổi tài sản cũ, hợp nhất nền tảng
- **Optimize**: tối ưu chi phí, tái sử dụng, chuẩn hóa báo cáo và KPI

### 2. Tiêu chuẩn hoá tài liệu vận hành

**Một bộ tài liệu vận hành nên có**:
- Thông tin hệ thống
- Kiến trúc tổng quan
- Cấu hình chuẩn
- Quy trình vận hành thường xuyên
- Kịch bản xử lý sự cố
- Kế hoạch backup/restore và DR

**Chia nội dung tài liệu thành 4 nhóm yêu cầu chính**:

1. **Hiệu năng & dung lượng**: Chỉ số hiệu năng mục tiêu, ngưỡng cảnh báo, dự báo tăng trưởng, kế hoạch nâng cấp công suất
2. **HA / DR**: Mô hình sẵn sàng cao, kiến trúc dự phòng, mục tiêu RTO/RPO, kịch bản khôi phục thảm họa
3. **Security**: Cơ chế xác thực, phân quyền, chính sách bản vá, ghi log, giám sát an ninh, bảo vệ dữ liệu
4. **Ops**: Quy trình vận hành hằng ngày/tuần/tháng, quy trình change/release/incident, danh bạ liên hệ, checklist kiểm tra định kỳ

---

## IV. Tổng kết

Quản trị hệ thống không chỉ là quản trị kỹ thuật mà còn là quản trị quy trình, trách nhiệm và rủi ro. Muốn hệ thống vận hành ổn định cần đồng thời bảo đảm:

- Quản lý người dùng và phân quyền chặt chẽ
- Cấu hình, log, backup rõ ràng
- Giám sát và xử lý sự cố có quy trình
- Quản trị tài sản CNTT có kế hoạch tài chính
- Tài liệu vận hành được tiêu chuẩn hóa

---

*Q & A*
