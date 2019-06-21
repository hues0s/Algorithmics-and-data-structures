// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>

unsigned long long int calculoPotencia(short int potencia) {
	unsigned long long int solucion = 1;
	for (int i = 0; i < potencia; ++i) {
		solucion *= 10;
	}
	return solucion;
}

// Descripción de la función: 
// Coste: 
long int resolverNormal(long int numero, int numDigitos) {
    
	if (numero == 0) {
		if (numDigitos > 0) return 0;
		else return 9;
	}
	else {
		return resolverNormal(numero / 10, numDigitos + 1) * 10 + (9 - numero % 10);
	}
    
}

long int resolverInverso(long int numero, int& potencia, int numDigitos) {
	
	if (numero == 0) {
		if (numDigitos > 0) return 0;
		else return 9;
	}
	else {

		int numeroRecursivo = resolverInverso(numero / 10, potencia, numDigitos + 1);
		int numeroASumar = (9 - (numero % 10)) * calculoPotencia(potencia);
		potencia += 1;
		return numeroASumar + numeroRecursivo;
	}	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	long int numero;
	std::cin >> numero;
    
    // escribir sol
	long int sol = resolverNormal(numero, 0);
	int potencia = 0;
	long int solInverso = resolverInverso(numero, potencia, 0);
	std::cout << sol << " " << solInverso << std::endl;
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