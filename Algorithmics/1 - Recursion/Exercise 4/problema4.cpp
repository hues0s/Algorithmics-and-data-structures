// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: Recibe una entrada ilimitada de numeros enteros positivos, 
// y elimina sus digitos pares.

#include <iostream>
#include <iomanip>
#include <fstream>

using ulli = unsigned long long int;


unsigned long long int calculoPotencia(short int potencia) {
	unsigned long long int solucion = 1;
	for (int i = 0; i < potencia; ++i) {
		solucion *= 10;
	}
	return solucion;
}

// Descripción de la función: dado un número, elimina sus cifras pares.
// Coste: 
ulli resolver(ulli n, short int potencia) {
    
	ulli solucion, aux;
	if (n == 0) {
		solucion = 0;
	}
	else {
		if ((n % 10) % 2 == 0) {
			aux = resolver(n / 10, potencia);
			solucion = aux;
		}
		else if ((n % 10) % 2 == 1) {
			potencia++;
			aux = resolver(n / 10, potencia);
			solucion = aux + (n % 10) * calculoPotencia(potencia);
		}
	}
	return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	ulli numeroLeido;
	std::cin >> numeroLeido;

    if (! std::cin)
        return false;
	
    ulli sol = resolver(numeroLeido, -1);
    
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