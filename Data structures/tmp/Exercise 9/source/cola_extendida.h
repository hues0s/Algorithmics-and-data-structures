#ifndef COLA_EXTENDIDA_H
#define COLA_EXTENDIDA_H

#include <iostream>
#include "queue_eda.h"

template<typename T>
class ColaExtendida : public queue<T> {

	using Nodo = typename queue<T>::Nodo; //Util saberlo: utilizamos el tipo de dato Nodo definido en la clase "queue"

	void invertirNodos(Nodo * anterior);

public:
	void mostrarCola() const;
	void invertirNodos();
};

//Implementaciones

template<typename T>
void ColaExtendida<T>::mostrarCola() const {

	Nodo * nodoActualPtr = ColaExtendida<T>::prim;
	for (int i = 0; i < ColaExtendida<T>::size(); ++i) {
		std::cout << nodoActualPtr->elem << " ";
		nodoActualPtr = nodoActualPtr->sig;
	}
	std::cout << std::endl;
}

template<typename T>
void ColaExtendida<T>::invertirNodos(Nodo * anterior) {

	if (ColaExtendida<T>::prim == ColaExtendida<T>::ult) { // Caso base
		ColaExtendida<T>::prim->sig = anterior;
	}
	else {
		Nodo * aux = ColaExtendida<T>::prim;

		ColaExtendida<T>::prim = ColaExtendida<T>::prim->sig;
		ColaExtendida<T>::invertirNodos(aux);
		aux->sig = anterior;
		ColaExtendida<T>::ult = anterior;

	}
}

template<typename T>
void ColaExtendida<T>::invertirNodos() {
	ColaExtendida<T>::invertirNodos(ColaExtendida<T>::prim);
	ColaExtendida<T>::ult->sig = nullptr;
}

#endif // !COLA_EXTENDIDA