#ifndef INSERTION_SORT_SELECTIONSORT_H
#define INSERTION_SORT_SELECTIONSORT_H

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelp {
	int *generateRandomArray(int n, int range_l, int range_r) {
		int *arr = new int[n];

		srand(time(NULL));
		for(int i = 0; i < n; i++) {
			arr[i] = rand() % (range_r - range_l + 1) + range_l;
		}
		return arr;
	}

	int *copyIntArray(int a[], int n) {
		int *arr = new int[n];

		copy(a, a + n, arr);
		return arr;
	}

	template<typename T>
	void printArray(T arr[], int n) {
		for(int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	template<typename T>
	bool isSorted(T arr[], int n) {
		for(int i = 0; i < n - 1; i ++) {
			if(arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}

	template<typename T>
	void testSort(const string &sortName, void(*sort)(T[], int), T arr[], int n) {
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();

		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

		assert(isSorted(arr, n));

		return;
	}
};

#endif
