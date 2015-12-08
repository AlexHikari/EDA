#include <iostream>

using namespace std;


long long int complementarioF(long long int numero,long long int paso) {

//caso base
	if (numero <= 0 && paso > 1) {
		return 0;
	}
	else {
	//calculamos el ultimo digito
		int ult = numero % 10;
	//calculamos complementario + llamada recursiva en algoritmo final
		return (long long int)(9 - ult)*paso + complementarioF(numero / 10, paso*10);
	}
}


int main() {

	long long int caso;

	cin >> caso;
	while (caso != -1) {
	
		
		cout << complementarioF(caso, 1)<< endl;
		cin >> caso;
	
	
	
	}

	return 0;
}