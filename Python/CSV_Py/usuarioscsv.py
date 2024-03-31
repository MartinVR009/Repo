import csv

datos = []

with open('rating_sql.csv', 'r', encoding='utf-8') as archivo_csv:
    lector_csv = csv.reader(archivo_csv)
    for fila in lector_csv:
        usuario = fila[3]
        nombre_usuario = ""
        edad = 0
        datos.append((usuario, nombre_usuario,edad))

with open('usuarios.csv', 'w',newline='',encoding='utf-8') as archivo_csv:
    escritor_csv = csv.writer(archivo_csv)
    escritor_csv.writerows(datos)