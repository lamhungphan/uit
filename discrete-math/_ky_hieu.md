# Bảng ký hiệu Toán rời rạc

Ký hiệu có thể được đọc theo nhiều cách tùy ngữ cảnh. Cột “Cách đọc” ghi cách đọc ngắn gọn để đọc công thức thành tiếng; nếu không có cách đọc tự nhiên, ô được để trống.

## Logic mệnh đề, vị từ và suy luận

| Ký hiệu | Cách đọc | Tiếng Việt | English | Ý nghĩa |
|---|---|---|---|---|
| $p,q,r$ |  | Mệnh đề | Propositions | Các khẳng định có giá trị đúng hoặc sai |
| $0,1$ |  | Sai, đúng | False, true | Giá trị chân lý; cũng dùng cho bit tắt/bật |
| $\lnot p$ | Không p | Phủ định của p | Negation of p | Đúng khi $p$ sai |
| $\bar p$ | Nghịch p | Phủ định của p | Negation of p | Cách viết khác của phủ định |
| $p\land q$ | P và q | Hội | Conjunction / AND | Đúng khi cả hai mệnh đề đúng |
| $p\lor q$ | P hoặc q | Tuyển | Disjunction / OR | Đúng khi ít nhất một mệnh đề đúng |
| $p\oplus q$ | P hoặc loại trừ q | Tuyển loại | Exclusive OR / XOR | Đúng khi đúng chính xác một vế |
| $p\to q$ | Nếu p thì q | Kéo theo | Implication | Chỉ sai khi $p$ đúng và $q$ sai |
| $p\Rightarrow q$ | P kéo theo q | Kéo theo / suy ra | Implies | Tùy ngữ cảnh: phép kéo theo hoặc ký hiệu suy ra |
| $p\leftrightarrow q$ | P khi và chỉ khi q | Tương đương | Biconditional | Đúng khi hai vế cùng giá trị chân lý |
| $p\equiv q$ | P tương đương logic với q | Tương đương logic | Logically equivalent | Hai biểu thức có cùng giá trị trong mọi trường hợp |
| $\top$ | Đúng | Hằng đúng | Tautology / true | Biểu thức luôn đúng |
| $\bot$ | Sai | Hằng sai / mâu thuẫn | Contradiction / false | Biểu thức luôn sai |
| $\forall x\,P(x)$ | Với mọi x, P của x | Lượng từ phổ quát | Universal quantifier | $P(x)$ đúng với mọi phần tử trong miền xét |
| $\exists x\,P(x)$ | Tồn tại x sao cho P của x | Lượng từ tồn tại | Existential quantifier | Có ít nhất một phần tử làm $P(x)$ đúng |
| $P(x)$ | P của x | Vị từ / hàm mệnh đề | Predicate | Mệnh đề có biến; cần gán biến hoặc lượng từ |
| $\therefore$ | Do đó | Suy ra kết luận | Therefore | Đặt trước kết luận của lập luận |
| $\vdash$ | Có thể suy ra | Suy diễn được | Derives / proves | Kết luận được suy ra từ tiền đề theo quy tắc |
| $\lnot(\forall x\,P(x))$ | Phủ định “với mọi x” | Phủ định lượng từ | Negation of universal | Tương đương $\exists x\,\lnot P(x)$ |
| $\lnot(\exists x\,P(x))$ | Phủ định “tồn tại x” | Phủ định lượng từ | Negation of existential | Tương đương $\forall x\,\lnot P(x)$ |
| $p,\ p\to q\ \therefore q$ | P; nếu p thì q; do đó q | Modus Ponens | Modus Ponens | Từ $p$ và $p\to q$ suy ra $q$ |
| $p\to q,\ \lnot q\ \therefore\lnot p$ | Nếu p thì q; không q; do đó không p | Modus Tollens | Modus Tollens | Từ hệ quả sai suy ra giả thiết sai |

## Tập hợp và phép đếm

