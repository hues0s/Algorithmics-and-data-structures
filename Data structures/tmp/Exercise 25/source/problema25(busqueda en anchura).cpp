// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <vector>

bool esMultiploDe7(int n) {
	return n % 7 == 0;
}

bool esPrimo(int n) {
	for (int i = 2; i < n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}


struct asociado {
	bintree<int> arbol;
	bool haPasadoPrimo;
	int nivel;
};

struct sol {
	int numero;
	int nivel;
};


sol resolver(bintree<int> const& arbol) {
	
	if (!arbol.empty()) {

		std::queue<asociado> pendientes;
		if(esPrimo(arbol.root())) pendientes.push({ arbol, true, 1 });
		else pendientes.push({ arbol, false, 1 });

		while (!pendientes.empty()) {
			asociado sig = pendientes.front();
			pendientes.pop();

			if (!sig.haPasadoPrimo) { //solo nos interesa analizar esta parte del arbol, si no ha pasado primo
				//analizamos la raiz del arbol actual
				if (esMultiploDe7(sig.arbol.root()))
					return { sig.arbol.root(), sig.nivel };

				if (!sig.arbol.left().empty()) {
					bool prIz = esPrimo(sig.arbol.left().root());
					pendientes.push({ sig.arbol.left(), prIz, sig.nivel + 1 });
				}
				if (!sig.arbol.right().empty()) {
					bool prDr = esPrimo(sig.arbol.right().root());
					pendientes.push({ sig.arbol.right(), prDr, sig.nivel + 1 });
				}
			}
		}
	
	}
	return { -1,-1 };
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	
	sol sol = resolver(arbol);
	if (sol.numero != -1) std::cout << sol.numero << " " << sol.nivel;
	else std::cout << "NO HAY";
	
	std::cout << std::endl;
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