#include <iostream>
#include "franklist.h"
#include <vector>
#include <list>

using namespace vhuk;



int main()
{

	FrankList<int> test;

	test.push_front(99);

	test.pop_front();

	for (FrankList<int>::iterator i = test.begin(); i != test.end(); i++)
	{
		std::cout << *i << std::endl;
	}


	// std::cout << "\nSize : " << test.size() << std::endl;


	return 0;
}
