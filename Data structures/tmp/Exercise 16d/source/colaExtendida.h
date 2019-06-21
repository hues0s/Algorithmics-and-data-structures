#ifndef COLAEXTENDIDA_H
#define COLAEXTENDIDA_H

#include "queue_eda.h"
#include <iostream>

template <typename T>
class colaExtendida : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:

	void mostrarNodos() {
		Nodo * actual = queue<T>::prim;
		while (actual != nullptr) {
			std::cout << actual->elem << " ";
			actual = actual->sig;
		}
		std::cout << std::endl;
	}

	//no puede ser recursiva porque hay que tener en cuenta las eliminaciones de izquierda a derecha
	void eliminarMenores() {
		Nodo * actual = queue<T>::prim->sig;
		Nodo * anterior = queue<T>::prim;

		while (actual != nullptr) {

			if (actual->elem < anterior->elem) {
				anterior->sig = actual->sig;
				--queue<T>::nelems; 
			}
			else anterior = actual; //el anterior solo hay que cambiarlo si no se cumple la condicion, porque
									//si se cumple, habra que comprobar si el nuevo elemento siguiente tambies es < que anterior.
			actual = actual->sig;
			
		}

	}

};



#endif // !COLAEXTENDIDA_H
