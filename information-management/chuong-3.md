# Chương 2 - Tổ chức thông tin trên máy tính: Biểu diễn dữ liệu mức logic

## Nội dung

1. Mô hình dữ liệu phẳng
2. Mô hình dữ liệu có cấu trúc
3. Chỉ mục và Khoá
4. Mô hình quan hệ
5. Ràng buộc toàn vẹn
6. Mô hình dữ liệu XML

---

## 1. Mô hình dữ liệu phẳng

### Khái niệm

- Một cơ sở dữ liệu phẳng là một hệ thống cơ sở dữ liệu đơn giản, trong đó mỗi cơ sở dữ liệu được biểu diễn như là **một bảng duy nhất**.
- Một số nhà phát triển ứng dụng vẫn sử dụng các tập tin phẳng để giảm chi phí và tính phức tạp của việc tích hợp cơ sở dữ liệu quan hệ.
- Cơ sở dữ liệu phẳng đôi khi cũng được gọi là **cơ sở dữ liệu tệp phẳng** (flat-file databases).

### Ví dụ

- Thông tin các lớp học và gia sư cho học sinh
- Bảng điểm sinh viên
- Thông tin nhân viên
- Thông tin sinh viên dưới dạng JSON

### Ưu và nhược điểm của CSDL phẳng

| ƯU ĐIỂM | NHƯỢC ĐIỂM |
|---|---|
| Nhiều phương thức truy xuất khác nhau: tuần tự, ngẫu nhiên, chỉ mục | Dữ liệu trùng lặp |
| | Cần chi phí để xử lý dữ liệu đồng nhất và điều khiển việc truy xuất |
| | Bảo mật kém |
| | Rất khó để điều khiển việc nhiều người dùng cùng truy cập một lúc |

---

## 2. Mô hình dữ liệu có cấu trúc

### 2.1 Mô hình phân cấp (Hierarchical model)

- Đưa ra vào những năm 60.
- Dữ liệu được tổ chức thành **cấu trúc cây** (tree).
  - Các nút (node) là tập các thực thể.
  - Các cành là các mối quan hệ giữa hai nút theo mối quan hệ nhất định.
- Là mô hình dữ liệu trong đó các bản ghi được sắp xếp theo cấu trúc top-down (tree).
- **Một con chỉ có một cha** - chỉ có một đường truy nhập tới dữ liệu đó.

#### Ví dụ

- Hệ thống máy tính (cơ bản và chi tiết)
- Sơ đồ cơ cấu của tổ chức
- Sơ đồ tổ chức của UIT

#### Ưu và nhược điểm

| ƯU ĐIỂM | NHƯỢC ĐIỂM |
|---|---|
| Đơn giản về khái niệm: nhóm dữ liệu có thể được liên quan đến nhau, dữ liệu liên quan có thể được xem với nhau | Biểu diễn hạn chế về mối quan hệ dữ liệu: không cho phép quan hệ (M:N) |
| Tập trung dữ liệu | Thực hiện phức tạp: cần kiến thức chuyên sâu về lưu trữ dữ liệu vật lý |
| Giảm sự dư thừa và phát huy tính nhất quán | Sự phụ thuộc cấu trúc: truy cập dữ liệu đòi hỏi đường dẫn lưu trữ vật lý |

### 2.2 Mô hình mạng (Network model)

- Được đưa vào cuối những năm 60.
- Dữ liệu được tổ chức thành một **đồ thị có hướng**.
  - Các đỉnh là các thực thể.
  - Các cung là quan hệ giữa hai đỉnh; một kiểu bản ghi có thể liên kết với nhiều kiểu bản ghi khác.
- **Một con có thể có nhiều cha** - có nhiều đường truy nhập đến một dữ liệu cho trước.

#### Ví dụ

- Hệ thống cửa hàng
- Mạng xã hội
- Cảnh báo và phát hiện gian lận tài chính
- Mạng viễn thông
- Mạng doanh nghiệp

