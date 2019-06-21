// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "claseSet.h"
#include <stack>

template <typename T>
void resolver(set<T> s, int k) {
	//O(k)
	for (int i = 0; i < k; ++i) {
		std::cout << s.getMinimumValue() << " ";
		s.eraseMinimumValue();
	}
	std::cout << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char elementType;
    std::cin >> elementType;
    if (!std::cin)
        return false;
    int k;
    std::cin >> k;
    
    if(elementType == 'N'){
        set<unsigned long int> s1(1);
        unsigned long int lectura;
        std::cin >> lectura;
        while(lectura != -1){
			if (s1.size() < k) s1.insert(lectura);
			else if (s1.size() == k && lectura > s1.getMinimumValue() && !s1.contains(lectura)) {
				s1.eraseMinimumValue();
				s1.insert(lectura);
			}
            std::cin >> lectura;
        }
		resolver(s1, k);
    }
    else if(elementType == 'P'){
        set<std::string> s2(1);
        std::string lectura2;
        std::cin >> lectura2;
        while(lectura2 != "FIN"){
			if(s2.size() < k) s2.insert(lectura2);
			else if (s2.size() == k && lectura2 > s2.getMinimumValue() && !s2.contains(lectura2)) {
				s2.eraseMinimumValue();
				s2.insert(lectura2);
			}
            std::cin >> lectura2;
        }
		resolver(s2, k);
    }
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