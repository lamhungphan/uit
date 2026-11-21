# Tổng quan Toán rời rạc

Toán rời rạc nghiên cứu các đối tượng có thể đếm, phân loại hoặc mô tả bằng cấu trúc hữu hạn: mệnh đề đúng/sai, tập hợp, quan hệ, đồ thị và cây. Môn học vừa cung cấp ngôn ngữ để diễn đạt lập luận, vừa đưa ra công cụ để đếm, đơn giản hóa mạch và giải bài toán mạng.

## Mạch nội dung

1. Dùng logic để diễn đạt câu đúng/sai và chứng minh kết luận.
2. Dùng tập hợp để mô tả nhóm đối tượng; dùng nguyên lý đếm để tính số khả năng.
3. Dùng quan hệ để biểu diễn cách các phần tử liên hệ, tương đương hoặc được sắp thứ tự.
4. Dùng đại số Bool để rút gọn biểu thức logic và thiết kế mạch.
5. Dùng đồ thị để mô hình hóa mạng lưới, đường đi và kết nối.
6. Dùng cây để biểu diễn cấu trúc phân cấp, biểu thức và mạng nối tối ưu.

---

# 1. Logic mệnh đề

## Mệnh đề là gì?

Mệnh đề là câu khẳng định có thể xác định là đúng hoặc sai. Câu hỏi, lời cảm thán hoặc biểu thức còn chứa biến chưa biết thường chưa phải mệnh đề, vì chưa xác định được giá trị đúng/sai.

Ta có thể ghép mệnh đề bằng các phép:

- **Phủ định:** đảo đúng thành sai và sai thành đúng.
- **Và:** đúng khi cả hai vế đều đúng.
- **Hoặc:** đúng khi ít nhất một vế đúng.
- **Hoặc loại trừ:** đúng khi chỉ một trong hai vế đúng.
- **Kéo theo:** “nếu điều kiện thì kết quả”; chỉ sai khi điều kiện đúng nhưng kết quả sai.
- **Tương đương:** đúng khi hai vế cùng đúng hoặc cùng sai.

Lưu ý: “hoặc” trong logic thông thường bao gồm cả trường hợp cả hai vế đúng; khác với “hoặc một trong hai” trong đời sống.

## Bảng chân trị và tương đương logic

Bảng chân trị liệt kê mọi cách gán đúng/sai cho các mệnh đề nhỏ rồi tính kết quả biểu thức. Với $n$ mệnh đề nhỏ, bảng có $2^n$ dòng.

Hai biểu thức tương đương logic nếu kết quả của chúng trùng nhau ở mọi dòng. Có thể kiểm tra bằng bảng chân trị hoặc biến đổi bằng các luật logic như De Morgan, phân phối, hấp thụ và luật kéo theo.

Một biểu thức luôn đúng trong mọi trường hợp là **hằng đúng**; luôn sai là **hằng sai**. Chúng hữu ích để kiểm tra lập luận và chứng minh công thức.

## Suy luận và chứng minh

Một lập luận gồm các tiền đề và kết luận. Lập luận hợp lệ nếu không thể có tình huống tất cả tiền đề đúng nhưng kết luận sai.

Các quy tắc thường gặp:

- **Modus Ponens:** biết “nếu $p$ thì $q$” và biết $p$, suy ra $q$.
- **Modus Tollens:** biết “nếu $p$ thì $q$” và biết $q$ sai, suy ra $p$ sai.
- **Tam đoạn luận:** nối hai điều kiện kéo theo thành một chuỗi.
- **Phản ví dụ:** chỉ cần tìm một trường hợp làm phát biểu tổng quát sai.
- **Phản chứng:** giả sử kết luận sai rồi suy ra mâu thuẫn.

Khi kiểm tra một lập luận, đừng nhầm “nghe có vẻ hợp lý” với “được suy ra tất yếu từ tiền đề”. Phương pháp phản ví dụ tìm một phép gán làm tiền đề đúng và kết luận sai; tìm được thì lập luận không hợp lệ.

## Vị từ và lượng từ

Vị từ là câu có biến, chẳng hạn “$x$ là số chẵn”. Thay biến bằng một giá trị cụ thể hoặc thêm lượng từ thì ta mới có một mệnh đề.

- “Với mọi” yêu cầu điều kiện đúng cho tất cả phần tử. Chỉ cần một phản ví dụ là bác bỏ được.
- “Tồn tại” chỉ cần tìm một phần tử làm điều kiện đúng.
- Thứ tự lượng từ lồng nhau quan trọng: “với mọi $x$, tìm được một $y$” không giống “có một $y$ dùng được với mọi $x$”.

