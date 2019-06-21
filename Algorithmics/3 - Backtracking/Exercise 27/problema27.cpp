// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

bool esSolucion(int k, int altura) {
	return k == altura - 1;
}


// Descripción de la función: 
// Coste: 
void backtracking(tMatriz matriz, int k, int altura, int & coste, int & costeMejor, std::vector<bool> & marcas ) {
	// altura = numero de trabajos (que coincide con el numero de trabajadores)
	// k = nivel actual
	for (int i = 0; i < altura; i++) {
		if (!marcas[i]) {
			coste += matriz[i][k];
			if (esSolucion(k, altura)) {
				if (coste < costeMejor) {
					costeMejor = coste;
				}
			}
			else {
				marcas[i] = true;
				backtracking(matriz, k + 1, altura, coste, costeMejor, marcas);
				marcas[i] = false;
			}
			coste -= matriz[i][k];
		}
	}

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int numFuncionarios;
	std::cin >> numFuncionarios;
    if (numFuncionarios == 0)
        return false;
    
	tMatriz matriz(numFuncionarios, std::vector<int>(numFuncionarios));
	for (int i = 0; i < numFuncionarios; ++i) {
		for (int j = 0; j < numFuncionarios; ++j) {
			std::cin >> matriz[i][j];
		}
	}
	std::vector<bool> marcas(numFuncionarios);
	int coste = 0;
	//int costeMejor = std::numeric_limits<int>::max();
	int costeMejor = 0;
	for (int i = 0; i < numFuncionarios; ++i) {
		costeMejor += matriz[i][i];
	}


	backtracking(matriz, 0, numFuncionarios, coste, costeMejor, marcas);
    // escribir sol
	std::cout << costeMejor << std::endl;

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