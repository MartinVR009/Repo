    #include <iostream>
    #include <string>

    using namespace std;

    // Estructura para representar un organismo
    struct Organismo {
        string reino;
        string division;
        string clase;
        string orden;
        string genero;
        string especie;
        string ser;
        string categoriaConservacion;
        int censo;
        
        // Constructor
        Organismo(string r, string d, string c, string o, string g, string e, string s, string cat, int cn)
            : reino(r), division(d), clase(c), orden(o), genero(g), especie(e), ser(s), categoriaConservacion(cat), censo(cn) {}
    };

    // Nodo para árbol binario
    struct Nodo {
        Organismo organismo;
        Nodo* izquierdo;
        Nodo* derecho;
        
        // Constructor
        Nodo(Organismo o) : organismo(o), izquierdo(nullptr), derecho(nullptr) {}
    };

    // Clase para manejar la clasificación de organismos
    class ClasificacionOrganismos {
    private:
        Nodo* raiz;

    public:
        // Constructor
        ClasificacionOrganismos() : raiz(nullptr) {}

        // Método para agregar un nuevo organismo a la clasificación
        void agregarOrganismo(Organismo organismo) {
            raiz = insertar(raiz, organismo);
        }

        // Método para calcular la distancia entre dos organismos
        int calcularDistancia(Organismo organismo1, Organismo organismo2) {
            return distanciaEntreOrganismos(raiz, organismo1, organismo2);
        }

    private:
        // Función auxiliar para insertar un organismo en el árbol
        Nodo* insertar(Nodo* nodo, Organismo organismo) {
            if (nodo == nullptr) {
                return new Nodo(organismo);
            } else if (organismo.reino < nodo->organismo.reino) {
                nodo->izquierdo = insertar(nodo->izquierdo, organismo);
            } else if (organismo.reino > nodo->organismo.reino) {
                nodo->derecho = insertar(nodo->derecho, organismo);
            } else if (organismo.division < nodo->organismo.division) {
                nodo->izquierdo = insertar(nodo->izquierdo, organismo);
            } else if (organismo.division > nodo->organismo.division) {
                nodo->derecho = insertar(nodo->derecho, organismo);
            } //...

            return nodo;
        }

        // Función auxiliar para calcular la distancia entre dos organismos en el árbol
        int distanciaEntreOrganismos(Nodo* nodo, Organismo organismo1, Organismo organismo2) {
            if (nodo == nullptr) {
                return -1;
            }

            if (organismo1.reino < nodo->organismo.reino) {
                return 1 + distanciaEntreOrganismos(nodo->izquierdo, organismo1, organismo2);
            } else if (organismo1.reino > nodo->organismo.reino) {
                return 1 + distanciaEntreOrganismos(nodo->derecho, organismo1, organismo2);
            } else if (organismo1.division < nodo->organismo.division) {
                return 1 + distanciaEntreOrganismos(nodo->izquierdo, organismo1, organismo2);
            } else if (organismo1.division > nodo->organismo.division) {
                return 1 + distanciaEntreOrganismos(nodo->derecho, organismo1, organismo2);
            } //...

            return 0;
        }
    };

    int main() {
        // Ejemplo de uso
        ClasificacionOrganismos clasificacion;

        // Crear un nuevo organismo
        Organismo tigre("Animalia", "Chordata", "Mammalia", "Carnivora", "Panthera", "Tigris", "Tigris", "Vulnerable", 4000);

        // Agregar el organismo a la clasificación
        clasificacion.agregarOrganismo(tigre);

        // Crear otro organismo
        Organismo elefante("Animalia", "Chordata", "Mammalia", "Proboscidea", "Loxodonta", "Africana", "Africana", "Vulnerable", 6000);

        // Agregar el segundo organismo a la clasificación
        clasificacion.agregarOrganismo(elefante);

        // Calcular la distancia entre los dos organismos
        int distancia = clasificacion.calcularDistancia(tigre, elefante);

        return 0;
    }
