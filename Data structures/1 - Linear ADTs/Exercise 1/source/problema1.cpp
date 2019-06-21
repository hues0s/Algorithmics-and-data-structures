// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Horas.h"

// Descripción de la función: busca la posicion inmediatamente siguiente a la hora leida del archivo de texto.
// Coste: O(log n) , ya que utilizamos la busqueda binaria para encontrar la posicion correcta
int resolver(std::vector<Horas> const& horasTrenes) {
	Horas h;
	std::cin >> h;
	auto iterator = std::lower_bound(horasTrenes.begin(), horasTrenes.end(), h);
	return std::distance(horasTrenes.begin(), iterator); // pasamos de iterator a int, para poder acceder a esa posicion del vector
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int numTrenes, numConsultas;
	std::cin >> numTrenes >> numConsultas;
    if (numTrenes == 0 && numConsultas == 0)
        return false;
    
	std::vector<Horas> horasTrenes;
	//std::vector<Horas> horasConsulta;

	//Rellenamos el vector que contiene las horas correctas de los trenes
	for (int i = 0; i < numTrenes; ++i) {
		Horas h;
		std::cin >> h;
		horasTrenes.push_back(h);
	}
	//Rellenamos el vector que contiene las horas a consultar
	for (int i = 0; i < numConsultas; ++i) {
		try {
			int posicionBuscada = resolver(horasTrenes);
			if (posicionBuscada < horasTrenes.size())
				std::cout << horasTrenes[posicionBuscada] << std::endl;
			else
				std::cout << "NO" << std::endl;
		}
		catch (std::invalid_argument ia) {
			std::cout << "ERROR" << std::endl;
		}
	}
	
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