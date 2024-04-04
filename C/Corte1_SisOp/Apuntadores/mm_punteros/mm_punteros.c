#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

/*** Un valor constante global ***/
#define DATA_SIZE (1024 * 1024 * 64)

void initMatrices(int SZ, double *ptrMA, double *ptrMB, double *ptrMC) {
  for (int i = 0; i < SZ * SZ; i += SZ) {
    for (int j = 0; j < SZ; j++) {
      ptrMA[i + j] = 2.1 + i + j;
      ptrMB[i + j] = 1.1 + i + j;
      ptrMC[i + j] = 0.0 + i + j;
    }
  }
}

void imprimirMatriz(int SZ, double *ptr) {
  printf("__impresion matriz__\n");
  for (int i = 0; i < SZ * SZ; i += SZ) {
    for (int j = 0; j < SZ; j++) {
      printf(" %f ", ptr[i + j]);
    }
    printf("\n*****************************************************\n");
  }
  printf("\n*****************************************************\n");
}

/**Se reserva un espacio de memmoria muy grande**/
static double MEM_CHUNK[DATA_SIZE];

int main(int argc, char *argv[]) {
  int SZ;
  if (argc > 1) {
    SZ = atoi(argv[1]);
  } else {
    printf("Ingreso incorrecto de parametros");
    return 1;
  }

  /**Crear las matrices **/
  double *ptrMA = MEM_CHUNK;
  double *ptrMB = MEM_CHUNK;
  ptrMB = ptrMB + (SZ * SZ + 1);
  double *ptrMC = ptrMB + (SZ * SZ);

  /**inicializar matrices***/
  initMatrices(SZ, ptrMA, ptrMB, ptrMC);

  /**Impresion matriz**/
  imprimirMatriz(SZ, ptrMA);
  imprimirMatriz(SZ, ptrMB);
  imprimirMatriz(SZ, ptrMC);

  printf("Tamanio de Matriz[%d][%d] \n", SZ, SZ);

  return 0;
}

/*
int vector[tam];
int *ptr = vector;
for (int i = 0; i < tam; i++) {
  vector[i] = 3 * i + 2;
}
*/