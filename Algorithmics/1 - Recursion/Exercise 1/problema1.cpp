// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64


#include <iostream>
#include <iomanip>
#include <fstream>

// función que recibe 2 números enteros, y devuelve el resultado de su multiplicación.
// Coste: O(log n)
long int resolver(long int a, long int b) {
    
	long int resultado = -1;

	if (b == 0) resultado = 0;
	else if (b == 1) resultado = a;
	else if (b > 1) {
		// es par
		if (b % 2 == 0) resultado = resolver(2 * a, b / 2);
		// es impar
		else resultado = resolver(2*a, b/2) + a;
	}
	return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	long int parametroA, parametroB;
	std::cin >> parametroA >> parametroB;
    
	// calcula la solucion
	long int sol = resolver(parametroA, parametroB);
    // escribir sol
	std::cout << sol << "\n";
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