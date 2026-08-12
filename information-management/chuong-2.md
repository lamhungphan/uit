# Chương 2 - Biểu diễn dữ liệu mức khái niệm

## 1. Mô hình hoá

### Khái niệm

- Mô hình hóa là một phương tiện giúp đơn giản hóa thế giới thực bằng các mô hình.
- Mô hình hóa giúp con người hiểu rõ hơn về hệ thống dưới một góc nhìn.

### Mô hình hoá dữ liệu

- Mô hình hóa dữ liệu là mô hình chuẩn được cung cấp tạo thuận lợi cho việc tổ chức dữ liệu sao cho việc truy vấn dữ liệu là dễ dàng.

## 2. Mô hình dữ liệu

### Định nghĩa mô hình (model)

- Là thuật ngữ để biểu diễn các hiện tượng trong một phương thức dễ đọc.
- Mô hình cũng có thể là sự trừu tượng hóa, đơn giản hóa về một thế giới thực, là cầu nối giữa lí thuyết và thực tiễn.
- Mô hình có thể được chia thành hai loại: Số hóa và không số hóa.
  - Mô hình không số hóa thì dễ hiểu nhưng khó quản trị bởi máy tính.

### Các dạng mô hình dữ liệu

Có 3 dạng mô hình dữ liệu:

- Mức 1: Mô hình dữ liệu mức **Quan niệm** (Conceptual).
- Mức 2: Mô hình dữ liệu mức **Logic** (Logical).
- Mức 3: Mô hình dữ liệu mức **Vật lý** (Physical).

### Tóm tắt sự khác biệt giữa các mô hình dữ liệu

| Tiêu chí | Mô hình Quan niệm (Conceptual) | Mô hình Logic (Logical) | Mô hình Vật lý (Physical) |
|---|---|---|---|
| Mức độ trừu tượng | Cao | Trung bình | Thấp |
| Mục tiêu | Xác định dữ liệu & quan hệ | Biểu diễn dữ liệu dưới dạng bảng | Lưu trữ và tối ưu hóa dữ liệu thực tế |
| Phụ thuộc vào DBMS | Không | Có (SQL, NoSQL, ...) | Hoàn toàn (MySQL, PostgreSQL, ...) |
| Cách biểu diễn | Sơ đồ thực thể - quan hệ (ERD), Sơ đồ lớp (CD) | Lược đồ quan hệ (Schema) | Cấu trúc lưu trữ, Index, Partitioning |
| Ví dụ thực tế | "Sinh viên đăng ký môn học" | Bảng SinhVien, MonHoc, LopHoc | Dữ liệu được lưu trên ổ cứng với chỉ mục |

## 3. Mô hình dữ liệu mức quan niệm

- Một mô hình dữ liệu quan niệm là hình thức trừu tượng nhất của mô hình dữ liệu, là phương tiện hữu ích để giao tiếp các ý tưởng, vì tính đơn giản của nó.

### Các mô hình dữ liệu ở mức quan niệm

- Mô hình thực thể - mối kết hợp (ERD).
- Mô hình lớp (CD).

### Ví dụ - Mô hình ERD (Chen, 1972)

- Các khái niệm trừu tượng: thực thể, mối kết hợp.
- Các quan hệ giữa các thực thể với nhau:
  - Quan hệ 1-1.
  - Quan hệ 1-n.
  - Quan hệ n-n.

## 4. Mô hình dữ liệu mức Logic

- Mô hình dữ liệu mức logic là phương thức biểu diễn lại dữ liệu sao cho thuận lợi để biểu diễn trên máy tính.
- Mô hình dữ liệu mức logic bao gồm:
  - Hệ thống ký hiệu để mô tả dữ liệu.
  - Tập hợp các phép toán thao tác trên dữ liệu đó.

### Ví dụ - Mô hình Quan hệ (Codd, 1970)

- Hệ thống các ký hiệu: Bộ (tuple), bản ghi (record), thuộc tính (attribute).
- Hệ thống các phép toán: phép chiếu, phép chọn, phép kết, phép gom nhóm, phép trừ, phép chia, ...

### Các dạng mô hình mức logic

- Mô hình dữ liệu phẳng (flat model).
- Mô hình phân cấp (Hierarchical model).
- Mô hình mạng (Network model).
- Mô hình dữ liệu quan hệ (Relational model).
- Mô hình dữ liệu hướng đối tượng (Object-oriented model).
- Mô hình dữ liệu quan hệ đối tượng (Object-relational model).

## 5. Mô hình quan niệm 1 - Mô hình ERD

### Đặt vấn đề