#### Ưu và nhược điểm

| ƯU ĐIỂM | NHƯỢC ĐIỂM |
|---|---|
| Cho phép nhiều loại quan hệ dữ liệu | Hệ thống phức tạp |
| Hiệu quả và truy cập dữ liệu linh hoạt | Đòi hỏi sự quen thuộc với cấu trúc nội bộ để truy cập dữ liệu |
| Phù hợp với các tiêu chuẩn | Thay đổi cấu trúc nhỏ đòi hỏi thay đổi chương trình |
| Tăng cường quản trị cơ sở dữ liệu | |

---

## 3. Chỉ mục và Khoá

### 3.1 Chỉ mục (Index)

- Chỉ mục (index) là **bảng tra cứu đặc biệt** mà Database Search Engine có thể sử dụng để tăng nhanh thời gian và hiệu suất thu thập dữ liệu.

**Phân loại:**

- Chỉ mục trên cột là khóa
- Chỉ mục trên cột không là khóa
- B-Tree

### 3.2 Chỉ mục trên cột là khoá

- Tập tin chỉ mục là một FILE với các mẫu tin có **2 cột: khóa và địa chỉ block**, đã được sắp trên thuộc tính khóa.
- Địa chỉ khóa cho biết vị trí của block chứa mẫu tin trên đĩa.
- Tập tin chỉ mục có kích thước nhỏ hơn nhiều so với FILE dữ liệu chính, vì vậy tập tin chỉ mục sẽ được đọc vào bộ nhớ chính khi chương trình CSDL khởi động.
- Vì tập tin chỉ mục đã được sắp nên nó dùng **thuật toán tìm kiếm nhị phân** khi tìm kiếm.
- Nếu 1 mẫu tin trong tập tin chỉ mục tương ứng 1 mẫu tin trong File dữ liệu chính: **chỉ mục dày** (dense index).
- Nếu 1 mẫu tin trong tập tin chỉ mục tương ứng nhiều mẫu tin trong File dữ liệu chính: **chỉ mục thưa** (nondense index).

### 3.3 Chỉ mục trên cột không là khoá

- Nếu các mẫu tin đã được sắp trên một cột không phải khóa (key) và có giá trị lặp lại, cột đó được gọi là cột Clustering (clustering field); trường hợp này tạo ra file chỉ mục gọi là **Clustering Index**.
- Clustering Index có 2 cột:
  - Cột 1 giống với cột clustering của file dữ liệu chính.
  - Cột 2 chứa con trỏ khối chỉ tới đầu khối có chứa dữ liệu cột clustering.
- Giá trị trên cột 1 trong Clustering Index là duy nhất. Nó là một ví dụ của **tập tin chỉ mục thưa**.

### 3.4 B-Tree

**Định nghĩa:** B-Tree là cây tìm kiếm nhiều nhánh thỏa các điều kiện sau:

- Tất cả các node lá có cùng độ cao.
- Tất cả các node trung gian có nhiều nhất m cây con và có ít nhất m/2 cây con khác rỗng.
- Node gốc có thể có m cây con hay 2 cây con không phải là lá.
- Các giá trị khóa trên các node đã được sắp (tăng dần).
- Gọi k là số cây con của một node thì số khóa nằm trên node là k-1.
- Các node có cùng cấu trúc dữ liệu.
- Mỗi node có cấu trúc: `<P1, <K1, Q1>, P2, <K2, Q2>, ...>`

Trong đó:

- `Pi` là con trỏ đến một node khác trong cây
- `Ki` là khóa
- `Qi` là con trỏ dữ liệu, trỏ đến block trên FILE dữ liệu chứa mẫu tin có khóa là Ki

**Đánh giá về B-Tree:**

- Vì có nhiều khóa trên một node và nhiều node trên cùng độ cao nên việc tìm kiếm trên B-Tree khá tốt.
- Càng nhiều mẫu tin trên một node thì cây càng có độ cao nhỏ, nhằm cải tiến tốc độ truy xuất đĩa.
- Tổ chức theo B-Tree không những nhanh hơn so với file có thứ tự mà việc thêm, xóa cũng hiệu quả hơn.

