#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <math.h>
using namespace std;

int assignment1() {
	int x, y;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;

	(x == y) ? y = 0, x = 0 : ((x > y) ? y = 0 : x = 0);

	cout << "x=" << x << endl;
	cout << "y=" << y << endl;


	return 0;
}

int assignment1_2() {
	int A, B, C;
	cout << "A=";
	cin >> A;
	cout << "B=";
	cin >> B;
	cout << "C=";
	cin >> C;

	if (A > B && A > C) {
		A -= 3;
		cout << "A=" << A;
	}
	else if (B > A && B > C) {
		B -= 3;
		cout << "B=" << B;
	}
	else if (C > A && C > B) {
		C -= 3;
		cout << "C=" << C;
	}
	else {
		cout << "Error";
	}

	return 0;

}

int assignment2() {
	float d,a, b;
	char zn;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
zn:
	cout << "zn: ";
	cin >> zn;

	if (zn == '/') {
		d = a / b;
	}
	else if (zn == '*') {
		d = a * b;
	}
	else if (zn == '+') {
		d = a + b;
	}
	else if (zn == '-') {
		d = a - b;
	}
	else if (zn == '%') {
		d = int(a) % int(b);
	}
	else {
		goto zn;
	}
	cout << d;

	return 0;
}


int assignment3() {
	int a, b;
	bool aoverb;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;

	if (a > b) {
		aoverb = true;
	}
	else if (b == a){
		cout << "a = b/n";
		return 0;
	}
	else {
		aoverb = false;
	}
	aoverb ? cout << "a > b" : cout << " b > a";

	return 0;
}


int assignment4() {
	float m, L, k, x1, x2;
	//  x1 = 0.7, x2 = 1.8, m = 5
	cout << "x1=";
	cin >> x1;
	cout << "x2=";
	cin >> x2;
	cout << "m=";
	cin >> m;
	k = pow(cos(pow(x1, 2)), 3) + pow(sin(pow(x2, 3)), 2);
	if (k < 1) {
		L = pow(k, 3) + pow(m, 0.2);
	}
	else {
		L = pow(k, 2) - exp(m);
	}

	cout << L << endl;
	return 0;
}


int assignment5() {
	float a, b, c, z,d;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	cout << "d=";
	cin >> d;

	if ((c >= d) && (a < d)) {
		z = a + b / c;
	}
	else if ((c < d) && (a > d)) {
		z = a - b / c;
	}
	else {
		z = 0;
	}
	cout << "z=" << z;

	return 0;
}
int assignment6() {
	float a, y, b, c;
	int N; 
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	cout << "N=";
	cin >> N;

	switch (N) {
		case 2: y = a * b - pow(a, 2);break;
		case 56: y = b * c;break;
		case 7: y = pow(a, 2) + c;break;
		case 3: y = a - b * c;break;
		default: y = pow((a + b), 3);break;
	}

	cout << "y=" << y;

	return 0;
}

