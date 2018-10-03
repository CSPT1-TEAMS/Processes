// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE * fp;
    fp = fopen("text.txt", "r+");
    int rc = fork();

    if(rc < 0){
        printf("Fork failed");
        exit(1);
    } else if(rc == 0) {
        printf("Child fork\n");
        // char *str = "Child.txt\n";
        // fwrite(str, sizeof(char), strlen(str), fp);
        fclose(fp);
    } else {
        printf("Parent fork\n");
        char *p_str = "Parent.txt\n";
        fwrite(p_str, sizeof(char), strlen(p_str), fp);
    }
    fclose(fp);
    return 0;
}
