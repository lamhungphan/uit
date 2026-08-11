# 4.1 - FCFS
- P1: Arrival Time = 4, Burst Time = 9
- P2: Arrival Time = 0, Burst Time = 6
- P3: Arrival Time = 16, Burst Time = 10
- P4: Arrival Time = 7, Burst Time = 20
- P5: Arrival Time = 6, Burst Time = 4

**Định thời dùng giải thuật FCFS (First Come First Served)**

## a. Quá trình điều phối
- Thời điểm t = 0: Chỉ có P2 đến (Arrival = 0). P2 chạy từ 0 đến 6 (Burst = 6).
- Thời điểm t = 6: P2 hoàn thành. Hàng chờ gồm P1 (đến t = 4), P5 (đến t = 6). P1 đến trước, chạy từ 6 đến 15 (6 + 9).
- Thời điểm t = 15: P1 hoàn thành. Hàng chờ gồm P5 (đến t = 6), P4 (đến t = 7). P5 đến trước, chạy từ 15 đến 19 (15 + 4).
- Thời điểm t = 19: P5 hoàn thành. P4 chạy từ 19 đến 39 (19 + 20).
- Thời điểm t = 39: P4 hoàn thành. P3 (đến t = 16) chạy từ 39 đến 49 (39 + 10).

## b. Trình tự thực thi của các tiến trình
- P2 (0 – 6)
- P1 (6 – 15)
- P5 (15 – 19)
- P4 (19 – 39)
- P3 (39 – 49)

## c. Thời gian đáp ứng (Response Time)
Công thức: RT = Thời điểm nhận CPU lần đầu - Thời điểm đến
- P1: 6 - 4 = 2
- P2: 0 - 0 = 0
- P3: 39 - 16 = 23
- P4: 19 - 7 = 12
- P5: 15 - 6 = 9
- Avg RT = (2 + 0 + 23 + 12 + 9) / 5 = 9.2

## d. Thời gian hoàn thành (Turnaround Time)
Công thức: TAT = Thời điểm hoàn thành - Thời điểm đến
- P1: 15 - 4 = 11
- P2: 6 - 0 = 6
- P3: 49 - 16 = 33
- P4: 39 - 7 = 32
- P5: 19 - 6 = 13
- Avg TAT = (11 + 6 + 33 + 32 + 13) / 5 = 19

## e. Thời gian chờ (Waiting Time)
Công thức: WT = TAT - Burst Time
- P1: 11 - 9 = 2
- P2: 6 - 6 = 0
- P3: 33 - 10 = 23
- P4: 32 - 20 = 12
- P5: 13 - 4 = 9
- Avg WT = (2 + 0 + 23 + 12 + 9) / 5 = 9.2

# 4.2 - SJF
- P1: Arrival Time = 6, Burst Time = 4
- P2: Arrival Time = 7, Burst Time = 17
- P3: Arrival Time = 0, Burst Time = 14
- P4: Arrival Time = 4, Burst Time = 9
- P5: Arrival Time = 15, Burst Time = 9

**Định thời dùng giải thuật SJF (Shortest Job First) không trưng dụng**

## a. Quá trình điều phối
- Thời điểm t = 0: Chỉ có P3 đến (Arrival = 0). P3 chạy từ 0 đến 14 (Burst = 14).
- Thời điểm t = 14: P3 hoàn thành. Hàng chờ gồm P1 (đến t = 6, Burst = 4), P2 (đến t = 7, Burst = 17), P4 (đến t = 4, Burst = 9). P1 có Burst nhỏ nhất (4), chạy từ 14 đến 18 (14 + 4).
- Thời điểm t = 18: P1 hoàn thành. Hàng chờ gồm P2 (Burst = 17), P4 (Burst = 9), P5 (đến t = 15, Burst = 9). P4 và P5 cùng Burst = 9, P4 đến trước (t = 4 < 15) nên P4 chạy từ 18 đến 27 (18 + 9).
- Thời điểm t = 27: P4 hoàn thành. Hàng chờ gồm P5 (Burst = 9), P2 (Burst = 17). P5 có Burst nhỏ hơn, chạy từ 27 đến 36 (27 + 9).
- Thời điểm t = 36: P5 hoàn thành. P2 chạy từ 36 đến 53 (36 + 17).

