// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

std::string imprimirResultado(long int solucion) {
	if (solucion == -1) return "NO EXISTE";
	else return std::to_string(solucion);
}

// Descripción de la función: 
// Coste: 
long int buscarDr(std::vector<unsigned short int> v, unsigned short int alturaBandido, long int ini, long int fin) {
	if (ini + 1 == fin) {//vector de 1 elemento
		if (v[ini] == alturaBandido) return ini;
		else return -1;
	}
	else if (ini + 2 == fin) { //vector de 2 elementos
		if (v[ini + 1] == alturaBandido) return ini + 1;
		else if (v[ini] == alturaBandido) return ini;
		else return -1;
	}
	else {
		long int mitad = (ini + fin) / 2;
		if (alturaBandido >= v[mitad]) return buscarDr(v, alturaBandido, mitad, fin);
		else return buscarDr(v, alturaBandido, ini, mitad);
	}
}

// Descripción de la función: 
// Coste: 
long int buscarIz(std::vector<unsigned short int> v, unsigned short int alturaBandido, long int ini, long int fin) {
	if (ini +1 == fin) {//vector de 1 elemento
		if (v[ini] == alturaBandido) return ini;
		else return -1;
	}
	else {
		long int mitad = (ini + fin - 1) / 2;
		if (alturaBandido > v[mitad]) return buscarIz(v, alturaBandido, mitad + 1, fin);
		else return buscarIz(v, alturaBandido, ini, mitad + 1);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	long int numeroSospechosos;
	unsigned short int alturaBandido;
	std::cin >> numeroSospechosos;
    if (! std::cin)
        return false;
	std::cin >> alturaBandido;
	std::vector<unsigned short int> v(numeroSospechosos);
	for (int i = 0; i < numeroSospechosos; ++i) std::cin >> v[i];
    
	long int solucionIz = buscarIz(v, alturaBandido, 0, numeroSospechosos);
	long int solucionDr = buscarDr(v, alturaBandido, 0, numeroSospechosos);

    // escribir sol
	if(solucionIz == solucionDr) std::cout << imprimirResultado(solucionIz) << std::endl;
	else std::cout << imprimirResultado(solucionIz) << " " << imprimirResultado(solucionDr) << std::endl;

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