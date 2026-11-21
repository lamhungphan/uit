# Tổng quan môn Xác suất & Thống kê

Môn học được chia thành hai phần. Phần xác suất trả lời câu hỏi “khả năng xảy ra là bao nhiêu?”, còn phần thống kê trả lời “từ dữ liệu quan sát được, ta có thể nói gì về đại lượng chưa biết?”

Luồng học dễ nhớ:

1. Xác định phép thử và các kết quả có thể.
2. Gán xác suất cho từng kết quả.
3. Dùng biến ngẫu nhiên để diễn đạt kết quả bằng con số.
4. Nhận diện mô hình phân phối phù hợp.
5. Dùng quy luật số lớn và giới hạn trung tâm để hiểu hành vi của mẫu.
6. Lấy mẫu, ước lượng tham số hoặc kiểm định tuyên bố.
7. Phân tích quan hệ giữa hai đại lượng.

---

# Chương 1. Xác suất của biến cố

## Ý chính

Chương này dạy cách mô tả một phép thử và tính khả năng một kết quả xảy ra.

Mỗi phép thử có:

- Không gian mẫu: tập hợp tất cả kết quả có thể.
- Biến cố: một nhóm kết quả mà ta quan tâm.

Ví dụ, khi tung một con xúc xắc, không gian mẫu gồm sáu mặt. Biến cố “ra số chẵn” gồm ba mặt: 2, 4 và 6.

## Các phép toán với biến cố

Hai biến cố có thể được kết hợp để mô tả các tình huống phức tạp:

- Hoặc xảy ra một trong hai biến cố.
- Cả hai cùng xảy ra.
- Một biến cố xảy ra nhưng biến cố kia không xảy ra.
- Biến cố đối lập: kết quả ngược lại với điều ta đang xét.
- Hai biến cố xung khắc: không thể cùng xảy ra trong một lần thử.
- Hệ đầy đủ: nhiều khả năng khác nhau, không trùng nhau và bao phủ mọi kết quả.

Một ví dụ dễ nhớ: tung xúc xắc thì mặt chẵn và mặt lẻ xung khắc. Đồng thời, hai biến cố này cũng tạo thành một hệ đầy đủ vì mọi kết quả đều thuộc một trong hai nhóm.

## Khi nào dùng xác suất cổ điển

Nếu mọi kết quả đều đồng khả năng, xác suất bằng:

> số trường hợp thuận lợi chia cho tổng số trường hợp.

Chẳng hạn chọn ngẫu nhiên một học sinh trong nhóm thì học sinh nào cũng có cơ hội được chọn như nhau.

Chương này chủ yếu dùng xác suất cổ điển để kết hợp đếm tổ hợp.

## Xác suất thống kê và xác suất hình học

Nếu không thể đếm kết quả lý thuyết, ta có thể lặp phép thử và xem tần suất xuất hiện biến cố. Khi số lần thử tăng, tần suất thường càng gần xác suất thực.

Xác suất hình học dùng khi kết quả rơi ngẫu nhiên vào một vùng hình học. Xác suất bằng tỉ lệ diện tích, độ dài hoặc thể tích của vùng quan tâm trên vùng tổng thể.

## Công thức cộng

Công thức cộng dùng để tính xác suất xuất hiện ít nhất một trong hai biến cố.

Nếu hai biến cố có thể đồng thời xảy ra, cần trừ phần giao để không đếm hai lần. Nếu hai biến cố xung khắc, xác suất tổng bằng tổng xác suất vì không có phần trùng nhau.

Một bài thường gặp là tính xác suất “ít nhất một lần thành công”. Cách thuận tiện là tính xác suất đối lập “không thành công lần nào”, sau đó lấy 1 trừ đi xác suất đó.

## Xác suất có điều kiện

Xác suất có điều kiện là xác suất của một biến cố khi đã biết một biến cố khác đã xảy ra.

Ví dụ, xác suất một người là nữ là 50% trong toàn bộ nhóm. Nhưng nếu đã biết người đó là 18 tuổi, xác suất là nữ chỉ được tính trong nhóm người 18 tuổi. Không gian quan sát đã bị thu hẹp.

Tư duy quan trọng:

- Không gian mẫu ban đầu là toàn bộ phép thử.
- Sau khi biết điều kiện, không gian mẫu chỉ còn phần tương ứng với điều kiện.

## Công thức nhân

Công thức nhân dùng khi nhiều bước xảy ra liên tiếp:

- Không độc lập: xác suất bước sau thay đổi tùy kết quả của bước trước.
- Độc lập: kết quả bước trước không làm thay đổi xác suất bước sau.

Trong bài lấy bóng không hoàn lại, xác suất lá bài thứ hai phụ thuộc vào lá bài đã lấy ở bước đầu. Trong bài tung nhiều đồng xu độc lập, xác suất của đồng xu sau không bị ảnh hưởng bởi đồng xu trước.

## Công thức xác suất đầy đủ

Công thức đầy đủ dùng khi kết quả quan tâm có thể xảy ra theo nhiều nguyên nhân khác nhau.

Tư duy là chia bài toán thành các nhánh:

1. Hãy xác định xem biến cố đã xảy ra qua nguyên nhân nào.
2. Tính xác suất đi qua từng nhánh.
3. Cộng xác suất của tất cả các nhánh.

Ví dụ, xác suất mua được bóng tốt bằng tổng của:

- xác suất mua bóng trắng nhân xác suất bóng trắng là tốt;
- xác suất mua bóng vàng nhân xác suất bóng vàng là tốt.

## Công thức Bayes

Bayes làm điều ngược lại: đã quan sát được kết quả, muốn truy ra nguyên nhân có khả năng nhất.

Ví dụ:

- Biết một sản phẩm là hỏng.
- Muốn biết nó có khả năng do phân xưởng nào sản xuất.

Công thức Bayes dùng xác suất ban đầu của từng phân xưởng và xác suất hỏng của từng phân xưởng để tính xác suất nguyên nhân sau khi đã thấy sản phẩm hỏng.

## Phép thử Bernoulli

Một phép thử Bernoulli chỉ có hai kết quả: thành công hoặc thất bại.

Nếu lặp lại nhiều lần độc lập, xác suất thành công không đổi, ta có mô hình nhị thức ở chương sau.

---

# Chương 2. Biến ngẫu nhiên

## Ý chính

Chương này biến các kết quả khác nhau của phép thử thành con số để thuận tiện phân tích.

Ví dụ tung hai đồng xu, ta có thể gọi biến ngẫu nhiên là số lần xuất hiện mặt ngửa. Kết quả của phép thử được quy thành 0, 1 hoặc 2.

## Hai loại biến ngẫu nhiên

### Biến rời rạc

Nhận giá trị đếm được:

- số khách đến cửa hàng;
- số câu làm đúng;
- số sản phẩm hỏng;
- số lần tung ra mặt ngửa.

Biến rời rạc được mô tả bằng bảng phân phối xác suất. Mỗi giá trị có xác suất riêng và tổng xác suất bằng 1.

### Biến liên tục

Nhận giá trị trong một khoảng:

- chiều cao;
- tuổi thọ;
- thời gian chờ;
- tốc độ truyền dữ liệu.

Biến liên tục dùng hàm mật độ. Không thể nói xác suất tại đúng một giá trị mà cần nói xác suất nằm trong một khoảng. Xác suất là diện tích dưới đường cong mật độ.

## Hàm phân phối

Hàm phân phối trả lời:

> Biến ngẫu nhiên nhận giá trị nhỏ hơn hoặc bằng mức nào đó với xác suất bao nhiêu?

Với biến rời rạc, hàm phân phối là hàm bậc thang: mỗi khi đi qua một giá trị có thể thì xác suất tích lũy tăng lên.

Với biến liên tục, hàm phân phối tăng dần từ 0 đến 1. Xác suất nằm trong một khoảng bằng chênh lệch hai giá trị của hàm phân phối.

## Kỳ vọng

Kỳ vọng là giá trị trung bình mà ta mong đợi theo xác suất.

Nó không nhất thiết là một giá trị có thể xảy ra. Ví dụ kỳ vọng khi tung xúc xắc là 3,5 nhưng không có mặt xúc xắc nào ghi 3,5.

