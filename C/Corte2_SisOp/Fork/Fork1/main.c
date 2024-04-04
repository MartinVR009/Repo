#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int processID = fork(); // Se crea un nuevo proceso con fork()

  if (processID > 0) { // El valor de retorno de fork() es positivo en el proceso padre
    printf("fork() devuelve un valor +ve. Este es el padre, ID: %d \n", getpid()); // Se imprime el ID del proceso padre
  } else if (processID == 0) { // El valor de retorno de fork() es 0 en el proceso hijo
    printf("Proceso hijo ID: %d \n", getpid()); // Se imprime el ID del proceso hijo
  } else { // fork() devuelve un valor negativo si falla
    printf("fork() fallo \n"); // Se imprime un mensaje de fallo
  }

  printf("\n\n Imprimiendo ...\n");
  for (int i = 0; i < 5; i++)
    printf(" %d ", i); // Se imprime una secuencia de números del 0 al 4
  printf("\n Fin \n");

  return 0; // El programa termina con éxito
}
