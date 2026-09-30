# ĐỀ CƯƠNG ÔN TẬP HỆ ĐIỀU HÀNH — Chương 5, 7, 8

> **Mã môn:** IT007 · **Phạm vi thi:** Chương 5 (Đồng bộ tiến trình), Chương 7 (Quản lý bộ nhớ), Chương 8 (Bộ nhớ ảo)
> **Đặc điểm đề:** Câu hỏi được **paraphrase** và **"lách léo"** để kiểm tra độ hiểu bản chất, KHÔNG hỏi định nghĩa nguyên văn.
> **Chiến lược:** Nắm **bản chất – phân biệt – phản ví dụ**, chứ không học thuộc lòng.

---

## 🎯 CHIẾN LƯỢC LÀM BÀI VỚI ĐỀ "LÁCH LÉO"

| Mẹo | Cách áp dụng |
|---|---|
| **1. Đọc kỹ chữ "KHÔNG / SAI / ngoại trừ"** | Đề hay hỏi "phát biểu nào SAI" — phải loại trừ, không chọn đáp án đúng. |
| **2. Nhận diện chiều của câu hỏi** | Cùng 1 kiến thức nhưng hỏi ngược: "tăng frame → page fault ?" (thường giảm, nhưng FIFO có Belady). |
| **3. Cảnh giác từ ngữ tuyệt đối** | "luôn luôn", "chắc chắn", "không bao giờ", "chỉ" → gần như luôn là bẫy. |
| **4. Phân biệt cặp khái niệm na ná nhau** | Xem bảng phân biệt tổng hợp ở Phần D. |
| **5. Tính toán: vẽ bảng từng bước** | Đừng nhẩm; page replacement & address translation phải kẻ bảng. |
| **6. Chú ý đơn vị** | KB/MB là $2^{10}$/$2^{20}$; đừng nhầm KB = 1000 B. |

---

# PHẦN A — CHƯƠNG 5: ĐỒNG BỘ TIẾN TRÌNH

## A1. Bản chất cần hiểu

### 1. Race condition (Điều kiện tranh đua)
- Nhiều tiến trình **truy cập đồng thời dữ liệu chia sẻ**, kết quả **phụ thuộc thứ tự thực thi** → dữ liệu sai, không nhất quán.
- Nguyên nhân gốc: một câu lệnh C (`count++`) được dịch thành **nhiều lệnh máy** (load → inc → store) → có thể bị xen kẽ.
- Ví dụ: Producer/Consumer tăng/giảm `count`; hai `fork()` cùng đọc `next_available_pid`.

> 🔑 **Hiểu bản chất:** Vấn đề KHÔNG phải "hai tiến trình cùng chạy", mà là **cùng ghi/đọc một biến chia sẻ mà không có bảo vệ**.

### 2. Critical Section (Vùng tranh chấp / Miền găng)
Cấu trúc bắt buộc:
```
entry section → CRITICAL SECTION → exit section → remainder section
```

### 3. BA yêu cầu bắt buộc của mọi lời giải (rất hay bị hỏi lệch)

| # | Yêu cầu | Bản chất dễ hiểu | Bị vi phạm khi nào |
|---|---|---|---|
| **(1)** | **Mutual Exclusion** | Chỉ 1 tiến trình ở trong CS tại 1 thời điểm | Lời giải dùng flag đơn thuần |
| **(2)** | **Progress** | Tiến trình **ngoài CS** không được cản tiến trình khác đang muốn vào CS | Dùng biến `turn` (phải chờ vô cớ) |
| **(3)** | **Bounded Waiting** | Mỗi tiến trình chỉ chờ **hữu hạn** lần bị vượt mặt → tránh **starvation** | Không giới hạn số lần chen ngang |

> ⚠️ **Bẫy kinh điển:** *"Progress"* ≠ *"Bounded waiting"*.
> - **Progress** = "đừng chặn người khác vào khi tôi không ở trong CS".
> - **Bounded waiting** = "đừng để tôi chờ mãi".
> - Đề hay mô tả tình huống chờ vô hạn rồi hỏi vi phạm điều kiện nào → thường là **Progress** (khi bàn về `turn`) hoặc **Bounded Waiting** (khi bàn về starvation).

