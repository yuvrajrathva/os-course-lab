// Create two separate C files. One is the sender program (Sender.c), and the second one is the receiver program (Receiver.c). Communication between them should happen using the shared memory approach. The sender process should send a string containing multiple words, and the receiver will read the content. Once reading is done, the receiver program should do the following activities:

// (1) Find the largest word among the entire string.
// (2) Sort the string based on the word length (ascending or descending).

// this is sender program c file

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