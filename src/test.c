#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "../includes/philo.h"

pthread_mutex_t mutex;
long long inde = 0;

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

void *count(void *arg)
{
    while (1)
    {
        //this region is the critical code region
        pthread_mutex_lock(&mutex);

        if(inde >= 10000)
        {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        
        inde++;
        //end of critical region
        pthread_mutex_unlock(&mutex);
        printf("index is equal to %lld\n", inde);
    }
}

int main(int argc, char **argv)
{
    pthread_t *t_group = malloc(sizeof(pthread_t) * 6);
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
	while (j < 6)
	{
		pthread_create(&t_group[j], NULL, &count, NULL);
		j++;
	}
    j = 0;
    while (j < 6)
    {
        pthread_join(t_group[j], NULL);
        j++;
    }
    pthread_mutex_destroy(&mutex);
    printf("done, %d\n", i);
    return 0;
}
