#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Compile on Linux: gcc threading.c -lpthread -o threading

// Shared resource (race condition without synchronization)
int shared_counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// 1. Thread function - runs in a separate thread
void* worker(void *arg) {
    int id = *(int*)arg;
    printf("[Thread %d] Started\n", id);

    for (int i = 0; i < 3; i++) {
        // Lock mutex before accessing shared resource
        pthread_mutex_lock(&mutex);
        shared_counter++;
        printf("[Thread %d] counter = %d\n", id, shared_counter);
        pthread_mutex_unlock(&mutex);

        usleep(100000);  // simulate work (100ms)
    }

    printf("[Thread %d] Finished\n", id);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    // 2. pthread_create() - spawn threads
    pthread_create(&t1, NULL, worker, &id1);
    pthread_create(&t2, NULL, worker, &id2);

    printf("[Main] Both threads running\n");

    // 3. pthread_join() - wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("[Main] Final counter = %d\n", shared_counter);
    pthread_mutex_destroy(&mutex);

    return 0;
}
