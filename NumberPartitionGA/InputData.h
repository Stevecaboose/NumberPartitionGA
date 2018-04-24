#pragma once
#include <string>
#include <vector>

class InputData
{
public:
	InputData();
	InputData::InputData(std::string in);
	~InputData();
	void loadData(std::string in);
	std::vector<int> getdataSet();
	bool getFail();
	int getListSize();
	void displayList();


private:
	char cNum[10]{};
	std::vector<int> dataSet;
	bool fail;
	std::string delimeter = ",";
	int listSize;
};

