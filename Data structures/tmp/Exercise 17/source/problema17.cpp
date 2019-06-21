// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

template <typename T>
struct Nodo {
	T elem;
	std::vector<Nodo<T> *> hijos;
};

//Lee un arbol en preorden y devuelve un puntero a su nodo raiz
template <typename T>
Nodo<T> * leer(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) {
		Nodo<T> * v = new Nodo<T>;
		v->elem = vacio;
		//v->hijos = nullptr;
		return v;
	}
	else {
		Nodo<T> * nd = new Nodo<T>;
		nd->elem = raiz;
		for (size_t i = 0; i < raiz; ++i) 
			nd->hijos.push_back(leer(vacio));
		return nd;
	}
}

//Calcula la altura del arbol, esto es, su rama mas larga, dada la raiz del arbol
template <typename T>
int calculoAltura(Nodo<T> * raiz) {
	if (raiz->elem == 0) {
		return 1;
	}
	else {
		int max = 0;
		int altura;
		for (size_t i = 0; i < raiz->elem; ++i) {
			altura = calculoAltura(raiz->hijos[i]) + 1;
			if (altura > max) max = altura;
		}
		return max;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	Nodo<int> * rz = leer(0);
	//Mostramos la altura del arbol leido por pantalla
	std::cout << calculoAltura(rz) << std::endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}