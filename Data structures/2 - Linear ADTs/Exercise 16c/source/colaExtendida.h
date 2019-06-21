#ifndef COLAEXTENDIDA_H
#define COLAEXTENDIDA_H

#include "queue_eda.h"
#include <iostream>

template <typename T>
class colaExtendida : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

	void eliminarPosicionesPares(Nodo * actual, Nodo * anterior, int pos) {
		if (actual == queue<T>::ult) {
			if (pos % 2 == 0) {
				anterior->sig = nullptr;
				queue<T>::ult = anterior;
			}
		}
		else {
			eliminarPosicionesPares(actual->sig, actual, pos + 1);
			if (pos % 2 == 0) {
				anterior->sig = actual->sig;
			}
		}
	}

public:
	void mostrarNodos() const {
		Nodo * nodoActualPtr = queue<T>::prim;
		while (nodoActualPtr != nullptr) {
			std::cout << nodoActualPtr->elem << " ";
			nodoActualPtr = nodoActualPtr->sig;
		}
		std::cout << std::endl;
	}

	void eliminarElementosPares() {
		if(queue<T>::nelems > 1)
			eliminarPosicionesPares(queue<T>::prim->sig, queue<T>::prim, 2);
		if(queue<T>::nelems % 2 == 0) queue<T>::nelems /= 2;
		else queue<T>::nelems = queue<T>::nelems / 2 + 1;
	}

};

#endif // !COLAEXTENDIDA_H