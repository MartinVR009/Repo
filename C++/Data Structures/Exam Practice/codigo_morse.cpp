/*1. Insertar
//Se da por hecho que la cadena de puntos y rayas bajas es una cola de cadena de caracteres o una deque
//Cuando paso la raiz, no se pasa el nodo actual, siempre un referente a la raiz del arbol 
Insertar(raiz, simbolo, cadena)
    si nodo actual es diferente de la raíz y cola de cadena está vacía
        nodo actual->valor = simbolo

    si simbolo es igual a "." 
        si nodo actual->izquierdo es nulo 
            sacar primer elemento de la cola
            nodo actual->izquierdo = Insertar(nuevo Nodo con simbolo, cadena)

    si simbolo es igual a "-" 
        si nodo actual->derecho es nulo 
            sacar primer elemento de la cola
            nodo actual->derecho = Insertar(nuevo Nodo con simbolo, cadena)*/

void Insertar(TreeNodee* raiz, TreeNode* nodo, char simbolo, queue<char> &cadena){
    if(raiz != this && cadena.isEmpty()){
        this->valor == simbolo
    }

    if(simbolo == '.'){
        if(this->left == nullptr){
            cadena.pop();
            this->left = Insertar(raiz, this->left, simbolo, cadena);
        }
    }
    f(simbolo == '-'){
        if(this->right == nullptr){
            cadena.pop();
            this->right = Insertar(raiz, this->right, simbolo, cadena);
        }
    }
}


/*2.Codificar
//Conjunto representa el conjunto de cadena de caracteres
//Codigo seria un vector de cadenas de caracteres para almacenar sus codificaciones

Codificar(conjunto, codigo)
    para cada letra en conjunto
        vector de cadenas de caracteres temporal llamado temporal
        vector de cadenas de caracteres temporal llamado verificacion
        dfs(nodo_actual,temporal, letra, verificacion)
        si verificacion es diferente de vacio 
            agregar a la cola de codigo verificacion
            verificacion igual a "" 
        si no
            salir

//Nodo representa donde estoy actualmente en el arbol
//objetivo representa que buscare en el arbol
//resultado donde guardare la ruta al objetivo de cadena de caracteres
dfs(Nodo, objetivo, resultado)
    si mi Nodo esta apuntando a vacio
        retornar ""
    
    si valor nodo actual = objetivo
        retornar resultado

    cadena de caracteres codificacionIzquierda
    cadena de caracteres codificacionDerecha

    codificacionIzquierda igual a dfs(nodo izquierdo,objetivo,  concatenar "." a resultado)
    codificacionDerecha igual a dfs(nodo derecho,objetivo,  concatenar "-" a resultado)

    si codificacionIzquierda es diferente de vacio ""
        retornar codificacionIzquierda
    o si codificacionDerecha es diferente de vacio ""
        retornar codificacionDerecha
    
    retornar vacio en caso de no encontrar nada

    
//Se espera los codigos de la palabra en morse vengan separados por un " " espacio en blanco*/
string dfs(TreeNode* root, char target, string& result) {
    if (root == nullptr) {
        return "";
    }

    if (root->value == target) {
        return result;
    }

    string leftCode = dfs(root->left, target, result + ".");
    string rightCode = dfs(root->right, target, result + "-");

    if (!leftCode.empty()) {
        return leftCode;
    } else if (!rightCode.empty()) {
        return rightCode;
    } else {
        return "";
    }
}

// Función para codificar un conjunto de letras a Morse
void Codificar(const string& conjunto, vector<string>& codigo, TreeNode* root) {
    for (char letra : conjunto) {
        string temp;
        string verificacion;
        string resultado;
        verificacion = dfs(root, letra, resultado);
        if (!verificacion.empty()) {
            codigo.push_back(verificacion);
            verificacion = "";
        } else {
            break;
        }
    }
}


//Codificar
/*3. Decodificar. 

Decodificar(codigos)
    crear cadena de caracteres vacia llamada palabra
    crear caracter vacio llamado temporal
    para cada codigo en codigos

        temporal igual a letra_codigo(codigo)
        si temporal es diferente de vacio ""
            concatenar temporal al final de palabra
        si no
            retornar vacio*/

// Función para decodificar un conjunto de códigos Morse a letras
string Decodificar(const vector<string>& codigos, TreeNode* root) {
    string palabra;
    for (const auto& codigo : codigos) {
        int idx = 0;
        char letra = dfs(root, codigo, idx);
        if (letra != ' ') {
            palabra += letra;
        } else {
            return ""; // No se pudo decodificar el código, retornar vacío
        }
    }
    return palabra;
}

/*letra_codigo(nodo, &codigo)
    crear apuntador que apunte a la primera direccion de memoria de codigo llamado ptr 
        si el caracter al que apunta ptr es igual a "." y nodo izquierdo es diferente de nulo

            si ptr mas uno es diferente de "/0"
                letra_codigo(nodo izquierdo, ptr mas uno)
            si no
                retornar valor nodo izquierdo

        si el caracter al que apunta ptr es igual a "-" y nodo derecho es diferente de nulo
            si ptr mas uno es diferente de "/0"
                letra_codigo(nodo derecho, ptr mas uno)
            si no
                retornar valor nodo derecho
        si no
            retornar vacio*/
// Algoritmo DFS para buscar el símbolo asociado a un código Morse

char letra_codigo(TreeNode* nodo, string& codigo, int idx){ //idx empezando en 0
    if(nodo == nullptr){
        return ' ';
    }

    if(idx == codigo.size()){
        return root->value;
    }

    if(codigo[idx] == '.' && nodo->left != nullptr){
        idx++;
        letra_codigo(root->left, codigo, idx);
    }else if(codigo[idx] == '-' && nodo->right != nullptr){
        idx++;
        letra_codigo(root->right, codigo, idx);
    }
    return ' ';
}