### 4. Giải pháp phần mềm

| Giải pháp | Cơ chế | Đảm bảo | Vi phạm |
|---|---|---|---|
| **Turn** (biến lượt) | Biến `turn` chỉ ai được vào | Mutual Exclusion | **Progress** (+ bounded waiting) |
| **Flag[]** | Mảng đánh dấu "tôi muốn vào" | (không đủ) | **Mutual Exclusion** — cả 2 cùng vào |
| **Peterson** | Kết hợp `flag[]` + `turn` | **Cả 3** | Chỉ hỏng trên CPU hiện đại do reorder |

```c
// Peterson cho tiến trình Pi (j là tiến trình kia)
flag[i] = true;
turn = j;
while (flag[j] && turn == j);   // busy waiting
/* --- critical section --- */
flag[i] = false;
```

> ⚠️ **Bẫy hiện đại:** CPU/compiler có thể **đảo thứ tự** `flag[i]=true` và `turn=j` → Peterson **thất bại**. Giải pháp: **Memory Barrier**.

### 5. Hỗ trợ phần cứng

| Khái niệm | Ý nghĩa |
|---|---|
| **Memory Barrier** | Bắt buộc thay đổi bộ nhớ lan truyền tới mọi CPU trước khi lệnh sau chạy |
| **Strongly ordered** | Thay đổi được biết ngay lập tức |
| **Weakly ordered** | Thay đổi có thể chưa được biết ngay |
| **test_and_set()** | Đọc giá trị cũ **và** ghi `true` trong 1 thao tác nguyên tử |
| **compare_and_swap()** | So sánh & đổi giá trị trong 1 thao tác nguyên tử |
| **Atomic (đơn nguyên)** | Không thể bị ngắt giữa chừng |

> ⚠️ **Bẫy:** `test_and_set` chỉ đảm bảo **mutual exclusion**, **KHÔNG** đảm bảo bounded waiting. `compare_and_swap` **có thể** đảm bảo bounded waiting.

### 6. Mutex Lock

```
acquire() { while (!available); available = false; }   // busy wait → SPINLOCK
release() { available = true; }
```
- **Spinlock:** tiến trình **quay vòng (busy waiting)** chờ khóa → tốn CPU.
- **Không cần HĐH hỗ trợ** (khác semaphore).
- Biến thể **không busy waiting**: dùng `block()`/`wakeup()` (cần HĐH hỗ trợ).

### 7. Semaphore

```c
wait(S)  { while (S <= 0); S--; }   // còn gọi P()
signal(S){ S++; }                    // còn gọi V()
```

| Loại | Giá trị | Dùng cho |
|---|---|---|
| **Counting semaphore** | Số nguyên không giới hạn | Quản lý **tài nguyên** (đếm số instance) |
| **Binary semaphore** | 0 hoặc 1 | **Mutual exclusion** (giống mutex) |

**Hiện thực KHÔNG busy waiting:**
```c
wait(S)   { S->value--; if (S->value < 0) block(); }
signal(S) { S->value++; if (S->value <= 0) wakeup(P); }
```
> 🔑 **Cực quan trọng:** **Số tiến trình đang bị block = |S->value|** khi `S->value < 0`.
> Ví dụ `S = -4` → có **4 tiến trình đang chờ**.

### 8. Ba ứng dụng semaphore (nhớ kỹ giá trị khởi tạo!)

| Mục đích | Khởi tạo | Mẫu |
|---|---|---|
| **Mutual exclusion** | `S = 1` | `wait(S)` ... CS ... `signal(S)` |
| **Đồng bộ thứ tự (S1 trước S2)** | `S = 0` | P1: `S1; signal(S);` — P2: `wait(S); S2;` |
| **Đồng bộ điều kiện** | Tùy tài nguyên | Tùy bài (empty=n, full=0) |

> ⚠️ **Bẫy:** Muốn ép "P2 chạy SAU P1" → `wait` ở P2 phải **block ngay từ đầu** → khởi tạo **`S = 0`** (không phải 1).

### 9. Deadlock do semaphore
```
P1: wait(S); wait(Q); ...        P2: wait(Q); wait(S); ...
```
Nếu P1 giữ S và P2 giữ Q, cả hai chờ nhau → **deadlock**.
> Khắc phục: **mọi tiến trình phải `wait()` theo cùng một thứ tự**.

