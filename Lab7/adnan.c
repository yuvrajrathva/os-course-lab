#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to pass data to the thread
struct ThreadData {
    int num1;
    int num2;
    int result;
};

// Function that calculates the sum of two numbers
void *calculate_sum(void *data) {
    struct ThreadData *threadData = (struct ThreadData *)data;
    threadData->result = threadData->num1 + threadData->num2;
    return NULL;
}

int main() {
    // Get two numbers from the user or any other source
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Create a thread and pass the data to it
    pthread_t tid;
    struct ThreadData data;
    data.num1 = num1;
    data.num2 = num2;

    if (pthread_create(&tid, NULL, calculate_sum, &data) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Wait for the thread to finish
    if (pthread_join(tid, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    // Get the result from the thread
    int result = data.result;

    // Print the result
    printf("The sum of %d and %d is %d\n", num1, num2, result);

    return 0;
}