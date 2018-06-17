#ifndef INSERTIONSORT_OPTIMIZATION_SORTTESTHELPER_H
#define INSERTIONSORT_OPTIMIZATION_SORTTESTHELPER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {
	// 生成含有 n 个元素的随机数组，每个随机元素的取值范围为: [rangeL, rangeR]
	int *generateRandomArray(int n, int range_l, int range_r) {
		int *arr = new int[n];

		srand(time(NULL));
		for(int i = 0; i < n; i++) {
			arr[i] = rand() % (range_r - range_l + 1) + range_l;
		}
		return arr;
	}

	/*
		生成一组近乎有序的数组，方法如下：
			1、生成含有 n 个元素的有序数组，然后随机交换 swapTimes 对数据
			2、swapTimes 定义了数组的无序程度。即 swapTimes 越大，数组越无序
	*/
	int *generateNearlyOrderedArray(int n, int swapTimes) {
		int *arr = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = i;
		}

		srand(time(NULL));
		for(int i = 0; i < swapTimes; i++) {
			int posx = rand() % n;
			int posy = rand() % n;

			swap(arr[posx], arr[posy]);
		}
		return arr;
	}
	
	// 拷贝现有数组到一个新的数组
	int *copyIntArray(int a[], int n) {
		int *arr = new int[n];
		copy(a, a + n, arr);
		return arr;
	}

	// 打印数组内所有元素
	template<typename T>
	void printArray(T arr[], int n) {
		for(int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	// 判断数组是否有序
	template<typename T>
	bool isSorted(T arr[], int n) {
		for(int i = 0; i < n - 1; i++) {
			if(arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}

	// 计算所采用算法的耗时，并检测排序结果是否正确
	template<typename T>
	void testSort(const string &sortName, void(*sort)(T[], int), T arr[], int n) {
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime   = clock();
		cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

		assert(isSorted(arr, n));
		return;
	}
};

#endif
