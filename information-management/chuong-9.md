# Chương 9 - Mô hình CSDL tiên tiến: CSDL NoSQL (phi quan hệ)

## 1. Vì sao cần NoSQL

Với sự phát triển của Internet, dữ liệu xung quanh chúng ta ngày càng lớn hơn bao giờ hết:

- Mọi loại dữ liệu (chuỗi, số, âm thanh, hình ảnh) đều có thể số hóa để lưu trữ, xử lý và chuyển tiếp cho nhiều người.
- Sự phát triển của mạng xã hội cho phép người dùng tự do tạo nội dung tương tác, làm khối lượng dữ liệu tăng trưởng cực lớn.
- Khối lượng dữ liệu tăng quá nhanh, vượt qua giới hạn xử lý của các hệ quản trị CSDL truyền thống.
- Các hệ CSDL quan hệ hiện tại bộc lộ nhiều hạn chế.

Do đó, các CSDL NoSQL được nghiên cứu trong những năm gần đây:

- Đặc biệt thích hợp cho các ứng dụng cực lớn.
- Giảm thiểu tối đa các phép tính toán và tác vụ đọc - ghi.
- Khả năng chịu tải, chịu lỗi cao nhưng đòi hỏi tài nguyên phần cứng khá thấp.

## 2. Đặc điểm của NoSQL

NoSQL là một loại CSDL có các đặc tính sau:

| Đặc tính | Ý nghĩa |
|---|---|
| Không ràng buộc | Không áp đặt các ràng buộc dữ liệu cứng nhắc |
| Phân tán | Dữ liệu được lưu trữ, xử lý trên nhiều máy |
| Mã nguồn mở | Phần lớn các hệ NoSQL là mã nguồn mở |
| Mở rộng theo chiều ngang | Thêm máy mới để tăng khả năng lưu trữ/xử lý |
| Lược đồ tự do | Không cần xác định lược đồ trước |

NoSQL có thể lưu trữ, xử lý dữ liệu từ lượng rất nhỏ cho đến hàng petabytes, trong một hệ thống chịu tải, chịu lỗi cao và đáp ứng thời gian thực.

## 3. Từ SQL (ACID) đến NoSQL (BASE)

### 3.1 ACID - Mô hình của CSDL quan hệ

ACID là viết tắt của:

| Chữ viết tắt | Ý nghĩa | Tiếng Việt |
|---|---|---|
| Atomicity | Tính nguyên tử | Giao dịch không thể chia nhỏ |
| Consistency | Tính nhất quán | Dữ liệu luôn hợp lệ sau mỗi giao dịch |
| Isolation | Tính cô lập | Các giao dịch độc lập với nhau |
| Durability | Tính bền vững | Dữ liệu ghi thành công được lưu vĩnh viễn |

Hạn chế: Trong CSDL quan hệ, các nguyên tắc ACID là quá mức cần thiết và trên thực tế đã cản trở hoạt động của CSDL. Việc thỏa mãn đầy đủ ACID là vô cùng khó khăn, do đó **Consistency và Isolation bị thu hồi** để đổi lấy hiệu năng và khả năng mở rộng.

### 3.2 Nguyên lý CAP

Trong hệ thống phân tán, không thể đồng thời đảm bảo đủ ba thuộc tính:

| Thuộc tính | Ý nghĩa |
|---|---|
| Consistency (C) | Tính nhất quán: mọi nút luôn thấy cùng một dữ liệu |
| Availability (A) | Tính sẵn sàng: mọi yêu cầu luôn nhận được phản hồi |
| Partition tolerance (P) | Tính chịu phân mảnh: hệ thống vẫn hoạt động khi mạng bị chia cắt |

Hệ thống phải chọn 2 trong 3 (CP hoặc AP):

- CSDL quan hệ ưu tiên **Consistency** (tuân thủ ACID).
- CSDL NoSQL ưu tiên **Availability** (tuân thủ BASE), chấp nhận nhất quán trễ.

