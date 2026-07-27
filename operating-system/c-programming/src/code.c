#include <stdio.h>
#include <stdlib.h>

enum State { NEW, READY, RUNNING, WAITING, TERMINATED };
const char *state_names[] = {"NEW", "READY", "RUNNING", "WAITING", "TERMINATED"};

typedef struct {
    int pid;
    enum State state;
} Process;

int main(int argc, char **argv)
{
    Process p[3] = {{1, NEW}, {2, NEW}, {3, NEW}};

    int i = 2;
    while (i < 5)
    {
        i++;
        if (i % 2 == 0)
        {
            printf("Hello");
            printf("Hi");
        }
        else
        {
            printf("Bye");
        }

        if (i == 3) { p[0].state = RUNNING; p[1].state = READY; }
        if (i == 4) { p[0].state = WAITING; p[1].state = RUNNING; p[2].state = READY; }
        if (i == 5) { p[0].state = READY; p[1].state = TERMINATED; p[2].state = RUNNING; }

        int counts[5] = {0};
        for (int j = 0; j < 3; j++) counts[p[j].state]++;
        printf(" | NEW=%d READY=%d RUN=%d WAIT=%d TERM=%d\n",
               counts[0], counts[1], counts[2], counts[3], counts[4]);
    }

    exit(0);
}
