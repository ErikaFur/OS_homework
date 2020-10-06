#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <unistd.h>
#include "string.h"
#include <sys/resource.h>

int main(){
    int time = 10;
    int *arr;
    for (int i = 0; i < time; ++i) {
        arr = malloc(10*1024*1024);
        memset(arr, 0 , 10*1024*1024);
        struct rusage *rus = malloc(sizeof(struct rusage));
        getrusage(RUSAGE_SELF, rus);
        printf("%ld\n", rus->ru_maxrss);
        sleep(1);
    }
    return 0;
}