#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>

int main()
{
    pid_t pid;
    char array[50];
    int error = 1;
    int input = 1;
    int fd[2], fd2[2];
    int buf;
    pipe(fd);
    pipe(fd2);

    switch(pid = fork()) {
        case -1: //checks if it made an error
                perror("Fork Error"); 
                exit(1);
        case 0:
                printf("CHILD PROCESS \n");
                printf("\tChild PID: %d\n", getpid());
                printf("\tChild Parent's PID: %d\n", getppid());
                printf("\tChild Return Value from fork(): %d\n", pid);
                close(fd2[0]);
                close(fd[1]);
                while(input != 0)
                {
                    read(fd[0], &buf, sizeof(buf));
                    printf("CHILD: read \"%d\"\n", buf);                    //the child will read from the pipe
                    if(buf == 0)                                            //if the user input 0. The child will tell the parent to stop.
                    {
                        printf("CHILD: Input is 0. Stop the process.\n");
                        break;
                    }
                    else                                                    //if the user did not input 0. The child will tell the parent to send more values.
                        printf("CHILD: Send more values.\n");
                    write(fd2[1], &buf, sizeof(buf));
                }
                close(fd[1]);
                close(fd2[0]);
                exit(0);
                break;

        default:
                sleep(1);
                printf("PARENT PROCESS\n");
                printf("\tParent PID: %d\n", getpid());
                printf("\tParent Parent's PID: %d\n", getppid());
                printf("\tParent Return Value from fork(): %d\n", pid);
                close(fd[0]);
                close(fd2[1]);
                while(input != 0)
                {
                    while (error != 0 && input > 0)
                    {
                        printf("Input an integer greater than or equal to 0: ");
                        scanf(" %s", array);
                        for(int x = 0; x < strlen(array); x++)
                        {
                            if(isdigit(array[x]) == 0)
                            {
                                printf("INVALID\n");
                                error = 1;
                                break;
                            }
                            else
                                error = 0;
                        }
                        if(error == 0)
                        {
                            input = atoi(array);
                            printf("VALID\n");
                            write(fd[1], &input, sizeof(input));                    //writing to the child
                            read(fd2[0], &input, sizeof(input));                    //reading from the child
                            printf("PARENT: read \"%d\"\n", input);
                            if(input != 0)
                            {
                                error = 1;
                            }
                            else
                            {
                                printf("Value is 0. Process Ended.\n");
                                input = 0;
                                exit(0);
                            }
                        }
                    }
                }
                close(fd[0]);
                close(fd2[1]);
                wait(NULL);
                break;
    }
    return 0;
}
