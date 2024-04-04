#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char *argv[]) {
  // Se verifica si se proporciona un argumento en la línea de comandos
  int tam;
  if (argc > 1) {
    tam = atoi(argv[1]); // Se convierte el argumento a un entero
  } else {
    return 1; // Si no se proporciona un argumento, se termina el programa con un código de error
  }
  
  int vector[tam]; // Se declara un vector de tamaño tam
  int *ptr = vector; // Se declara un puntero que apunta al inicio del vector
  printf("El tamanio es: %d \n", tam); // Se imprime el tamaño del vector
  
  // Se llena el vector con valores calculados
  for (int i = 0; i < tam; i++) {
    vector[i] = 3 * i + 2; // Cálculo del valor para el elemento i del vector
  }

  // Se imprime el contenido del vector
  for (int i = 0; i < tam; i++, ptr++) {
    printf("vector[%d] = %d \n", i, *ptr); // Se imprime el índice y el valor del elemento apuntado por ptr
  }
  
  ptr = vector; // Se reinicia el puntero al inicio del vector
  return 0; // Se termina el programa con éxito
}
