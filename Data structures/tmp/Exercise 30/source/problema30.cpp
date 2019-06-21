// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

typedef std::string tClave;
typedef unsigned int tValor;

//Funcion para leer los diccionarios del fichero de texto
void leerDatos(std::map<tClave, tValor> & dAntiguo, std::map<tClave, tValor> & dNuevo) {
	std::string linea1, linea2;
	getline(std::cin, linea1);
	getline(std::cin, linea2);

	std::stringstream ss(linea1);
	while (ss) {
		std::pair<tClave, tValor> parLeido;
		ss >> parLeido.first;
		ss >> parLeido.second;
		dAntiguo.insert(parLeido);
	}

	std::stringstream ss2(linea2);
	while (ss2) {
		std::pair<tClave, tValor> parLeido;
		ss2 >> parLeido.first;
		ss2 >> parLeido.second;
		dNuevo.insert(parLeido);
	}
}

//Funcion que resuelve el problema, implementando un algoritmo similar al de mezcla de listas ordenadas
void resolver(std::map<tClave, tValor> const& dAntiguo, std::map<tClave, tValor> const& dNuevo, 
	std::vector<tClave> & clavesNuevas, std::vector<tClave> & clavesEliminadas, std::vector<tClave> & clavesModificadas) {

	auto itAntiguo = dAntiguo.cbegin();
	auto itNuevo = dNuevo.cbegin();

	tClave ultimaClave;

	//En esta parte se comprueban si hay elementos nuevos antes del primer elemento antiguo.
	while (itNuevo->first < itAntiguo->first) {
		clavesNuevas.push_back(itNuevo->first);
		++itNuevo;
	}

	//En esta parte se consultan los diccionarios nuevo y antiguo de manera combinada
	while (itAntiguo != dAntiguo.cend() && itNuevo != dNuevo.cend()) {

		if (itAntiguo->first == itNuevo->first && itAntiguo->second == itNuevo->second) { //Si los valores antiguos y nuevos coinciden
			++itAntiguo;
			++itNuevo;
		}

		else if (itAntiguo->first < itNuevo->first) { //Si se elimina una clave
			clavesEliminadas.push_back(itAntiguo->first);
			++itAntiguo;
		}

		else if (itAntiguo->first == itNuevo->first && itAntiguo->second != itNuevo->second) { //Valor modificado
			clavesModificadas.push_back(itAntiguo->first);
			++itAntiguo;
			++itNuevo;
		}

		else if (itAntiguo->first > itNuevo->first) { //Si se añade una clave
			clavesNuevas.push_back(itNuevo->first);
			++itNuevo;
		}
	}

	//Si entramos aqui, quiere decir que quedan claves por analizar en dAntiguo; es decir, son claves que se han eliminado.
	while (itAntiguo != dAntiguo.cend()) {
		clavesEliminadas.push_back(itAntiguo->first);
		++itAntiguo;
	}

	// Si entramos aqui quiere decir que quedan claves por analizar en dNuevo; es decir, son claves que se han añadido.
	while (itNuevo != dNuevo.cend()) {
		clavesNuevas.push_back(itNuevo->first);
		++itNuevo;
	}
}

//Funcion que muestra la solucion de cada caso de prueba
void mostrarInformacion(std::vector<tClave> const& clavesNuevas,
	std::vector<tClave> const& clavesEliminadas, std::vector<tClave> const& clavesModificadas) {

	if (clavesNuevas.size() > 0 || clavesEliminadas.size() > 0 || clavesModificadas.size() > 0) {
		if (clavesNuevas.size() > 0) std::cout << "+ ";
		for (int i = 0; i < clavesNuevas.size(); ++i) std::cout << clavesNuevas[i] << " ";
		if (clavesNuevas.size() > 0) std::cout << std::endl;

		if (clavesEliminadas.size() > 0) std::cout << "- ";
		for (int i = 0; i < clavesEliminadas.size(); ++i) std::cout << clavesEliminadas[i] << " ";
		if (clavesEliminadas.size() > 0) std::cout << std::endl;

		if (clavesModificadas.size() > 0) std::cout << "* ";
		for (int i = 0; i < clavesModificadas.size(); ++i) std::cout << clavesModificadas[i] << " ";
		if (clavesModificadas.size() > 0) std::cout << std::endl;
	}
	else {
		std::cout << "Sin cambios" << std::endl;
	}

	std::cout << "----" << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    
	// Creamos e inicializamos los datos necesarios

	std::map<tClave, tValor> dAntiguo;
	std::map<tClave, tValor> dNuevo;
	
	std::vector<tClave> clavesNuevas;
	std::vector<tClave> clavesEliminadas;
	std::vector<tClave> clavesModificadas;

	leerDatos(dAntiguo, dNuevo);
	
	// Operamos con los datos

	resolver(dAntiguo, dNuevo, clavesNuevas, clavesEliminadas, clavesModificadas); 

	// Mostramos la informacion final

	mostrarInformacion(clavesNuevas, clavesEliminadas, clavesModificadas);
	
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
	std::cin.ignore(); //OJO: importante, evitamos leer el salto de linea restante de la primera linea al hacer getline.
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}