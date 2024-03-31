def main():
    direccion_inicial = actual_grado(input("Dirección Actual: "), "1")
    if direccion_inicial is not None:
        print(f"Dirección inicial: {direccion_inicial}")
        comando = input("Girando hacia (L/R/H/.): ")
        direccion_final = mirando(comando, direccion_inicial)
        if direccion_final is not None:
            print(f"Estamos mirando hacia el: {actual_grado(direccion_final, '2')}")
        else:
            print("Comando no válido.")
    else:
        print("Dirección no válida.")

def actual_grado(direccion, opcion):
    if opcion == "1":
        if direccion == "N":
            return 0
        elif direccion == "S":
            return 180
        elif direccion == "E":
            return 90
        elif direccion == "O":
            return 270
        else:
            return None
    elif opcion == "2":
        if direccion == 270:
            return "O"
        elif direccion == 180:
            return "S"
        elif direccion == 90:
            return "E"
        elif direccion == 0:
            return "N"
        else:
            return None

def mirando(dir, pos_ini):
    girar = 0
    if dir == "L":
        girar = -90
    elif dir == "R":
        girar = 90
    elif dir == "H":
        girar = 180
    elif dir == ".":
        girar = 0
    else:
        return None

    return cardinal_final(girar, pos_ini)

def cardinal_final(girar, inicial):
    dir = girar + inicial

    if dir > 360:
        return dir - 360
    elif dir < 0:
        return dir + 360
    else:
        return dir

main()