int assignment7() {
	// ax^4 + bx^2 + c = 0
	float a, b, c, x1, x2, x3, x4, y1, y2;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	if (a == 0) {
		if ((c <= 0 && b > 0) || (c >=0 && b < 0)) {
			x1 = sqrt(-c / b);
			x2 = -sqrt(-c / b);
			cout << "x1=" << x1 << endl << "x2=" << x2 << endl;
		}
		else {
			cout << "Error";
			return 0;
		}

	}
	else if (b == 0) {
		if (a > 0 && c <= 0 || a < 0 && c >= 0) {
			x1 = pow(-c, 1. / 4 );
			x2 = -pow(-c, 1. / 4);
			cout << "x1=" << x1 << endl << "x2=" << x2;
			return 0;

		}
		else {
			cout << "Error";
			return 0;
		}
	}
	else if (c == 0) {
		
		if ((a > 0 && b <= 0) || (a < 0 && b >= 0)) {
			x1 = 0;
			x2 = pow(-b / a, 1. / 2);
			cout << "x1=" << x1 << endl << "x2=" << x2;
		}
		else {
			cout << "Error";
			return 0;
		}
			
	}
	else {
		y1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		y2 = (-b + -sqrt(b * b - 4 * a * c)) / (2 * a);
		if (y1 >= 0) {
			x1 = sqrt(y1);
			x2 = -sqrt(y1);
			cout << "x1=" << x1 << endl << "x2=" << x2 << endl;
		}
		else {
			cout << "y1 < 0\n";
		}
		if (y2 >= 0) {
			x3 = sqrt(y2);
			x4 = -sqrt(y2);
			cout << "x3=" << x3 << endl << "x3=" << x4 << endl;
		}
		else {
			cout << "y2 < 0\n";
		}
	}


	return 0;


}
int assignment8() {
	int N, k, lastDigit, ts;
	cout << "N=";
	cin >> N;
	cout << "k=";
	cin >> k;

	if ((N >= 20) || (k >= 80)) {
		cout << "Error";
		return 0;
	}
	ts = N + k;
	lastDigit = ts % 10;

	if (ts >= 11 && ts <= 14) {
		cout << "У вас " << ts << " рублей\n";
		return 0;
	}

	switch (lastDigit) {
	case 1: cout << "У вас " << ts << " рубль\n"; break;
	case 2: cout << "У вас " << ts << " рубля\n"; break;
	case 3: cout << "У вас " << ts << " рубля\n"; break;
	case 4: cout << "У вас " << ts << " рубля\n"; break;
	case 5: cout << "У вас " << ts << " рублей\n"; break;
	case 6: cout << "У вас " << ts << " рублей\n"; break;
	case 7: cout << "У вас " << ts << " рублей\n"; break;
	case 8: cout << "У вас " << ts << " рублей\n"; break;
	case 9: cout << "У вас " << ts << " рублей\n"; break;
	case 0: cout << "У вас " << ts << " рублей\n"; break;
	default: cout << "Error"; return 0;
	}
	return 0;
}
int assignment9() {
	int currentYear, birthYear, age, yearRemainder;
	cout << "Current Year=";
	cin >> currentYear;
	cout << "Birth Year=";
	cin >> birthYear;
	age = currentYear - birthYear;
	if (age > 122 || age < 0) {
		cout << "Error";
		return 0;
	}
	yearRemainder = age % 10;

	if ((age >= 11 && age <= 14) || (age >= 111 && age <=114)) {
		cout << "Вам " << age << " лет\n";
		return 0;
	}
		switch (yearRemainder) {
		case 1: cout << "Вам " << age << " год.\n"; break;
		case 2: cout << "Вам " << age << " года \n"; break;
		case 3: cout << "Вам" << age << " года\n"; break;
		case 4: cout << "Вам " << age << " года \n"; break;
		case 5: cout << "Вам " << age << " лет \n"; break;
		case 6: cout << "Вам " << age << " лет \n"; break;
		case 7: cout << "Вам " << age << " лет \n"; break;
		case 8: cout << "Вам " << age << " лет \n"; break;
		case 9: cout << "Вам " << age << " лет \n"; break;
		case 0: cout << "Вам " << age << " лет \n"; break;
		default: cout << "Error\n"; return 0;
	}
	return 0;
}
int passignment1() {
	float y, x, z, f, c, alpha;
	int functionNumber;
	cout << "z=";
	cin >> z;
cout << "Alpha=";
cin >> alpha;
cout << "c=";
cin >> c;

if (z > 1) {
	x = 1 / sqrt(z - 1);
}
else {
	x = pow(z, 2) + 1;
}
cout << "1 - 2x \n2 - x^2\n3 - x/3\nChose f(x): ";
cin >> functionNumber;
switch (functionNumber) {
case 1:	f = 2 * x; break;
case 2: f = pow(x, 2); break;
case 3: f = x / 3; break;
default: cout << "Error\n"; return 0;
}

y = alpha * pow(sin(pow(f, 2) - 1), 3) + c * log(fabs(x)) + exp(x);
cout << "y=" << y << endl;

return 0;
}
int passignment2() {
	float x, y, s;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;

	if (y > 2 * x) {
		cout << "tg(x) + x^2\n";
		s = tan(x) + pow(x, 2);
	}
	else if (y < 2 * x) {
		cout << "|x+y|^3\n";
		s = pow(fabs(x + y), 3);
	}
	else {
		cout << "x^(1/3) * sin(x)\n";
		s = pow(x, 1. / 3) * sin(x);
	}
	cout << "s=" << s << endl;
	return 0;
}
int additionalAssignment1() {
	float x0, y0, x, y, R, xdif, ydif, hyp;
	cout << "x0=";
	cin >> x0;
	cout << "y0=";
	cin >> y0;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	cout << "R=";
	cin >> R;

	xdif = fabs(x0 - x);
	ydif = fabs(y0 - y);
	hyp = sqrt(pow(xdif, 2) + pow(ydif, 2));
	if (hyp > R) {
		cout << "Точка не попадает в круг\n";
	}
	else {
		cout << "Точка попадает в круг\n";
	}



	return 0;
}
int additionalAssignment2() {
	float a, b, c, x, y, f;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;

	if (a > b && a > c) {
		if (b < c) {
			f = b;
			b = c;
			c = f;
		}
		else {
			f = b;
			b = c;
			c = f;
		}
	}
	else if (a > b && a < c) {
		f = a;
		a = c;
		c = b;
		b = f;
		
	}
	else if (a <= b && a <= c) {
		if (b > c) {
			f = a;
			a = b;
			b = c;
			c = f;

		}
		else {
			f = a;
			a = c;
			c = f;
		}
	}
	cout << "a=" << a << "\nb=" << b << "\nc=" << c << endl;
	if (a < x) {
		if (b < y || c < y) {
			cout << "Кирпич пройдет\n";
		}
		else {
			cout << "Кирпч не пройдет\n";
			return 0;
		}
	}
	else if (b < x) {
		if ((a < y) || (c < y)){
			cout << "Кирпич пройдет\n";
		}
		else {
			cout << "Кирпич не пройдет\n";
			return 0;
		}
	}
	else if (c < x) {
		if ((b < y) || (a < y)) {
			cout << "Кирпич пройдет\n";
		}
		else {
			cout <<"Кирпич не пройдет\n";
				return 0;
		}
	}
	else {
		cout << "Кирпич не пройдет\n";
		
	}
	return 0;
}
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//assignment1();
	//assignment1_2();
	//assignment2();
	//assignment3();
	//assignment4(); 
	//assignment5(); 
	//assignment6();
	//assignment7(); 
	//assignment8();
	//assignment9();
	//passignment1();
	//passignment2();
	//additionalAssignment1();
	additionalAssignment2();
	return 0;
}


