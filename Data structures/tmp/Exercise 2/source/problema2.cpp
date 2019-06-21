// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Pelicula.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int numPeliculas, numFallosLectura = 0;
	std::cin >> numPeliculas;

    if (numPeliculas == 0)
        return false;
    
	std::vector<Pelicula> pelis;

	for (int i = 0; i < numPeliculas; ++i) {
		try {
			Pelicula p;
			std::cin >> p;
			pelis.push_back(p);
		}
		catch (const char * ex) {
			std::cout << ex << std::endl;
			++numFallosLectura;
		}
	}
    
	//ordenamos el vector de peliculas
	std::sort(pelis.begin(), pelis.end());

    // escribir sol
	for (int i = 0; i < numPeliculas - numFallosLectura; ++i) std::cout << pelis[i] << std::endl;
	std::cout << "---" << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}