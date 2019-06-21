// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

/* 
			Explicación general:

	Tenemos un diccionario donde guardaremos cada deporte y su numero de inscritos validos.
	Otro diccionario lo destinaremos a registrar a todos los alumnos, y su deporte asociado.
	
	No se utilizan diccionarios ordenados puesto que el ejercicio nos pide ordenar en primera instancia
	segun el valor de las entradas del diccionario de deportes.
	Para ordenar la salida, creamos un vector en el que metemos el contenido del diccionario de deportes,
	y luego ordenamos segun el criterio del enunciado utilizando la funcion sort.

*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <unordered_map>
#include <vector>
#include <algorithm> //Funcion std::sort
#include <functional> //Funcion std::greater<>

typedef std::string tDeporte;
typedef int tDemanda;

typedef std::string tNombreAlumno;
typedef std::string tDeporteAsociado;

struct sol {
	tDeporte deporte;
	tDemanda demanda;
};

//Funcion que sobrecarga el operador > para que funcione con variables de tipo sol, siguiendo el criterio del enunciado.
bool operator>(sol const& s1, sol const& s2) {
	//Un struct sol es mayor que otro si su demanda asociada es mayor
	if (s1.demanda > s2.demanda) return true;
	else if (s1.demanda < s2.demanda) return false;
	//En caso de demanda igual, se seguira el orden alfabetico, sin posibilidad de 2 iguales ya que todos los deportes son distintos.
	else {
		if (s1.deporte < s2.deporte) return true; //Se utiliza < puesto que el orden alfabetico va invertido
		return false;
	}
}

//Funcion que recibe un string y devuelve true en caso de que sea un deporte
bool esDeporte(std::string const& s) {
	//Si el primer caracter es una letra, y esa letra es mayuscula, ese string se corresponde con un deporte.
	if (isalpha(s[0]) && isupper(s[0])) return true;
	return false;
}

//Funcion que lee los datos, rellena los diccionarios y resuelve el problema.
void resolver(std::unordered_map<tDeporte, tDemanda> & deportes, 
	std::unordered_map<tNombreAlumno, tDeporteAsociado> & alumnos, std::string & lectura) {

	std::string deporteActual; //En este string guardaremos el deporte actual, del cual estamos leyendo los alumnos.

	while (lectura != "_FIN_") { //Mientras la string leida sea distinta de "_FIN_" seguiremos en el mismo caso de prueba.
		if (esDeporte(lectura)) {
			//Inicializamos la entrada de diccionario del deporte leido.
			deportes.insert({ lectura, 0 });
			deporteActual = lectura;
		}
		else { //Aqui entra si el string leido corresponde con el nombre de un alumno.
			auto & refDicAlumno = alumnos[lectura]; //Referencia a la entrada actual del diccionario alumnos para evitar coste de []
			if (refDicAlumno.length() == 0) { //Si el alumno no tiene ningun deporte asociado.
				refDicAlumno = deporteActual;
				++deportes[deporteActual];
			}
			else if (refDicAlumno != deporteActual &&
				refDicAlumno != "EXPULSADO") { //Si el alumno se ha apuntado a mas de un deporte, entra a este if.
				--deportes[refDicAlumno]; //Lo eliminamos del contador de ese deporte.
				refDicAlumno = "EXPULSADO"; //Marcamos ese alumno como expulsado para que en el futuro no reste aun mas
											//el contador de su primer deporte asociado.
			}
		}
		getline(std::cin, lectura);
	}
}

//Funcion que recibe el diccionario de deportes, y muestra la solucion.
void mostrarSolucion(std::unordered_map<tDeporte, tDemanda> const& deportes) {
	//Metemos al vector las claves y valores del diccionario, para ordenarlos y mostrarlos en orden.
	std::vector<sol> solucion;
	auto it = deportes.cbegin();
	while (it != deportes.cend()) {
		solucion.push_back({ it->first, it->second });
		++it;
	}

	//Ordenamos el vector; para ello, deberemos definir el operador >, para que la funcion std::greater pueda funcionar.

	std::sort(solucion.begin(), solucion.end(), std::greater<sol>());

	//Mostramos el vector en orden

	for (int i = 0; i < solucion.size(); ++i) {
		std::cout << solucion[i].deporte << " " << solucion[i].demanda << std::endl;
	}
	std::cout << "***" << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	std::string lectura;
	getline(std::cin, lectura);
    if (! std::cin)
        return false;

	std::unordered_map<tDeporte, tDemanda> deportes;	//Tenemos que mostrar la salida ordenada por valor, pero
														//si utilizamos map solo podremos ordenar por clave.
														//Por tanto, utilizamos unordered_map y ordenaremos mas tarde la salida.

	std::unordered_map<tNombreAlumno, tDeporteAsociado> alumnos;	//Cada alumno solo podra tener un deporte asociado.
																	//En caso de que se intente asociar a otro deporte, 
																	//se le borrara de todos.
    
	// operamos
	resolver(deportes, alumnos, lectura);

    // escribir sol
	mostrarSolucion(deportes);

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