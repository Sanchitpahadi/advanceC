#include <stdio.h>
#include <pthread.h>

void* thread_a(void* arg)
{
    for (int i = 0; i < 10; i++)
        printf("A: %d\n", i);

    return NULL;
}

void* thread_b(void* arg)
{
    for (int i = 0; i < 10; i++)
        printf("B: %d\n", i);

    return NULL;
}
int main(void)
{
    pthread_t a;
    pthread_t b;

    pthread_create(&a, NULL, thread_a, NULL);
    pthread_create(&b, NULL, thread_b, NULL);

    pthread_join(a, NULL);
    pthread_join(b, NULL);

    printf("Main finished\n");

    return 0;
}