#pragma once

#include <stdio.h>
#include <iostream>

template<typename T>
class Node
{
public:
	Node(T data);

public:
	T _data;
	Node<T>* _next{ nullptr };
};

template<typename T>
inline Node<T>::Node(T data)
	:_data(data)
{
}

template<typename T>
class LinkedList
{
public:
	LinkedList();

public:
	void AddData(T data);
	void DeleteData(int idx);

	void PrintData();
	void PrintSize();

private:
	int _size = 0;
	Node<T>* _root{ nullptr };
};

template<typename T>
inline LinkedList<T>::LinkedList()
{
	printf("LinkedList ����\n");
}

template<typename T>
inline void LinkedList<T>::AddData(T data)
{
	int index = _size;

	if (_size == 0)
	{
		_root = new Node<T>(data);
	}
	else
	{
		Node<T>* currentNode = _root;
		Node<T>* priviusNode{ nullptr };

		while (true)
		{
			if (currentNode == nullptr)
			{
				currentNode = new Node<T>(data);
				priviusNode->_next = currentNode;

				break;
			}

			priviusNode = currentNode;
			currentNode = currentNode->_next;
		}
	}

	_size += 1;

	printf("LinkedList ũ��: %d\n", _size);
}

template<typename T>
inline void LinkedList<T>::DeleteData(int idx)
{
	if (_size <= 0 || idx >= _size || idx < 0)
	{
		printf("�߸��� �ε��� ����\n");

		return;
	}

	// �� �տ� ���� ��
	if (idx == 0)
	{
		Node<T>* temp = _root->_next;
		delete _root;
		_root = temp;
	}
	else
	{
		Node<T>* current{ _root };
		Node<T>* prive{ nullptr };

		for (int i = 0; i < idx; i++)
		{
			prive = current;
			current = current->_next;
		}

		// �� �ڿ� ���� ��
		if (current->_next == nullptr)
		{
			prive->_next = nullptr;
			delete current;
		}
		// �߰��� ������
		else if (current->_next != nullptr)
		{
			prive->_next = current->_next;
			delete current;
		}
	}

	_size -= 1;
}

template<typename T>
inline void LinkedList<T>::PrintData()
{
	Node<T>* currentNode = _root;

	while (currentNode != nullptr)
	{
		std::cout << currentNode->_data << " ";

		currentNode = currentNode->_next;
	}

	printf("\n");
}

template<typename T>
inline void LinkedList<T>::PrintSize()
{
	printf("ũ��: %d\n",_size);
}

