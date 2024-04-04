#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define  RUNTIME_SECONDS 5

void * thread_func(void *arg){
  pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);

  printf("Hilo en ejecucion...\n");

  for(int i = 0; i < RUNTIME_SECONDS; ++i){
    sleep(1);
    printf("Hilo en ejecucion...\n");
  }

  printf("Fin de la ejecucion...\n");

  return NULL;
}

int main(){
  pthread_t thread;

  pthread_create(&thread, NULL, thread_func, NULL);
  sleep(2);

  int cancel_statuc = pthread_cancel(thread);
  if(cancel_statuc != 0){
    printf("Error al intentar cancelar el hilo %d\n", cancel_statuc);
  }else{
    printf("El hilo no pudo ser cancelado");
  }

  if(pthread_join(thread, NULL)){
    printf("Error al esperar el hilo.\n");
    return 1;
  }

  return 0;
}