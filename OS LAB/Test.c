#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char job;
    int at;
    int bt;
} Process;

typedef struct
{
    char job;
    int start;
    int stop;
} GanttChartInfo;

void swap(Process *a, Process *b)
{
    Process temp = *a;
    *a = *b;
    *b = temp;
}

void sortProcesses(Process *processesInfo, int numProcesses)
{
    for (int i = 0; i < numProcesses - 1; i++)
    {
        for (int j = i + 1; j < numProcesses; j++)
        {
            if (processesInfo[i].at > processesInfo[j].at)
            {
                swap(&processesInfo[i], &processesInfo[j]);
            }
        }
    }
}

void fcfs(int *arrivalTime, int *burstTime, int numProcesses)
{
    Process processesInfo[numProcesses];
    GanttChartInfo ganttChartInfo[numProcesses];

    for (int i = 0; i < numProcesses; i++)
    {
        processesInfo[i].job = (i + 10) + 'A';
        processesInfo[i].at = arrivalTime[i];
        processesInfo[i].bt = burstTime[i];
    }

    sortProcesses(processesInfo, numProcesses);

    int finishTime[numProcesses];
    printf("Job\tAT\tBT\tTAT\tWT\n");
    for (int i = 0; i < numProcesses; i++)
    {
        if (i == 0 || processesInfo[i].at > finishTime[i - 1])
        {
            finishTime[i] = processesInfo[i].at + processesInfo[i].bt;

            ganttChartInfo[i].job = processesInfo[i].job;
            ganttChartInfo[i].start = processesInfo[i].at;
            ganttChartInfo[i].stop = finishTime[i];
        }
        else
        {
            finishTime[i] = finishTime[i - 1] + processesInfo[i].bt;

            ganttChartInfo[i].job = processesInfo[i].job;
            ganttChartInfo[i].start = finishTime[i - 1];
            ganttChartInfo[i].stop = finishTime[i];
        }

        int tat = finishTime[i] - processesInfo[i].at;
        int wat = finishTime[i] - processesInfo[i].at - processesInfo[i].bt;
        printf("%c\t%d\t%d\t%d\t%d\n",
               processesInfo[i].job,
               processesInfo[i].at,
               processesInfo[i].bt,
               tat,
               wat);
    }

    printf("Gantt Chart:\n");
    printf("Job\tStart Time\tEnd Time\n");
    for (int i = 0; i < numProcesses; i++)
    {
        printf("%c\t%d\t\t%d\n",
               ganttChartInfo[i].job,
               ganttChartInfo[i].start,
               ganttChartInfo[i].stop);
    }
}

int main()
{
    int arrivalTime[] = {0, 1, 2, 3, 4, 5};
    int burstTime[] = {3, 2, 1, 4, 5, 2};
    int numProcesses = sizeof(arrivalTime) / sizeof(arrivalTime[0]);

    fcfs(arrivalTime, burstTime, numProcesses);

    return 0;
}
