#include <iostream>
#include <headers.h>
#include <iomanip>
using namespace std;
__declspec(dllexport) int assignmentdll2(int[], int);
void assignment2() {
	int size;
	cout << "size=";
	cin >> size;
	int* a = new int[size];
	cout << "Start entering values: \n";
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}
	int n = assignmentdll2(a, size);
	cout << n;
}
int assignment3() {
	int n;
	int integral_number;
	cout << "Accuracy: ";
	cin >> n;
	cout << "Integral number:";
	cin >> integral_number;
	float a;
	float b;
	float k;
	float h;
	float s = 0;
	
	switch (integral_number) {
	
	case 1: {
		a = 0.6;
		b = 2.4;
		k = a;
		h = (b - a) / n;
		for (; k < b; k += h) {
			s += (sqrt(1.1 * pow(k, 2) + 0.9) / (1.6 + sqrt(0.8 * pow(k, 2) + 1.4))) * h;

		}
	}break;
	case 2: {
		a = 0.4;
		b = 1.2;
		k = a;
		h = (b - a) / n;
		for (; k < b; k += h) {
			s += (cos(0.8 * pow(k, 2) + 1) / (1.4 + sin(0.3 * k + 0.5))) * h;

		}
	}break;
	
	case 3: {
		a = 0.5;
		b = 1.3;
		k = a;
		h = (b - a) / n;
		for (; k < b; k += h) {
			s += 1 / sqrt(pow(k,2)+ 2) * h;

		}
	}break;

	case 4: {
		a = 0.2;
		b = 1.8;
		k = a;
		h = (b - a) / n;
		for (; k < b; k += h) {
			s += (sqrt(k+ 1) * cos(pow(k,2))) * h;

		}
	}break;
	default: return 0;
	}

	cout << s;
	return s;
}
int additionalAssignment1() {
	int rows,cols;
	cout << "Rows: ";
	cin >> rows;
	cout << "Columns: ";
	cin >> cols;
	int el;
	int** a = new int* [rows];
	int** b = new int* [rows];
	for (int i = 0; i < rows; i++) {
		a[i] = new int[cols];
		b[i] = new int[cols];
	}
	
	
	cout << "Start entering the elements" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> el;
			a[i][j] = el;
			
		}
	}
	int k = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (j % 2 != 0 && a[i][j] % 2 != 0) {
				b[i][j] = a[i][j];
				k++;
			}
			else {
				b[i][j] = -1;
			}
		}
	}
	int* c = new int[k];
	int position = 0;
	for (int i = 0; i < rows;i++) {
		for (int j = 0; j < cols; j++) {
			if (b[i][j] != -1) {
				c[position] = b[i][j];
				position++;
			}
		}
	}
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout <<   a[i][j] << ' ';
		}
		cout << endl;
	}
	if (k == 0) {
		cout << "The array is empty";
		return 0;
	}
	cout << endl;
	int cSum = 0;
	for (int i = 0; i < k; i++) {
		cout << c[i] << ' ';
		cSum += c[i];
	}
	cout << endl;
	int average = cSum / k;
	cout << "Average: " << average << endl;
	return average;
}
int fFunction(int n) {
	if (n % 10 > 0) {
		return n % 10;
	}
	else if (n == 0) {
		return 0;
	}
	else {
		return fFunction(n / 10);
	}
}
int additionalAssignment2_1() {
	int p, q;
	cout << "p=";
	cin >> p;
	cout << "q=";
	cin >> q;
	int res;
	int funcSum = 0;
	for (;p <= q; p++) {
		res = fFunction(p);

		funcSum += res;
	}
	cout << funcSum;
	return funcSum;
	
}

void main() {
	//assignment1(6, 18);
	//assignment3();
	//additionalAssignment1();
	assignment2();
	//additionalAssignment2_1(); FIX
}

