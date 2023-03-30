#include <stdio.h>
int main()
{
    int pid[15];
    int arr[15];
    int bt[15];
    int ct[15];
    int tat[15];
    int wt[15];
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter process id of all the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pid[i]);
    }
    printf("Enter arrival time of all the processes: ");

    for (int i = 0; i < n; i++)
    {

        scanf("%d", &arr[i]);
    }
    printf("Enter burst time of all the processes: ");
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &bt[i]);
    }
    ct[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
    }
    float totalwt = 0.0;
    float totaltat = 0.0;
    for (int i = 0; i < n; i++)
    {
        totalwt += wt[i];
        totaltat += tat[i];
    }
    float avgwt = totalwt / n;
    float avgtat = totaltat / n;
    printf("Process ID   Arrival Time  Burst Time   Completion Time   Waiting Time     TurnAround Time\n");
    for (int i = 0; i < n; i++)
    {

        printf("%d\t\t", pid[i]);
        printf("%d\t\t", arr[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", ct[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\t\t", tat[i]);
        printf("\n");
    }
    printf("The average waiting time: %f\n", avgwt);
    printf("The average turnaround time: %f\n", avgtat);

    return 0;
}
