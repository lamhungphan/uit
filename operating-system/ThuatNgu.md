# DANH SÁCH THUẬT NGỮ TIẾNG ANH — HỆ ĐIỀU HÀNH (Chương 5, 7, 8)

## PHẦN 1 — CHƯƠNG 5: ĐỒNG BỘ TIẾN TRÌNH (Process Synchronization)

| # | Thuật ngữ | Nghĩa tiếng Việt | Ý nghĩa / Ghi chú |
|---|---|---|---|
| 1 | **Race Condition** | Điều kiện tranh đua | Nhiều tiến trình truy cập dữ liệu chia sẻ đồng thời → kết quả phụ thuộc thứ tự → **sai/không nhất quán** |
| 2 | **Critical Section (CS)** | Vùng tranh chấp / Miền găng | Đoạn code truy cập dữ liệu chia sẻ; chỉ 1 tiến trình được ở trong tại 1 thời điểm |
| 3 | **Entry Section** | Đoạn vào | Phần xin phép vào CS |
| 4 | **Exit Section** | Đoạn ra | Phần báo hiệu đã rời CS |
| 5 | **Remainder Section** | Đoạn còn lại | Phần code không truy cập dữ liệu chia sẻ |
| 6 | **Mutual Exclusion** | Loại trừ tương hỗ | Điều kiện (1): chỉ 1 tiến trình trong CS |
| 7 | **Progress** | Tiến triển | Điều kiện (2): tiến trình ngoài CS không cản người khác vào CS |
| 8 | **Bounded Waiting** | Chờ có giới hạn | Điều kiện (3): chờ hữu hạn lần → tránh starvation |
| 9 | **Busy Waiting** | Chờ bận / Chờ tích cực | Tiến trình quay vòng kiểm tra điều kiện → tốn CPU |
| 10 | **Spinlock** | Khóa quay vòng | Mutex dùng busy waiting |
| 11 | **Peterson's Solution** | Giải pháp Peterson | Kết hợp `flag[]` + `turn`, đảm bảo cả 3 điều kiện (trên máy cũ) |
| 12 | **Turn Variable** | Biến lượt | Chỉ định lượt tiến trình vào CS; vi phạm Progress |
| 13 | **Flag Array** | Mảng cờ | Đánh dấu "muốn vào CS"; dùng đơn thuần vi phạm Mutual Exclusion |
| 14 | **Memory Barrier** | Hàng rào bộ nhớ | Buộc thay đổi bộ nhớ lan truyền tới mọi CPU → chống reorder |
| 15 | **Strongly / Weakly Ordered** | Thứ tự mạnh / yếu | Strongly: thay đổi biết ngay. Weakly: có thể chưa biết ngay |
| 16 | **test_and_set()** | Kiểm tra-và-đặt | Lệnh phần cứng nguyên tử; đảm bảo mutual exclusion, **không** bounded waiting |
| 17 | **compare_and_swap()** | So sánh-và-đổi | Lệnh phần cứng nguyên tử; **có thể** đảm bảo bounded waiting |
| 18 | **Atomic Operation** | Thao tác đơn nguyên | Không thể bị ngắt giữa chừng |
| 19 | **Mutex (Mutual Exclusion Lock)** | Khóa loại trừ tương hỗ | `acquire()` / `release()`; có khái niệm **owner** |
| 20 | **acquire() / release()** | Xin khóa / Mở khóa | Hai thao tác phải nguyên tử |
| 21 | **block() / wakeup()** | Chặn / Đánh thức | API HĐH; `block` đưa vào hàng đợi ngủ, `wakeup` đưa về ready |
| 22 | **Semaphore** | Đèn hiệu | Biến nguyên, chỉ truy cập qua `wait`/`signal` |
| 23 | **wait(S) / P(S)** | Chờ / Xin tài nguyên | Giảm `S`; nếu < 0 thì block (**P = Proberen = thử**) |
| 24 | **signal(S) / V(S)** | Báo hiệu / Trả tài nguyên | Tăng `S`; đánh thức tiến trình chờ (**V = Verhogen = tăng**) |
| 25 | **Counting Semaphore** | Đèn hiệu đếm | Giá trị nguyên không giới hạn; quản lý **tài nguyên đếm được** |
| 26 | **Binary Semaphore** | Đèn hiệu nhị phân | Chỉ 0 hoặc 1; dùng như mutex |
| 27 | **Monitor** | Bộ giám sát | Kiểu dữ liệu trừu tượng; tự động đảm bảo chỉ 1 tiến trình vào tại 1 lúc |
| 28 | **Condition Variable** | Biến điều kiện | `x.wait()` / `x.signal()` trong monitor |
| 29 | **Urgent Queue** | Hàng đợi khẩn | Nơi tiến trình gọi `signal()` bị block |
| 30 | **Deadlock** | Tắc nghẽn / Bế tắc | 2+ tiến trình chờ nhau vô hạn, không ai tiến được |
| 31 | **Starvation** | Đói tài nguyên | Tiến trình bị bỏ quên mãi trong hàng đợi |
| 32 | **Liveness** | Tính sống động | Tập đặc điểm đảm bảo tiến trình thực sự được chạy |
| 33 | **Priority Inversion** | Đảo ngược ưu tiên | Ưu tiên thấp giữ khóa mà ưu tiên cao cần |
| 34 | **Priority Inheritance Protocol** | Giao thức thừa kế ưu tiên | Nâng tạm ưu tiên tiến trình giữ khóa → giải quyết priority inversion |
| 35 | **Bounded-Buffer Problem** | Bài toán bộ đệm giới hạn | Producer–Consumer |
| 36 | **Producer / Consumer** | Người sản xuất / Người tiêu thụ | Producer thêm, Consumer lấy; phải chờ `empty`/`full` |
| 37 | **Readers–Writers Problem** | Bài toán đọc-ghi | Nhiều reader đọc cùng lúc; writer độc quyền |
| 38 | **rw_mutex / read_count** | Khóa đọc-ghi / bộ đếm đọc | `rw_mutex` bảo vệ DB; `mutex` bảo vệ `read_count` |
| 39 | **Dining-Philosophers Problem** | Bài toán triết gia ăn tối | n triết gia, n đũa, cần 2 đũa → nguy cơ deadlock |
| 40 | **Asymmetric Solution** | Giải pháp bất đối xứng | Lẻ cầm đũa trái trước, chẵn cầm đũa phải trước → phá deadlock |

