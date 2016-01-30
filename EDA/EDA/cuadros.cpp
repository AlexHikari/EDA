#include <iostream>
using namespace std;

const int N = 10;
const int pared = 5;
typedef struct {
	double anchura;
	double altura;
	int prestigio;
} cuadro;

typedef cuadro cuadros[N];

void inicializaCuadros(cuadros &cuadros) {

	cuadros[0].altura = 1;
	cuadros[0].anchura = 2;
	cuadros[0].prestigio = 9;
	cuadros[1].altura = 0.5;
	cuadros[1].anchura = 1.5;
	cuadros[1].prestigio = 3;
	cuadros[2].altura = 3;
	cuadros[2].anchura = 2;
	cuadros[2].prestigio = 5;
	cuadros[3].altura = 3;
	cuadros[3].anchura = 0.5;
	cuadros[3].prestigio = 6;
	cuadros[4].altura = 2.5;
	cuadros[4].anchura = 1.5;
	cuadros[4].prestigio = 7;
	cuadros[5].altura = 3;
	cuadros[5].anchura = 1;
	cuadros[5].prestigio = 7;
	cuadros[6].altura = 1;
	cuadros[6].anchura = 1;
	cuadros[6].prestigio = 10;
	cuadros[7].altura = 0.5;
	cuadros[7].anchura = 1.5;
	cuadros[7].prestigio = 15;
	cuadros[8].altura = 0.5;
	cuadros[8].anchura = 2;
	cuadros[8].prestigio = 30;
	cuadros[9].altura = 3;
	cuadros[9].anchura = 3;
	cuadros[9].prestigio = 7;
}

void copiarSolucion(bool solucion[], bool solucionMejor[]) {

	for (int i = 0; i < N; i++) {
		solucionMejor[i] = solucion[i];
	}
}

void mochila(bool solucion[],cuadros cuadros, int L,int k, int N,int &prestigio, float &distancia, bool solucionMejor[], int &prestigiomejor) {

		solucion[k] = true;
		prestigio += cuadros[k].prestigio;
		distancia += cuadros[k].altura;
		
		if (distancia <= L && k < N) {
			if (distancia == L) {
				if (prestigiomejor < prestigio) {
					prestigiomejor = prestigio;
					copiarSolucion(solucion, solucionMejor);
				}
			}
			else {
				mochila(solucion, cuadros, L, k + 1, N, prestigio, distancia, solucionMejor, prestigiomejor);
			}
		}
		//para usar valor horizontal
		distancia -= cuadros[k].altura;
		distancia += cuadros[k].anchura;
		if (distancia <= L && k < N) {
			if (distancia == L) {
				if (prestigiomejor < prestigio) {
					prestigiomejor = prestigio;
					copiarSolucion(solucion, solucionMejor);
				}
			}
			else {
				mochila(solucion, cuadros, L, k + 1, N, prestigio, distancia, solucionMejor, prestigiomejor);
			}
		}
		//no pillo el cuadro
		solucion[k] = false;
		distancia += cuadros[k].anchura;
		prestigio -= cuadros[k].prestigio;
		if (distancia <= L && k < N) {
			if (distancia == L) {
				if (prestigiomejor < prestigio) {
					prestigiomejor = prestigio;
					copiarSolucion(solucion, solucionMejor);
				}
			}
			else {
				mochila(solucion, cuadros, L, k + 1, N, prestigio, distancia, solucionMejor, prestigiomejor);
			}
		}
}

int main() {

	cuadros cuadros;
	float distancia = 0;
	int prestigiomejor = 0;
	int prestigio = 0;
	inicializaCuadros(cuadros);
	bool solucion[N] = {false};
	bool solucionmejor[N];
	mochila(solucion,cuadros,pared,0,N,prestigio,distancia,solucionmejor,prestigiomejor);
	for (int i = 0; i < N;i++){
		if (solucionmejor[i])cout << "cuadro " << i << " ";
	}
	system("pause");
	return 0;
