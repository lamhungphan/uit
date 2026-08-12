# Chương 8 - Mô hình CSDL tiên tiến phần 1: CSDL phân tán

## 1. Khái niệm về CSDL phân tán

### Khái niệm

- **Khái niệm 1:** CSDL phân tán là tập dữ liệu mà về mặt logic thuộc cùng một hệ thống nhưng về mặt vật lý được trải ra nhiều nơi trong một mạng máy tính.
- **Khái niệm 2:** CSDL phân tán là tập CSDL phân bố trên các máy tính khác nhau trong cùng một mạng. Mỗi máy có khả năng xử lý tự trị, có các ứng dụng local, tham gia vào các ứng dụng global thông qua hệ thống mạng.

### Ví dụ minh họa

Ngân hàng ACB có 3 chi nhánh:

- Site A: Hà Nội
- Site B: Đà Nẵng
- Site C: TP. Hồ Chí Minh

Mỗi chi nhánh quản lý dữ liệu khách hàng và giao dịch tại địa phương mình:

| Quan hệ | Thuộc tính |
|---|---|
| KHACHHANG | MSKH, TENKH |
| GIAODICH | MSGD, MSKH, SOTIEN, GUIRUT |

Dữ liệu được phân tán như sau:

- Site A: chứa KHACHHANG & GIAODICH tại Hà Nội
- Site B: chứa KHACHHANG & GIAODICH tại Đà Nẵng
- Site C: chứa KHACHHANG & GIAODICH tại TP.HCM

Tình huống: Khách hàng John (MSKH = KH1001) đăng ký tài khoản tại chi nhánh C (TP.HCM):

- Gửi tiền tại C
- Rút tiền tại C
- Sau đó gửi tiền vào tài khoản người thân tại chi nhánh A (Hà Nội)

Khi xử lý giao dịch cuối, hệ thống cần truy vấn và cập nhật dữ liệu ở chi nhánh A và C, tức là:

- Có tương tác giữa hai site khác nhau
- Cùng một giao dịch ảnh hưởng nhiều vị trí lưu trữ dữ liệu

## 2. Đặc điểm của CSDL phân tán

Các đặc điểm chính:

- Độc lập dữ liệu, tự trị
- Dư thừa dữ liệu
- Cấu trúc vật lý phức tạp
- Tính toàn vẹn, toàn cục
- Điều khiển đồng thời
- Tính bảo mật

### Độc lập dữ liệu và tính tự trị (Data Independence & Autonomy)

- Mỗi site (nút trong hệ thống) có thể:
  - Tự quản lý dữ liệu tại chỗ
  - Quyết định cấu trúc bảng, quyền truy cập, chính sách riêng
  - Không cần phụ thuộc hoàn toàn vào trung tâm

Ví dụ: Chi nhánh A có thể cập nhật bảng KHACHHANG của riêng mình mà không cần xin phép trung tâm.

- Ưu điểm: dễ mở rộng, giảm phụ thuộc
- Thách thức: khó đồng bộ và chuẩn hóa dữ liệu

### Dư thừa dữ liệu (Data Redundancy)

- Cùng một dữ liệu có thể được lưu trữ ở nhiều site khác nhau để:
  - Tăng hiệu năng (truy vấn gần)
  - Hỗ trợ backup, khôi phục
  - Nhưng gây ra tình trạng trùng lặp dữ liệu nếu không quản lý tốt

Ví dụ: Dữ liệu khách hàng "John" có thể được lưu tại cả chi nhánh A và C.

- Ưu điểm: tăng tính sẵn sàng
- Thách thức: khó duy trì tính nhất quán

### Cấu trúc vật lý phức tạp (Complex Physical Structure)

- Dữ liệu được phân tán theo địa lý, server, định dạng khác nhau
- Cần có cơ chế định tuyến truy vấn, giao tiếp mạng, đồng bộ dữ liệu

Ví dụ: Một phần dữ liệu lưu ở Hà Nội (SQL Server), phần khác ở TP.HCM (Oracle).

