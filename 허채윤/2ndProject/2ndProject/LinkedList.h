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
			m_tail->m_next = newNode; // ������ ������ �� ��� ����
		}
		m_tail = newNode; // Ȯ�� �ʿ�...
		newNode->m_next = nullptr; // �� ����� ������ null��
	}

	void PopBack()
	{
		if (!m_head)
		{
			std::cout << "����Ʈ�� �ƹ��͵� �����ϴ�." << std::endl;
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
			} // �� ������ tail �ٷ� ����
			// ������ next�� tail�� ����Ű�ڳ�.
			// �� ������ tail�� �־�� ��.
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
		// ������µ� ��ħ �����
		if (temp != nullptr && temp->m_data == _key)
		{
			m_head = temp->m_next;
			delete temp;
			return;
		}

		// �Ϲ����� ��Ȳ��
		Node* prev = nullptr;
		while (temp != nullptr && temp->m_data != _key)
		{
			prev = temp;
			temp = temp->m_next;
		}
		if (temp == nullptr)
		{
			std::cout << "�� ����� ���� : ����Ʈ�� �ش� ���� ���� ���� �ʽ��ϴ�." << std::endl;
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