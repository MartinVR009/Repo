/*Autor: Martin Vasquez
  Fecha: 1 febrero 2024
  Materia: Sistemas Operativos
  Tema: Introduccion a C
  Topico: Compilacion por separado */

#include "biblio.h"
#include <stdio.h>

/*Funcion para imprimir en matriz */
void imprimirMatriz(int filas, int columnas) {
  int a = 0;
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      printf(" %i ", a++);
    }
    printf("\n");
  }
  printf("\n");
}

/*funcion para calcular area de un cilindro*/
float areaCilindro(float radio, float altura) {
  return 3.1415 * (radio * radio) * altura;
}

/*funcion para calcular volumen de un cubo*/
float volCubo(float a) { return a * a * a; }