#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX 1
#define loops  2

int buffer[MAX];
int fill = 0;
int use = 0;


void put(int value) {
    buffer[fill] = value;
    fill = (fill+1)% MAX;
}
int get() {
    int tmp = buffer[use];
    use = (use+1) % MAX;
    return tmp;
}

sem_t empty;
sem_t full;

void *producer(void *arg)  {
    int i;
    for (i = 0;i < loops; i++) {
        sem_wait(&empty);
        put(i);
        sem_post(&fill);
    }
}

void *consumer(void *arg) {
    int i, tmp;
    while (tmp != -1) {
        sem_wait(&full);
        tmp = get();
        sem_post(&empty);
        printf("tmp: %d\n", tmp);
        sleep(2);
    }
}


int main(int argc, char *argv[]) {
    sem_open(&empty, 0, MAX);
    sem_open(&full, 0, 0);

    pthread_t p;
    pthread_create(&p, NULL, producer, NULL);
    consumer(NULL);
}
