# Chương 10 - Mô hình CSDL tiên tiến: CSDL hướng đối tượng

## 1. Đặt vấn đề

### 1.1. Ưu/nhược điểm của CSDL quan hệ

| Ưu điểm | Nhược điểm |
|---|---|
| Nền tảng toán học vững chắc | Ngôn ngữ truy vấn thiếu: rẽ nhánh, vòng lặp |
| Nhiều hệ QTCSDL hỗ trợ | Không hỗ trợ các kiểu dữ liệu phức tạp: cấu trúc, tập hợp, ảnh, tri thức |
| Mô hình dữ liệu, khái niệm đơn giản, dễ hiểu | Biểu diễn dữ liệu trái với sự biểu diễn của thực tiễn |
| Phù hợp khá nhiều các ứng dụng | |
| Ngôn ngữ truy vấn SQL dễ hiểu, đáp ứng nhu cầu người dùng | |
| Có thể phục hồi dữ liệu khi gặp sự cố | |
| Dựa trên nền tảng dạng chuẩn | |

### 1.2. Hướng giải quyết

- Mở rộng CSDL quan hệ:
  - Mô hình ERD
  - Hình thành khái niệm: Tổng Quát Hóa và Chuyên Biệt Hóa
- Đề xuất mô hình mới:
  - Bỏ dạng chuẩn 1
  - Biểu diễn các đối tượng phức tạp

Hai trường phái:
- TP1: NNLTHDT tạo tiền đề để hiệu chỉnh, xây dựng CSDL hướng đối tượng
- TP2: CSDL hướng đối tượng tạo tiền đề để xây dựng NNLTHDT
- Kết luận: TP2 có vẻ thắng thế

## 2. Các tính chất của CSDL hướng đối tượng

### 2.1. Các khái niệm

- **Đối tượng (Object)**: là sự kết hợp giữa dữ liệu và các hành vi mô tả cho một thực thể.
- **Tính chất (Property)**: đặc trưng của một đối tượng được chỉ định bằng một tên, có thể ứng với một thuộc tính, một hàm hay một đối tượng con thành phần.

Ví dụ về tính chất:
- Thuộc tính đơn: tên của một người
- Hàm: Hàm tuổi (của một người)
- Thuộc tính kép: các con của một người

### 2.2. Đối tượng và phương thức

**Đối tượng (object)**
- Các đối tượng có cùng tính chất được đặc trưng bởi một cấu trúc và tập các phép toán tác dụng lên các đối tượng của lớp bằng cách che dấu cấu trúc.
- Việc đặc tả tiến triển của các lớp đối tượng làm thành một CSDL hướng đối tượng, cho phép mô hình hóa hành vi chung của các đối tượng một cách đơn thể và mở rộng được.

**Phương thức (method)**
- Thao tác liên kết với một lớp, xử lý hay đưa trả lại trạng thái của một đối tượng hay một phần của đối tượng thuộc lớp.
- Một đối tượng được thao tác bởi phương thức của lớp và được nhìn qua nguyên lý bao gói.
- Phương thức có thể áp dụng cho nhiều đối tượng thuộc các lớp khác nhau (đa lớp) → dùng để mô hình hóa các mối liên kết giữa các lớp.

### 2.3. Các tính chất của hướng đối tượng

- **Khái quát hóa**: liên kết phân cấp giữa hai lớp xác định rằng các đối tượng của lớp trên tổng quát hơn các đối tượng của lớp dưới; các đối tượng của lớp dưới có các tính chất đầy đủ và tinh tế hơn.
- **Tính kế thừa**: sự truyền tính chất của lớp cha tới lớp con. Mọi phần tử của lớp con kế thừa các tính chất của lớp trên. Một số tính chất của lớp con có thể được làm tinh tế hơn (định nghĩa lại).
- **Tính kế thừa bội**: cho phép một lớp có nhiều lớp trên trực tiếp. Lớp con kế thừa các tính chất và phương pháp của các lớp trên. Có thể xảy ra và cần giải quyết những xung đột về tên các tính chất hay phương pháp.

### 2.4. Các loại thừa kế

Có 2 loại thừa kế:
- **Thừa kế ISA**: kiểu con thừa kế từ Interface → chỉ thừa kế hành vi.
- **Thừa kế EXTENDS**: kiểu con thừa kế từ Class → cho thừa kế cả hành vi và đặc trưng.

### 2.5. Class diagram (sơ đồ lớp)

