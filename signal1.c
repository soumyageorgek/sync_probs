//This program synchronises reading input from a file and only after that writing to the standard output occurs.
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t s;
char buf[20];
void *readline(void *i)
{
	FILE *f1;
	
	f1 = fopen("fp.c","r");
	while(fgets(buf, 5, f1) != NULL){
		sem_post(&s);
		sleep(5);
	}
}
void *writeline(void *i)
{
	FILE *f1;
	
	while(1){
		sem_wait(&s);
		printf("%s\n",buf);
	}
}
main()
{
	pthread_t t1,t2;

	sem_init(&s, 0, 0);
	pthread_create(&t1, 0, readline, 0);
	pthread_create(&t2, 0, writeline, 0);
	pthread_join(t1, 0);
	pthread_join(t2, 0);
}
