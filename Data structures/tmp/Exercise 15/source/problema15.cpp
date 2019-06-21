// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: la cosa es meter todos los valores, y en funcion del valor que entre hago limpieza de los que haga falta.
//es importante saber que el mayor de cada intervalo DEBE estar en el front de la deque

#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>

struct sobre{
	int numero;
	int iteracion;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n, k;
	std::cin >> n >> k;
    if (n == 0 && k == 0)
        return false;
	
	sobre leido;
	
	std::deque<sobre> dq;
	dq.push_back({ 0,-1 }); //Inicializo un primer valor en dq, el maximo sera inicialmente un 0 y la iteracion -1.

	//1º busco el mayor en el primer intervalo de sobres
	for (int i = 0; i < k; ++i) {
		std::cin >> leido.numero;
		leido.iteracion = i;

		//basicamente lo que queremos son 2 cosas:
		//	1) si metemos un numero mayor que todos, borrarlos y meter el nuevo
		//	2) si metemos un numero menor que el maximo, pero mayor que otro detras del maximo, borrarlo y meter el nuevo.
		while (!dq.empty() && dq.back().numero < leido.numero) dq.pop_back();

		//Los numeros leido SI o SI los metemos. Mas adelante los limpiamos de estas 2 maneras:
		//	- si es un numero mayor que el maximo, limpiamos todo
		//	- si es un numero menor que el maximo, pero mayor que algun numero detras del maximo, limpiamos todo hasta el
		dq.push_back(leido);
		
	}

	std::cout << dq.front().numero << " "; //muestro el mayor de esta iteracion

	//ahora procedo a buscar el mayor valido para la siguiente iteracion; SOLO SI SE ENCONTRABA EN LA POS 0
	//si se encontraba posteriormente a i = 0, es valido para la siguiente iteracion.
	if (!dq.empty() && dq.front().iteracion == 0) {
		dq.pop_front();
	}
	

	//2º analizo el resto de numeros
	for (int i = k; i < n; ++i) {
		std::cin >> leido.numero;
		leido.iteracion = i;

		//basicamente lo que queremos son 2 cosas:
		//	1) si metemos un numero mayor que todos, borrarlos y meter el nuevo
		//	2) si metemos un numero menor que el maximo, pero mayor que otro detras del maximo, borrarlo y meter el nuevo.
		while (!dq.empty() && dq.back().numero < leido.numero) dq.pop_back();
		dq.push_back(leido);

		//IMPORTANTE: SOLO LO CAMBIO SI EL MAYOR SE ENCUENTRA 2 POSICIONES ATRAS
		while (!dq.empty() && dq.front().iteracion <= i - k) {
			dq.pop_front();
		}

		std::cout << dq.front().numero << " "; //muestro el mayor de esta iteracion
	}
	
    // escribir sol

	std::cout << std::endl;
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