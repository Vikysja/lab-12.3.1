// lab 12.3.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Квецко Вікторії
// Варіант 11

#include<iostream>
#include<Windows.h>
#include<time.h>
using namespace std;

struct Elem
{
	Elem* next,
		* prev;
	int info;
};


void enqueue(Elem*& first, Elem*& last, int value)
{
	Elem* tmp = new Elem;
	tmp->info = value; // 2
	tmp->next = NULL; // 3
	if (last != NULL)
		last->next = tmp; // 4
	tmp->prev = last; // 5
	last = tmp; // 6
	if (first == NULL)
		first = tmp; // 7
}

void Print(Elem* begin)
{
	while (begin != NULL)
	{
		cout << begin->info << "\t";
		begin = begin->next;
	}
	cout << endl;
}

bool AreInElem(Elem* begin1, Elem* begin2)
{
	bool result = false;
	Elem* L = begin2;
	while (begin1 != NULL)
	{
		if (L != NULL)
		{
			if (begin1->info == L->info)
			{
				L = L->next;
				result = true;
				begin1 = begin1->next;
			}
			else
			{
				if (begin1->info == begin2->info)
				{
					L = begin2;
					result = false;
				}
				else
				{
					L = begin2;
					result = false;
					begin1 = begin1->next;
				}
			}
		}
		else
		{
			break;
		}
	}
	return result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Elem* begin1 = NULL,
		* end1 = NULL,
		* begin2 = NULL,
		* end2 = NULL;
	int a1[5] = { 1,1,2,3,3 };
	int a2[3] = { 1,2,4 };
	for (int i = 0; i < 5; i++)
	{
		enqueue(begin1, end1, a1[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		enqueue(begin2, end2, a2[i]);
	}
	Print(begin2);
	Print(begin1);
	if (AreInElem(begin1, begin2))
	{
		cout << "Так, список l1 входить в список l2" << endl;
	}
	else
	{
		cout << "Ні, список l1 не входить в список l2" << endl;
	}

	return 0;
}

