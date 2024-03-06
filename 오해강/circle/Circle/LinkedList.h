#pragma once
#include "Node.h"
#include <iostream>

template <typename T>
class List
{
	// ����Ʈ�� ���ұ�? 
	// ����, �߰�, ������ �ؾ��Ѵ�
public:
	List() {};
	~List() {};
	// ����Ʈ�� ����ϱ����� �Լ�
	void Add(Node<T>* _node);		// ����Ʈ �Ĺ濡 ����߰� (tail ����)
	void AddFront(Node<T>* _node);	// ����Ʈ ���濡 ����߰� (head ����)

	void Insert(unsigned int _num, Node<T>* _node);	
	
	void Delete(unsigned int _num);

	Node<T>* GetNode(unsigned int _num);

	// ����� ���� Get/Set
public:
	Node<T>* Start() const { return m_head; };
	Node<T>* End() const { return m_tail; };
	unsigned int Size() const { return m_size; };

public:
	Node<T>* operator [](int _num)
	{

	}

private:
	// ���۰� ���� �˰� ����
	Node<T>* m_head = nullptr;
	Node<T>* m_tail = nullptr;
	unsigned int m_size = 0;
};

// �Ĺ� ��带 �߰��մϴ�.

template<typename T>
inline void List<T>::Add(Node<T>* _node)
{
	std::cout << "�Ĺ濡 �߰��մϴ�" << std::endl;
	// 1. �ƹ��͵� ���ٸ� Head�� ���Ĺ��̴�
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
	std::cout << "���濡 �߰��մϴ�" << std::endl;
	// 1. �ƹ��͵� ���ٸ� Head�� �������̴�
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

	std::cout << "�����մϴ�" << std::endl;
	// ����� 0�̸� �ƹ��͵� ����
	if (m_size == 0)
	{
		return;
	}
	// ������� ũ�� ������ �� ����.
	if (m_size + 1 < _num)
	{
		return;
	}

	// 0�� ������ ��� �տ� �ִ°�
	if (_num == 0)
	{
		_node->nextNode = m_head;
		m_head = _node;
		m_size++;
	}
	// ���ڰ� 1�ϰ�� �� ������ �ִ� ���̴�
	// �׷��⶧���� �����������Ѵ�.
	else if (_num == 1)
	{
		m_head->nextNode->nextNode = m_head->nextNode;
		m_head->nextNode = _node;
		m_size++;
	}
	// ���ڰ� 1�� �ƴ� ���� ���� ��忡�� ������ �Ѱ��ش�.
	else
	{
		m_head->InsertNode(_num , _node);
		m_size++;

	}

}

template<typename T>
inline void List<T>::Delete(unsigned int _num)
{
	std::cout << "�����մϴ�" << std::endl;
	// ������� ū�� ã�� �� ����.
	if (m_size == 0)
	{
		return;
	}
	if (m_size + 1 < _num)
	{
		return;
	}
	// ��带 ������ ���
	if (_num == 0)
	{
		// ��带 �����ϰ�
		delete m_head;
		// �ؽ�Ʈ ��带 �ִ´�
		m_head = m_head->nextNode;
		m_size--;
	}
	// 1�� ��� ������带 ����� ���ڸ��� �������� ��带 ����
	else if (_num == 1)
	{
		Node<T>* temp = m_head->nextNode;
		m_head->nextNode = m_head->nextNode->nextNode;
		delete temp;
		m_size--;
	}
	// �ƹ��͵��ƴϸ� �������� �ѱ��.
	else
	{
		m_head->DeleteNode(_num - 1);
		m_size--;
	}

}

template<typename T>
inline 	Node<T>* List<T>::GetNode(unsigned int _num)
{
	// ������� ū�� ã�� �� ����.
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
