/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_TEXT_CSTRING_H_
#define _ISHIKO_TEXT_CSTRING_H_

namespace Ishiko
{
namespace Text
{

class CString
{
public:
    static char* Duplicate(const char* str);
};

}
}

#include "linkoptions.h"

#endif
