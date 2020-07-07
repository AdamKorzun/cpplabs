#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;


struct Flight {
	int number;
	char planeName[20];
	char destination[100];
	char depTime[10];
};
bool stCompare(char comp[], char *structst) {
	//int compSize = sizeof(comp) / sizeof(char);
	for (int i = 0; i < strlen(comp); i++) {
		cout << int(comp[i]);
	}

	return false;
}
void printStruct(Flight struc[],int i) {
	cout << "Structure number: " << i << endl;
	cout << "Flight number: ";
	cout << (*(struc + i)).number << endl;
	cout << "Plane name: ";
	cout << (*(struc + i)).planeName << endl;
	cout << "Flight destionation: ";
	cout << (*(struc + i)).destination << endl;
	cout << "Departure time: ";
	cout << (*(struc + i)).depTime << endl;
	cout << endl;

}
void  quickSort(int* arr,int left,int right) {
	int pivot;
	int l_hold = left; 
	int r_hold = right; 
	pivot = arr[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((arr[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			arr[left] = arr[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо
		}
		while ((arr[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			arr[right] = arr[left]; // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо
		}
	}
	arr[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		quickSort(arr, left, pivot - 1);
	if (right > pivot)
		quickSort(arr, pivot + 1, right);
}


void assignment1() {	
	int n;
	int numberOfFlights = 0;
	int newLen = 0;
	int searchTerm = 0;
	int searchNumber;
	int option;
	int toDelete = 0;
	int changeInt = 0;
	char searchPhrase[100];
	char changedParam[100];
	int* numberArr = new int[1];
	Flight* struc;
	struc = new Flight[0];
	Flight* struc2;
	struc2 = new Flight[0];

	while (true) {
		cout << "1 - Create structures" << endl;
		cout << "2 - View structures" << endl;
		cout << "3 - Add structures" << endl;
		cout << "4 - Find structures" << endl;
		cout << "5 - Remove/edit structures" << endl;
		cout << "6 - Sort structures" << endl;
		cout << "7 - Exit" << endl;
		cout << "Option: ";
		cin >> n;

		switch (n) {
		case 1:
			cout << "Number of flights: ";
			cin >> numberOfFlights;
			gets_s((*(struc + 0)).planeName);	
			struc = new Flight[numberOfFlights];
			for (int i = 0; i < numberOfFlights; i++) {
				cout << "Structure number: " << i << endl;
			
				cout << "Flight number: ";
				cin >> (*(struc + i)).number;
				gets_s((*(struc)).planeName);
				cout << "Plane name: ";
				gets_s((*(struc + i)).planeName);
				cout << "Flight destionation: ";
				gets_s((*(struc + i)).destination);
				cout << "Plane departure time: ";
				gets_s((*(struc + i)).depTime);
			}break;
		case 2:
			//cout << numberOfFlights  << endl;
			//cout << toDelete << endl;
			for (int i = 0; i < numberOfFlights; i++) {
				printStruct(struc, i);
			}
			break;
		case 3:
			struc2 = new Flight[numberOfFlights];
			struc2 = struc;
			
			cout << "How many structures you want to add:  ";
		
			cin >> newLen;
			newLen += numberOfFlights;
			struc = new Flight[newLen];
			gets_s((*(struc + numberOfFlights)).planeName);
			for (int i = 0; i < numberOfFlights; i++) {
				(*(struc + i)).number = (*(struc2 + i)).number;
				strcpy_s((*(struc + i)).planeName,20, (*(struc2 + i)).planeName);
				strcpy_s((*(struc + i)).destination,100, (*(struc2 + i)).destination);
				strcpy_s((*(struc + i)).depTime,10, (*(struc2 + i)).depTime);
			
			}
			for (int i = numberOfFlights; i < newLen; i++) {
				cout << "Structure number: " << i << endl;
				cout << "Flight number: " << (*(struc + i)).number << endl;
				cin >> (*(struc + i)).number;
				gets_s((*(struc + i)).planeName);
				cout << "Plane name: ";
				gets_s((*(struc + i)).planeName);
				cout << "Flight destionation: ";
				gets_s((*(struc + i)).destination);
				cout << "Plane departure time: ";
				gets_s((*(struc + i)).depTime);
			}
			numberOfFlights = newLen;
			break;
		case 4:
			cout << "Search by: " << endl;
			cout << "1 - Number" << endl;
			cout << "2 - Name" << endl;
			cout << "3 - Destionation" << endl;
			cout << "4 - Department time" << endl;
			cout << "Search by: ";
			cin >> searchTerm;
			gets_s(searchPhrase);
			switch (searchTerm) {
			case 1:
				cout << "Number: ";
				cin >> searchNumber;
				for (int i = 0; i < numberOfFlights; i++) {
					if ((*(struc + i)).number == searchNumber) {
						printStruct(struc, i);
					}
				}
				break;
			case 2:
				cout << "Search phrase: ";
				gets_s(searchPhrase);
				for (int i = 0; i < numberOfFlights; i++) {
					if (!(strcmp(searchPhrase, (*(struc + i)).planeName))) {
						printStruct(struc, i);	
					}
				}
				break;
			case 3:
				cout << "Search phrase: ";
				gets_s(searchPhrase);
				for (int i = 0; i < numberOfFlights; i++) {
					if (!(strcmp(searchPhrase, (*(struc + i)).destination))) {
						printStruct(struc, i);
					}
				}
				break;
			case 4:
				cout << "Search phrase: ";
				gets_s(searchPhrase);
				for (int i = 0; i < numberOfFlights; i++) {
					if (!(strcmp(searchPhrase, (*(struc + i)).depTime))) {
						printStruct(struc, i);
					}
				}
				break;
			}
			
			break;
		case 5:
			cout << "1 - Delete structure \n";
			cout << "2 - Edit structure\n";
			cout << "Option: ";
			cin >> option;
			gets_s(searchPhrase);
			if (option == 1) {
				cout << "Delete by: " << endl;
				cout << "1 - Number" << endl;
				cout << "2 - Name" << endl;
				cout << "3 - Destionation" << endl;
				cout << "4 - Department time" << endl;
				cout << "Delete by: ";
				cin >> option;
				gets_s(searchPhrase);
				switch (option) {
				case 1:
					cout << "Number: ";
					cin >> searchNumber;
					for (int i = 0; i < numberOfFlights; i++) {
						if (!(*(struc + i)).number == searchNumber) {
							toDelete++;
						}
					}
					break;
				case 2:
					cout << "Search phrase: ";
					gets_s(searchPhrase);
					for (int i = 0; i < numberOfFlights; i++) {
						if (!(strcmp(searchPhrase, (*(struc + i)).planeName))) {
							toDelete++;
						}
					}
					break;
				case 3:
					cout << "Search phrase: ";
					gets_s(searchPhrase);
					for (int i = 0; i < numberOfFlights; i++) {	
						if (!(strcmp(searchPhrase, (*(struc + i)).destination))) {
							toDelete++;
						}
					}
					break;
				case 4:
					cout << "Search phrase: ";
					gets_s(searchPhrase);
					for (int i = 0; i < numberOfFlights; i++) {
						if ((strcmp(searchPhrase, (*(struc + i)).depTime))) {
							toDelete++;
						}
					}
					break;
				}
				if (toDelete != 0) {
					struc2 = new Flight[numberOfFlights];
					
					struc2 = struc;
					struc = new Flight[numberOfFlights - toDelete];
					for (int i = 0, j = 0; i < numberOfFlights; i++) {
						switch (option) {
						case 1:
							if (searchNumber != (*(struc2 + i)).number) {
								struc[j] = struc2[i];
								j+=1;
							}
							break;
						case 2:
							if ((strcmp(searchPhrase, (*(struc2 + i)).planeName))) { 
								struc[j] = struc2[i];
								j+=1;
							}
							break;
						case 3:
							if ((strcmp(searchPhrase, (*(struc2 + i)).destination))) {
								struc[j] = struc2[i];
								j+=1;
							}
							break;
						case 4:
							if ((strcmp(searchPhrase, (*(struc2 + i)).depTime))) {
								struc[j] = struc2[i];
								j+=1;
							}
							break;
						}
						
						
					}
					numberOfFlights -= toDelete;
					toDelete = 0;
				}

		
			}
			else if (option == 2) {
				cout << "Edit by: " << endl;
				cout << "1 - Number" << endl;
				cout << "2 - Name" << endl;
				cout << "3 - Destionation" << endl;
				cout << "4 - Departure time" << endl;
				cout << "Edit by: ";
				cin >> option;
				gets_s(searchPhrase);

				if (option == 1) {
					cout << "Option to change: ";
					cin >> option;
					gets_s(searchPhrase);
					cout << "New option: ";
					cin >> changeInt;
					for (int i = 0; i < numberOfFlights; i++) {
						if (option == (*(struc + i)).number) {
							(*(struc + i)).number = changeInt;
						}
					}
				}
				else if (option > 1 && option < 5){
					cout << "Option to change: ";
					gets_s(searchPhrase);
					cout << "New option: ";
					gets_s(changedParam);
					for (int i = 0; i < numberOfFlights; i++) {
						switch (option) {
						case 2:
							if (!(strcmp(searchPhrase, (*(struc + i)).planeName))) {
								strcpy_s((*(struc + i)).planeName, changedParam);
							}
							break;
						case 3:
							if (!(strcmp(searchPhrase, (*(struc + i)).destination))) {
								strcpy_s((*(struc + i)).destination, changedParam);
							}
							break;
						case 4:
							if (!(strcmp(searchPhrase, (*(struc + i)).depTime))) {
								strcpy_s((*(struc + i)).depTime, changedParam);
							}
							break;
						}

					}
				}

		
			}
			break;
		case 6:
			cout << "Deestination: ";
			gets_s(searchPhrase);
			gets_s(searchPhrase);
			searchNumber = 0;
			for (int i = 0,j=0; i < numberOfFlights; i++) {
				if (!(strcmp(searchPhrase, (*(struc + i)).destination))) {
					printStruct(struc, i);
					searchNumber++;
				}
			}
			if (searchNumber > 0) {
				numberArr = new int[searchNumber];
				for (int i = 0, j = 0; i < numberOfFlights; i++) {
					if (!(strcmp(searchPhrase, (*(struc + i)).destination))) {
						numberArr[j] = (*(struc + i)).number;
						j++;
					}
				}
				quickSort(numberArr, 0, searchNumber - 1);
			}
			for (int i = 0; i < searchNumber; i++) {
				cout << numberArr[i] << endl;
			}
			
			break;
		case 7:
			exit(0);
		default:
			break;
		}
		
		system("pause");
		system("cls");

	}
	
}
int minTime(char time[]) {
	int mins = 0;
	int fPos = 0;
	int ePos = 5;
	for (int i = 0; i < strlen(time);i++) {
		if (time[i] == ':') {
			fPos = i;

		}
		if (int(time[i]) <  '0' && int(time[i]) >'9' && time[i] != ':') {
			ePos = i;
			cout << ePos << endl;
			break;
		}
	}
	for (int i = 0; i < ePos; i++) {
		if (i < fPos) {
			mins += (time[i] - '0') * pow(10, fPos - i - 1) * 60;
		}
		else{
			mins += (time[i] - '0') * pow(10, ePos - i - 1);
		}
	}
	//cout << mins << endl;
	return mins;
}

struct Bus {
	int number;
	char type[100];
	char destination[100];
	char depTime[100];
	char arrTime[100];
};
void writeToF(Bus struc,FILE *fl = fopen("C:\\Users\\admin\\Desktop\\С++\\lab8\\files\\f1.txt", "w"),bool openfile = false) {
	
	if (openfile) {
		fl = fopen("C:\\Users\\admin\\Desktop\\С++\\lab8\\files\\f1.txt", "w");
	}

	fputs("Bus type: ", fl);
	fputs(struc.type, fl);
	fputs("\n", fl);
	fputs("Bus destionation: ", fl);
	fputs(struc.destination, fl);
	fputs("\n", fl);
	fputs("Departure time: ", fl);
	fputs(struc.depTime, fl);
	fputs("\n", fl);
	fputs("Arrival time: ", fl);
	fputs(struc.arrTime, fl);
	fputs("\n ", fl);
	if (openfile) {
		fclose(fl);
	}
	
}
void printStruct2(Bus struc[], int i) {
	cout << "Structure number: " << i << endl;
	cout << "Bus number: ";
	cout << (*(struc + i)).number << endl;
	cout << "Bus type: ";
	cout << (*(struc + i)).type << endl;
	cout << "Bus destionation: ";
	cout << (*(struc + i)).destination << endl;
	cout << "Departure time: ";
	cout << (*(struc + i)).depTime << endl;
	cout << "Arrival time: ";
	cout << (*(struc + i)).arrTime << endl;
	cout << endl;
}
void assignment2() {
	
	int n;
	int toDelete = 0;
	int numberOfStr = 0;
	int number = 0;
	char phrase[100];
	char changePhrase[100];
	int changeNumber = 0;
	Bus* struc;
	struc = new Bus[1];
	Bus* struc2;
	struc2 = new Bus[1];

	while (true) {
		cout << "1 - Create sctuctures \n";
		cout << "2 - Add sctuctures \n";
		cout << "3 - Remove/edit sctuctures \n";
		cout << "4 - View sctuctures \n";
		cout << "5 - Find route \n";
		cout << "6 - Exit \n";
		cout << "Option: ";
		cin >> n;
		switch (n) {
		case 1:
			cout << "How many structures you want: ";
			cin >> numberOfStr;
			struc = new Bus[numberOfStr];
			for (int i = 0; i < numberOfStr; i++) {

				cout << "Bus number: ";
				cin >> (*(struc + i)).number;
				gets_s(phrase);
				cout << "Bus type: ";
				gets_s((*(struc + i)).type);
				cout << "Bus destination: ";
				gets_s((*(struc + i)).destination);
				cout << "Departure time: ";
				gets_s((*(struc + i)).depTime);
				cout << "Arrival time: ";
				gets_s((*(struc + i)).arrTime);
				cout << endl;
			}
			break;
		case 2:
			cout << "How many structues you want to add: ";
			cin >> number;
			struc2 = new Bus[numberOfStr];
			struc2 = struc;
			struc = new Bus[numberOfStr + number];
			for (int i = 0; i < numberOfStr; i++) {
				struc[i] = struc2[i];
			}
			for (int i = numberOfStr; i < numberOfStr + number; i++) {
				cout << "Bus number: ";
				cin >> (*(struc + i)).number;
				gets_s(phrase);
				cout << "Bus type: ";
				gets_s((*(struc + i)).type);
				cout << "Bus destination: ";
				gets_s((*(struc + i)).destination);
				cout << "Departure time: ";
				gets_s((*(struc + i)).depTime);
				cout << "Arrival time: ";
				gets_s((*(struc + i)).arrTime);
				cout << endl;
			}
			numberOfStr += number;
			break;
		case 3:
			cout << "1 - Delete structures \n";
			cout << "2 - Edit structures \n";
			cin >> number;
			gets_s(phrase);
			switch (number) {
			case 1:
				cout << "Delete by: \n";
				cout << "1 - Number\n";
				cout << "2 - Type\n";
				cout << "3 - Destination\n";
				cout << "4 - Departure time\n";
				cout << "5 - Arrival time\n";
				cout << "Delete by: ";
				cin >> number;
				gets_s(phrase);
				switch (number) {
				case 1: 
					cout << "Search number: ";
					cin >> changeNumber;
					for (int i = 0; i < numberOfStr; i++) {
						if ((*(struc2 + i)).number == changeNumber) {
							toDelete++;
						}
					}
					break;
				case 2:
					cout << "Search phrase: ";
					gets_s(phrase);
					for (int i = 0; i < numberOfStr; i++) {
						if (!(strcmp(phrase, (*(struc + i)).type))) {
							toDelete++;
						}
					}
					break;
				case 3:
					cout << "Search phrase: ";
					gets_s(phrase);
					for (int i = 0; i < numberOfStr; i++) {
						if (!(strcmp(phrase, (*(struc + i)).destination))) {
							toDelete++;
						}
					}
					break;
				case 4:
					cout << "Search phrase: ";
					gets_s(phrase);
					for (int i = 0; i < numberOfStr; i++) {
						if (!(strcmp(phrase, (*(struc + i)).depTime))) {
							toDelete++;
						}
					}
					break;
				case 5:
					cout << "Search phrase: ";
					gets_s(phrase);
					for (int i = 0; i < numberOfStr; i++) {
						if (!(strcmp(phrase, (*(struc + i)).arrTime))) {
							toDelete++;
						}
					}
					break;
				}
				if (toDelete > 0) {
					struc2 = new Bus[numberOfStr];
					struc2 = struc;
					struc = new Bus[numberOfStr - toDelete];
					for (int i = 0, j = 0; i < numberOfStr; i++) {
						switch (number) {
						case 1:
							if ((*(struc2 + i)).number != changeNumber) {
								struc[j] = struc2[i];
								j++;
							}
							break;
						case 2:
							if (strcmp((*(struc2 + i)).type, phrase)) {
								struc[j] = struc2[i];
								j++;
							}
							break;
						case 3:
							if (strcmp((*(struc2 + i)).destination, phrase)) {
								struc[j] = struc2[i];
								j++;
							}
							break;
						case 4:
							if (strcmp((*(struc2 + i)).depTime, phrase)) {
								struc[j] = struc2[i];
								j++;
							}
							break;
						case 5:
							if (strcmp((*(struc2 + i)).arrTime, phrase)) {
								struc[j] = struc2[i];
								j++;
							}
							break;
						}



					}
					numberOfStr -= toDelete;
					toDelete = 0;
				}

				break;
			case 2:
				cout << "Edit by: \n";
				cout << "1 - Number\n";
				cout << "2 - Type\n";
				cout << "3 - Destination\n";
				cout << "4 - Department time\n";
				cout << "5 - Arrival time\n";
				cout << "Edit by: ";
				cin >> number;
				gets_s(phrase);
				if (number > 1) {
					cout << "Search phrase: ";
					gets_s(phrase);
					cout << "Change to: ";
					gets_s(changePhrase);
					for (int i = 0; i < numberOfStr; i++) {
						switch (number) {
					
						case 2:
							if (!(strcmp((*(struc + i)).type, phrase))) {
								strcpy_s((*(struc + i)).type, changePhrase);
							}
							break;
						case 3:
							if (!(strcmp((*(struc + i)).destination, phrase))) {
								strcpy_s((*(struc + i)).destination, changePhrase);
							}
							break;
						case 4:
							if (!(strcmp((*(struc + i)).depTime, phrase))) {
								strcpy_s((*(struc + i)).depTime, changePhrase);
							}
							break;
						case 5:
							if (!(strcmp((*(struc + i)).arrTime, phrase))) {
								strcpy_s((*(struc + i)).arrTime, changePhrase);
							}
							break;

						}


					}
				}
				else if (number == 1) {
					cout << "Serach number: ";
					cin >> number;
					cout << "Change to: ";
					cin >> changeNumber;
					for (int i = 0; i < numberOfStr; i++) {
						if ((*(struc + i)).number == number) {
							(*(struc + i)).number = changeNumber;
						}
					}
				}
				break;
			}
			break;
		case 4:
			for (int i = 0; i < numberOfStr; i++) {
				printStruct2(struc, i);
			}
			break;
		case 5:
			cout << "Destionation: ";
			gets_s(phrase);
			gets_s(phrase);
			cout << "Arrival time: ";
			gets_s(changePhrase);
			FILE* fl;
			fl = fopen("C:\\Users\\admin\\Desktop\\С++\\lab8\\files\\f1.txt", "w");
			for (int i = 0; i < numberOfStr; i++) {
				if (!(strcmp((*(struc + i)).destination, phrase))) {
					//cout << int((*(struc + i)).arrTime) << endl;
					if (minTime((*(struc + i)).arrTime) < minTime(changePhrase)) {
						printStruct2(struc, i);
						writeToF(struc[i],fl);
					}
				}
			}
			fclose(fl);
			break;
		case 6:
			exit(0);

		}
		system("pause");
		system("cls");

	}
	
}
int  main() {
	assignment1();
	//assignment2();
	return 0;
}