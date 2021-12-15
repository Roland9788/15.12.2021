#include <iostream>
#include <string>
#include <time.h>
using namespace std;

//class Queue
//{
//	//Очередь
//	int* Wait;
//	int* Pri;
//	//Максимальный размер очереди
//	int MaxQueueLength;
//	//Текущий размер очереди
//	int QueueLength;
//
//public:
//	//Конструктор
//	Queue(int m);
//	//Деструктор
//	~Queue();
//	//Добавление элемента
//	void Add(int c,int p);
//	//Извлечение элемента
//	int Extract();
//	//Очистка очереди
//	void Clear();
//	//Проверка существования элементов очереди
//	bool IsEmpty();
//	//Проверка на переполнение очереди
//	bool IsFull();
//	//Количество элементов в очереди
//	int GetCount();
//	//Вывод очереди
//	void Print();
//};
//void Queue::Print()
//{
//	cout << "\nОчередь: ";
//	for (int i = 0; i < QueueLength; i++)
//	{
//		cout << Wait[i] << "-" << Pri[i] << "\n";
//
//	}
//	cout << "\n";
//}
//Queue::~Queue()
//{
//	delete[]Wait;
//	delete[] Pri;
//}
//Queue::Queue(int m)
//{
//	//Получаем размер очереди
//	MaxQueueLength = m;
//	//Создаем Очередб
//	Wait = new int[MaxQueueLength];
//	Pri = new int[MaxQueueLength];
//	//Изночально очередь пуста
//	QueueLength = 0;
//}
//void Queue::Add(int c, int p)
//{
//	//Добавление элемента в очередь если там есть свобоное место
//	if (!IsFull())
//	{
//		Wait[QueueLength] = c;
//		Pri[QueueLength] = p;
//		QueueLength++;
//	}
//
//}
//int Queue::Extract()
//{
//	if (!IsEmpty())
//	{
//
//
//		int max_pri = Pri[0];
//		int pos_max_pri = 0;
//		for (int i = 1; i < QueueLength; i++)
//		{
//			if (max_pri < Pri[i])
//			{
//				max_pri = Pri[i];
//				pos_max_pri = i;
//			}
//		}
//		int temp = Wait[pos_max_pri];
//		int temp1 = Pri[pos_max_pri];
//		for (int i = pos_max_pri; i < QueueLength - 1; i++)
//		{
//			Wait[i] = Wait[i + 1];
//			Pri[i] = Pri[i + 1];
//		}
//		QueueLength--;
//		return temp;
//	}
//	else
//	{
//		return -1;
//	}
//}
//void Queue::Clear()
//{
//	//Эффективная очистка очереди
//	QueueLength = 0;
//}
//int Queue::GetCount()
//{
//	return QueueLength;
//}
//bool Queue::IsEmpty()
//{
//	//Проверка на пустоту
//	return QueueLength == 0;
//}
//bool Queue::IsFull()
//{
//	//Проверка на заполнение
//	return QueueLength == MaxQueueLength;
//}

/*Списки*/
/*Узел списка*/
//struct Node
//{
//	//Информационная часть узла
//	int value;
//	//Указатель на след узел
//	Node* next;
//};

struct Node
{
	//Информационная часть узла
	char data;
	//Указатель на след узел
	Node* next;
};
//Односвязный список
class List
{
	Node* Head;
	Node* Tail;
	int Count = 0;
public:
	List();
	~List();
	void Print();
	void Add(char data);
	void Del();
	void DellAll();
	int GetCount();

};

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	DellAll();
}

void List::Print()
{
	Node* temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n\n";
}

void List::Add(char data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if (Head != NULL)
	{
		Tail->next = temp;
		Tail = temp;
	}
	else
	{
		Head = Tail = temp;
	}
}

void List::Del()
{
	Node* temp = Head;
	Head = Head->next;
	delete[]temp;
}

void List::DellAll()
{
	while (Head != 0)
	{
		Del();
	}
}

int List::GetCount()
{
	return Count;
}






int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	//Queue ochered(25);
	//for (int i = 0; i < 10; i++)
	//{
	//	ochered.Add(rand() % 10, rand() % 5);
	//}
	//ochered.Print();
	//ochered.Extract();
	////ochered.Clear();
	//ochered.Print();

	//Node* pHead;
	//Node* pTail;
	//pHead = new Node;
	//pTail = pHead;
	//pTail->value = 1;
	//pTail->next = new Node;
	//pTail = pTail->next;
	//pTail->next= NULL;
	//pTail->value = 2;

	List list;
	//char s[] = "Hello World!!!!!!!\n";
	string st;
	getline(cin, st);
	int len = size(st);
	for (int i = 0; i < len; i++)
	{
		list.Add(st[i]);
	}
	list.Print();
	list.Del();
	list.Del();
	list.Del();
	list.Print();



	return 0;
}