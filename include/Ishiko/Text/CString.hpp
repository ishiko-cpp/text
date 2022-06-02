/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TEXT_CSTRING_HPP_
#define _ISHIKO_CPP_TEXT_CSTRING_HPP_

#include <string>

namespace Ishiko
{

class CString
{
public:
    static char* Duplicate(const char* str);
    static std::string Substring(const char* str, size_t begin);
    static std::string Substring(const char* str, size_t begin, size_t end);
    static size_t Find(const char* str, const char* substring);
    static bool StartsWith(const char* str, const char* prefix);
    static bool EndsWith(const char* str, const char* suffix);
};

}

#endif
