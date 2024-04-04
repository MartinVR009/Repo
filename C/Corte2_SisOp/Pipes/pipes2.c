#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define MESSAGESIZE 16 // Definición del tamaño máximo de los mensajes

char *mensaje1 = "Hola mundo, #1! \n"; // Definición de mensaje 1
char *mensaje2 = "Hola mundo, #2! \n"; // Definición de mensaje 2
char *mensaje3 = "Hola mundo, #3! \n"; // Definición de mensaje 3

int main(int argc, char *argv[]) {
  char inbuffer[MESSAGESIZE]; // Buffer de entrada para almacenar los mensajes recibidos
  int p[2], i, temp, nbytes, pid;

  if (pipe(p) < 0) // Creación de la tubería
    exit(1); // Salida del programa en caso de error

  if ((pid = fork()) > 0) { // Proceso padre
    temp = write(p[1], mensaje1, MESSAGESIZE); // Envío del mensaje 1 a través de la tubería
    temp = write(p[1], mensaje2, MESSAGESIZE); // Envío del mensaje 2 a través de la tubería
    temp = write(p[1], mensaje3, MESSAGESIZE); // Envío del mensaje 3 a través de la tubería
    wait(NULL); // Espera a que el proceso hijo termine
  } else { // Proceso hijo
    while ((nbytes = read(p[0], inbuffer, MESSAGESIZE)) > 0) // Lectura de los mensajes desde la tubería
      printf("%s\n", inbuffer); // Impresión de los mensajes recibidos
    if (nbytes != 0) // Si ocurre un error durante la lectura
      exit(2); // Salida del programa con un código de error
    printf("Finished reading \n"); // Mensaje indicando que la lectura ha terminado
  }
  
  return 0; // Fin del programa
}
