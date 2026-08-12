# Chương 3 (Bài giảng 04) - Truy vấn thông tin trên máy tính

## Nội dung chương

1. Truy vấn SQL
2. Xpath/Xquery
3. Các dạng truy vấn Select thường gặp

---

## Phần 1. Truy vấn SQL

### 1.1 Giới thiệu

SQL (Structured Query Language):

- Là ngôn ngữ cấp cao
- Dùng để truy vấn dữ liệu trong CSDL quan hệ
- Được IBM phát triển vào những năm 1970
- Ban đầu được gọi là SEQUEL
- Được ANSI công nhận và phát triển thành chuẩn SQL-86, SQL-92, SQL-99

SQL là ngôn ngữ chuẩn dùng để truy vấn trong các CSDL quan hệ. Các CSDL quan hệ dù khác nhau về nền tảng và hãng sản xuất nhưng luôn có điểm chung là dùng SQL làm ngôn ngữ truy vấn.

### 1.2 Các nhóm lệnh

| Nhóm lệnh | Chức năng | Các lệnh |
|---|---|---|
| DDL (Data Definition Language) | Định nghĩa dữ liệu: tạo, thay đổi cấu trúc bảng | Create, Drop, Alter |
| DML (Data Manipulation Language) | Thao tác dữ liệu: làm thay đổi dữ liệu lưu trong bảng | Insert, Delete, Update, Select |
| DCL (Data Control Language) | Điều khiển dữ liệu: quản lý quyền truy cập vào dữ liệu và các bảng | Grant, Revoke, Deny |

### 1.3 Phép kết trên nhiều bảng

#### Phép kết, kết tự nhiên

- Dùng mệnh đề WHERE để chỉ ra điều kiện kết giữa các thuộc tính của các bảng
- Hoặc dùng từ khóa `Inner Join` (hoặc `Join`) trong mệnh đề FROM

#### Phép kết trái, phải, ngoài

- Dùng `LEFT JOIN`, `RIGHT JOIN` (Half Outer Join) và `FULL OUTER JOIN` trong mệnh đề FROM

#### Lược đồ CSDL Quản lý nhân sự (Ví dụ)

```text
NHANVIEN (MANV, HONV, TENLOT, TENNV, NGSINH, DCHI, PHAI, LUONG, MA_NQL, PHG)
PHONGBAN (MAPHG, TENPHG, TRPHG, NG_NC)
DIADIEM (MADIADIEM, TENDIADIEM)
DIADIEM_PHG (MADIADIEM, MAPHG)
THANNHAN (MA_NVIEN, TENTN, PHAI, NGSINH, QUANHE)
DEAN (MADA, TENDA, DDIEM_DA, PHONG)
PHANCONG (MA_NVIEN, MADA, THOIGIAN)
```

Mô tả chi tiết và ràng buộc khóa:

- `NHANVIEN(Mã nhân viên, Họ, Tên lót, Tên, Ngày sinh, Địa chỉ, Giới tính, Lương, Mã người quản lý, Mã phòng)` - `Mã nhân viên` là khóa chính; `Mã phòng` là khóa ngoại đến `Mã phòng ban` của bảng PHÒNG BAN; `Mã người quản lý` là khóa ngoại đến `Trưởng phòng` của bảng PHÒNG BAN
- `PHÒNGBAN(Mã phòng ban, Tên phòng, Trưởng phòng, Ngày nhậm chức)` - `Mã phòng` là khóa chính
- `ĐỊAĐIỂM(Mã địa điểm, Tên địa điểm)` - `Mã địa điểm` là khóa chính
- `ĐỊAĐIỂM_PHÒNG(Mã địa điểm, Mã phòng ban)` - Khóa chính là cả 2 thuộc tính; `Mã địa điểm` là khóa ngoại đến bảng ĐỊA ĐIỂM, `Mã phòng ban` là khóa ngoại đến bảng PHÒNG BAN
- `THÂNNHÂN(Mã Nviên, Tên thân nhân, Giới tính, Ngày sinh, Quan hệ)` - `Mã Nviên` và `Tên thân nhân` là khóa chính; `Mã Nviên` là khóa ngoại đến `Mã nhân viên` trong bảng NHÂN VIÊN
- `ĐỀÁN(Mã đề án, Tên đề án, Địa điểm đề án, Phòng ban chủ trì)` - `Mã đề án` là khóa chính; `Phòng ban chủ trì` là khóa ngoại đến `Mã phòng ban` của bảng PHÒNG BAN
- `PHÂNCÔNG(Mã Nviên, Mã đề án, Thời gian)` - `Mã Nviên` và `Mã đề án` là khóa chính; `Mã Nviên` là khóa ngoại đến `Mã nhân viên` trong bảng NHÂN VIÊN, `Mã đề án` là khóa ngoại đến `Mã đề án` trong bảng ĐỀ ÁN

#### Ví dụ phép kết

> 1. In danh sách mã số, họ tên của tất cả các nhân viên và tên thân nhân của nhân viên đó.

```sql
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten, tentn
FROM Nhanvien JOIN Thannhan ON Nhanvien.manv = Thannhan.ma_nvien
```

