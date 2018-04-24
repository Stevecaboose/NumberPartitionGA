/**
*	@file InputData.cpp
*	@author Steven Scholz
*	@date 4/23/18
*	@version 1.0
*
*	@breif This file loads in a csv file and puts each element into a vector<int>
*/
#include "InputData.h"
#include <iostream>     // std::cerr
#include <fstream>      // std::ifstream
#include <sstream>
#include <string>
#include <boost/algorithm/string.hpp>



/**
 * @brief Default constructor
 */
InputData::InputData()
= default;

/**
 * @brief Constructor that opens and parses a file
 * @param in a string that is the name of the file
 */
InputData::InputData(const std::string in)
{
	fail = false;
	listSize = 0;
	loadData(in);
	if(fail)
	{
		std::cout << "Problem opening file\n";
	}

}

/**
 * @brief Default destructor
 */
InputData::~InputData()
= default;

/**
 * @brief Opens the file and parses the csv file
 * @param in a string that is the name of the file
 * @return void
 */
void InputData::loadData(const std::string in)
{

		std::ifstream file(in);
		
		
		

		if (file.is_open()){

			std::vector<int> dataList;
			

			std::string line;
			// Iterate through each line and split the content using delimeter
			while (std::getline(file, line))
			{
				std::vector<std::string> vec;
				boost::algorithm::split(vec, line, boost::is_any_of(delimeter));
				for (const auto& i : vec)
				{
					
					dataList.push_back(stoi(i));
				}
				
			}
			// Close the File
			file.close();
			dataSet = dataList;
			listSize = dataList.size();
		}else
		{
			std::cout << "Exception opening/reading/closing file\n";
			fail = true;
		}

		
		
}
	/**
	 * @brief returns the dataSet
	 * @return vector<int> dataSet
	 */
std::vector<int> InputData::getdataSet()
{
	return dataSet;
}

/**
 * @brief returns fail flag
 * @return bool fail
 */
bool InputData::getFail()
{
	return fail;
}

/**
 * @brief returns the size of the dataSet list
 * @return int number of elements of the dataSet list
 */
int InputData::getListSize()
{
	return listSize;
}

/**
 * @brief prints the list
 * @return void
 */
void InputData::displayList()
{
	for (int i = 0; i < listSize; i++)
	{
		std::cout << dataSet[i] << " ";
	}
}
