/*
 * CommandBase.h
 *
 *  Created on: 18 de ago de 2016
 *      Author: doreis
 */
#ifndef COMMAND_BASE_H_
#define COMMAND_BASE_H_

#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


//class TagTable
//{
//public:
//	const ASN1_Byte *tag;
//	std::string name;
//	TagTable(const ASN1_Byte *tag,  std::string name){this->tag = tag; this->name = name;};
//};

class CommandBase
{
protected:
    std::string name;
public:
//	static std::vector<TagTable> tagTable;

    CommandBase(std::string name){ this->name = name;}
    ~CommandBase(){};
	virtual std::string& Help(std::string&);
	virtual bool ParseParameters(std::vector<std::string>& paramList) = 0;
	virtual bool Execute(std::string& result) = 0;
};

#endif //COMMAND_BASE_H_