> 2. In danh sách mã số, họ tên của tất cả các nhân viên và tên thân nhân của nhân viên đó (nếu có).

```sql
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten, tentn
FROM Nhanvien LEFT JOIN Thannhan ON Nhanvien.manv = Thannhan.ma_nvien
```

- Vd 1 dùng `JOIN`: chỉ hiển thị nhân viên có thân nhân
- Vd 2 dùng `LEFT JOIN`: hiển thị tất cả nhân viên, thân nhân (nếu có)

### 1.4 Truy vấn lồng (Subquery)

- Các câu lệnh SELECT có thể lồng nhau ở nhiều mức
- Các câu truy vấn con thường trả về một tập các giá trị
- Các câu truy vấn con được kết hợp bằng phép nối logic với câu truy vấn cha

#### In và Not In

Cú pháp:

```text
<thuộc tính> (NOT) IN (<truy vấn con>)
```

Lưu ý: Thuộc tính ở mệnh đề SELECT của truy vấn con phải có cùng kiểu dữ liệu với thuộc tính ở mệnh đề WHERE của truy vấn cha.

> 3. Tìm nhân viên chưa được phân công thực hiện đề án nào

```sql
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten
FROM Nhanvien
WHERE manv NOT IN
    (SELECT DISTINCT ma_nvien FROM Phancong)
```

#### Any/Some và All

Cú pháp:

```text
<thuộc tính> <phép so sánh> ANY/SOME/ALL (<truy vấn con>)
```

Lưu ý:

- Thuộc tính ở mệnh đề SELECT của truy vấn con phải có cùng kiểu dữ liệu với thuộc tính ở mệnh đề WHERE của truy vấn cha
- `ANY` / `SOME`: so sánh với bất kỳ giá trị nào đó trong tập hợp
- `ALL`: so sánh với tất cả các giá trị trong tập hợp

#### Ví dụ Any/All

> Vd 4: Dùng self join để so sánh lương

```sql
SELECT nv1.manv, nv1.honv + ' ' + nv1.tenlot + ' ' + nv1.tennv AS hoten
FROM Nhanvien nv1, Nhanvien nv2
WHERE nv1.phai = 'Nu' AND nv1.luong > nv2.luong AND nv2.phai = 'Nam'
```

> Vd 5: Lấy nhân viên nữ có lương lớn hơn từng nhân viên nam một

```sql
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten
FROM Nhanvien
WHERE phai = 'Nu' AND luong > ANY
    (SELECT luong FROM Nhanvien WHERE phai = 'Nam')
```

> Vd 6: (theo cách dùng ALL) - tương đương tìm lương cao nhất

```sql
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten
FROM Nhanvien
WHERE luong >= ALL
    (SELECT luong FROM Nhanvien)
```

#### Nhận xét: Self JOIN so với ANY

| Tiêu chí | VD5 - Dùng Self JOIN | VD6 - Dùng ANY |
|---|---|---|
| Ý nghĩa | Lấy nhân viên nữ có lương lớn hơn từng nhân viên nam một | Lấy nhân viên nữ có lương lớn hơn ít nhất một nhân viên nam |
| Số dòng trả về | Một nữ có thể xuất hiện nhiều lần (tùy số nam thấp hơn) | Mỗi nữ chỉ xuất hiện 1 lần (nếu đáp ứng điều kiện) |
| Hiệu suất | Chậm hơn khi bảng lớn (JOIN tự kết hợp) | Tốt hơn (dùng subquery) |
| Trường hợp NULL | Nếu nv2.luong có NULL, kết quả có thể bị sai | Bỏ qua NULL, không gây lỗi |

#### Exists và Not Exists

Cú pháp:

```text
(NOT) EXISTS (<câu truy vấn con>)
```

Lưu ý:

- Không cần có thuộc tính, hằng số hay biểu thức nào khác đứng trước
- Không nhất thiết liệt kê tên thuộc tính ở mệnh đề SELECT của truy vấn con
- Những câu truy vấn có điều kiện `= ANY` hay `IN` đều có thể chuyển thành câu truy vấn có `EXISTS`

#### Ví dụ Exists / Not Exists

> Tìm nhân viên đã được phân công ít nhất một công việc

```sql
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten
FROM Nhanvien
WHERE EXISTS
    (SELECT * FROM Phancong WHERE manv = ma_nvien)
```

> Vd 7, 8, 9: Tìm nhân viên chưa được phân công thực hiện đề án nào (3 cách viết tương đương)

```sql
-- Cách 1 (Vd 7): NOT IN
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten
FROM Nhanvien
WHERE manv NOT IN
    (SELECT DISTINCT ma_nvien FROM Phancong)

-- Cách 2 (Vd 8): NOT EXISTS
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten
FROM Nhanvien
WHERE NOT EXISTS
    (SELECT * FROM Phancong WHERE manv = ma_nvien)

-- Cách 3 (Vd 9): <> ALL
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten
FROM Nhanvien
WHERE manv <> ALL
    (SELECT DISTINCT ma_nvien FROM Phancong)
```

#### Phân loại truy vấn lồng

