#pragma once
#include <iostream>

template <typename T>
struct Node
{
	Node(T& _data)
	{
		data = _data;
		prev = nullptr;
		next = nullptr;
	}

	T data;
	Node<T>* prev;
	Node<T>* next;
};

template <typename T>
class LinkedList
{
public:
	void PushBack(T& _data);
	void PopBack();
	void PushFront(T& _data);
	void PopFront();
	void Remove(T _data);
	void PrintAll();
	void Clear();


public:
	LinkedList();
	~LinkedList();

private:
	Node<T>* m_Head;
	Node<T>* m_Tail;
	size_t m_Size;
};

template<typename T>
inline void LinkedList<T>::PushBack(T& _data)
{
	if (m_Head == nullptr)
	{
		Node<T>* newNode = new Node<T>(_data);
		m_Head = newNode;
		m_Tail = newNode;
	}
	else
	{
		Node<T>* newNode = new Node<T>(_data);
		newNode->prev = m_Tail;
		m_Tail->next = newNode;
		m_Tail = newNode;
	}
	++m_Size;
}

template<typename T>
inline void LinkedList<T>::PopBack()
{
	if (m_Head == nullptr)
	{
		std::cout << "컨테이너가 비었습니다." << std::endl;
		return;
	}
	else
	{
		Node<T>* tail = m_Tail;
		m_Tail->prev->next = nullptr;
		m_Tail = m_Tail->prev;
		delete tail;
		--m_Size;
	}
}

template<typename T>
inline void LinkedList<T>::PushFront(T& _data)
{
	if (m_Head == nullptr)
	{
		Node<T>* newNode = new Node<T>(_data);
		m_Head = newNode;
		m_Tail = newNode;
	}
	else
	{
		Node<T>* newNode = new Node<T>(_data);
		newNode->next = m_Head;
		m_Head->prev = newNode;
		m_Head = newNode;
	}
	++m_Size;
}

template<typename T>
inline void LinkedList<T>::PopFront()
{
	if (m_Head == nullptr)
	{
		std::cout << "컨테이너가 비었습니다." << std::endl;
		return;
	}
	else
	{
		Node<T>* haed = m_Head;
		m_Head->next->prev = nullptr;
		m_Head = m_Head->next;
		delete haed;
		--m_Size;
	}
}

template<typename T>
inline void LinkedList<T>::Remove(T _data)
{
	Node<T>* nodepPtr = m_Head;
	while (nodepPtr)
	{
		if (nodepPtr->data == _data)
		{
			if (nodepPtr == m_Head)
			{
				m_Head = nodepPtr->next;
				m_Head->prev == nullptr;
				delete nodepPtr;
				nodepPtr = m_Head->next;
				--m_Size;
			}
			else if (nodepPtr == m_Tail)
			{
				m_Tail = nodepPtr->prev;
				m_Tail->next = nullptr;
				delete nodepPtr;
				--m_Size;
				break;
			}
			else
			{
				nodepPtr->prev->next = nodepPtr->next;
				nodepPtr->next->prev = nodepPtr->prev;

				Node<T>* nextNodePtr = nodepPtr->next;
				delete nodepPtr;
				nodepPtr = nextNodePtr;
				--m_Size;
			}
		}
		else
		{
			nodepPtr = nodepPtr->next;
		}
	}
}

template<typename T>
inline void LinkedList<T>::PrintAll()
{
	Node<T>* nodepPtr = m_Head;
	while (nodepPtr)
	{
		std::cout << nodepPtr->data << " ";
		nodepPtr = nodepPtr->next;
	}
	std::cout << std::endl;
}

template<typename T>
inline void LinkedList<T>::Clear()
{
	while (m_Head)
	{
		Node<T>* nodepPtr = m_Head;
		m_Head = nodepPtr->next;
		delete nodepPtr;
		--m_Size;
	}
}

template<typename T>
inline LinkedList<T>::LinkedList()
	: m_Head(nullptr)
	, m_Tail(nullptr)
	, m_Size(0)
{
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	Clear();
}
