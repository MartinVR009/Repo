#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int processID = fork();

  if (processID > 0) {
    printf("fork() devuelve un valor +ve. Este es el padre, ID: %d \n",
           getpid());
  } else if (processID == 0) {
    printf("Proceso hijo ID: %d \n", getpid());

  } else {
    printf("fork() fallo \n");
  }
  printf("\n\n Imprimiendo ...\n");
  for (int i = 0; i < 5; i++)
    printf(" %d ", i);
  printf("\n Fin \n");

  return 0;
}