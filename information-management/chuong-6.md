# Chương 6 - Lập trình xử lý thông tin

Lập trình cơ sở dữ liệu với T-SQL (Transact-SQL) trên SQL Server. Các nội dung chính:

1. Stored Procedure
2. Trigger
3. Function
4. Cursor

## 1. Stored Procedure

### 1.1 Giới thiệu

- Một **Stored Procedure** (thủ tục được lưu trữ) bao gồm các câu lệnh Transact-SQL được lưu lại trong cơ sở dữ liệu.
- Để thực thi chỉ cần gọi ra (EXEC).
- **Transact-SQL (T-SQL)** là ngôn ngữ lập trình được dùng làm trung gian giữa cơ sở dữ liệu và các ứng dụng. Nó tương đối dễ học vì thực chất được tạo bởi hầu hết là các lệnh SQL.

### 1.2 Lợi ích của Stored Procedure

- **Module hóa:** chỉ cần viết Stored Procedure 1 lần, sau đó gọi lại nhiều lần trong ứng dụng.
- **Thực thi nhanh hơn:** Stored Procedure được biên dịch và lưu vào bộ nhớ khi được tạo, thực thi nhanh hơn so với việc gửi từng đoạn lệnh SQL tới SQL Server.
- **Giảm tải băng thông:** gom các câu lệnh SQL vào 1 Stored Procedure và chỉ gọi 1 lần duy nhất qua mạng thay vì gọi nhiều lần.

### 1.3 Procedure không có tham số

Cú pháp khai báo:

```sql
CREATE PROCEDURE procedure_name
AS
BEGIN
    sql_statement
END
GO
```

Thực thi:

```sql
EXEC procedure_name
```

**Ví dụ:** viết procedure liệt kê danh sách tất cả khách hàng từ bảng Customers.

```sql
CREATE PROCEDURE GetCustomersList
AS
SELECT * FROM Customers
GO

EXEC GetCustomersList
```

### 1.4 Procedure có tham số

Có 3 trường hợp tham số:

- Một tham số vào (input).
- Nhiều tham số vào (multiple input).
- Tham số ra (output).

Cú pháp khai báo:

```sql
CREATE PROCEDURE procedure_name <@tham_so_1 kieu_du_lieu, ..., @tham_so_n kieu_du_lieu>
AS
BEGIN
    sql_statement
END
GO

EXEC procedure_name
```

#### Ví dụ trường hợp 1 tham số

```sql
CREATE PROCEDURE GetCustomersByCity @City nvarchar(30)
AS
SELECT * FROM Customers WHERE City = @City
GO

EXEC GetCustomersByCity @City = 'London'
```

#### Ví dụ trường hợp nhiều tham số

```sql
CREATE PROCEDURE GetCustomersByCityPostCode @City nvarchar(30), @PostalCode nvarchar(10)
AS
SELECT * FROM Customers WHERE City = @City AND PostalCode = @PostalCode
GO

EXEC GetCustomersByCityPostCode @City = 'London', @PostalCode = 'WA1 1DP'
```

#### Cú pháp khai báo Procedure có tham số ra

```sql
CREATE PROCEDURE procedure_name <@tham_so_1 kieu_du_lieu, @tham_so_2 kieu_du_lieu OUTPUT, ...>
AS
BEGIN
    sql_statement
END
GO

EXEC procedure_name
```

#### Ví dụ trường hợp tham số ra

```sql
CREATE PROCEDURE GetCustomerAddress @CustomerName nvarchar(50), @CustomerAddress nvarchar(100) OUTPUT
AS
SELECT @CustomerAddress = Address FROM Customers WHERE CustomerName = @CustomerName
GO

DECLARE @CustAddress nvarchar(100)
EXEC GetCustomerAddress @CustomerName = 'Maria Anders', @CustomerAddress = @CustAddress OUTPUT
PRINT @CustAddress
```

### 1.5 Bài tập dùng Stored Procedure

Cơ sở dữ liệu cho trước:

```
NHANVIEN (MANV, HONV, TENLOT, TENNV, NGSINH, DCHI, PHAI, LUONG, MA_NQL, PHG)
PHONGBAN (MAPHG, TENPHG, TRPHG, NG_NC)
DIADIEM (MADIADIEM, TENDIADIEM)
DIADIEM_PHG (MADIADIEM, MAPHG)
THANNHAN (MA_NVIEN, TENTN, PHAI, NGSINH, QUANHE)
DEAN (MADA, TENDA, DDIEM_DA, PHONG)
PHANCONG (MA_NVIEN, MADA, THOIGIAN)
```

Danh sách bài tập:

