// Create two separate C files. One is the sender program (Sender.c), and the second one is the receiver program (Receiver.c). Communication between them should happen using the shared memory approach. The sender process should send a string containing multiple words, and the receiver will read the content. Once reading is done, the receiver program should do the following activities:

// (1) Find the largest word among the entire string.
// (2) Sort the string based on the word length (ascending or descending).

// this is the receiver program c file

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{   
    char buff[100];
    int shmid;
    void *shared_memory;
    shmid = shmget((key_t)2346, 1024, 0666);
    shared_memory = shmat(shmid, NULL, 0);
    printf("Data written in shared memory: %s\n", (char *)shared_memory);

    char *token = strtok((char *)shared_memory, " ");
    char *largestWord = token;
    while (token != NULL)
    {
        if (strlen(token) > strlen(largestWord))
        {
            largestWord = token;
        }
        token = strtok(NULL, " ");
    }
    printf("Largest word: %s\n", largestWord);


    int n;
    token = strtok((char *)shared_memory, " ");
    while (token != NULL)
    {
        n++;
        token = strtok(NULL, " ");
    }
    printf("Number of words: %d\n", n);
    char *words[n];
    int i = 0;
    token = strtok((char *)shared_memory, " ");
    while (token != NULL)
    {
        words[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    int j;
    char *temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strlen(words[i]) > strlen(words[j]))
            {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
    printf("Sorted words: ");
    for (i = 0; i < n; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");
    return 0;
}