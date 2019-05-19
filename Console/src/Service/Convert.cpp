/*
 * Convert.cpp
 *
 *  Created on: 18 de ago de 2016
 *      Author: doreis
 */

#include "Convert.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>
#include <iomanip>
#include <algorithm>

std::string ByteToHex(uint8_t* data, uint32_t len, char separator)
{
	std::ostringstream os;

	for(uint32_t i = 0; i < len; i++)
	{
		os << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(data[i]);
		if(separator)
			os << separator;
	}


	return os.str();
}

void HexToBin(std::string& hex, std::vector<uint8_t>& bytes)
{
    remove_if(hex.begin(), hex.end(), isspace);
    remove_if(hex.begin(), hex.end(), iscntrl);

	for (unsigned int i = 0; i < hex.length(); i += 2)
	{
		std::string byteString = hex.substr(i, 2);
		char byte = (char) strtol(byteString.c_str(), NULL, 16);
		bytes.push_back(byte);
	}
}

bool splitString(std::string& input, char separator, std::vector<std::string>& result)
{
	std::istringstream ss(input);
	std::string token;

	while(std::getline(ss, token, separator)) {
		result.push_back(token);
	}
	return true;
}

bool IsStringPrint(uint8_t* data, uint32_t len)
{
	if (len <= 0) return false;

	for(uint32_t i = 0; i < len; i++)
		if(isprint(data[i]) == 0)
			return false;
	return true;
}

bool IsStringPrint(std::string &str)
{
    if (str.empty()) return false;

    for (auto c: str) {
        if (std::isprint(c) == 0 ){
            return false;
        }
    }
    return true;
}
