#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t condition;

int job_available = 0;

void* worker(void* arg)
{
    pthread_mutex_lock(&mutex);

    while (!job_available)
    {
        printf("Worker: no job, going to sleep...\n");

        pthread_cond_wait(&condition, &mutex);
    }

    printf("Worker: job received!\n");

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(void)
{
    pthread_t worker_thread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condition, NULL);

    pthread_create(&worker_thread, NULL, worker, NULL);

    sleep(2);

    pthread_mutex_lock(&mutex);

    job_available = 1;

    printf("Main: job created!\n");

    pthread_cond_signal(&condition);

    pthread_mutex_unlock(&mutex);

    pthread_join(worker_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition);

    return 0;
}