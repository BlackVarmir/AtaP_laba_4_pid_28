#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <locale>

using namespace std;

void Task1() {
    int n, m;
    cout << "Enter the size of the first array (n): ";
	cin >> n;
	cout << "Enter the size of the second array (m): ";
	cin >> m;

	double* a = new double[n];
	double* b = new double[m];

	cout << "Enter the elements of the first array:\n";
	int countA = 0, countB = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (((int)a[i]) % 3 != 0) countA++;
	}

	cout << "Enter the elements of the second array:\n";
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		if (((int)b[i]) % 3 != 0) countB++;
	}

	cout << "An array with more elements that are not a multiple of three: ";
	if (countA > countB) {
		for (int i = 0; i < n; i++) cout << a[i] << " ";
	}
	else {
		for (int i = 0; i < m; i++) cout << b[i] << " ";
	}
	cout << endl;

	delete[] a;
	delete[] b;
}

void filterEvenOnOddIndexes(double* a, int n, double*& b, int& m) {
	m = 0;
	for (int i = 0; i < n; i++) {
		if (((int)a[i]) % 2 == 0) m++;
	}

	b = new double[m];
	int index = 0;
	for (int i = 0; i < n; i += 2) {
		if (((int)a[i]) % 2 == 0) {
			b[index++] = a[i];
		}
	}
}

void Task2() {
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	double* a = new double[n];

	cout << "Enter the items:\n";
	for (int i = 0; i < n; i++) cin >> a[i];

	double* b = nullptr;
	int m = 0;
	filterEvenOnOddIndexes(a, n, b, m);

	cout << "Filtered array: ";
	for (int i = 0; i < m; i++) cout << b[i] << " ";
	cout << endl;

	delete[] a;
	delete[] b;
}

void Task3() {
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	double* a = new double[n];
	cout << "Enter the items:\n";
	for (int i = 0; i < n; i++) cin >> a[i];

	int m = 0;
	for (int i = 0; i < n; i++) {
		if (((int)a[i]) % 2 == 0) m++;
	}

	double* b = new double[m];
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (((int)a[i]) % 2 == 0) {
			b[index++] = a[i];
		}
	}

	sort(b, b + m);

	cout << "Sorted filtered array: ";
	for (int i = 0; i < m; i++) cout << b[i] << " ";
	cout << endl;

	delete[] a;
	delete[] b;
}

int findMin(int* a, int size) {
	int minVal = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] < minVal) minVal = a[i];
	}
	return minVal;
}

int findMax(int* a, int size) {
	int maxVal = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] > maxVal) maxVal = a[i];
	}
	return maxVal;
}	

void Task4() {
	int n; 
	cout << "Enter the size of the array: ";
	cin >> n;
	int* a = new int[n];
	srand(time(nullptr));

	for (int i = 0; i < n; i++) {
		a[i] = rand() % 6 - 2;
	}

	cout << "The generated array: ";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;

	int* b = new int[n * 2];
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0 && i > 0) {
			b[index++] = findMin(a, i) + findMax(a, i);
		}
		b[index++] = a[i];
	}

	cout << "Modified array: ";
	for (int i = 0; i < index; i++) cout << b[i] << " ";
	cout << endl;

	delete[] a;
	delete[] b;
}

int main()
{
	//setlocale(LC_CTYPE, "ukr");

	//SetConsoleOutputCP(1251);
	//SetConsoleCP(1251);
	while (true) {
		cout << "\nMenu:\n";
		cout << "1. Task 1\n";
		cout << "2. Task 2\n";
		cout << "3. Task 3\n";
		cout << "4. Task 4\n";
		cout << "0. Exit\n";
		cout << "Select the option: ";

		int choice;
		cin >> choice;

		switch (choice) {
		case 1: Task1(); break;
		case 2: Task2(); break;
		case 3: Task3(); break;
		case 4: Task4(); break;
		case 0: return 0;
		default: cout << "Wrong option! Please try again." << endl;
		}
	}
    
}