---

## 4. Mô hình quan hệ

### 4.1 Giới thiệu

- Được E.F. Codd đưa vào đầu những năm 70.
- Dựa trên **lý thuyết tập hợp** và **đại số quan hệ**.
- Vì tính chất chặt chẽ của toán học về lý thuyết tập hợp nên mô hình này mô tả dữ liệu một cách rõ ràng, mềm dẻo và là mô hình thông dụng.
- Nhiều hệ QTCSDL đều tổ chức dữ liệu theo mô hình dữ liệu quan hệ.
- Trong đó dữ liệu được tổ chức dưới dạng bảng; các phép toán thao tác trên dữ liệu dựa trên lý thuyết tập hợp của toán học.

### 4.2 Các thành phần chính của mô hình quan hệ

- **Quan hệ** - ứng với bảng.
- **Bộ** - ứng với dòng.
- **Thuộc tính** - ứng với cột.
- Tân từ.
- Thể hiện của một quan hệ.
- Lược đồ quan hệ.

### 4.3 Quan hệ

Các thông tin lưu trữ trong CSDL được tổ chức thành bảng (table) gọi là **quan hệ**.

Ví dụ quan hệ `NHANVIEN`:

| MaNV | HoNV | TenNV | Email | SDT | Phong | Luong |
|---|---|---|---|---|---|---|
| NV01 | Nguyen Van | A | email1@domain.com | 0123456789 | 1 | 20000 |
| NV02 | Tran Thanh | B | email2@domain.com | 0987643210 | 1 | 22000 |
| NV03 | Tran Thi | C | email3@domain.org | 0388888888 | 3 | 15000 |

### 4.4 Bộ (Tuple)

- Bộ là các **dòng của quan hệ** (trừ dòng tiêu đề: tên của các thuộc tính).
- Thể hiện dữ liệu cụ thể của các thuộc tính trong quan hệ.

Ví dụ: Mỗi dòng `NV01`, `NV02`, `NV03` trong bảng trên là một bộ.

### 4.5 Thuộc tính (Attribute)

- **Tên gọi**: dãy ký tự (gợi nhớ).
- **Kiểu dữ liệu**: Số, Chuỗi, Thời gian, Luận lý, OLE.
- **Miền giá trị**: tập giá trị mà thuộc tính có thể nhận. Ký hiệu miền giá trị của thuộc tính A là `Dom(A)`.
- Một thuộc tính không có giá trị hoặc chưa xác định được giá trị -> giá trị **Null**.
- Tên các cột của quan hệ mô tả ý nghĩa cho các giá trị tại cột đó; tất cả dữ liệu trong cùng một cột đều có cùng kiểu dữ liệu.

### 4.6 Thể hiện của quan hệ

- Thể hiện của một quan hệ là **tập hợp các bộ giá trị của quan hệ tại một thời điểm nhất định**.
- Ví dụ: Thể hiện cho quan hệ Nhân viên tại thời điểm t gồm các bộ (dòng) như bảng `NHANVIEN` ở trên.

### 4.7 Lược đồ quan hệ

- Cấu trúc của một quan hệ là **tập thuộc tính hình thành nên quan hệ**.
- Một lược đồ quan hệ gồm:
  - Một tập thuộc tính của quan hệ.
  - Một mô tả để xác định ý nghĩa và mối liên hệ giữa các thuộc tính.
- Lược đồ quan hệ được đặc trưng bởi:
  - Một tên phân biệt.
  - Một tập hợp hữu hạn các thuộc tính (A1, ..., An).
- **Ký hiệu:** `Q(A1, A2, ..., An)`.

**Ví dụ: quan hệ nhân viên**

- Tên quan hệ: `NhanVien`.
- Các thuộc tính: `MaNV, HoNV, TenNV, Email, SoDT, Phong, Luong`.
- Ký hiệu:

