// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    // Your code here
    //fork a child process
    char buffer[MSGSIZE];
    int fd[2];

    //pipe(pid); //pipe the fork

    // if (pipe(fd) < 0)
    // {
    //     printf("fork failed!");
    //     exit(1);

    int ex5 = fork();
    if (ex5 < 0) {
        printf("fork failed\n");
        exit(1);

    } else if (ex5 == 0){

        printf("child\n");
        int written = write(fd[1], msg1, MSGSIZE);
        int written = write(fd[1], msg2, MSGSIZE);
        int written = write(fd[1], msg3, MSGSIZE);

    } else {

        printf("parent\n");
        int read_it = read(0, buffer, sizeof buffer);

        write(STDOUT_FILENO, buffer, read_it);
    }
       
    return 0;
}
