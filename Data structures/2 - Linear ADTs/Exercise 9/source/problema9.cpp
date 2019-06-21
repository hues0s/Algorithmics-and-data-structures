// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "cola_extendida.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	unsigned int lectura;
	std::cin >> lectura;
    if (! std::cin)
        return false;
	
	//queue<unsigned int> q; //TODO por que si pongo parentesis no funciona????? si existe el constructor vacio
	ColaExtendida<unsigned int> q;

	while (lectura > 0) {
		q.push(lectura);
		std::cin >> lectura;
	}
	
	//Invertimos el orden
	if(q.size() > 1) q.invertirNodos();

	//Mostramos la lista enlazada invertida
	q.mostrarCola();

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