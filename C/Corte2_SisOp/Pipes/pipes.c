#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MESSAGESIZE 16 // Tamaño máximo de los mensajes

char *mensaje1 = "Hola mundo, #1! \n"; // Primer mensaje
char *mensaje2 = "Hola mundo, #2! \n"; // Segundo mensaje
char *mensaje3 = "Hola mundo, #3! \n"; // Tercer mensaje

int main(int argc, char *argv[]) {
  char inbufer[MESSAGESIZE]; // Buffer para almacenar mensajes
  int p[2], i, temp;

  if (pipe(p) < 0) // Crea una tubería
    exit(1); // Sal del programa si falla la creación de la tubería

  // Escribe los mensajes en la tubería
  temp = write(p[1], mensaje1, MESSAGESIZE);
  temp = write(p[1], mensaje2, MESSAGESIZE);
  temp = write(p[1], mensaje3, MESSAGESIZE);

  // Lee los mensajes de la tubería y los imprime
  for (i = 0; i < 3; i++) {
    temp = read(p[0], inbufer, MESSAGESIZE); // Lee un mensaje desde la tubería
    printf("%s\n", inbufer); // Imprime el mensaje leído
  }

  return 0; // Termina el programa con éxito
}