Muốn phủ định một mệnh đề có lượng từ, đổi “với mọi” thành “tồn tại”, đổi “tồn tại” thành “với mọi”, rồi phủ định điều kiện bên trong. Ví dụ: phủ định “mọi sinh viên đều đi học” là “có sinh viên không đi học”.

---

# 2. Tập hợp và nguyên lý đếm

## Phép toán tập hợp

Tập hợp gom các phần tử thỏa một điều kiện:

- **Giao:** phần tử nằm trong cả hai tập.
- **Hợp:** phần tử nằm trong ít nhất một tập.
- **Hiệu:** phần tử nằm trong tập thứ nhất nhưng không nằm trong tập thứ hai.
- **Phần bù:** phần tử của tập vũ trụ không nằm trong tập đang xét.

Các phép tập hợp có luật tương tự logic: giao tương ứng với “và”, hợp tương ứng với “hoặc”, phần bù tương ứng với phủ định. Nhờ vậy, có thể kiểm tra đẳng thức tập hợp bằng bảng thuộc tính, giống bảng chân trị.

Nếu biểu diễn tập hữu hạn bằng chuỗi bit, bit 1 nghĩa là phần tử thuộc tập, bit 0 nghĩa là không thuộc. Khi đó, hợp/giao/phần bù tương ứng với các phép OR/AND/NOT trên bit.

## Quy tắc cộng và nhân

- **Quy tắc cộng:** chọn một trong các cách không trùng nhau thì cộng số cách.
- **Quy tắc nhân:** công việc gồm nhiều bước liên tiếp thì nhân số lựa chọn của từng bước.

Ví dụ chọn một bạn nam và một bạn nữ là hai bước nên dùng phép nhân. Chọn một người là nam **hoặc** nữ từ hai nhóm không giao nhau thì dùng phép cộng.

## Bao hàm – loại trừ

Khi hai nhóm có phần giao, cộng kích thước của chúng sẽ đếm phần giao hai lần. Vì vậy phải trừ phần giao một lần. Với nhiều nhóm, các phần giao được cộng/trừ luân phiên.

Hãy dùng phương pháp này cho câu hỏi dạng “thuộc tập A hoặc tập B” khi A và B có thể trùng nhau.

## Nguyên lý chuồng bồ câu

Nếu phân nhiều vật vào ít hộp hơn số vật, ít nhất một hộp phải chứa từ hai vật trở lên. Bản tổng quát cho biết có một hộp chứa ít nhất phần nguyên trên của “số vật chia cho số hộp”.

Cách giải thường là xác định:

1. “Vật” là những đối tượng nào?
2. “Hộp” là những loại/nhóm nào?
3. Chia đều tối đa được bao nhiêu trước khi bắt buộc có một nhóm vượt ngưỡng?

## Hoán vị, chỉnh hợp và tổ hợp

Ba bài toán này khác nhau ở việc có quan tâm thứ tự hay không:

- **Hoán vị:** sắp xếp toàn bộ các phần tử.
- **Chỉnh hợp:** chọn một số phần tử và thứ tự có ý nghĩa.
- **Tổ hợp:** chọn một nhóm phần tử, thứ tự không quan trọng.

Ví dụ chọn ba người vào ba chức vụ khác nhau là chỉnh hợp; chọn ba người cùng đi trực nhật là tổ hợp.

## Nhị thức Newton

Khai triển lũy thừa của tổng bằng các hạng tử có hệ số tổ hợp. Công thức này liên hệ phép khai triển đại số với bài toán đếm số cách chọn. Khi cần hệ số của một hạng tử, tìm số mũ tương ứng rồi lấy hệ số tổ hợp.

---

# 3. Quan hệ

## Quan hệ hai ngôi

Quan hệ giữa các phần tử được biểu diễn bằng các cặp có thứ tự. Ví dụ “đã đăng ký học môn” nối một sinh viên với một môn học; “nhỏ hơn” nối một số với số lớn hơn nó.

Có thể biểu diễn một quan hệ bằng:

- tập các cặp;
- đồ thị có hướng;
- ma trận 0/1.

Trong ma trận, hàng biểu diễn phần tử thứ nhất của cặp, cột biểu diễn phần tử thứ hai. Ô bằng 1 nghĩa là cặp đó thuộc quan hệ.

## Bốn tính chất cần kiểm tra

