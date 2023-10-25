#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int fd[2];
    pipe(fd);
    pid_t pid1, pid2;

    pid1 = fork();

    if(pid1 == 0){
        printf("This is Producer Process \n");
        int n;
        printf("Enter the number of integers: ");
        scanf("%d", &n);

        int arr[n];
        for(int i=0; i<n; i++){
            arr[i] = i+1; 
        }

        write(fd[1], arr, sizeof(arr));
    }
    else{
        pid2 = fork();
        if(pid2 == 0){
            printf("Consumer Process\n");
            int arr[100];
            int count;
            count = read(fd[0], arr, sizeof(arr));
            int sum = 0;
            for(int i=0; i<count/sizeof(int); i++){
                if(arr[i]%2 != 0){
                    sum += arr[i];
                }
            }
            printf("Answer is: %d\n", sum);
        }
        else{
            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}