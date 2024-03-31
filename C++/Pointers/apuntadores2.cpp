#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int* sumaArreglos (int *arreglo1, int *arreglo2, int numElementos);

int main(int argc, char** argv) 
{
	int arreglo1[100];
	int arreglo2[100];
	int numE;
	int *ptr;
	
	cout <<"Ingrese la cantidad de elementos: ";
	cin >> numE;
	
	for(int i = 0; i < numE; i++)
	{
		cout << "Dato #" << i+1 << " arreglo1: ";
		cin >> arreglo1[i];
		cout << "Dato #" << i+1 << " arreglo2: ";
		cin >> arreglo2[i];
	}
	ptr = sumaArreglos(arreglo1, arreglo2, numE);
	
	for(int i = 0; i < numE; i++)
	{
		cout <<"DatoF: " << *ptr << endl;
		ptr++;
	}
}

int *sumaArreglos (int *arreglo1, int *arreglo2, int numElementos)
{
	static int resultado[100];
	int *ptr = resultado;
	
	for(int i = 0; i < numElementos; i++)
	{
		resultado[i] = *arreglo1 + *arreglo2;
		arreglo1++;
		arreglo2++;
	}
	
	return resultado;
	
}