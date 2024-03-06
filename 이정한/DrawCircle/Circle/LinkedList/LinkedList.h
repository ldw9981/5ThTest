#pragma once
#include <iostream>
template<typename T>
struct Node
{
    T data;
    Node<T>* nextNode = nullptr;

    Node(T value) : data(value), nextNode(nullptr) {}
};

template<typename T>
class LinkedList
{
public:
    LinkedList() {}
    ~LinkedList() {}

    bool isEmpty()
    {
        return headNode == nullptr;
    }

    void printAll()
    {
        Node<T>* printNode = headNode;

        if (isEmpty())
        {
            std::cout << "No more element to print" << std::endl;
            return;
        }

        while (printNode)
        {
            std::cout << printNode->data << ' ';
            printNode = printNode->nextNode;
        }

        std::cout << std::endl;
    }

    int GetSize()
    {
        Node<T>* size = headNode;
        int cnt = 0;

        if (isEmpty())
        {
            std::cout << "Container Size : " << cnt << std::endl;
            return cnt;
        }

        while (size)
        {
            size = size->nextNode;
            cnt++;
        }

        std::cout << "Container Size : " << cnt << std::endl;
        return cnt;
    }

    void clear()
    {
        Node<T>* clear = headNode;

        if (isEmpty())
        {
            std::cout << "Container is Empty." << std::endl;
            return;
        }

        while (clear->nextNode != nullptr)
        {
            pop_back();
        }

        if (clear == headNode)
        {
            delete clear;
            headNode = nullptr;
            std::cout << "All the elements are deleted. " << std::endl;
            GetSize();
        }
    }

    void push_back(const T& value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (!headNode)
        {
            headNode = newNode;
            return;
        }
        else
        {
            Node<T>* tempNode = headNode;

            while (tempNode->nextNode != nullptr)
            {
                tempNode = tempNode->nextNode;
            }

            tempNode->nextNode = newNode;
        }
    }

    void push_front(const T& value)
    {
        Node<T>* newNode = new Node<T>(value);

        if (!headNode)
        {
            headNode = newNode;
            return;
        }
        else
        {
            newNode->nextNode = headNode;
            headNode = newNode;
        }
    }

    void pop_back()
    {
        if (isEmpty())
        {
            std::cerr << "Container is empty. Can't delete anymore. " << std::endl;
            return;
        }

        Node<T>* currentNode = headNode;
        Node<T>* tempNode = headNode->nextNode;

        while (tempNode->nextNode != nullptr)
        {
            currentNode = currentNode->nextNode;
            tempNode = tempNode->nextNode;
        }

        delete tempNode;

        currentNode->nextNode = nullptr;
    }

    void pop_front()
    {
        if (isEmpty())
        {
            std::cerr << "Container is empty. Can't delete anymore. " << std::endl;
            return;
        }

        Node<T>* tempNode = headNode;

        headNode = tempNode->nextNode;

        delete tempNode;
    }

private:
    Node<T>* headNode = nullptr;
};