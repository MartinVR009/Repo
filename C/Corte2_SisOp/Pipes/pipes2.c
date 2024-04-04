#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define MESSAGESIZE 16
char *mensaje1 = "Hola mundo, #1! \n";
char *mensaje2 = "Hola mundo, #2! \n";
char *mensaje3 = "Hola mundo, #3! \n";

int main(int argc, char *argv[]) {
  char inbufer[MESSAGESIZE];
  int p[2], i, temp, nbytes, pid;

  if (pipe(p) < 0)
    exit(1);

  if ((pid = fork()) > 0) {
    temp = write(p[1], mensaje1, MESSAGESIZE);
    temp = write(p[1], mensaje2, MESSAGESIZE);
    temp = write(p[1], mensaje3, MESSAGESIZE);
    wait(NULL);
  } else {
    while ((nbytes = read(p[0], inbufer, MESSAGESIZE)) > 0)
      printf("%s\n", inbufer);
    if (nbytes != 0)
      exit(2);
    printf("Finished reading \n");
  }
  
  return 0;
}