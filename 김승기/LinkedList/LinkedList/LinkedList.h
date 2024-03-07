#pragma once
template<typename T>
struct Node
{
	T data;
	Node* prev;
	Node* next;
};

template<typename T>
class LinkedList
{
	Node<T>* Head = nullptr;
	Node<T>* Tail = nullptr;
	
public:
	void Push_Back(T data);
	void Pop_Back();
	void Erase(T data);
	void Clear();
};


template<typename T>
inline void LinkedList<T>::Push_Back(T data)
{
	Node<T>* node = new Node<T>();
	node->prev = nullptr;
	node->data = data;
	node->next = nullptr;

	if (nullptr == Head)
	{
		Head = node;
		Tail = node;
	}
	else
	{
		Tail->next = node;
		node->prev = Tail;
		Tail = node;
	}
}

template<typename T>
inline void LinkedList<T>::Pop_Back()
{
	Node<T>* node = Tail;
	node->prev->next = nullptr;
	Tail= node->prev;
	delete node;
	
}

template<typename T>
inline void LinkedList<T>::Erase(T data)
{
	Node<T>* node = Head;
	Node<T>* temp = node->next;
	while (node != nullptr)
	{
		temp = node->next;
		if (node->data == data)
		{
			if (node == Head)
			{
				node->next->prev = nullptr;
				Head = node->next;
			}
			else if (node == Tail)
			{
				node->prev->next = nullptr;
				Tail = node->prev;
			}
			else
			{
				node->prev->next = node->next;
				node->next->prev = node->prev;
			}
			delete node;
			node = nullptr;
		}
		node = temp;
	}
}

template<typename T>
inline void LinkedList<T>::Clear()
{
	Node<T>* node = Head;
	Node<T>* temp = Head->next;
	while (node != nullptr)
	{
		temp = node->next;
		delete node;
		node = nullptr;
		node = temp;
	}
	Head = nullptr;
	Tail = nullptr;
}

