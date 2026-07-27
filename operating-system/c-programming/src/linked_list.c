#include <stdio.h>
#include <stdlib.h>

// OS use: process scheduling queues (ready queue, wait queue),
//         free list in memory management, file system directory entries

typedef struct Node {
    int pid;              // process ID
    int priority;         // priority for scheduling
    int burst_time;       // CPU burst time
    struct Node *next;    // pointer to next node
} Node;

// Insert at head (push)
Node* push(Node *head, int pid, int priority, int burst) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->pid = pid;
    new_node->priority = priority;
    new_node->burst_time = burst;
    new_node->next = head;
    return new_node;  // new head
}

// Append at tail (enqueue)
Node* enqueue(Node *head, int pid, int priority, int burst) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->pid = pid;
    new_node->priority = priority;
    new_node->burst_time = burst;
    new_node->next = NULL;

    if (head == NULL)
        return new_node;

    Node *cur = head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = new_node;
    return head;
}

// Remove first node (pop / dequeue)
Node* dequeue(Node *head) {
    if (head == NULL) return NULL;
    Node *temp = head;
    head = head->next;
    printf("Dequeued PID %d\n", temp->pid);
    free(temp);
    return head;
}

// Remove by PID (e.g., process terminated or blocked)
Node* remove_by_pid(Node *head, int pid) {
    Node *cur = head, *prev = NULL;

    while (cur != NULL && cur->pid != pid) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) return head;  // not found

    if (prev == NULL)
        head = cur->next;  // removing head
    else
        prev->next = cur->next;

    printf("Removed PID %d\n", cur->pid);
    free(cur);
    return head;
}

void print_queue(Node *head, const char *label) {
    printf("%s: ", label);
    while (head != NULL) {
        printf("[PID=%d,pri=%d,burst=%d] -> ",
               head->pid, head->priority, head->burst_time);
        head = head->next;
    }
    printf("NULL\n");
}

void free_all(Node *head) {
    while (head != NULL) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node *ready_queue = NULL;

    // Simulate processes arriving in ready queue
    ready_queue = enqueue(ready_queue, 1, 0, 10);
    ready_queue = enqueue(ready_queue, 2, 1,  5);
    ready_queue = push(   ready_queue, 3, 2,  8);  // high priority at front
    print_queue(ready_queue, "Ready Queue");

    // Scheduler picks first process (FCFS)
    ready_queue = dequeue(ready_queue);
    print_queue(ready_queue, "After dequeue");

    // Process 2 terminates
    ready_queue = remove_by_pid(ready_queue, 2);
    print_queue(ready_queue, "After termination");

    free_all(ready_queue);
    return 0;
}
