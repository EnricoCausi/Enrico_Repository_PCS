#include <iostream>
#include <vector>
#include <cstdlib>
#include "is_sorted.hpp"
#include "sorts.hpp"
#include "randfiller.h"

template<typename T>
void print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";}
    std::cout << "\n";
}

int main(void)
{	
	randfiller rf;

    std::vector<int> dimensioni;
    dimensioni.resize(100);
    rf.fill(dimensioni, 1, 2000);
    std::cout<< "Vettore randomico per le lunghezze dei vettori (merge sort) ";
	print_vector(dimensioni);
	
	for (int i= 0; i<dimensioni.size(); i++) {
		std::vector<int> vi;
		vi.resize(dimensioni[i]);
		rf.fill(vi,-100,100);
		
		merge_sort(vi, 0, vi.size()-1);
		// print_vector(vi);
		if (!is_sorted(vi)) {
			std::cout << "ERRORE: Vettore di dimensione " << dimensioni[i] << " NON ordinato!\n";
            return EXIT_FAILURE;
			}		
	}
	
	// Test con le stringhe
	std::cout << "Inizio test con stringhe \n";
	std::vector<std::string> vs = { "zaino", "banana", "giorgio", "casa", "gatto", 
		"raffaele", "mia", "dado", "pcs", "limone"};

	merge_sort_str(vs, 0, vs.size()-1); 
	if (!is_sorted(vs)) {
		std::cout << "ERRORE: Vettore di stringhe NON ordinato!\n";
		return EXIT_FAILURE;
	}
	std::cout << "Test stringhe superato!\n";
	
    std::cout << "Tutti i test del MERGESORT sono passati con successo!\n";  
    return EXIT_SUCCESS;
}
