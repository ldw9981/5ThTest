#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Node
{
	T data;
	Node<T>* nextNode;

	Node(T data, Node<T>* nextNode = nullptr) : data(data), nextNode(nextNode) {}
};

template<typename T>
class ListIterator
{
public:
	ListIterator(Node<T>* node) : node(node) {}

	void operator++()
	{
		node = node->nextNode;
	}

	Node<T>* operator*()
	{
		return node;
	}

	bool operator==(const ListIterator<T> other)
	{
		return node == other.node;
	}
	
	bool operator!=(const ListIterator<T> other)
	{
		return node != other.node;
	}

	Node<T>* node;
};

template<typename T>
class LinkedList
{
public:

	void PushBack(const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		if (headNode == nullptr)
		{
			headNode = newNode;
		}
		else
		{
			for (auto iter = Begin(); iter != End(); ++iter)
			{
				if ((*iter)->nextNode == nullptr)
				{
					(*iter)->nextNode = newNode;
					break;
				}
			}
		}
	}

	void InsertAfter(ListIterator<T> position, const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		if (position == nullptr)
		{
			PushBack(value);
		}
		else
		{
			newNode->nextNode = (*position)->nextNode;
			(*position)->nextNode = newNode;
		}
	}

	void EraseAfter(ListIterator<T> position)
	{
		if (position == nullptr || (*position)->nextNode == nullptr)
			return;
		else
		{
			Node<T>* toDelete = (*position)->nextNode;
			(*position)->nextNode = (*position)->nextNode->nextNode;
			delete toDelete;
			toDelete = nullptr;
		}
	}

	void PushFront(const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->nextNode = headNode;
		headNode = newNode;
	}

	void PopFront()
	{
		Node<T>* toDelete = headNode;
		headNode = headNode->nextNode;
		delete toDelete;
		toDelete = nullptr;
	}

	void Clear()
	{
		auto iter = Begin();
		while (iter != End())
		{
			Node<T>* toDelete = *iter;
			++iter;
			delete toDelete;
			toDelete = nullptr;
		}

		headNode = nullptr;
	}

	ListIterator<T> Begin()
	{
		return ListIterator<T>(headNode);
	}

	ListIterator<T> End()
	{
		return ListIterator<T>(nullptr);
	}

	LinkedList<T> operator=(const LinkedList<T>& other)
	{
		ListIterator<T> curIter = Begin();
		for (auto iter = other.Begin(); iter != other.End(); ++iter)
		{
			*curIter = *iter;
			++curIter;
		}
	}

	void Print()
	{
		if (headNode == nullptr)
			return;

		auto iter = Begin();
	
		while (iter != End())
		{
			cout << (*iter)->data << endl;
			++iter;
		}
	}

private:
	Node<T>* headNode = nullptr;
};
