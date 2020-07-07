#include <iostream>
#include <conio.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;


int assignment() {
	float S, A, D, b, x, d;

	cout << "x=";
	cin >> x;
	cout << "D=";
	cin >> D;
	if (x == 0 && D == 0) {
		cout << "Error \n";
		return 0;
	}
	b = x + D;
	A = D * x / b;
	S = (pow(A, 2) + b * cos(x)) / (pow(D, 3) + (A + D - b)); //x / 180 * M_PI

	cout << "S=" << S << endl;


	return 0;
}
int additionalAssignment() {
	float s1, s2, area, perimeter, diagonal;
	
	cout << "s1=";
	cin >> s1;
	cout << "s2=";
	cin >> s2;

	if (s1 <= 0 || s2 <= 0) {
		cout << "Error";
		return 0;
	}

	perimeter = (s1 + s2) * 2;
	area = s1 * s2;
	diagonal = sqrt(pow(s1, 2) + pow(s2, 2));

	cout << "Perimeter=" << perimeter << endl << "Area=" << area << endl << "Diagonal=" << diagonal << endl;
	return 0;

}
int main() {
	assignment();
	additionalAssignment();
	_getch();
	return 0;

}