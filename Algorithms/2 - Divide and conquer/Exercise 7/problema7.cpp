// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: Recibe un numero limitado de vectores y, en cada caso, devuelve
// el numero igual a su posicion + el numero cantado. Si no hay ninguno, devuelve NO.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>


// Descripción de la función: Recibe un vector, y devuelve aquel numero que verifique las condiciones del problema.
// Coste: O(log n)
template <class T>
std::string resolver(std::vector<T> v, int ini, int fin, int numeroCantado) {
    
	if (ini == fin - 1) { // Vectores de 1 elemento
		if (v[ini] - numeroCantado == ini) return std::to_string(v[ini]);
		else return "NO";
	}
	else {
		int mitad = (ini + fin) / 2;
		if (v[mitad] - numeroCantado > mitad) return resolver(v, ini, mitad, numeroCantado);
		else return resolver(v, mitad, fin, numeroCantado);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int longitud, numeroCantado;
	std::cin >> longitud;
	std::cin >> numeroCantado;
	std::vector<int> v(longitud);
	for (int i = 0; i < longitud; i++) std::cin >> v[i];
    
    std::string sol = resolver(v,0,longitud,numeroCantado);
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