#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

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
    pthread_t t1;
    pthread_t t2;

    int i = 5;
    pthread_create(&t1, NULL, &myturn, &i);
    pthread_create(&t2, NULL, &yourturn, &i);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("done, %d\n", i);
    return 0;
}
