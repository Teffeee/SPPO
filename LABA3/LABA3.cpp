#include "Windows.h"
#include <iostream>

using namespace std;

struct element {
	double value;
	element* pointer;
	element() {
		value = 0;
		pointer = NULL;
	}
};

void f1(int n, element* one) {
	element* p2;
	p2 = one;
	element* p3 = p2;
	element* p4 = NULL;
	int max = 0;
	for (int i = 0; i < n; i++, p2 = p2->pointer) {
		int count = 0;
		for (int j = i; j < n; j++) {
			if (p2->value == p3->value) {
				count++;
				p3 = p3->pointer;
			}
		}
		if (max < count) {
			max = count;
			p4 = p2;
		}
	}
	if (max != 0)
		cout << "Самый повторяющийся элемент " << p4->value << endl;
	else
		cout << "Повторяющихся элементов нет" << endl;
}


int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int X;
	double a;
	element* first = NULL;
	element* p = first;

	//Ввод списка
	cout << "Введите длину списка ";
	cin >> X;
	int i = 0;
	cout << "Введите каждый элемент ";
	while (i < X) {
		cin >> a;
		element* p1 = new element();
		p1->value = a;
		if (first == NULL) {
			first = p1;
			p = p1;
		}
		else {
			p->pointer = p1;
			p = p1;
		}
		i++;
	}

	//Вывод списка
	p = first;
	do {
		cout << p->value << " ";
		p = p->pointer;
	} while (p != NULL);
	cout << endl;

	f1(X, first);

	system("pause");
	return 0;
}