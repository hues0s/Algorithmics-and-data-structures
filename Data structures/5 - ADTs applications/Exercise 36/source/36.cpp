#include "consultorio.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada:
	int numCasos;
	std::cin >> numCasos;

	//Si no hay más datos de entrada para de ejecutarse:
	if (!std::cin) return false; 

	//Eliminamos el salto de linea despues del numero de casos:
	std::cin.ignore(); 

	//Declaramos un string para poder leer linea a linea, las peticiones:
	std::string linea;
	//Declaramos nuestro consultorio:
	consultorio cp;

	//Recorre la lista de peticiones al consultorio hasta 
	//que se acaban los numeros de casos:
	for (int i = 0; i < numCasos; ++i) {
		std::getline(std::cin, linea); //Lee la primera linea;
		std::stringstream ss(linea);
		
		//Declaramos los datos auxiliares necesarios para poder 
		//leer bien los datos de entrada:
		std::string palabra, palMedico;
		int numero, dia, hora, min;

		//Leemos la primera palabra de una linea (peticion al consultorio):
		ss >> palabra;
		
		//Parsea cada una de las peticiones:
		try { 
			
			//Llama al metodo encargado de dar de alta un nuevo medico:
			if (palabra == "nuevoMedico") {
				ss >> palabra; 
				cp.nuevoMedico(palabra);
			} 
			
			//Llama al metodo encargado de generar una consulta nueva:
			else if (palabra == "pideConsulta") {
				ss >> palabra >> palMedico;
				ss >> dia >> hora >> min;
				fecha f(dia, hora, min);
				cp.pideConsulta(palabra, palMedico, f);
			} 
			
			//Llama al metodo encargado de listar a todos los pacientes de 
			//la lista de espera de un medico en particular, también se encarga
			//de mostrar la lista entera por pantalla:
			else if (palabra == "listaPacientes") {
				ss >> palabra >> numero;
				std::vector<infoPaciente> aux = cp.listaPacientes(palabra, numero);
				
				std::cout << "Doctor " << palabra << " dia " << numero << "\n";
				for (size_t i = 0; i < aux.size(); ++i) {
					std::cout << aux[i].p << " " <<
					std::setfill('0') << std::setw(2) << aux[i].f.getHora() << ":"
					<< std::setfill('0') << std::setw(2) << aux[i].f.getMinuto() << "\n";
				}

				std::cout << "---" << "\n";
			} 
			
			//Llama al metodo encargado de devolver el siguiente paciente de la lista
			//de espera de un medico en particular, también se encarga de mostarlo 
			//por pantalla:
			else if (palabra == "siguientePaciente") {
				ss >> palabra;
				paciente aux = cp.siguientePaciente(palabra);

				std::cout << "Siguiente paciente doctor " << palabra << "\n";
				std::cout << aux << "\n";

				std::cout << "---" << "\n";
			} 
			
			//Llama al metodo encargado de eliminar una cita de la lista de 
			//espera de un medico en concreto:
			else if (palabra == "atiendeConsulta") {
				ss >> palabra;
				cp.atiendeConsulta(palabra);
			} 
		} 
		//Recoge los mensajes de error y los muestra por pantalla:
		catch (const char * c) { 
			std::cout << c << "\n";
			std::cout << "---" << "\n";
		}
	}

	std::cout << "------" << "\n";
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to casos.txt
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 
	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}