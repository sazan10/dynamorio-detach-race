#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_func(void *arg) {
    printf("Thread started\n");
    sleep(2);  // Simulate some work in the thread
    printf("Thread finished\n");
    return NULL;
}

int main() {
    pthread_t thread;
    for (int i = 0; i < 5; i++) {
        pthread_create(&thread, NULL, thread_func, NULL);
        printf("Created thread %d\n", i + 1);
        usleep(100000);  // Create a small delay between thread creation
    }

    printf("All threads created, now sleeping...\n");
    sleep(3);  // Simulate some work in the main thread
    printf("Main thread exiting\n");
    return 0;
}
