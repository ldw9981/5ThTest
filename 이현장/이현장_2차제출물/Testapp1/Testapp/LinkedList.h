#pragma once
#include <iostream>
#include "Node.h"

template<typename T>
class LinkedList 
{
public:
	LinkedList() : m_HeadNode(nullptr), m_TailNode(nullptr) {}
	~LinkedList() {}

public:
	void Push_Front(T value);
	void Pop_Front();
		
	void Push_Back(T value);
	void Pop_Back();

	Node<T>* Front();
	Node<T>* Back();

	int Size();

	void Insert(int index, T value);

	void Clear();

	void PrintAll();
private:
	Node<T>* m_HeadNode;
	Node<T>* m_TailNode;
};

template<typename T>
inline void LinkedList<T>::Push_Front(T value)
{
	Node<T>* newnode = new Node<T>(value);
	if (m_HeadNode == nullptr)
	{
		m_HeadNode = newnode;
		m_TailNode = newnode;
	}
	else
	{
		Node<T>* tempHead = m_HeadNode;
		tempHead->SetNodePre(newnode);
		newnode->SetNodeNext(tempHead);
		m_HeadNode = newnode;
	}
}

template<typename T>
inline void LinkedList<T>::Pop_Front()
{
	if (m_HeadNode == nullptr)
	{
		return;
	}
	else
	{
		Node<T>* tempheadnode = m_HeadNode;
		m_HeadNode = tempheadnode->GetNodeNext();
		
		tempheadnode->SetValue(0);
		tempheadnode->SetNodeNext(nullptr);
		delete tempheadnode;
	}
}

template<typename T>
inline void LinkedList<T>::Push_Back(T value)
{
	Node<T>* newnode = new Node<T>(value);
	
	if(m_HeadNode ==nullptr)	// 첫번째 노드
	{
		m_HeadNode = newnode;
		m_TailNode = newnode;
	}
	else	// 두번째 노드
	{
		Node<T>* tempNode = m_HeadNode;

		while (tempNode->GetNodeNext() != nullptr)
		{
			tempNode = tempNode->GetNodeNext();
		}
		
		tempNode->SetNodeNext(newnode);
		newnode->SetNodePre(tempNode);

		m_TailNode = newnode;
	}
}

template<typename T>
inline void LinkedList<T>::Pop_Back()
{
	if (m_HeadNode == nullptr)
	{
		return;
	}
	else
	{
		Node<T>* tempnode = m_HeadNode;
		while (tempnode->GetNodeNext() != nullptr)
		{
			tempnode = tempnode->GetNodeNext();
		}
		
		m_TailNode = tempnode->GetnNodePre();
		m_TailNode->SetNodeNext(nullptr);
		
		tempnode->SetValue(0);
		tempnode->SetNodePre(nullptr);
		delete tempnode;
	}
}

template<typename T>
inline Node<T>* LinkedList<T>::Front()
{
	return m_HeadNode;
}

template<typename T>
inline Node<T>* LinkedList<T>::Back()
{
	return m_TailNode;
}

template<typename T>
inline int LinkedList<T>::Size()
{
	int count = 0;
	Node<T>* tempnode = m_HeadNode;

	while(tempnode != nullptr)
	{
		count++;
		tempnode = tempnode->GetNodeNext();
	}

	return count;
}

template<typename T>
inline void LinkedList<T>::Insert(int index, T value)
{
	Node<T>* newnode = new Node<T>(value);
	if (m_HeadNode == nullptr)
	{
		m_HeadNode = newnode;
		m_TailNode = newnode;
	}

	if (index <= 0)
	{
		m_HeadNode->SetNodePre(newnode);
		newnode->SetNodeNext(m_HeadNode);
		
		m_HeadNode = newnode;
	}
	else if(index >= Size())
	{
		Node<T>* tempnode = m_HeadNode;
		while (tempnode->GetNodeNext() != nullptr)
		{
			tempnode = tempnode->GetNodeNext();
		}
		
		tempnode->SetNodeNext(newnode);
		newnode->SetNodePre(tempnode);

		m_TailNode = newnode;
	}
	else
	{
		Node<T>* tempnode = m_HeadNode;
		for (int i = 0; i < index; i++)
		{
			tempnode = tempnode->GetNodeNext();
		}
		
		Node<T>* tempnodepre = tempnode->GetnNodePre();
		
		tempnodepre->SetNodeNext(newnode);
		newnode->SetNodePre(tempnodepre);
		
		tempnode->SetNodePre(newnode);
		newnode->SetNodeNext(tempnode);
	}
}

template<typename T>
inline void LinkedList<T>::Clear()
{
	
	for (int i = 0; i < Size(); i++)
	{
		Node<T>* tempnode = m_HeadNode;
		tempnode->SetValue(0);
		tempnode->SetNodePre(nullptr);
		m_HeadNode = tempnode->GetNodeNext();
		
		delete tempnode;
	}
	m_HeadNode = nullptr;
	m_TailNode = nullptr;
}

template<typename T>
inline void LinkedList<T>::PrintAll()
{
	if (m_HeadNode == nullptr)
	{
		std::cout << "비어있습니다." << std::endl;
	}
	Node<T>* tempnode = m_HeadNode;
	for (int i = 0; i < Size(); i++)
	{
		std::cout << tempnode->GetValue() <<  " ";
		tempnode = tempnode->GetNodeNext();
	}
}