## b. Trình tự thực thi của các tiến trình
- P3 (0 – 14)
- P1 (14 – 18)
- P4 (18 – 27)
- P5 (27 – 36)
- P2 (36 – 53)

## c. Thời gian đáp ứng (Response Time)
Công thức: RT = Thời điểm nhận CPU lần đầu - Thời điểm đến
- P1: 14 - 6 = 8
- P2: 36 - 7 = 29
- P3: 0 - 0 = 0
- P4: 18 - 4 = 14
- P5: 27 - 15 = 12
- Avg RT = (8 + 29 + 0 + 14 + 12) / 5 = 12.6

## d. Thời gian hoàn thành (Turnaround Time)
Công thức: TAT = Thời điểm hoàn thành - Thời điểm đến
- P1: 18 - 6 = 12
- P2: 53 - 7 = 46
- P3: 14 - 0 = 14
- P4: 27 - 4 = 23
- P5: 36 - 15 = 21
- Avg TAT = (12 + 46 + 14 + 23 + 21) / 5 = 23.2

## e. Thời gian chờ (Waiting Time)
Công thức: WT = TAT - Burst Time
- P1: 12 - 4 = 8
- P2: 46 - 17 = 29
- P3: 14 - 14 = 0
- P4: 23 - 9 = 14
- P5: 21 - 9 = 12
- Avg WT = (8 + 29 + 0 + 14 + 12) / 5 = 12.6

# 4.3.1 - Priority Scheduling (Preemptive)
- P1: Arrival Time = 6, Burst Time = 4, Priority = 1
- P2: Arrival Time = 7, Burst Time = 17, Priority = 2
- P3: Arrival Time = 0, Burst Time = 14, Priority = 4
- P4: Arrival Time = 4, Burst Time = 9, Priority = 3
- P5: Arrival Time = 15, Burst Time = 9, Priority = 5

**Định thời dùng giải thuật Priority Scheduling không trưng dụng (độ ưu tiên 1 > 2 > 3 > 4 > 5)**

## a. Quá trình điều phối
- Thời điểm t = 0: Chỉ có P3, P3 chạy từ 0 đến 14 (Burst = 14).
- Thời điểm t = 14: P3 hoàn thành. Hàng chờ gồm P1 (ưu tiên 1), P2 (2), P4 (3). P1 có độ ưu tiên cao nhất, chạy từ 14 đến 18 (14 + 4).
- Thời điểm t = 18: P1 hoàn thành. Hàng chờ gồm P2 (2), P4 (3), P5 (5). P2 chạy từ 18 đến 35 (18 + 17).
- Thời điểm t = 35: P2 hoàn thành. Hàng chờ gồm P4 (3), P5 (5). P4 chạy từ 35 đến 44 (35 + 9).
- Thời điểm t = 44: P4 hoàn thành. P5 chạy từ 44 đến 53 (44 + 9).

## b. Trình tự thực thi của các tiến trình
- P3 (0 – 14)
- P1 (14 – 18)
- P2 (18 – 35)
- P4 (35 – 44)
- P5 (44 – 53)

## c. Thời gian đáp ứng (Response Time)
Công thức: RT = Thời điểm nhận CPU lần đầu - Thời điểm đến
- P1: 14 - 6 = 8
- P2: 18 - 7 = 11
- P3: 0 - 0 = 0
- P4: 35 - 4 = 31
- P5: 44 - 15 = 29
- Avg RT = (8 + 11 + 0 + 31 + 29) / 5 = 15.8

