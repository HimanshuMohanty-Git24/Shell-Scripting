#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;
    int burst_time;
    int remaining_time;
    int arrival_time;
};

int main()
{
    int n, quantum_time, total_waiting_time = 0, total_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum_time);

    struct Process *processes = malloc(n * sizeof(struct Process));
    int *waiting_times = malloc(n * sizeof(int));
    int *turnaround_times = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        processes[i].pid = i + 1;
        printf("Enter the arrival time and burst time for process %d: ", processes[i].pid);
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    int time = 0;
    int completed_processes = 0;
    while (completed_processes < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= time)
            {
                if (processes[i].remaining_time <= quantum_time)
                {
                    time += processes[i].remaining_time;
                    turnaround_times[i] = time - processes[i].arrival_time;
                    completed_processes++;
                    total_waiting_time += time - processes[i].arrival_time - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                }
                else
                {
                    time += quantum_time;
                    processes[i].remaining_time -= quantum_time;
                }
            }
        }
    }

    printf("\nPID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, waiting_times[i], turnaround_times[i]);
        total_turnaround_time += turnaround_times[i];
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);

    free(processes);
    free(waiting_times);
    free(turnaround_times);

    return 0;
}
