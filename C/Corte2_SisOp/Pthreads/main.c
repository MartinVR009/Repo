#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define  RUNTIME_SECONDS 5 // Definición de la duración de ejecución del hilo en segundos

void * thread_func(void *arg){
  pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL); // Desactiva la cancelación del hilo

  printf("Hilo en ejecución...\n"); // Mensaje indicando que el hilo está en ejecución

  for(int i = 0; i < RUNTIME_SECONDS; ++i){
    sleep(1); // Hace que el hilo duerma durante 1 segundo
    printf("Hilo en ejecución...\n"); // Mensaje indicando que el hilo está en ejecución (se imprime cada segundo)
  }

  printf("Fin de la ejecución...\n"); // Mensaje indicando que la ejecución del hilo ha terminado

  return NULL; // Retorna NULL al finalizar el hilo
}

int main(){
  pthread_t thread; // Declaración de la variable que representa el hilo

  pthread_create(&thread, NULL, thread_func, NULL); // Creación del hilo

  sleep(2); // Espera 2 segundos antes de intentar cancelar el hilo

  int cancel_status = pthread_cancel(thread); // Intenta cancelar el hilo
  if(cancel_status != 0){
    printf("Error al intentar cancelar el hilo %d\n", cancel_status); // Mensaje de error si la cancelación falla
  }else{
    printf("El hilo no pudo ser cancelado"); // Mensaje si la cancelación no tuvo éxito
  }

  if(pthread_join(thread, NULL)){ // Espera a que el hilo termine su ejecución
    printf("Error al esperar el hilo.\n"); // Mensaje de error si hay problemas al esperar el hilo
    return 1; // Retorna un valor de error
  }

  return 0; // Retorna 0 indicando que el programa se ha ejecutado correctamente
}
