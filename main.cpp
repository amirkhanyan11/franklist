#include <iostream>
#include "franklist.h"
#include <vector>
#include <list>

int main()
{

	// FrankList<int> test = {42, 8, 7, 2, 5, 2222, 0, -8, 12};
	FrankList<int> test = {1, 2, 3, 4, 5, 6};


	// test.remove_if([](int i){return i % 2 == 0;});


	auto i = test.begin();
	auto j = test.end();


	for (int count = 0; count < 10; count++)
	{
		test.find(5);
		i = test.begin();
		j = test.end();
		test.print(i, j);
		std::cout << std::endl;
		std::cout << std::endl;
	}





	// for (FrankList<int>::reverse_iterator i = test.rbegin(); i != test.rend(); i++)
	// 	std::cout << *i << "  ";

	return 0;
}
