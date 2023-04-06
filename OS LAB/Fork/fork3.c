#include <unistd.h>
#include <stdio.h>
int main()
{
    int pid;
    printf("KIIT\n");
    pid = fork();
    if (pid == 0)
    {
        printf("Child ID : %d\n", getpid());
        printf("Parent ID of Child: %d\n", getppid());
    }
    else
    {
        printf("Parent ID : %d\n", getpid());
        printf("Parent ID of Parent : %d\n", getppid());
    }
    return 0;
}