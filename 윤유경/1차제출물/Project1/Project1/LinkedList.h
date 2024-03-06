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
//	// 맨 앞에 연결 리스트 추가
//	void AddNodeHead(int _data)
//	{
//		// 연결 리스트의 처음 부분으로 이동
//		// 그 위치에 추가하기
//	}
//
//	// 맨 뒤에 연결 리스트 추가
//	void AddNodeTail(int _data)
//	{
//		// 연결 리스트의 마지막 위치로 이동
//		// 그 위치에 추가
//	}
//
//	// 맨 앞의 연결 리스트 삭제
//	void DeleteNodeHead(int _data)
//	{
//		// 맨 앞에 있는 연결 리스트를 찾은 뒤 삭제
//	}
//
//	// 맨 뒤의 연결 리스트 삭제
//	void DeleteNodeTail(int _data)
//	{
//		// 맨 뒤에 있는 연결 리스트를 찾은 뒤 삭제
//	}
//};