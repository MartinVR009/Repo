#include "header.h" // Incluye el archivo de encabezado header.h
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

struct timeval start, stop;

// Función para registrar el inicio del tiempo
void inicio_tiempo() { gettimeofday(&start, NULL); }

// Función para registrar el fin del tiempo y calcular el tiempo transcurrido
void fin_tiempo() {
  gettimeofday(&stop, NULL);
  stop.tv_sec -= start.tv_sec;
  printf("%9.0f µs\n", (double)(stop.tv_sec * 1000000 + stop.tv_usec));
}

// Función para imprimir una matriz
void impresionMatriz(int M[][SZ], int n, int si) {
  printf("Impresion Matriz #%d \n", n); // Imprime el número de la matriz
  for (int i = 0; i < SZ; i++) { // Recorre las filas de la matriz
    for (int j = 0; j < SZ; j++) { // Recorre las columnas de la matriz
      if (si == 1) { // Si se especifica la opción si
        printf(" %d [%d][%d]", M[i][j], i + 1, j + 1); // Imprime el elemento de la matriz con sus coordenadas
      } else {
        printf(" %d", M[i][j]); // Si no se especifica la opción si, solo imprime el elemento de la matriz
      }
    }
    printf("\n"); // Imprime un salto de línea al final de cada fila
  }
}

// Función para crear una matriz con valores aleatorios
void crearMatrizAleatoria(int matriz[][SZ]) {
  for (int i = 0; i < SZ; i++) { // Recorre las filas de la matriz
    for (int j = 0; j < SZ; j++) { // Recorre las columnas de la matriz
      matriz[i][j] = 1 + rand() % 7; // Asigna un valor aleatorio entre 1 y 7 al elemento de la matriz
    }
  }
}

// Función para multiplicar dos matrices
void multiplicarMatriz(int M1[][SZ], int M2[][SZ], int M3[][SZ]) {
  for (int i = 0; i < SZ; i++) { // Recorre las filas de la primera matriz
    for (int j = 0; j < SZ; j++) { // Recorre las columnas de la segunda matriz
      for (int k = 0; k < SZ; k++) { // Recorre las filas de la segunda matriz (o las columnas de la primera matriz)
        M3[i][j] = M3[i][j] + M1[i][k] * M2[k][j]; // Multiplica y suma los elementos correspondientes de las matrices
      }
    }
  }
}
