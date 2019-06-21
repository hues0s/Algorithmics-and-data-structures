// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include "bintree_eda.h"
#include <string>


template <typename T>
T resolver(bintree<T> const& arbol, const T max) {
	T min = max;
	typename bintree<T>::const_iterator it = arbol.begin();
	while (it != arbol.end()) {
		if (*it < min) min = *it;
		++it;
	}
	return min;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	char lecturaChar;
	std::cin >> lecturaChar;
    if (! std::cin)
        return false;
	if (lecturaChar == 'N') {
		bintree<int> arbolInt = leerArbol(-1);
		int maximo = std::numeric_limits<int>::max(); //Inicializamos al maximo del tipo para buscar el menor
		std::cout << resolver(arbolInt, maximo) << std::endl;
	}
	else if (lecturaChar == 'P') {
		std::string vacio = "#";	// Hay que declarar la variable fuera porque si no, al pasarla como parametro, 
									// la detecta como const char*, ya que en realidad es un array de char.
		bintree<std::string> arbolString = leerArbol(vacio);
		std::string maximoS = " ";
		maximoS[0] = 'z' + 1; //Como todo van a ser palabras legibles, un elemento mayor a todas sera la ultima letra (z) + 1
		std::cout << resolver(arbolString, maximoS) << std::endl;
	}
    
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