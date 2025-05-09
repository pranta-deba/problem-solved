#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t chopstick[5];

void *philosophers(void *arg)
{
    int id = *(int *)arg;
    int left = id;
    int right = (id + 1) % 5;

    if (id == 4)
    {
        int temp = left;
        left = right;
        right = temp;
    }

    while (1)
    {
        sem_wait(&chopstick[left]);
        sem_wait(&chopstick[right]);

        printf("\n------------------------------------\n");
        printf("Philosopher %d is eating\n", id);
        printf("------------------------------------\n");
        sleep(2);

        sem_post(&chopstick[left]);
        sem_post(&chopstick[right]);

        printf("\n------------------------------------\n");
        printf("Philosopher %d is thinking\n", id);
        printf("------------------------------------\n");
        sleep(2);
    }
    return NULL;
}

int main()
{
    pthread_t philosophers_thread[5];
    int philosopher_ids[5];

    for (int i = 0; i < 5; i++)
    {
        if (sem_init(&chopstick[i], 0, 1) != 0)
        {
            perror("sem_init failed");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        philosopher_ids[i] = i;
        if (pthread_create(&philosophers_thread[i], NULL, philosophers, &philosopher_ids[i]) != 0)
        {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (pthread_join(philosophers_thread[i], NULL) != 0)
        {
            perror("pthread_join failed");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (sem_destroy(&chopstick[i]) != 0)
        {
            perror("sem_destroy failed");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