Thách thức:

- Cấu hình hệ thống phức tạp
- Chi phí hạ tầng cao

### Tính toàn vẹn và toàn cục (Integrity & Consistency)

- Hệ thống cần đảm bảo ràng buộc toàn vẹn dữ liệu ở mức toàn hệ thống, không chỉ trong 1 site
- Phải kiểm tra ràng buộc dù dữ liệu nằm ở nơi khác

Ví dụ: Mã khách hàng (MSKH) không được trùng trên toàn quốc.

- Ưu điểm: đảm bảo dữ liệu tin cậy
- Thách thức: khó thiết kế kiểm tra toàn cục, nhất là khi mạng không ổn định

### Điều khiển đồng thời (Concurrency Control)

- Nhiều người dùng ở nhiều site có thể cùng truy cập/sửa cùng một dữ liệu
- Cần có cơ chế kiểm soát xung đột, khóa phân tán, rollback đa site

Ví dụ: 2 nhân viên ở chi nhánh A và B cùng chỉnh sửa giao dịch cho khách hàng John.

- Ưu điểm: tránh lỗi logic, mất mát dữ liệu
- Thách thức: cần đồng bộ phức tạp (2-phase commit, timestamp...)

### Tính bảo mật (Security)

- Mỗi site có thể có chính sách bảo mật riêng
- Cần đảm bảo:
  - Xác thực người dùng theo phân quyền
  - Mã hóa khi truyền dữ liệu giữa các site
  - Phân quyền truy cập theo vùng

Ví dụ: Nhân viên giao dịch ở chi nhánh C không được phép xem dữ liệu không liên quan tại chi nhánh A.

- Ưu điểm: bảo vệ dữ liệu phân tán
- Thách thức: cần phối hợp chính sách bảo mật giữa nhiều node

### So sánh CSDL phân tán và CSDL tập trung

| Tiêu chí | CSDL tập trung | CSDL phân tán |
|---|---|---|
| Độc lập dữ liệu | Không cao | Cao |
| Tính tự trị | Tự trị duy nhất | Tính tự trị cao |
| Cấu trúc vật lý, quản trị | Đơn giản | Phức tạp |
| Rủi ro | Rủi ro cao | Phân tán rủi ro |
| Chi phí | Thấp hơn | Chi phí lớn |

## 3. Hệ quản trị CSDL phân tán

Các chức năng chính của hệ quản trị CSDL phân tán:

- Truy xuất dữ liệu từ xa (remote access)
- Hỗ trợ mức trong suốt (transparency) cho CSDL phân tán
- Hỗ trợ quản trị, giám sát CSDL
- Hỗ trợ phục hồi dữ liệu
- Hỗ trợ môi trường không đồng nhất

### Truy xuất dữ liệu từ xa

- Do hệ quản trị CSDL cung cấp: không phong phú, chưa đáp ứng nhu cầu đa dạng
- Do phần mềm ứng dụng cung cấp

### Hỗ trợ mức trong suốt (transparency)

Ví dụ: Cho các quan hệ:

```sql
HOADON(mshd, tt)
CTHD(mshd, msmh, sl, dongia)
MATHANG(msmh, ten, donvitinh)
```

Tại site A không có dữ liệu MATHANG. Sự hỗ trợ trong suốt làm cho A có cảm giác MATHANG vẫn có tại A.

### Quản trị, giám sát (audit, monitor)

CSDL phân tán có các công cụ:

- Quản lý dữ liệu trên nhiều site
- Giám sát trạng thái hoạt động, tốc độ đồng bộ, lỗi
- Phân quyền người dùng theo từng site hoặc toàn hệ thống

### Phục hồi (recover) dữ liệu

- Khi có giao tác phân tán không hoàn thành, hệ quản trị phải hỗ trợ phục hồi CSDL.

Ví dụ: Bảng NHANKHAU ở mức Phường và Quận:

