#ifndef HORAS
#define HORAS

#include <iostream>
#include <stdexcept>
#include <iomanip>

class Horas {

private: //No es necesario
	const int LIMITE_INFERIOR = 0, LIMITE_SUPERIOR_HORAS = 23, LIMITE_SUPERIOR_MINUTOS_SEGUNDOS = 59;
	int hora, minuto, segundo;

public:

	Horas(){}
	Horas(int h, int m, int s): hora(h), minuto(m), segundo(s){
		if (h < LIMITE_INFERIOR || h > LIMITE_SUPERIOR_HORAS)
			throw std::invalid_argument("La hora introducida no es válida");
		else if (m < LIMITE_INFERIOR || m > LIMITE_SUPERIOR_MINUTOS_SEGUNDOS)
			throw std::invalid_argument("El minuto introducido no es correcto");
		else if (s < LIMITE_INFERIOR || s > LIMITE_SUPERIOR_MINUTOS_SEGUNDOS)
			throw std::invalid_argument("El segundo introducido no es correcto");
	}

	int getHora() const { return hora; }
	int getMinuto() const { return minuto; }
	int getSegundo() const { return segundo; }


	bool operator<(Horas const& h) const {
		if (hora < h.getHora()) return true;
		else if (hora > h.getHora()) return false;
		else if (minuto < h.getMinuto()) return true;
		else if (minuto > h.getMinuto()) return false;
		else if (segundo < h.getSegundo()) return true;
		return false;
	}

	Horas operator=(Horas const& h) {
		hora = h.getHora();
		minuto = h.getMinuto();
		segundo = h.getSegundo();
		return *this;
	}
	
};

inline std::istream& operator>>(std::istream& in, Horas & h) {
	int hora, minuto, segundo;
	char vacio;
	in >> hora >> vacio >> minuto >> vacio >> segundo;
	h = Horas(hora, minuto, segundo);
	return in;
}

inline std::ostream& operator<<(std::ostream& out, Horas & h) {
	out << std::setw(2) << std::setfill('0') << h.getHora() << ":" <<
		std::setw(2) << std::setfill('0') << h.getMinuto() << ":" <<
		std::setw(2) << std::setfill('0') << h.getSegundo();
	return out;
}

#endif