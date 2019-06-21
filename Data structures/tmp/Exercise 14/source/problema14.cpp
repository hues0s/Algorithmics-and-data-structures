// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <deque>
#include <stack>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	std::string mensaje;
	getline(std::cin, mensaje);
    if (! std::cin)
        return false;
    
	//X'' -> X'
	std::deque<char> x;
	if (mensaje.length() % 2 == 0) {
		for (int i = mensaje.length() - 2; i >= 0; i -= 2) {
			x.push_front(mensaje[i]);
			x.push_back(mensaje[i + 1]);
		}
	}
	else {
		x.push_front(mensaje[mensaje.length() - 1]); //como es impar, metemos primero el elemento que no va a ir emparejado, 
															//que ira en medio
		for (int i = mensaje.length() - 3; i >= 0; i -= 2) {
			x.push_front(mensaje[i]);
			x.push_back(mensaje[i + 1]);
		}
	}
	
	//X' -> X
	std::stack<char> pila;
	std::string mensajeFinal = "";
	while (!x.empty()) {
		if (x.front() == 'a' || x.front() == 'e' || x.front() == 'i' || x.front() == 'o' || x.front() == 'u' 
			|| x.front() == 'A' || x.front() == 'E' || x.front() == 'I' || x.front() == 'O' || x.front() == 'U') {
			while (!pila.empty()) {
				mensajeFinal += pila.top();
				pila.pop();
			}
			mensajeFinal += x.front();
		}
		else {
			pila.push(x.front());
		}
		x.pop_front();
	}

	//Hacemos comprobacion final, porque puede ser que no se encuentre vocal pero si que haya elementos en la pila
	while (!pila.empty()) {
		mensajeFinal += pila.top();
		pila.pop();
	}

    
	std::cout << mensajeFinal << std::endl;

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