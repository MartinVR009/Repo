#include <stdlib.h>
#include <string.h>
#include <unistd.h>

 int main(void) {
  pid_t c_pid = fork();
  if (c_pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (c_pid == 0) {
    printf("printed from child process - %d\n", getpid());
    exit(EXIT_SUCCESS);
  } else {
    printf("printed from parent process - %d\n", getpid());
    wait(NULL);
  }

  exit(EXIT_SUCCESS);
}
