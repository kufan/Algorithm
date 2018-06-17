#ifndef INSERTIONSORT_OPTIMIZATION_SELECTION_H
#define INSERTIONSORT_OPTIMIZATION_SELECTION_H

#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
	for(int i = 0; i < n; i++) {
		int MinIndex = i;
		for(int j = i + 1; j < n; j++) {
			if(arr[j] < arr[MinIndex])
				MinIndex = j;
		}
		swap(arr[i], arr[MinIndex]);
	}
}

#endif
