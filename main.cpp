#include <iostream>
#include "franklist.h"
#include <vector>
#include <list>

int main()
{

	vhuk::FrankList<int> test = {42, 8, 7, 2, 5, 2222, 0, -8, 12};
	// vhuk::FrankList<int> test = {1, 2, 3, 4, 5, 6};


	// test.remove_if([](int i){return i % 2 == 0;});

	test.find(-8);
	// test.find(-8);
	// test.find(-8);
	// test.find(-8);
	// test.find(-8);
	// test.find(-8);

	auto i = test.abegin();
	auto j = test.aend();
	
	test.print(i, j);

	// for (vhuk::FrankList<int>::reverse_iterator i = test.rbegin(); i != test.rend(); i++)
	// 	std::cout << *i << "  ";

	return 0;
}
