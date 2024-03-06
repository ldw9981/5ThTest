#pragma once
#include <iostream>
using namespace std;

struct Node;

template <typename T>
class MyLinkedList
{
public:
    struct Node
    {
        T data;
        Node* prev = nullptr;
        Node* next = nullptr;
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
    Node* GetHead() { return m_head; }
    Node* GetTail() { return m_tail; }

private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
};


template<typename T>
void MyLinkedList<T>::PushFront(T data)
{
    Node* node = new Node;
    node->data = data;

    // ��ũ�� ����Ʈ�� �ƹ��͵� ���� ��
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

    // ��ũ�� ����Ʈ�� �ƹ��͵� ���� ��
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
    // ��尡 �ϳ� ������ ��
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
    // ��尡 �ϳ� ������ ��
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
            cout << "�ε����� ���" << endl;
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
            cout << "�ε����� ���" << endl;
            return;
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

