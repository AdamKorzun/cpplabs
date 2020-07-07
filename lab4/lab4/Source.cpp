#include <iostream>
#include <random>
#include <time.h>

using namespace std;
int assignment1() {
	const int k=5;
	int a[k], inversions = 0;
	for (int i = 0; i < k; i++) {
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	for (int i = 0; i < k; i++) {
		for (int j = i; j < k; j++) {
			if (a[i] > a[j]) {
				inversions++;
			}
		}
	}
	cout << inversions << endl;

	return 0;
}

int assignment2() {

	const int N=4, M=3;
	int a[N][M], mina;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = rand() % 10;
			cout << a[i][j] << ' ';
		}
		cout << endl;

	}
	cout << endl;
	for (int i = 0; i < M; i++) {
		mina = a[0][i];
		for (int j = 0; j < N; j++) {
			
			if (a[j][i] < mina) {
				mina = a[j][i];
			}
		}
		cout << "Min " << i + 1 << "=" << mina << endl;
	}
	return 0;
}
int assignment3() {
	int size;
	cout << "size=";
	cin >> size;
	float** a = new float*[size];
	float** ar = new float*[size];
	for (int i = 0; i < size; i++) {
		a[i] = new float[size];
		ar[i] = new float[size];
	}

	for (int i = 0;i < size;i++) {
		for (int j = 0; j < size;j++) {
			a[i][j] = rand() % 10;
			cout << a[i][j] << ' ';
			ar[i][j] = 0;
		}
		cout << endl;
	}

	cout << endl;
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (a[i][j] > a[i][i]) {
				ar[i][j] = 1;
			}
			else {
				ar[i][j] = 0;
			}
			cout << ar[i][j] << ' ';
		}
		cout << endl;
	}

	
	return 0;
}

int additionalAssignment1() {
	int size;
	float newEl;
	float counter;
	cout << "size=";
	cin >> size;
	float** a = new float* [size];
	float** ar = new float* [size];
	
	for (int i = 0; i < size; i++) {
		a[i] = new float[size];
		ar[i] = new float[size];
	}

	for (int i = 0;i < size;i++) {
		for (int j = 0; j < size;j++) {
			a[i][j] = rand() % 10;
			cout << a[i][j] << ' ';
			ar[i][j] = 0;
		}
		cout << endl;
	}

	cout << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size;j++) {
			newEl = 0;
			counter = 0;
			for (int k = i - 1; k <= i + 1; k++) {
				for (int g = j - 1; g <= j + 1; g++) {
					if (k < 0 || k >= size || g >= size || g < 0  || (k == i && g == j)) {
						
						continue;
					}
					
					newEl += a[k][g];
					counter++;
				}
			}
			newEl = newEl / counter;
			ar[i][j] = newEl;
			cout << int(ar[i][j]) << ' ';

		}
		cout << endl;
	}

	return 0;
}
int additionalAssignment2_1() {
	int col;
	int rows;
	cout << "Rows: " ;
	cin >> rows;
	cout << "Columns: ";
	cin >> col;
	int* sna = new int[rows];
	
	for (int i = 0; i < rows;i++) {
		sna[i] = 0;
	}
	int** a = new int* [rows];
	int** ar = new int* [rows];
	for (int i = 0; i < rows; i++) {
		a[i] = new int[col];
		ar[i] = new int[col];
	}

	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < col; j++) {
			a[i][j] = rand() % 10;
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	
	int counter;
	for (int i = 0; i < rows; i++) {
		counter = 0;
		for (int j = 0; j < col; j++) {
			counter = 0;
			ar[i][j] = a[i][j];
			for (int k = 0; k < col; k++) {
				if (a[i][k] == a[i][j] && k !=j) {
					ar[i][j] = a[i][j];
					
					counter++;
					
				}
				else if(a[i][k] != a[i][j] && counter == 0){
					ar[i][j] = -1;
				}
			}
		}
	}
	cout << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < col; j++) {
			cout << ar[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < rows;i++) {
		for (int j = 0; j < col;j++) {
			if (ar[i][j] != -1) {
				sna[i] += 1;
			}
		} 
	}
	int notzero = 0;
	
	for (int i = 0; i < rows;i++) {
		cout << sna[i] << ' ';
		if (sna[i] != 0) {
			notzero++;
		}
	}
	cout << endl << endl;
	int ind=0;
	int f = 0;
	int** sortedArray = new int* [notzero + 1];
	for (int i = 0; i < rows;i++) {
		f = 0;
		if (sna[i] != 0) {
			sortedArray[ind] = new int[sna[i]];
			for (int k = 0; k < col;k++) {
				if (ar[i][k] != -1) {
					sortedArray[ind][f] = ar[i][k];
					cout << sortedArray[ind][f] << ' ';
					f++;
				}
			}
			cout << endl;
			ind++;
		}
	}


	
	return 0;
}
int additionalAssignment2_2() {
	int size;
	cout << "size(odds only)=";
	cin >> size;
	float** a = new float* [size];

	for (int i = 0; i < size; i++) {
		a[i] = new float[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] = 0;
		}
	}


	int midpoint = round(double(size) / 2.);
	a[0][size / 2] = 1;
	int i = -1, j = midpoint;
	int step = 0;
	for (int k = 2; k <= size * size; k++) {
		
		if (i < 0) {
			if (a[size - 1][j] != 0) {
				i += 2;
				j -= 1;
				a[i][j] = k;
			}
			else {
				i = size - 1;
				
				a[i][j] = k;
			}
			
			
		}
		else if (j >= size) {
			
			j = 0;
			
			a[i][j] = k;
		}
		else if (a[i][j] != 0) {
			i += 2;
			j -= 1;
			a[i][j] = k;
		}
		else {
			a[i][j] = k;
		}

		i--;
		j++;
		/*
		cout << "Step: " << step << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << a[i][j] << ' ';
			}
			cout << endl;
		}
		step++;
		*/
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	

	return 0;
}

