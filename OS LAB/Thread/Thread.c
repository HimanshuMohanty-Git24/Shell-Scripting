#include <stdio.h>
#include <pthread.h>

void *hello_thread(void *thread_num_ptr)
{
    int thread_num = *((int *)thread_num_ptr);
    printf("Hello from thread %d!\n", thread_num);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[3];

    int thread_nums[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&threads[i], NULL, hello_thread, (void *)&thread_nums[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
