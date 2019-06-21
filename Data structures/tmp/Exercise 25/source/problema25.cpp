// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <limits>

struct sol {
	int multiplo;
	int nivel;
};

bool esPrimo(int n) {
	for (int i = 2; i < n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

bool esMultiplo7(int n) {
	return n % 7 == 0;
}

sol resolver(bintree<int> const& arbol, int nivel, bool esAccesible) {
	if (arbol.empty()) {
		//Pasamos el nivel maximo posible para no perder posibles soluciones que se encuentren en niveles mas abajo
		//del arbol vacio en el que estamos; así, cuando comparemos niveles, el programa escogera el de nivel posterior.
		return { -1, std::numeric_limits<int>::max() };
	}
	else {
		sol iz, dr, solucion = {0,0};
		iz = resolver(arbol.left(), nivel + 1, esAccesible && !esPrimo(arbol.root()));
		dr = resolver(arbol.right(), nivel + 1, esAccesible && !esPrimo(arbol.root()));

		if (iz.nivel <= dr.nivel) solucion = iz;
		else solucion = dr;

		if(esAccesible && esMultiplo7(arbol.root()) && nivel < solucion.nivel && 
			!esPrimo(arbol.root())){	//Esta ultima condicion es porque nosotros comprobamos si los anteriores son accesibles
										//al hacer la llamada recursiva, y ahora debemos comprobar si el nodo actual lo es tambien.
			solucion.multiplo = arbol.root();
			solucion.nivel = nivel;
		}
		return solucion;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    
	bintree<int> arbol = leerArbol(-1);
	if(arbol.empty()) std::cout << "NO HAY" << std::endl;
	else {
		sol solucion = resolver(arbol, 1, !esPrimo(arbol.root()));
		if (solucion.multiplo == -1) std::cout << "NO HAY" << std::endl;
		else std::cout << solucion.multiplo << " " << solucion.nivel << std::endl;
	}
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