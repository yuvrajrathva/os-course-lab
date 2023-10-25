#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

// Write a program to create a thread. The main process passes two numbers (a, b) and returns the sum to the parent process for printing.
int data[2] = {1, 2};
int sum = 0;

void *thread(void *arg)
{
    printf("Entering thread.\n");
    int *data = arg;
    sum = data[0] + data[1];
    pthread_exit(&sum);
    // return NULL;
}

int main(){
    // int data[2];
    // printf("Enter two numbers: ");
    // scanf("%d %d", &data[0], &data[1]);

    pthread_t tid;
    void *result;

    pthread_create(&tid, NULL, thread, (void *)data);
    pthread_join(tid, &result);
    printf("Entering into main thread \n");

    printf("Sum of %d and %d is %d\n", data[0], data[1], *((int *) result));
    return 0;
}