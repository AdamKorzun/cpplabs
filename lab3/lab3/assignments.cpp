#define  _USE_MATH_DEFINES
#include <math.h>
#include <string> 
#include <conio.h>
#include <iostream>
#include <cmath>
using namespace std;

int assignment1() {
	float a, b, N = 0;
	int i = 1;

	while (i <= 30) {
		if (i % 2 == 0){
			a = i / 2;
			b = pow(a, 3);
		}
		else {
			a = i;
			b = pow(i, 2);
		}
		N += pow((a - b), 2);
		i += 1;
	}
	cout << "N=" << N << endl;
	return 0;
}

int assignment2(){
	float d = 0, dn = 0, e = 0.001;
	int n = 1;
	do  {
		d = (1 / pow(2, n)) + (1 / pow(3, n));
		dn += d;
		n += 1;
	} while (d > e);
	cout << "dn=" << dn << endl;
	return 0;
}
int assignment3() {
	float y,H,M,A,B,x;
	
	A = 0;
	
	B = M_PI / 2;
	M = 20;
	H = (B - A) / M;
	for (float i = 0; (x = A + i * H) <= B; i++) {
		y = sin(x) + cos(x);
		cout << "y=" << y << endl;
	}
	return 0;
}	
int fact(int x) {
	int s = 1;
	for (int i = x; i >= 1; i--) {
		s *= i;
	}
	return s;

}
int personalAssignment1() {
		int n;
	float x,s = 0,f, numbers;
	
	cout << "n=";
	cin >> n;
	cout << "numbers=";
	cin >> numbers;
	for (int e = 1; e <= numbers; e++) {
		s = 0;
		cout << "x=";
		cin  >> x;
		for (int i = 1; i <= n; i++) {
			s += pow(-1, i) * pow(2 * x, 2 * i) / fact(i * 2);
		}
		f = 2 * (pow(cos(x), 2) - 1);
		cout << "f(" << x << ")=" << f << ";		s(" << x << ")=" << s << endl;
	}

	return 0;
}
int personalAssignment2() {
	double start = 0, end = 1, parts, step,minValue,y, closestX;
	
	cout << "Number of parts: ";
	cin >> parts;

		step = end - start / parts;
		minValue =fabs(sinh(start) + acos(start) - 1.5)	; 
		closestX = start;
	for (; start <= end; start += step) {
		y = sinh(start) + acos(start) - 1.5; 
		if (fabs(y) < minValue) {			
			minValue = fabs(y);
			closestX = start;
		}
		
	}
	cout << "\nf(" << closestX << ") = "<<(sinh(closestX) + acos(closestX) - 1.5) << endl;
	

	return 0;
}
/*float ch(float x) {
	float ch;
	ch = (exp(x) + exp(-x)) / 2;
	return ch;
}
*/
int personalAssignment3() {
	float f, a, b, h, step,ch;
	
	a = 1;
	step = a;
	b = 4;
	h = 1;
	for (; step <= b; step += h) {
		ch = (exp(step) + exp(-step)) / 2;
		f = exp(step) * ch;
		cout << "f(" << step << ") = " << f << endl;
	}
	return 0;
}

int additionalAssignment1() {
	int firstDigit,secondDigit, thirdDigit, originalSum;
	for (int i = 10; i < 100; i++) {
		firstDigit = i / 10;
		secondDigit = i % 10;
		originalSum = firstDigit + secondDigit;
		for (int b = 2; b < 10; b++) {
			if ((i * b) / 100 == 0) {
				if ((i * b / 10 + i * b % 10) != originalSum)
				{
					
					break;
				}
				
			}
			else {
				
				if (((i * b) / 100 + ((i * b / 10) % 10) + (i * b % 10)) != originalSum){
					
					break;
				}
			}
			if (b == 9) {
				cout << i << endl;
			}
			

		}

		
	}
	return 0;
}
int additionalAssignment2() {
	long int k, z1 = 0, z2 = 1, f = 0;
	string sequence = "" ;
	cout << "k = ";
	cin >> k;
	for (int i = 1; i <= k;i++) {
		if (i == 1){
			sequence = sequence + to_string(z1);
			continue;
		}
		if (i == 2){
			sequence = sequence + to_string(z2);
			continue;
		}
		f = z1 + z2;
		z1 = z2;
		z2 = f;
		sequence = sequence + to_string(f);
		
		
		
	}
	
	cout << sequence << endl;
	cout << sequence[k - 1];
	return 0;
}
int main() {
	//assignment1();
	//assignment2();
	//assignment3();
	//personalAssignment1();
	//personalAssignment2();
	//personalAssignment3();
	//additionalAssignment1();
	//additionalAssignment2();
	return 0;
	
}
