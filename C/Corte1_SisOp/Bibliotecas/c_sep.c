/*Autor: Martin Vasquez
  Fecha: 1 febrero 2024
  Materia: Sistemas Operativos
  Tema: Introduccion a C
  Topico: Compilacion por separado */

#include "biblio.h"
#include <stdio.h>

int main() {
  float r = 12, a = 7.6f;
  printf(
      "El area del cilindro de radio: %f, altura: %f, tiene un area de: %f \n",
      r, a, areaCilindro(r, a));
  imprimirMatriz(10, 10);
  printf("Volumen de un cubo con lado: %f , es: %f \n", a, volCubo(a));

  return 0;
}