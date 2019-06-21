//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno : Alejandro Ruiz Valero y Héctor Ullate Catalán
// Usuario del juez de clase : E53(Alejandro) y E64(Héctor)
// Usuario del juez de examen que has utilizado en la prueba de hoy : E19
//
//***************************************************


/*
		Explicacion general:

		Rellenamos un diccionario conforme leemos las peliculas del fichero, junto
		con las fechas de emision de las peliculas, que se guardan en un vector.
		Este vector se recorrera para mostrar la salida correcta.

*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

// Declarar las librerias que se utilicen en el codigo
typedef std::string tNombrePelicula; //Tipo de dato que almacena el nombre de la pelicula que leemos.
typedef std::vector<std::string> tFechas; //Fechas asociadas a la pelicula leida.


bool resuelveCaso() {
    int numDias; 
    std::cin >> numDias;
    if (!std::cin) return false;
    
    // Declaracion de estructuras de datos
	std::map<tNombrePelicula, tFechas> peliculas;

    // Bucle de lectura de datos
    for (int i = 0; i < numDias; ++i) {
        std::string fecha, titulo; int numPeliculas;
        std::cin >> fecha >> numPeliculas;
        std::cin.ignore();
        // Bucle de lectura de las peliculas de cada dia
        for (int i = 0; i < numPeliculas; ++i) {
            getline(std::cin, titulo);
            
            // Procesar datos. Codigo del alumno

			//Guardamos cada fecha leida en la entrada de su pelicula asociada.
			// Coste : O(log n), suponiendo que map se implementa con arbol binario de busqueda, y este esta equilibrado.
			//La funcion push_back tiene coste constante amortizado.
			peliculas[titulo].push_back(fecha);
            
            
        }
    }
    
    // Procesar y mostrar datos. Codigo del alumno

	//En primer lugar, recorremos el diccionario buscando el numero maximo de dias que se ha emitido una pelicula.
	//Para ello utilizaremos iteradores.
	//coste : O(n), porque recorremos todas las peliculas del diccionario.
	int numMaxDias = 0;
	auto it = peliculas.cbegin();
	while (it != peliculas.cend()) {
		if (it->second.size() > numMaxDias) numMaxDias = it->second.size();
		++it;
	}
	std::cout << numMaxDias << std::endl;

	//Una vez hemos calculado el numero maximo de dias, buscamos y mostramos por pantalla las fechas 
	// y el titulo de aquellas peliculas que compartan ese numero maximo de dias.
	//coste : O(n^2). ya que recorremos todas las peliculas, y para cada pelicula sus vectores asociados.
	auto it2 = peliculas.cbegin();
	std::string ultimaFechaMostrada = "";
	size_t contador = 0;
	while (it2 != peliculas.cend()) {
		
		//Para cada pelicula, comprobamos si contiene el mismo numero de fechas que el maximo.
		if (it2->second.size() == numMaxDias) {
			
			//Mostramos el titulo de la pelicula que cumple lo anterior.
			std::cout << it2->first << " ";
			
			//Si cumple lo anterior, recorremos el vector de fechas mostrandolas sin repeticion.
			for (int i = 0; i < it2->second.size(); ++i) {
				
				if (ultimaFechaMostrada != it2->second[contador]) {
					std::cout << it2->second[contador] << " ";
					ultimaFechaMostrada = it2->second[contador];
				}
				++contador;
			}
			ultimaFechaMostrada = "";
			contador = 0;
			std::cout << std::endl;
		}
		++it2;
	}
    

    // Marca de final de caso
    std::cout << "---\n";
    return true;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos
   
    // Para restablecer entrada. 
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
