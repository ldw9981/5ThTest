#pragma once

#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
};

template <typename T>
class Linkedlist
{
public:
	~Linkedlist();

	void Append(T data);			// ����Ʈ �� �κп� ��� �߰�
	void Deppend(T data);			// ����Ʈ ù �κп� ��� �߰�
	void PopEnd();					// ����Ʈ �� �κ� ��� ����
	void PopFront();				// ����Ʈ ù �κ� ��� ����
	int Size() { return size; }		// ����Ʈ ������ ��ȯ
	void Show();					// ��� ��� ������ ���

private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int size = 0;
};

template<typename T>
Linkedlist<T>::~Linkedlist()
{
	Node<T>* temp1 = head;
	Node<T>* temp2 = temp1;

	std::cout << " �ѤѤѤ� �Ҹ��� �ѤѤѤ� " << std::endl;

	while (temp2 != nullptr)
	{
		temp2 = temp1->next;
		std::cout << temp1->data << " ����" << std::endl;
		delete temp1;
		temp1 = temp2;
		--size;
	}

	head = nullptr;
	tail = nullptr;
}

template<typename T>
void Linkedlist<T>::Append(T data)
{
	Node<T>* temp = new Node<T>();
	temp->data = data;

	if (head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}

	temp->next = nullptr;
	++size;
}

template<typename T>
void Linkedlist<T>::Show()
{
	Node<T>* temp = head;

	std::cout << std::endl;
	std::cout << "�ѤѤѤѤ� Show �ѤѤѤѤ�" << std::endl;
	std::cout << "size : " << Size() << std::endl;

	if (temp == nullptr)
	{
		std::cout << "��尡 �������� �ʽ��ϴ�." << std::endl;
		return;
	}

	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}

	std::cout << std::endl;
	std::cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << std::endl;
	std::cout << std::endl;
}

template<typename T>
void Linkedlist<T>::Deppend(T data)
{
	Node<T>* temp = new Node<T>();
	temp->data = data;

	if (head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		head->next = temp;
		head = temp;
	}

	temp->next = nullptr;
	++size;
}

template<typename T>
void Linkedlist<T>::PopEnd()
{
	Node<T>* temp = head;
	Node<T>* newTail = nullptr;

	if (tail == nullptr)
	{
		std::cout << "��尡 �������� �ʽ��ϴ�." << std::endl;
		return;
	}

	while (temp->next != nullptr)
	{
		newTail = temp;
		temp = temp->next;
	}

	std::cout << temp->data << " PopEnd" << std::endl;

	delete temp;
	newTail->next = nullptr;
	tail = newTail;
	--size;
}

template<typename T>
void Linkedlist<T>::PopFront()
{
	Node<T>* temp = head;

	if (head == nullptr)
	{
		std::cout << "��尡 �������� �ʽ��ϴ�." << std::endl;
		return;
	}

	head = head->next;
	std::cout << temp->data << " PopFront" << std::endl;
	delete temp;
	--size;
}
