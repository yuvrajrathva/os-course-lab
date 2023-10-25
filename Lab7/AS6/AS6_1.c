#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

void* generate_file(void* arg) {
    const char* filename = "data.txt";
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("Failed to open file for writing");
        pthread_exit(NULL);
    }
    const char* initial_content = "This is the initial content.\n";
    write(fd, initial_content, strlen(initial_content));
    close(fd);
    pthread_exit(NULL);
}

void* write_to_file(void* arg) {
    const char* filename = "data.txt";
    int fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1) {
        perror("Failed to open file");
        pthread_exit(NULL);
    }

    const char* content_to_write = "This content is written by T2.\n";
    write(fd, content_to_write, strlen(content_to_write));

    close(fd);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    if (pthread_create(&thread1, NULL, generate_file, NULL) != 0) {
        perror("Thread 1 creation failed");
        return 1;
    }
    if (pthread_create(&thread2, NULL, write_to_file, NULL) != 0) {
        perror("Thread 2 creation failed");
        return 1;
    }
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("File 'data.txt' has been generated and modified by the threads.\n");

    return 0;
}