- **Phản xạ:** mỗi phần tử có quan hệ với chính nó.
- **Đối xứng:** nếu $a$ liên hệ với $b$ thì $b$ cũng liên hệ với $a$.
- **Phản xứng:** nếu hai phần tử khác nhau liên hệ hai chiều thì không được xảy ra; hai chiều chỉ có thể cùng đúng khi hai phần tử bằng nhau.
- **Bắc cầu:** nếu $a$ liên hệ với $b$ và $b$ liên hệ với $c$, thì phải có quan hệ từ $a$ đến $c$.

“Không đối xứng” không đồng nghĩa với “phản xứng”. Khi chứng minh một tính chất, hãy dùng đúng lượng từ và giả thiết của định nghĩa.

## Quan hệ tương đương

Quan hệ tương đương có đủ ba tính chất: phản xạ, đối xứng, bắc cầu. Nó gom các phần tử được xem là “giống nhau” theo một tiêu chí.

Ví dụ, hai số nguyên tương đương modulo 3 nếu chúng có cùng số dư khi chia cho 3. Các phần tử tương đương với nhau tạo thành một **lớp tương đương**. Tất cả lớp tương đương chia tập ban đầu thành những nhóm rời nhau và phủ kín tập đó; cách chia này gọi là một **phân hoạch**.

## Quan hệ thứ tự và biểu đồ Hasse

Quan hệ thứ tự bộ phận cần có phản xạ, phản xứng và bắc cầu. Nếu mọi cặp phần tử đều so sánh được thì là thứ tự toàn phần; nếu có cặp không so sánh được thì là thứ tự bộ phận.

Biểu đồ Hasse giúp vẽ gọn quan hệ thứ tự trên tập hữu hạn:

- đặt phần tử nhỏ hơn ở thấp, lớn hơn ở cao;
- bỏ vòng phản xạ;
- bỏ cạnh có thể suy ra từ một đường đi bắc cầu;
- bỏ mũi tên vì hướng luôn từ thấp lên cao.

---

# 4. Đại số Bool và mạch logic

## Đại số Bool

Đại số Bool làm việc với hai trạng thái 0 và 1, tương ứng với sai/đúng, tắt/bật hoặc mở/đóng.

Các phép cơ bản:

- phủ định đổi 0 thành 1 và ngược lại;
- AND chỉ bật khi mọi đầu vào đều bật;
- OR bật nếu có ít nhất một đầu vào bật.

Các phép này tuân theo nhiều luật giống logic mệnh đề và tập hợp. Dùng chúng để rút gọn biểu thức mà không cần lập bảng chân trị đầy đủ.

## Hàm Bool và dạng nối rời chính tắc

Hàm Bool nhận một nhóm đầu vào 0/1 và cho một đầu ra 0/1. Bảng chân trị mô tả đầy đủ mọi trường hợp đầu vào.

Dạng nối rời chính tắc được lập bằng cách lấy từng dòng có đầu ra 1, viết một hạng tử tương ứng rồi nối các hạng tử bằng OR. Dạng này dễ lập từ bảng nhưng thường dài.

## Biểu đồ Karnaugh

Karnaugh là cách nhìn bảng chân trị như một bản đồ để gom các ô đầu ra bằng 1 thành nhóm kích thước 1, 2, 4, 8,…

- Gom nhóm càng lớn thì càng loại được nhiều biến.
- Các mép của bảng được xem là kề nhau.
- Có thể dùng lại một ô trong nhiều nhóm nếu điều đó giúp nhóm lớn hơn.
- Phải phủ hết ô 1, đồng thời cố gắng dùng ít nhóm lớn nhất.

Kết quả là biểu thức đơn giản hơn, thường cần ít cổng logic hơn khi dựng mạch.

## Cổng logic

AND, OR, NOT là cổng cơ bản. NAND là phủ định của AND; NOR là phủ định của OR. Chỉ dùng NAND hoặc chỉ dùng NOR vẫn có thể dựng mọi mạch logic.

Quy trình thiết kế mạch:

1. Xác định đầu vào và đầu ra.
2. Lập bảng chân trị.
3. Viết biểu thức logic.
4. Rút gọn biểu thức bằng luật Bool hoặc Karnaugh.
5. Dựng mạch từ các cổng.

---

# 5. Lý thuyết đồ thị

## Mô hình hóa bằng đồ thị

Đồ thị gồm các **đỉnh** đại diện cho đối tượng và **cạnh** đại diện cho quan hệ giữa chúng.

Ví dụ:

- mạng máy tính: máy là đỉnh, đường kết nối là cạnh;
- bản đồ: địa điểm là đỉnh, đường đi là cạnh;
- mạng xã hội: người là đỉnh, quan hệ là cạnh.

