/*
 * Select.cpp
 *
 *  Created on: 18 de ago de 2016
 *      Author: doreis
 */
#include <Service/Convert.h>

#include <exception>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;

#include <Service/Convert.h>


#include "ShowASCII.h"



ShowASCII::ShowASCII(std::string name):CommandBase(name)
{
    //    std::copy(defaultName.begin(), defaultName.end(), std::back_inserter(fileName));
}
bool ShowASCII::ParseParameters(std::vector<std::string>& paramList)
{
    bool ret = true;

    if(paramList.size() >= 1)
        this->count = std::atoi(paramList[0].c_str());
      return ret;
}

bool ShowASCII::Execute(std::string& result)
{

	count = fmax(count, 127);
	char ch = 0x20;
	do
	{
		cout << "0x" << std::hex << (int)ch;
		cout << "=" << ch << "\t";
		if(ch % 10 == 0)
			cout << endl;
	}while(++ch < count);
    return true;
}

std::string& ShowASCII::Help(std::string& message)
{
    message = "Show ASCII table. Usage: " + name + " <char_count>";
    return message;
}