Trong kinh doanh, kỳ vọng lợi nhuận giúp so sánh hai phương án. Phương án nào có kỳ vọng cao hơn thường tốt hơn về mặt trung bình, nhưng chưa chắc ít rủi ro.

## Mode và trung vị

- Mode: giá trị có khả năng hoặc mật độ xuất hiện cao nhất.
- Trung vị: giá trị nằm chính giữa theo xác suất; 50% nằm dưới và 50% nằm trên.

Mode trả lời “giá trị nào dễ gặp nhất”, còn trung vị trả lời “điểm chia đôi phân phối”.

Trung bình có thể bị kéo bởi giá trị rất lớn hoặc rất nhỏ. Trung vị thường bền hơn trong dữ liệu có nhiễu.

## Phương sai và độ lệch chuẩn

Phương sai và độ lệch chuẩn mô tả mức độ phân tán.

- Phương sai nhỏ: giá trị tập trung quanh kỳ vọng.
- Phương sai lớn: giá trị trải rộng.
- Độ lệch chuẩn: đơn vị giống với biến, nên dễ diễn giải hơn phương sai.

Trong sản xuất, phương sai nhỏ thường đồng nghĩa máy móc ổn định. Trong đầu tư, phương sai lớn thường đồng nghĩa rủi ro cao.

---

# Chương 3. Phân phối xác suất thông dụng

## Ý chính

Chương này cung cấp các mô hình có sẵn để nhận diện nhanh bài toán thay vì lập bảng xác suất từ đầu.

## Phân phối Siêu bội

Dùng khi lấy một số phần tử **không hoàn lại** từ một tổng thể hữu hạn.

Ví dụ:

- chọn một nhóm sản phẩm từ một lô hàng;
- chọn bi từ hộp mà không bỏ lại;
- chọn người từ một danh sách đã cho.

Nếu tổng thể đủ lớn so với số phần tử lấy ra, việc lấy có hay không hoàn lại gần như không khác nhau.

## Phân phối Bernoulli

Dùng khi phép thử chỉ có hai kết quả:

- đạt hoặc không đạt;
- tốt hoặc hỏng;
- mua hoặc không mua;
- đúng hoặc sai.

Đây là viên gạch cơ bản của các mô hình nhị thức.

## Phân phối Nhị thức

Dùng khi lặp nhiều phép thử Bernoulli độc lập, xác suất thành công không đổi và ta quan tâm số lần thành công.

Ví dụ:

- trắc nghiệm nhiều câu;
- kiểm tra nhiều sản phẩm;
- 100 khách hàng có mua hay không mua;
- gieo một đồng xu nhiều lần.

Ba tham số cần nhìn là số lần thử, xác suất thành công mỗi lần và số lần thành công cần tìm.

## Phân phối Poisson

Dùng để đếm số sự kiện trong một khoảng thời gian hoặc không gian.

Ví dụ:

- số khách đến cửa hàng trong 10 phút;
- số xe đi qua trạm trong 1 giờ;
- số tai nạn trong một ngày;
- số cuộc gọi đến tổng đài trong 1 phút.

Giá trị trung bình trong khoảng quan sát là tham số quan trọng. Chẳng hạn, trung bình 5 phút có 18 khách thì trung bình 7 phút có 25,2 khách.

Poisson thường được dùng khi số lần thử rất lớn và xác suất xảy ra trong từng đơn vị rất nhỏ.

## Phân phối Chuẩn

Phân phối Chuẩn mô tả dữ liệu phân bố đối xứng hình chuông.

- Đỉnh ở trung bình.
- Hai bên đối xứng.
- Giá trị càng xa trung bình thì càng ít gặp.

Nhiều đại lượng có dạng gần chuẩn:

- chiều cao;
- cân nặng;
- điểm thi;
- sai số đo lường;
- thời gian xử lý.

Giá trị trung bình xác định vị trí của chuông. Độ lệch chuẩn xác định chuông rộng hay hẹp.

Quy tắc kinh nghiệm: phần lớn quan sát nằm trong vài độ lệch chuẩn quanh trung bình.

## Phân phối Chi bình phương và Student

Hai phân phối xuất hiện chủ yếu trong thống kê suy luận.

