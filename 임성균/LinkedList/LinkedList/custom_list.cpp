#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
	Node() : _prev(nullptr), _next(nullptr), _data(T())
	{

	}

	Node(const T& value) : _prev(nullptr), _next(nullptr), _data(value)
	{

	}

public:
	T _data;
	Node* _prev;
	Node* _next;
};

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{

	}
	Iterator(Node<T>* node) : _node(node)
	{

	}

public:
	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator<T> temp;
		_node = _node->_next;
		return temp;
	}

	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Iterator operator--(int)
	{
		Iterator<T> temp;
		_node = _node->_prev;
		return temp;
	}

	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}

	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}


public:
	Node<T>* _node;
};

template<typename T>
class List
{
public:	// ������, �Ҹ���
	List() :_size(0)
	{
		_head = new Node<T>();
		_tail = new Node<T>();

		_head->_next = _tail;
		_tail->_prev = _head;
	}
	~List()
	{
		// 0���� ũ�� Pop_back
		while (_size > 0)
			Pop_back();

		delete _head;
		delete _tail;

		_size = 0;
	}

private:	// AddNode, RemoveNode�� ����Ʈ������ �� ���̹Ƿ� private�� �����ص� �ȴ�
	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		// before����� �ٷ� �տ� ���ο� ��尡 ����
		// ... [preNode] <-> [before] ...
		// ... [preNode] <-> [newNode] <-> [before] ...
		Node<T>* newNode = new Node<T>(value);

		Node<T>* preNode = before->_prev;

		newNode->_prev = preNode;
		preNode->_next = newNode;

		newNode->_next = before;
		before->_prev = newNode;

		_size++;

		return newNode;	// ���� �߰��� ��带 ��ȯ�Ѵ�
	}

	Node<T>* RemoveNode(Node<T>* node)	// �ش��ϴ� node�� ����
	{
		// ������ ����� �������� ������带 ���� �̾��ش�
		// ... [prevNode] <-> [node] <-> [nextNode] ...
		// ... [preNode] <-> [nextNode] ...
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		// node ����
		delete node;

		_size--;

		return nextNode;	// ������ ����� ���� ��带 ��ȯ�Ѵ�
	}

public:
	void Push_back(const T& value)	/// void �ΰ� ���� ������ ���
	{
		AddNode(_tail, value);	// _tail����� �ٷ� �տ� �߰��Ѵ�
	}

	void Pop_back()		/// void �ΰ� ���� ������ ���
	{
		RemoveNode(_tail->_prev);		// _tail�� �ٷ� �ճ�带 �����Ѵ�
	}

	int Size()
	{
		return _size;
	}

public:		// ���ͷ����� ����
	using iterator = Iterator<T>;

	// Begin, End, Insert, Clear
	iterator Begin()
	{
		return _head->_next;	// _head�� ������ ����
	}

	iterator End()
	{
		return _tail;	// _tail�� ����
	}


	/// Insert�Լ� ���� ����
	iterator Insert(iterator& it, const T& value)
	{
		// ���ϴ� ��ġ�� 1�� �߰�
		Node<T>* node = new Node<T>();
		node = AddNode(it._node, value);
		
		// ���ο� node�� it�� _node�� ����
		it._node = node;

		return it;	 	
	}


	/// ���� �����Ѱ� �̷��� �������� �ʾ�����...
	/// ����� ���� �ʾƼ� �����Ҵ�
	/// ������ �Ǿ���Ѵ�..
	void Clear()
	{
		/// ��� ��Ҹ� �� �����, _size�� 0���� �����		
		// 0���� ũ�� Pop_back
		while (_size > 0)
			Pop_back();

		// �Ҹ��ڿ��� _head�� _tail�� �����ϴ� �κи� ���ݴ�.
	}




public:
	int _size;

	Node<T>* _head;
	Node<T>* _tail;

};


int main()
{
	List<int> li;

	List<int>::iterator eraseIt;

	for (int i = 0; i < 10; i++)
	{
		//if (i == 5)
		//{
		//	li.Insert(eraseIt, 2*i);	// error
		//}
		//else
		//	li.Push_back(i);

		li.Push_back(i);
	}

	for (List<int>::iterator it = li.Begin(); it != li.End(); it++)
	{
		std::cout << (*it) << std::endl;
	}

	std::cout << "======================" << std::endl;

	li.Pop_back();


	for (List<int>::iterator it = li.Begin(); it != li.End(); it++)
	{
		std::cout << (*it) << std::endl;
	}
	std::cout << "======================" << std::endl;

	li.Clear();
	for (List<int>::iterator it = li.Begin(); it != li.End(); it++)
	{
		std::cout << (*it) << std::endl;
	}


	/// Insert�Լ��� ������ �ְ�, �� �� �������� ����

}