NHANKHAU (msnk, tennk) ở Phường:

| msnk | tennk |
|---|---|
| 01 | A |
| 02 | B |

NHANKHAU (msnk, tennk, phuong) ở Quận:

| msnk | tennk | phuong |
|---|---|---|
| 01 | A | 1 |
| 02 | B | 1 |
| 03 | C | 2 |

Khi B cập nhật (02, 'B', 2) và truyền cập nhật tới Quận, nếu có sự cố xảy ra thì phải khôi phục đồng thời tại Phường và Quận, nghĩa là tại Phường thì 02 vẫn có giá trị (02, 'B').

### Hỗ trợ môi trường không đồng nhất (in-homogeneous)

- Các server có thể khác biệt phần cứng, hệ điều hành, hệ quản trị CSDL. Khác biệt về hệ quản trị CSDL (xử lý, lưu trữ, dữ liệu) là khó khăn lớn nhất.
- Một hệ phân tán hình thành từ các hệ đã tồn tại trước: khó đồng nhất.
- Một hệ phân tán hình thành từ khảo sát, phân tích, thiết kế từ đầu: dễ đồng nhất.

## 4. Kiến trúc CSDL phân tán

- Mỗi quan hệ toàn cục có thể được chia thành các thành phần không trùng nhau gọi là các **phân mảnh** (fragmentation).
- Có nhiều cách để phân mảnh.
- Ánh xạ từ các quan hệ toàn cục đến các phân mảnh được định nghĩa trong **lược đồ phân mảnh** (fragmentation schema).
- Phép ánh xạ này là **một-nhiều**: có một số phân mảnh tương ứng với một quan hệ toàn cục, nhưng chỉ có một quan hệ toàn cục ứng với một phân mảnh.
- Các phân mảnh được chỉ định bởi tên quan hệ toàn cục kèm chỉ mục phân mảnh, ví dụ `Ri` chỉ phân mảnh thứ i của quan hệ toàn cục R.

### Các thành phần của kiến trúc

| Thành phần | Nội dung |
|---|---|
| Global schema | Các lược đồ quan hệ toàn cục |
| Fragmentation schema | Các lược đồ quan hệ đã phân mảnh |
| Allocation schema | Các lược đồ quan hệ đã phân mảnh gắn liền với vị trí vật lý tương ứng |

Sau công đoạn thiết kế sẽ là phần cài đặt trên các hệ quản trị CSDL tại các vị trí vật lý cụ thể.

## 5. Các kỹ thuật phân mảnh

### Nhân bản (Replication)

- Một quan hệ toàn cục `R(A1, A2, ..., An)`, các quan hệ `Ri` được phân bố giống hoàn toàn về cấu trúc cũng như tất cả dữ liệu so với R tạo ra hiện tượng nhân bản.

Ví dụ: Cho quan hệ toàn cục `SV(MSSV, TENSV, NAMS, NOIS, GT, DIACHI, EMAIL, MSK)`. Nếu có 2 quan hệ `SV1`, `SV2` cùng cấu trúc và số dòng như SV nhưng khác site, thì SV1, SV2 được gọi là **nhân bản** của SV.

### Phân mảnh ngang (Horizontal fragmentation)

- Một quan hệ toàn cục `R` được chia thành tập các quan hệ con `Ri` dựa vào các thuộc tính trên R.
- Kí hiệu: `Ri = δ<điều kiện>(R)` (phép chọn).

Ví dụ: Cho quan hệ toàn cục `SV(MSSV, TENSV, NAMS, NOIS, GT, DIACHI, EMAIL, MSK)`, tạo 2 quan hệ SV3, SV4:

```sql
SV3 = δ MSK='CNTT' (SV)
SV4 = δ MSK='DTVT' (SV)
```

Phân loại phân mảnh ngang:

- **PMN nguyên thủy:** chỉ dựa trên một quan hệ.

Ví dụ:

```sql
SV3' = δ GT='Nữ' (SV)
SV4' = δ GT='Nam' (SV)
```

