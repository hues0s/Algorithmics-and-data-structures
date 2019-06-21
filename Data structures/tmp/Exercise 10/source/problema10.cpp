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
	unsigned long long int N;
	std::cin >> N;
    if (! std::cin)
        return false;
	
	ColaExtendida<unsigned long long int> q;
	unsigned long long int lectura;
	for (int i = 0; i < N; ++i) {
		std::cin >> lectura;
		q.push(lectura);
	}

	unsigned long long int M;
	unsigned long long int P;

	std::cin >> M >> P;

	ColaExtendida<unsigned long long int> colaAux;
	for (int i = 0; i < M; ++i) {
		std::cin >> lectura;
		colaAux.push(lectura);
	}
	
	//Insertamos la lista auxiliar en la posicion correcta de la lista principal

	q.insertarListaAuxiliar(colaAux, P);

	//Mostramos la lista enlazada MODIFICADA
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