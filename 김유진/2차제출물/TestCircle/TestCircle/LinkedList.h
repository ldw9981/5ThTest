#pragma once
#include <iostream>

template<typename T>
struct Node
{
	T data;
	Node<T>* next;
};

template<typename T>
class LinkedList
{
public:
	LinkedList()
	{
		start = nullptr;
		size = 0;
	}
	~LinkedList()
	{
		if (size != 0)
		{
			Node<T>* curNode = start;
			Node<T>* nextNode = nullptr;
			while (curNode->next != nullptr)
			{
				nextNode = curNode->next;
				delete curNode;
				curNode = nextNode;
			}
		}
	}

	// ���ڷ� ���޹��� �����͸� ���� ��带 �� �ڿ� �߰�
	void InsertBack(T data)
	{
		if (size == 0)
		{
			start = new Node<T>;
			start->data = data;
			start->next = nullptr;
		}
		else
		{
			Node<T>* curNode = start;
			while (curNode->next != nullptr)
			{
				curNode = curNode->next;
			}

			Node<T>* newNode = new Node<T>;
			newNode->data = data;
			newNode->next = nullptr;

			curNode->next = newNode;
		}

		size++;
	}

	// ���ڷ� ���޹��� �����͸� ���� ��带 �߰�
	void Insert(int index, T data)
	{
		if (size < index)
		{
			std::cout << "error: ����Ʈ�� ũ�⺸�� �ε����� Ů�ϴ�.\n";
		}

		if (size == 0)
		{
			start = new Node<T>;
			start->data = data;
			start->next = nullptr;
		}
		else
		{
			int count = index;

			Node<T>* preNode = nullptr;
			Node<T>* curNode = start;
			while (count > 0)
			{
				preNode = curNode;
				curNode = curNode->next;
				count--;
			}

			Node<T>* newNode = new Node<T>;
			newNode->data = data;
			newNode->next = nullptr;

			if (index != 0)
			{
				preNode->next = newNode;
			}
			else
			{
				start = newNode;
			}
			newNode->next = curNode;
		}

		size++;
	}

	// ���ڷ� ���޹��� �����͸� ���� ��� ����
	void DeleteData(T data)
	{
		Node<T>* preNode = nullptr;
		Node<T>* curNode = start;
		while (curNode->next != nullptr)
		{
			if (curNode->data == data)
			{
				// ù ��° ����� ��� ����ó��
				if (preNode == nullptr)
				{
					start = curNode->next;
				}
				else
				{
					preNode->next = curNode->next;
				}

				delete curNode;
				size--;
				return;
			}
			preNode = curNode;
			curNode = curNode->next;
		}

		if (curNode->data == data)
		{
			if (size > 1)
			{
				preNode->next = curNode->next;
			}

			delete curNode;
			size--;
			return;
		}

		std::cout << "error: �Է��� �����Ͱ� �������� �ʽ��ϴ�.\n";
	}

	// �ش� �ε����� ��� ����
	void Delete(int index)
	{
		int count = index;

		Node<T>* preNode = nullptr;
		Node<T>* curNode = start;

		if (size > index)
		{
			while (count > 0)
			{
				preNode = curNode;
				curNode = curNode->next;

				count--;
			}

			// ���۰� ���� �ƴҶ�
			if (preNode != nullptr)
			{
				if (curNode != nullptr)
				{
					preNode->next = curNode->next;
				}
			}
			else
			{
				start = curNode->next;
			}
			delete curNode;
			size--;
		}
		else
		{
			std::cout << "error: ����Ʈ�� ������� ū ���ڸ� �Է��߽��ϴ�.\n";
		}
	}

	// �ش� �ε����� �ش��ϴ� ������ ��ȯ
	T Search(int index)
	{
		int count = index;

		Node<T>* curNode = start;

		if (size > index)
		{
			while (count > 0)
			{
				curNode = curNode->next;
				count--;
			}

			return curNode->data;
		}
		else
		{
			std::cout << "error: ����Ʈ�� ������� ū ���ڸ� �Է��߽��ϴ�.\n";
		}
	}

	// ������ ��ȯ
	int GetSize() const
	{
		return size;
	}

	// ��� ������ ���
	void Show()
	{
		if (size == 0)
		{
			std::cout << "����Ʈ�� ����ֽ��ϴ�.\n";
			return;
		}

		Node<T>* curNode = start;
		while (curNode->next != nullptr)
		{
			std::cout << curNode->data << " ";
			curNode = curNode->next;
		}
		std::cout << curNode->data << " ";

		std::cout << "\n";
	}

private:
	Node<T>* start;
	int size;
};