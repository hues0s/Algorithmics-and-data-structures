// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Polinomio.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	monomio lectura;
	std::cin >> lectura.coeficiente;
    if (! std::cin)
        return false;
	std::cin >> lectura.exponente;
	Polinomio p;
	while (lectura.coeficiente != 0 || lectura.exponente != 0) {
		p.anadirMonomio(lectura.coeficiente, lectura.exponente);
		std::cin >> lectura.coeficiente >> lectura.exponente;
	}

	int numValores, valorActual;
	std::cin >> numValores;
	for (int i = 0; i < numValores; ++i) {
		std::cin >> valorActual;
		std::cout << p.evaluarPolinomio(valorActual) << " ";
	}
	std::cout << std::endl;
    
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