| Ký hiệu | Cách đọc | Tiếng Việt | English | Ý nghĩa |
|---|---|---|---|---|
| $A,B,S$ |  | Tập hợp | Set | Tập các phần tử đang xét |
| $x\in A$ | X thuộc A | Thuộc tập hợp | Is an element of | $x$ là phần tử của $A$ |
| $x\notin A$ | X không thuộc A | Không thuộc tập hợp | Is not an element of | $x$ không là phần tử của $A$ |
| $A\subseteq B$ | A là tập con của B | Tập con | Subset | Mọi phần tử của $A$ đều thuộc $B$ |
| $A\subset B$ | A là tập con thực sự của B | Tập con thực sự | Proper subset | $A$ là tập con và khác $B$ |
| $A\cup B$ | A hợp B | Hợp | Union | Phần tử thuộc $A$ hoặc $B$ hoặc cả hai |
| $A\cap B$ | A giao B | Giao | Intersection | Phần tử thuộc cả $A$ và $B$ |
| $A-B$ | A trừ B | Hiệu tập hợp | Set difference | Phần tử thuộc $A$ nhưng không thuộc $B$ |
| $\overline A$ | A gạch ngang trên | Phần bù của A | Complement of A | Các phần tử trong tập vũ trụ nhưng không thuộc $A$ |
| $\varnothing$ | Tập rỗng | Tập rỗng | Empty set | Tập không có phần tử |
| $U$ | U | Tập vũ trụ | Universal set | Tập chứa toàn bộ phần tử đang xét |
| $\mathcal P(S)$ | P hoa của S | Tập lũy thừa | Power set | Tập gồm mọi tập con của $S$ |
| $A\times B$ | A nhân Đề-các B | Tích Đề-các | Cartesian product | Tập các cặp $(a,b)$ với $a\in A,b\in B$ |
| $\lvert A\rvert$ | Số phần tử của A | Lực lượng tập hợp | Cardinality | Số phần tử của tập hữu hạn $A$ |
| $\lceil x\rceil$ | Trần của x | Hàm trần | Ceiling | Số nguyên nhỏ nhất lớn hơn hoặc bằng $x$ |
| $n!$ | N giai thừa | Giai thừa | Factorial | $n(n-1)\cdots1$; $0!=1$ |
| $P_n$ | P của n | Hoán vị n phần tử | Permutations | $P_n=n!$ cách sắp xếp $n$ phần tử |
| $A_n^k$ | A của n chập k | Chỉnh hợp chập k | k-permutations | Chọn và sắp thứ tự $k$ phần tử từ $n$: $\frac{n!}{(n-k)!}$ |
| $C_n^k$ | C của n chập k | Tổ hợp chập k | k-combinations | Chọn $k$ phần tử không xét thứ tự: $\frac{n!}{k!(n-k)!}$ |
| $\binom nk$ | N chọn k | Tổ hợp chập k | Binomial coefficient | Cách viết khác của $C_n^k$ |
| $\sum_{k=0}^n\binom nk$ | Tổng tổ hợp từ k bằng 0 đến n | Tổng các hệ số nhị thức | Sum of binomial coefficients | Bằng $2^n$ |
| $\lvert A\cup B\rvert$ | Số phần tử A hợp B | Lực lượng hợp | Cardinality of union | $\lvert A\rvert+\lvert B\rvert-\lvert A\cap B\rvert$ |
| $2^n$ | Hai mũ n | Lũy thừa hai | Power of two | Số chuỗi bit độ dài $n$; số dòng cho $n$ biến logic |

## Quan hệ và thứ tự

| Ký hiệu | Cách đọc | Tiếng Việt | English | Ý nghĩa |
|---|---|---|---|---|
| $R\subseteq A\times B$ | R là tập con của A nhân B | Quan hệ từ A đến B | Relation from A to B | Một tập các cặp có thứ tự |
| $aRb$ | A có quan hệ R với b | Quan hệ giữa a và b | a is related to b | Viết gọn cho $(a,b)\in R$ |
| $R^{-1}$ | R ngược | Quan hệ ngược | Inverse relation | Đổi $(a,b)$ thành $(b,a)$ |
| $M_R$ | Ma trận của R | Ma trận biểu diễn quan hệ | Matrix of a relation | Ô $(i,j)$ bằng 1 nếu cặp tương ứng thuộc $R$ |
| $M_R^T$ | M R chuyển vị | Ma trận chuyển vị | Transpose matrix | Ma trận quan hệ ngược |
| $a\mid b$ | A là ước của b | Chia hết | Divides | Có số nguyên $k$ sao cho $b=ak$ |
| $a\equiv b\pmod m$ | A đồng dư b modulo m | Đồng dư modulo m | Congruent modulo m | $m$ là ước của $a-b$ |
| $[a]_R$ | Lớp tương đương của a | Lớp tương đương | Equivalence class | Các phần tử tương đương với $a$ |
| $A/R$ | A chia R | Tập thương | Quotient set | Tập các lớp tương đương của $R$ trên $A$ |
| $\preceq$ | Nhỏ hơn hoặc bằng theo thứ tự | Quan hệ thứ tự bộ phận | Partial order | Quan hệ phản xạ, phản xứng và bắc cầu |
| $(A,\preceq)$ | A cùng thứ tự bộ phận | Poset / tập sắp thứ tự | Partially ordered set | Tập $A$ cùng quan hệ thứ tự |
| $a\prec b$ | A nhỏ hơn b theo thứ tự | Thứ tự nghiêm ngặt | Strict order | $a\preceq b$ và $a\ne b$ |
| $\mathbb Z$ |  | Tập số nguyên | Integers | $\{\ldots,-1,0,1,\ldots\}$ |
| $\mathbb Z^+$ | Z dương | Số nguyên dương | Positive integers | Các số nguyên dương |
| $\mathbb N$ |  | Tập số tự nhiên | Natural numbers | Tùy quy ước, có thể gồm hoặc không gồm số 0 |
| $\mathbb R$ |  | Tập số thực | Real numbers | Tập các số thực |
| $a\ne b$ | A khác b | Không bằng | Not equal | Hai giá trị không bằng nhau |
| $a\le b$ | A nhỏ hơn hoặc bằng b | Nhỏ hơn hoặc bằng | Less than or equal to | $a<b$ hoặc $a=b$ |
| $a\ge b$ | A lớn hơn hoặc bằng b | Lớn hơn hoặc bằng | Greater than or equal to | $a>b$ hoặc $a=b$ |

