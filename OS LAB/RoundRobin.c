#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void queueUpdation(int queue[], int timer, int at[], int n, int processIndex)
{
    int zeroIndex;
    for (int i = 0; i < n; i++)
    {
        if (queue[i] == 0)
        {
            zeroIndex = i;
            break;
        }
    }
    queue[zeroIndex] = processIndex + 1;
}

void queueMaintainence(int queue[], int n)
{
    for (int i = 0; (i < n - 1) && (queue[i + 1] != 0); i++)
    {
        int temp = queue[i];
        queue[i] = queue[i + 1];
        queue[i + 1] = temp;
    }
}

void checkNewArrival(int timer, int at[], int n, int processIndex, int queue[])
{
    if (timer <= at[n - 1])
    {
        int newArrival = 0;
        for (int j = (processIndex + 1); j < n; j++)
        {
            if (at[j] <= timer)
            {
                if (processIndex < j)
                {
                    processIndex = j;
                    newArrival = 1;
                }
            }
        }

        if (newArrival)
            queueUpdation(queue, timer, at, n, processIndex);
    }
}

void print(int at[], int bt[], int n, int tq)
{
    int complete[n], wt[n], ct[n], queue[n], temp_burst[n], ta[n];
    int timer = 0, processIndex = 0;
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                swap(&at[j], &at[j + 1]);
                swap(&bt[j], &bt[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        complete[i] = 0;
        queue[i] = 0;
        temp_burst[i] = bt[i];
    }
    while (timer < at[0])
        timer++;
    queue[0] = 1;

    while (1)
    {
        int flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (temp_burst[i] != 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            break;

        for (int i = 0; (i < n) && (queue[i] != 0); i++)
        {
            int ctr = 0;
            while ((ctr < tq) && (temp_burst[queue[0] - 1] > 0))
            {
                temp_burst[queue[0] - 1] -= 1;
                timer += 1;
                ctr++;

                checkNewArrival(timer, at, n, processIndex, queue);
            }

            if ((temp_burst[queue[0] - 1] == 0) && (complete[queue[0] - 1] == 0))
            {
                ct[queue[0] - 1] = timer;
                complete[queue[0] - 1] = 1;
            }

            int idle = 1;

            if (queue[n - 1] == 0)
            {
                for (int i = 0; i < n && queue[i] != 0; i++)
                {
                    if (complete[queue[i] - 1] == 0)
                    {
                        idle = 0;
                    }
                }
            }

            else
                idle = 0;

            if (idle)
            {
                timer++;
                checkNewArrival(timer, at, n, processIndex, queue);
            }

            queueMaintainence(queue, n);
        }
    }

    for (int i = 0; i < n; i++)
    {
        ta[i] = ct[i] - at[i];
        wt[i] = ta[i] - bt[i];
    }

    printf("\nPNo.\tAT\tBT\tCT\tTA\tWT\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], ta[i], wt[i]);
        avg_wt += (float)wt[i];
        avg_tat += (float)ta[i];
    }

    printf("\nAverage wt time : %f", avg_wt / n);
    printf("\nAverage Turn Around Time : %f", avg_tat / n);
}

int main()
{
    int n, tq;
    printf("Enter the number of process\n");
    scanf("%d", &n);
    int at[n], bt[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time and Burst time of Process p%d\n", i + 1);
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
    }
    printf("Enter the time quantum\n");
    scanf("%d", &tq);
    print(at, bt, n, tq);

    return 0;
}
