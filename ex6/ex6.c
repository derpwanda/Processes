/*
Write a program that will find the average time it takes for your computer
to make a system call an empty write to stdout. Your program should use the 
`clock_gettime` procedure to time how long a single system call takes. It'll 
do this for one million iterations, and then find the average of all of those 
iterations in nanoseconds.
For some helpful documentation and examples of using time-related system calls,
visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html
While the linked site does say that `clock_gettime()` does not work on OSX, this 
turns out to only be the case for OSX versions < 10.12. Anything later than that 
and `clock_gettime()` should work just fine. 
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    // Your code here
    struct timespec start, stop;
    // time_t tv_sec; //seconds
    // long tv_nsec; //nanoseconds
    long timediff;

    int i; 
    clock_gettime(CLOCK_REALTIME, &start); //red squiggly why?

    for (i = 0; i < number_iter; i++){
        write(fileno(stdout), NULL, 0); //empty write to stdout? fileno?
        clock_gettime(CLOCK_REALTIME, &stop);
    }

    timediff = BILLION * (stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec);
    
    printf("%ld\n", timediff); //%ld suggested by gcc
    return 0;
}
