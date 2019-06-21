#ifndef  BINTREEPLUS_H
#define BINTREEPLUS_H



#include "bintree_eda.h"

template <typename T>
class BintreePlus : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:
	BintreePlus():bintree<T>(){}
	BintreePlus(BintreePlus<T> const& l, T const& e, BintreePlus<T> const& r) : bintree<T>(l,e,r){}

	void calcularFrontera(std::vector<T> & frontera) const { calcularFrontera(this->raiz, frontera); }

private:
	void calcularFrontera(Link raiz, std::vector<T> & frontera) const {
		if(raiz == nullptr) {} //arbol vacio, por lo que dejamos de buscar mas abajo
		else {
			calcularFrontera(raiz->left, frontera);
			calcularFrontera(raiz->right, frontera);
			if (raiz->left == nullptr && raiz->right == nullptr) frontera.push_back(raiz->elem);
		}
	}

};


// lee un árbol binario de la entrada estándar
template <typename T>
inline BintreePlus<T> leerArbolPlus(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolPlus(vacio);
		auto dr = leerArbolPlus(vacio);
		return { iz, raiz, dr };
	}
}

#endif