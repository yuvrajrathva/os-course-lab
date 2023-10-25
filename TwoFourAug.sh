# Write a C program to create 3 processes, PO, P1, P2, such that PO becomes grandparent, P1 becomes parent, and P2 becomes a child. Prove the relationship by printing the output. You should upload code and screenshot of the output.

#!/bin/bash

echo "Enter the number of processes to be created: "
read n

for((i=0;i<n;i++))

do
    echo "Enter the process name: "
    read pname
    echo "Enter the process id: "
    read pid
    echo "Enter the parent process id: "
    read ppid
    echo "Enter the process memory: "
    read pmemory
    echo "Enter the process time: "
    read ptime

    echo "$pname $pid $ppid $pmemory $ptime" >> process.txt
done

echo "Enter the process name to be searched: "
read pname

echo "Enter the process id to be searched: "
read pid

echo "Enter the parent process id to be searched: "
read ppid

echo "Enter the process memory to be searched: "
read pmemory

echo "Enter the process time to be searched: "
read ptime

echo "The process details are: "
echo "Process Name: $pname"
echo "Process ID: $pid"
echo "Parent Process ID: $ppid"
echo "Process Memory: $pmemory"
echo "Process Time: $ptime"

