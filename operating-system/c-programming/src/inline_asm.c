#include <stdio.h>

// GCC inline assembly syntax: __asm__ volatile("code" : outputs : inputs : clobbers)
// OS use: context switching, interrupts, privileged instructions, CPUID, etc.

int main() {
    int result = 0;

    // 1. Basic inline asm: add two numbers
    int a = 10, b = 20;
    __asm__ volatile (
        "movl %1, %%eax;"   // %1 = input b -> eax
        "addl %2, %%eax;"   // %2 = input a -> add to eax
        "movl %%eax, %0;"   // eax -> %0 = output result
        : "=r" (result)     // output: result (register)
        : "r" (b), "r" (a)  // inputs: b, a in registers
        : "%eax"            // clobbered: eax
    );
    printf("asm add: %d + %d = %d\n", a, b, result);

    // 2. CPUID instruction (x86) - get processor info
    unsigned int eax, ebx, ecx, edx;
    eax = 0;  // leaf 0: vendor ID

    __asm__ volatile (
        "cpuid"
        : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx)
        : "a" (eax)
    );

    // Vendor ID string is in ebx, edx, ecx (12 bytes)
    char vendor[13];
    ((unsigned*)vendor)[0] = ebx;
    ((unsigned*)vendor)[1] = edx;
    ((unsigned*)vendor)[2] = ecx;
    vendor[12] = '\0';

    printf("CPUID vendor: %s\n", vendor);

    // 3. Read EFLAGS register (x86)
    unsigned long long eflags;
    __asm__ volatile (
        "pushfq;"      // push RFLAGS onto stack
        "popq %0;"     // pop into output operand
        : "=r" (eflags)
        :
        : "memory"
    );

    printf("EFLAGS: 0x%016llx\n", eflags);

    // 4. OS concept: switching to kernel mode (conceptual)
    // On x86: int 0x80 or syscall instruction
    // __asm__ volatile ("int $0x80" : : "a" (syscall_num), "b" (arg1));

    return 0;
}
