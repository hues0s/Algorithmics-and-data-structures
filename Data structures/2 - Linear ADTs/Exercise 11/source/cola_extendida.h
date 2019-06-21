#ifndef COLA_EXTENDIDA_H
#define COLA_EXTENDIDA_H

#include <iostream>
#include "queue_eda.h"

template<typename T>
class ColaExtendida : public queue<T> {

	using Nodo = typename queue<T>::Nodo; //Util saberlo: utilizamos el tipo de dato Nodo definido en la clase "queue"

public:
	void mostrarCola() const;
	void mezclarColas(ColaExtendida<T> & q2);
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
void ColaExtendida<T>::mezclarColas(ColaExtendida<T> & q2) {

	if (ColaExtendida<T>::nelems == 0) {
		ColaExtendida<T>::prim = q2.prim;
		ColaExtendida<T>::ult = q2.ult;
		ColaExtendida<T>::nelems = q2.nelems;
		q2.prim = nullptr;
		q2.ult = nullptr;
	}
	else if (q2.nelems == 0) {
		//No hacemos nada
	}
	else {

		Nodo * nodoActual = ColaExtendida<T>::prim;
		Nodo * nodoACopiar = q2.prim;
		Nodo * siguienteNodoQ2;
		Nodo * anterior = nodoActual;

		//Caso especial: si el primer elemento de q2 es < que el de q1
		if (nodoActual->elem > nodoACopiar->elem) {
			ColaExtendida<T>::prim = nodoACopiar;
			siguienteNodoQ2 = nodoACopiar->sig;
			nodoACopiar->sig = nodoActual;
			anterior = nodoACopiar;					//OJO: me faltaba esto. Si yo pongo como primer elemento al primer elemento de
													// la Q2, anterior ya no es el primer elemento de la Q1, sino de la Q2.
			nodoACopiar = siguienteNodoQ2;
		}

		while (nodoActual != nullptr  && nodoACopiar != nullptr) {
			if (nodoActual->elem <= nodoACopiar->elem) {
				anterior = nodoActual;
				nodoActual = nodoActual->sig;
			}
			else if (nodoActual->elem > nodoACopiar->elem) {
				anterior->sig = nodoACopiar;
				siguienteNodoQ2 = nodoACopiar->sig;
				nodoACopiar->sig = nodoActual;
				anterior = nodoACopiar;
				nodoACopiar = siguienteNodoQ2;
			}
		}

		if (nodoACopiar != nullptr) {
			anterior->sig = nodoACopiar;
			ColaExtendida<T>::ult = q2.ult;
		}

		ColaExtendida<T>::nelems += q2.nelems;
		q2.prim = nullptr;
		q2.ult = nullptr;
	}

}


#endif // !COLA_EXTENDIDA