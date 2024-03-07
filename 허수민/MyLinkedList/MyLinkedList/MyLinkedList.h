#pragma once
#include <iostream>

template <typename T>
class MyLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next = nullptr;
		Node* prev = nullptr;
	};

public:
	~MyLinkedList();

public:
	void Add(T data); // ����Ʈ�� �� ���� ��� �߰�
	void DeleteByData(T data);	// Ư�� �����͸� ���� ��� ����
	//void DeleteKthNode(int k);	// k��° ��� ����
	void DeleteAll();	// ��� ��ü ����

	int GetNodeCount() { return count; }

	void PrintAll();	// �ܼ� â�� ��� ���

private:
	Node* head;
	Node* tail;
	unsigned int count = 0;
};

template<typename T>
inline MyLinkedList<T>::~MyLinkedList()
{
	DeleteAll();
}

template<typename T>
inline void MyLinkedList<T>::Add(T data)
{
	Node* newNode = new Node;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	newNode->data = data;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
		
		count++;
		return;
	}

	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;

	count++;
}

template<typename T>
inline void MyLinkedList<T>::DeleteByData(T data)
{
	if (head == nullptr)
		return;

	if (head == tail)
	{
		if (head->data == data)
		{
			delete head;
			head = nullptr;
			tail = nullptr;

			count--;
			return;
		}
	}

	Node* curNode = head;
	Node* prevNode = curNode;

	while (curNode->next != nullptr)
	{
		//curNode = head;
		prevNode = curNode;

		// ��ü ����Ʈ�� ��ȸ�ϸ� Ư�� �����͸� ���� ��� ����
		if (curNode->data == data)
		{
			prevNode->prev->next = prevNode->next;
			prevNode->next->prev = prevNode->prev;

			// �����ϰ� ����
			delete curNode;
			count--;
			return;
		}

		curNode = curNode->next;
	}

	std::cout << "����!! ������ ��带 ã�� ���Ͽ����ϴ�." << std::endl;
}


template<typename T>
inline void MyLinkedList<T>::DeleteAll()
{
	if (head == nullptr)
		return;

	if (head == tail)	// ��尡 �ϳ��� ������ ���
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}

	Node* delNode = head;

	while(head->next != nullptr)
	{
		delNode = head;
		head = head->next;
		delete delNode;
	}

	head = nullptr;
	tail = nullptr;
	count = 0;
}

template<typename T>
inline void MyLinkedList<T>::PrintAll()
{
	if (head == nullptr)
		return;

	Node* curNode = head;

	while (curNode->next != nullptr)
	{
		std::cout << curNode->data << " >> ";
		curNode = curNode->next;
	}

	std::cout << curNode->data << std::endl;
}