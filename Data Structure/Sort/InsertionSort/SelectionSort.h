#ifndef INSERTION_SORT_SELECTIONSORT_H
#define INSERTION_SORT_SELECTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void SelectionSort(T arr[], int n) {
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