## d. Thời gian hoàn thành (Turnaround Time)
Công thức: TAT = Thời điểm hoàn thành - Thời điểm đến
- P1: 18 - 6 = 12
- P2: 35 - 7 = 28
- P3: 14 - 0 = 14
- P4: 44 - 4 = 40
- P5: 53 - 15 = 38
- Avg TAT = (12 + 28 + 14 + 40 + 38) / 5 = 26.4

## e. Thời gian chờ (Waiting Time)
Công thức: WT = TAT - Burst Time
- P1: 12 - 4 = 8
- P2: 28 - 17 = 11
- P3: 14 - 14 = 0
- P4: 40 - 9 = 31
- P5: 38 - 9 = 29
- Avg WT = (8 + 11 + 0 + 31 + 29) / 5 = 15.8

# 4.3.2 - Priority Scheduling (Non-preemptive)
- P1: Arrival Time = 6, Burst Time = 4, Priority = 1
- P2: Arrival Time = 7, Burst Time = 17, Priority = 2
- P3: Arrival Time = 0, Burst Time = 14, Priority = 4
- P4: Arrival Time = 4, Burst Time = 9, Priority = 3
- P5: Arrival Time = 15, Burst Time = 9, Priority = 5

**Định thời dùng giải thuật Priority Scheduling trưng dụng (độ ưu tiên 1 > 2 > 3 > 4 > 5)**

## a. Quá trình điều phối
- Thời điểm t = 0: P3 đến (ưu tiên 4). Chưa có tiến trình khác, P3 vào thực thi.
- Thời điểm t = 4: P4 đến (ưu tiên 3), trưng dụng CPU. P3 bị ngắt (đã chạy 4 đơn vị, còn lại 10). P4 thực thi.
- Thời điểm t = 6: P1 đến (ưu tiên 1), trưng dụng CPU. P4 bị ngắt (đã chạy 2 đơn vị, còn lại 7). P1 thực thi.
- Thời điểm t = 7: P2 đến (ưu tiên 2). P1 vẫn ưu tiên cao nhất nên tiếp tục chạy, P2 vào hàng chờ.
- Thời điểm t = 10: P1 hoàn thành. Hàng chờ gồm P2 (còn 17), P4 (còn 7), P3 (còn 10). P2 vào thực thi.
- Thời điểm t = 15: P5 đến (ưu tiên 5). P2 (ưu tiên 2) tiếp tục chạy.
- Thời điểm t = 27: P2 hoàn thành. Hàng chờ gồm P4 (còn 7), P3 (còn 10), P5 (còn 9). P4 vào thực thi.
- Thời điểm t = 34: P4 hoàn thành. Hàng chờ gồm P3 (còn 10), P5 (còn 9). P3 vào thực thi.
- Thời điểm t = 44: P3 hoàn thành. P5 thực thi đến khi hoàn thành lúc t = 53.

## b. Trình tự thực thi của các tiến trình
- P3 (0 – 4)
- P4 (4 – 6)
- P1 (6 – 10)
- P2 (10 – 27)
- P4 (27 – 34)
- P3 (34 – 44)
- P5 (44 – 53)

## c. Thời gian đáp ứng (Response Time)
Công thức: RT = Thời điểm nhận CPU lần đầu - Thời điểm đến
- P1: 6 - 6 = 0
- P2: 10 - 7 = 3
- P3: 0 - 0 = 0
- P4: 4 - 4 = 0
- P5: 44 - 15 = 29
- Avg RT = (0 + 3 + 0 + 0 + 29) / 5 = 6.4

## d. Thời gian hoàn thành (Turnaround Time)
Công thức: TAT = Thời điểm hoàn thành - Thời điểm đến
- P1: 10 - 6 = 4
- P2: 27 - 7 = 20
- P3: 44 - 0 = 44
- P4: 34 - 4 = 30
- P5: 53 - 15 = 38
- Avg TAT = (4 + 20 + 44 + 30 + 38) / 5 = 27.2

## e. Thời gian chờ (Waiting Time)
Công thức: WT = TAT - Burst Time
- P1: 4 - 4 = 0
- P2: 20 - 17 = 3
- P3: 44 - 14 = 30
- P4: 30 - 9 = 21
- P5: 38 - 9 = 29
- Avg WT = (0 + 3 + 30 + 21 + 29) / 5 = 16.6

