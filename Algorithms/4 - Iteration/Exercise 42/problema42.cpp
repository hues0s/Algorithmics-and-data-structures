// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// Descripción de la función: 
// Coste: O(n)
int resolver(std::vector<int> v) {
    
	int ultimaPosicion = -1;
	int numCeros = 0;
	int numUnos = 0;

	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == 0) ++numCeros;
		else if (v[i] == 1) ++numUnos;
		if (numCeros == numUnos) ultimaPosicion = i;
	}
    
	return ultimaPosicion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int longitudVector;
	std::cin >> longitudVector;
	std::vector<int> v(longitudVector);
	for (int i = 0; i < longitudVector; ++i) std::cin >> v[i];
    int sol = resolver(v);
    // escribir sol
	std::cout << sol << std::endl;
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