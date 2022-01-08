/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TEXT_CSTRING_HPP_
#define _ISHIKO_CPP_TEXT_CSTRING_HPP_

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

#endif
