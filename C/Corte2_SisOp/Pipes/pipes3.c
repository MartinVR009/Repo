#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int fd1[2];
  int fd2[2];

  char mensaje[] = "SistemasOperativos \n";
  char entrada[100];
  pid_t p;

  if (pipe(fd1) == -1) {
    fprintf(stderr, "Pipe fallo!");
    return -1;
  }

  if (pipe(fd2) == -1) {
    fprintf(stderr, "Pipe fallo!!");
    return -1;
  }

  scanf("%s", entrada);
  p = fork();
  if (p < 0) {
    fprintf(stderr, "fork fallo! ");
    return -1;
  }

  // Proceso Padre
  else if (p > 0) {
    char concat_str[100];
    close(fd1[0]);
    write(fd1[1], concat_str, 100);
    wait(NULL);
    close(fd2[1]);
    read(fd2[0], concat_str, 100);
    printf("Cadena concatenada %s\n", concat_str);
    close(fd2[0]);
  } else {
    close(fd1[1]);
    char concat_str[100];
    read(fd1[0], concat_str, 100);
    // Concatena una cadena fija
    int k = strlen(concat_str);
    int i;
    for (i = 0; i < strlen(entrada); i++) {
      concat_str[k++] = entrada[i];
    }
    concat_str[k] = '\0';

    close(fd1[0]);
    close(fd2[0]);

    write(fd1[1], concat_str, strlen(concat_str) + 1);
    close(fd1[1]);
  }

  return 0;
}