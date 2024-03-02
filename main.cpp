#include <iostream>
#include "franklist.h"
#include <vector>

using namespace vhuk;


int main()
{
	FrankList<int> flist(10);

	FrankList<int>::iterator iter = flist.begin();

	FrankList<int>::asc_iterator aiter = iter;

	std::cout << iter->val	<< std::endl;

	// for (auto i : flist)
	// {
	// 	std::cout << i << std::endl;
	// }

	return 0;
}
