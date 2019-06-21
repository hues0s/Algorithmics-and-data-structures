#ifndef BINTREEPLUS_H
#define BINTREEPLUS_H

#include "bintree_eda.h"

template <typename T>
class BintreePlus : public bintree<T> {
	using Link = typename bintree<T>::Link;
public:
	BintreePlus() : bintree<T> () {}
	BintreePlus(BintreePlus<T> const& l, T const& e, BintreePlus<T> const& r) : bintree<T> (l,e,r) {}

	T calcularElementoMinimo(const T maximo) const { return calcularElementoMinimo(this->raiz, maximo); }

private:
	T calcularElementoMinimo(Link const& raiz, const T maximo) const {
		if (raiz == nullptr) {
			return maximo;
		}
		else {
			T iz = calcularElementoMinimo(raiz->left, maximo);
			T dr = calcularElementoMinimo(raiz->right, maximo);
			if (raiz->elem < iz && raiz->elem < dr) return raiz->elem;
			else return std::min(iz, dr);
		}
	}
};

// lee un árbol binario de la entrada estándar
template <typename T>
inline BintreePlus<T> leerArbolExt(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolExt(vacio);
		auto dr = leerArbolExt(vacio);
		return { iz, raiz, dr };
	}
}
#endif // !BINTREEPLUS_H