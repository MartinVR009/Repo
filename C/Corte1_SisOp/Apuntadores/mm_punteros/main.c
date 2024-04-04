#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char *argv[]) {

  int tam;
  if (argc > 1) {
    tam = atoi(argv[1]);
  } else {
    return 1;
  }
  int vector[tam];
  int *ptr = vector;
  printf("El tamanio es: %d \n", tam);
  // Se llena el vector
  for (int i = 0; i < tam; i++) {
    vector[i] = 3 * i + 2;
  }

  // Se imprime
  for (int i = 0; i < tam; i++, ptr++) {
    printf("vector[%d] = %d \n", i, *ptr);
  }
  ptr = vector;
  return 0;
}