```
NhanVien(MaNV, HoNV, TenNV, Email, SoDT, Phong, Luong)
```

### 4.8 Tân từ

- **Định nghĩa:** Tân từ là một quy tắc dùng để mô tả một quan hệ.
- **Ký hiệu:** `||Q||`.

**Ví dụ:**

```
NhanVien(MaNV, HoNV, TenNV, Email, SoDT, Phong, Luong)
||NhanVien||: MaNV – mã nhân viên; HoNV – họ nhân viên; TenNV – tên nhân viên;
Email – email của nhân viên; SoDT – số điện thoại nhân viên;
Phong – phòng làm việc của nhân viên; Luong – lương của nhân viên.
```

### 4.9 Các phép toán trên quan hệ

| Phép toán | Ký hiệu |
|---|---|
| Phép chiếu | π |
| Phép chọn | σ |
| Phép hội | ∪ |
| Phép giao | ∩ |
| Phép trừ | \ |
| Phép chia | ÷ |
| Phép kết | ⋈ |
| Phép gom nhóm | ℑ |

---

## 5. Ràng buộc toàn vẹn

### 5.1 Ràng buộc dữ liệu

- Là những quy tắc, điều kiện, ràng buộc cần thỏa mãn cho mọi dữ liệu, để dữ liệu đúng đắn và thống nhất.
- **Ràng buộc toàn vẹn (RBTV - Integrity Constraint)** là các quy tắc, ràng buộc lên cơ sở dữ liệu, để hạn chế **tình trạng xấu của cơ sở dữ liệu**, không phản ánh đúng thế giới mà nó đang biểu diễn.
- Các quy tắc có thể xuất phát từ:
  - Bản thân mô hình dữ liệu.
  - Quy tắc trong quản lý.
  - Quy tắc trong tự nhiên.

**Ví dụ:**

```
NhanVien(MSNV, NgaySinh, NVCty)
```

Ta có: `NgaySinh < NVCty` (Ngày vào công ty của nhân viên phải lớn hơn ngày sinh của nhân viên).

### 5.2 Các loại ràng buộc

**RBTV có bối cảnh trên một quan hệ:**

- RBTV miền giá trị
- RBTV liên thuộc tính
- RBTV liên bộ

**RBTV có bối cảnh trên nhiều quan hệ:**

- RBTV tham chiếu
- RBTV liên bộ, liên quan hệ
- RBTV liên thuộc tính, liên quan hệ
- RBTV do thuộc tính tổng hợp
- RBTV do xuất hiện chu trình

### 5.3 Ràng buộc miền giá trị

- RBTV liên quan tới giá trị của một thuộc tính:
  - Ví dụ: Ngày nhận chức trưởng phòng phải là một ngày sau năm 1970.
- RBTV NOT NULL:
  - Ví dụ: Mọi nhân viên đều phải thuộc một phòng ban.
- RBTV về thời gian:
  - Ví dụ: Lương của nhân viên lúc nào cũng không được giảm.

**Ví dụ cụ thể với quan hệ KẾT QUẢ:**

```
KETQUA(MSMH, MSSV, DIEM, NAMHOC, HOCKI,...)
```

Các ràng buộc:

- `0 <= DIEM <= 10`
- `HOCKI = {1, 2}`

Ví dụ **sai** (vi phạm ràng buộc):

| MSSV | MSMH | DIEM | NAMHOC | HOCKI |
|---|---|---|---|---|
| 1 | CSDL | 1A | 2013-2014 | 1 |
| 1 | MMT | 9 | 2013-2014 | **4** |
| 2 | CSDL | 5 | 2013-2014 | 2 |

Điểm `1A` không hợp lệ (không thuộc `[0,10]`) và Học kỳ `4` không thuộc tập `{1,2}`.

### 5.4 Ràng buộc liên thuộc tính một quan hệ

Là ràng buộc giữa các thuộc tính trên **cùng 1 bộ** của quan hệ:

