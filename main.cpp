#include <iostream>
#include "franklist.h"
#include <vector>
#include <list>

using namespace vhuk;



int main()
{
	// std::size_t a = 5;

	// FrankList<int> flist(a, 1);

	FrankList<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	FrankList<int>::iterator f = c.begin();
	FrankList<int>::iterator l = c.end();

	FrankList<int> test(f, l);

	for (auto i : test)
	{
		std::cout << i << std::endl;
	}

	return 0;
}
