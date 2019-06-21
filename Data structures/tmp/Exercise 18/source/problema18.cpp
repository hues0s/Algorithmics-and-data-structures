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

template <typename T>
int calcularPrecarios(Nodo<T> * raiz, unsigned int numJefes, int alturaAcumulada) {
	//Los becarios son todas las hojas del arbol
	if (raiz->elem == 0) {
		if (alturaAcumulada > numJefes) return 1;
		else return 0;
	}
	else {
		int p = 0;
		for (size_t i = 0; i < raiz->elem; ++i) p += calcularPrecarios(raiz->hijos[i], numJefes, alturaAcumulada + 1);
		return p;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	unsigned int numJefes;
	std::cin >> numJefes;
    if (! std::cin)
        return false;
    
	Nodo<int> * rz = leer(0);
    
    // calcular y escribir sol
	int numPrecarios = calcularPrecarios(rz, numJefes, 1);
	std::cout << numPrecarios << std::endl;
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}