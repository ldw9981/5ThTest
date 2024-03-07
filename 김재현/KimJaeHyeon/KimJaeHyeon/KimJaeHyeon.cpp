

///
// 2차 제출물을 제작하면서 list의 iterator와 erase가 필요하다는 것을 깨닫고, 
// 제작하려하였으나 iterator의 구현이 막히고 시간이 얼마 남지않아서 제출하게 되었습니다.
///

#include <iostream>

template<typename T>
class Node
{
public:
    Node() {};
    Node(T _Data) { data = _Data; }

public:
    Node* prev = nullptr;
    Node* next = nullptr;
    T data = {};
    int m_index = 0;

};

template<typename T>
class myList
{
private:
    Node<T>* cur;

public:
    Node<T>* tail;
    Node<T>* head;
    int num = 0;

public:
    Node<T> front()
    {
        return *head->next;
    }

    Node<T> end()
    {
        return *tail->prev;
    }
    int size()
    {
        return num;
    }

    int GetIndex()
    {
       return cur->m_index;
    }

    Node<T>* GetCurNode()
    {
        return cur;
    }

    void SetCurNode(Node<T>& curNode)
    {
        curNode = cur;
    }

    void NextNode()
    {
        if (cur->next != nullptr)
            cur = cur->next;
        else
            cur = head->next;
    }

    void erase(int index)
    {
        if (cur->m_index = index)
        {
            cur->next = cur->prev->next;
            cur->prev = cur->next->prev;
            delete cur;
        }
    }

    void push_back(T instance)
    {
        if (num == 0)
        {
            Node<T>* element = new Node<T>(instance);
            Node<T>* myHead = new Node<T>();
            Node<T>* myTail = new Node<T>();
            
            head = myHead;
            tail = myTail;

            head->next = element;
            tail->prev = element;

            element->next = tail;
            element->prev = head;

            num++;
        }
        else 
        {
            Node<T>* element = new Node<T>(instance);

            element->prev = tail->prev;
            element->next = tail;

            tail->prev->next = element;
            tail->prev = element;
            num++;
        }
    }

    void pop()
    {
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev; 
        num--;
    }
};

int main()
{
    myList<int> mList;

    mList.push_back(3); 
    std::cout << "Front: " << mList.front().data << std::endl;
    std::cout << "End: " << mList.end().data << std::endl << std::endl;

    mList.pop();
    std::cout << "Pop Front: " << mList.front().data << std::endl;
    std::cout << "Pop End: " << mList.end().data << std::endl << std::endl;

    mList.push_back(1); 
    std::cout << "Front: " << mList.front().data << std::endl;
    std::cout << "End: " << mList.end().data << std::endl << std::endl;

    mList.push_back(5);
    std::cout << "Front: " << mList.front().data << std::endl;
    std::cout << "End: " << mList.end().data << std::endl;
    std::cout << "Size : " << mList.size() << std::endl << std::endl;
    
    mList.pop();
    std::cout << "Pop Front: " << mList.front().data << std::endl;
    std::cout << "Pop End: " << mList.end().data << std::endl << std::endl;

    mList.pop();
    std::cout << "Pop Front: " << mList.front().data << std::endl;
    std::cout << "Pop End: " << mList.end().data << std::endl << std::endl;

    mList.push_back(7);
    std::cout << "Front: " << mList.front().data << std::endl;
    std::cout << "End: " << mList.end().data << std::endl << std::endl;

    mList.push_back(9);  
    std::cout << "Front: " << mList.front().data << std::endl;
    std::cout << "End: " << mList.end().data << std::endl << std::endl;
}