#include <stdio.h>
#define n 14

struct process
{
	int arrival_time;
	int burst_time;
	int completion_time;
	int turn_around_time;
	int waiting_time;
};

double average_turnaround_time = 0;
double average_waiting_time = 0;

struct process processes[n];

int main(void) {
	int time = 0;
	printf("Input %d procecces in format 'number number' for each process\n", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &processes[i].arrival_time);
		scanf_s("%d", &processes[i].burst_time);
	}

	for (size_t i = 0; i < n; i++)
	{
		if (time < processes[i].arrival_time)
		{
			time = processes[i].arrival_time;
		}
		processes[i].waiting_time = time - processes[i].arrival_time;
		time += processes[i].burst_time;
		processes[i].completion_time = time;
		processes[i].turn_around_time = processes[i].burst_time + processes[i].waiting_time;
		printf("for process %d completion time is %d, turn around time is %d, waiting time is %d\n", i, processes[i].completion_time, processes[i].turn_around_time, processes[i].waiting_time);
	}

	for (size_t i = 0; i < n; i++)
	{
		average_turnaround_time += processes[i].turn_around_time;
		average_waiting_time += processes[i].waiting_time;
	}
	printf("time of compliting all programms = %d\naverage turnaround time = %lf\naverage waiting time = %lf", time, average_turnaround_time / n, average_waiting_time / n);
	return 0;
}