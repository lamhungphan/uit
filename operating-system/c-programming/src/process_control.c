#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <process.h>   // _spawnlp, _cwait
#include <unistd.h>    // getpid
#else
#include <unistd.h>    // fork, exec, getpid
#include <sys/wait.h>  // waitpid, WIFEXITED, etc.
#endif

int main() {
    printf("Parent process PID = %d\n", getpid());

#ifdef _WIN32
    // Windows: _spawnlp() = spawn child process (fork+exec combined)
    // _P_NOWAIT = run concurrently (like fork)
    printf("[PARENT] Spawning 'dir' as child process...\n");
    intptr_t child = _spawnlp(_P_NOWAIT, "dir", "dir", NULL);

    if (child == -1) {
        perror("_spawnlp failed");
        return 1;
    }

    printf("[PARENT] Child process handle = %p\n", (void*)child);

    // Wait for child to finish (_cwait)
    int status;
    if (_cwait(&status, child, 0) == child) {
        printf("[PARENT] Child exited with code %d\n", status);
    }

#else
    // POSIX: fork() creates exact copy of current process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // CHILD process
        printf("[CHILD]  PID = %d, Parent PID = %d\n", getpid(), getppid());

        printf("[CHILD]  Now executing 'ls'...\n");
        execlp("/bin/ls", "ls", "-l", NULL);

        perror("execlp failed");
        exit(1);

    } else {
        // PARENT process
        printf("[PARENT] Created child PID = %d\n", pid);

        int status;
        pid_t terminated_pid = waitpid(pid, &status, 0);

        if (terminated_pid == pid) {
            if (WIFEXITED(status)) {
                printf("[PARENT] Child exited with code %d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("[PARENT] Child killed by signal %d\n", WTERMSIG(status));
            }
        }
    }
#endif

    printf("[PARENT] Done.\n");
    return 0;
}
