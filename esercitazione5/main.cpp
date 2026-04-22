#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include "is_sorted.hpp"
#include "sorts.hpp"
#include "randfiller.h"
#include "timecounter.h"
#include <string>

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
	randfiller rf;
	timecounter tc;
	
	std::vector<int> length;
	length.resize(100);
	rf.fill(length,5,75); //creo 100 vettori randomici con dimensione minima 5, massima 75
	std::sort(length.begin(), length.end()); //ordino il vettore per capire meglio per quale dimensione gli
											 //algoritmi quadratici sono più veloci degli algoritmi logaritmici.
	
	
	//std::cout<< "DIM | BUBBLE | INSERTION | SELECTION | MERGE | QUICK | STD::SORT \n"; 
	std::cout << std::left  //ho usato l'IA generativa per aiutarmi nella formattazione 
          << std::setw(8)  << "DIM" 
          << std::setw(14) << "BUBBLE" 
          << std::setw(14) << "INSERTION" 
          << std::setw(14) << "SELECTION" 
          << std::setw(14) << "MERGE" 
          << std::setw(14) << "QUICK" 
          << std::setw(14) << "STD::SORT" << "\n";
	std::cout << std::scientific << std::setprecision(4);
	
	
	for (int i=0; i<length.size(); i++) {
	int dimvec = length[i];		
	std::vector<int> vi;
	vi.resize(dimvec);
	rf.fill(vi, -1000, 1000);
	std::vector<int> v_bubble = vi;
	std::vector<int> v_insertion = vi;
	std::vector<int> v_selection = vi;
	std::vector<int> v_std = vi;
	std::vector<int> v_merge = vi;
	std::vector<int> v_quick = vi;	
	
	tc.tic();
	bubble_sort(v_bubble);
	double secs_bubble = tc.toc();
	
	tc.tic();
	insertion_sort(v_insertion);
	double secs_insertion = tc.toc();

	tc.tic();
	selection_sort(v_selection);
	double secs_selection = tc.toc();
	
	tc.tic();
	std::sort(v_std.begin(), v_std.end());
	double secs_sort = tc.toc();
	
	tc.tic();
	merge_sort(v_merge, 0, v_merge.size()-1);
	double secs_merge = tc.toc();
	
	tc.tic();
	quick_sort(v_quick, 0, v_quick.size()-1);
	double secs_quick = tc.toc();
	
	std::cout << std::left
			  << std::setw(8)  << dimvec 
			  << std::setw(14) << secs_bubble 
			  << std::setw(14) << secs_insertion 
			  << std::setw(14) << secs_selection 
			  << std::setw(14) << secs_merge 
			  << std::setw(14) << secs_quick 
			  << std::setw(14) << secs_sort << "\n";
}

// SECONDA PARTE 

	int dim = 16;
	int num_vettori = 100;
	std::vector<std::vector<int>> matrice_insertion(num_vettori, std::vector<int>(dim));
	std::vector<std::vector<int>> matrice_quick(num_vettori, std::vector<int>(dim));

	for (int i = 0; i < num_vettori; i++) {
    rf.fill(matrice_insertion[i], -1000, 1000);
    matrice_quick[i] = matrice_insertion[i]; 
}

	// misuro il tempo per l'insertion sort
	tc.tic(); 
	for (int i = 0; i < num_vettori; i++) {
		insertion_sort(matrice_insertion[i]); // ordino uno ad uno i 100 vettori
	}

	double tempo_totale_insertion = tc.toc();
	double media_insertion = tempo_totale_insertion / num_vettori;

	// misuro il tempo per il quick sort
	tc.tic();
	for (int i = 0; i < num_vettori; i++) {
		quick_sort(matrice_quick[i], 0, matrice_quick[i].size() - 1);
	}
	double tempo_totale_quick = tc.toc();
	double media_quick = tempo_totale_quick / num_vettori;


	std::cout << "Dimensione: " << dim << "\n";
	std::cout << "Tempo medio Insertion: " << media_insertion << " s\n";
	std::cout << "Tempo medio Quick:  " << media_quick << " s\n";


	// in sorts.hpp ho scritto anche una modifica del quick sort che, dopo aver "spezzato" il vettore che gli viene passato come argomento,
	// controlla se la dimensione è inferiore alla soglia 16. Ho precedentemente osservato che quella è la soglia per cui un algoritmo quadratico
	// come l'insertion sort ha velocità maggiore rispetto a quelli logaritmici. Allora se il controllo di dimensione ha esito positivo (cioè 
	// è inferiore a 16) l'ordinamento del "sottovettore" avviene per mezzo dell'insertion sort.


}