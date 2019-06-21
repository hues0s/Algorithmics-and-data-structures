// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

template <typename T>
class listaPlus: public queue<T> {

    using Nodo = typename queue<T>::Nodo;

public:

    //Metodo que intercambia los elementos de la lista de 2 en 2
    void modifica(){
        Nodo * aux = this->prim;
        Nodo * aux2 = aux->sig;
        Nodo * tmp = nullptr;
        Nodo * tmp2 = nullptr;

        //Si la lista solo tiene un nodo, no es necesario cambiar el puntero al primero
        if(this->nelems > 1) this->prim = this->prim->sig;

        while(aux != nullptr && aux2 != nullptr){
            aux->sig = aux2->sig;
            tmp = aux2->sig;
            aux2->sig = aux;
            if(tmp2 != nullptr) tmp2->sig = aux2;
            tmp2 = aux;
            aux = tmp;
            if(aux != nullptr) aux2 = aux->sig;
        }

        //Si la lista solo tiene un nodo, no es necesario cambiar el puntero al ultimo
        if(this->nelems > 1) this->ult = tmp2;
    }

    //Metodo que escribe los elementos de la lista
    void print() const{
        Nodo * aux = this->prim;
        for(int i = 0; i < this->nelems; ++i){
            std::cout << aux->elem << " ";
            aux = aux->sig;
        }
        std::cout << std::endl;
    }

};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElems;
    std::cin >> numElems;
    if (numElems == 0)
        return false;

    listaPlus<int> q;
    int lectura;
    for(int i = 0; i < numElems; ++i){
        std::cin>>lectura;
        q.push(lectura);
    }

    q.modifica();
    q.print();

    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}