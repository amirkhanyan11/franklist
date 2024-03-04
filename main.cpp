#include <iostream>
#include "franklist.h"
#include <vector>
#include <list>

using namespace vhuk;



int main()
{

	FrankList<int> test = {8, 7, 6, 5, 2222, 0, -8};

	test.sort(true);

	for (FrankList<int>::iterator i = test.begin(); i != test.end(); i++)
	{
		std::cout << *i << "  ";
	}
	std::cout << std::endl;

	return 0;
}