---

## PHẦN 2 — CHƯƠNG 7: QUẢN LÝ BỘ NHỚ (Memory Management)

| # | Thuật ngữ | Nghĩa tiếng Việt | Ý nghĩa / Ghi chú |
|---|---|---|---|
| 1 | **Memory Management** | Quản lý bộ nhớ | Phân phối & sắp xếp tiến trình trong bộ nhớ |
| 2 | **Degree of Multiprogramming** | Mức độ đa chương | Số tiến trình cùng ở trong bộ nhớ; mục tiêu tăng nó |
| 3 | **Relocation** | Tái định vị | Dịch chuyển địa chỉ khi tiến trình bị dời trong bộ nhớ |
| 4 | **Physical Address** | Địa chỉ vật lý | Vị trí **thực** trong RAM; do MMU tạo |
| 5 | **Logical (Virtual) Address** | Địa chỉ luận lý (ảo) | Địa chỉ do CPU sinh; chương trình nhìn thấy |
| 6 | **Absolute Address** | Địa chỉ tuyệt đối | Tương đương địa chỉ thực; gắn cứng |
| 7 | **Relative (Relocatable) Address** | Địa chỉ tương đối / khả tái định vị | Biểu diễn tương đối so với vị trí gốc |
| 8 | **Address Binding** | Kết gán / Ràng buộc địa chỉ | Gán địa chỉ luận lý ↔ vật lý |
| 9 | **Compile Time** | Thời điểm biên dịch | Biết trước vị trí → sinh **absolute code** |
| 10 | **Load Time** | Thời điểm nạp | Loader chuyển địa chỉ khả tái định vị; cần reload nếu base đổi |
| 11 | **Execution Time** | Thời điểm thực thi | Dịch địa chỉ động; cần phần cứng (base/limit) |
| 12 | **Absolute Code** | Mã tuyệt đối | Sinh ra khi biết trước vị trí bộ nhớ |
| 13 | **Relocatable Code** | Mã khả tái định vị | Sinh ra khi chưa biết vị trí bộ nhớ |
| 14 | **Dynamic Loading** | Nạp động | Thủ tục chỉ nạp khi được gọi → tiết kiệm bộ nhớ |
| 15 | **Dynamic Linking** | Liên kết động | Link module ngoài (DLL/.so) sau khi tạo load module |
| 16 | **Stub** | Đoạn mồi | Tham chiếu routine; gọi lần đầu thì nạp routine |
| 17 | **DLL (Windows) / .so (Unix)** | Thư viện liên kết động | Chia sẻ mã giữa nhiều tiến trình |
| 18 | **Fixed Partitioning** | Phân vùng cố định | Kích thước partition cố định → **internal fragmentation** |
| 19 | **Dynamic Partitioning** | Phân vùng động | Partition tùy theo tiến trình → **external fragmentation** |
| 20 | **Internal Fragmentation** | Phân mảnh nội | Lỗ trống **bên trong** vùng đã cấp phát |
| 21 | **External Fragmentation** | Phân mảnh ngoại | Lỗ trống **giữa** các vùng đã cấp phát, không liên tục |
| 22 | **Compaction** | Kết khối / Nén | Gom các vùng trống lại thành 1 khối lớn; cần binding ở execution time |
| 23 | **First-Fit** | Vừa đầu tiên | Chọn khối trống **đầu tiên** đủ lớn |
| 24 | **Best-Fit** | Vừa khít nhất | Chọn khối trống **nhỏ nhất** đủ lớn |
| 25 | **Worst-Fit** | Vừa tệ nhất | Chọn khối trống **lớn nhất** |
| 26 | **Next-Fit** | Vừa kế tiếp | Như First-Fit nhưng quét từ vị trí cấp phát cuối |
| 27 | **Paging** | Phân trang | Chia bộ nhớ thành trang (logical) & khung (physical) cố định |
| 28 | **Page** | Trang | Đơn vị bộ nhớ **luận lý** |
| 29 | **Frame** | Khung trang | Đơn vị bộ nhớ **vật lý** (cùng kích thước page) |
| 30 | **Page Number (p)** | Số hiệu trang | Phần cao của địa chỉ luận lý |
| 31 | **Page Offset (d)** | Độ lệch trang | Phần thấp của địa chỉ; giữ nguyên khi dịch |
| 32 | **Page Table** | Bảng trang | Ánh xạ `page number → frame number` |
| 33 | **PTBR (Page-Table Base Register)** | Thanh ghi nền bảng trang | Trỏ tới **vị trí** bảng trang |
| 34 | **PTLR (Page-Table Length Register)** | Thanh ghi độ dài bảng trang | Lưu **kích thước** bảng trang |
| 35 | **TLB (Translation Look-aside Buffer)** | Bộ đệm chuyển đổi địa chỉ | Cache phần cứng nhỏ lưu ánh xạ gần đây |
| 36 | **TLB Hit / Miss** | Trúng / Trượt TLB | Hit = 1 lần truy cập RAM; Miss = 2 lần |
| 37 | **Hit Ratio (α)** | Tỉ lệ trúng | Xác suất tìm thấy ánh xạ trong TLB |
| 38 | **EAT (Effective Access Time)** | Thời gian truy xuất hiệu dụng | $EAT = (2-\alpha)x + \varepsilon$ |
| 39 | **Hierarchical / Two-level Paging** | Phân trang phân cấp / 2 cấp | Chia bảng trang lớn thành nhiều bảng con |
| 40 | **Inverted Page Table** | Bảng trang nghịch đảo | **1 mục / 1 frame**; tiết kiệm bộ nhớ nhưng tra cứu chậm |
| 41 | **Protection Bits** | Bit bảo vệ | read-only / read-write / execute-only |
| 42 | **Valid–Invalid Bit** | Bit hợp lệ–bất hợp lệ | `valid` = trang hợp lệ & trong bộ nhớ |
| 43 | **MMU (Memory Management Unit)** | Đơn vị quản lý bộ nhớ | Phần cứng dịch địa chỉ ảo → vật lý |
| 44 | **Swapping** | Tráo đổi | Đưa tiến trình ra bộ nhớ phụ tạm thời |
| 45 | **Backing Store** | Bộ nhớ phụ trợ | Nơi lưu tiến trình bị swap (đĩa) |
| 46 | **Roll out / Roll in** | Đẩy ra / Nạp vào | Dùng trong lập lịch ưu tiên |
| 47 | **Fragment / Hole** | Mảnh / Lỗ trống | Vùng nhớ trống chưa cấp phát |

