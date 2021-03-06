#include "stdafx.h"
#include <iostream>
#include <ctime>
#include "function.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массива: ";
	int _size;	// размер массива
	int _finded;	// искомое число
	_size = getSize();	// принимаем размер массива с проверкой на валидность
	int* _arr = createArray(_size);	// создаём массив с заполнением случайными элементами
	while (true)
	{
		switch (menu())
		{
		case 1:
		{
			printArray(_size, _arr);	// выводим массив
			break;
		}
		case 2:
		{
			cout << "Введите искомое число: ";
			_finded = inputInt();	// принимаем исходное число
			cout << "Количество " << _finded << " в массиве: " << valueOfEqual(_finded, _size, _arr) << endl;	// выводим число повторений искомого числа в массиве
			break;
		}
		case 3:											// переопределение массива
		{
			delete[] _arr;	// освобождаем память, занятую под переменную
			cout << "Введите размер массива: ";
			_size = getSize();
			_arr = createArray(_size);
			break;
		}
		default:
		{
			delete[] _arr;
			return 0;
		}
		}
	}
}