# 4.4
- P1: Arrival Time = 6, Burst Time = 4
- P2: Arrival Time = 7, Burst Time = 17
- P3: Arrival Time = 0, Burst Time = 14
- P4: Arrival Time = 4, Burst Time = 9
- P5: Arrival Time = 15, Burst Time = 9

**Định thời dùng giải thuật Round Robin với quantum q = 5**

## a. Quá trình điều phối
- Thời điểm t = 0: P3 chạy 5 đơn vị (0 → 5), còn lại 9. Tại t = 4, P4 đến. Hàng chờ: [P4, P3].
- Thời điểm t = 5: P4 chạy 5 đơn vị (5 → 10), còn lại 4. Tại t = 6, P1 đến; tại t = 7, P2 đến. Hàng chờ: [P3, P1, P2, P4].
- Thời điểm t = 10: P3 chạy 5 đơn vị (10 → 15), còn lại 4. Tại t = 15, P5 đến và đứng trước P3 (vừa hết lượt). Hàng chờ: [P1, P2, P4, P5, P3].
- Thời điểm t = 15: P1 chạy hết 4 đơn vị (15 → 19), hoàn thành. Hàng chờ: [P2, P4, P5, P3].
- Thời điểm t = 19: P2 chạy 5 đơn vị (19 → 24), còn lại 12. Hàng chờ: [P4, P5, P3, P2].
- Thời điểm t = 24: P4 chạy nốt 4 đơn vị (24 → 28), hoàn thành. Hàng chờ: [P5, P3, P2].
- Thời điểm t = 28: P5 chạy 5 đơn vị (28 → 33), còn lại 4. Hàng chờ: [P3, P2, P5].
- Thời điểm t = 33: P3 chạy nốt 4 đơn vị (33 → 37), hoàn thành. Hàng chờ: [P2, P5].
- Thời điểm t = 37: P2 chạy 5 đơn vị (37 → 42), còn lại 7. Hàng chờ: [P5, P2].
- Thời điểm t = 42: P5 chạy nốt 4 đơn vị (42 → 46), hoàn thành. Hàng chờ: [P2].
- Thời điểm t = 46: P2 chạy nốt 7 đơn vị (46 → 53), hoàn thành.

## b. Trình tự thực thi của các tiến trình
- P3 (0 – 5)
- P4 (5 – 10)
- P3 (10 – 15)
- P1 (15 – 19)
- P2 (19 – 24)
- P4 (24 – 28)
- P5 (28 – 33)
- P3 (33 – 37)
- P2 (37 – 42)
- P5 (42 – 46)
- P2 (46 – 53)

## c. Thời gian đáp ứng (Response Time)
Công thức: RT = Thời điểm nhận CPU lần đầu - Thời điểm đến
- P1: 15 - 6 = 9
- P2: 19 - 7 = 12
- P3: 0 - 0 = 0
- P4: 5 - 4 = 1
- P5: 28 - 15 = 13
- Avg RT = (9 + 12 + 0 + 1 + 13) / 5 = 7

## d. Thời gian hoàn thành (Turnaround Time)
Công thức: TAT = Thời điểm hoàn thành - Thời điểm đến
- P1: 19 - 6 = 13
- P2: 53 - 7 = 46
- P3: 37 - 0 = 37
- P4: 28 - 4 = 24
- P5: 46 - 15 = 31
- Avg TAT = (13 + 46 + 37 + 24 + 31) / 5 = 30.2

## e. Thời gian chờ (Waiting Time)
Công thức: WT = TAT - Burst Time
- P1: 13 - 4 = 9
- P2: 46 - 17 = 29
- P3: 37 - 14 = 23
- P4: 24 - 9 = 15
- P5: 31 - 9 = 22
- Avg WT = (9 + 29 + 23 + 15 + 22) / 5 = 19.6
