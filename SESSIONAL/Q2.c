#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int pid, pid1, pid2, pid3, pid4;
    pid = fork();
    if (pid == 0)
    {
        sleep(3);
        printf("pid process --> pid = %d and ppid = %d\n", getpid(), getppid());
    }
    else
    {
        pid1 = fork();
        if (pid1 == 0)
        {
            sleep(2);
            printf("pid1 process--> pid = %d and ppid = %d\n", getpid(), getppid());
        }
        pid2 = fork();
        if (pid2 == 0)
        {
            sleep(2);
            printf("pid2 --> pid = %d and ppid = %d\n", getpid(), getppid());
        }
        else
        {
            pid4 = fork();
            if (pid4 == 0)
            {
                printf("pid4 --> pid = %d and ppid = %d\n", getpid(), getppid());
            }
            else
            {
                printf("parent --> pid = %d\n", getpid());
            }
        }
        pid3 = fork();
        if (pid3 == 0)
        {
            sleep(2);
            printf("pid3 --> pid = %d and ppid = %d\n", getpid(), getppid());
        }
    }
    return 0;
}