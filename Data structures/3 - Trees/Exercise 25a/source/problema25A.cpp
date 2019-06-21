//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno: Héctor Ullate Catalán
// Usuario del juez de clase: E64
// Usuario del juez de examen que has utilizado en la prueba de hoy: E09
//
//***************************************************

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

struct sol {
	bool esCorrecto;
	int altura;
};

// Aqui función del alumno
template <typename T>
sol resolver(bintree<T> const& arbol) {
	if (arbol.empty()) {
		return { true, 0 };
	}
	else {
		sol iz, dr;
		iz = resolver(arbol.left());
		dr = resolver(arbol.right());
		
		if (iz.esCorrecto && dr.esCorrecto) {
			//La edad del padre siempre supera en al menos 18 a˜nos las edades de cada uno de los hijos (si existen).
			if (!arbol.left().empty() && arbol.root() < arbol.left().root() + 18) return { false, 0 };
			else if (!arbol.right().empty() && arbol.root() < arbol.right().root() + 18) return { false,0 };

			//Si un padre no tiene hijo izquierdo y si derecho, no es valido.
			else if (arbol.left().empty() && !arbol.right().empty()) return { false,0 };

			//La edad del segundo hijo (si existe) es al menos dos años menos que la del primer hijo.
			else if (!arbol.left().empty() && !arbol.right().empty() &&
				arbol.left().root() < arbol.right().root() + 2) return { false,0 };

			else {
				if (iz.altura >= dr.altura) return { true, iz.altura + 1 };
				return { true, dr.altura + 1 };
			}
		}
		return { false, 0 };
	}
}


void resuelveCaso() {
    bintree<int> tree = leerArbol(-1);

	sol solucion = resolver(tree);

	if (solucion.esCorrecto) std::cout << "SI " << solucion.altura << std::endl;
	else std::cout << "NO " << std::endl;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //redirect std::cin to casos.txt
#endif

    int numCasos; std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {resuelveCaso();}
    
    // Para restablecer entrada. 
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
