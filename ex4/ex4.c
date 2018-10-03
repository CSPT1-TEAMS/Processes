// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{

    int rc = fork();

    if (rc < 0)
    {
        printf("Fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("CHILD HERE.");
        char *arr[] = {"ls", "-1", NULL};
        execvp("ls", arr);
        printf("SECRET HIDDEN CODE. YOU CANNOT SEE THIS.");
    }
    else
    {
        wait(NULL);
        printf("PARENT HERE!");
    }
    return 0;
}
