#include <stdio.h>

// OS use case: syscall dispatch table, scheduler callbacks

// 1. Declare a function pointer type
typedef int (*Comparator)(int, int);

// 2. Some functions with same signature
int ascending(int a, int b)  { return a - b; }
int descending(int a, int b) { return b - a; }

// 3. Function that takes a callback (strategy pattern)
void bubble_sort(int arr[], int n, Comparator cmp) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (cmp(arr[j], arr[j + 1]) > 0) {  // use comparator
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 4. Array of function pointers (syscall dispatch table)
void sys_read()  { printf("syscall: read\n"); }
void sys_write() { printf("syscall: write\n"); }
void sys_open()  { printf("syscall: open\n"); }
void sys_close() { printf("syscall: close\n"); }

typedef void (*Syscall)(void);  // function pointer type

int main() {
    int arr[] = {5, 3, 8, 1, 9, 2};
    int n = 6;

    // Pass function pointer to sort ascending
    bubble_sort(arr, n, ascending);
    print_array(arr, n);

    // Reuse same sort function, different behavior
    bubble_sort(arr, n, descending);
    print_array(arr, n);

    // Syscall dispatch table
    Syscall syscall_table[4] = {sys_read, sys_write, sys_open, sys_close};

    int syscall_num = 1;
    printf("\nInvoking syscall #%d: ", syscall_num);
    syscall_table[syscall_num]();  // calls sys_write

    return 0;
}
