#pragma once

#include <iostream>
#include <vector>

// bubble sort
template<typename T>
void bubble_sort(std::vector<T>& vec)
{
	if (vec.size()== 0) {return;}
	for (int i= 0; i <vec.size() -1; i++) {
		for (int j = vec.size()-1; j>= i+1; j--) {
			if (vec[j]<vec[j-1]){T temp = vec[j]; vec[j] = vec[j-1]; vec[j-1] = temp;} //swap
		}
	}
}

// insertion sort
template<typename T>
void insertion_sort(std::vector<T>& vec)
{
	if (vec.size()== 0) {return;}
	for (int i= 1; i <=vec.size() -1; i++) {
		T value = vec[i];
		int j = i-1;
		while (j>=0 && vec[j]>value){
			vec[j+1] = vec[j];
			j--;
		}
		vec[j+1] =value;
		
	}
}

// selection sort
template<typename T>
void selection_sort(std::vector<T>& vec)
{
	if (vec.size()== 0) {return;}
	for (int i= 0; i <vec.size() -1; i++) {
		int min = i;
		for (int j= i+1; j< vec.size(); j++) {
			if (vec[j] < vec[min]) {min=j;}
		}
		T temp = vec[i];
		vec[i] = vec[min];
		vec[min] = temp;
	}
}