- VD1: Nếu ngày sinh trước 1/1/1970 thì nhân viên đó phải có lương tối thiểu là 50000.
- VD2: Ngày bắt đầu (TUNGAY) giảng dạy một môn học cho một lớp luôn nhỏ hơn ngày kết thúc (DENNGAY).

### 5.5 Ràng buộc liên bộ

Là ràng buộc giữa các bộ trên **cùng một quan hệ** (có thể liên quan đến nhiều thuộc tính):

- **RBTV khóa chính:** mỗi quan hệ có một khóa chính và các giá trị khóa chính đều phải khác null (một phần hay toàn bộ).
  - VD: Tất cả các học viên phải có mã số phân biệt với nhau.
- **RB duy nhất (Unique):**
  - VD: Tên các phòng ban phải khác nhau.
- **Ràng buộc về số bộ trong một quan hệ:**
  - VD: Mỗi dự án có tối đa 15 nhân viên tham gia.

### 5.6 RBTV có bối cảnh trên nhiều quan hệ

- RBTV tham chiếu
- RBTV liên bộ, liên quan hệ
- RBTV liên thuộc tính, liên quan hệ
- RBTV do thuộc tính tổng hợp
- RBTV do xuất hiện chu trình

### 5.7 RBTV tham chiếu (khóa ngoại)

Còn gọi là **ràng buộc phụ thuộc tồn tại** hay **ràng buộc khóa ngoại**: Giá trị xuất hiện tại các thuộc tính trong một quan hệ nào đó phải tham chiếu đến giá trị khóa chính của một quan hệ khác cho trước.

- Ví dụ 1: Một dự án do một phòng ban chủ trì.
- Ví dụ 2: Một thân nhân phải có mối quan hệ với một nhân viên trong công ty.
- Ví dụ 3: Sinh viên thi một môn học nào đó thì môn học đó phải có trong danh sách các môn học.

**Điều kiện khoá ngoại:** Xét R1 và R2 là 2 lược đồ, X được gọi là khoá ngoại của R1 tham chiếu đến R2 nếu thoả:

- X là khoá chính của R2. Giá trị trên R2 phải tồn tại trước R1.
- Khoá chính và khoá ngoại phải **cùng kiểu dữ liệu, cùng miền giá trị** (đặc biệt R1 có thể LÀ R2).

#### Đặc điểm khoá ngoại

- Có thể NULL.
- Một lược đồ quan hệ có thể có nhiều khoá ngoại.
- Một thuộc tính có thể vừa tham gia khoá ngoại vừa tham gia khoá chính.
- Tên khoá chính và khoá ngoại có thể khác nhau.
- Khoá chính và khoá ngoại có thể nằm trên một lược đồ.

#### Ví dụ

**Ví dụ 1 (sai):**

```
SINHVIEN(MSSV text(10), TENSV, QUEQUAN, MSLOP,...)
KETQUA(MSSV int, MSMH, DIEM)
```

Hai thuộc tính `MSSV` khác kiểu dữ liệu (text vs int) -> không hợp lệ.

**Ví dụ 2:** Cho 3 quan hệ

```
NhanVien (MSNV, TenNV,...)           (i)
DeAn_NhanVien (MSNV, MSDA, TGian)    (ii)
DeAn (MSDA, TenDA)                   (iii)
```

- `MSDA` trong (ii) là khoá ngoại tham chiếu đến `MSDA` trong (iii).
- `MSNV` trong (ii) là khoá ngoại tham chiếu đến `MSNV` trong (i).

**Ví dụ 3:**

```
SINHVIEN(MSSV, TENSV, QUEQUAN, MSLOP,...)
KETQUA(MSSV, MSMH, DIEM)
```

- `MSSV` trong `KETQUA` **vừa tham gia khoá ngoại vừa tham gia khoá chính**.

**Ví dụ 4:**