| Loại | Đặc điểm | Cách thực hiện |
|---|---|---|
| Lồng phân cấp | Mệnh đề WHERE của truy vấn con không tham chiếu đến thuộc tính của các quan hệ trong mệnh đề FROM ở truy vấn cha | Câu truy vấn con được thực hiện trước |
| Lồng tương quan | Mệnh đề WHERE của truy vấn con tham chiếu ít nhất một thuộc tính của các quan hệ trong mệnh đề FROM ở truy vấn cha | Câu truy vấn con được thực hiện nhiều lần, mỗi lần tương ứng với một bộ của truy vấn cha |

#### Ví dụ lồng phân cấp

> Vd 10: Kết hai bảng Nhanvien và Thannhan

```sql
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten
FROM Nhanvien, Thannhan
WHERE manv = ma_nvien AND quanhe = 'Con trai'
```

> Vd 11: Truy vấn con độc lập (lồng phân cấp) với IN

```sql
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten
FROM Nhanvien
WHERE manv IN
    (SELECT ma_nvien FROM Thannhan WHERE quanhe = 'Con trai')
```

#### Ví dụ lồng tương quan

> Vd 12: Kết hai bảng Nhanvien và Thannhan

```sql
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten
FROM Nhanvien, Thannhan
WHERE manv = ma_nvien AND quanhe = 'Con trai'
```

> Vd 13: Dùng EXISTS với truy vấn con tương quan

```sql
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten
FROM Nhanvien
WHERE EXISTS
    (SELECT * FROM Thannhan WHERE manv = ma_nvien AND quanhe = 'Con trai')
```

#### Nhận xét: JOIN so với IN so với EXISTS

| Tiêu chí | JOIN | IN | EXISTS |
|---|---|---|---|
| Cách hoạt động | Kết hợp hai bảng, lọc `quanhe = 'Con trai'` | Lấy danh sách ma_nvien từ Thannhan, lọc Nhanvien | Kiểm tra tồn tại của dòng trong Thannhan |
| Ưu điểm | Nhanh với bảng nhỏ, dễ hiểu | Dễ hiểu, kết quả không trùng | Tốt hơn với bảng lớn, không lỗi với NULL |
| Nhược điểm | Trả về nhiều dòng nếu có nhiều con trai | Chậm hơn với bảng lớn, lỗi nếu có NULL | Phức tạp hơn IN |
| Dùng khi nào | Khi cần lấy thêm thông tin từ Thannhan | Khi dữ liệu nhỏ, không có NULL | Khi dữ liệu lớn, có NULL |

#### Ví dụ lồng tương quan (không phân công)

> Vd 14: NOT IN

```sql
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten
FROM Nhanvien
WHERE manv NOT IN
    (SELECT DISTINCT ma_nvien FROM PHANCONG)
```

> Vd 15: NOT EXISTS

```sql
SELECT manv, honv + ' ' + tenlot + ' ' + tennv AS hoten
FROM Nhanvien
WHERE NOT EXISTS
    (SELECT * FROM Phancong WHERE manv = ma_nvien)
```

#### Nhận xét: IN / NOT IN / EXISTS / NOT EXISTS

| Tiêu chí | IN | NOT IN | EXISTS | NOT EXISTS |
|---|---|---|---|---|
| Mục đích | Kiểm tra một giá trị có thuộc danh sách kết quả từ subquery hay không | Kiểm tra một giá trị không thuộc danh sách kết quả từ subquery | Kiểm tra có ít nhất một bản ghi tồn tại trong subquery | Kiểm tra không có bản ghi nào tồn tại trong subquery |
| Cách hoạt động | So sánh từng giá trị với danh sách từ subquery | So sánh từng giá trị với danh sách từ subquery | Dừng ngay khi tìm thấy một kết quả khớp | Dừng ngay khi tìm thấy một kết quả khớp |
| Hiệu suất với dữ liệu lớn | Chậm hơn nếu danh sách lớn, phải kiểm tra tất cả giá trị | Chậm hơn nếu danh sách lớn, phải kiểm tra tất cả giá trị | Nhanh hơn IN vì chỉ cần tìm thấy một kết quả là dừng | Nhanh hơn NOT IN vì chỉ cần tìm thấy một kết quả là dừng |
| Khi có NULL | Có thể bị lỗi nếu danh sách chứa NULL | Có thể bị lỗi nếu danh sách chứa NULL | Không bị ảnh hưởng bởi NULL | Không bị ảnh hưởng bởi NULL |
| Dùng khi nào | Khi danh sách nhỏ và chắc chắn không có NULL | Khi danh sách nhỏ và chắc chắn không có NULL | Khi bảng dữ liệu lớn hoặc có NULL | Khi bảng dữ liệu lớn hoặc có NULL |

### 1.5 Một số dạng truy vấn khác

- Câu truy vấn con không chỉ xuất hiện ở mệnh đề WHERE mà có thể xuất hiện ở những nơi khác (SELECT, FROM, HAVING,...)
- Kết quả trả về của câu truy vấn con là một bảng trung gian trong quá trình truy vấn; bảng này không có lưu trữ thật sự

