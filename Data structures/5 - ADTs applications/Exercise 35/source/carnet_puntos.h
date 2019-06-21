#ifndef CARNET_PUNTOS_H
#define CARNET_PUNTOS_H

#include <unordered_map>
#include <stdexcept>
#include <list>

class carnet_puntos {

	const int MAX_PUNTOS = 15;
	const int MIN_PUNTOS = 0;

	//Creamos un hashmap para guardar cada dni con sus puntos asociados
	using dniConductor = std::string;
	using puntos = int;
	std::unordered_map<dniConductor, puntos> carnet;
	
	
	//Hashmap para relacionar cada numero de puntos con una lista, que contiene ordenados los dni, siendo el primero el mas reciente
	using listaDeConductores = std::list<dniConductor>;
	std::unordered_map<puntos, listaDeConductores> mapDeListaPorPuntos;

	//Guardamos un iterador de cada dni.
	//Para utilizarlo, primero deberemos consultar el map "carnet", y una vez sepamos en que lista de puntos esta
	//utilizaremos su iterador (asociado unicamente a esa lista)
	//La razon de tener el iterador de cada dni es porque en el futuro tendremos un dni que se añadio hace tiempo,
	//y se ha actualizado el valor de sus puntos, por lo que se debe borrar (para esto utilizamos el iterador)
	std::unordered_map<dniConductor, listaDeConductores::iterator> iteradores;

public:

	//Coste O(1), es decir, coste constante amortizado porque estamos utilizando un hashmap
	void nuevo(std::string dni) {
		if (carnet.count(dni) == 1) //Si el dni ya esta registrado en el map, lanzamos excepcion
			throw std::domain_error("Conductor duplicado");
		carnet.insert({ dni, MAX_PUNTOS });

		//Como el conductor es nuevo, en este caso es el que menos lleva con esos puntos, por lo que insertamos el primero
		mapDeListaPorPuntos[MAX_PUNTOS].insert(mapDeListaPorPuntos[MAX_PUNTOS].begin(), dni);

		iteradores[dni] = mapDeListaPorPuntos[MAX_PUNTOS].begin(); //Guardamos su iterador asociado, que en este caso es la pos inicial.
	}

	
	void quitar(std::string dni, int puntos) {
		if (carnet.count(dni) == 0)
			throw std::domain_error("Conductor inexistente");

		auto & ref = carnet[dni];
		//IMPORTANTE: si los puntos del conductor no cambian NO SE TIENE QUE MOVER DE SU POSICION EN LA LISTA
		if (puntos != 0 && ref != MIN_PUNTOS) {
			//Elimino el dni de la lista utilizando el iterador asociado. Coste ???????
			mapDeListaPorPuntos[ref].erase(iteradores[dni]);

			ref -= std::abs(puntos); //Por si el numero pasado por parametro fuera negativo
			if (ref < MIN_PUNTOS) ref = MIN_PUNTOS;

			mapDeListaPorPuntos[ref].insert(mapDeListaPorPuntos[ref].begin(), dni);
			iteradores[dni] = mapDeListaPorPuntos[ref].begin();
		}
	}

	void recuperar(std::string dni, int puntos) {
		if (carnet.count(dni) == 0)
			throw std::domain_error("Conductor inexistente");

		auto & ref = carnet[dni];
		if (puntos != 0 && ref != MAX_PUNTOS) {
			//Elimino el dni de la lista utilizando el iterador asociado. Coste ???????
			mapDeListaPorPuntos[ref].erase(iteradores[dni]);

			ref += std::abs(puntos);
			if (ref > MAX_PUNTOS) ref = MAX_PUNTOS;


			mapDeListaPorPuntos[ref].insert(mapDeListaPorPuntos[ref].begin(), dni);
			iteradores[dni] = mapDeListaPorPuntos[ref].begin();
		}
	}

	
	int consultar(std::string dni) {
		if (carnet.count(dni) == 0)
			throw std::domain_error("Conductor inexistente");
		return carnet[dni];
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos < MIN_PUNTOS || puntos > MAX_PUNTOS)
			throw std::domain_error("Puntos no validos");

		return mapDeListaPorPuntos[puntos].size();
	}

	std::list<dniConductor> lista_por_puntos(int puntos) {
		if (puntos < MIN_PUNTOS || puntos > MAX_PUNTOS)
			throw std::domain_error("Puntos no validos");

		return mapDeListaPorPuntos[puntos];
	}

};


#endif // !CARNET_PUNTOS_H
