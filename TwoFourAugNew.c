#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    pid_t pid1, pid2;

    pid1 = fork();

    if(pid1 == 0){
        printf("Child Process 1\n");
        printf("Child Process 1 ID: %d\n", getpid());
        printf("Child Process 1 Parent ID: %d\n", getppid());
    }
    else{
        wait(NULL);
        printf("Parent Process\n");
        printf("Parent Process ID: %d\n", getpid());
        printf("Parent Process Parent ID: %d\n", getppid());
    }

    return 0;
}