#include <iostream>
#include <algorithm>

using namespace std;

// void SelectionSort(int *arr, int n) {
void SelectionSort(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		int MinIndex = i;   // 在 [i, n) 区间内寻找最小值
		for(int j = i + 1; j < n; j++) {
			if(arr[j] < arr[MinIndex])
				MinIndex = j;
		}
		swap(arr[i], arr[MinIndex]);
	}
}

int main()
{
	int a[10] = {1, 3, 6, 2, 10, 7, 9, 4, 5, 8};
	SelectionSort(a, 10);

	for(int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