### 10. Monitor
- Kiểu dữ liệu trừu tượng đóng gói (biến nội bộ + thủ tục + khởi tạo).
- **Chỉ 1 tiến trình ở trong monitor tại 1 thời điểm** → mutual exclusion **tự động**.
- **Condition variable:** `x.wait()` (block), `x.signal()` (phục hồi 1 tiến trình đang chờ).
- Khi `signal()`: tiến trình gọi signal bị block, vào **urgent queue**.

> ⚠️ **Bẫy:** Monitor KHÁC semaphore. Monitor đảm bảo mutual exclusion **sẵn**, lập trình viên không tự `wait/signal` khóa.

### 11. Liveness (Tính sống động)

| Vấn đề | Mô tả | Giải pháp |
|---|---|---|
| **Deadlock** | 2+ tiến trình chờ nhau vô hạn | Thứ tự wait thống nhất |
| **Starvation** | Tiến trình không bao giờ thoát khỏi hàng đợi | Công bằng (fairness) |
| **Priority Inversion** | Tiến trình ưu tiên thấp giữ khóa cần bởi tiến trình ưu tiên cao | **Priority Inheritance Protocol** |

> ⚠️ **Bẫy Priority Inversion:** giải pháp là **priority inheritance** (tiến trình giữ khóa tạm được nâng ưu tiên), KHÔNG phải "tăng ưu tiên tiến trình cao" hay "dừng tiến trình thấp".

---

## A2. Ba bài toán đồng bộ kinh điển

### 1. Bounded-Buffer (Producer–Consumer)
- `empty = n` (chỗ trống), `full = 0` (chỗ có dữ liệu), `mutex = 1` (bảo vệ buffer).

**Producer** (chờ chỗ trống):
```c
wait(empty); wait(mutex);  /* thêm vào buffer */  signal(mutex); signal(full);
```
**Consumer** (chờ dữ liệu):
```c
wait(full); wait(mutex);   /* lấy ra buffer */    signal(mutex); signal(empty);
```
> ⚠️ **Bẫy:** Thứ tự `wait` phải đúng — nếu đảo `wait(mutex)` lên trước `wait(empty)` → có thể **deadlock**.

### 2. Readers–Writers
- Nhiều **Reader** đọc cùng lúc; **Writer** cần độc quyền.
- Biến: `rw_mutex` (bảo vệ DB), `mutex` (bảo vệ `read_count`).
- **Biến thể ưu tiên Reader** → Writer **starvation**.
- **Biến thể ưu tiên Writer** → Reader **starvation**.

> ⚠️ **Bẫy:** Câu hỏi "biến thể nào gây đói cho X?" — nhớ nguyên tắc: **ưu tiên ai thì người kia bị đói**.

### 3. Dining-Philosophers (Triết gia ăn tối)
- n triết gia, n đũa, cần **2 đũa** để ăn.
- **Deadlock:** tất cả cùng cầm đũa trái → chờ đũa phải mãi mãi.
- **Cách phá deadlock:**
  1. Tối đa **n−1** triết gia vào bàn.
  2. Chỉ nhặt đũa **khi cả 2 đũa sẵn sàng** (trong CS).
  3. **Bất đối xứng:** triết gia **lẻ** cầm trái trước, **chẵn** cầm phải trước.
- Có lời giải bằng **monitor** (dùng state THINKING/HUNGRY/EATING + condition variable).

---

## A3. Bẫy & phân biệt Chương 5

| Cặp dễ lẫn | Phân biệt |
|---|---|
| Race condition vs Deadlock | Race = tranh dữ liệu → kết quả sai. Deadlock = chờ nhau vô hạn → không ai chạy |
| Starvation vs Deadlock | Starvation = *có thể* chạy nhưng bị bỏ quên. Deadlock = *không bao giờ* chạy |
| Busy waiting vs Block/Wakeup | Busy = quay vòng tốn CPU (spinlock). Block = nhường CPU, cần HĐH |
| Mutex vs Binary semaphore | Mutex do người **sở hữu** (owner), semaphore thì không có khái niệm owner |
| Counting vs Binary semaphore | Counting > 1 (quản lý tài nguyên). Binary ∈ {0,1} (loại trừ) |
| `wait()` vs `signal()` | `wait` = xin/giảm giá trị (còn gọi P). `signal` = trả/tăng (còn gọi V) |

