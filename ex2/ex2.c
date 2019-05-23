// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// It doesnt seem that the both the child and parent can access the textfile.


//https://stackoverflow.com/questions/3463426/in-c-how-should-i-read-a-text-file-and-print-all-strings
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    // Your code here 
    FILE *fp;
    printf("Opening the file text.txt to read");
    fp = fopen("text.txt", "w");    

    int text_fork = fork();

    if (text_fork < 0)
    {
        printf("fork failed\n");
        exit(1);

    } else if (text_fork == 0)
    {
        printf("\nchild process \n");
        char *child_str = "This is a child string!\n";
        fwrite(child_str, sizeof(char), strlen(child_str), fp);

    } else
    {
        //wait(NULL);
        printf("\nparent process \n");
        char *parent_str = "This is a parent string!\n";
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp);

    }
    
    fclose(fp); // close after child and parent have a chance to write/read
    return 0;
}

    // fp = fopen("text.txt", "r"); 
// if (fp == NULL)
// {
//     printf("Could not open text.txt");
//     return 1;
// } else {
//     while ((c = getc(fp)) != EOF)
//         //putchar(c);
//         printf("%c", c);
//         // printf("\n");
//     fclose(fp);
// }

// TO READ. Only reads parent processes.
/* int main(void)
{
    // Your code here 
    char c;
    FILE *fp;
    printf("Opening the file text.txt to read");

    fp = fopen("text.txt", "r");    

    // so it prints parent fork print statement, 
    // then child fork print statement, but prints the
    // textfile from parent fork?
    int text_fork = fork();

    if (text_fork < 0)
    {
        printf("fork failed\n");
        exit(1);

    } else if (text_fork == 0)
    {
        printf("\nchild fork \n");
        while ((c = getc(fp)) != EOF)
            printf("%c", c);

    } else
    {
        //wait(NULL);
        printf("\nparent fork \n");
        while ((c = getc(fp)) != EOF)
            printf("%c", c);

    }
    
    fclose(fp);    
    return 0;
} */
