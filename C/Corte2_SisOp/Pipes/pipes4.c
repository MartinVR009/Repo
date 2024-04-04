#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
  int fd1[2], fd2[2];
  char input_str00[100], input_str01[100];
  pid_t p;

  printf("Ingrese primera frase (enter para continuar)\n");
  scanf("%s", input_str00);
  printf("Ingrese segunda frase (enter para continuar)\n");
  scanf("%s", input_str01);

  if ((pipe(fd1) == -1) || (pipe(fd2) == -1)) {
    fprintf(stderr, "Pipe Failed\n");
    return 1;
  }
  p = fork();

  if (p < 0) {
    fprintf(stderr, "fork Failed\n");
    return 1;
  }

  // Proceso del padre

  else if (p > 0) {
    char concat_str[100];
    close(fd1[0]);
    write(fd1[1], input_str01, strlen(input_str01) + 1);
    close(fd1[1]);
    wait(NULL);
    close(fd2[1]);
    read(fd2[0], concat_str, 100);
    printf("String concatenado: %s\n", concat_str);
    close(fd2[0]);
  }// Proceso del hijo
  else {
    close(fd1[1]);
    char concat_str[100];
    read(fd1[0], concat_str, 100);

    int k = strlen(concat_str), i;
    for (i = 0; i < strlen(input_str00); i++) {
      concat_str[k++] = input_str00[i];
    }

    concat_str[k] = '\0';
    close(fd1[0]);
    close(fd2[0]);
    write(fd2[1], concat_str, strlen(concat_str) + 1);
    close(fd2[1]);

    exit(0);
  }
  return 0;
}