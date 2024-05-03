#include <vector>
#include <list>
#include <iterator>
#include <string>
#include <iostream>
#include <stack>

class Vehiculo{
  protected:
    unsigned short modelo;
    std::string placa;
    unsigned int tarifaDiara;

  public:
    unsigned short obtenerModelo();
    std::string obtenerPlaca();
    unsigned int obtenerTarifa();
};

std::list<Vehiculo> carros;

std::list<std::list < Vehiculo > > vector_listas;

std::list<std::list<Vehiculo>> :: iterator my_vector_list_iterator;

// List vehiculos
// liST vehiculos
// list vehiculos

unsigned short obtenerModeloPar(std::string placa){
    for(my_vector_list_iterator = vector_listas.begin(); my_vector_list_iterator != vector_listas.end(); my_vector_list_iterator++){
        std::list<Vehiculo>::iterator it;
        for(it = my_vector_list_iterator -> begin(); it != my_vector_list_iterator->end(); it++){
            if(it->obtenerPlaca() == placa){
                return it->obtenerModelo();
            }
        }
    }
}


/*
void funcion(){
    
    for(my_vector_list_iterator = vector_listas.begin(); my_vector_list_iterator != vector_listas.end(); my_vector_list_iterator++){
        std::list<Vehiculo>::iterator it;
        for(it = my_vector_list_iterator->begin(); it != my_vector_list_iterator->end(); it++){

        }
    }
}
*/


unsigned short placaVehiculo(std::string placa){
std::list<Vehiculo>::iterator myIterator;

    for(myIterator = carros.begin(); myIterator != carros.end(); myIterator++){
        if(myIterator->obtenerPlaca() == placa){
            return myIterator -> obtenerModelo();
        }
    }

}


template <typename T, typename Container = std::deque<T>>
class MyStack {
public:
    // Función para añadir un elemento a la pila
    void push(const T& value) {
        container_.push_back(value);
    }

    // Función para eliminar el elemento del tope de la pila
    void pop() {
        if (!empty()) {
            container_.pop_back();
        }
    }

    // Función para acceder al elemento del tope de la pila
    T& top() {
        return container_.back();
    }

    // Función para comprobar si la pila está vacía
    bool empty() const {
        return container_.empty();
    }

    // Función para obtener el número de elementos en la pila
    size_t size() const {
        return container_.size();
    }

private:
    Container container_;
};

int main() {
    // Uso de la pila personalizada (MyStack)
    MyStack<int> miPila;

    // Añadir elementos a la pila
    miPila.push(1);
    miPila.push(2);
    miPila.push(3);

    // Mostrar el tamaño de la pila
    std::cout << "Elementos de la pila: " << miPila.size() << std::endl;

    // Acceder y mostrar el elemento del tope de la pila
    std::cout << "Elemento del tope: " << miPila.top() << std::endl;

    // Eliminar elementos de la pila
    miPila.pop();

    // Mostrar el tamaño de la pila después de la eliminación
    std::cout << "Elementos de la pila despues de pop: " << miPila.size() << std::endl;

    std::stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Mostrar el tamaño de la pila
    std::cout << "Elementos de la pila: " << myStack.size() << std::endl;

    // Acceder y mostrar el elemento del tope de la pila
    std::cout << "Elemento del tope: " << myStack.top() << std::endl;

    // Eliminar elementos de la pila
    myStack.pop();

    // Mostrar el tamaño de la pila después de la eliminación
    std::cout << "Elementos de la pila despues de pop: " << myStack.size() << std::endl;


    return 0;
}