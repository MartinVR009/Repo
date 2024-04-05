/****************************
Fecha : 4/04/2024
Autor: Martin Vasquez Ramirez
Materia: Sistemas Operativos
Tema: Concurrencia
Objetivo: hacer una metodologia para la implementacion de la multiplicacion de
matrices. La idea principal, es construir paso a paso la implementacion para
hacer uso de la biblioteca PTHREADS.Se implementa el algoritmo
clasico/tradicional de implementacion de matrices, para matrices cuadradas, es
decir, la dimension de filas es igual a la de columnas.
A continuacion se describen los pasos -Reserva de memoria
  -Creacion de punteros para matrices del tipo doble
  -Asignacion de memoria -Ingreso de argumentos de entrada (dimension
matriz numero de NH)
 -Inicializar matrices
 -Declaracion vector de NH
 -Creacion de NH segun tamaño de vector de NH
 -Crear estructura de datos que encapsulen los argumentos de entrada de la funcion MM
****************************/

// VERSION 2

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define RESERVA (1024 * 128 * 64 * 8)

struct datosMM{
  int SZ;
  int H;
  double *ptrMA, *ptrMB, *ptrMC;

};

static double MEM_CHUNK[RESERVA];

void initMatrices(int SZ, double *ptrMA, double *ptrMB, double *ptrMC) {
  // Llena las matrices MA, MB y MC con valores específicos
  for (int i = 0; i < SZ * SZ; i += SZ) {
    for (int j = 0; j < SZ; j++) {
      ptrMA[i + j] = 1.1 * (i + j); // Inicializa la matriz MA
      ptrMB[i + j] = 2.2 + (i + j); // Inicializa la matriz MB
      ptrMC[i + j] = i + j;         // Inicializa la matriz MC
    }
  }
}

void imprimirMatriz(int SZ, double *ptr) {
  for (int i = 0; i < SZ * SZ; i++) { 
    if (i % SZ == 0) { // Si se alcanza el inicio de una nueva fila
      printf("\n");
      for (int j = 0; j < SZ; j++) { // Se imprime, segun la cantidad de datos en una fila, una serie de "-" para impresion
        printf("------"); 
      }
      printf("\n"); // Imprime un salto de línea cada que se llega a una nueva fila
    }
    printf("|%.2f|", ptr[i]); // Imprime el elemento de la matriz con dos decimales de precisión y rodeado por barras verticales
  }
  printf("\n"); 
  for (int j = 0; j < SZ; j++) { // Imprime una línea horizontal final de la matriz
    printf("------"); 
  }
  printf("\n######################################\n"); // Imprime un mensaje de finalización
}


  void *multiplicarMatrices(void *argMM){
    double sumaTemp, *pA, *pB, *pC;

    for (int i = 0; i < SZ; i++) { // Itera sobre las filas 
      for (int j = 0; j < SZ; j++) { // Itera sobre las columnas 
          sumaTemp = 0.0; // reinicia la sumaTemp a 0
          pA = ptrMA + i * SZ; // Apunta al inicio de la matriz A
          pB = ptrMB + j; // Apunta a la columna j de la matriz B
          for (int k = 0; k < SZ; k++, pA++, pB += SZ) { // Itera de uno a uno los elementos de A y de modo columna los elementos de la matriz B
              sumaTemp += *pA * *pB; // Multiplica los elementos correspondientes y suma el resultado a la variable temporal
          }
          ptrMC[j + i * SZ] = sumaTemp; // Almacena el resultado en la matriz de resultado C en la posición (i, j)
      }
  }
}

int main(int argc, char *argv[]) {

  double *mA, *mB, *mC;
  double *matrices[3];
  int N, NH; // N representa las filas/columnas de las matrices dado que son
             // cuadradas
  if (argc > 2) { //Se verifica que se hayan recibido los 2 debidos argumentos 
    N = atoi(argv[1]); //Se convierte a entero el numero recibido para tamaño de matrices
    hilos = atoi(argv[2]); //Se convierte a entero el numero recibido para numero de hilos 
    if (N < 1 || hilos < 1) { //Verificacion que ambos datos sean mayores a 0
      printf("No se aceptan valores menores a 0\n");
      return 1; //Salida no exitosa
    }
  } else {
    printf("Se esperaban argumentos de entrada\n");
    return 1; //Salida no exitosa
  }


  pthread_t hilos[NH]; //Crea el vector de hilos

  mA = MEM_CHUNK;        // Puntero a la matriz MA
  mB = mA + (N * N + 1); // Desplaza el puntero para apuntar a la matriz MB
  mC = mB + (N * N);     // Puntero a la matriz MC

  initMatrices(N, mA, mB, mC);
  imprimirMatriz(N, mA);
  imprimirMatriz(N, mB);

  for (int h = 0; h < NH; h++) {
    pthread_create(hilos[h], NULL, multiplicarMatrices, &h);
  }

  multiplicarMatrices(N, mA, mB, mC);
  imprimirMatriz(N, mC);
  printf("Fin del programa \n");

  return 0;
}
