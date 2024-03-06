#include <iostream>
#include "franklist.h"
#include <vector>
#include <list>

int main()
{

	// FrankList<int> test = {42, 8, 7, 2, 5, 2222, 0, -8, 12};
	// FrankList<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	FrankList<int> test = {1, 2, 3}; // 3 2 1


	// test.remove_if([](int i){return i % 2 == 0;});


	test.insert(FrankList<int>::reverse_iterator(test.find(1)), {7, 8, 9});

	test.clear();

	auto i = test.begin();
	auto j = test.cmaend();


	// test.print(i, j);



	// for (int count = 0; count < 10; count++)
	// {
	// 	test.rfind(1);
	// 	i = test.rbegin();
	// 	j = test.rend();
	// 	test.print(i, j); // oke oke
	// 	std::cout << std::endl;
	// 	std::cout << std::endl;
	// }




	// for (FrankList<int>::reverse_iterator i = test.rbegin(); i != test.rend(); i++)
	// 	std::cout << *i << "  ";

	return 0;
}
