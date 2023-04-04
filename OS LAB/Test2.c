#include <stdio.h>

#define MAX_PROCESSES 100

void fcfs(int arrivalTime[], int burstTime[], int n, int finishTime[], char jobNames[][2])
{
    int i, j;
    int waitingTime[MAX_PROCESSES];
    int turnaroundTime[MAX_PROCESSES];
    int startTime[MAX_PROCESSES];
    int stopTime[MAX_PROCESSES];
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    // Initialize finish time of first process
    finishTime[0] = arrivalTime[0] + burstTime[0];
    stopTime[0] = finishTime[0];

    // Calculate finish time, waiting time, and turnaround time for each process
    for (i = 1; i < n; i++)
    {
        // Finish time is the maximum of the current time and the arrival time of the current process plus its burst time
        finishTime[i] = (arrivalTime[i] > finishTime[i - 1]) ? arrivalTime[i] + burstTime[i] : finishTime[i - 1] + burstTime[i];
        stopTime[i] = finishTime[i];

        // Calculate waiting time and turnaround time for the current process
        waitingTime[i] = finishTime[i] - (arrivalTime[i] + burstTime[i]);
        turnaroundTime[i] = finishTime[i] - arrivalTime[i];

        // Calculate total waiting time and turnaround time
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Print Gantt chart
    printf("\nGantt Chart:\n");
    for (i = 0; i < n; i++)
    {
        printf("| %c ", jobNames[i][0]);
    }
    printf("|\n");
    for (i = 0; i < n; i++)
    {
        printf("%d   ", startTime[i]);
    }
    printf("%d\n", stopTime[n - 1]);

    // Print process information
    printf("\nProcess\tArrival Time\tBurst Time\tFinish Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%c\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", jobNames[i][0], arrivalTime[i], burstTime[i], finishTime[i], waitingTime[i], turnaroundTime[i]);
    }

    // Print average waiting time and turnaround time
    printf("\nAverage waiting time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average turnaround time: %.2f\n", (float)totalTurnaroundTime / n);
}

int main()
{
    int arrivalTime[MAX_PROCESSES] = {0, 1, 2, 3, 4, 5};
    int burstTime[MAX_PROCESSES] = {3, 2, 1, 4, 5, 2};
    int n = 5;
    int finishTime[MAX_PROCESSES];
    char jobNames[MAX_PROCESSES][2];

    // Assign job names
    for (int i = 0; i < n; i++)
    {
        jobNames[i][0] = i + 65; // ASCII code for 'A' is 65
        jobNames[i][1] = '\0';
    }

    fcfs(arrivalTime, burstTime, n, finishTime, jobNames);

    return 0;
}
