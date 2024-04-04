
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

struct timeval start, stop;

void inicio_tiempo() { gettimeofday(&start, NULL); }

void fin_tiempo() {
  gettimeofday(&stop, NULL);
  stop.tv_sec -= start.tv_sec;
  printf("%9.0f µs\n", (double)(stop.tv_sec * 1000000 + stop.tv_usec));
}

void impresionMatriz(int M[][SZ], int n, int si) {
  printf("Impresion Matriz #%d \n", n);
  for (int i = 0; i < SZ; i++) {
    for (int j = 0; j < SZ; j++) {
      if (si == 1) {
        printf(" %d [%d][%d]", M[i][j], i + 1, j + 1);
      } else {
        printf(" %d", M[i][j]);
      }
    }
    printf("\n");
  }
}

void crearMatrizAleatoria(int matriz[][SZ]) {
  for (int i = 0; i < SZ; i++) {
    for (int j = 0; j < SZ; j++) {
      matriz[i][j] = 1 + rand() % 7;
    }
  }
}

void multiplicarMatriz(int M1[][SZ], int M2[][SZ], int M3[][SZ]) {
  for (int i = 0; i < SZ; i++) {
    for (int j = 0; j < SZ; j++) {
      for (int k = 0; k < SZ; k++) {
        M3[i][j] = M3[i][j] + M1[i][k] * M2[k][j];
      }
    }
  }
}
