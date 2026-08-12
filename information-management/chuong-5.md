# Chương 5 - Quản trị CSDL và an toàn thông tin

## 1. Quản trị CSDL

### 1.1 Khái niệm

- **Quản trị dữ liệu** là dùng các kỹ năng và thiết bị để tổ chức, làm an toàn, lưu trữ và rút trích thông tin từ CSDL.
- **Hệ quản trị CSDL** là một chương trình máy tính có khả năng:
  - Tạo ra các danh mục, chỉ mục, nắm bắt và lưu trữ dữ liệu
  - Duy trì tính toàn vẹn của dữ liệu
  - Kết xuất kết quả ở dạng mong muốn của người dùng
- Mục đích chung: tổ chức và quản lý dữ liệu, làm cho dữ liệu có sẵn theo yêu cầu.

### 1.2 Mục tiêu chính của quản trị CSDL

- Đảm bảo an toàn, toàn vẹn và tính sẵn sàng của dữ liệu
- Phân quyền truy cập đúng người, đúng nhiệm vụ
- Giám sát hoạt động và bảo trì hệ thống CSDL

### 1.3 Các công việc chính của người quản trị CSDL

| Nhóm công việc | Nội dung |
|---|---|
| 1. Cài đặt, cấu hình hệ thống CSDL | Cài đặt hệ QTCSDL (SQL Server, Oracle, MySQL...), cấu hình tham số hệ thống |
| 2. Thiết kế, xây dựng CSDL | Tạo và quản lý cấu trúc bảng, chỉ mục, quan hệ, trigger, stored procedure...; xây dựng, cập nhật lược đồ dữ liệu (schema) |
| 3. Quản lý dữ liệu | Nhập/xuất dữ liệu (Import/Export), sao lưu (backup) và phục hồi (restore) khi xảy ra sự cố, kiểm tra tính toàn vẹn và nhất quán của dữ liệu |
| 4. Quản lý bảo mật | Phân quyền người dùng, quản lý quyền truy cập; giám sát bảo mật, phát hiện truy cập trái phép; mã hóa dữ liệu quan trọng |
| 5. Giám sát và tối ưu hóa hiệu suất | Theo dõi tình trạng hoạt động của CSDL; phân tích và tối ưu hóa truy vấn, cấu hình server; quản lý tài nguyên (CPU, bộ nhớ, ổ cứng...) |
| 6. Xử lý lỗi và sự cố | Phát hiện sớm lỗi tiềm ẩn, xử lý nhanh chóng các vấn đề phát sinh; lên kế hoạch dự phòng, xây dựng kịch bản khôi phục thảm họa (Disaster Recovery) |
| 7. Hỗ trợ phát triển ứng dụng | Tư vấn, hỗ trợ lập trình viên về thiết kế và tối ưu hóa truy vấn; phối hợp triển khai các bản cập nhật và nâng cấp CSDL |

### 1.4 Các công việc thường xuyên

- Tạo tài khoản người dùng (Account)
- Phân quyền người dùng (Permission)
- Sao lưu – Khôi phục dữ liệu (Backup - Restore)
- Nhập – Xuất dữ liệu (Import - Export)
- Giám sát CSDL

## 2. Phân quyền Database

### 2.1 Các mức truy xuất của người dùng

1. **Quyền truy xuất đến Server** chứa CSDL
   - VD: truy xuất tới MySQL, SQL Server cần đăng nhập bằng tài khoản
2. **Quyền truy xuất đến CSDL** nào trên Server
   - VD: một server có nhiều db (QLBH, QLGV, ...) => chỉ được phép truy cập database được cấp quyền
3. **Quyền truy xuất đến đối tượng** trên mỗi CSDL (tables, views, procedures...)
   - VD: chỉ xem được bảng, không được xoá; có thể tạo View
4. **Quyền thực hiện hành động** trên đối tượng đó (create, alter, select, insert, ...)
   - VD: chỉ được SELECT trên bảng KETQUA, không được sửa/xóa (update, delete)

