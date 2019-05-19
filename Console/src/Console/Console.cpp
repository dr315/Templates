/*
 * Console.cpp
 *
 *  Created on: 18 de ago de 2016
 *      Author: doreis
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>
#include <iomanip>
#include <algorithm>

#include <Service/Convert.h>
#include "Console.h"
#include "Commands/ShowASCII.h"


Console::Console()
{
	commandMap["sa"] = new ShowASCII("sa");
    commandMap["exit"] = nullptr;
}


bool Console::ProcessCommand(std::string cmd)
{
    CommandBase* cmdHandler;
    std::string result;
    bool found;
    std::map<std::string, CommandBase*>::iterator it;
    std::vector<std::string> paramList;

    found = false;
    cmdHandler = nullptr;

    paramList.clear();
    splitString(cmd,' ', paramList);

    if(paramList.size() > 0)
    {
        cmd = paramList[0];
        std::transform(cmd.begin(), cmd.end(), cmd.begin(), toupper);

        for (auto it : this->commandMap)
        {
            std::string cmdName = it.first;
            std::transform(cmdName.begin(), cmdName.end(), cmdName.begin(), toupper);

            if(cmdName == cmd)
            {
                cmdHandler = it.second;
                found = true;
                break;
            }
        }

        if(cmdHandler == nullptr)
        {
            if(!found)
            {
                std::cout << "Command invalid!" << std::endl;
                return true;
            }
            else
            {
                std::cout << "Closing Terminal!" << std::endl;
                return false;
            }
        }

        paramList.erase(paramList.begin());

        if(cmdHandler->ParseParameters(paramList))
        {
            if (cmdHandler->Execute(result))
            {
            }
        }
        else
        {
            std::cout << "Invalid parameters Dumb!" << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid command Dumb!" << std::endl;
    }
    return true;
}

void Console::Execute()
{
	std::string cmd, result;

	do
	{
	    Help();

		std::cout << "Type a command: ";
		std::cout << std::endl;
		std::getline(std::cin, cmd);

	}while(ProcessCommand(cmd));
}

void Console::Help()
{
    std::cout << std::endl << "+" << std::setw(80) << std::right << std::setfill('-') << "-" << "+" << std::endl;
    std::cout << "|" << std::setw(80) << std::left << std::setfill(' ') << "                      Commands" << "|" << std::endl;

    for (auto it : this->commandMap)
    {
        std::string help = "Close";

        if(it.second)
        {
            it.second->Help(help);
        }

        std::cout << "|" << std::setw(80) << std::left << std::setfill(' ') << it.first + ": " + help << "|" << std::endl;
    }
    std::cout << "+"<< std::setw(80) << std::right << std::setfill('-') << "-" << "+" << std::endl << std::endl;

}
