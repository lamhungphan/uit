#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

// Windows note: On Linux/macOS this uses POSIX syscalls.
// On Windows, equivalent APIs are CreateFile/ReadFile/WriteFile.

int main() {
    const char *filename = "test.txt";
    const char *message = "Hello, OS course!\n";

    // 1. open() - syscall to open/create file
    // O_CREAT | O_WRONLY | O_TRUNC: create if not exists, write-only, truncate
    // S_IRUSR | S_IWUSR: owner read+write permissions
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) { perror("open"); return 1; }

    // 2. write() - syscall to write bytes
    ssize_t bytes_written = write(fd, message, strlen(message));
    printf("Wrote %zd bytes to %s (fd=%d)\n", bytes_written, filename, fd);

    // 3. close() - syscall to release fd
    close(fd);

    // 4. open() again for reading
    fd = open(filename, O_RDONLY);
    if (fd == -1) { perror("open"); return 1; }

    // 5. lseek() - reposition file offset
    // Seek to beginning
    lseek(fd, 0, SEEK_SET);

    // 6. read() - syscall to read bytes
    char buffer[64] = {0};
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    printf("Read %zd bytes: %s", bytes_read, buffer);

    close(fd);

    // 7. stat() - get file metadata
    struct stat st;
    if (stat(filename, &st) == 0) {
        printf("File size: %lld bytes, permissions: %o\n",
               (long long)st.st_size, st.st_mode & 0777);
    }

    remove(filename);  // cleanup
    return 0;
}
