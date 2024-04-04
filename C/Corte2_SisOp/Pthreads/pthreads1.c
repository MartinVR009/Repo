#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5 // Definición del número de hilos a crear

void *print_hello(void *thread_id) {
    long tid = (long)thread_id; // Se obtiene el identificador del hilo
    printf("Hola desde el hilo %ld\n", tid); // Se imprime un mensaje con el identificador del hilo
    pthread_exit(NULL); // Se termina el hilo
}

int main() {
    pthread_t threads[NUM_THREADS]; // Declaración de un arreglo de identificadores de hilos
    int rc; // Variable para almacenar el código de retorno de pthread_create
    long t; // Variable para el identificador del hilo

    for (t = 0; t < NUM_THREADS; t++) { // Bucle para crear los hilos
        printf("Creando hilo %ld\n", t); // Se imprime un mensaje indicando que se está creando un hilo
        
        rc = pthread_create(&threads[t], NULL, print_hello, (void *)t); // Se crea un hilo con pthread_create
        if (rc) { // Si hay un error al crear el hilo
            printf("Error al crear el hilo %ld; código de retorno: %d\n", t, rc); // Se imprime un mensaje de error
            return 1; // Se sale del programa con un código de retorno de error
        }
    }

    pthread_exit(NULL); // Se termina el hilo principal
}
