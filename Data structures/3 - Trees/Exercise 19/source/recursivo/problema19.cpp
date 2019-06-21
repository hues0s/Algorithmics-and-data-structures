// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct sol {
	int altura;
	int numNodos;
	int numHojas;
};

//Recibe un arbol binario, y calcula de manera recursiva su altura, su numero de nodos y su numero de hojas

template <typename T>
sol resolver(bintree<T> const& arbol) {
	if (arbol.empty()) {
		return { 0,0,0 };
	}
	else {
		sol iz, dr, definitiva;
		iz = resolver(arbol.left());
		dr = resolver(arbol.right());
		if (iz.altura >= dr.altura) {
			definitiva = iz;
			definitiva.numNodos += dr.numNodos;
			definitiva.numHojas += dr.numHojas;
		}
		else {
			definitiva = dr;
			definitiva.numNodos += iz.numNodos;
			definitiva.numHojas += iz.numHojas;
		}

		++definitiva.numNodos;
		if (arbol.left().empty() && arbol.right().empty()) ++definitiva.numHojas;
		++definitiva.altura;
		return definitiva;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<char> arbol = leerArbol('.');
    
	sol solucion = resolver(arbol);
	std::cout << solucion.numNodos << " " << solucion.numHojas << " " << solucion.altura << std::endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}