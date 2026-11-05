### Bài tập 1

Gọi $E$ là biến cố khách hàng mua được đúng 2 máy của A và 1 máy của B.

Số cách chọn 3 máy bất kỳ trong 30 máy là

$$
C_{30}^3
= \frac{30!}{3!(30-3)!}
= \frac{30 \cdot 29 \cdot 28}{3 \cdot 2 \cdot 1}
= 4060.
$$

Số cách chọn 2 máy của A trong 20 máy và 1 máy của B trong 10 máy là

$$
C_{20}^2 C_{10}^1
= \frac{20!}{2!(20-2)!} \cdot \frac{10!}{1!(10-1)!}
= \frac{20 \cdot 19}{2 \cdot 1} \cdot \frac{10}{1}
= 190 \cdot 10
= 1900.
$$

Do các máy được chọn ngẫu nhiên như nhau, xác suất cần tìm là

$$
\begin{aligned}
P(E)
&= \frac{C_{20}^2 C_{10}^1}{C_{30}^3} \\
&= \frac{1900}{4060} \\
&= \frac{95}{203} \\
&\approx 0{,}468.
\end{aligned}
$$

Vậy xác suất khách hàng mua được 2 máy của A và 1 máy của B là

$$
\boxed{\frac{95}{203} \approx 46{,}8\%}
$$
