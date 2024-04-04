/***** Captura de Tiempos ***********
Autor: John Corredor
Fecha: 6 febrero 2024
Materia: Sistemas Operativos
Pontificia Universidad Javeriana
Tema: Captura de tiempo de algoritmos
        - Multiplicación de Matrices
        - Creación de Makefile (compilación automatizada)
*************************************/
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>


int main() {
  srand(time(NULL));

  int matriz01[SZ][SZ];
  int matriz02[SZ][SZ];
  int matrizResultado[SZ][SZ];
  crearMatrizAleatoria(matriz01);
  crearMatrizAleatoria(matriz02);
  impresionMatriz(matriz01, 1, 0);
  impresionMatriz(matriz02, 2, 0);
  multiplicarMatriz(matriz01, matriz02, matrizResultado);
  impresionMatriz(matrizResultado, 3, 1);
  inicio_tiempo();
  fin_tiempo();
  return 0;
}