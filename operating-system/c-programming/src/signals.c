#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int ctrl_c_count = 0;

void sigint_handler(int sig) {
    ctrl_c_count++;
    printf("\n[SIGNAL] Caught SIGINT (%d). Press Ctrl-C %d more time(s) to exit.\n",
           sig, 3 - ctrl_c_count);
    if (ctrl_c_count >= 3) {
        printf("[SIGNAL] Exiting.\n");
        signal(SIGINT, SIG_DFL);
    }
}

int main() {
    signal(SIGINT, sigint_handler);

    printf("===== Signal Demo =====\n");
    printf("Part 1: Press Ctrl-C 3 times to trigger the handler.\n");
    printf("        The handler counts and exits on the 3rd press.\n\n");

    // Busy wait so the program stays alive for Ctrl-C testing
    printf("Waiting for Ctrl-C... Press it now!\n");
    fflush(stdout);
    while (ctrl_c_count < 3)
        ;

    printf("\n===== Part 2: raise() =====\n");
    printf("Now calling raise(SIGTERM) — this sends SIGTERM to self.\n");
    printf("Default action for SIGTERM is termination.\n");
    printf("You will NOT see the next printf.\n\n");
    fflush(stdout);

    raise(SIGTERM);  // kills the process

    printf("You should never see this line.\n");
    return 0;
}
