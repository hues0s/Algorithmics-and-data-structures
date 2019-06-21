// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: Programa que recibe datos que indican altura de una torre de piezas, y las piezas disponibles
// clasificandolas por color. Devuelve las posibles maneras de combinar esas piezas para construir la torre.
// Además, utilizamos MARCAJE para optimizar el algoritmo de vuelta atrás.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

const int INPUT_NUMBER = 4; //Indica el numero de elementos de entrada por caso
const int NUM_PIEZAS = 3; //Numero de piezas de colores distintos que se van a utilizar
typedef enum {azul,rojo,verde} tColor; //Tipo enumerado que contiene los colores posibles de la solucion

// Funcion auxiliar que permite obtener la string equivalente a su enumerado correspondiente
std::string color2str(tColor color) {
	switch (color) {
	case azul: return "azul";
	case rojo: return "rojo";
	case verde: return "verde";
	}
}

// Funcion que muestra en pantalla la solucion
void tratarSolucion(std::vector<tColor> solucion, int altura, std::string& stringSolucion) {
	for (int i = 0; i < altura; i++) stringSolucion += color2str(solucion[i]) + " ";
	stringSolucion += "\n";
}

// Funcion que devuelve TRUE si hemos alcanzado una solucion
bool esSolucion(int k, int altura) {
	return k == altura - 1;
}

// Funcion auxiliar que permite contar el numero de veces que se repite un color en un vector de tColor.
int contarPiezas(std::vector<tColor> solucion, int longitud, tColor color) {
	int contador = 0;
	for (int i = 0; i < longitud; i++) {
		if (solucion[i] == color) contador++;
	}
	return contador;
}

// Funcion de poda: devuelve TRUE si el hijo seleccionado del nivel puede conducir a una solucion valida.
bool esValida(std::vector<tColor> solucion, int k, int altura) {
	// CONDICIONES
	// 1- NO coloca 2 piezas verdes JUNTAS
	// 2- NO permite que el numero de piezas VERDES supere al de piezas AZULES en ningun momento mientras se va construyendo la torre
	// 3- SIEMPRE en la parte inferior hay una pieza ROJA
	// 4- En la torre final, nº de piezas ROJAS > piezas AZULES + VERDES

	//Para optimizar el algoritmo, contamos al inicio la cantidad de piezas de cada color
	int numAzul = contarPiezas(solucion, k + 1, azul), numRojo = contarPiezas(solucion, k + 1, rojo),
		numVerde = contarPiezas(solucion, k + 1, verde);

	//1
	if (k > 0 && (solucion[k] == verde && solucion[k - 1] == verde)) return false;
	//2
	if (numVerde > numAzul) return false;
	//3
	if (k == 0 && solucion[k] != rojo) return false;
	//4
	if ((numRojo) <= (numAzul + numVerde) && esSolucion(k, altura)) return false;
	//default
	return true;
}


// Descripción de la función: Recibe el vector solucion, y devuelve todas las posibles soluciones para una combinación de piezas.
// Coste: NUM_PIEZAS(3) ^ altura 
template <class T>
void resolver(std::vector<T> solucion, int k, int altura, std::string& stringSolucion,
	std::vector<int> marcas, std::vector<int> numMAX) {
	//solucion: vector solucion
	//k: nivel del arbol de exploracion
	//altura: altura de la torre a construir en cada caso
	//stringSolucion: string donde se almacena una solucion
	//marcas: vector de marcaje que sirve para optimizar el algoritmo de vuelta atras
	//numMAX: vector que almacena los numeros maximos de cada pieza

	for (int i = 0; i < NUM_PIEZAS; i++) {
		if (marcas[i] < numMAX[i]) {
			tColor colorParcial = (tColor)i;
			solucion[k] = colorParcial;
			if (esValida(solucion, k, altura)) {
				if (esSolucion(k, altura)) {
					tratarSolucion(solucion, altura, stringSolucion);
				}
				else {
					marcas[i]++;
					resolver(solucion, k + 1, altura, stringSolucion, marcas, numMAX);
					marcas[i]--;
				}
			}
		}
	}
}

// Funcion de generalizacion: proporciona todas las posibles solucion, simplificando los parametros necesarios de la llamada.
void resolver(std::vector<int> input, std::string& stringSolucion) {
	//input[0]: altura de la torre
	//input[1]: numero de piezas AZULES
	//input[2]: numero de piezas ROJAS
	//input[3]: numero de piezas VERDES

	std::vector<tColor> solucion(input[0]); // Vector que almacenara una solucion
	std::vector<int> marcas(NUM_PIEZAS); // Vector de marcas
	std::vector<int> numMAX(NUM_PIEZAS); // Vector que contiene los numeros maximos las piezas de cada color
	for (int i = 0; i < NUM_PIEZAS; i++) numMAX[i] = input[i + 1];

	resolver(solucion, 0, input[0], stringSolucion, marcas, numMAX);
	if (stringSolucion == "") stringSolucion = "SIN SOLUCION\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	std::vector<int> input(INPUT_NUMBER);
	for (int i = 0; i < INPUT_NUMBER; i++) std::cin >> input[i];

    if (input[0] == 0 && input[1] == 0 && input[2] == 0 && input[3] == 0)
        return false;
    
	std::string stringSolucion = "";
	resolver(input, stringSolucion);
    
    // escribir sol
	std::cout << stringSolucion << std::endl;
    
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