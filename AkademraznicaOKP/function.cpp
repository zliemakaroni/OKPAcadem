#include "stdafx.h"
#include "function.h"
#include <iostream>
#include <ctime>


using namespace std;


int menu()																				// Вывод меню и принятие ответа
{
	int foo;	// переменная для общения
	cout << "1. Вывести массив" << endl;
	cout << "2. Найти кол-во элементов, равное n" << endl;
	cout << "3. Переопределить массив" << endl;
	cout << "Введите любой другой символ для выхода" << endl;
	cout << "Введите команду: ";
	cin >> foo;
	return foo;
}


int* createArray(int size)																// Создание массива
{

	int* arr = new int[size];
	int bot;	// нижняя граница
	int top;	// верхняя граница
	do {																				// проверка на условие
		cout << "Нижняя граница должна быть меньше верхней" << endl;					// нижняя граница меньше чем верхняя
		cout << "Введите нижнюю границу массива: ";
		bot = inputInt();	// принимаем нижнюю границу
		cout << "Введите верхнюю границу массива: ";
		top = inputInt();	// принимаем верхню границу
	} while (bot > top);
	srand(time(0));
	for (int i = 0; i < size; i++)														// наполнение массива случайными числами
	{
		arr[i] = bot + rand() % (top - bot + 1);
	}
	return arr;
}

void printArray(int size, int* arr)														// вывод массива на экран
{																						// в одной строке не более 10 значений
	for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0 && i != 0)
		{
			cout << endl;
		}
		cout << arr[i] << " ";
	}
	cout << endl;
}

int valueOfEqual(int finded, int size, int* arr)													// нахождение количества вхождений числа в массив
{
	int value = 0; // счётчик
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == finded)
		{
			value++;
		}
	}
	return value;
}

int inputInt()																			// проверка вводимых cin int на отсутствие букв
{
	int value;	// вводимое число

	while (true)
	{
		cin >> value;
		if (cin.get() == '\n')
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Некорректное число, повторите ввод: ";
		}
	}
	return value;
}

int getSize()																			// получение размера
{
	int size;	// размер
	do
	{
		size = inputInt();
		if (size > 1)	// проверка size на неотрицательность
		{
			return size;
		}
		else
		{
			cout << "Размер должен быть неотрицательным" << endl;
		}
	} while (true);
}