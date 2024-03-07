#pragma once

template <typename T>
class Node
{
public:
	Node* prev;
	Node* next;
	T data;

	Node();
	Node(T getData);
	~Node() {};
};

template<typename T>
inline Node<T>::Node()
{
	data = 0;
	prev = nullptr;
	next = nullptr;
}

template<typename T>
inline Node<T>::Node(T getData)
{
	data = getData;
	prev = nullptr;
	next = nullptr;
}