- Chi bình phương liên quan đến tổng các bình phương sai lệch chuẩn, thường dùng cho phương sai.
- Student giống Chuẩn nhưng phình to ở hai đuôi, phù hợp với mẫu nhỏ khi chưa biết độ lệch chuẩn tổng thể.

Khi mẫu lớn, Student thường gần với Chuẩn.

---

# Chương 4. Định lý giới hạn

## Ý chính

Chương này giải thích vì sao dữ liệu nhiều lần quan sát lại trở nên ổn định và vì sao phân phối Chuẩn xuất hiện nhiều.

## Bất đẳng thức Tchébyshev

Tchébyshev cho ta một giới hạn bảo thủ về xác suất một biến ngẫu nhiên lệch xa trung bình.

Nó không cần biết phân phối cụ thể. Dù hơi lỏng, bất đẳng thức vẫn giúp đánh giá khả năng xảy ra các kết quả lệch xa.

## Luật số lớn

Khi thực hiện phép thử độc lập nhiều lần:

- trung bình mẫu tiến gần trung bình tổng thể;
- tần suất của biến cố tiến gần xác suất lý thuyết;
- kết quả càng ổn định khi số lần quan sát càng lớn.

Đây là cơ sở cho việc đo lặp nhiều lần rồi lấy trung bình.

## Hội tụ theo phân phối

Hội tụ theo phân phối nghĩa là hình dạng phân phối của biến ngẫu nhiên tiến gần một phân phối xác định khi cỡ mẫu tăng.

Đây là cầu nối để dùng phân phối Chuẩn thay cho phân phối rời rạc phức tạp.

## Định lý giới hạn trung tâm

Định lý này nói rằng tổng hoặc trung bình của nhiều biến ngẫu nhiên độc lập thường gần Chuẩn, ngay cả khi từng biến không có phân phối Chuẩn.

Ví dụ, tổng điểm của 30 câu hỏi, tổng cân nặng của 40 người hoặc trung bình thu nhập của một mẫu lớn thường có thể được xem gần Chuẩn.

Quy tắc thực hành trong bài học là:

- Nếu tổng thể đã Chuẩn, trung bình mẫu chuẩn với mọi cỡ mẫu.
- Nếu tổng thể không Chuẩn, trung bình mẫu gần Chuẩn khi mẫu khoảng 30 quan sát trở lên.

## Chuỗi xấp xỉ phân phối

Có thể nhận diện bài toán theo mức độ gần giữa các phân phối:

- Siêu bội → Nhị thức:
  dùng khi lấy mẫu ít so với tổng thể.
- Nhị thức → Poisson:
  dùng khi số lần thử lớn và xác suất thành công rất nhỏ.
- Nhị thức → Chuẩn:
  dùng khi số lần thử đủ lớn và xác suất không quá gần 0 hoặc 1.

Khi dùng Chuẩn thay cho Nhị thức, cần điều chỉnh 0,5 vì Nhị thức cho giá trị nguyên còn Chuẩn cho giá trị liên tục.

---

# Chương 5. Lý thuyết mẫu

## Ý chính

Chương này giải thích cách lấy một phần dữ liệu để suy ra đặc điểm của toàn bộ tổng thể.

## Tổng thể và mẫu

Tổng thể là toàn bộ đối tượng cần biết. Mẫu là tập con được quan sát.

Ví dụ:

- Muốn biết chiều cao trung bình của mọi sinh viên: tất cả sinh viên là tổng thể.
- Chọn ngẫu nhiên 100 sinh viên: 100 sinh viên là mẫu.

Lý do lấy mẫu:

- Không thể khảo sát mọi cá thể.
- Tiết kiệm thời gian và chi phí.
- Một số phép kiểm tra làm hỏng sản phẩm nên không thể kiểm tra toàn bộ.

## Mẫu ngẫu nhiên hợp lý

Mẫu cần đại diện cho tổng thể. Để đạt được điều này:

- mọi phần tử có cơ hội được chọn tương đương;
- mẫu không nên chọn chủ yếu trong một nhóm dễ tiếp cận;
- kích thước mẫu phải đủ lớn.

Mẫu chọn thiên lệch có thể cho kết quả chính xác về mặt tính toán nhưng sai về mặt ý nghĩa.

## Dạng dữ liệu mẫu

