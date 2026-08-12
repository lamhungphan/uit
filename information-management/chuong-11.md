# Chương 11 - Mô hình CSDL tiên tiến: Cơ sở dữ liệu di động

## 1. Tổng quan

### Cách tiếp cận đối với CSDL di động

- Hiện nay hầu hết các nhà phát triển ứng dụng di động sử dụng "các tập tin phẳng" (flat file) để lưu trữ dữ liệu ứng dụng.
- Một "tập tin phẳng" là một tập tin có chứa các bản ghi mà không có mối tương quan có cấu trúc.
  - Ưu điểm: nhỏ và dễ dàng hơn để quản lý.
  - Nhược điểm: các ứng dụng cần phải biết cách tổ chức của các bản ghi trong tập tin; các nhà phát triển phải tự thực hiện các chức năng của một cơ sở dữ liệu cần thiết.

### Tại sao cần MDB (Mobile Database)

- Số điện thoại thông minh sử dụng trên toàn thế giới vượt 1 tỷ trong năm 2012.
- Hàng tỷ thiết bị tiếp theo có thể đạt được trong vòng chưa đầy ba năm.
- Nhiều doanh nghiệp chuyển hướng đến nhân viên di động (employee mobility).
- Thiết bị máy tính nhẹ, mạnh mẽ và kết nối di động với chi phí thấp đã mở đường cho các ứng dụng hướng dữ liệu (data driven).
- Điện thoại di động ứng dụng hướng dữ liệu cho phép truy cập dữ liệu từ bất cứ nơi nào, bất cứ lúc nào.

### Ví dụ ứng dụng

- Người bán hàng có thể cập nhật hồ sơ bán hàng trong lúc di chuyển.
- Các phóng viên có thể cập nhật cơ sở dữ liệu thông tin bất cứ lúc nào.
- Các bác sĩ có thể lấy lịch sử y tế của bệnh nhân từ bất cứ nơi nào.
- Điều khiển giao thông.
- Giúp đỡ các trường hợp khẩn cấp: cứu hỏa, y tế.
- Chia sẻ thông tin tìm kiếm trong cộng đồng.

## 2. Định nghĩa CSDL di động

Một cơ sở dữ liệu di động là một cơ sở dữ liệu có thể được kết nối với một thiết bị máy tính bằng thiết bị di động thông qua mạng điện thoại di động không dây.

### Đặc điểm của CSDL di động

- Tách biệt về vật lý từ các máy chủ cơ sở dữ liệu trung tâm.
- Cư trú trên các thiết bị di động.
- Có khả năng giao tiếp với một máy chủ cơ sở dữ liệu trung ương hoặc các máy di động khác từ các site từ xa.
- Xử lý các truy vấn cục bộ không có kết nối.

## 3. Các mô hình kết nối với CSDL di động

1. Mô hình client-server Mobile Databases.
2. Mô hình Peer-to-Peer Mobile Databases.

### Mô hình client-server Mobile Databases

- Là mô hình truyền thống của các hệ thống thông tin.
- Là mô hình chủ đạo cho cơ sở dữ liệu điện thoại di động hiện có.
- Các máy chủ là một điểm duy nhất nên có thể tạo ra hiện tượng nút thắt cổ chai (Bottleneck).

### Mô hình Peer-to-Peer (P2P) Mobile Databases

- Trong cơ sở dữ liệu điện thoại di động P2P, các hoạt động đảm bảo cơ sở dữ liệu được phân bố cho các máy khách.
- Mỗi quá trình đóng một phần vai trò của máy chủ, bên cạnh vai trò của máy khách.
- Một máy khách nào muốn truy cập vào một mảnh của dữ liệu sẽ gửi yêu cầu cho máy khách khác, và chúng chuyển tiếp yêu cầu đến khi dữ liệu được tìm thấy.
- Các vấn đề lớn trong mô hình này là đảm bảo sự sẵn có của dữ liệu.

### Đặc điểm của môi trường di động

- Băng thông không dây và tốc độ truyền thông hạn chế.
- Kích thước màn hình làm giới hạn output.
- Khả năng truy vấn hạn chế đối với đầu vào.
- Hạn chế tính toán & dung lượng lưu trữ.
- An ninh yếu.
- Ngắt kết nối (disconnect).

## 4. Các yêu cầu đối với CSDL di động

### Các yêu cầu chính

