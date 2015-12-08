#include <iostream>
using namespace std;

const int N = 10000;

int main() {

	int numCasos,elems,posicion;
	int vector[N];
	bool valido, esCreciente, esDecreciente;

	cin >> numCasos;

	while (numCasos > 0)
	{
		cin >> elems;
		valido = true;
		esCreciente = false;
		esDecreciente = false;
		posicion = 0;
		for (int i = 0; i < elems; i++) {
			cin >> vector[i];
		}
		if (elems < 2 || elems > 10000) {
			valido = false;
		}
	 //bucle algoritmico
		for (int j = 0; j < elems - 1 && valido; j++) {

			if (vector[j] < vector[j + 1]) {
				esCreciente = true;
				posicion = j + 1;
				if (esDecreciente) {
					valido = false;
				}
			}
			else if (vector[j] > vector[j + 1]) {
				esDecreciente = true;
				if (!esCreciente) {
					valido = false;
				}
			}
			else { valido = false; }

		}
		// comprobaciones adicionales
		if (!esDecreciente) { valido = false; }
		if (valido) { cout << "Si " << posicion << endl; }
		else { cout << "No" << endl; }
		numCasos--;
	}

	return 0;
}