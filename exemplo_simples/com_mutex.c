#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int contador = 0;
pthread_mutex_t mutex;

void *contar(void *arg) {
    for (int i = 0; i < 10; i++) {
        usleep(rand() % 600000); // Simula tempo de processamento aleatório (em milissegundos)
        pthread_mutex_lock(&mutex);
        contador++;
        printf("Thread %ld: contador = %d\n", (long)arg, contador);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Inicializa o mutex
    pthread_mutex_init(&mutex, NULL);

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Cria as threads
    pthread_create(&t1, NULL, contar, (void *)1);
    pthread_create(&t2, NULL, contar, (void *)2);

    // Espera as threads terminarem
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroi o mutex
    pthread_mutex_destroy(&mutex);

    printf("Valor final do contador: %d\n", contador);
    return 0;
}
