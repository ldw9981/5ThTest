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

	// 2번에서 필요한 거 생성, 삭제랑 해당 부분을 삭제 해야 되니 찾는거 까지만 있으면 되겠다.
	// 생성, 삭제, 찾기, 출력
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
	// head Node가 비어 있다면 생성
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
	// node가 비어있다면 return
	if (_node == nullptr)
	{
		return;
	}

	// 해당 _node가 headNode거나 tailNode라면 삭제하고 다음 것이 head가 되겠지. tail이라면 전에 것이 tail이 될거다.
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

// RECT 전용 Find Template
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

