#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){
    // FILE *rd;
    // char buffer[50];
    // sprintf(buffer, "hello world");
    // rd = popen("wc -w", "w");
    // fwrite(buffer, sizeof(char), strlen(buffer), rd);
    // pclose(rd);

    FILE *rd;
    char buffer[50];
    rd = popen("ls", "r");
    fread(buffer, 1, 40, rd);
    printf("%s\n", buffer);
    pclose(rd);
}