
//10^9 es la mayor potencia que cabe en un int
//10^18 es ya long long int

/*

	DUDAS: es mejor utilizar at o []
	cual tiene menos coste

*/

// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

/*
		Explicación general: 

		- Si no existe el capitulo leido se inserta.
		- Si existe, 2 alternativas:
			-- Si el ultimo dia de emision de ese capitulo se encuentra dentro del intervalo, se comprueba si hay que actualizar
				numMaxDias, y despues se resetea el intervalo. Por ultimo, se actualiza su valor con i.
			-- Si el ultimo dia de emision se encuentra fuera del intervalo, simplemente actualizamos su valor con i, ya que 
				es un valor valido dentro de ese intervalo.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>

typedef int tNumeroCapitulo;
typedef int tUltimoDiaEmitido;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	std::unordered_map<tNumeroCapitulo, tUltimoDiaEmitido> serie;
	int numCapitulosEmitidos;
	std::cin >> numCapitulosEmitidos;

	tNumeroCapitulo capituloLeido;
	int primerDia = 0, ultimoDia, numMaxDias = 0, numDiasParcial;


	for (int i = 0; i < numCapitulosEmitidos; ++i) {

		std::cin >> capituloLeido;

		if (serie.count(capituloLeido) == 0) { //Si el capitulo leido no se encuentra en el diccionario
			//Insertamos el numero de capitulo y el dia en el que se ha emitido
			serie.insert({ capituloLeido, i });
		}

		else { //Si el capitulo leido SI se encuentra en el diccionario
			
			//Ahora comprobamos si la ultima i de este capitulo se encuentra dentro del intervalo actual
			//Si asi fuera, entramos al if y reseteamos el intervalo
			if (serie[capituloLeido] >= primerDia) {
				ultimoDia = i - 1;
				numDiasParcial = ultimoDia - primerDia + 1;
				if (numDiasParcial > numMaxDias)
					numMaxDias = numDiasParcial;
				primerDia = serie[capituloLeido] + 1;
			}
			
			//Actualizamos el dia de emision de este capitulo en concreto
			serie[capituloLeido] = i;
		}
	}
	
	//Esta comprobacion se hace por si se diera el caso de que el ultimo capitulo leido generara un intervalo mayor,
	//ya que entonces habria que actualizar el valor de la variable numMaxDias.
	if (serie[capituloLeido] >= primerDia) {
		ultimoDia = numCapitulosEmitidos - 1;
		numDiasParcial = ultimoDia - primerDia + 1;
		if (numDiasParcial > numMaxDias)
			numMaxDias = numDiasParcial;
	}

	std::cout << numMaxDias << std::endl;

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