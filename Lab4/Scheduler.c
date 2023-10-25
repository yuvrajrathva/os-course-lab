// This program is in ubuntu Write a C program that creates a pool of processes (P0, P1, P2, …., Pn) where n must be user input. After the process pool is initialized, your program should proceed to schedule these processes. 

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Create n number of processes by taking n from user using fork()
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int ids[n];
    pid_t pid[n];
    double arrival_time[n];
    int burst_time[n];
    int run_time[n];
    
    // store parent getpid() 
    pid_t parent = getpid();
    // store the run time of parent process at runtime[0]
    run_time[0] = 0;
    pid[0] = parent;

    // Create n number of processes using fork()    
    int i;
    clock_t start_time, end_time;

    for(i = 1; i < n; i++){
        start_time = clock();
        pid[i] = fork();
        
        // Error handling for fork()
        if(pid[i] < 0) {
            perror("fork");
            return 1;
        }

        if(pid[i] == 0){
            // Child process
            // store the arrival time of child process at arrival_time[i]
            end_time = clock();
            printf("%ld - %ld\n", start_time, end_time);
            // arrival_time[i] = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 10000000;
            exit(0);
        }
    }
    // end_time = clock();
    // printf("Time taken to create %d processes is %f\n", n, (double)(end_time - start_time) / CLOCKS_PER_SEC);

    // Wait for all the processes to finish
    for(i = 0; i < n; i++){
        wait(NULL);
    }

    // for(int i=0;i<n;i++){
    //     printf("Arrival time of process %d is %f: ", i, arrival_time[i]);
    // }
    // take boolean iput from user and store in rr
    // int rr;
    // printf("Enter 1 for Round Robin and 0 for Priority Scheduling: ");

    // // take input from user and store in rr
    // scanf("%d", &rr);

    // if(rr > 0){
    //     // Round Robin
    //     int time_quantum;
    //     printf("Enter the time quantum: ");
    //     scanf("%d", &time_quantum);

    //     // store the process IDs(ids[]) in the order of their arrival time[]
    //     // for(i = 0; i < n; i++){
    //     //     printf("Enter the arrival time of process %d: ", i);
    //     //     scanf("%d", &arrival_time[i]);
    //     // }

    //     // store the process IDs(ids[]) in the order of their burst time[]
    //     // for(i = 0; i < n; i++){
    //     //     printf("Enter the burst time of process %d: ", i);
    //     //     scanf("%d", &burst_time[i]);
    //     // }


    // } else {
    //     // Priority Scheduling
    //     // store the process IDs(ids[]) in the order of their priority[]
    //     int priority[n];
    //     for(i = 0; i < n; i++){
    //         printf("Enter the priority of process %d: ", i);
    //         scanf("%d", &priority[i]);
    //     }
    // }

    return 0;
}












