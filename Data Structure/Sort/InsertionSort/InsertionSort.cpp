#include <iostream>
#include <algorithm>
#include "SortTestHelp.h"
#include "SelectionSort.h"

using namespace std;

template<typename T>
void InsertionSort(T arr[], int n) {
	for(int i = 1; i < n; i++) {
		// 实现方式一：
		// for(int j = i; j > 0; j--) {
		//	if(arr[j] < arr[j - 1])
		//		swap(arr[j], arr[j - 1]);
		//	else
		//		break;
		// }
		
		// 实现方式二：
		for(int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
			swap(arr[j], arr[j - 1]);
		}
	}
	return;
}

//template<typename T>
//void SelectionSort(T arr[], int n) {
//	for(int i = 0; i < n; i++) {
//		int MinIndex = i;
//		for(int j = i + 1; j < n; j++) {
//			if(arr[j] < arr[MinIndex])
//				MinIndex = j;
//		}
//		swap(arr[i], arr[MinIndex]);
//	}
//}

int main()
{
	// 可以比较下 SelectionSort 和 InsertionSort
	int n = 20000;
	cout << "Test for random array, size = " << n << ", random range[0, " << n << "]" << endl;
	
	int *arr1 = SortTestHelp::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelp::copyIntArray(arr1, n);

	SortTestHelp::testSort("Insertion Sort", InsertionSort, arr1, n);
	SortTestHelp::testSort("Selection Sort", SelectionSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;

	return 0;
}
