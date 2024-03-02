#include <iostream>
#include "franklist.h"
#include <vector>

using namespace vhuk;



int main()
{
	FrankList<int> flist(10);

	FrankList<int>::iterator iter = flist.begin();

	
	for (auto i : flist)
	{
		std::cout << i << std::endl;
	}

	return 0;
}
