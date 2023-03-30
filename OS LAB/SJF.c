#include <stdio.h>

// Define the schdule
struct SJF
{
    int pId;
    int at;
    int bt;
    int tat;
    int wt;
    int ct;
};

void SJF(struct SJF s[], int n)
{
    // define the varibale
    struct SJF temp;
    float avg_wt = 0, avg_tat = 0;

    // Sorting acording to arrival time
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].at > s[j + 1].at)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // Set the compilation time
    for (int i = 0; i < n; i++)
    {
        for (int j = i; s[j].at <= s[i - 1].ct; j++)
        {
            if (s[i].bt > s[j].bt)
            {
                temp = s[j];
                s[j] = s[i];
                s[i] = temp;
            }
        }
        if (i != 0)
        {
            if (s[i - 1].ct < s[i].at)
                s[i].ct = s[i].at + s[i].bt;
            else
                s[i].ct = s[i].bt + s[i - 1].ct;
        }
        else
            s[0].ct = s[0].bt + s[0].at;
    }

    // calaulate the Turn around time and waiting time
    for (int i = 0; i < n; i++)
    {
        s[i].tat = s[i].ct - s[i].at;
        s[i].wt = s[i].tat - s[i].bt;
    }

    // print the table
    printf("PN\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++)
    {
        // calculate the average value
        avg_wt += (float)s[i].wt;
        avg_tat += (float)s[i].tat;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", s[i].wt, s[i].at, s[i].bt, s[i].ct, s[i].tat, s[i].wt);
    }
    printf("Average waiting time %f\n", avg_wt / (float)n);
    printf("Average TurnAround Time %f\n", avg_tat / (float)n);
}

int main()
{
    int n;
    printf("Enter the number of process\n");
    scanf("%d", &n);
    struct SJF s[n];

    for (int i = 0; i < n; i++)
    {
        s[i].pId = i + 1;
        printf("Enter the arrival time and Burst time of Process p%d\n", s[i].pId);
        scanf("%d", &s[i].at);
        scanf("%d", &s[i].bt);
    }

    ljf_find(s, n);
    return 0;
}