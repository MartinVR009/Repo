#include "cabeceras.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <cstdlib>
#else
#include <unistd.h>
#endif

using namespace std;

// Permite cambiar de color la salida de texto en consola y es portable
const string yellow = "\033[33m";
const string green = "\033[32m";
const string reset = "\033[0m";
const string red = "\033[31m";

vector<comandos_struct> cmds{
    {"inicializar",
     "Inicializa el sistema a partir del archivo diccionario.txt. \nDebe "
     "recibir un parametro parametro: el nombre del archivo con "
     "extension.\nEjemlo: inicializar diccionario.txt ",
     1},
    {"iniciar_inverso",
     "A diferencia del comando inicializar, este comando almacena las palabras "
     "en sentido inverso. \nDebe recibir un parametro: el nombre del archivo "
     "con su extension.\nEjemplo: iniciar_inverso diccionario.txt",
     2},
    {"puntaje",
     "Permite conocer la puntuacion que puede obtenerse con una palabra dada. "
     "\nDebe recibir un parametro: la palabra que desea conocer su "
     "puntaje.\nEjemplo: puntaje palabra",
     3},
    {"iniciar_arbol",
     "Inicializa el sistema a apartir del archivo diccionario.txt, ademas "
     "almacena las palabras en uno o mas arboles de letras. \nDebe recibir un "
     "Parametro: el archivo von su respectiva extension.\nEjemplo: "
     "iniciar_arbol diccionario.txt",
     4},
    {"iniciar_arbol_inverso",
     "Almacena las palabras en uno o mas arboles de letras pero en sentido "
     "inverso. \nDebe recibir como parametro: el archivo von su respectiva "
     "extension.\nEjemplo: iniciar_arbol_inverso diccionario.txt ",
     5},
    {"palabras_por_prefijo",
     "Realiza un recorrido de los arboles de letras para ubicar todas las "
     "palabras posibles a construir apartir del prefijo indicado, \nse le "
     "presenta al usuario todas las posibles palabras, longitud de cada una y "
     "la putuacion que cada una puede obtener \nDebe recibir como parametro El "
     "prefijo.\nEjemplo:palabras_por_prefijo prefijo",
     6},
    {"palabras_por_sufijo",
     "Realiza un recorrido de los arboles de letras para ubicar todas las "
     "palabras posibles a construir apartir del sufijo indicado, \\nse le "
     "presenta al usuario todas las posibles palabras, longitud de cada una y "
     "la putuacion que cada una puede obtener \nDebe recibir como parametro: "
     "El sufijo.\nEjemplo:palabras_por_sufijo sufijo",
     7},
    {"grafo_de_palabras",
     "Con base a las palabras almacenas en el diccionario, se construye un "
     "grafo de palabras, en donde cada palabra se conecta a las demas si y "
     "solo si difieren en una unica palabra. No tiene parametros.\nEjemplo: "
     "grafo_de_palabras",
     8},
    {"posibles_palabras",
     "Presenta en pantalla todas las palabras posibles a construir. \n recibe "
     "como parametro una palabra conformada con las letras a calcular sus "
     "posibles palabras.\nEjemplo: posibles_palabras letras",
     9},
    {"ayuda",
     "Lista los comandos disponibles y puede recibir o no un comando. \nSi "
     "escribe el nombre del comando después de ayuda, recibe una descripion "
     "más específica.\nEjemplo: ayuda o ayuda comando",
     0},
    {"salir", "Finaliza el programa. \n No recibe parametro.\nEjemplo: salir",
     11}};

int main() {

  string entrada;
  string comando, parametro;
  limpiarConsola();
  string ayudaprueba;
  int i = 1;

  cout << yellow << " __                _     _     _       " << endl;
  cout << "/ _\\ ___ _ __ __ _| |__ | |__ | | ___  " << endl;
  cout << "\\ \\ / __| '__/ _` | '_ \\| '_ \\| |/ _ \\ " << endl;
  cout << "_\\ \\ (__| | | (_| | |_) | |_) | |  __/ " << endl;
  cout << "\\__/\\___|_|  \\__,_|_.__/|_.__/|_|\\___| " << endl;
  cout << "                                       " << endl;
  cout << green << "Bienvenido al sistema de apoyo para el juego scrabble \n"
       << reset;

  while (true) {
    cout << green << "\n$" << reset;
    getline(cin, entrada);
    stringstream str(entrada);

    // Limpia las variables para que no retengan los valores por el ciclo
    comando.clear();
    parametro.clear();

    getline(str, comando, ' ');
    getline(str, parametro);

    if (comando == "salir") {
      cout << red << "\nSaliendo del programa...\n" << reset;
      break;
    }
    if (comando == "ayuda") {
      if (parametro.empty()) {
        ayudaCompleta("ayuda", cmds);
      } else {
        ayudaCompleta("ayuda " + parametro, cmds);
      }
    } else {
      seleccionarComandos(entrada, cmds, parametro);
    }
    if (comando == "clear") {
#ifdef _WIN32
      int ret = system("cls");
#else
      // En Linux y sistemas tipo Unix
      int ret = system("clear");
#endif
      cout << yellow << " __                _     _     _       " << endl;
      cout << "/ _\\ ___ _ __ __ _| |__ | |__ | | ___  " << endl;
      cout << "\\ \\ / __| '__/ _` | '_ \\| '_ \\| |/ _ \\ " << endl;
      cout << "_\\ \\ (__| | | (_| | |_) | |_) | |  __/ " << endl;
      cout << "\\__/\\___|_|  \\__,_|_.__/|_.__/|_|\\___| " << endl;
      cout << "                                       " << endl;
      cout << green
           << "Bienvenido al sistema de apoyo para el juego scrabble \n"
           << reset;
    }
  }

  return 0;
}

/*
 * Ingresa
 * entrada ==ayuda || grafo_palabras
 * grafo_palabras()
 * ayuda VerificarComando si es true, mostrarAyuda, si es false,
 * imprimirComandos else VerificarComando
 * *
 *
 */
