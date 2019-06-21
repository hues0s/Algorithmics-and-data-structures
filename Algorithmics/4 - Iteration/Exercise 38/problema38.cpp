// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// Descripción de la función: 
// Coste: 
void resolver(std::vector<int> vagones, int numVagonesAsalto) {

	int vagonSeleccionado = -1;
	int gananciaMaxima = -1;
	for (int i = 0; i < vagones.size() - numVagonesAsalto + 1; ++i){
		int gananciaParcial = 0;
		for (int j = i; j < i + numVagonesAsalto; ++j) gananciaParcial += vagones[j];
		if (gananciaParcial >= gananciaMaxima) {
			gananciaMaxima = gananciaParcial;
			vagonSeleccionado = i;
		}
	}
	std::cout << vagonSeleccionado << " " << gananciaMaxima << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int totalVagones, numVagonesAsalto;
	std::cin >> totalVagones;
	std::cin >> numVagonesAsalto;
	std::vector<int> vagones(totalVagones);
	for (int i = 0; i < totalVagones; ++i) std::cin >> vagones[i];
	resolver(vagones, numVagonesAsalto);
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