1. Tối ưu hóa hệ thống lưu trữ.
2. Đồng bộ dữ liệu.
3. An ninh.
4. Tiêu thụ điện năng thấp.
5. Tự quản lý.
6. Nhúng trong ứng dụng.

### 1. Tối ưu hóa hệ thống lưu trữ

Hệ thống lưu trữ tối ưu cần có những tính năng:

- Kích thước nhỏ.
- Đề kháng tốt với sốc.
- Tiêu thụ điện năng thấp.
- Thời gian truy cập nhanh.

### 2. Đồng bộ hóa dữ liệu

- Thiết bị cầm tay không thể kết nối mọi lúc.
- Người dùng có thể truy cập và thao tác dữ liệu trên các thiết bị của họ.
- Người dùng cũng không thể lưu trữ một lượng lớn dữ liệu do thiếu khả năng lưu trữ.
- DBMS di động nên có chức năng đồng bộ hóa để tích hợp các phiên bản khác nhau của dữ liệu vào một phiên bản phù hợp.

### 3. An toàn (Security)

- Dữ liệu được truyền qua một mạng không dây cần đặt ra các vấn đề an ninh.
- DBMS Mobile nên thực hiện một sự an toàn tuyệt đối end-to-end để đảm bảo việc chuyển giao an toàn của dữ liệu.

### 4. Tiêu thụ điện năng thấp

- Tuổi thọ pin của điện thoại di động dự kiến sẽ chỉ tăng 20% trong 10 năm tiếp theo.
- Bộ vi xử lý, hiển thị và kết nối mạng là những bộ phận tiêu hao điện năng chính trong một thiết bị di động.
- DBMS di động cần phải được tối ưu hóa cho tiêu thụ năng lượng hiệu quả.

### 5. Tự quản lý (Self-management)

- Trong cơ sở dữ liệu truyền thống, người quản trị cơ sở dữ liệu (DBA) chịu trách nhiệm bảo trì cơ sở dữ liệu.
- Trong DBMS di động có thể không có DBA để quản lý cơ sở dữ liệu.
- DBMS di động cần phải hỗ trợ tự quản lý và tự động thực hiện các nhiệm vụ của DBA.
- Một số DBMS di động cho phép quản lý từ xa.

### 6. Có thể nhúng trong các ứng dụng

- Các quản trị viên không có quyền truy cập trực tiếp đến các thiết bị di động.
- DBMS Mobile là một phần không thể thiếu của các ứng dụng, có thể được cung cấp như một phần của ứng dụng.
- Các cơ sở dữ liệu phải được nhúng như là một tập tin DLL/SDK trong ứng dụng.

## 5. Hệ quản trị CSDL di động

### Các yêu cầu về mặt chức năng

- Giao tiếp với máy chủ cơ sở dữ liệu tập trung thông qua các chế độ như truy cập không dây hoặc Internet.
- Sao chép dữ liệu trên máy chủ cơ sở dữ liệu tập trung và thiết bị di động.
- Đồng bộ hóa dữ liệu trên máy chủ cơ sở dữ liệu tập trung và thiết bị di động.
- Thu thập dữ liệu từ các nguồn khác nhau như Internet.
- Quản lý/phân tích dữ liệu trên thiết bị di động.
- Tạo ra các ứng dụng di động tùy chỉnh.

### Một số hệ quản trị CSDL di động

- Sybase SQL Anywhere.
- Oracle Lite.
- Microsoft SQL Server Compact.
- SQLite.
- IBM DB2 Everyplace (DB2e).

#### SAP SQL Anywhere

- Được đưa ra trong năm 1995.
- Thống trị lĩnh vực cơ sở dữ liệu di động với khoảng 68% thị trường.
- File cơ sở dữ liệu độc lập với hệ điều hành và có thể chuyển giao giữa các HĐH được hỗ trợ.
- Mã hóa được hỗ trợ mạnh mẽ.

#### Oracle Lite

- Omniscience Object Technology, Inc đã được mua lại bởi tập đoàn Oracle năm 1996.
- Chạy dưới 1 MB bộ nhớ và có thể được cài đặt trong 3 MB không gian đĩa cứng.
- Dùng cơ sở dữ liệu quan hệ một người dùng.

#### Microsoft SQL Server Compact

- Trước đây được gọi là SQL Server Mobile Edition.
- Miễn phí để tải về và phân phối.
- Cần bộ nhớ khoảng 2 MB, 5 MB cho lưu trữ và thực thi.

#### SQLite

