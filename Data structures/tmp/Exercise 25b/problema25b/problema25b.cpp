// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct sol {
	bool esZurdo;
	int numHijos;
};


template <typename T>
sol resolver(bintree<T> const& arbol) {
    
	if (arbol.empty()) { // Si el arbol es vacio, es zurdo
		return {true, 0};
	}
	else {
		sol iz, dr;
		iz = resolver(arbol.left());
		dr = resolver(arbol.right());
		
		if (arbol.left().empty() && arbol.right().empty()) // Si el arbol es una hoja, es zurdo
			return {true, iz.numHijos + dr.numHijos + 1};
		if (iz.esZurdo && dr.esZurdo && iz.numHijos > dr.numHijos) 	// Si los hijos izquierdo y derecho del arbol son zurdos, y el numero de hijos
																	// de la izquierda es mayor que el numero de hijos de la derecha, el arbol es zurdo
			return {true, iz.numHijos + dr.numHijos + 1};
		
		return {false, -1};
	}
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	bintree<char> arbol = leerArbol('.');
	sol solucion = resolver(arbol);
	if (solucion.esZurdo) std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;
    
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