// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <limits>

struct sol {
	bool esBinarioBusqueda;
	int mayorElemento;
	int menorElemento;
};

sol resolver(bintree<int> const& arbol) {

	//Es importante darse cuenta de que la raiz debe ser mayor que TODOS los de su izq, y menor que TODOS los de su derecha.

	if (arbol.empty()) {
		return {true, -1, std::numeric_limits<int>::max()};
	}
	else {
		sol iz, dr, sol;
		iz = resolver(arbol.left());
		dr = resolver(arbol.right());

		if (!iz.esBinarioBusqueda || !dr.esBinarioBusqueda) return {false,0,0};
		if (!arbol.left().empty() && arbol.root() <= iz.mayorElemento) return { false,0,0 };
		if (!arbol.right().empty() && arbol.root() >= dr.menorElemento) return { false,0,0 };

		//No sabemos si este nodo va a ser derecha o izquierda para su nodo padre, por lo que preparamos los dos casos.
		sol.menorElemento = std::min(iz.menorElemento, dr.menorElemento);
		sol.mayorElemento = std::max(dr.mayorElemento, iz.mayorElemento);

		if (arbol.root() > sol.mayorElemento) sol.mayorElemento = arbol.root();
		if (arbol.root() < sol.menorElemento) sol.menorElemento = arbol.root();
		
		//IMPORTANTE PONER ESTO: EL JUEZ NO PERDONA UNA
		sol.esBinarioBusqueda = true;

		return sol;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    
	bintree<int> arbol = leerArbol(-1);
	if (resolver(arbol).esBinarioBusqueda) std::cout << "SI" << std::endl;
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