1. Tìm các đề án theo tên địa điểm cụ thể
2. Tìm các nhân viên có lương trong khoảng từ a đến b
3. Tính tổng thời gian tham gia các đề án của một nhân viên cụ thể
4. Tìm mã, họ tên và ngày nhận chức của trưởng phòng của một phòng ban cụ thể
5. Tìm họ tên, địa chỉ và số lượng thân nhân của một nhân viên cụ thể

#### Bài 1: Tìm các đề án theo tên địa điểm cụ thể

```sql
CREATE PROCEDURE SP_DeAnTheoDiaDiem @TenDiaDiem NVARCHAR(50)
AS
BEGIN
    SELECT MADA, TENDA, PHONG
    FROM DEAN, DIADIEM
    WHERE DDIEM_DA = MADIADIEM AND TENDIADIEM = @TenDiaDiem
END
GO

-- Thực thi
EXEC SP_DeAnTheoDiaDiem @TenDiaDiem = N'TP.Hồ Chí Minh'
```

#### Bài 2: Tìm các nhân viên có lương trong khoảng từ a đến b

```sql
CREATE PROCEDURE SP_NhanVienTheoLuong @LuongTu INT, @LuongDen INT
AS
BEGIN
    SELECT MANV, HONV, TENLOT, TENNV, LUONG
    FROM NHANVIEN
    WHERE LUONG BETWEEN @LuongTu AND @LuongDen
END
GO

-- Thực thi
EXEC SP_NhanVienTheoLuong @LuongTu = 5000, @LuongDen = 15000
```

#### Bài 3: Tính tổng thời gian tham gia các đề án của một nhân viên cụ thể

```sql
CREATE PROCEDURE SP_TongTGThamGiaDeAn
    @MaNV INT, @TongTG INT OUTPUT
AS
BEGIN
    SELECT @TongTG = SUM(THOIGIAN) FROM PHANCONG
    WHERE MA_NVIEN = @MaNV
END
GO

-- Thực thi
DECLARE @Tong INT
EXEC SP_TongTGThamGiaDeAn @MaNV = 101, @TongTG = @Tong OUTPUT
PRINT N'Tổng thời gian tham gia đề án: ' + CAST(@Tong AS NVARCHAR)
```

#### Bài 4: Tìm mã, họ tên và ngày nhận chức của trưởng phòng của một phòng ban cụ thể

```sql
CREATE PROCEDURE SP_ThongTinTruongPhong
    @MaPhong INT, @MaTruongPhong INT OUTPUT,
    @TenTruongPhong NVARCHAR(40) OUTPUT, @NgayNhanChuc DATE OUTPUT
AS
BEGIN
    SELECT @MaTruongPhong = TRPHG,
           @TenTruongPhong = HONV + ' ' + TENLOT + ' ' + TENNV,
           @NgayNhanChuc = NG_NC
    FROM PHONGBAN, NHANVIEN
    WHERE TRPHG = MANV AND MAPHG = @MaPhong
END
GO

-- Thực thi
DECLARE @MaTP INT, @TenTP NVARCHAR(40), @NgayNC DATE
EXEC SP_ThongTinTruongPhong
    @MaPhong = 2,
    @MaTruongPhong = @MaTP OUTPUT,
    @TenTruongPhong = @TenTP OUTPUT,
    @NgayNhanChuc = @NgayNC OUTPUT
PRINT N'Mã trưởng phòng: ' + CAST(@MaTP AS NVARCHAR)
PRINT N'Tên trưởng phòng: ' + @TenTP
PRINT N'Ngày nhận chức: ' + CAST(@NgayNC AS NVARCHAR)
```

#### Bài 5: Tìm họ tên, địa chỉ và số lượng thân nhân của một nhân viên cụ thể

```sql
CREATE PROCEDURE SP_ThongTinNVvaSoThanNhan
    @MaNV INT, @HoTen NVARCHAR(100) OUTPUT,
    @DiaChi NVARCHAR(100) OUTPUT, @SoThanNhan INT OUTPUT
AS
BEGIN
    SELECT @HoTen = HONV + ' ' + TENLOT + ' ' + TENNV, @DiaChi = DCHI
    FROM NHANVIEN WHERE MANV = @MaNV

    SELECT @SoThanNhan = COUNT(*)
    FROM THANNHAN WHERE MA_NVIEN = @MaNV
END
GO

-- Thực thi
DECLARE @Ten NVARCHAR(100), @DC NVARCHAR(100), @SLTN INT
EXEC SP_ThongTinNVvaSoThanNhan @MaNV = 102,
    @HoTen = @Ten OUTPUT,
    @DiaChi = @DC OUTPUT,
    @SoThanNhan = @SLTN OUTPUT
PRINT N'Họ tên: ' + @Ten
PRINT N'Địa chỉ: ' + @DC
PRINT N'Số lượng thân nhân: ' + CAST(@SLTN AS NVARCHAR)
```

