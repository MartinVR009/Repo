#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
  int fd1[2], fd2[2]; // Definición de dos tuberías
  char input_str00[100], input_str01[100]; // Variables para almacenar las frases ingresadas por el usuario
  pid_t p; // Variable para almacenar el ID del proceso

  // Solicitar al usuario que ingrese dos frases
  printf("Ingrese primera frase (presione enter para continuar)\n");
  scanf("%s", input_str00);
  printf("Ingrese segunda frase (presione enter para continuar)\n");
  scanf("%s", input_str01);

  // Crear dos tuberías
  if ((pipe(fd1) == -1) || (pipe(fd2) == -1)) {
    fprintf(stderr, "Pipe Failed\n");
    return 1;
  }
  p = fork(); // Crear un nuevo proceso hijo

  if (p < 0) { // Si el fork falla
    fprintf(stderr, "fork Failed\n");
    return 1;
  }

  // Proceso del padre
  else if (p > 0) {
    char concat_str[100]; // Variable para almacenar la frase concatenada
    close(fd1[0]); // Cerrar el extremo de lectura de la primera tubería
    write(fd1[1], input_str01, strlen(input_str01) + 1); // Escribir la segunda frase en la primera tubería
    close(fd1[1]); // Cerrar el extremo de escritura de la primera tubería
    wait(NULL); // Esperar a que el proceso hijo termine
    close(fd2[1]); // Cerrar el extremo de escritura de la segunda tubería
    read(fd2[0], concat_str, 100); // Leer la frase concatenada desde la segunda tubería
    printf("String concatenado: %s\n", concat_str); // Imprimir la frase concatenada
    close(fd2[0]); // Cerrar el extremo de lectura de la segunda tubería
  }

  // Proceso del hijo
  else {
    close(fd1[1]); // Cerrar el extremo de escritura de la primera tubería
    char concat_str[100]; // Variable para almacenar la frase concatenada
    read(fd1[0], concat_str, 100); // Leer la segunda frase desde la primera tubería

    int k = strlen(concat_str), i; // Obtener la longitud de la cadena concatenada
    for (i = 0; i < strlen(input_str00); i++) {
      concat_str[k++] = input_str00[i]; // Concatenar la primera frase a la segunda frase
    }

    concat_str[k] = '\0'; // Agregar el carácter nulo al final de la cadena concatenada
    close(fd1[0]); // Cerrar el extremo de lectura de la primera tubería
    close(fd2[0]); // Cerrar el extremo de lectura de la segunda tubería
    write(fd2[1], concat_str, strlen(concat_str) + 1); // Escribir la cadena concatenada en la segunda tubería
    close(fd2[1]); // Cerrar el extremo de escritura de la segunda tubería

    exit(0); // Salir del proceso hijo
  }
  return 0; // Terminar el programa con éxito
}
