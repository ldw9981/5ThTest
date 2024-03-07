#include <iostream>


template <typename T>
struct Node
{
	Node(T data) :data(data), next(nullptr), prev(nullptr) {}
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T>
struct Iterator
{
	Iterator(Node<T>* node) :current(node) { }
	Node<T>* current;

	Iterator<T> operator++();
	Iterator<T> operator--();

	T operator*();
	Node<T>* operator&();

	bool operator==(Iterator<T> other);
	bool operator!=(Iterator<T> other);
};

template <typename T>
struct LinkedList
{
	LinkedList() :head(nullptr), tail(nullptr), iterator(nullptr) {}
	Node<T>* head;
	Node<T>* tail;
	Iterator<T> iterator;

	void push_back(T data);
	void push_front(T data);
	void pop_back();
	void pop_front();
	void erase(const Iterator<T>& it);
	void insert(const Iterator<T>& it, T data);

	Iterator<T> begin();
	Iterator<T> end();

};


// Iterator
template<typename T>
Iterator<T> Iterator<T>::operator++()
{
	current = current->next;
	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator--()
{
	current = current->prev;
	return *this;
}

template<typename T>
T Iterator<T>::operator*()
{
	return current->data;
}

template<typename T>
Node<T>* Iterator<T>::operator&()
{
	return current;
}

template<typename T>
bool Iterator<T>::operator==(Iterator<T> other)
{
	return (current == other.current);
}

template<typename T>
bool Iterator<T>::operator!=(Iterator<T> other)
{
	return (current != other.current);
}


// LinkedList
template<typename T>
void LinkedList<T>::push_back(T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (tail == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		Node<T>* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->prev = current;
		tail = newNode;
	}
}

template<typename T>
void LinkedList<T>::push_front(T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

template<typename T>
void LinkedList<T>::pop_back()
{
	if (tail == nullptr)
	{
		return;
	}
	else
	{
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
}

template<typename T>
void LinkedList<T>::pop_front()
{
	if (head == nullptr)
	{
		return;
	}
	else
	{
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}
}

template<typename T>
void LinkedList<T>::erase(const Iterator<T>& it)
{
	if (it.current == head)
	{
		pop_front();
	}
	else if (it.current == tail)
	{
		pop_back();
	}
	else
	{
		it.current->prev->next = it.current->next;
		it.current->next->prev = it.current->prev;
		delete it.current;
	}
}

template<typename T>
void LinkedList<T>::insert(const Iterator<T>& it, T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (it.current == head)
	{
		push_front(data);
	}
	else if (it.current == tail)
	{
		push_back(data);
	}
	else
	{
		newNode->next = it.current;
		newNode->prev = it.current->prev;
		it.current->prev->next = newNode;
		it.current->prev = newNode;
	}
}

template<typename T>
Iterator<T> LinkedList<T>::begin()
{
	return Iterator<T>(head);
}

template<typename T>
Iterator<T> LinkedList<T>::end()
{
	return Iterator<T>(nullptr);
}


int main()
{
	LinkedList<int>* intList = new LinkedList<int>();
	intList->push_back(10);
	intList->push_back(20);
	intList->push_back(30);

	intList->push_front(40);
	intList->push_front(50);
	intList->push_front(60);

	std::cout << "push_back, front test" << std::endl;
	for (auto it = intList->begin(); it != intList->end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "erase test" << std::endl;
	intList->erase(intList->begin());
	for (auto it = intList->begin(); it != intList->end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "insert test" << std::endl;
	intList->insert(++intList->begin(), 70);
	for (auto it = intList->begin(); it != intList->end(); ++it)
	{
		std::cout << *it << std::endl;
	}


	return 0;
}