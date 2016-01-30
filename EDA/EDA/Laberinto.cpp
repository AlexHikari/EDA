#include<iostream>

using namespace std;

const int N = 4;

typedef struct {
	int fila;
	int columna;
}casilla;

typedef struct {
	bool marca[N][N];
}marcas;


void tratarSolucion(casilla solucion[], int k) {
	for (int i = 0; i <= k; i++) {
		cout << "(" << solucion[i].fila << "," << solucion[i].columna << ")" << endl;
	}
}

//manual para un laberinto de 4x4
void generaLaberinto(bool laberinto[N][N], int N) {

	laberinto[0][3] = false;
	laberinto[1][0] = false;
	laberinto[1][1] = false;
	laberinto[1][1] = false;
	laberinto[1][3] = false;
	laberinto[2][3] = false;
}


casilla siguienteDireccion(int direccion, casilla posicion) {
	switch (direccion) {
		case 0: 
			++posicion.columna;
			break;
		case 1:
			++posicion.fila;
			break;
		case 2:
			--posicion.columna;
			break;
		case 3:
			--posicion.fila;
			break;
		default:
			break;
	}
	return posicion;
}

bool esValido(bool laberinto[N][N], casilla posicion, int N, marcas marcas) {
	return posicion.fila < N && posicion.fila >= 0 && posicion.columna < N && posicion.columna >= 0 && laberinto[posicion.fila][posicion.columna] && !marcas.marca[posicion.fila][posicion.columna];
}

bool esSolucion(casilla posicion, int N) {
	return posicion.columna == (N-1) && posicion.fila == (N-1);
}

void resolverLaberinto(bool laberinto[N][N], casilla solucion[], int k, int N, marcas marcas, bool &exito) {
	int direccion = 0;

	while ((direccion < 4 && !exito)) {
		solucion[k] = siguienteDireccion(direccion, solucion[k - 1]);
		if (esValido(laberinto, solucion[k], N, marcas)) {
			if (esSolucion(solucion[k], N)) {
				tratarSolucion(solucion, k);
			}

			else {
				marcas.marca[solucion[k].fila][solucion[k].columna] = true;
				resolverLaberinto(laberinto, solucion, k + 1, N, marcas, exito);
				//marcas[solucion[k].fila][solucion[k].columna] = false;
			}
		}
		direccion++;
	}
}

int main() {
	bool laberinto[N][N];
	marcas marcas;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			laberinto[i][j] = true;
			marcas.marca[i][j] = false;
		}
	}
	

	generaLaberinto(laberinto, N);

	casilla solucion[N * N];

	//casilla de partida
	solucion[0].fila = 0;
	solucion[0].columna = 0;
	marcas.marca[0][0] = true;
	bool exito = false;

	resolverLaberinto(laberinto, solucion, 1, N, marcas, exito);

	system("pause");
	return 0;
}
