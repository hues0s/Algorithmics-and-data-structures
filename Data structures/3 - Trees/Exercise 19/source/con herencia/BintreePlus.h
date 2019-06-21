#ifndef BINTREEPLUS_H
#define BINTREEPLUS_H

#include "bintree_eda.h"

template <typename T>
class BintreePlus : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	//Constructores
	BintreePlus() : bintree<T>() {}
	BintreePlus(BintreePlus<T> const& l, T const& e, BintreePlus<T> const& r) : bintree<T>(l, e, r) {}


	//Operaciones
	int getNumNodos() const { return getNumNodos(this->raiz); }

	int getNumHojas() const { return getNumHojas(this->raiz); }

	int getAltura() const { return getAltura(this->raiz); }

private:
	int getNumNodos(Link raiz) const {
		if (raiz == nullptr) {
			return 0;
		}
		else {
			int nodosIz = getNumNodos(raiz->left);
			int nodosDr = getNumNodos(raiz->right);
			return nodosIz + nodosDr + 1;
		}
	}

	int getNumHojas(Link raiz) const {
		if (raiz == nullptr) {
			return 0;
		}
		else {
			int hojasIz = getNumHojas(raiz->left);
			int hojasDr = getNumHojas(raiz->right);
			if (raiz->left == nullptr && raiz->right == nullptr) ++hojasDr; //Nos ahorramos crear otra variable
			return hojasIz + hojasDr;
		}
	}

	int getAltura(Link raiz) const {
		if (raiz == nullptr) {
			return 0;
		}
		else {
			int alturaIz = getAltura(raiz->left) + 1;
			int alturaDr = getAltura(raiz->right) + 1;
			if (alturaIz >= alturaDr) return alturaIz;
			return alturaDr;
		}
	}

};

// lee un árbol binario EXTENDIDO de la entrada estándar
template <typename T>
inline BintreePlus<T> leerBintreePlus(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerBintreePlus(vacio);
		auto dr = leerBintreePlus(vacio);
		return { iz, raiz, dr };
	}
}

#endif