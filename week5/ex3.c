#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//global variables
int produced = 0;
int producer_sleeps = 0;
int consumer_sleeps = 1;
int n = 8;

_Noreturn void produce(int *buffer)
{
    while (1)
    {
        if (!producer_sleeps)
        {
            buffer[produced] = 1;
            produced++;
            printf("Produced #%d\n", produced);
        }
        else {
            printf("Producer sleeps!\n");
        }
        producer_sleeps = n < produced;
        consumer_sleeps = produced < 1;
        sleep(1);
    }
}

_Noreturn void consume(int *buffer)
{
    while (1)
    {
        if (!consumer_sleeps)
        {
            produced--;
            buffer[produced] = 0;
            printf("Consumed #%d\n", produced+1);
        }
        else {
            printf("Consumer waits!\n");
        }
        producer_sleeps = n < produced;
        consumer_sleeps = produced < 1;
        sleep(2);
    }
}
int main()
{
    int* buf = malloc(n);
    pthread_t producer, consumer;
    pthread_create(&producer, NULL, produce, buf);
    pthread_create(&consumer, NULL, consume, buf);
    pthread_join(producer, NULL);
}