---

## PHẦN 3 — CHƯƠNG 8: BỘ NHỚ ẢO (Virtual Memory)

| # | Thuật ngữ | Nghĩa tiếng Việt | Ý nghĩa / Ghi chú |
|---|---|---|---|
| 1 | **Virtual Memory** | Bộ nhớ ảo | Cho phép tiến trình **không cần nạp toàn bộ** vào RAM |
| 2 | **Swap Space / Swap Partition** | Không gian tráo đổi | `swap partition` (Linux), `pagefile.sys` (Windows) |
| 3 | **Demand Paging** | Phân trang theo yêu cầu | Trang chỉ nạp khi được tham chiếu |
| 4 | **Lazy Swapper / Pager** | Bộ tráo lười / Bộ phân trang | Chỉ nạp trang khi cần |
| 5 | **Pure Demand Paging** | Phân trang theo yêu cầu thuần | Không nạp trước trang nào |
| 6 | **Page Fault** | Lỗi trang | Truy cập trang không có trong bộ nhớ vật lý |
| 7 | **Page-Fault Trap** | Ngắt lỗi trang | Ngắt báo HĐH xử lý lỗi trang |
| 8 | **Page-Fault Rate (p)** | Tỉ lệ lỗi trang | Tần suất xảy ra page fault |
| 9 | **PFSR (Page-Fault Service Routine)** | Thủ tục xử lý lỗi trang | Nạp trang từ đĩa vào frame |
| 10 | **Victim Page** | Trang bị hy sinh | Trang bị chọn để thay thế |
| 11 | **Page Replacement Algorithm** | Giải thuật thay thế trang | FIFO / OPT / LRU |
| 12 | **FIFO (First-In, First-Out)** | Vào trước ra trước | Thay trang vào sớm nhất → có **Belady's Anomaly** |
| 13 | **OPT / MIN (Optimal)** | Tối ưu | Thay trang dùng **trễ nhất tương lai**; bất khả thi thực tế |
| 14 | **LRU (Least Recently Used)** | Ít dùng gần đây nhất | Thay trang lâu nhất chưa dùng; cần phần cứng |
| 15 | **Belady's Anomaly** | Nghịch lý Belady | Tăng frame → page fault **tăng** (chỉ ở FIFO) |
| 16 | **Stack Algorithm** | Giải thuật ngăn xếp | Nhóm thuật toán (LRU/OPT) **không** có Belady's Anomaly |
| 17 | **Frame Allocation** | Cấp phát khung trang | Quyết định mỗi tiến trình nhận bao nhiêu frame |
| 18 | **Equal Allocation** | Cấp phát bằng nhau | Chia đều frame cho các tiến trình |
| 19 | **Proportional Allocation** | Cấp phát theo tỉ lệ | Dựa theo kích thước tiến trình |
| 20 | **Priority Allocation** | Cấp phát theo ưu tiên | Ưu tiên cao được nhiều frame hơn |
| 21 | **Local Replacement** | Thay thế cục bộ | Chỉ thay trang trong tập frame của chính tiến trình |
| 22 | **Global Replacement** | Thay thế toàn cục | Có thể lấy frame của tiến trình khác |
| 23 | **Thrashing** | Sự rung lắc | Trang bị hoán chuyển liên tục, page fault rất cao → **CPU util thấp** |
| 24 | **Locality of Reference** | Nguyên lý cục bộ tham chiếu | Tiến trình gồm nhiều cụm trang được tham chiếu gần nhau |
| 25 | **Working Set (WS)** | Tập làm việc | Tập Δ trang được tham chiếu trong cửa sổ gần nhất |
| 26 | **WSS (Working Set Size)** | Kích thước tập làm việc | Số trang trong working set; $D = \sum WSS_i$ |
| 27 | **Working Set Model** | Mô hình tập làm việc | Nếu $D > m$ → nguy cơ thrashing |
| 28 | **Working Set Window (Δ)** | Cửa sổ tập làm việc | Δ nhỏ → không phủ hết locality; Δ lớn → phủ nhiều locality |
| 29 | **Memory Access Time (ma)** | Thời gian truy xuất bộ nhớ | Cơ sở tính EAT |
| 30 | **Page Fault Service Time** | Thời gian phục vụ lỗi trang | Rất lớn (ms) so với truy xuất bộ nhớ (ns) |
| 31 | **Dirty / Modified Page** | Trang bẩn / đã sửa | Phải ghi ra đĩa trước khi thay |
| 32 | **Demand Paging vs Swapping** | Phân trang theo yêu cầu vs Tráo đổi | Demand paging = từng **trang**; Swapping = cả **tiến trình** |

