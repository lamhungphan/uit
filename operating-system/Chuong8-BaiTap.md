## Câu 1

**Đề bài:** Giả sử một tiến trình được cấp 3 khung trang trong bộ nhớ vật lý và 7 trang trong bộ nhớ ảo. Tại thời điểm ban đầu, 3 khung trang trên bộ nhớ vật lý này đang trống. Tiến trình truy xuất 7 trang (1, 2, 3, 4, 5, 6, 7) trong bộ nhớ ảo theo thứ tự như sau: 

`5 2 1 1 3 2 4 1 4 2 3 7 1 5 6 6 4 3 5 1`

Tại thời điểm tiến trình truy xuất trang nhớ số 7 lần đầu tiên, hệ thống đã xảy ra bao nhiêu lỗi trang (không tính lỗi trang khi nạp trang số 7 vào) nếu sử dụng giải thuật LRU?

| Bước | Trang truy xuất | Trạng thái bộ nhớ (3 khung) | Lỗi trang? | Giải thích chi tiết |
| :---: | :---: | :---: | :---: | :--- |
| 1 | **5** | `[5]` | **Có (1)** | Bộ nhớ trống, nạp 5 vào. |
| 2 | **2** | `[5, 2]` | **Có (2)** | Bộ nhớ trống, nạp 2 vào. |
| 3 | **1** | `[5, 2, 1]` | **Có (3)** | Bộ nhớ trống, nạp 1 vào. Bộ nhớ đầy. |
| 4 | **1** | `[5, 2, 1]` | **Không** | Trang 1 đã có trong bộ nhớ. Cập nhật trang 1 vừa được dùng. |
| 5 | **3** | `[3, 2, 1]` | **Có (4)** | Bộ nhớ đầy. Trang ít được dùng gần đây nhất là **5** $\rightarrow$ Thay 5 bằng 3. |
| 6 | **2** | `[3, 2, 1]` | **Không** | Trang 2 đã có trong bộ nhớ. Cập nhật trang 2 vừa được dùng. |
| 7 | **4** | `[3, 2, 4]` | **Có (5)** | Bộ nhớ đầy. Lịch sử sử dụng gần nhất là 2 (bước 6), 3 (bước 5), 1 (bước 4) $\rightarrow$ Trang **1** ít được dùng nhất $\rightarrow$ Thay 1 bằng 4. |
| 8 | **1** | `[1, 2, 4]` | **Có (6)** | Lịch sử sử dụng gần nhất là 4 (bước 7), 2 (bước 6), 3 (bước 5) $\rightarrow$ Trang **3** ít được dùng nhất $\rightarrow$ Thay 3 bằng 1. |
| 9 | **4** | `[1, 2, 4]` | **Không** | Trang 4 đã có trong bộ nhớ. |
| 10 | **2** | `[1, 2, 4]` | **Không** | Trang 2 đã có trong bộ nhớ. |
| 11 | **3** | `[3, 2, 4]` | **Có (7)** | Lịch sử sử dụng gần nhất là 2 (bước 10), 4 (bước 9), 1 (bước 8) $\rightarrow$ Trang **1** ít được dùng nhất $\rightarrow$ Thay 1 bằng 3. |
| 12 | **7** | — | — | Dừng lại, không tính lỗi trang khi nạp trang 7. |

**Kết luận:** Đã xảy ra **7 lỗi trang**.

---

## Câu 4

**Đề bài:** Giả sử một tiến trình được cấp 3 khung trang trong bộ nhớ vật lý và 7 trang trong bộ nhớ ảo. Tại thời điểm nạp tiến trình vào, 3 khung trang trên bộ nhớ vật lý này đang trống. Tiến trình truy xuất 7 trang (1, 2, 3, 4, 5, 6, 7, 8) trong bộ nhớ ảo theo thứ tự như sau:

`5 2 1 1 3 2 4 1 4 2 3 7 1 5 6 6 4 3 5 1`

Tại thời điểm tiến trình truy xuất trang nhớ số 6 lần đầu tiên, trang nhớ nào bị thay ra để nạp trang số 6 vào nếu áp dụng chiến lược LRU?

| Bước | Trang truy xuất | Trạng thái bộ nhớ (3 khung) | Giải thích chi tiết |
| :---: | :---: | :---: | :--- |
| 1 | **5** | `[5]` | Nạp trang 5. |
| 2 | **2** | `[5, 2]` | Nạp trang 2. |
| 3 | **1** | `[5, 2, 1]` | Nạp trang 1. |
| 4 | **1** | `[5, 2, 1]` | Trang 1 có sẵn (Cập nhật 1 vừa dùng). |
| 5 | **3** | `[3, 2, 1]` | Trang 5 ít dùng nhất $\rightarrow$ Thay trang 5 bằng 3. |
| 6 | **2** | `[3, 2, 1]` | Trang 2 có sẵn (Cập nhật 2 vừa dùng). |
| 7 | **4** | `[3, 2, 4]` | Trang 1 ít dùng nhất $\rightarrow$ Thay trang 1 bằng 4. |
| 8 | **1** | `[1, 2, 4]` | Trang 3 ít dùng nhất $\rightarrow$ Thay trang 3 bằng 1. |
| 9 | **4** | `[1, 2, 4]` | Trang 4 có sẵn (Cập nhật 4 vừa dùng). |
| 10 | **2** | `[1, 2, 4]` | Trang 2 có sẵn (Cập nhật 2 vừa dùng). |
| 11 | **3** | `[3, 2, 4]` | Trang 1 ít dùng nhất $\rightarrow$ Thay trang 1 bằng 3. |
| 12 | **7** | `[3, 2, 7]` | Lịch sử sử dụng gần nhất là 3 (bước 11), 2 (bước 10), 4 (bước 9) $\rightarrow$ Trang **4** ít được sử dụng nhất $\rightarrow$ Thay 4 bằng 7. |
| 13 | **1** | `[3, 1, 7]` | Lịch sử sử dụng gần nhất là 7 (bước 12), 3 (bước 11), 2 (bước 10) $\rightarrow$ Trang **2** ít được sử dụng nhất $\rightarrow$ Thay 2 bằng 1. |
| 14 | **5** | `[5, 1, 7]` | Lịch sử sử dụng gần nhất là 1 (bước 13), 7 (bước 12), 3 (bước 11) $\rightarrow$ Trang **3** ít được sử dụng nhất $\rightarrow$ Thay 3 bằng 5. |
| 15 | **6** | `[5, 1, 6]` | **Truy xuất trang 6 lần đầu tiên:**<br>- Bộ nhớ hiện tại: `[5, 1, 7]`.<br>- Lịch sử gần nhất: **5** (bước 14), **1** (bước 13), **7** (bước 12).<br>- Trang **7** ít được sử dụng nhất $\rightarrow$ **Thay trang số 7 ra để nạp trang 6 vào**. |

**Kết luận:** Trang bị thay ra để nạp trang số 6 vào là **Trang số 7**.