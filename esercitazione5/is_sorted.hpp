#pragma once

#include <iostream>
#include <vector>

template<typename T>
bool is_sorted(const std::vector<T>& vec)
{
	bool sorted = true;
	if (vec.size() == 0) {
	return sorted;
	}
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i-1]> vec[i]) {
			sorted = false;			
		}
	}
	return sorted;
}