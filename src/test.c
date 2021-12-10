#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

void* routine()
{
    printf("test\n");
    sleep(3);
    printf("end\n");
}

void*    myturn(void *arg)
{
    int *iptr = (int *)arg;
    printf("i egal %d\n", *iptr);
    printf("My turn! %d\n", *iptr);
    (*iptr)++;
    //return void cause we just cast, void can be anything
    return NULL;
}

void*    yourturn(void *arg)
{
    int *iptr = (int *)arg;
    printf("Your turn! %d\n", *iptr);
    (*iptr)++;
    //return void cause we dont care about return type, we just cast
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t t[10];
    pthread_t t2;

    int i = 5;
	#if 0
    pthread_create(&t[0], NULL, &myturn, &i);
    pthread_create(&t2, NULL, &yourturn, &i);
    pthread_join(t[0], NULL);
    pthread_join(t2, NULL);
	#endif

	int j = 0;

	pthread_mutex_init(&mutex, NULL);
	while (j < 3)
	{
		pthread_create(&t2, NULL, &myturn, &i);
		pthread_join(t2, NULL);
		j++;
	}
    printf("done, %d\n", i);
    return 0;
}
