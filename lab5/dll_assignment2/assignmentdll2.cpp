#include "pch.h"
#include <iostream>
using namespace std;
int __declspec(dllexport) assignmentdll2(int a[], int size) {
	int s1 = 0, s2 = 0;
	if (size <= 0) {
		return 0;
	}
	
	return assignmentdll2 (a, size - 1) + a[size - 1];

}