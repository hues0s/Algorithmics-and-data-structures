// Nombre del alumno Héctor Ullate Catalán
// Usuario del Juez E64

// Explicación general: recibe una entrada ilimitada de numeros enteros positivos,
// y los invierte de manera recursiva.

#include <iostream>
#include <iomanip>
#include <fstream>

struct sol {
	unsigned long int numero;
	int pot; // Potencia de 10 necesaria para calcular el numero en cada llamada
	// No se puede implementar ninguna funcion que calcule la potencia de un numero.
};

sol invertir(unsigned long int n);

// Descripción: dado un número, calcula su inverso.
// Coste:
sol invertir(unsigned long int n) {

	sol solucion;

	if (n == 0) {
		solucion.numero = 0;
		solucion.pot = 1;
	}
	else {
		int x = n % 10; // obtenemos los numeros individualmente antes de la llamada recursiva, para utilizarlos posteriormente
		solucion = invertir(n / 10);
		solucion.numero += x * solucion.pot;
		solucion.pot *= 10;
	}
	return solucion;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	unsigned long int numero;
	std::cin >> numero;

	// comprobamos el fin de la entrada
    if (! std::cin)
        return false;
    
    sol solucion = invertir(numero);
    
    // escribir sol
	std::cout << solucion.numero << std::endl;
    
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