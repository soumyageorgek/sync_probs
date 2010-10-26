/*In the below problem of two threads, at a point of execution, neither is allowed to proceed until both have arrived.*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t astart, bstart;
int i, j;
void *fna(void *s)
{
	while(1){
		i = 0;
		sem_post(&astart);
		sem_wait(&bstart);
		j++;
		sleep(3);
		printf("value of i and j in fna: %d %d\n", i, j);
		sleep(5);
	}
}
void *fnb(void *s)
{
	while(1){
		j=0;
		sem_post(&bstart);
		sem_wait(&astart);
		i++;
		sleep(3);
		printf("value of i and j in fnb: %d %d\n", i, j);
		sleep(5);
	}
}
main()
{
	pthread_t t1, t2;

	sem_init(&astart, 0, 0);
	sem_init(&bstart, 0, 0);
	pthread_create(&t1, 0, fna, 0);
	pthread_create(&t2, 0, fnb, 0);
	pthread_join(t1, 0);
	pthread_join(t2, 0);
}
