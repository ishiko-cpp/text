/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "CString.hpp"
#include <Ishiko/BasePlatform/Compilers.h>
#include <string.h>

namespace Ishiko
{

char* CString::Duplicate(const char* str)
{
#if ISHIKO_COMPILER == ISHIKO_COMPILER_GCC
    return strdup(str);
#elif ISHIKO_COMPILER == ISHIKO_COMPILER_MSVC
    return _strdup(str);
#else
    #error Unsupported or unrecognized compiler
#endif
}

std::string CString::Substring(const char* str, size_t begin)
{
    return std::string(str + begin);
}

std::string CString::Substring(const char* str, size_t begin, size_t end)
{
    return std::string(str + begin, str + end);
}

size_t CString::Find(const char* str, const char* substring)
{
    const char* ptr = strstr(str, substring);
    if (ptr == nullptr)
    {
        return std::string::npos;
    }
    else
    {
        return (ptr - str);
    }
}

bool CString::StartsWith(const char* str, const char* prefix)
{
    return (strncmp(str, prefix, strlen(prefix)) == 0);
}

}
