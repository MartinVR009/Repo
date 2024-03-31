import csv
import random   
import datetime


datos = []
with open('nuevo_rating.csv', 'r', encoding='utf-8') as archivo_csv:
    lector_csv = csv.reader(archivo_csv)
    next(lector_csv)  
    for fila in lector_csv:
        movie_id = fila[0]
        rating = float(fila[1])
        timestamp = int(fila[2])
        user_id = fila[3]
        fecha_hora = datetime.datetime.fromtimestamp(timestamp)

        datos.append((movie_id, rating, fecha_hora, user_id))

nuevos_datos = random.sample(datos, 2000)

with open('rating_sql.csv', 'w',newline='',encoding='utf-8') as archivo_csv:
    escritor_csv = csv.writer(archivo_csv)
    escritor_csv.writerows(nuevos_datos)