---

## PHẦN 4 — VIẾT TẮT THƯỜNG GẶP

| Viết tắt | Đầy đủ | Nghĩa |
|---|---|---|
| **CS** | Critical Section | Vùng tranh chấp / Miền găng |
| **P / V** | Proberen / Verhogen | `wait` / `signal` của semaphore |
| **PTBR** | Page-Table Base Register | Thanh ghi nền bảng trang |
| **PTLR** | Page-Table Length Register | Thanh ghi độ dài bảng trang |
| **TLB** | Translation Look-aside Buffer | Bộ đệm chuyển đổi địa chỉ |
| **EAT / EMAT** | (Effective) Access Time | Thời gian truy xuất hiệu dụng |
| **MMU** | Memory Management Unit | Đơn vị quản lý bộ nhớ |
| **LA / VA** | Logical / Virtual Address | Địa chỉ luận lý (ảo) |
| **PA** | Physical Address | Địa chỉ vật lý |
| **PF** | Page Fault | Lỗi trang |
| **WS / WSS** | Working Set / Working Set Size | Tập làm việc / Kích thước tập làm việc |
| **LRU** | Least Recently Used | Ít dùng gần đây nhất |
| **FIFO** | First-In, First-Out | Vào trước ra trước |
| **OPT / MIN** | Optimal | Tối ưu |
| **DLL** | Dynamic Link Library | Thư viện liên kết động (Windows) |

