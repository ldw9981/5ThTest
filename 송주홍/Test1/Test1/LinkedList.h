#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct Node
{
	T data;
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;
};

template<typename T>
class LinkedList
{
public:
	LinkedList() = default;
	~LinkedList() = default;

public:
	void Insert(T data);
	void DeleteBack();
	void Delete(Node<T>* node);
	void PrintAll();
	Node<T>* GetNode(int index);
	Node<T>* Find(T data);
	unsigned int Size();
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	unsigned int size = 0;

};

template<typename T>
inline void LinkedList<T>::Insert(T data)
{
	size++;
	if (head == nullptr)
	{
		head = new Node<T>;
		head->data = data;
		tail = head;
		return;
	}

	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
}

template<typename T>
inline void LinkedList<T>::DeleteBack()
{
	if (size == 0)
	{
		cout << "You can not delete : size 0" << endl;
		return;
	}

	Node<T>* temp = tail->prev;
	if(temp)
		temp->next = nullptr;
	delete tail;
	tail = temp;
	size--;

	if (size == 0)
	{
		head = nullptr;
	}
}

template<typename T>
inline void LinkedList<T>::Delete(Node<T>* node)
{
	Node<T>* cur = head;
	while (cur != nullptr)
	{
		if (cur == node)
		{
			if(cur->prev)
				cur->prev->next = cur->next;
			if(cur->next)
				cur->next->prev = cur->prev;
			if (cur == head)
				head = cur->next;
			if (cur == tail)
				tail = cur->prev;
			delete cur;
			size--;
			return;
		}
		cur = cur->next;
	}
	
}

template<typename T>
inline void LinkedList<T>::PrintAll()
{
	Node<T>* cur = head;
	while (cur != nullptr)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

template<typename T>
inline Node<T>* LinkedList<T>::GetNode(int index)
{
	Node<T>* cur = head;
	int idx = 0;
	while (cur != nullptr)
	{
		if (idx == index)
			return cur;
		cur = cur->next;
		idx++;
	}
	return nullptr;
}

template<typename T>
inline Node<T>* LinkedList<T>::Find(T data)
{
	Node<T>* cur = head;
	while (cur != nullptr)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	cout << "Data not Found" << endl;
	return nullptr;
}

template<typename T>
inline unsigned int LinkedList<T>::Size()
{
	return size;
}
