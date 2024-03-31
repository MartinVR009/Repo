expression = input("Insert your expression: ")
x,y,z = expression.split(" ")

x = int(x)
z = int(z)
    
if y == "+" :
    y = x+z
elif y == "-":
    y = x-z
elif y == "*":
    y = x*z
else:
    y = x/z

print(y)


