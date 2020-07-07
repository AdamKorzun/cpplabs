#include <iostream>
#include <math.h>
#include <algorithm>
#include <Windows.h>
using namespace std;

char* toBinary(char* arr) {
	int alen = strlen(arr);
	int binaryLen = strlen(arr) * 4 * 8;
	char* binaryString = new char[binaryLen + 1];
	binaryString[binaryLen] = '\0';
	char* binaryTemp = new char[binaryLen + 1];
	binaryTemp[binaryLen] = '\0';
	

	bool isNegative;
	int i;
	if (arr[0] == '-') {
		binaryString[0] = '1';
		binaryString[1] = ',';
		i = 1;
		isNegative = true;
	}
	else {
		binaryString[0] = '0';
		binaryString[1] = ',';
		i = 0;
		isNegative = false;
	}
	bool isFloat = false;
	int dotPos;
	for (int j = 0; j < strlen(arr);j++) {
		if (arr[j] == '.') {
			isFloat = true;
			dotPos = j;
		}
	}
	int IntPart = 0;
	float FloatPart = 0;
	
	if (isFloat) {
		for (int j = i;j < dotPos; j++) {
			IntPart += (int(arr[j])- '0') * pow(10, dotPos - j - 1);
		}
		for (int j = dotPos + 1; j < alen; j++) {
			FloatPart += (int(arr[j] - '0')) * pow(10, dotPos - j);
		}
	}
	
	else {
		for (int j = i;j < alen; j++) {
			IntPart += (int(arr[j]) - '0') * pow(10, alen - j - 1);
		}
	}

	//cout << IntPart << endl;
	//cout << FloatPart << endl;
	
	for (int k = 0; IntPart > 0; k++) {
		binaryTemp[k] = char(IntPart % 2 + int('0'));
		IntPart /= 2;
		
	}
	
	int tempLen = 0;
	for (int j = 0; j < strlen(binaryTemp); j++) {
		if (binaryTemp[j] == '0' || binaryTemp[j] == '1') {
			tempLen++;
		}
	}

	for (int j = tempLen - 1,c = 2; j >= 0; j--,c++) {
		
		binaryString[c] = binaryTemp[j];
		
	}
	if (isFloat) {
		binaryString[tempLen + 2] = '.';
		for (int s = tempLen + 3;FloatPart != int(FloatPart);s++) {
			FloatPart *= 2;
			binaryString[s] = char(int(FloatPart) + int('0'));
			if (FloatPart > 1.0) {
				FloatPart = FloatPart - int(FloatPart);
			}
		}
	}
	int bLen = 0;
	for (int j = 0; j < strlen(binaryString); j++) {
		if (binaryString[j] == '1' || binaryString[j] == '0' || binaryString[j] == '.' || binaryString[j] == ',') {
			bLen++;
		}
	}
	char* finalArray = new char[bLen + 1];
	finalArray[bLen] = '\0';
	for (int j = 0; j < bLen; j++) {
		finalArray[j] = binaryString[j];
	}
	cout << "Binary: ";
	puts(finalArray);

	return finalArray;
}
float toDecimal(char* arr,int base) {
	int alen = strlen(arr);
	int clen = alen * 4 * 8;
	char* convertedArray = new char[clen];
	convertedArray[clen] = '\0';
	char* tempArray = new char[clen];
	tempArray[clen] = '\0';
	float number = 0;
	bool isFloat = false;
	int k = 0;
	bool isNegative = false;
	if (arr[0] == '-') {
		isNegative = true;
		convertedArray[0] = '-';
		k = 1;
	}
	int dotPos;
	for (int i = 0;i < alen; i++) {
		if (arr[i] == '.') {
			isFloat = true;
			dotPos = i;
		}
	}
	if (isFloat) {
		for (int i = k; i < dotPos; i++) {

			if (arr[i] == 'A') {
				number += 10 * pow(base, dotPos - i - 1);
			
			}
			else if (arr[i] == 'B') {
				number += 11 * pow(base, dotPos - i - 1);
			}
			else if (arr[i] == 'C') {
				number += 12 * pow(base, dotPos - i - 1);
			}
			else if (arr[i] == 'D') {
				number += 13 * pow(base, dotPos - i - 1);
			}
			else if (arr[i] == 'E') {
				number += 14 * pow(base, dotPos- i - 1);
			}
			else if (arr[i] == 'F') {
				number += 15 * pow(base, dotPos - i - 1);
			}
			else {
				
				number += (int(arr[i]) - int('0')) * pow(base, dotPos - i - 1);
			}
		}
		for (int i = dotPos + 1; i < alen; i++) {
			if (arr[i] == 'A') {
				number += 10 * pow(base, dotPos - i);
			
			}
			else if (arr[i] == 'B') {
				number += 11 * pow(base, dotPos - i);
			}
			else if (arr[i] == 'C') {
				number += 12 * pow(base, dotPos - i);
			}
			else if (arr[i] == 'D') {
				number += 13 * pow(base, dotPos - i);
			}
			else if (arr[i] == 'E') {
				number += 14 * pow(base, dotPos - i);
			}
			else if (arr[i] == 'F') {
				number += 15 * pow(base, dotPos - i);
			}
			else {

				number += (int(arr[i]) - int('0')) * pow(base, dotPos - i);
			}
		}
	}
	else {
		for (int i = k; i < alen; i++) {
			
			if (arr[i] == 'A') {
				number += 10 * pow(base, alen - i - 1);
			}
			else if (arr[i] == 'B') {
				number += 11 * pow(base, alen - i - 1);
			}
			else if (arr[i] == 'C') {
				number += 12 * pow(base, alen - i - 1);
			}
			else if (arr[i] == 'D') {
				number += 13 * pow(base, alen - i - 1);
			}
			else if (arr[i] == 'E') {
				number += 14 * pow(base, alen - i - 1);
			}
			else if (arr[i] == 'F') {
				number += 15 * pow(base, alen - i - 1);
			}
			else {
				
				number += (int(arr[i]) - int('0'))* pow(base, alen - i - 1);
			}
		}
		
	}
	if (isNegative) {
		number *= -1;
	}
	

	return number;
}
void assignment1() {
	const int stLength = 256;
	char st[stLength] = {'\0'};
	cout << "Number: ";
	gets_s(st);
	int len = strlen(st);
	char* newSt = new char[len + 1];
	newSt[len] = '\0';
	for (int i = 0; i < len; i++) {
		newSt[i] = st[i];
	}
	//puts(newSt);

	float decNum = toDecimal(newSt,11);
	char* tempValue = new char[len * 8 + 1];
	tempValue[len * 8] = '\0';
	char* hexoValue = new char[len * 8 + 1];
	hexoValue[len * 8] = '\0';
	int k = 0;
	bool isNegative = false;
	bool isFloat = false;
	int intPart = fabs(int(decNum));
	float floatPart;
	if (decNum != int(decNum)) {
		isFloat = true;
		floatPart = fabs(decNum - int(decNum));
	}
	if (decNum < 0) {
		isNegative = true;
		k = 1;
		hexoValue[0] = '-';
	}
	decNum = fabs(decNum);
	if (isFloat) {
		int newL = 0;
		for (int i = 0; intPart > 0; i++) {
			tempValue[i] = char(int(intPart) % 6 + '0');
			intPart = intPart / 6;
			newL = i;
		}
		for (int i = k, j = newL; j >= 0; i++, j--) {
			hexoValue[i] = tempValue[j];
		}
		hexoValue[k + newL + 1] = '.';
		newL += k + 2;
		for (int i = newL; floatPart != int(floatPart); i++) {
			hexoValue[i] = char(int(floatPart * 6) + '0');
			floatPart = floatPart * 6;
			floatPart = floatPart - int(floatPart);
		}
		
	}
	else {
		int newL = 0;
		for (int i=0; decNum > 0;i++) {
			tempValue[i] = char(int(decNum) % 6 + '0');
			decNum = int(int(decNum) / 6);
			newL = i;
		}
		for (int i = k, j = newL; j >= 0; i++, j--) {
			hexoValue[i] = tempValue[j];
		}
	}
	int realLen = 0;
	for (int i = 0; i < len * 8; i++) {
		if (int(hexoValue[i]) != -51) {
			realLen++;
		}
	}
	char* finalNum = new char[realLen + 1];
	finalNum[realLen] = '\0';
	for (int i = 0; i < realLen; i++) {
		finalNum[i] = hexoValue[i];
	}
	puts(finalNum);
	//puts(newSt);

}
void assignment2() {
	
	const int stLength = 100;
	char st[stLength] = { '\0' };
	float numToConvert;
	cout << "Number: ";
	gets_s(st);
	int len = strlen(st);
	//cout << len;
	char* newSt = new char[len + 1];
	newSt[len] = '\0';
	for (int i = 0; i < len; i++) {
		newSt[i] = st[i];
	}
	//double b = atof(newSt);
	//cout << b;
	//puts(newSt);

	
	char *binStr = toBinary(newSt);
	for (int k = 2; k < strlen(binStr); k++) {
		if (binStr[0] == '1') {
			if (binStr[k] == '1') {
				binStr[k] = '0';
			}
			else if (binStr[k] == '0') {
				binStr[k] = '1';
			}
		}
	}
	cout << "Code: ";
	puts(binStr);
	//cout << sizeof(float);

}
void assignment3() {
	const int stLength = 100;
	char st1[stLength];
	cout << "First number: ";
	gets_s(st1);
	char st2[stLength];
	cout << "Second number: ";
	gets_s(st2);
	int len1 = strlen(st1);
	int len2 = strlen(st2);
	char* newSt1 = new char[len1 + 1];
	newSt1[len1] = '\0';
	char* newSt2 = new char[len2+ 1];
	newSt2[len2] = '\0';
	for (int i = 0; i < len1; i++) {
		newSt1[i] = st1[i];
	}
	for (int i = 0; i < len2; i++) {
		newSt2[i] = st2[i];
	}
	bool isFloat1 = false;
	bool isFloat2 = false;
	bool isNegative1 = false;
	bool isNegative2 = false;
	int dotPos1 = 0;
	int dotPos2 = 0;
	char* binNum1 = toBinary(newSt1);
	char* binNum2 = toBinary(newSt2);
	int newLen1 = strlen(binNum1);
	int newLen2 = strlen(binNum2);
	for (int i = 0; i < newLen1; i++) {
		if(binNum1[i] == '.'){
			isFloat1 = true;
			dotPos1 = i;
		}
		if (binNum1[0] == '1') {
			isNegative1 = true;
		}
	}
	for (int i = 0; i < newLen2; i++) {
		if (binNum2[i] == '.') {
			isFloat2 = true;
			dotPos2 = i;
		}
		if (binNum2[0] == '1') {
			isNegative2 = true;
		}
	}
	

	int maxLen = max(dotPos1, dotPos2) + max(strlen(binNum1) - dotPos1,strlen(binNum2) - dotPos2) ;
	char* secEl = new char[maxLen];
	secEl[maxLen] = '\0';
	char* newBin = new char[maxLen];
	newBin[maxLen] = '\0';
fl:
	if (dotPos1 >= dotPos2) {
		
		newBin = new char[maxLen + 1];
		newBin[maxLen] = '\0';
		if (isFloat2 && isFloat1) {
		
			newBin[dotPos1] = '.';
			newBin[0] = binNum2[0];
			newBin[1] = ',';
			for (int i = dotPos1 - 1, j = dotPos2- 1; j > 1; i--,j--) {
				newBin[i] = binNum2[j];
				
			}
			for (int i = dotPos2 - 1; i >= 0; i--) {
				if (int(newBin[i]) == -51) {
					newBin[i] = '0';
				}
			}
			for (int i = dotPos2 + 1, j = dotPos1 + 1; i < strlen(binNum2); i++, j++) {
				newBin[j] = binNum2[i];
			}
			for (int i = dotPos1 + 1; i < maxLen; i++) {
				if (int(newBin[i]) == -51) {
					newBin[i] = '0';
				}
			}
			strcpy_s(secEl, maxLen + 1, binNum1);
			secEl[maxLen] = '\0';
			for (int i = dotPos1 + 1; i < maxLen; i++) {
				if (secEl[i] != '1' && secEl[i] != '0') {
					secEl[i] = '0';
				}
			}
		}

		
		else {

			if (isFloat1 == false) {
				dotPos1 = strlen(binNum1);
				isFloat1 = true;
			}
			if (isFloat2 == false) {
				dotPos2 = strlen(binNum2);
				isFloat2 = true;
			}

			goto fl;

		}
	}
	else if (dotPos2 > dotPos1) {
		newBin = new char[maxLen + 1];
		newBin[maxLen] = '\0';
		if (isFloat2 && isFloat1) {
			//cout << "true";
			newBin[dotPos2] = '.';
			newBin[0] = binNum1[0];
			newBin[1] = ',';
			for (int i = dotPos2 - 1, j = dotPos1 - 1; j > 1; i--, j--) {
				newBin[i] = binNum1[j];

			}
			for (int i = dotPos2 - 1; i >= 0; i--) {
				if (int(newBin[i]) == -51) {
					newBin[i] = '0';
				}
			}
			for (int i = dotPos1 + 1, j = dotPos2 + 1; i < strlen(binNum1); i++, j++) {
				newBin[j] = binNum1[i];
			}
			for (int i = dotPos2 + 1; i < maxLen; i++) {
				if (int(newBin[i]) == -51) {
					newBin[i] = '0';
				}
			}
			strcpy_s(secEl, maxLen + 1, binNum2);
			secEl[maxLen] = '\0';
			for (int i = dotPos2 + 1; i < maxLen; i++) {
				if (secEl[i] != '1' && secEl[i] != '0') {
					secEl[i] = '0';
				}
			}
		}

		else {
		
			if (isFloat1 == false) {
				dotPos1 = strlen(binNum1);
				isFloat1 = true;	
			}
			if (isFloat2 == false) {
				dotPos2 = strlen(binNum2);
				isFloat2 = true;
			}
		
			goto fl;

		}
	}
	if (newBin[maxLen- 1] == '.' && secEl[maxLen - 1] == '.') {
		newBin[maxLen - 1] = '\0';
		secEl[maxLen - 1] = '\0';
	}
	maxLen += 1;
	char* newBin2 = new char[maxLen + 1];
	newBin2[maxLen] = '\0';
	char* secEl2 = new char[maxLen + 1];
	secEl2[maxLen] = '\0';
	newBin2[2] = '0';
	secEl2[2] = '0';
	newBin2[1] = ',';
	secEl2[1] = ',';
	newBin2[0] = newBin[0];
	secEl2[0] = secEl[0];
	for (int i = 3; i < maxLen; i++) {
		newBin2[i] = newBin[i - 1];
		secEl2[i] = secEl[i - 1];
	}
	if (newBin2[0] == '1'){
		for (int i = 2; i < maxLen; i++) {
			if (newBin2[i] == '0') {
				newBin2[i] = '1';
			}
			else if (newBin2[i] == '1') {
				newBin2[i] = '0';
			}
		}
	}

	if (secEl2[0] == '1') {
		for (int i = 2; i < maxLen; i++) {
			if (secEl2[i] == '0') {
				secEl2[i] = '1';
			}
			else if (secEl2[i] == '1') {
				secEl2[i] = '0';
			}
		}
	}
	char* newSum = new char[maxLen + 1];
	newSum[maxLen] = '\0';
	int addVal = 0;
	
	for (int i = maxLen - 1; i >= 2; i--) {
		if (newBin2[i] == '.') {
			newSum[i] = '.';
		}
		if ((newBin2[i] == '1' || newBin2[i] == '0')) {
			if ((newBin2[i] == '0' && secEl2[i] == '0') && addVal == 0) {
				newSum[i] = '0';
			}
			else if ((((newBin2[i] == '0' && secEl2[i] == '1') && addVal == 0) || ((newBin2[i] == '1' && secEl2[i] == '0')) && addVal == 0)) {
				newSum[i] = '1';
			}
			else if ((newBin2[i] == '1' && secEl2[i] == '1') && addVal == 0) {
				newSum[i] = '0';
				addVal = 1;
			}
			else if ((newBin2[i] == '0' && secEl2[i] == '0' && addVal == 1)) {
				newSum[i] = '1';
				addVal = 0;
			}
			else if ((newBin2[i] == '1' && secEl2[i] == '0' && addVal == 1) || (newBin2[i] == '0' && secEl2[i] == '1' && addVal == 1)) {
				newSum[i] = '0';
			}
			else if (newBin2[i] == '1' && secEl2[i] == '1' && addVal == 1) {
				newSum[i] = '1';
			}
		}
	}
	
	newSum[1] = ',';
	if(newBin2[0] == '0' && secEl2[0] == '0' ){
		newSum[0] = newBin2[0] + addVal;
		addVal = 0;
	}
	else if (newBin2[0] == '1' && secEl2[0] == '1' && addVal == 0) {
		newSum[0] = '1';
	}
	else if ((newBin2[0] == '1' && secEl2[0] == '0' && addVal == 0) || (newBin2[0] == '0' && secEl2[0] == '1' && addVal == 0)) {
		newSum[0] = '1';
	}
	else if (addVal == 1) {
	
		if ((newBin2[0] == '1' && secEl2[0] == '0') || ((newBin2[0] == '0' && secEl2[0] == '1'))) {
			newSum[0] = '0';
			
		}
		else {
			newSum[0] = '1';
		}
		for (int i = maxLen - 1; addVal != 0; i--) {
			if (newSum[i] == '1' || newSum[i] == '0') {
				if (newSum[i] == '0') {
					newSum[i] = '1';
					addVal = 0;
				}
				else if (newSum[i] == '1') {
					newSum[i] = '0';
				}
			}
		}
	}

	/*
	if (newSum[0] == '1'){
		for (int i = 2; i < maxLen; i++) {
			if (newSum[i] == '0') {
				newSum[i] = '1';
			}
			else if (newSum[i] == '1') {
				newSum[i] = '0';
			}
		}
	}
	*/
	
	char* final = new char[maxLen - 1];
	final[maxLen - 2] = '\0';

	for (int i = 2; i < maxLen; i++) {
		final[i - 2] = newSum[i];
	}

	
	puts(newBin2);
	cout << "+\n";
	puts(secEl2);
	puts(newSum);
	//puts(final)
	;
	if (final[strlen(final ) - 1] == -51) {
		final[strlen(final) - 1] = '\0';
	
	}
	if (final[0] == '1') {
		for (int i = 0; i < strlen(final); i++) {
			if (final[i] == '1') {
				final[i] = '0';
			}
			else if (final[i] == '0') {
				final[i] = '1';
			}
		}
	}

	
	float res = toDecimal(final, 2);
	if (newSum[0] == '1' && res != 0) {
		res = res * -1;
	}
	cout << res << endl;
}
int* toInt(char* arr) {
	int len = strlen(arr) + 1;
	int* ret = new int[len - 2];
	
	for (int i = 2,j=0; i < len; i++,j++) {
		if (arr[i] >= '0' && arr[i] <= '9') {
			ret[j] = int(arr[i] - '0');
		}
		else if (arr[i] == 'A') {
			ret[j] = 10;
		}
		else if (arr[i] == 'B') {
			ret[j] = 11;
		}
		else if (arr[i] == 'C') {
			ret[j] = 12;
		}
		else if (arr[i] == 'D') {
			ret[j] = 13;
		}
		else if (arr[i] == 'E') {
			ret[j] = 14;
		}
		else if (arr[i] == 'F') {
			ret[j] = 15;
		}
		else if (arr[i] == 'G') {
			ret[j] = 16;
		}
		else if (arr[i] == 'H') {
			ret[j] = 17;
		}


	}
	return ret;
}
void assignment4() {
	const int stLength = 100;
	char st[stLength] = {0};
	char operat;
	cout << "First number: ";
	gets_s(st);
	char st2[stLength] = { 0 };
	cout << "Operation (-/+): ";
	cin >> operat;
	cout << "Second number: ";
	gets_s(st2);
	gets_s(st2);
	int newLen1 = strlen(st);
	char* newSt1 = new char[newLen1];
	int newLen2 = strlen(st2);
	char* newSt2 = new char[newLen2];
	char* addStr = new char[1];
	char* secStr = new char[1];
	
	if (newLen1 != newLen2) {
		if (newLen1 > newLen2) {
			addStr = new char[newLen1 + 1 + 3];
			addStr[newLen1 + 3] = '\0';
			secStr = new char[newLen1 + 1 + 3];
			secStr[newLen1 + 3] = '\0';
			for (int i = 0; i < newLen1 + 3; i++) {
				addStr[i] = '0';
				secStr[i] = '0';
			}
			for (int i = newLen2, j = newLen1 + 3; i >= 0; i--, j--) {
				if (st2[i] != '-')
					secStr[j] = st2[i];


			}
			for (int i = 0; i < newLen1; i++) {
				if (st[i] != '-')
					addStr[i + 3] = st[i];
			}
		}
		else {
			addStr = new char[newLen2 + 1 + 3];
			addStr[newLen2 + 3] = '\0';
			secStr = new char[newLen2 + 1 + 3];
			secStr[newLen2 + 3] = '\0';
			for (int i = 0; i < newLen2 + 3; i++) {
				addStr[i] = '0';
				secStr[i] = '0';
			}
			for (int i = newLen1, j = newLen2 + 3; i >= 0; i--, j--) {
				if (st[i] != '-')
					addStr[j] = st[i];


			}
			for (int i = 0; i < newLen2; i++) {
				if (st2[i] != '-')
					secStr[i + 3] = st2[i];
			}
		}
	}
	else {
		addStr = new char[newLen1 + 4];
		addStr[newLen2 + 3] = '\0';
		secStr = new char[newLen1 + 1 + 3];
		secStr[newLen2 + 3] = '\0';
		for (int i = 0; i < newLen2 + 3; i++) {
			addStr[i] = '0';
			secStr[i] = '0';
		}
		for (int i = newLen1, j = newLen2 + 3; i >= 0; i--, j--) {
			if (st[i] != '-')
				addStr[j] = st[i];
			if (st2[i] != '-')
				secStr[j] = st2[i];
		}	
	}
	addStr[1] = ',';
	secStr[1] = ',';
	if (st[0] == '-') {
		addStr[0] = '1';
	}
	if (st2[0] == '-') {
		secStr[0] = '1';
	}
	int addSize = strlen(addStr) - 2;
	int secSize = strlen(secStr) - 2;
	int* addArr = toInt(addStr);
	int* secArr = toInt(secStr);
	int* combArr = new int[secSize];
	if (addStr[0] == '1') {
		for (int i = 0; i < addSize; i++) {
			*(addArr + i) *= -1;
		}
	}
	if (secStr[0] == '1') {
		for (int i = 0; i < addSize; i++) {
			
			*(secArr + i) *= -1;
		}
	}
	if (operat == '+') {
		for (int i = secSize - 1; i >= 0; i--) {
			combArr[i] = *(addArr + i) + *(secArr + i);
			
		}
		for (int i = secSize - 1; i >= 0; i--) {
			if (combArr[i] > 17) {
				combArr[i - 1] += 1;
				combArr[i] -= 18;
			}
			if (combArr[i] < -17) {
				combArr[i - 1] -= 1;
				combArr[i] += 18;
			}
			if (combArr[i] < 0) {
				if (combArr[i - 1] > 0) {
					combArr[i] += 18;
					combArr[i - 1] -= 1;
				}
			}
		}
	}
	else if (operat == '-') {
		for (int i = secSize - 1; i >= 0; i--) {
			combArr[i] = *(addArr + i) - *(secArr + i);
		}
		for (int i = secSize - 1; i >= 0; i--) {
			if (combArr[i] > 17) {
				combArr[i - 1] += 1;
				combArr[i] -= 18;
			}
			if (combArr[i] < -17) {
				combArr[i - 1] -= 1;
				combArr[i] += 18;
			}
			if (combArr[i] < 0) {
				if (combArr[i - 1] > 0) {
					combArr[i] += 18;
					combArr[i - 1] -= 1;
				}
			}
		}
	}
	char* finalNumber = new char[strlen(addStr) + 1];
	finalNumber[strlen(addStr)] = '\0';
	for (int i = 0; i < addSize; i++) {
		if (combArr[i] < 0) {
			finalNumber[0] = '1';
		}
	}
	for (int i = 0; i < strlen(addStr); i++) {
		finalNumber[i] = '0';
		if (combArr[i] < 0) {
			
			combArr[i] = abs(combArr[i]);
		}
	}

	finalNumber[1] = ',';
	for (int i = strlen(addStr), j =i-2; i > 1; i--,j--) {
		if (combArr[j] >= 0 && combArr[j] <= 9) {
			finalNumber[i] = combArr[j] + '0';
		}

		else if (combArr[j] == 10) {
			finalNumber[i] = 'A';
		}
		else if (combArr[j] == 11) {
			finalNumber[i] = 'B';
		}
		else if (combArr[j] == 12) {
			finalNumber[i] = 'C';
		}
		else if (combArr[j] == 13) {
			finalNumber[i] = 'D';
		}
		else if (combArr[j] == 14) {
			finalNumber[i] = 'E';
		}
		else if (combArr[j] == 15) {
			finalNumber[i] = 'F';
		}
		else if (combArr[j] == 16) {
			finalNumber[i] = 'G';
		}
		else if (combArr[j] == 17) {
			finalNumber[i] = 'H';
		}
	}

	/*
	for (int i = 0; i < secSize; i++) {
		cout << combArr[i] << ' ';
	}
	*/
	cout << endl;
	puts(addStr);
	cout << operat << endl;
	puts(secStr);
	puts(finalNumber);
	if (finalNumber[0] == '1') {
		cout << '-';
	}
	int notz = 2;
	for (int i = 2; finalNumber[i] != '0'; i++) {
		notz = i;
		if (i == strlen(addStr) - 1) {
			cout << '0';
			return;
		}
	}
	for (int i = notz + 1; i < strlen(addStr); i++) {
		cout << finalNumber[i];
	}
	cout << endl;
}
int main() {
	//assignment1();
	//assignment2();
	//assignment3(); 
	assignment4();
	system("pause");
	return 0;
}