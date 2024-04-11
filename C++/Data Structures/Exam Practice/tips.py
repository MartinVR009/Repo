
def treeSum(root):
    if root is None:
        return 0
    else:
        leftSum = treeSum(root.left)
        rightSum = treeSum(root.right)
        return root.data + leftSum + rightSum
    
def treeMax(root):
    if root is None:
        return 0
    else:
        leftMax = treeMax(root.left)
        rightMax = treeMax(root.right)
        return max(root.data, leftMax, rightMax)

def treeHeight(root):
    if root is None:
        return 0
    else:
        leftHeight = treeHeight(root.left)
        rightHeight = treeHeight(root.right)
        return 1 + max(leftHeight, rightHeight)
    
def existsInTree(root, target):
    if root is None:
        return False
    else:
        inLeft = existsInTree(root.left.value)
        inRight = existsInTree(root.right.value)
        if root.value == target or root.value == inLeft or root.value == inRight:
            return True

#Path Related Problems, DFS

def dfs(root, path): # donde path sera nuestro "vector/arreglo de la ruta del nodo"
    if root is None:
        return False
    else:
        print(root.value)
        path.append(root)
        dfs(root.left, path)
        dfs(root.right, path)
        path.pop()

"""
El algoritmo funciona de la siguiente manera:
0.Se verifica el arbol
1. Se añade el nodo en el que estamos actualmente al path
2.se visita el nodo izquierdo /si es un arbol general se recorren de izquierda a derecha por simplicidad
3.se visita el nodo derecho con la funcion
4.se elimina el ultimo valor agregado
"""

#Getting a specific path

#Se utiliza el algoritmo de DFS simplemente que 
#se mueve en cuanto el valor este en alguno de los paths 
#devuelto por un hijo o estemos actualmente en el valor buscado

def lookDfs(root, path, target):
    if root is None:
        return
    else:
        path.append(root)
        if root.value == target or dfs(root.left, path, target) or dfs(root.right, path, target):
            return path
        path.pop()
        return 
    
def look_dfs(root, path, target, result):
    if root is None:
        return
    else:
        path.append(root)
        if root.value == target:
            result.append(path[:])  # Agregar una copia de la ruta actual
        look_dfs(root.left, path, target, result)
        look_dfs(root.right, path, target, result)
        path.pop()  # Eliminar el nodo actual de la ruta
