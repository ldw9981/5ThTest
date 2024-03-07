#pragma once

template<typename T>
class Node
{
public:
	Node(T value) : m_value(value), m_NodeNext(nullptr), m_NodePre(nullptr) {}
	~Node() {}
public:

	T GetValue() { return m_value; }
	void SetValue(T value) { m_value = value; }
	
	Node<T>* GetNodeNext() { return m_NodeNext; }
	void SetNodeNext(Node<T>* node) { m_NodeNext = node; }

	Node<T>* GetnNodePre() { return m_NodePre; }
	void SetNodePre(Node<T>* node) { m_NodePre = node; }
		
private: 
	T m_value;
	Node<T>* m_NodeNext;
	Node<T>* m_NodePre;
};