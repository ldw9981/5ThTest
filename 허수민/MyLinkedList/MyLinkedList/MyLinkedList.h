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
	void Add(T data); // 리스트의 맨 끝에 노드 추가
	void DeleteByData(T data);	// 특정 데이터를 가진 노드 삭제
	//void DeleteKthNode(int k);	// k번째 노드 삭제
	void DeleteAll();	// 노드 전체 삭제

	int GetNodeCount() { return count; }

	void PrintAll();	// 콘솔 창에 노드 출력

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

		// 전체 리스트를 순회하며 특정 데이터를 가진 노드 삭제
		if (curNode->data == data)
		{
			prevNode->prev->next = prevNode->next;
			prevNode->next->prev = prevNode->prev;

			// 삭제하고 종료
			delete curNode;
			count--;
			return;
		}

		curNode = curNode->next;
	}

	std::cout << "에러!! 삭제할 노드를 찾지 못하였습니다." << std::endl;
}


template<typename T>
inline void MyLinkedList<T>::DeleteAll()
{
	if (head == nullptr)
		return;

	if (head == tail)	// 노드가 하나만 존재할 경우
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