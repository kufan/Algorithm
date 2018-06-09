#ifndef SELECTION_SORT_TEMPLATE_H
#define SELECTION_SORT_TEMPLATE_H

#include <iostream>
#include <string>

using namespace std;

struct Student{
	string name;
	int    score;

	// 重载 < ,用于 Student 之间的比较
	// 如果 score 相等，则比较 name 的字符顺序
	// 如果 score 不相等，则 score 大的靠前
	bool operator<(const Student& otherStudent) {
		return score != otherStudent.score ?
			   score > otherStudent.score : name < otherStudent.name;
	}

	friend ostream& operator<<(ostream& os, const Student& student) {
		os << "Student: " << student.name << " " << student.score << endl;
		return os;
	}
};

#endif