int additionalAssignment2_3() {
	int size;
	cout << "size=";
	cin >> size;
	int** a = new int* [size];
	for (int i = 0; i < size; i++) {
		a[i] = new int[size];
	}

	int i = 0, j, k = 0, p = 1;

	while (i < size * size)
	{
		k++;
		for (j = k - 1;j < size - k + 1;j++) {
			a[k - 1][j] = p++;
			i++;
		}  
		for (j = k;j < size - k + 1;j++) {
			a[j][size - k] = p++;
			i++;
		} 
		for (j = size - k - 1;j >= k - 1;j--) {
			a[size - k][j] = p++;
			i++;
		}   
		for (j = size - k - 1;j >= k;j--) {
			a[j][k - 1] = p++;
			i++;
		}   
	}

	for (int q = 0; q < size; q++) {
		for (int z = 0; z < size; z++) {
			cout << a[q][z] << ' ';
		}
		cout << endl;
	}

	return 0;

}
int additionalAssignment2_4() {
	int size;
	cout << "size=";
	cin >> size;
	int** a = new int* [size];
	int** ar = new int* [size];
	int sr_size = 0;
	for (int i = size; i > 0; i--) {
		sr_size += i;
	}
	
	int* sr = new int [sr_size];
	

	for (int i = 0; i < size; i++) {
		a[i] = new int[size];
		ar[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] = rand() % 10;
			ar[i][j] = a[i][j];
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	int s = size - 1;
	int counter = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= s; j++) {
			sr[counter] = a[i][j];
			counter++;
			cout << a[i][j] << ' ';

		}
		cout << endl;
		s -= 1;
	}
	cout << endl;
	sort(sr, sr + sr_size);
	/*
	for (int i = 0; i < sr_size; i++) {
		cout << sr[i] << ' ';
	}
	*/
	counter = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			ar[i][j] = sr[counter];
			counter++;
		}
		
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << ar[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
int additionalAssignment2_5() {
	int size;
	cout << "size=";
	cin >> size;
	float** a = new float* [size];
	float** ar = new float* [size];
	for (int i = 0; i < size; i++) {
		a[i] = new float[size];
		ar[i] = new float[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] = rand() % 10;
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			ar[i][j] = a[i][j];
			for (int k = 0; k <= i; k++) {
				for (int g = 0; g <= j; g++) {
					if (a[k][g] > ar[i][j]) {
						ar[i][j] = a[k][g];
					}
				}
			}

		}
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << ar[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}
int main() {
	srand(time(NULL));
	//assignment1();
	//assignment2();
	//assignment3();
	//additionalAssignment1();
	//additionalAssignment2_1(); 
	//additionalAssignment2_2(); 
	//additionalAssignment2_3();
	//additionalAssignment2_4();
	//additionalAssignment2_5();
	return 0;
}