// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// Descripción de la función: Recibe un vector y, si un elemento es par lo mantiene; si no, lo elimina.
// Coste: O(n)
void resolver(std::vector<unsigned int> &v) {
    
	int contador = 0, i = 0;
	while (i < v.size()) {
		if (v[i] % 2 == 0) {
			v[contador] = v[i];
			contador++;
		}
		++i;
	}
	v.resize(contador);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	unsigned int numElementos;
	std::cin >> numElementos;

	// vector de elementos positivos y estrictamente crecientes
	std::vector<unsigned int> v(numElementos);
	for (int i = 0; i < numElementos; ++i) std::cin >> v[i];

	resolver(v);
    // escribir sol
	for (int i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
	std::cout << std::endl;
    
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