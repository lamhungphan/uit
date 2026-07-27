#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// volatile tells the compiler: "this value can change at any time"
// Prevents the compiler from optimizing away reads/writes.
// Used in OS for: memory-mapped I/O, shared variables in ISRs, signals.

// Simulate a hardware register at a fixed address
// (normally would be #define HW_REG (*(volatile int*)0xFFFF0000))
volatile int hardware_flag = 0;

// Simulate a variable modified by an interrupt handler
volatile int ticks = 0;

int main() {
    // Without volatile, compiler might cache 'ticks' in a register
    // and never re-read from memory, so the loop never sees the update.
    // volatile forces a memory read every time.

    printf("Simulating polling a hardware register...\n");

    // Simulate hardware setting the flag asynchronously
    srand((unsigned)time(NULL));
    hardware_flag = rand() % 100;

    // Poll until flag reaches threshold (normally hardware changes it)
    int timeout = 0;
    while (hardware_flag < 50 && timeout < 1000000) {
        // volatile ensures hardware_flag is re-read from memory each iteration
        timeout++;
    }

    printf("Flag reached %d after %d iterations\n", hardware_flag, timeout);

    // Memory-mapped I/O example (conceptual):
    // volatile unsigned char *uart_status = (volatile unsigned char*)0x3F8;
    // while (!(*uart_status & 0x20));  // wait for TX buffer empty
    // *uart_data = 'A';                // write character

    return 0;
}
