// // int shmget(key_t key, size_t size, int shmflg);
// int shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
// // void *shmat(int shmid, const void *shmaddr, int shmflg);
// void *shared_memory;
// shared memory = shmat(shmid, NULL, 0);
// // here 3rd paramater is nulla dn third parameter is 0
// char buff[100];
// n = read(0, buff, 100);
// buff[n] = '\0';
// strcpy(shared_memory, buff);
// printf("Data written in shared memory: %s\n", (char *)shared_memory);
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{   
    int n;
    char buff[100];
    int shmid;
    void *shared_memory;
    shmid = shmget((key_t)2346, 1024, 0666 | IPC_CREAT);
    shared_memory = shmat(shmid, NULL, 0);
    n = read(0, buff, 100);
    buff[n] = '\0';
    strcpy(shared_memory, buff);
    printf("Data written in shared memory: %s\n", (char *)shared_memory);
    return 0;
}