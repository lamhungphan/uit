# C Programming for Operating Systems

A collection of self-contained C examples for learning OS concepts through debugging.

## Files

| File | Topics Covered |
|---|---|
| `pointer.c` | Pointers, pointer arithmetic, pointer-to-pointer, void pointer |
| `dynamic_memory.c` | `malloc`, `calloc`, `realloc`, `free`, memory leaks |
| `structs.c` | Struct, typedef, nested structs, self-referential structs |
| `function_pointer.c` | Function pointers, callbacks, dispatch tables |
| `bitwise.c` | Bitwise ops (`&`, `|`, `<<`, `>>`, `~`), bit fields, masks |
| `volatile_example.c` | `volatile` keyword, hardware registers, polling |
| `file_io.c` | POSIX `open`/`read`/`write`/`close`/`lseek`/`stat` |
| `process_control.c` | `fork`, `exec`, `wait`, process hierarchy |
| `threading.c` | `pthread_create`, `pthread_join`, mutex synchronization |
| `signals.c` | `signal`, `kill`, `alarm`, `pause`, signal handlers |
| `memory_layout.c` | Stack, heap, `.text`, `.data`, `.bss`, `.rodata` |
| `inline_asm.c` | GCC inline assembly, `cpuid`, EFLAGS |
| `linked_list.c` | Linked list operations, scheduling queue simulation |

## How to Use

### Compile (Linux / WSL / MinGW)

```bash
gcc -g pointer.c -o pointer
gcc -g threading.c -lpthread -o threading
gcc -g inline_asm.c -o inline_asm
```

The `-g` flag adds debug symbols for stepping through code.

### Debug in VS Code

1. Open this folder in VS Code
2. Set breakpoints (click line numbers)
3. Press `F5` → select `C++ (GDB/LLDB)`
4. Step through with `F10` (step over) / `F11` (step into)

### Debug with GDB (command line)

```bash
gcc -g pointer.c -o pointer
gdb ./pointer
(gdb) break main
(gdb) run
(gdb) next
(gdb) print x
(gdb) continue
```

## Notes

- `process_control.c`, `file_io.c`, `threading.c`, `signals.c` use POSIX APIs and run on Linux/WSL/macOS natively.
- On Windows, use **WSL** (Windows Subsystem for Linux) or **MinGW** with the appropriate libraries.
