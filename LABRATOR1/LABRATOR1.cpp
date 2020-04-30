#include <iostream>
#include "Windows.h"
#include <cmath>

using namespace std;

double f1(double x) {
	double v;
	if (x < 0)
		v = sin(x) * sin(x) + cos(x) * cos(x);
	else
		v = sin(x * x);
	return v;
}

double f2(double& n) {
	n = f1(n);
	return n;
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double x, y, b;
	cout << "Введите первое значение ";
	cin >> x;
	cout << "Введите количество ";
	cin >> y;
	cout << "Введите шаг ";
	cin >> b;

	double n = x;
	cout << endl;

	cout << "Работа первой функции " << endl;

	for (int i = 1; i <= y; i++, x += b) {
		cout << "Значение " << x << " результат " << f1(x);
		cout << endl;
	}
	cout << endl;

	cout << "Работа второй функции " << endl;

	for (int i = 1; i <= y; i++, n += b) {
		cout << "Результат " << f2(n);
		cout << endl;
	}

	system("pause");
	return 0;
}