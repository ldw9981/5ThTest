#pragma once

//����Ʈ�� �� ���
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


///����Ʈ
template<typename T>
class LinkedList
{
public:
	//������;
	LinkedList();

	LinkedList(T data);

	//�Ҹ���
	~LinkedList();

	////���� ������
	LinkedList(const LinkedList<T>& other);

	////���� ���� ������
	LinkedList<T>& operator=(const LinkedList& other);

	//��� �߰�
	void Push_back(T data);

	//�߰� ��� �߰�
	void Push(int count, T data);

	//��� ����
	void Pop_back();


	//�߰� ��� ����
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
	//������ ��� ����
	Node<T>* temp = new Node<T>(data);

	//����Ʈ�� ���������
	if (head == nullptr && tail == nullptr)
	{
		head = temp;
		tail = temp;
	}

	//������ ���� �ִٸ�
	tail->next = temp;
	temp->pre = tail;
	tail = temp;
}

template<typename T>
void LinkedList<T>::Push(int count, T data)
{
	//�߰��� �ֱ�

		//���� ��ġ�� ���ã��
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

	//������ ��� ����
	Node<T>* temp = new Node<T>(data);

	temp->pre = push;
	temp->next = nextNode;

	nextNode->pre = temp;
	push->next = temp;
}

template<typename T>
void LinkedList<T>::Pop_back()
{
	//�������� �������� �ٲ�
	tail = tail->pre;
	tail->next = nullptr;

	delete tail->next;
}

template<typename T>
void LinkedList<T>::Pop(int count)
{
	//������ ��ġ�� ���ã��
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
