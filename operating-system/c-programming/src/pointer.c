#include <stdio.h>

int main() {
    // 1. Pointer basics: & (address-of) and * (dereference)
    int x = 42;
    int *p = &x;  // p stores the memory address of x

    printf("x = %d\n", x);
    printf("&x = %p\n", (void*)&x);
    printf("p  = %p\n", (void*)p);
    printf("*p = %d\n", *p);  // dereference p to get the value at that address

    // 2. Changing value through pointer
    *p = 100;  // modify x indirectly
    printf("After *p = 100, x = %d\n\n", x);

    // 3. Pointer arithmetic (on int array)
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // arr decays to pointer to first element

    printf("arr[0] = %d, *ptr = %d\n", arr[0], *ptr);
    printf("arr[1] = %d, *(ptr+1) = %d\n", arr[1], *(ptr + 1));
    printf("arr[2] = %d, *(ptr+2) = %d\n", arr[2], *(ptr + 2));

    // ptr++ moves to next int (advances by sizeof(int) bytes)
    ptr++;
    printf("After ptr++, *ptr = %d (now points to arr[1])\n\n", *ptr);

    // 4. Pointer to pointer
    int y = 7;
    int *q = &y;
    int **r = &q;  // r stores address of pointer q

    printf("y = %d, *q = %d, **r = %d\n\n", y, *q, **r);

    // 5. NULL pointer
    int *null_ptr = NULL;
    if (null_ptr == NULL) {
        printf("null_ptr is NULL and points to nothing\n");
    }

    // 6. void pointer (generic pointer, must cast before dereference)
    int a = 99;
    float b = 3.14f;
    void *vp;

    vp = &a;
    printf("void* to int: %d\n", *(int*)vp);

    vp = &b;
    printf("void* to float: %.2f\n", *(float*)vp);

    return 0;
}
