#include <iostream>
#include "SortTestHelp.h"

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

int main()
{
	int N = 40000;
	int *arr = SortTestHelp::generateRandomArray(N, 0, N);
	SortTestHelp::testSort("Selection Sort", SelectionSort, arr, N);

	delete[] arr;
	return 0;
}
