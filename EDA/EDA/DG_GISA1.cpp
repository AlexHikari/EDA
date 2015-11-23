#include <iostream>
#include <string>
using namespace std;

const int N = 10000;


void paresImpares(const int v[], int n, bool &existe, int &p) {

	// existe sii par(0,numelem) v (par (0,0) ^ impar(0,numelem)) v (par(0,p) ^ impar(p,numelem)
	// p = #i ; 0<i<n ; v[i] % 2 = 0; 
	int j = 0;
	bool impar = false, par = false;
	while (j < n && existe)
	{
		if (p > 0 && impar && v[j] % 2 == 0) {
			existe = false;
		}
		else if (!impar && v[j] % 2 != 0) {
			impar = true;
			p = j;
		}
		else if (v[j] % 2 == 0 && !par) par = true;
		j++;
	}

	if (j == n && !impar) {
		existe = true;
		p = n;
	}
	if (impar && !par && j == n) {
		existe = true;
	}
	if (impar && existe && par && p == 0) {
		existe = false;
	}
}

int main() {

	int casos, numelems, p, v[N], elem[N];
	string resultado[N];
	bool existe;
	cin >> casos;
	int casosaux = casos;
	while (casos > 0) {

		cin >> numelems;
		for (int i = 0; i < numelems; i++) {
			cin >> v[i];
		}

		p = 0;
		existe = true;
		paresImpares(v, numelems, existe, p);
		if (existe) {
			resultado[casos] = "Si ";
			elem[casos] = p;
		}
		else {
			resultado[casos] = "No";
			elem[casos] = 0;
		}
		casos--;
	}

	for (int i = casosaux; i > 0; i--) {
		if (resultado[i] == "Si ") {
			cout << resultado[i] << elem[i] << endl;
		}
		else
			cout << resultado[i] << endl;
	}
	return 0;
}