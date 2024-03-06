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
public:	// 생성자, 소멸자
	List() :_size(0)
	{
		_head = new Node<T>();
		_tail = new Node<T>();

		_head->_next = _tail;
		_tail->_prev = _head;
	}
	~List()
	{
		// 0보다 크면 Pop_back
		while (_size > 0)
			Pop_back();

		delete _head;
		delete _tail;

		_size = 0;
	}

private:	// AddNode, RemoveNode는 리스트에서만 쓸 것이므로 private로 선언해도 된다
	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		// before노드의 바로 앞에 새로운 노드가 들어간다
		// ... [preNode] <-> [before] ...
		// ... [preNode] <-> [newNode] <-> [before] ...
		Node<T>* newNode = new Node<T>(value);

		Node<T>* preNode = before->_prev;

		newNode->_prev = preNode;
		preNode->_next = newNode;

		newNode->_next = before;
		before->_prev = newNode;

		_size++;

		return newNode;	// 새로 추가한 노드를 반환한다
	}

	Node<T>* RemoveNode(Node<T>* node)	// 해당하는 node를 삭제
	{
		// 삭제할 노드의 이전노드와 다음노드를 서로 이어준다
		// ... [prevNode] <-> [node] <-> [nextNode] ...
		// ... [preNode] <-> [nextNode] ...
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		// node 삭제
		delete node;

		_size--;

		return nextNode;	// 삭제한 노드의 다음 노드를 반환한다
	}

public:
	void Push_back(const T& value)	/// void 인것 같은 느낌이 들어
	{
		AddNode(_tail, value);	// _tail노드의 바로 앞에 추가한다
	}

	void Pop_back()		/// void 인것 같은 느낌이 들어
	{
		RemoveNode(_tail->_prev);		// _tail의 바로 앞노드를 제거한다
	}

	int Size()
	{
		return _size;
	}

public:		// 이터레이터 관련
	using iterator = Iterator<T>;

	// Begin, End, Insert, Clear
	iterator Begin()
	{
		return _head->_next;	// _head의 다음을 리턴
	}

	iterator End()
	{
		return _tail;	// _tail을 리턴
	}


	/// Insert함수 구현 실패
	iterator Insert(iterator& it, const T& value)
	{
		// 원하는 위치에 1개 추가
		Node<T>* node = new Node<T>();
		node = AddNode(it._node, value);
		
		// 새로운 node를 it의 _node에 저장
		it._node = node;

		return it;	 	
	}


	/// 원래 공부한건 이렇게 구현하지 않았지만...
	/// 기억이 나지 않아서 만들어보았다
	/// 실행은 되어야한다..
	void Clear()
	{
		/// 모든 요소를 다 지우고, _size를 0으로 만든다		
		// 0보다 크면 Pop_back
		while (_size > 0)
			Pop_back();

		// 소멸자에서 _head와 _tail을 삭제하는 부분만 없앴다.
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


	/// Insert함수에 문제가 있고, 그 외 나머지는 정상

}