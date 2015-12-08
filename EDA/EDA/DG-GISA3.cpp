#include <iostream>

using namespace std;
unsigned long long F[51];

// recursividad con memoria --> metodo avanzado
unsigned long long sucesionF(int n, int x, int y) {

	//caso recursivo, no existe caso base definido en memoria fuera
		if (F[n] != -1) { return F[n]; }
		F[n] = sucesionF(n - 1, x, y) + sucesionF(n - 2, x, y);
		
		return F[n];
	
}


int main() {

	// si -1 no está calculado
	for (int i = 0; i < 51; i++) {
		F[i] = -1;
	}
	int n,x,y;
	cin >> n;
	while (n != -1) {
		cin >> x >> y;
		F[0] = x;
		F[1] = y;
		std::cout.unsetf(std::ios::floatfield);
		std::cout.precision(20);
		cout << sucesionF(n, x, y) << endl;
		cin >> n;
	
	}
	return 0;
}