#ifndef HORAS_H
#define HORAS_H

#include <iostream>

class horas {
private:
	int h, m, s;

	bool comprobarValidez(int hora, int minuto, int segundo) const {
		if (hora < 0 || hora > 23) return false;
		else if (minuto < 0 || minuto > 59) return false;
		else if (segundo < 0 || segundo > 59) return false;
		return true;
	}

public:

	horas():h(0),m(0),s(0){}
	horas(int hora, int minuto, int segundo) {
		if (!comprobarValidez(hora,minuto,segundo))
			throw "ERROR"; // si la fecha introducida es erronea lanzamos una excepcion con texto "ERROR"
		this->h = hora;
		this->m = minuto;
		this->s = segundo;
	}

	int getHora () const { return h; }
	int getMinuto() const { return m; }
	int getSegundo() const { return s; }

	bool operator<(horas const& h2) {
		if (h > h2.getHora()) return false;
		else if(h == h2.getHora()) {
			if (m > h2.getMinuto()) return false;
			else if (m == h2.getMinuto()) {
				if (s >= h2.getSegundo()) return false;
				
			}
		}
		return true;
	}

};

inline std::ostream& operator<<(std::ostream& out, horas h) {
	int hora = h.getHora(), minuto = h.getMinuto(), segundo = h.getSegundo();

	if (hora < 10) out << "0" << hora;
	else out << hora;

	out << ":";

	if (minuto < 10) out << "0" << minuto;
	else out << minuto;

	out << ":";

	if (segundo < 10) out << "0" << segundo;
	else out << segundo;
	
	return out;
}

inline std::istream& operator>>(std::istream& in, horas & h) {
	int hora, min, seg;
	char vacio;
	in >> hora;
	in >> vacio;
	in >> min;
	in >> vacio;
	in >> seg;
	h = horas(hora, min, seg);
	return in;
}

#endif