- Các mô hình đối tượng thường phân biệt các tính chất được phân chia bởi nhiều lớp và hợp chúng trong các mối liên kết.
- Các dạng của mối liên kết:
  - Tương tự các liên kết trong ERD
  - Các liên kết khác

### 2.6. Các kiểu dữ liệu mới

| Kiểu dữ liệu | Mô tả |
|---|---|
| Bộ (tuple) | Cho phép gộp các thuộc tính (tích Đề-các) |
| Tập hợp (set) | Định nghĩa các đối tượng không sắp thứ tự, không chứa phần tử giống nhau |
| Túi (bag) | Các tập không sắp thứ tự, có các phần tử giống nhau |
| Danh sách (list) | Định nghĩa các đối tượng có thứ tự, được phép có các phần tử giống nhau |
| Bảng (table) | Các thực thể có thứ tự và có chỉ số |

### 2.7. Các ứng dụng của CSDL hướng đối tượng

- Các ứng dụng thiết kế công nghệ: CAD (Computer-Aided Design), CAM (Computer-Aided Manufacturing), CIM (Computer-Integrated Manufacturing)
- Các ứng dụng đa phương tiện (Multimedia)
- Các cơ sở tri thức
- Các ứng dụng đòi hỏi xử lý phân tán và tương tranh
- Các phần mềm nhúng

## 3. Chuyển đổi từ CSDL quan hệ sang CSDL hướng đối tượng

### 3.1. Ví dụ về khai báo lớp trong CSDL hướng đối tượng

**Ví dụ 1: Lớp CuaHang**

```
Class CuaHang
{
  attribute  String(30) tenGoi;
  attribute  struct diaChi{
    char(3) soPho,
    char(20) tenPho,
    char(15) tinhThanh
  };
  void  addSale(){…}
};
```

**Ví dụ 2: Lớp PhienBanHang và HBH (quan hệ hai chiều)**

```
Class PhienBanHang
{
  attribute  Date  ngayBan;
  attribute  Time  gioBan;
  relationship HBH banHang
    inverse ghiNhan::HBH;
  Boolean  becomeComplete(){…}
  void  makeLineItem()
  makePayment(){…}
  Number  total(){…}
};

Class HBH
{
  attribute  String(25) hangTruong;
  attribute  String(15) tenTruong;
  relationship set<PhienBanHang> ghiNhan
    inverse banHang::PhienBanHang;
  void  HBH();
  void  enterItems(){…}
  void  endSale(){…}
};
```

**Ví dụ 3: Lớp PhienBanHang chứa danh sách DongBanHang**

```
Class PhienBanHang
{
  attribute Date ngayBan;
  attribute Time gioBan;
  attribute List<DongBanHang> gomCo;
  Boolean becomeComplete(){…}
  void makeLineItem()
  void makePayment(){…}
  Number total(){…}
};

Class DongBanHang
{
  attribute Integer soLuong;
  Number subtotal(){…}
};
```

**Ví dụ 4: Kế thừa với extends và extent**

```
Class ThanhToanTM extends ThanhToan
(extent ThanhToanTM)
{
  …
};

Class ThanhToanThe extends ThanhToan
(extent ThanhToanThe)
{
  …
};
```

### 3.2. So sánh hai hệ quản trị

- (Slide trình bày bảng so sánh chi tiết giữa hệ QTCSDL quan hệ và hệ QTCSDL hướng đối tượng.)

### 3.3. Các bước chuyển từ mô hình quan hệ sang hướng đối tượng

- **Bước 1**: Xác định đối tượng (thực thể) từ mô hình quan hệ.
- **Bước 2**: Xác định quan hệ giữa các đối tượng.
- **Bước 3**: Xây dựng mô hình hướng đối tượng:
  - Biểu diễn cho 1 đối tượng: dùng kiểu tuple (bộ)
  - Biểu diễn cho nhiều đối tượng: dùng list (danh sách) hoặc set (tập hợp)
    - list: có thứ tự, phần tử trùng nhau
    - set: không thứ tự, không trùng nhau
  - Biểu diễn các đối tượng phức tạp: kết hợp set và tuple

### 3.4. Ví dụ chuyển CSDL quan hệ sang hướng đối tượng

**Mô hình quan hệ ban đầu:**

```
Tacgia  (#mstg, tentg, sdt, email)
Sach    (#mssach, tensach, sotrang, sotien, msnxb)
Nxb     (#msnxb, tennxb, sdt-xb, email-xb)
Tg-Sach (#mstg, #mssach, nam-xb)
```

