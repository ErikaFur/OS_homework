#include <stdio.h>
#define n 5
#define true 1
#define false 0



struct process
{
	int site;
	int arrival_time;
	int burst_time;
	int completion_time;
	int turn_around_time;
	int waiting_time;
};

void bubbleSort(struct process* a, int start, int end) {
	size_t i, j;
	struct process tmp;
	for (i = start + 1; i < end+1; i++) {
		for (j = start + 1; j < end+1; j++) {
			if (a[j].burst_time < a[j - 1].burst_time) {
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
	}
}

double average_turnaround_time = 0;
double average_waiting_time = 0;

struct process processes[n];
struct process processes_now[n];

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
	
	for (size_t i = 0; i < n; i++)
	{
		if (time >= processes[i].arrival_time && previous_arrival_time != processes[i].arrival_time) {
			counter = i;
			previous_arrival_time = processes[i].arrival_time;
			while (processes[counter].arrival_time <= previous_arrival_time && counter != n)
			{
				counter++;
			}
			counter--;
		}
		else if(time < processes[i].arrival_time) 
		{
			time = processes[i].arrival_time;
			i --;
			continue;
		}
		bubbleSort(processes, i, counter);
		processes[i].waiting_time = time - processes[i].arrival_time;
		time += processes[i].burst_time;
		processes[i].completion_time = time;
		processes[i].turn_around_time = processes[i].burst_time + processes[i].waiting_time;
		printf("for process %d completion time is %d, turn around time is %d, waiting time is %d\n", processes[i].site, processes[i].completion_time, processes[i].turn_around_time, processes[i].waiting_time);
	}

	for (size_t i = 0; i < n; i++)
	{
		average_turnaround_time += processes[i].turn_around_time;
		average_waiting_time += processes[i].waiting_time;
	}
	printf("time of compliting all programms = %d\naverage turnaround time = %lf\naverage waiting time = %lf", time, average_turnaround_time / n, average_waiting_time / n);
	return 0;
}

//0 1 0 2 0 1 3 1 3 2