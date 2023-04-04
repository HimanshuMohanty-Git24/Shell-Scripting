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
    int n, total_waiting_time = 0, total_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

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
        float highest_ratio = -1;
        int selected_process = -1;
        for (int i = 0; i < n; i++)
        {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= time)
            {
                float ratio = (float)(processes[i].burst_time + total_waiting_time - processes[i].arrival_time) / processes[i].burst_time;
                if (ratio > highest_ratio)
                {
                    highest_ratio = ratio;
                    selected_process = i;
                }
            }
        }
        if (selected_process == -1)
        {
            time++;
            continue;
        }
        waiting_times[selected_process] = time - processes[selected_process].arrival_time;
        time += processes[selected_process].burst_time;
        turnaround_times[selected_process] = time - processes[selected_process].arrival_time;
        total_waiting_time += waiting_times[selected_process];
        total_turnaround_time += turnaround_times[selected_process];
        processes[selected_process].remaining_time = 0;
        completed_processes++;
    }

    printf("\nPID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, waiting_times[i], turnaround_times[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);

    free(processes);
    free(waiting_times);
    free(turnaround_times);

    return 0;
}
