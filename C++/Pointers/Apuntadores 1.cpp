#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

char *reverse(char *cadena);

int main(int argc, char** argv) 
{
	char cadena[30];
	char *ptr;
	cout << "Ingrese una cadena: ";
	cin >> cadena;
	
	ptr = reverse(cadena);
	cout << "Inversa: " << *ptr;
}
char *reverse(char *cadena)
{
	char *char_ptr = cadena;
	static char inversa[30];
	int len = 0;
	int a = 0;
	while(*cadena != '\0')
	{
		cadena++;
		len++;
	}
	cadena--;
	for(int i = 0; i < len; i++)
	{
		inversa[i] = *cadena;
		cadena--;
	}
	cout << "Inversa FUNCION: " << inversa;
	inversa[len] = '\0';
	return inversa;
}
