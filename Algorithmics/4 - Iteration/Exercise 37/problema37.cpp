// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Descripción de la función: 
// Coste: O(n)
bool resolver(std::vector<int> v, int p) {
    
	//encontramos el elemento mayor de p hacia la izquierda
	int max = v[p];
	for (int i = 0; i < p; ++i) if (v[i] > max) max = v[i];
	//buscamos si hacia la derecha de p hay algun elemento menor que el maximo
	for (int i = p + 1; i < v.size(); ++i) if (v[i] <= max) return false;
	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int numElementos, p;
	std::cin >> numElementos;
	std::cin >> p;
	std::vector<int> v(numElementos);
	for (int i = 0; i < numElementos; ++i) std::cin >> v[i];
    
    bool sol = resolver(v, p);
    // escribir sol
	if (sol) std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;
    
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