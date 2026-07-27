#include <stdio.h>
#include <stdlib.h>

int x;           // .bss (uninitialized global)
int y = 15;      // .data (initialized global)

void print_addr(const char *label, void *addr) {
    printf("%-25s %p\n", label, addr);
}

int main(int argc, char *argv[]) {
    int *values;     // stack (pointer variable)
    int i;           // stack
    int local = 42;  // stack

    values = (int *)malloc(sizeof(int) * 5);  // heap

    for (i = 0; i < 5; i++)
        values[i] = i;

    printf("=== Memory Layout ===\n\n");
    print_addr("code (main)", main);
    print_addr("string literal", "hello");
    print_addr("global y (.data)", &y);
    print_addr("global x (.bss)", &x);
    print_addr("heap (values)", values);
    print_addr("local (stack)", &local);
    print_addr("argc (stack)", &argc);
    print_addr("argv (stack)", &argv);
    printf("\nStack: high addresses, grows down\n");
    printf("Heap:  lower addresses, grows up\n");
    printf("Code:  lowest addresses\n");

    free(values);
    return 0;
}
