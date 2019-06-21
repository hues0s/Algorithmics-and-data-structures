// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: recibe una entrada ilimitada de vectores, cuyos elementos son
// una serie de valores cuyo perfil se ajusta al de una curva concava.
// Se devuelve el valor minimo de cada uno.


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Descripción de la función: recibe un vector y devuelve su valor minimo.
// Coste: O(log n)
template <class T>
T resolver(std::vector<T> v, int ini, int fin) {

	if (ini + 1 == fin) return v[ini]; // vector de 1 elemento
	else if (ini + 2 == fin) { // vector de 2 elementos
		if (v[ini] < v[fin - 1]) return v[ini];
		else return v[fin - 1];
	}
	else { // vectores de 3 o mas elementos
		int mitad = (ini + fin) / 2;
		if (v[mitad] < v[mitad - 1] && v[mitad] > v[mitad + 1]) return resolver(v, mitad, fin);
		else return resolver(v, ini, mitad + 1);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int fin;
	std::cin >> fin;
    if (! std::cin)
        return false;
	std::vector<int> v(fin);
	for (int i = 0; i < fin; i++) std::cin >> v[i];

    int sol = resolver(v, 0, fin);
    
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