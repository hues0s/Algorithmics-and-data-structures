// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct sol {
	int numEquiposNecesarios;
	int maxExcursionistas;
};

template <typename T>
sol resolver(bintree<T> const& arbol) {
	if (arbol.empty()) {
		return { 0,0 };
	}
	else {
		sol iz, dr, solucion = { 0,0 };
		iz = resolver(arbol.left());
		dr = resolver(arbol.right());

		if (iz.maxExcursionistas >= dr.maxExcursionistas) solucion = iz;
		else solucion = dr;

		//Tenemos que combinar el numero de equipos de ambas ramas; es totalmente diferente 
		//al numero maximo de excursionistas, donde debemos elegir una rama u otra.
		solucion.numEquiposNecesarios = iz.numEquiposNecesarios + dr.numEquiposNecesarios;

		//Si estamos en un nodo cuyo elemento es distinto de 0, y el maximo de excursionistas avistados
		//hasta el momento es 0, quiere decir que estamos justo comenzando a rescatar al primer grupo.
		if (arbol.root() != 0 && solucion.maxExcursionistas == 0)
			++solucion.numEquiposNecesarios;

		solucion.maxExcursionistas += arbol.root();
		return solucion;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<int> arbol = leerArbol(-1);
	sol solucion = resolver(arbol);
    // escribir sol
	std::cout <<solucion.numEquiposNecesarios << " " << solucion.maxExcursionistas << std::endl;
    
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