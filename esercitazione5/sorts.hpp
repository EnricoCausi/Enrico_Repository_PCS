#pragma once
#include <iostream>
#include <vector>
#include <string>


// merge da inserire in merge_sort
template<typename T>
void merge(std::vector<T>& vec, int p, int q, int r) {
	
	int n_1 = q-p+1;
	int n_2 = r-q;
	std::vector<T> L(n_1 + 1); //inizializzo come vettori di zeri di lunghezze n1+1 e n2+1
	std::vector<T> R(n_2 + 1);
	
	for (int i=0; i<n_1; i++){
		L[i] = vec[p+i];
	}

	for (int j =0; j<n_2; j++){
		R[j] = vec[q+j+1];
	}
	L[n_1] = 999999; //inserisco infinito come ultimo elemento
	R[n_2] = 999999;
	
	int i = 0;
	int j = 0;
	
	for (int k = p; k<=r; k++){
		if (L[i] <= R[j]){
			vec[k] = L[i];
			i++;
			}
		else{
			vec[k] = R[j];
			j++;
		}
	}

}


// merge per stringhe da inserire in merge sort per stringhe
void merge_str(std::vector<std::string>& vec, int p, int q, int r) {
    int n_1 = q - p + 1;
    int n_2 = r - q;
    std::vector<std::string> L(n_1 + 1); 
    std::vector<std::string> R(n_2 + 1);
    
    for (int i = 0; i < n_1; i++) L[i] = vec[p + i];
    for (int j = 0; j < n_2; j++) R[j] = vec[q + j + 1];
    
    L[n_1] = "zzzzzz"; 
    R[n_2] = "zzzzzz";
    
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            vec[k] = L[i++];
        } else {
            vec[k] = R[j++];
        }
    }
}


//merge sort per stringhe
void merge_sort_str(std::vector<std::string>& vec, int p, int r) {
    if (vec.size() == 0) { return; }
    
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort_str(vec, p, q);
        merge_sort_str(vec, q + 1, r);
        
        merge_str(vec, p, q, r); 
    }
}


// merge sort per float/int
template<typename T>
void merge_sort(std::vector<T>& vec, int p, int r)
{
	if (vec.size()== 0) {return;} //controllo se la dimensione del vettore è 0
	
	if (p < r) {
		int q = (p+r)/2; //non ho bisogno di usare il floor tanto è una divisione intera
		merge_sort(vec, p, q);
		merge_sort(vec, q+1, r);
		merge(vec, p, q, r);
	}
}

//partition da inserire in quick sort
template<typename T>
int partition(std::vector<T>& vec, int p, int r)
{
	T x = vec[r];
	int i = p-1;
	for (int j=p; j<=r-1; j++) {
		if (vec[j] <=x) {
			i++;
			T temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
		}
	}
	T temp1 = vec[i+1];
	vec[i+1] = vec[r];
	vec[r] = temp1;
	return i+1;
}

// quick sort
template<typename T>
void quick_sort(std::vector<T>& vec, int p, int r)
{
	if (vec.size()== 0) {return;}
	if (p<r) {
		int q = partition(vec, p, r);
		quick_sort(vec, p, q-1);
		quick_sort(vec, q+1, r);
	}
	}


// insertion sort modificato per i sotto-vettori
template<typename T>
void insertion_sort(std::vector<T>& vec, int p, int r) {
    for (int i = p + 1; i <= r; i++) {
        T value = vec[i];
        int j = i - 1;
        
        while (j >= p && vec[j] > value) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = value;
    }
}

const int soglia = 16; 

template<typename T>
void quick_sort_modificato(std::vector<T>& vec, int p, int r) {
    if (vec.size() == 0) { return; }
    
    if (p < r) {
        int dimensione_vettore = r - p + 1;
        
        // IL BIVIO IBRIDO
        if (dimensione_vettore < soglia) {
            insertion_sort(vec, p, r);
        } 
        else {
            int q = partition(vec, p, r);
            quick_sort_modificato(vec, p, q - 1);
            quick_sort_modificato(vec, q + 1, r);
        }
    }
}


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