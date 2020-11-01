/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Text/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_TEXT_CSTRING_H_
#define _ISHIKO_TEXT_CSTRING_H_

namespace Ishiko
{

class CString
{
public:
    static char* Duplicate(const char* str);
};

}

#include "linkoptions.h"

#endif