### 2.2 Tài khoản mặc định trong SQL Server

- Tài khoản login mặc định do nhà sản xuất tạo sẵn trên hệ QTCSDL.
- Có 2 tài khoản login mặc định trong SQL Server:

| Tài khoản | Mô tả |
|---|---|
| `sa` (System Admin) | Tài khoản đặc biệt có tất cả quyền trên SQL Server và Database |
| `Built-in\Administrators` | Tài khoản mặc định cho tất cả admin của WinNT, có tất cả quyền trên SQL Server và Database |

- Các mức truy xuất qua tài khoản `sp_addlogin`:

```sql
-- Cú pháp
sp_addlogin 'login', 'password', 'Database'

-- Ví dụ
sp_addlogin 'anh', 'nothing', 'congchung'
-- Tên: anh; mật khẩu: nothing; CSDL mặc định: congchung
```

- Thông tin login được giữ trong table `syslogins` của CSDL `master`.
- Tài khoản login có thể là:
  - Tài khoản WinNT
  - Tài khoản mặc định
  - Tài khoản login SQL Server do User tạo ra

### 2.3 CSDL mặc định và tài khoản mặc định

- Khi thêm 1 tài khoản (account) thường được gán tới 1 CSDL mặc định nhưng chưa cấp cụ thể các quyền hạn. Nếu không gán, CSDL `master` là CSDL mặc định.
- Mỗi CSDL trong SQL Server có 2 tài khoản CSDL mặc định: **dbo** và **guest**.

### 2.4 Thêm 1 tài khoản Login

**Windows authentication:**

```sql
CREATE LOGIN [ten_mien\ten_dangnhap]
FROM WINDOWS
[ WITH DEFAULT_DATABASE = ten_cosodulieu
| DEFAULT_LANGUAGE = ten_ngonngu ];

-- Ví dụ
CREATE LOGIN [test_tenmien\quantrimang]
FROM WINDOWS;
```

**SQL authentication:**

```sql
CREATE LOGIN ten_dangnhap
WITH PASSWORD = { 'matkhau' | matkhau_bam HASHED } [ MUST_CHANGE ]
[ , SID = giatri_duynhat
| DEFAULT_DATABASE = ten_cosodulieu
| DEFAULT_LANGUAGE = ten_ngonngu
| CHECK_EXPIRATION = { ON | OFF }
| CHECK_POLICY = { ON | OFF }
| CREDENTIAL = ten_chungthuc ];

-- Ví dụ
CREATE LOGIN quantrimang
WITH PASSWORD = 'mk123';
```

### 2.5 Thêm 1 tài khoản user DB

```sql
CREATE USER user_name FOR LOGIN login_name;

-- user_name: tên database user cần tạo
-- login_name: tên login dùng để kết nối đến SQL Server
-- Lưu ý: phải tạo tài khoản login trước đó.

-- Ví dụ
CREATE USER DB_qtm FOR LOGIN quantrimang;
```

### 2.6 Ý nghĩa Login và User

- Tài khoản **Login** trong SQL Server là danh tính (identity) dùng để kết nối và xác thực với SQL Server. Nó cho phép người dùng hoặc ứng dụng truy cập SQL Server.
- Sau khi xác thực, thông tin login có thể truy xuất CSDL tùy thuộc vào quyền được chỉ định.
- Tóm lại:
  - Login là thông tin xác thực với SQL Server
  - Login phải được ánh xạ tới người dùng (User) CSDL để có được các quyền cụ thể trong CSDL

### 2.7 DBO là gì?

- Tài khoản login `sa` và các thành viên `sysadmin` được ánh xạ tới 1 tài khoản đặc biệt trong tất cả CSDL là **DBO (database owner)**.
- Bất cứ đối tượng nào người quản trị tạo ra đều tự động thuộc về `dbo`.

