#include <stdio.h>
#include "stdlib.h"
#include <math.h>
int update(const int *upd, int*ages, int age_size, int number_of_counters){
    //age_size = 8;
    for (int i = 0; i < number_of_counters; ++i) {
        ages[i] = ((int) pow(2,8-1)) * upd[i] + ages[i]/2;
    }
}

int main(){

    float fault = 0;
    float clock = 0;
    int n = 10;
    int age_size = 8;


    int number_of_counters = 1000;
    int pages_counters[number_of_counters];
    int to_update[number_of_counters];
    int table[n];
    for (int i = 0; i < n; ++i) {
        table[i] = -1;
    }
    char buff[255] = "12";
    int int_buff;
    FILE *fp = fopen("/home/senfur/Innopolis/os_homework/week9/Lab 09 input.txt", "r");
    while(fscanf(fp,"%s", buff)!= EOF) {
        clock++;
        int_buff = atoi(buff);
        int check = 0;
        for (int i = 0; i < n; ++i) {
            if (table[i] == int_buff){
                check = 1;
                break;
            }
        }
        if (check == 1){
            to_update[int_buff] = 1;
            update(to_update,pages_counters,age_size,number_of_counters);
            to_update[int_buff] = 0;
        }else {
            fault++;
            int min_index = 0;
            for (int i = 0; i < n; ++i) {
                if (table[i] == -1){
                    min_index = i;
                    break;
                }
                if (pages_counters[table[i]] < pages_counters[table[min_index]]){
                    min_index = i;
                }
            }
            table[min_index] = int_buff;
            to_update[table[min_index]] = 1;
            update(to_update,pages_counters,age_size,number_of_counters);
            to_update[int_buff] = 0;
        }

    }
    printf("n = %d\nmiss ratio %f\n",n,fault/clock);
    printf("hit ratio %f\n",1 - fault/clock);
    return 0;
}

/**
 * n = 10:
 * miss ratio 0.989000
 * hit ratio 0.011000
 *
 * n = 50:
 * miss ratio 0.951000
 * hit ratio 0.049000
 *
 * n = 100:
 *
 * miss ratio 0.903000
 * hit ratio 0.097000
  */

