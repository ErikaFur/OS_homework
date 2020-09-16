#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 6

void* text_smth(int* id){
        printf("here is thread %d\n", (int) *id);
    pthread_exit(0);
}

int main(){
    pthread_t thread;
    int status;
    for (int i = 1; i < N+1; ++i) {
        status = pthread_create(&thread, NULL, &text_smth, &i);
        if (status != 0){
            printf("thread was not created, error text is %d\n", status);
            exit(-1);
        }else{
            pthread_join(thread,NULL);
            printf("Hello from main!\n");
        }
    }
    return 0;
}
//with N = 6 output is:
//
//here is thread 1
//Hello from main!
//here is thread 2
//Hello from main!
//here is thread 3
//Hello from main!
//here is thread 4
//Hello from main!
//here is thread 5
//Hello from main!
//here is thread 6
//Hello from main!
//
//After creation of tread i check if it was creadted. After that if thread was created, programm waits thread to finish
// (print message). After that, main prints main message. Without pthread_join() I have output like this:
//
//Hello from main!
//Hello from main!
//here is thread 2
//here is thread 2
//Hello from main!
//here is thread 4
//Hello from main!
//here is thread 5
//Hello from main!
//here is thread 5
//Hello from main!
//here is thread 0
