matrizMulti.c es un simple programa de C con las funcionalidades principales de: crear una matriz de N*N de datos aleatorios de 1 a 7, donde finalmente crea una matriz resultado de la multiplicacion de matrices de las primeras matrices creadas aleatorias:

las funciones para el funcionamiento de matriz son:

void impresionMatriz(int M[][SZ], int n, int si); que cuenta con 3 parametros, la matriz a imprimir, un entero n para mostrar que matriz fue creada en caso de impresion limpia, y un entero bandera "si" encargado de que si es == 1 muestra la matriz de manera: 67 [1][1] 35 [1][2] 43 [1][3] 99 [2][1] 53 [2][2] 49 [2][3] 68 [3][1] 36 [3][2] 42 [3][3] para ver el dato de matriz en que posicion matricial i,j esta ubicada, o cualquier otro entero != 1 para impresion normal: 6 3 3 7 4 2 4 2 4

void crearMatrizAleatoria(int matriz[][SZ]); Esta funcion recibe como parametro una matriz para llenarla de manera aleatoria con numeros del 1 al 7.

void multiplicarMatriz(int M1[][SZ], int M2[][SZ], int M3[][SZ]); Esta funcion recibe 3 matrices, las matrices de enteros M1 y M2 son las matrices a multiplicar de forma A*B mientras que la matriz M3 guarda el resultado de la multiplicacion, de manera que pueda guardarse en una variable para su uso.

Finalmente el programa cuenta con 2 funciones adicionales: void inicio_tiempo(); void fin_tiempo();

donde inicio_tiempo() se encarga de inicialmente tomar la hora del dia a la que se ejecuto el programa.

fin_tiempo() es una funcion encargada de tomar el tiempo de ejecucion del programa, donde resta el momento donde se inicio el programa hasta que acaba, mostrando el resultado final de tiempo en medidas de µs millonesimas de segundo.

Para la ejecucion correcta del programa, escriba en su shell el siguiente comando:

gcc matrizMulti.c functions.c -o test el cual creara un archivo ejecutable llamado test, este puede cambiar el nombre simplemente cambiando test por su nombre de gusto
y finalmente para ejecutarlo

./test
Autor: Martin Vasquez Ramirez

El algoritmo de multiplicacion de matrices fue tomado de: AlgoritmosUrgentes.com. (s. f.). Multiplicación de matrices. https://algoritmosurgentes.com/algoritmo-complejo-en-pseudocodigo-pseint/multiplicacion-de-matrices