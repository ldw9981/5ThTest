#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	Node* head;
	Node* tail;
	T next;
};

template <typename T>
class LinkedList
{
public:
	LinkedList() {}
	~LinkedList() {}

public:
	LinkedList(T _data)
	{
		Node* node;
		node.head = nullptr;
		node.tail = nullptr;
	}

	void AddNodeHead(T _data)
	{
		Node* node;

	}

	void AddNodeTail(T _data)
	{
		Node* node;
	}

	void DeleteNodeHead(T _data)
	{
		Node* node;
	}

	void DeleteNodeTail(T _data)
	{
		Node* node;
	}
};
//struct Node
//{
//	Node* head;
//	Node* tail;
//	int next;
//};
//
//class LinkedList
//{
//public:
//	LinkedList();
//	~LinkedList();
//
//private:
//	Node* node;
//	int data;
//
//public:
//	LinkedList(Node* _node)
//	{
//		node->head = nullptr;
//		node->tail = nullptr;
//		node->next = 0;
//	}
//	
//	// �� �տ� ���� ����Ʈ �߰�
//	void AddNodeHead(int _data)
//	{
//		// ���� ����Ʈ�� ó�� �κ����� �̵�
//		// �� ��ġ�� �߰��ϱ�
//	}
//
//	// �� �ڿ� ���� ����Ʈ �߰�
//	void AddNodeTail(int _data)
//	{
//		// ���� ����Ʈ�� ������ ��ġ�� �̵�
//		// �� ��ġ�� �߰�
//	}
//
//	// �� ���� ���� ����Ʈ ����
//	void DeleteNodeHead(int _data)
//	{
//		// �� �տ� �ִ� ���� ����Ʈ�� ã�� �� ����
//	}
//
//	// �� ���� ���� ����Ʈ ����
//	void DeleteNodeTail(int _data)
//	{
//		// �� �ڿ� �ִ� ���� ����Ʈ�� ã�� �� ����
//	}
//};