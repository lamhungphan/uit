#include <stdio.h>
#include <string.h>

// 1. Basic struct definition
struct Process {
    int pid;
    char name[32];
    int priority;
};

// 2. typedef - create type alias
typedef struct {
    int x;
    int y;
} Point;

// 3. Nested structs (common in OS: PCB contains registers, etc.)
typedef struct {
    int eax, ebx, ecx, edx;  // CPU registers
    int pc;                   // program counter
    int sp;                   // stack pointer
} Registers;

typedef struct {
    int pid;
    char state[16];      // RUNNING, READY, BLOCKED
    Registers regs;      // nested struct - saved context
    struct Process *next; // pointer to next PCB (linked list)
} PCB;

// 4. Self-referential struct (linked list node)
typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main() {
    // Declare and initialize
    struct Process p1 = {1, "init", 0};
    printf("PID: %d, Name: %s, Priority: %d\n", p1.pid, p1.name, p1.priority);

    // Member access via pointer (->)
    struct Process *pp = &p1;
    pp->priority = 10;  // equivalent to (*pp).priority = 10
    printf("After -> priority = %d\n", p1.priority);

    // Point struct
    Point pt = {10, 20};
    printf("Point: (%d, %d)\n", pt.x, pt.y);

    // PCB with nested registers (simulating context switch)
    PCB pcb;
    pcb.pid = 42;
    strcpy(pcb.state, "RUNNING");
    pcb.regs.eax = 0;
    pcb.regs.ebx = 100;
    pcb.regs.pc = 0x4000;
    pcb.regs.sp = 0x7fff;

    printf("PCB[%d] %s: PC=0x%x, SP=0x%x\n",
           pcb.pid, pcb.state, pcb.regs.pc, pcb.regs.sp);

    // sizeof struct (may include padding!)
    printf("sizeof(PCB) = %zu bytes\n", sizeof(PCB));

    return 0;
}
