#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <stdio.h>

using namespace std;
const int MAX = 20; int n;
//Объявление структуры
struct Console {
	string name;
	string producer;
	int guarantee;
	double price;
};
//Создание массива структур
Console technics[MAX];
ofstream fout;
ifstream fin;
//Запись в каталог книг по умолчанию
void initConsoles() {
	
	technics[0].name = "PlayStation 5";
	technics[0].producer = "Sony";
	technics[0].guarantee = 24;
	technics[0].price = 60000.59;
	technics[1].name = "PlayStation 4";
	technics[1].producer = "Sony";
	technics[1].guarantee = 12;
	technics[1].price = 25000.69;
	technics[2].name = "PlayStation 4";
	technics[2].producer = "Sony";
	technics[2].guarantee = 6;
	technics[2].price = 20000.59;
	technics[3].name = "PlayStation 3";
	technics[3].producer = "Sony";
	technics[3].guarantee = 9;
	technics[3].price = 15000.49;
	technics[4].name = "PlayStation 2";
	technics[4].producer = "Sony";
	technics[4].guarantee = 2;
	technics[4].price = 4000.59;
	technics[5].name = "XBox Series X";
	technics[5].producer = "Microsoft";
	technics[5].guarantee = 24;
	technics[5].price = 50000.59;
	technics[6].name = "XBox Series S";
	technics[6].producer = "Microsoft";
	technics[6].guarantee = 24;
	technics[6].price = 30000.59;
	technics[7].name = "XBox One X";
	technics[7].producer = "Microsoft";
	technics[7].guarantee = 12;
	technics[7].price = 20000.59;
	technics[8].name = "XBox One S";
	technics[8].producer = "Microsoft";
	technics[8].guarantee = 12;
	technics[8].price = 14000.59;
	technics[9].name = "XBox One";
	technics[9].producer = "Microsoft";
	technics[9].guarantee = 6;
	technics[9].price = 10000.59;
	technics[10].name = "Nintendo Switch";
	technics[10].producer = "Nintendo";
	technics[10].guarantee = 12;
	technics[10].price = 20000.59;
	technics[11].name = "Nintendo Switch Lite";
	technics[11].producer = "Nintendo";
	technics[11].guarantee = 12;
	technics[11].price = 14000.59;
	n = 12;

}
//Вывод техникм на экран
void printConsoles() {
	cout << "--------------------------------------------------------------" << endl;
	cout.width(25);
	cout << "Наименование";
	cout.width(15);
	cout << "Производитель";
	cout.width(10);
	cout << "Гарантия";
	cout.width(13);
	cout << "Цена   |";
	cout << endl;
	cout.width(25);
	cout << "--------------------------------------------------------------|" << endl;
	cout.width(25);
	for (int i = 0; i < n; i++) {
		cout.width(25);
		cout << technics[i].name;
		cout.width(15);
		cout << technics[i].producer;
		cout.width(10);
		cout << technics[i].guarantee;
		printf("   %0.2llf |\n", technics[i].price);
	}
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
}
//Сортировка техники по гарантии
void sortConsoles(int* flag) {
	if (!*flag)
	{
		for (int i = 0; i < n - 1; i++) {
			int j_max = i;
			for (int j = i + 1; j < n; j++) {
				if (technics[j_max].guarantee < technics[j].guarantee) {
					j_max = j;
				}
			}
			Console temp = technics[i];
			technics[i] = technics[j_max];
			technics[j_max] = temp;
		}
	}
	else if (*flag)
	{
		for (int i = 0; i < n - 1; i++) {
			int j_max = i;
			for (int j = i + 1; j < n; j++) {
				if (technics[j_max].guarantee > technics[j].guarantee) {
					j_max = j;
				}
			}
			Console temp = technics[i];
			technics[i] = technics[j_max];
			technics[j_max] = temp;
		}
	}
}
//Сортировка техники по названию
void sortConsolesName(int* flag) {
	if (!*flag)
	{
		for (int i = 0; i < n - 1; i++) {
			int j_max = i;
			for (int j = i + 1; j < n; j++) {
				if (technics[j_max].name < technics[j].name) {
					j_max = j;
				}
			}
			Console temp = technics[i];
			technics[i] = technics[j_max];
			technics[j_max] = temp;
		}
	}
	else if (*flag)
	{
		for (int i = 0; i < n - 1; i++) {
			int j_max = i;
			for (int j = i + 1; j < n; j++) {
				if (technics[j_max].name > technics[j].name) {
					j_max = j;
				}
			}
			Console temp = technics[i];
			technics[i] = technics[j_max];
			technics[j_max] = temp;
		}
	}
}
//Сортировка техники по Производителю
void sortConsolesProd(int* flag) {
	if (!*flag)
	{
		for (int i = 0; i < n - 1; i++) {
			int j_max = i;
			for (int j = i + 1; j < n; j++) {
				if (technics[j_max].producer < technics[j].producer) {
					j_max = j;
				}
			}
			Console temp = technics[i];
			technics[i] = technics[j_max];
			technics[j_max] = temp;
		}
	}
	else if (*flag)
	{
		for (int i = 0; i < n - 1; i++) {
			int j_max = i;
			for (int j = i + 1; j < n; j++) {
				if (technics[j_max].name > technics[j].name) {
					j_max = j;
				}
			}
			Console temp = technics[i];
			technics[i] = technics[j_max];
			technics[j_max] = temp;
		}
	}
}
//Сортировка техники по Цене
void sortConsolesPrice(int* flag) {
	if (!*flag)
	{
		for (int i = 0; i < n - 1; i++) {
			int j_max = i;
			for (int j = i + 1; j < n; j++) {
				if (technics[j_max].price < technics[j].price) {
					j_max = j;
				}
			}
			Console temp = technics[i];
			technics[i] = technics[j_max];
			technics[j_max] = temp;
		}
	}
	else if (*flag)
	{
		for (int i = 0; i < n - 1; i++) {
			int j_max = i;
			for (int j = i + 1; j < n; j++) {
				if (technics[j_max].price > technics[j].price) {
					j_max = j;
				}
			}
			Console temp = technics[i];
			technics[i] = technics[j_max];
			technics[j_max] = temp;
		}
	}
}