---

# PHẦN B — CHƯƠNG 7: QUẢN LÝ BỘ NHỚ

## B1. Bản chất cần hiểu

### 1. Mục tiêu & 5 yêu cầu
Mục tiêu: **nạp càng nhiều tiến trình càng tốt** → tăng **mức độ đa chương (degree of multiprogramming)**.
1. Cấp phát bộ nhớ · 2. Tái định vị (relocation) · 3. Bảo vệ · 4. Chia sẻ · 5. Kết gán địa chỉ luận lý → thực.

### 2. Các loại địa chỉ (bẫy hay gài)

| Loại | Định nghĩa | Ghi nhớ |
|---|---|---|
| **Physical address** | Vị trí **thực** trong RAM | Do MMU tạo ra |
| **Logical (Virtual) address** | Địa chỉ do **CPU/chương trình** sinh ra | Người lập trình nhìn thấy |
| **Absolute address** | Tương đương địa chỉ thực | Gắn cứng, không tái định vị |
| **Relative address** | Địa chỉ **khả tái định vị**, biểu diễn tương đối | Cần base register |

> ⚠️ **Bẫy:** *Logical* ≡ *Virtual* (hai tên gọi cùng thứ). *Absolute* ≠ *Relative*.

### 3. Ba thời điểm kết gán địa chỉ (Address Binding)

| Thời điểm | Cơ chế | Hệ quả |
|---|---|---|
| **Compile time** | Biết trước vị trí → sinh **mã tuyệt đối** (absolute code) | Không chạy được nếu vị trí đổi (MS-DOS .COM) |
| **Load time** | Loader dịch địa chỉ khả tái định vị dựa trên base | Phải **reload** nếu base đổi |
| **Execution time** | Trì hoãn đến lúc chạy, cần **phần cứng** (base/limit) | Cần cho **swapping, paging, segmentation** |

> ⚠️ **Bẫy:** Compaction / paging / swapping **chỉ khả thi khi binding ở execution time** (vì phải dịch địa chỉ động).

### 4. Dynamic Loading vs Dynamic Linking

| Khái niệm | Bản chất | Lợi ích |
|---|---|---|
| **Dynamic Loading** | Thủ tục **chỉ nạp khi được gọi** | Tiết kiệm bộ nhớ (mã ít dùng như xử lý lỗi) |
| **Dynamic Linking** | Link module ngoài (DLL/.so) **sau** khi tạo load module | Chia sẻ mã, tiết kiệm bộ nhớ + đĩa |
| **Stub** | Đoạn mã nhỏ tham chiếu routine; gọi lần đầu → nạp routine | Cơ chế để dynamic linking hoạt động |

### 5. Fixed vs Dynamic Partitioning (bẫy kinh điển)

| | **Fixed Partitioning** | **Dynamic Partitioning** |
|---|---|---|
| Kích thước partition | Cố định từ đầu | Tùy theo tiến trình |
| Phân mảnh | **Internal fragmentation** (nội) | **External fragmentation** (ngoại) |
| Khắc phục | Partition không đều, gán vào partition nhỏ nhất đủ chứa | **Compaction** |

> 🔑 **Câu thần chú:** *Cố định → nội; Động → ngoại.* Ngược lại là SAI.

### 6. Chiến lược cấp phát (Placement)

| Chiến lược | Chọn khối | Ghi chú |
|---|---|---|
| **First-fit** | Khối trống **đầu tiên** đủ lớn | Nhanh, thường hiệu quả |
| **Best-fit** | Khối trống **nhỏ nhất** đủ lớn | Để lại lỗ rất nhỏ (khó dùng) |
| **Worst-fit** | Khối trống **lớn nhất** | Để lại lỗ lớn dùng được |
| **Next-fit** | Khối đủ lớn, **bắt đầu từ vị trí cấp phát cuối** | Như first-fit nhưng quét vòng |

> ⚠️ **Bẫy:** First-fit **KHÔNG** phải chậm nhất; Best-fit **KHÔNG** để lại khối lớn nhất. Worst-fit mới để lại khối lớn nhất (nhưng thường kém hiệu quả tổng thể).

