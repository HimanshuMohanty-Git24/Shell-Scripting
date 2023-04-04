#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n], arrival_time[n], remaining_time[n], completion_time[n];
    int waiting_time[n], turnaround_time[n];
    float average_waiting_time = 0, average_turnaround_time = 0;
    printf("\nEnter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    // Non-Preemptive SJF
    int time = 0;
    bool executed[n];
    for (int i = 0; i < n; i++)
        executed[i] = false;
    for (int i = 0; i < n; i++)
    {
        int min = 99999999, index;
        for (int j = 0; j < n; j++)
        {
            if (!executed[j] && arrival_time[j] <= time && remaining_time[j] < min)
            {
                min = remaining_time[j];
                index = j;
            }
        }
        if (min == 99999999)
        {
            time++;
            i--;
            continue;
        }
        time += remaining_time[index];
        completion_time[index] = time;
        executed[index] = true;
    }
    printf("\n\nSJF (Non-Preemptive):\n");
    printf("\nProcess\t\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time");
    for (int i = 0; i < n; i++)
    {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        average_waiting_time += waiting_time[i];
        average_turnaround_time += turnaround_time[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }
    average_waiting_time /= n;
    average_turnaround_time /= n;
    printf("\n\nAverage Waiting Time: %.2f", average_waiting_time);
    printf("\nAverage Turnaround Time: %.2f", average_turnaround_time);
    // Preemptive SJF
    for (int i = 0; i < n; i++)
        remaining_time[i] = burst_time[i];
    time = 0;
    int processes_left = n;
    while (processes_left > 0)
    {
        int min = 99999999, index = -1;
        for (int i = 0; i < n; i++)
        {
            if (arrival_time[i] <= time && remaining_time[i] > 0 && remaining_time[i] < min)
            {
                min = remaining_time[i];
                index = i;
            }
        }
        if (index == -1)
        {
            time++;
            continue;
        }
        remaining_time[index]--;
        if (remaining_time[index] == 0)
        {
            completion_time[index] = time + 1;
            processes_left--;
        }
        time++;
    }
    printf("\n\nSJF (Preemptive):\n");
    printf("\nProcess\t\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time");
    average_waiting_time = 0;
    average_turnaround_time = 0;
    for (int i = 0; i < n; i++)
    {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        average_waiting_time += waiting_time[i];
        average_turnaround_time += turnaround_time[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }
    average_waiting_time /= n;
    average_turnaround_time /= n;
    printf("\n\nAverage Waiting Time: %.2f", average_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", average_turnaround_time);
    return 0;
}