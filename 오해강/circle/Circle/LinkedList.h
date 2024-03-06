#pragma once
#include "Node.h"
#include <iostream>

template <typename T>
class List
{
	// 리스트로 뭘할까? 
	// 생성, 추가, 삭제를 해야한다
public:
	List() {};
	~List() {};
	// 리스트를 사용하기위한 함수
	void Add(Node<T>* _node);		// 리스트 후방에 노드추가 (tail 변경)
	void AddFront(Node<T>* _node);	// 리스트 전방에 노드추가 (head 변경)

	void Insert(unsigned int _num, Node<T>* _node);	
	
	void Delete(unsigned int _num);

	Node<T>* GetNode(unsigned int _num);

	// 멤버의 대한 Get/Set
public:
	Node<T>* Start() const { return m_head; };
	Node<T>* End() const { return m_tail; };
	unsigned int Size() const { return m_size; };

public:
	Node<T>* operator [](int _num)
	{

	}

private:
	// 시작과 끝은 알고 있자
	Node<T>* m_head = nullptr;
	Node<T>* m_tail = nullptr;
	unsigned int m_size = 0;
};

// 후방 노드를 추가합니다.

template<typename T>
inline void List<T>::Add(Node<T>* _node)
{
	std::cout << "후방에 추가합니다" << std::endl;
	// 1. 아무것도 없다면 Head가 최후방이다
	if (m_head == nullptr)
	{
		m_head = _node;
		//m_tail = _node;
		m_size++;
			return;
	}
	else if (m_size == 1 && m_head->nextNode == nullptr)
	{
		m_head->nextNode = _node;
		m_tail = _node;
		m_size++;
	}
	else
	{
		m_tail->nextNode = _node;
		m_tail = _node;
		m_size++;
	}
}

template<typename T>
inline void List<T>::AddFront(Node<T>* _node)
{
	std::cout << "전방에 추가합니다" << std::endl;
	// 1. 아무것도 없다면 Head가 최전방이다
	if (m_head == nullptr)
	{
		m_head = _node;
		m_tail = _node;
		m_size += 1;
		return;
	}

	_node->nextNode = m_head;
	m_head = _node;
	m_size += 1;
}

template<typename T>
inline void List<T>::Insert(unsigned int _num, Node<T>* _node)
{

	std::cout << "삽입합니다" << std::endl;
	// 사이즈가 0이면 아무것도 안함
	if (m_size == 0)
	{
		return;
	}
	// 사이즈보다 크면 삽입할 수 없다.
	if (m_size + 1 < _num)
	{
		return;
	}

	// 0번 삽입의 경우 앞에 넣는것
	if (_num == 0)
	{
		_node->nextNode = m_head;
		m_head = _node;
		m_size++;
	}
	// 숫자가 1일경우 내 다음에 넣는 것이다
	// 그렇기때문에 삽입을진행한다.
	else if (_num == 1)
	{
		m_head->nextNode->nextNode = m_head->nextNode;
		m_head->nextNode = _node;
		m_size++;
	}
	// 숫자가 1이 아닌 경우는 다음 노드에게 업무를 넘겨준다.
	else
	{
		m_head->InsertNode(_num , _node);
		m_size++;

	}

}

template<typename T>
inline void List<T>::Delete(unsigned int _num)
{
	std::cout << "삭제합니다" << std::endl;
	// 사이즈보다 큰건 찾을 수 없다.
	if (m_size == 0)
	{
		return;
	}
	if (m_size + 1 < _num)
	{
		return;
	}
	// 헤드를 삭제할 경우
	if (_num == 0)
	{
		// 헤드를 삭제하고
		delete m_head;
		// 넥스트 노드를 넣는다
		m_head = m_head->nextNode;
		m_size--;
	}
	// 1일 경우 다음노드를 지우고 그자리에 다음다음 노드를 넣자
	else if (_num == 1)
	{
		Node<T>* temp = m_head->nextNode;
		m_head->nextNode = m_head->nextNode->nextNode;
		delete temp;
		m_size--;
	}
	// 아무것도아니면 다음노드로 넘긴다.
	else
	{
		m_head->DeleteNode(_num - 1);
		m_size--;
	}

}

template<typename T>
inline 	Node<T>* List<T>::GetNode(unsigned int _num)
{
	// 사이즈보다 큰건 찾을 수 없다.
	if (m_size == 0)
	{
		return nullptr;
	}
	if (m_size + 1 < _num)
	{
		return nullptr;
	}

	return m_head->GetNode(_num);

}
