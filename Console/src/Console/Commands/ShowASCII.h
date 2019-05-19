/*
 * Select.h
 *
 *  Created on: 18 de ago de 2016
 *      Author: doreis
 */

#ifndef SHOWASCII_H_
#define SHOWASCII_H_

#include <string>
#include <vector>

#include "CommandBase.h"
class ShowASCII: public CommandBase
{
    int count;
public:

    ShowASCII(std::string name);
    ~ShowASCII(){};
    std::string& Help(std::string& message);
	bool ParseParameters(std::vector<std::string>& paramList);
    bool Execute(std::string& result);
};

#endif /* SHOWASCII_H_ */
