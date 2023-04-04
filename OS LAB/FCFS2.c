#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    int at[n];
    int atRep[n];
    printf("\nEnter the Arrival Time of Processes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter Arrival Time of P%d:", i);
        scanf("%d", &at[i]);
        atRep[i] = at[i];
        printf("\n");
    }
    int bt[n];
    int btRep[n];
    printf("\nEnter the Burst Time of Processes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter Burst Time of P%d:", i);
        scanf("%d", &bt[i]);
        btRep[i] = bt[i];
        printf("\n");
    }
    int ct[n];
    int tat[n];
    int wt[n];
    int itr = 0;
    int sum = 0;
    while (itr < n)
    {
        int minIndex = 0;
        for (int i = 0; i < n; i++)
        {
            if (atRep[minIndex] > atRep[i])
            {
                minIndex = i;
            }
        }
        atRep[minIndex] = 999;
        if (sum - atRep[minIndex] < 0)
        {
            sum = sum + bt[minIndex] + (at[minIndex] - sum);
        }
        else
        {
            sum = sum + bt[minIndex];
        }
        ct[minIndex] = sum;
        itr++;
    }
    printf("Completion time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d:%d\n", i, ct[i]);
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    printf("TAT\tWT\n");
    int sumTat = 0;
    int sumWt = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\n", tat[i], wt[i]);
        sumTat = sumTat + tat[i];
        sumWt = sumWt + wt[i];
    }
    float avgtat = (float)sumTat / (float)n;
    float avgwt = (float)sumWt / (float)n;
    printf("Average TAT:%f\nAverage WT:%f\n", avgtat, avgwt);
    return 0;
}
