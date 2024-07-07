#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
sem_t chopstick[5];

void *philos(void *n){
    int ph=*(int *)n;
    printf("philosopher %d wants to eat\n",ph);
    sem_wait(&chopstick[(ph+1)%5]);
    printf("philospher %d picks left chopstick\n",ph);
    sem_wait(&chopstick[ph]);
    sleep(1);
    printf("philosopher %d is eating\n",ph);
    sleep(1);
    printf("philosopher %d has finished eating",ph);
    sem_post(&chopstick[(ph+1)%5]);
    sem_post(&chopstick[ph]);
}
int main(){
    pthread_t T[5];
    int i,n[5];
    for(i=0;i<5;i++){
     sem_init(&chopstick[i],0,1);
    }
    for(i=0;i<5;i++){
        n[i]=i;
        pthread_create(&T[i],NULL,philos,(void*)&n[i]);
    }
    for(i=0;i<5;i++)
    pthread_join(T[i],NULL);
}
