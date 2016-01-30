#include<iostream>

using namespace std;


const int N = 8;

////////////////////////////////////////////////////////
bool esValida(int solucion[], int i, int k, bool marcas[N][N]) {
	bool correcto = true;
	int i = 0;
	while (i < k && correcto) {
		if (solucion[i] == solucion[k] || abs(solucion[k] - solucion[i]) == k - i)
			correcto = false;
		i++;
	}
	//return !marcas[i][k];
	return correcto;
}

////////////////////////////////////////////////////////
bool esSolucion(int k) {
	return k == N - 1;
}
////////////////////////////////////////////////////////
void tratarSolucion(int solucion[], int N) {
	cout << "Solucion: ";
	for (int i = 0; i < N; i++)
		cout << solucion[i] << " ";
	cout << endl;
}

////////////////////////////////////////////////////////

void marcarSol(bool marcas[][N], int f, int c, bool marca) {
	for (int s = 0; f + s<8 && c + s<8; s++) {
		marcas[f + s][c + s] = marca;
	}
	for (int s = 0; f - s>-1 && c + s<8; s++) {
		marcas[f - s][c + s] = marca;
	}
	for (int s = 0; c + s<8; s++) {
		marcas[f][c + s] = marca;
	}
}

////////////////////////////////////////////////////////
void reinas(bool marcas[][N], int solucion[], int N, int k) {

			for (int i = 0; i < N; i++) {
				solucion[k] = i;

				if (esValida(solucion, i, k, marcas)) {
					if (esSolucion(k)) {
						tratarSolucion(solucion, N);
					}
					else {
						//marcarSol(marcas,i,k,true);
						reinas(marcas,solucion, N, k + 1);
						//marcarSol(marcas, i, k,false);
					}
				}
			}
}
////////////////////////////////////////////////////////
int main() {

	int solucion[N] = { 0 };
	bool marcas[N][N] = { false };

	int k = 0; //inicializar profundidad
	//Profundidad maxima del problema N

	reinas(marcas,solucion, N, k);

	system("pause");
	return 0;
}
