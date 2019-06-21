// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct sol {
	int altura;
	int diametroMaximo;
};

//El diametro del arbol es su camino mas largo
template <typename T>
sol resolver(bintree<T> const& arbol) {
	if (arbol.empty()) {
		return { 0,0 };
	}
	else {
		sol iz, dr;
		iz = resolver(arbol.left());
		dr = resolver(arbol.right());

		int diametroMaxActual = std::max(iz.diametroMaximo, dr.diametroMaximo);
		if (iz.altura + dr.altura + 1 > diametroMaxActual) diametroMaxActual = iz.altura + dr.altura + 1;

		if (iz.altura >= dr.altura) {
			iz.diametroMaximo = diametroMaxActual;
			++iz.altura;
			return iz;
		}
		else {
			dr.diametroMaximo = diametroMaxActual;
			++dr.altura;
			return dr;
		}
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<char> arbol = leerArbol('.');
	sol solucion = resolver(arbol);
    // escribir sol
	std::cout << solucion.diametroMaximo << std::endl;
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