#### Ví dụ subquery trong SELECT

> Vd 16: Cho biết số lượng nhân viên Nam (phai='Nam'), nhân viên Nữ (phai='Nu') trong từng phòng ban.

```sql
SELECT MAPHG, TENPHG,
    (SELECT COUNT(*) FROM NHANVIEN
     WHERE PHAI = 'Nam' AND PHG = MAPHG) AS SLNAM,
    (SELECT COUNT(*) FROM NHANVIEN
     WHERE PHAI = 'Nu' AND PHG = MAPHG) AS SLNU
FROM PHONGBAN
```

- Duyệt từng phòng trong PHONGBAN
- Với mỗi phòng, chạy 2 subquery riêng biệt để đếm số nhân viên nam (SLNAM) và nữ (SLNU)
- Chạy lại 2 lần subquery cho mỗi dòng -> Không tối ưu khi có nhiều phòng ban

#### Ví dụ subquery trong FROM

> Vd 17: Cùng yêu cầu nhưng tối ưu bằng cách dùng subquery trong FROM

```sql
SELECT MAPHG, TENPHG, NAM.SLNV, NU.SLNV
FROM PHONGBAN,
    (SELECT PHG, COUNT(*) AS SLNV
     FROM NHANVIEN
     WHERE PHAI = 'Nam'
     GROUP BY PHG) AS NAM,
    (SELECT PHG, COUNT(*) AS SLNV
     FROM NHANVIEN
     WHERE PHAI = 'Nu'
     GROUP BY PHG) AS NU
WHERE MAPHG = NAM.PHG AND MAPHG = NU.PHG
```

- Dùng hai subquery NAM và NU trong FROM để tính trước số nhân viên nam và nữ theo từng PHG
- Kết hợp kết quả với PHONGBAN qua WHERE
- Tính toán nhóm trước (GROUP BY PHG), tránh chạy lại subquery cho từng dòng

### 1.6 Các phép toán trên tập hợp

SQL cài đặt các phép toán:

- Hội (UNION): lấy các bộ xuất hiện trong một hoặc cả hai truy vấn, nhưng loại bỏ các bộ trùng lặp
- Giao (INTERSECT): lấy các bộ xuất hiện trong cả hai truy vấn
- Trừ (EXCEPT): lấy các bộ có trong truy vấn đầu tiên nhưng không có trong truy vấn thứ hai

Kết quả trả về là tập hợp nên loại bỏ các bộ trùng nhau. Để giữ lại các bộ trùng nhau, dùng `UNION ALL`, `INTERSECT ALL`, `EXCEPT ALL`.

Cú pháp:

```text
SELECT <các thuộc tính> FROM <các bảng> WHERE <các điều kiện>
UNION [ALL]
SELECT <các thuộc tính> FROM <các bảng> WHERE <các điều kiện>
```

```text
SELECT <các thuộc tính> FROM <các bảng> WHERE <các điều kiện>
INTERSECT [ALL]
SELECT <các thuộc tính> FROM <các bảng> WHERE <các điều kiện>
```

```text
SELECT <các thuộc tính> FROM <các bảng> WHERE <các điều kiện>
EXCEPT [ALL]
SELECT <các thuộc tính> FROM <các bảng> WHERE <các điều kiện>
```

Ngoài ra:

- Có thể dùng IN, NOT IN, EXISTS, NOT EXISTS,... để thực hiện các phép toán hội, giao, trừ trên tập hợp
- Đối với phép chia: sử dụng NOT EXISTS

> Vd 18: Tìm họ tên nhân viên được phân công thực hiện tất cả các đề án.

```sql
SELECT manv, honv, tenlot, tennv
FROM Nhanvien
WHERE NOT EXISTS
    (SELECT * FROM Dean WHERE NOT EXISTS
        (SELECT * FROM Phancong
         WHERE manv = ma_nvien AND Dean.mada = Phancong.mada))
```

> Vd 19: Tìm tên các đề án được phân công cho tất cả các nhân viên thuộc phòng số 5 thực hiện.

```sql
SELECT tenda
FROM Dean
WHERE NOT EXISTS
    (SELECT * FROM Nhanvien WHERE phg = 5 AND NOT EXISTS
        (SELECT * FROM Phancong
         WHERE manv = ma_nvien AND Dean.mada = Phancong.mada))
```

### 1.7 Hàm kết hợp, Top N, Gom nhóm

#### Hàm kết hợp

Cú pháp chung:

```text
TÊN HÀM(<tên thuộc tính>)
```

- `MIN`, `MAX`, `SUM`, `AVG`: tính giá trị nhỏ nhất, lớn nhất, tổng và trung bình
- `COUNT`:
  - `COUNT(*)`: đếm số dòng
  - `COUNT(<tên thuộc tính>)`: đếm số dòng thuộc tính có giá trị khác NULL
  - `COUNT(DISTINCT <tên thuộc tính>)`: đếm số dòng thuộc tính có giá trị khác nhau và khác NULL

> 20. Tính lương thấp nhất, cao nhất, trung bình và tổng lương của nhân viên

