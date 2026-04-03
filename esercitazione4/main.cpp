#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include "is_sorted.hpp"
#include "sorts.hpp"
#include "randfiller.h"
#include "timecounter.h"

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
	randfiller rf; /* instantiate a randfiller */
	timecounter tc;

    std::vector<int> length = {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};
	
	std::cout<< "DIM | BUBBLE | INSERTION | SELECTION | STD::SORT \n"; 
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
		
		std::cout<< dimvec << " " << secs_bubble << "   " << secs_insertion<< "   "<< secs_selection<< "   " << secs_sort<< "   \n"; 	

	}


    return 0;
}