### 2.8 Role là gì?

- **Role** cung cấp con đường tập hợp nhiều người dùng vào 1 đơn thể, trên đó các quyền hạn của Server được áp dụng.
- SQL Server cung cấp một số role cố định trên server và CSDL để dễ phân chia quyền; với CSDL phức tạp, ta có thể tạo thêm role đại diện cho 1 lớp người dùng.
- Có 2 loại role chính:
  - Role trên server (server role)
  - Role trên database (database role)

#### Server role (Role trên server)

| Role | Mô tả |
|---|---|
| `SysAdmin` | Thực hiện mọi hoạt động trên Server |
| `ServerAdmin` | Có thể tạo cấu hình |
| `SetupAdmin` | Có thể Install bản sao |
| `SecurityAdmin` | Quản lí các Login |
| `ProcessAdmin` | Quản lí các tiến trình trong Server |
| `DbCreator` | Tạo và thay đổi CSDL |
| `DiskAdmin` | Quản lí các File trên đĩa |

Lưu ý:
- Quyền Sysadmin bao trùm tất cả quyền còn lại; login với `sa` có quyền này
- Các quyền server role quản lí độc lập với CSDL và được lưu giữ trong `Master`
- Không thể thêm các role trên server

**Thêm login vào server role:**

```sql
sp_addsrvrolemember 'login_name', 'role_name'

-- Ví dụ: thêm user "loc" vào role "securityadmin"
sp_addsrvrolemember 'loc', 'securityadmin'
```

Lưu ý khi dùng `sp_addsrvrolemember`:
- Khi một login được thêm vào server role cố định, nó sẽ có được các quyền liên quan đến vai trò đó
- Không thể thực hiện trong các Transaction do người dùng tự định nghĩa
- Cần phải có tư cách thành viên trong role mà thành viên mới được thêm vào

#### Database role (Role trên database)

| Role | Mô tả |
|---|---|
| `db_owner` | Thực hiện mọi hoạt động của mọi role CSDL |
| `db_accessadmin` | Thêm, xoá người dùng NT, SQL Server và nhóm người dùng NT |
| `db_datareader` | Đọc mọi dữ liệu của các table người dùng trong CSDL |
| `db_datawriter` | Thêm, đổi, xoá dữ liệu của các table người dùng trong CSDL |
| `db_ddladmin` | Thêm, đổi, xoá các đối tượng |
| `db_securityadmin` | Quản lý các role, thành viên của role CSDL và quyền hạn trên các đối tượng |
| `db_backupoperator` | Backup database |
| `db_denydatawriter` | Không thể thay đổi bất kỳ dữ liệu nào |

**Thêm role cho database:**

```sql
Exec sp_addRoleMember 'TenUser', 'Kiểu Role'
-- (server role: Exec sp_addsrvrolemember 'login', 'role')

-- Ví dụ: thêm role đọc mọi dữ liệu trên database cho user "TuanAnh"
Exec sp_addRoleMember 'TuanAnh', 'db_dataReader'
```

Chú ý:
- Các role cố định trên CSDL không thể xóa, sửa
- Bất cứ thành viên của 1 role nào đều có thể cấp cho 1 login vào role đó

**Tạo 1 database role mới:**

```sql
CREATE ROLE role_name [ AUTHORIZATION owner_name ];

-- role_name: tên của role sẽ được tạo
-- AUTHORIZATION owner_name: người dùng CSDL hoặc role sẽ sở hữu role mới.
--   Nếu không chỉ định, role mới thuộc sở hữu của người thực hiện CREATE ROLE.
--   Chủ sở hữu hoặc bất kỳ thành viên nào của role sở hữu đều có thể thêm/xóa thành viên.

-- VD1: Tạo role buyers sở hữu bởi người dùng BenMiller
CREATE ROLE buyers AUTHORIZATION BenMiller;

-- VD2: Tạo role auditors sở hữu bởi role cố định db_securityadmin
CREATE ROLE auditors AUTHORIZATION db_securityadmin;
```

