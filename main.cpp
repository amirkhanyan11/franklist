#include <iostream>
#include "franklist.h"
#include <vector>
#include <list>

using namespace vhuk;



int main()
{

	FrankList<int> test = {1, 2, 3, 4, 5};

	FrankList<int> hehe = {666, 666, 666, 1, 1};

	FrankList<int>::iterator i = test.begin();
	FrankList<int>::iterator j = hehe.begin();
	FrankList<int>::iterator k = hehe.begin();

	// std::list<int> stest = {1, 2, 3, 4, 5};
	// std::list<int> hehe = {666, 666, 666, 1, 1};

	// std::list<int>::iterator si = stest.begin();
	// std::list<int>::iterator hb = hehe.begin();
	// std::list<int>::iterator he = hehe.begin();


	// stest.insert(si, he, hb);

	// size_t s = 3;


	test.insert(i, j, k);

	for (FrankList<int>::iterator i = test.begin(); i != test.end(); i++)
	{
		std::cout << *i << "  ";
	}
	std::cout << std::endl;

	// for (auto i : stest)
	// {
	// 	std::cout << i << "  ";
	// }
	// std::cout << std::endl;



	return 0;
}