### 3.3 Nguyên tắc BASE của NoSQL

NoSQL dựa vào một mô hình nhẹ nhàng hơn, phù hợp hơn - cách tiếp cận **BASE** gồm ba nguyên tắc:

| Nguyên tắc | Ý nghĩa |
|---|---|
| **Basic Availability** (Sẵn có cơ bản) | Ứng dụng làm việc cơ bản xuyên suốt mọi thời gian |
| **Soft State** (Trạng thái mềm) | Không cần nhất quán trên tất cả thời gian hoạt động |
| **Eventual Consistency** (Nhất quán cuối) | Cuối cùng dữ liệu sẽ đạt trạng thái nhất quán |

=> BASE là cách tiếp cận để quản lý dữ liệu phi cấu trúc.

## 4. Ưu điểm và nhược điểm của NoSQL

### 4.1 Ưu điểm

- Đáp ứng được sự tăng trưởng của dữ liệu lớn (big data).
- Truy xuất dữ liệu lớn với tốc độ cao.
- Xử lý được dữ liệu đa dạng: có cấu trúc, bán cấu trúc hoặc phi cấu trúc.
- Dữ liệu phức tạp được lưu trữ và quản lý tại các trung tâm lưu trữ khác nhau.
- Cần ít tài nguyên và phần cứng máy chủ hơn.
- Hỗ trợ chỉ mục cho tất cả các thuộc tính.
- Mã nguồn mở.
- Có thể mở rộng theo cả chiều ngang lẫn chiều dọc.
- Được các hãng lớn sử dụng: Amazon, BBC, Facebook, Google.
- Kết hợp tự nhiên với công nghệ đám mây (cloud technology), tận dụng được việc cung cấp mềm dẻo của dịch vụ lưu trữ trên cloud.
- Hầu hết ghi vào bộ nhớ qua ổ đĩa như vị trí ghi đầu tiên, nhờ đó ngăn ngừa sự thực thi không ổn định của thao tác I/O.

### 4.2 Nhược điểm

- Sự tin tưởng chưa cao đối với nhiều doanh nghiệp; CSDL truyền thống vẫn là lựa chọn số một.
- Tính mới mẻ khiến chưa có nhiều lập trình viên và người quản trị biết công nghệ này.
- Vấn đề tương thích: mỗi CSDL NoSQL có API và giao diện truy vấn riêng biệt.
- Khó khăn trong việc lưu trữ các dữ liệu mang nội dung nghiệp vụ phức tạp.

## 5. Các mô hình NoSQL

Có 4 mô hình phi quan hệ chính:

1. Khoá - giá trị (Key-value)
2. Hướng tài liệu (Document)
3. Hướng cột (Column)
4. Đồ thị (Graph)

## 6. Mô hình Khoá - giá trị (Key-value)

- Dữ liệu được xác định bằng một khoá duy nhất (Key).
- Các giá trị (value) hoàn toàn tách biệt và không phụ thuộc vào nhau.
- Cấu trúc dữ liệu rất đơn giản nên CSDL cặp khoá - giá trị hoàn toàn **không có lược đồ**.
- Giá trị mới có thể được thêm vào trong lúc hệ thống đang chạy mà không gây xung đột dữ liệu nào.
- Hữu ích cho các xử lý đơn giản, chỉ phụ thuộc vào thuộc tính khoá.
- Ứng dụng: từ điển, truy xuất bộ đệm (cache).

Ví dụ sản phẩm: **Redis**.

Ví dụ dữ liệu lưu dưới dạng cặp khoá - giá trị:

```json
TACGIA
{
  "TG01": "NguyenA_098731_a@gmail.com",
  "TG02": "NguyenB:098731:b@gmail.com"
}

SACH
{
  "S01": "ABC_Trang:6_100000_NXB:DHQG"
}

NXB
{
  "NXB01": "NXB-DHQG-DT:0844643_nxb@gmail.com"
}

TG_SACH
{
  "TG01_S01": "2019",
  "TG01_S02": "2020"
}
```