### 7. Paging (Phân trang)

- Bộ nhớ **vật lý** chia thành **frames** (cố định, 512 B – 16 MB).
- Bộ nhớ **luận lý** chia thành **pages** (**cùng kích thước** frame).
- **Page Table** ánh xạ `page number → frame number`.
- **KHÔNG có external fragmentation** (nhưng **vẫn có internal fragmentation** ở trang cuối).

**Cấu trúc địa chỉ luận lý:**
```
┌──────────────┬───────────────┐
│ page number p │  offset d     │
└──────────────┴───────────────┘
   m−n bits          n bits
```
- Không gian ảo = $2^m$, page size = $2^n$ → số mục bảng trang = $2^{m-n}$.
- **PTBR** (Page-Table Base Register): trỏ tới bảng trang.
- **PTLR** (Page-Table Length Register): kích thước bảng trang.

> ⚠️ **Bẫy nhớ tên:** PT**B**R = **B**ase (vị trí). PT**L**R = **L**ength (kích thước).

### 8. TLB (Translation Look-aside Buffer)
- Cache phần cứng nhỏ (thường 64–1024 dòng) lưu ánh xạ gần đây.
- **Không có TLB:** mỗi truy cập tốn **2 lần truy cập bộ nhớ** (1 bảng trang + 1 dữ liệu).
- **Có TLB:**
  - **Hit:** 1 lần truy cập bộ nhớ (+ thời gian tra TLB).
  - **Miss:** 2 lần truy cập bộ nhớ (+ thời gian tra TLB).

**Công thức EAT:**
$$EAT = \alpha(\varepsilon + x) + (1-\alpha)(\varepsilon + 2x) = (2-\alpha)x + \varepsilon$$
Trong đó: $\varepsilon$ = thời gian tra TLB, $x$ = chu kỳ truy xuất bộ nhớ, $\alpha$ = hit ratio.

> ⚠️ **Bẫy:** TLB **hit ratio** ≠ **page-fault rate**. TLB hit cao nghĩa là ít phải tra bảng trang, KHÔNG có nghĩa ít lỗi trang (trang có thể vẫn không ở trong RAM).

### 9. Đa cấp trang & bảng trang nghịch đảo

| Kỹ thuật | Bản chất |
|---|---|
| **Phân trang 2 cấp / đa cấp** | Chia bảng trang lớn thành nhiều bảng con → tránh cấp phát bảng trang khổng lồ liên tục |
| **Bảng trang nghịch đảo (Inverted Page Table)** | **1 mục cho 1 frame** (không phải 1 mục cho 1 page) → tiết kiệm bộ nhớ, nhưng tra cứu **chậm hơn** (cần hash, tìm kiếm) |

> ⚠️ **Bẫy:** Inverted page table **không** giảm số lần truy cập, mà **tăng** thời gian tra cứu.

### 10. Bảo vệ bộ nhớ
- **Protection bits:** read-only / read-write / execute-only.
- **Valid/Invalid bit:** `valid` = trang hợp lệ và trong bộ nhớ; `invalid` = bất hợp lệ (chưa nạp hoặc không thuộc không gian địa chỉ).

### 11. Swapping
- Tiến trình bị đưa ra bộ nhớ phụ (backing store) tạm thời.
- **Round-robin:** swap out khi hết quantum, swap in tiến trình kế.
- **Roll out / roll in:** dùng trong lập lịch ưu tiên.

## B2. Dạng bài tính toán bắt buộc (Address Translation)

**Cho:** page size, page table, một địa chỉ (luận lý hoặc vật lý).
**Công thức:**
$$\text{page } p = \left\lfloor \frac{LA}{\text{page size}} \right\rfloor, \quad \text{offset } d = LA \bmod \text{page size}$$
$$PA = \text{frame} \times \text{page size} + d$$
**Chiều ngược (PA → LA):** tìm `f = ⌊PA / size⌋`, `d = PA mod size`, tra ngược bảng trang để tìm `p`, rồi `LA = p × size + d`.