Dữ liệu mẫu:

| Tacgia | | | |
|---|---|---|---|
| #mstg | tentg | sdt | email |
| TG01 | Nguyen A | 098731 | a@gmail.com |
| TG02 | Nguyen B | 098731 | b@gmail.com |

| Sach | | | | |
|---|---|---|---|---|
| #mssach | tensach | sotrang | sotien | msnxb |
| S01 | ABC | 6 | 100000 | NXB01 |

| Nxb | | | |
|---|---|---|---|
| #msnxb | tennxb | sdt-xb | email-xb |
| NXB01 | NXB-DHQG | 0844643 | nxb@gmail.com |

| Tg-Sach | | |
|---|---|---|
| #mstg | #mssach | nam-xb |
| TG01 | S01 | 2019 |
| TG02 | S01 | 2020 |

**Phân tích:**
- Số thực thể là 3: tác giả, sách, Nxb
- Nxb – sách: quan hệ 1 – n
- Tác giả – sách: quan hệ n – n

**Mô hình hướng đối tượng:**

```
TacgiaObj(mstg, tentg, sdt, email, set(SachObj, nam-xb))
SachObj(mssach, tensach, sotrang, sotien, tuple(NxbObj), set(TacgiaObj, nam-xb))
NxbObj (msnxb, tennxb, sdt-xb, email-xb, set(SachObj))
```

**Mô hình + dữ liệu:**

```
TacgiaObj(mstg, tentg, sdt, email, set(SachObj), nam-xb)
TG01  Nguyen A  098731  a@gmail.com  {(S01, ABC, 6, 100000, DHQG), 2019}
TG02  Nguyen B  098731  b@gmail.com  {(S01, ABC, 6, 100000, DHQG), 2020}

SachObj (mssach, tensach, sotrang, sotien, tuple(NxbObj), set(TacgiaObj, nam-xb))
S01  ABC  6  100000  (NXB01, NXB-DHQG, ...)  [{Obj(TG01), 2019}, {Obj(TG02), 2020}]

NxbObj (msnxb, tennxb, sdt-xb, email-xb, set(SachObj))
NXB01  NXB-DHQG  0844643  nxb@gmail.com  {(S01, ABC, 6, 100000)}
```

## 4. Tài liệu tham khảo

1. Nguyễn Gia Tuấn Anh, Trương Châu Long, *Bài tập và bài giải SQL Server*, NXB Thanh Niên (2005).
2. Đỗ Phúc, Nguyễn Đăng Tỵ, *Cơ sở dữ liệu*, NXB Đại học Quốc gia TPHCM (2010).
3. Nguyễn Gia Tuấn Anh, Mai Văn Cường, Bùi Danh Hường, *Cơ sở dữ liệu nâng cao*, NXB Đại học Quốc gia TPHCM (2019).
4. Itzik Ben-Gan, *Microsoft SQL Server 2012 - T-SQL Fundamentals*.

## 5. Bài tập

**Bài 1.** Chuyển mô hình sau sang hướng đối tượng:

```
Khach     (#msk, tenk, sdt, email)
Nhanvien  (#msnv, tennv, sdt-nv, email-nv)
Mathang   (#msmh, tenmh)
Hoadon    (#mshd, ngayhiod, tongtien, mskh, msnv)
CTHD      (#mshd, #msmh, SL, DG)
```

**Bài 2.** Thực nghiệm so sánh các thao tác: insert, update, delete, select và tính thời gian thực thi cho bài 1, bài 2.

**Bài 3.** Tại sao CSDL đa phương tiện (CSDLĐPT) thích hợp với CSDL hướng đối tượng? Cho ví dụ minh họa cho câu trả lời.

## 6. Ghi nhớ nhanh

- Đối tượng (object) = dữ liệu + hành vi
- CSDL hướng đối tượng mở rộng khái niệm của CSDL quan hệ: bỏ dạng chuẩn 1, biểu diễn đối tượng phức tạp
- 3 tính chất chính: khái quát hóa, kế thừa, kế thừa bội
- Thừa kế ISA (interface → hành vi) và thừa kế EXTENDS (class → hành vi + đặc trưng)
- Các kiểu dữ liệu mới: tuple, set, bag, list, table
- Chuyển đổi quan hệ → hướng đối tượng trong 3 bước: xác định đối tượng → xác định quan hệ → xây dựng mô hình OO