## 7. Mô hình Hướng tài liệu (Document)

- Được thiết kế để lưu trữ, truy xuất và quản lý dữ liệu dạng tài liệu, bán cấu trúc hoặc thông tin.
- Khái niệm quan hệ (bảng) được thay thế bởi khái niệm trừu tượng gọi là **tài liệu (document)**.
- Sử dụng khoá tài liệu (key-document hoặc key-value) để lấy một tài liệu; CSDL cung cấp API hoặc ngôn ngữ truy vấn cho phép lấy các tài liệu dựa trên **nội dung**.
- Ứng dụng: hệ thống lưu trữ nội dung mạng xã hội, trang web.

Ví dụ sản phẩm: **MongoDB**.

Ví dụ dữ liệu tài liệu có lồng nhau:

```json
[
  {
    "MATG": "TG01",
    "HOTEN": "NguyenA",
    "SDT": "098731",
    "Email": "a@gmail.com",
    "SACH": [
      { "MASACH": "S01", "NAM": "2019" },
      { "MASACH": "S01", "NAM": "2020", "TEN": "ABC" }
    ]
  },
  {
    "MATG": "TG02",
    "HOTEN": "NguyenB",
    "SDT": "098731",
    "Email": "b@gmail.com"
  }
]
```

Ví dụ truy vấn MongoDB:

```javascript
// Chèn một tài liệu
db.tacgia.insertOne({
  MATG: "TG01",
  HOTEN: "NguyenA",
  SACH: [{ MASACH: "S01", NAM: 2019 }]
})

// Truy vấn theo nội dung
db.tacgia.find({ "HOTEN": "NguyenA" })

// Tìm các tác giả có viết sách năm 2019
db.tacgia.find({ "SACH.NAM": 2019 })
```

## 8. Mô hình Hướng cột (Column)

- Xem xét nhiều trường hợp khác nhau của các thuộc tính: mỗi dòng chỉ chứa những cặp thuộc tính - giá trị cần thiết, còn lại các thuộc tính không cần lưu trữ (không cần giá trị null).
- Nhìn bên ngoài có nhiều điểm tương đồng với CSDL quan hệ, nhưng thật sự có nhiều khác biệt lớn bên trong:
  - Điểm khác biệt chính: không lưu trữ null đối với các thuộc tính không cần thiết.
  - Dữ liệu được lưu trữ **theo cột** thay vì theo dòng như CSDL quan hệ, do đó số thuộc tính không cần phải xác định trước.

Ví dụ sản phẩm: **Cassandra**.

Ví dụ minh họa (mỗi dòng có thể có số cột khác nhau):

| Row ID | Cột 1 | Cột 2 | Cột 3 |
|---|---|---|---|
| 1 | Tên: Nam | Website: www.vnexpress.com | *(không có)* |
| 2 | Tên: Mai | Email: mai@gmail.com | Website: Dantri.com.vn |

- Dòng 1 chỉ có 2 cột, dòng 2 có 3 cột mà không cần khai báo trước.

Ví dụ CQL (Cassandra Query Language):

```cql
-- Tạo bảng hướng cột
CREATE TABLE tacgia (
  mstg text PRIMARY KEY,
  tentg text,
  sdt text,
  email text
);

-- Chèn dữ liệu, cột thiếu có thể bỏ qua mà không cần null
INSERT INTO tacgia (mstg, tentg, sdt, email)
VALUES ('TG02', 'NguyenB', '098731', 'b@gmail.com');

-- Truy vấn theo khoá
SELECT * FROM tacgia WHERE mstg = 'TG01';
```

## 9. Mô hình Đồ thị (Graph)

