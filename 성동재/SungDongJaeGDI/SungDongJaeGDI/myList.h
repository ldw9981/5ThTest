#include <iostream>
#include<windows.h>
using namespace std;

template<typename T>
class Node
{
public:
	Node(T _data)
	{
		data = _data;
		nextNode = nullptr;
		prevNode = nullptr;
	}
	Node() {}
	~Node() {}
public:
	T data;
	Node<T>* nextNode;
	Node<T>* prevNode;
};

template<typename T>
class MyList
{
public:
	MyList()
	{
		startNode = new Node<T>();
		endNode = new Node<T>();
		startNode->prevNode = startNode;
		startNode->nextNode = endNode;
		endNode->prevNode = startNode;
		endNode->nextNode = endNode;
		size = 0;
	}
	~MyList() {}
public:
	Node<T>* startNode;
	Node<T>* endNode;
	int size;

public:
	void push_back(Node<T>* _node)
	{
		AddNode(endNode->prevNode, _node);
	}
	void push(int index, Node<T>* _node)
	{
		if (size < index)
		{
			cout << " 오류입니다. " << endl;
		}
		Node<T>* TargetNode = startNode;
		for (int i = 0; i < index; i++)
		{
			TargetNode = TargetNode->nextNode;
		}
		AddNode(TargetNode, _node);
	}
	void AddNode(Node<T>* parents, Node<T>* _node)
	{
		_node->nextNode = parents->nextNode;
		_node->prevNode = parents;
		parents->nextNode->prevNode = _node;
		parents->nextNode = _node;

		size++;
	}
	void erase(int index)
	{
		if (size < index)
		{
			cout << " 오류입니다. " << endl;
		}
		Node<T>* TargetNode = startNode;
		for (int i = 0; i < index; i++)
		{
			TargetNode = TargetNode->nextNode;
		}
		TargetNode->prevNode->nextNode = TargetNode->nextNode;
		TargetNode->nextNode->prevNode = TargetNode->prevNode;
		delete TargetNode;
		size--;
	}
	void clear()
	{
		Node<T>* TargetNode = startNode->nextNode;
		for (TargetNode = startNode->nextNode; TargetNode != endNode; )
		{
			Node<T>* tempNextTarget = TargetNode->nextNode;
			delete TargetNode;
			TargetNode = tempNextTarget;
		}
		startNode->nextNode = endNode;
		endNode->prevNode = startNode;
		size = 0;
	}


	void printAll()
	{
		Node<T>* TargetNode = startNode->nextNode;
		for (TargetNode = startNode->nextNode; TargetNode != endNode; TargetNode = TargetNode->nextNode)
			cout << TargetNode->data << " ";
		cout << endl;
	}
	void printAllReverse()
	{
		Node<T>* TargetNode = endNode->prevNode;
		for (TargetNode = endNode->prevNode; TargetNode != startNode; TargetNode = TargetNode->prevNode)
			cout << TargetNode->data << " ";
		cout << endl;
	}
};