#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_hello(void *thread_id) {
    long tid = (long)thread_id;
    printf("Hola desde el hilo %ld\n", tid);
    pthread_exit(NULL); 
}

int main() {
    pthread_t threads[NUM_THREADS]; 
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creando hilo %ld\n", t);
        
        rc = pthread_create(&threads[t], NULL, print_hello, (void *)t);
        if (rc) { 
            printf("Error al crear el hilo %ld; código de retorno: %d\n", t, rc);
            return 1; 
        }
    }

    pthread_exit(NULL); 
}