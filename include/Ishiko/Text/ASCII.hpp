/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TEXT_ASCII_HPP_
#define _ISHIKO_CPP_TEXT_ASCII_HPP_

#include <string>
#include <vector>

namespace Ishiko
{
namespace Text
{

class ASCII
{
public:
    static bool IsAlpha(char c);
    static bool IsNumeric(char c);
    static bool IsAlphanumeric(char c);
    static bool IsWhitespace(char c);

    static std::vector<std::string> GetLines(const std::string& str);
    static std::vector<std::string> Split(const std::string& str, char separator);
    static void ToLowerCase(std::string& str);
    static void ToUpperCase(std::string& str);
    // TODO: at the moment this only trims spaces and not other whitespace characters,
    // allow to pass list of characters that can be trimmed, also allow to trim front or back
    static void Trim(std::string& str);
};

}
}

#endif
