//In the below problem, there is a barrier created by semaphore s.The barrier can be overcome only if all other threads reach that point.
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int n=3;
int count=0;
pthread_mutex_t mutex, mutex1;
sem_t s;
void c_adjust()
{
	if(count < n)
                count++;
}
void c_check()
{
	int w;
	if(count == n){
		count = 0;
		for(w=0;w<n;w++)
			sem_post(&s);
	}	
}
void *fn1(void *str)
{
	pthread_mutex_lock(&mutex);
	c_adjust();
	pthread_mutex_unlock(&mutex);
	pthread_mutex_lock(&mutex1);
	c_check();
	pthread_mutex_unlock(&mutex1);
	sleep(5);
	sem_wait(&s);
	printf("%s\n", (char *)str);
}
main()
{
	pthread_t t1, t2, t3;

	pthread_mutex_init(&mutex, 0);
	sem_init(&s, 0, 0);
	pthread_create(&t1, 0, fn1, "first");
	pthread_create(&t2, 0, fn1, "second");
	pthread_create(&t3, 0, fn1, "third");
	pthread_join(t1, 0);
	pthread_join(t2, 0);
	pthread_join(t3, 0);
}