Từ 1 bài toán mô tả bằng văn bản và ngôn ngữ tự nhiên với đặc điểm:

- Không thứ tự.
- Lẫn lộn giữa các khái niệm.
- Thiếu hoặc thừa.
- Pha trộn giữa dữ liệu và xử lý không rõ ràng, không thứ tự.

Phân tích dữ liệu sẽ chuyển sang 1 bài toán:

- Có thứ tự, đúng, đủ, tách dữ liệu và xử lý, định nghĩa lại khái niệm.
- Đồng thời mô tả phần dữ liệu dưới dạng ngôn ngữ, mô hình này gọi là mô hình dữ liệu mức 1 (khái niệm).

### Giới thiệu

Mô hình quan hệ thực thể (Entity Relationship model - E-R) được **P.P. CHEN** giới thiệu vào năm **1976** là một mô hình được sử dụng rộng rãi trong các bản thiết kế cơ sở dữ liệu ở mức khái niệm, được xây dựng dựa trên việc nhận thức thế giới thực thông qua tập các đối tượng được gọi là các **thực thể** và các **mối quan hệ** giữa các đối tượng này.

### Các yếu tố cơ bản của mô hình ERD

Có 2 yếu tố cơ bản trong mô hình ERD:

- Thực thể (Entity).
- Mối kết hợp (Relationship).

### Thực thể (Entity)

- **Ý nghĩa:** Dùng biểu diễn một đối tượng trong bài toán cần phân tích.
- **Ký hiệu:** Hình chữ nhật với tên thực thể ở trên, bên trong liệt kê các thuộc tính A1, A2, ..., An.

```
┌───────────────────────┐
│       TÊN THỰC THỂ    │
│  A1, A2, ..., An      │
└───────────────────────┘
```

