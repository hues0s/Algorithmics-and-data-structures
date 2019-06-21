// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: Recibe un conjunto de juguetes, niños a cada uno de los cuales se les reparten 2 juguetes, y la
// satisfaccion minima que tiene que tener cada niño. El programa devuelve en cada caso las posibles combinaciones de
// reparto de juguetes.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

template <class T>
using tMatriz = std::vector<std::vector<T>>;

// Escribe una string con la solucion encontrada
void tratarSolucion(std::vector<int> solucion, int n, std::string& stringSolucion) {
	for (int i = 0; i < (n * 2); i++) stringSolucion += std::to_string(solucion[i]) + " ";
	stringSolucion += "\n";
}

// Devuelve true si hemos llegado a una solucion
bool esSolucion(int k, int altura) {
	return k == altura - 1;
}

// Devuelve true si una solucion parcial es valida
bool esValida(int satisfaccionMinima, int k, int n, std::vector<std::string> tiposPorJuguete, 
	std::vector<int> solucion, std::vector<std::vector<int>> matrizSatisfaccion) {
	// 1- cada niño tiene juguetes DISTINTOS
	// 2- si va a ser solucion, tiene que ser mayor de la satisfaccion minima (PARA CADA NIÑO)
	// 3- el primer juguete sera el de menor identificador y el segundo el de mayor identificador.

	//1
	if (k > 0 && tiposPorJuguete[solucion[k]] == tiposPorJuguete[solucion[k - 1]]) return false;
	//2
	if (k % 2 == 1 && 
		(matrizSatisfaccion[k/2][solucion[k]] + matrizSatisfaccion[k / 2][solucion[k - 1]]) < satisfaccionMinima) 
		return false;
	//3
	if (k % 2 == 1 && solucion[k] < solucion[k - 1]) return false;
	//default
	return true;
}

// Implementa el algoritmo de vuelta atras para obtener una solucion al problema
void backtracking(int k, int m, int n, int satisfaccionMinima, std::vector<int> unidadesPorJuguete,
	std::vector<std::string> tiposPorJuguete, std::vector<std::vector<int>> matrizSatisfaccion,
	std::vector<int> solucion, std::vector<int> marcas, int& satisfaccion, std::string& stringSolucion) {

	// m = nº de juguetes diferentes
	// n = nº de niños
	// Vector solucion: posicion par(juguete1), posicion impar(juguete2)
	for (int i = 0; i < m; i++) {
		if (marcas[i] < unidadesPorJuguete[i]) {
			solucion[k] = i;
			if (esValida(satisfaccionMinima, k, n, tiposPorJuguete, solucion, matrizSatisfaccion)){
				if (esSolucion(k, (n*2))) {
					tratarSolucion(solucion, n, stringSolucion);
				}
				else {
					marcas[i]++;
					backtracking(k + 1, m, n, satisfaccionMinima, unidadesPorJuguete,
						tiposPorJuguete, matrizSatisfaccion, solucion, marcas, satisfaccion, stringSolucion);
					marcas[i]--;
				}
			}
		}
	}
}

// Funcion de generalizacion que prepara lo necesario para ejecutar el algoritmo de vuelta atras
void resolver(int m, int n, int satisfaccionMinima, std::vector<int> unidadesPorJuguete,
	std::vector<std::string> tiposPorJuguete, std::vector<std::vector<int>> matrizSatisfaccion,
	std::string& stringSolucion) {

	std::vector<int> solucion(n * 2); // vector solucion
	std::vector<int> marcas(m);
	int satisfaccion = 0;
	backtracking(0, m, n, satisfaccionMinima, unidadesPorJuguete, tiposPorJuguete,
		matrizSatisfaccion, solucion, marcas, satisfaccion, stringSolucion);
	if (stringSolucion == "") stringSolucion = "SIN SOLUCION\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int m, n, satisfaccion;
	std::cin >> m;
    if (! std::cin)
        return false;

	std::cin >> n;
	std::cin >> satisfaccion;
	std::vector<int> unidadesPorJuguete(m);
	for (int i = 0; i < m; ++i) std::cin >> unidadesPorJuguete[i];
	std::vector<std::string> tiposPorJuguete(m);
	for (int i = 0; i < m; i++) std::cin >> tiposPorJuguete[i];

	tMatriz<int> matrizSatisfaccion(n, std::vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) std::cin >> matrizSatisfaccion[i][j];
	}
	std::string stringSolucion = "";
    resolver(m, n, satisfaccion, unidadesPorJuguete, tiposPorJuguete, matrizSatisfaccion, stringSolucion);
    
    // escribir sol
	std::cout << stringSolucion + "\n";
    
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