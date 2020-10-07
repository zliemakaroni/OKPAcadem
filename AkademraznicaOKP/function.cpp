#include "stdafx.h"
#include "function.h"
#include <iostream>
#include <ctime>


using namespace std;


int menu()																				// ����� ���� � �������� ������
{
	int foo;	// ���������� ��� �������
	cout << "1. ������� ������" << endl;
	cout << "2. ����� ���-�� ���������, ������ n" << endl;
	cout << "3. �������������� ������" << endl;
	cout << "������� ����� ������ ������ ��� ������" << endl;
	cout << "������� �������: ";
	cin >> foo;
	return foo;
}


int* createArray(int size)																// �������� �������
{

	int* arr = new int[size];
	int bot;	// ������ �������
	int top;	// ������� �������
	do {																				// �������� �� �������
		cout << "������ ������� ������ ���� ������ �������" << endl;					// ������ ������� ������ ��� �������
		cout << "������� ������ ������� �������: ";
		bot = inputInt();	// ��������� ������ �������
		cout << "������� ������� ������� �������: ";
		top = inputInt();	// ��������� ������ �������
	} while (bot > top);
	srand(time(0));
	for (int i = 0; i < size; i++)														// ���������� ������� ���������� �������
	{
		arr[i] = bot + rand() % (top - bot + 1);
	}
	return arr;
}

void printArray(int size, int* arr)														// ����� ������� �� �����
{																						// � ����� ������ �� ����� 10 ��������
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

int valueOfEqual(int finded, int size, int* arr)													// ���������� ���������� ��������� ����� � ������
{
	int value = 0; // �������
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == finded)
		{
			value++;
		}
	}
	return value;
}

int inputInt()																			// �������� �������� cin int �� ���������� ����
{
	int value;	// �������� �����

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
			cout << "������������ �����, ��������� ����: ";
		}
	}
	return value;
}

int getSize()																			// ��������� �������
{
	int size;	// ������
	do
	{
		size = inputInt();
		if (size > 1)	// �������� size �� �����������������
		{
			return size;
		}
		else
		{
			cout << "������ ������ ���� ���������������" << endl;
		}
	} while (true);
}