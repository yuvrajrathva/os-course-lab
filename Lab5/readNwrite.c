#include<stdio.h>
#include<unistd.h>

int main(){
    // write only
    // int count;
    // count = write(1, "hello\n", 6);
    // printf("Total bytes written: %d\n", count);

    // read and write
    int nread;
    char buff[20];
    nread = read(0, buff, 10);
    write(1, buff, nread);
}
