#pragma once
#include <iostream>
#include<assert.h>
using namespace std;

template <typename T>
class MyList
{
	template <typename T>
	struct Node
	{
		T data;
		Node* prev = nullptr;
		Node* next = nullptr;

		Node(T arg)
			:data(arg) {};
	};


public:
	MyList();
	~MyList();

	void PushFront(const T& arg);
	void PushBack(const T& arg);
	void PopFront();
	void PopBack();
	void Clear();
	void Show();

	void Erase(const unsigned int& index);
	T Get(const unsigned int& index);

private:
	Node<T>* m_frontNode = nullptr;
	Node<T>* m_backNode = nullptr;
};

template<typename T>
inline MyList<T>::MyList()
{

}

template<typename T>
inline MyList<T>::~MyList()
{
	Clear();
}

template<typename T>
inline void MyList<T>::PushFront(const T& arg)
{
	Node<T>* n = new Node<T>(arg);

	if (m_frontNode == nullptr)
	{
		m_frontNode = n;
	}
	else
	{
		n->next = m_frontNode;
		m_frontNode->prev = n;
		m_frontNode = n;
	}
}

template<typename T>
inline void MyList<T>::PushBack(const T& arg)
{
	if (m_frontNode == nullptr)
	{
		PushFront(arg);
	}
	else if (m_backNode == nullptr)
	{
		Node<T>* n = new Node<T>(arg);
		m_backNode = n;
		m_frontNode->next = n;
		m_backNode->prev = m_frontNode;
	}
	else
	{
		Node<T>* n = new Node<T>(arg);
		m_backNode->next = n;
		n->prev = m_backNode;
		m_backNode = n;
	}
}

template<typename T>
inline void MyList<T>::PopFront()
{
	if (m_frontNode == nullptr) {
		cout << "List가 비어있어서 Pop 할 것이 없음" << endl;
		return;
	}

	Node<T>* n = m_frontNode->next;
	if (n != nullptr)	n->prev = nullptr;
	delete m_frontNode;
	m_frontNode = n;

	if (m_frontNode == m_backNode) m_backNode = nullptr;
}

template<typename T>
inline void MyList<T>::PopBack()
{
	if (m_frontNode == nullptr) {
		cout << "List가 비어있어서 Pop 할 것이 없음" << endl;
		return;
	}

	if (m_backNode == nullptr)
	{
		PopFront();
	}
	else
	{
		Node<T>* n = m_backNode->prev;
		n->next = nullptr;
		delete m_backNode;
		if (n == m_frontNode)
		{
			m_backNode = nullptr;
		}
		else
		{
			m_backNode = n;
		}
	}
}

template<typename T>
inline void MyList<T>::Clear()
{
	Node<T>* n = m_frontNode;
	while (n != nullptr)
	{
		if (n->prev != nullptr) delete n->prev;
		n = n->next;
	}
	m_frontNode = nullptr;
	m_backNode = nullptr;
}

template<typename T>
inline void MyList<T>::Show()
{
	cout << "====================================================" << endl;

	Node<T>* n = m_frontNode;
	while (n != nullptr)
	{
		cout << n->data << "   prev : " << n->prev << "   next : " << n->next << endl;
		n = n->next;
	}

	cout << "   front : " << m_frontNode << "   back : " << m_backNode << endl;

	cout << "===================================================" << endl << endl;

}

template<typename T>
inline void MyList<T>::Erase(const unsigned int& index)
{
	int i = 0;
	Node<T>* n = m_frontNode;
	if (m_frontNode == nullptr) assert(false && "리스트가 비어있음");

	while (i < index)
	{
		if (n == nullptr) assert(false && "해당 index 가 없음");
		n = n->next;
		i++;
	}
	if (n == nullptr) assert(false && "해당 index 가 없음");

	// 하나 있을 때 그걸 삭제
	if (m_frontNode == n && !m_backNode) {
		m_frontNode = nullptr;
	}

	// 두개 있을 때 그걸 삭제
	else if (m_frontNode->next == m_backNode)
	{
		if (n == m_frontNode) PopFront();
		else if (n == m_backNode) PopBack();
	}

	// 그 밖에
	else if (n->prev && n->next)
	{
		n->prev->next = n->next;
		n->next->prev = n->prev;
	}
	else if (n->prev && !n->next)
	{
		n->prev->next = nullptr;
	}
	else if (!n->prev && n->next)
	{
		n->next->prev = nullptr;
	}

	if( n) delete n;
}

template<typename T>
inline T MyList<T>::Get(const unsigned int& index)
{
	int i = 0;
	Node<T>* n = m_frontNode;
	if (m_frontNode == nullptr) assert(false && "리스트가 비어있음");

	while (i < index)
	{
		if (n == nullptr) assert(false && "해당 index 가 없음");
		n = n->next;
		i++;
	}
	if (n == nullptr) assert(false && "해당 index 가 없음");
	return n->data;
}

