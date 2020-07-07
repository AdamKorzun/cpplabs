// assignment1.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
void assignment1(int n, int k) {
	int** a = new int* [n];
	int** b = new int* [n];
	for (int i = 0; i < n;i++) {
		a[i] = new int[k];
		b[i] = new int[k];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (j <= 9 || i > 3) {
				a[i][j] = 2 * i * j - 2;
			}
			else if (j > 9) {
				a[i][j] = 3 * i * pow(j, 2) - 3 * j;
			}
			else if (i <= 3) {
				a[i][j] = 2 * i * pow(j, 2) - 2 * j;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			b[i][j] = pow(a[i][j], 2);
		}
	}
	int sumA = 0;
	int sumB = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << setw(4) << a[i][j] << ' ';
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k;j++) {
			if (j != 0 && j % 2 == 0) {
				sumA += a[i][j];
				sumB += b[i][j];
			}
		}
	}
	cout << "Sum[A]=" << sumA << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << setw(10) << b[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "Sum[B]=" << sumB << endl;
	//delete[] a;
	//delete[] b;
	return;
}

// TODO: This is an example of a library function