```sql
SELECT MIN(luong) AS CN, MAX(luong) AS TN, AVG(luong) AS TB, SUM(luong) AS TONG
FROM Nhanvien
```

> 21. Có tất cả bao nhiêu nhân viên

```sql
SELECT COUNT(*) AS SLNV
FROM Nhanvien
```

> 22. Có bao nhiêu nhân viên được quản lý trực tiếp bởi người khác

```sql
SELECT COUNT(ma_nql) AS SLNV
FROM Nhanvien
```

> 23. Có tất cả bao nhiêu người quản lý

```sql
SELECT COUNT(DISTINCT ma_nql) AS SLNQL
FROM Nhanvien
```

> 24. Có bao nhiêu nhân viên không có người quản lý trực tiếp

```sql
SELECT COUNT(*) AS SLNV
FROM Nhanvien
WHERE ma_nql IS NULL
```

(Lưu ý: để kiểm tra, có thể dùng kết hợp với `WHERE ma_nql IS NOT NULL`)

#### Top N

- Trả về N dòng kết quả đầu tiên của câu truy vấn
- Cú pháp: `TOP N` với N là số nguyên dương
- Nên sử dụng ORDER BY để sắp xếp kết quả

> Vd 25: Tìm lương cao nhất bằng TOP 1

```sql
SELECT TOP 1 luong AS CN
FROM Nhanvien
ORDER BY luong DESC
```

#### Gom nhóm

Cú pháp:

```text
SELECT <các thuộc tính>
FROM <các bảng>
[WHERE <các điều kiện>]
GROUP BY <các thuộc tính gom nhóm>
[HAVING <các điều kiện>]
```

Trong đó:

- Điều kiện ở WHERE thực hiện trước khi gom nhóm
- Điều kiện ở HAVING thực hiện sau khi gom nhóm
- Các thuộc tính sau GROUP BY dùng để gom nhóm và phải có đầy đủ các thuộc tính sau SELECT (trừ những thuộc tính nằm trong các hàm kết hợp)

> 26. Tìm số lượng nhân viên của từng phòng ban

```sql
SELECT PHG, COUNT(*) AS SLNV
FROM Nhanvien
GROUP BY PHG
```

> 27. Tìm số lượng nhân viên Nam (phai='Nam') của từng phòng ban

```sql
SELECT PHG, COUNT(*) AS SLNV
FROM Nhanvien
WHERE PHAI = 'Nam'
GROUP BY PHG
```

> 28. Tìm phòng ban có từ 2 nhân viên Nam (phai='Nam') trở lên

```sql
SELECT PHG, COUNT(*) AS SLNV
FROM Nhanvien
WHERE PHAI = 'Nam'
GROUP BY PHG
HAVING COUNT(*) >= 2
```

> 29. Tìm phòng ban có đông nhân viên nhất

```sql
SELECT TOP 1 PHG, COUNT(*) AS SLNV
FROM Nhanvien
GROUP BY PHG
ORDER BY COUNT(*) DESC
```

> 30. Tìm đề án có ít nhân viên Nữ (phai='Nu') tham gia nhất

```sql
SELECT MADA, COUNT(DISTINCT MA_NVIEN) AS SLNV
FROM Phancong
WHERE MA_NVIEN IN (SELECT MANV FROM Nhanvien WHERE PHAI = 'Nu')
GROUP BY MADA
```

> 31. Tìm 3 nhân viên thuộc phòng số 4 (phg=4) có lương thấp nhất

```sql
SELECT TOP 3 manv, honv + ' ' + tenlot + ' ' + tennv AS hoten, luong
FROM Nhanvien
WHERE phg = 4
ORDER BY luong ASC
```

---

## Phần 2. Xpath/Xquery

### 2.1 Giới thiệu

- Xpath và Xquery là hai ngôn ngữ có rất nhiều mặt giống nhau, hỗ trợ tìm kiếm thông tin trong tài liệu XML
- Có thể xem Xpath là tập hợp con của Xquery
- Xquery sử dụng Xpath như là một ngôn ngữ chính để định hướng tìm kiếm thay vì dùng đệ qui để duyệt cây

### 2.2 Xpath

Xpath (XML Path language):

- Là một chuẩn để xử lý tài liệu XML (cũng như SQL là một chuẩn để làm việc với CSDL)
- Dùng để xử lý nhiều kiểu truy vấn trong tài liệu XML và các biến thể của nó (như HTML)
- Là ngôn ngữ rất phổ biến
- Tiết kiệm thời gian trích xuất dữ liệu

#### Ví dụ 36: CSDL XML

```xml
<users>
  <user>
    <name>
      <first>Lola</first>
      <last>Solis</last>
    </name>
    <age>2</age>
  </user>
  <user>
    <name>
      <first>Nina</first>
      <last>Serafina</last>
    </name>
    <age>4</age>
    <visits>
      <first>2008-01-15</first>
      <last>2008-02-15</last>
    </visits>
  </user>
  <user>
    <name>
      <first>Tracy</first>
      <last>Keller</last>
    </name>
    <age>35</age>
  </user>
</users>
```

#### Ví dụ: tìm tên của người dùng dưới 18 tuổi

