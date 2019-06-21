#ifndef FECHA_H
#define FECHA_H


class fecha {

	int dia, hora, minuto;

public:

	fecha(int d, int h, int m) : dia(d), hora(h), minuto(m) {}

	int getDia() const { return dia; }
	int getHora() const { return hora; }
	int getMinuto() const { return minuto; }

	bool operator<(fecha const& f2) const {
		if (dia < f2.getDia()) return true;
		else if (dia > f2.getDia()) return false;
		else {
			if (hora < f2.getHora()) return true;
			else if (hora > f2.getHora()) return false;
			else return minuto < f2.getMinuto();
		}
	}

};


#endif // !FECHA_H
