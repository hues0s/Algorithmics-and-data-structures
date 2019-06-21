// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>

//Funcion que nos devuelve el complementario a uno de los char
char getComplementary(char c) {
	switch (c) {
	case ')':
		return '(';
		break;
	case ']':
		return '[';
		break;
	case '}':
		return '{';
		break;
	}
}

// Descripción de la función: 
// Coste: 
bool resolver(std::string const& l, std::stack<char> & pila) {
    
	for (size_t i = 0; i < l.length(); ++i) {
		if (l[i] == '(' || l[i] == '{' || l[i] == '[') { pila.push(l[i]); }
		else if (l[i] == ')' || l[i] == '}' || l[i] == ']') {
			if (pila.empty()) return false;
			else if (pila.top() != getComplementary(l[i])) return false;
			else pila.pop();
		}
	}
	if (!pila.empty()) return false;
	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	std::string l;
	getline(std::cin, l);
    if (! std::cin)
        return false;
    
	std::stack<char> pila;
    bool sol = resolver(l, pila);
    
    // escribir sol
	if (sol) std::cout << "SI\n";
	else std::cout << "NO\n";
    
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