#ifndef COLA_EXTENDIDA_H
#define COLA_EXTENDIDA_H

#include <iostream>
#include "queue_eda.h"

template<typename T>
class ColaExtendida : public queue<T> {

	using Nodo = typename queue<T>::Nodo; //Util saberlo: utilizamos el tipo de dato Nodo definido en la clase "queue"

public:
	void mostrarCola() const;
	void insertarListaAuxiliar(ColaExtendida<T> & listaAux, unsigned long long int P);
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
void ColaExtendida<T>::insertarListaAuxiliar(ColaExtendida<T> & listaAux, unsigned long long int P) {
	Nodo * nodoActualPtr = ColaExtendida<T>::prim;
	Nodo * anterior = ColaExtendida<T>::prim;
	for (int i = 0; i < P; ++i) { // Colocamos el puntero a nodo en la posicion donde debemos insertar la sublista
		anterior = nodoActualPtr;
		nodoActualPtr = nodoActualPtr->sig;
	}

	if (P == 0) {
		ColaExtendida<T>::prim = listaAux.prim;
		listaAux.ult->sig = nodoActualPtr;
	}
	else if (P == ColaExtendida<T>::size()) {
		ColaExtendida<T>::ult = listaAux.ult;
		anterior->sig = listaAux.prim;
	}
	else {
		anterior->sig = listaAux.prim;
		listaAux.ult->sig = nodoActualPtr;
	}
	ColaExtendida<T>::nelems += listaAux.nelems;

	//La lista auxiliar debe quedar vacia, por lo que su puntero inicial debe ser nullptr.
	listaAux.prim = nullptr;
	
	//No hace falta pero por seguridad ponemos el puntero al final de la lista a nullptr.
	listaAux.ult = nullptr;
}

#endif // !COLA_EXTENDIDA