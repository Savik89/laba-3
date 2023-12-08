#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void fillZero(int* p, int &n)
{
	int* end = p + n*n;
	for (int* i = p; i < end; i++)
	{
		*i = 0;
		if ((*i - *p + 1) % n == 0)
			cout << '\n';
	}
}
// вывод без задержки
void showMatrix(int* p, int& n) {
	int* end = p + n * n;
	for (int* i = p; i < end; i++) {
		cout << *i << "\t";
		if ((i - p + 1) % n == 0)
			cout << '\n';
	}
}
// вывод с задержкой
void printMatrix(int *p, int &n) {
	system("cls");
	int* end = p + n * n;
	for (int* i = p; i < end; i++) {
		cout << *i << "\t";
		if ((i - p + 1) % n == 0)
			cout << '\n';
	}
	Sleep(400);
}
void createMatrix(int* p, int &n) {
	int* end = p + n * n;
	for (int* i = p; i < end; ++i) {
		*i = rand() % (n * n - 1) + 1;
	}
}
void createMatrixA(int *p, int &n) {
	for (int i = 0; i < n / 2; i++){
		for (int j = i; j < n - i; j++){
			*(p + j + n * i) = rand() % (n * n - 1) + 1;
			printMatrix(p, n);
		}
		for (int j = i + 1; j < n - i; j++){
			*(p + n - 1 - i + n * j) = rand() % (n * n - 1) + 1;
			printMatrix(p, n);
		}
		for (int j = n - i - 1; j > i; j--){
			*(p + (j - 1) + (n) * (n - i - 1)) = rand() % (n * n - 1) + 1;
			printMatrix(p, n);
		}
		for (int j = n - i - 2; j >= 1 + i; j--){
			*(p + i + n * j) = rand() % (n * n - 1) + 1;
			printMatrix(p, n);
		}
	}

	cout << "\n\nНажмите любую кнопку для возвращения в меню";
	_getch();
	system("cls");
}
void createMatrixB(int* p, int &n) {
	for (int i = 0; i < n; i++){
		if (i % 2 == 0){
			for (int j = 0; j < n; j++){
				*(p + i + n * j) = rand() % (n * n - 1) + 1;
				printMatrix(p, n);
			}
		}
		else{
			for (int j = n - 1; j >= 0; j--){
				*(p + i + n * j) = rand() % (n * n - 1) + 1;
				printMatrix(p, n);
			}
		}
	}
	cout << "\n\nНажмите любую кнопку для возвращения в меню";
	_getch();
	system("cls");
}
void upper(int* p, int &n) {
	for (int i = 0; i < n / 2; ++i) {
		for (int* j = p + i * n; j < p + n / 2 + i * n; j++) {
			swap(*j, *(j + n / 2));
		}
	}
}
void lower(int* p, int& n) {
	for (int i = 0; i < n / 2; ++i) {
		for (int* j = p + n*n/2 + n*i; j < p + n * n / 2 + n * i + n/2; j++) {
			swap(*j, *(j + n / 2));
		}
	}
}
void left(int* p, int& n) {
	for (int i = 0; i < n / 2; ++i) {
		for (int* j = p + i; j < p + i + n*n/2; j+=n) {
			swap(*j, *(j + n*n/2));
		}
	}
}
void right(int* p, int& n) {
	for (int i = 0; i < n / 2; ++i) {
		for (int* j = p + i + n/2; j < p + i + n * n / 2 + n/2; j += n) {
			swap(*j, *(j + n * n / 2));
		}
	}
}
void circle(int* p, int& n) {
	left(p, n);
	lower(p, n);
	right(p, n);
}
void quickSortMatrix(int* p, int left, int right) {
	int i = left, j = right;

	int pivot = *(p + (left + right) / 2);
	while (i <= j) {
		while (*(p+i) < pivot)
			i++;
		while (*(p+j) > pivot)
			j--;
		if (i <= j) {
			swap(*(p+i), *(p+j));
			i++;
			j--;
		}
	}
	if (left < j)
		quickSortMatrix(p, left, j);
	if (i < right)
		quickSortMatrix(p, i, right);
}
void menu(int *p, int *p2, int n) {
	setlocale(0, "");
	int choice;
	cout << "Что будем делать? \n"
			<< "1 - Создать матрицу\n"
			<< "2 - Переставить блоки в матрице\n"
			<< "3 - Сортировать матрицу\n"
			<< "4 - Математические операции с матрицей\n"
			<< "5 - Сложение матриц (Idz №1)\n"
			<< "6 - Выход\n";
	cin >> choice;
	switch (choice) {
	case 1:
		fillZero(p, n);
		char a;
		system("cls");
		cout << "Каким способом будет заполняться матрица? a/b\n";
		cin >> a;
		switch (a) {
		case 'a':
			createMatrixA(p, n);
			break;
		case 'b':
			createMatrixB(p, n);
			break;
		}
		cout << "\n\nНажмите любую кнопку для возвращения в меню";
		_getch();
		system("cls");
		menu(p, p2, n);
		break;
	case 2:
		fillZero(p, n);
		createMatrix(p, n);
		int b;
		system("cls");
		cout << "Каким образом будут меняться блоки в матрице?\n1) по кругу\n2) по диагонали\n3) по вертикали\n4) по горизонтали" << endl;
		cin >> b;
		system("cls");

		showMatrix(p, n);
		switch (b) {
		case 1:
			circle(p, n);
			cout << endl << endl;
			showMatrix(p, n);
			cout << "\n\nНажмите любую кнопку для возвращения в меню";
			_getch();
			system("cls");
			menu(p, p2, n);
			break;
		case 2:
			circle(p, n);
			circle(p, n);
			cout << endl << endl;
			showMatrix(p, n);
			cout << "\n\nНажмите любую кнопку для возвращения в меню";
			_getch();
			system("cls");
			menu(p, p2, n);
			break;
		case 3:
			left(p, n);
			right(p, n);
			cout << endl << endl;
			showMatrix(p, n);
			cout << "\n\nНажмите любую кнопку для возвращения в меню";
			_getch();
			system("cls");
			menu(p, p2, n);
			break;
		case 4:
			upper(p, n);
			lower(p, n);
			cout << endl << endl;
			showMatrix(p, n);
			cout << "\n\nНажмите любую кнопку для возвращения в меню";
			_getch();
			system("cls");
			menu(p, p2, n);
			break;
		default:
			cout << "\nТакого варианта нет!\n";
			exit(0);
		}
		break;
	case 3:
		fillZero(p, n);
		createMatrix(p, n);
		system("cls");
		cout << "Неотсортированная матрица: \n";
		showMatrix(p, n);
		cout << "\nОтсортированная матрица:\n";
		quickSortMatrix(p, 0, n * n - 1);
		showMatrix(p, n);
		cout << "\n\nНажмите любую кнопку для возвращения в меню";
		_getch();
		system("cls");
		menu(p, p2, n);
		break;
	case 4:
		system("cls");
		int c;
		int ratio;
		createMatrix(p, n);
		cout << "Матрица до преобразований: \n";
		showMatrix(p, n);
		cout << "\nЧто будем делать с каждым элементом матрицы?\n1) уменьшить на число\n2) увеличить на число\n3) умножить на число\n4) поделить на число\n";
		cin >> c;
		cout << "\nНа какое число?\n";
		cin >> ratio;
		system("cls");
		cout << "Матрица до преобразований: \n";
		showMatrix(p, n);
		switch (c) {
		case 1:
			for (int* i = p; i < p + n * n; ++i)
				*i -= ratio;
			break;
		case 2:
			for (int* i = p; i < p + n * n; ++i)
				*i += ratio;
		case 3:
			for (int* i = p; i < p + n * n; ++i)
				*i *= ratio;
		case 4:
			if (ratio != 0) {
				for (int* i = p; i < p + n * n; ++i)
					*i /= ratio;
			}
			else {
				cout << "На ноль делить нельзя!!!";
				break;
			}
		}
		cout << "Матрица после преобразований: \n";
		showMatrix(p, n);
		cout << "\n\nНажмите любую кнопку для возвращения в меню";
		_getch();
		system("cls");
		menu(p, p2, n);
		break;
	case 5:
		createMatrix(p, n);
		createMatrix(p2, n);
		system("cls");
		cout << "Первая матрица:\n";
		showMatrix(p, n);
		cout << "\nВторая матрица:\n";
		showMatrix(p2, n);
		cout << "\nСложение матриц:\n";
		int* elem;
		elem = p2;
		for (int* i = p; i < p + n * n; ++i) {
			cout << *i << " + " << *elem << "\t\t";
			*elem += *i;
			if ((i - p + 1) % n == 0)
				cout << '\n';
			++elem;
		}
		cout << "\nИтоговая матрица:\n";
		showMatrix(p2, n);
		cout << "\n\nНажмите любую кнопку для возвращения в меню";
		_getch();
		system("cls");
		menu(p, p2, n);
		break;
	case 6:
		exit(1);
		break;
	default:
		cout << "Ошибка! Попробуйте снова\n";
		_getch();
		system("cls");
		menu(p, p2, n);
		break;
	}
}
int main()
{
	setlocale(0, "");
	int a;
	while (true){
		cout << "Какой будет размер матрицы, 6/8/10 ?" << '\n';
		cin >> a;
		int* p = 0, *p2 = 0;
		int n;
		cout << endl;
		switch (a)
		{
		case 6:
			int a1[6][6], idz1[6][6];
			p = *a1;
			p2 = *idz1;
			n = 6;
			menu(p, p2, n);
			break;
		case 8:
			int a2[8][8], idz2[8][8];
			p = *a2;
			p2 = *idz2;
			n = 8;
			menu(p, p2, n);
			break;
		case 10:
			int a3[10][10], idz3[10][10];
			p = *a3;
			p2 = *idz3;
			n = 10;
			menu(p, p2, n);
			break;
		default:
			cout << "Неверный размер матрицы! Попробуйте снова.\n\n";
			main();
			break;
		}
	}
}