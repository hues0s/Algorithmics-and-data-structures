#ifndef CONSULTORIO_H
#define CONSULTORIO_H

#include "fecha.h"
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>

using medico = std::string;
using paciente = std::string;

using diaOcupado = int;

struct infoPaciente {
	paciente p;
	fecha f;
};

class consultorio {

	

	std::unordered_map<medico, std::map<fecha, paciente>> medicos;

	//Con este unordered map consigo que a la hora de devolver la lista de pacientes en x dia, si ese dia no esta
	//el coste sea constante, en lugar de lineal.
	std::unordered_map<medico, std::unordered_map<diaOcupado, int>> dias; //los dias guardados cambiaran en pideConsulta() y atiendeConsulta()

	

public:

	void nuevoMedico(medico const& m) {
		if (medicos.count(m) == 0) { //Solo añadimos el medico si no existe
			medicos[m];
		}
	}

	void pideConsulta(paciente const& p,medico const& m,fecha const& f) {
		if (medicos.count(m) == 0)
			throw "Medico no existente";
		if (medicos.count(m) == 1 && medicos[m].count(f) == 1)
			throw "Fecha ocupada";

		medicos[m][f] = p;
		
		++dias[m][f.getDia()]; //guardo el dia con contador de 1

	}

	paciente siguientePaciente(medico const& m) {
		if (medicos.count(m) == 0)
			throw "Medico no existente";
		if (medicos[m].size() == 0)
			throw "No hay pacientes";
		return medicos[m].begin()->second;
	}

	void atiendeConsulta(medico const& m) {
		if (medicos.count(m) == 0)
			throw "Medico no existente";
		if (medicos[m].size() == 0)
			throw "No hay pacientes";

		auto & ref = medicos[m];

		if(dias[m][medicos[m].begin()->first.getDia()] == 1)
			dias[m].erase(medicos[m].begin()->first.getDia()); // si solo tenia anotado un dia borro el dia
		else dias[m][medicos[m].begin()->first.getDia()]--; //Si no, solo resto 1 al contador


		medicos[m].erase(medicos[m].begin());
	}

	std::vector<infoPaciente> listaPacientes(medico const& m, int d) {
		if (medicos.count(m) == 0)
			throw "Medico no existente";

		std::vector<infoPaciente> v;

		if (dias[m].count(d) == 0) //Si ese medico no tiene ningun paciente ese dia, devolvemos el vector vacio.
			return v;

		//En primer lugar, busco el primer paciente 
		auto it = medicos[m].begin();
		while (it != medicos[m].end() && it->first.getDia() != d) ++it;
		//rellenamos el vector con los pacientes que tengan el dia d asociado
		while (it != medicos[m].end() && it->first.getDia() == d) {
			v.push_back({it->second, it->first});
			++it;
		}
		return v;
	}

};

#endif // !CONSULTORIO_H