## 2. Trigger

### 2.1 Giới thiệu

- **Trigger** là Stored Procedure đặc biệt sẽ tự động thực hiện khi có hành động bổ sung dữ liệu lên 1 table mà trigger bảo vệ.
- Trigger có thể bao gồm hầu hết các phát biểu T-SQL.

### 2.2 Các tính chất của Trigger

- **Liên kết với Table:** trigger được định nghĩa trên 1 table cụ thể gọi là trigger liên kết table.
- **Thực hiện tự động:** nếu có các hành động INSERT, UPDATE, DELETE mà trigger định nghĩa thì nó tự động thực hiện. Trigger không được gọi trực tiếp và không chấp nhận tham số.
- **Là 1 giao tác (Transaction):**
  - Trigger và phát biểu tạo ra nó được thực hiện như 1 giao tác, có thể Rollback bất cứ đâu trong trigger. Trong trigger có thể có `ROLLBACK TRANSACTION` mà không có `BEGIN TRAN`, SQL Server tự hiểu có `BEGIN TRAN` ảo ở đây.
  - Nếu có Rollback được thực hiện thì toàn bộ transaction sẽ Rollback.
  - Nếu trong 1 batch có Rollback thì toàn bộ batch bị hủy, các phát biểu sau Rollback sẽ không thực hiện.
  - Nên tránh lạm dụng Rollback trong Trigger vì nó phải làm undo các thao tác trước đó -> kiểm tra tính hợp lệ trước khi bắt đầu transaction.

### 2.3 Lợi ích của Trigger

- **Bổ sung dây chuyền (cascade):** các bổ sung dây chuyền bằng Trigger làm giảm coding cần thiết cho sự thay đổi trên các bảng liên quan.
- **Tăng cường toàn vẹn dữ liệu:** do có thể tham chiếu nhiều cột trên các bảng nên có tác dụng hơn CHECK. Tuy vậy các ràng buộc được ưu tiên kiểm tra trước, nếu vi phạm thì trigger không thực thi.
- **Thông báo lỗi do người dùng định nghĩa:** các thông báo Rule, Default, Check.
- **Bảo quản dữ liệu không tiêu chuẩn hóa:** ví dụ bảng:

```
HOADON (MSHD, NGAYHD, TONGTIEN)
CTHOADON (MSHD, MSMH, SOLUONG, DONGIA)
```

Khi sửa số lượng, đơn giá dẫn đến ảnh hưởng tổng tiền.

### 2.4 Lưu ý

- Trigger là phản ứng, ràng buộc được thực hiện trước.
- Ràng buộc được kiểm tra đầu tiên.
- 1 bảng có thể viết nhiều trigger.
- Trigger không thể tạo trên View và bảng tạm.
- Trigger không thể trả về các tập kết quả.

### 2.5 Các loại Trigger phổ biến

- **AFTER Trigger (FOR Trigger):** được thực thi ngay sau khi câu lệnh INSERT, UPDATE hoặc DELETE xảy ra.
- **INSTEAD OF Trigger:** thực thi thay thế cho các câu lệnh INSERT, UPDATE, DELETE gốc, trước khi dữ liệu thực sự thay đổi.

### 2.6 Các thao tác với Trigger

#### Tạo Trigger

```sql
CREATE TRIGGER TenTrigger
ON table [WITH (...)]
[FOR / INSTEAD OF INSERT, UPDATE, DELETE]
[WITH APPEND]
[NOT FOR REPLICATION]
AS
    phát_biểu_SQL
```

#### Sửa Trigger

```sql
ALTER TRIGGER TenTrigger
ON TenTable [WITH ENCRYPTION]
[FOR / INSTEAD OF INSERT, UPDATE, DELETE]
[NOT FOR REPLICATION]
AS
    phát_biểu_SQL
```

#### Xóa Trigger

```sql
DROP TRIGGER TenTrigger
```

- Có thể làm mất hiệu lực tạm thời của Trigger lên 1 table:

```sql
ALTER TABLE tenTable
{ENABLE / DISABLE} TRIGGER {ALL / TenTrigger}
```

- Ví dụ:

```sql
ALTER TABLE KETQUA
DISABLE TRIGGER KiemTraThi2Lan
```

- Muốn có hiệu lực lại: dùng `ENABLE`.

### 2.7 Các bảng đặc biệt: inserted và deleted