- Trong các thuộc tính Ai (i=1..n), có 1 (hay nhiều) thuộc tính được chọn là khóa chính (primary key) - PK.
- Thuộc tính PK được gạch dưới (hoặc dùng kí hiệu qui ước khác: #).

```
┌───────────────────────┐
│        SACH           │
│  MaSach, TenSach, ... │
└───────────────────────┘
```

### Một số lưu ý về thực thể

- Tên của thực thể phải là danh từ.
- Các thuộc tính của 1 thực thể do ứng dụng đặt ra.
- Hai ứng dụng khác nhau cùng sử dụng một thực thể nhưng thuộc tính khác.
- Thực thể không có thuộc tính khoá ngoại.

### Mối kết hợp (Relationship)

- **Ý nghĩa:** Mô tả sự liên quan giữa các thực thể trong 1 ứng dụng.
- **Ký hiệu:** Hình thoi có ghi tên mối kết hợp, nối với các thực thể tham gia.

```
        ┌──────────┐
 ┌──────┤  CUA     ├──────┐
 │      └──────────┘      │
┌▼──────┐           ┌─────▼───┐
│ SACH  │           │ TACGIA  │
└───────┘           └─────────┘
```

- Một số lưu ý:
  - Hai thực thể có thể: không có mối kết hợp, hoặc có nhiều mối kết hợp.
  - Một thực thể có thể có mối kết hợp với chính nó.

### Một số ví dụ về mối kết hợp

- Thực thể SACH và thực thể TACGIA quan hệ với nhau qua mối quan hệ CUA.

- Hai thực thể GV và DETAI có 2 mối quan hệ với nhau là: **HD** (hướng dẫn) và **PB** (phản biện).

- Thực thể NKHAU có mối quan hệ "Ket hon" với chính nó (mối kết hợp tự thân, 2 vai trò khác nhau của cùng thực thể).

- 3 thực thể NVIEN, PBAN và PXUONG có các mối quan hệ như sau:
  1. NVIEN quan hệ Thuoc1 với PBAN.
  2. NVIEN quan hệ Thuoc2 với PXUONG.
  3. PBAN không có quan hệ với PXUONG.

### Bản số (Cardinality)

- **Ý nghĩa:** Nhằm mô tả định lượng mối quan hệ giữa các thực thể.
- Định lượng thể hiện 2 trị: min, max.

Ví dụ với quan hệ SACH - CUA - TACGIA:

- C: 1 tác giả tối thiểu viết mấy sách? -> giá trị min của phía SACH.
- D: 1 tác giả tối đa viết mấy sách? -> giá trị max của phía SACH.
- A: 1 sách tối thiểu của mấy tác giả? -> giá trị min của phía TACGIA.
- B: 1 sách tối đa của mấy tác giả? -> giá trị max của phía TACGIA.

### Ví dụ - Bài toán quản lý nhân sự

Trong mô hình quản lý nhân sự, có các nhân viên, phòng ban và các chức vụ của nhân viên trong phòng ban. Một nhân viên có thể nắm nhiều chức vụ trong các phòng ban, một phòng ban có thể có nhiều nhân viên với các chức vụ, và một chức vụ cũng có thể cho nhiều nhân viên trong các phòng ban.

**Yêu cầu:** Thiết kế mô hình ERD cho bài toán trên.

**Các thực thể:**

- NV: Nhân viên.
- PB: Phòng ban.
- CHUCVU: Chức vụ.

**Mối kết hợp và bản số:**

- 1 nhân viên có thể thuộc 1 hoặc nhiều phòng ban. Một phòng ban có thể có 1 hoặc nhiều nhân viên.
- Một nhân viên có thể đảm nhiệm một hoặc nhiều chức vụ. Một chức vụ có thể do một hoặc nhiều nhân viên đảm nhiệm.

## 6. Chuyển đổi mô hình quan niệm (ERD) sang mô hình logic

- **Mục đích:** Chuyển dữ liệu từ mức quan niệm (mức 1) sang mức logic (mức 2).
- Có các khả năng chuyển như sau:
  - Khả năng 1: Bản số (1,1)-(1,1).
  - Khả năng 2: Bản số (0,1)-(1,1).
  - Khả năng 3: Bản số (0,1)-(0,1).
  - Khả năng 4: Bản số (1,1)-(1,n).
  - Khả năng 5: Bản số (1,n)-(1,n).

### Khả năng 1: Bản số (1,1)-(1,1)

```
 T1            T2
┌──────┐      ┌──────┐
│ A1   │      │ B1   │
│ A2   │  R   │ B2   │
└──────┘      └──────┘
  (1,1)         (1,1)
```

Chuyển:

```
T1 (A1, A2, B1)
T2 (B1, B2, A1)
```

### Khả năng 2: Bản số (0,1)-(1,1)

```
 T1            T2
┌──────┐      ┌──────┐
│ A1   │  R   │ B1   │
│ A2   │      │ B2   │
└──────┘      └──────┘
  (0,1)         (1,1)
```

Chuyển (nhúng khoá bên phía (1,1) vào bên phía (0,1)):

```
T1 (A1, A2)
T2 (B1, B2, A1)
```

### Khả năng 3: Bản số (0,1)-(0,1)

```
 T1            T2
┌──────┐      ┌──────┐
│ A1   │  R   │ B1   │
│ A2   │      │ B2   │
└──────┘      └──────┘
  (0,1)         (0,1)
```

Chuyển (dùng bảng trung gian):

```
T1 (A1, A2)
T2 (B1, B2)
T1T2 (A1, B1)
```

### Khả năng 4: Bản số (1,1)-(1,n)

```
 T1            T2
┌──────┐      ┌──────┐
│ A1   │  R   │ B1   │
│ A2   │      │ B2   │
└──────┘      └──────┘
  (1,1)         (1,n)
```

Chuyển (nhúng khoá bên phía (1,1) vào bên phía (1,n)):

```
T1 (A1, A2, B1)
T2 (B1, B2)
```

### Khả năng 5: Bản số (1,n)-(1,n)

```
 T1            T2
┌──────┐      ┌──────┐
│ A1   │  R   │ B1   │
│ A2   │      │ B2   │
└──────┘      └──────┘
  (1,n)         (1,n)
```

Chuyển (dùng bảng trung gian):

```
T1 (A1, A2)
T2 (B1, B2)
T1T2 (A1, B1)
```

### Các khả năng khác

1. (0,n)-(0,n)
2. (0,n)-(1,n)
3. (0,1)-(0,n)

### Ví dụ chuyển từ mức quan niệm sang mức logic

Từ bài toán quản lý chuyến bay, mức logic thu được:

```
THANHPHO (MSTP, DCSB)
TUYENBAY (MSTB, SoGio, MSTPDen, MSTPDi)
CHUYENBAY (MSCB, LoaiCB, Ngay, GioBD)
TUYENBAY_CHUYENBAY (MSTB, MSCB)
PHICONG (MSPC, Ten, SDT, DC, MSDV)
CHUYENBAY_PHICONG (MSCB, MSPC)
HANHKHACH (CMND, TenHK, DC, SDT)
CHUYENBAY_HANHKHACH (MSCB, CMND)
DONVI (MSDV, TenDV)
```

## 7. Mô hình quan niệm 2 - Mô hình lớp (Class diagram)

### Giới thiệu

- Sơ đồ lớp là một loại sơ đồ cấu trúc tĩnh mô tả cấu trúc của hệ thống bằng cách hiển thị các lớp của hệ thống, thuộc tính, hoạt động của chúng và mối quan hệ giữa các đối tượng.
- Đối tượng chính của mô hình này là lớp và mối quan hệ giữa chúng.

### Lớp (class)

- Lớp (class) dùng biểu diễn 1 thực thể trong thế giới thực.
- Các thành phần cơ bản của lớp:
  - Tên lớp.
  - Thuộc tính (field, property).
  - Hành vi (method, function).

```
┌──────────────────────────────┐
│          Tên lớp             │
│──────────────────────────────│
│  Thuộc tính (field, property)│
│──────────────────────────────│
│  Phương thức (hành vi)       │
└──────────────────────────────┘
```

### Tìm kiếm lớp

- Tên lớp: là một danh từ.
- Ví dụ:
  - Kho: Đúng (danh từ).
  - KiemTraKho: Sai (động từ/hành vi).
  - DonDatHang: Đúng (danh từ).
  - DatHang: Sai (động từ/hành vi).
- Khi phỏng vấn, khảo sát, đọc đề thì các thông tin sau gợi ý phát hiện lớp:
  - Lưu trữ.
  - Thống kê.
  - Phân tích.
  - Tác nhân.

### Tìm kiếm thuộc tính

- Chủ yếu:
  - Từ thực tế.
  - Từ đề bài.
  - Không nên tưởng tượng thái quá.
- Có thể nhầm lẫn giữa thuộc tính và lớp.
- Ví dụ: người ta cần thống kê số sinh viên theo quốc tịch.
  - Nhận xét: quốc tịch có thể thêm, bớt, thay đổi => quốc tịch là **lớp**, không phải thuộc tính.

### Mối quan hệ giữa các lớp

- Quan hệ kế thừa (inherit).
- Quan hệ kết hợp (associate).
- Quan hệ tụ hợp (aggregation).

### Quan hệ kế thừa

- Mở rộng (specialize thêm thuộc tính, hành vi của lớp con).
- Giới hạn (lớp con hạn chế bớt một phần của lớp cha).

### Quan hệ kết hợp

- Lớp này có tham chiếu đến lớp kia (bằng thuộc tính hoặc trong phương thức).

### Quan hệ tụ hợp (aggregation)

Gồm 4 dạng:

- Tồn tại độc lập.
- Tồn tại không độc lập.
- Độc quyền.
- Không độc quyền.

Ví dụ:
- Tồn tại độc lập: các đối tượng thành phần có thể tồn tại khi đối tượng chứa bị xóa.
- Tồn tại không độc lập: đối tượng thành phần phụ thuộc đối tượng chứa, bị xóa khi đối tượng chứa bị xóa.

## 8. Chuyển từ mô hình CD sang mô hình logic

Có 3 khả năng xảy ra:

- Khả năng 1: quan hệ 1-1.
- Khả năng 2: quan hệ 1-n.
- Khả năng 3: quan hệ m-n.

### Khả năng 1: quan hệ 1-1

(Các kiểu dữ liệu int, char chỉ có tính tượng trưng)

```
Class A             Class B
{  A1: int,          {  B1: int,
   A2: int,             B2: char,
   B1: B              A1: A
}                    }
```

Chuyển: hai lớp tham chiếu lẫn nhau.

### Khả năng 2: quan hệ 1-n

```
Class A             Class B
{  A1: int,          {  B1: int,
   A2: int,             B2: char,
   B1: set(B)           A1: A
}                    }
```

Chuyển: một đối tượng A quản lý tập hợp (set) các đối tượng B; mỗi B tham chiếu ngược lại A.

### Khả năng 3: quan hệ m-n

```
Class A             Class B
{  A1: int,          {  B1: int,
   A2: int,             B2: char,
   B1: set(B)           A1: set(A)
}                    }
```

Chuyển: cả hai lớp cùng quản lý tập hợp tham chiếu lẫn nhau.

## 9. Tổng kết

- Mô hình là phương tiện để biểu diễn thông tin từ các đối tượng trong thế giới thực lên máy tính.
- Có 3 mức biểu diễn dữ liệu: mức 1 - quan niệm, mức 2 - logic và mức 3 - vật lý.
- Ở mức quan niệm, có 2 mô hình chính: ERD và CD.
- Mô hình ERD: gồm 2 đối tượng chính là thực thể và mối kết hợp giữa chúng. Mối kết hợp có thể định lượng.
- Mô hình CD: gồm 2 đối tượng chính là lớp và quan hệ giữa các lớp. Một lớp gồm có 3 thành phần: tên, thuộc tính và phương thức.

## 10. Bài tập

Yêu cầu chung cho 2 bài:

- Tìm mô hình ERD và CD cho 2 bài toán sau.
- Chuyển 2 mô hình trên sang mô hình logic.

### Bài 1 - Quản lý các đề tài tốt nghiệp

Người ta cần tin học hoá khâu Quản lý các đề tài tốt nghiệp của 1 trường ĐH. Với các thông tin sau:

- Mỗi SV năm 4 sẽ làm đề tài TN. Mỗi đề tài bao gồm Tên DT, giáo viên hướng dẫn, thời gian bắt đầu, kết thúc, thuộc khoa nào.
- Khoa sẽ thành lập hội đồng khoa học, mỗi HĐ gồm: 1 Chủ tịch, 1 Thư kí, 1 Ủy viên, ngày bảo vệ tại địa chỉ cụ thể.
- Mỗi đề tài sẽ bảo vệ tại một hội đồng, điểm đề tài là: (Điểm GVHD x 2 + Điểm GVPB x 2 + Điểm Chủ tịch + Điểm thư ký + Điểm ủy viên) / 7.
- Giáo viên cho điểm theo từng SV mặc dù các SV có thể làm chung đề tài.
- Trong đợt bảo vệ có thể có nhiều hội đồng, 1 GV có thể hướng dẫn nhiều DT, hay phản biện nhiều DT.
- Chủ tịch HD, Ủy viên, Thư ký là giáo viên.
- Mỗi giáo viên cần thông tin: Tên, địa chỉ, SDT, học vị, chuyên ngành.
- Mỗi DT có thể tối đa 02 SV thực hiện.
- SV có điểm bảo vệ < 5 sẽ phải bảo vệ lại với khóa sau và chỉ được bảo vệ tối đa 2 lần, đề tài lần 1 phải khác lần 2.

### Bài 2 - Quản lý mua bán cửa hàng xe máy

Người ta cần tin học hoá khâu Quản lý mua bán tại cửa hàng bán xe máy 2 bánh với các thông tin sau:

- Khách hàng có thể mua trả hết hay trả góp, nhiều nhất 3 lần cho mỗi hóa đơn.
- Thông tin xe gồm: Nước SX, loại xe, Số PK, số khung, số sườn, màu xe.
- Khi mua xe khách hàng được giao Hợp đồng có: SỐ HD, Ngày HD, Thời gian bảo hành, Tiền phải thanh toán, tiền đã thanh toán, nhân viên lập, kế toán.
- Ngoài ra còn thông tin KH: Tên, địa chỉ, SDT.
- Nếu trả nhiều lần trên HD sẽ ghi rõ 2 lần trả kế tiếp, Ngày trả lần 1, ngày trả lần 2.
- Khi KH thanh toán lần 2 cần lập phiếu thanh toán và ghi rõ: Thanh toán cho HD nào, ngày trả, số tiền, người nhận và người trả.
- Với các HD thanh toán 1 lần sẽ giảm 2% cho mỗi HD và tỉ lệ này có thể thay đổi.
- Với khách hàng mua số lượng 1 lần trên 3 chiếc và thanh toán 1 lần sẽ giảm 5% trên HD và tỉ lệ này có thể thay đổi.
- Trường hợp KH yêu cầu bảo hành sẽ có bộ phận kĩ thuật kiểm tra và báo cáo bằng phiếu nhận xét, ghi rõ tên các linh kiện, lí do BH, lỗi thuộc về khách hay sản phẩm, giá tiền.
- Cửa hàng có nhiều đại lí nằm trên các vị trí khác nhau.
- Nhân viên bao gồm: Hành chánh (chức vụ, thuộc phòng ban nào, trình độ học vấn), Kĩ thuật (chức vụ, bậc thợ, số năm kinh nghiệm).

## 11. Tài liệu tham khảo

1. Nguyễn Gia Tuấn Anh, Trương Châu Long, *Bài tập và bài giải SQL Server*, NXB Thanh niên (2005).
2. Đỗ Phúc, Nguyễn Đăng Tỵ, *Cơ sở dữ liệu*, NXB Đại học quốc gia TPHCM (2010).
3. Nguyễn Gia Tuấn Anh, Mai Văn Cường, Bùi Danh Hường, *Cơ sở dữ liệu nâng cao*, NXB Đại học quốc gia TPHCM (2019).
4. Itzik Ben-Gan, *Microsoft SQL Server 2012 - TSQL Fundamentals*.
5. P. P. Chen, *The Entity-Relationship Model: Toward a Unified View of Data*, ACM Transactions on Database Systems (1976).