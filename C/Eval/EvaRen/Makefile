# **************************************************************
#
# ****************************************************************

# Variables
CC = gcc
CFLAGS = -Wall -lpthread
OBJ = functions.c
TARGETS = Fuente_Evaluacion mm_clasico mm_transpuesta

# Compilación por defecto
all: $(TARGETS)

# Reglas específicas para cada ejecutable
Fuente_Evaluacion: Fuente_Evaluacion.c $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

mm_clasico: mm_clasico.c $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

mm_transpuesta: mm_transpuesta.c $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

# Comandos para correr cada ejecutable
# Ejemplo: make run_Fuente_Evaluacion TAM=1024 HILOS=4
run_Fuente_Evaluacion:
	./Fuente_Evaluacion $(TAM) $(HILOS)

run_mm_clasico:
	./mm_clasico $(TAM) $(HILOS)

run_mm_transpuesta:
	./mm_transpuesta $(TAM) $(HILOS)

# Limpieza
clean:
	rm -f $(TARGETS)

.PHONY: all clean run_Fuente_Evaluacion run_mm_clasico run_mm_transpuesta
