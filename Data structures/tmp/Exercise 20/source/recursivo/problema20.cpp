// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <vector>

template <typename T>
void calcularFrontera(bintree<T> arbol, std::vector<T> & frontera) {
	if (arbol.empty()) {} //arbol vacio, por lo que dejamos de buscar mas abajo
	else {
		calcularFrontera(arbol.left(), frontera);
		calcularFrontera(arbol.right(), frontera);
		//si nos encontramos en una subarbol, cuyos subelementos son ambos nulos, es una hoja, por lo que guardamos su valor
		if (arbol.left().empty() && arbol.right().empty()) frontera.push_back(arbol.root()); 
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<int> arbol = leerArbol(-1);
    
	std::vector<int> frontera;
	calcularFrontera(arbol, frontera);
	for (int i = 0; i < frontera.size(); ++i) std::cout << frontera[i] << " ";
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