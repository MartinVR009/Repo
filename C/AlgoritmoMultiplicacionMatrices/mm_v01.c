/****************************
Fecha : 4/04/2024
Autor: Martin Vasquez Ramirez
Materia: Sistemas Operativos
Tema: Concurrencia
Objetivo: hacer una metodologia para la implementacion de la multiplicacion de
matrices. La idea principal, es construir paso a paso la implementacion para
hacer uso de la biblioteca PTHREADS.Se implementa el algoritmo
clasico/tradicional de implementacion de matrices, para matrices cuadradas, es
decir, la dimension de filas es igual a la de columnas. A continuacion se
describen los pasos -Reserva de memoria -Creacion de punteros para matrices del
tipo doble -Asignacion de memoria -Ingreso de argumentos de entrada (dimension
matriz numero de hilos)
****************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define RESERVA (1024 * 128 * 64 * 8)

static double MEM_CHUNK[RESERVA];

int main(int argc, char *argv[]) {

  double *mA, *mB, *mC;
  int N, hilos; // N representa las filas/columnas de las matrices dado que son
                // cuadradas
  if (argc > 3) {
    if (N < 1 || hilos < 1) {
      printf("No se aceptan valores menores a 0\n");
      return 1;
    }
    N = atoi(argv[1]);
    hilos = atoi(argv[2]);
  } else {
    printf("Se esperaban argumentos de entrada\n");
    return 1;
  }

  mA = MEM_CHUNK;        // Puntero a la matriz MA
  mB = mA + (N * N + 1); // Desplaza el puntero para apuntar a la matriz MB
  mC = mB + (N * N);     // Puntero a la matriz MC

  printf("Fin del programa \n");

  return 0;
}