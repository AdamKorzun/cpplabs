#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <Windows.h>
using namespace std;
void assignment1() {
	const int stLength = 80;
	char st[stLength];
	char st1[stLength] = " ";
	char st2[stLength];
	cout << "string=";
	gets_s(st);
	
	int k;
	cout << "k=";
	cin >> k;
	if (st[k] == ' ') {
		for (int i = k + 1, j = 0; i < stLength - 1; i++, j++) {
			st2[j] = st[i];

		}
		for (int j = 0; j < k; j++) {
			st1[j] = st[j];
		}
	}
	else {
		int spaceNumber;
		for (int j = k; j >= 0; j--) {
			if (st[j] == ' ') {
				spaceNumber = j;
				break;
			}
		}
		for (int i = 0; i < spaceNumber;i++) {
			st1[i] = st[i];
		}
		for (int j = 0;spaceNumber + 1 < stLength - 1;spaceNumber++, j++) {
			st2[j] = st[spaceNumber + 1];
		}

	}
	puts(st1);
	puts(st2);
}


void assignment2() {
	const int stLength = 80;
	char st[stLength];
	cout << "string=";
	gets_s(st);
	char uniqueLetters[stLength];
	int letterNumber = 0;
	int ul = 0;
	
	int a = strlen(st);
	char* dynamicString = new char[a + 1];

	for (int i = 0; i < a; i++) {
		dynamicString[i] = st[i];
	}
	
	for (int i = 0; i <  a; i++) {
		if (dynamicString[i] != ' ') {
			ul++;
		}
	}
	// массив без пробелов
	char* withoutSpaces = new char[ul + 1];
	for(int i = 0,j=0; i < a; i++){
		if (dynamicString[i] != ' ') {
			withoutSpaces[j] = dynamicString[i];
			//cout << withoutSpaces[j];
			j++;
			
		}
	}
	char* uniqueLetter = new char[ul + 1];
	for (int i = 0; i < ul;i++) {
		uniqueLetter[i] = ' ';
	}
	// массив со всеми знаками
	for (int i = 0,k=0; i < ul; i++) {
		for (int j = 0; j < ul; j++) {
			if (withoutSpaces[i] == uniqueLetter[j]) {
				break;
			}
			if (j == ul - 1) {
				uniqueLetter[k] = withoutSpaces[i];
				//cout << uniqueLetter[k];
				k++;
			}
		}
	}
	int ulLength = 0;
	for (int i = 0; i < ul;i++) {
		if (uniqueLetter[i] != ' ') {
			ulLength += 1;
		}
	}
	char mostCommon = uniqueLetter[0];
	int mostInString = 0;
	int timesInString = 0;
	// наиболее частый символ
	for (int i = 0; i < ulLength;i++) {
		timesInString = 0;
		for (int j = 0;j < ul;j++) {
			if (uniqueLetter[i] == withoutSpaces[j]) {
				timesInString++;
				if (timesInString > mostInString) {
					mostInString = timesInString;
					mostCommon = uniqueLetter[i];
				}
			}
		}
	}
	cout << mostCommon << ':' << mostInString;
	//cout << ulLength;
}
bool isDigit(char a) {
	if (int(a) > 47 && int(a) < 58) {
		return true;
	}
	return false;
}
void assignment3() {
	// -1 == dot
	const int stLength = 80;
	int fillament = -5;
	int** Digits = new int* [stLength];
	for (int i = 0; i < stLength;i++) {
		Digits[i] = new int[stLength];
	}
	for (int i = 0; i < stLength; i++) {
		for (int j = 0; j < stLength;j++) {
			Digits[i][j] = fillament;
		}

	}
	char st[stLength];
	cout << "string=";
	cin >> st;
	int k = 0;
	int pos = 0;
	for (int i = 0; i < stLength;i++) {
		pos = 0;
		if (isDigit(st[i])) {
			//Digits[k][pos] = int(st[i])  - '0';
			//pos++;
			for (int j = i; j < stLength;j++) {
				if (isDigit(st[j])) {
					if (i == j && int(st[i]) - '0' == 0) {
						continue;
					}
					else {
						Digits[k][pos] = int(st[j]) - '0';
					}

				}
				else if (st[j] == int('.')) {
					Digits[k][pos] = -1;
				}
				else {
					break;
				}
				pos++;
			}
			k++;
		}
		if (pos != 0) {
			i = i + pos;
		}

	}
	// ол-во заполненных массивов 
	int notFArrays = 0;
	for (int i = 0; i < stLength; i++) {
		if (Digits[i][0] != fillament) {
			
			notFArrays++;
		}	
	}
	//«аполнение массива только целыми числами
	int** finalArray = new int* [notFArrays];
	int arrayLen = 0;
	int* lenArray = new int[notFArrays];

	for (int i = 0; i < notFArrays; i++) {
		arrayLen = 0;
		for (int j = 0; j < stLength; j++) {
			arrayLen++;
			if ((Digits[i][j] == fillament) || (Digits[i][j] == -1)) {
				break;
			}
				
		}
		//cout << arrayLen;
		finalArray[i] = new int[arrayLen];
		lenArray[i] = arrayLen - 1;
		//cout << lenArray[i];
		for (int j = 0; j < stLength; j++) {
			if ((Digits[i][j] == fillament) || (Digits[i][j] == -1)) {
				break;
			}
			finalArray[i][j] = Digits[i][j];
			//cout << finalArray[i][j];
		}
		//cout << endl;
	}
	int** rArray = new int* [notFArrays];
	for (int i = 0; i < notFArrays;i++) {
		rArray[i] = new int[1];
		int sum = 0;
		//cout << lenArray[i] << endl;
		//cout << sizeof(finalArray) << endl;
		
		//cout << size;
		for (int j = 0; j < lenArray[i];j++) {

			sum += pow(10, lenArray[i] - j - 1) * finalArray[i][j];
			//cout << sum << endl;
		}
		rArray[i][0] = sum;
		//cout << rArray[i][0] << endl;
	}
	int maxEl = rArray[0][0];
	for (int i = 0; i < notFArrays;i++){
		if (rArray[i][0] > maxEl) {
			maxEl = rArray[i][0];
		}
	}
	cout << "Max. element: " << maxEl << endl;
}
void additionalAssignment1() {

	const int stLength = 100;
	char st[stLength];
	cout << "string=";
	gets_s(st);
	
	int actualLength = 0;
	for (int i = 0;i < stLength;i++) {
		if (int(st[i]) != -2) {

			actualLength++;

		}
	}

	actualLength -= 1;
	int newLen = actualLength;
	for (int i = 0; i < actualLength;i++) {
		if (st[i] == 'p' && st[i + 1] == 'h') {
			newLen--;
		}
		if (st[i] == 'o' && st[i + 1] == 'o') {
			newLen--;
		}
		if (st[i] == 'e' && st[i + 1] == 'e') {
			newLen--;
		}
		if (st[i] == 't' && st[i + 1] == 'h') {
			newLen--;
		}
		if (st[i] == 'x') {
			newLen++;
		}
		if (st[i] == 'y' && st[i + 1] == 'o' && st[i + 2] == 'u') {
			newLen -= 2;
		}
		if (st[i] == st[i + 1]) {
			newLen--;
		}
	}
	//cout << "Actual len. " << actualLength << endl;
	//cout << "new len. " << newLen << endl;
	char* newString = new char[newLen + 3];
	newString[newLen+ 2] = '\0';
	for (int i = 0, j = 0; i < actualLength; i++) {
		if (st[i] == 'c') {
			if (st[i + 1] == 'e' || st[i + 1] == 'i' || st[i + 1] == 'y') {
				newString[j] = 's';

			}
			else {
				newString[j] = 'k';
			}
			j++;
		}
		else if (st[i] == 'q') {
			if (st[i + 1] == 'u') {
				newString[j] = 'k';
				newString[j + 1] = 'v';
				j += 2;
				i += 1;
			}
			else {
				newString[j] = 'k';
				j++;
			}
		}
		else if (st[i] == 'x') {
			newString[j] = 'k';
			newString[j + 1] = 's';
			j += 2;
		}
		else if (st[i] == 'w') {
			newString[j] = 'v';
			j++;
		}
		else if (st[i] == 'p' && st[i + 1] == 'h') {
			newString[j] = 'f';
			j++;
			i++;
		}
		else if (st[i] == 'y' && st[i + 1] == 'o' && st[i + 2] == 'u') {
			newString[j] = 'u';
			j++;
			i += 2;
		}
		else if (st[i] == 'o' && st[i + 1] == 'o') {
			newString[j] = 'u';
			j++;
			i++;
		}
		else if (st[i] == 'e' && st[i + 1] == 'e') {
			newString[j] = 'i';
			j++;
			i++;
		}
		else if (st[i] == 't' && st[i + 1] == 'h') {
			newString[j] = 'z';
			j++;
			i++;
		}
		//Capital
		else if (st[i] == 'C') {
			if (st[i + 1] == 'e' || st[i + 1] == 'i' || st[i + 1] == 'y') {
				newString[j] = 'S';

			}
			else {
				newString[j] = 'K';
			}
			j++;
		}
		else if (st[i] == 'Q') {
			if (st[i + 1] == 'u') {
				newString[j] = 'K';
				newString[j + 1] = 'v';
				j += 2;
				i += 1;
			}
			else {
				newString[j] = 'K';
				j++;
			}
		}
		else if (st[i] == 'X') {
			newString[j] = 'K';
			newString[j + 1] = 's';
			j += 2;
		}
		else if (st[i] == 'W') {
			newString[j] = 'V';
			j++;
		}
		else if (st[i] == 'P' && st[i + 1] == 'h') {
			newString[j] = 'F';
			j++;
			i++;
		}
		else if (st[i] == 'Y' && st[i + 1] == 'o' && st[i + 2] == 'u') {
			newString[j] = 'U';
			j++;
			i += 2;
		}
		else if (st[i] == 'O' && st[i + 1] == 'o') {
			newString[j] = 'U';
			j++;
			i++;
		}
		else if (st[i] == 'E' && st[i + 1] == 'e') {
			newString[j] = 'I';
			j++;
			i++;
		}
		else if (st[i] == 'T' && st[i + 1] == 'h') {
			newString[j] = 'Z';
			j++;
			i++;
		}

		else if (st[i] == st[i + 1]) {

			newString[j] = st[i];
			j += 1;
			i += 1;
			
		}
		else {
			newString[j] = st[i];

			j++;
		}
		//cout << newString[j - 1];
	}
	newString[newLen + 2] = '\0';
	//puts(newString);
	cout << endl;
	//cout << newLen << endl;
	char *finalString = new char[newLen+3];
	finalString[newLen + 2] = '\0';
	cout << endl;
	for (int i = 0,j=0; i < newLen+3;i++) {
		if (newString[i] == newString[i + 1]) {
			finalString[j] = newString[i];
			j++;
			i++;
			newLen--;

		}
		
		else {
			finalString[j] = newString[i];
			j++;
		}
		
	}
	
	char* re = new char[newLen + 1];

	re[newLen + 1] = '\0'; 
	for (int i = 0; i < newLen + 2; i++) {
		if (int(finalString[i]) != -51) {
			cout << finalString[i];
		}
		
	}

}
void additionalAssignment2() {
	return;

}
int fact(int a) {
	if (a <= 1) {
		return 1;
	}
	return a * fact((a - 1));
}
void additionalAssignment3() {
	const int stLength = 14;
	char st[stLength + 1] = { '\0' };
	cout << "string=";
	gets_s(st);
	int len = strlen(st);
	int result = fact(len);
	char* realString = new char[len + 1];
	strcpy_s(realString, stLength, st);
	char safeState;
	int minASCII;
	for (int i = 0; i < len;i++) {
		minASCII = int(realString[i]);
		for (int j = i; j < len; j++) {
			if (int(realString[j] < minASCII)) {
				safeState = realString[i];
				minASCII = int(realString[j]);
				realString[i] = realString[j];
				realString[j] = safeState;
			}
		}
	}
	int repNum = 0;
	for (int i = 0; i < len; i++) {
		repNum = 0;
		if (realString[i] != realString[i + 1]) {
			continue;
		}
		else {
			for (int j = i; j < len; j++) {
				if (realString[i] == realString[j]) {
					
					repNum+=1;
					
				}
				else if (j == (len - 1)) {
					i = j;
				}
				else {
					i = j;
					break;
				}
			}
			result /= fact(repNum);
			
		}
	}
	cout << result;
		
}
int main() {
	//assignment1();
	//assignment2();
	assignment3();
	//additionalAssignment1();

	//additionalAssignment3();
	system("pause");
	return 0;
}