- Chuyên dùng trong quản lý dữ liệu với nhiều liên kết (quan hệ) phức tạp.
- Mỗi thực thể (instance) tương ứng với một **nút (node)**, quan hệ giữa các thực thể được biểu diễn bởi **cạnh (edge)**.
- Nút và cạnh là các đối tượng chứa các cặp khoá - giá trị.
- Tầm vực (scope) của các cặp khoá - giá trị được định nghĩa trong lược đồ, nhờ đó mô tả được các ràng buộc phức tạp một cách dễ dàng.

Ví dụ sản phẩm: **Neo4j**.

Ví dụ mô hình đồ thị cho thư viện (TACGIA, SACH, NXB):

```text
[TACGIA] --(VIET: nam=2019)--> [TACGIA] --(VIET: nam=2020)-->
   TG01                         TG02
    |                               |
    +----------(CUA)----------------+
                              |
                            [SACH]
                              |  S01
                        (THUOC)
                              |
                           [NXB]
                          NXB01
```

Truy vấn Cypher (Neo4j):

```cypher
// Tạo nút và cạnh
CREATE (tg:TacGia {mstg: 'TG01', tentg: 'NguyenA'})
CREATE (s:Sach {mssach: 'S01', tensach: 'ABC'})
CREATE (n:Nxb {msnxb: 'NXB01', tennxb: 'NXB-DHQG'})
CREATE (tg)-[:VIET {nam: 2019}]->(s)
CREATE (s)-[:THUOC]->(n)

// Truy vấn: tác giả nào đã viết cuốn sách ABC
MATCH (tg:TacGia)-[:VIET]->(s:Sach {tensach: 'ABC'})
RETURN tg.tentg, s.tensach
```

## 10. Chuyển từ mô hình quan hệ sang NoSQL

### 10.1 Mô hình quan hệ ban đầu

