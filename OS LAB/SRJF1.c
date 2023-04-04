#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], rt[n], wt[n], tat[n];
    float avwt = 0, avtat = 0;
    printf("\nEnter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    int complete = 0, t = 0, minm = 10000000;
    int shortest = 0, finish_time;
    bool check = false;
    while (complete != n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((at[j] <= t) && (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }
        if (check == false)
        {
            t++;
            continue;
        }
        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = 10000000;
        if (rt[shortest] == 0)
        {
            complete++;
            check = false;
            finish_time = t + 1;
            wt[shortest] = finish_time - bt[shortest] - at[shortest];
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
    printf("\n\nSRTF:\n");
    printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, at[i], bt[i], wt[i], tat[i]);
    }
    avwt /= n;
    avtat /= n;
    printf("\n\nAverage Waiting Time:%.2f", avwt);
    printf("\nAverage Turnaround Time:%.2f", avtat);

    return 0;
}