Đoạn Xpath sau tìm tên (last) của người dùng dưới 18 tuổi:

```xquery
/user[age lt 18]/name/last/text()
```

`: (Result`
`Solis`
`Serafina`
`:)`

- Nếu không dùng Xpath sẽ gặp chút khó khăn khi xử lý việc loại bỏ giá trị trong node visits

#### Nhận xét về Xpath

- Biểu thức Xpath ngắn gọn, rõ ràng
- Hiểu được các node phức tạp trong tài liệu XML và biết các mối quan hệ giữa chúng
- Hạn chế: không cung cấp cách chuyển đổi tập kết quả trả về (ví dụ không thể sắp kết quả hiển thị tăng dần theo tên)

### 2.3 XQuery

Xquery:

- Phức tạp hơn so với Xpath
- Sử dụng cú pháp pha trộn XML và Xpath
- Khắc phục được nhược điểm của Xpath:
  - Sắp xếp kết quả của câu truy vấn hoặc chuyển chúng thành HTML, CSV, SQL, XML,...
  - Cung cấp tính năng biểu thức FLWOR
  - Sử dụng hàm và đệ quy
  - Diễn tả các phép nối

#### Biểu thức FLWOR

- Biểu thức FLWOR dùng để liên kết các tiêu chí rút trích dữ liệu và chuyển đổi tập kết quả trả về của câu truy vấn
- FLWOR là viết tắt của các từ: **for**, **let**, **where**, **order by** và **return**
- Bắt đầu bằng một biểu thức `for` hoặc `let` và kết thúc bằng một biểu thức `return`

#### Ví dụ 1: Tìm tên người dùng dưới 18 tuổi, có sắp xếp tăng dần

```xquery
let $xml := _XML from Vidu36
for $user in $xml//user[age lt 18]
order by $user/name/last
return $user/name/last/text()
```

`: (Result`
`Serafina`
`Solis`
`:)`

#### Ví dụ 2: Kết quả trả về 1 đoạn HTML, danh sách có đánh số thứ tự

```xquery
let $xml := _XML from Vidu36
return
<ol>{
  for $user in $xml//user[age lt 18]
  order by $user/name/last
  return <li>{$user/name/last/text()}</li>
}</ol>
```

`: (Result`
`<ol><li>Serafina</li><li>Solis</li></ol>`
`:)`

#### Sử dụng hàm và đệ quy

- Xquery cung cấp các hàm, các phép toán được xây dựng sẵn và cho phép định nghĩa các hàm riêng
- Xquery cũng hỗ trợ đệ quy: tiện lợi khi làm việc với XML (có thể chứa các node lồng nhau tùy ý)

#### Ví dụ 4: Định nghĩa hàm transform-names thay đổi tên các node

Phần 1 - khai báo hàm (đệ quy, thay dấu `_` thành `-`):

```xquery
(: Part 1 :)
define function transform-names($node as node()) as node() {
  element { replace(name($node), "_", "-") } {
    $node/text(), for $subnode in $node/* return transform-names($subnode)
  }
}
```

Phần 2 - dữ liệu mẫu và gọi hàm:

```xquery
(: Part 2 :)
let $xml :=
  <item>
    <item_type>book</item_type>
    <contributors>
      <author>
        <first_name>Charles</first_name>
        <last_name>Edward</last_name>
        <home_address>
          <home_street>206 S. Solomon St.</home_street>
          <home_city>New Orleans</home_city>
          <home_state>LA</home_state>
          <home_zip>70119</home_zip>
        </home_address>
      </author>
      <artist>
        <last_name>Salinas</last_name>
      </artist>
    </contributors>
  </item>
return transform-names($xml)
```

Kết quả (các node `_` được đổi thành `-`):

```xml
<item>
  <item-type>book</item-type>
  <contributors>
    <author>
      <first-name>Charles</first-name>
      <last-name>Edward</last-name>
      <home-address>
        <home-street>206 S. Solomon St.</home-street>
        <home-city>New Orleans</home-city>
        <home-state>LA</home-state>
        <home-zip>70119</home-zip>
      </home-address>
    </author>
    <artist>
      <last-name>Salinas</last-name>
    </artist>
  </contributors>
</item>
```

---

## Phần 3. Các dạng truy vấn Select thường gặp (CSDL Quản lý bán hàng)

### Lược đồ CSDL Quản lý bán hàng

```text
KHACHHANG (MAKH, HOTEN, DCHI, SODT, NGSINH, DOANHSO, NGDK)
NHANVIEN (MANV, HOTEN, NGVL, SODT)
SANPHAM (MASP, TENSP, DVT, NUOCSX, GIA)
HOADON (SOHD, NGHD, MAKH, MANV, TRIGIA)
CTHD (SOHD, MASP, SL)
```

### Cú pháp chung của câu truy vấn SELECT

```text
SELECT <cột 1>, <cột 2>, ....
FROM <tên bảng>
WHERE <điều kiện>
ORDER BY <tên cột> ASC | DESC
GROUP BY <tên cột 1>, <tên cột 2>, ....
HAVING <điều kiện>
```