| TACGIA (#mstg, tentg, sdt, email) |
|---|
| TG01 | Nguyen A | 098731 | a@gmail.com |
| TG02 | Nguyen B | 098731 | b@gmail.com |

| SACH (#mssach, tensach, sotrang, sotien, msnxb) |
|---|
| S01 | ABC | 6 | 100000 | DHQG |

| NXB (#msnxb, tennxb, sdt-xb, email-xb) |
|---|
| NXB01 | NXB-DHQG | 0844643 | nxb@gmail.com |

| TG-SACH (#mstg, #mssach, nam-xb) |
|---|
| TG01 | S01 | 2019 |
| TG02 | S01 | 2020 |

### 10.2 Chuyển sang Key-value

- Ghép toàn bộ giá trị của mỗi dòng thành một chuỗi, dùng khoá duy nhất để truy xuất.
- Mất khả năng truy vấn theo từng thuộc tính.

```json
TG_SACH
{
  "TG01_S01": "2019",
  "TG01_S02": "2020"
}
```

### 10.3 Chuyển sang Document

- Gộp dữ liệu có liên quan vào cùng một tài liệu (denormalization), dùng tài liệu lồng nhau để thay quan hệ.

SACH lồng NXB:

```json
[
  {
    "MASACH": "S01",
    "TENSACH": "ABC",
    "SOTRANG": 6,
    "SOTIEN": "100000",
    "NXB": {
      "TEN": "NXB-DHQG",
      "MANXB": "NXB01",
      "DT": "0844643",
      "EMAIL": "nxb@gmail.com"
    }
  }
]
```

NXB chứa danh sách sách do NXB xuất bản:

```json
{
  "TEN": "NXB-DHQG",
  "MANXB": "NXB01",
  "DT": "0844643",
  "EMAIL": "nxb@gmail.com",
  "TTSACH": [
    { "MASACH": "S01", "NAM": "2019" },
    { "MASACH": "S01", "NAM": "2020", "TEN": "ABC" }
  ]
}
```

### 10.4 Chuyển sang Column

- Giữ nguyên tư tưởng bảng nhưng lưu theo cột, mỗi dòng chỉ lưu trữ các cột có giá trị (không chứa null).

| Tacgia | |
|---|---|
| Ho | Ten |
|---|---|
| TG01 | Nguyen | A |
| HoVaTen |
| TG02 | Nguyen B |

- Số cột mỗi dòng khác nhau: dòng TG01 tách thành 2 cột (Ho, Ten), dòng TG02 gộp thành 1 cột (HoVaTen).

### 10.5 Chuyển sang Graph

- Đối tượng (bảng) trở thành nút (node), bảng quan hệ (TG-SACH) trở thành cạnh (edge) mang thuộc tính.
- Ví dụ: 3 đối tượng TACGIA, SACH, NXB với 4 thể hiện => 4 nút (TG01, TG02, S01, NXB01), các cạnh:

```text
TG01 --(VIET "NAM":2019)--> S01
TG02 --(VIET "NAM":2020)--> S01
TG01 --(CUA)--> S01
TG02 --(CUA)--> S01
S01  --(THUOC)--> NXB01
NXB01 --(XUAT_BAN)--> S01
```

## 11. So sánh giữa các mô hình

| Tiêu chí | Key-value | Document | Column | Graph |
|---|---|---|---|---|
| Đơn vị dữ liệu | Cặp khoá - giá trị | Tài liệu (JSON...) | Bảng cột (wide-column) | Nút và cạnh |
| Lược đồ | Không có | Tự do | Cột linh hoạt | Có lược đồ định nghĩa phạm vi |
| Truy vấn | Theo khoá | Theo khoá và nội dung | Theo cột/khoá | Duyệt quan hệ (traversal) |
| Thế mạnh | Tốc độ, bộ đệm | Dữ liệu bán cấu trúc | Dữ liệu khổng lồ, phân tán | Dữ liệu nhiều liên kết |
| Ứng dụng | Từ điển, cache | Mạng xã hội, web | Lưu trữ hàng loạt | Mạng xã hội, khuyến nghị, phân tích liên kết |
| Sản phẩm | Redis | MongoDB | Cassandra | Neo4j |

Tham khảo chi tiết hơn: https://arxiv.org/ftp/arxiv/papers/1307/1307.0191.pdf

## 12. Đặc điểm của CSDL phi quan hệ

### Non-relational (phi quan hệ)

- Các mô hình không có mối quan hệ ràng buộc lẫn nhau.
- Có thể có cấu trúc dữ liệu phức tạp hơn nhưng không cứng nhắc như mô hình quan hệ.
- Không sử dụng các ràng buộc dữ liệu để đảm bảo nhất quán.

### Distributed storage (lưu trữ phân tán)

- CSDL NoSQL được phân tán sang nhiều máy tính khác nhau để cung cấp dữ liệu cho người dùng.
- Mỗi phần dữ liệu được nhân rộng trên một số lượng nhất định máy dự phòng với tính sẵn sàng đáp ứng cao.

### Eventual consistency (nhất quán cuối)

- Tính nhất quán không cần đảm bảo ngay tức khắc sau mỗi tác vụ ghi.
- Thay đổi lan truyền theo phương thức lan truyền; sau một khoảng thời gian, thay đổi sẽ đi đến mọi điểm trong hệ thống.
- Cuối cùng (eventually) dữ liệu trên hệ thống trở lại trạng thái nhất quán.

### Vertical scalable (mở rộng chiều dọc)

- Khi dữ liệu lớn về lượng, tăng khả năng lưu trữ và xử lý bằng cách cải tiến phần mềm và cải thiện phần cứng trên một máy tính đơn lẻ.

## 13. Các CSDL phi quan hệ thường gặp

| CSDL | Mô hình |
|---|---|
| MongoDB | Document |
| Cassandra | Column |
| Redis | Key-value |

Tham khảo bảng xếp hạng: https://db-engines.com/en/ranking

## 14. Tổng kết

1. CSDL phi quan hệ được thiết kế nhằm phá bỏ một số nguyên tắc nhất định của CSDL quan hệ => linh hoạt, uyển chuyển. Trong đó **Consistency và Isolation bị thu hồi**.
2. Các mô hình CSDL NoSQL thường gặp: Hướng tài liệu (document), hướng cột (column), khoá - giá trị (key-value) và đồ thị (graph).
3. Các CSDL phi quan hệ thường gặp: MongoDB (document), Cassandra (column), Redis (key-value) ...

## 15. Phụ lục: Thực nghiệm so sánh CSDL quan hệ và phi quan hệ

- Bài toán: So sánh thời gian thực thi của các thao tác truy xuất đọc/ghi vào CSDL.
- CSDL minh hoạ:
  - CSDL quan hệ: MySQL (tương đương MSSQL).
  - CSDL phi quan hệ (hướng tài liệu): MongoDB.

Kết quả và nhận xét:

- Chi phí thời gian thực hiện thao tác **xem** (tìm kiếm) của MongoDB vượt xa so với MSSQL.
- Chi phí thời gian thực hiện thao tác **thêm** của MongoDB vượt trội so với MSSQL.
- Chi phí thời gian thao tác **cập nhật** của MongoDB và MSSQL khá cân bằng.
- Rõ ràng MongoDB rất phù hợp cho các ứng dụng có dữ liệu lớn phục vụ hai thao tác tìm kiếm và thêm - đây cũng là đặc trưng của ứng dụng mạng xã hội.

## 16. Bài tập

**Bài tập 1: Chuyển đổi mô hình quan hệ sang NoSQL**
- Cho mô hình quan hệ: SINHVIEN (#mssv, hoten, sdt, email), LOP (#malop, tenlop), SV_LOP (#mssv, #malop, nam_nhaphoc).
- Chuyển mô hình trên lần lượt sang các mô hình: key-value, document (JSON), column (bảng hướng cột), graph (vẽ nút - cạnh).

**Bài tập 2: Truy vấn NoSQL**
- Viết câu truy vấn MongoDB lấy danh sách sinh viên của một lớp.
- Viết câu lệnh CQL (Cassandra) tạo bảng và chèn một sinh viên.
- Viết truy vấn Cypher (Neo4j) tìm sinh viên cùng lớp.

**Bài tập 3: So sánh thực nghiệm**
- Cài đặt MySQL và MongoDB trên cùng một máy.
- Chuẩn bị một lượng dữ liệu lớn, đo thời gian thực hiện thao tác thêm, sửa, xem trên cả hai CSDL.
- Nhận xét kết quả theo kết luận trong bài học (thêm/xem MongoDB nhanh hơn, sửa cân bằng).

**Bài tập 4: Tìm hiểu thực tế**
- Truy cập https://db-engines.com/en/ranking, liệt kê 5 CSDL NoSQL phổ biến nhất và xác định mô hình của từng CSDL.

## 17. Tài liệu tham khảo

1. Nguyễn Gia Tuấn Anh, Trương Châu Long, *Bài tập và bài giải SQL Server*, NXB Thanh niên (2005)
2. Đỗ Phúc, Nguyễn Đăng Tỵ, *Cơ sở dữ liệu*, NXB Đại học quốc gia TPHCM (2010)
3. Nguyễn Gia Tuấn Anh, Mai Văn Cường, Bùi Danh Hường, *Cơ sở dữ liệu nâng cao*, NXB Đại học quốc gia TPHCM (2019)
4. Itzik Ben-Gan, *Microsoft SQL Server 2012 - TSQL Fundamentals*
5. So sánh các mô hình dữ liệu NoSQL: https://arxiv.org/ftp/arxiv/papers/1307/1307.0191.pdf
6. Bảng xếp hạng CSDL (DB-Engines): https://db-engines.com/en/ranking