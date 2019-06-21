// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "treemap_eda.h"
#include <string>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int numEjercicios;
	std::cin >> numEjercicios;
    if (numEjercicios == 0)
        return false;
    
	std::cin.ignore();	//Sirve para terminar de leer la linea, sino el getline va a leer lo que queda de linea.
						// Explicacion: cin ignora los separadores(espacios, saltos de linea, ...), pero getline no.
						// La cosa es que ignora los que va leyendo, pero los siguientes quedan en el buffer de entrada.
						// Con el metodo .ignore() lo que hacemos es quitar estos separadores.

	map<std::string, int> alumnos;	// No hace falta establecer un comparador porque por defecto esta std::less<>
									// y el orden alfabetico es de menor a mayor.
	
	std::string lecturaNombre, lecturaCorreccion;

	for (int i = 0; i < numEjercicios; ++i) {
		getline(std::cin, lecturaNombre);
		getline(std::cin, lecturaCorreccion);
		if (!alumnos.count(lecturaNombre)) alumnos.insert({ lecturaNombre, 0 });
		if (lecturaCorreccion == "CORRECTO") {
			alumnos[lecturaNombre] += 1;
		}
		else {
			alumnos[lecturaNombre] -= 1;
		}
	}
    
    // escribir sol

	typename map<std::string, int>::iterator it = alumnos.begin();
	while (it != alumnos.end()) {
		if((*it).valor != 0) std::cout << (*it).clave << ", " << (*it).valor << std::endl;
		++it;
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