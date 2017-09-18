#pragma once
#include <list>
class GA
{
public:
	GA();
	~GA();

	void run(); //no input data. Data is randomly generated
	std::list <std::string> tournament(std::list<std::string>& L, int size);
};

