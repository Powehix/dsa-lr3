#include <iostream>
#include <time.h>

using namespace std;

struct List {
	List * next;
	int info;
	List * prev;
};

void print(List * k); //вывод списка (вывод 25 элементов)
void print_prev(List * k); //вывод списка в обратном порядке
void search(List * k); //поиск элемента
int average(List * k); //вычисление среднего значения для всех элементов списка
void delete_avg(List * k, int avg); //удаление элементов в списке, значение которых ниже среднего
void print_list(List * k, int avg); //вывод списка после удаления

void main() {
	List * first = new List();
	srand(time(0));
	first->info = rand() % 100;
	List * k = first;
	for (int i = 0; i < 9; i++) {
		k->next = new List();
		k->next->prev = k;
		k = k->next;
		k->info = rand() % 100;
	} 
	first->prev = k;
	k->next = first; //инициализация и заполнение

	k = first; //в начало списка
	print(k);

	k = first->prev; //в конец списка
	print_prev(k);

	k = first;
	search(k);

	int avg;
	avg = average(k);

	delete_avg(k, avg);
	print_list(k, avg);

	system("PAUSE");
}


void print(List * k) {
	cout << "1. List output:\n\n";
	for (int i = 0; i < 10; i++) {
		cout << i << ". " << k->info << " \n";
		k = k->next;
	}
}

void print_prev(List * k) {
	cout << "\n2. List output (prev):\n\n";
	for (int i = 0; i < 10; i++) {
		cout << i << ". " << k->info << " \n";
		k = k->prev;
	}
}

void search(List * k) {
	int x, count = 0;
	cout << "\n2. Enter the key > ";
	cin >> x;
	for (int i = 0; i < 10; i++) {
		if (k->info == x) {
			cout << "The key is found! Its serial number is " << i << endl;
			count = 1;
		}
		k = k->next;
	}
	if (count != 1)
		cout << "Key not found.\n";
}

int average(List * k) {
	int average = 0;
	for (int i = 0; i < 10; i++) {
		average += k->info;
		k = k->next;
	}
	cout << "\n3. The average of all elements is " << average / 10 << endl;
	return average / 10;
}

void delete_avg(List * k, int avg) {
	for (int i = 0; i < 10; i++) {
		if (k->info < avg) {
			k->next->prev = k->prev;
			k->prev->next = k->next;
		}
		k = k->next;
	}
}

void print_list(List * k, int avg) {
	cout << "\n4-5. List output (after removal):\n\n";
	for (int i = 0; i < 10; i++) {
		if (k->info < avg)
			k = k->next;
		else break;
	}
	for (int i = 0; i < 10; i++) {
		cout << i << ". " << k->info << " \n";
		k = k->next;
	}
}