**Dạng tính số bit địa chỉ:**
- Số bit page number: $p = \lceil \log_2(\text{số trang cần định danh}) \rceil$
- Số bit offset: $d = \log_2(\text{page size})$
- Số bit địa chỉ luận lý = $p + d$

> ⚠️ **Bẫy:** "Số trang" có thể cho **12 trang** → cần $\lceil\log_2 12\rceil = 4$ bit (không phải 12 bit). Tương tự số frame 36 → 6 bit.

---

# PHẦN C — CHƯƠNG 8: BỘ NHỚ ẢO

## C1. Bản chất cần hiểu

### 1. Bộ nhớ ảo (Virtual Memory)
- Kỹ thuật cho phép **không nạp toàn bộ** tiến trình vào bộ nhớ vật lý.
- **Lợi ích:** nhiều tiến trình hơn trong RAM; tiến trình **lớn hơn RAM** vẫn chạy; giảm gánh nặng lập trình viên.
- **Swap space:** vùng tráo đổi trên đĩa (`swap partition` Linux, `pagefile.sys` Windows).

### 2. Demand Paging (Phân trang theo yêu cầu)
- Trang **chỉ được nạp khi được yêu cầu** (lazy swapper / pager).
- Tham chiếu trang **không có** trong bộ nhớ → **page-fault trap**.

**Các bước xử lý page fault:**
1. Kiểm tra truy xuất hợp lệ (không hợp lệ → lỗi tiến trình).
2. Không có frame trống → dùng **giải thuật thay trang** chọn **victim page**.
3. Nếu victim bị "dirty" → **ghi ra đĩa**.
4. **Nạp trang cần** vào frame vừa trống.
5. Cập nhật **page table** + **frame table**.
6. Tiến trình quay lại chạy tại lệnh đã gây lỗi.

> 🔑 **Trạng thái tiến trình:** Khi xảy ra page fault → tiến trình chuyển sang **BLOCKED / WAITING** (chờ I/O đĩa).
> ⚠️ **Bẫy:** Nó **KHÔNG** chuyển ngay sang **Ready**. Chỉ khi I/O hoàn tất mới → **Ready**.

### 3. Các giải thuật thay trang

| Giải thuật | Chọn victim | Đặc điểm |
|---|---|---|
| **FIFO** | Trang **vào sớm nhất** | Có thể gặp **Belady's Anomaly** |
| **OPT** | Trang sẽ được dùng **trễ nhất trong tương lai** | Tối ưu nhưng **không thực thi được** (cần tương lai) |
| **LRU** | Trang **lâu nhất chưa dùng** (nhìn quá khứ) | Cần **phần cứng** hỗ trợ (counter/stack); gần OPT |

> 🔑 **Belady's Anomaly:** tăng số frame nhưng **số page fault lại TĂNG**. Chỉ xảy ra với **FIFO** (và một số thuật toán không phải "stack algorithm"). **LRU/OPT không có** Belady's Anomaly.
> ⚠️ **Bẫy:** "Thêm frame thì page fault luôn giảm" → **SAI** (phản ví dụ FIFO).

### 4. Cấp phát Frame

| Chiến lược | Cách làm |
|---|---|
| **Equal (bằng nhau)** | Chia đều: 100 frame / 5 tiến trình = 20 frame |
| **Proportional (tỉ lệ)** | Dựa theo **kích thước** tiến trình |
| **Priority (ưu tiên)** | Tiến trình ưu tiên cao → nhiều frame |

- Cấp **ít frame** → nhiều page fault. Cấp **quá nhiều** → giảm mức độ multiprogramming.
- **Dynamic allocation:** điều chỉnh số frame theo tần suất page fault khi chạy.

### 5. Thrashing (Sự rung lắc)

- **Định nghĩa:** trang bị hoán chuyển vào/ra **liên tục**; **page fault rate rất cao** → CPU utilization **giảm**.
- **Nguyên nhân:** tiến trình **không đủ frame** để chứa locality hiện tại.
- **Nguyên lý Locality:** tiến trình gồm nhiều **cụm trang** được tham chiếu gần nhau.
- Thrashing xảy ra khi: $\sum \text{size of locality} > \text{memory size}$.

> ⚠️ **Bẫy cực hay ra:** Khi thrashing, **CPU utilization THẤP** (không phải cao). HĐH càng tăng mức đa chương → càng thrashing → vòng xoáy. **KHÔNG** nhầm với trạng thái CPU bận.

