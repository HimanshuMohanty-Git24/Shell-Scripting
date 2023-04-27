#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t p1, p2, p3, p4;

    p1 = getpid();
    printf("p1 pid: %d, ppid: %d\n", (int)p1, (int)getppid());

    p2 = fork();
    if (p2 == 0)
    {
        printf("p2 pid: %d, ppid: %d\n", (int)getpid(), (int)getppid());

        p4 = fork();
        if (p4 == 0)
        {
            printf("p4 pid: %d, ppid: %d\n", (int)getpid(), (int)getppid());
        }
    }
    else
    {
        p3 = fork();
        if (p3 == 0)
        {
            printf("p3 pid: %d, ppid: %d\n", (int)getpid(), (int)getppid());
        }
    }

    return 0;
}
