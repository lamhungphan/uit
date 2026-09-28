## Câu 1. 
Giả sử một tiến trình được cấp 3 khung trang trong bộ nhớ vật lý và 7 trang trong bộ nhớ ảo. Tại thời điểm ban đầu, 3 khung trang trên bộ nhớ vật lý này đang trống. Tiến trình truy xuất 7 trang (1, 2, 3, 4, 5, 6, 7) trong bộ nhớ ảo theo thứ tự như sau: 

5 2 1 1 3 2 4 1 4 2 3 7 1 5 6 6 4 3 5 1. 

Tại thời điểm tiến trình truy xuất trang nhớ số 7 lần đầu tiên, hệ thống đã xảy ra bao nhiêu lỗi trang (không tính lỗi trang khi nạp trang số 7 vào) nếu sử dụng giải thuật LRU?

- Truy xuất 5: Bộ nhớ [5]. Lỗi trang (1).
- Truy xuất 2: Bộ nhớ [5, 2]. Lỗi trang (2).
- Truy xuất 1: Bộ nhớ [5, 2, 1]. Lỗi trang (3).
- Truy xuất 1: Trang 1 đã có trong bộ nhớ [5, 2, 1]. Không lỗi trang. (Trang 1 vừa được dùng).
- Truy xuất 3: Bộ nhớ đầy. Trang ít được dùng gần đây nhất là 5 $\rightarrow$ Thay 5 bằng 3. Bộ nhớ [3, 2, 1]. Lỗi trang (4).
- Truy xuất 2: Trang 2 đã có trong bộ nhớ [3, 2, 1]. Không lỗi trang. (Trang 2 vừa được dùng).
- Truy xuất 4: Bộ nhớ đầy. Lịch sử sử dụng gần nhất là: 2 (bước 6), 3 (bước 5), 1 (bước 4) $\rightarrow$ Trang 1 ít được dùng nhất. Thay 1 bằng 4. Bộ nhớ [3, 2, 4]. 
- Lỗi trang (5).Truy xuất 1: Lịch sử gần nhất: 4 (bước 7), 2 (bước 6), 3 (bước 5) $\rightarrow$ Trang 3 ít được dùng nhất. Thay 3 bằng 1. Bộ nhớ [1, 2, 4]. Lỗi trang (6).
- Truy xuất 4: Trang 4 đã có trong bộ nhớ [1, 2, 4]. Không lỗi trang.Truy xuất 2: Trang 2 đã có trong bộ nhớ [1, 2, 4]. Không lỗi trang.
- Truy xuất 3: Lịch sử gần nhất: 2 (bước 10), 4 (bước 9), 1 (bước 8) $\rightarrow$ Trang 1 ít được dùng nhất. Thay 1 bằng 3. Bộ nhớ [3, 2, 4]. Lỗi trang (7).
- Truy xuất 7: Đề bài yêu cầu không tính lỗi trang khi nạp trang 7 này.

## Câu 4. 
Giả sử một tiến trình được cấp 3 khung trang trong bộ nhớ vật lý và 7 trang trong bộ nhớ ảo. Tại thời điểm nạp tiến trình vào, 3 khung trang trên bộ nhớ vật lý này đang trống. Tiến trình truy xuất 7 trang (1, 2, 3, 4, 5, 6, 7, 8) trong bộ nhớ ảo theo thứ tự như sau:

5 2 1 1 3 2 4 1 4 2 3 7 1 5 6 6 4 3 5 1

Tại thời điểm tiến trình truy xuất trang nhớ số 6 lần đầu tiên, trang nhớ nào bị thay ra để nạp trang số 6 vào nếu áp dụng chiến lược LRU?

- Nạp 5: [5]
- Nạp 2: [5, 2]
- Nạp 1: [5, 2, 1]
- Nạp 1: [5, 2, 1] (Cập nhật 1 vừa dùng)
- Nạp 3: Thay trang 5 $\rightarrow$ [3, 2, 1]
- Nạp 2: [3, 2, 1] (Cập nhật 2 vừa dùng)
- Nạp 4: Thay trang 1 $\rightarrow$ [3, 2, 4]
- Nạp 1: Thay trang 3 $\rightarrow$ [1, 2, 4]
- Nạp 4: [1, 2, 4] (Cập nhật 4 vừa dùng)
- Nạp 2: [1, 2, 4] (Cập nhật 2 vừa dùng)
- Nạp 3: Thay trang 1 $\rightarrow$ [3, 2, 4]
- Nạp 7: Lịch sử sử dụng gần nhất là 3 (bước 11), 2 (bước 10), 4 (bước 9) $\rightarrow$ Trang 4 ít được sử dụng nhất gần đây. Thay 4 bằng 7 $\rightarrow$ [3, 2, 7]
- Nạp 1: Lịch sử gần nhất: 7 (bước 12), 3 (bước 11), 2 (bước 10) $\rightarrow$ Trang 2 ít được sử dụng nhất gần đây. Thay 2 bằng 1 $\rightarrow$ [3, 1, 7]
- Nạp 5: Lịch sử gần nhất: 1 (bước 13), 7 (bước 12), 3 (bước 11) $\rightarrow$ Trang 3 ít được sử dụng nhất gần đây. Thay 3 bằng 5 $\rightarrow$ [5, 1, 7]
- Nạp 6 (lần đầu tiên):
  - Trạng thái bộ nhớ trước khi nạp 6: [5, 1, 7]
  - Xem lại lịch sử truy xuất gần nhất tính tới thời điểm này:
    - 5 vừa được nạp ở bước 14
    - 1 vừa được nạp ở bước 13
    - 7 được nạp ở bước 12
  - Trang ít được sử dụng nhất trong 3 trang [5, 1, 7] chính là Trang số 7
  - Hệ thống sẽ thay trang số 7 ra để nạp trang số 6 vào (bộ nhớ thành [5, 1, 6])