#include <iostream>
#include <vector>


int main() {
    // Crear un vector de vectores de float
    std::vector<std::vector<float>> matriz;

    // Llenar la matriz con algunos datos
    matriz.push_back({1.1f, 2.2f, 3.3f});
    matriz.push_back({4.4f, 5.5f, 6.6f});
    matriz.push_back({7.7f, 8.8f, 9.9f});

    // Imprimir los datos originales
    std::cout << "Datos originales:" << std::endl;
    for (const auto& fila : matriz) {
        for (float elemento : fila) {
            std::cout << elemento << ' ';
        }
        std::cout << std::endl;
    }

    // Liberar la memoria liberando los elementos internos de la matriz
    for (auto& fila : matriz) {
        fila.clear();
    }
    matriz.clear();

    // Ingresar nuevos datos
    matriz.push_back({10.1f, 20.2f, 30.3f});
    matriz.push_back({40.4f, 50.5f, 60.6f});
    matriz.push_back({70.7f, 80.8f, 90.9f});

    // Imprimir los nuevos datos
    std::cout << "\nNuevos datos:" << std::endl;
    for (const auto& fila : matriz) {
        for (float elemento : fila) {
            std::cout << elemento << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
