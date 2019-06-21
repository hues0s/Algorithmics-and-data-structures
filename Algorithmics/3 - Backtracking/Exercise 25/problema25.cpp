#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//Funcion que comprueba si una determinada solucion final es valida
bool esSolucion(int k, int longitudTiraLuces) {
	return k == longitudTiraLuces - 1;
}

//Funcion que suma los colores diferentes al de este nivel
int numeroColoresRestantes(std::vector<int> const& sumaColores, int colorNoSumable) {
	int sumaTotal = 0;
	for (int i = 0; i < sumaColores.size(); ++i) sumaTotal += sumaColores[i];
	sumaTotal -= sumaColores[colorNoSumable];
	return sumaTotal;
}

//Funcion que comprueba si una determinada funcion parcial es correcta
bool esValida(std::vector<int> const& solucion, int k, std::vector<int> const& sumaColores, int consumoMaximoSoportado,
	int consumoActual) {

	//1
	if (k > 1 && solucion[k] == solucion[k - 1] && solucion[k] == solucion[k - 2]) return false;
	//2
	if (sumaColores[solucion[k]] > 1 + numeroColoresRestantes(sumaColores, solucion[k])) return false;
	//3
	//if (consumoActual > consumoMaximoSoportado) return false;

	return true;
}

//Funcion que implementa el algoritmo de vuelta atras para resolver el problema 
void backtracking(std::vector<int> & solucion, int k, std::vector<bool> & marcas, int longitudTiraLuces,
	int& numeroCombinaciones, int numColoresDiferentes, std::vector<int> & sumaColores,
	int consumoMaximoSoportado, int& consumoActual, std::vector<int> const& arrayConsumos) {
    
	for (int i = 0; i < numColoresDiferentes; ++i) {
		if (arrayConsumos[i] + consumoActual <= consumoMaximoSoportado) {
			solucion[k] = i;
			sumaColores[i]++; //sumo 1 a el color de esa posicion
			consumoActual += arrayConsumos[i];
			if (esValida(solucion, k, sumaColores, consumoMaximoSoportado, consumoActual)) {
				if (esSolucion(k, longitudTiraLuces)) numeroCombinaciones++;
				else {
					//if (consumoActual + arrayConsumos[i] > consumoMaximoSoportado) marcas[i] = true;
					backtracking(solucion, k + 1, marcas, longitudTiraLuces, numeroCombinaciones, numColoresDiferentes,
						sumaColores, consumoMaximoSoportado, consumoActual, arrayConsumos);
					//marcas[i] = false;
				}
			}
			//deshago los cambios
			sumaColores[i]--; 
			consumoActual -= arrayConsumos[i];
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int longitudTiraLuces, numColoresDiferentes, consumoMaximoSoportado;
	std::cin >> longitudTiraLuces;
    if (! std::cin)
        return false;
    
	std::cin >> numColoresDiferentes;
	std::cin >> consumoMaximoSoportado;
	std::vector<int> arrayConsumos(numColoresDiferentes);
	for (int i = 0; i < numColoresDiferentes; i++) std::cin >> arrayConsumos[i];

	std::vector<int> solucion(longitudTiraLuces);
	std::vector<bool> marcas(numColoresDiferentes);
	int numeroCombinaciones = 0;
	int consumoActual = 0;
	std::vector<int> sumaColores(numColoresDiferentes);

	// calcular sol
	backtracking(solucion, 0, marcas, longitudTiraLuces, numeroCombinaciones, numColoresDiferentes,
		sumaColores, consumoMaximoSoportado, consumoActual, arrayConsumos);

    // escribir sol
	std::cout << numeroCombinaciones << std::endl;
    
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