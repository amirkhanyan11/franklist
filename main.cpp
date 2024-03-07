#include <iostream>
#include "franklist.h"
#include <vector>
#include <list>






int main()
{

	// FrankList<int> test = {42, 8, 7, 2, 5, 2222, 0, -8, 12};

	std::size_t size = 10;

	FrankList<int> mi = {4, 5, 3, 7, 8, 99, 0, 1, -4, 6};
	std::list<int> stl = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// auto mm = mi.begin();
	// auto ss = stl.begin();

	// int count = 5;
	// while(count > 0)
	// {
	// 	mm++, ss++, count--;
	// }


	// mi.insert(mi.begin(), {1, 2, 3, 4, 5, 6});
	// mi.insert(mi.begin(), {1, 2, 3, 4, 5, 6});
	// mi.insert(mi.begin(), {1, 2, 3, 4, 5, 6});
	// stl.insert(stl.begin(), {1, 2, 3, 4, 5, 6});
	// stl.insert(stl.begin(), {1, 2, 3, 4, 5, 6});
	// stl.insert(stl.begin(), {1, 2, 3, 4, 5, 6});

	// auto iter = stl.begin();


	mi.sort();

	mi.print();

	std::cout <<  std::endl;

	mi.print(true);
	mi.sort(true);
	mi.print();

	// std::cout <<  std::endl;

	// mi.sort();

	// mi.print();

	// std::cout <<  std::endl;

	// for (auto i : stl)
	// 	std::cout << i << "  ";

	// std::cout << std::endl;

	int count = 1;

	// mi.traverse([iter, count](const int i) mutable {

	// 	if (*iter != i)
	// 		std::cout << "Test " << count <<  " : novu nonononoo snekek olololo\n";
	// 	else
	// 		std::cout << "Test " << count <<  " : vu\n";

	// 	iter++;
	// 	count++;
	// },
	// mi.begin(), mi.end());

	return 0;
}
