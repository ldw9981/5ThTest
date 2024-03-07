#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* prevNode = nullptr;
	Node* nextNode = nullptr;
};

template <typename T>
class LinkedList
{
public:
	Node<T>* headNode = nullptr;
	Node<T>* tailNode = nullptr;

	void PushBack(T data);
	void PushFront(T data);

	void PopBack();
	void PopFront();

	void DeleteNode(T data);

	void PrintAll();
};

template<typename T>
inline void LinkedList<T>::PushBack(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;

	if (tailNode == nullptr)
	{
		headNode = newNode;
		tailNode = newNode;
		return;
	}

	if (tailNode != nullptr)
	{
		tailNode->nextNode = newNode;
		newNode->prevNode = tailNode;
		tailNode = newNode;
	}
}

template<typename T>
inline void LinkedList<T>::PushFront(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;

	if (headNode == nullptr)
	{
		headNode = newNode;
		tailNode = newNode;
		return;
	}

	if (headNode != nullptr)
	{
		headNode->prevNode = newNode;
		newNode->nextNode = headNode;
		headNode = newNode;
	}
}

template<typename T>
inline void LinkedList<T>::PopBack()
{
	if (tailNode == nullptr)
	{
		return;
	}

	if (tailNode != nullptr)
	{
		Node<T>* prev = tailNode->prevNode;
		prev->nextNode = nullptr;
		tailNode = prev;
	}
}

template<typename T>
inline void LinkedList<T>::PopFront()
{
	if (headNode == nullptr)
	{
		return;
	}

	if (headNode != nullptr)
	{
		if (headNode->nextNode == nullptr)
		{
			headNode = nullptr;
			tailNode = nullptr;
			return;
		}
		
		Node<T>* next = headNode->nextNode;
		next->prevNode = nullptr;
		headNode = next;
	}
}

template<typename T>
inline void LinkedList<T>::DeleteNode(T data)
{
	if (headNode == nullptr || tailNode == nullptr)
	{
		return;
	}

	if (headNode->data == data)
	{
		PopFront();
		return;
	}

	if (tailNode->data == data)
	{
		PopBack();
		return;
	}

	Node<T>* curNode = headNode;
	while (curNode != nullptr)
	{
		if (curNode->data == data)
		{
			Node<T>* prev = curNode->prevNode;
			Node<T>* next = curNode->nextNode;
			prev->nextNode = next;
			next->prevNode = prev;
		}
		curNode = curNode->nextNode;
	}
}

template<typename T>
inline void LinkedList<T>::PrintAll()
{
	if (headNode == nullptr)
	{
		cout << "이중 연결 리스트가 비어있습니다." << endl;
		return;
	}

	cout << "이중 연결 리스트 : [";
	Node<T>* curNode = headNode;
	while (curNode != nullptr)
	{
		cout << curNode->data;
		if (curNode->nextNode != nullptr)
			cout << "->";
		curNode = curNode->nextNode;
	}
	cout << "]" << endl;
}
