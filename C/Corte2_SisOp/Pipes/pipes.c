#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MESSAGESIZE 16
char *mensaje1 = "Hola mundo, #1! \n";
char *mensaje2 = "Hola mundo, #2! \n";
char *mensaje3 = "Hola mundo, #3! \n";

int main(int argc, char *argv[]) {
  char inbufer[MESSAGESIZE];
  int p[2], i, temp;

  if (pipe(p) < 0)
    exit(1);

  temp = write(p[1], mensaje1, MESSAGESIZE);
  temp = write(p[1], mensaje2, MESSAGESIZE);
  temp = write(p[1], mensaje3, MESSAGESIZE);

  for (i = 0; i < 3; i++) {
    temp = read(p[0], inbufer, MESSAGESIZE);
    printf("%s\n", inbufer);
  }
  return 0;
}