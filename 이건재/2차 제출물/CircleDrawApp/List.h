#pragma once

template <typename T>
class Node
{
public:
	Node(T data)
		: m_Data(data)
		, NextNode(nullptr)
		, PrevNode(nullptr)
	{}
	~Node() {}

public:
	T m_Data;
	Node* NextNode;
	Node* PrevNode;
};

template <typename T>
class List
{
public:
	List()
		: NodeSize(0)
		, HeadNode(nullptr)
		, TailNode(nullptr)
	{}
	~List() {}

public:
	int GetSize() { return NodeSize; }

public:
	void PushFront(T data);
	T Front();
	T Back();
	void PopFront();
	Node<T>* Find(const T& data);
	Node<T>* Find(int number);
	void eraser(Node<T>* node);

public:
	Node<T>* HeadNode;
	Node<T>* TailNode;
	int NodeSize;
};

template<typename T>
inline void List<T>::PushFront(T data)
{
	NodeSize++;

	if (HeadNode == nullptr)
	{
		Node<T>* node = new Node<T>(data);
		HeadNode = node;
		TailNode = node;
		node->NextNode = TailNode;
		node->PrevNode = HeadNode;

		return;
	}

	Node<T>* tempNode = HeadNode;
	HeadNode = new Node<T>(data);
	HeadNode->NextNode = tempNode;
	HeadNode->PrevNode = TailNode;
	tempNode->PrevNode = HeadNode;
}

template<typename T>
inline T List<T>::Front()
{
	return HeadNode->m_Data;
}

template<typename T>
inline T List<T>::Back()
{
	return TailNode->m_Data;
}

template<typename T>
inline void List<T>::PopFront()
{
	if (HeadNode == nullptr)
	{
		return;
	}
	if (HeadNode == TailNode)
	{
		delete HeadNode;
		HeadNode = nullptr;
		TailNode = nullptr;
		NodeSize--;
		return;
	}

	Node<T>* tempNode = HeadNode->NextNode;
	delete HeadNode;
	tempNode->PrevNode = nullptr;
	HeadNode = tempNode;
	NodeSize--;
}

template<typename T>
inline Node<T>* List<T>::Find(const T& data)
{
	if (HeadNode == nullptr)
	{
		return nullptr;
	}

	Node<T>* CurrentNode = HeadNode;

	while (true)
	{
		if (CurrentNode->m_Data == data)
		{
			return CurrentNode;
		}

		if (CurrentNode == TailNode)
		{
			return nullptr;
		}

		CurrentNode = CurrentNode->NextNode;
	}

	return CurrentNode;
}

template<typename T>
inline Node<T>* List<T>::Find(int number)
{
	Node<T>* CurrentNode = HeadNode;

	for (int i = 0; i < number; i++)
	{
		CurrentNode = CurrentNode->NextNode;
	}

	return CurrentNode;
}

template<typename T>
inline void List<T>::eraser(Node<T>* node)
{
	if (HeadNode == node)
	{
		Node<T>* tempNode = HeadNode->NextNode;
		HeadNode->PrevNode = TailNode;
		delete HeadNode;
		HeadNode = tempNode;
		NodeSize--;

		return;
	}
	else if (TailNode == node)
	{
		Node<T>* tempNode = TailNode->PrevNode;
		tempNode->NextNode = HeadNode;
		delete TailNode;
		TailNode = tempNode;
		NodeSize--;

		return;
	}


	Node<T>* CurrentNode = HeadNode->NextNode;

	while (true)
	{
		if (CurrentNode == node)
		{
			Node<T>* tempNode = CurrentNode->NextNode;
			tempNode->PrevNode = CurrentNode->PrevNode;
			tempNode = CurrentNode->PrevNode;
			tempNode->NextNode = CurrentNode->NextNode;

			delete CurrentNode;
			NodeSize--;
			return;
		}
		else
		{
			CurrentNode = CurrentNode->NextNode;

			if (CurrentNode->NextNode == TailNode)
			{
				return;
			}
		}
	}
}