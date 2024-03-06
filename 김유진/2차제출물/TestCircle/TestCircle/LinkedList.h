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

	// 인자로 전달받은 데이터를 가진 노드를 맨 뒤에 추가
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

	// 인자로 전달받은 데이터를 가진 노드를 추가
	void Insert(int index, T data)
	{
		if (size < index)
		{
			std::cout << "error: 리스트의 크기보다 인덱스가 큽니다.\n";
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

	// 인자로 전달받은 데이터를 가진 노드 삭제
	void DeleteData(T data)
	{
		Node<T>* preNode = nullptr;
		Node<T>* curNode = start;
		while (curNode->next != nullptr)
		{
			if (curNode->data == data)
			{
				// 첫 번째 노드일 경우 예외처리
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

		std::cout << "error: 입력한 데이터가 존재하지 않습니다.\n";
	}

	// 해당 인덱스의 노드 삭제
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

			// 시작과 끝이 아닐때
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
			std::cout << "error: 리스트의 사이즈보다 큰 숫자를 입력했습니다.\n";
		}
	}

	// 해당 인덱스에 해당하는 데이터 반환
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
			std::cout << "error: 리스트의 사이즈보다 큰 숫자를 입력했습니다.\n";
		}
	}

	// 사이즈 반환
	int GetSize() const
	{
		return size;
	}

	// 모든 데이터 출력
	void Show()
	{
		if (size == 0)
		{
			std::cout << "리스트가 비어있습니다.\n";
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