## Đại số Bool

| Ký hiệu | Cách đọc | Tiếng Việt | English | Ý nghĩa |
|---|---|---|---|---|
| $B=\{0,1\}$ | B gồm không và một | Tập Bool | Boolean set | Tập giá trị sai/đúng hoặc tắt/bật |
| $\bar x$ | X gạch ngang trên | Phủ định / phần bù của x | Complement / NOT | Trong Bool: $\bar x=1-x$ |
| $xy$ | X nhân y | Phép AND Bool | Boolean product / AND | Bằng 1 khi cả $x,y$ bằng 1 |
| $x\lor y$ | X hoặc y | Phép OR Bool | Boolean sum / OR | Bằng 1 nếu ít nhất một đầu vào bằng 1 |
| $x\land y$ | X và y | Phép AND | AND | Bằng 1 khi cả hai đầu vào bằng 1 |
| $f:B^n\to B$ | F từ B mũ n vào B | Hàm Bool n biến | Boolean function | Nhận $n$ đầu vào nhị phân và trả về 0 hoặc 1 |
| $\operatorname{Kar}(f)$ | Kar của f | Các ô bằng 1 trên bản đồ Karnaugh | Karnaugh map of f | Tập các tổ hợp đầu vào làm $f=1$ |
| NAND |    | Phủ định của AND | NOT-AND | $\overline{xy}$ |
| NOR |  | Phủ định của OR | NOT-OR | $\overline{x\lor y}$ |

## Đồ thị

| Ký hiệu | Cách đọc | Tiếng Việt | English | Ý nghĩa |
|---|---|---|---|---|
| $G=(V,E)$ | G bằng V, E | Đồ thị | Graph | $V$ là tập đỉnh, $E$ là tập cạnh |
| $V$ |  | Tập đỉnh | Vertex set | Các đối tượng trong đồ thị |
| $E$ |  | Tập cạnh | Edge set | Các kết nối giữa các đỉnh |
| $v,w\in V$ | V, w thuộc V | Đỉnh | Vertices | Các nút của đồ thị |
| $e=vw$ | Cạnh v-w | Cạnh nối v và w | Edge joining v and w | Cạnh vô hướng có hai đầu mút $v,w$ |
| $\deg(v)$ | Bậc của v | Bậc đỉnh | Degree | Số cạnh liên thuộc với $v$; vòng tính hai |
| $\lvert V\rvert,\lvert E\rvert$ | Số đỉnh, số cạnh | Số lượng đỉnh/cạnh | Number of vertices/edges | Kích thước các tập đỉnh và cạnh |
| $K_n$ | K của n | Đồ thị đầy đủ | Complete graph | Đơn đồ thị $n$ đỉnh, mọi cặp đỉnh nối nhau |
| $C_n$ | C của n | Đồ thị vòng | Cycle graph | Chu trình gồm $n$ đỉnh |
| $W_n$ | W của n | Đồ thị bánh xe | Wheel graph | Vòng và một đỉnh trung tâm nối với mọi đỉnh trên vòng |
| $K_{m,n}$ | K của m, n | Đồ thị lưỡng phân đầy đủ | Complete bipartite graph | Hai phía có $m,n$ đỉnh; mọi đỉnh khác phía được nối |
| $Q_n$ | Q của n | Khối lập phương n chiều | n-cube / hypercube | Đỉnh là chuỗi bit độ dài $n$, hai đỉnh nối nếu khác một bit |
| $\overline G$ | G bù | Đồ thị bù | Complement graph | Giữ đỉnh, đảo các cạnh của đơn đồ thị |
| $G\cong G'$ | G đẳng cấu G phẩy | Đẳng cấu đồ thị | Graph isomorphism | Có phép ghép đỉnh bảo toàn quan hệ kề |
| $A=(a_{ij})$ | A có phần tử a-i-j | Ma trận kề | Adjacency matrix | $a_{ij}$ ghi số cạnh nối hai đỉnh tương ứng |
| $M=(m_{ij})$ | M có phần tử m-i-j | Ma trận liên thuộc | Incidence matrix | Ghi đỉnh nào liên thuộc với cạnh nào |
| $\deg^+(v)$ | Bậc ra của v | Bậc ra | Out-degree | Số cung đi ra khỏi $v$ |
| $\deg^-(v)$ | Bậc vào của v | Bậc vào | In-degree | Số cung đi vào $v$ |
| $w(e)$ | W của e | Trọng số cạnh | Edge weight | Chi phí, độ dài hoặc thời gian gán cho cạnh |
| $w(p)$ | W của p | Trọng số đường đi | Path weight | Tổng trọng số các cạnh trên đường đi |
| $\infty$ | Vô cùng | Vô cùng | Infinity | Nhãn khởi tạo cho đỉnh chưa có đường đi đã biết |
| $S$ |  | Tập đỉnh đã chốt | Settled set | Trong Dijkstra, các đỉnh đã xác định khoảng cách ngắn nhất |
| $K_n$ có $\frac{n(n-1)}2$ cạnh | K của n có n nhân n trừ một chia hai cạnh | Số cạnh đồ thị đầy đủ | Edges in complete graph | Mỗi cạnh ứng với một cặp đỉnh |
| $\sum_{v\in V}\deg(v)=2\lvert E\rvert$ | Tổng bậc các đỉnh bằng hai lần số cạnh | Định lý bắt tay | Handshaking lemma | Mỗi cạnh đóng góp hai đầu mút vào tổng bậc |