Trọng tâm thường không phải hình vẽ trông như thế nào mà là đỉnh nào nối với đỉnh nào.

## Loại đồ thị và bậc

- Đơn đồ thị không có vòng và không có cạnh song song.
- Đa đồ thị có thể có vòng hoặc nhiều cạnh giữa cùng hai đỉnh.
- Đồ thị có hướng dùng mũi tên; mỗi đỉnh có bậc vào và bậc ra.
- Đồ thị có trọng số gán chi phí, khoảng cách hoặc thời gian cho cạnh.

Bậc của đỉnh là số cạnh chạm vào nó; một vòng góp hai vào bậc của đỉnh. Định lý bắt tay nói tổng bậc mọi đỉnh bằng hai lần số cạnh, nên số đỉnh bậc lẻ luôn chẵn.

## Biểu diễn đồ thị

- Hình vẽ phù hợp để quan sát cấu trúc.
- Ma trận kề ghi số cạnh giữa mỗi cặp đỉnh.
- Ma trận liên thuộc ghi đỉnh nào thuộc cạnh nào.
- Danh sách kề ghi các láng giềng của từng đỉnh, thường gọn cho đồ thị thưa.

Mỗi cách có ưu nhược điểm; chọn theo bài toán và cách lưu trữ dữ liệu.

## Đồ thị đặc biệt và đẳng cấu

Các họ thường gặp gồm đồ thị đầy đủ, vòng, bánh xe, đều bậc, khối lập phương và lưỡng phân. Nhận diện đúng cấu trúc giúp tính nhanh số đỉnh, số cạnh hoặc bậc.

Hai đồ thị **đẳng cấu** nếu chỉ khác tên đỉnh hoặc cách vẽ nhưng giữ nguyên mọi quan hệ kề. Để chứng minh đẳng cấu, chỉ ra phép ghép một-một giữa các đỉnh và kiểm tra cạnh được bảo toàn. Để chứng minh không đẳng cấu, tìm một đặc điểm không khớp như số cạnh, dãy bậc hoặc tính liên thông.

## Đường đi, chu trình và liên thông

- Đường đi là dãy cạnh nối tiếp nhau.
- Đường đi sơ cấp không lặp đỉnh; đường đi đơn không lặp cạnh.
- Chu trình là đường đi khép kín.
- Đồ thị liên thông nếu đi được giữa mọi cặp đỉnh.
- Đỉnh cắt hoặc cầu là điểm/nút nối mà khi bỏ đi làm mạng bị chia thành nhiều phần.

Đỉnh cắt và cầu dùng để nhận ra điểm yếu của mạng. Với đồ thị có hướng, phân biệt liên thông mạnh (đi hai chiều được giữa mọi cặp) và liên thông yếu (bỏ hướng thì liên thông).

## Euler và Hamilton: đừng nhầm

- **Euler:** tìm đường đi hoặc chu trình đi qua mọi **cạnh** đúng một lần.
- **Hamilton:** tìm đường đi hoặc chu trình ghé mọi **đỉnh** đúng một lần.

Với đồ thị vô hướng liên thông:

- Chu trình Euler tồn tại khi mọi đỉnh có bậc chẵn.
- Đường đi Euler nhưng không phải chu trình tồn tại khi đúng hai đỉnh có bậc lẻ.

Hamilton khó kiểm tra tổng quát hơn; các định lý Dirac và Ore là điều kiện đủ để khẳng định có chu trình Hamilton, không phải điều kiện cần.

Mẹo nhận biết đề: “đi qua mọi con đường/cạnh” là Euler; “ghé mọi thành phố/đỉnh một lần” là Hamilton.

## Đường đi ngắn nhất

Trong đồ thị có trọng số, độ dài đường đi là tổng trọng số các cạnh trên đường đó. Đường có ít cạnh nhất chưa chắc có tổng chi phí nhỏ nhất.

Thuật toán Dijkstra tìm đường ngắn nhất từ một đỉnh nguồn bằng cách lần lượt chốt đỉnh có nhãn tạm thời nhỏ nhất rồi cập nhật các láng giềng. Thuật toán này yêu cầu trọng số cạnh không âm.

---

# 6. Cây

## Cây và rừng

Cây là đồ thị vô hướng liên thông nhưng không có chu trình. Vì không có chu trình mà vẫn liên thông, giữa hai đỉnh bất kỳ của cây có đúng một đường đi sơ cấp.

Một cây có $n$ đỉnh luôn có $n-1$ cạnh. Rừng không có chu trình nhưng có thể gồm nhiều thành phần; nếu có $n$ đỉnh và $k$ thành phần cây thì có $n-k$ cạnh.

