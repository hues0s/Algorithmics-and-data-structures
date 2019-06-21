#ifndef COLA_EXTENDIDA_H
#define COLA_EXTENDIDA_H

#include <iostream>
#include "queue_eda.h"

template<typename T>
class ColaExtendida : public queue<T> {

	using Nodo = typename queue<T>::Nodo; //Util saberlo: utilizamos el tipo de dato Nodo definido en la clase "queue"

public:
	void mostrarCola() const;
	void duplicarElementos();
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
void ColaExtendida<T>::duplicarElementos() {

	//Implementacion colocando los nodos duplicados delante de sus originales

	int sizeOriginal = ColaExtendida<T>::size();
	Nodo * nodoActualPtr = ColaExtendida<T>::prim;
	Nodo * NodoDup = NULL;
	Nodo * nodoPorAjustar = NULL;

	for (int i = 0; i < sizeOriginal; ++i) {
		NodoDup = new Nodo(nodoActualPtr->elem);
		if (i == 0) {
			NodoDup->sig = nodoActualPtr;
			ColaExtendida<T>::prim = NodoDup;
			nodoPorAjustar = nodoActualPtr;
		}
		else {
			NodoDup->sig = nodoActualPtr;
			nodoPorAjustar->sig = NodoDup;
			nodoPorAjustar = nodoActualPtr;
		}
		++ColaExtendida<T>::nelems;
		nodoActualPtr = NodoDup->sig->sig;
	}
}

#endif // !COLA_EXTENDIDA_H
