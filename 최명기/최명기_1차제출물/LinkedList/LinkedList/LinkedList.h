#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* nextNode;
};

template <typename T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;

public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
public:
	void AddFrontNode(T data);
	void AddNode(T data);
	void Insert(Node<T>* prevNode, T data);
	void Delete(Node<T>* prevNode);

	Node<T>* getHead() {
		return head;
	}
	void Display(Node<T>* head);
};

template <typename T>
void LinkedList<T>::AddFrontNode(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->nextNode = head;
		head = newNode;
	}
}

template <typename T>
void LinkedList<T>::AddNode(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;

	newNode->nextNode = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->nextNode = newNode;
		tail = newNode;
	}
}

template <typename T>
void LinkedList<T>::Insert(Node<T>* prevNode, T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;

	newNode->nextNode = prevNode->nextNode;

	prevNode->nextNode = newNode;
}

template <typename T>
void LinkedList<T>::Delete(Node<T>* prevNode)
{
	Node<T>* deleteNode = prevNode->nextNode;
	prevNode->nextNode = deleteNode->nextNode;
	
	delete deleteNode;
}

template <typename T>
void LinkedList<T>::Display(Node<T>* head)
{
	if (head == nullptr)
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << head->data << " ";
		Display(head->nextNode);
	}
}