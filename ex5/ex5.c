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
    char buffer[MSGSIZE]; // write to buffer
    int fd[2]; // create pipe array
    pipe(fd); // create the pipe and pop fd


    int ex5 = fork(); // create fork
    if (ex5 < 0) {
        printf("fork failed\n");
        exit(1);

    } else if (ex5 == 0){

        // close(fd[1]);

        printf("child\n");
        write(fd[1], msg1, MSGSIZE);
        write(fd[1], msg2, MSGSIZE);
        write(fd[1], msg3, MSGSIZE);


    } else {

        wait(NULL);
        //close(fd[0]);

        printf("parent\n");
        // int read_it = read(fd[0], buffer, sizeof buffer);
        while(read(fd[0], buffer, sizeof buffer) != 0){
            printf("%s\n", buffer);
        }

        //write(STDOUT_FILENO, buffer, read_it);
    }
       
    return 0;
}
