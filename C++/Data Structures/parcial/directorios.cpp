//1.Eliminar
/*
1.Eliminar

//ruta, la ruta seria un vector de cadenas de caracteres representando el nombre de la ruta de directorios al arbol a eliminar
//El llamado a eliminar debe hacerse con indice 0
Eliminar(nodo, ruta, index)
    si el nodo actual es nulo
        devolver Falso
    
    si el tamaño de la ruta es igual al indice -1
        el nodo actual es una hoja? //No tiene descendientes
            si, eliminar nodo actual
                devolver verdadero
            no, devolver falso //No es un archivo

    directorio a buscar = nombre de la ruta en indice actual

    para cada descendiente del nodo actual
        Si, el valor del descendiente es igual al directorio
                Si eliminar(ruta, index + 1)

        //Fin del ciclo 
         No se hayo el nombre en la ruta
            devolver Falso
*/

bool Eliminar(Node* nodo, std::vector<string> ruta, int index){
    if (nodo == nullptr){
        return false;
    }

    if(index-1 == ruta.size()){
        if(desc.empty()){
            delete nodo;
            return true;
        }else{
            return false;
        }
    }

    string directorio = ruta[index];

    for(Node* descendiente : nodo->hijos){
        if(descendiente->valor == directorio){
            Eliminar(descendiente, ruta, index++);
        }
    }
    return false;
    //C:/tareas/estructuras/parcial.pdf
}

/*//ruta, vector de rutas llamado ruta
2.buscar archivo recibe: nodo, cadena, ruta buscar archivo(nodo, cadena, ruta)
    si nodo es nulo
        retornar
    si no
        adjuntar valor de nodo actual a la cola de ruta
        si el valor del nodo actual es igual a la cadena
            devolver la ruta
        buscar archivo en nodo izquierdo, con su ruta, objetivo
        buscar archivo en nodo derecho, con su ruta, objetivo

        quitar ultimo elemento de la ruta */

std::vector<string> buscarArchivo(Node* nodo, string cadena, std::vector<string> &ruta){
    if(nodo == nullptr){
        return;
    }else{
        ruta.push_back(nodo->valor);
        if(nodo->valor == cadena){
            return ruta;
        }
        for(Node* desc : nodo->hijos){
            buscarArchivo(desc, cadena, ruta);
        }
        ruta.pop_back();
    }
}

/*
//resultado, guardara todos los vectores ruta que lleven hacia la cadena
3. buscar todos archivos, recibe: nodo, cadena, ruta , resultado
    si nodo es igual a nulo
        retornar
    si no,
        adjuntar a la cola de ruta
        si el valor del nodo es igual a la cadena 
            adjuntar vector ruta actual a resultado
        buscar todos archivos,en nodo izquierdo, con su cadena, con su ruta, con su resultado
        buscar todos archivos,en nodo derecho, con su cadena, con su ruta, con su resultado
        
        quitar elemento de la cola de ruta*/

std::vector<std::vector<std::string>> buscarTodos(Node* nodo, string cadena, std::vector<string> &ruta, std::vector<std::vector<std::string>> &resultado){
    if(nodo == nullptr){
        return;
    }else{
        ruta.push_back(nodo->valor);
        if(nodo->valor == cadena){
            resultado.push_back(ruta);
        }

        /*for(Node* desc : nodo->hijos){
            buscarArchivo(desc, cadena, ruta);
        }*/
        
        buscarTodos(nodo->izquierda, cadena, ruta, resultado);
        buscarTodos(nodo->derecha, cadena, ruta, resultado);
        ruta.pop_back();
    }
}

