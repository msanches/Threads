#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int cadeiras = 1;
int qtdcadeiras = 10;
pthread_mutex_t mutex;

void *vendas(void *args) {
  int num = *(int *)args;
  printf("Cliente %d: em atendimento\n", num);
  sleep(rand() % 10);

  pthread_mutex_lock(&mutex); // Bloqueia o mutex antes de acessar cadeiras
  if (cadeiras <= qtdcadeiras) {
    printf("Cliente %d finalizou a compra da cadeira %d\n", num, cadeiras);
    cadeiras++;
  } else {
    printf("Cliente %d ficou sem cadeira\n", num);
  }
  pthread_mutex_unlock(&mutex); // Desbloqueia o mutex após acessar cadeiras

  return NULL;
}

int main(void) {
  pthread_mutex_init(&mutex, NULL); // Inicializa o mutex

  pthread_t threads[15];
  int args[15];

  for (int i = 0; i < 15; i++) {
    args[i] = i + 1; // Passa um valor único para cada thread
    //cria múltiplas threads, cada uma representando uma venda de ingresso
    pthread_create(&threads[i], NULL, vendas, (void *)&args[i]);

  }

  for (int i = 0; i < 15; i++) {
    pthread_join(threads[i], NULL); // Espera todas as threads terminarem
  }

  pthread_mutex_destroy(&mutex); // Destroi o mutex
  return 0;
}