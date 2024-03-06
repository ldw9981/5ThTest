#pragma once
template<typename T>
struct Node
{
    //나중에 원 중심값을 저장해둘거니까 데이터를 미리 2개로 만들어두자
    T data1;
    T data2;

    Node* pNode;
    Node* nNode;
};

template<typename T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;

    int count;

public:
    LinkedList();
    ~LinkedList();

public:
    int Add(T _data1, T _data2);
    int Delete(T _data, T _data2);
    Node<T>* Search(T _data, T _data2);

    void ShowAll();
    void Clear();

};