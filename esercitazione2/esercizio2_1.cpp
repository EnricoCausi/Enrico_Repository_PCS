#include <iostream>
#include <cmath>

// 1. Si scorra tutto l’array da ordinare, confrontando gli elementi adiacenti. Se l’elemento in
// posizione i-esima `e pi`u grande dell’elemento in posizione (i + 1)-esima, si scambino i due
// elementi,
// 2. Se nel passo precedente sono stati effettuati uno o pi`u scambi, ritornare al punto 1. Se invece
// non `e stato effettuato nessuno scambio l’algoritmo termina


int main() {
	static const int N = 10;
	double arr[N] = {6, 21, 28, 30, 69, 42, 3.14, 5.63, 12, 2.65};
	
	int flag = 1;
	while (flag) {
	int scambi = 0;	
	
		for (int i = 0; i < N-1; i++) {
			if (arr[i] > arr[i+1]) {
				double var_temporanea = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = var_temporanea;
				scambi = 1;
			}
			
		
		}
	if (scambi == 0) {
		flag = 0;
	}
		
	}
	
	std::cout << "Vettore ordinato: ";
	for (int i = 0; i<N; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	
}