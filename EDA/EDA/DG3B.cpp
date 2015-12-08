#include <iostream>
#include <string>

using namespace std;

const int N = 10000;

int main() {

	string palabra,aux;
	string sub[N];
	int elems, num, max,pos;
	bool encontrado;
	cin >> palabra;
	while (palabra.compare("XXX")!= 0)
	{
		elems = palabra.length();
		num = 0;
		max = 0;
		pos = 0;
		encontrado = false;
		for (int i = 0; i < elems; i++) {

			if (palabra[i] <= palabra[i + 1]) {
				aux += palabra[i];
				encontrado = true;
			}
			else if (encontrado && palabra[i] > palabra[i + 1]) {
				aux += palabra[i];
				encontrado = false;
				sub[num] = aux;  num++;
				aux = "";
			}
			else { aux = ""; }
			
			
		}
		for (int j = 0; j <= num; j++) {
			if (max <= sub[j].length()) {
				max = sub[j].length();
				pos = j;
			}
		}
		if (elems == 1) {
			cout << elems << " " << elems << " " << palabra << endl;
		}
		else {
			cout << elems << " " << sub[pos].length() << " " << sub[pos] << endl;
		}
		for (int i = 0; i < num; i++) {
			sub[i] = "";
		}
		cin >> palabra;
	}
	

	return 0;
}