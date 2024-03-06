#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<int>* myIntList = new LinkedList<int>();

    myIntList->push_back(1);
    myIntList->push_back(2);
    myIntList->push_back(2);
    myIntList->push_back(2);
    myIntList->push_front(5);

    myIntList->pop_front();
    myIntList->pop_front();
    myIntList->pop_front();

    myIntList->printAll();

    myIntList->GetSize();

    myIntList->clear();
    myIntList->printAll();


    std::cout << "========================================" << std::endl;

    LinkedList<char>* myCharList = new LinkedList<char>();

    myCharList->push_front('c');
    myCharList->push_front('y');
    myCharList->push_back('p');
    myCharList->push_back('q');

    myCharList->printAll();
    myCharList->GetSize();

    myCharList->clear();
}