## Đường đi, Euler và Hamilton

| Ký hiệu | Cách đọc | Tiếng Việt | English | Ý nghĩa |
|---|---|---|---|---|
| $v_0v_1\cdots v_n$ | V không, v một, …, v n | Đường đi | Walk / path | Dãy đỉnh liên tiếp được nối bởi cạnh |
| $C$ |  | Chu trình | Cycle | Đường đi khép kín |
| $P_n$ | P của n | Đường đi có n đỉnh | Path graph | Đồ thị dạng một đường thẳng gồm $n$ đỉnh |
| $\deg(v)=0$ | Bậc v bằng không | Đỉnh cô lập | Isolated vertex | Đỉnh không có cạnh kề |
| $\deg(v)=1$ | Bậc v bằng một | Đỉnh treo | Pendant vertex | Đỉnh chỉ có một cạnh liên thuộc |
| Euler | Ơ-le | Đường đi/chu trình qua mọi cạnh | Euler trail/circuit | Mỗi cạnh được đi qua đúng một lần |
| Hamilton |  | Đường đi/chu trình qua mọi đỉnh | Hamilton path/cycle | Mỗi đỉnh được thăm đúng một lần |
| $u\to v$ | U đi tới v | Cung có hướng | Directed edge / arc | Cạnh có chiều từ $u$ đến $v$ |
| $G\cup G'$ | G hợp G phẩy | Hợp đồ thị | Union of graphs | Hợp các tập đỉnh và cạnh |

## Cây

| Ký hiệu | Cách đọc | Tiếng Việt | English | Ý nghĩa |
|---|---|---|---|---|
| $T$ |  | Cây | Tree | Đồ thị vô hướng liên thông, không chu trình |
| $F$ |  | Rừng | Forest | Đồ thị không có chu trình; mỗi thành phần là cây |
| $n-1$ | n trừ một | Số cạnh của cây n đỉnh | Edges in a tree | Cây có $n$ đỉnh luôn có $n-1$ cạnh |
| $K_{1,n}$ | K của một và n | Cây hình sao | Star graph | Một tâm nối với $n$ đỉnh lá |
| $m$-phân |  | Cây m-phân | m-ary tree | Mỗi nút trong có không quá $m$ con |
| $i$ |  | Số nút trong | Number of internal vertices | Nút có ít nhất một con |
| $l$ |  | Số lá | Number of leaves | Nút không có con |
| $h$ |  | Chiều cao cây | Tree height | Mức lớn nhất của một nút |
| $T_{\min}$ | T nhỏ nhất | Cây khung nhỏ nhất | Minimum spanning tree | Cây khung có tổng trọng số nhỏ nhất |
| RPN | Ar-pi-en  | Ký pháp nghịch đảo Ba Lan / hậu tố | Reverse Polish notation | Toán tử theo sau các toán hạng; tính bằng stack |