Một mẫu có thể được trình bày theo ba cách:

- Dạng điểm: ghi từng quan sát.
- Dạng tần số: gom các giá trị trùng nhau.
- Dạng khoảng: chia dữ liệu thành các lớp.

Dạng khoảng tiện đọc và tính toán nhưng làm mất một phần chi tiết vì mỗi quan sát trong lớp được đại diện bằng tâm lớp.

## Trung bình, phương sai và tỷ lệ mẫu

- Trung bình mẫu mô tả xu hướng trung tâm của dữ liệu đã quan sát.
- Phương sai mẫu mô tả dữ liệu phân tán.
- Tỷ lệ mẫu mô tả phần trăm phần tử có tính chất quan tâm.

Khi lấy nhiều mẫu khác nhau, các giá trị trung bình mẫu và tỷ lệ mẫu cũng khác nhau. Vì vậy, chúng phải được xem là biến ngẫu nhiên thay vì một con số duy nhất.

## Phân phối trung bình mẫu

Trung bình của mọi mẫu có:

- kỳ vọng bằng trung bình tổng thể;
- độ phân tán giảm khi cỡ mẫu tăng.

Độ phân tán này nhỏ hơn độ phân tán của từng quan sát vì trung bình đã làm dịu các giá trị cực đoan.

Nếu tổng thể Chuẩn, trung bình mẫu Chuẩn. Nếu tổng thể không Chuẩn và mẫu đủ lớn, trung bình mẫu gần Chuẩn.

## Phân phối tỷ lệ mẫu

Tỷ lệ mẫu từ nhiều mẫu khác nhau cũng có một phân phối.

Khi cỡ mẫu đủ lớn, tỷ lệ mẫu gần Chuẩn, có trung tâm tại tỷ lệ tổng thể và độ phân tán giảm khi cỡ mẫu tăng.

---

# Chương 6. Ước lượng tham số

## Ý chính

Chương này dùng dữ liệu mẫu để phỏng đoán tham số của tổng thể.

## Ước lượng điểm

Ước lượng điểm trả lời bằng một giá trị duy nhất:

- dùng trung bình mẫu để ước lượng trung bình tổng thể;
- dùng tỷ lệ mẫu để ước lượng tỷ lệ tổng thể;
- dùng độ lệch chuẩn mẫu để ước lượng độ lệch chuẩn tổng thể.

Ưu điểm là cho một con số cụ thể. Nhược điểm là không cho biết sai số có thể gặp.

## Ước lượng khoảng

Ước lượng khoảng đưa ra một miền và đi kèm độ tin cậy.

Ví dụ: khoảng 156 đến 173 với độ tin cậy 95% nghĩa là quy tắc lập khoảng này dự kiến bao trúng giá trị tổng thể ở 95 trong 100 lần dựng khoảng từ các mẫu.

Khoảng rộng hơn:

- sai số lớn hơn;
- độ chính xác thấp hơn;
- nhưng độ tin cậy có thể cao hơn.

## Ước lượng trung bình tổng thể

Chọn công thức dựa trên các điều kiện sau:

### Khi biết độ lệch chuẩn tổng thể

Dùng phân phối Chuẩn.

### Khi không biết độ lệch chuẩn tổng thể và mẫu lớn

Thay độ lệch chuẩn tổng thể bằng độ lệch chuẩn có hiệu chỉnh của mẫu, sau đó dùng phân phối Chuẩn xấp xỉ.

### Khi không biết độ lệch chuẩn và mẫu nhỏ

Nếu dữ liệu có phân phối Chuẩn, dùng phân phối Student. Student có hai đuôi dày hơn, vì thiếu thông tin phương sai làm khoảng ước lượng rộng hơn.

## Các bài toán ước lượng thường gặp

### Tìm khoảng

Biết trung bình mẫu, độ lệch chuẩn, cỡ mẫu và độ tin cậy, tính sai số rồi cộng/trừ với trung bình mẫu.

### Tìm độ tin cậy

Biết sai số và dữ liệu mẫu, tìm ngược điểm phân vị tương ứng để suy ra độ tin cậy.

### Tìm cỡ mẫu

Biết sai số tối đa cho phép và độ tin cậy mong muốn, tính cỡ mẫu tối thiểu để đạt yêu cầu.

