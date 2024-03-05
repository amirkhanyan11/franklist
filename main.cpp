#include <iostream>
#include "franklist.h"
#include <vector>
#include <list>

using namespace vhuk;

int main()
{

	// FrankList<int> test = {42, 8, 7, 6, 5, 2222, 0, -8, 12};
	FrankList<int> test = {1, 2, 3, 4, 5, 6};

	//test.clear();
	// FrankList<int>::iterator i = test.begin();
	//FrankList<int>::iterator j = test.end();

	// FrankList<int>::const_reverse_iterator i = test.crbegin();
	// FrankList<int>::const_reverse_iterator j = test.crend();

	// test.remove_if([](int i){return i % 2 == 0;});


	//test.print(i, j);

	std::cout << test << std::endl;

	// for (FrankList<int>::reverse_iterator i = test.rbegin(); i != test.rend(); i++)
	// 	std::cout << *i << "  ";

	return 0;
}
