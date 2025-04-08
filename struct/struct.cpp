/*	Программа: Сортировка структур.
	Версия программы: 0.2
	Автор: Андрей Хусаинов.
	Дата разработки: 09.02.2023
Задание:
Вариант 19
1.)
Описать структуру с именем PRICE, содержащую следующие поля:
- название товара;
- название магазина, в котором продается товар;
- стоимость товара в рублях.
2.)
Написать программу, выполняющую следующие действия:
- ввод с клавиатуры данных в массив, состоящий из n элементов типа
PRICE, записи должны быть размещены в алфавитном порядке по названиям
магазинов;
- вывод на дисплей информации о товарах, продающихся в магазине,
название которого введено с клавиатуры;
- если такого магазина нет, выдать на дисплей соответствующее сообщение.*/

#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

const int k = 17;

struct PRICE {
	char cName[k]; // название товара
	char cShop[k]; // название магазина
	char cPrice[k]; // цена товара
};

int main() {
	// ставит ввод и вывод на русский
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//-------------------
	int j = 1, // j - переменная для выхода из массива while
		l; // l - переменная для работы case menu
	unsigned i, n; // i - переменная для работы массивов, n - количество структур PRICE
	char cSortShop[k]; // переменная, по которой будет искаться магазин
	bool bSearch; // переменная, которая хранит информацию о том найден ли магазин

	cout << "Введите количество структур PRICE: ";
	cin >> n;
	while (n > 10) {
		cin.clear();
		cin.ignore();
		cout << "Введите количество структур PRICE(не больше 10). Попробуйте ещё: ";
		cin >> n;
	}
	cin.ignore();
	system("cls");

	PRICE* price = new PRICE[n];

	//Вводим данные структур
	for (i = 0; i < n; i++) {
		cout << "Введите название магазина №" << i + 1 << ": ";
		cin.getline(price[i].cName, k);
		cout << "Название товара этого магазина: ";
		cin.getline(price[i].cShop, k);
		cout << "Введите цену за товар: ";
		cin.getline(price[i].cPrice, k);
		cout << endl;
	}

	cout << endl;

	cout << "[ЭХО-КОНТРОЛЬ] Вывод введеных данных:" << endl << endl;
	cout << setw(17) << "Название магазина\t" << setw(17) << "Название товара\t" << setw(17) << "Цена товара" << endl;
	for (i = 0; i < n; i++) {
		cout.width(25); cout.unsetf(ios::right); cout.setf(ios::left);
		cout << price[i].cName;
		cout.width(30);
		cout << price[i].cShop;
		cout.unsetf(ios::left); cout.setf(ios::right);
		cout.width(10);
		cout << price[i].cPrice;
		cout << endl;
	}

	cout << endl;

	PRICE temp; // буферная переменная для сортировки
	// сортировка по алфавиту
	while (j == 1) {
		j = 0;
		for (i = 0; i < n - 1; i++) {
			if (strcmp(price[i].cName, price[i + 1].cName) > 0) {
				temp = price[i];
				price[i] = price[i + 1];
				price[i + 1] = temp;
				j = 1;
			}
		}
	}
	cout << "Вывод отсортированных данных:" << endl << endl;
	cout << setw(17) << "Название магазина\t" << setw(17) << "Название товара\t" << setw(17) << "Цена товара" << endl;
	for (i = 0; i < n; i++) {
		cout.width(25); cout.unsetf(ios::right); cout.setf(ios::left);
		cout << price[i].cName;
		cout.width(30);
		cout << price[i].cShop;
		cout.unsetf(ios::left); cout.setf(ios::right);
		cout.width(10);
		cout << price[i].cPrice;
		cout << endl;
	}

	cout << endl;
	cin.ignore();

	do {
		cout << endl;
		cout << "Меню: " << endl;
		cout << "1. Вывод списка магазинов." << endl;
		cout << "2. Вывод на дисплей информации о товарах, продающихся в магазине." << endl;
		cout << "3. Выход из программы." << endl;
		cout << "Выберите пункт меню: ";
		cin >> l;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Введеное вами данные не явлюятся целочисленным числом. Попробуйте ещё: ";
			cin >> l;
		}
		cin.ignore();
		switch (l) {
		case 1: {
			system("cls");
			cout << "Вывод отсортированных данных:" << endl << endl;
			cout << setw(17) << "Название магазина\t" << setw(17) << "Название товара\t" << setw(17) << "Цена товара" << endl;
			for (i = 0; i < n; i++) {
				cout.width(25); cout.unsetf(ios::right); cout.setf(ios::left);
				cout << price[i].cName;
				cout.width(30);
				cout << price[i].cShop;
				cout.unsetf(ios::left); cout.setf(ios::right);
				cout.width(10);
				cout << price[i].cPrice;
				cout << endl;
			}

			cout << endl;
			break;
		}
		case 2: {
			system("cls");
			bSearch = false;
			cout << endl;
			cout << "Введите название магазина по которому нужно вывести информацию: ";
			cin.getline(cSortShop, k);
			cout << endl;

			cout << "Вывод данных по названию магазина:" << endl;
			for (i = 0; i < n; i++) {
				if (strcmp(price[i].cName, cSortShop) == 0) {
					printf("Магазин: %s, товар: %s, стоимость: %s", price[i].cName, price[i].cShop, price[i].cPrice);
					cout << endl;
					bSearch = true;
				}
			}

			if (bSearch == false)
				cout << "Магазин с таким названием отсуствует. " << endl;

			cout << endl;
			break;
		}
		case 3: {
			cout << endl;
			delete[]price; // очистка памяти
			cout << "Память очищена! Выходим из программы" << endl;
		}
		}
	} while (l != 3);
}