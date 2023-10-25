#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int fd[2];
    char buff[100];
    pipe(fd);
    pid_t pid;

    pid = fork();

    if(pid == 0){
        printf("Child Process \n");
        int count;
        count = read(fd[0], buff, 100);
        write(1, buff, count);
    }
    else{
        printf("Parent Process\n");
        write(fd[1], "hello\n", 6);
    }

    return 0;
}