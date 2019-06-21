// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct sol {
	int caudalActual;
	int tramosNavegables;
};


sol calcularTramosNavegables(bintree<int> const& arbol) {
	if (arbol.empty()) {
		return { 0,0 };
	}
	else {
		sol iz, dr, solucion = {0,0};
		iz = calcularTramosNavegables(arbol.left());
		dr = calcularTramosNavegables(arbol.right());

		if (arbol.left().empty() && arbol.right().empty())
			solucion.caudalActual += 1;
		else solucion.caudalActual += iz.caudalActual + dr.caudalActual;
		
		solucion.tramosNavegables = iz.tramosNavegables + dr.tramosNavegables;

		//OJO: al restar el caudal de un rio, nunca va a ser negativo, como mucho sera 0.
		solucion.caudalActual -= arbol.root();
		if (solucion.caudalActual < 0) solucion.caudalActual = 0;

		if (solucion.caudalActual >= 3)
			++solucion.tramosNavegables;
		return solucion;
	}
}

int resolver(bintree<int> const& arbol) {

	//Esta funcion es importante, puesto que en la raiz no debemos comprobar si el siguiente fragmento tiene un tramo navegable.

	sol iz = calcularTramosNavegables(arbol.left());
	sol dr = calcularTramosNavegables(arbol.right());

	return iz.tramosNavegables + dr.tramosNavegables;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	int solucion = resolver(arbol);
	std::cout << solucion << std::endl;
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