---

## PHẦN 5 — TỪ KHÓA "BẪY" HAY BỊ PARAPHRASE

Đề hay **thay từ** để đánh lừa. Nhận diện nhanh:

| Đề có thể viết... | Ý thực sự là... |
|---|---|
| "Đoạn chương trình thao tác trên dữ liệu dùng chung" | **Critical Section** |
| "Chỉ một tiến trình được thao tác tại một thời điểm" | **Mutual Exclusion** |
| "Một tiến trình có thể chờ vô thời hạn dù không có gì cản trở" | **Bounded Waiting** bị vi phạm |
| "Tiến trình liên tục kiểm tra điều kiện trong vòng lặp" | **Busy Waiting / Spinlock** |
| "Số tiến trình đang xếp hàng chờ tài nguyên" | **\|S->value\|** của semaphore âm |
| "Không gian trống bị chia cắt thành nhiều mảnh nhỏ" | **External Fragmentation** |
| "Phần nhớ dư thừa nằm trong vùng đã cấp" | **Internal Fragmentation** |
| "Cơ chế phần cứng dịch địa chỉ ảo" | **MMU** (dùng TLB / page table) |
| "Vị trí của bảng trang" | **PTBR** |
| "Kích thước của bảng trang" | **PTLR** |
| "Trang bị đẩy ra để nhường chỗ" | **Victim Page** |
| "Hệ thống chạy chậm do liên tục nạp/xuất trang" | **Thrashing** |
| "Cấp thêm khung trang nhưng lỗi trang lại tăng" | **Belady's Anomaly** |
| "Tập trang đang được dùng trong khoảng thời gian gần đây" | **Working Set** |
| "Tiến trình đang chờ I/O đĩa sau lỗi trang" | Trạng thái **Blocked/Waiting** |
| "Khóa do một tiến trình sở hữu" | **Mutex** (khác semaphore) |