- Khi tạo Trigger, thông tin trigger được insert vào các bảng hệ thống `sysobject` và `syscomment`.
- Có sẵn hai bảng đặc biệt trong trigger: **deleted** và **inserted**.
- Bảng **deleted** chứa các bản sao các dòng bị tác động bởi các phát biểu UPDATE và DELETE.
- Bảng **inserted** chứa các bản sao các dòng bị tác động bởi các phát biểu INSERT và UPDATE.
- Không thể thay đổi dữ liệu trên các bảng deleted và inserted trực tiếp, có thể dùng phát biểu SELECT.

### 2.8 Chú ý: các phát biểu không được dùng trong Trigger

SQL không cho phép các phát biểu sau trong Trigger:

- Tất cả các phát biểu CREATE, ALTER, DROP.
- GRANT, REVOKE, DENY.
- LOAD, RESTORE.
- RECONFIGURE.
- TRUNCATE TABLE.
- UPDATE STATISTIC.
- SELECT INTO.

### 2.9 Các hoạt động của Trigger

#### Hoạt động khi INSERT

- Phát biểu INSERT thực hiện trên bảng mà Trigger định nghĩa.
- Phát biểu INSERT được ghi lại.
- Trigger bị bắn phá và các phát biểu trong Trigger thực thi. Khi Trigger INSERT bắn phá, các dòng mới được thêm vào hai bảng: bảng gốc và bảng Insert. Bảng Insert nắm giữ bản sao các dòng đã Insert.
- Trigger có thể khảo sát bảng Insert để quyết định hành động của mình. Các dòng trong bảng Insert thường bị trùng lặp.

#### Hoạt động khi UPDATE

- Phát biểu UPDATE thực hiện trên bảng mà Trigger định nghĩa và được ghi lại.
- Trigger bị bắn phá, phát biểu trong Trigger thực hiện có thể xem như 2 bước: xóa (delete) rồi chèn (insert).
- Các dòng gốc di chuyển đến bảng deleted và các dòng cập nhật được chèn vào bảng inserted.
- Có thể định nghĩa 1 trigger giám sát việc cập nhật dữ liệu trên 1 cột đặc biệt bằng phát biểu `IF UPDATE`:

```sql
IF UPDATE(column) [{AND | OR} UPDATE(cols)]
```

- Ví dụ:

```sql
CREATE TRIGGER CapnhatMSSV
ON SinhVien
FOR UPDATE
AS
BEGIN
    IF UPDATE(MSSV)
    BEGIN
        PRINT 'Không được cập nhật mã số SV'
        ROLLBACK TRANSACTION
    END
END
```

#### Hoạt động khi DELETE

- Phát biểu DELETE thực hiện trên bảng mà Trigger định nghĩa và được ghi lại.
- Khi Trigger bắn phá, các dòng bị xóa được đặt trong bảng Deleted (bảng Deleted lưu giữ bản sao các dòng bị xóa).
- Chú ý:
  - Các dòng Deleted không tồn tại trong cơ sở dữ liệu, vì vậy bảng xóa và cơ sở dữ liệu không có các "dòng chung".
  - Trigger bắn phá bởi DELETE không thực hiện phát biểu `TRUNCATE TABLE`.

### 2.10 Ví dụ

#### Ví dụ 1: Tự động lưu lịch sử khi thay đổi lương của nhân viên

Cho bảng: `LICHSULUONG (MANV, LUONG_CU, LUONG_MOI, NGAYTHAYDOI)`

```sql
CREATE TRIGGER TRG_LuuLichSuLuong
ON NHANVIEN FOR UPDATE
AS
BEGIN
    INSERT INTO LICHSULUONG(MANV, LUONG_CU, LUONG_MOI, NGAYTHAYDOI)
    SELECT i.MANV, d.LUONG, i.LUONG, GETDATE()
    FROM inserted i       -- dữ liệu mới
    JOIN deleted d        -- dữ liệu cũ
    ON i.MANV = d.MANV
    WHERE i.LUONG <> d.LUONG  -- chỉ lưu khi lương thay đổi
END
```

#### Ví dụ 2: Ngăn không cho xóa nhân viên nếu họ đang tham gia đề án

```sql
CREATE TRIGGER TRG_NganXoaNhanVien
ON NHANVIEN INSTEAD OF DELETE
AS
BEGIN
    IF EXISTS (SELECT * FROM PHANCONG
               WHERE MA_NVIEN IN (SELECT MANV FROM deleted))
    BEGIN
        RAISERROR(N'Không được xóa nhân viên đang tham gia đề án!', 16, 1)
        ROLLBACK TRANSACTION
    END
    ELSE
        DELETE FROM NHANVIEN WHERE MANV IN (SELECT MANV FROM deleted)
END
```

