
juegos_devolver = ""

if edad > 18:
    juegos_devolver = j1["titutlo"] + ","+ j2["rating"] + "," + j3["rating"] + "," + j4["rating"]
elif 13 < edad < 18:
    if j1["rating"] != "M":
        juegos_devolver += j1 +" "
    if j2["rating"] != "M":
        juegos_devolver += j2 +" "
    if j3["rating"] != "M":
        juegos_devolver += j3 +" "
    if j4["rating"] != "M":
        juegos_devolver += j4 +" "
elif 10 < edad < 13:
    if j1["rating"] != "M" and j1["rating"] != "T":
        juegos_devolver += j1 +" "
    if j2["rating"] != "M" and j2["rating"] != "T":
        juegos_devolver += j2 +" "
    if j3["rating"] != "M" and j3["rating"] != "T":
        juegos_devolver += j3 +" "
    if j4["rating"] != "M" and j4["rating"] != "T":
        juegos_devolver += j4 +" "
elif edad < 10:
    if j1["rating"] != "M" and j1["rating"] != "T" and j1["rating"] != "E10+":
        juegos_devolver += j1 +" "
    if j2["rating"] != "M" and j2["rating"] != "T" and j2["rating"] != "E10+":
        juegos_devolver += j2 +" "
    if j3["rating"] != "M" and j3["rating"] != "T" and j3["rating"] != "E10+":
        juegos_devolver += j3 +" "
    if j4["rating"] != "M" and j4["rating"] != "T" and j4["rating"] != "E10+":
        juegos_devolver += j4 +" "

return juegos_devolver