- **PMN dẫn xuất:** phân mảnh một quan hệ nhưng cần dựa vào quan hệ khác.

Ví dụ:

```sql
SV5 = ∏ [δ tenkhoa='Cong Nghe Thong Tin' (SV ◄► KHOA) + điều kiện phép kết]
SV6 = ∏ [δ tenkhoa='Dien Tu Vien Thong' (SV ◄► KHOA) + điều kiện phép kết]
```

Một cách thể hiện khác:

```sql
SV5 = ∏ [ (SV3 ◄► KHOA) ]
SV6 = ∏ [ (SV4 ◄► KHOA) ]
```

### Phân mảnh dọc (Vertical fragmentation)

- Một quan hệ toàn cục `R` chia thành tập các quan hệ con `Ri` bằng cách rải các thuộc tính vào các quan hệ con.
- Kí hiệu: `Ri = ∏ các cột(R)` (phép chiếu).

Ví dụ: Cho quan hệ toàn cục `SV(MSSV, TENSV, NAMS, NOIS, GT, DIACHI, EMAIL, MSK)`:

```sql
SV7 = ∏ MSSV, NAMS, NOIS, GT, DIACHI, EMAIL, MSK (SV)
SV8 = ∏ MSSV, TENSV (SV)
```

Phân loại phân mảnh dọc:

- **Không dư thừa (non-redundant fragmentation):** các phân mảnh dọc không chứa thuộc tính chung không khóa nào cả.

Ví dụ: `GV(MSGV, TENGV, NAMS, NOIS, GT, DC, SDT, NGAYVD)` chia thành:

```text
GV1(MSGV, TENGV, NAMS, NOIS, GT, DC, SDT)
GV2(MSGV, NGAYVD)
```

- **Dư thừa (redundant fragmentation):** các phân mảnh dọc chứa một hoặc nhiều thuộc tính chung không khóa.

Ví dụ:

```text
GV3(MSGV, TENGV, NAMS, NOIS, GT, DC, SDT)
GV4(MSGV, TENGV, NGAYVD)
```

### Phân mảnh hỗn hợp (Mixed/Hybrid fragmentation)

- Một quan hệ toàn cục `R` được chia thành các quan hệ con `Ri` kết hợp cả phân mảnh ngang lẫn phân mảnh dọc.

Ví dụ: Cho `SV(MSSV, TENSV, NAMS, NOIS, GT, DIACHI, EMAIL, MSK)`, trước hết tạo 2 phân mảnh ngang:

```sql
SV3 = δ MSK='CNTT' (SV)
SV4 = δ MSK='DTVT' (SV)
```

Sau đó tạo SV9, SV10:

```sql
SV9  = ∏ MSSV, NAMS, NOIS, GT, DIACHI, EMAIL, MSK [δ MSK='CNTT' (SV)]
SV10 = ∏ MSSV, TENSV [δ MSK='CNTT' (SV)]
```

SV9, SV10 được gọi là **phân mảnh hỗn hợp** của SV.

## 6. Ưu khuyết điểm của việc phân mảnh

### Mô hình 1: Trùng lắp dữ liệu và cấu trúc (Nhân bản)

Ưu điểm:

- Tốc độ truy xuất dữ liệu nhanh chóng do khoảng cách vật lý nhỏ
- Số xử lý trong cùng một thời điểm là nhỏ
- Sức đề kháng cao: xác suất toàn bộ mạng sụp đổ cùng lúc là nhỏ

Khuyết điểm:

- Cơ sở vật chất tốn kém (CPU, harddisk)
- Xử lý thêm/xóa/sửa phức tạp do dữ liệu cần đồng nhất

### Mô hình 2: Trùng về cấu trúc, khác dữ liệu (Cắt ngang - phân mảnh ngang)

Ưu điểm:

- Tự nhiên
- Hiệu quả tìm kiếm
- An toàn dữ liệu, dễ tìm lỗi

Khuyết điểm:

