#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int cadeiras = 1;
int qtdcadeiras = 10;

void *vendas(void *args) {
  int num = *(int *)args;
  printf("Cliente %d: em atendimento\n", num);
  sleep(rand() % 10);
  if (cadeiras < 11) {
    printf("Cliente %d finalizou a compra da cadeira %d\n", num, cadeiras);
    cadeiras++;
  } else
    printf("Cliente %d ficou sem cadeira\n", num);
  return NULL;
}

int main(void) {
  pthread_t threads[15];
  for (int i = 0; i < 15; i++) {
    pthread_create(&threads[i], NULL, vendas, (void *)&i);
  }
  sleep(10);
  return 0;
}