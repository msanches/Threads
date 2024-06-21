#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int contador = 0;

void *contar(void *arg) {
    for (int i = 0; i < 10; i++) {
        int temp = contador;
        usleep(rand() % 600000); // Simula tempo de processamento aleatório (até 600 milissegundos)
        contador = temp + 1;
        printf("Thread %ld: contador = %d\n", (long)arg, contador);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Cria as threads
    pthread_create(&t1, NULL, contar, (void *)1);
    pthread_create(&t2, NULL, contar, (void *)2);

    // Espera as threads terminarem - faz o sincronismo com a thread principal
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Simula tempo de processamento aleatório (thread principal)
    //usleep(rand() % 120000000000); 
    
    printf("Valor final do contador: %d\n", contador);

    return 0;
}
