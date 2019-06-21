// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

// Descripción de la función: 
// Coste: 
bool resolver(std::vector<long int> v, unsigned int k, long int ini, long int fin) {
    
	if (ini + 1 == fin) return true; // vector de 1 elemento --> siempre TRUE
	else if (ini + 2 == fin) { // vector de 2 elementos
		unsigned long int diferencia = std::abs(v[ini] - v[fin - 1]);
		if (diferencia >= k) return true;
		else return false;
	}
	else {
		long int mitad = (ini + fin) / 2;
		bool mitadDerecha = resolver(v, k, mitad, fin);
		if (!mitadDerecha) return false;
		bool mitadIzquierda = resolver(v, k, ini, mitad);
		if (!mitadIzquierda) return false;
		return true;
	}

    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	unsigned int numTiradas, k;
	std::cin >> numTiradas;
    if (! std::cin)
        return false;
	std::cin >> k;
	std::vector<long int> v(numTiradas);
	for (int i = 0; i < numTiradas; ++i) std::cin >> v[i];
    
	bool solucion = resolver(v, k, 0, numTiradas);
    // escribir sol
	if (solucion) std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;
    
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