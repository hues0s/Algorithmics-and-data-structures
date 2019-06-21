// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	unsigned int numAlumnos, salta;
	std::cin >> numAlumnos >> salta;
    if (numAlumnos == 0 && salta == 0)
        return false;
    
	//Resolucion

	std::list<unsigned int> l;
	std::list<unsigned int>::iterator it;
	for (int i = 0; i < numAlumnos; ++i) l.push_back(i + 1);
	it = l.begin();
	while (l.size() > 1) {
		for (int i = 0; i < salta; ++i) {
			if (it == l.end()) it = l.begin();
			++it;
			if (it == l.end()) it = l.begin();
		}
		it = l.erase(it);
	}

	std::cout << l.front() << std::endl;
    
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