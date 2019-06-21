// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

/* Explicación general: 
	
	Para clasificar a los equipos se sigue este orden:
		1º Por numero de problemas resueltos.
		2º A igualdad de problemas resueltos, se ordena por tiempo total de cada equipo.
		3º A igualdad de problemas resueltos y tiempo, se ordena por orden alfabetico.


	Para resolver el problema guardamos un diccionario con los nombres de los equipos, que a su vez tiene un subdiccionario
	con los problemas enviados por cada equipo. 

	Utilizamos unordered_map porque tenemos varios criterios a la hora de ordenar, y por tanto lo mejor es pasar el contenido del
	map a un vector, y ordenar ese vector utilizando la sobrecarga del operador >.


*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <functional>

const std::string PROBLEMA_CORRECTO = "AC";
const int PENALIZACION_POR_FALLO = 20;

typedef std::string tNombreEquipo;

typedef struct {
	//De cada problema guardaremos el tiempo total que consume, y si esta ya correcto, ya que envios posteriores a AC no cuentan.
	int tiempoTotal = 0;
	bool esApto = false;
} tDatosProblema;

typedef std::unordered_map<std::string, tDatosProblema> tProblemasAsociados;

struct sol{
	//Este struct contiene los 3 datos fundamentales que debemos mostrar por pantalla para cada equipo.
	std::string nombreEquipo;
	int numProblemas;
	int tiempo;
};


//Sobrecarga del operador > para poder utilizar std::greater() en std::sort()
bool operator>(sol const& s1, sol const& s2) {
	if (s1.numProblemas > s2.numProblemas) return true;
	else if (s1.numProblemas < s2.numProblemas) return false;
	else {
		if (s1.tiempo < s2.tiempo) return true;
		else if (s1.tiempo > s2.tiempo) return false;
		else {
			return s1.nombreEquipo < s2.nombreEquipo;
		}
	}
}

//Funcion que recibe un string con separaciones, y devuelve un vector con las palabras que la componen.
std::vector<std::string> split(std::string const& s, const char separator) {
	std::string tmp;
	std::vector<std::string> ret;
	auto it = s.cbegin();
	while (it != s.cend()) {
		if (*it != separator) {
			tmp.push_back(*it);
		}
		else {
			//Aqui entrara cuando se llegue al separador; es entonces cuando metemos tmp al vector solucion y reseteamos el string.
			ret.push_back(tmp);
			tmp = "";
		}
		++it;
	}

	//Comprobacion final por si quedan elementos por copiar al vector solucion.
	if (tmp.length() > 0) ret.push_back(tmp);

	return ret;
}

//Funcion que recibe un map con los equipos y sus datos asociados, y los muestra por orden en pantalla.
void mostrarSolucion(std::unordered_map<tNombreEquipo, tProblemasAsociados> const& clasificacion) {
	//Rellenamos el vector con los datos del diccionario
	std::vector<sol> v;
	int posicionActual = -1; //Contador que lleva la posicion actual que estamos actualizando del vector
	auto it = clasificacion.cbegin(); //Iterador principal que recorre cada equipo
	while (it != clasificacion.cend()) {
		auto subIt = it->second.cbegin(); //Iterador que recorre todos los problemas de un equipo.
		while (subIt != it->second.cend()) {
			
			//Si el problema al que apunta el subiterador es apto, lo debemos tener en cuenta
			if (v.size() == 0 || v[posicionActual].nombreEquipo != it->first) {
				//Si el vector esta vacio o el ultimo nombre de equipo insertado difiere con el equipo que estamos analizando:
				v.push_back({ it->first, 0, 0});
				++posicionActual;
			}
			if (subIt->second.esApto) {
				//Si el equipo ya se ha insertado, simplemente actualizamos sus valores, si el problema es apto.
				++v[posicionActual].numProblemas;
				v[posicionActual].tiempo += subIt->second.tiempoTotal;
			}
			
			++subIt;
		}
		++it;
	}

	//Ordenamos el vector
	std::sort(v.begin(), v.end(), std::greater<sol>());

	//Mostramos el vector por pantalla
	for (int i = 0; i < v.size(); ++i) std::cout << v[i].nombreEquipo << " " << v[i].numProblemas << " " << v[i].tiempo << std::endl;
	std::cout << "----" << std::endl;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	std::string lectura;
	std::vector<std::string> lecturaLinea;
	std::unordered_map<tNombreEquipo, tProblemasAsociados> clasificacion;

	//Rellenamos el diccionario de manera correcta
	getline(std::cin, lectura);
	while (lectura != "FIN") {
		lecturaLinea = split(lectura, ' ');
		auto & ref = clasificacion[lecturaLinea[0]]; //Diccionario
		auto & subRef = ref[lecturaLinea[1]]; //Subdiccionario
		if (!subRef.esApto) {
			if (lecturaLinea[3] == PROBLEMA_CORRECTO) {
				//SI el problema es correcto:
				subRef.esApto = true;
				subRef.tiempoTotal += stoi(lecturaLinea[2]);
			}
			else {
				subRef.tiempoTotal += PENALIZACION_POR_FALLO;
			}
		}
		getline(std::cin, lectura);
	}

	// escribir sol
	mostrarSolucion(clasificacion);

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
	std::cin.ignore();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}