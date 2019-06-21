// Nombre del alumno: Héctor Ullate Catalán
// Usuario del Juez: E64

// Explicación general: consiste en que tenemos 2 colas, la principal y la auxiliar.
//La principal guardara todos los posibles valores en cada iteracion, y en la auxiliar iremos guardando
//los valores que nos sigan siendo validos, mientras que a los no validos simplemente haremos pop()

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int numAlumnos, salto;
	std::cin >> numAlumnos >> salto;
    if (numAlumnos == 0 && salto == 0)
        return false;
    
	std::queue<int> q1,qAux;
	for (int i = 0; i < numAlumnos; ++i) q1.push(i + 1);
	int contador = 0;
	while (q1.size() > 1) {
		while (q1.size() > 0) {
			if (contador == salto) {
				q1.pop();
				contador = 0;
			}
			else {
				qAux.push(q1.front());
				q1.pop();
				++contador;
			}
		}
		while (qAux.size() > 0) {
			q1.push(qAux.front());
			qAux.pop();
		}
	}
    
	std::cout << q1.front() << std::endl;
    
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