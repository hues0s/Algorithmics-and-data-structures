// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación de la solución:
//Para transformar un numero decimal a binario, debemos dividir entre 2 hasta que el cociente sea 1,
// y concatenar los restos en orden inverso.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// función que resuelve el problema
// Coste: O(log n)
std::string conversor(int numeroDecimal) {

	if (numeroDecimal == 0) return "0";
	else if (numeroDecimal == 1) return "1";
	else if (numeroDecimal > 1) return conversor(numeroDecimal / 2) + char('0' + numeroDecimal % 2);

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int numeroLeido;
	std::cin >> numeroLeido;
    // calculamos la solucion
    std::string sol = conversor(numeroLeido);
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