Lưu ý về ownership và quyền:
- Chủ sở hữu (owner) của một role có quyền:
  - Thêm/xóa thành viên trong role
  - Xóa role hoặc thay đổi quyền hạn, quản lý role đó
- Role mới **KHÔNG CÓ** nghĩa là sẽ kế thừa tự động các quyền từ chủ sở hữu:
  - VD role `auditors` chưa được cấp bất kỳ quyền cụ thể nào; `db_securityadmin` chỉ có quyền quản lý role này
  - Muốn `auditors` có quyền cụ thể (SELECT, UPDATE, INSERT...) phải cấp quyền riêng bằng GRANT, DENY, REVOKE
- Tóm lại: **Sở hữu (ownership) ≠ Kế thừa quyền (permission inheritance)**

```sql
-- Ví dụ cấp quyền cho role
GRANT SELECT ON dbo.Employees TO auditors;
```

### 2.9 Tóm tắt Login – User – Role

| | Login | User | Role |
|---|---|---|---|
| Ý nghĩa | Được tạo ở cấp độ SQL Server (SQL Server / Windows Authentication) | Login phải ánh xạ với user trong từng CSDL để truy cập được; mỗi CSDL cần tạo riêng 1 user cho login đó | Tập hợp các quyền có thể gán cho nhiều user; giúp quản lý quyền dễ dàng và linh hoạt hơn |
| Ví dụ | `CREATE LOGIN NgDungA WITH PASSWORD = '123456'` | `USE QUANLYBANHANG; CREATE USER NgDungA FOR LOGIN NgDungA` | `CREATE ROLE XemBaoCao; GRANT SELECT ON HOADON TO XemBaoCao; EXEC sp_addrolemember 'XemBaoCao', 'NgDungA'` |

### 2.10 Các nhóm quyền hạn

- Để cho phép người dùng truy xuất hay tạo ra các đối tượng trên Server, người dùng phải được gán quyền hạn trên các đối tượng.
- Có 3 nhóm quyền hạn:
  - Quyền **Phát biểu** (statement)
  - Quyền **Đối tượng** (object)
  - Quyền **Mặc định**

### 2.11 Các thao tác phân quyền

- Có 3 thao tác phân quyền chính trên database: Cấp quyền, Từ chối quyền, Thu hồi quyền.
- Sử dụng các lệnh trong nhóm **DCL (Data Control Language)**:

| Lệnh | Ý nghĩa |
|---|---|
| `GRANT` | Cấp quyền |
| `DENY` | Từ chối quyền |
| `REVOKE` | Thu hồi quyền |

**Cấp quyền (Grant):**
- Đang ở DB nào thì cấp quyền trên DB đó
- Quyền cấp cho role/user mặc định là các thành viên của: sysadmin, db_owner, db_security
- Quyền phát biểu Create database chỉ có thể cấp cho User và role trong Master DB

```sql
GRANT { các quyền hạn, ... }
ON các đối tượng
TO các role, user

-- Ví dụ
GRANT insert, update, delete ON KhachHang TO KETOAN
```

**Từ chối quyền (Deny):**

```sql
DENY { các quyền hạn, ... }
ON các đối tượng
TO các role, user

-- Ví dụ
DENY insert, update, delete ON KhachHang TO GIAMDOC
```

**Thu hồi quyền (Revoke):**

```sql
REVOKE { các quyền hạn, ... }
ON các đối tượng
FROM các role, user

-- Ví dụ
REVOKE insert, update ON KhachHang FROM DIEUHANH
```

### 2.12 Ví dụ phân quyền - CSDL QUẢN LÝ BÁN HÀNG

Lược đồ CSDL:

```text
KHACHHANG (MAKH, HOTEN, DCHI, SODT, NGSINH, DOANHSO, NGDK)
NHANVIEN  (MANV, HOTEN, NGVL, SODT)
SANPHAM   (MASP, TENSP, DVT, NUOCSX, GIA)
HOADON    (SOHD, NGHD, MAKH, MANV, TRIGIA)
CTHD      (SOHD, MASP, SL)
```

Tạo login và user cho nhân viên bán hàng:

```sql
CREATE LOGIN NVBanHang WITH PASSWORD = 'Sale2025!'
USE QUANLYBANHANG
CREATE USER NVBanHang FOR LOGIN NVBanHang
```

Phân quyền trực tiếp cho user:

```sql
-- Cho phép xem bảng sản phẩm
GRANT SELECT ON SANPHAM TO NVBanHang

-- Cho phép thêm, xem hóa đơn
GRANT SELECT, INSERT ON HOADON TO NVBanHang
GRANT SELECT, INSERT ON CTHD TO NVBanHang

-- Cho phép xem thông tin khách hàng
GRANT SELECT ON KHACHHANG TO NVBanHang
```

Phân quyền theo hướng tạo ROLE chung rồi thêm user vào role (dễ quản lý hơn):

```sql
-- Tạo role chung
CREATE ROLE RoleBanHang

-- Cấp quyền cho role
GRANT SELECT ON SANPHAM TO RoleBanHang
GRANT SELECT, INSERT ON HOADON TO RoleBanHang
GRANT SELECT, INSERT ON CTHD TO RoleBanHang
GRANT SELECT ON KHACHHANG TO RoleBanHang

-- Thêm user vào role
ALTER ROLE RoleBanHang ADD MEMBER NVBanHang
-- Hoặc
SP_ADDROLEMEMBER 'RoleBanHang', 'NVBanHang'
```

## 3. Khung nhìn (View)

### 3.1 Giới thiệu

- **Bảng (Table)** là quan hệ được tổ chức lưu trữ vật lý trong CSDL.
- **Khung nhìn (View)** cũng là một quan hệ nhưng:
  - Là bảng ảo (không được lưu trữ vật lý)
  - Không chứa dữ liệu
  - Được định nghĩa từ những bảng khác
  - Có thể truy vấn hay cập nhật thông qua View

### 3.2 Mục đích

- Che dấu tính phức tạp của dữ liệu
- Đơn giản hóa các câu truy vấn
- Hiển thị dữ liệu dưới dạng tiện dụng nhất
- An toàn dữ liệu (bảo mật)

### 3.3 Định nghĩa View

```sql
-- Tạo View
CREATE VIEW <tên khung nhìn> AS <câu truy vấn>

-- Xóa View
DROP VIEW <tên khung nhìn>
```

Bảng ảo có:
- Danh sách thuộc tính trùng với các thuộc tính trong mệnh đề SELECT
- Số dòng phụ thuộc vào điều kiện ở mệnh đề WHERE
- Dữ liệu được lấy từ các bảng ở mệnh đề FROM

### 3.4 Ví dụ

**VD1: View tổng hợp số lượng nhân viên, tổng thời gian theo đề án**

```sql
CREATE VIEW TONGTG_SLNV_DA AS
SELECT MADA, TENDA, COUNT(*) AS SLNV, SUM(THOIGIAN) AS TONGTG
FROM DEAN, PHANCONG
WHERE MADA = SODA
GROUP BY MADA, TENDA
```

**VD2: View các đề án của phòng 5**

```sql
CREATE VIEW DEAN_P5 AS
SELECT MADA, TENDA, DDIEM_DA
FROM DEAN
WHERE PHONG = 5
```

**VD3: Thống kê doanh thu theo khách hàng**

