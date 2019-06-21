// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: recibe de entrada un numero ilimitado de vectores, y para
// cada uno de ellos, devuelve su valor minimo.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// Descripción de la función: recibe un vector, y devuelve su valor minimo.
// Coste: O(log n)
template <class T>
int resolver(std::vector<T> v, int ini, int fin) {
	
	if (ini == fin - 1) return v[ini]; // Vector de 1 elemento
	else if (ini == fin - 2) { // Vector de 2 elementos
		if (v[ini] < v[fin - 1]) return v[ini];
		else return v[fin - 1];
	}
	else {
		int mitad = (ini + fin) / 2;
		if (v[ini] < v[mitad]) return resolver(v, ini, mitad);
		else return resolver(v, mitad, fin);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int longitud;
	std::cin >> longitud;

    if (! std::cin)
        return false;
    
	std::vector<int> v(longitud);
	for (int i = 0; i < longitud; i++) std::cin >> v[i];

    int sol = resolver(v,0,longitud);
    
    // escribir sol
	std::cout << sol << std::endl;
    
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