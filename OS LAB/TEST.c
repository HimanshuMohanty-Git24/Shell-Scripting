#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct
{
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void sjf_scheduling(Process *processes, int n)
{
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int i, j, min_index;
    Process temp;

    // Calculate waiting and turnaround times for each process
    for (i = 0; i < n; i++)
    {
        min_index = i;
        for (j = i + 1; j < n; j++)
        {
            if (processes[j].burst_time < processes[min_index].burst_time)
            {
                min_index = j;
            }
        }

        temp = processes[i];
        processes[i] = processes[min_index];
        processes[min_index] = temp;

        processes[i].waiting_time = total_waiting_time;
        total_waiting_time += processes[i].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    // Print out results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("Average waiting time = %f\n", (float)total_waiting_time / n);
    printf("Average turnaround time = %f\n", (float)total_turnaround_time / n);
}

int main()
{
    int n, i;
    Process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        processes[i].id = i + 1;
        scanf("%d", &processes[i].burst_time);
    }
    printf("Enter arrival time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
    }