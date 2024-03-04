#include <iostream>
#include "franklist.h"
#include <vector>
#include <list>

using namespace vhuk;



int main()
{

	// FrankList<int> test = {42, 8, 7, 6, 5, 2222, 0, -8};
	FrankList<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	FrankList<int>::iterator i = test.begin();
	FrankList<int>::iterator j = test.end();

	test.remove_if([](int i){return i % 2 == 0;});

	test.print(test.begin(), test.end());
	test.print(test.rbegin(), test.rend());

	// std::cout << "\n" << test.size() << "\n";	

	return 0;
}