### 6. Working Set Model

- **WS** (Working Set): tập $\Delta$ trang được tham chiếu trong **cửa sổ thời gian gần nhất**.
- **WSS$_i$:** kích thước working set của tiến trình $P_i$.
- $D = \sum \text{WSS}_i$ (tổng nhu cầu).
- Nếu $D > m$ (số frame hệ thống) → **nguy cơ thrashing** → tạm dừng 1 tiến trình.

| Chọn $\Delta$ | Hệ quả |
|---|---|
| $\Delta$ **quá nhỏ** | Không bao phủ hết **locality** hiện tại |
| $\Delta$ **quá lớn** | Bao phủ **nhiều locality** khác nhau (không chính xác) |

### 7. EAT có page fault

$$EAT = (1-p)\cdot ma + p \cdot (\text{page fault service time})$$

Trong đó $p$ = page-fault rate, $ma$ = memory access time.

> ⚠️ **Bẫy:** "Tăng page-fault rate làm EAT giảm" → **SAI** (page fault service time rất lớn, cỡ ms, so với ns).

---

# PHẦN D — BẢNG PHÂN BIỆT TỔNG HỢP (HAY BỊ GÀI NHẤT)

| Cặp khái niệm | Phân biệt chốt hạ |
|---|---|
| **Page vs Frame** | Page = đơn vị **luận lý** (chương trình). Frame = đơn vị **vật lý** (RAM) |
| **Logical vs Physical address** | Logical do CPU sinh; Physical do MMU tạo |
| **Internal vs External fragmentation** | Nội = lỗ **bên trong** partition/trang cấp phát. Ngoại = lỗ **giữa** các partition |
| **Fixed vs Dynamic partitioning** | Cố định → nội; Động → ngoại |
| **Page fault vs TLB miss** | Page fault = trang **không ở RAM** (tốn I/O đĩa). TLB miss = chỉ tra bảng trang, **có thể trang vẫn ở RAM** |
| **Belady's Anomaly** | Xảy ra FIFO; **không** xảy ra LRU/OPT |
| **LRU vs FIFO** | FIFO xét **lúc vào**; LRU xét **lúc dùng gần nhất** |
| **OPT vs LRU** | OPT nhìn **tương lai** (bất khả thi); LRU nhìn **quá khứ** |
| **Thrashing** | Page fault cao → CPU util **thấp** |
| **Demand paging vs Swapping** | Demand paging = nạp từng **trang**; Swapping = tráo cả **tiến trình** |
| **Fragmentation vs Compaction** | Fragmentation là vấn đề; Compaction là **cách giải quyết** (cần binding ở execution time) |

---

# PHẦN E — CHECKLIST TỰ KIỂM TRA

## Chương 5
- [ ] Phân biệt được **Race condition** và **Critical Section**.
- [ ] Nêu và **giải thích bản chất** 3 điều kiện của lời giải CS.
- [ ] Biết chính xác giải pháp `turn` / `flag` / `Peterson` đảm bảo và vi phạm gì.
- [ ] Giải thích vì sao Peterson hỏng trên CPU hiện đại (reorder) và Memory Barrier.
- [ ] Phân biệt **busy waiting** và **block/wakeup**.
- [ ] Viết được `wait`/`signal` không busy waiting và **tính số tiến trình bị block từ giá trị âm**.
- [ ] Nhớ **giá trị khởi tạo** semaphore cho từng mục đích (0 vs 1).
- [ ] Viết được code 3 bài toán kinh điển, chỉ ra chỗ có thể deadlock/starvation.
- [ ] Phân biệt **Deadlock / Starvation / Priority Inversion**.

## Chương 7
- [ ] Phân biệt 4 loại địa chỉ và 3 thời điểm binding.
- [ ] Nhớ hệ quả: cố định → nội, động → ngoại.
- [ ] Phân biệt 4 chiến lược placement (first/best/worst/next).
- [ ] Giải thích `p`, `d`, số mục bảng trang.
- [ ] Tính EAT có/không TLB thành thạo.
- [ ] Chuyển đổi **LA ↔ PA** thành thạo (kẻ bảng từng bước).
- [ ] Phân biệt PTBR/PTLR, 2-level paging, inverted page table.
- [ ] Biết paging **vẫn có internal fragmentation** ở trang cuối.

