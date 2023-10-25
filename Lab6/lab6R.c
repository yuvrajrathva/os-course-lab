#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{   
    // int i;
    // char buff[100], input[100];
    int shmid;
    void *shared_memory;
    shmid = shmget((key_t)2346, 1024, 0666);
    shared_memory = shmat(shmid, NULL, 0);
    // n = read(0, buff, 100);
    // buff[n] = '\0';
    // strcpy(shared_memory, buff);
    printf("Data written in shared memory: %s\n", (char *)shared_memory);
    return 0;
}