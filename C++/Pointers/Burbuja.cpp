 #include <stdio.h>
 #include <iostream>
 
 #define tam 8
 using namespace std;
 void ordenar(int *arreglo, int n);
 void intercambiar(int *p1, int *p2);
 main(){
 	
 	int i, arreglo[tam] ={10,2,6,89,12,43,1,23};
 	
 	cout <<"Arreglo sin ordenar \n";
 	for (int j=0; j<tam;j++){
 		cout <<"["<<arreglo[j]<<"]";
	 }
	 cout <<endl;

	ordenar (arreglo,tam);

	cout <<"Arreglo ordenado \n";
 	for (int j=0; j<tam;j++){
 		cout <<"["<<arreglo[j]<<"]";
	 }
	 cout <<endl;	 
	 	
	 
 	
 }
 
 void ordenar(int *arreglo, int n){
 	
 	int x,y;
 	
 	for (x=0;x<n;x++){
 		for (y=x+1;y<n;y++){
 			if (arreglo[x]>arreglo[y]){
 				intercambiar(&arreglo[x],&arreglo[y]);
 				cout<<"-->";	
 				for (int x=0; x<tam;x++)
 					cout <<"["<<arreglo[x]<<"]";
 				cout<< endl;
			 }
		 }
	 }
 	
 	
 	
 }
 
 void intercambiar(int *p1, int *p2)
 {
 	int aux;
 	aux=*p1;
 	*p1=*p2;
 	*p2=aux;
 	
 }