import csv

datos_csv1 = []
with open('nuevas_peliculas.csv', 'r', encoding='utf-8') as archivo_csv1: 
    lector_csv1 = csv.reader(archivo_csv1)
    for fila in lector_csv1:
        datos_csv1.append(fila)

valores_id_csv1 = set(fila[0] for fila in datos_csv1)

datos_csv2 = []
with open('RatingFiltrado.csv', 'r', encoding='utf-8') as archivo_csv2:
    lector_csv2 = csv.reader(archivo_csv2)
    for fila in lector_csv2:
        id_fila2 = fila[0]
        if id_fila2 in valores_id_csv1:
            datos_csv2.append(fila)
            print(f"{id_fila2} fila hallada")
            
with open('nuevo_rating.csv', 'w', newline='', encoding='utf-8') as archivo_coincidencias:
    escritor_csv = csv.writer(archivo_coincidencias)
    for fila in datos_csv2:
        escritor_csv.writerow(fila)