#### Ví dụ 3: Tự động cập nhật tổng tiền (TONGTIEN) trong bảng HOADON

Mỗi khi có thêm, sửa hoặc xóa chi tiết hóa đơn (CTHD), tự động cập nhật tổng tiền trong bảng HOADON, đồng thời in thông báo giả lập gửi email.

```sql
CREATE TRIGGER TRIG_CTHD
ON CTHD
AFTER INSERT, UPDATE, DELETE
AS
BEGIN
    UPDATE HOADON
    SET TONGTIEN = (
        SELECT COALESCE(SUM(SOLUONG * DONGIA), 0)
        FROM CTHD
        WHERE CTHD.SOHD = HOADON.SOHD
    )
    WHERE SOHD IN (
        SELECT SOHD FROM INSERTED
        UNION
        SELECT SOHD FROM DELETED
    )

    -- Send email
    PRINT 'Email notification sent to customer'
END
```

### 2.11 Trigger lồng (Nested Trigger)

- Trigger có thể lồng nhau **32 mức**. Bất cứ trigger nào trong chuỗi lồng bị loop (mức lồng vượt quá 32) thì transaction sẽ rollback.
- Chú ý:
  - Mặc định, cấu hình lồng bằng ON.
  - Trigger bị lồng không bị bắn phá 2 lần trong 1 transaction; trigger không thể tự bắn phá chính nó (trường hợp này gọi là trigger đệ quy).
  - Một trigger là 1 transaction; 1 lỗi xảy ra ở bất kỳ đâu thì tất cả việc bổ sung dữ liệu sẽ rollback. Có thể thêm phát biểu PRINT để kiểm tra lỗi xảy ra tại đâu.
- Mức lồng sẽ tăng lên khi có trigger lồng bị bắn phá. Để tránh mức lồng vượt quá 32, nên dùng hàm `@@NESTLEVEL`.

#### Lợi ích của Trigger lồng

- Dùng trigger là công cụ hữu hiệu đảm bảo dữ liệu toàn vẹn.
- Khi cài đặt SQL Server, lồng nhau là mặc định. Có thể tạm thời mất hiệu lực trigger lồng bằng cú pháp:
  - `sp_configure 'nested triggers', 0` (tắt)
  - `sp_configure 'nested triggers', 1` (bật)
- Ví dụ: thiết lập trigger khi một đơn đặt hàng mới được đặt; trigger này gọi một trigger khác gửi thông báo qua email cho các bên liên quan và một trigger khác cập nhật trạng thái của đơn đặt hàng trong cơ sở dữ liệu.

#### Điểm yếu của Trigger lồng

- Làm mất tính log của trigger do tính phức tạp của nó.
- Có thể thay thế chức năng log của trigger bằng cách: mỗi trigger được khởi tạo sẽ bổ sung tất cả dữ liệu cần thiết nhờ trợ giúp của Stored Procedure.

### 2.12 Trigger đệ quy (Recursive Trigger)

- Trigger có thể có các phát biểu UPDATE, INSERT, DELETE đến cùng một bảng hay bảng khác. Khi option đệ quy được bật, trigger có thể thay đổi table mà bắn phá chính nó. Option đệ quy mặc định là không (OFF).
- Cú pháp bật/tắt:

```sql
sp_dboption database, 'recursive triggers', (True | False)
```

#### Các loại đệ quy

- **Đệ quy trực tiếp:** ví dụ, một ứng dụng cập nhật table A gây nên trig1; trig1 lại cập nhật A một lần nữa và trig1 bị gọi lại.
- **Đệ quy gián tiếp:** ví dụ, ứng dụng cập nhật table A gây nên trig1 bắn phá, trig1 cập nhật table B gây nên trig2, trig2 cập nhật table A làm trig1 bắn phá lần nữa.

### 2.13 Bài tập dùng Trigger

1. Tạo ràng buộc không cho phép giảm lương nhân viên
2. Tạo ràng buộc không cho phép xóa phòng ban nếu phòng ban còn nhân viên
3. Tạo ràng buộc một nhân viên tham gia không quá 3 đề án

#### Bài 1: Không cho phép giảm lương nhân viên

```sql
CREATE TRIGGER TRG_NganGiamLuong_Update
ON NHANVIEN
FOR UPDATE
AS
BEGIN
    IF EXISTS (SELECT * FROM INSERTED i JOIN DELETED d ON i.MANV = d.MANV
               WHERE i.LUONG < d.LUONG)
    BEGIN
        RAISERROR(N'Không được giảm lương nhân viên!', 16, 1)
        ROLLBACK TRANSACTION
    END
END
```

#### Bài 2: Không cho phép xóa phòng ban nếu phòng ban còn nhân viên

