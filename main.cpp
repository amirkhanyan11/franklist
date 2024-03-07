#include <iostream>
#include "franklist.h"
#include <vector>
#include <list>


class niger
{
public:
	double gender;
	niger(double d) { gender = d; }
	bool operator<(const niger& other) const
	{
		return true;
	}
	bool operator>(const niger& other) const
	{
		return false;
	}
	bool operator>=(const niger& other) const
	{
		return true;
	}

};


int main()
{
	FrankList<niger> nlist = {niger(3.14), niger(2.7)};

	for (FrankList<niger>::iterator i = nlist.begin(); i != nlist.end(); i++)
	{
		std::cout << i->gender << std::endl;
	}


	return 0;
}
