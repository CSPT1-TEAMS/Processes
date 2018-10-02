// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 1;
    printf("x value is %d\n",x );
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr,"fork failed\n");
        exit(1);
    } else if(rc == 0) {
        printf("child process pid: %d\n", (int) getpid());
        x = 100;
        printf("x value is now %d\n",x);
    }
    else{
        printf("hello parent here %d of child %d\n", (int) getpid(),rc );
        x = 1;
        printf("modified from parent %d\n", x);
    }


    return 0;
}
