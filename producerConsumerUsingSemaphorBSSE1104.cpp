#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>

#define SIZE 5

atomic_int khali = 1, kaaj_chole = 0, lock = 0;

int input = 0, output = 0, produced = 0, consumed = 0;
int store[SIZE];

void wait(atomic_int *semaphore)
{
    while(*semaphore <= 0); //wait korbe

    (*semaphore)--;
}

void signals(atomic_int *semaphore)
{
    (*semaphore)++;
}

atomic_int test_and_set(atomic_int *locked)
{
    atomic_int rv = *locked;
    *locked = 1;
    return rv;
}


void *producer()
{

    while(produced < 50)
    {

        wait(&khali);

        while(test_and_set(&lock));

        store[input] = ++produced;

        printf("Producer produced = %d\n", store[input]);
        printf("current status of the queue :");

        for(int i = 0; i < SIZE; i++)
        {
            printf("%d", store[i]);
        }

        printf("\n");

        input = (input+1)%SIZE;
        lock = 0;
        signals(&kaaj_chole);
    }
}

void *consumer()
{
    while(consumed < 50)
    {
        wait(&kaaj_chole);
        while(test_and_set(&lock));

        int item = store[output];
        store[output] = 0;
        consumed++;

        printf("Consumer consumed = %d\n",item);

        printf("current status of the queue :");

        output = (output+1)%SIZE;

        if(output == input)printf("BLANK\n");

        else
        {
            for(int i = 0; i < SIZE; i++)
            {
                printf("%d",store[i]);
            }
            printf("\n");
        }
        lock = 0;
        signals(&khali);
    }
}

int main()
{
    pthread_t thread1,thread2;

    pthread_create(&thread1, NULL, (void *)producer, NULL);
    pthread_create(&thread2, NULL, (void *)consumer, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;

}