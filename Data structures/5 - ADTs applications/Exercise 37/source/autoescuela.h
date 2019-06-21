#ifndef AUTOESCUELA_H
#define AUTOESCUELA_H

#include <string>
#include <unordered_map>
#include <set>
#include <map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stdexcept>

class autoescuela {

	const int MIN_PUNTOS = 0;

	using profesor = std::string;
	using alumno = std::string;

	using puntos = int;

	struct infoIterador{
		std::unordered_set<alumno>::iterator it;
		puntos puntosActuales;
		profesor profesorActual;
	};


	std::unordered_map<profesor, std::unordered_map<puntos, std::unordered_set<alumno>>> profesores;

	std::unordered_map<alumno, infoIterador> iteradores;


public:

	//constructora: al comienzo ningun profesor tiene asignados alumnos.
	autoescuela() {

	}

	//alta: sirve tanto para dar de alta a un alumno como para cambiarle de profesor.
	void alta(alumno const& a, profesor const& p) {

		//Si el alumno no existia, se inserta con una puntuacion de 0.
		if (iteradores.count(a) == 0) {
			auto & refIt = iteradores[a];
			refIt.it = profesores[p][MIN_PUNTOS].insert(a).first;
			refIt.puntosActuales = MIN_PUNTOS;
			refIt.profesorActual = p;
		}
		//Si ya existe, se le cambia de profesor, CONSERVANDO LA PUNTUACION.
		else {
				auto & refIt = iteradores[a];
			if (p != refIt.profesorActual) { //Si se le intenta dar de alta con el mismo profesor, no hacemos nada.
				//Insertamos con el nuevo profesor asociado
				std::unordered_set<alumno>::iterator itParcial = profesores[p][refIt.puntosActuales].insert(a).first;
				//Borramos del map del profesor viejo
				profesores[refIt.profesorActual][refIt.puntosActuales].erase(refIt.it);
				//actualizamos el valor del iterador asociado
				refIt.profesorActual = p;
				refIt.it = itParcial;
			}
		}

	}

	bool es_alumno(alumno const& a, profesor const& p) {
		if(iteradores.count(a) == 1) return iteradores[a].profesorActual == p;
		return false;
	}

	puntos puntuacion(alumno const& a) {
		if (iteradores.count(a) == 0) //si el alumno no esta registrado, lanzamos excepcion
			throw std::domain_error("El alumno " + a +" no esta matriculado");
		return iteradores[a].puntosActuales;
	}

	void actualizar(alumno const& a, int N) {
		if (iteradores.count(a) == 0) //si el alumno no esta registrado, lanzamos excepcion
			throw std::domain_error("El alumno " + a + " no esta matriculado");

		if (N > 0) { //Solo accederemos a los maps en caso de que REALMENTE haya que actualizar puntos
			auto & refIt = iteradores[a];
			int nuevosPuntos = N + refIt.puntosActuales;

			//Insertamos el alumno en la posicion del map que le corresponde
			std::unordered_set<alumno>::iterator itParcial = profesores[refIt.profesorActual][nuevosPuntos].insert(a).first;
			//Borramos al alumno de su antigua posicion en el map de puntos
			profesores[refIt.profesorActual][refIt.puntosActuales].erase(refIt.it);
			//Actualizamos los valores del map de iteradores
			refIt.it = itParcial;
			refIt.puntosActuales = nuevosPuntos;
		}

	}

	std::vector<alumno> examen(profesor const& p, int N) {
		auto & ref = profesores[p];
		
		std::vector<alumno> finalVector;

		//Voy a recorrer el map de puntos asociados al profesor P, copiando al vector aquellos alumnos que tengan >= N puntos
		auto it = ref.begin();
		while (it != ref.end()) {
			if (it->first >= N) {
				//Si he encontrado >= N puntos, copio los alumnos asociados al vector
				std::vector<alumno> k(ref[it->first].begin(), ref[it->first].end());
				finalVector.insert(finalVector.end(), k.begin(), k.end());
			}
			++it;
		}
		//Ordeno el vector por orden alfabetico
		std::sort(finalVector.begin(), finalVector.end());
		return finalVector;
	}

	void aprobar(alumno const& a) {
		if (iteradores.count(a) == 0) //si el alumno no esta registrado, lanzamos excepcion
			throw std::domain_error("El alumno " + a + " no esta matriculado");

		auto & refIt = iteradores[a];

		//Borro al alumno de su entrada en el map de profesores
		profesores[refIt.profesorActual][refIt.puntosActuales].erase(refIt.it);
		//Borro al alumno del map de iteradores
		iteradores.erase(a);
	}

};


#endif // !AUTOESCUELA_H