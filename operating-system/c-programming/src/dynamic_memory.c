#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // 1. malloc - allocates uninitialized memory
    int *arr = (int*)malloc(5 * sizeof(int));
    // arr now points to 5 * 4 = 20 bytes on the heap
    // Contents are UNINITIALIZED (garbage values)

    for (int i = 0; i < 5; i++)
        arr[i] = i * 10;

    printf("malloc array: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // 2. calloc - allocates ZERO-INITIALIZED memory
    int *zero_arr = (int*)calloc(5, sizeof(int));
    // All bytes are set to 0

    printf("calloc array: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", zero_arr[i]);  // all 0
    printf("\n");

    // 3. realloc - resize existing allocation
    arr = (int*)realloc(arr, 10 * sizeof(int));  // grow to 10 elements
    // Old data preserved in first 5; new elements uninitialized
    for (int i = 5; i < 10; i++)
        arr[i] = i * 10;

    printf("realloc array: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // 4. free - return memory to OS
    free(arr);       // must free exactly what malloc/calloc/realloc returned
    free(zero_arr);  // double-free or use-after-free = undefined behavior

    // 5. Common pitfalls
    // Memory leak: allocated memory with no pointer to free it
    // Dangling pointer: using a pointer after free
    // Buffer overflow: writing past allocated bounds

    return 0;
}
