## Con trỏ và ứng dụng

### Đặt vấn đề
trong 1 chương trình khai báo 3 biến. hỏi 3 biến được quản lý như thế nào

```cpp
#include <iostream>
using namespace std;

int main(){
    char c = 'F';
    int x = 10;
    double y = 1.8;

    return 0;
}
```

### Vùng nhớ RAM
trong ram chứa nhiều cell kích thước 1 byte tương ứng với 1 địa chỉ hệ 16 theo thứ tự

### Trả lời
- hiểu đơn giản là giá trị được đưa vô cell, còn bằng cách nào nằm ở môn "kiến trúc máy tính". Hễ gọi đến c là gọi đến vùng nhớ có địa chỉ...
- chọn địa chỉ để làm vùng nhớ (duy nhất và không trùng nhau)
=> để quản lý biến x hoặc địa chỉ
=> con trỏ là sử dụng giá trị địa chỉ

- địa chỉ giống như tờ giấy đánh dấu kho hàng ở đâu, việc gọi biến giống như lấy cả kho hàng

## Toán tử &
- dùng để lấy địa chỉ của biến
- `&tên_biến`

## Toán tử *
- dùng để truy cập vào giá trị mà một con trỏ đang trỏ đến
- `*địa_chỉ`

## Con trỏ
- 1 biến lưu trữ địa chỉ của 1 vùng nhớ
- `kiểu_dữ_liệu* tên_biến`

## Cấp phát bộ nhớ tĩnh (Static Memory Allocation)

## Cấp phát bộ nhớ động (Dynamic Memory Allocation)

## Thu hồi / Giải phóng

## Con trỏ và mảng 1 chiều