```sql
CREATE TRIGGER TRG_NganXoaPhongBan_Delete
ON PHONGBAN INSTEAD OF DELETE
AS
BEGIN
    IF EXISTS (SELECT * FROM NHANVIEN WHERE PHG IN (SELECT MAPHG FROM DELETED))
    BEGIN
        RAISERROR(N'Phòng ban vẫn còn nhân viên, không thể xóa!', 16, 1)
        ROLLBACK TRANSACTION
    END
    ELSE
        DELETE FROM PHONGBAN WHERE MAPHG IN (SELECT MAPHG FROM DELETED)
END
```

#### Bài 3: Một nhân viên tham gia không quá 3 đề án

```sql
CREATE TRIGGER TRG_GioiHanSoDeAnNV
ON PHANCONG AFTER INSERT, UPDATE
AS
BEGIN
    IF EXISTS (SELECT i.MA_NVIEN FROM INSERTED i JOIN PHANCONG p
               ON i.MA_NVIEN = p.MA_NVIEN
               GROUP BY i.MA_NVIEN HAVING COUNT(p.MADA) > 3)
    BEGIN
        RAISERROR(N'Mỗi nhân viên chỉ được tham gia tối đa 3 đề án.', 16, 1)
        ROLLBACK TRANSACTION
    END
END
```

## 3. Function

### 3.1 Giới thiệu

- **Function (Hàm)** là một đối tượng trong cơ sở dữ liệu bao gồm một tập nhiều câu lệnh được nhóm lại với nhau và được tạo ra với mục đích sử dụng lại.
- Trong SQL Server, hàm được lưu trữ; bạn có thể truyền tham số vào cũng như nhận các giá trị trả về.

### 3.2 Các thao tác với hàm

Khai báo hàm trong SQL có 3 dạng:

- Dạng 1: Scalar-valued Functions.
- Dạng 2: Inline Table-valued Functions.
- Dạng 3: Multi-statement Table-valued Functions.

Xóa hàm:

```sql
DROP FUNCTION function_name;
```

### 3.3 Dạng 1: Scalar-valued Functions

Trả về một giá trị vô hướng.

```sql
CREATE FUNCTION [owner_name.] function_name
( [{ @parameter_name [AS] scalar_parameter_data_type [= default] } [,...n] ] )
RETURNS scalar_return_data_type
[AS]
BEGIN
    function_body
    RETURN scalar_expression
END
```

#### Ví dụ 1: Thực hiện phép tính cộng hai số nguyên

```sql
CREATE FUNCTION CONG(@X1 INT, @X2 INT) RETURNS INT
AS
BEGIN
    RETURN @X1 + @X2
END

-- Sử dụng
SELECT DBO.CONG(1, -5) AS KQ
```

### 3.4 Dạng 2: Inline Table-valued Functions

Trả về một bảng kết quả từ một câu SELECT (inline).

```sql
CREATE FUNCTION [owner_name.] function_name
( [{ @parameter_name [AS] scalar_parameter_data_type [= default] } [,...n] ] )
RETURNS TABLE
[AS]
RETURN [(] select-stmt [)]
```

#### Ví dụ 2: Tìm sinh viên có điểm thấp hơn một điểm cho trước

```sql
CREATE FUNCTION DIEMNHOHON(@DIEM INT) RETURNS TABLE
AS
RETURN (SELECT * FROM KETQUA WHERE DIEM < @DIEM)

-- Sử dụng
SELECT * FROM DBO.DIEMNHOHON(5)
```

### 3.5 Dạng 3: Multi-statement Table-valued Functions

Trả về một biến bảng (table variable) được định nghĩa rõ cấu trúc, thân hàm có nhiều phát biểu.

```sql
CREATE FUNCTION [owner_name.] function_name
( [{ @parameter_name [AS] scalar_parameter_data_type [= default] } [,...n] ] )
RETURNS @return_variable TABLE <table_type_definition>
[WITH <function_option> [[,]...n]]
[AS]
BEGIN
    function_body
    RETURN
END
```

#### Ví dụ 3

```sql
CREATE FUNCTION KETQUATHEODIEM(@DIEM INT) RETURNS @RESULT TABLE (MSGV INT, MSMH INT, DIEM INT)
AS
BEGIN
    INSERT INTO @RESULT(MSGV, MSMH, DIEM)
    SELECT MSGV, MSMH, DIEM FROM KETQUA WHERE DIEM > @DIEM
    RETURN
END
```

### 3.6 So sánh Stored Procedure và Function

