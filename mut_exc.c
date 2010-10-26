//Since mutual exclusion is established, no increments are lost.The program prints 10 as output.
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int m=0;
sem_t s;
void *inca(void *str)
{
	int i=0;
	while(i<5){
		sem_wait(&s);
		m++;
		sem_post(&s);
		i++;
	}
}
void *incb(void *str)
{
	int i=0;
	while(i<5){
		sem_wait(&s);
		m++;
		sem_post(&s);
		i++;
	}
}
main()
{
	pthread_t t1, t2;
	
	sem_init(&s, 0, 1);
	pthread_create(&t1, 0, inca, 0);
	pthread_create(&t2, 0, incb, 0);
	pthread_join(t1, 0);
	pthread_join(t2, 0);
	printf("%d\n", m);
}