- Tốc độ không tốt khi truy xuất từ xa
- Gặp sự cố trên node chứa dữ liệu độc quyền dẫn đến mất mát dữ liệu
- Rất phổ biến

### Mô hình 3: Khác nhau về cấu trúc, trùng dữ liệu (Cắt dọc - phân mảnh dọc)

Ưu điểm:

- Tiết kiệm không gian lưu trữ

Khuyết điểm:

- Mất thời gian lấy dữ liệu từ xa

### Mô hình 4: Mô hình hỗn hợp

- Là sự trộn lẫn giữa 3 mô hình trên.

Ưu điểm:

- Lấy ưu điểm của 3 mô hình
- Độ linh động cao

Khuyết điểm:

- Lấy khuyết điểm của 3 mô hình
- Quản lý rất phức tạp
- Mang tính tự nhiên cao nhất

## 7. Ví dụ thiết kế CSDL phân tán

Cho CSDL Quản lý sinh viên:

```text
SINHVIEN(MSSV, HoTen, NgVDoan, NgVDang, NgSinh, QueQuan, MaKhoa)
MONHOC(MSMH, TenMH, SoTC, MaKhoaQL)
DIEMSO(MSSV, MSMH, Diem)
KHOA(MaKhoa, TenKhoa, NGTL)
```

Yêu cầu: Xây dựng CSDL phân bố cho các phòng ban:

- Phòng đào tạo
- Phòng CTSV
- Văn phòng Khoa (Khoa Khoa học và Kỹ thuật thông tin)

### Phòng đào tạo

```text
SINHVIEN(MSSV, HoTen, NgVDoan, QueQuan, MaKhoa)        → Phân mảnh dọc
MONHOC(MSMH, TenMH, SoTC, MaKhoaQL)                     → Nhân bản
DIEMSO(MSSV, MSMH, Diem)                                 → Nhân bản
KHOA(MaKhoa, TenKhoa, NGTL)                              → Nhân bản
```

### Phòng CTSV

```text
SINHVIEN(MSSV, HoTen, NgVDoan, NgVDang, NgSinh, QueQuan, MaKhoa) → Nhân bản
KHOA(MaKhoa, TenKhoa, NGTL)                                        → Nhân bản
```

### Văn phòng Khoa

```text
SINHVIEN(MSSV, HoTen, NgVDoan, NgVDang, NgSinh, QueQuan) → Phân mảnh dọc
MONHOC(MSMH, TenMH, SoTC)                                → Phân mảnh dọc
DIEMSO(MSSV, MSMH, Diem)                                 → Phân mảnh ngang
KHOA                                                      → Phân mảnh dọc
```

## 8. Thiết kế CSDL phân tán

### Các mục tiêu thiết kế

1. Sự truy xuất cục bộ
2. Tính sẵn sàng của các dữ liệu phân tán
3. Sự phân bố tải
4. Chi phí lưu trữ

### 1. Sự truy xuất cục bộ

- Mục tiêu của sự phân tán dữ liệu là để các ứng dụng truy xuất dữ liệu cục bộ càng nhiều càng tốt, giảm bớt các truy xuất dữ liệu từ xa.
- Việc thiết kế để tối đa hóa truy xuất cục bộ có thể thực hiện bằng cách thêm số lượng các CSDL cục bộ thay thế cho các tham khảo CSDL từ xa tương ứng.

### 2. Tính sẵn sàng của dữ liệu phân tán

- Mức độ sẵn sàng cao đối với các ứng dụng chỉ đọc được thực hiện bằng cách lưu trữ nhiều bản sao của cùng một thông tin; hệ thống phải có khả năng chuyển đến bản sao được chọn thích hợp khi một bản sao không được truy xuất bình thường.
- Độ khả tín cũng được thực hiện bằng cách lưu trữ nhiều bản sao, khi đó hệ thống có khả năng phục hồi khi có sự phá hủy một số bản sao.

### 3. Sự phân bố tải