```sql
CREATE VIEW vw_ThongKeDoanhThuKH AS
SELECT KH.MAKH, KH.HOTEN,
       COUNT(HD.SOHD) AS SoHoaDon,
       SUM(HD.TRIGIA) AS TongTienMua
FROM KHACHHANG KH
LEFT JOIN HOADON HD ON KH.MAKH = HD.MAKH
GROUP BY KH.MAKH, KH.HOTEN

SELECT * FROM vw_ThongKeDoanhThuKH
-- Người dùng không cần quan tâm cách JOIN hay tính toán bên trong
```

**VD4: Chi tiết một hóa đơn (kết hợp nhiều bảng)**

```sql
CREATE VIEW vw_ChiTietHoaDon AS
SELECT HD.SOHD, HD.NGHD, KH.HOTEN AS TenKH,
       NV.HOTEN AS TenNV, SP.MASP, SP.TENSP, CTHD.SOLUONG,
       SP.GIA, (CT.SOLUONG * SP.GIA) AS THANHTIEN
FROM HOADON HD
JOIN KHACHHANG KH ON HD.MAKH = KH.MAKH
JOIN NHANVIEN NV ON HD.MANV = NV.MANV
JOIN CTHD ON HD.SOHD = CTHD.SOHD
JOIN SANPHAM SP ON CTHD.MASP = SP.MASP

SELECT * FROM vw_ThongTinChiTietHoaDon
WHERE SOHD = 1001
```

### 3.5 Truy vấn trên View

- View không chứa dữ liệu nhưng được truy xuất như một bảng
- Có thể viết câu truy vấn dữ liệu từ View và bảng

```sql
SELECT * FROM DEAN_P5 WHERE DDIEM_DA = 'TP HCM'
SELECT MA_NVIEN FROM DEAN_P5, PHANCONG WHERE MADA = SODA
```

### 3.6 Cập nhật trên View

- Đối với View đơn giản xây dựng trên 1 bảng và có khóa chính của bảng: có thể dùng các câu lệnh INSERT, DELETE, UPDATE.
- **Không thể cập nhật** trên View nếu View:
  - Dùng từ khóa DISTINCT
  - Sử dụng các hàm kết hợp
  - Có mệnh đề SELECT mở rộng
  - Được xây dựng từ bảng có ràng buộc trên cột
  - Được xây dựng từ nhiều bảng

### 3.7 View phục vụ bảo mật

View dùng để giấu các cột/cột nhạy cảm, sau đó chỉ cấp quyền trên View mà không cấp trên bảng gốc.

**VD1: Lấy thông tin khách hàng nhưng không hiển thị Số điện thoại và ngày sinh**

```sql
CREATE VIEW vw_ThongTinKhachHang AS
SELECT MAKH, HOTEN, DCHI, NGDK
FROM KHACHHANG

SELECT * FROM vw_ThongTinKhachHang
```

**VD2: Ẩn thông tin lương trong bảng nhân viên**

```sql
CREATE VIEW vw_NhanVien_CongKhai AS
SELECT MANV, HOTEN, SODT, NGAYSINH, DIACHI
FROM NHANVIEN

-- Chỉ cấp quyền SELECT trên View, không cấp trên bảng NHANVIEN
GRANT SELECT ON vw_NhanVien_CongKhai TO NguoiDungA
```

**VD3: Che 1 phần số điện thoại**

```sql
CREATE VIEW vw_KhachHang_AnSoDT AS
SELECT MAKH, HOTEN,
       STUFF(SODT, 4, 5, 'xxxxx') AS SODT,
       NGDK
FROM KHACHHANG

-- Kết quả: 038xxxxx92
```

## 4. Backup / Restore

### 4.1 Giới thiệu

- Vì sao cần Backup? Dữ liệu mất mát và hư hỏng là vấn đề đáng quan tâm; Server dùng cơ chế Backup để giảm tối thiểu tình trạng dữ liệu hư hỏng và mất mát.
- Cần xây dựng chiến lược backup để giảm tối thiểu dữ liệu mất và có thể khôi phục dữ liệu.
- Dữ liệu bị mất có thể do các lý do:
  - Phát biểu Delete
  - Phát biểu Update
  - Virus
  - Trộm cắp, thiên tai

