#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory> // Cho Smart Pointers

using namespace std; // Giúp không cần gõ std:: trước vector, cout, cin...

// ==========================================
// 1. CLASS & STRUCT (Cấu trúc dữ liệu custom)
// ==========================================

// In Java: mọi thứ là class. 
// In C++: struct và class tương tự nhau, khác biệt duy nhất:
// struct mặc định member là public, class mặc định member là private.
// Môn DSA thường dùng struct cho Node của Linked List / Tree cho ngắn gọn.

struct Node {
    int val;
    Node* next; // Con trỏ trỏ đến Node tiếp theo (Java: Node next)

    // Constructor
    Node(int v) : val(v), next(nullptr) {} 
};

class Student {
private:
    string name;
    int age;

public:
    // Constructor với Member Initializer List (Hiệu năng tốt hơn gán trong body)
    Student(string n, int a) : name(n), age(a) {}

    // Getter
    string getName() const { return name; } // const nghĩa là hàm này không sửa thuộc tính của class
    int getAge() const { return age; }

    // Overload operator (C++ có, Java không có) - Dùng để so sánh/sort object
    bool operator<(const Student& other) const {
        return age < other.age; // Sắp xếp theo tuổi tăng dần
    }
};

// ==========================================
// 2. PASS BY VALUE, REFERENCE, POINTER
// ==========================================

// Pass by value (Truyền tham trị) - Tạo bản sao, thay đổi không ảnh hưởng biến ngoài
void incrementValue(int a) {
    a++;
}

// Pass by reference (Truyền tham chiếu) - Dùng dấu &, sửa trực tiếp biến gốc (Rất dùng nhiều trong DSA!)
void incrementRef(int& a) {
    a++;
}

// Pass by pointer (Truyền con trỏ) - Tương tự Java khi truyền object
void incrementPtr(int* a) {
    if (a != nullptr) {
        (*a)++; // Giải tham chiếu (dereference) để lấy giá trị và cộng 1
    }
}

// ==========================================
// MAIN FUNCTION
// ==========================================
int main() {
    // Tối ưu tốc độ I/O cho competitive programming / chấm bài online (BẮT BUỘC NÊN DÙNG)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "=== 1. (I/O) ===" << endl;
    int x = 10;
    double y = 3.14;
    string s = "Hello DSA";
    cout << "x = " << x << ", y = " << y << ", s = " << s << "\n"; // '\n' nhanh hơn endl

    // Nhập dữ liệu (uncomment khi test thủ công):
    // cin >> x; 
    // getline(cin, s); // Nhập cả dòng có khoảng trắng (tương đương scanner.nextLine())

    cout << "\n=== 2. DYNAMIC ARRAY (std::vector ~ Java ArrayList) ===" << endl;
    vector<int> nums = {1, 2, 3, 4, 5};
    nums.push_back(6); // Thêm vào cuối (Java: add)
    nums.pop_back();   // Xóa phần tử cuối

    // Duyệt vector:
    // Cách 1: Range-based for loop (for-each)
    for (int num : nums) {
        cout << num << " ";
    }
    cout << "\n";

    // Cách 2: Duyệt bằng chỉ số index
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";

    // Khai báo vector kích thước N với giá trị mặc định 0:
    vector<int> grid(10, 0); 
    // Khai báo ma trận 2D N x M:
    vector<vector<int>> matrix(3, vector<int>(4, -1)); // 3 hàng, 4 cột toàn -1

    cout << "\n=== 3. STRING (std::string) ===" << endl;
    string str = "Data Structures";
    cout << "Length: " << str.length() << "\n";
    cout << "Substring (pos, len): " << str.substr(0, 4) << "\n"; // "Data"
    if (str.find("Struct") != string::npos) {
        cout << "Found 'Struct' at index: " << str.find("Struct") << "\n";
    }

    cout << "\n=== 4. Pointers & Dynamic Memory ===" << endl;
    int a = 100;
    int* ptr = &a; // ptr lưu địa chỉ của a
    cout << "Gia tri a: " << a << "\n";
    cout << "Dia chi a (&a): " << &a << "\n";
    cout << "Gia tri ptr tro toi (*ptr): " << *ptr << "\n";

    // Cấp phát động bằng new/delete (Giống Java new, nhưng C++ phải delete tay nếu dùng pointer thô)
    Node* head = new Node(10);
    head->next = new Node(20); // Dùng dấu '->' khi truy cập member thông qua pointer
    
    cout << "Node 1: " << head->val << " -> Node 2: " << head->next->val << "\n";

    // Dọn dẹp bộ nhớ (Tránh memory leak)
    delete head->next;
    delete head;

    cout << "\n=== 5. STACK, QUEUE & PRIORITY QUEUE ===" << endl;
    // Stack (LIFO)
    stack<int> st;
    st.push(1); st.push(2);
    cout << "Stack top: " << st.top() << "\n";
    st.pop(); // Xóa nhưng không trả về giá trị

    // Queue (FIFO)
    queue<int> q;
    q.push(10); q.push(20);
    cout << "Queue front: " << q.front() << "\n";
    q.pop();

    // Priority Queue (Max Heap mặc định - Java mặc định là Min Heap!)
    priority_queue<int> maxHeap;
    maxHeap.push(3); maxHeap.push(1); maxHeap.push(5);
    cout << "Max Heap top: " << maxHeap.top() << "\n"; // Output: 5

    // Min Heap trong C++
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(3); minHeap.push(1); minHeap.push(5);
    cout << "Min Heap top: " << minHeap.top() << "\n"; // Output: 1

    cout << "\n=== 6. SET & MAP ===" << endl;
    // Hash Map (Java: HashMap) - O(1)
    unordered_map<string, int> ageMap;
    ageMap["Alice"] = 20;
    ageMap["Bob"] = 22;
    if (ageMap.find("Alice") != ageMap.end()) {
        cout << "Alice's age: " << ageMap["Alice"] << "\n";
    }

    // Tree Map (Java: TreeMap) - Tự động sắp xếp key - O(log N)
    map<int, string> sortedMap;
    sortedMap[3] = "Three";
    sortedMap[1] = "One";

    // Hash Set (Java: HashSet)
    unordered_set<int> uniqueNums;
    uniqueNums.insert(5);
    uniqueNums.insert(5); // Sẽ bị trùng, chỉ lưu 1 số 5

    // Tree Set (Java: TreeSet)
    set<int> sortedSet = {3, 1, 4, 1, 5}; // Luôn giữ thứ tự tăng dần

    cout << "\n=== 7. BUILT-IN ALGORITHMS (std::algorithm) ===" << endl;
    vector<int> arr = {5, 2, 8, 1, 3};

    // Sort tăng dần
    sort(arr.begin(), arr.end()); // C++ dùng iterator begin() và end()

    // Sort giảm dần
    sort(arr.begin(), arr.end(), greater<int>());

    // Tìm kiếm nhị phân (Binary Search) - Yêu cầu mảng đã sort
    sort(arr.begin(), arr.end());
    bool found = binary_search(arr.begin(), arr.end(), 3);
    cout << "Is 3 in array? " << (found ? "Yes" : "No") << "\n";

    // Max/Min element
    int maxVal = *max_element(arr.begin(), arr.end());
    cout << "Max element: " << maxVal << "\n";

    cout << "\n=== 8. PASS BY REFERENCE ===" << endl;
    int val = 5;
    incrementRef(val);
    cout << "Val after incrementRef: " << val << "\n"; // Output: 6

    return 0;
}