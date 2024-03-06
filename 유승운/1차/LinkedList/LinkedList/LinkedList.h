#pragma once

//리스트에 들어갈 노드
template<typename T>
class Node
{
public:
	Node<T>* pre;
	Node<T>* next;

	T data;

	Node()
	{

	}

	Node(T val) : pre(nullptr), next(nullptr)
	{
		data = val;
	}

	~Node()
	{
		delete pre;
		delete next;
	}

};


///리스트
template<typename T>
class LinkedList
{
public:
	//생성자;
	LinkedList();

	LinkedList(T data);

	//소멸자
	~LinkedList();

	////복사 생성자
	LinkedList(const LinkedList<T>& other);

	////복사 대입 연산자
	LinkedList<T>& operator=(const LinkedList& other);

	//노드 추가
	void Push_back(T data);

	//중간 노드 추가
	void Push(int count, T data);

	//노드 제거
	void Pop_back();


	//중간 노드 제거
	void Pop(int count);

private:

	Node<T>* head;
	Node<T>* tail;
};

template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(T data)
{
	Node<T>* temp = new Node(data);
	head = temp;
	tail = temp;
}

template<typename T>
LinkedList<T>::~LinkedList()
{

}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
	this->head = nullptr;
	this->tail = nullptr;

	Node<T>* temp = nullptr;
	temp = other.head;

	while (temp != nullptr)
	{
		this->Push_back(temp->data);

		temp = temp->next;
	}

}

template<typename T>
LinkedList<T>& LinkedList<T>:: operator=(const LinkedList& other)
{
	this->head = nullptr;
	this->tail = nullptr;

	Node<T>* temp = nullptr;
	temp = other.head;

	while (temp != nullptr)
	{
		this->Push_back(temp->data);

		temp = temp->next;
	}
}


template<typename T>
void LinkedList<T>::Push_back(T data)
{
	//연결할 노드 생성
	Node<T>* temp = new Node<T>(data);

	//리스트가 비어있으면
	if (head == nullptr && tail == nullptr)
	{
		head = temp;
		tail = temp;
	}

	//기존의 것이 있다면
	tail->next = temp;
	temp->pre = tail;
	tail = temp;
}

template<typename T>
void LinkedList<T>::Push(int count, T data)
{
	//중간에 넣기

		//넣을 위치의 노드찾기
	Node<T>* push = head;
	for (int i = 1; i < count; i++)
	{
		if (push == nullptr)
		{
			return;
		}

		push = push->next;
	}

	Node<T>* nextNode = push->next;

	//연결할 노드 생성
	Node<T>* temp = new Node<T>(data);

	temp->pre = push;
	temp->next = nextNode;

	nextNode->pre = temp;
	push->next = temp;
}

template<typename T>
void LinkedList<T>::Pop_back()
{
	//마지막꺼 이전꺼로 바꿈
	tail = tail->pre;
	tail->next = nullptr;

	delete tail->next;
}

template<typename T>
void LinkedList<T>::Pop(int count)
{
	//제거할 위치의 노드찾기
	Node<T>* destroy = head;

	for (int i = 0; i < count; i++)
	{
		if (destroy == nullptr)
		{
			return;
		}

		destroy = destroy->next;
	}


	Node<T>* preNode = destroy->pre;
	Node<T>* nextNode = destroy->next;

	preNode->next = nextNode;
	nextNode->pre = preNode;

	destroy->pre = nullptr;
	destroy->next = nullptr;

	delete destroy;
}
