#include<stdio.h>
#include<pthread.h>
#include <sys/types.h> 
#include<stdlib.h>

#define BUFFER_SIZE 5

int mycount,in,out;
int buf[BUFFER_SIZE];
int next_produced,next_consumed;
void *producer(void *param);
void *consumer(void *param);

int main()
{
    pthread_t thread1,thread2;
    pthread_attr_t attr1,attr2;
    //int *p;
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_create(&thread1,&attr1,&producer,NULL);
    pthread_create(&thread2,&attr2,&consumer,NULL);
}

void* producer(void* arg)
{
    while(1)
    {
            //printf(">0 created");
        while(mycount==BUFFER_SIZE)
        {
            printf("producer mycount: %d\n",mycount);
        }
        buf[in]=next_produced++;
        printf("Produced: %d, in: %d\n",next_produced-1,in);
        in = (in+1)%BUFFER_SIZE;
        mycount++;
    }
}

void* consumer(void* arg)
{
    while(1)
    {
        //printf("0 created");
        while(mycount==0)
        {
            printf("Consumer mycount: %d\n",mycount);
        }
        next_consumed=buf[out];
        printf("Consumed %d, out: %d\n", next_consumed,out);
        out = (out+1)%BUFFER_SIZE;
        mycount--;
    }
}