| Stored Procedure | Function |
|---|---|
| Là một tập các câu lệnh SQL | Là một tập các câu lệnh SQL |
| Có thể trả về 0, 1 hoặc nhiều giá trị | Luôn trả về một giá trị hoặc bảng dữ liệu |
| Có tham số vào và ra | Chỉ có các tham số vào |
| Có thể gọi Function trong Stored Procedure | Không thể gọi Stored Procedure trong Function |
| Không thể sử dụng trong câu SELECT / WHERE / HAVING | Có thể sử dụng trong câu SELECT / WHERE / HAVING / JOIN |
| Có TRY-CATCH | Không có TRY-CATCH |
| Có Transaction | Không có Transaction |

## 4. Cursor

### 4.1 Giới thiệu

- **Cursor (con trỏ)** là một kỹ thuật lập trình CSDL cao cấp trong SQL, dùng để tính toán và chọn một trường/ô (duyệt - traversal) trong một bảng (table) của CSDL.
- Cursor tạo điều kiện xử lý tiếp theo kết hợp với traversal, chẳng hạn như thu hồi, bổ sung và loại bỏ các bản ghi.
- Trong các thủ tục SQL, cursor cho phép định nghĩa một tập kết quả (một tập hợp các dòng dữ liệu) và thực hiện logic phức tạp trên cơ sở hàng bằng hàng.

### 4.2 Vấn đề

- Các câu lệnh SQL thao tác lên nhiều dòng dữ liệu thỏa điều kiện WHERE cùng lúc, không thể thao tác trên từng dòng cụ thể.
- Cursor là kiểu dữ liệu có thể duyệt qua từng dòng kết quả trả về của câu lệnh SELECT, giúp xử lý khác nhau cho từng kết quả mong muốn.
- Khuyết điểm: xử lý rất chậm.

### 4.3 Các bước sử dụng một Cursor

1. Khai báo một con trỏ xác định một tập kết quả.
2. Thiết lập kết quả cho con trỏ.
3. Gán dữ liệu cho các biến cục bộ cần thiết cho con trỏ và một hàng.
4. Đóng cursor khi hoàn thành.

### 4.4 Các cú pháp

#### Bước 1: Khai báo Cursor

```sql
DECLARE ten_con_tro [SCROLL] CURSOR
FOR
SELECT ... FROM ... WHERE ...
[FOR {READ ONLY | UPDATE [OF ten_cot [truong]]}]
```

- **SCROLL:** cho phép con trỏ di chuyển lên xuống, qua lại giữa các mẫu tin.
- **READ ONLY:** không cho phép thực thi các hành động như UPDATE...
- **UPDATE:** xác định khả năng cập nhật của con trỏ; nếu `OF` được chỉ định thì chỉ những cột trong danh sách được chỉnh sửa.
- Có thể khởi tạo riêng con trỏ rồi mới gán lệnh SELECT cho con trỏ:

```sql
DECLARE @ten_con_tro CURSOR
SET @ten_con_tro = CURSOR FOR SELECT ...
```

#### Bước 2: Mở Cursor

```sql
OPEN [GLOBAL] ten_con_tro | @ten_con_tro
```

Lưu ý: GLOBAL là biến toàn cục.

#### Bước 3: Truy cập Cursor (FETCH)

```sql
FETCH [NEXT | PRIOR | FIRST | LAST | ABSOLUTE {n | @nVar} | RELATIVE {n | @nVar}]
FROM [GLOBAL] ten_con_tro | @ten_con_tro
[INTO @ten_bien [du_lieu]]
```

- **NEXT, PRIOR, FIRST, LAST:** chỉ định cách đọc dữ liệu.
- **ABSOLUTE:** chỉ định n số dòng dữ liệu cần đọc:
  - n = 0: không có giá trị trả về.
  - n < 0: xuất phát từ phần đáy dữ liệu.
  - n > 0: xuất phát từ phần đỉnh dữ liệu.
- **RELATIVE** cũng giống như ABSOLUTE nhưng bắt đầu từ vị trí hiện tại.
- Dùng lệnh `@@FETCH_STATUS` để kiểm tra hệ thống đọc dữ liệu thành công hay thất bại.

#### Bước 4: Đóng Cursor

```sql
CLOSE [GLOBAL] ten_con_tro | @ten_con_tro
-- hoặc
DEALLOCATE [GLOBAL] ten_con_tro | @ten_con_tro
```

- **CLOSE** đóng cursor lại nhưng có thể tái sử dụng ở lần sau.
- **DEALLOCATE** giải phóng hoàn toàn cursor ra khỏi bộ nhớ; nếu có lệnh nào tham chiếu tới cursor sau đó có thể gây lỗi.

### 4.5 Ví dụ tính điểm trung bình của sinh viên

