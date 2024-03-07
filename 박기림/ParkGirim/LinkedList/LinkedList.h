#pragma once
#include "Node.h"
#include <iostream>

template <typename T>
class LinkedList
{
public:
	LinkedList() = default;
	~LinkedList()
	{
		Node<T>* iterator = head;
		while (iterator)
		{
			Node<T>* temp = iterator->nextNode;

			delete iterator;

			iterator = temp;
		}
	}

	void InsertFront(T data)
	{
		// 첫 데이터 삽입인 경우
		if (!head)
		{
			head = new Node<T>;

			head->data = data;
			head->prevNode = nullptr;
			head->nextNode = nullptr;
			tail = head;

			return;
		}

		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		newNode->prevNode = nullptr;
		newNode->nextNode = head;

		head->prevNode = newNode;
		head = newNode;
	}

	void InsertBack(T data)
	{
		// 첫 데이터 삽입인 경우
		if (!head)
		{
			head = new Node<T>;

			head->data = data;
			head->prevNode = nullptr;
			head->nextNode = nullptr;
			tail = head;

			return;
		}

		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		newNode->prevNode = tail;
		newNode->nextNode = nullptr;

		tail->nextNode = newNode;
		tail = newNode;
	}

	// 해당 데이터가 있는 첫 번째 노드 반환
	Node<T>* FindNode(T data)
	{
		Node<T>* iterator = head;
		while (iterator)
		{
			if (iterator->data == data)
			{
				return iterator;
			}

			iterator = iterator->nextNode;
		}

		return nullptr;
	}

	void DeleteNode(T data)
	{
		Node<T>* delNode = FindNode(data);

		DeleteNode(delNode);
	}

	void DeleteNode(Node<T>* node)
	{
		if (head == tail)
		{
			head = nullptr;
			tail = nullptr;

			delete node;
			return;
		}

		if (node == head)
		{
			node->nextNode->prevNode = nullptr;
			head = node->nextNode;

			delete node;
			return;
		}

		if (node == tail)
		{
			node->prevNode->nextNode = nullptr;
			tail = node->prevNode;

			delete node;
			return;
		}

		node->prevNode->nextNode = node->nextNode;
		node->nextNode->prevNode = node->prevNode;

		delete node;
	}

	void PrintAll()
	{
		Node<T>* iterator = head;
		while (iterator)
		{
			std::cout << iterator->data << " ";
			iterator = iterator->nextNode;
		}

		std::cout << '\n';
	}

	Node<T>* head;
	Node<T>* tail;
};

