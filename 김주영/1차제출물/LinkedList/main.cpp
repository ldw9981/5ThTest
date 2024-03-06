#include "LinkedList.h"

int main()
{
	LinkedList<int> list;

	list.AddData(2);
	list.AddData(1);
	list.AddData(3);
	list.AddData(5);
	list.AddData(4);
	list.AddData(6);

	list.PrintData();
	
	// 맨 앞의 데이터를 지울 때
	list.DeleteData(0);
	list.PrintSize();
	list.PrintData();

	// 맨 뒤의 데이터를 지울 때
	list.DeleteData(4);
	list.PrintSize();
	list.PrintData();

	// 중간 데이터를 지울 때
	list.DeleteData(2);
	list.PrintSize();
	list.PrintData();

	// 잘못된 범주의 인덱스를 입력할 때
	list.DeleteData(-1);
	list.DeleteData(10);

}