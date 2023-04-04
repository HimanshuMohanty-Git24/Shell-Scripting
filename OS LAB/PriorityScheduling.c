#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 50

// Struct to hold process details
typedef struct
{
    int at;  // Arrival Time
    int bt;  // Burst Time
    int pr;  // Priority
    int pno; // Process Number
} process;

// Function to sort processes by arrival time and then priority
int comp(const void *a, const void *b)
{
    const process *p1 = a;
    const process *p2 = b;

    if (p1->at == p2->at)
    {
        return (p1->pr - p2->pr);
    }

    return (p1->at - p2->at);
}

// Function to calculate waiting time
void get_wt_time(process proc[], int n, int wt[])
{
    // Initializing initial elements of the arrays
    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = proc[i - 1].bt + wt[i - 1];

        // If waiting time is negative, change it to zero
        if (wt[i] < 0)
        {
            wt[i] = 0;
        }
    }
}

// Function to calculate turnaround time
void get_tat_time(process proc[], int n, int wt[], int tat[])
{
    // Filling turnaround time array
    for (int i = 0; i < n; i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }
}

// Function to find the Gantt Chart
void findgc(process proc[], int n)
{
    // Declare waiting time and turnaround time array
    int wt[MAX_PROCESS], tat[MAX_PROCESS];

    double wavg = 0, tavg = 0;

    // Function call to find waiting time array
    get_wt_time(proc, n, wt);

    // Function call to find turnaround time
    get_tat_time(proc, n, wt, tat);

    int stime[MAX_PROCESS], ctime[MAX_PROCESS];

    stime[0] = proc[0].at;
    ctime[0] = stime[0] + tat[0];

    // Calculating starting and ending time
    for (int i = 1; i < n; i++)
    {
        stime[i] = ctime[i - 1];
        ctime[i] = stime[i] + tat[i] - wt[i];
    }

    printf("Process_no\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time\n");

    // Display the process details
    for (int i = 0; i < n; i++)
    {
        wavg += wt[i];
        tavg += tat[i];

        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", proc[i].pno, stime[i], ctime[i], tat[i], wt[i]);
    }

    // Display the average waiting time and average turn around time
    printf("Average waiting time is: %.2f\n", wavg / (double)n);
    printf("Average turnaround time: %.2f\n", tavg / (double)n);
}
int main()
{
    process proc[MAX_PROCESS];

    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Taking process details
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time, burst time and priority of process %d: ", i + 1);
        scanf("%d %d %d", &proc[i].at, &proc[i].bt, &proc[i].pr);

        proc[i].pno = i + 1;
    }

    // Sorting the processes by arrival time and then priority
    qsort(proc, n, sizeof(process), comp);

    // Function call to find the Gantt Chart
    findgc(proc, n);

    return 0;
}