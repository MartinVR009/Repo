#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

/*** Un valor constante global ***/
#define DATA_SIZE (1024 * 1024 * 64) // Tamaño del chunk de memoria

// Función para inicializar las matrices MA, MB y MC
void initMatrices(int SZ, double *ptrMA, double *ptrMB, double *ptrMC) {
  // Llena las matrices MA, MB y MC con valores específicos
  for (int i = 0; i < SZ * SZ; i += SZ) {
    for (int j = 0; j < SZ; j++) {
      ptrMA[i + j] = 2.1 + i + j; // Inicializa la matriz MA
      ptrMB[i + j] = 1.1 + i + j; // Inicializa la matriz MB
      ptrMC[i + j] = 0.0 + i + j; // Inicializa la matriz MC
    }
  }
}

// Función para imprimir una matriz
void imprimirMatriz(int SZ, double *ptr) {
  printf("__impresion matriz__\n");
  for (int i = 0; i < SZ * SZ; i += SZ) {
    for (int j = 0; j < SZ; j++) {
      printf(" %f ", ptr[i + j]); // Imprime los elementos de la matriz
    }
    printf("\n*****************************************************\n");
  }
  printf("\n*****************************************************\n");
}

/**Se reserva un espacio de memoria muy grande**/
static double MEM_CHUNK[DATA_SIZE]; // Declaración de un chunk de memoria estático

int main(int argc, char *argv[]) {
  int SZ;
  if (argc > 1) {
    SZ = atoi(argv[1]); // Lee el tamaño de la matriz desde la línea de comandos
  } else {
    printf("Ingreso incorrecto de parametros"); // Mensaje de error si no se proporciona el tamaño de la matriz
    return 1;
  }

  /**Crear las matrices **/
  double *ptrMA = MEM_CHUNK; // Puntero a la matriz MA
  double *ptrMB = MEM_CHUNK; // Puntero a la matriz MB
  ptrMB = ptrMB + (SZ * SZ + 1); // Desplaza el puntero para apuntar a la matriz MB
  double *ptrMC = ptrMB + (SZ * SZ); // Puntero a la matriz MC

  /**inicializar matrices***/
  initMatrices(SZ, ptrMA, ptrMB, ptrMC); // Inicializa las matrices MA, MB y MC

  /**Impresion matriz**/
  imprimirMatriz(SZ, ptrMA); // Imprime la matriz MA
  imprimirMatriz(SZ, ptrMB); // Imprime la matriz MB
  imprimirMatriz(SZ, ptrMC); // Imprime la matriz MC

  printf("Tamanio de Matriz[%d][%d] \n", SZ, SZ); // Imprime el tamaño de la matriz

  return 0; // Retorna 0 para indicar una ejecución exitosa
}
