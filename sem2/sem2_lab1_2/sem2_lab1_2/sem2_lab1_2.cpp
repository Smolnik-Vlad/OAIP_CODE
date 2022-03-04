#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> get_surnames(string sur)
{
	vector<string> surnames;
	string surname="";
	sur += ' ';
	bool a=true;
	for (int i = 0; i < sur.length(); i++)
	{
		if (sur[i] != ' ')
		{
			surname += sur[i];
			a = 0;
		}

		else if(sur[i]==' ' && a==0)
		{
			surnames.push_back(surname);
			surname = "";
			a=1;
		}
	}
	return surnames;
}

void aver(int physics, int math, int inf, int chem, double& average)
{

	average = (physics + math + inf + chem) / 4.;
}


class Student
{
protected:
	string name, father_name;
	int year, numb_of_groop, physics, math, inf, chem;
	double  average;

public:
	string surname;

	void enter_info(string surname)
	{
		this->surname = surname;
		cout << "Введите инфу по студенту " << surname<<endl;
		cout << "Введите имя: ";
		cin >> name;
		cout << "\nВведите отчество: ";
		cin >> father_name;
		cout << "\nВведите год рождения: ";
		cin >> year;
		cout << "\nВведите номер группы: ";
		cin >> numb_of_groop;
		cout << "\nВведите оценки за семестр: " << endl << "По физике: ";
		cin >> physics;
		cout << "\nПо математике: ";
		cin >> math;
		cout << "\nПо информатике: ";
		cin >> inf;
		cout << "\nПо химии: ";
		cin >> chem;

		aver(physics, math, inf, chem, average);

	}

	void get_info()
	{
		cout <<endl<< surname << " "<<name <<" "<< father_name << endl;
		cout << "Год: " << year<<endl;
		cout << "Группа: " << numb_of_groop<<endl;
		cout << "Отметка по" << endl;
		cout << "Математике: " << math<<endl;
		cout << "Физике: " << physics << endl;
		cout << "Информатике: " << inf << endl;
		cout << "Химии: " << chem<<endl;
		cout << "Средняя отметка: " << average<<endl;

	}

	void changing(vector<string>& surnames, int numb)
	{
		string new_name;
		int choose;
		cout << "Что вы хотите изменить? 1. Фамилию 2. Имя 3. Отчество 4. Год рождения 5. Номер группы 6. Отметку по физике 7. Отметку по математике 8. Отметку по информатике 9. Отметку по химии: ";
		cin >> choose;

		switch (choose)
		{

		 case 1:
			cout << "\nНовая фамилия: ";
			
			cin >> new_name;
			surnames[numb] = new_name;
			surname = new_name;
			break;

		 case 2:
			 cout << "\nНовое имя: ";
			 cin >> name;
			 break;
		 case 3:
			 cout << "\n Новое отчество: ";
			 father_name = father_name;
			 break;
		 case 4:
			 cout << "\n Год рождения: ";
			 cin >> year;
			 break;
		 case 5:
			 cout << "\nНомер группы: ";
			 cin >> numb_of_groop;
			 break;
		 case 6:
			 cout << "\nОтметка по физике: ";
			 cin >> physics;
			 break;
		 case 7:
			 cout << "\nОтметка по математике: ";
			 cin >> math;
			 break;
		 case 8:
			 cout << "\nОтметка по информатике: ";
			 cin >> inf;
			 break;
		 case 9:
			 cout << "\nОтметка по химии: ";
		     cin >> chem;
			 break;
		}
		aver(physics, math, inf, chem, average);
	}

};

int choose_student(vector<Student> student)
{
	int choose;
	cout << "Выберите студента: ";
	for (int i = 0; i < student.size(); i++)
	{
		cout << i + 1 << " " << student[i].surname << " ";
	}
	cout << ":";
	cin >> choose;
	return choose;
}


void info(vector<Student> student)
{
	int choose;
	cout << "О каком студенте хотите получить инфу: ";
	for (int i = 0; i < student.size(); i++)
	{
		cout << i+1 << ". " << student[i].surname << " ";
	}
	cin >> choose;
	student[choose - 1].get_info();
}

void changing(vector<Student>& student, vector<string>& surnames)
{
	int choose;
	string new_stud;

	cout << "\nЧто вы хотите сделать? 1. Удалить студента 2. Добавить студента 3. Изменить информацию о студенте 4. Отмена действия: ";
	cin >> choose;

	switch (choose)
	{
	 case 1:
		
		choose = choose_student(student);
		student.erase(student.begin() + choose - 1);
		break;

	 case 2:
		 cout << "Фамилия нового студента: ";
		 cin >> new_stud;
		 student.resize(student.size()+1);
		 surnames.push_back(new_stud);
		 student[student.size() - 1].enter_info(surnames[surnames.size() - 1]);

	 case 3:
		 choose = choose_student(student);
		 student[choose - 1].changing(surnames, choose-1);
	 case 4: break;
	}

}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите фамилии студентов в строку: ";
	int choose;
	bool a = true;;
	string sur;
	vector <string> surnames;
	getline(cin, sur);

	surnames = get_surnames(sur);

	vector<Student> student(surnames.size());

	for (int i = 0; i < student.size(); i++)
	{
		student[i].enter_info(surnames[i]);
	}

	while (a)
	{
		cout << "\n1. Просмотреть инфу по студенту 2. Изменить инфу о студенте; 3. 4. Выйти из программы: ";

		cin >> choose;

		switch (choose)
		{
		case 1:
			info(student);
			break;
		case 2:
			changing(student, surnames);
			break;
		case 3:
			break;
		case 4:
			a = false;
			break;
		}


		
	}
}