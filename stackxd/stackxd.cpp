#include <iostream>
using namespace std;

class Stack
{
	static const int SIZE = 10; // количество элементов в стеке (при желании можно поменять)

	int* ar = new int[SIZE]; // обычно реализуется как статический массив
	int index = 0; // индекс, по которому добавится новый элемент
	// также индекс можно воспринимать как количество элементов, которые были добавлены в стек на данный момент

public:
	~Stack()
	{
		if (index > 0)
		delete[] ar;
		ar = nullptr;
	}
	Stack()
	{
		ar = nullptr; // необязательно
		index = 0; // количество элементов в стеке определяется по значению index
	}
	Stack(const Stack& st)
	{
		
		ar = new int[st.index];
		index = st.index;
	    for (int i = 0; i < index; i++)
		ar[i] = st.ar[i];
    }
	Stack operator=(const Stack& st)
	{
		if (index > 0)
		{
			index = 0;
			delete[] ar;
		}
		ar = new int[st.index];
		index = st.index;
		for (int i = 0; i < index; i++)
		ar[i] = st.ar[i];
	    return *this;
	}

	void Clear()
	{
		index = 0;
	}

	bool IsEmpty() const
	{
		return index == 0;
	}

	bool IsFull() const
	{
		return index == SIZE;
	}

	int GetCount()
	{
		return index;
	}

	void Push(int number)
	{
		if (!IsFull())
		{
			ar[index] = number;
			index++;
		}
		else
		{
			throw "Stack overflow!";
		}
	}

	int Pop()
	{
		if (!IsEmpty())
		{
			index--;
			return ar[index];
		}
		else
		{
			throw "Stack is empty!";
		}
	}
};

int main()
{
	Stack st; // создаём "пустой" стек

	// до тех пор, пока стек не заполнился
	while (!st.IsFull())
		st.Push(rand() % 90 + 10); // добавляем элемент на вершину стека

	// до тех пор, пока в стеке есть какие-либо значения
	while (!st.IsEmpty())
		cout << st.Pop() << "  "; // извлечь значение и показать на экране

}