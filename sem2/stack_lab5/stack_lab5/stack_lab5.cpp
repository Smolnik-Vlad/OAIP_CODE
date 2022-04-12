#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
using namespace std;


class Stack
{
private:
	struct Node
	{
		int value;
		Node* n_ptr;
		Node(int value, Node* n_ptr)
		{
			this->value = value;
			this->n_ptr = n_ptr;
		}
	};
	Node* head;

public:
	Stack()
	{
		head = nullptr;
		Node* p = head;
		cout << "Введите первый элемент стека: ";
		int a;
		cin >> a;
		head = new Node(a, p);
	}

	void push()
	{
		cout << "Новый элемент: ";
		int a;
		cin >> a;
		Node* current = head;
		head = new Node(a, current);
		
	}
	
	void check_Stack()
	{
		Node* current = head;
		if (head != nullptr)
		{
			while (current != nullptr)
			{
				cout << current->value << " ";
				current = current->n_ptr;

			}
		}
		else cout << "В стеке нет элементов" << endl;
		
	}

	void del_even() //удаляет четные элеементы
	{
		Node* current = head;
		while (current != nullptr && current==head && current->value%2==0 ) //Сразу проверяем наличие четных элементов в самом начале (когда head указывает на четный элемент)
		{
			Node* del = head;
			head = current->n_ptr;
			current = current->n_ptr;
			delete del;
		}
		current = head;
		if (head != nullptr)   // проверка идет со второго элемента, поскольку на первый элемент указывает указатель, который уже проверен
		{
			while (current->n_ptr != nullptr)
			{
				if (current->n_ptr->value % 2 == 0)
				{
					Node* del = current->n_ptr;
					current->n_ptr = current->n_ptr->n_ptr;
					delete del;
				}
				else current= current->n_ptr;
			}
		}
		
		
	} 

	void sort_values()
	{
		Node* current_1 = head;
		for (current_1; current_1->n_ptr != nullptr; current_1 = current_1->n_ptr)
		{
			for (Node* current_2 = current_1->n_ptr; current_2 != nullptr; current_2=current_2->n_ptr)
			{
				if (current_1->value > current_2->value)
				{
					swap(current_1->value, current_2->value);
				}
			}
		}
	}

	void sort_node()
	{
		Node* current_1 = head;
		Node* current_2;
		for (current_1; current_1->n_ptr->n_ptr != nullptr; current_1 = current_1->n_ptr)
		{
			for (current_2=current_1->n_ptr; current_2->n_ptr != nullptr; current_2 = current_2->n_ptr)
			{
				
				if (current_1->n_ptr->value > current_2->n_ptr->value)
				{
					Node* A= current_1->n_ptr;  
					Node* B = current_2->n_ptr;
					Node* ptr_1 = current_1->n_ptr->n_ptr;
					

					A->n_ptr = B->n_ptr;
					B->n_ptr = ptr_1;

					current_1->n_ptr = B;
					current_2->n_ptr = A;
					
				}
				
			}
		}

	}

	
};

void sorts(Stack& st)
{
	cout << "Как вы хотите сортировать список: 1. МЕНЯЯ ЗНАЧЕНИЯ. 2. МЕНЯЯ УЗЛЫ:  ";
	int choose;
	cin >> choose;
	switch (choose)
	{
	case 1:
		st.sort_values();
		break;
	case 2:
		st.sort_node();
		break;
	}
}



int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	Stack st;
	cout << "При создании стека был добавлен один элемент." << endl;
	while (true)
	{
		cout << "\n1. Добавить новый элемент. 2. Просмотреть весь стек. 3. Удалить все четные элементы. 4. Сортировка. 5. Выйти из программы";
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
			st.push();
			break;
		case 2:
			st.check_Stack();
			break;
		case 3:
			st.del_even();
			break;
		case 4:
			sorts(st);
			break;
		case 5:
			return 0;
			break;
		}
		
	}
	
}