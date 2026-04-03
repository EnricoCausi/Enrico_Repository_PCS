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
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main(void)
{	
	// std::vector<int> vi = {30, 29, 45, 31, 67, 60};
    // print_vector(vi);
	
	randfiller rf; /* instantiate a randfiller */

    std::vector<int> dimensioni;
    dimensioni.resize(100);
    rf.fill(dimensioni, 1, 200);
    std::cout<< "Vettore randomico per le lunghezze dei vettori (selection sort) ";
	print_vector(dimensioni);
	
	for (int i= 0; i<dimensioni.size(); i++) {
		std::vector<int> vi;
		vi.resize(dimensioni[i]);
		rf.fill(vi,-100,100);
		
		selection_sort(vi);
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

	selection_sort(vs); 
	if (!is_sorted(vs)) {
		std::cout << "ERRORE: Vettore di stringhe NON ordinato!\n";
		return EXIT_FAILURE;
	}
	std::cout << "Test stringhe superato!\n";
	
    std::cout << "Tutti i test del SELECTIONSORT sono passati con successo!\n";  
    return EXIT_SUCCESS;
}
