#include <iostream>
//#include "franklist.h"
#include <vector>

int main()
{
	std::vector<int> vec = {1, 2, 3, 4, 5};



    for (auto i = vec.rbegin(); i != vec.rend(); i++)
	{
		auto j = std::move(i);
		std::cout << (i == j) << std::endl;
	}
}
