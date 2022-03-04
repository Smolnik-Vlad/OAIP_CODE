#include <iostream>
using namespace std;

int binary(int* mass, int min, int max, int a, int& numb)
{
	if (mass[min] == a)
	{
		numb = min;
		return 0;
	}
	else if (mass[max] == a)
	{
		numb = max;
		return 0;
	}
	else if (a >= mass[(max + min) / 2])
	{
		min = (max + min) / 2;
	}
	else if (a < mass[(max + min) / 2])
	{
		max = (max + min) / 2;
	}
	binary(mass, min, max, a, numb);
	return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите разммер массива: ";
	int n, a, numb;
	cin >> n;
	int* mass = new int[n];
	for (int i = 0; i < n; i++)
	{
		mass[i] = i + 1;
	}
	cout << "\nВведите находящийся элемент массива для нахождения его номера в массиве: ";
	cin >> a;
	binary(mass, 0, n - 1, a, numb);
	cout <<"Номер элемента: "<< numb+1;
}

/*int main()
{
	double check = true;
	int n, a, min, max, numb;
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массива: ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	cout << "\nВведите находящийся элемент массива для нахождения его номера в массиве: ";
	cin >> a;
	min = arr[0];
	max = arr[n - 1];
	while (check)
	{
		if (arr[min] == a)
		{
			numb = min;
			check = false;
		}
		else if (arr[max] == a)
		{
			numb = max;
			check = false;
		}
		else if (a >= arr[(max + min) / 2])
		{
			min = (max + min) / 2;
		}
		else if (a <= arr[(max + min) / 2])
		{
			max = (max + min) / 2;
		}
	}
	cout << "Номер элемента: " << numb+1;
}*/