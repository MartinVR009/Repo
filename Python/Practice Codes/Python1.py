my_list = list([1,2,33,45,646,124,35,534])

for num in enumerate(my_list):
    result = num[0]
    value = num[1]
    print(f"El valor es:{value} y el indice es {result}" )

print("Ahora con Range")
for i in range(len(my_list)):
    print(f"El valor es: {my_list[i]}" )