### 4.2 Các loại Backup chính

| Loại Backup | Mô tả |
|---|---|
| **Full Backup** | Sao lưu toàn bộ cơ sở dữ liệu; là loại cơ bản, nền tảng cho các loại khác |
| **Differential Backup** | Sao lưu phần dữ liệu thay đổi kể từ lần full backup gần nhất; tăng tốc backup, giảm dung lượng |
| **Transaction Log Backup** | Sao lưu nhật ký giao dịch, giúp phục hồi đến thời điểm chính xác; phục hồi chi tiết, dùng cho hệ thống quan trọng |

**Full Backup:**

```sql
BACKUP DATABASE QuanLyDeTai
TO DISK = 'D:\Backup\QuanLyDeTai_Full.bak'
WITH INIT, FORMAT
```

**Differential Backup:**

```sql
BACKUP DATABASE QuanLyDeTai
TO DISK = 'D:\Backup\QuanLyDeTai_Diff.bak'
WITH DIFFERENTIAL
```

**Transaction Log Backup (kết hợp full backup):**

```sql
BACKUP DATABASE QuanLyDeTai
TO DISK = 'D:\Backup\QuanLyDeTai_Full.bak'
WITH INIT, FORMAT

BACKUP LOG QuanLyDeTai
TO DISK = 'D:\Backup\QuanLyDeTai_Full.trn'

-- Lưu ý: CSDL phải ở FULL Recovery Model mới dùng được log backup
```

### 4.3 Recovery Model

| Recovery Model | Có thể dùng Log Backup? | Ứng dụng |
|---|---|---|
| `Simple` | Không | Hệ thống không quan trọng, không cần phục hồi chi tiết |
| `Full` | Có | Hệ thống quan trọng, cần phục hồi đến từng phút |
| `Bulk-logged` | Có (hạn chế) | Khi import dữ liệu lớn, giảm log tạm thời |

```sql
-- Kiểm tra Recovery Model
SELECT name, recovery_model_desc FROM sys.databases

-- Đổi sang Full
ALTER DATABASE QuanLyDeTai SET RECOVERY FULL
```

> Quy trình trong SQL Server: vào Task -> Back Up Database -> chọn loại Backup (Full/Differential/Transaction Log) -> chọn đích -> OK.

### 4.4 Restore

- **Khôi phục dữ liệu** là đưa dữ liệu từ trạng thái nhất quán sau cùng về trạng thái bình thường.
- Khôi phục không nhất thiết được dùng khi CSDL hỏng.
- Đối với người quản trị CSDL, thao tác backup/restore là thao tác bắt buộc.

**Restore Full:**

```sql
RESTORE DATABASE QuanLyDeTai
FROM DISK = 'D:\Backup\QuanLyDeTai_Full.bak'
WITH REPLACE
```

**Restore Full + Differential:**

```sql
RESTORE DATABASE QuanLyDeTai
FROM DISK = 'D:\Backup\QuanLyDeTai_Full.bak'
WITH NORECOVERY

RESTORE DATABASE QuanLyDeTai
FROM DISK = 'D:\Backup\QuanLyDeTai_Diff.bak'
WITH RECOVERY
```

**Restore Point-in-time (đến thời điểm cụ thể bằng log):**

```sql
RESTORE DATABASE QuanLyDeTai
FROM DISK = 'D:\Backup\QuanLyDeTai_Full.bak'
WITH NORECOVERY

RESTORE LOG QuanLyDeTai
FROM DISK = 'D:\Backup\QuanLyDeTai_Full.trn'
WITH STOPAT = '2025-03-27 07:30:00', RECOVERY
```

> Quy trình trong SQL Server: chọn database -> Tasks -> Restore -> chọn nguồn backup -> OK.

## 5. Import / Export

### 5.1 Tổng quan

