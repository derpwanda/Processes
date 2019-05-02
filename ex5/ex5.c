// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 


//NOTES: https://www.geeksforgeeks.org/c-program-demonstrate-fork-and-pipe/
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
    char buffer[MSGSIZE]; // write to buffer
    int fd[2]; // create pipe array
    pipe(fd); // create the pipe and pop fd


    int ex5 = fork(); // create fork
    if (ex5 < 0) {
        printf("fork failed\n");
        exit(1);

    } else if (ex5 == 0){

        printf("child\n");
        write(fd[1], msg1, MSGSIZE);
        write(fd[1], msg2, MSGSIZE);
        write(fd[1], msg3, MSGSIZE);


    } else {
        close(fd[1]);
        wait(NULL);
        printf("parent\n");
        while(read(fd[0], buffer, sizeof buffer) != 0){
            printf("%s\n", buffer);
        }

    }
       
    return 0;
}