Sai số mong muốn càng nhỏ thì cỡ mẫu cần càng lớn.

## Ước lượng tỷ lệ

Ước lượng tỷ lệ dùng tỷ lệ trong mẫu để ước lượng tỷ lệ trong tổng thể.

Khoảng ước lượng càng rộng nếu:

- độ tin cậy tăng;
- cỡ mẫu giảm;
- tỷ lệ gần 50%.

Tỷ lệ gần 50% là trường hợp khó dự đoán nhất vì dữ liệu phân tán nhiều nhất.

---

# Chương 7. Kiểm định giả thiết thống kê

## Ý chính

Kiểm định giả thiết là quá trình dùng dữ liệu để quyết định có đủ bằng chứng bác bỏ một tuyên bố hay không.

## Giả thiết gốc và đối thiết

Giả thiết gốc thường là tuyên bố không thay đổi hoặc không có khác biệt:

- trung bình bằng một giá trị;
- tỷ lệ bằng một giá trị;
- không có hiệu ứng.

Đối thiết là kết luận muốn kiểm tra:

- khác giá trị đó;
- lớn hơn giá trị đó;
- nhỏ hơn giá trị đó.

## Hai loại sai lầm

- Sai lầm loại I: bác bỏ giả thiết gốc khi nó đúng.
- Sai lầm loại II: chấp nhận giả thiết gốc khi nó sai.

Trong thực tế, sai lầm loại I thường được xem nguy hiểm hơn. Vì vậy, mức ý nghĩa thường được chọn rất nhỏ, như 5% hoặc 1%.

## Quy trình kiểm định

1. Lập giả thiết gốc và đối thiết.
2. Chọn mức ý nghĩa.
3. Tính thống kê kiểm định từ mẫu.
4. Xác định miền bác bỏ dựa trên phân phối của thống kê.
5. Nếu giá trị mẫu rơi trong miền bác bỏ, kết luận bác bỏ giả thiết gốc.
6. Nếu không rơi trong miền bác bỏ, chỉ kết luận chưa đủ bằng chứng để bác bỏ.

Chưa đủ bằng chứng không đồng nghĩa đã chứng minh giả thiết gốc chắc chắn đúng.

## Kiểm định trung bình

Chọn phân phối kiểm định theo dữ liệu:

- biết độ lệch chuẩn tổng thể: dùng chuẩn hóa kiểu chuẩn.
- không biết độ lệch chuẩn, mẫu lớn: dùng ước lượng độ lệch chuẩn mẫu.
- không biết độ lệch chuẩn, mẫu nhỏ và tổng thể chuẩn: dùng Student.

Sau đó, so giá trị tính được với ngưỡng:

- hai đuôi: kết luận thay đổi nếu giá trị nằm xa hai phía.
- đuôi phải: kết luận trung bình lớn hơn giá trị giả thiết.
- đuôi trái: kết luận trung bình nhỏ hơn giá trị giả thiết.

## Kiểm định tỷ lệ

Kiểm định tỷ lệ dùng tỷ lệ trong mẫu để xem có phù hợp với tỷ lệ được tuyên bố trong tổng thể hay không.

Bài toán thường xuất hiện dưới dạng:

- đảng chính trị tuyên bố tỷ lệ cử tri;
- nhà máy tuyên bố tỷ lệ sản phẩm hỏng;
- công ty tuyên bố tỷ lệ khách hàng hài lòng.

## Ý nghĩa kết quả

Nếu bác bỏ giả thiết gốc, có bằng chứng mẫu đủ mạnh cho đối thiết ở mức ý nghĩa đã chọn.

Nếu không bác bỏ, ta chỉ nói dữ liệu hiện tại chưa cung cấp bằng chứng đủ mạnh.

---

# Chương 8. Tương quan và hồi quy

## Ý chính

Chương này phân tích quan hệ giữa hai đại lượng số.

## Biểu đồ phân tán

Mỗi quan sát là một cặp giá trị. Vẽ các cặp trên mặt phẳng tọa độ giúp nhận ra xu hướng:

- hai đại lượng tăng cùng nhau;
- một đại lượng tăng thì đại lượng kia giảm;
- quan hệ cong;
- không có xu hướng rõ ràng;
- có điểm bất thường.

