#ifndef CARNET_PUNTOS_H
#define CARNET_PUNTOS_H

#include <unordered_map>
#include <stdexcept>

class carnet_puntos {

	const int MAX_PUNTOS = 15;
	const int MIN_PUNTOS = 0;

	//Creamos un hashmap para guardar cada dni con sus puntos asociados
	using dniConductor = std::string;
	using puntos = int;
	std::unordered_map<dniConductor, puntos> carnet;
	
	//Creamos otro hashmap para clasificar a los conductores por sus puntos asociados,
	//y asi poder obtener ese dato en tiempo amortizado constante
	using numConductores = int;
	std::unordered_map<puntos, numConductores> conductoresPorPuntos;

public:

	//Coste O(1), es decir, coste constante amortizado porque estamos utilizando un hashmap
	void nuevo(std::string dni) {
		if (carnet.count(dni) == 1) //Si el dni ya esta registrado en el map, lanzamos excepcion
			throw std::domain_error("Conductor duplicado");
		carnet.insert({ dni, MAX_PUNTOS });
		++conductoresPorPuntos[MAX_PUNTOS];
	}

	
	void quitar(std::string dni, int puntos) {
		if (carnet.count(dni) == 0)
			throw std::domain_error("Conductor inexistente");

		auto & ref = carnet[dni];

		--conductoresPorPuntos[ref]; //Restamos 1 del numero de conductores con ref puntos.

		ref -= puntos;
		if (ref < 0) ref = 0;

		++conductoresPorPuntos[ref]; //Sumamos 1 en el numero de conductores con ref (nuevo) puntos.


	}

	
	int consultar(std::string dni) {
		if (carnet.count(dni) == 0)
			throw std::domain_error("Conductor inexistente");
		return carnet[dni];
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos < MIN_PUNTOS || puntos > MAX_PUNTOS)
			throw std::domain_error("Puntos no validos");

		return conductoresPorPuntos[puntos];

		/*
		int n = 0;
		auto it = carnet.cbegin();
		while (it != carnet.cend()) {
			if (it->second == puntos)++n;
			++it;
		}
		return n;
		*/
	}

};


#endif // !CARNET_PUNTOS_H