- **Import dữ liệu** trong hệ QTCSDL: sao chép dữ liệu từ nguồn A tới đích B, trong đó B là một hệ QTCSDL.
- **Export dữ liệu** trong hệ QTCSDL: sao chép dữ liệu từ nguồn A tới đích B, trong đó A là một hệ QTCSDL.
- Đây là thao tác có thể gặp trong thực tế; A, B có thể khác hệ quản trị.
- Các định dạng thường được hỗ trợ khi import/export:
  - Comma separated values (.csv)
  - Excel (.xls)
  - SQL script (.sql)

### 5.2 Ví dụ 1: Import dữ liệu từ MS Access sang SQL Server

Các bước thực hiện (dùng Import and Export Data wizard):
1. Khởi động wizard Import And Export Data
2. Chọn nguồn dữ liệu: Microsoft Access (chọn file .mdb/.accdb)
3. Chọn đích: SQL Server, nhập server, database đích
4. Chọn cách sao chép: copy từ bảng/view hoặc viết câu truy vấn
5. Kiểm tra các cột được ánh xạ
6. Chạy và kiểm tra dữ liệu đã import

### 5.3 Ví dụ 2: Export dữ liệu từ SQL Server sang MS Access

Các bước thực hiện:
1. Khởi động wizard Import And Export Data
2. Chọn nguồn: SQL Server (server, database)
3. Chọn đích: Microsoft Access (tạo/trỏ tới file đích)
4. Chọn bảng hoặc câu truy vấn muốn xuất
5. Chạy và kiểm tra dữ liệu trong Access

## 6. Tổng kết

- Quản trị CSDL là dùng các kỹ năng và thiết bị để tổ chức, làm an toàn, lưu trữ và rút trích thông tin từ CSDL.
- Các thao tác chính khi quản trị dữ liệu:
  - **Phân quyền**
    - Quyền trên server: server role
    - Quyền trên database: database role
  - Backup / Restore
  - Import / Export

## 7. Bài tập

**Bài tập 1: Import/Export**
- Chọn 1 file dữ liệu (SV) từ Excel và import vào SQL Server
- Chọn 1 table trong SQL Server và export tới file Excel

**Bài tập 2: Backup/Restore**
- Backup 1 CSDL từ SQL Server trên máy A vào đĩa USB, đặt tên a.bak
- Restore file a.bak từ USB vào SQL Server trên máy B

**Bài tập 3: Tạo user, role và phân quyền**
- Tạo 6 user từ u1 đến u6
- Tạo 3 role từ r1 đến r3
- Tạo nhóm: u1, u2 thuộc r1; u3, u4 thuộc r2; u5, u6 thuộc r3
- Phân quyền cho r1, r2, r3:
  - r1 là thành viên của SysAdmin
  - r2 là thành viên của db_owner, db_accessadmin
  - r3 là thành viên của SysAdmin, db_owner, db_accessadmin

**Bài tập 4: GRANT, DENY, REVOKE**
- Thực hành các phát biểu grant, deny, revoke trên CSDL gồm các table T1, T2, T3...
  - u1 có quyền select, delete trên T1, T3
  - u2 có quyền update, delete trên T2
  - u3 có quyền insert trên T1, T2, T3
  - u1 bị từ chối quyền insert trên T1, T2

## 8. Tài liệu tham khảo

1. Nguyễn Gia Tuấn Anh, Trương Châu Long, *Bài tập và bài giải SQL Server*, NXB Thanh niên (2005)
2. Đỗ Phúc, Nguyễn Đăng Tỵ, *Cơ sở dữ liệu*, NXB Đại học quốc gia TPHCM (2010)
3. Nguyễn Gia Tuấn Anh, Mai Văn Cường, Bùi Danh Hường, *Cơ sở dữ liệu nâng cao*, NXB Đại học quốc gia TPHCM (2019)
4. Itzik Ben-Gan, *Microsoft SQL Server 2012 - TSQL Fundamentals*