## Chương 8
- [ ] Trình bày 6 bước xử lý page fault và **trạng thái tiến trình** ở mỗi bước.
- [ ] So sánh FIFO/OPT/LRU; biết ai có **Belady's Anomaly**.
- [ ] Giải thích Belady's Anomaly bằng phản ví dụ.
- [ ] Phân biệt 3 chiến lược cấp phát frame.
- [ ] Giải thích **Thrashing** và mối quan hệ với CPU utilization.
- [ ] Trình bày **Working Set Model**, $D > m$ nghĩa là gì, $\Delta$ nhỏ/lớn ra sao.

---

# PHẦN F — CÂU HỎI TỰ LUYỆN DẠNG "PARAPHRASE"

> Đây là các câu được **viết lại theo kiểu lách léo** — tự trả lời để test độ hiểu.

### Chương 5
1. "Nếu hai tiến trình luôn chạy tuần tự và chưa bao giờ bị ngắt, liệu có thể xảy ra race condition không? Vì sao?" *(Gợi ý: không, vì không có xen kẽ.)*
2. "Một lời giải đảm bảo mỗi lúc chỉ 1 tiến trình vào CS, nhưng một tiến trình có thể chờ mãi. Lời giải này vi phạm điều kiện nào?" *(Progress hoặc Bounded waiting — tùy mô tả.)*
3. "Tôi khởi tạo `synch = 1` để ép P2 chạy sau P1, có đúng không?" *(Sai — phải là 0.)*
4. "Vì sao mutex thường không cần HĐH hỗ trợ còn semaphore không busy-waiting thì cần?" *(Vì `block/wakeup` là API của HĐH.)*
5. "Nếu semaphore có giá trị `-3`, hệ thống đang có bao nhiêu tiến trình bị chặn?" *(3.)*
6. "Trong Dining-Philosophers, nếu mọi triết gia đều thuận tay trái, hậu quả là gì?" *(Deadlock.)*
7. "Ưu tiên đảo ngược (priority inversion) có phải là deadlock không?" *(Không — là tình huống ưu tiên bị đảo, giải bằng priority inheritance.)*

### Chương 7
8. "Phân vùng cố định gây ra loại phân mảnh nào, và phân vùng động gây ra loại nào?" *(Nội / Ngoại.)*
9. "Vì sao compaction không thể thực hiện nếu binding ở compile time?" *(Vì địa chỉ tuyệt đối gắn cứng, không tái định vị được.)*
10. "Nếu không có TLB, một lệnh `load` truy cập bộ nhớ chính mấy lần?" *(2 lần.)*
11. "Kỹ thuật phân trang có làm mất hoàn toàn phân mảnh không?" *(Không — hết ngoại nhưng còn nội ở trang cuối.)*
12. "Bảng trang nghịch đảo có số mục bằng số trang hay số frame?" *(Số frame.)*
13. "Không gian địa chỉ ảo 32 bit, page size 4 KB. Bảng trang có bao nhiêu mục?" *($2^{32}/2^{12} = 2^{20} \approx 1\text{M}$ mục.)*

### Chương 8
14. "Nếu tăng số frame cấp cho tiến trình, số page fault có luôn giảm?" *(Không — ngoại lệ FIFO/Belady.)*
15. "Khi thrashing, CPU utilization cao hay thấp?" *(Thấp.)*
16. "Working set có kích thước $\Delta$ rất nhỏ thì sao?" *(Không bao phủ hết locality.)*
17. "Khi xảy ra page fault, tiến trình chuyển sang trạng thái nào?" *(Blocked/Waiting, không phải Ready.)*
18. "Giải thuật thay trang nào không thể cài đặt trong thực tế và vì sao?" *(OPT — cần biết tương lai.)*
19. "TLB hit ratio 99% có nghĩa page fault rate gần 0%?" *(Không — hai khái niệm khác nhau.)*
20. "Nếu $D = \sum \text{WSS}_i > m$ thì điều gì xảy ra?" *(Nguy cơ thrashing, cần giảm mức đa chương.)*
