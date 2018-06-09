#ifndef SORT_TEST_HELP_H
#define SORT_TEST_HELP_H

#include <iostream>
#include <ctime>
#include <string>
#include <cassert>

using namespace std;

namespace SortTestHelp {
	// 生成含有 n 个元素的随机数组，每个元素的范围是：[rangeL, rangeR]
	int *generateRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeL <= rangeR);
		int* arr = new int[n];

		srand(time(NULL));  // 设置随机数种子
		for(int i = 0; i < n; i++) {
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}

	// 打印数组 arr 中的所有元素
	template<typename T>
	void printArray(T arr[], int n) {
		for(int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	
	// 判断排序是否成功
	template<typename T>
	bool isSorted(T arr[], int n) {
		for(int i = 0; i < n - 1; i++) {
			if(arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}
	
	// 判断排序结果的正确性以及排序所用的时间
	template<typename T>
	void testSort(const string &sortName, void (*sort)(T[], int), T arr[], int n) {
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();

		assert(isSorted(arr, n));

		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		return;
	}
};

#endif
