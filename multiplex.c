//Here we constrain that atmost 2 threads exist in the critical section.But there are 5 threads competing for critical section.
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t s;
void *inca(void *var)
{

	while(1){
		sem_wait(&s);
		printf("Thread %d is inside function\n",*(int *)var);
		sem_post(&s);
		printf("Thread %d is exiting\n",*(int *)var);
		sleep(5);
	}
}
main()
{
	pthread_t t[5];
	int a[5];
	int i;
	
	for(i=0;i<5;i++)
		a[i]=i;
	sem_init(&s, 0, 2);
	for(i=0;i<5;i++)
		pthread_create(&t[i], 0, inca, &a[i]);
	for(i=0;i<5;i++)
		pthread_join(t[i], 0);
}
