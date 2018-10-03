// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *fp;
    fp = fopen("text.txt","w+");
    int rc = fork();
    if (rc == 0) {
        printf("In Child, pid %d", (int) getpid());
        fprintf(fp, "hello world!");
        // fp.write("hello")

    }
    fprintf(fp, "hello Ma'am!");

    fclose(fp);
    return 0;
}
