#ifndef SORT_TEST_HELP_H
#define SORT_TEST_HELP_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelp {
	// 生成包含 n 个元素的随机数组，且每个元素的范围为：[rangeL, rangeR]
	int *generateRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeL <= rangeR);

		int *arr = new int[n];

		srand(time(NULL));   // 设置随机种子
		for(int i = 0; i < n; i++) {
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}

	// 打印数组内的元素
	template<typename T>
	void printArray(T arr[], int n) {
		for(int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
};

#endif
