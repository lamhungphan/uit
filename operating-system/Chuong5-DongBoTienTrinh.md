## 1. Race condition

### 1.1. Bài toán Producer vs. Consumer
- **Producer**: tạo hàng hóa → tăng biến `count`
- **Consumer**: bán hàng → giảm biến `count`
- `count++` và `count--` được thực thi qua nhiều lệnh máy (load, inc/dec, store)
- Khi đan xen nhau → kết quả `count` không chính xác

### 1.2. Bài toán cấp phát PID
- Hai tiến trình cùng gọi `fork()` → cùng đọc `next_available_pid` → nhận cùng PID
- Cần cơ chế ngăn truy cập đồng thời

### 1.3. Định nghĩa Race condition
- Xảy ra khi nhiều tiến trình cùng truy cập đồng thời vào **dữ liệu được chia sẻ**
- Kết quả phụ thuộc vào thứ tự thực thi → dữ liệu sai và không nhất quán
- Cần cơ chế đồng bộ để tại mỗi thời điểm chỉ một tiến trình thao tác trên dữ liệu chia sẻ

## 2. Vấn đề vùng tranh chấp (Critical Section)

- **Vùng tranh chấp (critical section - CS)**: đoạn code mà tiến trình tác động lên dữ liệu chia sẻ
- Khi một tiến trình trong CS, các tiến trình khác **KHÔNG** được vào CS của chúng
- Cấu trúc: `entry section → critical section → exit section → remainder section`

## 3. Yêu cầu cho lời giải bài toán vùng tranh chấp

| Yêu cầu | Mô tả |
|---|---|
| **(1) Mutual exclusion** | Khi P trong CS thì không có Q nào trong CS của Q |
| **(2) Progress** | Tiến trình tạm dừng ngoài CS không được ngăn tiến trình khác vào CS. Deadlock xảy ra khi P chờ Q và Q chờ P |
| **(3) Bounded waiting** | Mỗi tiến trình chỉ chờ tối đa một khoảng thời gian có hạn định → không starvation |

### Phân loại giải pháp
- **Phần mềm** (dựa trên ngắt): Peterson, Dekker, Bakery
- **Phần cứng**: TestAndSet, CompareAndSwap
- **Busy waiting**: tiến trình liên tục kiểm tra điều kiện
- **Sleep & Wakeup**: HĐH cung cấp `block()` và `wakeup()`

## 4. Các giải pháp dựa trên ngắt (phần mềm)

### 4.1. Giải pháp 1 - Biến turn
- Dùng biến `turn` chỉ đến lượt tiến trình vào CS
- **Đảm bảo**: Mutual exclusion
- **Không đảm bảo**: Progress (P phải chờ dù Q không vào CS) và Bounded waiting

### 4.2. Giải pháp 2 - Mảng flag
- Dùng mảng `flag[]` đánh dấu tiến trình sẵn sàng vào CS
- **Không đảm bảo** cả Mutual exclusion (cả hai có thể cùng vào CS)

### 4.3. Giải pháp Peterson
- Kết hợp cả `turn` và `flag[]`
- **Đảm bảo** cả 3 yêu cầu
```
Pi:
  flag[i] = true;
  turn = j;
  while (flag[j] && turn == j);
  /* critical section */
  flag[i] = false;
```

### 4.4. Peterson và kiến trúc hiện đại
- CPU/trình biên dịch có thể sắp xếp lại thao tác độc lập
- `flag[i] = true` và `turn = j` có thể bị đảo thứ tự → Peterson thất bại
- Giải pháp: **Memory Barrier**

## 5. Hỗ trợ từ phần cứng

### 5.1. Memory Barrier
- Lệnh bắt buộc mọi thay đổi bộ nhớ được lan truyền đến tất cả CPU
- **Strongly ordered**: thay đổi được biết ngay lập tức
- **Weakly ordered**: thay đổi có thể chưa được biết ngay

### 5.2. Lệnh phần cứng đơn nguyên
- `test_and_set()`: đọc và ghi nguyên tử
- `compare_and_swap()`: so sánh và đổi nguyên tử

## 6. Mutex Locks

### 6.1. Định nghĩa
- **Mutex** (Mutual Exclusion): khóa giúp đảm bảo loại trừ tương hỗ
- `acquire()`: yêu cầu khóa (nếu không được → busy waiting → **spinlock**)
- `release()`: mở khóa
- `acquire()` và `release()` phải là thao tác đơn nguyên
- Không cần hệ điều hành hỗ trợ

### 6.2. Mutex locks không busy waiting
- Dùng `block()`: tạm dừng tiến trình (đưa vào hàng đợi ngủ)
- Dùng `wakeup()`: đánh thức tiến trình (đưa vào ready queue)
- Cần hệ điều hành hỗ trợ 2 API trên

