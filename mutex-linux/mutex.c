#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *th1(void *arg)
{
	for(;;)
	{
		pthread_mutex_lock (&mutex);
		usleep(100); putchar('a'); fflush(stdout);
		usleep(100); putchar('b'); fflush(stdout);
		usleep(100); putchar('c'); fflush(stdout);
		pthread_mutex_unlock (&mutex);
	}
	return (NULL);
}

void *th2(void *arg)
{
	for(;;)
	{
		pthread_mutex_lock (&mutex);
		usleep(100); putchar('x'); fflush(stdout);
		usleep(100); putchar('y'); fflush(stdout);
		usleep(100); putchar('z'); fflush(stdout);
		pthread_mutex_unlock (&mutex);
	}
	return (NULL);
}

int main() {
	pthread_t a, b;
	pthread_mutex_init (&mutex, NULL);
	pthread_create(&a, NULL, th1, NULL);
	pthread_create(&b, NULL, th2, NULL);
	sleep(10);
	pthread_mutex_destroy(&mutex);
	return 0;
}
