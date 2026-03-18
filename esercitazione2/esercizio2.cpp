#include <iostream>
#include <cmath>

int main() {
	static const int N = 10;
	double arr[N] = {6, 21, 28, 30, 69, 42, 3.14, 5.63, 12, 2.65};

	double sum = 0;
	for (int i = 0; i< N; i++) {
		sum += arr[i];
	}
	std::cout << "somma " << sum << "\n";
	
	double media = sum/N;
	std::cout << "Media " << media << "\n";
	
	double max_val = arr[0];

	for (int i = 1; i < N; i++) {
		if (arr[i] > max_val) {
			max_val = arr[i];
		}
	}
	std::cout << "Massimo: " << max_val << "\n";
	
	double min_val = arr[0];

	for (int i = 1; i < N; i++) {
		if (arr[i] < min_val) {
			min_val = arr[i];
		}
	}
	std::cout << "Minimo: " << min_val << "\n";
	
//deviazione standard	
	double SSx = 0;
	for (int i = 0; i < N; i++) {
		SSx  += ( arr[i] - media )*( arr[i] - media );
	}
	double deviaz_st = std::sqrt(SSx/N);
	std::cout << "deviazione standard: " << deviaz_st << "\n";
	
}