/*
 * Console.h
 *
 *  Created on: 18 de ago de 2016
 *      Author: doreis
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_
#include <string>
#include <map>

#include "Commands/CommandBase.h"

class Console {
    std::map<std::string, CommandBase*> commandMap;

  public:
    Console();
    void Help();
	void Execute();
	bool ProcessCommand(std::string comand);
};

#endif /* CONSOLE_H_ */