Lưu ý:

- Mệnh đề HAVING sử dụng cho các hàm gom nhóm
- ASC: sắp xếp tăng dần; DESC: sắp xếp giảm dần

### Dạng 1: Truy vấn lấy dữ liệu tất cả

```text
SELECT * FROM <tên bảng>
```

hoặc

```text
SELECT <danh sách cột> FROM <tên bảng>
```

Ví dụ:

```sql
SELECT * FROM KHACHHANG
SELECT MAKH, HOTEN, DCHI FROM KHACHHANG
```

### Dạng 2: Truy vấn dữ liệu có điều kiện

```text
SELECT <danh sách cột> FROM <tên bảng>
WHERE <điều kiện>
```

Ví dụ: Lấy thông tin MAKH, HOTEN, DCHI của khách hàng có doanh số trên 10000

```sql
SELECT MAKH, HOTEN, DCHI FROM KHACHHANG
WHERE DOANHSO > 10000
```

### Dạng 3: Truy vấn dữ liệu có kết bảng

```text
SELECT <danh sách cột>
FROM <tên bảng 1>
INNER JOIN <tên bảng 2> ON <tên bảng 1>.<mã khóa ngoại> = <tên bảng 2>.<mã khóa chính>
[WHERE <điều kiện>]
```

Các phép kết:

- `INNER JOIN`: kết bằng
- `LEFT OUTER JOIN`: kết mở rộng về bên trái
- `RIGHT OUTER JOIN`: kết mở rộng về bên phải

Ví dụ: Tìm danh sách khách hàng đã mua hàng vào ngày 16/7/2019

```sql
SELECT MAKH, HOTEN
FROM HOADON INNER JOIN KHACHHANG ON KHACHHANG.MAKH = HOADON.MAKH
WHERE NGHD = '16/7/2019'
```

### Dạng 4: Truy vấn dữ liệu có sắp xếp

```text
SELECT <danh sách tên cột> FROM <tên bảng>
[WHERE <điều kiện>]
ORDER BY <danh sách cột cần sắp xếp> ASC | DESC
```

Ví dụ: Sắp xếp khách hàng theo ngày sinh giảm dần

```sql
SELECT MAKH, HOTEN, NGSINH FROM KHACHHANG
ORDER BY NGSINH DESC
```

### Dạng 5: Truy vấn sử dụng các hàm gom nhóm

```text
SELECT <các hàm gom nhóm> FROM <tên bảng>
[WHERE <điều kiện>]
GROUP BY <tên cột 1>, <tên cột 2>, ...
```

Các hàm gom nhóm: `COUNT()`, `AVG()`, `MAX()`, `MIN()`, `SUM()`.

Lưu ý: Các thuộc tính trong mệnh đề SELECT (trừ các hàm kết hợp) phải xuất hiện trong mệnh đề GROUP BY.

Ví dụ: Tính giá trị trung bình doanh số theo từng MAKH đối với khách hàng có doanh số trên 10000

```sql
SELECT MAKH, AVG(DOANHSO) FROM KHACHHANG
WHERE DOANHSO > 10000
GROUP BY MAKH
```

### Dạng 6: Truy vấn sử dụng hội - giao - trừ

```text
SELECT <danh sách cột 1> FROM <tên bảng> [WHERE <điều kiện 1>]
UNION (hội) | INTERSECT (giao) | EXCEPT (trừ)
SELECT <danh sách cột 2> FROM <tên bảng> [WHERE <điều kiện 2>]
```

Lưu ý: Để sử dụng các phép hội giao trừ thì 2 quan hệ phải khả hợp, tức `<danh sách cột 1> = <danh sách cột 2>`.

VD1: Tìm khách hàng mua hóa đơn HD01 hoặc HD02

```sql
SELECT MAKH, HOTEN FROM KHACHHANG INNER JOIN HOADON ON KHACHHANG.MAKH = HOADON.MAKH
WHERE MAHD = 'HD01'
UNION
SELECT MAKH, HOTEN FROM KHACHHANG INNER JOIN HOADON ON KHACHHANG.MAKH = HOADON.MAKH
WHERE MAHD = 'HD02'
```

VD2: Tìm khách hàng mua cùng lúc hóa đơn HD01 và HD02

```sql
SELECT MAKH, HOTEN FROM KHACHHANG INNER JOIN HOADON ON KHACHHANG.MAKH = HOADON.MAKH
WHERE MAHD = 'HD01'
INTERSECT
SELECT MAKH, HOTEN FROM KHACHHANG INNER JOIN HOADON ON KHACHHANG.MAKH = HOADON.MAKH
WHERE MAHD = 'HD02'
```

VD3: Tìm khách hàng không mua hóa đơn nào

```sql
SELECT MAKH, HOTEN FROM KHACHHANG
EXCEPT
SELECT MAKH, HOTEN FROM KHACHHANG INNER JOIN HOADON ON KHACHHANG.MAKH = HOADON.MAKH
```

### Dạng 7: Truy vấn lồng

```text
SELECT <danh sách cột> FROM <tên bảng>
WHERE <so sánh tập hợp> (
    SELECT <danh sách cột> FROM <tên bảng>
    WHERE <điều kiện>
)
```