//Вывод меню на экран
void printMenu() {
	cout << "1 - Вывод всей техники\n";
	cout << "2 - Сортировка техники по гарантии\n";
	cout << "3 - Сортировка техники по названию\n";
	cout << "4 - Сортировка техники по производителю\n";
	cout << "5 - Сортировка техники по цене\n";
	cout << "6 - Записать данные в файл\n";
	cout << "7 - Считать данные из файла\n";
	cout << "0 - Выход\n";

	cout << "Ваш выбор:\n";
}
//Запись каталога в файл
void writeData() {
	fout.open("Consoles.txt");
	fout << n << endl;
	for (int i = 0; i < n; i++) {
		fout << technics[i].name << endl;
		fout << technics[i].producer << endl;
		fout << technics[i].guarantee << endl;
		fout << technics[i].price << endl;
	}
	fout.close();
}
//Чтение каталога из файла
void readData() {
	fin.open("Consoles.txt");
	fin >> n;
	fin.ignore();
	for (int i = 0; i < n; i++) {
		getline(fin, technics[i].name);
		getline(fin, technics[i].producer);
		fin >> technics[i].guarantee;
		fin.ignore();
		fin >> technics[i].price;
		fin.ignore();
	}
	fin.close();
}
int main() {
	int ptr = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	initConsoles();
	while (true) {
		system("cls");
		printMenu();
		int choice;
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1: printConsoles(); break;
		case 2:
		{
			sortConsoles(&ptr);
			if (ptr == 0) ptr = 1; else ptr = 0;
			break;
		}
		case 3:
		{
			sortConsolesName(&ptr);
			if (ptr == 0) ptr = 1; else ptr = 0;
			break;
		}
		case 4:
		{
			sortConsolesProd(&ptr);
			if (ptr == 0) ptr = 1; else ptr = 0;
			break;
		}
		case 5:
		{
			sortConsolesPrice(&ptr);
			if (ptr == 0) ptr = 1; else ptr = 0;
			break;
		}
		case 6: writeData(); break;
		case 7: readData(); break;
		case 0: exit(0);

		default: cout << "Неверный выбор\n";
		}
		system("pause");
	}
	return 0;
}
