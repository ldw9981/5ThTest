#include <iostream>
#include "LinkedList.h"


//template <typename T>
int main()
{
	LinkedList<int>* list = new LinkedList<int>;
	int num;
	int num2;
	int val;
	while (1)
	{
		std::cout << "�߰� : 1, ã�� : 2, ���� : 3, ��� ��� : 4" << std::endl;
		std::cout << "�Է�: ";
		std::cin >> num;
		if (num == 1)
		{
			std::cout << "�߰��� �� �Է�: " << std::endl;
			std::cin >> val;
			list->Add(val);
		}
		else if (num == 2)
		{
			std::cout << "ã�� ���� �Է�: " << std::endl;
			std::cin >> num2;
			list->Find(num2);
		}
		else if (num == 3)
		{
			std::cout << "�� �ڿ� ����" << std::endl;
			list->Delete(1);
		}
		else if (num == 4)
		{
			list->PrintAll();
		}
		else
		{
			std::cout << "���� ���" << std::endl;
		}
	
	}
	//list->Add(1);
	//list->Add(2);
	//list->Add(3);
	//list->Add(4);
	//
	//list->Delete(4);
	//list->Add(6);
	//std::cout<<"ã��" << std::endl;
	//std::cout<<list->Find(1)->value << std::endl;
	//
	//list->Add(6);

	return 0;
}