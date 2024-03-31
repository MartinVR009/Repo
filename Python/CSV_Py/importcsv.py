import csv
import random   

datos = []

with open('DescripcionPeliculas.csv', 'r', encoding='utf-8') as archivo_csv:
    lector_csv = csv.reader(archivo_csv)
    for fila in lector_csv:
        datos.append(fila)

registros_al_azar = random.sample(datos, 200)

with open('nuevo_archivo.csv', 'w', newline='', encoding='utf-8') as archivo_nuevo:
    escritor_csv = csv.writer(archivo_nuevo)
    escritor_csv.writerows(registros_al_azar)

