#include <iostream>

template <typename T>
struct Node
{
	Node(const T& value) : data(value) {}
	Node() : data(T()) {}
	~Node() = default;

	//---------------------------------

	T data;
	Node* front = nullptr;
	Node* back = nullptr;
};

template <typename T>
class List
{
public:
	List();
	List(const T& value);
	~List();

public:
	void push_front(const T& value);
	void push_back(const T& value);
	void insert(size_t pos, const T& value);

	const T& pop_front();
	const T& pop_back();
	void remove(const T& value);
	bool empty() { if (size == 0) return true; else return false; }

	T& front();
	T& back();

	size_t size() { return m_size; }
	
private:
	Node<T>* m_head = nullptr;
	Node<T>* m_tail = nullptr;
	size_t m_size = 0;
};

// 생성, 소멸자 -------------------------------------------------

template<typename T>
inline List<T>::List()
{
	m_head = new Node<T>();
	m_tail = m_head;
	m_size++;
}

template<typename T>
inline List<T>::List(const T& value)
{
	m_head = new Node<T>(value);
	m_tail = m_head;
	m_size++;
}

template<typename T>
inline List<T>::~List()
{
}

// 삽입 ------------------------------------------------------

template<typename T>
inline void List<T>::push_front(const T& value)
{
	if (m_size == 0)
	{
		m_head = new Node<T>(value);
		m_tail = m_head;
		m_size++;
		return;
	}

	Node<T>* newNode = new Node<T>(value);
	m_head->front = newNode;
	newNode->back = m_head;
	m_head = newNode;
	m_size++;
}

template<typename T>
inline void List<T>::push_back(const T& value)
{
	if (m_size == 0)
	{
		m_head = new Node<T>(value);
		m_tail = m_head;
		m_size++;
		return;
	}

	Node<T>* newNode = new Node<T>(value);
	m_tail->back = newNode;
	newNode->front = m_tail;
	m_tail = newNode;
	m_size++;
}

template<typename T>
inline void List<T>::insert(size_t pos, const T& value)
{
	if (pos == 0)
	{
		push_front(value);
		return;
	}
	if (pos >= m_size)
	{
		push_back(value);
		return;
	}

	// 헤드에서부터 탐색, pos번째 노드를 찾는다
	Node<T>* currentNode = m_head;
	for (int i = 0; i < pos; i++)
		currentNode = currentNode->back;

	// 새로운 노드를 pos번째에 삽입
	Node<T>* newNode = new Node<T>(value);
	newNode->front = currentNode->front;
	newNode->back = currentNode;
	currentNode->front->back = newNode;
	currentNode->front = newNode;

	// 현재 노드가 헤드일 경우
	if (currentNode == m_head) m_head = newNode;
	else if (currentNode == m_tail) m_tail = newNode;

	// 예외처리는 테스트 코드 짜면서

	m_size++;
}

template<typename T>
inline const T& List<T>::pop_front()
{
	Node<T>* temp = m_head;
	T data = temp->data;
	if(m_head->back != nullptr) m_head = m_head->back;
	m_head->front = nullptr;

	delete temp;
	m_size--;

	if (m_size == 1)
	{
		m_tail = m_head;
	}

	return data;
}

template<typename T>
inline const T& List<T>::pop_back()
{
	Node<T>* temp = m_tail;
	T data = temp->data;
	if(m_tail->front != nullptr) m_tail = m_tail->front;
	m_tail->back = nullptr;
	delete temp;
	m_size--;

	if (m_size == 1)
	{
		m_head = m_tail;
	}

	return data;
}

template<typename T>
inline void List<T>::remove(const T& value)
{
	// 모든 노드를 순회하면서 데이터 비교 후 삭제
	Node<T>* currentNode = m_head;
	while (currentNode != nullptr)
	{
		if (currentNode->data == value)
		{
			Node<T>* temp = currentNode;
			if (currentNode == m_head)
			{
				currentNode = currentNode->back;
				pop_front();
				continue;
			}
			else if (currentNode == m_tail)
			{
				pop_back();
				return;
			}
			else
			{
				currentNode->front->back = currentNode->back;
				currentNode->back->front = currentNode->front;
				currentNode = currentNode->back;
				delete temp;

				m_size--;
			}
		}
		else currentNode = currentNode->back;
	}
}

template<typename T>
inline T& List<T>::front()
{
	return m_head->data;
}

template<typename T>
inline T& List<T>::back()
{
	return m_tail->data;
}
