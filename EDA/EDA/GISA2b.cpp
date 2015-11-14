#include <iostream>
#include <string>
using namespace std;

const int N = 100000;


int main() {

	int casos, numelems, v[N], cont = 0, min, resultado[N];
	cin >> casos;
	int casosaux = casos;
	while (casos > 0) {

		cin >> numelems;
		for (int i = 0; i < numelems; i++) {
			cin >> v[i];
		}
		min = v[numelems - 1];
		for (int j = numelems - 2; j >= 0; j--) {
			if (v[j] > min) cont++;
			else if (v[j] < min) min = v[j];
		}
		resultado[casos] = cont;
		cont = 0;
		casos--;
	}

	for (int i = casosaux; i > 0; i--) {
		cout << resultado[i] << endl;
	}
	return 0;
}