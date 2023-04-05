// WAP to implement priority scheduling algorithm with different arrival time.
// Find average waiting time and average turn around time.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int priority;
};

void main()
{
    int n, i, j, k, temp, total = 0, pos, avg_wt, avg_tat;
    printf("Enter number of process: ");
    scanf("%d", &n);
    struct process p[n];
    for (i = 0; i < n; i++)
    {
        printf(" Enter process id: ");
        scanf("%d", &p[i].pid);
        printf(" Enter arrival time: ");
        scanf("%d", &p[i].at);
        printf(" Enter burst time: ");
        scanf("%d", &p[i].bt);
        printf(" Enter priority: ");
        scanf("%d", &p[i].priority);
    }
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (p[j].priority < p[pos].priority)
                pos = j;
        }
        temp = p[i].priority;
        p[i].priority = p[pos].priority;
        p[pos].priority = temp;
        temp = p[i].at;
        p[i].at = p[pos].at;
        p[pos].at = temp;
        temp = p[i].bt;
        p[i].bt = p[pos].bt;
        p[pos].bt = temp;
        temp = p[i].pid;
        p[i].pid = p[pos].pid;
        p[pos].pid = temp;
    }
    for (i = 0; i < n; i++)
    {
        total = total + p[i].bt;
        p[i].ct = total;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
    printf("Process ID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurn Around Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d \n", p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].ct, p[i].tat, p[i].wt);
    }

    getch();
}
