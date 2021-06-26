/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_TEXT_ASCII_H_
#define _ISHIKO_TEXT_ASCII_H_

#include <string>
#include <vector>

namespace Ishiko
{
namespace Text
{

class ASCII
{
public:
    static std::vector<std::string> GetLines(const std::string& str);
    // TODO: this function splits only based on the space character, update it to take
    // on which character(s) to split
    static std::vector<std::string> Split(const std::string& str);
    static void ToLowerCase(std::string& str);
    static void ToUpperCase(std::string& str);
    // TODO: at the moment this only trims spaces and not other whitespace characters,
    // allow to pass list of characters that can be trimmed, also allow to trim front or back
    static void Trim(std::string& str);
};

}
}

#include "linkoptions.h"

#endif
