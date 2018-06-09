#include <iostream>
#include "Student.h"

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
	int a[10] = {1, 3, 6, 2, 10, 7, 9, 4, 5, 8};
	SelectionSort(a, 10);
	for(int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	float b[5] = {4.4, 4.1, 3, 9.9, 0.5};
	SelectionSort(b, 5);
	for(int i = 0; i < 5; i++) {
		cout << b[i] << " ";
	}
	cout << endl;

	string s[5] = {"a", "D", "G", "B", "e"};
	SelectionSort(s, 5);
	for(int i = 0; i < 5; i++) {
		cout << s[i] << " ";
	}
	cout << endl;

	Student t[5] = {{"Liu", 98}, {"Coco", 99}, {"Yang", 59}, {"Alice", 96}, {"Xiao", 78}};
	SelectionSort(t, 5);
	for(int i = 0; i < 5; i++) {
		cout << t[i];
	}
	cout << endl;
	
	return 0;
}
