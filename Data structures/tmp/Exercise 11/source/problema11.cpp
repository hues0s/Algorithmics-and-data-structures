// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "cola_extendida.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
   	unsigned long long int lectura;
	ColaExtendida<unsigned long long int> q1;
	std::cin >> lectura;
	while (lectura > 0) {
		q1.push(lectura);
		std::cin >> lectura;
	}
	ColaExtendida<unsigned long long int> q2;
	std::cin >> lectura;
	while (lectura > 0) {
		q2.push(lectura);
		std::cin >> lectura;
	}

	//Mezclamos las listas de manera ordenada
	q1.mezclarColas(q2);

	//Escribimos en pantalla la lista mezclada ordenada
	q1.mostrarCola();

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