```
NHANKHAU(M SNK, TENNK, TONGIAO,...)
PHIEUKETHON(MSPKH, MSNK1, MSNK2,...)
```

- Tên khoá chính và khoá ngoại có thể khác nhau.
- `PHIEUKETHON` có **2 khoá ngoại** (`MSNK1`, `MSNK2`).

### 5.8 Các lưu ý

- Khi thêm, xoá, sửa dữ liệu có thể vi phạm các ràng buộc khóa chính và khóa ngoại.
- Thứ tự tạo và xoá bảng có ý nghĩa.
- Thứ tự tạo và xoá dữ liệu trong bảng có ý nghĩa.

### 5.9 Một số trường hợp đặc biệt

**Trường hợp 1:**

```
R1(A, B, C, D)
R2(A, C, M)
```

Kết quả: **Không có khóa ngoại** (không có thuộc tính nào của R2 tham chiếu đến toàn bộ/1 phần khóa chính của R1).

**Trường hợp 2:**

```
R1(A, B, C, D)
R2(K, C, A, B)
```

Kết quả: có khoá ngoại là **bộ (A, B)** (tham chiếu đến khóa chính (A,B) của R1).

### 5.10 RBTV liên bộ, liên quan hệ

Là ràng buộc xảy ra giữa các bộ trên **nhiều quan hệ khác nhau**:

- Ví dụ 1: Một phòng ban có ít nhất 3 nhân viên -> Liên quan đến 2 quan hệ `PHONGBAN`, `NHANVIEN`.

### 5.11 RBTV liên thuộc tính, liên quan hệ

Là ràng buộc giữa các thuộc tính trên **những quan hệ khác nhau**. Thông thường đó là các phụ thuộc tính toán, một suy diễn giá trị của một hay nhiều thuộc tính.

- Ví dụ 1: Ngày sinh của trưởng phòng phải nhỏ hơn ngày nhận chức (`PHONGBAN`, `NHANVIEN`).
- Ví dụ 2: Ngày thi một môn học phải lớn hơn ngày kết thúc học môn học đó (`GIANGDAY`, `KETQUATHI`).

### 5.12 RBTV do thuộc tính tổng hợp

- **Thuộc tính tổng hợp** là thuộc tính có giá trị được tính toán từ các thuộc tính khác của quan hệ khác.
- Khi CSDL có thuộc tính tổng hợp, RBTV bảo đảm **quan hệ giữa thuộc tính tổng hợp và các thuộc tính nguồn**.
  - VD1: Thuộc tính `SLMH` trong `HOADON` cho biết số loại sản phẩm có trong một hóa đơn (đếm từ bảng `CTHD`).
  - VD2: Trị giá của một hoá đơn bằng tổng thành tiền của các chi tiết thuộc hoá đơn đó (tổng Số lượng × Đơn giá của tất cả sản phẩm).
  - VD3: Sĩ số của một lớp là số lượng sinh viên thuộc lớp đó.

### 5.13 RBTV do xuất hiện chu trình

RBTV do sự hiện diện của **chu trình trên đồ thị biểu diễn lược đồ CSDL**:

- VD1: Trưởng phòng là một trong các nhân viên thuộc phòng.
- VD2: Nhân viên chỉ được phân công vào các đề án do phòng ban của mình phụ trách.

**Ví dụ:**

```
MONHOC(MSMON, TENMON, MSKHOA, SOTC)
GIAOVIEN(MSGV, TENGV, MSKHOA, HOCVI)
GIANGDAY(MSGV, MSMON, TUNGAY, DENNGAY)
```

Câu hỏi: Giảng viên chỉ được phân công dạy những môn do khoa trực thuộc phụ trách?

---

### 5.14 Bài tập: Thiết kế lược đồ quan hệ cho CSDL quản lý đề tài tốt nghiệp

Người ta cần tin học hoá khâu quản lí các đề tài tốt nghiệp của 1 trường ĐH, với các thông tin sau:

- Mỗi SV năm 4 sẽ làm đề tài TN. Mỗi đề tài bao gồm Tên ĐT, giáo viên hướng dẫn, thời gian bắt đầu, kết thúc, thuộc khoa nào.
- Khoa sẽ thành lập hội đồng khoa học. Mỗi HĐ gồm: Chủ tịch, 1 thành viên thư kí, ngày bảo vệ tại địa chỉ cụ thể.
- Mỗi đề tài sẽ bảo vệ tại một hội đồng. Điểm đề tài là trung bình cộng của: Chủ tịch, 01 GV phản biện, 01 GV hướng dẫn.
- Giáo viên cho điểm theo từng Sinh viên mặc dù các sinh viên có thể làm chung đề tài.
- Trong đợt bảo vệ có thể có nhiều hội đồng. 1 GV có thể hướng dẫn nhiều ĐT, hay phản biện nhiều ĐT.
- Chủ tịch HĐ, thư ký là giáo viên. Mỗi giáo viên cần thông tin: Tên, địa chỉ, SDT, học vị, chuyên ngành.
- Mỗi ĐT có thể tối đa 03 Sinh viên thực hiện.
- SV có điểm TB < 5 sẽ phải bảo vệ lại với khóa sau và chỉ được bảo vệ tối đa 2 lần; đề tài lần 1 phải khác lần 2.

---

## 6. Mô hình dữ liệu XML

### 6.1 Giới thiệu

- Cơ sở dữ liệu nhỏ.
- Nền tảng: Win32, WinCE, PalmOS, Linux, Solaris.
- Tìm kiếm, thêm, cập nhật và xóa dữ liệu trong cơ sở dữ liệu được tạo ra bởi các tập tin XML.
- Các cơ sở dữ liệu có thể là một phần của một ứng dụng.

### 6.2 XML

- Là một dạng **ngôn ngữ đánh dấu** (markup language).
- Được sử dụng để tạo ra **cấu trúc cho dữ liệu**.
- Gồm 2 thành phần chính:
  - **Thẻ:**
    - Thẻ mở đầu: ký hiệu `<tag>`.
    - Thẻ kết thúc: ký hiệu `</tag>`.
    - Thuộc tính cho thẻ (nếu có).
  - **Nội dung.**

### 6.3 Ví dụ

```xml
<Telephone>
  <EntryID>1038</EntryID>
  <LoginName>jake</LoginName>
  <PassWord>pass38</PassWord>
  <Lastname>Kim</Lastname>
  <Firstname>Jungkee</Firstname>
  <Date_of_Birth>10.01.1964</Date_of_Birth>
  <Company>FSU</Company>
  <Salutation>Mr.</Salutation>
  <Email>jake@csit.fsu.edu</Email>
  <Address>
    <Street>400 Dirac Science Library</Street>
    <City>Tallahassee</City>
    <ZIP>32306</ZIP>
    <Country>Korea</Country>
    <Telephone>6447018</Telephone>
    <Fax />
  </Address>
</Telephone>

<university>
  <department>
    <dept_name>Comp. Sci.</dept_name>
    <building>Taylor</building>
    <budget>100000</budget>
  </department>
  <course>
    <course_id>CS-101</course_id>
    <title>Intro. to Computer Science</title>
    <dept_name>Comp. Sci</dept_name>
    <credits>4</credits>
  </course>
</university>
```

### 6.4 Cấu trúc cơ bản của một CSDL XML

- Một CSDL XML gồm: Document Database, Search/Delete/Update/Insert, XML Parser, XML Generator.
- Để truy vấn dữ liệu trên CSDL XML, ta dùng **XPath** và **XQuery**.

---

## 7. Bài tập

- Tạo 1 CSDL mẫu.
  - Phát hiện các ràng buộc trên CSDL.
  - Cài đặt CSDL và các ràng buộc này trên SQL Server.
