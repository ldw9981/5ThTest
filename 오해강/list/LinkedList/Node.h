#pragma once

template <typename T>
struct Node
{
public:
	void InsertNode(unsigned int _num, Node<T>* _node);
	Node<T>* GetNode(unsigned int _num);
	void DeleteNode(unsigned int _num);

public:
	// 노드가 갖는 데이터
	T data{};
	// 다음노드
	Node* nextNode = nullptr;


};

template<typename T>
inline void Node<T>::InsertNode(unsigned int _num, Node<T>* _node)
{
	if (_num == 1)
	{
		_node->nextNode = nextNode;
		nextNode = _node;
	}
	else
	{
		nextNode->InsertNode(_num - 1, _node);
	}
}

template<typename T>
inline Node<T>* Node<T>::GetNode(unsigned int _num)
{
	if (_num == 0)
	{
		return this;
	}
	else
	{
		return nextNode->GetNode(_num - 1);
	}
}

template<typename T>
inline void Node<T>::DeleteNode(unsigned int _num)
{
	if (_num == 1)
	{
		Node<T>* temp = nextNode;
		nextNode = nextNode->nextNode;
		delete temp;
	}
	else
	{
		nextNode->DeleteNode(_num - 1);
	}
}
