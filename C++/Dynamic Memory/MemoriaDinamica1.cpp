#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Persona
{
	char nombre[50];
	char direccion[50];
	float sueldo;
	int edad;
};

void llenar(Persona *persona, int registros);
void mostrar(Persona *persona, int registros);

int main(int argc, char** argv) 
{
	int n;
	cout << "ingrese el numero de registros: ";
	cin >> n;
	fflush(stdin);
	
	Persona *persona = new Persona[n];
	
	llenar(persona, n);
	mostrar(persona, n);
	delete persona;
	
	
}

void llenar(Persona *persona, int registros)
{
	for(int i = 0; i < registros; i++)
	{
		cout << "Datos Persona Nro:" << i+1 << endl;
		cout <<"Ingrese el nombre: ";
		cin.getline(persona->nombre, 50);
		cout <<"Ingrese la direccion: ";
		cin.getline(persona->direccion, 50);
		cout <<"Ingrese el sueldo: ";
		cin >>persona->sueldo;
		fflush(stdin);
		cout <<"Ingrese la edad: ";
		cin >>persona->edad;
		fflush(stdin);
		persona++;
	}
}
void mostrar(Persona *persona, int registros)
{
	for(int i = 0; i < registros; i++)
	{
		cout << "Datos Persona Nro:" << i+1 << endl;
		cout <<"Nombre: " << persona->nombre << endl;
		cout <<"Direccion: " << persona->direccion << endl;
		cout <<"Sueldo: " << persona->sueldo << endl;
		cout <<"Edad: " << persona->edad <<endl;
		persona++;
	}
}