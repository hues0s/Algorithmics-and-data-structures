#ifndef PELICULA_H
#define PELICULA_H

#include "Horas.h"
#include <string>
#include <iostream>

class Pelicula {

private:
	Horas horaFin;
	std::string titulo;

public:

	Pelicula(){}
	Pelicula(Horas hi, Horas d, std::string t) {
		horaFin = hi + d;
		titulo = t;
	}

	Horas getHoraFin() const { return horaFin; }
	std::string getTitulo() const { return titulo; }

	bool operator<(Pelicula const& p) const {
		if (horaFin < p.getHoraFin()) return true;
		else if (horaFin == p.getHoraFin()) {
			if (titulo < p.getTitulo()) return true;
			return false;
		}
		return false;
	}

};

inline std::istream& operator>>(std::istream& in, Pelicula & p) {
	Horas hi, d;
	std::string titulo;
	in >> hi >> d;
	std::getline(in, titulo);
	p = Pelicula(hi, d, titulo);
	return in;
}

inline std::ostream& operator<<(std::ostream& out, Pelicula const& p) {
	out << p.getHoraFin() << p.getTitulo();
	return out;
}

#endif