CC = gcc

all: sensor monitor main

sensor: sensor.c
	$(CC) $@.c -o $@

monitor: monitor.c
	$(CC) $@.c -o $@

clear:
	rm -f phA.txt temp.txt

clean:
	rm -f sensor monitor main
