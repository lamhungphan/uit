#include <stdio.h>

// OS use: flags, permissions, hardware registers, bitmaps

// Permission flags (like Unix chmod)
#define READ    (1 << 2)  // 100 = 4
#define WRITE   (1 << 1)  // 010 = 2
#define EXECUTE (1 << 0)  // 001 = 1

// Bit fields for compact register representation
typedef struct {
    unsigned int present : 1;   // 1 bit
    unsigned int writable : 1;  // 1 bit
    unsigned int user : 1;      // 1 bit
    unsigned int reserved : 5;  // 5 bits
    unsigned int addr : 24;     // 24 bits
} PageTableEntry;  // total: 32 bits

int main() {
    // 1. Setting / clearing / toggling bits
    unsigned char flags = 0;

    flags |= READ;              // set READ bit: 000 -> 100
    flags |= WRITE;             // set WRITE bit: 100 -> 110
    printf("flags after READ|WRITE: 0x%02x\n", flags);

    flags &= ~WRITE;            // clear WRITE bit: 110 -> 100
    printf("flags after clearing WRITE: 0x%02x\n", flags);

    flags ^= EXECUTE;           // toggle EXECUTE: 100 -> 101
    printf("flags after toggling EXECUTE: 0x%02x\n", flags);

    // 2. Checking bits
    if (flags & READ)
        printf("READ permission granted\n");

    // 3. Masking: extract specific bits
    unsigned int reg = 0xABCD1234;
    unsigned int low_byte = reg & 0xFF;           // 0x34
    unsigned int high_word = (reg >> 16) & 0xFFFF; // 0xABCD
    printf("low_byte = 0x%02x, high_word = 0x%04x\n", low_byte, high_word);

    // 4. Bit field struct (page table entry)
    PageTableEntry pte;
    pte.present  = 1;
    pte.writable = 1;
    pte.user     = 0;
    pte.reserved = 0;
    pte.addr     = 0x123456;  // physical frame address

    printf("PTE: present=%d, writable=%d, addr=0x%06x\n",
           pte.present, pte.writable, pte.addr);

    return 0;
}