Cơ sở dữ liệu cho trước:

```
KQ (MASV, TENMH, DIEM)
SV (MASV, TENSV, DIEMTB)
```

Dữ liệu bảng KQ:

| MASV | TENMH | DIEM |
|---|---|---|
| s1 | m1 | 7 |
| s2 | m1 | 8 |
| s3 | m1 | 6 |
| s1 | m3 | 4 |
| s2 | m3 | 9 |
| s5 | m4 | 3 |
| s2 | m4 | 8 |
| s1 | m4 | 9 |

Dữ liệu bảng SV:

| MASV | TENSV | DIEMTB |
|---|---|---|
| s1 | B | --- |
| s2 | A | --- |
| s3 | C | --- |
| s5 | D | --- |

#### Ví dụ 1: Các bước thực hiện

```sql
-- Khai báo biến
DECLARE @A CHAR(10), @B FLOAT

-- Khai báo con trỏ
DECLARE X CURSOR FOR SELECT MASV FROM SV

-- Mở con trỏ
OPEN X

-- Truy cập con trỏ
FETCH NEXT FROM X INTO @A

-- Kiểm tra con trỏ đọc dữ liệu được hay không
WHILE (@@FETCHSTATUS = 0)
BEGIN
    -- Tính điểm TB dựa vào con trỏ
    SELECT @B = AVG(DIEM) FROM KQ WHERE MASV = @A
    UPDATE SV SET DIEMTB = @B WHERE MASV = @A
    FETCH NEXT FROM X INTO @A
END

-- Đóng con trỏ
CLOSE X
DEALLOCATE X
```

#### Thực thi Cursor

- Để thực thi Cursor, dùng lệnh EXEC.

```sql
EXEC TINHDIEM
```

#### CODE mẫu

```sql
CREATE PROCEDURE TINHDIEM
AS
BEGIN
    DECLARE @A CHAR(10), @B FLOAT
    DECLARE X CURSOR FOR SELECT MASV FROM SV
    OPEN X
    FETCH NEXT FROM X INTO @A
    WHILE (@@FETCHSTATUS = 0)
    BEGIN
        SELECT @B = AVG(DIEM) FROM KQ WHERE MASV = @A
        UPDATE SINHVIEN SET @B = DTB WHERE MASV = @A
        FETCH NEXT FROM X INTO @A
    END
    CLOSE X
    DEALLOCATE X
END
```

#### Ví dụ 2: Tính điểm trung bình của từng sinh viên

```sql
DECLARE X CURSOR FOR
SELECT MASV, AVG(DIEM) AS DTB
FROM KQ
GROUP BY MASV
OPEN X
DECLARE @A CHAR(10), @B FLOAT
FETCH X INTO @A, @B
WHILE (@@FETCHSTATUS = 0)
BEGIN
    FETCH NEXT FROM X INTO @A, @B
END
```

### 4.6 Bài tập Cursor

- Bài 1. Viết Cursor trả về SỐ MÔN HỌC của SV.
- Bài 2. Viết Cursor trả về SỐ MÔN HỌC LẠI của SV (sinh viên học lại khi DIEM < 5).
- Bài 3. Viết Cursor cập nhật số môn học của sinh viên từ bảng SV vào bảng KQ.

## 5. Tổng kết

- T-SQL là ngôn ngữ lập trình CSDL, kết hợp các nhóm lệnh SQL lại với nhau.
- Stored Procedure là một dạng thủ tục, dùng để nhóm các câu lệnh SQL lại với nhau. Có 2 dạng: không tham số và có tham số (tham số gồm 2 dạng: tham số vào và tham số ra).
- Trigger được thực thi tự động khi có hành vi thay đổi trên CSDL. Trigger không có tham số.
- Function là một dạng đối tượng nhận tham số đầu vào và trả về giá trị cụ thể, dùng để tái sử dụng lại các lệnh SQL.
- Cursor là kỹ thuật lập trình nâng cao, cho phép truy xuất dữ liệu phức tạp theo từng dòng và từng ô.

## 6. Tài liệu tham khảo

1. Nguyễn Gia Tuấn Anh, Trương Châu Long, *Bài tập và bài giải SQL Server*, NXB Thanh niên (2005).
2. Đỗ Phúc, Nguyễn Đăng Tỵ, *Cơ sở dữ liệu*, NXB Đại học quốc gia TPHCM (2010).
3. Nguyễn Gia Tuấn Anh, Mai Văn Cường, Bùi Danh Hường, *Cơ sở dữ liệu nâng cao*, NXB Đại học quốc gia TPHCM (2019).
4. Itzik Ben-Gan, *Microsoft SQL Server 2012 - TSQL Fundamentals*.