#include "Windows.h"
#include <iostream>

using namespace std;

void f1(double* mas, double size) {
	int max = 1, n = -1;
	for (int i = 0; i < size; i++) {
		int count = 0;
		for (int j = i; j < size; j++) {
			if (mas[i] == mas[j])
				count++;
		}
		if (max < count) {
			max = count;
			n = i;
		}
	}
	if (n > -1)
		cout << "Самый повторяющийся элемент " << mas[n];
	else
		cout << "Повторяющихся элементов нет";
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double X = 0;

	cout << "Введите длину массива ";
	cin >> X;

	double* mas = new double[X];

	cout << "Введите элементы массива " << endl;

	for (int i = 0; i < X; i++) {
		cin >> mas[i];
	}

	f1(mas, X);

	cout << endl;

	delete[] mas;
	system("pause");
	return 0;
}