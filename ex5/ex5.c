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
    char pipeBuffer[MSGSIZE];
    int pipePointers[2];

    if(pipe(pipePointers) < 0)
    {
        printf("Nothing to pipe through.");
        exit(1);
    }

    int rc = fork();

    if(rc < 0){
        printf("Fork failed");
        exit(2);

    } else if(rc == 0){
        printf("CHILD HERE\n");
        write(pipePointers[1], msg1, MSGSIZE);
        write(pipePointers[1], msg2, MSGSIZE);
        write(pipePointers[1], msg3, MSGSIZE);


    } else {
        wait(NULL);
        close(pipePointers[1]);
        printf("PARENT HERE\n");

        while(read(pipePointers[0], pipeBuffer, MSGSIZE) > 0)
        {
            printf("Reading Pipe in parent %s\n", pipeBuffer);
        }

    }
    return 0;

}
