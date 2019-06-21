// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>

typedef std::string tPalabra;
//typedef std::set<int> tLineasDeAparicion; //Utilizamos un conjunto para que cada fila solo pueda aparecer una vez por palabra; NOO

typedef std::vector<int> tLineasDeAparicion;	//Utilizamos un vector en lugar de un set porque solo tenemos que consultar la
												//ultima posicion para ver si ya hemos guardado esa linea.
												//Si hiciera falta consultar mas posiciones del vector, entonces lo optimo
												//seria un set. La cosa es que las operaciones del vector son menos costosas, 
												//por lo que, en caso de ser posible, siempre es mejor utilizar vector.


//Funcion que recibe un string y lo devuelve con todos sus caracteres en minuscula.
void upperToLower(std::string & s) {
	for(int i = 0; i < s.length();++i) s[i] = tolower(s[i]);
	/*

			Alternativa propuesta por isabel:
			transform(s.begin(), s.end(), s.begin(), ::tolower);

		La funcion transform permite aplicar una operación a toda una secuencia.

	*/
}

//Funcion que guarda en un diccionario las lineas en las que aparece cada palabra
void resolver(std::map<tPalabra, tLineasDeAparicion> & palabras, const int N) {
	
	std::string lectura, lecturaPalabra;

	for (int i = 0; i < N; ++i) {
		//leemos una linea del texto
		getline(std::cin, lectura);
		std::stringstream ss(lectura);
		while (ss) {
			ss >> lecturaPalabra;
			upperToLower(lecturaPalabra); //Pasamos todos los caracteres a minuscula. OJO: puede haber mayusculas en cualquiera de ellos.
			if (lecturaPalabra.length() > 2) {

				auto & ref = palabras[lecturaPalabra];	//IMPORTANTE: como vamos a hacer muchas menciones al valor de la clave
														//guardamos su direccion de memoria para ahorrarnos el coste de la operacion.

				//Si el vector esta vacio, no habra ninguna linea guardada, por lo que simplemente añadimos la linea.
				if (ref.size() == 0)
					ref.push_back(i + 1);
				else {
					//Si el vector no esta vacio, sabemos si la linea ya ha sido guardada consultando la ultima posicion del vector.
					//Si esa ultima posicion no contiene la linea actual, la insertamos.
					if(ref[ref.size()-1] != i+1) 
						ref.push_back(i + 1);
				}
			}
		}
	}
}

//Funcion que muestra por pantalla cada palabra junto con las lineas en las que aparece
void mostrarSolucion(std::map<tPalabra, tLineasDeAparicion> const& palabras) {
	auto itPalabras = palabras.cbegin();
	while (itPalabras != palabras.cend()) {
		std::cout << itPalabras->first << " ";

		//Recorremos las lineas asociadas a cada palabra. Es un VECTOR, pero se puede recorrer igualmente con iteradores (coste igual).
		auto itLineas = itPalabras->second.cbegin();
		while (itLineas != itPalabras->second.cend()) {
			std::cout << *itLineas << " ";
			++itLineas;
		}
		std::cout << std::endl;
		++itPalabras;
	}
	std::cout << "----" << std::endl;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int N;
	std::cin >> N;
    if (N == 0)
        return false;
	std::cin.ignore();

    // operamos
	std::map<tPalabra, tLineasDeAparicion> palabras;
	resolver(palabras, N);
    
    // escribir sol
	mostrarSolucion(palabras);
	
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