Các cách nhận diện cây tương đương nhau, chẳng hạn:

- liên thông và có $n-1$ cạnh;
- không có chu trình và có $n-1$ cạnh;
- giữa mọi cặp đỉnh có duy nhất một đường đi.

## Cây có gốc và cây m-phân

Chọn một đỉnh làm gốc sẽ tạo cấu trúc cha-con:

- cha, con, anh em;
- tổ tiên, con cháu;
- lá là nút không có con;
- mức là khoảng cách từ gốc;
- chiều cao là mức lớn nhất.

Cây m-phân giới hạn số con tối đa của mỗi nút trong. Cây m-phân đầy đủ yêu cầu mỗi nút trong có đúng $m$ con. Cây nhị phân là trường hợp $m=2$.

Ví dụ ứng dụng: cây thư mục, sơ đồ tổ chức và cây giải đấu loại trực tiếp.

## Duyệt cây nhị phân

Duyệt cây là thăm mỗi nút đúng một lần. Ba thứ tự đệ quy phổ biến:

- **Tiền tự:** gốc, cây con trái, cây con phải.
- **Trung tự:** cây con trái, gốc, cây con phải.
- **Hậu tự:** cây con trái, cây con phải, gốc.

Tên gọi chỉ vị trí của gốc trong thứ tự. Duyệt trung tự hữu ích để khôi phục biểu thức; tiền tự/hậu tự có thể viết biểu thức mà không cần ngoặc.

## Cây biểu thức và RPN

Cây biểu thức đặt toán tử ở nút trong và toán hạng ở lá. Toán tử thực hiện cuối cùng thường nằm ở gốc.

- Duyệt tiền tự cho ký pháp tiền tố.
- Duyệt trung tự cho cách viết thông thường.
- Duyệt hậu tự cho ký pháp nghịch đảo Ba Lan (RPN).

RPN được tính từ trái qua phải bằng ngăn xếp: gặp số thì đẩy vào; gặp toán tử thì lấy hai toán hạng trên cùng, tính rồi đẩy kết quả lại.

## Cây khung và cây khung nhỏ nhất

Cây khung là cây con giữ lại tất cả đỉnh của một đồ thị liên thông. Với $n$ đỉnh, cây khung có đúng $n-1$ cạnh.

Nếu các cạnh có chi phí, cây khung nhỏ nhất (MST) là cây khung có tổng chi phí thấp nhất. Dùng khi muốn nối tất cả nút mạng với tổng dây/chi phí nhỏ nhất.

- **Prim:** bắt đầu từ một đỉnh và mỗi lần nối cây hiện tại với đỉnh ngoài bằng cạnh rẻ nhất.
- **Kruskal:** xét cạnh từ rẻ đến đắt, chọn cạnh nếu nó không tạo chu trình.

Hai thuật toán có thể cho cây khác nhau nhưng cùng tổng trọng số tối thiểu. Lưu ý Prim tối ưu một cạnh để mở rộng cây; Dijkstra tối ưu tổng độ dài đường đi. Chúng không phải cùng một thuật toán.

---

# Gợi ý chọn công cụ

| Dạng câu hỏi | Chủ đề nên nghĩ tới |
|---|---|
| Câu đúng/sai, phủ định, “nếu…thì” | Logic mệnh đề |
| “Mọi”, “tồn tại”, biến chưa xác định | Vị từ và lượng từ |
| Đếm cách làm theo nhiều bước | Quy tắc nhân |
| Chọn một trong nhiều phương án rời nhau | Quy tắc cộng |
| Hai nhóm có thể trùng nhau | Bao hàm – loại trừ |
| Nhiều vật phải chia vào ít nhóm | Chuồng bồ câu |
| Chọn/sắp xếp phần tử | Hoán vị, chỉnh hợp, tổ hợp |
| Các phần tử có quan hệ đôi một | Quan hệ |
| Gom phần tử “tương đương” theo một tiêu chí | Lớp tương đương, phân hoạch |
| Đơn giản biểu thức 0/1 hoặc mạch điện | Đại số Bool, Karnaugh |
| Mạng các đối tượng và kết nối | Đồ thị |
| Đi qua mọi cạnh một lần | Euler |
| Đi qua mọi đỉnh một lần | Hamilton |
| Tìm tuyến có tổng chi phí nhỏ nhất từ nguồn | Dijkstra |
| Nối tất cả đỉnh với tổng chi phí cạnh nhỏ nhất | Cây khung nhỏ nhất, Prim/Kruskal |
| Cấu trúc phân cấp hoặc biểu thức | Cây |
