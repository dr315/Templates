/*
 * Convert.h
 *
 *  Created on: 18 de ago de 2016
 *      Author: doreis
 */

#ifndef CONVERT_H_
#define CONVERT_H_

#include <stdint.h>
#include <string>       // std::string
#include <vector>

//void HexToBin(std::string& hex, std::vector<ASN1_UByte>& bytes);
std::string ByteToHex(uint8_t* data, uint32_t len, char separator);
bool splitString(std::string& input, char separator, std::vector<std::string>& result);
bool IsStringPrint(uint8_t* data, uint32_t len);
bool IsStringPrint(std::string &);

#endif /* CONVERT_H_ */
