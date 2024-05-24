#include "graph.h" // Include the header file containing your Graph class
#include <iostream>
#include <utility>
#include <cmath>
#include <fstream>

using DataPair = std::pair<std::pair<float, float>, std::pair<float, float>>;

double calcularDistancia(double x1, double y1, double x2, double y2);
void crearAristas(Graph<std::pair<float, float>> &printer);
void leerArchivo(std::string nombreArchivo, Graph<std::pair<float, float>> &printer, int &n, int &m);

int main(int argc, char* argv[]) {
    // Create a graph
    Graph<std::pair<float, float>> printer;

    int n; //Numero de circuitos a perforar
    int m; //Numero de agujeros del circuito i = 0
    std::string nombre_archivo;
    if(argc > 1){
        nombre_archivo = argv[1];
        leerArchivo(nombre_archivo,printer,n,m);
    }else{
        /*Lectura archivo y meter datos*/
        leerArchivo("in_1.txt", printer,n,m);
    }


    return 0;
}

// Función para calcular la distancia entre dos puntos
double calcularDistancia(double x1, double y1, double x2, double y2) {
    // Calcula las diferencias en las coordenadas X y Y
    double diffX = x2 - x1;
    double diffY = y2 - y1;

    // Eleva al cuadrado las diferencias en las coordenadas X y Y
    double cuadradoX = pow(diffX, 2);
    double cuadradoY = pow(diffY, 2);

    // Suma los resultados de los cuadrados de las diferencias
    double sumaCuadrados = cuadradoX + cuadradoY;

    // Calcula la raíz cuadrada del resultado obtenido
    double distancia = sqrt(sumaCuadrados);

    return distancia;
}

void crearAristas(Graph<std::pair<float, float>> &printer){
    std::vector<std::pair<float, float>> v = printer.getVertex(); //Vertex of pairs of X and Y of the graph
    int tam = v.size();
    float w = 0;
    for(int i = 0; i < tam; i++){
        //std::cout <<"Tam : " << tam <<" , i:" << i << "\n"; 
        for(int j = i+1; j < tam; j++){
            w = calcularDistancia(v[i].first, v[i].second, v[j].first , v[j].second);
            //std::cout<<"V"<<i<<": "<< v[i] << " V"<<j<<": " << v[j] << "distancia: " << w <<"\n";
            printer.addEdgeW(v[i], v[j], w);
        }
    }
}

void leerArchivo(std::string nombreArchivo, Graph<std::pair<float, float>> &printer, int &n, int &m){
    std::ifstream archivo(nombreArchivo);
    std::string n_archivo = "circuitos.txt";
    if (archivo.is_open()) {
        archivo >> n;

        std::ofstream salida(n_archivo);

        if(salida.is_open()){
            salida << n << "\n";
            for (int i = 0; i < n; i++) {
                int m;
                archivo >> m;
                salida << m << "\n";
                printer.addVertex({0,0});
                for (int j = 0; j < m; ++j) {
                    float x, y;
                    archivo >> x >> y;
                    printer.addVertex({x,y});
                }
                crearAristas(printer);
                std::cout << "Grafo del circuito# " << i << "\n"; 
                printer.printGraph();
                
                std::vector<std::pair<std::pair<float,float>,std::pair<float,float>>> mst;
                printer.primXY(mst);
               for (const auto& edge : mst) {
                    salida << "(" << edge.first.first << ", " << edge.first.second << ") - (" << edge.second.first << ", " << edge.second.second << ")" << std::endl;
                }
                
                mst.clear();
                printer.clear_();
            }
        } else {
            std::cerr << "No se pudo abrir el archivo de salida." << std::endl;
        }

        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}
