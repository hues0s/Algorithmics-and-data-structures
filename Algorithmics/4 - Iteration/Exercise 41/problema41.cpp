// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: ejercicio iterativo

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

enum piedrasPreciosas { diamante, rubi, esmeralda, zafiro, jade };
std::istream& operator>> (std::istream& entrada, piedrasPreciosas& p) {
	char num;
	entrada >> num;
	switch (num) {
	case 'd': p = diamante; break;
	case 'r': p = rubi; break;
	case 'e': p = esmeralda; break;
	case 'z': p = zafiro; break;
	case 'j': p = jade; break;
	}
	return entrada;
}


// Descripción de la función: 
// Coste: 
int resolver(std::vector<piedrasPreciosas> v, int tamSecuencia, piedrasPreciosas tipo1, int numTipo1,
	piedrasPreciosas tipo2, int numTipo2) {
    
	int i = 0;
	int contadorParcialSecuencia = 0;
	int contadorTipo1 = 0;
	int contadorTipo2 = 0;
	int contadorSecuenciasValidas = 0;
	int limiteBucle = v.size() ;
	while (i < limiteBucle) {
		if (contadorParcialSecuencia < tamSecuencia) {
			++contadorParcialSecuencia;
			if (v[i] == tipo1) {
				++contadorTipo1;
			}
			else if (v[i] == tipo2) {
				++contadorTipo2;
			}
		}
		else {
			if (contadorTipo1 >= numTipo1 && contadorTipo2 >= numTipo2) {
				++contadorSecuenciasValidas;
			}
			contadorParcialSecuencia = 0;
			contadorTipo1 = 0;
			contadorTipo2 = 0;
			i = i - tamSecuencia;
		}
		++i;
	}
	if (contadorTipo1 >= numTipo1 && contadorTipo2 >= numTipo2) {
		++contadorSecuenciasValidas;
	}
	contadorParcialSecuencia = 0;
	contadorTipo1 = 0;
	contadorTipo2 = 0;
	return contadorSecuenciasValidas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int numpiedras, tamSecuencia, numtipo1, numtipo2;
	piedrasPreciosas tipo1, tipo2;
	std::cin >> numpiedras >> tamSecuencia >> tipo1 >> numtipo1 >> tipo2 >> numtipo2;
    
	std::vector<piedrasPreciosas> v(numpiedras);
	for (piedrasPreciosas& i : v) std::cin >> i;

	int sol = resolver(v, tamSecuencia, tipo1, numtipo1, tipo2, numtipo2);
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