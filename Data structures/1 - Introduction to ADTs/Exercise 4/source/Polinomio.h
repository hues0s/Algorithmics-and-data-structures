#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <vector>
#include <cmath>
#include <algorithm>

struct monomio {
	int coeficiente;
	int exponente;
};

inline bool operator>(monomio m1, monomio m2);
inline bool operator<(monomio m1, monomio m2);
inline bool operator==(monomio m1, monomio m2);

class Polinomio {

	std::vector<monomio> v;

public:
	Polinomio() {};

	void anadirMonomio(int c, int exp) {
		if (c != 0) {
			monomio mParcial = { c,exp };
			bool anadido = false;
			if (v.size() == 0) {
				v.push_back(mParcial);
				anadido = true;
			}

			if (!anadido) {
				//Busqueda binaria para encontrar la posicion de un elemento igual o mayor
				auto iterator = std::lower_bound(v.begin(), v.end(), mParcial);
				int pos = std::distance(v.begin(), iterator);
				
				if (!(pos >= 0 && pos < v.size())) v.push_back(mParcial);
				else {
					if (v[pos] == mParcial) {
						v[pos].coeficiente += c;
						anadido = true;
					}
					if (v[pos] > mParcial) { // meter el nuevo elemento en su posicion correcta directamente
						monomio aux = v[v.size() - 1];
						for (unsigned int j = v.size() - 1; j > pos; j--) v[j] = v[j - 1];
						v[pos] = mParcial;
						v.push_back(aux);
						anadido = true;
					}
				}
			}
		}
	}

	long long int evaluarPolinomio(int x) const {
		long long int sol = 0;
		long long int potencia = 1;
		unsigned int vectorCounter = 0;
		for (int i = 0; i <= v[v.size() - 1].exponente; ++i) {
			if (v[vectorCounter].exponente == i) {
				sol += v[vectorCounter].coeficiente * potencia;
				++vectorCounter;
			}
			potencia *= x;
		}
		return sol;
	}
	
};

inline bool operator>(monomio m1, monomio m2) {
	if (m1.exponente > m2.exponente) return true;
	return false;
}

inline bool operator<(monomio m1, monomio m2) {
	if (m1.exponente < m2.exponente) return true;
	return false;
}

inline bool operator==(monomio m1, monomio m2) {
	if (m1.exponente == m2.exponente) return true;
	return false;
}


#endif
