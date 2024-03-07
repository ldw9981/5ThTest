#include <iostream>

template <typename T>
class LinkedList
{
public:
	struct Node
	{
		T m_data;
		Node* m_next;

		Node(T _input)
		{
			m_data = _input;
			m_next = nullptr;
		}

		Node()
		{
			m_data = 0;
			m_next = nullptr;
		}
	};
public:
	Node* m_head;
	Node* m_tail;

	LinkedList()
	{
		m_head = nullptr;
		m_tail = nullptr;
	}

	void PushBack(T _input)
	{
		Node* newNode = new Node(_input);
		if (!m_head)
		{
			m_head = newNode;
		}
		else
		{
			m_tail->m_next = newNode; // 꼬리의 다음에 새 노드 삽입
		}
		m_tail = newNode; // 확인 필요...
		newNode->m_next = nullptr; // 새 노드의 다음을 null로
	}

	void PopBack()
	{
		if (!m_head)
		{
			std::cout << "리스트에 아무것도 없습니다." << std::endl;
			return;
		}

		if (m_head == m_tail)
		{
			delete m_head;
			m_head = nullptr;
			m_tail = nullptr;
			return;
		}
		else
		{
			Node* temp = m_head;
			while (temp->m_next != m_tail)
			{
				temp = temp->m_next;
			} // 이 템프는 tail 바로 앞임
			// 템프의 next는 tail을 가리키겠네.
			// 이 템프에 tail을 넣어야 함.
			//m_tail = temp->m_next;
			delete m_tail;
			temp->m_next = nullptr;
			m_tail->m_next = temp->m_next;
			m_tail = temp;
		}
	}

	void eraseNode(T _key)
	{
		Node* temp = m_head;
		// 지우려는데 마침 헤드임
		if (temp != nullptr && temp->m_data == _key)
		{
			m_head = temp->m_next;
			delete temp;
			return;
		}

		// 일반적인 상황임
		Node* prev = nullptr;
		while (temp != nullptr && temp->m_data != _key)
		{
			prev = temp;
			temp = temp->m_next;
		}
		if (temp == nullptr)
		{
			std::cout << "값 지우기 실패 : 리스트는 해당 값을 갖고 있지 않습니다." << std::endl;
			return;
		}

		prev->m_next = temp->m_next;

		delete temp;

	}

	void PrintAll()
	{
		for (auto iter = Begin(); iter != End(); ++iter)
		{
			std::cout << *iter << ' ';
		}
		std::cout << std::endl;
	}

	void Clear()
	{
		Node* temp = m_head;
		while (temp != nullptr && m_tail != nullptr)
		{
			PopBack();
		}
	}

public:
	class MyIterator
	{
	private:
		Node* m_current;

	public:
		MyIterator(Node* _node = 0)
		{
			m_current = _node;
		}

		MyIterator& operator++()
		{
			m_current = m_current->m_next;
			return *this;
		}

		T& operator*()
		{
			return m_current->m_data;
		}

		bool operator != (const MyIterator& compare)
		{
			return m_current != compare.m_current;
		}

		bool operator == (const MyIterator& compare)
		{
			return m_current == compare.m_current;
		}
	};

	MyIterator Begin()
	{
		return MyIterator(m_head);
	}

	MyIterator End()
	{
		return MyIterator(nullptr);
	}
};


int main()
{
	// 선언
	LinkedList <int> list;

	// 0~4까지 집어넣기
	for (int i = 0; i <= 3; i++)
	{
		list.PushBack(i);
	}
	// 출력
	list.PrintAll();

	// 2개 삭제 후 출력
	for (int i = 0; i <= 1; i++)
	{
		list.PopBack();
	}
	list.PrintAll();

	// 완전히 지운 후 출력
	list.Clear();
	list.PrintAll();

	// 0~4까지 입력 후 출력
	for (int i = 0; i <= 4; i++)
	{
		list.PushBack(i);
	}
	list.PrintAll();

	// 리스트 내 값이 2인 것을 삭제 후 출력
	list.eraseNode(2);
	list.PrintAll();

	return 0;
}