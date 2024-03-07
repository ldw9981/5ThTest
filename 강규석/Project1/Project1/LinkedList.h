#pragma once
#include <iostream>

template <typename T>
struct Node
{
	Node() : next(nullptr), prev(nullptr), data(0) {}
	Node(const T& d) : next(nullptr), prev(nullptr), data(d) {}

	Node* next;
	Node* prev;
	T data;
};

template <typename T>
class Iterator
{
public:
	Iterator() : node(nullptr)
	{
		
	}

	Iterator(Node<T>* n) : node(n) 
	{
		
	}
	Iterator(const Iterator& right)
	{
		node = right.node;
	}

	void operator=(const Iterator& right)
	{
		node = right.node;
		//return Iterator(right.node);
	}
	
	bool operator!=(const Iterator& right)
	{
		return node->data != right.node->data;
	}

	Iterator& operator++(int)
	{
		node = node->next;
		return *this;
	}

	Iterator operator++()
	{
		Iterator ret(node);
		node = node->next;
		return ret;
	}

	

	T& operator*()
	{
		return node->data;
	}

	Node<T>* node;
};

template <typename T>
class LinkedList
{
public:
	typedef Iterator<T> Iterator;

	LinkedList()
	{
		header = new Node<T>();
		header->next = header;
		header->prev = header;
	}
	~LinkedList()
	{
		while (_size > 0)
		{
			pop_back();
		}
		delete header;
	}

	void push_back(const T& data)
	{
		AddNode(header, data);
	}

	void pop_back()
	{
		DeleteNode(header->prev);
	}

	void AddNode(Node<T>* currentNode, const T& data)
	{
		Node<T>* prevNode = currentNode->prev;
		//Node<T>* nextNode = currentNode->next;

		Node<T>* newNode = new Node<T>(data);

		prevNode->next = newNode;
		currentNode->prev = newNode;

		newNode->prev = prevNode;
		newNode->next = currentNode;

		_size++;
	}

	void DeleteNode(Node<T>* currentNode)
	{
		Node<T>* prevNode = currentNode->prev;
		Node<T>* nextNode = currentNode->next;

		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete currentNode;
		_size--;
	}

	Iterator begin()
	{
		return Iterator(header->next);
	}

	Iterator end()
	{
		return Iterator(header);
	}

	Iterator insert(Iterator it, const T& data)
	{
		AddNode(it.node, data);
		return Iterator(it.node->prev);
	}

	Iterator erase(Iterator it)
	{
		Node<T>* node = it.node->next;
		DeleteNode(it.node);
		return Iterator(node);
	}

	int size()
	{
		return _size;
	}

private:
	int _size = 0;
	Node<T>* header;
};

