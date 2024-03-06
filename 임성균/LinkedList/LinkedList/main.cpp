#include <list>
#include <iostream>
using namespace std;

/// <summary>
/// 생각이 안날 때 시그니처를 참고하기 위해 만들었다
/// </summary>
/// <returns></returns>

int main()
{
	std::list<int> li;
	std::list<int>::const_iterator citr;
	const int& val= 10;

	li.insert(citr, val);

	li.clear();
}