- Sự phân bố tải trên các sites là một tính chất quan trọng của các hệ thống máy tính phân tán.
- Mục đích: tận dụng sức mạnh sử dụng của các máy tính và cực đại hóa mức độ xử lý song song các lệnh thực thi của các ứng dụng.
- Vì phân bố tải có thể ảnh hưởng xấu đến sự truy xuất cục bộ nên cần xem xét để cân bằng hai mục tiêu này.

### 4. Chi phí lưu trữ

- Sự phân tán CSDL phản ánh chi phí của sự lưu trữ tại các site khác nhau.
- Tuy nhiên chi phí lưu trữ dữ liệu không đáng kể so với chi phí xuất nhập, chi phí truyền thông của các ứng dụng.
- Những giới hạn của bộ lưu trữ phải được xem xét kỹ.

### Các chiến lược thiết kế CSDL phân tán

Có hai cách tiếp cận:

- **Top-down** (từ trên xuống)
- **Bottom-up** (từ dưới lên)

### Tiếp cận TOP-DOWN

Các bước:

1. Thiết kế lược đồ phổ quát
2. Thiết kế sự phân mảnh cơ sở dữ liệu
3. Cấp phát các mảnh đến các sites, tạo các ảnh vật lý của chúng

- Thích hợp đối với các hệ thống được phát triển từ đầu và cho phép thiết kế một cách hợp lý.
- Khi CSDL phân tán được phát triển như là sự tổ hợp các CSDL sẵn có, phương pháp này không dễ dàng. Lược đồ phổ quát thường được tạo ra từ sự thỏa hiệp giữa các mô tả dữ liệu sẵn có, do đó cách tiếp cận từ dưới lên được sử dụng.

### Tiếp cận BOTTOM-UP

Các bước:

1. Chọn một mô hình CSDL chung để mô tả lược đồ phổ quát của CSDL
2. Chuyển dịch mỗi lược đồ cục bộ vào trong mô hình dữ liệu chung
3. Tổ hợp lại lược đồ cục bộ vào trong lược đồ phổ quát chung

- Ba vấn đề này không riêng biệt gì đối với CSDL phân tán mà hiện diện ngay trong các hệ thống tập trung.

## 9. Tài liệu tham khảo

1. Nguyễn Gia Tuấn Anh, Trương Châu Long, *Bài tập và bài giải SQL Server*, NXB Thanh niên (2005).
2. Đỗ Phúc, Nguyễn Đăng Tỵ, *Cơ sở dữ liệu*, NXB Đại học Quốc gia TPHCM (2010).
3. Nguyễn Gia Tuấn Anh, Mai Văn Cường, Bùi Danh Hường, *Cơ sở dữ liệu nâng cao*, NXB Đại học Quốc gia TPHCM (2019).
4. Itzik Ben-Gan, *Microsoft SQL Server 2012 - TSQL Fundamentals*.

## 10. Bài tập

### Bài tập 1

Cho CSDL toàn cục sau, hãy đề xuất một mô hình phân tán và lí giải cách chọn lựa; biết nhà trường hiện có 5 cơ sở tại các tỉnh A, B, C, D, E; mỗi cơ sở hiện có 8 khoa: k1, k2, k3, ..., k8.

```text
SV(#mssv, tensv, noisinh, namsinh, msk)
KHOA(#msk, tenkhoa)
MON(#msm, tenm, STC)
SV-MON(#mssv, #msm, diem)
COSO(#mscs, tencs, diachi, sdt)
```

### Bài tập 2

Tìm các ứng dụng phổ biến đang sử dụng mô hình phân tán? Tại sao đó là lựa chọn tốt nhất?

### Bài tập 3

Tiến hành cài đặt bài 1 bằng một hệ quản trị CSDL. Viết các thực nghiệm so sánh với CSDL tập trung.

### Bài tập 4

So sánh các tính năng phân tán được hỗ trợ trên hai hệ quản trị CSDL Oracle và MySQL.