Biểu đồ phân tán là bước đầu bắt buộc trước khi tính các chỉ số hồi quy.

## Hệ số tương quan

Hệ số tương quan đo mức độ đi cùng nhau theo đường thẳng.

- Gần 1: tương quan tuyến tính thuận mạnh.
- Gần -1: tương quan tuyến tính nghịch mạnh.
- Gần 0: gần như không có quan hệ tuyến tính.

Tương quan không chứng minh nhân quả. Hai đại lượng có thể cùng tăng vì cùng chịu ảnh hưởng của một yếu tố thứ ba.

Ví dụ, bán kem và tai nạn ở bể bơi có thể tăng cùng mùa hè mà không có quan hệ nguyên nhân trực tiếp.

## Hồi quy tuyến tính

Hồi quy tìm một đường thẳng mô tả mối quan hệ để dự đoán đại lượng này từ đại lượng kia.

Phương pháp bình phương bé nhất chọn đường thẳng làm cho tổng sai khác bình phương giữa dữ liệu thực và đường dự đoán là nhỏ nhất.

Khi hồi quy $Y$ theo $X$:

- $X$ là biến biết trước hoặc biến độc lập.
- $Y$ là đại lượng cần dự đoán hoặc biến phụ thuộc.

Ví dụ, chiều dài cá dùng để dự đoán cân nặng. Trường hợp này, chiều dài là $X$ và cân nặng là $Y$.

## Hướng hồi quy

Phương trình hồi quy $Y$ theo $X$ không thể đảo vai trò để tự động trở thành phương trình $X$ theo $Y$.

Vì sai số được tối thiểu hóa theo hướng biến phụ thuộc khác nhau nên hai phương trình hồi quy thường khác nhau.

## Ý nghĩa kết quả

Hệ số góc cho biết mỗi khi $X$ tăng một đơn vị thì $Y$ dự đoán thay đổi bao nhiêu đơn vị.

Ví dụ, hệ số góc 2 kg trên năm kinh nghiệm nghĩa là, trong miền dữ liệu quan sát, mỗi năm kinh nghiệm tương ứng với số liệu dự đoán tăng trung bình 2 kg về đại lượng được phân tích.

Hồi quy chỉ nên dùng để dự đoán trong hoặc gần miền dữ liệu đã quan sát. Dự đoán xa khỏi miền dữ liệu có thể sai lệch lớn.

---

# Bảng tra nhanh cách nhận diện bài toán

| Dữ liệu / yêu cầu | Mô hình hoặc công cụ |
|---|---|
| Đếm trường hợp đồng khả năng | Xác suất cổ điển |
| Biết một điều kiện đã xảy ra | Xác suất có điều kiện |
| Hai bước độc lập cùng xảy ra | Công thức nhân |
| Kết quả qua nhiều nhánh | Công thức xác suất đầy đủ |
| Đã biết kết quả, truy nguyên nhân | Công thức Bayes |
| Chỉ hai kết quả, lặp nhiều lần | Nhị thức |
| Chọn không hoàn lại từ tổng thể hữu hạn | Siêu bội |
| Đếm sự kiện trong thời gian hoặc không gian | Poisson |
| Dữ liệu liên tục đối xứng hình chuông | Chuẩn |
| Mẫu lớn, tính xác suất trung bình hoặc tổng | Giới hạn trung tâm |
| Chọn mẫu để suy ra tổng thể | Lý thuyết mẫu |
| Ước lượng trung bình với $\sigma$ đã biết | Khoảng Chuẩn |
| Mẫu nhỏ, $\sigma$ chưa biết, tổng thể Chuẩn | Khoảng Student |
| Ước lượng tỷ lệ tổng thể | Khoảng tỷ lệ |
| Kiểm tra tuyên bố về trung bình | Kiểm định $z$ hoặc $t$ |
| Kiểm tra tuyên bố về tỷ lệ | Kiểm định tỷ lệ |
| Hai đại lượng có đi cùng nhau theo tuyến tính không | Hệ số tương quan |
| Dự đoán đại lượng $Y$ từ $X$ | Hồi quy tuyến tính |
