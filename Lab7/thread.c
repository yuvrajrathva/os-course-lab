#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *thread(void *arg)
{
    printf("Entering thread.\n");
    for(int i=0;i<5;i++)
    {
        printf("Thread=%d\n", i + 1);
        // sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, thread, NULL);
    // pthread_join(tid, NULL);
    printf("Entering into main thread \n");
    for(int i=0;i<5;i++)
    {
        printf("Main=%d\n", i + 1);
        // sleep(1);
    }
    return 0;
}