`<so sánh tập hợp>`: ALL, IN, NOT IN, ANY, EXISTS, NOT EXISTS.

Ví dụ: Tìm thông tin mã hóa đơn có trị giá cao nhất

```sql
SELECT SOHD FROM HOADON
WHERE TRIGIA = (
    SELECT MAX(TRIGIA) FROM HOADON
)
```

### Dạng 8: Truy vấn lồng tương quan

```text
SELECT <danh sách cột> FROM <tên bảng> AS OB1
WHERE <so sánh tập hợp> (
    SELECT <danh sách cột> FROM <tên bảng> AS OB2
    WHERE OB1.<tên cột> = OB2.<tên cột>
)
```

`<so sánh tập hợp>`: ALL, IN, NOT IN, ANY, EXISTS, NOT EXISTS.

Ví dụ: Tìm tất cả các nước sản xuất có giá cao nhất của từng sản phẩm

```sql
SELECT MASP, NUOCSX, GIA
FROM SANPHAM AS SP1
WHERE GIA = (
    SELECT MAX(GIA) FROM SANPHAM AS SP2
    WHERE SP1.MASP = SP2.MASP
)
```

### Dạng 9: Truy vấn dùng bảng "con" (inner aggregate)

```text
SELECT <danh sách cột 1>
FROM (
    SELECT <danh sách cột 2> FROM <tên bảng>
    WHERE <điều kiện>
) AS <tên bảng con>
```

Lưu ý: `<danh sách cột 1>` phụ thuộc vào `<danh sách cột 2>` trả về từ câu truy vấn con (subquery).

Ví dụ: Tìm khách hàng có số lần mua hàng nhiều nhất

```sql
SELECT MAKH FROM HOADON
GROUP BY MAKH
HAVING COUNT(SOHD) = (
    SELECT MAX(SL_HD)
    FROM (
        SELECT MAKH, COUNT(SOHD) AS SL_HD
        FROM HOADON
        GROUP BY MAKH
    ) AS T
)
```

Lưu ý: Không thể sử dụng dạng `COUNT(MAX(SOHD))` trong SQL Server.

### Dạng 10: Phép chia

Tìm `<đối tượng 1>` đã ... tất cả `<đối tượng 2>`.

Cần xác định:

- Đối tượng 1 (MaDT1, ...)
- Đối tượng 2 (MaDT2, ...)
- Quan hệ giữa Đối tượng 1 và Đối tượng 2 (MaDT1, MaDT2, ...)

Cú pháp tổng quát (dùng NOT EXISTS kép):

```text
SELECT <danh sách cột>
FROM <tên bảng đối tượng 1> AS OB1
WHERE NOT EXISTS (
    SELECT <danh sách cột> FROM <tên bảng đối tượng 2> AS OB2
    WHERE ... AND NOT EXISTS (
        SELECT * FROM <tên bảng quan hệ đối tượng 1 và 2> AS OB3
        WHERE OB2.<khóa chính> = OB3.<khóa ngoại>
          AND OB3.<khóa ngoại> = OB1.<khóa chính>
    )
)
```

Ví dụ: Tìm hóa đơn đã mua tất cả sản phẩm xuất xứ Thái Lan

- Đối tượng 1: HOADON (SOHD, NGHD, ...)
- Đối tượng 2: SANPHAM (MASP, TENSP, XUATXU)
- Quan hệ giữa 2 đối tượng: CTHD (MASP, TENSP)

```sql
SELECT SOHD FROM HOADON AS T1
WHERE NOT EXISTS (
    SELECT MASP FROM SANPHAM AS T2
    WHERE XUATXU = 'Thái Lan' AND NOT EXISTS (
        SELECT MASP, TENSP FROM CTHD AS T3
        WHERE T2.MASP = T3.MASP AND T1.SOHD = T3.SOHD
    )
)
```

---

## Tổng kết

1. Để truy vấn dữ liệu trong CSDL quan hệ, ta dùng ngôn ngữ SQL
2. SQL có 3 nhóm lệnh chính: DDL, DML và DCL
3. Các truy vấn nâng cao trên SQL: kết (nhiều bảng), gom nhóm, truy vấn lồng
4. Xpath/Xquery là ngôn ngữ dùng để truy vấn CSDL XML
5. Xquery là phiên bản mở rộng của Xpath, hỗ trợ các hàm, đệ quy,... mà bản thân Xpath không làm được

## Tài liệu tham khảo

1. Nguyễn Gia Tuấn Anh, Trương Châu Long, Bài tập và bài giải SQL Server, NXB Thanh niên (2005)
2. Đỗ Phúc, Nguyễn Đăng Tỵ, Cơ sở dữ liệu, NXB Đại học quốc gia TPHCM (2010)
3. Nguyễn Gia Tuấn Anh, Mai Văn Cường, Bùi Danh Hường, Cơ sở dữ liệu nâng cao, NXB Đại học quốc gia TPHCM (2019)
4. Itzik Ben-Gan, Microsoft SQL Server 2012 - TSQL Fundamentals