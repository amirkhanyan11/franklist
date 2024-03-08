#include <iostream>
#include "franklist.h"
#include <vector>
#include <list>

using namespace vhuk;

class niger
{
public:
	double gender;
	niger(double d) { gender = d; }
	niger() = delete;

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
    friend std::ostream& operator<<(std::ostream& os, const niger& ng); 

};

std::ostream& operator<<(std::ostream& os, const niger& ng)
{
	os << ng.gender;
	return os;
}


int main()
{
	// vhuk::FrankList<niger> nlist = {niger(3.14), niger(2.7)};

	// for (vhuk::FrankList<niger>::iterator i = nlist.begin(); i != nlist.end(); i++)
	// {
	// 	std::cout << i->gender << std::endl;
	// }

	std::list<niger> stl;
	vhuk::FrankList<niger> mi;

	auto i = mi.begin();

	std::cout << i->gender << std::endl;


	return 0;
}
