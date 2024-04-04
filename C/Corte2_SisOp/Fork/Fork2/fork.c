#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
  pid_t c_pid = fork(); // Se crea un nuevo proceso con fork()

  if (c_pid == -1) { // Si fork() devuelve -1, indica un error
    perror("fork"); // Se imprime el mensaje de error asociado a la función fork()
    exit(EXIT_FAILURE); // Se sale del programa con un estado de fallo
  }

  if (c_pid == 0) { // Si fork() devuelve 0, indica que este es el proceso hijo
    printf("printed from child process - %d\n", getpid()); // Se imprime el ID del proceso hijo
    exit(EXIT_SUCCESS); // Se sale del proceso hijo con un estado de éxito
  } else { // Si fork() devuelve un valor diferente de 0, indica que este es el proceso padre
    printf("printed from parent process - %d\n", getpid()); // Se imprime el ID del proceso padre
    wait(NULL); // El proceso padre espera a que el proceso hijo termine
  }

  exit(EXIT_SUCCESS); // Se sale del programa con un estado de éxito
}
