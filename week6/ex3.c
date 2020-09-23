#include <stdio.h>
#define n 5
#define true 1
#define false 0
#define quantum 1


struct process
{
	int site;
	int arrival_time;
	int burst_time;
	int completion_time;
	int turn_around_time;
	int waiting_time;
};


double average_turnaround_time = 0;
double average_waiting_time = 0;

struct process processes[n];
int done[n];

int main(void) {
	int time = 0;
	int counter = 0;
	int previous_arrival_time = -1;
	//input
	printf("Input %d procecces in format 'number number' for each process\n", n);
	for (int i = 0; i < n; i++) {
		processes[i].site = i;
		scanf_s("%d", &processes[i].arrival_time);
		scanf_s("%d", &processes[i].burst_time);
	}
	
	int turn = 0;
	while (counter != n)
	{
		turn++;
		for (size_t i = 0; i < n; i++)
		{
			if (done[i] == 1) continue;
			if (processes[i].burst_time <= quantum * turn) {
				processes[i].waiting_time += time - processes[i].arrival_time;
				time += quantum;
				processes[i].completion_time = time - quantum + processes[i].burst_time;
				processes[i].turn_around_time = processes[i].burst_time + processes[i].waiting_time;
				counter++;
				done[i] = 1;
				printf("for process %d completion time is %d, turn around time is %d, waiting time is %d\n", processes[i].site, processes[i].completion_time, processes[i].turn_around_time, processes[i].waiting_time);
			}
			else {
				processes[i].waiting_time += time - processes[i].arrival_time;
				time += quantum;
			}
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		average_turnaround_time += processes[i].turn_around_time;
		average_waiting_time += processes[i].waiting_time;
	}
	printf("time of compliting all programms = %d\naverage turnaround time = %lf\naverage waiting time = %lf", time, average_turnaround_time / n, average_waiting_time / n);
	return 0;
}

