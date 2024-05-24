
#ifndef MONITOR_H
#define MONITOR_H

#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_MAX 100

typedef struct {
  float buf[BUFFER_MAX];
  int in;
  int out;
  sem_t full;
  sem_t empty;
  sem_t mutex;
} sbuf_t;

extern int BUFFER_SIZE;

void InicializarBuffers();
void LiberarBuffers();
void *Recolector(void *arg);
void *HiloTemp();
void *HiloPh();
void EjecutarMonitor(int argc, char *argv[]);
void *HiloFuera();

#endif // MONITOR_H
