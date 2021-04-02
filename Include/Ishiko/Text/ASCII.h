/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Text/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_TEXT_ASCII_H_
#define _ISHIKO_TEXT_ASCII_H_

#include <string>

namespace Ishiko
{
namespace Text
{

class ASCII
{
public:
    static void ToLowerCase(std::string& str);
    static void ToUpperCase(std::string& str);
};

}
}

#include "linkoptions.h"

#endif
