#ifndef COMPLEJOS_H
#define COMPLEJOS_H

#include <cmath>

template<typename T1, typename T2>
class Complejo {
private: 
	T1 a;
	T2 b;
public:

	Complejo(T1 iniA, T2 iniB): a(iniA), b(iniB) {}

	T1 getA() const { return a; }
	T2 getB() const { return b; }

	Complejo operator+(Complejo const& c) {
		a += c.getA();
		b += c.getB();
		return *this;
	}

	Complejo operator*(Complejo const& c) {
		T1 aParcial = a, cParcial = c.getA();
		T2 bParcial = b, dParcial = c.getB();
		/*No entiendo por que al hacer la instruccion return modifico tambien el Complejo c, ?¿!!solo utilizo getters*/
		
		a = aParcial*cParcial - bParcial*dParcial;
		b = aParcial*dParcial + cParcial*bParcial;
		return *this;
	}

	float modComplejo() const {
		return sqrt(a*a + b*b);
	}

};

#endif