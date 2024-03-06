#include <iostream>

using namespace std;

template <typename T>
class MyLinkedList
{
public:
    struct Node
    {
        T data;
        Node* prev = nullptr;
        Node* next = nullptr;

        Node* operator++()
        {
            return next;
        }
    };
public:
    MyLinkedList() = default;
    ~MyLinkedList() = default;

public:
    void PushFront(T data);
    void PushBack(T data);
    void PopFront();
    void PopBack();
    void Insert(T data, int idx);
    void Erase(int idx);
    void EraseAll();
    void ShowList();

private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
};


int main()
{
    MyLinkedList<int> mll;
    mll.PushBack(1);
    mll.ShowList();
    mll.PushBack(2);
    mll.ShowList();
    mll.PushFront(3);
    mll.ShowList();
    mll.Insert(4, 1);
    mll.ShowList();
    mll.Erase(1);
    mll.ShowList();
    mll.PopBack();
    mll.ShowList();
    mll.PopFront();
    mll.ShowList();
    mll.PopBack();
    mll.ShowList();
    mll.PushBack(1);
    mll.PushBack(2);
    mll.PushBack(3);
    mll.PushBack(4);
    mll.ShowList();
    mll.EraseAll();
    mll.ShowList();
}

template<typename T>
void MyLinkedList<T>::PushFront(T data)
{
    Node* node = new Node;
    node->data = data;

    // 링크드 리스트에 아무것도 없을 때
    if (m_head == nullptr && m_tail == nullptr)
    {
        m_head = node;
        m_tail = node;
    }
    else
    {
        node->next = m_head;
        m_head->prev = node;
        m_head = node;
    }
}

template<typename T>
void MyLinkedList<T>::PushBack(T data)
{
    Node* node = new Node;
    node->data = data;

    // 링크드 리스트에 아무것도 없을 때
    if (m_head == nullptr && m_tail == nullptr)
    {
        m_head = node;
        m_tail = node;
    }
    else
    {
        node->prev = m_tail;
        m_tail->next = node;
        m_tail = node;
    }
}

template<typename T>
void MyLinkedList<T>::PopFront()
{
    Node* nextHead = m_head->next;

    if (nextHead)
    {
        m_head = nextHead;

        delete m_head->prev;
        m_head->prev = nullptr;
    }
    // 노드가 하나 남았을 때
    else
    {
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
    }
}

template<typename T>
void MyLinkedList<T>::PopBack()
{
    Node* prevTail = m_tail->prev;

    if (prevTail)
    {
        m_tail = prevTail;

        delete m_tail->next;
        m_tail->next = nullptr;
    }
    // 노드가 하나 남았을 때
    else
    {
        delete m_tail;
        m_tail = nullptr;
        m_head = nullptr;
    }
}

template<typename T>
void MyLinkedList<T>::Insert(T data, int idx)
{
    Node* newNode = new Node;

    newNode->data = data;

    int cnt = 0;

    Node* curNode = m_head;
    while (cnt != idx)
    {
        if (!curNode)
        {
            cout << "인덱스를 벗어남" << endl;
            break;
        }
        curNode = curNode->next;
        cnt++;
    }

    Node* prevNode = curNode->prev;

    if (prevNode)
    {
        newNode->prev = prevNode;
        prevNode->next = newNode;
    }

    curNode->prev = newNode;
    newNode->next = curNode;
}

template<typename T>
void MyLinkedList<T>::Erase(int idx)
{
    int cnt = 0;
    Node* curNode = m_head;
    while (cnt != idx)
    {
        if (!curNode)
        {
            cout << "인덱스를 벗어남" << endl;
            break;
        }
        curNode = curNode->next;
        cnt++;
    }

    Node* nextNode = curNode->next;
    Node* prevNode = curNode->prev;

    if (nextNode)
    {
        nextNode->prev = prevNode;
    }

    if (prevNode)
    {
        prevNode->next = nextNode;
    }

    delete curNode;
    curNode = nullptr;
}

template<typename T>
inline void MyLinkedList<T>::EraseAll()
{
    Node* temp = m_head;
    while (temp)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    m_head = nullptr;
    m_tail = nullptr;
}

template<typename T>
void MyLinkedList<T>::ShowList()
{
    Node* temp = m_head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