- Tạo 1 CSDL mẫu.
  - Thêm vào các bảng dữ liệu mẫu bằng vòng lặp `for` (khoảng 100000 dòng).
  - Viết câu `SELECT` đơn giản trên 1 cột (c1) **chưa index** và để ý đến thời gian thực hiện `T1`.
  - Chọn các cột trên các quan hệ để index.
  - Cài đặt các index trên SQL Server.
  - Viết câu `SELECT` đơn giản trên 1 cột (c1) **đã index** và so sánh thời gian thực hiện `T2` với `T1`.

---

## 8. Phụ lục: Chuẩn hoá CSDL

### 8.1 Giới thiệu

- Thiết kế cơ sở dữ liệu là 1 phần cực kì quan trọng; nếu thiết kế cẩn thận thì sau này sẽ tiết kiệm được rất nhiều thời gian trong quá trình phát triển.
- Để tối ưu cơ sở dữ liệu nên tuân theo các chuẩn thiết kế.
- Có 4 loại dạng chuẩn:
  - First Normal Form (1NF): dạng chuẩn 1NF
  - Second Normal Form (2NF): dạng chuẩn 2NF
  - Third Normal Form (3NF): dạng chuẩn 3NF
  - Boyce-Codd Normal Form (BCNF): dạng chuẩn Boyce-Codd

### 8.2 Dạng chuẩn 1 (1NF)

- Lược đồ quan hệ R ở dạng chuẩn 1 nếu **mọi thuộc tính của R đều chứa các giá trị nguyên tố** (atomic value); giá trị này không là một danh sách các giá trị hoặc giá trị phức hợp (composite value).

**Ví dụ:** Thuộc tính chưa là giá trị nguyên tố:

```
TENMON: "CSDLAnh" có thể phân rã ra thành: "CSDL" và "Anh".
```

### 8.3 Phụ thuộc hàm (FD - Functional Dependency)

- Cho lược đồ quan hệ `R(U)`, `r` là một quan hệ bất kỳ trên lược đồ quan hệ R; X và Y là hai tập thuộc tính con của U.
- **Phụ thuộc hàm** `X -> Y` trên lược đồ quan hệ R, được đọc là "X xác định hàm Y" hoặc "Y phụ thuộc hàm vào X", nếu:

```
∀t1, t2 ∈ r(R): t1[X] = t2[X] => t1[Y] = t2[Y]
```

- Tức là mỗi giá trị của X trong r chỉ tương ứng với một giá trị của Y.

### 8.4 Dạng chuẩn 2 (2NF)

- Lược đồ quan hệ R ở dạng chuẩn 2 đối với tập phụ thuộc hàm F nếu R ở dạng chuẩn 1 và **mọi thuộc tính không khóa đều phụ thuộc hàm đầy đủ vào mọi khóa của R**.

### 8.5 Dạng chuẩn 3 (3NF)

- Phải đạt chuẩn 2NF.
- Mọi thuộc tính không khóa phụ thuộc **bắc cầu** vào thuộc tính khóa (tất cả các thuộc tính không khóa phải được suy ra trực tiếp từ thuộc tính khóa).

### 8.6 Dạng chuẩn 4 (BCNF - Boyce-Codd-Kent)

- Phải đạt chuẩn 3NF.
- Không có thuộc tính khóa nào phụ thuộc vào thuộc tính không khóa.

---

## 9. Tài liệu tham khảo

1. Nguyễn Gia Tuấn Anh, Trương Châu Long, *Bài tập và bài giải SQL Server*, NXB Thanh niên (2005).
2. Đỗ Phúc, Nguyễn Đăng Tỵ, *Cơ sở dữ liệu*, NXB Đại học quốc gia TPHCM (2010).
3. Nguyễn Gia Tuấn Anh, Mai Văn Cường, Bùi Danh Hường, *Cơ sở dữ liệu nâng cao*, NXB Đại học quốc gia TPHCM (2019).
4. Itzik Ben-Gan, *Microsoft SQL Server 2012 - TSQL Fundamentals*.
5. E. Codd, *A relational model of data for large shared data banks*, Communications of the ACM (1970).