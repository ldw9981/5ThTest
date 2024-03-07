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
		std::cout << "추가 : 1, 찾기 : 2, 삭제 : 3, 모두 출력 : 4" << std::endl;
		std::cout << "입력: ";
		std::cin >> num;
		if (num == 1)
		{
			std::cout << "추가할 값 입력: " << std::endl;
			std::cin >> val;
			list->Add(val);
		}
		else if (num == 2)
		{
			std::cout << "찾을 순서 입력: " << std::endl;
			std::cin >> num2;
			list->Find(num2);
		}
		else if (num == 3)
		{
			std::cout << "맨 뒤에 삭제" << std::endl;
			list->Delete(1);
		}
		else if (num == 4)
		{
			list->PrintAll();
		}
		else
		{
			std::cout << "없는 기능" << std::endl;
		}
	
	}
	//list->Add(1);
	//list->Add(2);
	//list->Add(3);
	//list->Add(4);
	//
	//list->Delete(4);
	//list->Add(6);
	//std::cout<<"찾음" << std::endl;
	//std::cout<<list->Find(1)->value << std::endl;
	//
	//list->Add(6);

	return 0;
}