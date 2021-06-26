/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "CString.h"
#include <Ishiko/Platform/Compilers.h>
#include <string.h>

namespace Ishiko
{
namespace Text
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

}
}
