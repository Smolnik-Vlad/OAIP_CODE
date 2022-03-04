

#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <map>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str, add, word = "";
	vector<string> check;
	map <string, int> map_check_key;
	map <int, string> map_check;
	int a = 0;
	cout << "Enter the string, that consist of some words: " << endl;
	getline(cin, str);
	str += ' ';

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			add += str[i];
		}
		else
		{
			check.push_back(add);
			add = "";

		}
	}


	for (int i = 0; i < check.size(); i++)
	{

		map_check[i] = check[i];				/*Создаем мап с ключем(цифрой) и значением*/
		for(int j=0; j<check[i].length(); j++)
		{
			check[i][j] = tolower(check[i][j]);
		}
		map_check_key[check[i]] = i;            /*Создаем мап с маленькими буквами со значением, по которому будем искать ключ (цифру для map_check)*/


	}

	sort(check.begin(), check.end());
	cout << "sorted: ";
	for (auto it = check.begin(); it != check.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;

	for (int i = 0; i < check.size() - 1; i++)
	{
		if (check[i] == check[i + 1])
		{
			a++;

		}
		else if (check[i] != check[i + 1] && a != 0)
		{
			a = 0;
		}
		else if (check[i] != check[i + 1] && a == 0)
		{
			int it = map_check_key.at(check[i]);
			word = map_check.at(it);
			break;
		}
	}

	if (word == "" && check[check.size() - 1] != check[check.size() - 2])
	{
		/*word = check[check.size() - 1];*/
		int it = map_check_key.at(check[check.size() - 1]);
		word = map_check.at(it);
	}
	else if (word == "")  word = "Не существует такого слова";
	cout << "\n" << word;
}