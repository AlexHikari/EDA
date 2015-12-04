#include <iostream>

using namespace std;



const int N = 20;
const int M = 100000;


int main(){

	int numCasos, casos,elems,element,sum =0,pot,suma[M];
	cin >> numCasos;
	casos = numCasos;

	while (numCasos > 0){
	
		cin >> elems;
		if (elems > N){
			suma[numCasos] = 0;
		}
		else{

			for (int i = 0; i < elems; i++)
			{
				if (i == 0) pot = 1;
				else{
					pot = pot * 2;
				}
				cin >> element;
				if (element == pot)
					sum += element;
			}
			suma[numCasos] = sum;
		}
		pot = 1;
		numCasos--;
		sum = 0;
	}

	for (int j = casos; j > 0; j--){
		cout << suma[j] << endl;
	
	}

	return 0;
}