- Là một cơ sở dữ liệu điện thoại di động mã nguồn mở.
- Ít cần cấu hình với máy chủ.
- Là một lựa chọn phổ biến như cơ sở dữ liệu di động.
- Thực hiện hầu hết các tiêu chuẩn SQL-92.

#### DB2e

- Có thị phần lớn nhất sau SQL Anywhere.
- Có bộ nhớ nhỏ nhất (350 KB) so với các cơ sở dữ liệu điện thoại di động thương mại khác.
- Đã bị ngưng vào tháng 4, 2013.
- IBM đã thay thế DB2e với IBM solidDB.
- SolidDB là một trong những MDBMS có các tính năng trên dữ liệu khá tốt.

#### PicoDBMS

- Hỗ trợ đầy đủ các chức năng cho ứng dụng trên thẻ thông minh (smart card).
- Ứng dụng thẻ thông minh được sử dụng để quản lý dữ liệu như chèn, xóa, cập nhật và tìm kiếm.
- Hỗ trợ một phần của SQL:
  - INSERT, UPDATE, DELETE
  - CREATE / DROP TABLE
  - GRANT
- Kích thước của PicoDBMS: 30 KBytes.

#### TinyDB

- Được phát triển tại Đại học Berkeley.
- Chỉ hỗ trợ các chức năng cần thiết cho các ứng dụng cảm biến.
- Hầu hết các ứng dụng cảm biến được sử dụng để lọc ra một số dữ liệu với điều kiện nhất định.
- Chỉ hỗ trợ hoạt động SELECT của SQL chuẩn.
- Bộ nhớ của nó: 3 KBytes.

## 6. Các vấn đề mà MDB cần xử lý

- Xử lý truy vấn.
- Điều khiển tính đồng thời.
- Quản lý giao tác và khôi phục.

### Xử lý truy vấn

- Các loại query:
  - Location dependent query (truy vấn phụ thuộc vị trí).
  - Location independent query (truy vấn độc lập vị trí).
- Các ràng buộc:
  - Query response time (thời gian phản hồi truy vấn).
  - Search-result accuracy (độ chính xác của kết quả tìm kiếm).
  - Throughput: số lượng truy vấn trên mỗi đơn vị thời gian.

## 7. Các thách thức ở tương lai

- Indexing and storage of mobile data (đánh chỉ mục và lưu trữ dữ liệu di động).
- Efficient query processing and retrieval of mobile data (xử lý truy vấn và truy xuất dữ liệu di động hiệu quả).
- Content adaptation and information presentation for small display (thích nghi nội dung và trình bày thông tin cho màn hình nhỏ).
- User interface design for mobile search (thiết kế giao diện người dùng cho tìm kiếm di động).
- Automatic summarization and personalization of mobile data (tóm tắt tự động và cá nhân hóa dữ liệu di động).
- Scalable algorithms for large mobile databases (thuật toán mở rộng cho cơ sở dữ liệu di động lớn).
- Knowledge sharing among mobile peers (chia sẻ tri thức giữa các thiết bị di động ngang hàng).
- Security and trusted retrieval of mobile data (an ninh và truy xuất đáng tin cậy dữ liệu di động).
- Location-based search for mobile devices (tìm kiếm dựa trên vị trí cho thiết bị di động).

## 8. Tổng kết

1. Các nhu cầu của CSDL di động: sự phát triển của các thiết bị di động, các ứng dụng cần lưu trữ dữ liệu trên thiết bị di động.
2. Các yêu cầu cụ thể của CSDL di động.
3. Các đặc điểm mà một CSDL di động cần có.
4. Một số hệ quản trị CSDL thường gặp.

## 9. Bài tập

- Tìm hiểu CSDL mà ứng dụng Viber đã triển khai. Cho biết nó thuộc phân loại nào so với lý thuyết?

## 10. Tài liệu tham khảo

1. Nguyễn Gia Tuấn Anh, Trương Châu Long, *Bài tập và bài giải SQL Server*, NXB Thanh niên (2005).
2. Đỗ Phúc, Nguyễn Đăng Tỵ, *Cơ sở dữ liệu*, NXB Đại học quốc gia TPHCM (2010).
3. Nguyễn Gia Tuấn Anh, Mai Văn Cường, Bùi Danh Hường, *Cơ sở dữ liệu nâng cao*, NXB Đại học quốc gia TPHCM (2019).
4. Itzik Ben-Gan, *Microsoft SQL Server 2012 - TSQL Fundamentals*.