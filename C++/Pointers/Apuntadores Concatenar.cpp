#include <iostream>
using namespace std;

int longitud  (char *cad){
	int l=0;
	while (*cad!='\0'){
		l++;
		cad++;
	}
	return l;
}

char *concatenar (char *cad1, char *cad2){

	
	
	//char *aux = (char*) malloc(50); //(tipoDato *)malloc(tamano)
	static char aux[50]; //En este caso no se devuelve la direccion de memoria del arreglo
	//int *aux2 = (int*) malloc(50); Devolver un arreglo de enteros
	//static int aux2[50]; //Devolver un arreglo de enteros
	
	strcpy(aux,cad1);
	cout <<"Pasando el valor de cad1 a aux: "<<aux<<endl;
	int l =longitud(cad1);
	while (*cad2!='\0'){
		//cad1[l]=*cad2;
		aux[l]=*cad2;
		l++;
		cad2++;
	}
	aux[l]='\0';
	//cad1[l]='\0';
   //cout <<"Despues concatenar el resultado en  cad1:"<<cad1<<" dir mem:"<<&cad1<<endl;
   cout <<"Despues concatenar el resultado en aux:"<<aux<<" dir mem:"<<&aux<<endl;
	
	return aux;	
}

int main(){
	char cadena1[50];
	char cadena2[50];
	cout <<"Ingrese una cadena de caracteres:";
	cin.getline(cadena1,50);
	cout <<"Ingrese otra cadena cadena de caracteres:";
	cin.getline(cadena2,50);
	
	//char *x=concatenar (cadena1,cadena2);
	char *x=concatenar (cadena1,cadena2);	
	cout <<"Cadenas concatenadas en X: "<< x<< " dir mem X:"<<&x <<endl;
	cout <<"Cadena1: "<< cadena1<<endl;
	return 0;
}