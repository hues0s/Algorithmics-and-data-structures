// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: recibe una entrada limitada de vectores ordenados de caracteres,
// y determina cual es el que falta siguiendo el orden en cada caso.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

template <class T>
T funcionAuxiliar(std::vector<T> v, int ini, int fin) {

	int mitad;
	T solucion;

	if (fin - ini <= 2) {
		solucion = T(v[ini] + 1);
	}
	else {
		mitad = ((ini + fin) / 2);

		if (v[mitad] - v[ini] > mitad - ini) solucion = funcionAuxiliar(v, ini, mitad + 1);
		else solucion = funcionAuxiliar(v, mitad, fin);
	}
	return solucion;
}

// Descripción de la función: recibe un vector ordenado, y determina que elemento falta en él, siguiendo el orden.
// Coste: O(log n)
template <class T>
T resolver(std::vector<T> v, T primerElemento, T ultimoElemento) {
	int longitud = ultimoElemento - primerElemento;
	// Comprobamos si la letra que falta no esta en los extremos
	if (primerElemento != v[0]) return primerElemento;
	else if (ultimoElemento != v[longitud-1]) return ultimoElemento;
	// Si esta dentro, llamamos a la funcion recursiva
	return funcionAuxiliar(v, 0, longitud);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	char primeraLetra, segundaLetra;
	std::cin >> primeraLetra >> segundaLetra;
	int longitudVector = segundaLetra - primeraLetra;
	std::vector<char> v(longitudVector);
	for (int i = 0; i < v.size(); i++) std::cin >> v[i];
    
	// calculo de la solucion
    char sol = resolver(v, primeraLetra, segundaLetra);

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