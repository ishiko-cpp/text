/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TEXT_ASCII_HPP_
#define _ISHIKO_CPP_TEXT_ASCII_HPP_

#include <Ishiko/Errors.hpp>
#include <string>
#include <vector>

namespace Ishiko
{

class ASCII
{
public:
    static bool IsAlpha(char c);
    static bool IsNumeric(char c);
    static bool IsAlphanumeric(char c);
    static bool IsWhitespace(char c);

    static std::vector<std::string> GetLines(const std::string& str);
    static std::vector<std::string> Split(const std::string& str, char separator, bool conflateAdjacentSeparators);
    static void ToLowerCase(std::string& str);
    static void ToUpperCase(std::string& str);
    // TODO: at the moment this only trims spaces and not other whitespace characters,
    // allow to pass list of characters that can be trimmed, also allow to trim front or back
    static void Trim(std::string& str);

    static void Convert(const std::string& str, int8_t& number, Error& error);
    static void Convert(std::string::const_iterator begin, std::string::const_iterator end, int8_t& number,
        Error& error);
    static void Convert(const std::string& str, uint8_t& number, Error& error);
    static void Convert(std::string::const_iterator begin, std::string::const_iterator end, uint8_t& number,
        Error& error);
    static void Convert(const std::string& str, int16_t& number, Error& error);
    static void Convert(std::string::const_iterator begin, std::string::const_iterator end, int16_t& number,
        Error& error);
    static void Convert(const std::string& str, uint16_t& number, Error& error);
    static void Convert(std::string::const_iterator begin, std::string::const_iterator end, uint16_t& number,
        Error& error);
};

}

#endif
