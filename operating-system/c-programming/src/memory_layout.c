#include <stdio.h>
#include <stdlib.h>

// Memory layout of a process:
//
// High addresses
//   +------------------+
//   |      Stack       |  local variables, function frames (grows down)
//   |        |         |
//   |        v         |
//   + - - - - - - - - -+
//   |        ^         |
//   |        |         |
//   |      Heap        |  malloc/calloc/realloc (grows up)
//   +------------------+
//   |    .bss          |  uninitialized global/static data (zero-filled)
//   +------------------+
//   |    .data         |  initialized global/static data
//   +------------------+
//   |    .rodata       |  read-only data (string literals)
//   +------------------+
//   |    .text         |  program code (instructions)
//   +------------------+
// Low addresses

// Global in .data (initialized)
int global_init = 42;
// Global in .bss (uninitialized -> zero)
int global_uninit;

// Static in .data
static int static_init = 100;
// Static in .bss
static int static_uninit;

// String literal in .rodata
const char *str = "Hello, OS!";

void print_addr(const char *label, void *addr) {
    printf("%-20s %p\n", label, addr);
}

void func() {
    int local = 5;  // stack
    print_addr("local (stack)", &local);
}

int main() {
    int local_main = 10;          // stack
    int *heap = malloc(4);        // heap
    int *heap2 = calloc(1, 4);    // heap
    void *func_ptr = func;        // .text

    printf("=== Process Memory Layout ===\n\n");

    print_addr("code (.text)", func_ptr);
    print_addr("string (.rodata)", str);
    print_addr("global_init (.data)", &global_init);
    print_addr("static_init (.data)", &static_init);
    print_addr("global_uninit (.bss)", &global_uninit);
    print_addr("static_uninit (.bss)", &static_uninit);
    print_addr("heap (malloc)", heap);
    print_addr("heap (calloc)", heap2);
    print_addr("local_main (stack)", &local_main);

    func();

    printf("\nNote: Stack grows downward (lower addresses on each call)\n");
    printf("      Heap grows upward (higher addresses with each malloc)\n");

    free(heap);
    free(heap2);
    return 0;
}
