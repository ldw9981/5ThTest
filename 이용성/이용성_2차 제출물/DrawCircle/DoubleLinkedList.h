#pragma once
#include <iostream>

template<typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList() {};
	~DoubleLinkedList() {};

	struct Node
	{
		T data;
		Node* preNode;
		Node* nextNode;
	};

	// 2������ �ʿ��� �� ����, ������ �ش� �κ��� ���� �ؾ� �Ǵ� ã�°� ������ ������ �ǰڴ�.
	// ����, ����, ã��, ���
	void PushBack(T _data);
	void Remove(Node* _node);
	struct DoubleLinkedList<T>::Node* Find(T _data);
	void Print();

private:
	Node* headNode;
	Node* tailNode;		
};

template<typename T>
inline void DoubleLinkedList<T>::PushBack(T _data)
{
	// head Node�� ��� �ִٸ� ����
	if (headNode == nullptr)
	{
		DoubleLinkedList::Node* tempNode = new DoubleLinkedList::Node();

		tempNode->data = _data;
		tempNode->preNode = nullptr;
		tempNode->nextNode = nullptr;
		headNode = tempNode;
		tailNode = tempNode;
	}
	else
	{
		DoubleLinkedList::Node* tempNode = new DoubleLinkedList::Node();
		
		tempNode->data = _data;
		tempNode->preNode = tailNode;
		tempNode->nextNode = nullptr;
		tailNode->nextNode = tempNode;
		tailNode = tempNode;
	}
}

template<typename T>
inline void DoubleLinkedList<T>::Remove(Node* _node)
{
	// node�� ����ִٸ� return
	if (_node == nullptr)
	{
		return;
	}

	// �ش� _node�� headNode�ų� tailNode��� �����ϰ� ���� ���� head�� �ǰ���. tail�̶�� ���� ���� tail�� �ɰŴ�.
	if (_node == headNode || _node == tailNode)
	{
		if (_node == headNode)
		{
			headNode = _node->nextNode;
			delete _node;
			_node = nullptr;
		}
		else
		{
			tailNode = _node->preNode;
			delete _node;
			_node = nullptr;
		}
	}
	else
	{
		DoubleLinkedList<T>::Node* preNode = _node->preNode;
		DoubleLinkedList<T>::Node* nextNode = _node->nextNode;

		preNode->nextNode = nextNode;
		nextNode->preNode = preNode;

		delete _node;
		_node = nullptr;
	}
}

template<typename T>
inline struct DoubleLinkedList<T>::Node* DoubleLinkedList<T>::Find(T _data)
{
	DoubleLinkedList<T>::Node* currentNode = headNode;

	while (currentNode != nullptr)
	{
		if (currentNode->data == _data)
		{
			return currentNode;
		}
		currentNode = currentNode->nextNode;
	}

	return nullptr;
}

// RECT ���� Find Template
template<>
inline struct DoubleLinkedList<RECT>::Node* DoubleLinkedList<RECT>::Find(RECT _data)
{
	DoubleLinkedList<RECT>::Node* currentNode = headNode;

	while (currentNode != nullptr)
	{
		if (currentNode->data.left >= _data.left &&
			currentNode->data.top >= _data.top &&
			currentNode->data.right <= _data.right &&
			currentNode->data.bottom <= _data.bottom)
		{
			return currentNode;
		}
		currentNode = currentNode->nextNode;
	}

	return nullptr;
}

template<typename T>
inline void DoubleLinkedList<T>::Print()
{
	DoubleLinkedList<T>::Node* currentNode = headNode;

	while (currentNode != nullptr)
	{
		std::cout << currentNode->data << " ";
		currentNode = currentNode->nextNode;
	}
	std::cout << std::endl;
}

