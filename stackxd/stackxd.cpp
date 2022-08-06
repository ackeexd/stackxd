#include <iostream>
using namespace std;

class Stack
{
	static const int SIZE = 10; // ���������� ��������� � ����� (��� ������� ����� ��������)

	int* ar = new int[SIZE]; // ������ ����������� ��� ����������� ������
	int index = 0; // ������, �� �������� ��������� ����� �������
	// ����� ������ ����� ������������ ��� ���������� ���������, ������� ���� ��������� � ���� �� ������ ������

public:
	~Stack()
	{
		if (index > 0)
		delete[] ar;
		ar = nullptr;
	}
	Stack()
	{
		ar = nullptr; // �������������
		index = 0; // ���������� ��������� � ����� ������������ �� �������� index
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
	Stack st; // ������ "������" ����

	// �� ��� ���, ���� ���� �� ����������
	while (!st.IsFull())
		st.Push(rand() % 90 + 10); // ��������� ������� �� ������� �����

	// �� ��� ���, ���� � ����� ���� �����-���� ��������
	while (!st.IsEmpty())
		cout << st.Pop() << "  "; // ������� �������� � �������� �� ������

}