#pragma once
#include "LinaIter.h"
#include <iostream>

using namespace std;

template <typename T>
class LinaList
{
public:
	int number; //����� �� ����.
	Node<T>* first;
	Node<T>* end;
	Node<T>* temp;

	LinaList();
	~LinaList() {};

	void pushBack(T getData);
	void popBack();
	void pushFront(T getData);
	void popFront();
	void Insert(LinaIter<T> i, T getData);
	LinaIter<T> Erase(LinaIter<T> i);
	void Print();
	LinaIter<T> Begin();
	LinaIter<T> End();
};

template<typename T>
inline LinaList<T>::LinaList()
{
	number = -1; //-1�̶�� ���� ��尡 �ƿ� ���ٴ°����� �մϴ�.
	first = nullptr;
	end = nullptr;
	temp = new Node<T>();
}

template<typename T>
inline void LinaList<T>::pushBack(T getData)
{
	if (number == -1)
	{
		first = new Node<T>(getData);
		end = first;
		first->next = temp;
		first->prev = temp;
		temp->prev = first;
		temp->next = first;

		//end = first->next->prev;
		//end
	}
	else
	{
		end->next = new Node<T>(getData);
		end->next->prev = end;
		end = end->next;
		end->next = temp;
		temp->prev = end;
	}
	number++;
}

template<typename T>
inline void LinaList<T>::popBack()
{
	if (number == -1)
	{
		cout << "��尡 �����" << endl;
	}
	else if (number == 0) //��尡 �ϳ��� �ִ� ���¶�
	{
		delete end;
		end = nullptr;
		first = nullptr;
		number--;
	}
	else
	{
		Node<T>* popTemp = end->prev;
		popTemp->next = temp;
		temp->prev = popTemp;
		delete end;
		end = popTemp;
		number--;
	}
}

template<typename T>
inline void LinaList<T>::pushFront(T getData)
{
	if (number == -1)
	{
		first = new Node<T>(getData);
		end = first;
		first->next = temp;
		first->prev = temp;
		temp->prev = first;
		temp->next = first;
	}
	else
	{
		first->next = new Node<T>(getData);
		first->prev->next = end;
		first = first->prev;
		first->prev = temp;
		temp->next = first;
	}
	number++;
}

template<typename T>
inline void LinaList<T>::popFront()
{
	if (number == -1)
	{
		cout << "��尡 �����" << endl;
	}
	else if (number == 0)
	{
		delete end;
		end = nullptr;
		first = nullptr;
		number--;
	}
	else
	{
		Node<T>* popTemp = first->next;
		delete first;
		first = popTemp;
		first->prev = temp;
		temp->next = first;
		number--;
	}
}

template<typename T>
inline void LinaList<T>::Insert(LinaIter<T> i, T getData)
{
	///������ �ȵȴ� ���
	/*Node<T>* now = &i;
	Node<T>* prevNode =now->prev;
	Node<T>* nextNode = new Node<T>(getData);
	prevNode->next = nextNode;
	prevNode->prev = prevNode;
	prevNode->next = now;
	now->prev = nextNode;
	if (now == first) first = nextNode;
	if (now == end) end = nextNode;
	number++;*/

	Node<T>* now = &i;
	Node<T>* prevnode = now->prev;
	Node<T>* newnode = new Node<T>(getData);
	prevnode->next = newnode;
	newnode->prev = prevnode;
	newnode->next = now;
	now->prev = newnode;
	if (now == first) first = newnode;
	if (now == end) end = newnode; //end���� temp����?
	number++;
}

template<typename T>
inline LinaIter<T> LinaList<T>::Erase(LinaIter<T> i)
{
	Node<T>* now = &i;
	Node<T>* prevnode = now->prev;
	Node<T>* newnode = now->next;
	prevnode->next = newnode;
	newnode->prev = prevnode;
	if (now == first) newnode = first;
	if (now == end) prevnode = end;
	return LinaIter<T>(newnode);
}

template<typename T>
inline void LinaList<T>::Print()
{
	if (number == -1)
	{
		cout << "����� ��尡 �ϳ��� �����ϴ�." << endl;
	}

	for (auto iter = this->Begin(); iter != this->End(); ++iter)
	{
		cout << *iter << endl;
	}
}

template<typename T>
inline LinaIter<T> LinaList<T>::Begin()
{
	return LinaIter<T>(first);
}

template<typename T>
inline LinaIter<T> LinaList<T>::End()
{
	return LinaIter<T>(temp);
}