### 6.3. Cách sử dụng
```c
pthread_mutex_lock(&mutex);
/* critical section */
pthread_mutex_unlock(&mutex);
```

## 7. Semaphore

### 7.1. Định nghĩa
- Biến số nguyên, chỉ truy cập qua `wait()` và `signal()` (hay `P()` và `V()`)
```
wait(S) {
  while (S <= 0); // busy wait
  S--;
}
signal(S) {
  S++;
}
```

### 7.2. Phân loại
| Loại | Giá trị | Ứng dụng |
|---|---|---|
| **Counting semaphore** | Số nguyên không giới hạn | Quản lý tài nguyên |
| **Binary semaphore** | 0 hoặc 1 | Giống mutex lock |

### 7.3. Hiện thực không busy waiting
- Mỗi semaphore gắn với một hàng đợi
- `value < 0`: số tiến trình đang bị blocked là |value|
```
wait(S):
  S->value--;
  if (S->value < 0) { block(); }

signal(S):
  S->value++;
  if (S->value <= 0) { wakeup(P); }
```

### 7.4. Ứng dụng

| Mục đích | Cách thực hiện |
|---|---|
| **Mutual exclusion** | Khởi tạo S = 1, bao CS bằng `wait(S)`/`signal(S)` |
| **Đồng bộ thứ tự** | Khởi tạo S = 0, `signal()` ở P1, `wait()` ở P2 |
| **Đồng bộ điều kiện** | Xác định tài nguyên, đặt `wait()`/`signal()` phù hợp |

### 7.5. Vấn đề khi dùng semaphore
- **Deadlock**: thứ tự `wait()` sai (P1: wait(S), wait(Q); P2: wait(Q), wait(S))
- Cần lưu ý giá trị khởi tạo và thứ tự các thao tác

## 8. Monitor

### 8.1. Định nghĩa
- Kiểu dữ liệu trừu tượng đóng gói: biến nội bộ, thủ tục, code khởi tạo
- Chỉ một tiến trình vào monitor tại một thời điểm → mutual exclusion được đảm bảo

### 8.2. Condition variable
- `x.wait()`: block tiến trình trên condition variable x
- `x.signal()`: phục hồi một tiến trình bị block trên x
- Khi signal → tiến trình gọi signal bị blocked, vào **urgent queue**

## 9. Liveness

- Tập đặc điểm đảm bảo tiến trình thực sự chạy
- **Deadlock**: hai+ tiến trình chờ nhau vô hạn
- **Starvation**: tiến trình không bao giờ thoát khỏi hàng đợi semaphore
- **Priority inversion**: tiến trình ưu tiên thấp giữ khóa cần bởi tiến trình ưu tiên cao → giải pháp: **priority inheritance protocol**

---

## 10. Bài toán đồng bộ Bounded-Buffer

- Mảng buffer[] có n phần tử, count = số phần tử hiện có
- **Producer**: không thể thêm khi buffer đầy (count = n)
- **Consumer**: không thể xóa khi buffer rỗng (count = 0)
- **Vùng tranh chấp**: code truy cập buffer và count
- Giải pháp semaphore:
  - `empty` = n (số vị trí trống)
  - `full` = 0 (số vị trí có dữ liệu)  
  - `mutex` = 1 (bảo vệ CS)
- **Lỗi thường gặp**: dùng `while`/`if` thay semaphore; bỏ qua vùng tranh chấp

## 11. Bài toán đồng bộ Readers-Writers

- **Readers**: chỉ đọc dữ liệu
- **Writers**: có thể đọc và ghi
- **Nguyên tắc**: nhiều Readers cùng đọc được; Writer cần mutual exclusion
- **Biến thể 1** (ưu tiên Readers): Writers có thể bị starvation
- **Biến thể 2** (ưu tiên Writers): Readers có thể bị starvation
- Giải pháp dùng: `rw_mutex` (bảo vệ database), `mutex` (bảo vệ `read_count`)

## 12. Bài toán đồng bộ Dining-Philosophers

- n triết gia, n chiếc đũa, cần 2 đũa để ăn
- Giải pháp semaphore: mỗi đũa là một semaphore
- **Deadlock**: tất cả cùng cầm đũa trái → không ai ăn được
- **Cách tránh deadlock**:
  - Tối đa 4 triết gia vào bàn
  - Chỉ cầm đũa khi cả 2 sẵn sàng (dùng CS)
  - Giải pháp bất đối xứng: lẻ cầm trái trước, chẵn cầm phải trước
- Giải pháp monitor: dùng state (THINKING, HUNGRY, EATING) và condition variable
