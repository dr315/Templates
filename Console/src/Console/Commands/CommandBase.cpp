/*+
 * CommandBase.cpp*
 *
 *  Created on: 19 de ago de 2016
 *      Author: doreis
 */

#include "CommandBase.h"
#include <cstring>
#include <Service/Convert.h>

extern "C"
{
}


//std::vector<TagTable> CommandBase::tagTable =
//        //CommandBase::tagTable =
//{
//        TagTable("\x04"                                         , "OctetString"),
//};

std::string& CommandBase::Help(std::string& message)
{
    message = "Nothing important";
    return message;
}
