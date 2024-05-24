#include "AVLNode.h"
#include "AVLTree.h"
#include "Library.h"
#include "cabeceras.h"
#include "wordTree.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

// Herramientas para limpiar pantalla y que sean portables
#ifdef _WIN32
#include <cstdlib>
#else
#include <unistd.h>
#endif

using namespace std;
Library systemLib;
dictionarys diccionarios;
const string red = "\033[31m";
const string reset = "\033[0m";

void limpiarConsola() {
#ifdef _WIN32
  int ret = system("cls");
  if (ret != 0) {
    std::cout << "Error!";
  }
#else
  // En Linux y sistemas tipo Unix
  int ret = system("clear");
  if (ret != 0) {
    std::cout << "Error!";
  }
#endif
}

void elegirFuncion(int n, string parametro) {

  switch (n) {
  // Configuración
  case 1:
    diccionarios.inicializar(parametro);
    // diccionarios.imprimir();
    break;
  case 2:
    diccionarios.inicializar_reverso(parametro);
    break;
    // Búsqueda
  case 3:
    diccionarios.puntaje(parametro);
    break;
  case 4:
    systemLib.iniciar_arbol(parametro);
    break;
  case 5:
    systemLib.iniciar_arbol_reverso(parametro);
    break;
  case 6:
    systemLib.prefijos(parametro);
    break;
  case 7:
    systemLib.sufijos(parametro);
    break;
  case 8:
    grafo_de_palabras();
    break;
  case 9:
    posibles_palabras();
    break;
  }
}

bool verificarParametro(const string &entrada) {

  istringstream stream(entrada);
  string palabra1, palabra2;

  // Intentar extraer dos palabras del flujo
  if (stream >> palabra1 && stream >> palabra2 && stream.eof()) {
    // cout<<"Correcto Formato \n";
    return true;
  } else {
    cout << red
         << "\nError en la entrada. El comando esta mal escrito y/o le hace "
            "falta un parametro.\n"
         << reset;
    return false;
  }
}

void seleccionarComandos(const string entrada, vector<comandos_struct> cmds,
                         string parametro) {

  if (entrada == "grafo_de_palabras") {
    elegirFuncion(8, parametro);
    return;
  }
  if (entrada.find("ayuda") != string::npos) {
    elegirFuncion(0, parametro);
    return;
  }

  size_t posicionEspacio = entrada.find(' ');

  if (verificarParametro(entrada)) {
    std::string comando = entrada.substr(0, posicionEspacio);
    int i = 1;
    bool aux = false;
    for (comandos_struct &v : cmds) {
      if (v.nombre == comando) {
        elegirFuncion(i, parametro);
        aux = true;
        return;
      }
      i++;
    }
    if (!aux) {
      cout << red
           << "\nError en la entrada. El comando esta mal escrito y/o le hace "
              "falta un parametro.\n"
           << reset;
    }
  }
}

void ayudaCompleta(const string entrada, const vector<comandos_struct> cmds) {

  if (entrada == "ayuda") {
    cout << "\nLos comandos disponibles dentro del programa son:\n\n";
    for (size_t i = 0; i < cmds.size(); ++i) {
      cout << i + 1 << ". " << cmds[i].nombre << "\n";
    }
    cout << "\n";
  } else {
    string comandoBuscado = entrada.substr(6);
    bool encontrado = false;
    for (const comandos_struct &o : cmds) {
      if (o.nombre == comandoBuscado) {
        cout << o.descripcion << endl;
        encontrado = true;
        break;
      }
    }
    if (!encontrado) {
      cout << red << "\nNo se encontro el comando especificado\n" << reset;
    }
  }
}
